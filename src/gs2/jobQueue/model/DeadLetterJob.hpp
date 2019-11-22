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

#ifndef GS2_JOBQUEUE_MODEL_DEADLETTERJOB_HPP_
#define GS2_JOBQUEUE_MODEL_DEADLETTERJOB_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "JobResultBody.hpp"
#include <memory>

namespace gs2 { namespace jobQueue {

/**
 * デッドレタージョブ
 *
 * @author Game Server Services, Inc.
 *
 */
class DeadLetterJob : public Gs2Object
{
    friend bool operator!=(const DeadLetterJob& lhs, const DeadLetterJob& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** デッドレタージョブ */
        optional<StringHolder> deadLetterJobId;
        /** ジョブの名前 */
        optional<StringHolder> name;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** ジョブの実行に使用するスクリプト のGRN */
        optional<StringHolder> scriptId;
        /** 引数 */
        optional<StringHolder> args;
        /** ジョブ実行結果 */
        optional<List<JobResultBody>> result;
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
    DeadLetterJob() = default;
    DeadLetterJob(const DeadLetterJob& deadLetterJob) = default;
    DeadLetterJob(DeadLetterJob&& deadLetterJob) = default;
    ~DeadLetterJob() = default;

    DeadLetterJob& operator=(const DeadLetterJob& deadLetterJob) = default;
    DeadLetterJob& operator=(DeadLetterJob&& deadLetterJob) = default;

    DeadLetterJob deepCopy() const;

    const DeadLetterJob* operator->() const
    {
        return this;
    }

    DeadLetterJob* operator->()
    {
        return this;
    }
    /**
     * デッドレタージョブを取得
     *
     * @return デッドレタージョブ
     */
    const optional<StringHolder>& getDeadLetterJobId() const
    {
        return ensureData().deadLetterJobId;
    }

    /**
     * デッドレタージョブを設定
     *
     * @param deadLetterJobId デッドレタージョブ
     */
    void setDeadLetterJobId(StringHolder deadLetterJobId)
    {
        ensureData().deadLetterJobId.emplace(std::move(deadLetterJobId));
    }

    /**
     * デッドレタージョブを設定
     *
     * @param deadLetterJobId デッドレタージョブ
     */
    DeadLetterJob& withDeadLetterJobId(StringHolder deadLetterJobId)
    {
        setDeadLetterJobId(std::move(deadLetterJobId));
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
    DeadLetterJob& withName(StringHolder name)
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
    DeadLetterJob& withUserId(StringHolder userId)
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
    DeadLetterJob& withScriptId(StringHolder scriptId)
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
    DeadLetterJob& withArgs(StringHolder args)
    {
        setArgs(std::move(args));
        return *this;
    }

    /**
     * ジョブ実行結果を取得
     *
     * @return ジョブ実行結果
     */
    const optional<List<JobResultBody>>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * ジョブ実行結果を設定
     *
     * @param result ジョブ実行結果
     */
    void setResult(List<JobResultBody> result)
    {
        ensureData().result.emplace(std::move(result));
    }

    /**
     * ジョブ実行結果を設定
     *
     * @param result ジョブ実行結果
     */
    DeadLetterJob& withResult(List<JobResultBody> result)
    {
        setResult(std::move(result));
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
    DeadLetterJob& withCreatedAt(Int64 createdAt)
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
    DeadLetterJob& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const DeadLetterJob& lhs, const DeadLetterJob& lhr);

inline bool operator==(const DeadLetterJob& lhs, const DeadLetterJob& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_JOBQUEUE_MODEL_DEADLETTERJOB_HPP_