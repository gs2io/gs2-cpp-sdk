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

#include "EzJobEntry.hpp"
#include <gs2/jobQueue/model/JobEntry.hpp>


namespace gs2 { namespace ez { namespace jobQueue {

EzJobEntry::Data::Data(const Data& data) :
    Gs2Object(data),
    scriptId(data.scriptId),
    args(data.args),
    maxTryCount(data.maxTryCount)
{
}

EzJobEntry::Data::Data(const gs2::jobQueue::JobEntry& jobEntry) :
    scriptId(jobEntry.getScriptId()),
    args(jobEntry.getArgs()),
    maxTryCount(jobEntry.getMaxTryCount() ? *jobEntry.getMaxTryCount() : 0)
{
}

EzJobEntry::EzJobEntry(gs2::jobQueue::JobEntry jobEntry) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(jobEntry)
{
}

EzJobEntry EzJobEntry::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzJobEntry);
}

gs2::jobQueue::JobEntry EzJobEntry::ToModel() const
{
    gs2::jobQueue::JobEntry jobEntry;
    jobEntry.setScriptId(getScriptId());
    jobEntry.setArgs(getArgs());
    jobEntry.setMaxTryCount(getMaxTryCount());
    return jobEntry;
}

}}}