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

#ifndef GS2_MISSION_CONTROL_UPDATENAMESPACEREQUEST_HPP_
#define GS2_MISSION_CONTROL_UPDATENAMESPACEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/mission/Gs2MissionConst.hpp>
#include <gs2/mission/model/model.hpp>
#include <memory>

namespace gs2 { namespace mission
{

/**
 * ネームスペースを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateNamespaceRequest : public Gs2BasicRequest, public Gs2Mission
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
        /** ミッション達成時 に実行されるスクリプト のGRN */
        optional<StringHolder> missionCompleteTriggerScriptId;
        /** ミッション達成完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> missionCompleteDoneTriggerScriptId;
        /** ミッション達成完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> missionCompleteDoneTriggerQueueNamespaceId;
        /** カウンター上昇時 に実行されるスクリプト のGRN */
        optional<StringHolder> counterIncrementTriggerScriptId;
        /** カウンター上昇完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> counterIncrementDoneTriggerScriptId;
        /** カウンター上昇完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> counterIncrementDoneTriggerQueueNamespaceId;
        /** 報酬受け取り時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveRewardsTriggerScriptId;
        /** 報酬受け取り完了時 に実行されるスクリプト のGRN */
        optional<StringHolder> receiveRewardsDoneTriggerScriptId;
        /** 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN */
        optional<StringHolder> receiveRewardsDoneTriggerQueueNamespaceId;
        /** 報酬付与処理をジョブとして追加するキューネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;
        /** ミッションのタスクを達成したときのプッシュ通知 */
        optional<NotificationSetting> completeNotification;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            missionCompleteTriggerScriptId(data.missionCompleteTriggerScriptId),
            missionCompleteDoneTriggerScriptId(data.missionCompleteDoneTriggerScriptId),
            missionCompleteDoneTriggerQueueNamespaceId(data.missionCompleteDoneTriggerQueueNamespaceId),
            counterIncrementTriggerScriptId(data.counterIncrementTriggerScriptId),
            counterIncrementDoneTriggerScriptId(data.counterIncrementDoneTriggerScriptId),
            counterIncrementDoneTriggerQueueNamespaceId(data.counterIncrementDoneTriggerQueueNamespaceId),
            receiveRewardsTriggerScriptId(data.receiveRewardsTriggerScriptId),
            receiveRewardsDoneTriggerScriptId(data.receiveRewardsDoneTriggerScriptId),
            receiveRewardsDoneTriggerQueueNamespaceId(data.receiveRewardsDoneTriggerQueueNamespaceId),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId)
        {
            if (data.completeNotification)
            {
                completeNotification = data.completeNotification->deepCopy();
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
     * ミッション達成時 に実行されるスクリプト のGRNを取得
     *
     * @return ミッション達成時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getMissionCompleteTriggerScriptId() const
    {
        return ensureData().missionCompleteTriggerScriptId;
    }

    /**
     * ミッション達成時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteTriggerScriptId ミッション達成時 に実行されるスクリプト のGRN
     */
    void setMissionCompleteTriggerScriptId(StringHolder missionCompleteTriggerScriptId)
    {
        ensureData().missionCompleteTriggerScriptId.emplace(std::move(missionCompleteTriggerScriptId));
    }

    /**
     * ミッション達成時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteTriggerScriptId ミッション達成時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withMissionCompleteTriggerScriptId(StringHolder missionCompleteTriggerScriptId)
    {
        ensureData().missionCompleteTriggerScriptId.emplace(std::move(missionCompleteTriggerScriptId));
        return *this;
    }

    /**
     * ミッション達成完了時 に実行されるスクリプト のGRNを取得
     *
     * @return ミッション達成完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getMissionCompleteDoneTriggerScriptId() const
    {
        return ensureData().missionCompleteDoneTriggerScriptId;
    }

    /**
     * ミッション達成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteDoneTriggerScriptId ミッション達成完了時 に実行されるスクリプト のGRN
     */
    void setMissionCompleteDoneTriggerScriptId(StringHolder missionCompleteDoneTriggerScriptId)
    {
        ensureData().missionCompleteDoneTriggerScriptId.emplace(std::move(missionCompleteDoneTriggerScriptId));
    }

    /**
     * ミッション達成完了時 に実行されるスクリプト のGRNを設定
     *
     * @param missionCompleteDoneTriggerScriptId ミッション達成完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withMissionCompleteDoneTriggerScriptId(StringHolder missionCompleteDoneTriggerScriptId)
    {
        ensureData().missionCompleteDoneTriggerScriptId.emplace(std::move(missionCompleteDoneTriggerScriptId));
        return *this;
    }

    /**
     * ミッション達成完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return ミッション達成完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getMissionCompleteDoneTriggerQueueNamespaceId() const
    {
        return ensureData().missionCompleteDoneTriggerQueueNamespaceId;
    }

    /**
     * ミッション達成完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param missionCompleteDoneTriggerQueueNamespaceId ミッション達成完了時 にジョブが登録されるネームスペース のGRN
     */
    void setMissionCompleteDoneTriggerQueueNamespaceId(StringHolder missionCompleteDoneTriggerQueueNamespaceId)
    {
        ensureData().missionCompleteDoneTriggerQueueNamespaceId.emplace(std::move(missionCompleteDoneTriggerQueueNamespaceId));
    }

    /**
     * ミッション達成完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param missionCompleteDoneTriggerQueueNamespaceId ミッション達成完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withMissionCompleteDoneTriggerQueueNamespaceId(StringHolder missionCompleteDoneTriggerQueueNamespaceId)
    {
        ensureData().missionCompleteDoneTriggerQueueNamespaceId.emplace(std::move(missionCompleteDoneTriggerQueueNamespaceId));
        return *this;
    }

    /**
     * カウンター上昇時 に実行されるスクリプト のGRNを取得
     *
     * @return カウンター上昇時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCounterIncrementTriggerScriptId() const
    {
        return ensureData().counterIncrementTriggerScriptId;
    }

    /**
     * カウンター上昇時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementTriggerScriptId カウンター上昇時 に実行されるスクリプト のGRN
     */
    void setCounterIncrementTriggerScriptId(StringHolder counterIncrementTriggerScriptId)
    {
        ensureData().counterIncrementTriggerScriptId.emplace(std::move(counterIncrementTriggerScriptId));
    }

    /**
     * カウンター上昇時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementTriggerScriptId カウンター上昇時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCounterIncrementTriggerScriptId(StringHolder counterIncrementTriggerScriptId)
    {
        ensureData().counterIncrementTriggerScriptId.emplace(std::move(counterIncrementTriggerScriptId));
        return *this;
    }

    /**
     * カウンター上昇完了時 に実行されるスクリプト のGRNを取得
     *
     * @return カウンター上昇完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getCounterIncrementDoneTriggerScriptId() const
    {
        return ensureData().counterIncrementDoneTriggerScriptId;
    }

    /**
     * カウンター上昇完了時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementDoneTriggerScriptId カウンター上昇完了時 に実行されるスクリプト のGRN
     */
    void setCounterIncrementDoneTriggerScriptId(StringHolder counterIncrementDoneTriggerScriptId)
    {
        ensureData().counterIncrementDoneTriggerScriptId.emplace(std::move(counterIncrementDoneTriggerScriptId));
    }

    /**
     * カウンター上昇完了時 に実行されるスクリプト のGRNを設定
     *
     * @param counterIncrementDoneTriggerScriptId カウンター上昇完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withCounterIncrementDoneTriggerScriptId(StringHolder counterIncrementDoneTriggerScriptId)
    {
        ensureData().counterIncrementDoneTriggerScriptId.emplace(std::move(counterIncrementDoneTriggerScriptId));
        return *this;
    }

    /**
     * カウンター上昇完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return カウンター上昇完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getCounterIncrementDoneTriggerQueueNamespaceId() const
    {
        return ensureData().counterIncrementDoneTriggerQueueNamespaceId;
    }

    /**
     * カウンター上昇完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param counterIncrementDoneTriggerQueueNamespaceId カウンター上昇完了時 にジョブが登録されるネームスペース のGRN
     */
    void setCounterIncrementDoneTriggerQueueNamespaceId(StringHolder counterIncrementDoneTriggerQueueNamespaceId)
    {
        ensureData().counterIncrementDoneTriggerQueueNamespaceId.emplace(std::move(counterIncrementDoneTriggerQueueNamespaceId));
    }

    /**
     * カウンター上昇完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param counterIncrementDoneTriggerQueueNamespaceId カウンター上昇完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withCounterIncrementDoneTriggerQueueNamespaceId(StringHolder counterIncrementDoneTriggerQueueNamespaceId)
    {
        ensureData().counterIncrementDoneTriggerQueueNamespaceId.emplace(std::move(counterIncrementDoneTriggerQueueNamespaceId));
        return *this;
    }

    /**
     * 報酬受け取り時 に実行されるスクリプト のGRNを取得
     *
     * @return 報酬受け取り時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveRewardsTriggerScriptId() const
    {
        return ensureData().receiveRewardsTriggerScriptId;
    }

    /**
     * 報酬受け取り時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsTriggerScriptId 報酬受け取り時 に実行されるスクリプト のGRN
     */
    void setReceiveRewardsTriggerScriptId(StringHolder receiveRewardsTriggerScriptId)
    {
        ensureData().receiveRewardsTriggerScriptId.emplace(std::move(receiveRewardsTriggerScriptId));
    }

    /**
     * 報酬受け取り時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsTriggerScriptId 報酬受け取り時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withReceiveRewardsTriggerScriptId(StringHolder receiveRewardsTriggerScriptId)
    {
        ensureData().receiveRewardsTriggerScriptId.emplace(std::move(receiveRewardsTriggerScriptId));
        return *this;
    }

    /**
     * 報酬受け取り完了時 に実行されるスクリプト のGRNを取得
     *
     * @return 報酬受け取り完了時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReceiveRewardsDoneTriggerScriptId() const
    {
        return ensureData().receiveRewardsDoneTriggerScriptId;
    }

    /**
     * 報酬受け取り完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsDoneTriggerScriptId 報酬受け取り完了時 に実行されるスクリプト のGRN
     */
    void setReceiveRewardsDoneTriggerScriptId(StringHolder receiveRewardsDoneTriggerScriptId)
    {
        ensureData().receiveRewardsDoneTriggerScriptId.emplace(std::move(receiveRewardsDoneTriggerScriptId));
    }

    /**
     * 報酬受け取り完了時 に実行されるスクリプト のGRNを設定
     *
     * @param receiveRewardsDoneTriggerScriptId 報酬受け取り完了時 に実行されるスクリプト のGRN
     */
    UpdateNamespaceRequest& withReceiveRewardsDoneTriggerScriptId(StringHolder receiveRewardsDoneTriggerScriptId)
    {
        ensureData().receiveRewardsDoneTriggerScriptId.emplace(std::move(receiveRewardsDoneTriggerScriptId));
        return *this;
    }

    /**
     * 報酬受け取り完了時 にジョブが登録されるネームスペース のGRNを取得
     *
     * @return 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN
     */
    const optional<StringHolder>& getReceiveRewardsDoneTriggerQueueNamespaceId() const
    {
        return ensureData().receiveRewardsDoneTriggerQueueNamespaceId;
    }

    /**
     * 報酬受け取り完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveRewardsDoneTriggerQueueNamespaceId 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN
     */
    void setReceiveRewardsDoneTriggerQueueNamespaceId(StringHolder receiveRewardsDoneTriggerQueueNamespaceId)
    {
        ensureData().receiveRewardsDoneTriggerQueueNamespaceId.emplace(std::move(receiveRewardsDoneTriggerQueueNamespaceId));
    }

    /**
     * 報酬受け取り完了時 にジョブが登録されるネームスペース のGRNを設定
     *
     * @param receiveRewardsDoneTriggerQueueNamespaceId 報酬受け取り完了時 にジョブが登録されるネームスペース のGRN
     */
    UpdateNamespaceRequest& withReceiveRewardsDoneTriggerQueueNamespaceId(StringHolder receiveRewardsDoneTriggerQueueNamespaceId)
    {
        ensureData().receiveRewardsDoneTriggerQueueNamespaceId.emplace(std::move(receiveRewardsDoneTriggerQueueNamespaceId));
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
     * ミッションのタスクを達成したときのプッシュ通知を取得
     *
     * @return ミッションのタスクを達成したときのプッシュ通知
     */
    const optional<NotificationSetting>& getCompleteNotification() const
    {
        return ensureData().completeNotification;
    }

    /**
     * ミッションのタスクを達成したときのプッシュ通知を設定
     *
     * @param completeNotification ミッションのタスクを達成したときのプッシュ通知
     */
    void setCompleteNotification(NotificationSetting completeNotification)
    {
        ensureData().completeNotification.emplace(std::move(completeNotification));
    }

    /**
     * ミッションのタスクを達成したときのプッシュ通知を設定
     *
     * @param completeNotification ミッションのタスクを達成したときのプッシュ通知
     */
    UpdateNamespaceRequest& withCompleteNotification(NotificationSetting completeNotification)
    {
        ensureData().completeNotification.emplace(std::move(completeNotification));
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

#endif //GS2_MISSION_CONTROL_UPDATENAMESPACEREQUEST_HPP_