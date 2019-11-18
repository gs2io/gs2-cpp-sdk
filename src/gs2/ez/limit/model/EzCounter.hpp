

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

#include <gs2/limit/model/Counter.hpp>


namespace gs2 { namespace ez { namespace limit {

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

        Data(const Data& data) :
            Gs2Object(data),
            counterId(data.counterId),
            name(data.name),
            count(data.count),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::limit::Counter& counter) :
            counterId(counter.getCounterId()),
            name(counter.getName()),
            count(counter.getCount() ? *counter.getCount() : 0),
            createdAt(counter.getCreatedAt() ? *counter.getCreatedAt() : 0),
            updatedAt(counter.getUpdatedAt() ? *counter.getUpdatedAt() : 0)
        {
        }

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

    EzCounter(gs2::limit::Counter counter) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(counter)
    {}

    EzCounter& operator=(const EzCounter& ezCounter) = default;
    EzCounter& operator=(EzCounter&& ezCounter) = default;

    EzCounter deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCounter);
    }

    gs2::limit::Counter ToModel() const
    {
        gs2::limit::Counter counter;
        counter.setCounterId(getCounterId());
        counter.setName(getName());
        counter.setCount(getCount());
        counter.setCreatedAt(getCreatedAt());
        counter.setUpdatedAt(getUpdatedAt());
        return counter;
    }

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