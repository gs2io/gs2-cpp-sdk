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

#ifndef GS2_LOG_MODEL_ISSUESTAMPSHEETLOG_HPP_
#define GS2_LOG_MODEL_ISSUESTAMPSHEETLOG_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace log {

/**
 * スタンプシート発行ログ
 *
 * @author Game Server Services, Inc.
 *
 */
class IssueStampSheetLog : public Gs2Object
{
    friend bool operator!=(const IssueStampSheetLog& lhs, const IssueStampSheetLog& lhr);

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
        /** スタンプタスク */
        optional<StringHolder> tasks;

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
    IssueStampSheetLog() = default;
    IssueStampSheetLog(const IssueStampSheetLog& issueStampSheetLog) = default;
    IssueStampSheetLog(IssueStampSheetLog&& issueStampSheetLog) = default;
    ~IssueStampSheetLog() = default;

    IssueStampSheetLog& operator=(const IssueStampSheetLog& issueStampSheetLog) = default;
    IssueStampSheetLog& operator=(IssueStampSheetLog&& issueStampSheetLog) = default;

    IssueStampSheetLog deepCopy() const;

    const IssueStampSheetLog* operator->() const
    {
        return this;
    }

    IssueStampSheetLog* operator->()
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
    IssueStampSheetLog& withTimestamp(Int64 timestamp)
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
    IssueStampSheetLog& withTransactionId(StringHolder transactionId)
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
    IssueStampSheetLog& withService(StringHolder service)
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
    IssueStampSheetLog& withMethod(StringHolder method)
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
    IssueStampSheetLog& withUserId(StringHolder userId)
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
    IssueStampSheetLog& withAction(StringHolder action)
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
    IssueStampSheetLog& withArgs(StringHolder args)
    {
        setArgs(std::move(args));
        return *this;
    }

    /**
     * スタンプタスクを取得
     *
     * @return スタンプタスク
     */
    const optional<StringHolder>& getTasks() const
    {
        return ensureData().tasks;
    }

    /**
     * スタンプタスクを設定
     *
     * @param tasks スタンプタスク
     */
    void setTasks(StringHolder tasks)
    {
        ensureData().tasks.emplace(std::move(tasks));
    }

    /**
     * スタンプタスクを設定
     *
     * @param tasks スタンプタスク
     */
    IssueStampSheetLog& withTasks(StringHolder tasks)
    {
        setTasks(std::move(tasks));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const IssueStampSheetLog& lhs, const IssueStampSheetLog& lhr);

inline bool operator==(const IssueStampSheetLog& lhs, const IssueStampSheetLog& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOG_MODEL_ISSUESTAMPSHEETLOG_HPP_