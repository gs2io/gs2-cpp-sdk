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

#ifndef GS2_INBOX_CONTROL_DELETEMESSAGESREQUEST_HPP_
#define GS2_INBOX_CONTROL_DELETEMESSAGESREQUEST_HPP_

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
class DeleteMessagesRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "DeleteMessages";

private:
    class Data : public Gs2Object
    {
    public:
        /** 受信ボックスの名前を指定します。 */
        optional<StringHolder> inboxName;
        /** 削除するメッセージのメッセージIDのリストを指定します。 */
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
    DeleteMessagesRequest() :
        m_pData(nullptr)
    {}

    DeleteMessagesRequest(const DeleteMessagesRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteMessagesRequest(DeleteMessagesRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteMessagesRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteMessagesRequest& operator=(const DeleteMessagesRequest& deleteMessagesRequest)
    {
        Gs2BasicRequest::operator=(deleteMessagesRequest);
        Gs2Inbox::operator=(deleteMessagesRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteMessagesRequest.m_pData);

        return *this;
    }

    DeleteMessagesRequest& operator=(DeleteMessagesRequest&& deleteMessagesRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteMessagesRequest));
        Gs2Inbox::operator=(std::move(deleteMessagesRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteMessagesRequest.m_pData;
        deleteMessagesRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteMessagesRequest* operator->() const
    {
        return this;
    }

    DeleteMessagesRequest* operator->()
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
    DeleteMessagesRequest& withInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
        return *this;
    }

    /**
     * 削除するメッセージのメッセージIDのリストを指定します。を取得
     *
     * @return 削除するメッセージのメッセージIDのリストを指定します。
     */
    const optional<StringHolder>& getMessageIds() const
    {
        return ensureData().messageIds;
    }

    /**
     * 削除するメッセージのメッセージIDのリストを指定します。を設定
     *
     * @param messageIds 削除するメッセージのメッセージIDのリストを指定します。
     */
    void setMessageIds(const Char* messageIds)
    {
        ensureData().messageIds.emplace(messageIds);
    }

    /**
     * 削除するメッセージのメッセージIDのリストを指定します。を設定
     *
     * @param messageIds 削除するメッセージのメッセージIDのリストを指定します。
     */
    DeleteMessagesRequest& withMessageIds(const Char* messageIds)
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
    DeleteMessagesRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteMessagesRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteMessagesRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteMessagesRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INBOX_CONTROL_DELETEMESSAGESREQUEST_HPP_