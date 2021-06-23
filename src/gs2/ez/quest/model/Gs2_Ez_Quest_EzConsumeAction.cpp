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

#include "EzConsumeAction.hpp"
#include <gs2/quest/model/ConsumeAction.hpp>


namespace gs2 { namespace ez { namespace quest {

EzConsumeAction::Data::Data(const Data& data) :
    Gs2Object(data),
    action(data.action),
    request(data.request)
{
}

EzConsumeAction::Data::Data(const gs2::quest::ConsumeAction& consumeAction) :
    action(consumeAction.getAction()),
    request(consumeAction.getRequest())
{
}

EzConsumeAction::EzConsumeAction(gs2::quest::ConsumeAction consumeAction) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(consumeAction)
{
}

EzConsumeAction EzConsumeAction::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzConsumeAction);
}

gs2::quest::ConsumeAction EzConsumeAction::ToModel() const
{
    gs2::quest::ConsumeAction consumeAction;
    consumeAction.setAction(getAction());
    consumeAction.setRequest(getRequest());
    return consumeAction;
}

}}}