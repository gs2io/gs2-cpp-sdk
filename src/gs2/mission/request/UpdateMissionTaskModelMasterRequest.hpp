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

#ifndef GS2_MISSION_CONTROL_UPDATEMISSIONTASKMODELMASTERREQUEST_HPP_
#define GS2_MISSION_CONTROL_UPDATEMISSIONTASKMODELMASTERREQUEST_HPP_

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
 * ミッションタスクマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateMissionTaskModelMasterRequest : public Gs2BasicRequest, public Gs2Mission
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ミッショングループ名 */
        optional<StringHolder> missionGroupName;
        /** タスク名 */
        optional<StringHolder> missionTaskName;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** ミッションタスクの説明 */
        optional<StringHolder> description;
        /** カウンター名 */
        optional<StringHolder> counterName;
        /** 目標値 */
        optional<Int64> targetValue;
        /** ミッション達成時の報酬 */
        optional<List<AcquireAction>> completeAcquireActions;
        /** 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN */
        optional<StringHolder> challengePeriodEventId;
        /** このタスクに挑戦するために達成しておく必要のあるタスクの名前 */
        optional<StringHolder> premiseMissionTaskName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            missionGroupName(data.missionGroupName),
            missionTaskName(data.missionTaskName),
            metadata(data.metadata),
            description(data.description),
            counterName(data.counterName),
            targetValue(data.targetValue),
            challengePeriodEventId(data.challengePeriodEventId),
            premiseMissionTaskName(data.premiseMissionTaskName)
        {
            if (data.completeAcquireActions)
            {
                completeAcquireActions = data.completeAcquireActions->deepCopy();
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
    UpdateMissionTaskModelMasterRequest() = default;
    UpdateMissionTaskModelMasterRequest(const UpdateMissionTaskModelMasterRequest& updateMissionTaskModelMasterRequest) = default;
    UpdateMissionTaskModelMasterRequest(UpdateMissionTaskModelMasterRequest&& updateMissionTaskModelMasterRequest) = default;
    ~UpdateMissionTaskModelMasterRequest() GS2_OVERRIDE = default;

    UpdateMissionTaskModelMasterRequest& operator=(const UpdateMissionTaskModelMasterRequest& updateMissionTaskModelMasterRequest) = default;
    UpdateMissionTaskModelMasterRequest& operator=(UpdateMissionTaskModelMasterRequest&& updateMissionTaskModelMasterRequest) = default;

    UpdateMissionTaskModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateMissionTaskModelMasterRequest);
    }

    const UpdateMissionTaskModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateMissionTaskModelMasterRequest* operator->()
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
    UpdateMissionTaskModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ミッショングループ名を取得
     *
     * @return ミッショングループ名
     */
    const optional<StringHolder>& getMissionGroupName() const
    {
        return ensureData().missionGroupName;
    }

    /**
     * ミッショングループ名を設定
     *
     * @param missionGroupName ミッショングループ名
     */
    void setMissionGroupName(StringHolder missionGroupName)
    {
        ensureData().missionGroupName.emplace(std::move(missionGroupName));
    }

    /**
     * ミッショングループ名を設定
     *
     * @param missionGroupName ミッショングループ名
     */
    UpdateMissionTaskModelMasterRequest& withMissionGroupName(StringHolder missionGroupName)
    {
        ensureData().missionGroupName.emplace(std::move(missionGroupName));
        return *this;
    }

    /**
     * タスク名を取得
     *
     * @return タスク名
     */
    const optional<StringHolder>& getMissionTaskName() const
    {
        return ensureData().missionTaskName;
    }

    /**
     * タスク名を設定
     *
     * @param missionTaskName タスク名
     */
    void setMissionTaskName(StringHolder missionTaskName)
    {
        ensureData().missionTaskName.emplace(std::move(missionTaskName));
    }

    /**
     * タスク名を設定
     *
     * @param missionTaskName タスク名
     */
    UpdateMissionTaskModelMasterRequest& withMissionTaskName(StringHolder missionTaskName)
    {
        ensureData().missionTaskName.emplace(std::move(missionTaskName));
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    UpdateMissionTaskModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * ミッションタスクの説明を取得
     *
     * @return ミッションタスクの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * ミッションタスクの説明を設定
     *
     * @param description ミッションタスクの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * ミッションタスクの説明を設定
     *
     * @param description ミッションタスクの説明
     */
    UpdateMissionTaskModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * カウンター名を取得
     *
     * @return カウンター名
     */
    const optional<StringHolder>& getCounterName() const
    {
        return ensureData().counterName;
    }

    /**
     * カウンター名を設定
     *
     * @param counterName カウンター名
     */
    void setCounterName(StringHolder counterName)
    {
        ensureData().counterName.emplace(std::move(counterName));
    }

    /**
     * カウンター名を設定
     *
     * @param counterName カウンター名
     */
    UpdateMissionTaskModelMasterRequest& withCounterName(StringHolder counterName)
    {
        ensureData().counterName.emplace(std::move(counterName));
        return *this;
    }

    /**
     * 目標値を取得
     *
     * @return 目標値
     */
    const optional<Int64>& getTargetValue() const
    {
        return ensureData().targetValue;
    }

    /**
     * 目標値を設定
     *
     * @param targetValue 目標値
     */
    void setTargetValue(Int64 targetValue)
    {
        ensureData().targetValue.emplace(targetValue);
    }

    /**
     * 目標値を設定
     *
     * @param targetValue 目標値
     */
    UpdateMissionTaskModelMasterRequest& withTargetValue(Int64 targetValue)
    {
        ensureData().targetValue.emplace(targetValue);
        return *this;
    }

    /**
     * ミッション達成時の報酬を取得
     *
     * @return ミッション達成時の報酬
     */
    const optional<List<AcquireAction>>& getCompleteAcquireActions() const
    {
        return ensureData().completeAcquireActions;
    }

    /**
     * ミッション達成時の報酬を設定
     *
     * @param completeAcquireActions ミッション達成時の報酬
     */
    void setCompleteAcquireActions(List<AcquireAction> completeAcquireActions)
    {
        ensureData().completeAcquireActions.emplace(std::move(completeAcquireActions));
    }

    /**
     * ミッション達成時の報酬を設定
     *
     * @param completeAcquireActions ミッション達成時の報酬
     */
    UpdateMissionTaskModelMasterRequest& withCompleteAcquireActions(List<AcquireAction> completeAcquireActions)
    {
        ensureData().completeAcquireActions.emplace(std::move(completeAcquireActions));
        return *this;
    }

    /**
     * 達成報酬の受け取り可能な期間を指定するイベントマスター のGRNを取得
     *
     * @return 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN
     */
    const optional<StringHolder>& getChallengePeriodEventId() const
    {
        return ensureData().challengePeriodEventId;
    }

    /**
     * 達成報酬の受け取り可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN
     */
    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
    }

    /**
     * 達成報酬の受け取り可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 達成報酬の受け取り可能な期間を指定するイベントマスター のGRN
     */
    UpdateMissionTaskModelMasterRequest& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
        return *this;
    }

    /**
     * このタスクに挑戦するために達成しておく必要のあるタスクの名前を取得
     *
     * @return このタスクに挑戦するために達成しておく必要のあるタスクの名前
     */
    const optional<StringHolder>& getPremiseMissionTaskName() const
    {
        return ensureData().premiseMissionTaskName;
    }

    /**
     * このタスクに挑戦するために達成しておく必要のあるタスクの名前を設定
     *
     * @param premiseMissionTaskName このタスクに挑戦するために達成しておく必要のあるタスクの名前
     */
    void setPremiseMissionTaskName(StringHolder premiseMissionTaskName)
    {
        ensureData().premiseMissionTaskName.emplace(std::move(premiseMissionTaskName));
    }

    /**
     * このタスクに挑戦するために達成しておく必要のあるタスクの名前を設定
     *
     * @param premiseMissionTaskName このタスクに挑戦するために達成しておく必要のあるタスクの名前
     */
    UpdateMissionTaskModelMasterRequest& withPremiseMissionTaskName(StringHolder premiseMissionTaskName)
    {
        ensureData().premiseMissionTaskName.emplace(std::move(premiseMissionTaskName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateMissionTaskModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateMissionTaskModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MISSION_CONTROL_UPDATEMISSIONTASKMODELMASTERREQUEST_HPP_