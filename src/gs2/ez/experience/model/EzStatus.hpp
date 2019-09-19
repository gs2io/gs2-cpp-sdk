

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** 経験値の種類の名前 */
        gs2::optional<StringHolder> experienceName;
        /** プロパティID */
        gs2::optional<StringHolder> propertyId;
        /** 累計獲得経験値 */
        gs2::optional<Int64> experienceValue;
        /** 現在のランク */
        gs2::optional<Int64> rankValue;
        /** 現在のランクキャップ */
        gs2::optional<Int64> rankCapValue;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            experienceName(data.experienceName),
            propertyId(data.propertyId),
            experienceValue(data.experienceValue),
            rankValue(data.rankValue),
            rankCapValue(data.rankCapValue)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::experience::Status& status) :
            experienceName(status.getExperienceName()),
            propertyId(status.getPropertyId()),
            experienceValue(status.getExperienceValue() ? *status.getExperienceValue() : 0),
            rankValue(status.getRankValue() ? *status.getRankValue() : 0),
            rankCapValue(status.getRankCapValue() ? *status.getRankCapValue() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzStatus() = default;
    EzStatus(const EzStatus& ezStatus) = default;
    EzStatus(EzStatus&& ezStatus) = default;
    ~EzStatus() = default;

    EzStatus(gs2::experience::Status status) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(status)
    {}

    EzStatus& operator=(const EzStatus& ezStatus) = default;
    EzStatus& operator=(EzStatus&& ezStatus) = default;

    EzStatus deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzStatus);
    }

    gs2::experience::Status ToModel() const
    {
        gs2::experience::Status status;
        status.setExperienceName(getExperienceName());
        status.setPropertyId(getPropertyId());
        status.setExperienceValue(getExperienceValue());
        status.setRankValue(getRankValue());
        status.setRankCapValue(getRankCapValue());
        return status;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getExperienceName() const
    {
        return *ensureData().experienceName;
    }

    const StringHolder& getPropertyId() const
    {
        return *ensureData().propertyId;
    }

    Int64 getExperienceValue() const
    {
        return *ensureData().experienceValue;
    }

    Int64 getRankValue() const
    {
        return *ensureData().rankValue;
    }

    Int64 getRankCapValue() const
    {
        return *ensureData().rankCapValue;
    }

    // ========================================
    //   Setters
    // ========================================

    void setExperienceName(StringHolder experienceName)
    {
        ensureData().experienceName = std::move(experienceName);
    }

    void setPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId = std::move(propertyId);
    }

    void setExperienceValue(Int64 experienceValue)
    {
        ensureData().experienceValue = experienceValue;
    }

    void setRankValue(Int64 rankValue)
    {
        ensureData().rankValue = rankValue;
    }

    void setRankCapValue(Int64 rankCapValue)
    {
        ensureData().rankCapValue = rankCapValue;
    }

    EzStatus& withExperienceName(StringHolder experienceName)
    {
        setExperienceName(std::move(experienceName));
        return *this;
    }

    EzStatus& withPropertyId(StringHolder propertyId)
    {
        setPropertyId(std::move(propertyId));
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