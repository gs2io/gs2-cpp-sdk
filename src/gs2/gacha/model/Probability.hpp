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

#ifndef GS2_GACHA_MODEL_PROBABILITY_HPP_
#define GS2_GACHA_MODEL_PROBABILITY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gacha {

/**
 * レアリティ毎の排出率
 *
 * @author Game Server Services, Inc.
 *
 */
class Probability : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** レアリティ名 */
        optional<StringHolder> name;
        /** 排出率 */
        optional<Float> rate;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            name(data.name),
            rate(data.rate)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            name(std::move(data.name)),
            rate(std::move(data.rate))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "rate") == 0) {
                if (jsonValue.IsFloat())
                {
                    this->rate = jsonValue.GetFloat();
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
    Probability() :
        m_pData(nullptr)
    {}

    Probability(const Probability& probability) :
        Gs2Object(probability),
        m_pData(probability.m_pData != nullptr ? new Data(*probability.m_pData) : nullptr)
    {}

    Probability(Probability&& probability) :
        Gs2Object(std::move(probability)),
        m_pData(probability.m_pData)
    {
        probability.m_pData = nullptr;
    }

    ~Probability()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Probability& operator=(const Probability& probability)
    {
        Gs2Object::operator=(probability);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*probability.m_pData);

        return *this;
    }

    Probability& operator=(Probability&& probability)
    {
        Gs2Object::operator=(std::move(probability));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = probability.m_pData;
        probability.m_pData = nullptr;

        return *this;
    }

    const Probability* operator->() const
    {
        return this;
    }

    Probability* operator->()
    {
        return this;
    }


    /**
     * レアリティ名を取得
     *
     * @return レアリティ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * レアリティ名を設定
     *
     * @param name レアリティ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 排出率を取得
     *
     * @return 排出率
     */
    const optional<Float>& getRate() const
    {
        return ensureData().rate;
    }

    /**
     * 排出率を設定
     *
     * @param rate 排出率
     */
    void setRate(Float rate)
    {
        ensureData().rate.emplace(rate);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GACHA_MODEL_PROBABILITY_HPP_