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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

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
    Job() = default;
    Job(const Job& job) = default;
    Job(Job&& job) = default;
    ~Job() = default;

    Job& operator=(const Job& job) = default;
    Job& operator=(Job&& job) = default;

    Job deepCopy() const;

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
    void setJobId(StringHolder jobId)
    {
        ensureData().jobId.emplace(std::move(jobId));
    }

    /**
     * ジョブを設定
     *
     * @param jobId ジョブ
     */
    Job& withJobId(StringHolder jobId)
    {
        setJobId(std::move(jobId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ジョブの名前を設定
     *
     * @param name ジョブの名前
     */
    Job& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Job& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
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
    void setScriptId(StringHolder scriptId)
    {
        ensureData().scriptId.emplace(std::move(scriptId));
    }

    /**
     * ジョブの実行に使用するスクリプト のGRNを設定
     *
     * @param scriptId ジョブの実行に使用するスクリプト のGRN
     */
    Job& withScriptId(StringHolder scriptId)
    {
        setScriptId(std::move(scriptId));
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
    void setArgs(StringHolder args)
    {
        ensureData().args.emplace(std::move(args));
    }

    /**
     * 引数を設定
     *
     * @param args 引数
     */
    Job& withArgs(StringHolder args)
    {
        setArgs(std::move(args));
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

bool operator!=(const Job& lhs, const Job& lhr);

inline bool operator==(const Job& lhs, const Job& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_JOBQUEUE_MODEL_JOB_HPP_