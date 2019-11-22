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

#include "WalletDetail.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace money {

WalletDetail::Data::Data(const Data& data) :
    detail::json::IModel(data),
    walletDetailId(data.walletDetailId),
    userId(data.userId),
    slot(data.slot),
    price(data.price),
    count(data.count),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
}

void WalletDetail::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "walletDetailId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->walletDetailId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "slot") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->slot = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "price") == 0)
    {
        if (jsonValue.IsFloat())
        {
            this->price = jsonValue.GetFloat();
        }
    }
    else if (std::strcmp(name_, "count") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->count = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "createdAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->createdAt = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "updatedAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->updatedAt = jsonValue.GetInt64();
        }
    }
}

WalletDetail WalletDetail::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WalletDetail);
}

bool operator!=(const WalletDetail& lhs, const WalletDetail& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->walletDetailId != lhr.m_pData->walletDetailId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->slot != lhr.m_pData->slot)
        {
            return true;
        }
        if (lhs.m_pData->price != lhr.m_pData->price)
        {
            return true;
        }
        if (lhs.m_pData->count != lhr.m_pData->count)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

} }