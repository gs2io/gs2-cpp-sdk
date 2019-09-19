

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

#include <gs2/matchmaking/model/AttributeRange.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

class EzAttributeRange : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 属性名 */
        gs2::optional<StringHolder> name;
        /** ギャザリング参加可能な属性値の最小値 */
        gs2::optional<Int32> min;
        /** ギャザリング参加可能な属性値の最大値 */
        gs2::optional<Int32> max;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            min(data.min),
            max(data.max)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::matchmaking::AttributeRange& attributeRange) :
            name(attributeRange.getName()),
            min(attributeRange.getMin() ? *attributeRange.getMin() : 0),
            max(attributeRange.getMax() ? *attributeRange.getMax() : 0)
        {
        }

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

    EzAttributeRange(gs2::matchmaking::AttributeRange attributeRange) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(attributeRange)
    {}

    EzAttributeRange& operator=(const EzAttributeRange& ezAttributeRange) = default;
    EzAttributeRange& operator=(EzAttributeRange&& ezAttributeRange) = default;

    EzAttributeRange deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAttributeRange);
    }

    gs2::matchmaking::AttributeRange ToModel() const
    {
        gs2::matchmaking::AttributeRange attributeRange;
        attributeRange.setName(getName());
        attributeRange.setMin(getMin());
        attributeRange.setMax(getMax());
        return attributeRange;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    Int32 getMin() const
    {
        return *ensureData().min;
    }

    Int32 getMax() const
    {
        return *ensureData().max;
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