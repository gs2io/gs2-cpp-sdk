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

#ifndef GS2_SHOWCASE_CONTROL_DELETESALESITEMGROUPMASTERRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_DELETESALESITEMGROUPMASTERRESULT_HPP_

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
 * 商品グループマスターを削除 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteSalesItemGroupMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 削除した商品グループマスター */
        optional<SalesItemGroupMaster> item;

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
    DeleteSalesItemGroupMasterResult() :
        m_pData(nullptr)
    {}

    DeleteSalesItemGroupMasterResult(const DeleteSalesItemGroupMasterResult& deleteSalesItemGroupMasterResult) :
        Gs2Object(deleteSalesItemGroupMasterResult),
        m_pData(deleteSalesItemGroupMasterResult.m_pData != nullptr ? new Data(*deleteSalesItemGroupMasterResult.m_pData) : nullptr)
    {}

    DeleteSalesItemGroupMasterResult(DeleteSalesItemGroupMasterResult&& deleteSalesItemGroupMasterResult) :
        Gs2Object(std::move(deleteSalesItemGroupMasterResult)),
        m_pData(deleteSalesItemGroupMasterResult.m_pData)
    {
        deleteSalesItemGroupMasterResult.m_pData = nullptr;
    }

    ~DeleteSalesItemGroupMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteSalesItemGroupMasterResult& operator=(const DeleteSalesItemGroupMasterResult& deleteSalesItemGroupMasterResult)
    {
        Gs2Object::operator=(deleteSalesItemGroupMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteSalesItemGroupMasterResult.m_pData);

        return *this;
    }

    DeleteSalesItemGroupMasterResult& operator=(DeleteSalesItemGroupMasterResult&& deleteSalesItemGroupMasterResult)
    {
        Gs2Object::operator=(std::move(deleteSalesItemGroupMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteSalesItemGroupMasterResult.m_pData;
        deleteSalesItemGroupMasterResult.m_pData = nullptr;

        return *this;
    }

    const DeleteSalesItemGroupMasterResult* operator->() const
    {
        return this;
    }

    DeleteSalesItemGroupMasterResult* operator->()
    {
        return this;
    }
    /**
     * 削除した商品グループマスターを取得
     *
     * @return 削除した商品グループマスター
     */
    const optional<SalesItemGroupMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 削除した商品グループマスターを設定
     *
     * @param item 削除した商品グループマスター
     */
    void setItem(const SalesItemGroupMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_DELETESALESITEMGROUPMASTERRESULT_HPP_