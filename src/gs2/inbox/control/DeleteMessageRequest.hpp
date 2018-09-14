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

#ifndef GS2_INBOX_CONTROL_DELETEMESSAGEREQUEST_HPP_
#define GS2_INBOX_CONTROL_DELETEMESSAGEREQUEST_HPP_

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
class DeleteMessageRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "DeleteMessage";

private:
    class Data : public Gs2Object
    {
    public:
        /** 受信ボックスの名前を指定します。 */
        optional<StringHolder> inboxName;
        /** 削除するメッセージIDを指定します。 */
        optional<StringHolder> messageId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            inboxName(data.inboxName),
            messageId(data.messageId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            inboxName(std::move(data.inboxName)),
            messageId(std::move(data.messageId))
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
    DeleteMessageRequest() :
        m_pData(nullptr)
    {}

    DeleteMessageRequest(const DeleteMessageRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteMessageRequest(DeleteMessageRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteMessageRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteMessageRequest& operator=(const DeleteMessageRequest& deleteMessageRequest)
    {
        Gs2BasicRequest::operator=(deleteMessageRequest);
        Gs2Inbox::operator=(deleteMessageRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteMessageRequest.m_pData);

        return *this;
    }

    DeleteMessageRequest& operator=(DeleteMessageRequest&& deleteMessageRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteMessageRequest));
        Gs2Inbox::operator=(std::move(deleteMessageRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteMessageRequest.m_pData;
        deleteMessageRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteMessageRequest* operator->() const
    {
        return this;
    }

    DeleteMessageRequest* operator->()
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
    DeleteMessageRequest& withInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
        return *this;
    }

    /**
     * 削除するメッセージIDを指定します。を取得
     *
     * @return 削除するメッセージIDを指定します。
     */
    const optional<StringHolder>& getMessageId() const
    {
        return ensureData().messageId;
    }

    /**
     * 削除するメッセージIDを指定します。を設定
     *
     * @param messageId 削除するメッセージIDを指定します。
     */
    void setMessageId(const Char* messageId)
    {
        ensureData().messageId.emplace(messageId);
    }

    /**
     * 削除するメッセージIDを指定します。を設定
     *
     * @param messageId 削除するメッセージIDを指定します。
     */
    DeleteMessageRequest& withMessageId(const Char* messageId)
    {
        ensureData().messageId.emplace(messageId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteMessageRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteMessageRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteMessageRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteMessageRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INBOX_CONTROL_DELETEMESSAGEREQUEST_HPP_