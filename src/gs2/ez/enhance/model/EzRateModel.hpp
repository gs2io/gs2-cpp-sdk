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

#ifndef GS2_EZ_ENHANCE_MODEL_EZRATEMODEL_HPP_
#define GS2_EZ_ENHANCE_MODEL_EZRATEMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace enhance {

class RateModel;

}

namespace ez { namespace enhance {

class EzRateModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 強化レート名 */
        gs2::optional<StringHolder> name;
        /** 強化レートのメタデータ */
        gs2::optional<StringHolder> metadata;
        /** 強化素材に使用できるインベントリ のGRN */
        gs2::optional<StringHolder> materialInventoryId;
        /** 獲得できる経験値の種類マスター のGRN */
        gs2::optional<StringHolder> experienceModelId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::enhance::RateModel& rateModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRateModel() = default;
    EzRateModel(const EzRateModel& ezRateModel) = default;
    EzRateModel(EzRateModel&& ezRateModel) = default;
    ~EzRateModel() = default;

    EzRateModel(gs2::enhance::RateModel rateModel);

    EzRateModel& operator=(const EzRateModel& ezRateModel) = default;
    EzRateModel& operator=(EzRateModel&& ezRateModel) = default;

    EzRateModel deepCopy() const;

    gs2::enhance::RateModel ToModel() const;

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

    const StringHolder& getMaterialInventoryId() const
    {
        return *ensureData().materialInventoryId;
    }

    const StringHolder& getExperienceModelId() const
    {
        return *ensureData().experienceModelId;
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

    void setMaterialInventoryId(StringHolder materialInventoryId)
    {
        ensureData().materialInventoryId = std::move(materialInventoryId);
    }

    void setExperienceModelId(StringHolder experienceModelId)
    {
        ensureData().experienceModelId = std::move(experienceModelId);
    }

    EzRateModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzRateModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzRateModel& withMaterialInventoryId(StringHolder materialInventoryId)
    {
        setMaterialInventoryId(std::move(materialInventoryId));
        return *this;
    }

    EzRateModel& withExperienceModelId(StringHolder experienceModelId)
    {
        setExperienceModelId(std::move(experienceModelId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_ENHANCE_EZRATEMODEL_HPP_