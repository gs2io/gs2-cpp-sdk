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

#ifndef GS2_INBOX_CONTROL_CREATEINBOXREQUEST_HPP_
#define GS2_INBOX_CONTROL_CREATEINBOXREQUEST_HPP_

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
class CreateInboxRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "CreateInbox";

private:
    class Data : public Gs2Object
    {
    public:
        /** 受信ボックス名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービスクラス */
        optional<StringHolder> serviceClass;
        /** 開封時自動削除 */
        optional<Bool> autoDelete;
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
            name(data.name),
            description(data.description),
            serviceClass(data.serviceClass),
            autoDelete(data.autoDelete),
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
            name(std::move(data.name)),
            description(std::move(data.description)),
            serviceClass(std::move(data.serviceClass)),
            autoDelete(std::move(data.autoDelete)),
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
    CreateInboxRequest() :
        m_pData(nullptr)
    {}

    CreateInboxRequest(const CreateInboxRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateInboxRequest(CreateInboxRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateInboxRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateInboxRequest& operator=(const CreateInboxRequest& createInboxRequest)
    {
        Gs2BasicRequest::operator=(createInboxRequest);
        Gs2Inbox::operator=(createInboxRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createInboxRequest.m_pData);

        return *this;
    }

    CreateInboxRequest& operator=(CreateInboxRequest&& createInboxRequest)
    {
        Gs2BasicRequest::operator=(std::move(createInboxRequest));
        Gs2Inbox::operator=(std::move(createInboxRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createInboxRequest.m_pData;
        createInboxRequest.m_pData = nullptr;

        return *this;
    }

    const CreateInboxRequest* operator->() const
    {
        return this;
    }

    CreateInboxRequest* operator->()
    {
        return this;
    }

    /**
     * 受信ボックス名を取得
     *
     * @return 受信ボックス名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 受信ボックス名を設定
     *
     * @param name 受信ボックス名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 受信ボックス名を設定
     *
     * @param name 受信ボックス名
     */
    CreateInboxRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    CreateInboxRequest& withDescription(const Char* description)
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
    CreateInboxRequest& withServiceClass(const Char* serviceClass)
    {
        ensureData().serviceClass.emplace(serviceClass);
        return *this;
    }

    /**
     * 開封時自動削除を取得
     *
     * @return 開封時自動削除
     */
    const optional<Bool>& getAutoDelete() const
    {
        return ensureData().autoDelete;
    }

    /**
     * 開封時自動削除を設定
     *
     * @param autoDelete 開封時自動削除
     */
    void setAutoDelete(Bool autoDelete)
    {
        ensureData().autoDelete.emplace(autoDelete);
    }

    /**
     * 開封時自動削除を設定
     *
     * @param autoDelete 開封時自動削除
     */
    CreateInboxRequest& withAutoDelete(Bool autoDelete)
    {
        ensureData().autoDelete.emplace(autoDelete);
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
    CreateInboxRequest& withCooperationUrl(const Char* cooperationUrl)
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
    CreateInboxRequest& withReceiveMessageTriggerScript(const Char* receiveMessageTriggerScript)
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
    CreateInboxRequest& withReceiveMessageDoneTriggerScript(const Char* receiveMessageDoneTriggerScript)
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
    CreateInboxRequest& withReadMessageTriggerScript(const Char* readMessageTriggerScript)
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
    CreateInboxRequest& withReadMessageDoneTriggerScript(const Char* readMessageDoneTriggerScript)
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
    CreateInboxRequest& withDeleteMessageTriggerScript(const Char* deleteMessageTriggerScript)
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
    CreateInboxRequest& withDeleteMessageDoneTriggerScript(const Char* deleteMessageDoneTriggerScript)
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
    CreateInboxRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateInboxRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateInboxRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateInboxRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INBOX_CONTROL_CREATEINBOXREQUEST_HPP_