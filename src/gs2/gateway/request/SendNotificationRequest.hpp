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

#ifndef GS2_GATEWAY_CONTROL_SENDNOTIFICATIONREQUEST_HPP_
#define GS2_GATEWAY_CONTROL_SENDNOTIFICATIONREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2GatewayConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace gateway
{

/**
 * 通知を送信 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SendNotificationRequest : public Gs2BasicRequest, public Gs2Gateway
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 通知元のサービス */
        optional<StringHolder> issuer;
        /** タイトル */
        optional<StringHolder> subject;
        /** ペイロード */
        optional<StringHolder> payload;
        /** 通知先のユーザがオフラインだったときにモバイルプッシュ通知に転送するか */
        optional<Bool> enableTransferMobileNotification;
        /** 再生する音声ファイル名 */
        optional<StringHolder> sound;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            issuer(data.issuer),
            subject(data.subject),
            payload(data.payload),
            enableTransferMobileNotification(data.enableTransferMobileNotification),
            sound(data.sound),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            userId(std::move(data.userId)),
            issuer(std::move(data.issuer)),
            subject(std::move(data.subject)),
            payload(std::move(data.payload)),
            enableTransferMobileNotification(std::move(data.enableTransferMobileNotification)),
            sound(std::move(data.sound)),
            duplicationAvoider(std::move(data.duplicationAvoider))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    SendNotificationRequest() :
        m_pData(nullptr)
    {}

    SendNotificationRequest(const SendNotificationRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Gateway(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SendNotificationRequest(SendNotificationRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Gateway(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SendNotificationRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SendNotificationRequest& operator=(const SendNotificationRequest& sendNotificationRequest)
    {
        Gs2BasicRequest::operator=(sendNotificationRequest);
        Gs2Gateway::operator=(sendNotificationRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*sendNotificationRequest.m_pData);

        return *this;
    }

    SendNotificationRequest& operator=(SendNotificationRequest&& sendNotificationRequest)
    {
        Gs2BasicRequest::operator=(std::move(sendNotificationRequest));
        Gs2Gateway::operator=(std::move(sendNotificationRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = sendNotificationRequest.m_pData;
        sendNotificationRequest.m_pData = nullptr;

        return *this;
    }

    const SendNotificationRequest* operator->() const
    {
        return this;
    }

    SendNotificationRequest* operator->()
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    SendNotificationRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    SendNotificationRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 通知元のサービスを取得
     *
     * @return 通知元のサービス
     */
    const optional<StringHolder>& getIssuer() const
    {
        return ensureData().issuer;
    }

    /**
     * 通知元のサービスを設定
     *
     * @param issuer 通知元のサービス
     */
    void setIssuer(const Char* issuer)
    {
        ensureData().issuer.emplace(issuer);
    }

    /**
     * 通知元のサービスを設定
     *
     * @param issuer 通知元のサービス
     */
    SendNotificationRequest& withIssuer(const Char* issuer)
    {
        ensureData().issuer.emplace(issuer);
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
    void setSubject(const Char* subject)
    {
        ensureData().subject.emplace(subject);
    }

    /**
     * タイトルを設定
     *
     * @param subject タイトル
     */
    SendNotificationRequest& withSubject(const Char* subject)
    {
        ensureData().subject.emplace(subject);
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
    void setPayload(const Char* payload)
    {
        ensureData().payload.emplace(payload);
    }

    /**
     * ペイロードを設定
     *
     * @param payload ペイロード
     */
    SendNotificationRequest& withPayload(const Char* payload)
    {
        ensureData().payload.emplace(payload);
        return *this;
    }

    /**
     * 通知先のユーザがオフラインだったときにモバイルプッシュ通知に転送するかを取得
     *
     * @return 通知先のユーザがオフラインだったときにモバイルプッシュ通知に転送するか
     */
    const optional<Bool>& getEnableTransferMobileNotification() const
    {
        return ensureData().enableTransferMobileNotification;
    }

    /**
     * 通知先のユーザがオフラインだったときにモバイルプッシュ通知に転送するかを設定
     *
     * @param enableTransferMobileNotification 通知先のユーザがオフラインだったときにモバイルプッシュ通知に転送するか
     */
    void setEnableTransferMobileNotification(Bool enableTransferMobileNotification)
    {
        ensureData().enableTransferMobileNotification.emplace(enableTransferMobileNotification);
    }

    /**
     * 通知先のユーザがオフラインだったときにモバイルプッシュ通知に転送するかを設定
     *
     * @param enableTransferMobileNotification 通知先のユーザがオフラインだったときにモバイルプッシュ通知に転送するか
     */
    SendNotificationRequest& withEnableTransferMobileNotification(Bool enableTransferMobileNotification)
    {
        ensureData().enableTransferMobileNotification.emplace(enableTransferMobileNotification);
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
    void setSound(const Char* sound)
    {
        ensureData().sound.emplace(sound);
    }

    /**
     * 再生する音声ファイル名を設定
     *
     * @param sound 再生する音声ファイル名
     */
    SendNotificationRequest& withSound(const Char* sound)
    {
        ensureData().sound.emplace(sound);
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
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    SendNotificationRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    SendNotificationRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    SendNotificationRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    SendNotificationRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SendNotificationRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_GATEWAY_CONTROL_SENDNOTIFICATIONREQUEST_HPP_