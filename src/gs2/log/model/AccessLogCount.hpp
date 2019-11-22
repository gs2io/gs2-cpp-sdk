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

#ifndef GS2_LOG_MODEL_ACCESSLOGCOUNT_HPP_
#define GS2_LOG_MODEL_ACCESSLOGCOUNT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace log {

/**
 * アクセスログ集計
 *
 * @author Game Server Services, Inc.
 *
 */
class AccessLogCount : public Gs2Object
{
    friend bool operator!=(const AccessLogCount& lhs, const AccessLogCount& lhr);

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
    AccessLogCount() = default;
    AccessLogCount(const AccessLogCount& accessLogCount) = default;
    AccessLogCount(AccessLogCount&& accessLogCount) = default;
    ~AccessLogCount() = default;

    AccessLogCount& operator=(const AccessLogCount& accessLogCount) = default;
    AccessLogCount& operator=(AccessLogCount&& accessLogCount) = default;

    AccessLogCount deepCopy() const;

    const AccessLogCount* operator->() const
    {
        return this;
    }

    AccessLogCount* operator->()
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
    AccessLogCount& withService(StringHolder service)
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
    AccessLogCount& withMethod(StringHolder method)
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
    AccessLogCount& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
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
    AccessLogCount& withCount(Int64 count)
    {
        setCount(count);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const AccessLogCount& lhs, const AccessLogCount& lhr);

inline bool operator==(const AccessLogCount& lhs, const AccessLogCount& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOG_MODEL_ACCESSLOGCOUNT_HPP_