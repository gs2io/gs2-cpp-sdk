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

set(CMAKE_CXX_STANDARD 11)

include_directories(../../)
include_directories(${cocos2d-x_SOURCE_DIR}/cocos)

# external/cryptopp/crc-simd.cpp のビルド対応
add_definitions(-DGS2_CRYPTOPP_DISABLE_SSE4 -DGS2_CRYPTOPP_MANUALLY_INSTANTIATE_TEMPLATES)

if(GS2_LINUX)
    add_definitions(-DLINUX)
endif(GS2_LINUX)


file(GLOB ${PROJECT_NAME}_HEADER_FILES
        AbstractGs2Client.hpp
        AsyncResult.hpp
        common.hpp
        Gs2Constant.hpp
        Gs2Core.hpp
        Gs2Object.hpp
        IAllocator.hpp
        macros.hpp
        types.hpp
        control/Gs2BasicRequest.hpp
        control/Gs2UserRequest.hpp
        exception/Gs2ClientException.hpp
        json/Allocator.hpp
        json/IModel.hpp
        json/JsonParser.hpp
        json/JsonWriter.hpp
        model/BasicGs2Credential.hpp
        model/ErrorResponse.hpp
        model/IGs2Credential.hpp
        model/OnetimeTokenGs2Credential.hpp
        model/Region.hpp
        model/RequestError.hpp
        network/HttpRequest.hpp
        util/Base64.hpp
        util/DefaultAllocator.hpp
        util/List.hpp
        util/SignUtil.hpp
        util/StandardAllocator.hpp
        util/StringHolder.hpp
        util/StringUtil.hpp
        util/StringVariable.hpp
        util/UrlEncoder.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        AbstractGs2Client.cpp
        Gs2Constant.cpp
        Gs2Object.cpp
        control/Gs2BasicRequest.cpp
        json/Allocator.cpp
        json/JsonParser.cpp
        json/JsonWriter.cpp
        model/BasicGs2Credential.cpp
        model/IGs2Credential.cpp
        model/OnetimeTokenGs2Credential.cpp
        model/Region.cpp
        util/Base64.cpp
        util/DefaultAllocator.cpp
        util/SignUtil.cpp
        util/StringHolder.cpp
        util/StringUtil.cpp
        util/StringVariable.cpp
        util/UrlEncoder.cpp
        )

file(GLOB ${PROJECT_NAME}_ETC_FILES
        )

include(external/CopyExternalFiles.cmake)
define_external_file_rule(
        ${CMAKE_CURRENT_LIST_DIR}/../../external/
        ${CMAKE_CURRENT_LIST_DIR}/external/
        EXTERNAL_FILES
        EXTERNAL_SOURCE_FILES
)

set(${PROJECT_NAME}_FILES
        ${${PROJECT_NAME}_HEADER_FILES}
        ${${PROJECT_NAME}_SOURCE_FILES}
        ${${PROJECT_NAME}_ETC_FILES}
        ${EXTERNAL_FILES}
        )


add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        ${EXTERNAL_SOURCE_FILES}
        )

# ライブラリのビルド前に、外部ライブラリの必要なファイルだけをコピーする

add_custom_target(copy_external_files
        DEPENDS ${EXTERNAL_FILES}
        )

add_dependencies(${PROJECT_NAME}
        copy_external_files
        )

set(gs2-cpp-sdk_FILES
        ${gs2-cpp-sdk_FILES}
        ${${PROJECT_NAME}_FILES}
        PARENT_SCOPE
        )
