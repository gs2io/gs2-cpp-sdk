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

#ifndef GS2_LOG_MODEL_EXECUTESTAMPSHEETLOGCOUNT_HPP_
#define GS2_LOG_MODEL_EXECUTESTAMPSHEETLOGCOUNT_HPP_

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
 * スタンプシート実行ログ集計
 *
 * @author Game Server Services, Inc.
 *
 */
class ExecuteStampSheetLogCount : public Gs2Object
{
    friend bool operator!=(const ExecuteStampSheetLogCount& lhs, const ExecuteStampSheetLogCount& lhr);

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

        Data(const Data& data) :
            detail::json::IModel(data),
            service(data.service),
            method(data.method),
            userId(data.userId),
            action(data.action),
            count(data.count)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "service") == 0)
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
            else if (std::strcmp(name_, "count") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->count = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ExecuteStampSheetLogCount() = default;
    ExecuteStampSheetLogCount(const ExecuteStampSheetLogCount& executeStampSheetLogCount) = default;
    ExecuteStampSheetLogCount(ExecuteStampSheetLogCount&& executeStampSheetLogCount) = default;
    ~ExecuteStampSheetLogCount() = default;

    ExecuteStampSheetLogCount& operator=(const ExecuteStampSheetLogCount& executeStampSheetLogCount) = default;
    ExecuteStampSheetLogCount& operator=(ExecuteStampSheetLogCount&& executeStampSheetLogCount) = default;

    ExecuteStampSheetLogCount deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ExecuteStampSheetLogCount);
    }

    const ExecuteStampSheetLogCount* operator->() const
    {
        return this;
    }

    ExecuteStampSheetLogCount* operator->()
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
    ExecuteStampSheetLogCount& withService(StringHolder service)
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
    ExecuteStampSheetLogCount& withMethod(StringHolder method)
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
    ExecuteStampSheetLogCount& withUserId(StringHolder userId)
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
    ExecuteStampSheetLogCount& withAction(StringHolder action)
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
    ExecuteStampSheetLogCount& withCount(Int64 count)
    {
        setCount(count);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ExecuteStampSheetLogCount& lhs, const ExecuteStampSheetLogCount& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
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
        if (lhs.m_pData->count != lhr.m_pData->count)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const ExecuteStampSheetLogCount& lhs, const ExecuteStampSheetLogCount& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOG_MODEL_EXECUTESTAMPSHEETLOGCOUNT_HPP_