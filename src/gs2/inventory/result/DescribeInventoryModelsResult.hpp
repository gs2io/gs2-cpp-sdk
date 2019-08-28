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

#ifndef GS2_INVENTORY_CONTROL_DESCRIBEINVENTORYMODELSRESULT_HPP_
#define GS2_INVENTORY_CONTROL_DESCRIBEINVENTORYMODELSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inventory
{

/**
 * インベントリモデルの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeInventoryModelsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** インベントリモデルのリスト */
        optional<List<InventoryModel>> items;

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
                        InventoryModel item;
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
    DescribeInventoryModelsResult() :
        m_pData(nullptr)
    {}

    DescribeInventoryModelsResult(const DescribeInventoryModelsResult& describeInventoryModelsResult) :
        Gs2Object(describeInventoryModelsResult),
        m_pData(describeInventoryModelsResult.m_pData != nullptr ? new Data(*describeInventoryModelsResult.m_pData) : nullptr)
    {}

    DescribeInventoryModelsResult(DescribeInventoryModelsResult&& describeInventoryModelsResult) :
        Gs2Object(std::move(describeInventoryModelsResult)),
        m_pData(describeInventoryModelsResult.m_pData)
    {
        describeInventoryModelsResult.m_pData = nullptr;
    }

    ~DescribeInventoryModelsResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeInventoryModelsResult& operator=(const DescribeInventoryModelsResult& describeInventoryModelsResult)
    {
        Gs2Object::operator=(describeInventoryModelsResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeInventoryModelsResult.m_pData);

        return *this;
    }

    DescribeInventoryModelsResult& operator=(DescribeInventoryModelsResult&& describeInventoryModelsResult)
    {
        Gs2Object::operator=(std::move(describeInventoryModelsResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeInventoryModelsResult.m_pData;
        describeInventoryModelsResult.m_pData = nullptr;

        return *this;
    }

    const DescribeInventoryModelsResult* operator->() const
    {
        return this;
    }

    DescribeInventoryModelsResult* operator->()
    {
        return this;
    }
    /**
     * インベントリモデルのリストを取得
     *
     * @return インベントリモデルのリスト
     */
    const optional<List<InventoryModel>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * インベントリモデルのリストを設定
     *
     * @param items インベントリモデルのリスト
     */
    void setItems(const List<InventoryModel>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<DescribeInventoryModelsResult> AsyncDescribeInventoryModelsResult;

} }

#endif //GS2_INVENTORY_CONTROL_DESCRIBEINVENTORYMODELSRESULT_HPP_