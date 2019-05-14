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

#ifndef GS2_LOTTERY_MODEL_LOTTERY_HPP_
#define GS2_LOTTERY_MODEL_LOTTERY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * None
 *
 * @author Game Server Services, Inc.
 *
 */
class Lottery : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
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
    Lottery() :
        m_pData(nullptr)
    {}

    Lottery(const Lottery& lottery) :
        Gs2Object(lottery),
        m_pData(lottery.m_pData != nullptr ? new Data(*lottery.m_pData) : nullptr)
    {}

    Lottery(Lottery&& lottery) :
        Gs2Object(std::move(lottery)),
        m_pData(lottery.m_pData)
    {
        lottery.m_pData = nullptr;
    }

    ~Lottery()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Lottery& operator=(const Lottery& lottery)
    {
        Gs2Object::operator=(lottery);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*lottery.m_pData);

        return *this;
    }

    Lottery& operator=(Lottery&& lottery)
    {
        Gs2Object::operator=(std::move(lottery));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = lottery.m_pData;
        lottery.m_pData = nullptr;

        return *this;
    }

    const Lottery* operator->() const
    {
        return this;
    }

    Lottery* operator->()
    {
        return this;
    }

    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_LOTTERY_MODEL_LOTTERY_HPP_