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

#ifndef GS2_QUEST_MODEL_QUESTMODEL_HPP_
#define GS2_QUEST_MODEL_QUESTMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Contents.hpp"
#include "ConsumeAction.hpp"
#include "AcquireAction.hpp"
#include <memory>

namespace gs2 { namespace quest {

/**
 * None
 *
 * @author Game Server Services, Inc.
 *
 */
class QuestModel : public Gs2Object
{
    friend bool operator!=(const QuestModel& lhs, const QuestModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエストモデル */
        optional<StringHolder> questModelId;
        /** クエストモデル名 */
        optional<StringHolder> name;
        /** クエストモデルのメタデータ */
        optional<StringHolder> metadata;
        /** クエストの内容 */
        optional<List<Contents>> contents;
        /** 挑戦可能な期間を指定するイベントマスター のGRN */
        optional<StringHolder> challengePeriodEventId;
        /** クエストの参加料 */
        optional<List<ConsumeAction>> consumeActions;
        /** クエスト失敗時の報酬 */
        optional<List<AcquireAction>> failedAcquireActions;
        /** クエストに挑戦するためにクリアしておく必要のあるクエスト名 */
        optional<List<StringHolder>> premiseQuestNames;

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
    QuestModel() = default;
    QuestModel(const QuestModel& questModel) = default;
    QuestModel(QuestModel&& questModel) = default;
    ~QuestModel() = default;

    QuestModel& operator=(const QuestModel& questModel) = default;
    QuestModel& operator=(QuestModel&& questModel) = default;

    QuestModel deepCopy() const;

    const QuestModel* operator->() const
    {
        return this;
    }

    QuestModel* operator->()
    {
        return this;
    }
    /**
     * クエストモデルを取得
     *
     * @return クエストモデル
     */
    const optional<StringHolder>& getQuestModelId() const
    {
        return ensureData().questModelId;
    }

    /**
     * クエストモデルを設定
     *
     * @param questModelId クエストモデル
     */
    void setQuestModelId(StringHolder questModelId)
    {
        ensureData().questModelId.emplace(std::move(questModelId));
    }

    /**
     * クエストモデルを設定
     *
     * @param questModelId クエストモデル
     */
    QuestModel& withQuestModelId(StringHolder questModelId)
    {
        setQuestModelId(std::move(questModelId));
        return *this;
    }

    /**
     * クエストモデル名を取得
     *
     * @return クエストモデル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * クエストモデル名を設定
     *
     * @param name クエストモデル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * クエストモデル名を設定
     *
     * @param name クエストモデル名
     */
    QuestModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * クエストモデルのメタデータを取得
     *
     * @return クエストモデルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * クエストモデルのメタデータを設定
     *
     * @param metadata クエストモデルのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * クエストモデルのメタデータを設定
     *
     * @param metadata クエストモデルのメタデータ
     */
    QuestModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * クエストの内容を取得
     *
     * @return クエストの内容
     */
    const optional<List<Contents>>& getContents() const
    {
        return ensureData().contents;
    }

    /**
     * クエストの内容を設定
     *
     * @param contents クエストの内容
     */
    void setContents(List<Contents> contents)
    {
        ensureData().contents.emplace(std::move(contents));
    }

    /**
     * クエストの内容を設定
     *
     * @param contents クエストの内容
     */
    QuestModel& withContents(List<Contents> contents)
    {
        setContents(std::move(contents));
        return *this;
    }

    /**
     * 挑戦可能な期間を指定するイベントマスター のGRNを取得
     *
     * @return 挑戦可能な期間を指定するイベントマスター のGRN
     */
    const optional<StringHolder>& getChallengePeriodEventId() const
    {
        return ensureData().challengePeriodEventId;
    }

    /**
     * 挑戦可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 挑戦可能な期間を指定するイベントマスター のGRN
     */
    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(std::move(challengePeriodEventId));
    }

    /**
     * 挑戦可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 挑戦可能な期間を指定するイベントマスター のGRN
     */
    QuestModel& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        setChallengePeriodEventId(std::move(challengePeriodEventId));
        return *this;
    }

    /**
     * クエストの参加料を取得
     *
     * @return クエストの参加料
     */
    const optional<List<ConsumeAction>>& getConsumeActions() const
    {
        return ensureData().consumeActions;
    }

    /**
     * クエストの参加料を設定
     *
     * @param consumeActions クエストの参加料
     */
    void setConsumeActions(List<ConsumeAction> consumeActions)
    {
        ensureData().consumeActions.emplace(std::move(consumeActions));
    }

    /**
     * クエストの参加料を設定
     *
     * @param consumeActions クエストの参加料
     */
    QuestModel& withConsumeActions(List<ConsumeAction> consumeActions)
    {
        setConsumeActions(std::move(consumeActions));
        return *this;
    }

    /**
     * クエスト失敗時の報酬を取得
     *
     * @return クエスト失敗時の報酬
     */
    const optional<List<AcquireAction>>& getFailedAcquireActions() const
    {
        return ensureData().failedAcquireActions;
    }

    /**
     * クエスト失敗時の報酬を設定
     *
     * @param failedAcquireActions クエスト失敗時の報酬
     */
    void setFailedAcquireActions(List<AcquireAction> failedAcquireActions)
    {
        ensureData().failedAcquireActions.emplace(std::move(failedAcquireActions));
    }

    /**
     * クエスト失敗時の報酬を設定
     *
     * @param failedAcquireActions クエスト失敗時の報酬
     */
    QuestModel& withFailedAcquireActions(List<AcquireAction> failedAcquireActions)
    {
        setFailedAcquireActions(std::move(failedAcquireActions));
        return *this;
    }

    /**
     * クエストに挑戦するためにクリアしておく必要のあるクエスト名を取得
     *
     * @return クエストに挑戦するためにクリアしておく必要のあるクエスト名
     */
    const optional<List<StringHolder>>& getPremiseQuestNames() const
    {
        return ensureData().premiseQuestNames;
    }

    /**
     * クエストに挑戦するためにクリアしておく必要のあるクエスト名を設定
     *
     * @param premiseQuestNames クエストに挑戦するためにクリアしておく必要のあるクエスト名
     */
    void setPremiseQuestNames(List<StringHolder> premiseQuestNames)
    {
        ensureData().premiseQuestNames.emplace(std::move(premiseQuestNames));
    }

    /**
     * クエストに挑戦するためにクリアしておく必要のあるクエスト名を設定
     *
     * @param premiseQuestNames クエストに挑戦するためにクリアしておく必要のあるクエスト名
     */
    QuestModel& withPremiseQuestNames(List<StringHolder> premiseQuestNames)
    {
        setPremiseQuestNames(std::move(premiseQuestNames));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const QuestModel& lhs, const QuestModel& lhr);

inline bool operator==(const QuestModel& lhs, const QuestModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_QUESTMODEL_HPP_