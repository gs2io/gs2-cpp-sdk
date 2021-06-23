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

#include "EzTakeOver.hpp"
#include <gs2/account/model/TakeOver.hpp>


namespace gs2 { namespace ez { namespace account {

EzTakeOver::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    type(data.type),
    userIdentifier(data.userIdentifier),
    createdAt(data.createdAt)
{
}

EzTakeOver::Data::Data(const gs2::account::TakeOver& takeOver) :
    userId(takeOver.getUserId()),
    type(takeOver.getType() ? *takeOver.getType() : 0),
    userIdentifier(takeOver.getUserIdentifier()),
    createdAt(takeOver.getCreatedAt() ? *takeOver.getCreatedAt() : 0)
{
}

EzTakeOver::EzTakeOver(gs2::account::TakeOver takeOver) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(takeOver)
{
}

EzTakeOver EzTakeOver::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzTakeOver);
}

gs2::account::TakeOver EzTakeOver::ToModel() const
{
    gs2::account::TakeOver takeOver;
    takeOver.setUserId(getUserId());
    takeOver.setType(getType());
    takeOver.setUserIdentifier(getUserIdentifier());
    takeOver.setCreatedAt(getCreatedAt());
    return takeOver;
}

}}}