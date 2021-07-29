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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace jobQueue {

class Job;

}

namespace ez { namespace jobQueue {

class EzJob : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ジョブ */
        StringHolder jobId;
        /** ジョブの実行に使用するスクリプト のGRN */
        StringHolder scriptId;
        /** 引数 */
        StringHolder args;
        /** 現在のリトライ回数 */
        Int32 currentRetryCount;
        /** 最大試行回数 */
        Int32 maxTryCount;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::jobQueue::Job& job);
        Data(const gs2::optional<gs2::jobQueue::Job>& job);
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

    EzJob(gs2::jobQueue::Job job);
    EzJob(gs2::optional<gs2::jobQueue::Job> job);

    EzJob& operator=(const EzJob& ezJob) = default;
    EzJob& operator=(EzJob&& ezJob) = default;

    EzJob deepCopy() const;

    gs2::jobQueue::Job ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getJobId() const
    {
        return ensureData().jobId;
    }

    const StringHolder& getScriptId() const
    {
        return ensureData().scriptId;
    }

    const StringHolder& getArgs() const
    {
        return ensureData().args;
    }

    Int32 getCurrentRetryCount() const
    {
        return ensureData().currentRetryCount;
    }

    Int32 getMaxTryCount() const
    {
        return ensureData().maxTryCount;
    }

    // ========================================
    //   Setters
    // ========================================

    void setJobId(StringHolder jobId)
    {
        ensureData().jobId = std::move(jobId);
    }

    void setScriptId(StringHolder scriptId)
    {
        ensureData().scriptId = std::move(scriptId);
    }

    void setArgs(StringHolder args)
    {
        ensureData().args = std::move(args);
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

    EzJob& withScriptId(StringHolder scriptId)
    {
        setScriptId(std::move(scriptId));
        return *this;
    }

    EzJob& withArgs(StringHolder args)
    {
        setArgs(std::move(args));
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