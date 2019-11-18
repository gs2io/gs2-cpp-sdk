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

#ifndef GS2_FRIEND_CONTROL_SENDREQUESTBYUSERIDREQUEST_HPP_
#define GS2_FRIEND_CONTROL_SENDREQUESTBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/friend/Gs2FriendConst.hpp>
#include <gs2/friend/model/model.hpp>
#include <memory>

namespace gs2 { namespace friend_
{

/**
 * ユーザーIDを指定してフレンドリクエストを送信 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SendRequestByUserIdRequest : public Gs2BasicRequest, public Gs2Friend
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** リクエストの送信元ユーザID */
        optional<StringHolder> userId;
        /** リクエストの送信先ユーザID */
        optional<StringHolder> targetUserId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            targetUserId(data.targetUserId),
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
    SendRequestByUserIdRequest() = default;
    SendRequestByUserIdRequest(const SendRequestByUserIdRequest& sendRequestByUserIdRequest) = default;
    SendRequestByUserIdRequest(SendRequestByUserIdRequest&& sendRequestByUserIdRequest) = default;
    ~SendRequestByUserIdRequest() GS2_OVERRIDE = default;

    SendRequestByUserIdRequest& operator=(const SendRequestByUserIdRequest& sendRequestByUserIdRequest) = default;
    SendRequestByUserIdRequest& operator=(SendRequestByUserIdRequest&& sendRequestByUserIdRequest) = default;

    SendRequestByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SendRequestByUserIdRequest);
    }

    const SendRequestByUserIdRequest* operator->() const
    {
        return this;
    }

    SendRequestByUserIdRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    SendRequestByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * リクエストの送信元ユーザIDを取得
     *
     * @return リクエストの送信元ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * リクエストの送信元ユーザIDを設定
     *
     * @param userId リクエストの送信元ユーザID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * リクエストの送信元ユーザIDを設定
     *
     * @param userId リクエストの送信元ユーザID
     */
    SendRequestByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * リクエストの送信先ユーザIDを取得
     *
     * @return リクエストの送信先ユーザID
     */
    const optional<StringHolder>& getTargetUserId() const
    {
        return ensureData().targetUserId;
    }

    /**
     * リクエストの送信先ユーザIDを設定
     *
     * @param targetUserId リクエストの送信先ユーザID
     */
    void setTargetUserId(StringHolder targetUserId)
    {
        ensureData().targetUserId.emplace(std::move(targetUserId));
    }

    /**
     * リクエストの送信先ユーザIDを設定
     *
     * @param targetUserId リクエストの送信先ユーザID
     */
    SendRequestByUserIdRequest& withTargetUserId(StringHolder targetUserId)
    {
        ensureData().targetUserId.emplace(std::move(targetUserId));
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
    SendRequestByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    SendRequestByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SendRequestByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FRIEND_CONTROL_SENDREQUESTBYUSERIDREQUEST_HPP_