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

#ifndef GS2_SCHEDULE_CONTROL_GETEVENTMASTERRESULT_HPP_
#define GS2_SCHEDULE_CONTROL_GETEVENTMASTERRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace schedule
{

/**
 * @author Game Server Services, Inc.
 */
class GetEventMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** イベントマスター */
        optional<EventMaster> item;

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
    GetEventMasterResult() :
        m_pData(nullptr)
    {}

    GetEventMasterResult(const GetEventMasterResult& getEventMasterResult) :
        Gs2Object(getEventMasterResult),
        m_pData(getEventMasterResult.m_pData != nullptr ? new Data(*getEventMasterResult.m_pData) : nullptr)
    {}

    GetEventMasterResult(GetEventMasterResult&& getEventMasterResult) :
        Gs2Object(std::move(getEventMasterResult)),
        m_pData(getEventMasterResult.m_pData)
    {
        getEventMasterResult.m_pData = nullptr;
    }

    ~GetEventMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetEventMasterResult& operator=(const GetEventMasterResult& getEventMasterResult)
    {
        Gs2Object::operator=(getEventMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getEventMasterResult.m_pData);

        return *this;
    }

    GetEventMasterResult& operator=(GetEventMasterResult&& getEventMasterResult)
    {
        Gs2Object::operator=(std::move(getEventMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getEventMasterResult.m_pData;
        getEventMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetEventMasterResult* operator->() const
    {
        return this;
    }

    GetEventMasterResult* operator->()
    {
        return this;
    }


    /**
     * イベントマスターを取得
     *
     * @return イベントマスター
     */
    const optional<EventMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * イベントマスターを設定
     *
     * @param item イベントマスター
     */
    void setItem(const EventMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_GETEVENTMASTERRESULT_HPP_