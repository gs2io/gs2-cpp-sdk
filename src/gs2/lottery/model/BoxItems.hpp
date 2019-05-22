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
 * 排出済みの景品情報
 *
 * @author Game Server Services, Inc.
 *
 */
class BoxItems : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 排出済みの景品情報 のGRN */
        optional<StringHolder> boxId;
        /** 景品テーブル名 */
        optional<StringHolder> prizeTableName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 排出済みの景品情報のリスト */
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
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
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
     * 排出済みの景品情報 のGRNを取得
     *
     * @return 排出済みの景品情報 のGRN
     */
    const optional<StringHolder>& getBoxId() const
    {
        return ensureData().boxId;
    }

    /**
     * 排出済みの景品情報 のGRNを設定
     *
     * @param boxId 排出済みの景品情報 のGRN
     */
    void setBoxId(const Char* boxId)
    {
        ensureData().boxId.emplace(boxId);
    }

    /**
     * 景品テーブル名を取得
     *
     * @return 景品テーブル名
     */
    const optional<StringHolder>& getPrizeTableName() const
    {
        return ensureData().prizeTableName;
    }

    /**
     * 景品テーブル名を設定
     *
     * @param prizeTableName 景品テーブル名
     */
    void setPrizeTableName(const Char* prizeTableName)
    {
        ensureData().prizeTableName.emplace(prizeTableName);
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
     * 排出済みの景品情報のリストを取得
     *
     * @return 排出済みの景品情報のリスト
     */
    const optional<List<BoxItem>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 排出済みの景品情報のリストを設定
     *
     * @param items 排出済みの景品情報のリスト
     */
    void setItems(const List<BoxItem>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOTTERY_MODEL_BOXITEMS_HPP_