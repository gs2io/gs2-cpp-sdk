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

#include "EzJob.hpp"
#include <gs2/jobQueue/model/Job.hpp>


namespace gs2 { namespace ez { namespace jobQueue {

EzJob::Data::Data(const Data& data) :
    Gs2Object(data),
    jobId(data.jobId),
    scriptId(data.scriptId),
    args(data.args),
    currentRetryCount(data.currentRetryCount),
    maxTryCount(data.maxTryCount)
{
}

EzJob::Data::Data(const gs2::jobQueue::Job& job) :
    jobId(job.getJobId()),
    scriptId(job.getScriptId()),
    args(job.getArgs()),
    currentRetryCount(job.getCurrentRetryCount() ? *job.getCurrentRetryCount() : 0),
    maxTryCount(job.getMaxTryCount() ? *job.getMaxTryCount() : 0)
{
}

EzJob::EzJob(gs2::jobQueue::Job job) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(job)
{
}

EzJob EzJob::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzJob);
}

gs2::jobQueue::Job EzJob::ToModel() const
{
    gs2::jobQueue::Job job;
    job.setJobId(getJobId());
    job.setScriptId(getScriptId());
    job.setArgs(getArgs());
    job.setCurrentRetryCount(getCurrentRetryCount());
    job.setMaxTryCount(getMaxTryCount());
    return job;
}

}}}