/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_MONEY_CONTROL_GETWALLETDETAILRESULT_HPP_
#define GS2_MONEY_CONTROL_GETWALLETDETAILRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace money
{

/**
 * @author Game Server Services, Inc.
 */
class GetWalletDetailResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ウォレットの詳細 */
        optional<List<Wallet>> items;

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

        ~Data() = default;

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
                        Wallet item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->items += std::move(item);
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
    GetWalletDetailResult() :
        m_pData(nullptr)
    {}

    GetWalletDetailResult(const GetWalletDetailResult& getWalletDetailResult) :
        Gs2Object(getWalletDetailResult),
        m_pData(getWalletDetailResult.m_pData != nullptr ? new Data(*getWalletDetailResult.m_pData) : nullptr)
    {}

    GetWalletDetailResult(GetWalletDetailResult&& getWalletDetailResult) :
        Gs2Object(std::move(getWalletDetailResult)),
        m_pData(getWalletDetailResult.m_pData)
    {
        getWalletDetailResult.m_pData = nullptr;
    }

    ~GetWalletDetailResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetWalletDetailResult& operator=(const GetWalletDetailResult& getWalletDetailResult)
    {
        Gs2Object::operator=(getWalletDetailResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getWalletDetailResult.m_pData);

        return *this;
    }

    GetWalletDetailResult& operator=(GetWalletDetailResult&& getWalletDetailResult)
    {
        Gs2Object::operator=(std::move(getWalletDetailResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getWalletDetailResult.m_pData;
        getWalletDetailResult.m_pData = nullptr;

        return *this;
    }

    const GetWalletDetailResult* operator->() const
    {
        return this;
    }

    GetWalletDetailResult* operator->()
    {
        return this;
    }


    /**
     * ウォレットの詳細を取得
     *
     * @return ウォレットの詳細
     */
    const optional<List<Wallet>>& getItems() const
    {
        return ensureData().items;
    }

    /**
     * ウォレットの詳細を設定
     *
     * @param items ウォレットの詳細
     */
    void setItems(const List<Wallet>& items)
    {
        ensureData().items.emplace(items);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MONEY_CONTROL_GETWALLETDETAILRESULT_HPP_