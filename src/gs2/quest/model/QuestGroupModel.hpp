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
#include <gs2/core/external/optional/optional.hpp>
#include "QuestModel.hpp"
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            questGroupModelId(data.questGroupModelId),
            name(data.name),
            metadata(data.metadata),
            quests(data.quests),
            challengePeriodEventId(data.challengePeriodEventId)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            questGroupModelId(std::move(data.questGroupModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            quests(std::move(data.quests)),
            challengePeriodEventId(std::move(data.challengePeriodEventId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "questGroupModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->questGroupModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "quests") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->quests.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        QuestModel item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        detail::addToList(*this->quests, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "challengePeriodEventId") == 0) {
                if (jsonValue.IsString())
                {
                    this->challengePeriodEventId.emplace(jsonValue.GetString());
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    QuestGroupModel() :
        m_pData(nullptr)
    {}

    QuestGroupModel(const QuestGroupModel& questGroupModel) :
        Gs2Object(questGroupModel),
        m_pData(questGroupModel.m_pData != nullptr ? new Data(*questGroupModel.m_pData) : nullptr)
    {}

    QuestGroupModel(QuestGroupModel&& questGroupModel) :
        Gs2Object(std::move(questGroupModel)),
        m_pData(questGroupModel.m_pData)
    {
        questGroupModel.m_pData = nullptr;
    }

    ~QuestGroupModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    QuestGroupModel& operator=(const QuestGroupModel& questGroupModel)
    {
        Gs2Object::operator=(questGroupModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*questGroupModel.m_pData);

        return *this;
    }

    QuestGroupModel& operator=(QuestGroupModel&& questGroupModel)
    {
        Gs2Object::operator=(std::move(questGroupModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = questGroupModel.m_pData;
        questGroupModel.m_pData = nullptr;

        return *this;
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
    void setQuestGroupModelId(const Char* questGroupModelId)
    {
        ensureData().questGroupModelId.emplace(questGroupModelId);
    }

    /**
     * クエストグループを設定
     *
     * @param questGroupModelId クエストグループ
     */
    QuestGroupModel& withQuestGroupModelId(const Char* questGroupModelId)
    {
        setQuestGroupModelId(questGroupModelId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * クエストグループ名を設定
     *
     * @param name クエストグループ名
     */
    QuestGroupModel& withName(const Char* name)
    {
        setName(name);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * クエストグループのメタデータを設定
     *
     * @param metadata クエストグループのメタデータ
     */
    QuestGroupModel& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    void setQuests(const List<QuestModel>& quests)
    {
        ensureData().quests.emplace(quests);
    }

    /**
     * グループに属するクエストを設定
     *
     * @param quests グループに属するクエスト
     */
    QuestGroupModel& withQuests(const List<QuestModel>& quests)
    {
        setQuests(quests);
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
    void setChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        ensureData().challengePeriodEventId.emplace(challengePeriodEventId);
    }

    /**
     * 挑戦可能な期間を指定するイベントマスター のGRNを設定
     *
     * @param challengePeriodEventId 挑戦可能な期間を指定するイベントマスター のGRN
     */
    QuestGroupModel& withChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        setChallengePeriodEventId(challengePeriodEventId);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const QuestGroupModel& lhs, const QuestGroupModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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

bool operator==(const QuestGroupModel& lhs, const QuestGroupModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_QUESTGROUPMODEL_HPP_