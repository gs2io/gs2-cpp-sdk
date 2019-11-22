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

#include "NotificationType.hpp"
#include <gs2/core/json/JsonParser.hpp>
#include <cstring>

namespace gs2 { namespace chat {

NotificationType::Data::Data(const Data& data) :
    detail::json::IModel(data),
    category(data.category),
    enableTransferMobilePushNotification(data.enableTransferMobilePushNotification)
{
}

void NotificationType::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "category") == 0)
    {
        if (jsonValue.IsInt())
        {
            this->category = jsonValue.GetInt();
        }
    }
    else if (std::strcmp(name_, "enableTransferMobilePushNotification") == 0)
    {
        if (jsonValue.IsBool())
        {
            this->enableTransferMobilePushNotification = jsonValue.GetBool();
        }
    }
}

NotificationType NotificationType::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(NotificationType);
}

bool operator!=(const NotificationType& lhs, const NotificationType& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->category != lhr.m_pData->category)
        {
            return true;
        }
        if (lhs.m_pData->enableTransferMobilePushNotification != lhr.m_pData->enableTransferMobilePushNotification)
        {
            return true;
        }
    }
    return false;
}

} }