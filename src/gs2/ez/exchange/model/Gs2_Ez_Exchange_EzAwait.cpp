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

#include "EzAwait.hpp"
#include <gs2/exchange/model/Await.hpp>


namespace gs2 { namespace ez { namespace exchange {

EzAwait::Data::Data(const Data& data) :
    Gs2Object(data),
    userId(data.userId),
    rateName(data.rateName),
    name(data.name),
    exchangedAt(data.exchangedAt)
{
}

EzAwait::Data::Data(const gs2::exchange::Await& await_) :
    userId(await_.getUserId() ? *await_.getUserId() : StringHolder()),
    rateName(await_.getRateName() ? *await_.getRateName() : StringHolder()),
    name(await_.getName() ? *await_.getName() : StringHolder()),
    exchangedAt(await_.getExchangedAt() ? *await_.getExchangedAt() : 0)
{
}

EzAwait::Data::Data(const gs2::optional<gs2::exchange::Await>& await_) :
    userId(await_ && await_->getUserId() ? *await_->getUserId() : StringHolder()),
    rateName(await_ && await_->getRateName() ? *await_->getRateName() : StringHolder()),
    name(await_ && await_->getName() ? *await_->getName() : StringHolder()),
    exchangedAt(await_ && await_->getExchangedAt() ? *await_->getExchangedAt() : 0)
{
}

EzAwait::EzAwait(gs2::exchange::Await await_) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(await_)
{
}

EzAwait::EzAwait(gs2::optional<gs2::exchange::Await> await_) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(await_)
{
}

EzAwait EzAwait::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAwait);
}

gs2::exchange::Await EzAwait::ToModel() const
{
    gs2::exchange::Await await_;
    await_.setUserId(getUserId());
    await_.setRateName(getRateName());
    await_.setName(getName());
    await_.setExchangedAt(getExchangedAt());
    return await_;
}

}}}