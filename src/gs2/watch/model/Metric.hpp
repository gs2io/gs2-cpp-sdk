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

#ifndef GS2_WATCH_MODEL_METRIC_HPP_
#define GS2_WATCH_MODEL_METRIC_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace watch {

/**
 * メトリック
 *
 * @author Game Server Services, Inc.
 *
 */
class Metric : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** タイムスタンプ(エポック秒) */
        optional<Int32> timestamp;
        /** 値 */
        optional<Double> value;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            timestamp(data.timestamp),
            value(data.value)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            timestamp(std::move(data.timestamp)),
            value(std::move(data.value))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "timestamp") == 0) {
                if (jsonValue.IsInt())
                {
                    this->timestamp = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "value") == 0) {
                if (jsonValue.IsDouble())
                {
                    this->value = jsonValue.GetDouble();
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
    Metric() :
        m_pData(nullptr)
    {}

    Metric(const Metric& metric) :
        Gs2Object(metric),
        m_pData(metric.m_pData != nullptr ? new Data(*metric.m_pData) : nullptr)
    {}

    Metric(Metric&& metric) :
        Gs2Object(std::move(metric)),
        m_pData(metric.m_pData)
    {
        metric.m_pData = nullptr;
    }

    ~Metric()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Metric& operator=(const Metric& metric)
    {
        Gs2Object::operator=(metric);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*metric.m_pData);

        return *this;
    }

    Metric& operator=(Metric&& metric)
    {
        Gs2Object::operator=(std::move(metric));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = metric.m_pData;
        metric.m_pData = nullptr;

        return *this;
    }

    const Metric* operator->() const
    {
        return this;
    }

    Metric* operator->()
    {
        return this;
    }


    /**
     * タイムスタンプ(エポック秒)を取得
     *
     * @return タイムスタンプ(エポック秒)
     */
    const optional<Int32>& getTimestamp() const
    {
        return ensureData().timestamp;
    }

    /**
     * タイムスタンプ(エポック秒)を設定
     *
     * @param timestamp タイムスタンプ(エポック秒)
     */
    void setTimestamp(Int32 timestamp)
    {
        ensureData().timestamp.emplace(timestamp);
    }

    /**
     * 値を取得
     *
     * @return 値
     */
    const optional<Double>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 値を設定
     *
     * @param value 値
     */
    void setValue(Double value)
    {
        ensureData().value.emplace(value);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_WATCH_MODEL_METRIC_HPP_