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

#ifndef GS2_EZ_MISSION_MODEL_EZSCOPEDVALUE_HPP_
#define GS2_EZ_MISSION_MODEL_EZSCOPEDVALUE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace mission {

class ScopedValue;

}

namespace ez { namespace mission {

class EzScopedValue : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** リセットタイミング */
        StringHolder resetType;
        /** カウント */
        Int64 value;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::mission::ScopedValue& scopedValue);
        Data(const gs2::optional<gs2::mission::ScopedValue>& scopedValue);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzScopedValue() = default;
    EzScopedValue(const EzScopedValue& ezScopedValue) = default;
    EzScopedValue(EzScopedValue&& ezScopedValue) = default;
    ~EzScopedValue() = default;

    EzScopedValue(gs2::mission::ScopedValue scopedValue);
    EzScopedValue(gs2::optional<gs2::mission::ScopedValue> scopedValue);

    EzScopedValue& operator=(const EzScopedValue& ezScopedValue) = default;
    EzScopedValue& operator=(EzScopedValue&& ezScopedValue) = default;

    EzScopedValue deepCopy() const;

    gs2::mission::ScopedValue ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getResetType() const
    {
        return ensureData().resetType;
    }

    Int64 getValue() const
    {
        return ensureData().value;
    }

    // ========================================
    //   Setters
    // ========================================

    void setResetType(StringHolder resetType)
    {
        ensureData().resetType = std::move(resetType);
    }

    void setValue(Int64 value)
    {
        ensureData().value = value;
    }

    EzScopedValue& withResetType(StringHolder resetType)
    {
        setResetType(std::move(resetType));
        return *this;
    }

    EzScopedValue& withValue(Int64 value)
    {
        setValue(value);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZSCOPEDVALUE_HPP_