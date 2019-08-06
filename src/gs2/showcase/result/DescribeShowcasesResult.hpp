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

#ifndef GS2_SHOWCASE_CONTROL_DESCRIBESHOWCASESRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_DESCRIBESHOWCASESRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace showcase
{

/**
 * 陳列棚の一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeShowcasesResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 陳列棚のリスト */
        optional<List<Showcase>> items;

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

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Showcase item;
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
    DescribeShowcasesResult() :
        m_pData(nullptr)
    {}

    DescribeShowcasesResult(const DescribeShowcasesResult& describeShowcasesResult) :
        Gs2Object(describeShowcasesResult),
        m_pData(describeShowcasesResult.m_pData != nullptr ? new Data(*describeShowcasesResult.m_pData) : nullptr)
    {}

    DescribeShowcasesResult(DescribeShowcasesResult&& describeShowcasesResult) :
        Gs2Object(std::move(describeShowcasesResult)),
        m_pData(describeShowcasesResult.m_pData)
    {
        describeShowcasesResult.m_pData = nullptr;
    }

    ~DescribeShowcasesResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeShowcasesResult& operator=(const DescribeShowcasesResult& describeShowcasesResult)
    {
        Gs2Object::operator=(describeShowcasesResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeShowcasesResult.m_pData);

        return *this;
    }

    DescribeShowcasesResult& operator=(DescribeShowcasesResult&& describeShowcasesResult)
    {
        Gs2Object::operator=(std::move(describeShowcasesResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeShowcasesResult.m_pData;
        describeShowcasesResult.m_pData = nullptr;

        return *this;
    }

    const DescribeShowcasesResult* operator->() const
    {
        return this;
    }

    DescribeShowcasesResult* operator->()
    {
        return this;
    }
    /**
     * 陳列棚のリストを取得
     *
     * @return 陳列棚のリスト
     */
    const optional<List<Showcase>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * 陳列棚のリストを設定
     *
     * @param items 陳列棚のリスト
     */
    void setItems(const List<Showcase>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_DESCRIBESHOWCASESRESULT_HPP_