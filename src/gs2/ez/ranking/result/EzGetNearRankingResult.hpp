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

#ifndef GS2_EZ_RANKING_EZGETNEARRANKINGRESULT_HPP_
#define GS2_EZ_RANKING_EZGETNEARRANKINGRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/ranking/result/DescribeNearRankingsResult.hpp>


namespace gs2 { namespace ez { namespace ranking {

class EzGetNearRankingResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ランキングのリスト */
        List<EzRanking> items;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::ranking::DescribeNearRankingsResult& describeNearRankingsResult)
        {
            {
                auto& list = *describeNearRankingsResult.getItems();
                for (int i = 0; i < list.getCount(); ++i)
                {
                    items += EzRanking(list[i]);
                }
            }
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGetNearRankingResult() = default;
    EzGetNearRankingResult(const EzGetNearRankingResult& result) = default;
    EzGetNearRankingResult(EzGetNearRankingResult&& result) = default;
    ~EzGetNearRankingResult() = default;

    EzGetNearRankingResult(gs2::ranking::DescribeNearRankingsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetNearRankingResult& operator=(const EzGetNearRankingResult& result) = default;
    EzGetNearRankingResult& operator=(EzGetNearRankingResult&& result) = default;

    EzGetNearRankingResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetNearRankingResult);
    }

    static bool isConvertible(const gs2::ranking::DescribeNearRankingsResult& result)
    {
        return
            result.getItems().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzRanking>& getItems() const
    {
        return ensureData().items;
    }
};

typedef gs2::AsyncResult<EzGetNearRankingResult> AsyncEzGetNearRankingResult;

}}}

#endif //GS2_EZ_RANKING_EZGETNEARRANKINGRESULT_HPP_