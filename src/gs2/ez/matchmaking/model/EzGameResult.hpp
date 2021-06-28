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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZGAMERESULT_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZGAMERESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace matchmaking {

class GameResult;

}

namespace ez { namespace matchmaking {

class EzGameResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 順位 */
        gs2::optional<Int32> rank;
        /** ユーザーID */
        gs2::optional<StringHolder> userId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::matchmaking::GameResult& gameResult);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzGameResult() = default;
    EzGameResult(const EzGameResult& ezGameResult) = default;
    EzGameResult(EzGameResult&& ezGameResult) = default;
    ~EzGameResult() = default;

    EzGameResult(gs2::matchmaking::GameResult gameResult);

    EzGameResult& operator=(const EzGameResult& ezGameResult) = default;
    EzGameResult& operator=(EzGameResult&& ezGameResult) = default;

    EzGameResult deepCopy() const;

    gs2::matchmaking::GameResult ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    Int32 getRank() const
    {
        return *ensureData().rank;
    }

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setRank(Int32 rank)
    {
        ensureData().rank = rank;
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    EzGameResult& withRank(Int32 rank)
    {
        setRank(rank);
        return *this;
    }

    EzGameResult& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZGAMERESULT_HPP_