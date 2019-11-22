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

#ifndef GS2_JOBQUEUE_MODEL_JOBRESULTBODY_HPP_
#define GS2_JOBQUEUE_MODEL_JOBRESULTBODY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace jobQueue {

/**
 * ジョブの実行結果
 *
 * @author Game Server Services, Inc.
 *
 */
class JobResultBody : public Gs2Object
{
    friend bool operator!=(const JobResultBody& lhs, const JobResultBody& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 試行回数 */
        optional<Int32> tryNumber;
        /** ステータスコード */
        optional<Int32> statusCode;
        /** レスポンスの内容 */
        optional<StringHolder> result;
        /** 実行日時 */
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
    JobResultBody() = default;
    JobResultBody(const JobResultBody& jobResultBody) = default;
    JobResultBody(JobResultBody&& jobResultBody) = default;
    ~JobResultBody() = default;

    JobResultBody& operator=(const JobResultBody& jobResultBody) = default;
    JobResultBody& operator=(JobResultBody&& jobResultBody) = default;

    JobResultBody deepCopy() const;

    const JobResultBody* operator->() const
    {
        return this;
    }

    JobResultBody* operator->()
    {
        return this;
    }
    /**
     * 試行回数を取得
     *
     * @return 試行回数
     */
    const optional<Int32>& getTryNumber() const
    {
        return ensureData().tryNumber;
    }

    /**
     * 試行回数を設定
     *
     * @param tryNumber 試行回数
     */
    void setTryNumber(Int32 tryNumber)
    {
        ensureData().tryNumber.emplace(tryNumber);
    }

    /**
     * 試行回数を設定
     *
     * @param tryNumber 試行回数
     */
    JobResultBody& withTryNumber(Int32 tryNumber)
    {
        setTryNumber(tryNumber);
        return *this;
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
     * ステータスコードを設定
     *
     * @param statusCode ステータスコード
     */
    JobResultBody& withStatusCode(Int32 statusCode)
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
    JobResultBody& withResult(StringHolder result)
    {
        setResult(std::move(result));
        return *this;
    }

    /**
     * 実行日時を取得
     *
     * @return 実行日時
     */
    const optional<Int64>& getTryAt() const
    {
        return ensureData().tryAt;
    }

    /**
     * 実行日時を設定
     *
     * @param tryAt 実行日時
     */
    void setTryAt(Int64 tryAt)
    {
        ensureData().tryAt.emplace(tryAt);
    }

    /**
     * 実行日時を設定
     *
     * @param tryAt 実行日時
     */
    JobResultBody& withTryAt(Int64 tryAt)
    {
        setTryAt(tryAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const JobResultBody& lhs, const JobResultBody& lhr);

inline bool operator==(const JobResultBody& lhs, const JobResultBody& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_JOBQUEUE_MODEL_JOBRESULTBODY_HPP_