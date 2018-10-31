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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MQTT_SUBSCRIBEREQUEST_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MQTT_SUBSCRIBEREQUEST_HPP_

#include "../common.hpp"
#include "AbstractRequest.hpp"

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE
namespace detail2 {

class SubscribeRequest : public AbstractRequest {
private:
    const Char **m_pTopics;
    UInt32 m_NumberOfTopics;

    virtual UInt32 getRemainingMessageLength() const;

public:
    SubscribeRequest();

    // NOTICE: 現在の挙動ではポインタのコピーしかしないため、メッセージ長の取得やエンコード時には渡したバッファが生存している必要があります
    SubscribeRequest &withTopics(const Char* topics[], UInt32 numberOfTopics) {
        m_pTopics = topics;
        m_NumberOfTopics = numberOfTopics;
        return *this;
    }

    virtual void dump(MessageBufferProxy &messageBufferProxy) const;
};

}
GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE

#endif //GS2_INGAMEPUSHNOTIFICATION_MQTT_SUBSCRIBEREQUEST_HPP_
