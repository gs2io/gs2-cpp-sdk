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

#ifndef GS2_EZ_FORMATION_MODEL_EZMOLD_HPP_
#define GS2_EZ_FORMATION_MODEL_EZMOLD_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace formation {

class Mold;

}

namespace ez { namespace formation {

class EzMold : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** フォームの保存領域の名前 */
        gs2::optional<StringHolder> name;
        /** ユーザーID */
        gs2::optional<StringHolder> userId;
        /** 現在のキャパシティ */
        gs2::optional<Int32> capacity;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::formation::Mold& mold);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzMold() = default;
    EzMold(const EzMold& ezMold) = default;
    EzMold(EzMold&& ezMold) = default;
    ~EzMold() = default;

    EzMold(gs2::formation::Mold mold);

    EzMold& operator=(const EzMold& ezMold) = default;
    EzMold& operator=(EzMold&& ezMold) = default;

    EzMold deepCopy() const;

    gs2::formation::Mold ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    Int32 getCapacity() const
    {
        return *ensureData().capacity;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setCapacity(Int32 capacity)
    {
        ensureData().capacity = capacity;
    }

    EzMold& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzMold& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzMold& withCapacity(Int32 capacity)
    {
        setCapacity(capacity);
        return *this;
    }
};

}}}

#endif //GS2_EZ_FORMATION_EZMOLD_HPP_