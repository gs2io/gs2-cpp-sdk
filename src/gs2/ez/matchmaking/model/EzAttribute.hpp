

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

#ifndef GS2_EZ_MATCHMAKING_MODEL_EZATTRIBUTE_HPP_
#define GS2_EZ_MATCHMAKING_MODEL_EZATTRIBUTE_HPP_

#include <gs2/matchmaking/model/Attribute.hpp>


namespace gs2 { namespace ez { namespace matchmaking {

class EzAttribute : public gs2::Gs2Object
{
private:
    /** 属性名 */
    gs2::optional<StringHolder> m_Name;
    /** 属性値 */
    gs2::optional<Int32> m_Value;

public:
    EzAttribute() = default;

    EzAttribute(gs2::matchmaking::Attribute attribute) :
        m_Name(attribute.getName()),
        m_Value(attribute.getValue() ? *attribute.getValue() : 0)
    {
    }

    gs2::matchmaking::Attribute ToModel() const
    {
        gs2::matchmaking::Attribute attribute;
        attribute.setName(*m_Name);
        attribute.setValue(*m_Value);
        return attribute;
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

    Int32 getValue() const
    {
        return *m_Value;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setValue(Int32 value)
    {
        m_Value = value;
    }

    EzAttribute& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzAttribute& withValue(Int32 value)
    {
        setValue(value);
        return *this;
    }
};

}}}

#endif //GS2_EZ_MATCHMAKING_EZATTRIBUTE_HPP_