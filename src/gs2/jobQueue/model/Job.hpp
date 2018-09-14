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

#ifndef GS2_JOBQUEUE_MODEL_JOB_HPP_
#define GS2_JOBQUEUE_MODEL_JOB_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace jobQueue {

/**
 * ジョブ
 *
 * @author Game Server Services, Inc.
 *
 */
class Job : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ジョブID */
        optional<StringHolder> jobId;
        /** キューGRN */
        optional<StringHolder> queueId;
        /** オーナーID */
        optional<StringHolder> userId;
        /** スクリプト名 */
        optional<StringHolder> scriptName;
        /** 引数 */
        optional<StringHolder> args;
        /** 現在のリトライ回数 */
        optional<Int32> currentRetry;
        /** 最大リトライ回数 */
        optional<Int32> maxRetry;
        /** 作成日時 */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            jobId(data.jobId),
            queueId(data.queueId),
            userId(data.userId),
            scriptName(data.scriptName),
            args(data.args),
            currentRetry(data.currentRetry),
            maxRetry(data.maxRetry),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            jobId(std::move(data.jobId)),
            queueId(std::move(data.queueId)),
            userId(std::move(data.userId)),
            scriptName(std::move(data.scriptName)),
            args(std::move(data.args)),
            currentRetry(std::move(data.currentRetry)),
            maxRetry(std::move(data.maxRetry)),
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
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "scriptName") == 0) {
                if (jsonValue.IsString())
                {
                    this->scriptName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "args") == 0) {
                if (jsonValue.IsString())
                {
                    this->args.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "currentRetry") == 0) {
                if (jsonValue.IsInt())
                {
                    this->currentRetry = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "maxRetry") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxRetry = jsonValue.GetInt();
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
    Job() :
        m_pData(nullptr)
    {}

    Job(const Job& job) :
        Gs2Object(job),
        m_pData(job.m_pData != nullptr ? new Data(*job.m_pData) : nullptr)
    {}

    Job(Job&& job) :
        Gs2Object(std::move(job)),
        m_pData(job.m_pData)
    {
        job.m_pData = nullptr;
    }

    ~Job()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Job& operator=(const Job& job)
    {
        Gs2Object::operator=(job);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*job.m_pData);

        return *this;
    }

    Job& operator=(Job&& job)
    {
        Gs2Object::operator=(std::move(job));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = job.m_pData;
        job.m_pData = nullptr;

        return *this;
    }

    const Job* operator->() const
    {
        return this;
    }

    Job* operator->()
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
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * オーナーIDを設定
     *
     * @param userId オーナーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * スクリプト名を取得
     *
     * @return スクリプト名
     */
    const optional<StringHolder>& getScriptName() const
    {
        return ensureData().scriptName;
    }

    /**
     * スクリプト名を設定
     *
     * @param scriptName スクリプト名
     */
    void setScriptName(const Char* scriptName)
    {
        ensureData().scriptName.emplace(scriptName);
    }

    /**
     * 引数を取得
     *
     * @return 引数
     */
    const optional<StringHolder>& getArgs() const
    {
        return ensureData().args;
    }

    /**
     * 引数を設定
     *
     * @param args 引数
     */
    void setArgs(const Char* args)
    {
        ensureData().args.emplace(args);
    }

    /**
     * 現在のリトライ回数を取得
     *
     * @return 現在のリトライ回数
     */
    const optional<Int32>& getCurrentRetry() const
    {
        return ensureData().currentRetry;
    }

    /**
     * 現在のリトライ回数を設定
     *
     * @param currentRetry 現在のリトライ回数
     */
    void setCurrentRetry(Int32 currentRetry)
    {
        ensureData().currentRetry.emplace(currentRetry);
    }

    /**
     * 最大リトライ回数を取得
     *
     * @return 最大リトライ回数
     */
    const optional<Int32>& getMaxRetry() const
    {
        return ensureData().maxRetry;
    }

    /**
     * 最大リトライ回数を設定
     *
     * @param maxRetry 最大リトライ回数
     */
    void setMaxRetry(Int32 maxRetry)
    {
        ensureData().maxRetry.emplace(maxRetry);
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

#endif //GS2_JOBQUEUE_MODEL_JOB_HPP_