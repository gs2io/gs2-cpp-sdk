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

#ifndef GS2_INBOX_CONTROL_GETMESSAGEREQUEST_HPP_
#define GS2_INBOX_CONTROL_GETMESSAGEREQUEST_HPP_

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
class GetMessageRequest : public Gs2UserRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** プレゼントボックス名 */
        optional<StringHolder> namespaceName;
        /** メッセージID */
        optional<StringHolder> messageName;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            messageName(data.messageName),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            messageName(std::move(data.messageName)),
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
    GetMessageRequest() :
        m_pData(nullptr)
    {}

    GetMessageRequest(const GetMessageRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetMessageRequest(GetMessageRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetMessageRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetMessageRequest& operator=(const GetMessageRequest& getMessageRequest)
    {
        Gs2UserRequest::operator=(getMessageRequest);
        Gs2Inbox::operator=(getMessageRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getMessageRequest.m_pData);

        return *this;
    }

    GetMessageRequest& operator=(GetMessageRequest&& getMessageRequest)
    {
        Gs2UserRequest::operator=(std::move(getMessageRequest));
        Gs2Inbox::operator=(std::move(getMessageRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getMessageRequest.m_pData;
        getMessageRequest.m_pData = nullptr;

        return *this;
    }

    const GetMessageRequest* operator->() const
    {
        return this;
    }

    GetMessageRequest* operator->()
    {
        return this;
    }
    /**
     * プレゼントボックス名を取得
     *
     * @return プレゼントボックス名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param namespaceName プレゼントボックス名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param namespaceName プレゼントボックス名
     */
    GetMessageRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * メッセージIDを取得
     *
     * @return メッセージID
     */
    const optional<StringHolder>& getMessageName() const
    {
        return ensureData().messageName;
    }

    /**
     * メッセージIDを設定
     *
     * @param messageName メッセージID
     */
    void setMessageName(const Char* messageName)
    {
        ensureData().messageName.emplace(messageName);
    }

    /**
     * メッセージIDを設定
     *
     * @param messageName メッセージID
     */
    GetMessageRequest& withMessageName(const Char* messageName)
    {
        ensureData().messageName.emplace(messageName);
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
    GetMessageRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    GetMessageRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetMessageRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetMessageRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetMessageRequest& withRequestId(const Char* gs2RequestId)
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
    GetMessageRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_INBOX_CONTROL_GETMESSAGEREQUEST_HPP_