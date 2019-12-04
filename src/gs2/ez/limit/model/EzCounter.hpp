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

#ifndef GS2_EZ_LIMIT_MODEL_EZCOUNTER_HPP_
#define GS2_EZ_LIMIT_MODEL_EZCOUNTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace limit {

class Counter;

}

namespace ez { namespace limit {

class EzCounter : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** カウンター */
        gs2::optional<StringHolder> counterId;
        /** カウンターの名前 */
        gs2::optional<StringHolder> name;
        /** カウント値 */
        gs2::optional<Int32> count;
        /** 作成日時 */
        gs2::optional<Int64> createdAt;
        /** 最終更新日時 */
        gs2::optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::limit::Counter& counter);
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

    EzCounter(gs2::limit::Counter counter);

    EzCounter& operator=(const EzCounter& ezCounter) = default;
    EzCounter& operator=(EzCounter&& ezCounter) = default;

    EzCounter deepCopy() const;

    gs2::limit::Counter ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getCounterId() const
    {
        return *ensureData().counterId;
    }

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    Int32 getCount() const
    {
        return *ensureData().count;
    }

    Int64 getCreatedAt() const
    {
        return *ensureData().createdAt;
    }

    Int64 getUpdatedAt() const
    {
        return *ensureData().updatedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setCounterId(StringHolder counterId)
    {
        ensureData().counterId = std::move(counterId);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setCount(Int32 count)
    {
        ensureData().count = count;
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt = updatedAt;
    }

    EzCounter& withCounterId(StringHolder counterId)
    {
        setCounterId(std::move(counterId));
        return *this;
    }

    EzCounter& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzCounter& withCount(Int32 count)
    {
        setCount(count);
        return *this;
    }

    EzCounter& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    EzCounter& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_LIMIT_EZCOUNTER_HPP_