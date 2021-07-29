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

#include "EzMoldModel.hpp"
#include <gs2/formation/model/MoldModel.hpp>


namespace gs2 { namespace ez { namespace formation {

EzMoldModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    initialMaxCapacity(data.initialMaxCapacity),
    maxCapacity(data.maxCapacity)
{
    formModel = data.formModel.deepCopy();
}

EzMoldModel::Data::Data(const gs2::formation::MoldModel& moldModel) :
    name(moldModel.getName() ? *moldModel.getName() : StringHolder()),
    metadata(moldModel.getMetadata() ? *moldModel.getMetadata() : StringHolder()),
    formModel(moldModel.getFormModel()),
    initialMaxCapacity(moldModel.getInitialMaxCapacity() ? *moldModel.getInitialMaxCapacity() : 0),
    maxCapacity(moldModel.getMaxCapacity() ? *moldModel.getMaxCapacity() : 0)
{
}

EzMoldModel::Data::Data(const gs2::optional<gs2::formation::MoldModel>& moldModel) :
    name(moldModel && moldModel->getName() ? *moldModel->getName() : StringHolder()),
    metadata(moldModel && moldModel->getMetadata() ? *moldModel->getMetadata() : StringHolder()),
    formModel(moldModel ? moldModel->getFormModel() : gs2::optional<gs2::formation::FormModel>()),
    initialMaxCapacity(moldModel && moldModel->getInitialMaxCapacity() ? *moldModel->getInitialMaxCapacity() : 0),
    maxCapacity(moldModel && moldModel->getMaxCapacity() ? *moldModel->getMaxCapacity() : 0)
{
}

EzMoldModel::EzMoldModel(gs2::formation::MoldModel moldModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(moldModel)
{
}

EzMoldModel::EzMoldModel(gs2::optional<gs2::formation::MoldModel> moldModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(moldModel)
{
}

EzMoldModel EzMoldModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMoldModel);
}

gs2::formation::MoldModel EzMoldModel::ToModel() const
{
    gs2::formation::MoldModel moldModel;
    moldModel.setName(getName());
    moldModel.setMetadata(getMetadata());
    moldModel.setFormModel(getFormModel().ToModel());
    moldModel.setInitialMaxCapacity(getInitialMaxCapacity());
    moldModel.setMaxCapacity(getMaxCapacity());
    return moldModel;
}

}}}