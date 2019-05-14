/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef GS2_STAMINA_CONTROL_CREATEGROUPREQUEST_HPP_
#define GS2_STAMINA_CONTROL_CREATEGROUPREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * スタミナの種類を新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateGroupRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタミナの種類名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRN */
        optional<StringHolder> overflowTriggerScriptId;
        /** スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRN */
        optional<StringHolder> overflowTriggerQueueId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            overflowTriggerScriptId(data.overflowTriggerScriptId),
            overflowTriggerQueueId(data.overflowTriggerQueueId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            overflowTriggerScriptId(std::move(data.overflowTriggerScriptId)),
            overflowTriggerQueueId(std::move(data.overflowTriggerQueueId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    CreateGroupRequest() :
        m_pData(nullptr)
    {}

    CreateGroupRequest(const CreateGroupRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateGroupRequest(CreateGroupRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateGroupRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGroupRequest& operator=(const CreateGroupRequest& createGroupRequest)
    {
        Gs2BasicRequest::operator=(createGroupRequest);
        Gs2Stamina::operator=(createGroupRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGroupRequest.m_pData);

        return *this;
    }

    CreateGroupRequest& operator=(CreateGroupRequest&& createGroupRequest)
    {
        Gs2BasicRequest::operator=(std::move(createGroupRequest));
        Gs2Stamina::operator=(std::move(createGroupRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGroupRequest.m_pData;
        createGroupRequest.m_pData = nullptr;

        return *this;
    }

    const CreateGroupRequest* operator->() const
    {
        return this;
    }

    CreateGroupRequest* operator->()
    {
        return this;
    }
    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param name スタミナの種類名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param name スタミナの種類名
     */
    CreateGroupRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    CreateGroupRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRNを取得
     *
     * @return スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRN
     */
    const optional<StringHolder>& getOverflowTriggerScriptId() const
    {
        return ensureData().overflowTriggerScriptId;
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRNを設定
     *
     * @param overflowTriggerScriptId スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRN
     */
    void setOverflowTriggerScriptId(const Char* overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(overflowTriggerScriptId);
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRNを設定
     *
     * @param overflowTriggerScriptId スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRN
     */
    CreateGroupRequest& withOverflowTriggerScriptId(const Char* overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(overflowTriggerScriptId);
        return *this;
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRNを取得
     *
     * @return スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRN
     */
    const optional<StringHolder>& getOverflowTriggerQueueId() const
    {
        return ensureData().overflowTriggerQueueId;
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRNを設定
     *
     * @param overflowTriggerQueueId スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRN
     */
    void setOverflowTriggerQueueId(const Char* overflowTriggerQueueId)
    {
        ensureData().overflowTriggerQueueId.emplace(overflowTriggerQueueId);
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRNを設定
     *
     * @param overflowTriggerQueueId スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する キュー のGRN
     */
    CreateGroupRequest& withOverflowTriggerQueueId(const Char* overflowTriggerQueueId)
    {
        ensureData().overflowTriggerQueueId.emplace(overflowTriggerQueueId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateGroupRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    CreateGroupRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    CreateGroupRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGroupRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_CREATEGROUPREQUEST_HPP_