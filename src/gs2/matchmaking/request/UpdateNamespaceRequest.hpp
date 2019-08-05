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

#ifndef GS2_MATCHMAKING_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MatchmakingConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace matchmaking
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ネームスペースの説明 */
        optional<StringHolder> description;
        /** ギャザリング新規作成時のアクション */
        optional<StringHolder> createGatheringTriggerType;
        /** ギャザリング新規作成時 にルームを作成するネームスペース のGRN */
        optional<StringHolder> createGatheringTriggerRealtimeNamespaceId;
        /** ギャザリング新規作成時 に実行されるスクリプト のGRN */
        optional<StringHolder> createGatheringTriggerScriptId;
        /** マッチメイキング完了時のアクション */
        optional<StringHolder> completeMatchmakingTriggerType;
        /** マッチメイキング完了時 にルームを作成するネームスペース のGRN */
        optional<StringHolder> completeMatchmakingTriggerRealtimeNamespaceId;
        /** マッチメイキング完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> completeMatchmakingTriggerScriptId;
        /** ギャザリングに新規プレイヤーが参加したときのプッシュ通知 */
        optional<NotificationSetting> joinNotification;
        /** ギャザリングからプレイヤーが離脱したときのプッシュ通知 */
        optional<NotificationSetting> leaveNotification;
        /** マッチメイキングが完了したときのプッシュ通知 */
        optional<NotificationSetting> completeNotification;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            description(data.description),
            createGatheringTriggerType(data.createGatheringTriggerType),
            createGatheringTriggerRealtimeNamespaceId(data.createGatheringTriggerRealtimeNamespaceId),
            createGatheringTriggerScriptId(data.createGatheringTriggerScriptId),
            completeMatchmakingTriggerType(data.completeMatchmakingTriggerType),
            completeMatchmakingTriggerRealtimeNamespaceId(data.completeMatchmakingTriggerRealtimeNamespaceId),
            completeMatchmakingTriggerScriptId(data.completeMatchmakingTriggerScriptId),
            joinNotification(data.joinNotification),
            leaveNotification(data.leaveNotification),
            completeNotification(data.completeNotification)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            description(std::move(data.description)),
            createGatheringTriggerType(std::move(data.createGatheringTriggerType)),
            createGatheringTriggerRealtimeNamespaceId(std::move(data.createGatheringTriggerRealtimeNamespaceId)),
            createGatheringTriggerScriptId(std::move(data.createGatheringTriggerScriptId)),
            completeMatchmakingTriggerType(std::move(data.completeMatchmakingTriggerType)),
            completeMatchmakingTriggerRealtimeNamespaceId(std::move(data.completeMatchmakingTriggerRealtimeNamespaceId)),
            completeMatchmakingTriggerScriptId(std::move(data.completeMatchmakingTriggerScriptId)),
            joinNotification(std::move(data.joinNotification)),
            leaveNotification(std::move(data.leaveNotification)),
            completeNotification(std::move(data.completeNotification))
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
        Gs2Matchmaking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateNamespaceRequest(UpdateNamespaceRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Matchmaking(std::move(obj)),
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
        Gs2Matchmaking::operator=(updateNamespaceRequest);

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
        Gs2Matchmaking::operator=(std::move(updateNamespaceRequest));

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
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
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
     * ギャザリング新規作成時のアクションを取得
     *
     * @return ギャザリング新規作成時のアクション
     */
    const optional<StringHolder>& getCreateGatheringTriggerType() const
    {
        return ensureData().createGatheringTriggerType;
    }

    /**
     * ギャザリング新規作成時のアクションを設定
     *
     * @param createGatheringTriggerType ギャザリング新規作成時のアクション
     */
    void setCreateGatheringTriggerType(const Char* createGatheringTriggerType)
    {
        ensureData().createGatheringTriggerType.emplace(createGatheringTriggerType);
    }

    /**
     * ギャザリング新規作成時のアクションを設定
     *
     * @param createGatheringTriggerType ギャザリング新規作成時のアクション
     */
    UpdateNamespaceRequest& withCreateGatheringTriggerType(const Char* createGatheringTriggerType)
    {
        ensureData().createGatheringTriggerType.emplace(createGatheringTriggerType);
        return *this;
    }

    /**
     * ギャザリング新規作成時 にルームを作成するネームスペース のGRNを取得
     *
     * @return ギャザリング新規作成時 にルームを作成するネームスペース のGRN
     */
    const optional<StringHolder>& getCreateGatheringTriggerRealtimeNamespaceId() const
    {
        return ensureData().createGatheringTriggerRealtimeNamespaceId;
    }

    /**
     * ギャザリング新規作成時 にルームを作成するネームスペース のGRNを設定
     *
     * @param createGatheringTriggerRealtimeNamespaceId ギャザリング新規作成時 にルームを作成するネームスペース のGRN
     */
    void setCreateGatheringTriggerRealtimeNamespaceId(const Char* createGatheringTriggerRealtimeNamespaceId)
    {
        ensureData().createGatheringTriggerRealtimeNamespaceId.emplace(createGatheringTriggerRealtimeNamespaceId);
    }

    /**
     * ギャザリング新規作成時 にルームを作成するネームスペース のGRNを設定
     *
     * @param createGatheringTriggerRealtimeNamespaceId ギャザリング新規作成時 にルームを作成するネームスペース のGRN
     */
    UpdateNamespaceRequest& withCreateGatheringTriggerRealtimeNamespaceId(const Char* createGatheringTriggerRealtimeNamespaceId)
    {
        ensureData().createGatheringTriggerRealtimeNamespaceId.emplace(createGatheringTriggerRealtimeNamespaceId);
        return *this;
    }

    /**
     * ギャザリング新規作成時 に実行されるスクリプト のGRNを取得
     *
     * @return ギャザリング新規作成時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCreateGatheringTriggerScriptId() const
    {
        return ensureData().createGatheringTriggerScriptId;
    }

    /**
     * ギャザリング新規作成時 に実行されるスクリプト のGRNを設定
     *
     * @param createGatheringTriggerScriptId ギャザリング新規作成時 に実行されるスクリプト のGRN
     */
    void setCreateGatheringTriggerScriptId(const Char* createGatheringTriggerScriptId)
    {
        ensureData().createGatheringTriggerScriptId.emplace(createGatheringTriggerScriptId);
    }

    /**
     * ギャザリング新規作成時 に実行されるスクリプト のGRNを設定
     *
     * @param createGatheringTriggerScriptId ギャザリング新規作成時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCreateGatheringTriggerScriptId(const Char* createGatheringTriggerScriptId)
    {
        ensureData().createGatheringTriggerScriptId.emplace(createGatheringTriggerScriptId);
        return *this;
    }

    /**
     * マッチメイキング完了時のアクションを取得
     *
     * @return マッチメイキング完了時のアクション
     */
    const optional<StringHolder>& getCompleteMatchmakingTriggerType() const
    {
        return ensureData().completeMatchmakingTriggerType;
    }

    /**
     * マッチメイキング完了時のアクションを設定
     *
     * @param completeMatchmakingTriggerType マッチメイキング完了時のアクション
     */
    void setCompleteMatchmakingTriggerType(const Char* completeMatchmakingTriggerType)
    {
        ensureData().completeMatchmakingTriggerType.emplace(completeMatchmakingTriggerType);
    }

    /**
     * マッチメイキング完了時のアクションを設定
     *
     * @param completeMatchmakingTriggerType マッチメイキング完了時のアクション
     */
    UpdateNamespaceRequest& withCompleteMatchmakingTriggerType(const Char* completeMatchmakingTriggerType)
    {
        ensureData().completeMatchmakingTriggerType.emplace(completeMatchmakingTriggerType);
        return *this;
    }

    /**
     * マッチメイキング完了時 にルームを作成するネームスペース のGRNを取得
     *
     * @return マッチメイキング完了時 にルームを作成するネームスペース のGRN
     */
    const optional<StringHolder>& getCompleteMatchmakingTriggerRealtimeNamespaceId() const
    {
        return ensureData().completeMatchmakingTriggerRealtimeNamespaceId;
    }

    /**
     * マッチメイキング完了時 にルームを作成するネームスペース のGRNを設定
     *
     * @param completeMatchmakingTriggerRealtimeNamespaceId マッチメイキング完了時 にルームを作成するネームスペース のGRN
     */
    void setCompleteMatchmakingTriggerRealtimeNamespaceId(const Char* completeMatchmakingTriggerRealtimeNamespaceId)
    {
        ensureData().completeMatchmakingTriggerRealtimeNamespaceId.emplace(completeMatchmakingTriggerRealtimeNamespaceId);
    }

    /**
     * マッチメイキング完了時 にルームを作成するネームスペース のGRNを設定
     *
     * @param completeMatchmakingTriggerRealtimeNamespaceId マッチメイキング完了時 にルームを作成するネームスペース のGRN
     */
    UpdateNamespaceRequest& withCompleteMatchmakingTriggerRealtimeNamespaceId(const Char* completeMatchmakingTriggerRealtimeNamespaceId)
    {
        ensureData().completeMatchmakingTriggerRealtimeNamespaceId.emplace(completeMatchmakingTriggerRealtimeNamespaceId);
        return *this;
    }

    /**
     * マッチメイキング完了時 に実行されるスクリプト のGRNを取得
     *
     * @return マッチメイキング完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCompleteMatchmakingTriggerScriptId() const
    {
        return ensureData().completeMatchmakingTriggerScriptId;
    }

    /**
     * マッチメイキング完了時 に実行されるスクリプト のGRNを設定
     *
     * @param completeMatchmakingTriggerScriptId マッチメイキング完了時 に実行されるスクリプト のGRN
     */
    void setCompleteMatchmakingTriggerScriptId(const Char* completeMatchmakingTriggerScriptId)
    {
        ensureData().completeMatchmakingTriggerScriptId.emplace(completeMatchmakingTriggerScriptId);
    }

    /**
     * マッチメイキング完了時 に実行されるスクリプト のGRNを設定
     *
     * @param completeMatchmakingTriggerScriptId マッチメイキング完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCompleteMatchmakingTriggerScriptId(const Char* completeMatchmakingTriggerScriptId)
    {
        ensureData().completeMatchmakingTriggerScriptId.emplace(completeMatchmakingTriggerScriptId);
        return *this;
    }

    /**
     * ギャザリングに新規プレイヤーが参加したときのプッシュ通知を取得
     *
     * @return ギャザリングに新規プレイヤーが参加したときのプッシュ通知
     */
    const optional<NotificationSetting>& getJoinNotification() const
    {
        return ensureData().joinNotification;
    }

    /**
     * ギャザリングに新規プレイヤーが参加したときのプッシュ通知を設定
     *
     * @param joinNotification ギャザリングに新規プレイヤーが参加したときのプッシュ通知
     */
    void setJoinNotification(const NotificationSetting& joinNotification)
    {
        ensureData().joinNotification.emplace(joinNotification);
    }

    /**
     * ギャザリングに新規プレイヤーが参加したときのプッシュ通知を設定
     *
     * @param joinNotification ギャザリングに新規プレイヤーが参加したときのプッシュ通知
     */
    UpdateNamespaceRequest& withJoinNotification(const NotificationSetting& joinNotification)
    {
        ensureData().joinNotification.emplace(joinNotification);
        return *this;
    }

    /**
     * ギャザリングからプレイヤーが離脱したときのプッシュ通知を取得
     *
     * @return ギャザリングからプレイヤーが離脱したときのプッシュ通知
     */
    const optional<NotificationSetting>& getLeaveNotification() const
    {
        return ensureData().leaveNotification;
    }

    /**
     * ギャザリングからプレイヤーが離脱したときのプッシュ通知を設定
     *
     * @param leaveNotification ギャザリングからプレイヤーが離脱したときのプッシュ通知
     */
    void setLeaveNotification(const NotificationSetting& leaveNotification)
    {
        ensureData().leaveNotification.emplace(leaveNotification);
    }

    /**
     * ギャザリングからプレイヤーが離脱したときのプッシュ通知を設定
     *
     * @param leaveNotification ギャザリングからプレイヤーが離脱したときのプッシュ通知
     */
    UpdateNamespaceRequest& withLeaveNotification(const NotificationSetting& leaveNotification)
    {
        ensureData().leaveNotification.emplace(leaveNotification);
        return *this;
    }

    /**
     * マッチメイキングが完了したときのプッシュ通知を取得
     *
     * @return マッチメイキングが完了したときのプッシュ通知
     */
    const optional<NotificationSetting>& getCompleteNotification() const
    {
        return ensureData().completeNotification;
    }

    /**
     * マッチメイキングが完了したときのプッシュ通知を設定
     *
     * @param completeNotification マッチメイキングが完了したときのプッシュ通知
     */
    void setCompleteNotification(const NotificationSetting& completeNotification)
    {
        ensureData().completeNotification.emplace(completeNotification);
    }

    /**
     * マッチメイキングが完了したときのプッシュ通知を設定
     *
     * @param completeNotification マッチメイキングが完了したときのプッシュ通知
     */
    UpdateNamespaceRequest& withCompleteNotification(const NotificationSetting& completeNotification)
    {
        ensureData().completeNotification.emplace(completeNotification);
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

#endif //GS2_MATCHMAKING_CONTROL_UPDATENAMESPACEREQUEST_HPP_