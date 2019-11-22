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

#ifndef GS2_EZ_QUEST_MODEL_EZQUESTGROUPMODEL_HPP_
#define GS2_EZ_QUEST_MODEL_EZQUESTGROUPMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzQuestModel.hpp"
#include <memory>


namespace gs2 {

namespace quest {

class QuestGroupModel;

}

namespace ez { namespace quest {

class EzQuestGroupModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** クエストグループ名 */
        gs2::optional<StringHolder> name;
        /** クエストグループのメタデータ */
        gs2::optional<StringHolder> metadata;
        /** グループに属するクエスト */
        gs2::optional<List<EzQuestModel>> quests;
        /** 挑戦可能な期間を指定するイベントマスター のGRN */
        gs2::optional<StringHolder> challengePeriodEventId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::quest::QuestGroupModel& questGroupModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzQuestGroupModel() = default;
    EzQuestGroupModel(const EzQuestGroupModel& ezQuestGroupModel) = default;
    EzQuestGroupModel(EzQuestGroupModel&& ezQuestGroupModel) = default;
    ~EzQuestGroupModel() = default;

    EzQuestGroupModel(gs2::quest::QuestGroupModel questGroupModel);

    EzQuestGroupModel& operator=(const EzQuestGroupModel& ezQuestGroupModel) = default;
    EzQuestGroupModel& operator=(EzQuestGroupModel&& ezQuestGroupModel) = default;

    EzQuestGroupModel deepCopy() const;

    gs2::quest::QuestGroupModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const List<EzQuestModel>& getQuests() const
    {
        return *ensureData().quests;
    }

    const StringHolder& getChallengePeriodEventId() const
    {
        return *ensureData().challengePeriodEventId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setQuests(List<EzQuestModel> quests)
    {
        ensureData().quests = std::move(quests);
    }

    void setChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        ensureData().challengePeriodEventId = std::move(challengePeriodEventId);
    }

    EzQuestGroupModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzQuestGroupModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzQuestGroupModel& withQuests(List<EzQuestModel> quests)
    {
        setQuests(std::move(quests));
        return *this;
    }

    EzQuestGroupModel& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        setChallengePeriodEventId(std::move(challengePeriodEventId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_QUEST_EZQUESTGROUPMODEL_HPP_