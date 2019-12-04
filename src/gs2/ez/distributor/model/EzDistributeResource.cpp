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

#include "EzDistributeResource.hpp"
#include <gs2/distributor/model/DistributeResource.hpp>


namespace gs2 { namespace ez { namespace distributor {

EzDistributeResource::Data::Data(const Data& data) :
    Gs2Object(data),
    action(data.action),
    request(data.request)
{
}

EzDistributeResource::Data::Data(const gs2::distributor::DistributeResource& distributeResource) :
    action(distributeResource.getAction()),
    request(distributeResource.getRequest())
{
}

EzDistributeResource::EzDistributeResource(gs2::distributor::DistributeResource distributeResource) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(distributeResource)
{
}

EzDistributeResource EzDistributeResource::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDistributeResource);
}

gs2::distributor::DistributeResource EzDistributeResource::ToModel() const
{
    gs2::distributor::DistributeResource distributeResource;
    distributeResource.setAction(getAction());
    distributeResource.setRequest(getRequest());
    return distributeResource;
}

}}}