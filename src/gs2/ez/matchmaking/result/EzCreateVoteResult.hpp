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

#ifndef GS2_EZ_MATCHMAKING_EZCREATEVOTERESULT_HPP_
#define GS2_EZ_MATCHMAKING_EZCREATEVOTERESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/matchmaking/result/GetBallotResult.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

class EzCreateVoteResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 投票用紙 */
        EzBallot item;
        /** 署名対象のデータ */
        StringHolder body;
        /** 署名データ */
        StringHolder signature;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            body(data.body),
            signature(data.signature)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::matchmaking::GetBallotResult& getBallotResult) :
            item(*getBallotResult.getItem()),
            body(*getBallotResult.getBody()),
            signature(*getBallotResult.getSignature())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzCreateVoteResult() = default;
    EzCreateVoteResult(const EzCreateVoteResult& result) = default;
    EzCreateVoteResult(EzCreateVoteResult&& result) = default;
    ~EzCreateVoteResult() = default;

    EzCreateVoteResult(gs2::matchmaking::GetBallotResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzCreateVoteResult& operator=(const EzCreateVoteResult& result) = default;
    EzCreateVoteResult& operator=(EzCreateVoteResult&& result) = default;

    EzCreateVoteResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCreateVoteResult);
    }

    static bool isConvertible(const gs2::matchmaking::GetBallotResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getBody().has_value() &&
            result.getSignature().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzBallot& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getBody() const
    {
        return ensureData().body;
    }

    const StringHolder& getSignature() const
    {
        return ensureData().signature;
    }
};

typedef gs2::AsyncResult<EzCreateVoteResult> AsyncEzCreateVoteResult;

}}}

#endif //GS2_EZ_MATCHMAKING_EZCREATEVOTERESULT_HPP_