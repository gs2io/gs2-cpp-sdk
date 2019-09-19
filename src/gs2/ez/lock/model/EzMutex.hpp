

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

#ifndef GS2_EZ_LOCK_MODEL_EZMUTEX_HPP_
#define GS2_EZ_LOCK_MODEL_EZMUTEX_HPP_

#include <gs2/lock/model/Mutex.hpp>


namespace gs2 { namespace ez { namespace lock {

class EzMutex : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ミューテックス */
        gs2::optional<StringHolder> mutexId;
        /** プロパティID */
        gs2::optional<StringHolder> propertyId;
        /** ロックを取得したトランザクションID */
        gs2::optional<StringHolder> transactionId;
        /** 参照回数 */
        gs2::optional<Int32> referenceCount;
        /** ロックの有効期限 */
        gs2::optional<Int64> ttlAt;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            mutexId(data.mutexId),
            propertyId(data.propertyId),
            transactionId(data.transactionId),
            referenceCount(data.referenceCount),
            ttlAt(data.ttlAt)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::lock::Mutex& mutex) :
            mutexId(mutex.getMutexId()),
            propertyId(mutex.getPropertyId()),
            transactionId(mutex.getTransactionId()),
            referenceCount(mutex.getReferenceCount() ? *mutex.getReferenceCount() : 0),
            ttlAt(mutex.getTtlAt() ? *mutex.getTtlAt() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzMutex() = default;
    EzMutex(const EzMutex& ezMutex) = default;
    EzMutex(EzMutex&& ezMutex) = default;
    ~EzMutex() = default;

    EzMutex(gs2::lock::Mutex mutex) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(mutex)
    {}

    EzMutex& operator=(const EzMutex& ezMutex) = default;
    EzMutex& operator=(EzMutex&& ezMutex) = default;

    EzMutex deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMutex);
    }

    gs2::lock::Mutex ToModel() const
    {
        gs2::lock::Mutex mutex;
        mutex.setMutexId(getMutexId());
        mutex.setPropertyId(getPropertyId());
        mutex.setTransactionId(getTransactionId());
        mutex.setReferenceCount(getReferenceCount());
        mutex.setTtlAt(getTtlAt());
        return mutex;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getMutexId() const
    {
        return *ensureData().mutexId;
    }

    const StringHolder& getPropertyId() const
    {
        return *ensureData().propertyId;
    }

    const StringHolder& getTransactionId() const
    {
        return *ensureData().transactionId;
    }

    Int32 getReferenceCount() const
    {
        return *ensureData().referenceCount;
    }

    Int64 getTtlAt() const
    {
        return *ensureData().ttlAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMutexId(StringHolder mutexId)
    {
        ensureData().mutexId = std::move(mutexId);
    }

    void setPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId = std::move(propertyId);
    }

    void setTransactionId(StringHolder transactionId)
    {
        ensureData().transactionId = std::move(transactionId);
    }

    void setReferenceCount(Int32 referenceCount)
    {
        ensureData().referenceCount = referenceCount;
    }

    void setTtlAt(Int64 ttlAt)
    {
        ensureData().ttlAt = ttlAt;
    }

    EzMutex& withMutexId(StringHolder mutexId)
    {
        setMutexId(std::move(mutexId));
        return *this;
    }

    EzMutex& withPropertyId(StringHolder propertyId)
    {
        setPropertyId(std::move(propertyId));
        return *this;
    }

    EzMutex& withTransactionId(StringHolder transactionId)
    {
        setTransactionId(std::move(transactionId));
        return *this;
    }

    EzMutex& withReferenceCount(Int32 referenceCount)
    {
        setReferenceCount(referenceCount);
        return *this;
    }

    EzMutex& withTtlAt(Int64 ttlAt)
    {
        setTtlAt(ttlAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_LOCK_EZMUTEX_HPP_