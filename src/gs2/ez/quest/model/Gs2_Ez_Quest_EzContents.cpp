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

#include "EzContents.hpp"
#include <gs2/quest/model/Contents.hpp>


namespace gs2 { namespace ez { namespace quest {

EzContents::Data::Data(const Data& data) :
    Gs2Object(data),
    metadata(data.metadata)
{
    completeAcquireActions = data.completeAcquireActions.deepCopy();
}

EzContents::Data::Data(const gs2::quest::Contents& contents) :
    metadata(contents.getMetadata() ? *contents.getMetadata() : StringHolder())
{
    if (contents.getCompleteAcquireActions())
    {
        for (int i = 0; i < contents.getCompleteAcquireActions()->getCount(); ++i)
        {
            completeAcquireActions += EzAcquireAction((*contents.getCompleteAcquireActions())[i]);
        }
    }
}

EzContents::Data::Data(const gs2::optional<gs2::quest::Contents>& contents) :
    metadata(contents && contents->getMetadata() ? *contents->getMetadata() : StringHolder())
{
    if (contents && contents->getCompleteAcquireActions())
    {
        for (int i = 0; i < contents->getCompleteAcquireActions()->getCount(); ++i)
        {
            completeAcquireActions += EzAcquireAction((*contents->getCompleteAcquireActions())[i]);
        }
    }
}

EzContents::EzContents(gs2::quest::Contents contents) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(contents)
{
}

EzContents::EzContents(gs2::optional<gs2::quest::Contents> contents) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(contents)
{
}

EzContents EzContents::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzContents);
}

gs2::quest::Contents EzContents::ToModel() const
{
    gs2::quest::Contents contents;
    contents.setMetadata(getMetadata());
    {
        gs2::List<gs2::quest::AcquireAction> list;
        auto& completeAcquireActions = getCompleteAcquireActions();
        for (int i = 0; i < completeAcquireActions.getCount(); ++i)
        {
            list += completeAcquireActions[i].ToModel();
        }
        contents.setCompleteAcquireActions(list);
    }
    return contents;
}

}}}