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

#include "Namespace.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace money {

Namespace::Data::Data(const Data& data) :
    detail::json::IModel(data),
    namespaceId(data.namespaceId),
    ownerId(data.ownerId),
    name(data.name),
    description(data.description),
    priority(data.priority),
    shareFree(data.shareFree),
    currency(data.currency),
    appleKey(data.appleKey),
    googleKey(data.googleKey),
    enableFakeReceipt(data.enableFakeReceipt),
    balance(data.balance),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.createWalletScript)
    {
        createWalletScript = data.createWalletScript->deepCopy();
    }
    if (data.depositScript)
    {
        depositScript = data.depositScript->deepCopy();
    }
    if (data.withdrawScript)
    {
        withdrawScript = data.withdrawScript->deepCopy();
    }
    if (data.logSetting)
    {
        logSetting = data.logSetting->deepCopy();
    }
}

void Namespace::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "namespaceId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->namespaceId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "ownerId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->ownerId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "description") == 0)
    {
        if (jsonValue.IsString())
        {
            this->description.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "priority") == 0)
    {
        if (jsonValue.IsString())
        {
            this->priority.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "shareFree") == 0)
    {
        if (jsonValue.IsBool())
        {
            this->shareFree = jsonValue.GetBool();
        }
    }
    else if (std::strcmp(name_, "currency") == 0)
    {
        if (jsonValue.IsString())
        {
            this->currency.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "appleKey") == 0)
    {
        if (jsonValue.IsString())
        {
            this->appleKey.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "googleKey") == 0)
    {
        if (jsonValue.IsString())
        {
            this->googleKey.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "enableFakeReceipt") == 0)
    {
        if (jsonValue.IsBool())
        {
            this->enableFakeReceipt = jsonValue.GetBool();
        }
    }
    else if (std::strcmp(name_, "createWalletScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->createWalletScript.emplace();
            detail::json::JsonParser::parse(&this->createWalletScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "depositScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->depositScript.emplace();
            detail::json::JsonParser::parse(&this->depositScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "withdrawScript") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->withdrawScript.emplace();
            detail::json::JsonParser::parse(&this->withdrawScript->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "balance") == 0)
    {
        if (jsonValue.IsDouble())
        {
            this->balance = jsonValue.GetDouble();
        }
    }
    else if (std::strcmp(name_, "logSetting") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->logSetting.emplace();
            detail::json::JsonParser::parse(&this->logSetting->getModel(), jsonObject);
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

Namespace Namespace::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Namespace);
}

bool operator!=(const Namespace& lhs, const Namespace& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->namespaceId != lhr.m_pData->namespaceId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->priority != lhr.m_pData->priority)
        {
            return true;
        }
        if (lhs.m_pData->shareFree != lhr.m_pData->shareFree)
        {
            return true;
        }
        if (lhs.m_pData->currency != lhr.m_pData->currency)
        {
            return true;
        }
        if (lhs.m_pData->appleKey != lhr.m_pData->appleKey)
        {
            return true;
        }
        if (lhs.m_pData->googleKey != lhr.m_pData->googleKey)
        {
            return true;
        }
        if (lhs.m_pData->enableFakeReceipt != lhr.m_pData->enableFakeReceipt)
        {
            return true;
        }
        if (lhs.m_pData->createWalletScript != lhr.m_pData->createWalletScript)
        {
            return true;
        }
        if (lhs.m_pData->depositScript != lhr.m_pData->depositScript)
        {
            return true;
        }
        if (lhs.m_pData->withdrawScript != lhr.m_pData->withdrawScript)
        {
            return true;
        }
        if (lhs.m_pData->balance != lhr.m_pData->balance)
        {
            return true;
        }
        if (lhs.m_pData->logSetting != lhr.m_pData->logSetting)
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