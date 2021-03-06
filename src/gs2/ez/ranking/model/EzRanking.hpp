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

#ifndef GS2_EZ_RANKING_MODEL_EZRANKING_HPP_
#define GS2_EZ_RANKING_MODEL_EZRANKING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace ranking {

class Ranking;

}

namespace ez { namespace ranking {

class EzRanking : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 順位 */
        gs2::optional<Int64> rank;
        /** 1位からのインデックス */
        gs2::optional<Int64> index;
        /** ユーザID */
        gs2::optional<StringHolder> userId;
        /** スコア */
        gs2::optional<Int64> score;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;
        /** 作成日時 */
        gs2::optional<Int64> createdAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::ranking::Ranking& ranking);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRanking() = default;
    EzRanking(const EzRanking& ezRanking) = default;
    EzRanking(EzRanking&& ezRanking) = default;
    ~EzRanking() = default;

    EzRanking(gs2::ranking::Ranking ranking);

    EzRanking& operator=(const EzRanking& ezRanking) = default;
    EzRanking& operator=(EzRanking&& ezRanking) = default;

    EzRanking deepCopy() const;

    gs2::ranking::Ranking ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    Int64 getRank() const
    {
        return *ensureData().rank;
    }

    Int64 getIndex() const
    {
        return *ensureData().index;
    }

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    Int64 getScore() const
    {
        return *ensureData().score;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    Int64 getCreatedAt() const
    {
        return *ensureData().createdAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setRank(Int64 rank)
    {
        ensureData().rank = rank;
    }

    void setIndex(Int64 index)
    {
        ensureData().index = index;
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setScore(Int64 score)
    {
        ensureData().score = score;
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    EzRanking& withRank(Int64 rank)
    {
        setRank(rank);
        return *this;
    }

    EzRanking& withIndex(Int64 index)
    {
        setIndex(index);
        return *this;
    }

    EzRanking& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzRanking& withScore(Int64 score)
    {
        setScore(score);
        return *this;
    }

    EzRanking& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzRanking& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_RANKING_EZRANKING_HPP_