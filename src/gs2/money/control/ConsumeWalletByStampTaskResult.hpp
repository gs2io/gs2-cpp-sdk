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

#ifndef GS2_MONEY_CONTROL_CONSUMEWALLETBYSTAMPTASKRESULT_HPP_
#define GS2_MONEY_CONTROL_CONSUMEWALLETBYSTAMPTASKRESULT_HPP_

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
class ConsumeWalletByStampTaskResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ウォレット */
        optional<Summary> item;

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
    ConsumeWalletByStampTaskResult() :
        m_pData(nullptr)
    {}

    ConsumeWalletByStampTaskResult(const ConsumeWalletByStampTaskResult& consumeWalletByStampTaskResult) :
        Gs2Object(consumeWalletByStampTaskResult),
        m_pData(consumeWalletByStampTaskResult.m_pData != nullptr ? new Data(*consumeWalletByStampTaskResult.m_pData) : nullptr)
    {}

    ConsumeWalletByStampTaskResult(ConsumeWalletByStampTaskResult&& consumeWalletByStampTaskResult) :
        Gs2Object(std::move(consumeWalletByStampTaskResult)),
        m_pData(consumeWalletByStampTaskResult.m_pData)
    {
        consumeWalletByStampTaskResult.m_pData = nullptr;
    }

    ~ConsumeWalletByStampTaskResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ConsumeWalletByStampTaskResult& operator=(const ConsumeWalletByStampTaskResult& consumeWalletByStampTaskResult)
    {
        Gs2Object::operator=(consumeWalletByStampTaskResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*consumeWalletByStampTaskResult.m_pData);

        return *this;
    }

    ConsumeWalletByStampTaskResult& operator=(ConsumeWalletByStampTaskResult&& consumeWalletByStampTaskResult)
    {
        Gs2Object::operator=(std::move(consumeWalletByStampTaskResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = consumeWalletByStampTaskResult.m_pData;
        consumeWalletByStampTaskResult.m_pData = nullptr;

        return *this;
    }

    const ConsumeWalletByStampTaskResult* operator->() const
    {
        return this;
    }

    ConsumeWalletByStampTaskResult* operator->()
    {
        return this;
    }


    /**
     * ウォレットを取得
     *
     * @return ウォレット
     */
    const optional<Summary>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ウォレットを設定
     *
     * @param item ウォレット
     */
    void setItem(const Summary& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MONEY_CONTROL_CONSUMEWALLETBYSTAMPTASKRESULT_HPP_