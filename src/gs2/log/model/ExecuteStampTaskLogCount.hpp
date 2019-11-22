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

#ifndef GS2_LOG_MODEL_EXECUTESTAMPTASKLOGCOUNT_HPP_
#define GS2_LOG_MODEL_EXECUTESTAMPTASKLOGCOUNT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace log {

/**
 * スタンプタスク実行ログ集計
 *
 * @author Game Server Services, Inc.
 *
 */
class ExecuteStampTaskLogCount : public Gs2Object
{
    friend bool operator!=(const ExecuteStampTaskLogCount& lhs, const ExecuteStampTaskLogCount& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** マイクロサービスの種類 */
        optional<StringHolder> service;
        /** マイクロサービスのメソッド */
        optional<StringHolder> method;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 報酬アクション */
        optional<StringHolder> action;
        /** 回数 */
        optional<Int64> count;

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
    ExecuteStampTaskLogCount() = default;
    ExecuteStampTaskLogCount(const ExecuteStampTaskLogCount& executeStampTaskLogCount) = default;
    ExecuteStampTaskLogCount(ExecuteStampTaskLogCount&& executeStampTaskLogCount) = default;
    ~ExecuteStampTaskLogCount() = default;

    ExecuteStampTaskLogCount& operator=(const ExecuteStampTaskLogCount& executeStampTaskLogCount) = default;
    ExecuteStampTaskLogCount& operator=(ExecuteStampTaskLogCount&& executeStampTaskLogCount) = default;

    ExecuteStampTaskLogCount deepCopy() const;

    const ExecuteStampTaskLogCount* operator->() const
    {
        return this;
    }

    ExecuteStampTaskLogCount* operator->()
    {
        return this;
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
    ExecuteStampTaskLogCount& withService(StringHolder service)
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
    ExecuteStampTaskLogCount& withMethod(StringHolder method)
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
    ExecuteStampTaskLogCount& withUserId(StringHolder userId)
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
    ExecuteStampTaskLogCount& withAction(StringHolder action)
    {
        setAction(std::move(action));
        return *this;
    }

    /**
     * 回数を取得
     *
     * @return 回数
     */
    const optional<Int64>& getCount() const
    {
        return ensureData().count;
    }

    /**
     * 回数を設定
     *
     * @param count 回数
     */
    void setCount(Int64 count)
    {
        ensureData().count.emplace(count);
    }

    /**
     * 回数を設定
     *
     * @param count 回数
     */
    ExecuteStampTaskLogCount& withCount(Int64 count)
    {
        setCount(count);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const ExecuteStampTaskLogCount& lhs, const ExecuteStampTaskLogCount& lhr);

inline bool operator==(const ExecuteStampTaskLogCount& lhs, const ExecuteStampTaskLogCount& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOG_MODEL_EXECUTESTAMPTASKLOGCOUNT_HPP_