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

#ifndef GS2_SHOWCASE_MODEL_SALESITEMGROUP_HPP_
#define GS2_SHOWCASE_MODEL_SALESITEMGROUP_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "SalesItem.hpp"
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * 商品グループ
 *
 * @author Game Server Services, Inc.
 *
 */
class SalesItemGroup : public Gs2Object
{
    friend bool operator!=(const SalesItemGroup& lhs, const SalesItemGroup& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品グループ名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** 商品リスト */
        optional<List<SalesItem>> salesItems;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            metadata(data.metadata),
            salesItems(data.salesItems)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            salesItems(std::move(data.salesItems))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "salesItems") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->salesItems.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        SalesItem item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->salesItems, std::move(item));
                    }
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
    SalesItemGroup() :
        m_pData(nullptr)
    {}

    SalesItemGroup(const SalesItemGroup& salesItemGroup) :
        Gs2Object(salesItemGroup),
        m_pData(salesItemGroup.m_pData != nullptr ? new Data(*salesItemGroup.m_pData) : nullptr)
    {}

    SalesItemGroup(SalesItemGroup&& salesItemGroup) :
        Gs2Object(std::move(salesItemGroup)),
        m_pData(salesItemGroup.m_pData)
    {
        salesItemGroup.m_pData = nullptr;
    }

    ~SalesItemGroup()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SalesItemGroup& operator=(const SalesItemGroup& salesItemGroup)
    {
        Gs2Object::operator=(salesItemGroup);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*salesItemGroup.m_pData);

        return *this;
    }

    SalesItemGroup& operator=(SalesItemGroup&& salesItemGroup)
    {
        Gs2Object::operator=(std::move(salesItemGroup));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = salesItemGroup.m_pData;
        salesItemGroup.m_pData = nullptr;

        return *this;
    }

    const SalesItemGroup* operator->() const
    {
        return this;
    }

    SalesItemGroup* operator->()
    {
        return this;
    }
    /**
     * 商品グループ名を取得
     *
     * @return 商品グループ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 商品グループ名を設定
     *
     * @param name 商品グループ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 商品グループ名を設定
     *
     * @param name 商品グループ名
     */
    SalesItemGroup& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    SalesItemGroup& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * 商品リストを取得
     *
     * @return 商品リスト
     */
    const optional<List<SalesItem>>& getSalesItems() const
    {
        return ensureData().salesItems;
    }

    /**
     * 商品リストを設定
     *
     * @param salesItems 商品リスト
     */
    void setSalesItems(const List<SalesItem>& salesItems)
    {
        ensureData().salesItems.emplace(salesItems);
    }

    /**
     * 商品リストを設定
     *
     * @param salesItems 商品リスト
     */
    SalesItemGroup& withSalesItems(const List<SalesItem>& salesItems)
    {
        setSalesItems(salesItems);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const SalesItemGroup& lhs, const SalesItemGroup& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->salesItems != lhr.m_pData->salesItems)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const SalesItemGroup& lhs, const SalesItemGroup& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_SHOWCASE_MODEL_SALESITEMGROUP_HPP_