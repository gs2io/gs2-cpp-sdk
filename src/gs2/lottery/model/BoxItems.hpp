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
#include <gs2/core/external/optional/optional.hpp>
#include "BoxItem.hpp"
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            boxId(data.boxId),
            prizeTableName(data.prizeTableName),
            userId(data.userId),
            items(data.items)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            boxId(std::move(data.boxId)),
            prizeTableName(std::move(data.prizeTableName)),
            userId(std::move(data.userId)),
            items(std::move(data.items))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "boxId") == 0) {
                if (jsonValue.IsString())
                {
                    this->boxId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "prizeTableName") == 0) {
                if (jsonValue.IsString())
                {
                    this->prizeTableName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        BoxItem item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->items, std::move(item));
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
    BoxItems() :
        m_pData(nullptr)
    {}

    BoxItems(const BoxItems& boxItems) :
        Gs2Object(boxItems),
        m_pData(boxItems.m_pData != nullptr ? new Data(*boxItems.m_pData) : nullptr)
    {}

    BoxItems(BoxItems&& boxItems) :
        Gs2Object(std::move(boxItems)),
        m_pData(boxItems.m_pData)
    {
        boxItems.m_pData = nullptr;
    }

    ~BoxItems()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    BoxItems& operator=(const BoxItems& boxItems)
    {
        Gs2Object::operator=(boxItems);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*boxItems.m_pData);

        return *this;
    }

    BoxItems& operator=(BoxItems&& boxItems)
    {
        Gs2Object::operator=(std::move(boxItems));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = boxItems.m_pData;
        boxItems.m_pData = nullptr;

        return *this;
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
    void setBoxId(const Char* boxId)
    {
        ensureData().boxId.emplace(boxId);
    }

    /**
     * ボックスを設定
     *
     * @param boxId ボックス
     */
    BoxItems& withBoxId(const Char* boxId)
    {
        setBoxId(boxId);
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
    void setPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
    }

    /**
     * 排出確率テーブル名を設定
     *
     * @param prizeTableName 排出確率テーブル名
     */
    BoxItems& withPrizeTableName(const Char* prizeTableName)
    {
        setPrizeTableName(prizeTableName);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    BoxItems& withUserId(const Char* userId)
    {
        setUserId(userId);
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
    void setItems(const List<BoxItem>& items)
    {
        ensureData().items.emplace(items);
    }

    /**
     * ボックスから取り出したアイテムのリストを設定
     *
     * @param items ボックスから取り出したアイテムのリスト
     */
    BoxItems& withItems(const List<BoxItem>& items)
    {
        setItems(items);
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
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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