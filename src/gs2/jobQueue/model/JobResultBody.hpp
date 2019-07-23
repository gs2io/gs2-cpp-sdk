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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            tryNumber(data.tryNumber),
            statusCode(data.statusCode),
            result(data.result),
            tryAt(data.tryAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            tryNumber(std::move(data.tryNumber)),
            statusCode(std::move(data.statusCode)),
            result(std::move(data.result)),
            tryAt(std::move(data.tryAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "tryNumber") == 0) {
                if (jsonValue.IsInt())
                {
                    this->tryNumber = jsonValue.GetInt();
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
            else if (std::strcmp(name, "tryAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->tryAt = jsonValue.GetInt64();
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
    JobResultBody() :
        m_pData(nullptr)
    {}

    JobResultBody(const JobResultBody& jobResultBody) :
        Gs2Object(jobResultBody),
        m_pData(jobResultBody.m_pData != nullptr ? new Data(*jobResultBody.m_pData) : nullptr)
    {}

    JobResultBody(JobResultBody&& jobResultBody) :
        Gs2Object(std::move(jobResultBody)),
        m_pData(jobResultBody.m_pData)
    {
        jobResultBody.m_pData = nullptr;
    }

    ~JobResultBody()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    JobResultBody& operator=(const JobResultBody& jobResultBody)
    {
        Gs2Object::operator=(jobResultBody);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*jobResultBody.m_pData);

        return *this;
    }

    JobResultBody& operator=(JobResultBody&& jobResultBody)
    {
        Gs2Object::operator=(std::move(jobResultBody));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = jobResultBody.m_pData;
        jobResultBody.m_pData = nullptr;

        return *this;
    }

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
    void setResult(const Char* result)
    {
        ensureData().result.emplace(result);
    }

    /**
     * レスポンスの内容を設定
     *
     * @param result レスポンスの内容
     */
    JobResultBody& withResult(const Char* result)
    {
        setResult(result);
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

bool operator!=(const JobResultBody& lhs, const JobResultBody& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->tryNumber != lhr.m_pData->tryNumber)
        {
            return true;
        }
        if (lhs.m_pData->statusCode != lhr.m_pData->statusCode)
        {
            return true;
        }
        if (lhs.m_pData->result != lhr.m_pData->result)
        {
            return true;
        }
        if (lhs.m_pData->tryAt != lhr.m_pData->tryAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const JobResultBody& lhs, const JobResultBody& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_JOBQUEUE_MODEL_JOBRESULTBODY_HPP_