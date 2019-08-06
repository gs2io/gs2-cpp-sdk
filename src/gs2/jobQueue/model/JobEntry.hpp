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

#ifndef GS2_JOBQUEUE_MODEL_JOBENTRY_HPP_
#define GS2_JOBQUEUE_MODEL_JOBENTRY_HPP_

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
class JobEntry : public Gs2Object
{
    friend bool operator!=(const JobEntry& lhs, const JobEntry& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スクリプト のGRN */
        optional<StringHolder> scriptId;
        /** 引数 */
        optional<StringHolder> args;
        /** 最大試行回数 */
        optional<Int32> maxTryCount;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            scriptId(data.scriptId),
            args(data.args),
            maxTryCount(data.maxTryCount)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            scriptId(std::move(data.scriptId)),
            args(std::move(data.args)),
            maxTryCount(std::move(data.maxTryCount))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "scriptId") == 0) {
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
            else if (std::strcmp(name_, "maxTryCount") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxTryCount = jsonValue.GetInt();
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
    JobEntry() :
        m_pData(nullptr)
    {}

    JobEntry(const JobEntry& jobEntry) :
        Gs2Object(jobEntry),
        m_pData(jobEntry.m_pData != nullptr ? new Data(*jobEntry.m_pData) : nullptr)
    {}

    JobEntry(JobEntry&& jobEntry) :
        Gs2Object(std::move(jobEntry)),
        m_pData(jobEntry.m_pData)
    {
        jobEntry.m_pData = nullptr;
    }

    ~JobEntry()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    JobEntry& operator=(const JobEntry& jobEntry)
    {
        Gs2Object::operator=(jobEntry);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*jobEntry.m_pData);

        return *this;
    }

    JobEntry& operator=(JobEntry&& jobEntry)
    {
        Gs2Object::operator=(std::move(jobEntry));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = jobEntry.m_pData;
        jobEntry.m_pData = nullptr;

        return *this;
    }

    const JobEntry* operator->() const
    {
        return this;
    }

    JobEntry* operator->()
    {
        return this;
    }
    /**
     * スクリプト のGRNを取得
     *
     * @return スクリプト のGRN
     */
    const optional<StringHolder>& getScriptId() const
    {
        return ensureData().scriptId;
    }

    /**
     * スクリプト のGRNを設定
     *
     * @param scriptId スクリプト のGRN
     */
    void setScriptId(const Char* scriptId)
    {
        ensureData().scriptId.emplace(scriptId);
    }

    /**
     * スクリプト のGRNを設定
     *
     * @param scriptId スクリプト のGRN
     */
    JobEntry& withScriptId(const Char* scriptId)
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
    JobEntry& withArgs(const Char* args)
    {
        setArgs(args);
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
    JobEntry& withMaxTryCount(Int32 maxTryCount)
    {
        setMaxTryCount(maxTryCount);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const JobEntry& lhs, const JobEntry& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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
        if (lhs.m_pData->maxTryCount != lhr.m_pData->maxTryCount)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const JobEntry& lhs, const JobEntry& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_JOBQUEUE_MODEL_JOBENTRY_HPP_