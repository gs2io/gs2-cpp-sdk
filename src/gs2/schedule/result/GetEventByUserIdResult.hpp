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

#ifndef GS2_SCHEDULE_CONTROL_GETEVENTBYUSERIDRESULT_HPP_
#define GS2_SCHEDULE_CONTROL_GETEVENTBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace schedule
{

/**
 * ユーザIDを指定してイベントを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetEventByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** イベント */
        optional<Event> item;

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

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
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
    GetEventByUserIdResult() :
        m_pData(nullptr)
    {}

    GetEventByUserIdResult(const GetEventByUserIdResult& getEventByUserIdResult) :
        Gs2Object(getEventByUserIdResult),
        m_pData(getEventByUserIdResult.m_pData != nullptr ? new Data(*getEventByUserIdResult.m_pData) : nullptr)
    {}

    GetEventByUserIdResult(GetEventByUserIdResult&& getEventByUserIdResult) :
        Gs2Object(std::move(getEventByUserIdResult)),
        m_pData(getEventByUserIdResult.m_pData)
    {
        getEventByUserIdResult.m_pData = nullptr;
    }

    ~GetEventByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetEventByUserIdResult& operator=(const GetEventByUserIdResult& getEventByUserIdResult)
    {
        Gs2Object::operator=(getEventByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getEventByUserIdResult.m_pData);

        return *this;
    }

    GetEventByUserIdResult& operator=(GetEventByUserIdResult&& getEventByUserIdResult)
    {
        Gs2Object::operator=(std::move(getEventByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getEventByUserIdResult.m_pData;
        getEventByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const GetEventByUserIdResult* operator->() const
    {
        return this;
    }

    GetEventByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * イベントを取得
     *
     * @return イベント
     */
    const optional<Event>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * イベントを設定
     *
     * @param item イベント
     */
    void setItem(const Event& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<GetEventByUserIdResult> AsyncGetEventByUserIdResult;

} }

#endif //GS2_SCHEDULE_CONTROL_GETEVENTBYUSERIDRESULT_HPP_