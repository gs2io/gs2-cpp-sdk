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

#ifndef GS2_INBOX_CONTROL_UPDATEINBOXREQUEST_HPP_
#define GS2_INBOX_CONTROL_UPDATEINBOXREQUEST_HPP_

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
class UpdateInboxRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "UpdateInbox";

private:
    class Data : public Gs2Object
    {
    public:
        /** 受信ボックスの名前を指定します。 */
        optional<StringHolder> inboxName;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** メッセージの開封通知先URL */
        optional<StringHolder> cooperationUrl;
        /** メッセージ受信時 に実行されるGS2-Script */
        optional<StringHolder> receiveMessageTriggerScript;
        /** メッセージ受信完了時 に実行されるGS2-Script */
        optional<StringHolder> receiveMessageDoneTriggerScript;
        /** メッセージ開封時 に実行されるGS2-Script */
        optional<StringHolder> readMessageTriggerScript;
        /** メッセージ開封完了時 に実行されるGS2-Script */
        optional<StringHolder> readMessageDoneTriggerScript;
        /** メッセージ削除時 に実行されるGS2-Script */
        optional<StringHolder> deleteMessageTriggerScript;
        /** メッセージ削除完了時 に実行されるGS2-Script */
        optional<StringHolder> deleteMessageDoneTriggerScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            inboxName(data.inboxName),
            description(data.description),
            serviceClass(data.serviceClass),
            cooperationUrl(data.cooperationUrl),
            receiveMessageTriggerScript(data.receiveMessageTriggerScript),
            receiveMessageDoneTriggerScript(data.receiveMessageDoneTriggerScript),
            readMessageTriggerScript(data.readMessageTriggerScript),
            readMessageDoneTriggerScript(data.readMessageDoneTriggerScript),
            deleteMessageTriggerScript(data.deleteMessageTriggerScript),
            deleteMessageDoneTriggerScript(data.deleteMessageDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            inboxName(std::move(data.inboxName)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            cooperationUrl(std::move(data.cooperationUrl)),
            receiveMessageTriggerScript(std::move(data.receiveMessageTriggerScript)),
            receiveMessageDoneTriggerScript(std::move(data.receiveMessageDoneTriggerScript)),
            readMessageTriggerScript(std::move(data.readMessageTriggerScript)),
            readMessageDoneTriggerScript(std::move(data.readMessageDoneTriggerScript)),
            deleteMessageTriggerScript(std::move(data.deleteMessageTriggerScript)),
            deleteMessageDoneTriggerScript(std::move(data.deleteMessageDoneTriggerScript))
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
    UpdateInboxRequest() :
        m_pData(nullptr)
    {}

    UpdateInboxRequest(const UpdateInboxRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateInboxRequest(UpdateInboxRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateInboxRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateInboxRequest& operator=(const UpdateInboxRequest& updateInboxRequest)
    {
        Gs2BasicRequest::operator=(updateInboxRequest);
        Gs2Inbox::operator=(updateInboxRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateInboxRequest.m_pData);

        return *this;
    }

    UpdateInboxRequest& operator=(UpdateInboxRequest&& updateInboxRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateInboxRequest));
        Gs2Inbox::operator=(std::move(updateInboxRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateInboxRequest.m_pData;
        updateInboxRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateInboxRequest* operator->() const
    {
        return this;
    }

    UpdateInboxRequest* operator->()
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
    UpdateInboxRequest& withInboxName(const Char* inboxName)
    {
        ensureData().inboxName.emplace(inboxName);
        return *this;
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateInboxRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * サービスクラスを取得
     *
     * @return サービスクラス
     */
    const optional<StringHolder>& getServiceClass() const
    {
        return ensureData().serviceClass;
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    void setServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
    }

    /**
     * サービスクラスを設定
     *
     * @param serviceClass サービスクラス
     */
    UpdateInboxRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
    }

    /**
     * メッセージの開封通知先URLを取得
     *
     * @return メッセージの開封通知先URL
     */
    const optional<StringHolder>& getCooperationUrl() const
    {
        return ensureData().cooperationUrl;
    }

    /**
     * メッセージの開封通知先URLを設定
     *
     * @param cooperationUrl メッセージの開封通知先URL
     */
    void setCooperationUrl(const Char* cooperationUrl)
    {
        ensureData().cooperationUrl.emplace(cooperationUrl);
    }

    /**
     * メッセージの開封通知先URLを設定
     *
     * @param cooperationUrl メッセージの開封通知先URL
     */
    UpdateInboxRequest& withCooperationUrl(const Char* cooperationUrl)
    {
        ensureData().cooperationUrl.emplace(cooperationUrl);
        return *this;
    }

    /**
     * メッセージ受信時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ受信時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReceiveMessageTriggerScript() const
    {
        return ensureData().receiveMessageTriggerScript;
    }

    /**
     * メッセージ受信時 に実行されるGS2-Scriptを設定
     *
     * @param receiveMessageTriggerScript メッセージ受信時 に実行されるGS2-Script
     */
    void setReceiveMessageTriggerScript(const Char* receiveMessageTriggerScript)
    {
        ensureData().receiveMessageTriggerScript.emplace(receiveMessageTriggerScript);
    }

    /**
     * メッセージ受信時 に実行されるGS2-Scriptを設定
     *
     * @param receiveMessageTriggerScript メッセージ受信時 に実行されるGS2-Script
     */
    UpdateInboxRequest& withReceiveMessageTriggerScript(const Char* receiveMessageTriggerScript)
    {
        ensureData().receiveMessageTriggerScript.emplace(receiveMessageTriggerScript);
        return *this;
    }

    /**
     * メッセージ受信完了時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ受信完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReceiveMessageDoneTriggerScript() const
    {
        return ensureData().receiveMessageDoneTriggerScript;
    }

    /**
     * メッセージ受信完了時 に実行されるGS2-Scriptを設定
     *
     * @param receiveMessageDoneTriggerScript メッセージ受信完了時 に実行されるGS2-Script
     */
    void setReceiveMessageDoneTriggerScript(const Char* receiveMessageDoneTriggerScript)
    {
        ensureData().receiveMessageDoneTriggerScript.emplace(receiveMessageDoneTriggerScript);
    }

    /**
     * メッセージ受信完了時 に実行されるGS2-Scriptを設定
     *
     * @param receiveMessageDoneTriggerScript メッセージ受信完了時 に実行されるGS2-Script
     */
    UpdateInboxRequest& withReceiveMessageDoneTriggerScript(const Char* receiveMessageDoneTriggerScript)
    {
        ensureData().receiveMessageDoneTriggerScript.emplace(receiveMessageDoneTriggerScript);
        return *this;
    }

    /**
     * メッセージ開封時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ開封時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReadMessageTriggerScript() const
    {
        return ensureData().readMessageTriggerScript;
    }

    /**
     * メッセージ開封時 に実行されるGS2-Scriptを設定
     *
     * @param readMessageTriggerScript メッセージ開封時 に実行されるGS2-Script
     */
    void setReadMessageTriggerScript(const Char* readMessageTriggerScript)
    {
        ensureData().readMessageTriggerScript.emplace(readMessageTriggerScript);
    }

    /**
     * メッセージ開封時 に実行されるGS2-Scriptを設定
     *
     * @param readMessageTriggerScript メッセージ開封時 に実行されるGS2-Script
     */
    UpdateInboxRequest& withReadMessageTriggerScript(const Char* readMessageTriggerScript)
    {
        ensureData().readMessageTriggerScript.emplace(readMessageTriggerScript);
        return *this;
    }

    /**
     * メッセージ開封完了時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ開封完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getReadMessageDoneTriggerScript() const
    {
        return ensureData().readMessageDoneTriggerScript;
    }

    /**
     * メッセージ開封完了時 に実行されるGS2-Scriptを設定
     *
     * @param readMessageDoneTriggerScript メッセージ開封完了時 に実行されるGS2-Script
     */
    void setReadMessageDoneTriggerScript(const Char* readMessageDoneTriggerScript)
    {
        ensureData().readMessageDoneTriggerScript.emplace(readMessageDoneTriggerScript);
    }

    /**
     * メッセージ開封完了時 に実行されるGS2-Scriptを設定
     *
     * @param readMessageDoneTriggerScript メッセージ開封完了時 に実行されるGS2-Script
     */
    UpdateInboxRequest& withReadMessageDoneTriggerScript(const Char* readMessageDoneTriggerScript)
    {
        ensureData().readMessageDoneTriggerScript.emplace(readMessageDoneTriggerScript);
        return *this;
    }

    /**
     * メッセージ削除時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ削除時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteMessageTriggerScript() const
    {
        return ensureData().deleteMessageTriggerScript;
    }

    /**
     * メッセージ削除時 に実行されるGS2-Scriptを設定
     *
     * @param deleteMessageTriggerScript メッセージ削除時 に実行されるGS2-Script
     */
    void setDeleteMessageTriggerScript(const Char* deleteMessageTriggerScript)
    {
        ensureData().deleteMessageTriggerScript.emplace(deleteMessageTriggerScript);
    }

    /**
     * メッセージ削除時 に実行されるGS2-Scriptを設定
     *
     * @param deleteMessageTriggerScript メッセージ削除時 に実行されるGS2-Script
     */
    UpdateInboxRequest& withDeleteMessageTriggerScript(const Char* deleteMessageTriggerScript)
    {
        ensureData().deleteMessageTriggerScript.emplace(deleteMessageTriggerScript);
        return *this;
    }

    /**
     * メッセージ削除完了時 に実行されるGS2-Scriptを取得
     *
     * @return メッセージ削除完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getDeleteMessageDoneTriggerScript() const
    {
        return ensureData().deleteMessageDoneTriggerScript;
    }

    /**
     * メッセージ削除完了時 に実行されるGS2-Scriptを設定
     *
     * @param deleteMessageDoneTriggerScript メッセージ削除完了時 に実行されるGS2-Script
     */
    void setDeleteMessageDoneTriggerScript(const Char* deleteMessageDoneTriggerScript)
    {
        ensureData().deleteMessageDoneTriggerScript.emplace(deleteMessageDoneTriggerScript);
    }

    /**
     * メッセージ削除完了時 に実行されるGS2-Scriptを設定
     *
     * @param deleteMessageDoneTriggerScript メッセージ削除完了時 に実行されるGS2-Script
     */
    UpdateInboxRequest& withDeleteMessageDoneTriggerScript(const Char* deleteMessageDoneTriggerScript)
    {
        ensureData().deleteMessageDoneTriggerScript.emplace(deleteMessageDoneTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateInboxRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateInboxRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateInboxRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateInboxRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INBOX_CONTROL_UPDATEINBOXREQUEST_HPP_