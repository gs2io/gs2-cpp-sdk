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

#ifndef GS2_INVENTORY_MODEL_ITEMSETGROUP_HPP_
#define GS2_INVENTORY_MODEL_ITEMSETGROUP_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace inventory {

/**
 * 有効期限ごとのアイテム所持数量 (このモデルは SDK では使用されません)
 *
 * @author Game Server Services, Inc.
 *
 */
class ItemSetGroup : public Gs2Object
{
    friend bool operator!=(const ItemSetGroup& lhs, const ItemSetGroup& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 有効期限ごとのアイテム所持数量 (このモデルは SDK では使用されません) */
        optional<StringHolder> itemSetGroupId;
        /** インベントリの名前 */
        optional<StringHolder> inventoryName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** アイテムマスターの名前 */
        optional<StringHolder> itemName;
        /** 表示順番 */
        optional<Int32> sortValue;
        /** アイテムセットIDのリスト */
        optional<List<StringHolder>> itemSetItemSetIdList;
        /** アイテムセットを識別する名前のリスト */
        optional<List<StringHolder>> itemSetNameList;
        /** 所持数量のリスト */
        optional<List<Int64>> itemSetCountList;
        /** 参照元のリストのリスト */
        optional<List<List<StringHolder>>> itemSetReferenceOfList;
        /** 有効期限のリスト */
        optional<List<Int64>> itemSetExpiresAtList;
        /** 作成日時のリスト */
        optional<List<Int64>> itemSetCreatedAtList;
        /** 更新日時のリスト */
        optional<List<Int64>> itemSetUpdatedAtList;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            itemSetGroupId(data.itemSetGroupId),
            inventoryName(data.inventoryName),
            userId(data.userId),
            itemName(data.itemName),
            sortValue(data.sortValue),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.itemSetItemSetIdList)
            {
                itemSetItemSetIdList = data.itemSetItemSetIdList->deepCopy();
            }
            if (data.itemSetNameList)
            {
                itemSetNameList = data.itemSetNameList->deepCopy();
            }
            if (data.itemSetCountList)
            {
                itemSetCountList = data.itemSetCountList->deepCopy();
            }
            if (data.itemSetReferenceOfList)
            {
                itemSetReferenceOfList = data.itemSetReferenceOfList->deepCopy();
            }
            if (data.itemSetExpiresAtList)
            {
                itemSetExpiresAtList = data.itemSetExpiresAtList->deepCopy();
            }
            if (data.itemSetCreatedAtList)
            {
                itemSetCreatedAtList = data.itemSetCreatedAtList->deepCopy();
            }
            if (data.itemSetUpdatedAtList)
            {
                itemSetUpdatedAtList = data.itemSetUpdatedAtList->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "itemSetGroupId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->itemSetGroupId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "inventoryName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->inventoryName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "itemName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->itemName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "sortValue") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->sortValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "itemSetItemSetIdList") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->itemSetItemSetIdList.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->itemSetItemSetIdList += std::move(stringHolder);
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "itemSetNameList") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->itemSetNameList.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->itemSetNameList += std::move(stringHolder);
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "itemSetCountList") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->itemSetCountList.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsInt64())
                        {
                            *this->itemSetCountList += json->GetInt64();
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "itemSetReferenceOfList") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->itemSetReferenceOfList.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        List<StringHolder> item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->itemSetReferenceOfList += std::move(item_);
                    }
                }
            }
            else if (std::strcmp(name_, "itemSetExpiresAtList") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->itemSetExpiresAtList.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsInt64())
                        {
                            *this->itemSetExpiresAtList += json->GetInt64();
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "itemSetCreatedAtList") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->itemSetCreatedAtList.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsInt64())
                        {
                            *this->itemSetCreatedAtList += json->GetInt64();
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "itemSetUpdatedAtList") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->itemSetUpdatedAtList.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsInt64())
                        {
                            *this->itemSetUpdatedAtList += json->GetInt64();
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ItemSetGroup() = default;
    ItemSetGroup(const ItemSetGroup& itemSetGroup) = default;
    ItemSetGroup(ItemSetGroup&& itemSetGroup) = default;
    ~ItemSetGroup() = default;

    ItemSetGroup& operator=(const ItemSetGroup& itemSetGroup) = default;
    ItemSetGroup& operator=(ItemSetGroup&& itemSetGroup) = default;

    ItemSetGroup deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ItemSetGroup);
    }

    const ItemSetGroup* operator->() const
    {
        return this;
    }

    ItemSetGroup* operator->()
    {
        return this;
    }
    /**
     * 有効期限ごとのアイテム所持数量 (このモデルは SDK では使用されません)を取得
     *
     * @return 有効期限ごとのアイテム所持数量 (このモデルは SDK では使用されません)
     */
    const optional<StringHolder>& getItemSetGroupId() const
    {
        return ensureData().itemSetGroupId;
    }

    /**
     * 有効期限ごとのアイテム所持数量 (このモデルは SDK では使用されません)を設定
     *
     * @param itemSetGroupId 有効期限ごとのアイテム所持数量 (このモデルは SDK では使用されません)
     */
    void setItemSetGroupId(StringHolder itemSetGroupId)
    {
        ensureData().itemSetGroupId.emplace(std::move(itemSetGroupId));
    }

    /**
     * 有効期限ごとのアイテム所持数量 (このモデルは SDK では使用されません)を設定
     *
     * @param itemSetGroupId 有効期限ごとのアイテム所持数量 (このモデルは SDK では使用されません)
     */
    ItemSetGroup& withItemSetGroupId(StringHolder itemSetGroupId)
    {
        setItemSetGroupId(std::move(itemSetGroupId));
        return *this;
    }

    /**
     * インベントリの名前を取得
     *
     * @return インベントリの名前
     */
    const optional<StringHolder>& getInventoryName() const
    {
        return ensureData().inventoryName;
    }

    /**
     * インベントリの名前を設定
     *
     * @param inventoryName インベントリの名前
     */
    void setInventoryName(StringHolder inventoryName)
    {
        ensureData().inventoryName.emplace(std::move(inventoryName));
    }

    /**
     * インベントリの名前を設定
     *
     * @param inventoryName インベントリの名前
     */
    ItemSetGroup& withInventoryName(StringHolder inventoryName)
    {
        setInventoryName(std::move(inventoryName));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    ItemSetGroup& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * アイテムマスターの名前を取得
     *
     * @return アイテムマスターの名前
     */
    const optional<StringHolder>& getItemName() const
    {
        return ensureData().itemName;
    }

    /**
     * アイテムマスターの名前を設定
     *
     * @param itemName アイテムマスターの名前
     */
    void setItemName(StringHolder itemName)
    {
        ensureData().itemName.emplace(std::move(itemName));
    }

    /**
     * アイテムマスターの名前を設定
     *
     * @param itemName アイテムマスターの名前
     */
    ItemSetGroup& withItemName(StringHolder itemName)
    {
        setItemName(std::move(itemName));
        return *this;
    }

    /**
     * 表示順番を取得
     *
     * @return 表示順番
     */
    const optional<Int32>& getSortValue() const
    {
        return ensureData().sortValue;
    }

    /**
     * 表示順番を設定
     *
     * @param sortValue 表示順番
     */
    void setSortValue(Int32 sortValue)
    {
        ensureData().sortValue.emplace(sortValue);
    }

    /**
     * 表示順番を設定
     *
     * @param sortValue 表示順番
     */
    ItemSetGroup& withSortValue(Int32 sortValue)
    {
        setSortValue(sortValue);
        return *this;
    }

    /**
     * アイテムセットIDのリストを取得
     *
     * @return アイテムセットIDのリスト
     */
    const optional<List<StringHolder>>& getItemSetItemSetIdList() const
    {
        return ensureData().itemSetItemSetIdList;
    }

    /**
     * アイテムセットIDのリストを設定
     *
     * @param itemSetItemSetIdList アイテムセットIDのリスト
     */
    void setItemSetItemSetIdList(List<StringHolder> itemSetItemSetIdList)
    {
        ensureData().itemSetItemSetIdList.emplace(std::move(itemSetItemSetIdList));
    }

    /**
     * アイテムセットIDのリストを設定
     *
     * @param itemSetItemSetIdList アイテムセットIDのリスト
     */
    ItemSetGroup& withItemSetItemSetIdList(List<StringHolder> itemSetItemSetIdList)
    {
        setItemSetItemSetIdList(std::move(itemSetItemSetIdList));
        return *this;
    }

    /**
     * アイテムセットを識別する名前のリストを取得
     *
     * @return アイテムセットを識別する名前のリスト
     */
    const optional<List<StringHolder>>& getItemSetNameList() const
    {
        return ensureData().itemSetNameList;
    }

    /**
     * アイテムセットを識別する名前のリストを設定
     *
     * @param itemSetNameList アイテムセットを識別する名前のリスト
     */
    void setItemSetNameList(List<StringHolder> itemSetNameList)
    {
        ensureData().itemSetNameList.emplace(std::move(itemSetNameList));
    }

    /**
     * アイテムセットを識別する名前のリストを設定
     *
     * @param itemSetNameList アイテムセットを識別する名前のリスト
     */
    ItemSetGroup& withItemSetNameList(List<StringHolder> itemSetNameList)
    {
        setItemSetNameList(std::move(itemSetNameList));
        return *this;
    }

    /**
     * 所持数量のリストを取得
     *
     * @return 所持数量のリスト
     */
    const optional<List<Int64>>& getItemSetCountList() const
    {
        return ensureData().itemSetCountList;
    }

    /**
     * 所持数量のリストを設定
     *
     * @param itemSetCountList 所持数量のリスト
     */
    void setItemSetCountList(List<Int64> itemSetCountList)
    {
        ensureData().itemSetCountList.emplace(std::move(itemSetCountList));
    }

    /**
     * 所持数量のリストを設定
     *
     * @param itemSetCountList 所持数量のリスト
     */
    ItemSetGroup& withItemSetCountList(List<Int64> itemSetCountList)
    {
        setItemSetCountList(std::move(itemSetCountList));
        return *this;
    }

    /**
     * 参照元のリストのリストを取得
     *
     * @return 参照元のリストのリスト
     */
    const optional<List<List<StringHolder>>>& getItemSetReferenceOfList() const
    {
        return ensureData().itemSetReferenceOfList;
    }

    /**
     * 参照元のリストのリストを設定
     *
     * @param itemSetReferenceOfList 参照元のリストのリスト
     */
    void setItemSetReferenceOfList(List<List<StringHolder>> itemSetReferenceOfList)
    {
        ensureData().itemSetReferenceOfList.emplace(std::move(itemSetReferenceOfList));
    }

    /**
     * 参照元のリストのリストを設定
     *
     * @param itemSetReferenceOfList 参照元のリストのリスト
     */
    ItemSetGroup& withItemSetReferenceOfList(List<List<StringHolder>> itemSetReferenceOfList)
    {
        setItemSetReferenceOfList(std::move(itemSetReferenceOfList));
        return *this;
    }

    /**
     * 有効期限のリストを取得
     *
     * @return 有効期限のリスト
     */
    const optional<List<Int64>>& getItemSetExpiresAtList() const
    {
        return ensureData().itemSetExpiresAtList;
    }

    /**
     * 有効期限のリストを設定
     *
     * @param itemSetExpiresAtList 有効期限のリスト
     */
    void setItemSetExpiresAtList(List<Int64> itemSetExpiresAtList)
    {
        ensureData().itemSetExpiresAtList.emplace(std::move(itemSetExpiresAtList));
    }

    /**
     * 有効期限のリストを設定
     *
     * @param itemSetExpiresAtList 有効期限のリスト
     */
    ItemSetGroup& withItemSetExpiresAtList(List<Int64> itemSetExpiresAtList)
    {
        setItemSetExpiresAtList(std::move(itemSetExpiresAtList));
        return *this;
    }

    /**
     * 作成日時のリストを取得
     *
     * @return 作成日時のリスト
     */
    const optional<List<Int64>>& getItemSetCreatedAtList() const
    {
        return ensureData().itemSetCreatedAtList;
    }

    /**
     * 作成日時のリストを設定
     *
     * @param itemSetCreatedAtList 作成日時のリスト
     */
    void setItemSetCreatedAtList(List<Int64> itemSetCreatedAtList)
    {
        ensureData().itemSetCreatedAtList.emplace(std::move(itemSetCreatedAtList));
    }

    /**
     * 作成日時のリストを設定
     *
     * @param itemSetCreatedAtList 作成日時のリスト
     */
    ItemSetGroup& withItemSetCreatedAtList(List<Int64> itemSetCreatedAtList)
    {
        setItemSetCreatedAtList(std::move(itemSetCreatedAtList));
        return *this;
    }

    /**
     * 更新日時のリストを取得
     *
     * @return 更新日時のリスト
     */
    const optional<List<Int64>>& getItemSetUpdatedAtList() const
    {
        return ensureData().itemSetUpdatedAtList;
    }

    /**
     * 更新日時のリストを設定
     *
     * @param itemSetUpdatedAtList 更新日時のリスト
     */
    void setItemSetUpdatedAtList(List<Int64> itemSetUpdatedAtList)
    {
        ensureData().itemSetUpdatedAtList.emplace(std::move(itemSetUpdatedAtList));
    }

    /**
     * 更新日時のリストを設定
     *
     * @param itemSetUpdatedAtList 更新日時のリスト
     */
    ItemSetGroup& withItemSetUpdatedAtList(List<Int64> itemSetUpdatedAtList)
    {
        setItemSetUpdatedAtList(std::move(itemSetUpdatedAtList));
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
    ItemSetGroup& withCreatedAt(Int64 createdAt)
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
    ItemSetGroup& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ItemSetGroup& lhs, const ItemSetGroup& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->itemSetGroupId != lhr.m_pData->itemSetGroupId)
        {
            return true;
        }
        if (lhs.m_pData->inventoryName != lhr.m_pData->inventoryName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->itemName != lhr.m_pData->itemName)
        {
            return true;
        }
        if (lhs.m_pData->sortValue != lhr.m_pData->sortValue)
        {
            return true;
        }
        if (lhs.m_pData->itemSetItemSetIdList != lhr.m_pData->itemSetItemSetIdList)
        {
            return true;
        }
        if (lhs.m_pData->itemSetNameList != lhr.m_pData->itemSetNameList)
        {
            return true;
        }
        if (lhs.m_pData->itemSetCountList != lhr.m_pData->itemSetCountList)
        {
            return true;
        }
        if (lhs.m_pData->itemSetReferenceOfList != lhr.m_pData->itemSetReferenceOfList)
        {
            return true;
        }
        if (lhs.m_pData->itemSetExpiresAtList != lhr.m_pData->itemSetExpiresAtList)
        {
            return true;
        }
        if (lhs.m_pData->itemSetCreatedAtList != lhr.m_pData->itemSetCreatedAtList)
        {
            return true;
        }
        if (lhs.m_pData->itemSetUpdatedAtList != lhr.m_pData->itemSetUpdatedAtList)
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

inline bool operator==(const ItemSetGroup& lhs, const ItemSetGroup& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INVENTORY_MODEL_ITEMSETGROUP_HPP_