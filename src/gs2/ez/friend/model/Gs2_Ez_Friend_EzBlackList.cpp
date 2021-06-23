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

#include "EzBlackList.hpp"
#include <gs2/friend/model/BlackList.hpp>


namespace gs2 { namespace ez { namespace friend_ {

EzBlackList::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId)
{
    if (data.targetUserIds)
    {
        targetUserIds = data.targetUserIds->deepCopy();
    }
}

EzBlackList::Data::Data(const gs2::friend_::BlackList& blackList) :
    userId(blackList.getUserId()),
    targetUserIds(blackList.getTargetUserIds())
{
}

EzBlackList::EzBlackList(gs2::friend_::BlackList blackList) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(blackList)
{
}

EzBlackList EzBlackList::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzBlackList);
}

gs2::friend_::BlackList EzBlackList::ToModel() const
{
    gs2::friend_::BlackList blackList;
    blackList.setUserId(getUserId());
    blackList.setTargetUserIds(getTargetUserIds());
    return blackList;
}

}}}