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

#include "EzSetCookieRequestEntry.hpp"
#include <gs2/news/model/SetCookieRequestEntry.hpp>


namespace gs2 { namespace ez { namespace news {

EzSetCookieRequestEntry::Data::Data(const Data& data) :
    Gs2Object(data),
    key(data.key),
    value(data.value)
{
}

EzSetCookieRequestEntry::Data::Data(const gs2::news::SetCookieRequestEntry& setCookieRequestEntry) :
    key(setCookieRequestEntry.getKey() ? *setCookieRequestEntry.getKey() : StringHolder()),
    value(setCookieRequestEntry.getValue() ? *setCookieRequestEntry.getValue() : StringHolder())
{
}

EzSetCookieRequestEntry::Data::Data(const gs2::optional<gs2::news::SetCookieRequestEntry>& setCookieRequestEntry) :
    key(setCookieRequestEntry && setCookieRequestEntry->getKey() ? *setCookieRequestEntry->getKey() : StringHolder()),
    value(setCookieRequestEntry && setCookieRequestEntry->getValue() ? *setCookieRequestEntry->getValue() : StringHolder())
{
}

EzSetCookieRequestEntry::EzSetCookieRequestEntry(gs2::news::SetCookieRequestEntry setCookieRequestEntry) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(setCookieRequestEntry)
{
}

EzSetCookieRequestEntry::EzSetCookieRequestEntry(gs2::optional<gs2::news::SetCookieRequestEntry> setCookieRequestEntry) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(setCookieRequestEntry)
{
}

EzSetCookieRequestEntry EzSetCookieRequestEntry::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSetCookieRequestEntry);
}

gs2::news::SetCookieRequestEntry EzSetCookieRequestEntry::ToModel() const
{
    gs2::news::SetCookieRequestEntry setCookieRequestEntry;
    setCookieRequestEntry.setKey(getKey());
    setCookieRequestEntry.setValue(getValue());
    return setCookieRequestEntry;
}

}}}