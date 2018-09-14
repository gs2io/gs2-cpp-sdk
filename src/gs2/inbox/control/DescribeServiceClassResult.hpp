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

#ifndef GS2_INBOX_CONTROL_DESCRIBESERVICECLASSRESULT_HPP_
#define GS2_INBOX_CONTROL_DESCRIBESERVICECLASSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeServiceClassResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** サービスクラス一覧 */
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
    DescribeServiceClassResult() :
        m_pData(nullptr)
    {}

    DescribeServiceClassResult(const DescribeServiceClassResult& describeServiceClassResult) :
        Gs2Object(describeServiceClassResult),
        m_pData(describeServiceClassResult.m_pData != nullptr ? new Data(*describeServiceClassResult.m_pData) : nullptr)
    {}

    DescribeServiceClassResult(DescribeServiceClassResult&& describeServiceClassResult) :
        Gs2Object(std::move(describeServiceClassResult)),
        m_pData(describeServiceClassResult.m_pData)
    {
        describeServiceClassResult.m_pData = nullptr;
    }

    ~DescribeServiceClassResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeServiceClassResult& operator=(const DescribeServiceClassResult& describeServiceClassResult)
    {
        Gs2Object::operator=(describeServiceClassResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeServiceClassResult.m_pData);

        return *this;
    }

    DescribeServiceClassResult& operator=(DescribeServiceClassResult&& describeServiceClassResult)
    {
        Gs2Object::operator=(std::move(describeServiceClassResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeServiceClassResult.m_pData;
        describeServiceClassResult.m_pData = nullptr;

        return *this;
    }

    const DescribeServiceClassResult* operator->() const
    {
        return this;
    }

    DescribeServiceClassResult* operator->()
    {
        return this;
    }


    /**
     * サービスクラス一覧を取得
     *
     * @return サービスクラス一覧
     */
    const optional<List<StringHolder>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * サービスクラス一覧を設定
     *
     * @param items サービスクラス一覧
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

#endif //GS2_INBOX_CONTROL_DESCRIBESERVICECLASSRESULT_HPP_