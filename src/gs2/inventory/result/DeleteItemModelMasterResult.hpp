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

#ifndef GS2_INVENTORY_CONTROL_DELETEITEMMODELMASTERRESULT_HPP_
#define GS2_INVENTORY_CONTROL_DELETEITEMMODELMASTERRESULT_HPP_

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
 * アイテムマスターを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteItemModelMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除したアイテムマスター */
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

        ~Data() = default;

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
    DeleteItemModelMasterResult() :
        m_pData(nullptr)
    {}

    DeleteItemModelMasterResult(const DeleteItemModelMasterResult& deleteItemModelMasterResult) :
        Gs2Object(deleteItemModelMasterResult),
        m_pData(deleteItemModelMasterResult.m_pData != nullptr ? new Data(*deleteItemModelMasterResult.m_pData) : nullptr)
    {}

    DeleteItemModelMasterResult(DeleteItemModelMasterResult&& deleteItemModelMasterResult) :
        Gs2Object(std::move(deleteItemModelMasterResult)),
        m_pData(deleteItemModelMasterResult.m_pData)
    {
        deleteItemModelMasterResult.m_pData = nullptr;
    }

    ~DeleteItemModelMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteItemModelMasterResult& operator=(const DeleteItemModelMasterResult& deleteItemModelMasterResult)
    {
        Gs2Object::operator=(deleteItemModelMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteItemModelMasterResult.m_pData);

        return *this;
    }

    DeleteItemModelMasterResult& operator=(DeleteItemModelMasterResult&& deleteItemModelMasterResult)
    {
        Gs2Object::operator=(std::move(deleteItemModelMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteItemModelMasterResult.m_pData;
        deleteItemModelMasterResult.m_pData = nullptr;

        return *this;
    }

    const DeleteItemModelMasterResult* operator->() const
    {
        return this;
    }

    DeleteItemModelMasterResult* operator->()
    {
        return this;
    }
    /**
     * 削除したアイテムマスターを取得
     *
     * @return 削除したアイテムマスター
     */
    const optional<ItemModelMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 削除したアイテムマスターを設定
     *
     * @param item 削除したアイテムマスター
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

#endif //GS2_INVENTORY_CONTROL_DELETEITEMMODELMASTERRESULT_HPP_