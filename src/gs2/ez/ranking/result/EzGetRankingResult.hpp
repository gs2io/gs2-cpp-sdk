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

#ifndef GS2_EZ_RANKING_EZGETRANKINGRESULT_HPP_
#define GS2_EZ_RANKING_EZGETRANKINGRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/ranking/result/DescribeRankingsResult.hpp>


namespace gs2 { namespace ez { namespace ranking {

class EzGetRankingResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ランキングのリスト */
        List<EzRanking> items;
        /** リストの続きを取得するためのページトークン */
        optional<StringHolder> nextPageToken;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            nextPageToken(data.nextPageToken)
        {
            items = data.items.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::ranking::DescribeRankingsResult& describeRankingsResult) :
            nextPageToken(describeRankingsResult.getNextPageToken())
        {
            if (describeRankingsResult.getItems())
            {
                auto& list = *describeRankingsResult.getItems();
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
    EzGetRankingResult() = default;
    EzGetRankingResult(const EzGetRankingResult& result) = default;
    EzGetRankingResult(EzGetRankingResult&& result) = default;
    ~EzGetRankingResult() = default;

    EzGetRankingResult(gs2::ranking::DescribeRankingsResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzGetRankingResult& operator=(const EzGetRankingResult& result) = default;
    EzGetRankingResult& operator=(EzGetRankingResult&& result) = default;

    EzGetRankingResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzGetRankingResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const List<EzRanking>& getItems() const
    {
        return ensureData().items;
    }

    const optional<StringHolder>& getNextPageToken() const
    {
        return ensureData().nextPageToken;
    }
};

typedef gs2::AsyncResult<EzGetRankingResult> AsyncEzGetRankingResult;

}}}

#endif //GS2_EZ_RANKING_EZGETRANKINGRESULT_HPP_