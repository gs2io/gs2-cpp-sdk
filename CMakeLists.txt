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

# 上位の CMakeLists.txt や外部から cocos2d-x_SOURCE_DIR が指定されていなければアーカイブを取得して展開する
# （これによって cocos2d-x_(SOURCE|BINARAY)_DIR が指定される）
# NOTE: 外部から指定する場合は絶対パスで指定すること
if(NOT COCOS2DX_ROOT_PATH)
        if(NOT cocos2d-x_SOURCE_DIR)
                download_project(
                        PROJ cocos2d-x
                        # URL http://cocos2d-x.org/filedown/cocos2d-x-3.17.zip
                        URL http://cocos2d-x.org/filedown/start/402
                        UPDATE_DISCONNECTED 1
                )
        endif(NOT cocos2d-x_SOURCE_DIR)

        set(COCOS2DX_ROOT_PATH ${cocos2d-x_SOURCE_DIR})
        set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

        set(CMAKE_CXX_FLAGS "/source-charset:utf-8")

        include(CocosBuildSet)
        add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)

        # Cocos2d-x 自体のビルドは不要なので、簡略化のために空のファイル一つに置き換える
        set_target_properties(cocos2d
                PROPERTIES
                SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/dummy.cpp
                )
endif()

set(GS2_LIBRARY_BUILD True)

add_subdirectory(src/gs2)
