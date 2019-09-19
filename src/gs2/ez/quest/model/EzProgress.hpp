

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

#include <gs2/quest/model/Progress.hpp>


namespace gs2 { namespace ez { namespace quest {

class EzProgress : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** クエスト挑戦 */
        gs2::optional<StringHolder> progressId;
        /** クエストモデル */
        gs2::optional<StringHolder> questModelId;
        /** 乱数シード */
        gs2::optional<Int64> randomSeed;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            progressId(data.progressId),
            questModelId(data.questModelId),
            randomSeed(data.randomSeed)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::quest::Progress& progress) :
            progressId(progress.getProgressId()),
            questModelId(progress.getQuestModelId()),
            randomSeed(progress.getRandomSeed() ? *progress.getRandomSeed() : 0)
        {
        }

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

    EzProgress(gs2::quest::Progress progress) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(progress)
    {}

    EzProgress& operator=(const EzProgress& ezProgress) = default;
    EzProgress& operator=(EzProgress&& ezProgress) = default;

    EzProgress deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzProgress);
    }

    gs2::quest::Progress ToModel() const
    {
        gs2::quest::Progress progress;
        progress.setProgressId(getProgressId());
        progress.setQuestModelId(getQuestModelId());
        progress.setRandomSeed(getRandomSeed());
        return progress;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getProgressId() const
    {
        return *ensureData().progressId;
    }

    const StringHolder& getQuestModelId() const
    {
        return *ensureData().questModelId;
    }

    Int64 getRandomSeed() const
    {
        return *ensureData().randomSeed;
    }

    // ========================================
    //   Setters
    // ========================================

    void setProgressId(StringHolder progressId)
    {
        ensureData().progressId = std::move(progressId);
    }

    void setQuestModelId(StringHolder questModelId)
    {
        ensureData().questModelId = std::move(questModelId);
    }

    void setRandomSeed(Int64 randomSeed)
    {
        ensureData().randomSeed = randomSeed;
    }

    EzProgress& withProgressId(StringHolder progressId)
    {
        setProgressId(std::move(progressId));
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
};

}}}

#endif //GS2_EZ_QUEST_EZPROGRESS_HPP_