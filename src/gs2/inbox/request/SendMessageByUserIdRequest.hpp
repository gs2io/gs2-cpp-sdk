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

#ifndef GS2_INBOX_CONTROL_SENDMESSAGEBYUSERIDREQUEST_HPP_
#define GS2_INBOX_CONTROL_SENDMESSAGEBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InboxConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * メッセージを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class SendMessageByUserIdRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** プレゼントボックス名 */
        optional<StringHolder> inboxName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** メッセージの内容に相当するメタデータ */
        optional<StringHolder> metadata;
        /** メッセージ開封時 に実行されるスクリプト のGRN */
        optional<StringHolder> readMessageTriggerScriptId;
        /** メッセージ開封時 に実行されるスクリプト に指定する引数 */
        optional<StringHolder> readMessageTriggerScriptArgs;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            inboxName(data.inboxName),
            userId(data.userId),
            metadata(data.metadata),
            readMessageTriggerScriptId(data.readMessageTriggerScriptId),
            readMessageTriggerScriptArgs(data.readMessageTriggerScriptArgs),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            inboxName(std::move(data.inboxName)),
            userId(std::move(data.userId)),
            metadata(std::move(data.metadata)),
            readMessageTriggerScriptId(std::move(data.readMessageTriggerScriptId)),
            readMessageTriggerScriptArgs(std::move(data.readMessageTriggerScriptArgs)),
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
    SendMessageByUserIdRequest() :
        m_pData(nullptr)
    {}

    SendMessageByUserIdRequest(const SendMessageByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SendMessageByUserIdRequest(SendMessageByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SendMessageByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SendMessageByUserIdRequest& operator=(const SendMessageByUserIdRequest& sendMessageByUserIdRequest)
    {
        Gs2BasicRequest::operator=(sendMessageByUserIdRequest);
        Gs2Inbox::operator=(sendMessageByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*sendMessageByUserIdRequest.m_pData);

        return *this;
    }

    SendMessageByUserIdRequest& operator=(SendMessageByUserIdRequest&& sendMessageByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(sendMessageByUserIdRequest));
        Gs2Inbox::operator=(std::move(sendMessageByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = sendMessageByUserIdRequest.m_pData;
        sendMessageByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const SendMessageByUserIdRequest* operator->() const
    {
        return this;
    }

    SendMessageByUserIdRequest* operator->()
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
    SendMessageByUserIdRequest& withInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
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
    SendMessageByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * メッセージの内容に相当するメタデータを取得
     *
     * @return メッセージの内容に相当するメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メッセージの内容に相当するメタデータを設定
     *
     * @param metadata メッセージの内容に相当するメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * メッセージの内容に相当するメタデータを設定
     *
     * @param metadata メッセージの内容に相当するメタデータ
     */
    SendMessageByUserIdRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
        return *this;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ開封時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReadMessageTriggerScriptId() const
    {
        return ensureData().readMessageTriggerScriptId;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageTriggerScriptId メッセージ開封時 に実行されるスクリプト のGRN
     */
    void setReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
    {
        ensureData().readMessageTriggerScriptId.emplace(readMessageTriggerScriptId);
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageTriggerScriptId メッセージ開封時 に実行されるスクリプト のGRN
     */
    SendMessageByUserIdRequest& withReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
    {
        ensureData().readMessageTriggerScriptId.emplace(readMessageTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト に指定する引数を取得
     *
     * @return メッセージ開封時 に実行されるスクリプト に指定する引数
     */
    const optional<StringHolder>& getReadMessageTriggerScriptArgs() const
    {
        return ensureData().readMessageTriggerScriptArgs;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト に指定する引数を設定
     *
     * @param readMessageTriggerScriptArgs メッセージ開封時 に実行されるスクリプト に指定する引数
     */
    void setReadMessageTriggerScriptArgs(const Char* readMessageTriggerScriptArgs)
    {
        ensureData().readMessageTriggerScriptArgs.emplace(readMessageTriggerScriptArgs);
    }

    /**
     * メッセージ開封時 に実行されるスクリプト に指定する引数を設定
     *
     * @param readMessageTriggerScriptArgs メッセージ開封時 に実行されるスクリプト に指定する引数
     */
    SendMessageByUserIdRequest& withReadMessageTriggerScriptArgs(const Char* readMessageTriggerScriptArgs)
    {
        ensureData().readMessageTriggerScriptArgs.emplace(readMessageTriggerScriptArgs);
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
    SendMessageByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    SendMessageByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    SendMessageByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    SendMessageByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SendMessageByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INBOX_CONTROL_SENDMESSAGEBYUSERIDREQUEST_HPP_