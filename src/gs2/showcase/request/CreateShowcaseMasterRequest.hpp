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

#ifndef GS2_SHOWCASE_CONTROL_CREATESHOWCASEMASTERREQUEST_HPP_
#define GS2_SHOWCASE_CONTROL_CREATESHOWCASEMASTERREQUEST_HPP_

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
 * 陳列棚マスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateShowcaseMasterRequest : public Gs2BasicRequest, public Gs2Showcase
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
        optional<StringHolder> name;
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
            name(data.name),
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
    CreateShowcaseMasterRequest() = default;
    CreateShowcaseMasterRequest(const CreateShowcaseMasterRequest& createShowcaseMasterRequest) = default;
    CreateShowcaseMasterRequest(CreateShowcaseMasterRequest&& createShowcaseMasterRequest) = default;
    ~CreateShowcaseMasterRequest() GS2_OVERRIDE = default;

    CreateShowcaseMasterRequest& operator=(const CreateShowcaseMasterRequest& createShowcaseMasterRequest) = default;
    CreateShowcaseMasterRequest& operator=(CreateShowcaseMasterRequest&& createShowcaseMasterRequest) = default;

    CreateShowcaseMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateShowcaseMasterRequest);
    }

    const CreateShowcaseMasterRequest* operator->() const
    {
        return this;
    }

    CreateShowcaseMasterRequest* operator->()
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
    CreateShowcaseMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 陳列棚名を取得
     *
     * @return 陳列棚名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 陳列棚名を設定
     *
     * @param name 陳列棚名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 陳列棚名を設定
     *
     * @param name 陳列棚名
     */
    CreateShowcaseMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    CreateShowcaseMasterRequest& withDescription(StringHolder description)
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
    CreateShowcaseMasterRequest& withMetadata(StringHolder metadata)
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
    CreateShowcaseMasterRequest& withDisplayItems(List<DisplayItemMaster> displayItems)
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
    CreateShowcaseMasterRequest& withSalesPeriodEventId(StringHolder salesPeriodEventId)
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
    CreateShowcaseMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateShowcaseMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_CREATESHOWCASEMASTERREQUEST_HPP_