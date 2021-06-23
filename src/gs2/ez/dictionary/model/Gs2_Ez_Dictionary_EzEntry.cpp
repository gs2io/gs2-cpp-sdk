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

#include "EzEntry.hpp"
#include <gs2/dictionary/model/Entry.hpp>


namespace gs2 { namespace ez { namespace dictionary {

EzEntry::Data::Data(const Data& data) :
    Gs2Object(data),
    entryId(data.entryId),
    userId(data.userId),
    name(data.name),
    acquiredAt(data.acquiredAt)
{
}

EzEntry::Data::Data(const gs2::dictionary::Entry& entry) :
    entryId(entry.getEntryId()),
    userId(entry.getUserId()),
    name(entry.getName()),
    acquiredAt(entry.getAcquiredAt() ? *entry.getAcquiredAt() : 0)
{
}

EzEntry::EzEntry(gs2::dictionary::Entry entry) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(entry)
{
}

EzEntry EzEntry::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzEntry);
}

gs2::dictionary::Entry EzEntry::ToModel() const
{
    gs2::dictionary::Entry entry;
    entry.setEntryId(getEntryId());
    entry.setUserId(getUserId());
    entry.setName(getName());
    entry.setAcquiredAt(getAcquiredAt());
    return entry;
}

}}}