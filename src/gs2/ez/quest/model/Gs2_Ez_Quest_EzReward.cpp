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

#include "EzReward.hpp"
#include <gs2/quest/model/Reward.hpp>


namespace gs2 { namespace ez { namespace quest {

EzReward::Data::Data(const Data& data) :
    Gs2Object(data),
    action(data.action),
    request(data.request),
    itemId(data.itemId),
    value(data.value)
{
}

EzReward::Data::Data(const gs2::quest::Reward& reward) :
    action(reward.getAction() ? *reward.getAction() : StringHolder()),
    request(reward.getRequest() ? *reward.getRequest() : StringHolder()),
    itemId(reward.getItemId() ? *reward.getItemId() : StringHolder()),
    value(reward.getValue() ? *reward.getValue() : 0)
{
}

EzReward::Data::Data(const gs2::optional<gs2::quest::Reward>& reward) :
    action(reward && reward->getAction() ? *reward->getAction() : StringHolder()),
    request(reward && reward->getRequest() ? *reward->getRequest() : StringHolder()),
    itemId(reward && reward->getItemId() ? *reward->getItemId() : StringHolder()),
    value(reward && reward->getValue() ? *reward->getValue() : 0)
{
}

EzReward::EzReward(gs2::quest::Reward reward) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(reward)
{
}

EzReward::EzReward(gs2::optional<gs2::quest::Reward> reward) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(reward)
{
}

EzReward EzReward::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzReward);
}

gs2::quest::Reward EzReward::ToModel() const
{
    gs2::quest::Reward reward;
    reward.setAction(getAction());
    reward.setRequest(getRequest());
    reward.setItemId(getItemId());
    reward.setValue(getValue());
    return reward;
}

}}}