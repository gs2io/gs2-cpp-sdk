

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
    /** 試行回数 */
    gs2::optional<Int32> m_TryNumber;
    /** ステータスコード */
    gs2::optional<Int32> m_StatusCode;
    /** レスポンスの内容 */
    gs2::optional<StringHolder> m_Result;
    /** 実行日時 */
    gs2::optional<Int64> m_TryAt;

public:
    EzJobResultBody() = default;

    EzJobResultBody(gs2::jobQueue::JobResultBody jobResultBody) :
        m_TryNumber(jobResultBody.getTryNumber() ? *jobResultBody.getTryNumber() : 0),
        m_StatusCode(jobResultBody.getStatusCode() ? *jobResultBody.getStatusCode() : 0),
        m_Result(jobResultBody.getResult()),
        m_TryAt(jobResultBody.getTryAt() ? *jobResultBody.getTryAt() : 0)
    {
    }

    gs2::jobQueue::JobResultBody ToModel() const
    {
        gs2::jobQueue::JobResultBody jobResultBody;
        jobResultBody.setTryNumber(*m_TryNumber);
        jobResultBody.setStatusCode(*m_StatusCode);
        jobResultBody.setResult(*m_Result);
        jobResultBody.setTryAt(*m_TryAt);
        return jobResultBody;
    }

    // ========================================
    //   Getters
    // ========================================

    Int32 getTryNumber() const
    {
        return *m_TryNumber;
    }

    Int32 getStatusCode() const
    {
        return *m_StatusCode;
    }

    const gs2::StringHolder& getResult() const
    {
        return *m_Result;
    }

    gs2::StringHolder& getResult()
    {
        return *m_Result;
    }

    Int64 getTryAt() const
    {
        return *m_TryAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setTryNumber(Int32 tryNumber)
    {
        m_TryNumber = tryNumber;
    }

    void setStatusCode(Int32 statusCode)
    {
        m_StatusCode = statusCode;
    }

    void setResult(Char* result)
    {
        m_Result.emplace(result);
    }

    void setTryAt(Int64 tryAt)
    {
        m_TryAt = tryAt;
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

    EzJobResultBody& withResult(Char* result)
    {
        setResult(result);
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