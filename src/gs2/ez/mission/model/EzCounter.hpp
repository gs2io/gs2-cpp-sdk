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

#ifndef GS2_EZ_MISSION_MODEL_EZCOUNTER_HPP_
#define GS2_EZ_MISSION_MODEL_EZCOUNTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzScopedValue.hpp"
#include <memory>


namespace gs2 {

namespace mission {

class Counter;

}

namespace ez { namespace mission {

class EzCounter : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** カウンター名 */
        StringHolder name;
        /** 値 */
        List<EzScopedValue> values;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::mission::Counter& counter);
        Data(const gs2::optional<gs2::mission::Counter>& counter);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzCounter() = default;
    EzCounter(const EzCounter& ezCounter) = default;
    EzCounter(EzCounter&& ezCounter) = default;
    ~EzCounter() = default;

    EzCounter(gs2::mission::Counter counter);
    EzCounter(gs2::optional<gs2::mission::Counter> counter);

    EzCounter& operator=(const EzCounter& ezCounter) = default;
    EzCounter& operator=(EzCounter&& ezCounter) = default;

    EzCounter deepCopy() const;

    gs2::mission::Counter ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const List<EzScopedValue>& getValues() const
    {
        return ensureData().values;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setValues(List<EzScopedValue> values)
    {
        ensureData().values = std::move(values);
    }

    EzCounter& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzCounter& withValues(List<EzScopedValue> values)
    {
        setValues(std::move(values));
        return *this;
    }
};

}}}

#endif //GS2_EZ_MISSION_EZCOUNTER_HPP_