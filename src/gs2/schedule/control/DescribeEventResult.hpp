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

#ifndef GS2_SCHEDULE_CONTROL_DESCRIBEEVENTRESULT_HPP_
#define GS2_SCHEDULE_CONTROL_DESCRIBEEVENTRESULT_HPP_

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
class DescribeEventResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** イベント */
        optional<List<Event>> items;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            items(data.items)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            items(std::move(data.items))
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
                        Event item;
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
    DescribeEventResult() :
        m_pData(nullptr)
    {}

    DescribeEventResult(const DescribeEventResult& describeEventResult) :
        Gs2Object(describeEventResult),
        m_pData(describeEventResult.m_pData != nullptr ? new Data(*describeEventResult.m_pData) : nullptr)
    {}

    DescribeEventResult(DescribeEventResult&& describeEventResult) :
        Gs2Object(std::move(describeEventResult)),
        m_pData(describeEventResult.m_pData)
    {
        describeEventResult.m_pData = nullptr;
    }

    ~DescribeEventResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeEventResult& operator=(const DescribeEventResult& describeEventResult)
    {
        Gs2Object::operator=(describeEventResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeEventResult.m_pData);

        return *this;
    }

    DescribeEventResult& operator=(DescribeEventResult&& describeEventResult)
    {
        Gs2Object::operator=(std::move(describeEventResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeEventResult.m_pData;
        describeEventResult.m_pData = nullptr;

        return *this;
    }

    const DescribeEventResult* operator->() const
    {
        return this;
    }

    DescribeEventResult* operator->()
    {
        return this;
    }


    /**
     * イベントを取得
     *
     * @return イベント
     */
    const optional<List<Event>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * イベントを設定
     *
     * @param items イベント
     */
    void setItems(const List<Event>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SCHEDULE_CONTROL_DESCRIBEEVENTRESULT_HPP_