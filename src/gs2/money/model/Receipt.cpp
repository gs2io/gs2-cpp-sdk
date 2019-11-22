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

#include "Receipt.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace money {

Receipt::Data::Data(const Data& data) :
    detail::json::IModel(data),
    receiptId(data.receiptId),
    transactionId(data.transactionId),
    userId(data.userId),
    type(data.type),
    slot(data.slot),
    price(data.price),
    paid(data.paid),
    free(data.free),
    total(data.total),
    contentsId(data.contentsId),
    createdAt(data.createdAt)
{
}

void Receipt::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "receiptId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->receiptId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "transactionId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->transactionId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "userId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->userId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "type") == 0)
    {
        if (jsonValue.IsString())
        {
            this->type.emplace(jsonValue.GetString());
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
    else if (std::strcmp(name_, "paid") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->paid = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "free") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->free = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "total") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->total = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "contentsId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->contentsId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "createdAt") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->createdAt = jsonValue.GetInt64();
        }
    }
}

Receipt Receipt::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Receipt);
}

bool operator!=(const Receipt& lhs, const Receipt& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->receiptId != lhr.m_pData->receiptId)
        {
            return true;
        }
        if (lhs.m_pData->transactionId != lhr.m_pData->transactionId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
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
        if (lhs.m_pData->paid != lhr.m_pData->paid)
        {
            return true;
        }
        if (lhs.m_pData->free != lhr.m_pData->free)
        {
            return true;
        }
        if (lhs.m_pData->total != lhr.m_pData->total)
        {
            return true;
        }
        if (lhs.m_pData->contentsId != lhr.m_pData->contentsId)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

} }