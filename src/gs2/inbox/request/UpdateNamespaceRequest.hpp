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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2InboxConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
    {
    public:
        /** プレゼントボックス名 */
        optional<StringHolder> namespaceName;
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
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
            deleteMessageDoneTriggerNamespaceId(data.deleteMessageDoneTriggerNamespaceId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
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
            deleteMessageDoneTriggerNamespaceId(std::move(data.deleteMessageDoneTriggerNamespaceId))
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
    UpdateNamespaceRequest() :
        m_pData(nullptr)
    {}

    UpdateNamespaceRequest(const UpdateNamespaceRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Inbox(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateNamespaceRequest(UpdateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Inbox(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateNamespaceRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateNamespaceRequest& operator=(const UpdateNamespaceRequest& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(updateNamespaceRequest);
        Gs2Inbox::operator=(updateNamespaceRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateNamespaceRequest.m_pData);

        return *this;
    }

    UpdateNamespaceRequest& operator=(UpdateNamespaceRequest&& updateNamespaceRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateNamespaceRequest));
        Gs2Inbox::operator=(std::move(updateNamespaceRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateNamespaceRequest.m_pData;
        updateNamespaceRequest.m_pData = nullptr;

        return *this;
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * プレゼントボックス名を設定
     *
     * @param namespaceName プレゼントボックス名
     */
    UpdateNamespaceRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    UpdateNamespaceRequest& withDescription(const Char* description)
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
    UpdateNamespaceRequest& withIsAutomaticDeletingEnabled(Bool isAutomaticDeletingEnabled)
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
    UpdateNamespaceRequest& withReceiveMessageTriggerScriptId(const Char* receiveMessageTriggerScriptId)
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
    UpdateNamespaceRequest& withReceiveMessageDoneTriggerScriptId(const Char* receiveMessageDoneTriggerScriptId)
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
    UpdateNamespaceRequest& withReceiveMessageDoneTriggerNamespaceId(const Char* receiveMessageDoneTriggerNamespaceId)
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
    UpdateNamespaceRequest& withReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
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
    UpdateNamespaceRequest& withReadMessageDoneTriggerScriptId(const Char* readMessageDoneTriggerScriptId)
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
    UpdateNamespaceRequest& withReadMessageDoneTriggerNamespaceId(const Char* readMessageDoneTriggerNamespaceId)
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
    UpdateNamespaceRequest& withDeleteMessageTriggerScriptId(const Char* deleteMessageTriggerScriptId)
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
    UpdateNamespaceRequest& withDeleteMessageDoneTriggerScriptId(const Char* deleteMessageDoneTriggerScriptId)
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
    UpdateNamespaceRequest& withDeleteMessageDoneTriggerNamespaceId(const Char* deleteMessageDoneTriggerNamespaceId)
    {
        ensureData().deleteMessageDoneTriggerNamespaceId.emplace(deleteMessageDoneTriggerNamespaceId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateNamespaceRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateNamespaceRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateNamespaceRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateNamespaceRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_INBOX_CONTROL_UPDATENAMESPACEREQUEST_HPP_