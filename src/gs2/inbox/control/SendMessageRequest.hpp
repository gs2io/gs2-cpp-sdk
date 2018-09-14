/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_INBOX_CONTROL_SENDMESSAGEREQUEST_HPP_
#define GS2_INBOX_CONTROL_SENDMESSAGEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InboxConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * @author Game Server Services, Inc.
 */
class SendMessageRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "SendMessage";

private:
    class Data : public Gs2Object
    {
    public:
        /** 受信ボックスの名前を指定します。 */
        optional<StringHolder> inboxName;
        /** メッセージを送信する相手のユーザID */
        optional<StringHolder> userId;
        /** 送信するメッセージ本文 */
        optional<StringHolder> message;
        /** true を設定すると、メッセージ開封時に受信ボックスに指定された連携用URLにメッセージIDが通知されます */
        optional<Bool> cooperation;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            inboxName(data.inboxName),
            userId(data.userId),
            message(data.message),
            cooperation(data.cooperation)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            inboxName(std::move(data.inboxName)),
            userId(std::move(data.userId)),
            message(std::move(data.message)),
            cooperation(std::move(data.cooperation))
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
    SendMessageRequest() :
        m_pData(nullptr)
    {}

    SendMessageRequest(const SendMessageRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SendMessageRequest(SendMessageRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SendMessageRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SendMessageRequest& operator=(const SendMessageRequest& sendMessageRequest)
    {
        Gs2BasicRequest::operator=(sendMessageRequest);
        Gs2Inbox::operator=(sendMessageRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*sendMessageRequest.m_pData);

        return *this;
    }

    SendMessageRequest& operator=(SendMessageRequest&& sendMessageRequest)
    {
        Gs2BasicRequest::operator=(std::move(sendMessageRequest));
        Gs2Inbox::operator=(std::move(sendMessageRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = sendMessageRequest.m_pData;
        sendMessageRequest.m_pData = nullptr;

        return *this;
    }

    const SendMessageRequest* operator->() const
    {
        return this;
    }

    SendMessageRequest* operator->()
    {
        return this;
    }

    /**
     * 受信ボックスの名前を指定します。を取得
     *
     * @return 受信ボックスの名前を指定します。
     */
    const optional<StringHolder>& getInboxName() const
    {
        return ensureData().inboxName;
    }

    /**
     * 受信ボックスの名前を指定します。を設定
     *
     * @param inboxName 受信ボックスの名前を指定します。
     */
    void setInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
    }

    /**
     * 受信ボックスの名前を指定します。を設定
     *
     * @param inboxName 受信ボックスの名前を指定します。
     */
    SendMessageRequest& withInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
        return *this;
    }

    /**
     * メッセージを送信する相手のユーザIDを取得
     *
     * @return メッセージを送信する相手のユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * メッセージを送信する相手のユーザIDを設定
     *
     * @param userId メッセージを送信する相手のユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * メッセージを送信する相手のユーザIDを設定
     *
     * @param userId メッセージを送信する相手のユーザID
     */
    SendMessageRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 送信するメッセージ本文を取得
     *
     * @return 送信するメッセージ本文
     */
    const optional<StringHolder>& getMessage() const
    {
        return ensureData().message;
    }

    /**
     * 送信するメッセージ本文を設定
     *
     * @param message 送信するメッセージ本文
     */
    void setMessage(const Char* message)
    {
        ensureData().message.emplace(message);
    }

    /**
     * 送信するメッセージ本文を設定
     *
     * @param message 送信するメッセージ本文
     */
    SendMessageRequest& withMessage(const Char* message)
    {
        ensureData().message.emplace(message);
        return *this;
    }

    /**
     * true を設定すると、メッセージ開封時に受信ボックスに指定された連携用URLにメッセージIDが通知されますを取得
     *
     * @return true を設定すると、メッセージ開封時に受信ボックスに指定された連携用URLにメッセージIDが通知されます
     */
    const optional<Bool>& getCooperation() const
    {
        return ensureData().cooperation;
    }

    /**
     * true を設定すると、メッセージ開封時に受信ボックスに指定された連携用URLにメッセージIDが通知されますを設定
     *
     * @param cooperation true を設定すると、メッセージ開封時に受信ボックスに指定された連携用URLにメッセージIDが通知されます
     */
    void setCooperation(Bool cooperation)
    {
        ensureData().cooperation.emplace(cooperation);
    }

    /**
     * true を設定すると、メッセージ開封時に受信ボックスに指定された連携用URLにメッセージIDが通知されますを設定
     *
     * @param cooperation true を設定すると、メッセージ開封時に受信ボックスに指定された連携用URLにメッセージIDが通知されます
     */
    SendMessageRequest& withCooperation(Bool cooperation)
    {
        ensureData().cooperation.emplace(cooperation);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    SendMessageRequest& withGs2ClientId(const Char* gs2ClientId)
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
    SendMessageRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    SendMessageRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SendMessageRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_INBOX_CONTROL_SENDMESSAGEREQUEST_HPP_