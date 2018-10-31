# Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
# Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License").
# You may not use this file except in compliance with the License.
# A copy of the License is located at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# or in the "license" file accompanying this file. This file is distributed
# on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
# express or implied. See the License for the specific language governing
# permissions and limitations under the License.

cmake_minimum_required(VERSION 3.2)
project(gs2-cpp-sdk-in-game-push-notification)

set(CMAKE_CXX_STANDARD 11)

include_directories(../../)
include_directories(${cocos2d-x_SOURCE_DIR}/cocos)

if(GS2_LINUX)
    add_definitions(-DLINUX)
endif(GS2_LINUX)


file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2InGamePushNotification.hpp
        Gs2InGamePushNotificationClient.hpp
        Gs2InGamePushNotificationConst.hpp
        common.hpp
        control/CreateCertificateRequest.hpp
        control/CreateCertificateResult.hpp
        control/CreateGameRequest.hpp
        control/CreateGameResult.hpp
        control/DeleteCertificateRequest.hpp
        control/DeleteGameRequest.hpp
        control/DescribeGameRequest.hpp
        control/DescribeGameResult.hpp
        control/DescribeServiceClassRequest.hpp
        control/DescribeServiceClassResult.hpp
        control/DescribeStatusRequest.hpp
        control/DescribeStatusResult.hpp
        control/GetGameRequest.hpp
        control/GetGameResult.hpp
        control/GetGameStatusRequest.hpp
        control/GetGameStatusResult.hpp
        control/GetMqttHostRequest.hpp
        control/GetMqttHostResult.hpp
        control/GetWebSocketHostRequest.hpp
        control/GetWebSocketHostResult.hpp
        control/PublishRequest.hpp
        control/PublishResult.hpp
        control/SetFirebaseTokenRequest.hpp
        control/SetFirebaseTokenResult.hpp
        control/UpdateGameRequest.hpp
        control/UpdateGameResult.hpp
        control/controller.hpp
        macros.hpp
        model/Certificate.hpp
        model/FirebaseToken.hpp
        model/Game.hpp
        model/MqttHost.hpp
        model/PublishResponse.hpp
        model/Status.hpp
        model/WebSocketHost.hpp
        model/model.hpp
        mqtt/AbstractRequest.hpp
        mqtt/ConnectRequest.hpp
        mqtt/ConnectResponse.hpp
        mqtt/EventHandler.hpp
        mqtt/MessageBufferProxy.hpp
        mqtt/MqttClient.hpp
        mqtt/MqttTypes.hpp
        mqtt/PingRequest.hpp
        mqtt/PublishResponse.hpp
        mqtt/SubscribeRequest.hpp
        mqtt/mqtt.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        mqtt/ConnectRequest.cpp
        mqtt/ConnectResponse.cpp
        mqtt/MqttClient.cpp
        mqtt/PingRequest.cpp
        mqtt/PublishResponse.cpp
        mqtt/SubscribeRequest.cpp
        )

file(GLOB ${PROJECT_NAME}_ETC_FILES
        )

set(${PROJECT_NAME}_FILES
        ${${PROJECT_NAME}_HEADER_FILES}
        ${${PROJECT_NAME}_SOURCE_FILES}
        ${${PROJECT_NAME}_ETC_FILES}
        )


add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        ${EXTERNAL_SOURCE_FILES}
        )

add_dependencies(${PROJECT_NAME}
        gs2-cpp-sdk-core
        )
