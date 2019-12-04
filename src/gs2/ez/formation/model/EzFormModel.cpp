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

#include "EzFormModel.hpp"
#include <gs2/formation/model/FormModel.hpp>


namespace gs2 { namespace ez { namespace formation {

EzFormModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata)
{
    if (data.slots)
    {
        slots = data.slots->deepCopy();
    }
}

EzFormModel::Data::Data(const gs2::formation::FormModel& formModel) :
    name(formModel.getName()),
    metadata(formModel.getMetadata())
{
    slots.emplace();
    if (formModel.getSlots())
    {
        for (int i = 0; i < formModel.getSlots()->getCount(); ++i)
        {
            *slots += EzSlotModel((*formModel.getSlots())[i]);
        }
    }
}

EzFormModel::EzFormModel(gs2::formation::FormModel formModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(formModel)
{
}

EzFormModel EzFormModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzFormModel);
}

gs2::formation::FormModel EzFormModel::ToModel() const
{
    gs2::formation::FormModel formModel;
    formModel.setName(getName());
    formModel.setMetadata(getMetadata());
    {
        gs2::List<gs2::formation::SlotModel> list;
        auto& slots = getSlots();
        for (int i = 0; i < slots.getCount(); ++i)
        {
            list += slots[i].ToModel();
        }
        formModel.setSlots(list);
    }
    return formModel;
}

}}}