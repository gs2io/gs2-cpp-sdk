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
#include <gs2/exchange/model/RateModel.hpp>


namespace gs2 { namespace ez { namespace exchange {

EzRateModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata)
{
    consumeActions = data.consumeActions.deepCopy();
    acquireActions = data.acquireActions.deepCopy();
}

EzRateModel::Data::Data(const gs2::exchange::RateModel& rateModel) :
    name(rateModel.getName() ? *rateModel.getName() : StringHolder()),
    metadata(rateModel.getMetadata() ? *rateModel.getMetadata() : StringHolder())
{
    if (rateModel.getConsumeActions())
    {
        for (int i = 0; i < rateModel.getConsumeActions()->getCount(); ++i)
        {
            consumeActions += EzConsumeAction((*rateModel.getConsumeActions())[i]);
        }
    }
    if (rateModel.getAcquireActions())
    {
        for (int i = 0; i < rateModel.getAcquireActions()->getCount(); ++i)
        {
            acquireActions += EzAcquireAction((*rateModel.getAcquireActions())[i]);
        }
    }
}

EzRateModel::Data::Data(const gs2::optional<gs2::exchange::RateModel>& rateModel) :
    name(rateModel && rateModel->getName() ? *rateModel->getName() : StringHolder()),
    metadata(rateModel && rateModel->getMetadata() ? *rateModel->getMetadata() : StringHolder())
{
    if (rateModel && rateModel->getConsumeActions())
    {
        for (int i = 0; i < rateModel->getConsumeActions()->getCount(); ++i)
        {
            consumeActions += EzConsumeAction((*rateModel->getConsumeActions())[i]);
        }
    }
    if (rateModel && rateModel->getAcquireActions())
    {
        for (int i = 0; i < rateModel->getAcquireActions()->getCount(); ++i)
        {
            acquireActions += EzAcquireAction((*rateModel->getAcquireActions())[i]);
        }
    }
}

EzRateModel::EzRateModel(gs2::exchange::RateModel rateModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(rateModel)
{
}

EzRateModel::EzRateModel(gs2::optional<gs2::exchange::RateModel> rateModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(rateModel)
{
}

EzRateModel EzRateModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzRateModel);
}

gs2::exchange::RateModel EzRateModel::ToModel() const
{
    gs2::exchange::RateModel rateModel;
    rateModel.setName(getName());
    rateModel.setMetadata(getMetadata());
    {
        gs2::List<gs2::exchange::ConsumeAction> list;
        auto& consumeActions = getConsumeActions();
        for (int i = 0; i < consumeActions.getCount(); ++i)
        {
            list += consumeActions[i].ToModel();
        }
        rateModel.setConsumeActions(list);
    }
    {
        gs2::List<gs2::exchange::AcquireAction> list;
        auto& acquireActions = getAcquireActions();
        for (int i = 0; i < acquireActions.getCount(); ++i)
        {
            list += acquireActions[i].ToModel();
        }
        rateModel.setAcquireActions(list);
    }
    return rateModel;
}

}}}