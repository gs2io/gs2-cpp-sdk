

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
    /** ミューテックス */
    gs2::optional<StringHolder> m_MutexId;
    /** プロパティID */
    gs2::optional<StringHolder> m_PropertyId;
    /** ロックを取得したトランザクションID */
    gs2::optional<StringHolder> m_TransactionId;
    /** 参照回数 */
    gs2::optional<Int32> m_ReferenceCount;
    /** ロックの有効期限 */
    gs2::optional<Int64> m_TtlAt;

public:
    EzMutex() = default;

    EzMutex(gs2::lock::Mutex mutex) :
        m_MutexId(mutex.getMutexId()),
        m_PropertyId(mutex.getPropertyId()),
        m_TransactionId(mutex.getTransactionId()),
        m_ReferenceCount(mutex.getReferenceCount() ? *mutex.getReferenceCount() : 0),
        m_TtlAt(mutex.getTtlAt() ? *mutex.getTtlAt() : 0)
    {
    }

    gs2::lock::Mutex ToModel() const
    {
        gs2::lock::Mutex mutex;
        mutex.setMutexId(*m_MutexId);
        mutex.setPropertyId(*m_PropertyId);
        mutex.setTransactionId(*m_TransactionId);
        mutex.setReferenceCount(*m_ReferenceCount);
        mutex.setTtlAt(*m_TtlAt);
        return mutex;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getMutexId() const
    {
        return *m_MutexId;
    }

    gs2::StringHolder& getMutexId()
    {
        return *m_MutexId;
    }

    const gs2::StringHolder& getPropertyId() const
    {
        return *m_PropertyId;
    }

    gs2::StringHolder& getPropertyId()
    {
        return *m_PropertyId;
    }

    const gs2::StringHolder& getTransactionId() const
    {
        return *m_TransactionId;
    }

    gs2::StringHolder& getTransactionId()
    {
        return *m_TransactionId;
    }

    Int32 getReferenceCount() const
    {
        return *m_ReferenceCount;
    }

    Int64 getTtlAt() const
    {
        return *m_TtlAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMutexId(Char* mutexId)
    {
        m_MutexId.emplace(mutexId);
    }

    void setPropertyId(Char* propertyId)
    {
        m_PropertyId.emplace(propertyId);
    }

    void setTransactionId(Char* transactionId)
    {
        m_TransactionId.emplace(transactionId);
    }

    void setReferenceCount(Int32 referenceCount)
    {
        m_ReferenceCount = referenceCount;
    }

    void setTtlAt(Int64 ttlAt)
    {
        m_TtlAt = ttlAt;
    }

    EzMutex& withMutexId(Char* mutexId)
    {
        setMutexId(mutexId);
        return *this;
    }

    EzMutex& withPropertyId(Char* propertyId)
    {
        setPropertyId(propertyId);
        return *this;
    }

    EzMutex& withTransactionId(Char* transactionId)
    {
        setTransactionId(transactionId);
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