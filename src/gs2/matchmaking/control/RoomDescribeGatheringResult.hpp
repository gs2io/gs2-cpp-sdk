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

#ifndef GS2_MATCHMAKING_CONTROL_ROOMDESCRIBEGATHERINGRESULT_HPP_
#define GS2_MATCHMAKING_CONTROL_ROOMDESCRIBEGATHERINGRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace matchmaking
{

/**
 * @author Game Server Services, Inc.
 */
class RoomDescribeGatheringResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** Roomマッチメイキング ギャザリング */
        optional<List<RoomGathering>> items;
        /** 次のページを読み込むためのトークン */
        optional<StringHolder> nextPageToken;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items),
            nextPageToken(data.nextPageToken)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items)),
            nextPageToken(std::move(data.nextPageToken))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        RoomGathering item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name, "nextPageToken") == 0) {
                if (jsonValue.IsString())
                {
                    this->nextPageToken.emplace(jsonValue.GetString());
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
    RoomDescribeGatheringResult() :
        m_pData(nullptr)
    {}

    RoomDescribeGatheringResult(const RoomDescribeGatheringResult& roomDescribeGatheringResult) :
        Gs2Object(roomDescribeGatheringResult),
        m_pData(roomDescribeGatheringResult.m_pData != nullptr ? new Data(*roomDescribeGatheringResult.m_pData) : nullptr)
    {}

    RoomDescribeGatheringResult(RoomDescribeGatheringResult&& roomDescribeGatheringResult) :
        Gs2Object(std::move(roomDescribeGatheringResult)),
        m_pData(roomDescribeGatheringResult.m_pData)
    {
        roomDescribeGatheringResult.m_pData = nullptr;
    }

    ~RoomDescribeGatheringResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RoomDescribeGatheringResult& operator=(const RoomDescribeGatheringResult& roomDescribeGatheringResult)
    {
        Gs2Object::operator=(roomDescribeGatheringResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*roomDescribeGatheringResult.m_pData);

        return *this;
    }

    RoomDescribeGatheringResult& operator=(RoomDescribeGatheringResult&& roomDescribeGatheringResult)
    {
        Gs2Object::operator=(std::move(roomDescribeGatheringResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = roomDescribeGatheringResult.m_pData;
        roomDescribeGatheringResult.m_pData = nullptr;

        return *this;
    }

    const RoomDescribeGatheringResult* operator->() const
    {
        return this;
    }

    RoomDescribeGatheringResult* operator->()
    {
        return this;
    }


    /**
     * Roomマッチメイキング ギャザリングを取得
     *
     * @return Roomマッチメイキング ギャザリング
     */
    const optional<List<RoomGathering>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * Roomマッチメイキング ギャザリングを設定
     *
     * @param items Roomマッチメイキング ギャザリング
     */
    void setItems(const List<RoomGathering>& items)
    {
        ensureData().items.emplace(items);
    }

    /**
     * 次のページを読み込むためのトークンを取得
     *
     * @return 次のページを読み込むためのトークン
     */
    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }

    /**
     * 次のページを読み込むためのトークンを設定
     *
     * @param nextPageToken 次のページを読み込むためのトークン
     */
    void setNextPageToken(const Char* nextPageToken)
    {
        ensureData().nextPageToken.emplace(nextPageToken);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_ROOMDESCRIBEGATHERINGRESULT_HPP_