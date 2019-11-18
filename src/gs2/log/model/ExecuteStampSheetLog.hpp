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

#ifndef GS2_LOG_MODEL_EXECUTESTAMPSHEETLOG_HPP_
#define GS2_LOG_MODEL_EXECUTESTAMPSHEETLOG_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace log {

/**
 * スタンプシート実行ログ
 *
 * @author Game Server Services, Inc.
 *
 */
class ExecuteStampSheetLog : public Gs2Object
{
    friend bool operator!=(const ExecuteStampSheetLog& lhs, const ExecuteStampSheetLog& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 日時 */
        optional<Int64> timestamp;
        /** トランザクションID */
        optional<StringHolder> transactionId;
        /** マイクロサービスの種類 */
        optional<StringHolder> service;
        /** マイクロサービスのメソッド */
        optional<StringHolder> method;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 報酬アクション */
        optional<StringHolder> action;
        /** 引数 */
        optional<StringHolder> args;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            timestamp(data.timestamp),
            transactionId(data.transactionId),
            service(data.service),
            method(data.method),
            userId(data.userId),
            action(data.action),
            args(data.args)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "timestamp") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->timestamp = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "transactionId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->transactionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "service") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->service.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "method") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->method.emplace(jsonValue.GetString());
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
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ExecuteStampSheetLog() = default;
    ExecuteStampSheetLog(const ExecuteStampSheetLog& executeStampSheetLog) = default;
    ExecuteStampSheetLog(ExecuteStampSheetLog&& executeStampSheetLog) = default;
    ~ExecuteStampSheetLog() = default;

    ExecuteStampSheetLog& operator=(const ExecuteStampSheetLog& executeStampSheetLog) = default;
    ExecuteStampSheetLog& operator=(ExecuteStampSheetLog&& executeStampSheetLog) = default;

    ExecuteStampSheetLog deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ExecuteStampSheetLog);
    }

    const ExecuteStampSheetLog* operator->() const
    {
        return this;
    }

    ExecuteStampSheetLog* operator->()
    {
        return this;
    }
    /**
     * 日時を取得
     *
     * @return 日時
     */
    const optional<Int64>& getTimestamp() const
    {
        return ensureData().timestamp;
    }

    /**
     * 日時を設定
     *
     * @param timestamp 日時
     */
    void setTimestamp(Int64 timestamp)
    {
        ensureData().timestamp.emplace(timestamp);
    }

    /**
     * 日時を設定
     *
     * @param timestamp 日時
     */
    ExecuteStampSheetLog& withTimestamp(Int64 timestamp)
    {
        setTimestamp(timestamp);
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
    ExecuteStampSheetLog& withTransactionId(StringHolder transactionId)
    {
        setTransactionId(std::move(transactionId));
        return *this;
    }

    /**
     * マイクロサービスの種類を取得
     *
     * @return マイクロサービスの種類
     */
    const optional<StringHolder>& getService() const
    {
        return ensureData().service;
    }

    /**
     * マイクロサービスの種類を設定
     *
     * @param service マイクロサービスの種類
     */
    void setService(StringHolder service)
    {
        ensureData().service.emplace(std::move(service));
    }

    /**
     * マイクロサービスの種類を設定
     *
     * @param service マイクロサービスの種類
     */
    ExecuteStampSheetLog& withService(StringHolder service)
    {
        setService(std::move(service));
        return *this;
    }

    /**
     * マイクロサービスのメソッドを取得
     *
     * @return マイクロサービスのメソッド
     */
    const optional<StringHolder>& getMethod() const
    {
        return ensureData().method;
    }

    /**
     * マイクロサービスのメソッドを設定
     *
     * @param method マイクロサービスのメソッド
     */
    void setMethod(StringHolder method)
    {
        ensureData().method.emplace(std::move(method));
    }

    /**
     * マイクロサービスのメソッドを設定
     *
     * @param method マイクロサービスのメソッド
     */
    ExecuteStampSheetLog& withMethod(StringHolder method)
    {
        setMethod(std::move(method));
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
    ExecuteStampSheetLog& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * 報酬アクションを取得
     *
     * @return 報酬アクション
     */
    const optional<StringHolder>& getAction() const
    {
        return ensureData().action;
    }

    /**
     * 報酬アクションを設定
     *
     * @param action 報酬アクション
     */
    void setAction(StringHolder action)
    {
        ensureData().action.emplace(std::move(action));
    }

    /**
     * 報酬アクションを設定
     *
     * @param action 報酬アクション
     */
    ExecuteStampSheetLog& withAction(StringHolder action)
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
    ExecuteStampSheetLog& withArgs(StringHolder args)
    {
        setArgs(std::move(args));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ExecuteStampSheetLog& lhs, const ExecuteStampSheetLog& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->timestamp != lhr.m_pData->timestamp)
        {
            return true;
        }
        if (lhs.m_pData->transactionId != lhr.m_pData->transactionId)
        {
            return true;
        }
        if (lhs.m_pData->service != lhr.m_pData->service)
        {
            return true;
        }
        if (lhs.m_pData->method != lhr.m_pData->method)
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
    }
    return false;
}

inline bool operator==(const ExecuteStampSheetLog& lhs, const ExecuteStampSheetLog& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOG_MODEL_EXECUTESTAMPSHEETLOG_HPP_