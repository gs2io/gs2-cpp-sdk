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
project(gs2-cpp-sdk-realtime)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Realtime.hpp
        Gs2RealtimeConst.hpp
        Gs2RealtimeRestClient.hpp
        Gs2RealtimeWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Room.hpp
        model/NotificationSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeRoomsRequest.hpp
        request/WantRoomRequest.hpp
        request/GetRoomRequest.hpp
        request/DeleteRoomRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeRoomsResult.hpp
        result/WantRoomResult.hpp
        result/GetRoomResult.hpp
        result/DeleteRoomResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2RealtimeRestClient.cpp
        Gs2RealtimeWebSocketClient.cpp
        model/Namespace.cpp
        model/Room.cpp
        model/NotificationSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeRoomsResult.cpp
        result/WantRoomResult.cpp
        result/GetRoomResult.cpp
        result/DeleteRoomResult.cpp
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