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

#ifndef GS2_INVENTORY_CONTROL_GETINVENTORYMODELRESULT_HPP_
#define GS2_INVENTORY_CONTROL_GETINVENTORYMODELRESULT_HPP_

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
 * インベントリモデルを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetInventoryModelResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** インベントリモデル */
        optional<InventoryModel> item;

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

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
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
    GetInventoryModelResult() :
        m_pData(nullptr)
    {}

    GetInventoryModelResult(const GetInventoryModelResult& getInventoryModelResult) :
        Gs2Object(getInventoryModelResult),
        m_pData(getInventoryModelResult.m_pData != nullptr ? new Data(*getInventoryModelResult.m_pData) : nullptr)
    {}

    GetInventoryModelResult(GetInventoryModelResult&& getInventoryModelResult) :
        Gs2Object(std::move(getInventoryModelResult)),
        m_pData(getInventoryModelResult.m_pData)
    {
        getInventoryModelResult.m_pData = nullptr;
    }

    ~GetInventoryModelResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetInventoryModelResult& operator=(const GetInventoryModelResult& getInventoryModelResult)
    {
        Gs2Object::operator=(getInventoryModelResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getInventoryModelResult.m_pData);

        return *this;
    }

    GetInventoryModelResult& operator=(GetInventoryModelResult&& getInventoryModelResult)
    {
        Gs2Object::operator=(std::move(getInventoryModelResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getInventoryModelResult.m_pData;
        getInventoryModelResult.m_pData = nullptr;

        return *this;
    }

    const GetInventoryModelResult* operator->() const
    {
        return this;
    }

    GetInventoryModelResult* operator->()
    {
        return this;
    }
    /**
     * インベントリモデルを取得
     *
     * @return インベントリモデル
     */
    const optional<InventoryModel>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * インベントリモデルを設定
     *
     * @param item インベントリモデル
     */
    void setItem(const InventoryModel& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_GETINVENTORYMODELRESULT_HPP_