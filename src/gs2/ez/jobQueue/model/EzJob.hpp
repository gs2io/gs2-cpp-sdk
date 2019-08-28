

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
    /** ジョブ */
    gs2::optional<StringHolder> m_JobId;
    /** 現在のリトライ回数 */
    gs2::optional<Int32> m_CurrentRetryCount;
    /** 最大試行回数 */
    gs2::optional<Int32> m_MaxTryCount;

public:
    EzJob() = default;

    EzJob(gs2::jobQueue::Job job) :
        m_JobId(job.getJobId()),
        m_CurrentRetryCount(job.getCurrentRetryCount() ? *job.getCurrentRetryCount() : 0),
        m_MaxTryCount(job.getMaxTryCount() ? *job.getMaxTryCount() : 0)
    {
    }

    gs2::jobQueue::Job ToModel() const
    {
        gs2::jobQueue::Job job;
        job.setJobId(*m_JobId);
        job.setCurrentRetryCount(*m_CurrentRetryCount);
        job.setMaxTryCount(*m_MaxTryCount);
        return job;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getJobId() const
    {
        return *m_JobId;
    }

    gs2::StringHolder& getJobId()
    {
        return *m_JobId;
    }

    Int32 getCurrentRetryCount() const
    {
        return *m_CurrentRetryCount;
    }

    Int32 getMaxTryCount() const
    {
        return *m_MaxTryCount;
    }

    // ========================================
    //   Setters
    // ========================================

    void setJobId(Char* jobId)
    {
        m_JobId.emplace(jobId);
    }

    void setCurrentRetryCount(Int32 currentRetryCount)
    {
        m_CurrentRetryCount = currentRetryCount;
    }

    void setMaxTryCount(Int32 maxTryCount)
    {
        m_MaxTryCount = maxTryCount;
    }

    EzJob& withJobId(Char* jobId)
    {
        setJobId(jobId);
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