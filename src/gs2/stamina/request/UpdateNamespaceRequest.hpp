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

#ifndef GS2_STAMINA_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_STAMINA_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 説明文 */
        optional<StringHolder> description;
        /** スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRN */
        optional<StringHolder> overflowTriggerScriptId;
        /** スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する ネームスペース のGRN */
        optional<StringHolder> overflowTriggerNamespaceId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            description(data.description),
            overflowTriggerScriptId(data.overflowTriggerScriptId),
            overflowTriggerNamespaceId(data.overflowTriggerNamespaceId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            description(std::move(data.description)),
            overflowTriggerScriptId(std::move(data.overflowTriggerScriptId)),
            overflowTriggerNamespaceId(std::move(data.overflowTriggerNamespaceId))
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
    UpdateNamespaceRequest() :
        m_pData(nullptr)
    {}

    UpdateNamespaceRequest(const UpdateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateNamespaceRequest(UpdateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(updateNamespaceRequest);
        Gs2Stamina::operator=(updateNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateNamespaceRequest.m_pData);

        return *this;
    }

    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateNamespaceRequest));
        Gs2Stamina::operator=(std::move(updateNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateNamespaceRequest.m_pData;
        updateNamespaceRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateNamespaceRequest* operator->() const
    {
        return this;
    }

    UpdateNamespaceRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateNamespaceRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    UpdateNamespaceRequest& withDescription(const Char* description)
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
    UpdateNamespaceRequest& withOverflowTriggerScriptId(const Char* overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(overflowTriggerScriptId);
        return *this;
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する ネームスペース のGRNを取得
     *
     * @return スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する ネームスペース のGRN
     */
    const optional<StringHolder>& getOverflowTriggerNamespaceId() const
    {
        return ensureData().overflowTriggerNamespaceId;
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する ネームスペース のGRNを設定
     *
     * @param overflowTriggerNamespaceId スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する ネームスペース のGRN
     */
    void setOverflowTriggerNamespaceId(const Char* overflowTriggerNamespaceId)
    {
        ensureData().overflowTriggerNamespaceId.emplace(overflowTriggerNamespaceId);
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する ネームスペース のGRNを設定
     *
     * @param overflowTriggerNamespaceId スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する ネームスペース のGRN
     */
    UpdateNamespaceRequest& withOverflowTriggerNamespaceId(const Char* overflowTriggerNamespaceId)
    {
        ensureData().overflowTriggerNamespaceId.emplace(overflowTriggerNamespaceId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_UPDATENAMESPACEREQUEST_HPP_