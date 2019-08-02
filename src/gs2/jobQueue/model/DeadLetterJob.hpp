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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "JobResultBody.hpp"
#include <cstring>

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            deadLetterJobId(data.deadLetterJobId),
            name(data.name),
            userId(data.userId),
            scriptId(data.scriptId),
            args(data.args),
            result(data.result),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            deadLetterJobId(std::move(data.deadLetterJobId)),
            name(std::move(data.name)),
            userId(std::move(data.userId)),
            scriptId(std::move(data.scriptId)),
            args(std::move(data.args)),
            result(std::move(data.result)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "deadLetterJobId") == 0) {
                if (jsonValue.IsString())
                {
                    this->deadLetterJobId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "scriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->scriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "args") == 0) {
                if (jsonValue.IsString())
                {
                    this->args.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "result") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->result.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        JobResultBody item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->result, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
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
    DeadLetterJob() :
        m_pData(nullptr)
    {}

    DeadLetterJob(const DeadLetterJob& deadLetterJob) :
        Gs2Object(deadLetterJob),
        m_pData(deadLetterJob.m_pData != nullptr ? new Data(*deadLetterJob.m_pData) : nullptr)
    {}

    DeadLetterJob(DeadLetterJob&& deadLetterJob) :
        Gs2Object(std::move(deadLetterJob)),
        m_pData(deadLetterJob.m_pData)
    {
        deadLetterJob.m_pData = nullptr;
    }

    ~DeadLetterJob()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeadLetterJob& operator=(const DeadLetterJob& deadLetterJob)
    {
        Gs2Object::operator=(deadLetterJob);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deadLetterJob.m_pData);

        return *this;
    }

    DeadLetterJob& operator=(DeadLetterJob&& deadLetterJob)
    {
        Gs2Object::operator=(std::move(deadLetterJob));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deadLetterJob.m_pData;
        deadLetterJob.m_pData = nullptr;

        return *this;
    }

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
    void setDeadLetterJobId(const Char* deadLetterJobId)
    {
        ensureData().deadLetterJobId.emplace(deadLetterJobId);
    }

    /**
     * デッドレタージョブを設定
     *
     * @param deadLetterJobId デッドレタージョブ
     */
    DeadLetterJob& withDeadLetterJobId(const Char* deadLetterJobId)
    {
        setDeadLetterJobId(deadLetterJobId);
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
    DeadLetterJob& withName(const Char* name)
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
    DeadLetterJob& withUserId(const Char* userId)
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
    DeadLetterJob& withScriptId(const Char* scriptId)
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
    DeadLetterJob& withArgs(const Char* args)
    {
        setArgs(args);
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
    void setResult(const List<JobResultBody>& result)
    {
        ensureData().result.emplace(result);
    }

    /**
     * ジョブ実行結果を設定
     *
     * @param result ジョブ実行結果
     */
    DeadLetterJob& withResult(const List<JobResultBody>& result)
    {
        setResult(result);
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

inline bool operator!=(const DeadLetterJob& lhs, const DeadLetterJob& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->deadLetterJobId != lhr.m_pData->deadLetterJobId)
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
        if (lhs.m_pData->result != lhr.m_pData->result)
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

inline bool operator==(const DeadLetterJob& lhs, const DeadLetterJob& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_JOBQUEUE_MODEL_DEADLETTERJOB_HPP_