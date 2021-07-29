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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace lock {

class Mutex;

}

namespace ez { namespace lock {

class EzMutex : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ミューテックス */
        StringHolder mutexId;
        /** プロパティID */
        StringHolder propertyId;
        /** ロックを取得したトランザクションID */
        StringHolder transactionId;
        /** 参照回数 */
        Int32 referenceCount;
        /** ロックの有効期限 */
        Int64 ttlAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::lock::Mutex& mutex);
        Data(const gs2::optional<gs2::lock::Mutex>& mutex);
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

    EzMutex(gs2::lock::Mutex mutex);
    EzMutex(gs2::optional<gs2::lock::Mutex> mutex);

    EzMutex& operator=(const EzMutex& ezMutex) = default;
    EzMutex& operator=(EzMutex&& ezMutex) = default;

    EzMutex deepCopy() const;

    gs2::lock::Mutex ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getMutexId() const
    {
        return ensureData().mutexId;
    }

    const StringHolder& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    const StringHolder& getTransactionId() const
    {
        return ensureData().transactionId;
    }

    Int32 getReferenceCount() const
    {
        return ensureData().referenceCount;
    }

    Int64 getTtlAt() const
    {
        return ensureData().ttlAt;
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