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

#ifndef GS2_QUEST_MODEL_QUESTMODELMASTER_HPP_
#define GS2_QUEST_MODEL_QUESTMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Contents.hpp"
#include "ConsumeAction.hpp"
#include "AcquireAction.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace quest {

/**
 * クエストモデルマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class QuestModelMaster : public Gs2Object
{
    friend bool operator!=(const QuestModelMaster& lhs, const QuestModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエストモデルマスター */
        optional<StringHolder> questModelId;
        /** クエストモデル名 */
        optional<StringHolder> questGroupName;
        /** クエスト名 */
        optional<StringHolder> name;
        /** クエストモデルの説明 */
        optional<StringHolder> description;
        /** クエストのメタデータ */
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
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            questModelId(data.questModelId),
            questGroupName(data.questGroupName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            challengePeriodEventId(data.challengePeriodEventId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.contents)
            {
                contents = data.contents->deepCopy();
            }
            if (data.consumeActions)
            {
                consumeActions = data.consumeActions->deepCopy();
            }
            if (data.failedAcquireActions)
            {
                failedAcquireActions = data.failedAcquireActions->deepCopy();
            }
            if (data.premiseQuestNames)
            {
                premiseQuestNames = data.premiseQuestNames->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "questModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->questModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "questGroupName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->questGroupName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "contents") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->contents.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Contents item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->contents += std::move(item);
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
            else if (std::strcmp(name_, "consumeActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->consumeActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        ConsumeAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->consumeActions += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "failedAcquireActions") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->failedAcquireActions.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        AcquireAction item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->failedAcquireActions += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "premiseQuestNames") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->premiseQuestNames.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->premiseQuestNames += std::move(stringHolder);
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    QuestModelMaster() = default;
    QuestModelMaster(const QuestModelMaster& questModelMaster) = default;
    QuestModelMaster(QuestModelMaster&& questModelMaster) = default;
    ~QuestModelMaster() = default;

    QuestModelMaster& operator=(const QuestModelMaster& questModelMaster) = default;
    QuestModelMaster& operator=(QuestModelMaster&& questModelMaster) = default;

    QuestModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(QuestModelMaster);
    }

    const QuestModelMaster* operator->() const
    {
        return this;
    }

    QuestModelMaster* operator->()
    {
        return this;
    }
    /**
     * クエストモデルマスターを取得
     *
     * @return クエストモデルマスター
     */
    const optional<StringHolder>& getQuestModelId() const
    {
        return ensureData().questModelId;
    }

    /**
     * クエストモデルマスターを設定
     *
     * @param questModelId クエストモデルマスター
     */
    void setQuestModelId(StringHolder questModelId)
    {
        ensureData().questModelId.emplace(std::move(questModelId));
    }

    /**
     * クエストモデルマスターを設定
     *
     * @param questModelId クエストモデルマスター
     */
    QuestModelMaster& withQuestModelId(StringHolder questModelId)
    {
        setQuestModelId(std::move(questModelId));
        return *this;
    }

    /**
     * クエストモデル名を取得
     *
     * @return クエストモデル名
     */
    const optional<StringHolder>& getQuestGroupName() const
    {
        return ensureData().questGroupName;
    }

    /**
     * クエストモデル名を設定
     *
     * @param questGroupName クエストモデル名
     */
    void setQuestGroupName(StringHolder questGroupName)
    {
        ensureData().questGroupName.emplace(std::move(questGroupName));
    }

    /**
     * クエストモデル名を設定
     *
     * @param questGroupName クエストモデル名
     */
    QuestModelMaster& withQuestGroupName(StringHolder questGroupName)
    {
        setQuestGroupName(std::move(questGroupName));
        return *this;
    }

    /**
     * クエスト名を取得
     *
     * @return クエスト名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * クエスト名を設定
     *
     * @param name クエスト名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * クエスト名を設定
     *
     * @param name クエスト名
     */
    QuestModelMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * クエストモデルの説明を取得
     *
     * @return クエストモデルの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * クエストモデルの説明を設定
     *
     * @param description クエストモデルの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * クエストモデルの説明を設定
     *
     * @param description クエストモデルの説明
     */
    QuestModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * クエストのメタデータを取得
     *
     * @return クエストのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * クエストのメタデータを設定
     *
     * @param metadata クエストのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * クエストのメタデータを設定
     *
     * @param metadata クエストのメタデータ
     */
    QuestModelMaster& withMetadata(StringHolder metadata)
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
    QuestModelMaster& withContents(List<Contents> contents)
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
    QuestModelMaster& withChallengePeriodEventId(StringHolder challengePeriodEventId)
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
    QuestModelMaster& withConsumeActions(List<ConsumeAction> consumeActions)
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
    QuestModelMaster& withFailedAcquireActions(List<AcquireAction> failedAcquireActions)
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
    QuestModelMaster& withPremiseQuestNames(List<StringHolder> premiseQuestNames)
    {
        setPremiseQuestNames(std::move(premiseQuestNames));
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
    QuestModelMaster& withCreatedAt(Int64 createdAt)
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
    QuestModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const QuestModelMaster& lhs, const QuestModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->questModelId != lhr.m_pData->questModelId)
        {
            return true;
        }
        if (lhs.m_pData->questGroupName != lhr.m_pData->questGroupName)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
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
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const QuestModelMaster& lhs, const QuestModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_QUESTMODELMASTER_HPP_