/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#ifndef GS2_CORE_NETWORK_GS2SESSIONTASKID_HPP_
#define GS2_CORE_NETWORK_GS2SESSIONTASKID_HPP_

#include "../Gs2Object.hpp"

GS2_START_OF_NAMESPACE

namespace detail {

class Gs2SessionTaskId : public Gs2Object
{
    friend bool operator==(const Gs2SessionTaskId& gs2SessionTaskId1, const Gs2SessionTaskId& gs2SessionTaskId2);

public:
    typedef Int32 ValueType;

    friend bool operator==(const Gs2SessionTaskId& gs2SessionTaskId, ValueType value);

    static const ValueType InvalidIdValue = 0;
    static const ValueType ReservedIdValueMax = 10000;

    class Generator : public Gs2Object
    {
    private:
        ValueType m_Counter;

    public:
        Generator() :
            m_Counter(ReservedIdValueMax)
        {}

        ~Generator() = default;

        ValueType issue()
        {
            if (++m_Counter <= ReservedIdValueMax)
            {
                m_Counter = ReservedIdValueMax + 1;
            }
            return m_Counter;
        }
    };

private:
    ValueType m_Value;

public:
    Gs2SessionTaskId() :
        m_Value(InvalidIdValue)
    {}

    Gs2SessionTaskId(ValueType value) :
        m_Value(value)
    {}

    ~Gs2SessionTaskId() = default;

    inline Gs2SessionTaskId& operator=(ValueType value)
    {
        m_Value = value;
        return *this;
    }

    inline ValueType get() const
    {
        return m_Value;
    }
};

inline bool operator==(const Gs2SessionTaskId& gs2SessionTaskId1, const Gs2SessionTaskId& gs2SessionTaskId2)
{
    return gs2SessionTaskId1.m_Value == gs2SessionTaskId2.m_Value;
}

inline bool operator!=(const Gs2SessionTaskId& gs2SessionTaskId1, const Gs2SessionTaskId& gs2SessionTaskId2)
{
    return !(gs2SessionTaskId1 == gs2SessionTaskId2);
}

inline bool operator==(const Gs2SessionTaskId& gs2SessionTaskId, Gs2SessionTaskId::ValueType value)
{
    return gs2SessionTaskId.m_Value == value;
}

inline bool operator!=(const Gs2SessionTaskId& gs2SessionTaskId, Gs2SessionTaskId::ValueType value)
{
    return !(gs2SessionTaskId == value);
}

inline bool operator==(Gs2SessionTaskId::ValueType value, const Gs2SessionTaskId& gs2SessionTaskId)
{
    return gs2SessionTaskId == value;
}

inline bool operator!=(Gs2SessionTaskId::ValueType value, const Gs2SessionTaskId& gs2SessionTaskId)
{
    return !(gs2SessionTaskId == value);
}

}

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_NETWORK_GS2SESSIONTASKID_HPP_
