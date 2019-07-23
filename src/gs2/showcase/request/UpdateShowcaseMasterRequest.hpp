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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ShowcaseConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            showcaseName(data.showcaseName),
            description(data.description),
            metadata(data.metadata),
            displayItems(data.displayItems),
            salesPeriodEventId(data.salesPeriodEventId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            showcaseName(std::move(data.showcaseName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            displayItems(std::move(data.displayItems)),
            salesPeriodEventId(std::move(data.salesPeriodEventId))
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
    UpdateShowcaseMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateShowcaseMasterRequest(const UpdateShowcaseMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Showcase(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateShowcaseMasterRequest(UpdateShowcaseMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Showcase(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateShowcaseMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateShowcaseMasterRequest& operator=(const UpdateShowcaseMasterRequest& updateShowcaseMasterRequest)
    {
        Gs2BasicRequest::operator=(updateShowcaseMasterRequest);
        Gs2Showcase::operator=(updateShowcaseMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateShowcaseMasterRequest.m_pData);

        return *this;
    }

    UpdateShowcaseMasterRequest& operator=(UpdateShowcaseMasterRequest&& updateShowcaseMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateShowcaseMasterRequest));
        Gs2Showcase::operator=(std::move(updateShowcaseMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateShowcaseMasterRequest.m_pData;
        updateShowcaseMasterRequest.m_pData = nullptr;

        return *this;
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateShowcaseMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
    }

    /**
     * 陳列棚名を設定
     *
     * @param showcaseName 陳列棚名
     */
    UpdateShowcaseMasterRequest& withShowcaseName(const Char* showcaseName)
    {
        ensureData().showcaseName.emplace(showcaseName);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 陳列棚マスターの説明を設定
     *
     * @param description 陳列棚マスターの説明
     */
    UpdateShowcaseMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 商品のメタデータを設定
     *
     * @param metadata 商品のメタデータ
     */
    UpdateShowcaseMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
    void setDisplayItems(const List<DisplayItemMaster>& displayItems)
    {
        ensureData().displayItems.emplace(displayItems);
    }

    /**
     * 陳列する商品モデル一覧を設定
     *
     * @param displayItems 陳列する商品モデル一覧
     */
    UpdateShowcaseMasterRequest& withDisplayItems(const List<DisplayItemMaster>& displayItems)
    {
        ensureData().displayItems.emplace(displayItems);
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
    void setSalesPeriodEventId(const Char* salesPeriodEventId)
    {
        ensureData().salesPeriodEventId.emplace(salesPeriodEventId);
    }

    /**
     * 販売期間とするイベントマスター のGRNを設定
     *
     * @param salesPeriodEventId 販売期間とするイベントマスター のGRN
     */
    UpdateShowcaseMasterRequest& withSalesPeriodEventId(const Char* salesPeriodEventId)
    {
        ensureData().salesPeriodEventId.emplace(salesPeriodEventId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateShowcaseMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateShowcaseMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateShowcaseMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateShowcaseMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SHOWCASE_CONTROL_UPDATESHOWCASEMASTERREQUEST_HPP_