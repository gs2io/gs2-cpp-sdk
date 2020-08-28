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

#include "EzRateModel.hpp"
#include <gs2/enhance/model/RateModel.hpp>


namespace gs2 { namespace ez { namespace enhance {

EzRateModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    targetInventoryModelId(data.targetInventoryModelId),
    acquireExperienceSuffix(data.acquireExperienceSuffix),
    materialInventoryModelId(data.materialInventoryModelId),
    experienceModelId(data.experienceModelId)
{
}

EzRateModel::Data::Data(const gs2::enhance::RateModel& rateModel) :
    name(rateModel.getName()),
    metadata(rateModel.getMetadata()),
    targetInventoryModelId(rateModel.getTargetInventoryModelId()),
    acquireExperienceSuffix(rateModel.getAcquireExperienceSuffix()),
    materialInventoryModelId(rateModel.getMaterialInventoryModelId()),
    experienceModelId(rateModel.getExperienceModelId())
{
}

EzRateModel::EzRateModel(gs2::enhance::RateModel rateModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(rateModel)
{
}

EzRateModel EzRateModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRateModel);
}

gs2::enhance::RateModel EzRateModel::ToModel() const
{
    gs2::enhance::RateModel rateModel;
    rateModel.setName(getName());
    rateModel.setMetadata(getMetadata());
    rateModel.setTargetInventoryModelId(getTargetInventoryModelId());
    rateModel.setAcquireExperienceSuffix(getAcquireExperienceSuffix());
    rateModel.setMaterialInventoryModelId(getMaterialInventoryModelId());
    rateModel.setExperienceModelId(getExperienceModelId());
    return rateModel;
}

}}}