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

#ifndef GS2_WATCH_CONTROL_DESCRIBESERVICERESULT_HPP_
#define GS2_WATCH_CONTROL_DESCRIBESERVICERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace watch
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeServiceResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** None */
        optional<List<StringHolder>> items;

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
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->items += std::move(stringHolder);
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
    DescribeServiceResult() :
        m_pData(nullptr)
    {}

    DescribeServiceResult(const DescribeServiceResult& describeServiceResult) :
        Gs2Object(describeServiceResult),
        m_pData(describeServiceResult.m_pData != nullptr ? new Data(*describeServiceResult.m_pData) : nullptr)
    {}

    DescribeServiceResult(DescribeServiceResult&& describeServiceResult) :
        Gs2Object(std::move(describeServiceResult)),
        m_pData(describeServiceResult.m_pData)
    {
        describeServiceResult.m_pData = nullptr;
    }

    ~DescribeServiceResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeServiceResult& operator=(const DescribeServiceResult& describeServiceResult)
    {
        Gs2Object::operator=(describeServiceResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeServiceResult.m_pData);

        return *this;
    }

    DescribeServiceResult& operator=(DescribeServiceResult&& describeServiceResult)
    {
        Gs2Object::operator=(std::move(describeServiceResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeServiceResult.m_pData;
        describeServiceResult.m_pData = nullptr;

        return *this;
    }

    const DescribeServiceResult* operator->() const
    {
        return this;
    }

    DescribeServiceResult* operator->()
    {
        return this;
    }


    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<List<StringHolder>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * Noneを設定
     *
     * @param items None
     */
    void setItems(const List<StringHolder>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_WATCH_CONTROL_DESCRIBESERVICERESULT_HPP_