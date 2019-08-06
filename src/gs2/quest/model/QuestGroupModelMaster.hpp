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

#ifndef GS2_QUEST_MODEL_QUESTGROUPMODELMASTER_HPP_
#define GS2_QUEST_MODEL_QUESTGROUPMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace quest {

/**
 * クエストグループマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class QuestGroupModelMaster : public Gs2Object
{
    friend bool operator!=(const QuestGroupModelMaster& lhs, const QuestGroupModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** クエストグループマスター */
        optional<StringHolder> questGroupModelId;
        /** クエストグループモデル名 */
        optional<StringHolder> name;
        /** クエストグループマスターの説明 */
        optional<StringHolder> description;
        /** クエストグループのメタデータ */
        optional<StringHolder> metadata;
        /** 挑戦可能な期間を指定するイベントマスター のGRN */
        optional<StringHolder> challengePeriodEventId;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            questGroupModelId(data.questGroupModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            challengePeriodEventId(data.challengePeriodEventId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            questGroupModelId(std::move(data.questGroupModelId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            challengePeriodEventId(std::move(data.challengePeriodEventId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "questGroupModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->questGroupModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "challengePeriodEventId") == 0) {
                if (jsonValue.IsString())
                {
                    this->challengePeriodEventId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    QuestGroupModelMaster() :
        m_pData(nullptr)
    {}

    QuestGroupModelMaster(const QuestGroupModelMaster& questGroupModelMaster) :
        Gs2Object(questGroupModelMaster),
        m_pData(questGroupModelMaster.m_pData != nullptr ? new Data(*questGroupModelMaster.m_pData) : nullptr)
    {}

    QuestGroupModelMaster(QuestGroupModelMaster&& questGroupModelMaster) :
        Gs2Object(std::move(questGroupModelMaster)),
        m_pData(questGroupModelMaster.m_pData)
    {
        questGroupModelMaster.m_pData = nullptr;
    }

    ~QuestGroupModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    QuestGroupModelMaster& operator=(const QuestGroupModelMaster& questGroupModelMaster)
    {
        Gs2Object::operator=(questGroupModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*questGroupModelMaster.m_pData);

        return *this;
    }

    QuestGroupModelMaster& operator=(QuestGroupModelMaster&& questGroupModelMaster)
    {
        Gs2Object::operator=(std::move(questGroupModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = questGroupModelMaster.m_pData;
        questGroupModelMaster.m_pData = nullptr;

        return *this;
    }

    const QuestGroupModelMaster* operator->() const
    {
        return this;
    }

    QuestGroupModelMaster* operator->()
    {
        return this;
    }
    /**
     * クエストグループマスターを取得
     *
     * @return クエストグループマスター
     */
    const optional<StringHolder>& getQuestGroupModelId() const
    {
        return ensureData().questGroupModelId;
    }

    /**
     * クエストグループマスターを設定
     *
     * @param questGroupModelId クエストグループマスター
     */
    void setQuestGroupModelId(const Char* questGroupModelId)
    {
        ensureData().questGroupModelId.emplace(questGroupModelId);
    }

    /**
     * クエストグループマスターを設定
     *
     * @param questGroupModelId クエストグループマスター
     */
    QuestGroupModelMaster& withQuestGroupModelId(const Char* questGroupModelId)
    {
        setQuestGroupModelId(questGroupModelId);
        return *this;
    }

    /**
     * クエストグループモデル名を取得
     *
     * @return クエストグループモデル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * クエストグループモデル名を設定
     *
     * @param name クエストグループモデル名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * クエストグループモデル名を設定
     *
     * @param name クエストグループモデル名
     */
    QuestGroupModelMaster& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * クエストグループマスターの説明を取得
     *
     * @return クエストグループマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * クエストグループマスターの説明を設定
     *
     * @param description クエストグループマスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * クエストグループマスターの説明を設定
     *
     * @param description クエストグループマスターの説明
     */
    QuestGroupModelMaster& withDescription(const Char* description)
    {
        setDescription(description);
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
    QuestGroupModelMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    QuestGroupModelMaster& withChallengePeriodEventId(const Char* challengePeriodEventId)
    {
        setChallengePeriodEventId(challengePeriodEventId);
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
    QuestGroupModelMaster& withCreatedAt(Int64 createdAt)
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
    QuestGroupModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const QuestGroupModelMaster& lhs, const QuestGroupModelMaster& lhr)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->challengePeriodEventId != lhr.m_pData->challengePeriodEventId)
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

inline bool operator==(const QuestGroupModelMaster& lhs, const QuestGroupModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_QUEST_MODEL_QUESTGROUPMODELMASTER_HPP_