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

#ifndef GS2_MONEY_CONTROL_WITHDRAWRESULT_HPP_
#define GS2_MONEY_CONTROL_WITHDRAWRESULT_HPP_

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
 * ウォレットから残高を消費します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class WithdrawResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 消費後のウォレット */
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
    WithdrawResult() :
        m_pData(nullptr)
    {}

    WithdrawResult(const WithdrawResult& withdrawResult) :
        Gs2Object(withdrawResult),
        m_pData(withdrawResult.m_pData != nullptr ? new Data(*withdrawResult.m_pData) : nullptr)
    {}

    WithdrawResult(WithdrawResult&& withdrawResult) :
        Gs2Object(std::move(withdrawResult)),
        m_pData(withdrawResult.m_pData)
    {
        withdrawResult.m_pData = nullptr;
    }

    ~WithdrawResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WithdrawResult& operator=(const WithdrawResult& withdrawResult)
    {
        Gs2Object::operator=(withdrawResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*withdrawResult.m_pData);

        return *this;
    }

    WithdrawResult& operator=(WithdrawResult&& withdrawResult)
    {
        Gs2Object::operator=(std::move(withdrawResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = withdrawResult.m_pData;
        withdrawResult.m_pData = nullptr;

        return *this;
    }

    const WithdrawResult* operator->() const
    {
        return this;
    }

    WithdrawResult* operator->()
    {
        return this;
    }
    /**
     * 消費後のウォレットを取得
     *
     * @return 消費後のウォレット
     */
    const optional<Wallet>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * 消費後のウォレットを設定
     *
     * @param item 消費後のウォレット
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

#endif //GS2_MONEY_CONTROL_WITHDRAWRESULT_HPP_