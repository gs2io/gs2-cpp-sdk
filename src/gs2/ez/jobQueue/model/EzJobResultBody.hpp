

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

#ifndef GS2_EZ_JOBQUEUE_MODEL_EZJOBRESULTBODY_HPP_
#define GS2_EZ_JOBQUEUE_MODEL_EZJOBRESULTBODY_HPP_

#include <gs2/jobQueue/model/JobResultBody.hpp>


namespace gs2 { namespace ez { namespace jobQueue {

class EzJobResultBody : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 試行回数 */
        gs2::optional<Int32> tryNumber;
        /** ステータスコード */
        gs2::optional<Int32> statusCode;
        /** レスポンスの内容 */
        gs2::optional<StringHolder> result;
        /** 実行日時 */
        gs2::optional<Int64> tryAt;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            tryNumber(data.tryNumber),
            statusCode(data.statusCode),
            result(data.result),
            tryAt(data.tryAt)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::jobQueue::JobResultBody& jobResultBody) :
            tryNumber(jobResultBody.getTryNumber() ? *jobResultBody.getTryNumber() : 0),
            statusCode(jobResultBody.getStatusCode() ? *jobResultBody.getStatusCode() : 0),
            result(jobResultBody.getResult()),
            tryAt(jobResultBody.getTryAt() ? *jobResultBody.getTryAt() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzJobResultBody() = default;
    EzJobResultBody(const EzJobResultBody& ezJobResultBody) = default;
    EzJobResultBody(EzJobResultBody&& ezJobResultBody) = default;
    ~EzJobResultBody() = default;

    EzJobResultBody(gs2::jobQueue::JobResultBody jobResultBody) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(jobResultBody)
    {}

    EzJobResultBody& operator=(const EzJobResultBody& ezJobResultBody) = default;
    EzJobResultBody& operator=(EzJobResultBody&& ezJobResultBody) = default;

    EzJobResultBody deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzJobResultBody);
    }

    gs2::jobQueue::JobResultBody ToModel() const
    {
        gs2::jobQueue::JobResultBody jobResultBody;
        jobResultBody.setTryNumber(getTryNumber());
        jobResultBody.setStatusCode(getStatusCode());
        jobResultBody.setResult(getResult());
        jobResultBody.setTryAt(getTryAt());
        return jobResultBody;
    }

    // ========================================
    //   Getters
    // ========================================

    Int32 getTryNumber() const
    {
        return *ensureData().tryNumber;
    }

    Int32 getStatusCode() const
    {
        return *ensureData().statusCode;
    }

    const StringHolder& getResult() const
    {
        return *ensureData().result;
    }

    Int64 getTryAt() const
    {
        return *ensureData().tryAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setTryNumber(Int32 tryNumber)
    {
        ensureData().tryNumber = tryNumber;
    }

    void setStatusCode(Int32 statusCode)
    {
        ensureData().statusCode = statusCode;
    }

    void setResult(StringHolder result)
    {
        ensureData().result = std::move(result);
    }

    void setTryAt(Int64 tryAt)
    {
        ensureData().tryAt = tryAt;
    }

    EzJobResultBody& withTryNumber(Int32 tryNumber)
    {
        setTryNumber(tryNumber);
        return *this;
    }

    EzJobResultBody& withStatusCode(Int32 statusCode)
    {
        setStatusCode(statusCode);
        return *this;
    }

    EzJobResultBody& withResult(StringHolder result)
    {
        setResult(std::move(result));
        return *this;
    }

    EzJobResultBody& withTryAt(Int64 tryAt)
    {
        setTryAt(tryAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_JOBQUEUE_EZJOBRESULTBODY_HPP_