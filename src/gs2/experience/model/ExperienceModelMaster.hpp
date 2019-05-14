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

namespace gs2 { namespace  {

/**
 * 経験値の種類
 *
 * @author Game Server Services, Inc.
 *
 */
class ExperienceModelMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 経験値の種類 のGRN */
        optional<StringHolder> experienceModelId;
        /** 経験値の種類名 */
        optional<StringHolder> name;
        /** 経験値の種類の説明 */
        optional<StringHolder> description;
        /** 経験値の種類のメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の初期値 */
        
        optional<Int64> defaultExperience;
        /** ランクキャップの初期値 */
        
        optional<Int64> defaultRankCap;
        /** ランクキャップの最大値 */
        
        optional<Int64> maxRankCap;
        /** ランク計算に用いるランクアップ閾値 のGRN */
        optional<StringHolder> rankThresholdId;
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** 最終更新日時 */
        
        optional<Int64> updateAt;

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
            createAt(data.createAt),
            updateAt(data.updateAt)
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
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "experienceModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "defaultExperience") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->defaultExperience = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "defaultRankCap") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->defaultRankCap = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "maxRankCap") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->maxRankCap = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "rankThresholdId") == 0) {
                if (jsonValue.IsString())
                {
                    this->rankThresholdId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
     * 経験値の種類 のGRNを取得
     *
     * @return 経験値の種類 のGRN
     */
    const optional<StringHolder>& getExperienceModelId() const
    {
        return ensureData().experienceModelId;
    }

    /**
     * 経験値の種類 のGRNを設定
     *
     * @param experienceModelId 経験値の種類 のGRN
     */
    void setExperienceModelId(const Char* experienceModelId)
    {
        ensureData().experienceModelId.emplace(experienceModelId);
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
     * 経験値の種類の説明を取得
     *
     * @return 経験値の種類の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 経験値の種類の説明を設定
     *
     * @param description 経験値の種類の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
     * ランク計算に用いるランクアップ閾値 のGRNを取得
     *
     * @return ランク計算に用いるランクアップ閾値 のGRN
     */
    const optional<StringHolder>& getRankThresholdId() const
    {
        return ensureData().rankThresholdId;
    }

    /**
     * ランク計算に用いるランクアップ閾値 のGRNを設定
     *
     * @param rankThresholdId ランク計算に用いるランクアップ閾値 のGRN
     */
    void setRankThresholdId(const Char* rankThresholdId)
    {
        ensureData().rankThresholdId.emplace(rankThresholdId);
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_EXPERIENCE_MODEL_EXPERIENCEMODELMASTER_HPP_