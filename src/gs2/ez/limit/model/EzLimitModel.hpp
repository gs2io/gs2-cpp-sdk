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

#ifndef GS2_EZ_LIMIT_MODEL_EZLIMITMODEL_HPP_
#define GS2_EZ_LIMIT_MODEL_EZLIMITMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace limit {

class LimitModel;

}

namespace ez { namespace limit {

class EzLimitModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 回数制限の種類 */
        StringHolder limitModelId;
        /** 回数制限の種類名 */
        StringHolder name;
        /** 回数制限の種類のメタデータ */
        StringHolder metadata;
        /** リセットタイミング */
        StringHolder resetType;
        /** リセットをする日にち */
        Int32 resetDayOfMonth;
        /** リセットする曜日 */
        StringHolder resetDayOfWeek;
        /** リセット時刻 */
        Int32 resetHour;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::limit::LimitModel& limitModel);
        Data(const gs2::optional<gs2::limit::LimitModel>& limitModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzLimitModel() = default;
    EzLimitModel(const EzLimitModel& ezLimitModel) = default;
    EzLimitModel(EzLimitModel&& ezLimitModel) = default;
    ~EzLimitModel() = default;

    EzLimitModel(gs2::limit::LimitModel limitModel);
    EzLimitModel(gs2::optional<gs2::limit::LimitModel> limitModel);

    EzLimitModel& operator=(const EzLimitModel& ezLimitModel) = default;
    EzLimitModel& operator=(EzLimitModel&& ezLimitModel) = default;

    EzLimitModel deepCopy() const;

    gs2::limit::LimitModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getLimitModelId() const
    {
        return ensureData().limitModelId;
    }

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return ensureData().metadata;
    }

    const StringHolder& getResetType() const
    {
        return ensureData().resetType;
    }

    Int32 getResetDayOfMonth() const
    {
        return ensureData().resetDayOfMonth;
    }

    const StringHolder& getResetDayOfWeek() const
    {
        return ensureData().resetDayOfWeek;
    }

    Int32 getResetHour() const
    {
        return ensureData().resetHour;
    }

    // ========================================
    //   Setters
    // ========================================

    void setLimitModelId(StringHolder limitModelId)
    {
        ensureData().limitModelId = std::move(limitModelId);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setResetType(StringHolder resetType)
    {
        ensureData().resetType = std::move(resetType);
    }

    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        ensureData().resetDayOfMonth = resetDayOfMonth;
    }

    void setResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        ensureData().resetDayOfWeek = std::move(resetDayOfWeek);
    }

    void setResetHour(Int32 resetHour)
    {
        ensureData().resetHour = resetHour;
    }

    EzLimitModel& withLimitModelId(StringHolder limitModelId)
    {
        setLimitModelId(std::move(limitModelId));
        return *this;
    }

    EzLimitModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzLimitModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzLimitModel& withResetType(StringHolder resetType)
    {
        setResetType(std::move(resetType));
        return *this;
    }

    EzLimitModel& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        setResetDayOfMonth(resetDayOfMonth);
        return *this;
    }

    EzLimitModel& withResetDayOfWeek(StringHolder resetDayOfWeek)
    {
        setResetDayOfWeek(std::move(resetDayOfWeek));
        return *this;
    }

    EzLimitModel& withResetHour(Int32 resetHour)
    {
        setResetHour(resetHour);
        return *this;
    }
};

}}}

#endif //GS2_EZ_LIMIT_EZLIMITMODEL_HPP_