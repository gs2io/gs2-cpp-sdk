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

#ifndef GS2_INVENTORY_CONTROL_DESCRIBEITEMMODELSRESULT_HPP_
#define GS2_INVENTORY_CONTROL_DESCRIBEITEMMODELSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * アイテムマスターの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeItemModelsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アイテムマスターのリスト */
        optional<List<ItemModel>> items;

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

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "items") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->items.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ItemModel item;
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
    DescribeItemModelsResult() :
        m_pData(nullptr)
    {}

    DescribeItemModelsResult(const DescribeItemModelsResult& describeItemModelsResult) :
        Gs2Object(describeItemModelsResult),
        m_pData(describeItemModelsResult.m_pData != nullptr ? new Data(*describeItemModelsResult.m_pData) : nullptr)
    {}

    DescribeItemModelsResult(DescribeItemModelsResult&& describeItemModelsResult) :
        Gs2Object(std::move(describeItemModelsResult)),
        m_pData(describeItemModelsResult.m_pData)
    {
        describeItemModelsResult.m_pData = nullptr;
    }

    ~DescribeItemModelsResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeItemModelsResult& operator=(const DescribeItemModelsResult& describeItemModelsResult)
    {
        Gs2Object::operator=(describeItemModelsResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeItemModelsResult.m_pData);

        return *this;
    }

    DescribeItemModelsResult& operator=(DescribeItemModelsResult&& describeItemModelsResult)
    {
        Gs2Object::operator=(std::move(describeItemModelsResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeItemModelsResult.m_pData;
        describeItemModelsResult.m_pData = nullptr;

        return *this;
    }

    const DescribeItemModelsResult* operator->() const
    {
        return this;
    }

    DescribeItemModelsResult* operator->()
    {
        return this;
    }
    /**
     * アイテムマスターのリストを取得
     *
     * @return アイテムマスターのリスト
     */
    const optional<List<ItemModel>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * アイテムマスターのリストを設定
     *
     * @param items アイテムマスターのリスト
     */
    void setItems(const List<ItemModel>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_DESCRIBEITEMMODELSRESULT_HPP_