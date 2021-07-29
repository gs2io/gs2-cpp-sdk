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

#include "EzMutex.hpp"
#include <gs2/lock/model/Mutex.hpp>


namespace gs2 { namespace ez { namespace lock {

EzMutex::Data::Data(const Data& data) :
    Gs2Object(data),
    mutexId(data.mutexId),
    propertyId(data.propertyId),
    transactionId(data.transactionId),
    referenceCount(data.referenceCount),
    ttlAt(data.ttlAt)
{
}

EzMutex::Data::Data(const gs2::lock::Mutex& mutex) :
    mutexId(mutex.getMutexId() ? *mutex.getMutexId() : StringHolder()),
    propertyId(mutex.getPropertyId() ? *mutex.getPropertyId() : StringHolder()),
    transactionId(mutex.getTransactionId() ? *mutex.getTransactionId() : StringHolder()),
    referenceCount(mutex.getReferenceCount() ? *mutex.getReferenceCount() : 0),
    ttlAt(mutex.getTtlAt() ? *mutex.getTtlAt() : 0)
{
}

EzMutex::Data::Data(const gs2::optional<gs2::lock::Mutex>& mutex) :
    mutexId(mutex && mutex->getMutexId() ? *mutex->getMutexId() : StringHolder()),
    propertyId(mutex && mutex->getPropertyId() ? *mutex->getPropertyId() : StringHolder()),
    transactionId(mutex && mutex->getTransactionId() ? *mutex->getTransactionId() : StringHolder()),
    referenceCount(mutex && mutex->getReferenceCount() ? *mutex->getReferenceCount() : 0),
    ttlAt(mutex && mutex->getTtlAt() ? *mutex->getTtlAt() : 0)
{
}

EzMutex::EzMutex(gs2::lock::Mutex mutex) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(mutex)
{
}

EzMutex::EzMutex(gs2::optional<gs2::lock::Mutex> mutex) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(mutex)
{
}

EzMutex EzMutex::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMutex);
}

gs2::lock::Mutex EzMutex::ToModel() const
{
    gs2::lock::Mutex mutex;
    mutex.setMutexId(getMutexId());
    mutex.setPropertyId(getPropertyId());
    mutex.setTransactionId(getTransactionId());
    mutex.setReferenceCount(getReferenceCount());
    mutex.setTtlAt(getTtlAt());
    return mutex;
}

}}}