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

#ifndef GS2_EXPERIENCE_MODEL_EXPERIENCEMODELMASTER_HPP_
#define GS2_EXPERIENCE_MODEL_EXPERIENCEMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace experience {

/**
 * 経験値の種類マスター
 *
 * @author Game Server Services, Inc.
 *
 */
class ExperienceModelMaster : public Gs2Object
{
    friend bool operator!=(const ExperienceModelMaster& lhs, const ExperienceModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 経験値の種類マスター */
        optional<StringHolder> experienceModelId;
        /** 経験値の種類名 */
        optional<StringHolder> name;
        /** 経験値の種類マスターの説明 */
        optional<StringHolder> description;
        /** 経験値の種類のメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の初期値 */
        optional<Int64> defaultExperience;
        /** ランクキャップの初期値 */
        optional<Int64> defaultRankCap;
        /** ランクキャップの最大値 */
        optional<Int64> maxRankCap;
        /** ランク計算に用いる */
        optional<StringHolder> rankThresholdId;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            experienceModelId(data.experienceModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            defaultExperience(data.defaultExperience),
            defaultRankCap(data.defaultRankCap),
            maxRankCap(data.maxRankCap),
            rankThresholdId(data.rankThresholdId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            experienceModelId(std::move(data.experienceModelId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            defaultExperience(std::move(data.defaultExperience)),
            defaultRankCap(std::move(data.defaultRankCap)),
            maxRankCap(std::move(data.maxRankCap)),
            rankThresholdId(std::move(data.rankThresholdId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "experienceModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "defaultExperience") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->defaultExperience = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "defaultRankCap") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->defaultRankCap = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "maxRankCap") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->maxRankCap = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "rankThresholdId") == 0) {
                if (jsonValue.IsString())
                {
                    this->rankThresholdId.emplace(jsonValue.GetString());
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
    ExperienceModelMaster() :
        m_pData(nullptr)
    {}

    ExperienceModelMaster(const ExperienceModelMaster& experienceModelMaster) :
        Gs2Object(experienceModelMaster),
        m_pData(experienceModelMaster.m_pData != nullptr ? new Data(*experienceModelMaster.m_pData) : nullptr)
    {}

    ExperienceModelMaster(ExperienceModelMaster&& experienceModelMaster) :
        Gs2Object(std::move(experienceModelMaster)),
        m_pData(experienceModelMaster.m_pData)
    {
        experienceModelMaster.m_pData = nullptr;
    }

    ~ExperienceModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ExperienceModelMaster& operator=(const ExperienceModelMaster& experienceModelMaster)
    {
        Gs2Object::operator=(experienceModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*experienceModelMaster.m_pData);

        return *this;
    }

    ExperienceModelMaster& operator=(ExperienceModelMaster&& experienceModelMaster)
    {
        Gs2Object::operator=(std::move(experienceModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = experienceModelMaster.m_pData;
        experienceModelMaster.m_pData = nullptr;

        return *this;
    }

    const ExperienceModelMaster* operator->() const
    {
        return this;
    }

    ExperienceModelMaster* operator->()
    {
        return this;
    }
    /**
     * 経験値の種類マスターを取得
     *
     * @return 経験値の種類マスター
     */
    const optional<StringHolder>& getExperienceModelId() const
    {
        return ensureData().experienceModelId;
    }

    /**
     * 経験値の種類マスターを設定
     *
     * @param experienceModelId 経験値の種類マスター
     */
    void setExperienceModelId(const Char* experienceModelId)
    {
        ensureData().experienceModelId.emplace(experienceModelId);
    }

    /**
     * 経験値の種類マスターを設定
     *
     * @param experienceModelId 経験値の種類マスター
     */
    ExperienceModelMaster& withExperienceModelId(const Char* experienceModelId)
    {
        setExperienceModelId(experienceModelId);
        return *this;
    }

    /**
     * 経験値の種類名を取得
     *
     * @return 経験値の種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 経験値の種類名を設定
     *
     * @param name 経験値の種類名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 経験値の種類名を設定
     *
     * @param name 経験値の種類名
     */
    ExperienceModelMaster& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * 経験値の種類マスターの説明を取得
     *
     * @return 経験値の種類マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 経験値の種類マスターの説明を設定
     *
     * @param description 経験値の種類マスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 経験値の種類マスターの説明を設定
     *
     * @param description 経験値の種類マスターの説明
     */
    ExperienceModelMaster& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * 経験値の種類のメタデータを取得
     *
     * @return 経験値の種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 経験値の種類のメタデータを設定
     *
     * @param metadata 経験値の種類のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 経験値の種類のメタデータを設定
     *
     * @param metadata 経験値の種類のメタデータ
     */
    ExperienceModelMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * 経験値の初期値を取得
     *
     * @return 経験値の初期値
     */
    const optional<Int64>& getDefaultExperience() const
    {
        return ensureData().defaultExperience;
    }

    /**
     * 経験値の初期値を設定
     *
     * @param defaultExperience 経験値の初期値
     */
    void setDefaultExperience(Int64 defaultExperience)
    {
        ensureData().defaultExperience.emplace(defaultExperience);
    }

    /**
     * 経験値の初期値を設定
     *
     * @param defaultExperience 経験値の初期値
     */
    ExperienceModelMaster& withDefaultExperience(Int64 defaultExperience)
    {
        setDefaultExperience(defaultExperience);
        return *this;
    }

    /**
     * ランクキャップの初期値を取得
     *
     * @return ランクキャップの初期値
     */
    const optional<Int64>& getDefaultRankCap() const
    {
        return ensureData().defaultRankCap;
    }

    /**
     * ランクキャップの初期値を設定
     *
     * @param defaultRankCap ランクキャップの初期値
     */
    void setDefaultRankCap(Int64 defaultRankCap)
    {
        ensureData().defaultRankCap.emplace(defaultRankCap);
    }

    /**
     * ランクキャップの初期値を設定
     *
     * @param defaultRankCap ランクキャップの初期値
     */
    ExperienceModelMaster& withDefaultRankCap(Int64 defaultRankCap)
    {
        setDefaultRankCap(defaultRankCap);
        return *this;
    }

    /**
     * ランクキャップの最大値を取得
     *
     * @return ランクキャップの最大値
     */
    const optional<Int64>& getMaxRankCap() const
    {
        return ensureData().maxRankCap;
    }

    /**
     * ランクキャップの最大値を設定
     *
     * @param maxRankCap ランクキャップの最大値
     */
    void setMaxRankCap(Int64 maxRankCap)
    {
        ensureData().maxRankCap.emplace(maxRankCap);
    }

    /**
     * ランクキャップの最大値を設定
     *
     * @param maxRankCap ランクキャップの最大値
     */
    ExperienceModelMaster& withMaxRankCap(Int64 maxRankCap)
    {
        setMaxRankCap(maxRankCap);
        return *this;
    }

    /**
     * ランク計算に用いるを取得
     *
     * @return ランク計算に用いる
     */
    const optional<StringHolder>& getRankThresholdId() const
    {
        return ensureData().rankThresholdId;
    }

    /**
     * ランク計算に用いるを設定
     *
     * @param rankThresholdId ランク計算に用いる
     */
    void setRankThresholdId(const Char* rankThresholdId)
    {
        ensureData().rankThresholdId.emplace(rankThresholdId);
    }

    /**
     * ランク計算に用いるを設定
     *
     * @param rankThresholdId ランク計算に用いる
     */
    ExperienceModelMaster& withRankThresholdId(const Char* rankThresholdId)
    {
        setRankThresholdId(rankThresholdId);
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
    ExperienceModelMaster& withCreatedAt(Int64 createdAt)
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
    ExperienceModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ExperienceModelMaster& lhs, const ExperienceModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->experienceModelId != lhr.m_pData->experienceModelId)
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
        if (lhs.m_pData->defaultExperience != lhr.m_pData->defaultExperience)
        {
            return true;
        }
        if (lhs.m_pData->defaultRankCap != lhr.m_pData->defaultRankCap)
        {
            return true;
        }
        if (lhs.m_pData->maxRankCap != lhr.m_pData->maxRankCap)
        {
            return true;
        }
        if (lhs.m_pData->rankThresholdId != lhr.m_pData->rankThresholdId)
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

inline bool operator==(const ExperienceModelMaster& lhs, const ExperienceModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXPERIENCE_MODEL_EXPERIENCEMODELMASTER_HPP_