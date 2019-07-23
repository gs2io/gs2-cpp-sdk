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

#ifndef GS2_INVENTORY_CONTROL_CREATEITEMMODELMASTERRESULT_HPP_
#define GS2_INVENTORY_CONTROL_CREATEITEMMODELMASTERRESULT_HPP_

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
 * アイテムモデルマスターを新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateItemModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 作成したアイテムモデルマスター */
        optional<ItemModelMaster> item;

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
    CreateItemModelMasterResult() :
        m_pData(nullptr)
    {}

    CreateItemModelMasterResult(const CreateItemModelMasterResult& createItemModelMasterResult) :
        Gs2Object(createItemModelMasterResult),
        m_pData(createItemModelMasterResult.m_pData != nullptr ? new Data(*createItemModelMasterResult.m_pData) : nullptr)
    {}

    CreateItemModelMasterResult(CreateItemModelMasterResult&& createItemModelMasterResult) :
        Gs2Object(std::move(createItemModelMasterResult)),
        m_pData(createItemModelMasterResult.m_pData)
    {
        createItemModelMasterResult.m_pData = nullptr;
    }

    ~CreateItemModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateItemModelMasterResult& operator=(const CreateItemModelMasterResult& createItemModelMasterResult)
    {
        Gs2Object::operator=(createItemModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createItemModelMasterResult.m_pData);

        return *this;
    }

    CreateItemModelMasterResult& operator=(CreateItemModelMasterResult&& createItemModelMasterResult)
    {
        Gs2Object::operator=(std::move(createItemModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createItemModelMasterResult.m_pData;
        createItemModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const CreateItemModelMasterResult* operator->() const
    {
        return this;
    }

    CreateItemModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 作成したアイテムモデルマスターを取得
     *
     * @return 作成したアイテムモデルマスター
     */
    const optional<ItemModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 作成したアイテムモデルマスターを設定
     *
     * @param item 作成したアイテムモデルマスター
     */
    void setItem(const ItemModelMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INVENTORY_CONTROL_CREATEITEMMODELMASTERRESULT_HPP_