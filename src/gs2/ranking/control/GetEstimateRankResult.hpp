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

#ifndef GS2_RANKING_CONTROL_GETESTIMATERANKRESULT_HPP_
#define GS2_RANKING_CONTROL_GETESTIMATERANKRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace ranking
{

/**
 * @author Game Server Services, Inc.
 */
class GetEstimateRankResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 推定最小順位 */
        optional<Int64> min;
        /** 推定最大順位 */
        optional<Int64> max;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            min(data.min),
            max(data.max)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            min(std::move(data.min)),
            max(std::move(data.max))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "min") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->min = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "max") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->max = jsonValue.GetInt64();
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
    GetEstimateRankResult() :
        m_pData(nullptr)
    {}

    GetEstimateRankResult(const GetEstimateRankResult& getEstimateRankResult) :
        Gs2Object(getEstimateRankResult),
        m_pData(getEstimateRankResult.m_pData != nullptr ? new Data(*getEstimateRankResult.m_pData) : nullptr)
    {}

    GetEstimateRankResult(GetEstimateRankResult&& getEstimateRankResult) :
        Gs2Object(std::move(getEstimateRankResult)),
        m_pData(getEstimateRankResult.m_pData)
    {
        getEstimateRankResult.m_pData = nullptr;
    }

    ~GetEstimateRankResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetEstimateRankResult& operator=(const GetEstimateRankResult& getEstimateRankResult)
    {
        Gs2Object::operator=(getEstimateRankResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getEstimateRankResult.m_pData);

        return *this;
    }

    GetEstimateRankResult& operator=(GetEstimateRankResult&& getEstimateRankResult)
    {
        Gs2Object::operator=(std::move(getEstimateRankResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getEstimateRankResult.m_pData;
        getEstimateRankResult.m_pData = nullptr;

        return *this;
    }

    const GetEstimateRankResult* operator->() const
    {
        return this;
    }

    GetEstimateRankResult* operator->()
    {
        return this;
    }


    /**
     * 推定最小順位を取得
     *
     * @return 推定最小順位
     */
    const optional<Int64>& getMin() const
    {
        return ensureData().min;
    }

    /**
     * 推定最小順位を設定
     *
     * @param min 推定最小順位
     */
    void setMin(Int64 min)
    {
        ensureData().min.emplace(min);
    }

    /**
     * 推定最大順位を取得
     *
     * @return 推定最大順位
     */
    const optional<Int64>& getMax() const
    {
        return ensureData().max;
    }

    /**
     * 推定最大順位を設定
     *
     * @param max 推定最大順位
     */
    void setMax(Int64 max)
    {
        ensureData().max.emplace(max);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_RANKING_CONTROL_GETESTIMATERANKRESULT_HPP_