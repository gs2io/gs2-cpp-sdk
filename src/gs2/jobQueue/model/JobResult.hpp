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

#ifndef GS2_JOBQUEUE_MODEL_JOBRESULT_HPP_
#define GS2_JOBQUEUE_MODEL_JOBRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace jobQueue {

/**
 * ジョブ実行結果
 *
 * @author Game Server Services, Inc.
 *
 */
class JobResult : public Gs2Object
{
    friend bool operator!=(const JobResult& lhs, const JobResult& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ジョブ実行結果 */
        optional<StringHolder> jobResultId;
        /** ジョブ */
        optional<StringHolder> jobId;
        /** None */
        optional<Int32> tryNumber;
        /** None */
        optional<Int32> statusCode;
        /** レスポンスの内容 */
        optional<StringHolder> result;
        /** 作成日時 */
        optional<Int64> tryAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    JobResult() = default;
    JobResult(const JobResult& jobResult) = default;
    JobResult(JobResult&& jobResult) = default;
    ~JobResult() = default;

    JobResult& operator=(const JobResult& jobResult) = default;
    JobResult& operator=(JobResult&& jobResult) = default;

    JobResult deepCopy() const;

    const JobResult* operator->() const
    {
        return this;
    }

    JobResult* operator->()
    {
        return this;
    }
    /**
     * ジョブ実行結果を取得
     *
     * @return ジョブ実行結果
     */
    const optional<StringHolder>& getJobResultId() const
    {
        return ensureData().jobResultId;
    }

    /**
     * ジョブ実行結果を設定
     *
     * @param jobResultId ジョブ実行結果
     */
    void setJobResultId(StringHolder jobResultId)
    {
        ensureData().jobResultId.emplace(std::move(jobResultId));
    }

    /**
     * ジョブ実行結果を設定
     *
     * @param jobResultId ジョブ実行結果
     */
    JobResult& withJobResultId(StringHolder jobResultId)
    {
        setJobResultId(std::move(jobResultId));
        return *this;
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
    void setJobId(StringHolder jobId)
    {
        ensureData().jobId.emplace(std::move(jobId));
    }

    /**
     * ジョブを設定
     *
     * @param jobId ジョブ
     */
    JobResult& withJobId(StringHolder jobId)
    {
        setJobId(std::move(jobId));
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int32>& getTryNumber() const
    {
        return ensureData().tryNumber;
    }

    /**
     * Noneを設定
     *
     * @param tryNumber None
     */
    void setTryNumber(Int32 tryNumber)
    {
        ensureData().tryNumber.emplace(tryNumber);
    }

    /**
     * Noneを設定
     *
     * @param tryNumber None
     */
    JobResult& withTryNumber(Int32 tryNumber)
    {
        setTryNumber(tryNumber);
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<Int32>& getStatusCode() const
    {
        return ensureData().statusCode;
    }

    /**
     * Noneを設定
     *
     * @param statusCode None
     */
    void setStatusCode(Int32 statusCode)
    {
        ensureData().statusCode.emplace(statusCode);
    }

    /**
     * Noneを設定
     *
     * @param statusCode None
     */
    JobResult& withStatusCode(Int32 statusCode)
    {
        setStatusCode(statusCode);
        return *this;
    }

    /**
     * レスポンスの内容を取得
     *
     * @return レスポンスの内容
     */
    const optional<StringHolder>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * レスポンスの内容を設定
     *
     * @param result レスポンスの内容
     */
    void setResult(StringHolder result)
    {
        ensureData().result.emplace(std::move(result));
    }

    /**
     * レスポンスの内容を設定
     *
     * @param result レスポンスの内容
     */
    JobResult& withResult(StringHolder result)
    {
        setResult(std::move(result));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getTryAt() const
    {
        return ensureData().tryAt;
    }

    /**
     * 作成日時を設定
     *
     * @param tryAt 作成日時
     */
    void setTryAt(Int64 tryAt)
    {
        ensureData().tryAt.emplace(tryAt);
    }

    /**
     * 作成日時を設定
     *
     * @param tryAt 作成日時
     */
    JobResult& withTryAt(Int64 tryAt)
    {
        setTryAt(tryAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const JobResult& lhs, const JobResult& lhr);

inline bool operator==(const JobResult& lhs, const JobResult& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_JOBQUEUE_MODEL_JOBRESULT_HPP_