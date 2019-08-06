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

#ifndef GS2_SHOWCASE_CONTROL_GETSALESITEMGROUPMASTERRESULT_HPP_
#define GS2_SHOWCASE_CONTROL_GETSALESITEMGROUPMASTERRESULT_HPP_

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
 * 商品グループマスターを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetSalesItemGroupMasterResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 商品グループマスター */
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

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0) {
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
    GetSalesItemGroupMasterResult() :
        m_pData(nullptr)
    {}

    GetSalesItemGroupMasterResult(const GetSalesItemGroupMasterResult& getSalesItemGroupMasterResult) :
        Gs2Object(getSalesItemGroupMasterResult),
        m_pData(getSalesItemGroupMasterResult.m_pData != nullptr ? new Data(*getSalesItemGroupMasterResult.m_pData) : nullptr)
    {}

    GetSalesItemGroupMasterResult(GetSalesItemGroupMasterResult&& getSalesItemGroupMasterResult) :
        Gs2Object(std::move(getSalesItemGroupMasterResult)),
        m_pData(getSalesItemGroupMasterResult.m_pData)
    {
        getSalesItemGroupMasterResult.m_pData = nullptr;
    }

    ~GetSalesItemGroupMasterResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetSalesItemGroupMasterResult& operator=(const GetSalesItemGroupMasterResult& getSalesItemGroupMasterResult)
    {
        Gs2Object::operator=(getSalesItemGroupMasterResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getSalesItemGroupMasterResult.m_pData);

        return *this;
    }

    GetSalesItemGroupMasterResult& operator=(GetSalesItemGroupMasterResult&& getSalesItemGroupMasterResult)
    {
        Gs2Object::operator=(std::move(getSalesItemGroupMasterResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getSalesItemGroupMasterResult.m_pData;
        getSalesItemGroupMasterResult.m_pData = nullptr;

        return *this;
    }

    const GetSalesItemGroupMasterResult* operator->() const
    {
        return this;
    }

    GetSalesItemGroupMasterResult* operator->()
    {
        return this;
    }
    /**
     * 商品グループマスターを取得
     *
     * @return 商品グループマスター
     */
    const optional<SalesItemGroupMaster>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 商品グループマスターを設定
     *
     * @param item 商品グループマスター
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

#endif //GS2_SHOWCASE_CONTROL_GETSALESITEMGROUPMASTERRESULT_HPP_