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

#ifndef GS2_AUTH_CONTROL_LOGINREQUEST_HPP_
#define GS2_AUTH_CONTROL_LOGINREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AuthConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace auth
{

/**
 * 指定したユーザIDでGS2にログインし、アクセストークンを取得します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class LoginRequest : public Gs2BasicRequest, public Gs2Auth
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 現在時刻に対する補正値（現在時刻を起点とした秒数） */
        optional<Int32> timeOffset;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            userId(data.userId),
            timeOffset(data.timeOffset),
            duplicationAvoider(data.duplicationAvoider)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    LoginRequest() = default;
    LoginRequest(const LoginRequest& loginRequest) = default;
    LoginRequest(LoginRequest&& loginRequest) = default;
    ~LoginRequest() GS2_OVERRIDE = default;

    LoginRequest& operator=(const LoginRequest& loginRequest) = default;
    LoginRequest& operator=(LoginRequest&& loginRequest) = default;

    LoginRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LoginRequest);
    }

    const LoginRequest* operator->() const
    {
        return this;
    }

    LoginRequest* operator->()
    {
        return this;
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
    LoginRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * 現在時刻に対する補正値（現在時刻を起点とした秒数）を取得
     *
     * @return 現在時刻に対する補正値（現在時刻を起点とした秒数）
     */
    const optional<Int32>& getTimeOffset() const
    {
        return ensureData().timeOffset;
    }

    /**
     * 現在時刻に対する補正値（現在時刻を起点とした秒数）を設定
     *
     * @param timeOffset 現在時刻に対する補正値（現在時刻を起点とした秒数）
     */
    void setTimeOffset(Int32 timeOffset)
    {
        ensureData().timeOffset.emplace(timeOffset);
    }

    /**
     * 現在時刻に対する補正値（現在時刻を起点とした秒数）を設定
     *
     * @param timeOffset 現在時刻に対する補正値（現在時刻を起点とした秒数）
     */
    LoginRequest& withTimeOffset(Int32 timeOffset)
    {
        ensureData().timeOffset.emplace(timeOffset);
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    LoginRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    LoginRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    LoginRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_AUTH_CONTROL_LOGINREQUEST_HPP_