

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

#ifndef GS2_EZ_JOBQUEUE_MODEL_EZJOB_HPP_
#define GS2_EZ_JOBQUEUE_MODEL_EZJOB_HPP_

#include <gs2/jobQueue/model/Job.hpp>


namespace gs2 { namespace ez { namespace jobQueue {

class EzJob : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ジョブ */
        gs2::optional<StringHolder> jobId;
        /** 現在のリトライ回数 */
        gs2::optional<Int32> currentRetryCount;
        /** 最大試行回数 */
        gs2::optional<Int32> maxTryCount;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            jobId(data.jobId),
            currentRetryCount(data.currentRetryCount),
            maxTryCount(data.maxTryCount)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::jobQueue::Job& job) :
            jobId(job.getJobId()),
            currentRetryCount(job.getCurrentRetryCount() ? *job.getCurrentRetryCount() : 0),
            maxTryCount(job.getMaxTryCount() ? *job.getMaxTryCount() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzJob() = default;
    EzJob(const EzJob& ezJob) = default;
    EzJob(EzJob&& ezJob) = default;
    ~EzJob() = default;

    EzJob(gs2::jobQueue::Job job) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(job)
    {}

    EzJob& operator=(const EzJob& ezJob) = default;
    EzJob& operator=(EzJob&& ezJob) = default;

    EzJob deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzJob);
    }

    gs2::jobQueue::Job ToModel() const
    {
        gs2::jobQueue::Job job;
        job.setJobId(getJobId());
        job.setCurrentRetryCount(getCurrentRetryCount());
        job.setMaxTryCount(getMaxTryCount());
        return job;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getJobId() const
    {
        return *ensureData().jobId;
    }

    Int32 getCurrentRetryCount() const
    {
        return *ensureData().currentRetryCount;
    }

    Int32 getMaxTryCount() const
    {
        return *ensureData().maxTryCount;
    }

    // ========================================
    //   Setters
    // ========================================

    void setJobId(StringHolder jobId)
    {
        ensureData().jobId = std::move(jobId);
    }

    void setCurrentRetryCount(Int32 currentRetryCount)
    {
        ensureData().currentRetryCount = currentRetryCount;
    }

    void setMaxTryCount(Int32 maxTryCount)
    {
        ensureData().maxTryCount = maxTryCount;
    }

    EzJob& withJobId(StringHolder jobId)
    {
        setJobId(std::move(jobId));
        return *this;
    }

    EzJob& withCurrentRetryCount(Int32 currentRetryCount)
    {
        setCurrentRetryCount(currentRetryCount);
        return *this;
    }

    EzJob& withMaxTryCount(Int32 maxTryCount)
    {
        setMaxTryCount(maxTryCount);
        return *this;
    }
};

}}}

#endif //GS2_EZ_JOBQUEUE_EZJOB_HPP_