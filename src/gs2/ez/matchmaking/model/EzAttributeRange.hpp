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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZATTRIBUTERANGE_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZATTRIBUTERANGE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace matchmaking {

class AttributeRange;

}

namespace ez { namespace matchmaking {

class EzAttributeRange : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 属性名 */
        StringHolder name;
        /** ギャザリング参加可能な属性値の最小値 */
        Int32 min;
        /** ギャザリング参加可能な属性値の最大値 */
        Int32 max;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::matchmaking::AttributeRange& attributeRange);
        Data(const gs2::optional<gs2::matchmaking::AttributeRange>& attributeRange);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzAttributeRange() = default;
    EzAttributeRange(const EzAttributeRange& ezAttributeRange) = default;
    EzAttributeRange(EzAttributeRange&& ezAttributeRange) = default;
    ~EzAttributeRange() = default;

    EzAttributeRange(gs2::matchmaking::AttributeRange attributeRange);
    EzAttributeRange(gs2::optional<gs2::matchmaking::AttributeRange> attributeRange);

    EzAttributeRange& operator=(const EzAttributeRange& ezAttributeRange) = default;
    EzAttributeRange& operator=(EzAttributeRange&& ezAttributeRange) = default;

    EzAttributeRange deepCopy() const;

    gs2::matchmaking::AttributeRange ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    Int32 getMin() const
    {
        return ensureData().min;
    }

    Int32 getMax() const
    {
        return ensureData().max;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMin(Int32 min)
    {
        ensureData().min = min;
    }

    void setMax(Int32 max)
    {
        ensureData().max = max;
    }

    EzAttributeRange& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzAttributeRange& withMin(Int32 min)
    {
        setMin(min);
        return *this;
    }

    EzAttributeRange& withMax(Int32 max)
    {
        setMax(max);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZATTRIBUTERANGE_HPP_