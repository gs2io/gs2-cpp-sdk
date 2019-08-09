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

#ifndef GS2_INBOX_CONTROL_CREATENAMESPACEREQUEST_HPP_
#define GS2_INBOX_CONTROL_CREATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InboxConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * ネームスペースを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateNamespaceRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** プレゼントボックス名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** 開封したメッセージを自動的に削除するか */
        optional<Bool> isAutomaticDeletingEnabled;
        /** メッセージ受信時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveMessageTriggerScriptId;
        /** メッセージ受信完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveMessageDoneTriggerScriptId;
        /** メッセージ受信完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> receiveMessageDoneTriggerNamespaceId;
        /** メッセージ開封時 に実行されるスクリプト のGRN */
        optional<StringHolder> readMessageTriggerScriptId;
        /** メッセージ開封完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> readMessageDoneTriggerScriptId;
        /** メッセージ開封完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> readMessageDoneTriggerNamespaceId;
        /** メッセージ削除時 に実行されるスクリプト のGRN */
        optional<StringHolder> deleteMessageTriggerScriptId;
        /** メッセージ削除完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> deleteMessageDoneTriggerScriptId;
        /** メッセージ削除完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> deleteMessageDoneTriggerNamespaceId;
        /** 報酬付与処理をジョブとして追加するキューネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;
        /** メッセージを受信したときのプッシュ通知 */
        optional<NotificationSetting> receiveNotification;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            isAutomaticDeletingEnabled(data.isAutomaticDeletingEnabled),
            receiveMessageTriggerScriptId(data.receiveMessageTriggerScriptId),
            receiveMessageDoneTriggerScriptId(data.receiveMessageDoneTriggerScriptId),
            receiveMessageDoneTriggerNamespaceId(data.receiveMessageDoneTriggerNamespaceId),
            readMessageTriggerScriptId(data.readMessageTriggerScriptId),
            readMessageDoneTriggerScriptId(data.readMessageDoneTriggerScriptId),
            readMessageDoneTriggerNamespaceId(data.readMessageDoneTriggerNamespaceId),
            deleteMessageTriggerScriptId(data.deleteMessageTriggerScriptId),
            deleteMessageDoneTriggerScriptId(data.deleteMessageDoneTriggerScriptId),
            deleteMessageDoneTriggerNamespaceId(data.deleteMessageDoneTriggerNamespaceId),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId),
            receiveNotification(data.receiveNotification)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            isAutomaticDeletingEnabled(std::move(data.isAutomaticDeletingEnabled)),
            receiveMessageTriggerScriptId(std::move(data.receiveMessageTriggerScriptId)),
            receiveMessageDoneTriggerScriptId(std::move(data.receiveMessageDoneTriggerScriptId)),
            receiveMessageDoneTriggerNamespaceId(std::move(data.receiveMessageDoneTriggerNamespaceId)),
            readMessageTriggerScriptId(std::move(data.readMessageTriggerScriptId)),
            readMessageDoneTriggerScriptId(std::move(data.readMessageDoneTriggerScriptId)),
            readMessageDoneTriggerNamespaceId(std::move(data.readMessageDoneTriggerNamespaceId)),
            deleteMessageTriggerScriptId(std::move(data.deleteMessageTriggerScriptId)),
            deleteMessageDoneTriggerScriptId(std::move(data.deleteMessageDoneTriggerScriptId)),
            deleteMessageDoneTriggerNamespaceId(std::move(data.deleteMessageDoneTriggerNamespaceId)),
            queueNamespaceId(std::move(data.queueNamespaceId)),
            keyId(std::move(data.keyId)),
            receiveNotification(std::move(data.receiveNotification))
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
    CreateNamespaceRequest() :
        m_pData(nullptr)
    {}

    CreateNamespaceRequest(const CreateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateNamespaceRequest(CreateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateNamespaceRequest& operator=(const CreateNamespaceRequest& createNamespaceRequest)
    {
        Gs2BasicRequest::operator=(createNamespaceRequest);
        Gs2Inbox::operator=(createNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createNamespaceRequest.m_pData);

        return *this;
    }

    CreateNamespaceRequest& operator=(CreateNamespaceRequest&& createNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(createNamespaceRequest));
        Gs2Inbox::operator=(std::move(createNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createNamespaceRequest.m_pData;
        createNamespaceRequest.m_pData = nullptr;

        return *this;
    }

    const CreateNamespaceRequest* operator->() const
    {
        return this;
    }

    CreateNamespaceRequest* operator->()
    {
        return this;
    }

    /**
     * プレゼントボックス名を取得
     *
     * @return プレゼントボックス名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param name プレゼントボックス名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param name プレゼントボックス名
     */
    CreateNamespaceRequest& withName(const Char* name)
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
    CreateNamespaceRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * 開封したメッセージを自動的に削除するかを取得
     *
     * @return 開封したメッセージを自動的に削除するか
     */
    const optional<Bool>& getIsAutomaticDeletingEnabled() const
    {
        return ensureData().isAutomaticDeletingEnabled;
    }

    /**
     * 開封したメッセージを自動的に削除するかを設定
     *
     * @param isAutomaticDeletingEnabled 開封したメッセージを自動的に削除するか
     */
    void setIsAutomaticDeletingEnabled(Bool isAutomaticDeletingEnabled)
    {
        ensureData().isAutomaticDeletingEnabled.emplace(isAutomaticDeletingEnabled);
    }

    /**
     * 開封したメッセージを自動的に削除するかを設定
     *
     * @param isAutomaticDeletingEnabled 開封したメッセージを自動的に削除するか
     */
    CreateNamespaceRequest& withIsAutomaticDeletingEnabled(Bool isAutomaticDeletingEnabled)
    {
        ensureData().isAutomaticDeletingEnabled.emplace(isAutomaticDeletingEnabled);
        return *this;
    }

    /**
     * メッセージ受信時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ受信時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveMessageTriggerScriptId() const
    {
        return ensureData().receiveMessageTriggerScriptId;
    }

    /**
     * メッセージ受信時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveMessageTriggerScriptId メッセージ受信時 に実行されるスクリプト のGRN
     */
    void setReceiveMessageTriggerScriptId(const Char* receiveMessageTriggerScriptId)
    {
        ensureData().receiveMessageTriggerScriptId.emplace(receiveMessageTriggerScriptId);
    }

    /**
     * メッセージ受信時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveMessageTriggerScriptId メッセージ受信時 に実行されるスクリプト のGRN
     */
    CreateNamespaceRequest& withReceiveMessageTriggerScriptId(const Char* receiveMessageTriggerScriptId)
    {
        ensureData().receiveMessageTriggerScriptId.emplace(receiveMessageTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ受信完了時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ受信完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveMessageDoneTriggerScriptId() const
    {
        return ensureData().receiveMessageDoneTriggerScriptId;
    }

    /**
     * メッセージ受信完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveMessageDoneTriggerScriptId メッセージ受信完了時 に実行されるスクリプト のGRN
     */
    void setReceiveMessageDoneTriggerScriptId(const Char* receiveMessageDoneTriggerScriptId)
    {
        ensureData().receiveMessageDoneTriggerScriptId.emplace(receiveMessageDoneTriggerScriptId);
    }

    /**
     * メッセージ受信完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveMessageDoneTriggerScriptId メッセージ受信完了時 に実行されるスクリプト のGRN
     */
    CreateNamespaceRequest& withReceiveMessageDoneTriggerScriptId(const Char* receiveMessageDoneTriggerScriptId)
    {
        ensureData().receiveMessageDoneTriggerScriptId.emplace(receiveMessageDoneTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ受信完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return メッセージ受信完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getReceiveMessageDoneTriggerNamespaceId() const
    {
        return ensureData().receiveMessageDoneTriggerNamespaceId;
    }

    /**
     * メッセージ受信完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveMessageDoneTriggerNamespaceId メッセージ受信完了時 にジョブが登録されるネームスペース のGRN
     */
    void setReceiveMessageDoneTriggerNamespaceId(const Char* receiveMessageDoneTriggerNamespaceId)
    {
        ensureData().receiveMessageDoneTriggerNamespaceId.emplace(receiveMessageDoneTriggerNamespaceId);
    }

    /**
     * メッセージ受信完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveMessageDoneTriggerNamespaceId メッセージ受信完了時 にジョブが登録されるネームスペース のGRN
     */
    CreateNamespaceRequest& withReceiveMessageDoneTriggerNamespaceId(const Char* receiveMessageDoneTriggerNamespaceId)
    {
        ensureData().receiveMessageDoneTriggerNamespaceId.emplace(receiveMessageDoneTriggerNamespaceId);
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
    CreateNamespaceRequest& withReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
    {
        ensureData().readMessageTriggerScriptId.emplace(readMessageTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ開封完了時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ開封完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReadMessageDoneTriggerScriptId() const
    {
        return ensureData().readMessageDoneTriggerScriptId;
    }

    /**
     * メッセージ開封完了時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageDoneTriggerScriptId メッセージ開封完了時 に実行されるスクリプト のGRN
     */
    void setReadMessageDoneTriggerScriptId(const Char* readMessageDoneTriggerScriptId)
    {
        ensureData().readMessageDoneTriggerScriptId.emplace(readMessageDoneTriggerScriptId);
    }

    /**
     * メッセージ開封完了時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageDoneTriggerScriptId メッセージ開封完了時 に実行されるスクリプト のGRN
     */
    CreateNamespaceRequest& withReadMessageDoneTriggerScriptId(const Char* readMessageDoneTriggerScriptId)
    {
        ensureData().readMessageDoneTriggerScriptId.emplace(readMessageDoneTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ開封完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return メッセージ開封完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getReadMessageDoneTriggerNamespaceId() const
    {
        return ensureData().readMessageDoneTriggerNamespaceId;
    }

    /**
     * メッセージ開封完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param readMessageDoneTriggerNamespaceId メッセージ開封完了時 にジョブが登録されるネームスペース のGRN
     */
    void setReadMessageDoneTriggerNamespaceId(const Char* readMessageDoneTriggerNamespaceId)
    {
        ensureData().readMessageDoneTriggerNamespaceId.emplace(readMessageDoneTriggerNamespaceId);
    }

    /**
     * メッセージ開封完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param readMessageDoneTriggerNamespaceId メッセージ開封完了時 にジョブが登録されるネームスペース のGRN
     */
    CreateNamespaceRequest& withReadMessageDoneTriggerNamespaceId(const Char* readMessageDoneTriggerNamespaceId)
    {
        ensureData().readMessageDoneTriggerNamespaceId.emplace(readMessageDoneTriggerNamespaceId);
        return *this;
    }

    /**
     * メッセージ削除時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ削除時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getDeleteMessageTriggerScriptId() const
    {
        return ensureData().deleteMessageTriggerScriptId;
    }

    /**
     * メッセージ削除時 に実行されるスクリプト のGRNを設定
     *
     * @param deleteMessageTriggerScriptId メッセージ削除時 に実行されるスクリプト のGRN
     */
    void setDeleteMessageTriggerScriptId(const Char* deleteMessageTriggerScriptId)
    {
        ensureData().deleteMessageTriggerScriptId.emplace(deleteMessageTriggerScriptId);
    }

    /**
     * メッセージ削除時 に実行されるスクリプト のGRNを設定
     *
     * @param deleteMessageTriggerScriptId メッセージ削除時 に実行されるスクリプト のGRN
     */
    CreateNamespaceRequest& withDeleteMessageTriggerScriptId(const Char* deleteMessageTriggerScriptId)
    {
        ensureData().deleteMessageTriggerScriptId.emplace(deleteMessageTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ削除完了時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ削除完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getDeleteMessageDoneTriggerScriptId() const
    {
        return ensureData().deleteMessageDoneTriggerScriptId;
    }

    /**
     * メッセージ削除完了時 に実行されるスクリプト のGRNを設定
     *
     * @param deleteMessageDoneTriggerScriptId メッセージ削除完了時 に実行されるスクリプト のGRN
     */
    void setDeleteMessageDoneTriggerScriptId(const Char* deleteMessageDoneTriggerScriptId)
    {
        ensureData().deleteMessageDoneTriggerScriptId.emplace(deleteMessageDoneTriggerScriptId);
    }

    /**
     * メッセージ削除完了時 に実行されるスクリプト のGRNを設定
     *
     * @param deleteMessageDoneTriggerScriptId メッセージ削除完了時 に実行されるスクリプト のGRN
     */
    CreateNamespaceRequest& withDeleteMessageDoneTriggerScriptId(const Char* deleteMessageDoneTriggerScriptId)
    {
        ensureData().deleteMessageDoneTriggerScriptId.emplace(deleteMessageDoneTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ削除完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return メッセージ削除完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getDeleteMessageDoneTriggerNamespaceId() const
    {
        return ensureData().deleteMessageDoneTriggerNamespaceId;
    }

    /**
     * メッセージ削除完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param deleteMessageDoneTriggerNamespaceId メッセージ削除完了時 にジョブが登録されるネームスペース のGRN
     */
    void setDeleteMessageDoneTriggerNamespaceId(const Char* deleteMessageDoneTriggerNamespaceId)
    {
        ensureData().deleteMessageDoneTriggerNamespaceId.emplace(deleteMessageDoneTriggerNamespaceId);
    }

    /**
     * メッセージ削除完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param deleteMessageDoneTriggerNamespaceId メッセージ削除完了時 にジョブが登録されるネームスペース のGRN
     */
    CreateNamespaceRequest& withDeleteMessageDoneTriggerNamespaceId(const Char* deleteMessageDoneTriggerNamespaceId)
    {
        ensureData().deleteMessageDoneTriggerNamespaceId.emplace(deleteMessageDoneTriggerNamespaceId);
        return *this;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを取得
     *
     * @return 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    const optional<StringHolder>& getQueueNamespaceId() const
    {
        return ensureData().queueNamespaceId;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    void setQueueNamespaceId(const Char* queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(queueNamespaceId);
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    CreateNamespaceRequest& withQueueNamespaceId(const Char* queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(queueNamespaceId);
        return *this;
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを取得
     *
     * @return 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    void setKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    CreateNamespaceRequest& withKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
        return *this;
    }

    /**
     * メッセージを受信したときのプッシュ通知を取得
     *
     * @return メッセージを受信したときのプッシュ通知
     */
    const optional<NotificationSetting>& getReceiveNotification() const
    {
        return ensureData().receiveNotification;
    }

    /**
     * メッセージを受信したときのプッシュ通知を設定
     *
     * @param receiveNotification メッセージを受信したときのプッシュ通知
     */
    void setReceiveNotification(const NotificationSetting& receiveNotification)
    {
        ensureData().receiveNotification.emplace(receiveNotification);
    }

    /**
     * メッセージを受信したときのプッシュ通知を設定
     *
     * @param receiveNotification メッセージを受信したときのプッシュ通知
     */
    CreateNamespaceRequest& withReceiveNotification(const NotificationSetting& receiveNotification)
    {
        ensureData().receiveNotification.emplace(receiveNotification);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateNamespaceRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_INBOX_CONTROL_CREATENAMESPACEREQUEST_HPP_