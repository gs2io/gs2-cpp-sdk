

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

#ifndef GS2_EZ_EXPERIENCE_MODEL_EZSTATUS_HPP_
#define GS2_EZ_EXPERIENCE_MODEL_EZSTATUS_HPP_

#include <gs2/experience/model/Status.hpp>


namespace gs2 { namespace ez { namespace experience {

class EzStatus : public gs2::Gs2Object
{
private:
    /** 経験値の種類の名前 */
    gs2::optional<StringHolder> m_ExperienceName;
    /** プロパティID */
    gs2::optional<StringHolder> m_PropertyId;
    /** 累計獲得経験値 */
    gs2::optional<Int64> m_ExperienceValue;
    /** 現在のランク */
    gs2::optional<Int64> m_RankValue;
    /** 現在のランクキャップ */
    gs2::optional<Int64> m_RankCapValue;

public:
    EzStatus() = default;

    EzStatus(gs2::experience::Status status) :
        m_ExperienceName(status.getExperienceName()),
        m_PropertyId(status.getPropertyId()),
        m_ExperienceValue(status.getExperienceValue() ? *status.getExperienceValue() : 0),
        m_RankValue(status.getRankValue() ? *status.getRankValue() : 0),
        m_RankCapValue(status.getRankCapValue() ? *status.getRankCapValue() : 0)
    {
    }

    gs2::experience::Status ToModel() const
    {
        gs2::experience::Status status;
        status.setExperienceName(*m_ExperienceName);
        status.setPropertyId(*m_PropertyId);
        status.setExperienceValue(*m_ExperienceValue);
        status.setRankValue(*m_RankValue);
        status.setRankCapValue(*m_RankCapValue);
        return status;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getExperienceName() const
    {
        return *m_ExperienceName;
    }

    gs2::StringHolder& getExperienceName()
    {
        return *m_ExperienceName;
    }

    const gs2::StringHolder& getPropertyId() const
    {
        return *m_PropertyId;
    }

    gs2::StringHolder& getPropertyId()
    {
        return *m_PropertyId;
    }

    Int64 getExperienceValue() const
    {
        return *m_ExperienceValue;
    }

    Int64 getRankValue() const
    {
        return *m_RankValue;
    }

    Int64 getRankCapValue() const
    {
        return *m_RankCapValue;
    }

    // ========================================
    //   Setters
    // ========================================

    void setExperienceName(Char* experienceName)
    {
        m_ExperienceName.emplace(experienceName);
    }

    void setPropertyId(Char* propertyId)
    {
        m_PropertyId.emplace(propertyId);
    }

    void setExperienceValue(Int64 experienceValue)
    {
        m_ExperienceValue = experienceValue;
    }

    void setRankValue(Int64 rankValue)
    {
        m_RankValue = rankValue;
    }

    void setRankCapValue(Int64 rankCapValue)
    {
        m_RankCapValue = rankCapValue;
    }

    EzStatus& withExperienceName(Char* experienceName)
    {
        setExperienceName(experienceName);
        return *this;
    }

    EzStatus& withPropertyId(Char* propertyId)
    {
        setPropertyId(propertyId);
        return *this;
    }

    EzStatus& withExperienceValue(Int64 experienceValue)
    {
        setExperienceValue(experienceValue);
        return *this;
    }

    EzStatus& withRankValue(Int64 rankValue)
    {
        setRankValue(rankValue);
        return *this;
    }

    EzStatus& withRankCapValue(Int64 rankCapValue)
    {
        setRankCapValue(rankCapValue);
        return *this;
    }
};

}}}

#endif //GS2_EZ_EXPERIENCE_EZSTATUS_HPP_