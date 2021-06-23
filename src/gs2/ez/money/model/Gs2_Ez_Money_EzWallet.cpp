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

#include "EzWallet.hpp"
#include <gs2/money/model/Wallet.hpp>


namespace gs2 { namespace ez { namespace money {

EzWallet::Data::Data(const Data& data) :
    Gs2Object(data),
    slot(data.slot),
    paid(data.paid),
    free(data.free),
    updatedAt(data.updatedAt)
{
}

EzWallet::Data::Data(const gs2::money::Wallet& wallet) :
    slot(wallet.getSlot() ? *wallet.getSlot() : 0),
    paid(wallet.getPaid() ? *wallet.getPaid() : 0),
    free(wallet.getFree() ? *wallet.getFree() : 0),
    updatedAt(wallet.getUpdatedAt() ? *wallet.getUpdatedAt() : 0)
{
}

EzWallet::EzWallet(gs2::money::Wallet wallet) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(wallet)
{
}

EzWallet EzWallet::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzWallet);
}

gs2::money::Wallet EzWallet::ToModel() const
{
    gs2::money::Wallet wallet;
    wallet.setSlot(getSlot());
    wallet.setPaid(getPaid());
    wallet.setFree(getFree());
    wallet.setUpdatedAt(getUpdatedAt());
    return wallet;
}

}}}