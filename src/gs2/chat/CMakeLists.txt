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
project(gs2-cpp-sdk-chat)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Chat.hpp
        Gs2ChatConst.hpp
        Gs2ChatRestClient.hpp
        Gs2ChatWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Room.hpp
        model/Message.hpp
        model/Subscribe.hpp
        model/ResponseCache.hpp
        model/NotificationType.hpp
        model/ScriptSetting.hpp
        model/NotificationSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeRoomsRequest.hpp
        request/CreateRoomRequest.hpp
        request/CreateRoomFromBackendRequest.hpp
        request/GetRoomRequest.hpp
        request/UpdateRoomRequest.hpp
        request/DeleteRoomRequest.hpp
        request/DeleteRoomFromBackendRequest.hpp
        request/DescribeMessagesRequest.hpp
        request/PostRequest.hpp
        request/PostByUserIdRequest.hpp
        request/GetMessageRequest.hpp
        request/DeleteMessageRequest.hpp
        request/DescribeSubscribesRequest.hpp
        request/DescribeSubscribesByUserIdRequest.hpp
        request/DescribeSubscribesByRoomNameRequest.hpp
        request/SubscribeRequest.hpp
        request/SubscribeByUserIdRequest.hpp
        request/GetSubscribeRequest.hpp
        request/GetSubscribeByUserIdRequest.hpp
        request/UpdateNotificationTypeRequest.hpp
        request/UpdateNotificationTypeByUserIdRequest.hpp
        request/UnsubscribeRequest.hpp
        request/UnsubscribeByUserIdRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeRoomsResult.hpp
        result/CreateRoomResult.hpp
        result/CreateRoomFromBackendResult.hpp
        result/GetRoomResult.hpp
        result/UpdateRoomResult.hpp
        result/DeleteRoomResult.hpp
        result/DeleteRoomFromBackendResult.hpp
        result/DescribeMessagesResult.hpp
        result/PostResult.hpp
        result/PostByUserIdResult.hpp
        result/GetMessageResult.hpp
        result/DeleteMessageResult.hpp
        result/DescribeSubscribesResult.hpp
        result/DescribeSubscribesByUserIdResult.hpp
        result/DescribeSubscribesByRoomNameResult.hpp
        result/SubscribeResult.hpp
        result/SubscribeByUserIdResult.hpp
        result/GetSubscribeResult.hpp
        result/GetSubscribeByUserIdResult.hpp
        result/UpdateNotificationTypeResult.hpp
        result/UpdateNotificationTypeByUserIdResult.hpp
        result/UnsubscribeResult.hpp
        result/UnsubscribeByUserIdResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2ChatRestClient.cpp
        Gs2ChatWebSocketClient.cpp
        model/Namespace.cpp
        model/Room.cpp
        model/Message.cpp
        model/Subscribe.cpp
        model/ResponseCache.cpp
        model/NotificationType.cpp
        model/ScriptSetting.cpp
        model/NotificationSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeRoomsResult.cpp
        result/CreateRoomResult.cpp
        result/CreateRoomFromBackendResult.cpp
        result/GetRoomResult.cpp
        result/UpdateRoomResult.cpp
        result/DeleteRoomResult.cpp
        result/DeleteRoomFromBackendResult.cpp
        result/DescribeMessagesResult.cpp
        result/PostResult.cpp
        result/PostByUserIdResult.cpp
        result/GetMessageResult.cpp
        result/DeleteMessageResult.cpp
        result/DescribeSubscribesResult.cpp
        result/DescribeSubscribesByUserIdResult.cpp
        result/DescribeSubscribesByRoomNameResult.cpp
        result/SubscribeResult.cpp
        result/SubscribeByUserIdResult.cpp
        result/GetSubscribeResult.cpp
        result/GetSubscribeByUserIdResult.cpp
        result/UpdateNotificationTypeResult.cpp
        result/UpdateNotificationTypeByUserIdResult.cpp
        result/UnsubscribeResult.cpp
        result/UnsubscribeByUserIdResult.cpp
        )

add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} gs2-cpp-sdk-core)

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )