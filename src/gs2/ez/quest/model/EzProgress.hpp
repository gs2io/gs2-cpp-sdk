

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
    /** クエスト挑戦 */
    gs2::optional<StringHolder> m_ProgressId;
    /** クエストモデル */
    gs2::optional<StringHolder> m_QuestModelId;
    /** 乱数シード */
    gs2::optional<Int64> m_RandomSeed;

public:
    EzProgress() = default;

    EzProgress(gs2::quest::Progress progress) :
        m_ProgressId(progress.getProgressId()),
        m_QuestModelId(progress.getQuestModelId()),
        m_RandomSeed(progress.getRandomSeed() ? *progress.getRandomSeed() : 0)
    {
    }

    gs2::quest::Progress ToModel() const
    {
        gs2::quest::Progress progress;
        progress.setProgressId(*m_ProgressId);
        progress.setQuestModelId(*m_QuestModelId);
        progress.setRandomSeed(*m_RandomSeed);
        return progress;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getProgressId() const
    {
        return *m_ProgressId;
    }

    gs2::StringHolder& getProgressId()
    {
        return *m_ProgressId;
    }

    const gs2::StringHolder& getQuestModelId() const
    {
        return *m_QuestModelId;
    }

    gs2::StringHolder& getQuestModelId()
    {
        return *m_QuestModelId;
    }

    Int64 getRandomSeed() const
    {
        return *m_RandomSeed;
    }

    // ========================================
    //   Setters
    // ========================================

    void setProgressId(Char* progressId)
    {
        m_ProgressId.emplace(progressId);
    }

    void setQuestModelId(Char* questModelId)
    {
        m_QuestModelId.emplace(questModelId);
    }

    void setRandomSeed(Int64 randomSeed)
    {
        m_RandomSeed = randomSeed;
    }

    EzProgress& withProgressId(Char* progressId)
    {
        setProgressId(progressId);
        return *this;
    }

    EzProgress& withQuestModelId(Char* questModelId)
    {
        setQuestModelId(questModelId);
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