

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
    /** 属性名 */
    gs2::optional<StringHolder> m_Name;
    /** ギャザリング参加可能な属性値の最小値 */
    gs2::optional<Int32> m_Min;
    /** ギャザリング参加可能な属性値の最大値 */
    gs2::optional<Int32> m_Max;

public:
    EzAttributeRange() = default;

    EzAttributeRange(gs2::matchmaking::AttributeRange attributeRange) :
        m_Name(attributeRange.getName()),
        m_Min(attributeRange.getMin() ? *attributeRange.getMin() : 0),
        m_Max(attributeRange.getMax() ? *attributeRange.getMax() : 0)
    {
    }

    gs2::matchmaking::AttributeRange ToModel() const
    {
        gs2::matchmaking::AttributeRange attributeRange;
        attributeRange.setName(*m_Name);
        attributeRange.setMin(*m_Min);
        attributeRange.setMax(*m_Max);
        return attributeRange;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    Int32 getMin() const
    {
        return *m_Min;
    }

    Int32 getMax() const
    {
        return *m_Max;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMin(Int32 min)
    {
        m_Min = min;
    }

    void setMax(Int32 max)
    {
        m_Max = max;
    }

    EzAttributeRange& withName(Char* name)
    {
        setName(name);
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