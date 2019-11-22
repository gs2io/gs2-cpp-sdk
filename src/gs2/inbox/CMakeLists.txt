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
project(gs2-cpp-sdk-inbox)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Inbox.hpp
        Gs2InboxConst.hpp
        Gs2InboxRestClient.hpp
        Gs2InboxWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Message.hpp
        model/ResponseCache.hpp
        model/Config.hpp
        model/ScriptSetting.hpp
        model/NotificationSetting.hpp
        model/LogSetting.hpp
        model/AcquireAction.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeMessagesRequest.hpp
        request/DescribeMessagesByUserIdRequest.hpp
        request/SendMessageByUserIdRequest.hpp
        request/GetMessageRequest.hpp
        request/GetMessageByUserIdRequest.hpp
        request/OpenMessageRequest.hpp
        request/OpenMessageByUserIdRequest.hpp
        request/ReadMessageRequest.hpp
        request/ReadMessageByUserIdRequest.hpp
        request/DeleteMessageRequest.hpp
        request/DeleteMessageByUserIdRequest.hpp
        request/OpenByStampTaskRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeMessagesResult.hpp
        result/DescribeMessagesByUserIdResult.hpp
        result/SendMessageByUserIdResult.hpp
        result/GetMessageResult.hpp
        result/GetMessageByUserIdResult.hpp
        result/OpenMessageResult.hpp
        result/OpenMessageByUserIdResult.hpp
        result/ReadMessageResult.hpp
        result/ReadMessageByUserIdResult.hpp
        result/DeleteMessageResult.hpp
        result/DeleteMessageByUserIdResult.hpp
        result/OpenByStampTaskResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2InboxRestClient.cpp
        Gs2InboxWebSocketClient.cpp
        model/Namespace.cpp
        model/Message.cpp
        model/ResponseCache.cpp
        model/Config.cpp
        model/ScriptSetting.cpp
        model/NotificationSetting.cpp
        model/LogSetting.cpp
        model/AcquireAction.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeMessagesResult.cpp
        result/DescribeMessagesByUserIdResult.cpp
        result/SendMessageByUserIdResult.cpp
        result/GetMessageResult.cpp
        result/GetMessageByUserIdResult.cpp
        result/OpenMessageResult.cpp
        result/OpenMessageByUserIdResult.cpp
        result/ReadMessageResult.cpp
        result/ReadMessageByUserIdResult.cpp
        result/DeleteMessageResult.cpp
        result/DeleteMessageByUserIdResult.cpp
        result/OpenByStampTaskResult.cpp
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