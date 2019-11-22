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

#ifndef GS2_LOG_MODEL_ACCESSLOG_HPP_
#define GS2_LOG_MODEL_ACCESSLOG_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace log {

/**
 * アクセスログ
 *
 * @author Game Server Services, Inc.
 *
 */
class AccessLog : public Gs2Object
{
    friend bool operator!=(const AccessLog& lhs, const AccessLog& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 日時 */
        optional<Int64> timestamp;
        /** リクエストID */
        optional<StringHolder> requestId;
        /** マイクロサービスの種類 */
        optional<StringHolder> service;
        /** マイクロサービスのメソッド */
        optional<StringHolder> method;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** リクエストパラメータ */
        optional<StringHolder> request;
        /** 応答内容 */
        optional<StringHolder> result;

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
    AccessLog() = default;
    AccessLog(const AccessLog& accessLog) = default;
    AccessLog(AccessLog&& accessLog) = default;
    ~AccessLog() = default;

    AccessLog& operator=(const AccessLog& accessLog) = default;
    AccessLog& operator=(AccessLog&& accessLog) = default;

    AccessLog deepCopy() const;

    const AccessLog* operator->() const
    {
        return this;
    }

    AccessLog* operator->()
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
    AccessLog& withTimestamp(Int64 timestamp)
    {
        setTimestamp(timestamp);
        return *this;
    }

    /**
     * リクエストIDを取得
     *
     * @return リクエストID
     */
    const optional<StringHolder>& getRequestId() const
    {
        return ensureData().requestId;
    }

    /**
     * リクエストIDを設定
     *
     * @param requestId リクエストID
     */
    void setRequestId(StringHolder requestId)
    {
        ensureData().requestId.emplace(std::move(requestId));
    }

    /**
     * リクエストIDを設定
     *
     * @param requestId リクエストID
     */
    AccessLog& withRequestId(StringHolder requestId)
    {
        setRequestId(std::move(requestId));
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
    AccessLog& withService(StringHolder service)
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
    AccessLog& withMethod(StringHolder method)
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
    AccessLog& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * リクエストパラメータを取得
     *
     * @return リクエストパラメータ
     */
    const optional<StringHolder>& getRequest() const
    {
        return ensureData().request;
    }

    /**
     * リクエストパラメータを設定
     *
     * @param request リクエストパラメータ
     */
    void setRequest(StringHolder request)
    {
        ensureData().request.emplace(std::move(request));
    }

    /**
     * リクエストパラメータを設定
     *
     * @param request リクエストパラメータ
     */
    AccessLog& withRequest(StringHolder request)
    {
        setRequest(std::move(request));
        return *this;
    }

    /**
     * 応答内容を取得
     *
     * @return 応答内容
     */
    const optional<StringHolder>& getResult() const
    {
        return ensureData().result;
    }

    /**
     * 応答内容を設定
     *
     * @param result 応答内容
     */
    void setResult(StringHolder result)
    {
        ensureData().result.emplace(std::move(result));
    }

    /**
     * 応答内容を設定
     *
     * @param result 応答内容
     */
    AccessLog& withResult(StringHolder result)
    {
        setResult(std::move(result));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const AccessLog& lhs, const AccessLog& lhr);

inline bool operator==(const AccessLog& lhs, const AccessLog& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOG_MODEL_ACCESSLOG_HPP_