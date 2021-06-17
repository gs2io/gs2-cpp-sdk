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

#ifndef GS2_LOTTERY_MODEL_BOXITEMS_HPP_
#define GS2_LOTTERY_MODEL_BOXITEMS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "BoxItem.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * ボックスから取り出したアイテムのリスト
 *
 * @author Game Server Services, Inc.
 *
 */
class BoxItems : public Gs2Object
{
    friend bool operator!=(const BoxItems& lhs, const BoxItems& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ボックス */
        optional<StringHolder> boxId;
        /** 排出確率テーブル名 */
        optional<StringHolder> prizeTableName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** ボックスから取り出したアイテムのリスト */
        optional<List<BoxItem>> items;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            boxId(data.boxId),
            prizeTableName(data.prizeTableName),
            userId(data.userId)
        {
            if (data.items)
            {
                items = data.items->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "boxId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->boxId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "prizeTableName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->prizeTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "items") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        BoxItem item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->items += std::move(item_);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    BoxItems() = default;
    BoxItems(const BoxItems& boxItems) = default;
    BoxItems(BoxItems&& boxItems) = default;
    ~BoxItems() = default;

    BoxItems& operator=(const BoxItems& boxItems) = default;
    BoxItems& operator=(BoxItems&& boxItems) = default;

    BoxItems deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(BoxItems);
    }

    const BoxItems* operator->() const
    {
        return this;
    }

    BoxItems* operator->()
    {
        return this;
    }
    /**
     * ボックスを取得
     *
     * @return ボックス
     */
    const optional<StringHolder>& getBoxId() const
    {
        return ensureData().boxId;
    }

    /**
     * ボックスを設定
     *
     * @param boxId ボックス
     */
    void setBoxId(StringHolder boxId)
    {
        ensureData().boxId.emplace(std::move(boxId));
    }

    /**
     * ボックスを設定
     *
     * @param boxId ボックス
     */
    BoxItems& withBoxId(StringHolder boxId)
    {
        setBoxId(std::move(boxId));
        return *this;
    }

    /**
     * 排出確率テーブル名を取得
     *
     * @return 排出確率テーブル名
     */
    const optional<StringHolder>& getPrizeTableName() const
    {
        return ensureData().prizeTableName;
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param prizeTableName 排出確率テーブル名
     */
    void setPrizeTableName(StringHolder prizeTableName)
    {
        ensureData().prizeTableName.emplace(std::move(prizeTableName));
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param prizeTableName 排出確率テーブル名
     */
    BoxItems& withPrizeTableName(StringHolder prizeTableName)
    {
        setPrizeTableName(std::move(prizeTableName));
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
    BoxItems& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * ボックスから取り出したアイテムのリストを取得
     *
     * @return ボックスから取り出したアイテムのリスト
     */
    const optional<List<BoxItem>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * ボックスから取り出したアイテムのリストを設定
     *
     * @param items ボックスから取り出したアイテムのリスト
     */
    void setItems(List<BoxItem> items)
    {
        ensureData().items.emplace(std::move(items));
    }

    /**
     * ボックスから取り出したアイテムのリストを設定
     *
     * @param items ボックスから取り出したアイテムのリスト
     */
    BoxItems& withItems(List<BoxItem> items)
    {
        setItems(std::move(items));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const BoxItems& lhs, const BoxItems& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->boxId != lhr.m_pData->boxId)
        {
            return true;
        }
        if (lhs.m_pData->prizeTableName != lhr.m_pData->prizeTableName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->items != lhr.m_pData->items)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const BoxItems& lhs, const BoxItems& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_BOXITEMS_HPP_