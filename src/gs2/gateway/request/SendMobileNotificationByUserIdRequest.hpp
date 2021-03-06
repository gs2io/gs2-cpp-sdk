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

#ifndef GS2_GATEWAY_CONTROL_SENDMOBILENOTIFICATIONBYUSERIDREQUEST_HPP_
#define GS2_GATEWAY_CONTROL_SENDMOBILENOTIFICATIONBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/gateway/Gs2GatewayConst.hpp>
#include <gs2/gateway/model/model.hpp>
#include <memory>

namespace gs2 { namespace gateway
{

/**
 * モバイルプッシュ通知を送信 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SendMobileNotificationByUserIdRequest : public Gs2BasicRequest, public Gs2Gateway
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** タイトル */
        optional<StringHolder> subject;
        /** ペイロード */
        optional<StringHolder> payload;
        /** 再生する音声ファイル名 */
        optional<StringHolder> sound;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            subject(data.subject),
            payload(data.payload),
            sound(data.sound),
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
    SendMobileNotificationByUserIdRequest() = default;
    SendMobileNotificationByUserIdRequest(const SendMobileNotificationByUserIdRequest& sendMobileNotificationByUserIdRequest) = default;
    SendMobileNotificationByUserIdRequest(SendMobileNotificationByUserIdRequest&& sendMobileNotificationByUserIdRequest) = default;
    ~SendMobileNotificationByUserIdRequest() GS2_OVERRIDE = default;

    SendMobileNotificationByUserIdRequest& operator=(const SendMobileNotificationByUserIdRequest& sendMobileNotificationByUserIdRequest) = default;
    SendMobileNotificationByUserIdRequest& operator=(SendMobileNotificationByUserIdRequest&& sendMobileNotificationByUserIdRequest) = default;

    SendMobileNotificationByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(SendMobileNotificationByUserIdRequest);
    }

    const SendMobileNotificationByUserIdRequest* operator->() const
    {
        return this;
    }

    SendMobileNotificationByUserIdRequest* operator->()
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
    SendMobileNotificationByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    SendMobileNotificationByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * タイトルを取得
     *
     * @return タイトル
     */
    const optional<StringHolder>& getSubject() const
    {
        return ensureData().subject;
    }

    /**
     * タイトルを設定
     *
     * @param subject タイトル
     */
    void setSubject(StringHolder subject)
    {
        ensureData().subject.emplace(std::move(subject));
    }

    /**
     * タイトルを設定
     *
     * @param subject タイトル
     */
    SendMobileNotificationByUserIdRequest& withSubject(StringHolder subject)
    {
        ensureData().subject.emplace(std::move(subject));
        return *this;
    }

    /**
     * ペイロードを取得
     *
     * @return ペイロード
     */
    const optional<StringHolder>& getPayload() const
    {
        return ensureData().payload;
    }

    /**
     * ペイロードを設定
     *
     * @param payload ペイロード
     */
    void setPayload(StringHolder payload)
    {
        ensureData().payload.emplace(std::move(payload));
    }

    /**
     * ペイロードを設定
     *
     * @param payload ペイロード
     */
    SendMobileNotificationByUserIdRequest& withPayload(StringHolder payload)
    {
        ensureData().payload.emplace(std::move(payload));
        return *this;
    }

    /**
     * 再生する音声ファイル名を取得
     *
     * @return 再生する音声ファイル名
     */
    const optional<StringHolder>& getSound() const
    {
        return ensureData().sound;
    }

    /**
     * 再生する音声ファイル名を設定
     *
     * @param sound 再生する音声ファイル名
     */
    void setSound(StringHolder sound)
    {
        ensureData().sound.emplace(std::move(sound));
    }

    /**
     * 再生する音声ファイル名を設定
     *
     * @param sound 再生する音声ファイル名
     */
    SendMobileNotificationByUserIdRequest& withSound(StringHolder sound)
    {
        ensureData().sound.emplace(std::move(sound));
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
    SendMobileNotificationByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    SendMobileNotificationByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SendMobileNotificationByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_GATEWAY_CONTROL_SENDMOBILENOTIFICATIONBYUSERIDREQUEST_HPP_