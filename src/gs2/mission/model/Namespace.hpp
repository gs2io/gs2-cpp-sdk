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

#ifndef GS2_MISSION_MODEL_NAMESPACE_HPP_
#define GS2_MISSION_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "NotificationSetting.hpp"
#include "LogSetting.hpp"
#include <memory>

namespace gs2 { namespace mission {

/**
 * ネームスペース
 *
 * @author Game Server Services, Inc.
 *
 */
class Namespace : public Gs2Object
{
    friend bool operator!=(const Namespace& lhs, const Namespace& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ネームスペース */
        optional<StringHolder> namespaceId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ネームスペース名 */
        optional<StringHolder> name;
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
        /** ログの出力設定 */
        optional<LogSetting> logSetting;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Namespace() = default;
    Namespace(const Namespace& namespace_) = default;
    Namespace(Namespace&& namespace_) = default;
    ~Namespace() = default;

    Namespace& operator=(const Namespace& namespace_) = default;
    Namespace& operator=(Namespace&& namespace_) = default;

    Namespace deepCopy() const;

    const Namespace* operator->() const
    {
        return this;
    }

    Namespace* operator->()
    {
        return this;
    }
    /**
     * ネームスペースを取得
     *
     * @return ネームスペース
     */
    const optional<StringHolder>& getNamespaceId() const
    {
        return ensureData().namespaceId;
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    void setNamespaceId(StringHolder namespaceId)
    {
        ensureData().namespaceId.emplace(std::move(namespaceId));
    }

    /**
     * ネームスペースを設定
     *
     * @param namespaceId ネームスペース
     */
    Namespace& withNamespaceId(StringHolder namespaceId)
    {
        setNamespaceId(std::move(namespaceId));
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Namespace& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
        return *this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ネームスペース名を設定
     *
     * @param name ネームスペース名
     */
    Namespace& withName(StringHolder name)
    {
        setName(std::move(name));
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
    Namespace& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    Namespace& withMissionCompleteTriggerScriptId(StringHolder missionCompleteTriggerScriptId)
    {
        setMissionCompleteTriggerScriptId(std::move(missionCompleteTriggerScriptId));
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
    Namespace& withMissionCompleteDoneTriggerScriptId(StringHolder missionCompleteDoneTriggerScriptId)
    {
        setMissionCompleteDoneTriggerScriptId(std::move(missionCompleteDoneTriggerScriptId));
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
    Namespace& withMissionCompleteDoneTriggerQueueNamespaceId(StringHolder missionCompleteDoneTriggerQueueNamespaceId)
    {
        setMissionCompleteDoneTriggerQueueNamespaceId(std::move(missionCompleteDoneTriggerQueueNamespaceId));
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
    Namespace& withCounterIncrementTriggerScriptId(StringHolder counterIncrementTriggerScriptId)
    {
        setCounterIncrementTriggerScriptId(std::move(counterIncrementTriggerScriptId));
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
    Namespace& withCounterIncrementDoneTriggerScriptId(StringHolder counterIncrementDoneTriggerScriptId)
    {
        setCounterIncrementDoneTriggerScriptId(std::move(counterIncrementDoneTriggerScriptId));
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
    Namespace& withCounterIncrementDoneTriggerQueueNamespaceId(StringHolder counterIncrementDoneTriggerQueueNamespaceId)
    {
        setCounterIncrementDoneTriggerQueueNamespaceId(std::move(counterIncrementDoneTriggerQueueNamespaceId));
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
    Namespace& withReceiveRewardsTriggerScriptId(StringHolder receiveRewardsTriggerScriptId)
    {
        setReceiveRewardsTriggerScriptId(std::move(receiveRewardsTriggerScriptId));
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
    Namespace& withReceiveRewardsDoneTriggerScriptId(StringHolder receiveRewardsDoneTriggerScriptId)
    {
        setReceiveRewardsDoneTriggerScriptId(std::move(receiveRewardsDoneTriggerScriptId));
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
    Namespace& withReceiveRewardsDoneTriggerQueueNamespaceId(StringHolder receiveRewardsDoneTriggerQueueNamespaceId)
    {
        setReceiveRewardsDoneTriggerQueueNamespaceId(std::move(receiveRewardsDoneTriggerQueueNamespaceId));
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
    Namespace& withQueueNamespaceId(StringHolder queueNamespaceId)
    {
        setQueueNamespaceId(std::move(queueNamespaceId));
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
    Namespace& withKeyId(StringHolder keyId)
    {
        setKeyId(std::move(keyId));
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
    Namespace& withCompleteNotification(NotificationSetting completeNotification)
    {
        setCompleteNotification(std::move(completeNotification));
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
    Namespace& withLogSetting(LogSetting logSetting)
    {
        setLogSetting(std::move(logSetting));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Namespace& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Namespace& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Namespace& lhs, const Namespace& lhr);

inline bool operator==(const Namespace& lhs, const Namespace& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_NAMESPACE_HPP_