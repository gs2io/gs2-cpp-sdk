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

#ifndef GS2_INBOX_CONTROL_GETMESSAGESREQUEST_HPP_
#define GS2_INBOX_CONTROL_GETMESSAGESREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InboxConst.hpp"

namespace gs2 { namespace inbox
{

/**
 * メッセージを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetMessagesRequest : public Gs2UserRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** プレゼントボックス名 */
        optional<StringHolder> inboxName;
        /** メッセージIDのリスト */
        optional<List<StringHolder>> messageNames;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            inboxName(data.inboxName),
            messageNames(data.messageNames),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            inboxName(std::move(data.inboxName)),
            messageNames(std::move(data.messageNames)),
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
    GetMessagesRequest() :
        m_pData(nullptr)
    {}

    GetMessagesRequest(const GetMessagesRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetMessagesRequest(GetMessagesRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetMessagesRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMessagesRequest& operator=(const GetMessagesRequest& getMessagesRequest)
    {
        Gs2UserRequest::operator=(getMessagesRequest);
        Gs2Inbox::operator=(getMessagesRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMessagesRequest.m_pData);

        return *this;
    }

    GetMessagesRequest& operator=(GetMessagesRequest&& getMessagesRequest)
    {
        Gs2UserRequest::operator=(std::move(getMessagesRequest));
        Gs2Inbox::operator=(std::move(getMessagesRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMessagesRequest.m_pData;
        getMessagesRequest.m_pData = nullptr;

        return *this;
    }

    const GetMessagesRequest* operator->() const
    {
        return this;
    }

    GetMessagesRequest* operator->()
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
    GetMessagesRequest& withInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
        return *this;
    }

    /**
     * メッセージIDのリストを取得
     *
     * @return メッセージIDのリスト
     */
    const optional<List<StringHolder>>& getMessageNames() const
    {
        return ensureData().messageNames;
    }

    /**
     * メッセージIDのリストを設定
     *
     * @param messageNames メッセージIDのリスト
     */
    void setMessageNames(const List<StringHolder>& messageNames)
    {
        ensureData().messageNames.emplace(messageNames);
    }

    /**
     * メッセージIDのリストを設定
     *
     * @param messageNames メッセージIDのリスト
     */
    GetMessagesRequest& withMessageNames(const List<StringHolder>& messageNames)
    {
        ensureData().messageNames.emplace(messageNames);
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
    GetMessagesRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    GetMessagesRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetMessagesRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetMessagesRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetMessagesRequest& withRequestId(const Char* gs2RequestId)
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
    GetMessagesRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
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

#endif //GS2_INBOX_CONTROL_GETMESSAGESREQUEST_HPP_