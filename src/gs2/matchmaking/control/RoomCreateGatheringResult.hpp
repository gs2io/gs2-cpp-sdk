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

#ifndef GS2_MATCHMAKING_CONTROL_ROOMCREATEGATHERINGRESULT_HPP_
#define GS2_MATCHMAKING_CONTROL_ROOMCREATEGATHERINGRESULT_HPP_

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
class RoomCreateGatheringResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** Roomマッチメイキング ギャザリング */
        optional<RoomGathering> item;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
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
    RoomCreateGatheringResult() :
        m_pData(nullptr)
    {}

    RoomCreateGatheringResult(const RoomCreateGatheringResult& roomCreateGatheringResult) :
        Gs2Object(roomCreateGatheringResult),
        m_pData(roomCreateGatheringResult.m_pData != nullptr ? new Data(*roomCreateGatheringResult.m_pData) : nullptr)
    {}

    RoomCreateGatheringResult(RoomCreateGatheringResult&& roomCreateGatheringResult) :
        Gs2Object(std::move(roomCreateGatheringResult)),
        m_pData(roomCreateGatheringResult.m_pData)
    {
        roomCreateGatheringResult.m_pData = nullptr;
    }

    ~RoomCreateGatheringResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RoomCreateGatheringResult& operator=(const RoomCreateGatheringResult& roomCreateGatheringResult)
    {
        Gs2Object::operator=(roomCreateGatheringResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*roomCreateGatheringResult.m_pData);

        return *this;
    }

    RoomCreateGatheringResult& operator=(RoomCreateGatheringResult&& roomCreateGatheringResult)
    {
        Gs2Object::operator=(std::move(roomCreateGatheringResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = roomCreateGatheringResult.m_pData;
        roomCreateGatheringResult.m_pData = nullptr;

        return *this;
    }

    const RoomCreateGatheringResult* operator->() const
    {
        return this;
    }

    RoomCreateGatheringResult* operator->()
    {
        return this;
    }


    /**
     * Roomマッチメイキング ギャザリングを取得
     *
     * @return Roomマッチメイキング ギャザリング
     */
    const optional<RoomGathering>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * Roomマッチメイキング ギャザリングを設定
     *
     * @param item Roomマッチメイキング ギャザリング
     */
    void setItem(const RoomGathering& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_ROOMCREATEGATHERINGRESULT_HPP_