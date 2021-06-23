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

#include "EzNotificationType.hpp"
#include <gs2/chat/model/NotificationType.hpp>


namespace gs2 { namespace ez { namespace chat {

EzNotificationType::Data::Data(const Data& data) :
    Gs2Object(data),
    category(data.category),
    enableTransferMobilePushNotification(data.enableTransferMobilePushNotification)
{
}

EzNotificationType::Data::Data(const gs2::chat::NotificationType& notificationType) :
    category(notificationType.getCategory() ? *notificationType.getCategory() : 0),
    enableTransferMobilePushNotification(notificationType.getEnableTransferMobilePushNotification() ? *notificationType.getEnableTransferMobilePushNotification() : false)
{
}

EzNotificationType::EzNotificationType(gs2::chat::NotificationType notificationType) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(notificationType)
{
}

EzNotificationType EzNotificationType::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzNotificationType);
}

gs2::chat::NotificationType EzNotificationType::ToModel() const
{
    gs2::chat::NotificationType notificationType;
    notificationType.setCategory(getCategory());
    notificationType.setEnableTransferMobilePushNotification(getEnableTransferMobilePushNotification());
    return notificationType;
}

}}}