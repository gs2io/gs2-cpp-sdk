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

#include "EzCompletedQuestList.hpp"
#include <gs2/quest/model/CompletedQuestList.hpp>


namespace gs2 { namespace ez { namespace quest {

EzCompletedQuestList::Data::Data(const Data& data) :
    Gs2Object(data),
    questGroupName(data.questGroupName)
{
    if (data.completeQuestNames)
    {
        completeQuestNames = data.completeQuestNames->deepCopy();
    }
}

EzCompletedQuestList::Data::Data(const gs2::quest::CompletedQuestList& completedQuestList) :
    questGroupName(completedQuestList.getQuestGroupName()),
    completeQuestNames(completedQuestList.getCompleteQuestNames())
{
}

EzCompletedQuestList::EzCompletedQuestList(gs2::quest::CompletedQuestList completedQuestList) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(completedQuestList)
{
}

EzCompletedQuestList EzCompletedQuestList::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCompletedQuestList);
}

gs2::quest::CompletedQuestList EzCompletedQuestList::ToModel() const
{
    gs2::quest::CompletedQuestList completedQuestList;
    completedQuestList.setQuestGroupName(getQuestGroupName());
    completedQuestList.setCompleteQuestNames(getCompleteQuestNames());
    return completedQuestList;
}

}}}