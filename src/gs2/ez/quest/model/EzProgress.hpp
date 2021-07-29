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

#ifndef GS2_EZ_QUEST_MODEL_EZPROGRESS_HPP_
#define GS2_EZ_QUEST_MODEL_EZPROGRESS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzReward.hpp"
#include <memory>


namespace gs2 {

namespace quest {

class Progress;

}

namespace ez { namespace quest {

class EzProgress : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** クエスト挑戦 */
        StringHolder progressId;
        /** トランザクションID */
        StringHolder transactionId;
        /** クエストモデル */
        StringHolder questModelId;
        /** 乱数シード */
        Int64 randomSeed;
        /** クエストで得られる報酬の上限 */
        List<EzReward> rewards;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::quest::Progress& progress);
        Data(const gs2::optional<gs2::quest::Progress>& progress);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzProgress() = default;
    EzProgress(const EzProgress& ezProgress) = default;
    EzProgress(EzProgress&& ezProgress) = default;
    ~EzProgress() = default;

    EzProgress(gs2::quest::Progress progress);
    EzProgress(gs2::optional<gs2::quest::Progress> progress);

    EzProgress& operator=(const EzProgress& ezProgress) = default;
    EzProgress& operator=(EzProgress&& ezProgress) = default;

    EzProgress deepCopy() const;

    gs2::quest::Progress ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getProgressId() const
    {
        return ensureData().progressId;
    }

    const StringHolder& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    const StringHolder& getQuestModelId() const
    {
        return ensureData().questModelId;
    }

    Int64 getRandomSeed() const
    {
        return ensureData().randomSeed;
    }

    const List<EzReward>& getRewards() const
    {
        return ensureData().rewards;
    }

    // ========================================
    //   Setters
    // ========================================

    void setProgressId(StringHolder progressId)
    {
        ensureData().progressId = std::move(progressId);
    }

    void setTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId = std::move(transactionId);
    }

    void setQuestModelId(StringHolder questModelId)
    {
        ensureData().questModelId = std::move(questModelId);
    }

    void setRandomSeed(Int64 randomSeed)
    {
        ensureData().randomSeed = randomSeed;
    }

    void setRewards(List<EzReward> rewards)
    {
        ensureData().rewards = std::move(rewards);
    }

    EzProgress& withProgressId(StringHolder progressId)
    {
        setProgressId(std::move(progressId));
        return *this;
    }

    EzProgress& withTransactionId(StringHolder transactionId)
    {
        setTransactionId(std::move(transactionId));
        return *this;
    }

    EzProgress& withQuestModelId(StringHolder questModelId)
    {
        setQuestModelId(std::move(questModelId));
        return *this;
    }

    EzProgress& withRandomSeed(Int64 randomSeed)
    {
        setRandomSeed(randomSeed);
        return *this;
    }

    EzProgress& withRewards(List<EzReward> rewards)
    {
        setRewards(std::move(rewards));
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZPROGRESS_HPP_