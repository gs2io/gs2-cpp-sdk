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
project(gs2-cpp-sdk-auth)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Auth.hpp
        Gs2AuthConst.hpp
        Gs2AuthRestClient.hpp
        Gs2AuthWebSocketClient.hpp
        model/model.hpp
        model/AccessToken.hpp
        request/LoginRequest.hpp
        request/LoginBySignatureRequest.hpp
        result/LoginResult.hpp
        result/LoginBySignatureResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2AuthRestClient.cpp
        Gs2AuthWebSocketClient.cpp
        model/AccessToken.cpp
        result/LoginResult.cpp
        result/LoginBySignatureResult.cpp
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