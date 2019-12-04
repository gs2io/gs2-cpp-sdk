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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace matchmaking {

class Attribute;

}

namespace ez { namespace matchmaking {

class EzAttribute : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 属性名 */
        gs2::optional<StringHolder> name;
        /** 属性値 */
        gs2::optional<Int32> value;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::matchmaking::Attribute& attribute);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzAttribute() = default;
    EzAttribute(const EzAttribute& ezAttribute) = default;
    EzAttribute(EzAttribute&& ezAttribute) = default;
    ~EzAttribute() = default;

    EzAttribute(gs2::matchmaking::Attribute attribute);

    EzAttribute& operator=(const EzAttribute& ezAttribute) = default;
    EzAttribute& operator=(EzAttribute&& ezAttribute) = default;

    EzAttribute deepCopy() const;

    gs2::matchmaking::Attribute ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    Int32 getValue() const
    {
        return *ensureData().value;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setValue(Int32 value)
    {
        ensureData().value = value;
    }

    EzAttribute& withName(StringHolder name)
    {
        setName(std::move(name));
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