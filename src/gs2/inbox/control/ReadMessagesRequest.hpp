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

#ifndef GS2_INBOX_CONTROL_READMESSAGESREQUEST_HPP_
#define GS2_INBOX_CONTROL_READMESSAGESREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InboxConst.hpp"

namespace gs2 { namespace inbox {

/**
 * @author Game Server Services, Inc.
 */
class ReadMessagesRequest : public Gs2UserRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "ReadMessages";

private:
    class Data : public Gs2Object
    {
    public:
        /** 受信ボックスの名前を指定します。 */
        optional<StringHolder> inboxName;
        /** カンマ区切りの開封するメッセージのメッセージIDリスト */
        optional<StringHolder> messageIds;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            inboxName(data.inboxName),
            messageIds(data.messageIds)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            inboxName(std::move(data.inboxName)),
            messageIds(std::move(data.messageIds))
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
    ReadMessagesRequest() :
        m_pData(nullptr)
    {}

    ReadMessagesRequest(const ReadMessagesRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    ReadMessagesRequest(ReadMessagesRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~ReadMessagesRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ReadMessagesRequest& operator=(const ReadMessagesRequest& readMessagesRequest)
    {
        Gs2UserRequest::operator=(readMessagesRequest);
        Gs2Inbox::operator=(readMessagesRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*readMessagesRequest.m_pData);

        return *this;
    }

    ReadMessagesRequest& operator=(ReadMessagesRequest&& readMessagesRequest)
    {
        Gs2UserRequest::operator=(std::move(readMessagesRequest));
        Gs2Inbox::operator=(std::move(readMessagesRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = readMessagesRequest.m_pData;
        readMessagesRequest.m_pData = nullptr;

        return *this;
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
    ReadMessagesRequest& withInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
        return *this;
    }

    /**
     * カンマ区切りの開封するメッセージのメッセージIDリストを取得
     *
     * @return カンマ区切りの開封するメッセージのメッセージIDリスト
     */
    const optional<StringHolder>& getMessageIds() const
    {
        return ensureData().messageIds;
    }

    /**
     * カンマ区切りの開封するメッセージのメッセージIDリストを設定
     *
     * @param messageIds カンマ区切りの開封するメッセージのメッセージIDリスト
     */
    void setMessageIds(const Char* messageIds)
    {
        ensureData().messageIds.emplace(messageIds);
    }

    /**
     * カンマ区切りの開封するメッセージのメッセージIDリストを設定
     *
     * @param messageIds カンマ区切りの開封するメッセージのメッセージIDリスト
     */
    ReadMessagesRequest& withMessageIds(const Char* messageIds)
    {
        ensureData().messageIds.emplace(messageIds);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    ReadMessagesRequest& withGs2ClientId(const Char* gs2ClientId)
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
    ReadMessagesRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    ReadMessagesRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    ReadMessagesRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    ReadMessagesRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_INBOX_CONTROL_READMESSAGESREQUEST_HPP_