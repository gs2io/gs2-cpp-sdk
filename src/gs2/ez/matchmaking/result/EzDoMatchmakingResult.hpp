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

#ifndef GS2_EZ_MATCHMAKING_EZDOMATCHMAKINGRESULT_HPP_
#define GS2_EZ_MATCHMAKING_EZDOMATCHMAKINGRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/matchmaking/result/DoMatchmakingResult.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

class EzDoMatchmakingResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ギャザリング */
        EzGathering item;
        /** マッチメイキングの状態を保持するトークン */
        StringHolder matchmakingContextToken;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            matchmakingContextToken(data.matchmakingContextToken)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::matchmaking::DoMatchmakingResult& doMatchmakingResult) :
            item(*doMatchmakingResult.getItem()),
            matchmakingContextToken(*doMatchmakingResult.getMatchmakingContextToken())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzDoMatchmakingResult() = default;
    EzDoMatchmakingResult(const EzDoMatchmakingResult& result) = default;
    EzDoMatchmakingResult(EzDoMatchmakingResult&& result) = default;
    ~EzDoMatchmakingResult() = default;

    EzDoMatchmakingResult(gs2::matchmaking::DoMatchmakingResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzDoMatchmakingResult& operator=(const EzDoMatchmakingResult& result) = default;
    EzDoMatchmakingResult& operator=(EzDoMatchmakingResult&& result) = default;

    EzDoMatchmakingResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDoMatchmakingResult);
    }

    static bool isConvertible(const gs2::matchmaking::DoMatchmakingResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getMatchmakingContextToken().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzGathering& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getMatchmakingContextToken() const
    {
        return ensureData().matchmakingContextToken;
    }
};

typedef gs2::AsyncResult<EzDoMatchmakingResult> AsyncEzDoMatchmakingResult;

}}}

#endif //GS2_EZ_MATCHMAKING_EZDOMATCHMAKINGRESULT_HPP_