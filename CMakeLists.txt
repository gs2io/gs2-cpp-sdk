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
project(gs2-cpp-sdk)

include(external/DownloadProject/DownloadProject.cmake)

if(NOT COCOS2DX_ROOT_PATH)
    include(cmake/Gs2ImportCocos2dx.cmake)

    # Cocos2d-x 自体のビルドは不要なので、簡略化のために空のファイル一つに置き換える
    set_target_properties(cocos2d
            PROPERTIES
            SOURCES ${CMAKE_CURRENT_LIST_DIR}/cmake/dummy.cpp
            )
endif()

add_subdirectory(src/gs2)

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        PARENT_SCOPE
        )

# パッケージングルール

add_custom_target(gs2-cpp-sdk-package)

add_custom_command(TARGET gs2-cpp-sdk-package
        COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_COMMAND} -E tar c gs2-cocos2dx-sdk_YYYY.MM.R.zip --format=zip gs2
        )

add_dependencies(gs2-cpp-sdk-package
        gs2-cpp-sdk-core-external
        )
