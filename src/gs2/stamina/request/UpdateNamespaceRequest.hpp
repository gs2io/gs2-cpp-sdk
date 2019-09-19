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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            overflowTriggerScriptId(data.overflowTriggerScriptId),
            overflowTriggerNamespaceId(data.overflowTriggerNamespaceId)
        {
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateNamespaceRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateNamespaceRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setOverflowTriggerScriptId(StringHolder overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(std::move(overflowTriggerScriptId));
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRNを設定
     *
     * @param overflowTriggerScriptId スタミナオーバーフロー上限に当たって回復できなかったスタミナを通知する スクリプト のGRN
     */
    UpdateNamespaceRequest& withOverflowTriggerScriptId(StringHolder overflowTriggerScriptId)
    {
        ensureData().overflowTriggerScriptId.emplace(std::move(overflowTriggerScriptId));
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
    void setOverflowTriggerNamespaceId(StringHolder overflowTriggerNamespaceId)
    {
        ensureData().overflowTriggerNamespaceId.emplace(std::move(overflowTriggerNamespaceId));
    }

    /**
     * スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する ネームスペース のGRNを設定
     *
     * @param overflowTriggerNamespaceId スタミナオーバーフロー上限に当たって回復できなかったスタミナを追加する ネームスペース のGRN
     */
    UpdateNamespaceRequest& withOverflowTriggerNamespaceId(StringHolder overflowTriggerNamespaceId)
    {
        ensureData().overflowTriggerNamespaceId.emplace(std::move(overflowTriggerNamespaceId));
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

#endif //GS2_STAMINA_CONTROL_UPDATENAMESPACEREQUEST_HPP_