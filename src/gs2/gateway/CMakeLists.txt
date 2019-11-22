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
project(gs2-cpp-sdk-gateway)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Gateway.hpp
        Gs2GatewayConst.hpp
        Gs2GatewayRestClient.hpp
        Gs2GatewayWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/WebSocketSession.hpp
        model/FirebaseToken.hpp
        model/ResponseCache.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeWebSocketSessionsRequest.hpp
        request/DescribeWebSocketSessionsByUserIdRequest.hpp
        request/SetUserIdRequest.hpp
        request/SetUserIdByUserIdRequest.hpp
        request/GetWebSocketSessionRequest.hpp
        request/GetWebSocketSessionByConnectionIdRequest.hpp
        request/SendNotificationRequest.hpp
        request/SetFirebaseTokenRequest.hpp
        request/SetFirebaseTokenByUserIdRequest.hpp
        request/GetFirebaseTokenRequest.hpp
        request/GetFirebaseTokenByUserIdRequest.hpp
        request/DeleteFirebaseTokenRequest.hpp
        request/DeleteFirebaseTokenByUserIdRequest.hpp
        request/SendMobileNotificationByUserIdRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeWebSocketSessionsResult.hpp
        result/DescribeWebSocketSessionsByUserIdResult.hpp
        result/SetUserIdResult.hpp
        result/SetUserIdByUserIdResult.hpp
        result/GetWebSocketSessionResult.hpp
        result/GetWebSocketSessionByConnectionIdResult.hpp
        result/SendNotificationResult.hpp
        result/SetFirebaseTokenResult.hpp
        result/SetFirebaseTokenByUserIdResult.hpp
        result/GetFirebaseTokenResult.hpp
        result/GetFirebaseTokenByUserIdResult.hpp
        result/DeleteFirebaseTokenResult.hpp
        result/DeleteFirebaseTokenByUserIdResult.hpp
        result/SendMobileNotificationByUserIdResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2GatewayRestClient.cpp
        Gs2GatewayWebSocketClient.cpp
        model/Namespace.cpp
        model/WebSocketSession.cpp
        model/FirebaseToken.cpp
        model/ResponseCache.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeWebSocketSessionsResult.cpp
        result/DescribeWebSocketSessionsByUserIdResult.cpp
        result/SetUserIdResult.cpp
        result/SetUserIdByUserIdResult.cpp
        result/GetWebSocketSessionResult.cpp
        result/GetWebSocketSessionByConnectionIdResult.cpp
        result/SendNotificationResult.cpp
        result/SetFirebaseTokenResult.cpp
        result/SetFirebaseTokenByUserIdResult.cpp
        result/GetFirebaseTokenResult.cpp
        result/GetFirebaseTokenByUserIdResult.cpp
        result/DeleteFirebaseTokenResult.cpp
        result/DeleteFirebaseTokenByUserIdResult.cpp
        result/SendMobileNotificationByUserIdResult.cpp
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