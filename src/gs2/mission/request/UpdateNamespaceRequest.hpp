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
        /** ミッションを達成したときに実行するスクリプト */
        optional<ScriptSetting> missionCompleteScript;
        /** カウンターを上昇したときに実行するスクリプト */
        optional<ScriptSetting> counterIncrementScript;
        /** 報酬を受け取ったときに実行するスクリプト */
        optional<ScriptSetting> receiveRewardsScript;
        /** 報酬付与処理をジョブとして追加するキューネームスペース のGRN */
        optional<StringHolder> queueNamespaceId;
        /** 報酬付与処理のスタンプシートで使用する暗号鍵GRN */
        optional<StringHolder> keyId;
        /** ミッションのタスクを達成したときのプッシュ通知 */
        optional<NotificationSetting> completeNotification;
        /** ログの出力設定 */
        optional<LogSetting> logSetting;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            description(data.description),
            queueNamespaceId(data.queueNamespaceId),
            keyId(data.keyId)
        {
            if (data.missionCompleteScript)
            {
                missionCompleteScript = data.missionCompleteScript->deepCopy();
            }
            if (data.counterIncrementScript)
            {
                counterIncrementScript = data.counterIncrementScript->deepCopy();
            }
            if (data.receiveRewardsScript)
            {
                receiveRewardsScript = data.receiveRewardsScript->deepCopy();
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
     * ミッションを達成したときに実行するスクリプトを取得
     *
     * @return ミッションを達成したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getMissionCompleteScript() const
    {
        return ensureData().missionCompleteScript;
    }

    /**
     * ミッションを達成したときに実行するスクリプトを設定
     *
     * @param missionCompleteScript ミッションを達成したときに実行するスクリプト
     */
    void setMissionCompleteScript(ScriptSetting missionCompleteScript)
    {
        ensureData().missionCompleteScript.emplace(std::move(missionCompleteScript));
    }

    /**
     * ミッションを達成したときに実行するスクリプトを設定
     *
     * @param missionCompleteScript ミッションを達成したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withMissionCompleteScript(ScriptSetting missionCompleteScript)
    {
        ensureData().missionCompleteScript.emplace(std::move(missionCompleteScript));
        return *this;
    }

    /**
     * カウンターを上昇したときに実行するスクリプトを取得
     *
     * @return カウンターを上昇したときに実行するスクリプト
     */
    const optional<ScriptSetting>& getCounterIncrementScript() const
    {
        return ensureData().counterIncrementScript;
    }

    /**
     * カウンターを上昇したときに実行するスクリプトを設定
     *
     * @param counterIncrementScript カウンターを上昇したときに実行するスクリプト
     */
    void setCounterIncrementScript(ScriptSetting counterIncrementScript)
    {
        ensureData().counterIncrementScript.emplace(std::move(counterIncrementScript));
    }

    /**
     * カウンターを上昇したときに実行するスクリプトを設定
     *
     * @param counterIncrementScript カウンターを上昇したときに実行するスクリプト
     */
    UpdateNamespaceRequest& withCounterIncrementScript(ScriptSetting counterIncrementScript)
    {
        ensureData().counterIncrementScript.emplace(std::move(counterIncrementScript));
        return *this;
    }

    /**
     * 報酬を受け取ったときに実行するスクリプトを取得
     *
     * @return 報酬を受け取ったときに実行するスクリプト
     */
    const optional<ScriptSetting>& getReceiveRewardsScript() const
    {
        return ensureData().receiveRewardsScript;
    }

    /**
     * 報酬を受け取ったときに実行するスクリプトを設定
     *
     * @param receiveRewardsScript 報酬を受け取ったときに実行するスクリプト
     */
    void setReceiveRewardsScript(ScriptSetting receiveRewardsScript)
    {
        ensureData().receiveRewardsScript.emplace(std::move(receiveRewardsScript));
    }

    /**
     * 報酬を受け取ったときに実行するスクリプトを設定
     *
     * @param receiveRewardsScript 報酬を受け取ったときに実行するスクリプト
     */
    UpdateNamespaceRequest& withReceiveRewardsScript(ScriptSetting receiveRewardsScript)
    {
        ensureData().receiveRewardsScript.emplace(std::move(receiveRewardsScript));
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

#endif //GS2_MISSION_CONTROL_UPDATENAMESPACEREQUEST_HPP_