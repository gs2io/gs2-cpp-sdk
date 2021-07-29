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

#include "EzAcquireAction.hpp"
#include <gs2/inbox/model/AcquireAction.hpp>


namespace gs2 { namespace ez { namespace inbox {

EzAcquireAction::Data::Data(const Data& data) :
    Gs2Object(data),
    action(data.action),
    request(data.request)
{
}

EzAcquireAction::Data::Data(const gs2::inbox::AcquireAction& acquireAction) :
    action(acquireAction.getAction() ? *acquireAction.getAction() : StringHolder()),
    request(acquireAction.getRequest() ? *acquireAction.getRequest() : StringHolder())
{
}

EzAcquireAction::Data::Data(const gs2::optional<gs2::inbox::AcquireAction>& acquireAction) :
    action(acquireAction && acquireAction->getAction() ? *acquireAction->getAction() : StringHolder()),
    request(acquireAction && acquireAction->getRequest() ? *acquireAction->getRequest() : StringHolder())
{
}

EzAcquireAction::EzAcquireAction(gs2::inbox::AcquireAction acquireAction) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(acquireAction)
{
}

EzAcquireAction::EzAcquireAction(gs2::optional<gs2::inbox::AcquireAction> acquireAction) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(acquireAction)
{
}

EzAcquireAction EzAcquireAction::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAcquireAction);
}

gs2::inbox::AcquireAction EzAcquireAction::ToModel() const
{
    gs2::inbox::AcquireAction acquireAction;
    acquireAction.setAction(getAction());
    acquireAction.setRequest(getRequest());
    return acquireAction;
}

}}}