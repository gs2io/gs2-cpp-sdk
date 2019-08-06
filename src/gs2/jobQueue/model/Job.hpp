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
    friend bool operator!=(const Job& lhs, const Job& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ジョブ */
        optional<StringHolder> jobId;
        /** ジョブの名前 */
        optional<StringHolder> name;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** ジョブの実行に使用するスクリプト のGRN */
        optional<StringHolder> scriptId;
        /** 引数 */
        optional<StringHolder> args;
        /** 現在のリトライ回数 */
        optional<Int32> currentRetryCount;
        /** 最大試行回数 */
        optional<Int32> maxTryCount;
        /** ソート用インデックス(現在時刻(ミリ秒).登録時のインデックス) */
        optional<Double> index;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            jobId(data.jobId),
            name(data.name),
            userId(data.userId),
            scriptId(data.scriptId),
            args(data.args),
            currentRetryCount(data.currentRetryCount),
            maxTryCount(data.maxTryCount),
            index(data.index),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            jobId(std::move(data.jobId)),
            name(std::move(data.name)),
            userId(std::move(data.userId)),
            scriptId(std::move(data.scriptId)),
            args(std::move(data.args)),
            currentRetryCount(std::move(data.currentRetryCount)),
            maxTryCount(std::move(data.maxTryCount)),
            index(std::move(data.index)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "jobId") == 0) {
                if (jsonValue.IsString())
                {
                    this->jobId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "scriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->scriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "args") == 0) {
                if (jsonValue.IsString())
                {
                    this->args.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "currentRetryCount") == 0) {
                if (jsonValue.IsInt())
                {
                    this->currentRetryCount = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "maxTryCount") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxTryCount = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "index") == 0) {
                if (jsonValue.IsDouble())
                {
                    this->index = jsonValue.GetDouble();
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
     * ジョブを取得
     *
     * @return ジョブ
     */
    const optional<StringHolder>& getJobId() const
    {
        return ensureData().jobId;
    }

    /**
     * ジョブを設定
     *
     * @param jobId ジョブ
     */
    void setJobId(const Char* jobId)
    {
        ensureData().jobId.emplace(jobId);
    }

    /**
     * ジョブを設定
     *
     * @param jobId ジョブ
     */
    Job& withJobId(const Char* jobId)
    {
        setJobId(jobId);
        return *this;
    }

    /**
     * ジョブの名前を取得
     *
     * @return ジョブの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ジョブの名前を設定
     *
     * @param name ジョブの名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * ジョブの名前を設定
     *
     * @param name ジョブの名前
     */
    Job& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Job& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * ジョブの実行に使用するスクリプト のGRNを取得
     *
     * @return ジョブの実行に使用するスクリプト のGRN
     */
    const optional<StringHolder>& getScriptId() const
    {
        return ensureData().scriptId;
    }

    /**
     * ジョブの実行に使用するスクリプト のGRNを設定
     *
     * @param scriptId ジョブの実行に使用するスクリプト のGRN
     */
    void setScriptId(const Char* scriptId)
    {
        ensureData().scriptId.emplace(scriptId);
    }

    /**
     * ジョブの実行に使用するスクリプト のGRNを設定
     *
     * @param scriptId ジョブの実行に使用するスクリプト のGRN
     */
    Job& withScriptId(const Char* scriptId)
    {
        setScriptId(scriptId);
        return *this;
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
     * 引数を設定
     *
     * @param args 引数
     */
    Job& withArgs(const Char* args)
    {
        setArgs(args);
        return *this;
    }

    /**
     * 現在のリトライ回数を取得
     *
     * @return 現在のリトライ回数
     */
    const optional<Int32>& getCurrentRetryCount() const
    {
        return ensureData().currentRetryCount;
    }

    /**
     * 現在のリトライ回数を設定
     *
     * @param currentRetryCount 現在のリトライ回数
     */
    void setCurrentRetryCount(Int32 currentRetryCount)
    {
        ensureData().currentRetryCount.emplace(currentRetryCount);
    }

    /**
     * 現在のリトライ回数を設定
     *
     * @param currentRetryCount 現在のリトライ回数
     */
    Job& withCurrentRetryCount(Int32 currentRetryCount)
    {
        setCurrentRetryCount(currentRetryCount);
        return *this;
    }

    /**
     * 最大試行回数を取得
     *
     * @return 最大試行回数
     */
    const optional<Int32>& getMaxTryCount() const
    {
        return ensureData().maxTryCount;
    }

    /**
     * 最大試行回数を設定
     *
     * @param maxTryCount 最大試行回数
     */
    void setMaxTryCount(Int32 maxTryCount)
    {
        ensureData().maxTryCount.emplace(maxTryCount);
    }

    /**
     * 最大試行回数を設定
     *
     * @param maxTryCount 最大試行回数
     */
    Job& withMaxTryCount(Int32 maxTryCount)
    {
        setMaxTryCount(maxTryCount);
        return *this;
    }

    /**
     * ソート用インデックス(現在時刻(ミリ秒).登録時のインデックス)を取得
     *
     * @return ソート用インデックス(現在時刻(ミリ秒).登録時のインデックス)
     */
    const optional<Double>& getIndex() const
    {
        return ensureData().index;
    }

    /**
     * ソート用インデックス(現在時刻(ミリ秒).登録時のインデックス)を設定
     *
     * @param index ソート用インデックス(現在時刻(ミリ秒).登録時のインデックス)
     */
    void setIndex(Double index)
    {
        ensureData().index.emplace(index);
    }

    /**
     * ソート用インデックス(現在時刻(ミリ秒).登録時のインデックス)を設定
     *
     * @param index ソート用インデックス(現在時刻(ミリ秒).登録時のインデックス)
     */
    Job& withIndex(Double index)
    {
        setIndex(index);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Job& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Job& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Job& lhs, const Job& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->jobId != lhr.m_pData->jobId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->scriptId != lhr.m_pData->scriptId)
        {
            return true;
        }
        if (lhs.m_pData->args != lhr.m_pData->args)
        {
            return true;
        }
        if (lhs.m_pData->currentRetryCount != lhr.m_pData->currentRetryCount)
        {
            return true;
        }
        if (lhs.m_pData->maxTryCount != lhr.m_pData->maxTryCount)
        {
            return true;
        }
        if (lhs.m_pData->index != lhr.m_pData->index)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Job& lhs, const Job& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_JOBQUEUE_MODEL_JOB_HPP_