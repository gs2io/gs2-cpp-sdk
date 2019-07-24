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

#ifndef GS2_SHOWCASE_CONTROL_UPDATESALESITEMMASTERRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_UPDATESALESITEMMASTERRESULT_HPP_

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
 * 商品マスターを更新 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateSalesItemMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 更新した商品マスター */
        optional<SalesItemMaster> item;

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
    UpdateSalesItemMasterResult() :
        m_pData(nullptr)
    {}

    UpdateSalesItemMasterResult(const UpdateSalesItemMasterResult& updateSalesItemMasterResult) :
        Gs2Object(updateSalesItemMasterResult),
        m_pData(updateSalesItemMasterResult.m_pData != nullptr ? new Data(*updateSalesItemMasterResult.m_pData) : nullptr)
    {}

    UpdateSalesItemMasterResult(UpdateSalesItemMasterResult&& updateSalesItemMasterResult) :
        Gs2Object(std::move(updateSalesItemMasterResult)),
        m_pData(updateSalesItemMasterResult.m_pData)
    {
        updateSalesItemMasterResult.m_pData = nullptr;
    }

    ~UpdateSalesItemMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateSalesItemMasterResult& operator=(const UpdateSalesItemMasterResult& updateSalesItemMasterResult)
    {
        Gs2Object::operator=(updateSalesItemMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateSalesItemMasterResult.m_pData);

        return *this;
    }

    UpdateSalesItemMasterResult& operator=(UpdateSalesItemMasterResult&& updateSalesItemMasterResult)
    {
        Gs2Object::operator=(std::move(updateSalesItemMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateSalesItemMasterResult.m_pData;
        updateSalesItemMasterResult.m_pData = nullptr;

        return *this;
    }

    const UpdateSalesItemMasterResult* operator->() const
    {
        return this;
    }

    UpdateSalesItemMasterResult* operator->()
    {
        return this;
    }
    /**
     * 更新した商品マスターを取得
     *
     * @return 更新した商品マスター
     */
    const optional<SalesItemMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 更新した商品マスターを設定
     *
     * @param item 更新した商品マスター
     */
    void setItem(const SalesItemMaster& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SHOWCASE_CONTROL_UPDATESALESITEMMASTERRESULT_HPP_