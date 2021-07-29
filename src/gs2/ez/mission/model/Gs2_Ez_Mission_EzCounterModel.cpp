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

#include "EzCounterModel.hpp"
#include <gs2/mission/model/CounterModel.hpp>


namespace gs2 { namespace ez { namespace mission {

EzCounterModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata),
    challengePeriodEventId(data.challengePeriodEventId)
{
    scopes = data.scopes.deepCopy();
}

EzCounterModel::Data::Data(const gs2::mission::CounterModel& counterModel) :
    name(counterModel.getName() ? *counterModel.getName() : StringHolder()),
    metadata(counterModel.getMetadata() ? *counterModel.getMetadata() : StringHolder()),
    challengePeriodEventId(counterModel.getChallengePeriodEventId() ? *counterModel.getChallengePeriodEventId() : StringHolder())
{
    if (counterModel.getScopes())
    {
        for (int i = 0; i < counterModel.getScopes()->getCount(); ++i)
        {
            scopes += EzCounterScopeModel((*counterModel.getScopes())[i]);
        }
    }
}

EzCounterModel::Data::Data(const gs2::optional<gs2::mission::CounterModel>& counterModel) :
    name(counterModel && counterModel->getName() ? *counterModel->getName() : StringHolder()),
    metadata(counterModel && counterModel->getMetadata() ? *counterModel->getMetadata() : StringHolder()),
    challengePeriodEventId(counterModel && counterModel->getChallengePeriodEventId() ? *counterModel->getChallengePeriodEventId() : StringHolder())
{
    if (counterModel && counterModel->getScopes())
    {
        for (int i = 0; i < counterModel->getScopes()->getCount(); ++i)
        {
            scopes += EzCounterScopeModel((*counterModel->getScopes())[i]);
        }
    }
}

EzCounterModel::EzCounterModel(gs2::mission::CounterModel counterModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(counterModel)
{
}

EzCounterModel::EzCounterModel(gs2::optional<gs2::mission::CounterModel> counterModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(counterModel)
{
}

EzCounterModel EzCounterModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCounterModel);
}

gs2::mission::CounterModel EzCounterModel::ToModel() const
{
    gs2::mission::CounterModel counterModel;
    counterModel.setName(getName());
    counterModel.setMetadata(getMetadata());
    {
        gs2::List<gs2::mission::CounterScopeModel> list;
        auto& scopes = getScopes();
        for (int i = 0; i < scopes.getCount(); ++i)
        {
            list += scopes[i].ToModel();
        }
        counterModel.setScopes(list);
    }
    counterModel.setChallengePeriodEventId(getChallengePeriodEventId());
    return counterModel;
}

}}}