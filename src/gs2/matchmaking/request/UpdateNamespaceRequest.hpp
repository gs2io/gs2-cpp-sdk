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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/matchmaking/Gs2MatchmakingConst.hpp>
#include <gs2/matchmaking/model/model.hpp>
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
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
        /** ログの出力設定 */
        optional<LogSetting> logSetting;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            createGatheringTriggerType(data.createGatheringTriggerType),
            createGatheringTriggerRealtimeNamespaceId(data.createGatheringTriggerRealtimeNamespaceId),
            createGatheringTriggerScriptId(data.createGatheringTriggerScriptId),
            completeMatchmakingTriggerType(data.completeMatchmakingTriggerType),
            completeMatchmakingTriggerRealtimeNamespaceId(data.completeMatchmakingTriggerRealtimeNamespaceId),
            completeMatchmakingTriggerScriptId(data.completeMatchmakingTriggerScriptId)
        {
            if (data.joinNotification)
            {
                joinNotification = data.joinNotification->deepCopy();
            }
            if (data.leaveNotification)
            {
                leaveNotification = data.leaveNotification->deepCopy();
            }
            if (data.completeNotification)
            {
                completeNotification = data.completeNotification->deepCopy();
            }
            if (data.logSetting)
            {
                logSetting = data.logSetting->deepCopy();
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateNamespaceRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ネームスペースの説明を設定
     *
     * @param description ネームスペースの説明
     */
    UpdateNamespaceRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setCreateGatheringTriggerType(StringHolder createGatheringTriggerType)
    {
        ensureData().createGatheringTriggerType.emplace(std::move(createGatheringTriggerType));
    }

    /**
     * ギャザリング新規作成時のアクションを設定
     *
     * @param createGatheringTriggerType ギャザリング新規作成時のアクション
     */
    UpdateNamespaceRequest& withCreateGatheringTriggerType(StringHolder createGatheringTriggerType)
    {
        ensureData().createGatheringTriggerType.emplace(std::move(createGatheringTriggerType));
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
    void setCreateGatheringTriggerRealtimeNamespaceId(StringHolder createGatheringTriggerRealtimeNamespaceId)
    {
        ensureData().createGatheringTriggerRealtimeNamespaceId.emplace(std::move(createGatheringTriggerRealtimeNamespaceId));
    }

    /**
     * ギャザリング新規作成時 にルームを作成するネームスペース のGRNを設定
     *
     * @param createGatheringTriggerRealtimeNamespaceId ギャザリング新規作成時 にルームを作成するネームスペース のGRN
     */
    UpdateNamespaceRequest& withCreateGatheringTriggerRealtimeNamespaceId(StringHolder createGatheringTriggerRealtimeNamespaceId)
    {
        ensureData().createGatheringTriggerRealtimeNamespaceId.emplace(std::move(createGatheringTriggerRealtimeNamespaceId));
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
    void setCreateGatheringTriggerScriptId(StringHolder createGatheringTriggerScriptId)
    {
        ensureData().createGatheringTriggerScriptId.emplace(std::move(createGatheringTriggerScriptId));
    }

    /**
     * ギャザリング新規作成時 に実行されるスクリプト のGRNを設定
     *
     * @param createGatheringTriggerScriptId ギャザリング新規作成時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCreateGatheringTriggerScriptId(StringHolder createGatheringTriggerScriptId)
    {
        ensureData().createGatheringTriggerScriptId.emplace(std::move(createGatheringTriggerScriptId));
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
    void setCompleteMatchmakingTriggerType(StringHolder completeMatchmakingTriggerType)
    {
        ensureData().completeMatchmakingTriggerType.emplace(std::move(completeMatchmakingTriggerType));
    }

    /**
     * マッチメイキング完了時のアクションを設定
     *
     * @param completeMatchmakingTriggerType マッチメイキング完了時のアクション
     */
    UpdateNamespaceRequest& withCompleteMatchmakingTriggerType(StringHolder completeMatchmakingTriggerType)
    {
        ensureData().completeMatchmakingTriggerType.emplace(std::move(completeMatchmakingTriggerType));
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
    void setCompleteMatchmakingTriggerRealtimeNamespaceId(StringHolder completeMatchmakingTriggerRealtimeNamespaceId)
    {
        ensureData().completeMatchmakingTriggerRealtimeNamespaceId.emplace(std::move(completeMatchmakingTriggerRealtimeNamespaceId));
    }

    /**
     * マッチメイキング完了時 にルームを作成するネームスペース のGRNを設定
     *
     * @param completeMatchmakingTriggerRealtimeNamespaceId マッチメイキング完了時 にルームを作成するネームスペース のGRN
     */
    UpdateNamespaceRequest& withCompleteMatchmakingTriggerRealtimeNamespaceId(StringHolder completeMatchmakingTriggerRealtimeNamespaceId)
    {
        ensureData().completeMatchmakingTriggerRealtimeNamespaceId.emplace(std::move(completeMatchmakingTriggerRealtimeNamespaceId));
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
    void setCompleteMatchmakingTriggerScriptId(StringHolder completeMatchmakingTriggerScriptId)
    {
        ensureData().completeMatchmakingTriggerScriptId.emplace(std::move(completeMatchmakingTriggerScriptId));
    }

    /**
     * マッチメイキング完了時 に実行されるスクリプト のGRNを設定
     *
     * @param completeMatchmakingTriggerScriptId マッチメイキング完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCompleteMatchmakingTriggerScriptId(StringHolder completeMatchmakingTriggerScriptId)
    {
        ensureData().completeMatchmakingTriggerScriptId.emplace(std::move(completeMatchmakingTriggerScriptId));
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
    void setJoinNotification(NotificationSetting joinNotification)
    {
        ensureData().joinNotification.emplace(std::move(joinNotification));
    }

    /**
     * ギャザリングに新規プレイヤーが参加したときのプッシュ通知を設定
     *
     * @param joinNotification ギャザリングに新規プレイヤーが参加したときのプッシュ通知
     */
    UpdateNamespaceRequest& withJoinNotification(NotificationSetting joinNotification)
    {
        ensureData().joinNotification.emplace(std::move(joinNotification));
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
    void setLeaveNotification(NotificationSetting leaveNotification)
    {
        ensureData().leaveNotification.emplace(std::move(leaveNotification));
    }

    /**
     * ギャザリングからプレイヤーが離脱したときのプッシュ通知を設定
     *
     * @param leaveNotification ギャザリングからプレイヤーが離脱したときのプッシュ通知
     */
    UpdateNamespaceRequest& withLeaveNotification(NotificationSetting leaveNotification)
    {
        ensureData().leaveNotification.emplace(std::move(leaveNotification));
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
    void setCompleteNotification(NotificationSetting completeNotification)
    {
        ensureData().completeNotification.emplace(std::move(completeNotification));
    }

    /**
     * マッチメイキングが完了したときのプッシュ通知を設定
     *
     * @param completeNotification マッチメイキングが完了したときのプッシュ通知
     */
    UpdateNamespaceRequest& withCompleteNotification(NotificationSetting completeNotification)
    {
        ensureData().completeNotification.emplace(std::move(completeNotification));
        return *this;
    }

    /**
     * ログの出力設定を取得
     *
     * @return ログの出力設定
     */
    const optional<LogSetting>& getLogSetting() const
    {
        return ensureData().logSetting;
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    void setLogSetting(LogSetting logSetting)
    {
        ensureData().logSetting.emplace(std::move(logSetting));
    }

    /**
     * ログの出力設定を設定
     *
     * @param logSetting ログの出力設定
     */
    UpdateNamespaceRequest& withLogSetting(LogSetting logSetting)
    {
        ensureData().logSetting.emplace(std::move(logSetting));
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

#endif //GS2_MATCHMAKING_CONTROL_UPDATENAMESPACEREQUEST_HPP_