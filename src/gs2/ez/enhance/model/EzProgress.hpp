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

#ifndef GS2_EZ_ENHANCE_MODEL_EZPROGRESS_HPP_
#define GS2_EZ_ENHANCE_MODEL_EZPROGRESS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace enhance {

class Progress;

}

namespace ez { namespace enhance {

class EzProgress : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 強化実行 */
        StringHolder progressId;
        /** レートモデル名 */
        StringHolder rateName;
        /** 強化対象のプロパティID */
        StringHolder propertyId;
        /** 入手できる経験値 */
        Int32 experienceValue;
        /** 経験値倍率 */
        Float rate;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::enhance::Progress& progress);
        Data(const gs2::optional<gs2::enhance::Progress>& progress);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzProgress() = default;
    EzProgress(const EzProgress& ezProgress) = default;
    EzProgress(EzProgress&& ezProgress) = default;
    ~EzProgress() = default;

    EzProgress(gs2::enhance::Progress progress);
    EzProgress(gs2::optional<gs2::enhance::Progress> progress);

    EzProgress& operator=(const EzProgress& ezProgress) = default;
    EzProgress& operator=(EzProgress&& ezProgress) = default;

    EzProgress deepCopy() const;

    gs2::enhance::Progress ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getProgressId() const
    {
        return ensureData().progressId;
    }

    const StringHolder& getRateName() const
    {
        return ensureData().rateName;
    }

    const StringHolder& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    Int32 getExperienceValue() const
    {
        return ensureData().experienceValue;
    }

    Float getRate() const
    {
        return ensureData().rate;
    }

    // ========================================
    //   Setters
    // ========================================

    void setProgressId(StringHolder progressId)
    {
        ensureData().progressId = std::move(progressId);
    }

    void setRateName(StringHolder rateName)
    {
        ensureData().rateName = std::move(rateName);
    }

    void setPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId = std::move(propertyId);
    }

    void setExperienceValue(Int32 experienceValue)
    {
        ensureData().experienceValue = experienceValue;
    }

    void setRate(Float rate)
    {
        ensureData().rate = rate;
    }

    EzProgress& withProgressId(StringHolder progressId)
    {
        setProgressId(std::move(progressId));
        return *this;
    }

    EzProgress& withRateName(StringHolder rateName)
    {
        setRateName(std::move(rateName));
        return *this;
    }

    EzProgress& withPropertyId(StringHolder propertyId)
    {
        setPropertyId(std::move(propertyId));
        return *this;
    }

    EzProgress& withExperienceValue(Int32 experienceValue)
    {
        setExperienceValue(experienceValue);
        return *this;
    }

    EzProgress& withRate(Float rate)
    {
        setRate(rate);
        return *this;
    }
};

}}}

#endif //GS2_EZ_ENHANCE_EZPROGRESS_HPP_