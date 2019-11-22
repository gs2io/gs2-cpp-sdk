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

#include "DisplayItem.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace showcase {

DisplayItem::Data::Data(const Data& data) :
    detail::json::IModel(data),
    displayItemId(data.displayItemId),
    type(data.type),
    salesPeriodEventId(data.salesPeriodEventId)
{
    if (data.salesItem)
    {
        salesItem = data.salesItem->deepCopy();
    }
    if (data.salesItemGroup)
    {
        salesItemGroup = data.salesItemGroup->deepCopy();
    }
}

void DisplayItem::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "displayItemId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->displayItemId.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "type") == 0)
    {
        if (jsonValue.IsString())
        {
            this->type.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "salesItem") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->salesItem.emplace();
            detail::json::JsonParser::parse(&this->salesItem->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "salesItemGroup") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->salesItemGroup.emplace();
            detail::json::JsonParser::parse(&this->salesItemGroup->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "salesPeriodEventId") == 0)
    {
        if (jsonValue.IsString())
        {
            this->salesPeriodEventId.emplace(jsonValue.GetString());
        }
    }
}

DisplayItem DisplayItem::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DisplayItem);
}

bool operator!=(const DisplayItem& lhs, const DisplayItem& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->displayItemId != lhr.m_pData->displayItemId)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->salesItem != lhr.m_pData->salesItem)
        {
            return true;
        }
        if (lhs.m_pData->salesItemGroup != lhr.m_pData->salesItemGroup)
        {
            return true;
        }
        if (lhs.m_pData->salesPeriodEventId != lhr.m_pData->salesPeriodEventId)
        {
            return true;
        }
    }
    return false;
}

} }