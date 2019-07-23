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

set(CMAKE_CXX_STANDARD 11)


include(external/DownloadProject/DownloadProject.cmake)

# 上位の CMakeLists.txt や外部から cocos2d-x_SOURCE_DIR が指定されていなければアーカイブを取得して展開する
# （これによって cocos2d-x_(SOURCE|BINARAY)_DIR が指定される）
# NOTE: 外部から指定する場合は絶対パスで指定すること
if(NOT cocos2d-x_SOURCE_DIR)
    download_project(
            PROJ cocos2d-x
            # URL http://www.cocos2d-x.org/filedown/cocos2d-x-3.16.zip
            URL http://www.cocos2d-x.org/filedown/start/384
            UPDATE_DISCONNECTED 1
    )
endif(NOT cocos2d-x_SOURCE_DIR)


if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    if(GS2_ANDROID)
    else()
        set(GS2_LINUX True)
    endif()
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

add_subdirectory(src/gs2/core)
#add_subdirectory(src/gs2/inGamePushNotification)
