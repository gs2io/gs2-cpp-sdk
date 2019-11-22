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

#ifndef GS2_MATCHMAKING_MODEL_NAMESPACE_HPP_
#define GS2_MATCHMAKING_MODEL_NAMESPACE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "NotificationSetting.hpp"
#include "NotificationSetting.hpp"
#include "NotificationSetting.hpp"
#include "LogSetting.hpp"
#include <memory>

namespace gs2 { namespace matchmaking {

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
    Namespace& withCreateGatheringTriggerType(StringHolder createGatheringTriggerType)
    {
        setCreateGatheringTriggerType(std::move(createGatheringTriggerType));
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
    Namespace& withCreateGatheringTriggerRealtimeNamespaceId(StringHolder createGatheringTriggerRealtimeNamespaceId)
    {
        setCreateGatheringTriggerRealtimeNamespaceId(std::move(createGatheringTriggerRealtimeNamespaceId));
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
    Namespace& withCreateGatheringTriggerScriptId(StringHolder createGatheringTriggerScriptId)
    {
        setCreateGatheringTriggerScriptId(std::move(createGatheringTriggerScriptId));
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
    Namespace& withCompleteMatchmakingTriggerType(StringHolder completeMatchmakingTriggerType)
    {
        setCompleteMatchmakingTriggerType(std::move(completeMatchmakingTriggerType));
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
    Namespace& withCompleteMatchmakingTriggerRealtimeNamespaceId(StringHolder completeMatchmakingTriggerRealtimeNamespaceId)
    {
        setCompleteMatchmakingTriggerRealtimeNamespaceId(std::move(completeMatchmakingTriggerRealtimeNamespaceId));
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
    Namespace& withCompleteMatchmakingTriggerScriptId(StringHolder completeMatchmakingTriggerScriptId)
    {
        setCompleteMatchmakingTriggerScriptId(std::move(completeMatchmakingTriggerScriptId));
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
    Namespace& withJoinNotification(NotificationSetting joinNotification)
    {
        setJoinNotification(std::move(joinNotification));
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
    Namespace& withLeaveNotification(NotificationSetting leaveNotification)
    {
        setLeaveNotification(std::move(leaveNotification));
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

#endif //GS2_MATCHMAKING_MODEL_NAMESPACE_HPP_