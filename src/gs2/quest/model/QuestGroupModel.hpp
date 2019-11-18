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

#ifndef GS2_QUEST_MODEL_QUESTGROUPMODEL_HPP_
#define GS2_QUEST_MODEL_QUESTGROUPMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "QuestModel.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace quest {

/**
 * クエストグループ
 *
 * @author Game Server Services, Inc.
 *
 */
class QuestGroupModel : public Gs2Object
{
    friend bool operator!=(const QuestGroupModel& lhs, const QuestGroupModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエストグループ */
        optional<StringHolder> questGroupModelId;
        /** クエストグループ名 */
        optional<StringHolder> name;
        /** クエストグループのメタデータ */
        optional<StringHolder> metadata;
        /** グループに属するクエスト */
        optional<List<QuestModel>> quests;
        /** 挑戦可能な期間を指定するイベントマスター のGRN */
        optional<StringHolder> challengePeriodEventId;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            questGroupModelId(data.questGroupModelId),
            name(data.name),
            metadata(data.metadata),
            challengePeriodEventId(data.challengePeriodEventId)
        {
            if (data.quests)
            {
                quests = data.quests->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "questGroupModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->questGroupModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "quests") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->quests.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        QuestModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->quests, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name_, "challengePeriodEventId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->challengePeriodEventId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    QuestGroupModel() = default;
    QuestGroupModel(const QuestGroupModel& questGroupModel) = default;
    QuestGroupModel(QuestGroupModel&& questGroupModel) = default;
    ~QuestGroupModel() = default;

    QuestGroupModel& operator=(const QuestGroupModel& questGroupModel) = default;
    QuestGroupModel& operator=(QuestGroupModel&& questGroupModel) = default;

    QuestGroupModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(QuestGroupModel);
    }

    const QuestGroupModel* operator->() const
    {
        return this;
    }

    QuestGroupModel* operator->()
    {
        return this;
    }
    /**
     * クエストグループを取得
     *
     * @return クエストグループ
     */
    const optional<StringHolder>& getQuestGroupModelId() const
    {
        return ensureData().questGroupModelId;
    }

    /**
     * クエストグループを設定
     *
     * @param questGroupModelId クエストグループ
     */
    void setQuestGroupModelId(StringHolder questGroupModelId)
    {
        ensureData().questGroupModelId.emplace(std::move(questGroupModelId));
    }

    /**
     * クエストグループを設定
     *
     * @param questGroupModelId クエストグループ
     */
    QuestGroupModel& withQuestGroupModelId(StringHolder questGroupModelId)
    {
        setQuestGroupModelId(std::move(questGroupModelId));
        return *this;
    }

    /**
     * クエストグループ名を取得
     *
     * @return クエストグループ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * クエストグループ名を設定
     *
     * @param name クエストグループ名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * クエストグループ名を設定
     *
     * @param name クエストグループ名
     */
    QuestGroupModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * クエストグループのメタデータを取得
     *
     * @return クエストグループのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * クエストグループのメタデータを設定
     *
     * @param metadata クエストグループのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * クエストグループのメタデータを設定
     *
     * @param metadata クエストグループのメタデータ
     */
    QuestGroupModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * グループに属するクエストを取得
     *
     * @return グループに属するクエスト
     */
    const optional<List<QuestModel>>& getQuests() const
    {
        return ensureData().quests;
    }

    /**
     * グループに属するクエストを設定
     *
     * @param quests グループに属するクエスト
     */
    void setQuests(List<QuestModel> quests)
    {
        ensureData().quests.emplace(std::move(quests));
    }

    /**
     * グループに属するクエストを設定
     *
     * @param quests グループに属するクエスト
     */
    QuestGroupModel& withQuests(List<QuestModel> quests)
    {
        setQuests(std::move(quests));
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
    QuestGroupModel& withChallengePeriodEventId(StringHolder challengePeriodEventId)
    {
        setChallengePeriodEventId(std::move(challengePeriodEventId));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const QuestGroupModel& lhs, const QuestGroupModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->questGroupModelId != lhr.m_pData->questGroupModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->quests != lhr.m_pData->quests)
        {
            return true;
        }
        if (lhs.m_pData->challengePeriodEventId != lhr.m_pData->challengePeriodEventId)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const QuestGroupModel& lhs, const QuestGroupModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_QUESTGROUPMODEL_HPP_