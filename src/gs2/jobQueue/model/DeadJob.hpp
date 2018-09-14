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

#ifndef GS2_JOBQUEUE_MODEL_DEADJOB_HPP_
#define GS2_JOBQUEUE_MODEL_DEADJOB_HPP_

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
class DeadJob : public Gs2Object
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
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            jobId(std::move(data.jobId)),
            queueId(std::move(data.queueId)),
            userId(std::move(data.userId)),
            scriptName(std::move(data.scriptName)),
            args(std::move(data.args)),
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
    DeadJob() :
        m_pData(nullptr)
    {}

    DeadJob(const DeadJob& deadJob) :
        Gs2Object(deadJob),
        m_pData(deadJob.m_pData != nullptr ? new Data(*deadJob.m_pData) : nullptr)
    {}

    DeadJob(DeadJob&& deadJob) :
        Gs2Object(std::move(deadJob)),
        m_pData(deadJob.m_pData)
    {
        deadJob.m_pData = nullptr;
    }

    ~DeadJob()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeadJob& operator=(const DeadJob& deadJob)
    {
        Gs2Object::operator=(deadJob);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deadJob.m_pData);

        return *this;
    }

    DeadJob& operator=(DeadJob&& deadJob)
    {
        Gs2Object::operator=(std::move(deadJob));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deadJob.m_pData;
        deadJob.m_pData = nullptr;

        return *this;
    }

    const DeadJob* operator->() const
    {
        return this;
    }

    DeadJob* operator->()
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

#endif //GS2_JOBQUEUE_MODEL_DEADJOB_HPP_