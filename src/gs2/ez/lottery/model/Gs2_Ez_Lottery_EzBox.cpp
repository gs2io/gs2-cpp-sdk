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

#include "EzBox.hpp"
#include <gs2/lottery/model/Box.hpp>


namespace gs2 { namespace ez { namespace lottery {

EzBox::Data::Data(const Data& data) :
    Gs2Object(data),
    prizeTableName(data.prizeTableName)
{
    if (data.drawnIndexes)
    {
        drawnIndexes = data.drawnIndexes->deepCopy();
    }
}

EzBox::Data::Data(const gs2::lottery::Box& box) :
    prizeTableName(box.getPrizeTableName()),
    drawnIndexes(box.getDrawnIndexes())
{
}

EzBox::EzBox(gs2::lottery::Box box) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(box)
{
}

EzBox EzBox::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzBox);
}

gs2::lottery::Box EzBox::ToModel() const
{
    gs2::lottery::Box box;
    box.setPrizeTableName(getPrizeTableName());
    box.setDrawnIndexes(getDrawnIndexes());
    return box;
}

}}}