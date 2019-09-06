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

#ifndef GS2_INVENTORY_CONTROL_CREATENAMESPACEREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_CREATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * ネームスペースを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateNamespaceRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリー名 */
        optional<StringHolder> name;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** アイテム入手したときに実行するスクリプト */
        optional<ScriptSetting> acquireScript;
        /** 入手上限に当たって入手できなかったときに実行するスクリプト */
        optional<ScriptSetting> overflowScript;
        /** アイテム消費するときに実行するスクリプト */
        optional<ScriptSetting> consumeScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            acquireScript(data.acquireScript),
            overflowScript(data.overflowScript),
            consumeScript(data.consumeScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            acquireScript(std::move(data.acquireScript)),
            overflowScript(std::move(data.overflowScript)),
            consumeScript(std::move(data.consumeScript))
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
    CreateNamespaceRequest() :
        m_pData(nullptr)
    {}

    CreateNamespaceRequest(const CreateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inventory(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateNamespaceRequest(CreateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inventory(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateNamespaceRequest& operator=(const CreateNamespaceRequest& createNamespaceRequest)
    {
        Gs2BasicRequest::operator=(createNamespaceRequest);
        Gs2Inventory::operator=(createNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createNamespaceRequest.m_pData);

        return *this;
    }

    CreateNamespaceRequest& operator=(CreateNamespaceRequest&& createNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(createNamespaceRequest));
        Gs2Inventory::operator=(std::move(createNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createNamespaceRequest.m_pData;
        createNamespaceRequest.m_pData = nullptr;

        return *this;
    }

    const CreateNamespaceRequest* operator->() const
    {
        return this;
    }

    CreateNamespaceRequest* operator->()
    {
        return this;
    }

    /**
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カテゴリー名を設定
     *
     * @param name カテゴリー名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * カテゴリー名を設定
     *
     * @param name カテゴリー名
     */
    CreateNamespaceRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * ネームスペースの説明を取得
     *
     * @return ネームスペースの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    CreateNamespaceRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * アイテム入手したときに実行するスクリプトを取得
     *
     * @return アイテム入手したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getAcquireScript() const
    {
        return ensureData().acquireScript;
    }

    /**
     * アイテム入手したときに実行するスクリプトを設定
     *
     * @param acquireScript アイテム入手したときに実行するスクリプト
     */
    void setAcquireScript(const ScriptSetting& acquireScript)
    {
        ensureData().acquireScript.emplace(acquireScript);
    }

    /**
     * アイテム入手したときに実行するスクリプトを設定
     *
     * @param acquireScript アイテム入手したときに実行するスクリプト
     */
    CreateNamespaceRequest& withAcquireScript(const ScriptSetting& acquireScript)
    {
        ensureData().acquireScript.emplace(acquireScript);
        return *this;
    }

    /**
     * 入手上限に当たって入手できなかったときに実行するスクリプトを取得
     *
     * @return 入手上限に当たって入手できなかったときに実行するスクリプト
     */
    const optional<ScriptSetting>& getOverflowScript() const
    {
        return ensureData().overflowScript;
    }

    /**
     * 入手上限に当たって入手できなかったときに実行するスクリプトを設定
     *
     * @param overflowScript 入手上限に当たって入手できなかったときに実行するスクリプト
     */
    void setOverflowScript(const ScriptSetting& overflowScript)
    {
        ensureData().overflowScript.emplace(overflowScript);
    }

    /**
     * 入手上限に当たって入手できなかったときに実行するスクリプトを設定
     *
     * @param overflowScript 入手上限に当たって入手できなかったときに実行するスクリプト
     */
    CreateNamespaceRequest& withOverflowScript(const ScriptSetting& overflowScript)
    {
        ensureData().overflowScript.emplace(overflowScript);
        return *this;
    }

    /**
     * アイテム消費するときに実行するスクリプトを取得
     *
     * @return アイテム消費するときに実行するスクリプト
     */
    const optional<ScriptSetting>& getConsumeScript() const
    {
        return ensureData().consumeScript;
    }

    /**
     * アイテム消費するときに実行するスクリプトを設定
     *
     * @param consumeScript アイテム消費するときに実行するスクリプト
     */
    void setConsumeScript(const ScriptSetting& consumeScript)
    {
        ensureData().consumeScript.emplace(consumeScript);
    }

    /**
     * アイテム消費するときに実行するスクリプトを設定
     *
     * @param consumeScript アイテム消費するときに実行するスクリプト
     */
    CreateNamespaceRequest& withConsumeScript(const ScriptSetting& consumeScript)
    {
        ensureData().consumeScript.emplace(consumeScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateNamespaceRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_CREATENAMESPACEREQUEST_HPP_