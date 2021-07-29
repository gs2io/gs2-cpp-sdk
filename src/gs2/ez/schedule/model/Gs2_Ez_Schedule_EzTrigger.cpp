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

#include "EzTrigger.hpp"
#include <gs2/schedule/model/Trigger.hpp>


namespace gs2 { namespace ez { namespace schedule {

EzTrigger::Data::Data(const Data& data) :
    Gs2Object(data),
    triggerId(data.triggerId),
    name(data.name),
    createdAt(data.createdAt),
    expiresAt(data.expiresAt)
{
}

EzTrigger::Data::Data(const gs2::schedule::Trigger& trigger) :
    triggerId(trigger.getTriggerId() ? *trigger.getTriggerId() : StringHolder()),
    name(trigger.getName() ? *trigger.getName() : StringHolder()),
    createdAt(trigger.getCreatedAt() ? *trigger.getCreatedAt() : 0),
    expiresAt(trigger.getExpiresAt() ? *trigger.getExpiresAt() : 0)
{
}

EzTrigger::Data::Data(const gs2::optional<gs2::schedule::Trigger>& trigger) :
    triggerId(trigger && trigger->getTriggerId() ? *trigger->getTriggerId() : StringHolder()),
    name(trigger && trigger->getName() ? *trigger->getName() : StringHolder()),
    createdAt(trigger && trigger->getCreatedAt() ? *trigger->getCreatedAt() : 0),
    expiresAt(trigger && trigger->getExpiresAt() ? *trigger->getExpiresAt() : 0)
{
}

EzTrigger::EzTrigger(gs2::schedule::Trigger trigger) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(trigger)
{
}

EzTrigger::EzTrigger(gs2::optional<gs2::schedule::Trigger> trigger) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(trigger)
{
}

EzTrigger EzTrigger::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzTrigger);
}

gs2::schedule::Trigger EzTrigger::ToModel() const
{
    gs2::schedule::Trigger trigger;
    trigger.setTriggerId(getTriggerId());
    trigger.setName(getName());
    trigger.setCreatedAt(getCreatedAt());
    trigger.setExpiresAt(getExpiresAt());
    return trigger;
}

}}}