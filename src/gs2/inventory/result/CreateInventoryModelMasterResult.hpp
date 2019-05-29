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

#ifndef GS2_INVENTORY_CONTROL_CREATEINVENTORYMODELMASTERRESULT_HPP_
#define GS2_INVENTORY_CONTROL_CREATEINVENTORYMODELMASTERRESULT_HPP_

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
 * インベントリマスターを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateInventoryModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したインベントリマスター */
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
    CreateInventoryModelMasterResult() :
        m_pData(nullptr)
    {}

    CreateInventoryModelMasterResult(const CreateInventoryModelMasterResult& createInventoryModelMasterResult) :
        Gs2Object(createInventoryModelMasterResult),
        m_pData(createInventoryModelMasterResult.m_pData != nullptr ? new Data(*createInventoryModelMasterResult.m_pData) : nullptr)
    {}

    CreateInventoryModelMasterResult(CreateInventoryModelMasterResult&& createInventoryModelMasterResult) :
        Gs2Object(std::move(createInventoryModelMasterResult)),
        m_pData(createInventoryModelMasterResult.m_pData)
    {
        createInventoryModelMasterResult.m_pData = nullptr;
    }

    ~CreateInventoryModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateInventoryModelMasterResult& operator=(const CreateInventoryModelMasterResult& createInventoryModelMasterResult)
    {
        Gs2Object::operator=(createInventoryModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createInventoryModelMasterResult.m_pData);

        return *this;
    }

    CreateInventoryModelMasterResult& operator=(CreateInventoryModelMasterResult&& createInventoryModelMasterResult)
    {
        Gs2Object::operator=(std::move(createInventoryModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createInventoryModelMasterResult.m_pData;
        createInventoryModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const CreateInventoryModelMasterResult* operator->() const
    {
        return this;
    }

    CreateInventoryModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 作成したインベントリマスターを取得
     *
     * @return 作成したインベントリマスター
     */
    const optional<InventoryModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したインベントリマスターを設定
     *
     * @param item 作成したインベントリマスター
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

#endif //GS2_INVENTORY_CONTROL_CREATEINVENTORYMODELMASTERRESULT_HPP_