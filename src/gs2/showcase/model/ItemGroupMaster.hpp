/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_SHOWCASE_MODEL_ITEMGROUPMASTER_HPP_
#define GS2_SHOWCASE_MODEL_ITEMGROUPMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * 商品グループ
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemGroupMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品グループGRN */
        optional<StringHolder> itemGroupId;
        /** 商品グループ名 */
        optional<StringHolder> name;
        /** 販売している商品名のリスト */
        optional<List<StringHolder>> itemNames;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            itemGroupId(data.itemGroupId),
            name(data.name),
            itemNames(data.itemNames),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            itemGroupId(std::move(data.itemGroupId)),
            name(std::move(data.name)),
            itemNames(std::move(data.itemNames)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "itemGroupId") == 0) {
                if (jsonValue.IsString())
                {
                    this->itemGroupId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "itemNames") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->itemNames.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->itemNames += std::move(stringHolder);
                    }
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    ItemGroupMaster() :
        m_pData(nullptr)
    {}

    ItemGroupMaster(const ItemGroupMaster& itemGroupMaster) :
        Gs2Object(itemGroupMaster),
        m_pData(itemGroupMaster.m_pData != nullptr ? new Data(*itemGroupMaster.m_pData) : nullptr)
    {}

    ItemGroupMaster(ItemGroupMaster&& itemGroupMaster) :
        Gs2Object(std::move(itemGroupMaster)),
        m_pData(itemGroupMaster.m_pData)
    {
        itemGroupMaster.m_pData = nullptr;
    }

    ~ItemGroupMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ItemGroupMaster& operator=(const ItemGroupMaster& itemGroupMaster)
    {
        Gs2Object::operator=(itemGroupMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*itemGroupMaster.m_pData);

        return *this;
    }

    ItemGroupMaster& operator=(ItemGroupMaster&& itemGroupMaster)
    {
        Gs2Object::operator=(std::move(itemGroupMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = itemGroupMaster.m_pData;
        itemGroupMaster.m_pData = nullptr;

        return *this;
    }

    const ItemGroupMaster* operator->() const
    {
        return this;
    }

    ItemGroupMaster* operator->()
    {
        return this;
    }


    /**
     * 商品グループGRNを取得
     *
     * @return 商品グループGRN
     */
    const optional<StringHolder>& getItemGroupId() const
    {
        return ensureData().itemGroupId;
    }

    /**
     * 商品グループGRNを設定
     *
     * @param itemGroupId 商品グループGRN
     */
    void setItemGroupId(const Char* itemGroupId)
    {
        ensureData().itemGroupId.emplace(itemGroupId);
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
     * 販売している商品名のリストを取得
     *
     * @return 販売している商品名のリスト
     */
    const optional<List<StringHolder>>& getItemNames() const
    {
        return ensureData().itemNames;
    }

    /**
     * 販売している商品名のリストを設定
     *
     * @param itemNames 販売している商品名のリスト
     */
    void setItemNames(const List<StringHolder>& itemNames)
    {
        ensureData().itemNames.emplace(itemNames);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_MODEL_ITEMGROUPMASTER_HPP_