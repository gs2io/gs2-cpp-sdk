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

#include "VersionModel.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace version {

VersionModel::Data::Data(const Data& data) :
    detail::json::IModel(data),
    versionModelId(data.versionModelId),
    name(data.name),
    metadata(data.metadata),
    scope(data.scope),
    needSignature(data.needSignature),
    signatureKeyId(data.signatureKeyId)
{
    if (data.warningVersion)
    {
        warningVersion = data.warningVersion->deepCopy();
    }
    if (data.errorVersion)
    {
        errorVersion = data.errorVersion->deepCopy();
    }
    if (data.currentVersion)
    {
        currentVersion = data.currentVersion->deepCopy();
    }
}

void VersionModel::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "versionModelId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->versionModelId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "name") == 0)
    {
        if (jsonValue.IsString())
        {
            this->name.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "metadata") == 0)
    {
        if (jsonValue.IsString())
        {
            this->metadata.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "warningVersion") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->warningVersion.emplace();
            detail::json::JsonParser::parse(&this->warningVersion->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "errorVersion") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->errorVersion.emplace();
            detail::json::JsonParser::parse(&this->errorVersion->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "scope") == 0)
    {
        if (jsonValue.IsString())
        {
            this->scope.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "currentVersion") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->currentVersion.emplace();
            detail::json::JsonParser::parse(&this->currentVersion->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "needSignature") == 0)
    {
        if (jsonValue.IsBool())
        {
            this->needSignature = jsonValue.GetBool();
        }
    }
    else if (std::strcmp(name_, "signatureKeyId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->signatureKeyId.emplace(jsonValue.GetString());
        }
    }
}

VersionModel VersionModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(VersionModel);
}

bool operator!=(const VersionModel& lhs, const VersionModel& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->versionModelId != lhr.m_pData->versionModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->warningVersion != lhr.m_pData->warningVersion)
        {
            return true;
        }
        if (lhs.m_pData->errorVersion != lhr.m_pData->errorVersion)
        {
            return true;
        }
        if (lhs.m_pData->scope != lhr.m_pData->scope)
        {
            return true;
        }
        if (lhs.m_pData->currentVersion != lhr.m_pData->currentVersion)
        {
            return true;
        }
        if (lhs.m_pData->needSignature != lhr.m_pData->needSignature)
        {
            return true;
        }
        if (lhs.m_pData->signatureKeyId != lhr.m_pData->signatureKeyId)
        {
            return true;
        }
    }
    return false;
}

} }