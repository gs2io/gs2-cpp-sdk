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

#include "EzProgress.hpp"
#include <gs2/quest/model/Progress.hpp>


namespace gs2 { namespace ez { namespace quest {

EzProgress::Data::Data(const Data& data) :
    Gs2Object(data),
    progressId(data.progressId),
    transactionId(data.transactionId),
    questModelId(data.questModelId),
    randomSeed(data.randomSeed)
{
    if (data.rewards)
    {
        rewards = data.rewards->deepCopy();
    }
}

EzProgress::Data::Data(const gs2::quest::Progress& progress) :
    progressId(progress.getProgressId()),
    transactionId(progress.getTransactionId()),
    questModelId(progress.getQuestModelId()),
    randomSeed(progress.getRandomSeed() ? *progress.getRandomSeed() : 0)
{
    rewards.emplace();
    if (progress.getRewards())
    {
        for (int i = 0; i < progress.getRewards()->getCount(); ++i)
        {
            *rewards += EzReward((*progress.getRewards())[i]);
        }
    }
}

EzProgress::EzProgress(gs2::quest::Progress progress) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(progress)
{
}

EzProgress EzProgress::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzProgress);
}

gs2::quest::Progress EzProgress::ToModel() const
{
    gs2::quest::Progress progress;
    progress.setProgressId(getProgressId());
    progress.setTransactionId(getTransactionId());
    progress.setQuestModelId(getQuestModelId());
    progress.setRandomSeed(getRandomSeed());
    {
        gs2::List<gs2::quest::Reward> list;
        auto& rewards = getRewards();
        for (int i = 0; i < rewards.getCount(); ++i)
        {
            list += rewards[i].ToModel();
        }
        progress.setRewards(list);
    }
    return progress;
}

}}}