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

#ifndef GS2_INBOX_CONTROL_SENDMESSAGESBYUSERIDREQUEST_HPP_
#define GS2_INBOX_CONTROL_SENDMESSAGESBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InboxConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * メッセージを複数まとめて新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SendMessagesByUserIdRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** プレゼントボックス名 */
        optional<StringHolder> inboxName;
        /** 一括送信するメッセージのボディリスト */
        optional<List<Body>> bodies;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            inboxName(data.inboxName),
            bodies(data.bodies)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            inboxName(std::move(data.inboxName)),
            bodies(std::move(data.bodies))
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
    SendMessagesByUserIdRequest() :
        m_pData(nullptr)
    {}

    SendMessagesByUserIdRequest(const SendMessagesByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SendMessagesByUserIdRequest(SendMessagesByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SendMessagesByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SendMessagesByUserIdRequest& operator=(const SendMessagesByUserIdRequest& sendMessagesByUserIdRequest)
    {
        Gs2BasicRequest::operator=(sendMessagesByUserIdRequest);
        Gs2Inbox::operator=(sendMessagesByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*sendMessagesByUserIdRequest.m_pData);

        return *this;
    }

    SendMessagesByUserIdRequest& operator=(SendMessagesByUserIdRequest&& sendMessagesByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(sendMessagesByUserIdRequest));
        Gs2Inbox::operator=(std::move(sendMessagesByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = sendMessagesByUserIdRequest.m_pData;
        sendMessagesByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const SendMessagesByUserIdRequest* operator->() const
    {
        return this;
    }

    SendMessagesByUserIdRequest* operator->()
    {
        return this;
    }
    /**
     * プレゼントボックス名を取得
     *
     * @return プレゼントボックス名
     */
    const optional<StringHolder>& getInboxName() const
    {
        return ensureData().inboxName;
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param inboxName プレゼントボックス名
     */
    void setInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param inboxName プレゼントボックス名
     */
    SendMessagesByUserIdRequest& withInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
        return *this;
    }

    /**
     * 一括送信するメッセージのボディリストを取得
     *
     * @return 一括送信するメッセージのボディリスト
     */
    const optional<List<Body>>& getBodies() const
    {
        return ensureData().bodies;
    }

    /**
     * 一括送信するメッセージのボディリストを設定
     *
     * @param bodies 一括送信するメッセージのボディリスト
     */
    void setBodies(const List<Body>& bodies)
    {
        ensureData().bodies.emplace(bodies);
    }

    /**
     * 一括送信するメッセージのボディリストを設定
     *
     * @param bodies 一括送信するメッセージのボディリスト
     */
    SendMessagesByUserIdRequest& withBodies(const List<Body>& bodies)
    {
        ensureData().bodies.emplace(bodies);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    SendMessagesByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    SendMessagesByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    SendMessagesByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SendMessagesByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INBOX_CONTROL_SENDMESSAGESBYUSERIDREQUEST_HPP_