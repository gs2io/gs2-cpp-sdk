/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MQTT_PUBLISHRESPONSE_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MQTT_PUBLISHRESPONSE_HPP_

#include "../common.hpp"
#include <gs2/core/Gs2Object.hpp>

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE
namespace detail2 {

class PublishResponse : public Gs2Object {
private:
    const void *m_Payload;
    UInt32 m_PayloadSize;

public:
    PublishResponse(void *message, UInt32 size);

    const void *getPayload() const {
        return m_Payload;
    }

    UInt32 getPayloadSize() const {
        return m_PayloadSize;
    }
};

}
GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE

#endif //GS2_INGAMEPUSHNOTIFICATION_MQTT_PUBLISHRESPONSE_HPP_
