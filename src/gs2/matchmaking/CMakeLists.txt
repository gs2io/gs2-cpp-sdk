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
project(gs2-cpp-sdk-matchmaking)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Matchmaking.hpp
        Gs2MatchmakingConst.hpp
        Gs2MatchmakingRestClient.hpp
        Gs2MatchmakingWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Gathering.hpp
        model/ResponseCache.hpp
        model/NotificationSetting.hpp
        model/LogSetting.hpp
        model/AttributeRange.hpp
        model/CapacityOfRole.hpp
        model/Attribute.hpp
        model/Player.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeGatheringsRequest.hpp
        request/CreateGatheringRequest.hpp
        request/CreateGatheringByUserIdRequest.hpp
        request/UpdateGatheringRequest.hpp
        request/UpdateGatheringByUserIdRequest.hpp
        request/DoMatchmakingByPlayerRequest.hpp
        request/DoMatchmakingRequest.hpp
        request/GetGatheringRequest.hpp
        request/CancelMatchmakingRequest.hpp
        request/CancelMatchmakingByUserIdRequest.hpp
        request/DeleteGatheringRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeGatheringsResult.hpp
        result/CreateGatheringResult.hpp
        result/CreateGatheringByUserIdResult.hpp
        result/UpdateGatheringResult.hpp
        result/UpdateGatheringByUserIdResult.hpp
        result/DoMatchmakingByPlayerResult.hpp
        result/DoMatchmakingResult.hpp
        result/GetGatheringResult.hpp
        result/CancelMatchmakingResult.hpp
        result/CancelMatchmakingByUserIdResult.hpp
        result/DeleteGatheringResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2MatchmakingRestClient.cpp
        Gs2MatchmakingWebSocketClient.cpp
        model/Namespace.cpp
        model/Gathering.cpp
        model/ResponseCache.cpp
        model/NotificationSetting.cpp
        model/LogSetting.cpp
        model/AttributeRange.cpp
        model/CapacityOfRole.cpp
        model/Attribute.cpp
        model/Player.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeGatheringsResult.cpp
        result/CreateGatheringResult.cpp
        result/CreateGatheringByUserIdResult.cpp
        result/UpdateGatheringResult.cpp
        result/UpdateGatheringByUserIdResult.cpp
        result/DoMatchmakingByPlayerResult.cpp
        result/DoMatchmakingResult.cpp
        result/GetGatheringResult.cpp
        result/CancelMatchmakingResult.cpp
        result/CancelMatchmakingByUserIdResult.cpp
        result/DeleteGatheringResult.cpp
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