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

#ifndef GS2_SHOWCASE_CONTROL_UPDATESALESITEMMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_UPDATESALESITEMMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace showcase
{

/**
 * 商品マスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateSalesItemMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 商品名 */
        optional<StringHolder> salesItemName;
        /** 商品マスターの説明 */
        optional<StringHolder> description;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** 消費アクションリスト */
        optional<List<ConsumeAction>> consumeActions;
        /** 入手アクションリスト */
        optional<List<AcquireAction>> acquireActions;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            salesItemName(data.salesItemName),
            description(data.description),
            metadata(data.metadata)
        {
            if (data.consumeActions)
            {
                consumeActions = data.consumeActions->deepCopy();
            }
            if (data.acquireActions)
            {
                acquireActions = data.acquireActions->deepCopy();
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
    UpdateSalesItemMasterRequest() = default;
    UpdateSalesItemMasterRequest(const UpdateSalesItemMasterRequest& updateSalesItemMasterRequest) = default;
    UpdateSalesItemMasterRequest(UpdateSalesItemMasterRequest&& updateSalesItemMasterRequest) = default;
    ~UpdateSalesItemMasterRequest() GS2_OVERRIDE = default;

    UpdateSalesItemMasterRequest& operator=(const UpdateSalesItemMasterRequest& updateSalesItemMasterRequest) = default;
    UpdateSalesItemMasterRequest& operator=(UpdateSalesItemMasterRequest&& updateSalesItemMasterRequest) = default;

    UpdateSalesItemMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateSalesItemMasterRequest);
    }

    const UpdateSalesItemMasterRequest* operator->() const
    {
        return this;
    }

    UpdateSalesItemMasterRequest* operator->()
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
    UpdateSalesItemMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 商品名を取得
     *
     * @return 商品名
     */
    const optional<StringHolder>& getSalesItemName() const
    {
        return ensureData().salesItemName;
    }

    /**
     * 商品名を設定
     *
     * @param salesItemName 商品名
     */
    void setSalesItemName(StringHolder salesItemName)
    {
        ensureData().salesItemName.emplace(std::move(salesItemName));
    }

    /**
     * 商品名を設定
     *
     * @param salesItemName 商品名
     */
    UpdateSalesItemMasterRequest& withSalesItemName(StringHolder salesItemName)
    {
        ensureData().salesItemName.emplace(std::move(salesItemName));
        return *this;
    }

    /**
     * 商品マスターの説明を取得
     *
     * @return 商品マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 商品マスターの説明を設定
     *
     * @param description 商品マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 商品マスターの説明を設定
     *
     * @param description 商品マスターの説明
     */
    UpdateSalesItemMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 商品のメタデータを取得
     *
     * @return 商品のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    UpdateSalesItemMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 消費アクションリストを取得
     *
     * @return 消費アクションリスト
     */
    const optional<List<ConsumeAction>>& getConsumeActions() const
    {
        return ensureData().consumeActions;
    }

    /**
     * 消費アクションリストを設定
     *
     * @param consumeActions 消費アクションリスト
     */
    void setConsumeActions(List<ConsumeAction> consumeActions)
    {
        ensureData().consumeActions.emplace(std::move(consumeActions));
    }

    /**
     * 消費アクションリストを設定
     *
     * @param consumeActions 消費アクションリスト
     */
    UpdateSalesItemMasterRequest& withConsumeActions(List<ConsumeAction> consumeActions)
    {
        ensureData().consumeActions.emplace(std::move(consumeActions));
        return *this;
    }

    /**
     * 入手アクションリストを取得
     *
     * @return 入手アクションリスト
     */
    const optional<List<AcquireAction>>& getAcquireActions() const
    {
        return ensureData().acquireActions;
    }

    /**
     * 入手アクションリストを設定
     *
     * @param acquireActions 入手アクションリスト
     */
    void setAcquireActions(List<AcquireAction> acquireActions)
    {
        ensureData().acquireActions.emplace(std::move(acquireActions));
    }

    /**
     * 入手アクションリストを設定
     *
     * @param acquireActions 入手アクションリスト
     */
    UpdateSalesItemMasterRequest& withAcquireActions(List<AcquireAction> acquireActions)
    {
        ensureData().acquireActions.emplace(std::move(acquireActions));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateSalesItemMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateSalesItemMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_UPDATESALESITEMMASTERREQUEST_HPP_