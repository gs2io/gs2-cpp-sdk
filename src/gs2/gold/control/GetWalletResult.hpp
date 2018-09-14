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

#ifndef GS2_GOLD_CONTROL_GETWALLETRESULT_HPP_
#define GS2_GOLD_CONTROL_GETWALLETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace gold
{

/**
 * @author Game Server Services, Inc.
 */
class GetWalletResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ウォレット */
        optional<Wallet> item;

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
    GetWalletResult() :
        m_pData(nullptr)
    {}

    GetWalletResult(const GetWalletResult& getWalletResult) :
        Gs2Object(getWalletResult),
        m_pData(getWalletResult.m_pData != nullptr ? new Data(*getWalletResult.m_pData) : nullptr)
    {}

    GetWalletResult(GetWalletResult&& getWalletResult) :
        Gs2Object(std::move(getWalletResult)),
        m_pData(getWalletResult.m_pData)
    {
        getWalletResult.m_pData = nullptr;
    }

    ~GetWalletResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetWalletResult& operator=(const GetWalletResult& getWalletResult)
    {
        Gs2Object::operator=(getWalletResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getWalletResult.m_pData);

        return *this;
    }

    GetWalletResult& operator=(GetWalletResult&& getWalletResult)
    {
        Gs2Object::operator=(std::move(getWalletResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getWalletResult.m_pData;
        getWalletResult.m_pData = nullptr;

        return *this;
    }

    const GetWalletResult* operator->() const
    {
        return this;
    }

    GetWalletResult* operator->()
    {
        return this;
    }


    /**
     * ウォレットを取得
     *
     * @return ウォレット
     */
    const optional<Wallet>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ウォレットを設定
     *
     * @param item ウォレット
     */
    void setItem(const Wallet& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GOLD_CONTROL_GETWALLETRESULT_HPP_