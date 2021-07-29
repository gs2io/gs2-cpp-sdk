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

#include "EzDistributorModel.hpp"
#include <gs2/distributor/model/DistributorModel.hpp>


namespace gs2 { namespace ez { namespace distributor {

EzDistributorModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    inboxNamespaceId(data.inboxNamespaceId)
{
    whiteListTargetIds = data.whiteListTargetIds.deepCopy();
}

EzDistributorModel::Data::Data(const gs2::distributor::DistributorModel& distributorModel) :
    name(distributorModel.getName() ? *distributorModel.getName() : StringHolder()),
    metadata(distributorModel.getMetadata() ? *distributorModel.getMetadata() : StringHolder()),
    inboxNamespaceId(distributorModel.getInboxNamespaceId() ? *distributorModel.getInboxNamespaceId() : StringHolder()),
    whiteListTargetIds(distributorModel.getWhiteListTargetIds() ? *distributorModel.getWhiteListTargetIds() : List<StringHolder>())
{
}

EzDistributorModel::Data::Data(const gs2::optional<gs2::distributor::DistributorModel>& distributorModel) :
    name(distributorModel && distributorModel->getName() ? *distributorModel->getName() : StringHolder()),
    metadata(distributorModel && distributorModel->getMetadata() ? *distributorModel->getMetadata() : StringHolder()),
    inboxNamespaceId(distributorModel && distributorModel->getInboxNamespaceId() ? *distributorModel->getInboxNamespaceId() : StringHolder()),
    whiteListTargetIds(distributorModel && distributorModel->getWhiteListTargetIds() ? *distributorModel->getWhiteListTargetIds() : List<StringHolder>())
{
}

EzDistributorModel::EzDistributorModel(gs2::distributor::DistributorModel distributorModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(distributorModel)
{
}

EzDistributorModel::EzDistributorModel(gs2::optional<gs2::distributor::DistributorModel> distributorModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(distributorModel)
{
}

EzDistributorModel EzDistributorModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDistributorModel);
}

gs2::distributor::DistributorModel EzDistributorModel::ToModel() const
{
    gs2::distributor::DistributorModel distributorModel;
    distributorModel.setName(getName());
    distributorModel.setMetadata(getMetadata());
    distributorModel.setInboxNamespaceId(getInboxNamespaceId());
    distributorModel.setWhiteListTargetIds(getWhiteListTargetIds());
    return distributorModel;
}

}}}