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

#ifndef GS2_CORE_MODEL_STAMPSHEET_HPP_
#define GS2_CORE_MODEL_STAMPSHEET_HPP_

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
 * スタンプシート
 *
 * @author Game Server Services, Inc.
 *
 */
class StampSheet : public Gs2Object
{
    friend bool operator!=(const StampSheet& lhs, const StampSheet& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** アクション名 */
        optional<StringHolder> action;
        /** 引数 */
        optional<StringHolder> args;
        /** スタンプタスクのリスト */
        optional<List<StringHolder>> tasks;
        /** トランザクションID */
        optional<StringHolder> transactionId;
        /** タイムスタンプ */
        optional<Int64> timestamp;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            ownerId(data.ownerId),
            userId(data.userId),
            action(data.action),
            args(data.args),
            transactionId(data.transactionId),
            timestamp(data.timestamp)
        {
            if (data.tasks)
            {
                tasks = data.tasks->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "tasks") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->tasks.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->tasks, std::move(stringHolder));
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "transactionId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->transactionId.emplace(jsonValue.GetString());
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
    StampSheet() = default;
    StampSheet(const StampSheet& stampSheet) = default;
    StampSheet(StampSheet&& stampSheet) = default;
    ~StampSheet() = default;

    StampSheet& operator=(const StampSheet& stampSheet) = default;
    StampSheet& operator=(StampSheet&& stampSheet) = default;

    StampSheet deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(StampSheet);
    }

    const StampSheet* operator->() const
    {
        return this;
    }

    StampSheet* operator->()
    {
        return this;
    }
    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    StampSheet& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
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
    StampSheet& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
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
    StampSheet& withAction(StringHolder action)
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
    StampSheet& withArgs(StringHolder args)
    {
        setArgs(std::move(args));
        return *this;
    }

    /**
     * スタンプタスクのリストを取得
     *
     * @return スタンプタスクのリスト
     */
    const optional<List<StringHolder>>& getTasks() const
    {
        return ensureData().tasks;
    }

    /**
     * スタンプタスクのリストを設定
     *
     * @param tasks スタンプタスクのリスト
     */
    void setTasks(List<StringHolder> tasks)
    {
        ensureData().tasks.emplace(std::move(tasks));
    }

    /**
     * スタンプタスクのリストを設定
     *
     * @param tasks スタンプタスクのリスト
     */
    StampSheet& withTasks(List<StringHolder> tasks)
    {
        setTasks(std::move(tasks));
        return *this;
    }

    /**
     * トランザクションIDを取得
     *
     * @return トランザクションID
     */
    const optional<StringHolder>& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    void setTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId.emplace(std::move(transactionId));
    }

    /**
     * トランザクションIDを設定
     *
     * @param transactionId トランザクションID
     */
    StampSheet& withTransactionId(StringHolder transactionId)
    {
        setTransactionId(std::move(transactionId));
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
    StampSheet& withTimestamp(Int64 timestamp)
    {
        setTimestamp(timestamp);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const StampSheet& lhs, const StampSheet& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
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
        if (lhs.m_pData->tasks != lhr.m_pData->tasks)
        {
            return true;
        }
        if (lhs.m_pData->transactionId != lhr.m_pData->transactionId)
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

inline bool operator==(const StampSheet& lhs, const StampSheet& lhr)
{
    return !(lhs != lhr);
}

}

#endif //GS2_CORE_MODEL_STAMPSHEET_HPP_