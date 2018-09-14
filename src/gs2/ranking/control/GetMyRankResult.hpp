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

#ifndef GS2_RANKING_CONTROL_GETMYRANKRESULT_HPP_
#define GS2_RANKING_CONTROL_GETMYRANKRESULT_HPP_

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
class GetMyRankResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 先頭からの位置 */
        optional<Int64> index;
        /** 同点同順位を採用した場合の順位 */
        optional<Int64> rank;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            index(data.index),
            rank(data.rank)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            index(std::move(data.index)),
            rank(std::move(data.rank))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "index") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->index = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "rank") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->rank = jsonValue.GetInt64();
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
    GetMyRankResult() :
        m_pData(nullptr)
    {}

    GetMyRankResult(const GetMyRankResult& getMyRankResult) :
        Gs2Object(getMyRankResult),
        m_pData(getMyRankResult.m_pData != nullptr ? new Data(*getMyRankResult.m_pData) : nullptr)
    {}

    GetMyRankResult(GetMyRankResult&& getMyRankResult) :
        Gs2Object(std::move(getMyRankResult)),
        m_pData(getMyRankResult.m_pData)
    {
        getMyRankResult.m_pData = nullptr;
    }

    ~GetMyRankResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMyRankResult& operator=(const GetMyRankResult& getMyRankResult)
    {
        Gs2Object::operator=(getMyRankResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMyRankResult.m_pData);

        return *this;
    }

    GetMyRankResult& operator=(GetMyRankResult&& getMyRankResult)
    {
        Gs2Object::operator=(std::move(getMyRankResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMyRankResult.m_pData;
        getMyRankResult.m_pData = nullptr;

        return *this;
    }

    const GetMyRankResult* operator->() const
    {
        return this;
    }

    GetMyRankResult* operator->()
    {
        return this;
    }


    /**
     * 先頭からの位置を取得
     *
     * @return 先頭からの位置
     */
    const optional<Int64>& getIndex() const
    {
        return ensureData().index;
    }

    /**
     * 先頭からの位置を設定
     *
     * @param index 先頭からの位置
     */
    void setIndex(Int64 index)
    {
        ensureData().index.emplace(index);
    }

    /**
     * 同点同順位を採用した場合の順位を取得
     *
     * @return 同点同順位を採用した場合の順位
     */
    const optional<Int64>& getRank() const
    {
        return ensureData().rank;
    }

    /**
     * 同点同順位を採用した場合の順位を設定
     *
     * @param rank 同点同順位を採用した場合の順位
     */
    void setRank(Int64 rank)
    {
        ensureData().rank.emplace(rank);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_RANKING_CONTROL_GETMYRANKRESULT_HPP_