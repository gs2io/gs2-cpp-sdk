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

#ifndef GS2_CORE_MODEL_STAMPTASK_HPP_
#define GS2_CORE_MODEL_STAMPTASK_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 {

/**
 * スタンプタスク
 *
 * @author Game Server Services, Inc.
 *
 */
class StampTask : public Gs2Object
{
    friend bool operator!=(const StampTask& lhs, const StampTask& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** タスクID */
        optional<StringHolder> taskId;
        /** アクション名 */
        optional<StringHolder> action;
        /** 引数 */
        optional<StringHolder> args;
        /** タイムスタンプ */
        optional<Int64> timestamp;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            taskId(data.taskId),
            action(data.action),
            args(data.args),
            timestamp(data.timestamp)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "taskId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->taskId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "action") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->action.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "args") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->args.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "timestamp") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->timestamp = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    StampTask() = default;
    StampTask(const StampTask& stampTask) = default;
    StampTask(StampTask&& stampTask) = default;
    ~StampTask() = default;

    StampTask& operator=(const StampTask& stampTask) = default;
    StampTask& operator=(StampTask&& stampTask) = default;

    StampTask deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(StampTask);
    }

    const StampTask* operator->() const
    {
        return this;
    }

    StampTask* operator->()
    {
        return this;
    }
    /**
     * タスクIDを取得
     *
     * @return タスクID
     */
    const optional<StringHolder>& getTaskId() const
    {
        return ensureData().taskId;
    }

    /**
     * タスクIDを設定
     *
     * @param taskId タスクID
     */
    void setTaskId(StringHolder taskId)
    {
        ensureData().taskId.emplace(std::move(taskId));
    }

    /**
     * タスクIDを設定
     *
     * @param taskId タスクID
     */
    StampTask& withTaskId(StringHolder taskId)
    {
        setTaskId(std::move(taskId));
        return *this;
    }

    /**
     * アクション名を取得
     *
     * @return アクション名
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * アクション名を設定
     *
     * @param action アクション名
     */
    void setAction(StringHolder action)
    {
        ensureData().action.emplace(std::move(action));
    }

    /**
     * アクション名を設定
     *
     * @param action アクション名
     */
    StampTask& withAction(StringHolder action)
    {
        setAction(std::move(action));
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
    StampTask& withArgs(StringHolder args)
    {
        setArgs(std::move(args));
        return *this;
    }

    /**
     * タイムスタンプを取得
     *
     * @return タイムスタンプ
     */
    const optional<Int64>& getTimestamp() const
    {
        return ensureData().timestamp;
    }

    /**
     * タイムスタンプを設定
     *
     * @param timestamp タイムスタンプ
     */
    void setTimestamp(Int64 timestamp)
    {
        ensureData().timestamp.emplace(timestamp);
    }

    /**
     * タイムスタンプを設定
     *
     * @param timestamp タイムスタンプ
     */
    StampTask& withTimestamp(Int64 timestamp)
    {
        setTimestamp(timestamp);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const StampTask& lhs, const StampTask& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->taskId != lhr.m_pData->taskId)
        {
            return true;
        }
        if (lhs.m_pData->action != lhr.m_pData->action)
        {
            return true;
        }
        if (lhs.m_pData->args != lhr.m_pData->args)
        {
            return true;
        }
        if (lhs.m_pData->timestamp != lhr.m_pData->timestamp)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const StampTask& lhs, const StampTask& lhr)
{
    return !(lhs != lhr);
}

}

#endif //GS2_CORE_MODEL_STAMPTASK_HPP_