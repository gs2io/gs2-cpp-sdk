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

#ifndef GS2_FRIEND_CONTROL_ACCEPTREQUESTBYUSERIDREQUEST_HPP_
#define GS2_FRIEND_CONTROL_ACCEPTREQUESTBYUSERIDREQUEST_HPP_

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
 * ユーザーIDを指定してフレンドリクエストを承諾 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class AcceptRequestByUserIdRequest : public Gs2BasicRequest, public Gs2Friend
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** フレンドリクエストを受け取ったユーザID */
        optional<StringHolder> userId;
        /** フレンドリクエストを送信したユーザID */
        optional<StringHolder> fromUserId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            fromUserId(data.fromUserId),
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
    AcceptRequestByUserIdRequest() = default;
    AcceptRequestByUserIdRequest(const AcceptRequestByUserIdRequest& acceptRequestByUserIdRequest) = default;
    AcceptRequestByUserIdRequest(AcceptRequestByUserIdRequest&& acceptRequestByUserIdRequest) = default;
    ~AcceptRequestByUserIdRequest() GS2_OVERRIDE = default;

    AcceptRequestByUserIdRequest& operator=(const AcceptRequestByUserIdRequest& acceptRequestByUserIdRequest) = default;
    AcceptRequestByUserIdRequest& operator=(AcceptRequestByUserIdRequest&& acceptRequestByUserIdRequest) = default;

    AcceptRequestByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AcceptRequestByUserIdRequest);
    }

    const AcceptRequestByUserIdRequest* operator->() const
    {
        return this;
    }

    AcceptRequestByUserIdRequest* operator->()
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
    AcceptRequestByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * フレンドリクエストを受け取ったユーザIDを取得
     *
     * @return フレンドリクエストを受け取ったユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * フレンドリクエストを受け取ったユーザIDを設定
     *
     * @param userId フレンドリクエストを受け取ったユーザID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * フレンドリクエストを受け取ったユーザIDを設定
     *
     * @param userId フレンドリクエストを受け取ったユーザID
     */
    AcceptRequestByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * フレンドリクエストを送信したユーザIDを取得
     *
     * @return フレンドリクエストを送信したユーザID
     */
    const optional<StringHolder>& getFromUserId() const
    {
        return ensureData().fromUserId;
    }

    /**
     * フレンドリクエストを送信したユーザIDを設定
     *
     * @param fromUserId フレンドリクエストを送信したユーザID
     */
    void setFromUserId(StringHolder fromUserId)
    {
        ensureData().fromUserId.emplace(std::move(fromUserId));
    }

    /**
     * フレンドリクエストを送信したユーザIDを設定
     *
     * @param fromUserId フレンドリクエストを送信したユーザID
     */
    AcceptRequestByUserIdRequest& withFromUserId(StringHolder fromUserId)
    {
        ensureData().fromUserId.emplace(std::move(fromUserId));
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
    AcceptRequestByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    AcceptRequestByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AcceptRequestByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_FRIEND_CONTROL_ACCEPTREQUESTBYUSERIDREQUEST_HPP_