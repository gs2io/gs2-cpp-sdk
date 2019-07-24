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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Contents.hpp"
#include "ConsumeAction.hpp"
#include "AcquireAction.hpp"
#include <cstring>

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            questModelId(data.questModelId),
            name(data.name),
            metadata(data.metadata),
            contents(data.contents),
            challengePeriodEventId(data.challengePeriodEventId),
            consumeActions(data.consumeActions),
            failedAcquireActions(data.failedAcquireActions),
            premiseQuestNames(data.premiseQuestNames)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            questModelId(std::move(data.questModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            contents(std::move(data.contents)),
            challengePeriodEventId(std::move(data.challengePeriodEventId)),
            consumeActions(std::move(data.consumeActions)),
            failedAcquireActions(std::move(data.failedAcquireActions)),
            premiseQuestNames(std::move(data.premiseQuestNames))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "questModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->questModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "contents") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->contents.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Contents item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->contents, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "challengePeriodEventId") == 0) {
                if (jsonValue.IsString())
                {
                    this->challengePeriodEventId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "consumeActions") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->consumeActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ConsumeAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->consumeActions, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "failedAcquireActions") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->failedAcquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        detail::addToList(*this->failedAcquireActions, std::move(item));
                    }
                }
            }
            else if (std::strcmp(name, "premiseQuestNames") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->premiseQuestNames.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            detail::addToList(*this->premiseQuestNames, std::move(stringHolder));
                        }
                    }
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
    QuestModel() :
        m_pData(nullptr)
    {}

    QuestModel(const QuestModel& questModel) :
        Gs2Object(questModel),
        m_pData(questModel.m_pData != nullptr ? new Data(*questModel.m_pData) : nullptr)
    {}

    QuestModel(QuestModel&& questModel) :
        Gs2Object(std::move(questModel)),
        m_pData(questModel.m_pData)
    {
        questModel.m_pData = nullptr;
    }

    ~QuestModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    QuestModel& operator=(const QuestModel& questModel)
    {
        Gs2Object::operator=(questModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*questModel.m_pData);

        return *this;
    }

    QuestModel& operator=(QuestModel&& questModel)
    {
        Gs2Object::operator=(std::move(questModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = questModel.m_pData;
        questModel.m_pData = nullptr;

        return *this;
    }

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
    void setQuestModelId(const Char* questModelId)
    {
        ensureData().questModelId.emplace(questModelId);
    }

    /**
     * クエストモデルを設定
     *
     * @param questModelId クエストモデル
     */
    QuestModel& withQuestModelId(const Char* questModelId)
    {
        setQuestModelId(questModelId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * クエストモデル名を設定
     *
     * @param name クエストモデル名
     */
    QuestModel& withName(const Char* name)
    {
        setName(name);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * クエストモデルのメタデータを設定
     *
     * @param metadata クエストモデルのメタデータ
     */
    QuestModel& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    void setContents(const List<Contents>& contents)
    {
        ensureData().contents.emplace(contents);
    }

    /**
     * クエストの内容を設定
     *
     * @param contents クエストの内容
     */
    QuestModel& withContents(const List<Contents>& contents)
    {
        setContents(contents);
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
    QuestModel& withChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        setChallengePeriodEventId(challengePeriodEventId);
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
    void setConsumeActions(const List<ConsumeAction>& consumeActions)
    {
        ensureData().consumeActions.emplace(consumeActions);
    }

    /**
     * クエストの参加料を設定
     *
     * @param consumeActions クエストの参加料
     */
    QuestModel& withConsumeActions(const List<ConsumeAction>& consumeActions)
    {
        setConsumeActions(consumeActions);
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
    void setFailedAcquireActions(const List<AcquireAction>& failedAcquireActions)
    {
        ensureData().failedAcquireActions.emplace(failedAcquireActions);
    }

    /**
     * クエスト失敗時の報酬を設定
     *
     * @param failedAcquireActions クエスト失敗時の報酬
     */
    QuestModel& withFailedAcquireActions(const List<AcquireAction>& failedAcquireActions)
    {
        setFailedAcquireActions(failedAcquireActions);
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
    void setPremiseQuestNames(const List<StringHolder>& premiseQuestNames)
    {
        ensureData().premiseQuestNames.emplace(premiseQuestNames);
    }

    /**
     * クエストに挑戦するためにクリアしておく必要のあるクエスト名を設定
     *
     * @param premiseQuestNames クエストに挑戦するためにクリアしておく必要のあるクエスト名
     */
    QuestModel& withPremiseQuestNames(const List<StringHolder>& premiseQuestNames)
    {
        setPremiseQuestNames(premiseQuestNames);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const QuestModel& lhs, const QuestModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->questModelId != lhr.m_pData->questModelId)
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
        if (lhs.m_pData->contents != lhr.m_pData->contents)
        {
            return true;
        }
        if (lhs.m_pData->challengePeriodEventId != lhr.m_pData->challengePeriodEventId)
        {
            return true;
        }
        if (lhs.m_pData->consumeActions != lhr.m_pData->consumeActions)
        {
            return true;
        }
        if (lhs.m_pData->failedAcquireActions != lhr.m_pData->failedAcquireActions)
        {
            return true;
        }
        if (lhs.m_pData->premiseQuestNames != lhr.m_pData->premiseQuestNames)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const QuestModel& lhs, const QuestModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_QUESTMODEL_HPP_