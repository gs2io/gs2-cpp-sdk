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

#include "EzDrawnPrize.hpp"
#include <gs2/lottery/model/DrawnPrize.hpp>


namespace gs2 { namespace ez { namespace lottery {

EzDrawnPrize::Data::Data(const Data& data) :
    Gs2Object(data)
{
    if (data.acquireActions)
    {
        acquireActions = data.acquireActions->deepCopy();
    }
}

EzDrawnPrize::Data::Data(const gs2::lottery::DrawnPrize& drawnPrize)
{
    acquireActions.emplace();
    if (drawnPrize.getAcquireActions())
    {
        for (int i = 0; i < drawnPrize.getAcquireActions()->getCount(); ++i)
        {
            *acquireActions += EzAcquireAction((*drawnPrize.getAcquireActions())[i]);
        }
    }
}

EzDrawnPrize::EzDrawnPrize(gs2::lottery::DrawnPrize drawnPrize) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(drawnPrize)
{
}

EzDrawnPrize EzDrawnPrize::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDrawnPrize);
}

gs2::lottery::DrawnPrize EzDrawnPrize::ToModel() const
{
    gs2::lottery::DrawnPrize drawnPrize;
    {
        gs2::List<gs2::lottery::AcquireAction> list;
        auto& acquireActions = getAcquireActions();
        for (int i = 0; i < acquireActions.getCount(); ++i)
        {
            list += acquireActions[i].ToModel();
        }
        drawnPrize.setAcquireActions(list);
    }
    return drawnPrize;
}

}}}