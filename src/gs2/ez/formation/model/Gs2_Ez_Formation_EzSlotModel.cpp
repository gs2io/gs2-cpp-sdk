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

#include "EzSlotModel.hpp"
#include <gs2/formation/model/SlotModel.hpp>


namespace gs2 { namespace ez { namespace formation {

EzSlotModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    propertyRegex(data.propertyRegex),
    metadata(data.metadata)
{
}

EzSlotModel::Data::Data(const gs2::formation::SlotModel& slotModel) :
    name(slotModel.getName() ? *slotModel.getName() : StringHolder()),
    propertyRegex(slotModel.getPropertyRegex() ? *slotModel.getPropertyRegex() : StringHolder()),
    metadata(slotModel.getMetadata() ? *slotModel.getMetadata() : StringHolder())
{
}

EzSlotModel::Data::Data(const gs2::optional<gs2::formation::SlotModel>& slotModel) :
    name(slotModel && slotModel->getName() ? *slotModel->getName() : StringHolder()),
    propertyRegex(slotModel && slotModel->getPropertyRegex() ? *slotModel->getPropertyRegex() : StringHolder()),
    metadata(slotModel && slotModel->getMetadata() ? *slotModel->getMetadata() : StringHolder())
{
}

EzSlotModel::EzSlotModel(gs2::formation::SlotModel slotModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(slotModel)
{
}

EzSlotModel::EzSlotModel(gs2::optional<gs2::formation::SlotModel> slotModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(slotModel)
{
}

EzSlotModel EzSlotModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzSlotModel);
}

gs2::formation::SlotModel EzSlotModel::ToModel() const
{
    gs2::formation::SlotModel slotModel;
    slotModel.setName(getName());
    slotModel.setPropertyRegex(getPropertyRegex());
    slotModel.setMetadata(getMetadata());
    return slotModel;
}

}}}