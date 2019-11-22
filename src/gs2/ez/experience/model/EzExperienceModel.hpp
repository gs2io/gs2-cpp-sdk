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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzThreshold.hpp"
#include <memory>


namespace gs2 {

namespace experience {

class ExperienceModel;

}

namespace ez { namespace experience {

class EzExperienceModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 経験値の種類名 */
        gs2::optional<StringHolder> name;
        /** 経験値の種類のメタデータ */
        gs2::optional<StringHolder> metadata;
        /** 経験値の初期値 */
        gs2::optional<Int64> defaultExperience;
        /** ランクキャップの初期値 */
        gs2::optional<Int64> defaultRankCap;
        /** ランクキャップの最大値 */
        gs2::optional<Int64> maxRankCap;
        /** ランクアップ閾値 */
        gs2::optional<EzThreshold> rankThreshold;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::experience::ExperienceModel& experienceModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzExperienceModel() = default;
    EzExperienceModel(const EzExperienceModel& ezExperienceModel) = default;
    EzExperienceModel(EzExperienceModel&& ezExperienceModel) = default;
    ~EzExperienceModel() = default;

    EzExperienceModel(gs2::experience::ExperienceModel experienceModel);

    EzExperienceModel& operator=(const EzExperienceModel& ezExperienceModel) = default;
    EzExperienceModel& operator=(EzExperienceModel&& ezExperienceModel) = default;

    EzExperienceModel deepCopy() const;

    gs2::experience::ExperienceModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    Int64 getDefaultExperience() const
    {
        return *ensureData().defaultExperience;
    }

    Int64 getDefaultRankCap() const
    {
        return *ensureData().defaultRankCap;
    }

    Int64 getMaxRankCap() const
    {
        return *ensureData().maxRankCap;
    }

    const EzThreshold& getRankThreshold() const
    {
        return *ensureData().rankThreshold;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setDefaultExperience(Int64 defaultExperience)
    {
        ensureData().defaultExperience = defaultExperience;
    }

    void setDefaultRankCap(Int64 defaultRankCap)
    {
        ensureData().defaultRankCap = defaultRankCap;
    }

    void setMaxRankCap(Int64 maxRankCap)
    {
        ensureData().maxRankCap = maxRankCap;
    }

    void setRankThreshold(EzThreshold rankThreshold)
    {
        ensureData().rankThreshold = std::move(rankThreshold);
    }

    EzExperienceModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzExperienceModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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

    EzExperienceModel& withRankThreshold(EzThreshold rankThreshold)
    {
        setRankThreshold(std::move(rankThreshold));
        return *this;
    }
};

}}}

#endif //GS2_EZ_EXPERIENCE_EZEXPERIENCEMODEL_HPP_