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

#ifndef GS2_CHAT_CONTROL_DESCRIBEMESSAGERESULT_HPP_
#define GS2_CHAT_CONTROL_DESCRIBEMESSAGERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace chat
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeMessageResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージ */
        optional<List<Message>> items;

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
                        Message item;
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
    DescribeMessageResult() :
        m_pData(nullptr)
    {}

    DescribeMessageResult(const DescribeMessageResult& describeMessageResult) :
        Gs2Object(describeMessageResult),
        m_pData(describeMessageResult.m_pData != nullptr ? new Data(*describeMessageResult.m_pData) : nullptr)
    {}

    DescribeMessageResult(DescribeMessageResult&& describeMessageResult) :
        Gs2Object(std::move(describeMessageResult)),
        m_pData(describeMessageResult.m_pData)
    {
        describeMessageResult.m_pData = nullptr;
    }

    ~DescribeMessageResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeMessageResult& operator=(const DescribeMessageResult& describeMessageResult)
    {
        Gs2Object::operator=(describeMessageResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeMessageResult.m_pData);

        return *this;
    }

    DescribeMessageResult& operator=(DescribeMessageResult&& describeMessageResult)
    {
        Gs2Object::operator=(std::move(describeMessageResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeMessageResult.m_pData;
        describeMessageResult.m_pData = nullptr;

        return *this;
    }

    const DescribeMessageResult* operator->() const
    {
        return this;
    }

    DescribeMessageResult* operator->()
    {
        return this;
    }


    /**
     * メッセージを取得
     *
     * @return メッセージ
     */
    const optional<List<Message>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * メッセージを設定
     *
     * @param items メッセージ
     */
    void setItems(const List<Message>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CHAT_CONTROL_DESCRIBEMESSAGERESULT_HPP_