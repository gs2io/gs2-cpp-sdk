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

#include "EzForm.hpp"
#include <gs2/formation/model/Form.hpp>


namespace gs2 { namespace ez { namespace formation {

EzForm::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    index(data.index)
{
    slots = data.slots.deepCopy();
}

EzForm::Data::Data(const gs2::formation::Form& form) :
    name(form.getName() ? *form.getName() : StringHolder()),
    index(form.getIndex() ? *form.getIndex() : 0)
{
    if (form.getSlots())
    {
        for (int i = 0; i < form.getSlots()->getCount(); ++i)
        {
            slots += EzSlot((*form.getSlots())[i]);
        }
    }
}

EzForm::Data::Data(const gs2::optional<gs2::formation::Form>& form) :
    name(form && form->getName() ? *form->getName() : StringHolder()),
    index(form && form->getIndex() ? *form->getIndex() : 0)
{
    if (form && form->getSlots())
    {
        for (int i = 0; i < form->getSlots()->getCount(); ++i)
        {
            slots += EzSlot((*form->getSlots())[i]);
        }
    }
}

EzForm::EzForm(gs2::formation::Form form) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(form)
{
}

EzForm::EzForm(gs2::optional<gs2::formation::Form> form) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(form)
{
}

EzForm EzForm::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzForm);
}

gs2::formation::Form EzForm::ToModel() const
{
    gs2::formation::Form form;
    form.setName(getName());
    form.setIndex(getIndex());
    {
        gs2::List<gs2::formation::Slot> list;
        auto& slots = getSlots();
        for (int i = 0; i < slots.getCount(); ++i)
        {
            list += slots[i].ToModel();
        }
        form.setSlots(list);
    }
    return form;
}

}}}