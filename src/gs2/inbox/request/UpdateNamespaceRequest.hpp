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

#ifndef GS2_INBOX_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_INBOX_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InboxConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace inbox
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Inbox
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** プレゼントボックス名 */
        optional<StringHolder> namespaceName;
        /** 説明文 */
        optional<StringHolder> description;
        /** 開封したメッセージを自動的に削除するか */
        optional<Bool> isAutomaticDeletingEnabled;
        /** メッセージ受信したときに実行するスクリプト */
        optional<ScriptSetting> receiveMessageScript;
        /** メッセージ開封したときに実行するスクリプト */
        optional<ScriptSetting> readMessageScript;
        /** メッセージ削除したときに実行するスクリプト */
        optional<ScriptSetting> deleteMessageScript;
        /** 報酬付与処理をジョブとして追加するキューネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;
        /** メッセージを受信したときのプッシュ通知 */
        optional<NotificationSetting> receiveNotification;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            isAutomaticDeletingEnabled(data.isAutomaticDeletingEnabled),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId)
        {
            if (data.receiveMessageScript)
            {
                receiveMessageScript = data.receiveMessageScript->deepCopy();
            }
            if (data.readMessageScript)
            {
                readMessageScript = data.readMessageScript->deepCopy();
            }
            if (data.deleteMessageScript)
            {
                deleteMessageScript = data.deleteMessageScript->deepCopy();
            }
            if (data.receiveNotification)
            {
                receiveNotification = data.receiveNotification->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    UpdateNamespaceRequest() = default;
    UpdateNamespaceRequest(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest(UpdateNamespaceRequest&& updateNamespaceRequest) = default;
    ~UpdateNamespaceRequest() GS2_OVERRIDE = default;

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest) = default;
    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest) = default;

    UpdateNamespaceRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateNamespaceRequest);
    }

    const UpdateNamespaceRequest* operator->() const
    {
        return this;
    }

    UpdateNamespaceRequest* operator->()
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param namespaceName プレゼントボックス名
     */
    UpdateNamespaceRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateNamespaceRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    UpdateNamespaceRequest& withIsAutomaticDeletingEnabled(Bool isAutomaticDeletingEnabled)
    {
        ensureData().isAutomaticDeletingEnabled.emplace(isAutomaticDeletingEnabled);
        return *this;
    }

    /**
     * メッセージ受信したときに実行するスクリプトを取得
     *
     * @return メッセージ受信したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getReceiveMessageScript() const
    {
        return ensureData().receiveMessageScript;
    }

    /**
     * メッセージ受信したときに実行するスクリプトを設定
     *
     * @param receiveMessageScript メッセージ受信したときに実行するスクリプト
     */
    void setReceiveMessageScript(ScriptSetting receiveMessageScript)
    {
        ensureData().receiveMessageScript.emplace(std::move(receiveMessageScript));
    }

    /**
     * メッセージ受信したときに実行するスクリプトを設定
     *
     * @param receiveMessageScript メッセージ受信したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withReceiveMessageScript(ScriptSetting receiveMessageScript)
    {
        ensureData().receiveMessageScript.emplace(std::move(receiveMessageScript));
        return *this;
    }

    /**
     * メッセージ開封したときに実行するスクリプトを取得
     *
     * @return メッセージ開封したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getReadMessageScript() const
    {
        return ensureData().readMessageScript;
    }

    /**
     * メッセージ開封したときに実行するスクリプトを設定
     *
     * @param readMessageScript メッセージ開封したときに実行するスクリプト
     */
    void setReadMessageScript(ScriptSetting readMessageScript)
    {
        ensureData().readMessageScript.emplace(std::move(readMessageScript));
    }

    /**
     * メッセージ開封したときに実行するスクリプトを設定
     *
     * @param readMessageScript メッセージ開封したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withReadMessageScript(ScriptSetting readMessageScript)
    {
        ensureData().readMessageScript.emplace(std::move(readMessageScript));
        return *this;
    }

    /**
     * メッセージ削除したときに実行するスクリプトを取得
     *
     * @return メッセージ削除したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getDeleteMessageScript() const
    {
        return ensureData().deleteMessageScript;
    }

    /**
     * メッセージ削除したときに実行するスクリプトを設定
     *
     * @param deleteMessageScript メッセージ削除したときに実行するスクリプト
     */
    void setDeleteMessageScript(ScriptSetting deleteMessageScript)
    {
        ensureData().deleteMessageScript.emplace(std::move(deleteMessageScript));
    }

    /**
     * メッセージ削除したときに実行するスクリプトを設定
     *
     * @param deleteMessageScript メッセージ削除したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withDeleteMessageScript(ScriptSetting deleteMessageScript)
    {
        ensureData().deleteMessageScript.emplace(std::move(deleteMessageScript));
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
    void setQueueNamespaceId(StringHolder queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(std::move(queueNamespaceId));
    }

    /**
     * 報酬付与処理をジョブとして追加するキューネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューネームスペース のGRN
     */
    UpdateNamespaceRequest& withQueueNamespaceId(StringHolder queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(std::move(queueNamespaceId));
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
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 報酬付与処理のスタンプシートで使用する暗号鍵GRNを設定
     *
     * @param keyId 報酬付与処理のスタンプシートで使用する暗号鍵GRN
     */
    UpdateNamespaceRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
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
    void setReceiveNotification(NotificationSetting receiveNotification)
    {
        ensureData().receiveNotification.emplace(std::move(receiveNotification));
    }

    /**
     * メッセージを受信したときのプッシュ通知を設定
     *
     * @param receiveNotification メッセージを受信したときのプッシュ通知
     */
    UpdateNamespaceRequest& withReceiveNotification(NotificationSetting receiveNotification)
    {
        ensureData().receiveNotification.emplace(std::move(receiveNotification));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_INBOX_CONTROL_UPDATENAMESPACEREQUEST_HPP_