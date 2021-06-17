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

#ifndef GS2_EZ_MATCHMAKING_EZVOTEMULTIPLERESULT_HPP_
#define GS2_EZ_MATCHMAKING_EZVOTEMULTIPLERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/matchmaking/result/VoteMultipleResult.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

class EzVoteMultipleResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 投票用紙 */
        EzBallot item;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::matchmaking::VoteMultipleResult& voteMultipleResult) :
            item(*voteMultipleResult.getItem())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzVoteMultipleResult() = default;
    EzVoteMultipleResult(const EzVoteMultipleResult& result) = default;
    EzVoteMultipleResult(EzVoteMultipleResult&& result) = default;
    ~EzVoteMultipleResult() = default;

    EzVoteMultipleResult(gs2::matchmaking::VoteMultipleResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzVoteMultipleResult& operator=(const EzVoteMultipleResult& result) = default;
    EzVoteMultipleResult& operator=(EzVoteMultipleResult&& result) = default;

    EzVoteMultipleResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzVoteMultipleResult);
    }

    static bool isConvertible(const gs2::matchmaking::VoteMultipleResult& result)
    {
        return
            result.getItem().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzBallot& getItem() const
    {
        return ensureData().item;
    }
};

typedef gs2::AsyncResult<EzVoteMultipleResult> AsyncEzVoteMultipleResult;

}}}

#endif //GS2_EZ_MATCHMAKING_EZVOTEMULTIPLERESULT_HPP_