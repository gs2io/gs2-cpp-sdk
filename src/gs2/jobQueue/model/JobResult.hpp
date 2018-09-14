/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_JOBQUEUE_MODEL_JOBRESULT_HPP_
#define GS2_JOBQUEUE_MODEL_JOBRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace jobQueue {

/**
 * ジョブ結果
 *
 * @author Game Server Services, Inc.
 *
 */
class JobResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ジョブID */
        optional<StringHolder> jobId;
        /** キューGRN */
        optional<StringHolder> queueId;
        /** ステータスコード */
        optional<Int32> statusCode;
        /** 実行結果 */
        optional<StringHolder> result;
        /** キューの中で最後のジョブだったか */
        optional<Bool> endOfJob;
        /** 作成日時 */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            jobId(data.jobId),
            queueId(data.queueId),
            statusCode(data.statusCode),
            result(data.result),
            endOfJob(data.endOfJob),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            jobId(std::move(data.jobId)),
            queueId(std::move(data.queueId)),
            statusCode(std::move(data.statusCode)),
            result(std::move(data.result)),
            endOfJob(std::move(data.endOfJob)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "jobId") == 0) {
                if (jsonValue.IsString())
                {
                    this->jobId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "queueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->queueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "statusCode") == 0) {
                if (jsonValue.IsInt())
                {
                    this->statusCode = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "result") == 0) {
                if (jsonValue.IsString())
                {
                    this->result.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "endOfJob") == 0) {
                if (jsonValue.IsBool())
                {
                    this->endOfJob = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
        }
    };
    
    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    JobResult() :
        m_pData(nullptr)
    {}

    JobResult(const JobResult& jobResult) :
        Gs2Object(jobResult),
        m_pData(jobResult.m_pData != nullptr ? new Data(*jobResult.m_pData) : nullptr)
    {}

    JobResult(JobResult&& jobResult) :
        Gs2Object(std::move(jobResult)),
        m_pData(jobResult.m_pData)
    {
        jobResult.m_pData = nullptr;
    }

    ~JobResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    JobResult& operator=(const JobResult& jobResult)
    {
        Gs2Object::operator=(jobResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*jobResult.m_pData);

        return *this;
    }

    JobResult& operator=(JobResult&& jobResult)
    {
        Gs2Object::operator=(std::move(jobResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = jobResult.m_pData;
        jobResult.m_pData = nullptr;

        return *this;
    }

    const JobResult* operator->() const
    {
        return this;
    }

    JobResult* operator->()
    {
        return this;
    }


    /**
     * ジョブIDを取得
     *
     * @return ジョブID
     */
    const optional<StringHolder>& getJobId() const
    {
        return ensureData().jobId;
    }

    /**
     * ジョブIDを設定
     *
     * @param jobId ジョブID
     */
    void setJobId(const Char* jobId)
    {
        ensureData().jobId.emplace(jobId);
    }

    /**
     * キューGRNを取得
     *
     * @return キューGRN
     */
    const optional<StringHolder>& getQueueId() const
    {
        return ensureData().queueId;
    }

    /**
     * キューGRNを設定
     *
     * @param queueId キューGRN
     */
    void setQueueId(const Char* queueId)
    {
        ensureData().queueId.emplace(queueId);
    }

    /**
     * ステータスコードを取得
     *
     * @return ステータスコード
     */
    const optional<Int32>& getStatusCode() const
    {
        return ensureData().statusCode;
    }

    /**
     * ステータスコードを設定
     *
     * @param statusCode ステータスコード
     */
    void setStatusCode(Int32 statusCode)
    {
        ensureData().statusCode.emplace(statusCode);
    }

    /**
     * 実行結果を取得
     *
     * @return 実行結果
     */
    const optional<StringHolder>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * 実行結果を設定
     *
     * @param result 実行結果
     */
    void setResult(const Char* result)
    {
        ensureData().result.emplace(result);
    }

    /**
     * キューの中で最後のジョブだったかを取得
     *
     * @return キューの中で最後のジョブだったか
     */
    const optional<Bool>& getEndOfJob() const
    {
        return ensureData().endOfJob;
    }

    /**
     * キューの中で最後のジョブだったかを設定
     *
     * @param endOfJob キューの中で最後のジョブだったか
     */
    void setEndOfJob(Bool endOfJob)
    {
        ensureData().endOfJob.emplace(endOfJob);
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_JOBQUEUE_MODEL_JOBRESULT_HPP_