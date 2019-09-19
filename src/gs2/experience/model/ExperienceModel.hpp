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

#ifndef GS2_EXPERIENCE_MODEL_EXPERIENCEMODEL_HPP_
#define GS2_EXPERIENCE_MODEL_EXPERIENCEMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Threshold.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace experience {

/**
 * 経験値・ランクアップ閾値モデル
 *
 * @author Game Server Services, Inc.
 *
 */
class ExperienceModel : public Gs2Object
{
    friend bool operator!=(const ExperienceModel& lhs, const ExperienceModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 経験値の種類マスター */
        optional<StringHolder> experienceModelId;
        /** 経験値の種類名 */
        optional<StringHolder> name;
        /** 経験値の種類のメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の初期値 */
        optional<Int64> defaultExperience;
        /** ランクキャップの初期値 */
        optional<Int64> defaultRankCap;
        /** ランクキャップの最大値 */
        optional<Int64> maxRankCap;
        /** ランクアップ閾値 */
        optional<Threshold> rankThreshold;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            experienceModelId(data.experienceModelId),
            name(data.name),
            metadata(data.metadata),
            defaultExperience(data.defaultExperience),
            defaultRankCap(data.defaultRankCap),
            maxRankCap(data.maxRankCap)
        {
            if (data.rankThreshold)
            {
                rankThreshold = data.rankThreshold->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "experienceModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->experienceModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "defaultExperience") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->defaultExperience = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "defaultRankCap") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->defaultRankCap = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "maxRankCap") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->maxRankCap = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "rankThreshold") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->rankThreshold.emplace();
                    detail::json::JsonParser::parse(&this->rankThreshold->getModel(), jsonObject);
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    ExperienceModel() = default;
    ExperienceModel(const ExperienceModel& experienceModel) = default;
    ExperienceModel(ExperienceModel&& experienceModel) = default;
    ~ExperienceModel() = default;

    ExperienceModel& operator=(const ExperienceModel& experienceModel) = default;
    ExperienceModel& operator=(ExperienceModel&& experienceModel) = default;

    ExperienceModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(ExperienceModel);
    }

    const ExperienceModel* operator->() const
    {
        return this;
    }

    ExperienceModel* operator->()
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
    void setExperienceModelId(StringHolder experienceModelId)
    {
        ensureData().experienceModelId.emplace(std::move(experienceModelId));
    }

    /**
     * 経験値の種類マスターを設定
     *
     * @param experienceModelId 経験値の種類マスター
     */
    ExperienceModel& withExperienceModelId(StringHolder experienceModelId)
    {
        setExperienceModelId(std::move(experienceModelId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 経験値の種類名を設定
     *
     * @param name 経験値の種類名
     */
    ExperienceModel& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 経験値の種類のメタデータを設定
     *
     * @param metadata 経験値の種類のメタデータ
     */
    ExperienceModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    ExperienceModel& withDefaultExperience(Int64 defaultExperience)
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
    ExperienceModel& withDefaultRankCap(Int64 defaultRankCap)
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
    ExperienceModel& withMaxRankCap(Int64 maxRankCap)
    {
        setMaxRankCap(maxRankCap);
        return *this;
    }

    /**
     * ランクアップ閾値を取得
     *
     * @return ランクアップ閾値
     */
    const optional<Threshold>& getRankThreshold() const
    {
        return ensureData().rankThreshold;
    }

    /**
     * ランクアップ閾値を設定
     *
     * @param rankThreshold ランクアップ閾値
     */
    void setRankThreshold(Threshold rankThreshold)
    {
        ensureData().rankThreshold.emplace(std::move(rankThreshold));
    }

    /**
     * ランクアップ閾値を設定
     *
     * @param rankThreshold ランクアップ閾値
     */
    ExperienceModel& withRankThreshold(Threshold rankThreshold)
    {
        setRankThreshold(std::move(rankThreshold));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const ExperienceModel& lhs, const ExperienceModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
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
        if (lhs.m_pData->rankThreshold != lhr.m_pData->rankThreshold)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const ExperienceModel& lhs, const ExperienceModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_EXPERIENCE_MODEL_EXPERIENCEMODEL_HPP_