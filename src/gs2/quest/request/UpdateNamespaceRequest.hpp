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

#ifndef GS2_QUEST_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_QUEST_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2QuestConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace quest
{

/**
 * クエストを分類するカテゴリーを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Quest
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** クエスト開始時 に実行されるスクリプト のGRN */
        optional<StringHolder> startQuestTriggerScriptId;
        /** クエスト開始完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> startQuestDoneTriggerScriptId;
        /** クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRN */
        optional<StringHolder> startQuestDoneTriggerQueueNamespaceId;
        /** クエストクリア時 に実行されるスクリプト のGRN */
        optional<StringHolder> completeQuestTriggerScriptId;
        /** クエストクリア完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> completeQuestDoneTriggerScriptId;
        /** クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRN */
        optional<StringHolder> completeQuestDoneTriggerQueueNamespaceId;
        /** クエスト失敗時 に実行されるスクリプト のGRN */
        optional<StringHolder> failedQuestTriggerScriptId;
        /** クエスト失敗完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> failedQuestDoneTriggerScriptId;
        /** クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRN */
        optional<StringHolder> failedQuestDoneTriggerQueueNamespaceId;
        /** 報酬付与処理をジョブとして追加するキューのネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            description(data.description),
            startQuestTriggerScriptId(data.startQuestTriggerScriptId),
            startQuestDoneTriggerScriptId(data.startQuestDoneTriggerScriptId),
            startQuestDoneTriggerQueueNamespaceId(data.startQuestDoneTriggerQueueNamespaceId),
            completeQuestTriggerScriptId(data.completeQuestTriggerScriptId),
            completeQuestDoneTriggerScriptId(data.completeQuestDoneTriggerScriptId),
            completeQuestDoneTriggerQueueNamespaceId(data.completeQuestDoneTriggerQueueNamespaceId),
            failedQuestTriggerScriptId(data.failedQuestTriggerScriptId),
            failedQuestDoneTriggerScriptId(data.failedQuestDoneTriggerScriptId),
            failedQuestDoneTriggerQueueNamespaceId(data.failedQuestDoneTriggerQueueNamespaceId),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            description(std::move(data.description)),
            startQuestTriggerScriptId(std::move(data.startQuestTriggerScriptId)),
            startQuestDoneTriggerScriptId(std::move(data.startQuestDoneTriggerScriptId)),
            startQuestDoneTriggerQueueNamespaceId(std::move(data.startQuestDoneTriggerQueueNamespaceId)),
            completeQuestTriggerScriptId(std::move(data.completeQuestTriggerScriptId)),
            completeQuestDoneTriggerScriptId(std::move(data.completeQuestDoneTriggerScriptId)),
            completeQuestDoneTriggerQueueNamespaceId(std::move(data.completeQuestDoneTriggerQueueNamespaceId)),
            failedQuestTriggerScriptId(std::move(data.failedQuestTriggerScriptId)),
            failedQuestDoneTriggerScriptId(std::move(data.failedQuestDoneTriggerScriptId)),
            failedQuestDoneTriggerQueueNamespaceId(std::move(data.failedQuestDoneTriggerQueueNamespaceId)),
            queueNamespaceId(std::move(data.queueNamespaceId)),
            keyId(std::move(data.keyId))
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
        Gs2Quest(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateNamespaceRequest(UpdateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Quest(std::move(obj)),
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
        Gs2Quest::operator=(updateNamespaceRequest);

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
        Gs2Quest::operator=(std::move(updateNamespaceRequest));

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
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    UpdateNamespaceRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * ネームスペースの説明を取得
     *
     * @return ネームスペースの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    UpdateNamespaceRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * クエスト開始時 に実行されるスクリプト のGRNを取得
     *
     * @return クエスト開始時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getStartQuestTriggerScriptId() const
    {
        return ensureData().startQuestTriggerScriptId;
    }

    /**
     * クエスト開始時 に実行されるスクリプト のGRNを設定
     *
     * @param startQuestTriggerScriptId クエスト開始時 に実行されるスクリプト のGRN
     */
    void setStartQuestTriggerScriptId(const Char* startQuestTriggerScriptId)
    {
        ensureData().startQuestTriggerScriptId.emplace(startQuestTriggerScriptId);
    }

    /**
     * クエスト開始時 に実行されるスクリプト のGRNを設定
     *
     * @param startQuestTriggerScriptId クエスト開始時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withStartQuestTriggerScriptId(const Char* startQuestTriggerScriptId)
    {
        ensureData().startQuestTriggerScriptId.emplace(startQuestTriggerScriptId);
        return *this;
    }

    /**
     * クエスト開始完了時 に実行されるスクリプト のGRNを取得
     *
     * @return クエスト開始完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getStartQuestDoneTriggerScriptId() const
    {
        return ensureData().startQuestDoneTriggerScriptId;
    }

    /**
     * クエスト開始完了時 に実行されるスクリプト のGRNを設定
     *
     * @param startQuestDoneTriggerScriptId クエスト開始完了時 に実行されるスクリプト のGRN
     */
    void setStartQuestDoneTriggerScriptId(const Char* startQuestDoneTriggerScriptId)
    {
        ensureData().startQuestDoneTriggerScriptId.emplace(startQuestDoneTriggerScriptId);
    }

    /**
     * クエスト開始完了時 に実行されるスクリプト のGRNを設定
     *
     * @param startQuestDoneTriggerScriptId クエスト開始完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withStartQuestDoneTriggerScriptId(const Char* startQuestDoneTriggerScriptId)
    {
        ensureData().startQuestDoneTriggerScriptId.emplace(startQuestDoneTriggerScriptId);
        return *this;
    }

    /**
     * クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRNを取得
     *
     * @return クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    const optional<StringHolder>& getStartQuestDoneTriggerQueueNamespaceId() const
    {
        return ensureData().startQuestDoneTriggerQueueNamespaceId;
    }

    /**
     * クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param startQuestDoneTriggerQueueNamespaceId クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    void setStartQuestDoneTriggerQueueNamespaceId(const Char* startQuestDoneTriggerQueueNamespaceId)
    {
        ensureData().startQuestDoneTriggerQueueNamespaceId.emplace(startQuestDoneTriggerQueueNamespaceId);
    }

    /**
     * クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param startQuestDoneTriggerQueueNamespaceId クエスト開始完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    UpdateNamespaceRequest& withStartQuestDoneTriggerQueueNamespaceId(const Char* startQuestDoneTriggerQueueNamespaceId)
    {
        ensureData().startQuestDoneTriggerQueueNamespaceId.emplace(startQuestDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * クエストクリア時 に実行されるスクリプト のGRNを取得
     *
     * @return クエストクリア時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCompleteQuestTriggerScriptId() const
    {
        return ensureData().completeQuestTriggerScriptId;
    }

    /**
     * クエストクリア時 に実行されるスクリプト のGRNを設定
     *
     * @param completeQuestTriggerScriptId クエストクリア時 に実行されるスクリプト のGRN
     */
    void setCompleteQuestTriggerScriptId(const Char* completeQuestTriggerScriptId)
    {
        ensureData().completeQuestTriggerScriptId.emplace(completeQuestTriggerScriptId);
    }

    /**
     * クエストクリア時 に実行されるスクリプト のGRNを設定
     *
     * @param completeQuestTriggerScriptId クエストクリア時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCompleteQuestTriggerScriptId(const Char* completeQuestTriggerScriptId)
    {
        ensureData().completeQuestTriggerScriptId.emplace(completeQuestTriggerScriptId);
        return *this;
    }

    /**
     * クエストクリア完了時 に実行されるスクリプト のGRNを取得
     *
     * @return クエストクリア完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCompleteQuestDoneTriggerScriptId() const
    {
        return ensureData().completeQuestDoneTriggerScriptId;
    }

    /**
     * クエストクリア完了時 に実行されるスクリプト のGRNを設定
     *
     * @param completeQuestDoneTriggerScriptId クエストクリア完了時 に実行されるスクリプト のGRN
     */
    void setCompleteQuestDoneTriggerScriptId(const Char* completeQuestDoneTriggerScriptId)
    {
        ensureData().completeQuestDoneTriggerScriptId.emplace(completeQuestDoneTriggerScriptId);
    }

    /**
     * クエストクリア完了時 に実行されるスクリプト のGRNを設定
     *
     * @param completeQuestDoneTriggerScriptId クエストクリア完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCompleteQuestDoneTriggerScriptId(const Char* completeQuestDoneTriggerScriptId)
    {
        ensureData().completeQuestDoneTriggerScriptId.emplace(completeQuestDoneTriggerScriptId);
        return *this;
    }

    /**
     * クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRNを取得
     *
     * @return クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    const optional<StringHolder>& getCompleteQuestDoneTriggerQueueNamespaceId() const
    {
        return ensureData().completeQuestDoneTriggerQueueNamespaceId;
    }

    /**
     * クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param completeQuestDoneTriggerQueueNamespaceId クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    void setCompleteQuestDoneTriggerQueueNamespaceId(const Char* completeQuestDoneTriggerQueueNamespaceId)
    {
        ensureData().completeQuestDoneTriggerQueueNamespaceId.emplace(completeQuestDoneTriggerQueueNamespaceId);
    }

    /**
     * クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param completeQuestDoneTriggerQueueNamespaceId クエストクリア完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    UpdateNamespaceRequest& withCompleteQuestDoneTriggerQueueNamespaceId(const Char* completeQuestDoneTriggerQueueNamespaceId)
    {
        ensureData().completeQuestDoneTriggerQueueNamespaceId.emplace(completeQuestDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * クエスト失敗時 に実行されるスクリプト のGRNを取得
     *
     * @return クエスト失敗時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getFailedQuestTriggerScriptId() const
    {
        return ensureData().failedQuestTriggerScriptId;
    }

    /**
     * クエスト失敗時 に実行されるスクリプト のGRNを設定
     *
     * @param failedQuestTriggerScriptId クエスト失敗時 に実行されるスクリプト のGRN
     */
    void setFailedQuestTriggerScriptId(const Char* failedQuestTriggerScriptId)
    {
        ensureData().failedQuestTriggerScriptId.emplace(failedQuestTriggerScriptId);
    }

    /**
     * クエスト失敗時 に実行されるスクリプト のGRNを設定
     *
     * @param failedQuestTriggerScriptId クエスト失敗時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withFailedQuestTriggerScriptId(const Char* failedQuestTriggerScriptId)
    {
        ensureData().failedQuestTriggerScriptId.emplace(failedQuestTriggerScriptId);
        return *this;
    }

    /**
     * クエスト失敗完了時 に実行されるスクリプト のGRNを取得
     *
     * @return クエスト失敗完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getFailedQuestDoneTriggerScriptId() const
    {
        return ensureData().failedQuestDoneTriggerScriptId;
    }

    /**
     * クエスト失敗完了時 に実行されるスクリプト のGRNを設定
     *
     * @param failedQuestDoneTriggerScriptId クエスト失敗完了時 に実行されるスクリプト のGRN
     */
    void setFailedQuestDoneTriggerScriptId(const Char* failedQuestDoneTriggerScriptId)
    {
        ensureData().failedQuestDoneTriggerScriptId.emplace(failedQuestDoneTriggerScriptId);
    }

    /**
     * クエスト失敗完了時 に実行されるスクリプト のGRNを設定
     *
     * @param failedQuestDoneTriggerScriptId クエスト失敗完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withFailedQuestDoneTriggerScriptId(const Char* failedQuestDoneTriggerScriptId)
    {
        ensureData().failedQuestDoneTriggerScriptId.emplace(failedQuestDoneTriggerScriptId);
        return *this;
    }

    /**
     * クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRNを取得
     *
     * @return クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    const optional<StringHolder>& getFailedQuestDoneTriggerQueueNamespaceId() const
    {
        return ensureData().failedQuestDoneTriggerQueueNamespaceId;
    }

    /**
     * クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param failedQuestDoneTriggerQueueNamespaceId クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    void setFailedQuestDoneTriggerQueueNamespaceId(const Char* failedQuestDoneTriggerQueueNamespaceId)
    {
        ensureData().failedQuestDoneTriggerQueueNamespaceId.emplace(failedQuestDoneTriggerQueueNamespaceId);
    }

    /**
     * クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRNを設定
     *
     * @param failedQuestDoneTriggerQueueNamespaceId クエスト失敗完了時 に通知するジョブを追加するキューのネームスペース のGRN
     */
    UpdateNamespaceRequest& withFailedQuestDoneTriggerQueueNamespaceId(const Char* failedQuestDoneTriggerQueueNamespaceId)
    {
        ensureData().failedQuestDoneTriggerQueueNamespaceId.emplace(failedQuestDoneTriggerQueueNamespaceId);
        return *this;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューのネームスペース のGRNを取得
     *
     * @return 報酬付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    const optional<StringHolder>& getQueueNamespaceId() const
    {
        return ensureData().queueNamespaceId;
    }

    /**
     * 報酬付与処理をジョブとして追加するキューのネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    void setQueueNamespaceId(const Char* queueNamespaceId)
    {
        ensureData().queueNamespaceId.emplace(queueNamespaceId);
    }

    /**
     * 報酬付与処理をジョブとして追加するキューのネームスペース のGRNを設定
     *
     * @param queueNamespaceId 報酬付与処理をジョブとして追加するキューのネームスペース のGRN
     */
    UpdateNamespaceRequest& withQueueNamespaceId(const Char* queueNamespaceId)
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
    UpdateNamespaceRequest& withKeyId(const Char* keyId)
    {
        ensureData().keyId.emplace(keyId);
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
};

} }

#endif //GS2_QUEST_CONTROL_UPDATENAMESPACEREQUEST_HPP_