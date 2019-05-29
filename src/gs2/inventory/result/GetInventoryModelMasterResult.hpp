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

#ifndef GS2_INVENTORY_CONTROL_GETINVENTORYMODELMASTERRESULT_HPP_
#define GS2_INVENTORY_CONTROL_GETINVENTORYMODELMASTERRESULT_HPP_

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
 * インベントリマスターを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetInventoryModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** インベントリマスター */
        optional<InventoryModelMaster> item;

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
                    const auto& jsonObject = jsonValue.GetObject();
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
    GetInventoryModelMasterResult() :
        m_pData(nullptr)
    {}

    GetInventoryModelMasterResult(const GetInventoryModelMasterResult& getInventoryModelMasterResult) :
        Gs2Object(getInventoryModelMasterResult),
        m_pData(getInventoryModelMasterResult.m_pData != nullptr ? new Data(*getInventoryModelMasterResult.m_pData) : nullptr)
    {}

    GetInventoryModelMasterResult(GetInventoryModelMasterResult&& getInventoryModelMasterResult) :
        Gs2Object(std::move(getInventoryModelMasterResult)),
        m_pData(getInventoryModelMasterResult.m_pData)
    {
        getInventoryModelMasterResult.m_pData = nullptr;
    }

    ~GetInventoryModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetInventoryModelMasterResult& operator=(const GetInventoryModelMasterResult& getInventoryModelMasterResult)
    {
        Gs2Object::operator=(getInventoryModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getInventoryModelMasterResult.m_pData);

        return *this;
    }

    GetInventoryModelMasterResult& operator=(GetInventoryModelMasterResult&& getInventoryModelMasterResult)
    {
        Gs2Object::operator=(std::move(getInventoryModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getInventoryModelMasterResult.m_pData;
        getInventoryModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetInventoryModelMasterResult* operator->() const
    {
        return this;
    }

    GetInventoryModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * インベントリマスターを取得
     *
     * @return インベントリマスター
     */
    const optional<InventoryModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * インベントリマスターを設定
     *
     * @param item インベントリマスター
     */
    void setItem(const InventoryModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_GETINVENTORYMODELMASTERRESULT_HPP_