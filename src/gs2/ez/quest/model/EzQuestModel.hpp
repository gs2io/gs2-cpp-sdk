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

#ifndef GS2_EZ_QUEST_MODEL_EZQUESTMODEL_HPP_
#define GS2_EZ_QUEST_MODEL_EZQUESTMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzContents.hpp"
#include "EzConsumeAction.hpp"
#include "EzAcquireAction.hpp"
#include <memory>


namespace gs2 {

namespace quest {

class QuestModel;

}

namespace ez { namespace quest {

class EzQuestModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** クエストモデル */
        gs2::optional<StringHolder> questModelId;
        /** クエストモデル名 */
        gs2::optional<StringHolder> name;
        /** クエストモデルのメタデータ */
        gs2::optional<StringHolder> metadata;
        /** クエストの内容 */
        gs2::optional<List<EzContents>> contents;
        /** 挑戦可能な期間を指定するイベントマスター のGRN */
        gs2::optional<StringHolder> challengePeriodEventId;
        /** クエストの参加料 */
        gs2::optional<List<EzConsumeAction>> consumeActions;
        /** クエスト失敗時の報酬 */
        gs2::optional<List<EzAcquireAction>> failedAcquireActions;
        /** クエストに挑戦するためにクリアしておく必要のあるクエスト名 */
        gs2::optional<List<StringHolder>> premiseQuestNames;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::quest::QuestModel& questModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzQuestModel() = default;
    EzQuestModel(const EzQuestModel& ezQuestModel) = default;
    EzQuestModel(EzQuestModel&& ezQuestModel) = default;
    ~EzQuestModel() = default;

    EzQuestModel(gs2::quest::QuestModel questModel);

    EzQuestModel& operator=(const EzQuestModel& ezQuestModel) = default;
    EzQuestModel& operator=(EzQuestModel&& ezQuestModel) = default;

    EzQuestModel deepCopy() const;

    gs2::quest::QuestModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getQuestModelId() const
    {
        return *ensureData().questModelId;
    }

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const List<EzContents>& getContents() const
    {
        return *ensureData().contents;
    }

    const StringHolder& getChallengePeriodEventId() const
    {
        return *ensureData().challengePeriodEventId;
    }

    const List<EzConsumeAction>& getConsumeActions() const
    {
        return *ensureData().consumeActions;
    }

    const List<EzAcquireAction>& getFailedAcquireActions() const
    {
        return *ensureData().failedAcquireActions;
    }

    const List<StringHolder>& getPremiseQuestNames() const
    {
        return *ensureData().premiseQuestNames;
    }

    // ========================================
    //   Setters
    // ========================================

    void setQuestModelId(StringHolder questModelId)
    {
        ensureData().questModelId = std::move(questModelId);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setContents(List<EzContents> contents)
    {
        ensureData().contents = std::move(contents);
    }

    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId = std::move(challengePeriodEventId);
    }

    void setConsumeActions(List<EzConsumeAction> consumeActions)
    {
        ensureData().consumeActions = std::move(consumeActions);
    }

    void setFailedAcquireActions(List<EzAcquireAction> failedAcquireActions)
    {
        ensureData().failedAcquireActions = std::move(failedAcquireActions);
    }

    void setPremiseQuestNames(List<StringHolder> premiseQuestNames)
    {
        ensureData().premiseQuestNames = std::move(premiseQuestNames);
    }

    EzQuestModel& withQuestModelId(StringHolder questModelId)
    {
        setQuestModelId(std::move(questModelId));
        return *this;
    }

    EzQuestModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzQuestModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzQuestModel& withContents(List<EzContents> contents)
    {
        setContents(std::move(contents));
        return *this;
    }

    EzQuestModel& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        setChallengePeriodEventId(std::move(challengePeriodEventId));
        return *this;
    }

    EzQuestModel& withConsumeActions(List<EzConsumeAction> consumeActions)
    {
        setConsumeActions(std::move(consumeActions));
        return *this;
    }

    EzQuestModel& withFailedAcquireActions(List<EzAcquireAction> failedAcquireActions)
    {
        setFailedAcquireActions(std::move(failedAcquireActions));
        return *this;
    }

    EzQuestModel& withPremiseQuestNames(List<StringHolder> premiseQuestNames)
    {
        setPremiseQuestNames(std::move(premiseQuestNames));
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZQUESTMODEL_HPP_