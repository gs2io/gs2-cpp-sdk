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

#ifndef GS2_SHOWCASE_MODEL_SHOWCASEMASTER_HPP_
#define GS2_SHOWCASE_MODEL_SHOWCASEMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "DisplayItemMaster.hpp"
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * 陳列棚マスター
 *
 * @author Game Server Services, Inc.
 *
 */
class ShowcaseMaster : public Gs2Object
{
    friend bool operator!=(const ShowcaseMaster& lhs, const ShowcaseMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列棚マスター */
        optional<StringHolder> showcaseId;
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            showcaseId(data.showcaseId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            displayItems(data.displayItems),
            salesPeriodEventId(data.salesPeriodEventId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            showcaseId(std::move(data.showcaseId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            displayItems(std::move(data.displayItems)),
            salesPeriodEventId(std::move(data.salesPeriodEventId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "showcaseId") == 0) {
                if (jsonValue.IsString())
                {
                    this->showcaseId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "displayItems") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->displayItems.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        DisplayItemMaster item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->displayItems, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "salesPeriodEventId") == 0) {
                if (jsonValue.IsString())
                {
                    this->salesPeriodEventId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
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
    ShowcaseMaster() :
        m_pData(nullptr)
    {}

    ShowcaseMaster(const ShowcaseMaster& showcaseMaster) :
        Gs2Object(showcaseMaster),
        m_pData(showcaseMaster.m_pData != nullptr ? new Data(*showcaseMaster.m_pData) : nullptr)
    {}

    ShowcaseMaster(ShowcaseMaster&& showcaseMaster) :
        Gs2Object(std::move(showcaseMaster)),
        m_pData(showcaseMaster.m_pData)
    {
        showcaseMaster.m_pData = nullptr;
    }

    ~ShowcaseMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ShowcaseMaster& operator=(const ShowcaseMaster& showcaseMaster)
    {
        Gs2Object::operator=(showcaseMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*showcaseMaster.m_pData);

        return *this;
    }

    ShowcaseMaster& operator=(ShowcaseMaster&& showcaseMaster)
    {
        Gs2Object::operator=(std::move(showcaseMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = showcaseMaster.m_pData;
        showcaseMaster.m_pData = nullptr;

        return *this;
    }

    const ShowcaseMaster* operator->() const
    {
        return this;
    }

    ShowcaseMaster* operator->()
    {
        return this;
    }
    /**
     * 陳列棚マスターを取得
     *
     * @return 陳列棚マスター
     */
    const optional<StringHolder>& getShowcaseId() const
    {
        return ensureData().showcaseId;
    }

    /**
     * 陳列棚マスターを設定
     *
     * @param showcaseId 陳列棚マスター
     */
    void setShowcaseId(const Char* showcaseId)
    {
        ensureData().showcaseId.emplace(showcaseId);
    }

    /**
     * 陳列棚マスターを設定
     *
     * @param showcaseId 陳列棚マスター
     */
    ShowcaseMaster& withShowcaseId(const Char* showcaseId)
    {
        setShowcaseId(showcaseId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 陳列棚名を設定
     *
     * @param name 陳列棚名
     */
    ShowcaseMaster& withName(const Char* name)
    {
        setName(name);
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
    ShowcaseMaster& withDescription(const Char* description)
    {
        setDescription(description);
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
    ShowcaseMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    ShowcaseMaster& withDisplayItems(const List<DisplayItemMaster>& displayItems)
    {
        setDisplayItems(displayItems);
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
    ShowcaseMaster& withSalesPeriodEventId(const Char* salesPeriodEventId)
    {
        setSalesPeriodEventId(salesPeriodEventId);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    ShowcaseMaster& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    ShowcaseMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ShowcaseMaster& lhs, const ShowcaseMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->showcaseId != lhr.m_pData->showcaseId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->displayItems != lhr.m_pData->displayItems)
        {
            return true;
        }
        if (lhs.m_pData->salesPeriodEventId != lhr.m_pData->salesPeriodEventId)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const ShowcaseMaster& lhs, const ShowcaseMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SHOWCASEMASTER_HPP_