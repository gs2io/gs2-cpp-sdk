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

#ifndef GS2_STAMINA_CONTROL_DESCRIBESTAMINAMODELSRESULT_HPP_
#define GS2_STAMINA_CONTROL_DESCRIBESTAMINAMODELSRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * スタミナモデルの一覧を取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DescribeStaminaModelsResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナモデルのリスト */
        optional<List<StaminaModel>> items;

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
                        StaminaModel item;
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
    DescribeStaminaModelsResult() :
        m_pData(nullptr)
    {}

    DescribeStaminaModelsResult(const DescribeStaminaModelsResult& describeStaminaModelsResult) :
        Gs2Object(describeStaminaModelsResult),
        m_pData(describeStaminaModelsResult.m_pData != nullptr ? new Data(*describeStaminaModelsResult.m_pData) : nullptr)
    {}

    DescribeStaminaModelsResult(DescribeStaminaModelsResult&& describeStaminaModelsResult) :
        Gs2Object(std::move(describeStaminaModelsResult)),
        m_pData(describeStaminaModelsResult.m_pData)
    {
        describeStaminaModelsResult.m_pData = nullptr;
    }

    ~DescribeStaminaModelsResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeStaminaModelsResult& operator=(const DescribeStaminaModelsResult& describeStaminaModelsResult)
    {
        Gs2Object::operator=(describeStaminaModelsResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeStaminaModelsResult.m_pData);

        return *this;
    }

    DescribeStaminaModelsResult& operator=(DescribeStaminaModelsResult&& describeStaminaModelsResult)
    {
        Gs2Object::operator=(std::move(describeStaminaModelsResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeStaminaModelsResult.m_pData;
        describeStaminaModelsResult.m_pData = nullptr;

        return *this;
    }

    const DescribeStaminaModelsResult* operator->() const
    {
        return this;
    }

    DescribeStaminaModelsResult* operator->()
    {
        return this;
    }
    /**
     * スタミナモデルのリストを取得
     *
     * @return スタミナモデルのリスト
     */
    const optional<List<StaminaModel>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * スタミナモデルのリストを設定
     *
     * @param items スタミナモデルのリスト
     */
    void setItems(const List<StaminaModel>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_CONTROL_DESCRIBESTAMINAMODELSRESULT_HPP_