

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

#ifndef GS2_EZ_EXPERIENCE_MODEL_EZEXPERIENCEMODEL_HPP_
#define GS2_EZ_EXPERIENCE_MODEL_EZEXPERIENCEMODEL_HPP_

#include <gs2/experience/model/ExperienceModel.hpp>
#include "EzThreshold.hpp"


namespace gs2 { namespace ez { namespace experience {

class EzExperienceModel : public gs2::Gs2Object
{
private:
    /** 経験値の種類名 */
    gs2::optional<StringHolder> m_Name;
    /** 経験値の種類のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** 経験値の初期値 */
    gs2::optional<Int64> m_DefaultExperience;
    /** ランクキャップの初期値 */
    gs2::optional<Int64> m_DefaultRankCap;
    /** ランクキャップの最大値 */
    gs2::optional<Int64> m_MaxRankCap;
    /** ランクアップ閾値 */
    gs2::optional<EzThreshold> m_RankThreshold;

public:
    EzExperienceModel() = default;

    EzExperienceModel(gs2::experience::ExperienceModel experienceModel) :
        m_Name(experienceModel.getName()),
        m_Metadata(experienceModel.getMetadata()),
        m_DefaultExperience(experienceModel.getDefaultExperience() ? *experienceModel.getDefaultExperience() : 0),
        m_DefaultRankCap(experienceModel.getDefaultRankCap() ? *experienceModel.getDefaultRankCap() : 0),
        m_MaxRankCap(experienceModel.getMaxRankCap() ? *experienceModel.getMaxRankCap() : 0),
        m_RankThreshold(*experienceModel.getRankThreshold())
    {
    }

    gs2::experience::ExperienceModel ToModel() const
    {
        gs2::experience::ExperienceModel experienceModel;
        experienceModel.setName(*m_Name);
        experienceModel.setMetadata(*m_Metadata);
        experienceModel.setDefaultExperience(*m_DefaultExperience);
        experienceModel.setDefaultRankCap(*m_DefaultRankCap);
        experienceModel.setMaxRankCap(*m_MaxRankCap);
        experienceModel.setRankThreshold(m_RankThreshold->ToModel());
        return experienceModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    Int64 getDefaultExperience() const
    {
        return *m_DefaultExperience;
    }

    Int64 getDefaultRankCap() const
    {
        return *m_DefaultRankCap;
    }

    Int64 getMaxRankCap() const
    {
        return *m_MaxRankCap;
    }

    const EzThreshold& getRankThreshold() const
    {
        return *m_RankThreshold;
    }

    EzThreshold& getRankThreshold()
    {
        return *m_RankThreshold;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setDefaultExperience(Int64 defaultExperience)
    {
        m_DefaultExperience = defaultExperience;
    }

    void setDefaultRankCap(Int64 defaultRankCap)
    {
        m_DefaultRankCap = defaultRankCap;
    }

    void setMaxRankCap(Int64 maxRankCap)
    {
        m_MaxRankCap = maxRankCap;
    }

    void setRankThreshold(const EzThreshold& rankThreshold)
    {
        m_RankThreshold = rankThreshold;
    }

    void setRankThreshold(EzThreshold&& rankThreshold)
    {
        m_RankThreshold = std::move(rankThreshold);
    }

    EzExperienceModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzExperienceModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzExperienceModel& withDefaultExperience(Int64 defaultExperience)
    {
        setDefaultExperience(defaultExperience);
        return *this;
    }

    EzExperienceModel& withDefaultRankCap(Int64 defaultRankCap)
    {
        setDefaultRankCap(defaultRankCap);
        return *this;
    }

    EzExperienceModel& withMaxRankCap(Int64 maxRankCap)
    {
        setMaxRankCap(maxRankCap);
        return *this;
    }

    EzExperienceModel& withRankThreshold(const EzThreshold& rankThreshold)
    {
        setRankThreshold(rankThreshold);
        return *this;
    }

    EzExperienceModel& withRankThreshold(EzThreshold&& rankThreshold)
    {
        setRankThreshold(std::move(rankThreshold));
        return *this;
    }
};

}}}

#endif //GS2_EZ_EXPERIENCE_EZEXPERIENCEMODEL_HPP_