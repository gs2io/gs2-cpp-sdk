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

#ifndef GS2_DISTRIBUTOR_CONTROL_GETDISTRIBUTORRESULT_HPP_
#define GS2_DISTRIBUTOR_CONTROL_GETDISTRIBUTORRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace distributor
{

/**
 * ディストリビュータを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class GetDistributorResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ディストリビュータ */
        optional<Distributor> item;

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
    GetDistributorResult() :
        m_pData(nullptr)
    {}

    GetDistributorResult(const GetDistributorResult& getDistributorResult) :
        Gs2Object(getDistributorResult),
        m_pData(getDistributorResult.m_pData != nullptr ? new Data(*getDistributorResult.m_pData) : nullptr)
    {}

    GetDistributorResult(GetDistributorResult&& getDistributorResult) :
        Gs2Object(std::move(getDistributorResult)),
        m_pData(getDistributorResult.m_pData)
    {
        getDistributorResult.m_pData = nullptr;
    }

    ~GetDistributorResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetDistributorResult& operator=(const GetDistributorResult& getDistributorResult)
    {
        Gs2Object::operator=(getDistributorResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getDistributorResult.m_pData);

        return *this;
    }

    GetDistributorResult& operator=(GetDistributorResult&& getDistributorResult)
    {
        Gs2Object::operator=(std::move(getDistributorResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getDistributorResult.m_pData;
        getDistributorResult.m_pData = nullptr;

        return *this;
    }

    const GetDistributorResult* operator->() const
    {
        return this;
    }

    GetDistributorResult* operator->()
    {
        return this;
    }
    /**
     * ディストリビュータを取得
     *
     * @return ディストリビュータ
     */
    const optional<Distributor>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ディストリビュータを設定
     *
     * @param item ディストリビュータ
     */
    void setItem(const Distributor& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_DISTRIBUTOR_CONTROL_GETDISTRIBUTORRESULT_HPP_