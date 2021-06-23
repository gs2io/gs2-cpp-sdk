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
project(gs2-cpp-sdk-core)

include(../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        AbstractGs2Client.hpp
        AsyncResult.hpp
        common.hpp
        control/Gs2BasicRequest.hpp
        exception/Gs2ClientException.hpp
        external/optional/optional.hpp
        Gs2Constant.hpp
        Gs2Core.hpp
        Gs2Object.hpp
        IAllocator.hpp
        json/Allocator.hpp
        json/IModel.hpp
        json/JsonParser.hpp
        json/JsonWriter.hpp
        macros.hpp
        model/BasicGs2Credential.hpp
        model/IGs2Credential.hpp
        model/NotificationMessage.hpp
        model/Region.hpp
        model/RequestError.hpp
        model/SignedStampSheet.hpp
        model/SignedStampTask.hpp
        model/StampSheet.hpp
        model/StampTask.hpp
        network/Gs2Response.hpp
        network/Gs2RestResponse.hpp
        network/Gs2RestSession.hpp
        network/Gs2RestSessionTask.hpp
        network/Gs2Session.hpp
        network/Gs2SessionTask.hpp
        network/Gs2SessionTaskId.hpp
        network/Gs2WebSocketResponse.hpp
        network/Gs2WebSocketSession.hpp
        network/Gs2WebSocketSessionTask.hpp
        network/HttpTask.hpp
        network/LoginResultModel.hpp
        network/RootCaCertificates.hpp
        network/WebSocket.hpp
        types.hpp
        util/Base64.hpp
        util/DefaultAllocator.hpp
        util/IntrusiveList.hpp
        util/List.hpp
        util/StandardAllocator.hpp
        util/StringHolder.hpp
        util/StringVariable.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2_Core_AbstractGs2Client.cpp
        Gs2_Core_Gs2Constant.cpp
        Gs2_Core_Gs2Object.cpp
        json/Gs2_Core_Json_Allocator.cpp
        json/Gs2_Core_Json_JsonParser.cpp
        json/Gs2_Core_Json_JsonWriter.cpp
        model/Gs2_Core_Model_BasicGs2Credential.cpp
        model/Gs2_Core_Model_Region.cpp
        network/Gs2_Core_Network_Gs2Response.cpp
        network/Gs2_Core_Network_Gs2RestResponse.cpp
        network/Gs2_Core_Network_Gs2RestSession.cpp
        network/Gs2_Core_Network_Gs2RestSessionTask.cpp
        network/Gs2_Core_Network_Gs2Session.cpp
        network/Gs2_Core_Network_Gs2SessionTask.cpp
        network/Gs2_Core_Network_Gs2SessionTaskId.cpp
        network/Gs2_Core_Network_Gs2WebSocketResponse.cpp
        network/Gs2_Core_Network_Gs2WebSocketSession.cpp
        network/Gs2_Core_Network_Gs2WebSocketSessionTask.cpp
        network/Gs2_Core_Network_HttpTask.cpp
        network/Gs2_Core_Network_RootCaCertificates.cpp
        network/Gs2_Core_Network_WebSocket.cpp
        util/Gs2_Core_Util_Base64.cpp
        util/Gs2_Core_Util_DefaultAllocator.cpp
        util/Gs2_Core_Util_StringHolder.cpp
        util/Gs2_Core_Util_StringVariable.cpp
        )

file(GLOB ${PROJECT_NAME}_ETC_FILES
        )

set(${PROJECT_NAME}_FILES
        ${${PROJECT_NAME}_HEADER_FILES}
        ${${PROJECT_NAME}_SOURCE_FILES}
        ${${PROJECT_NAME}_ETC_FILES}
        )


gs2_add_library(${PROJECT_NAME} STATIC
        "${${PROJECT_NAME}_SOURCE_FILES}"
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})

gs2_target_include_directories(${PROJECT_NAME}
        PUBLIC ../..
        )

gs2_target_link_libraries(${PROJECT_NAME}
        PUBLIC cocos2d
        )

set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/../../"
        )

gs2_add_dependencies(gs2-cpp-sdk-all
        ${PROJECT_NAME}
        )

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )

include(external/Gs2CoreExternal.cmake)

set(gs2-cpp-sdk_FILES
        ${gs2-cpp-sdk_FILES}
        ${${PROJECT_NAME}_FILES}
        PARENT_SCOPE
        )
