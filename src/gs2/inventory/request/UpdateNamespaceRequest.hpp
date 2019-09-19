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

#ifndef GS2_INVENTORY_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_INVENTORY_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InventoryConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace inventory
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Inventory
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** カテゴリー名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** アイテム入手したときに実行するスクリプト */
        optional<ScriptSetting> acquireScript;
        /** 入手上限に当たって入手できなかったときに実行するスクリプト */
        optional<ScriptSetting> overflowScript;
        /** アイテム消費するときに実行するスクリプト */
        optional<ScriptSetting> consumeScript;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description)
        {
            if (data.acquireScript)
            {
                acquireScript = data.acquireScript->deepCopy();
            }
            if (data.overflowScript)
            {
                overflowScript = data.overflowScript->deepCopy();
            }
            if (data.consumeScript)
            {
                consumeScript = data.consumeScript->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    UpdateNamespaceRequest() = default;
    UpdateNamespaceRequest(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest(UpdateNamespaceRequest&& updateNamespaceRequest) = default;
    ~UpdateNamespaceRequest() GS2_OVERRIDE = default;

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest) = default;

    UpdateNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateNamespaceRequest);
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
     * カテゴリー名を取得
     *
     * @return カテゴリー名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリー名を設定
     *
     * @param namespaceName カテゴリー名
     */
    UpdateNamespaceRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    UpdateNamespaceRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setAcquireScript(ScriptSetting acquireScript)
    {
        ensureData().acquireScript.emplace(std::move(acquireScript));
    }

    /**
     * アイテム入手したときに実行するスクリプトを設定
     *
     * @param acquireScript アイテム入手したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withAcquireScript(ScriptSetting acquireScript)
    {
        ensureData().acquireScript.emplace(std::move(acquireScript));
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
    void setOverflowScript(ScriptSetting overflowScript)
    {
        ensureData().overflowScript.emplace(std::move(overflowScript));
    }

    /**
     * 入手上限に当たって入手できなかったときに実行するスクリプトを設定
     *
     * @param overflowScript 入手上限に当たって入手できなかったときに実行するスクリプト
     */
    UpdateNamespaceRequest& withOverflowScript(ScriptSetting overflowScript)
    {
        ensureData().overflowScript.emplace(std::move(overflowScript));
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
    void setConsumeScript(ScriptSetting consumeScript)
    {
        ensureData().consumeScript.emplace(std::move(consumeScript));
    }

    /**
     * アイテム消費するときに実行するスクリプトを設定
     *
     * @param consumeScript アイテム消費するときに実行するスクリプト
     */
    UpdateNamespaceRequest& withConsumeScript(ScriptSetting consumeScript)
    {
        ensureData().consumeScript.emplace(std::move(consumeScript));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_UPDATENAMESPACEREQUEST_HPP_