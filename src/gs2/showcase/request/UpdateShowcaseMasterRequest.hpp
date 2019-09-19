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

#ifndef GS2_SHOWCASE_CONTROL_UPDATESHOWCASEMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_UPDATESHOWCASEMASTERREQUEST_HPP_

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
 * 陳列棚マスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateShowcaseMasterRequest : public Gs2BasicRequest, public Gs2Showcase
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 陳列棚名 */
        optional<StringHolder> showcaseName;
        /** 陳列棚マスターの説明 */
        optional<StringHolder> description;
        /** 商品のメタデータ */
        optional<StringHolder> metadata;
        /** 陳列する商品モデル一覧 */
        optional<List<DisplayItemMaster>> displayItems;
        /** 販売期間とするイベントマスター のGRN */
        optional<StringHolder> salesPeriodEventId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            showcaseName(data.showcaseName),
            description(data.description),
            metadata(data.metadata),
            salesPeriodEventId(data.salesPeriodEventId)
        {
            if (data.displayItems)
            {
                displayItems = data.displayItems->deepCopy();
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
    UpdateShowcaseMasterRequest() = default;
    UpdateShowcaseMasterRequest(const UpdateShowcaseMasterRequest& updateShowcaseMasterRequest) = default;
    UpdateShowcaseMasterRequest(UpdateShowcaseMasterRequest&& updateShowcaseMasterRequest) = default;
    ~UpdateShowcaseMasterRequest() GS2_OVERRIDE = default;

    UpdateShowcaseMasterRequest& operator=(const UpdateShowcaseMasterRequest& updateShowcaseMasterRequest) = default;
    UpdateShowcaseMasterRequest& operator=(UpdateShowcaseMasterRequest&& updateShowcaseMasterRequest) = default;

    UpdateShowcaseMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateShowcaseMasterRequest);
    }

    const UpdateShowcaseMasterRequest* operator->() const
    {
        return this;
    }

    UpdateShowcaseMasterRequest* operator->()
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
    UpdateShowcaseMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 陳列棚名を取得
     *
     * @return 陳列棚名
     */
    const optional<StringHolder>& getShowcaseName() const
    {
        return ensureData().showcaseName;
    }

    /**
     * 陳列棚名を設定
     *
     * @param showcaseName 陳列棚名
     */
    void setShowcaseName(StringHolder showcaseName)
    {
        ensureData().showcaseName.emplace(std::move(showcaseName));
    }

    /**
     * 陳列棚名を設定
     *
     * @param showcaseName 陳列棚名
     */
    UpdateShowcaseMasterRequest& withShowcaseName(StringHolder showcaseName)
    {
        ensureData().showcaseName.emplace(std::move(showcaseName));
        return *this;
    }

    /**
     * 陳列棚マスターの説明を取得
     *
     * @return 陳列棚マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 陳列棚マスターの説明を設定
     *
     * @param description 陳列棚マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 陳列棚マスターの説明を設定
     *
     * @param description 陳列棚マスターの説明
     */
    UpdateShowcaseMasterRequest& withDescription(StringHolder description)
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
    UpdateShowcaseMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 陳列する商品モデル一覧を取得
     *
     * @return 陳列する商品モデル一覧
     */
    const optional<List<DisplayItemMaster>>& getDisplayItems() const
    {
        return ensureData().displayItems;
    }

    /**
     * 陳列する商品モデル一覧を設定
     *
     * @param displayItems 陳列する商品モデル一覧
     */
    void setDisplayItems(List<DisplayItemMaster> displayItems)
    {
        ensureData().displayItems.emplace(std::move(displayItems));
    }

    /**
     * 陳列する商品モデル一覧を設定
     *
     * @param displayItems 陳列する商品モデル一覧
     */
    UpdateShowcaseMasterRequest& withDisplayItems(List<DisplayItemMaster> displayItems)
    {
        ensureData().displayItems.emplace(std::move(displayItems));
        return *this;
    }

    /**
     * 販売期間とするイベントマスター のGRNを取得
     *
     * @return 販売期間とするイベントマスター のGRN
     */
    const optional<StringHolder>& getSalesPeriodEventId() const
    {
        return ensureData().salesPeriodEventId;
    }

    /**
     * 販売期間とするイベントマスター のGRNを設定
     *
     * @param salesPeriodEventId 販売期間とするイベントマスター のGRN
     */
    void setSalesPeriodEventId(StringHolder salesPeriodEventId)
    {
        ensureData().salesPeriodEventId.emplace(std::move(salesPeriodEventId));
    }

    /**
     * 販売期間とするイベントマスター のGRNを設定
     *
     * @param salesPeriodEventId 販売期間とするイベントマスター のGRN
     */
    UpdateShowcaseMasterRequest& withSalesPeriodEventId(StringHolder salesPeriodEventId)
    {
        ensureData().salesPeriodEventId.emplace(std::move(salesPeriodEventId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateShowcaseMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateShowcaseMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_UPDATESHOWCASEMASTERREQUEST_HPP_