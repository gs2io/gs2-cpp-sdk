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

if(NOT GS2_ALREADY_INCLUDED_Gs2ImportCocos2dx)
    set(GS2_ALREADY_INCLUDED_Gs2ImportCocos2dx True)
    set(GS2_CURRENT_LIST_DIR_Gs2ImportCocos2dx ${CMAKE_CURRENT_LIST_DIR})
    set(GS2_PROJECT_NAME_Gs2ImportCocos2dx ${PROJECT_NAME})

    project(Cocos2d-x)

    # 上位の CMakeLists.txt や外部から cocos2d-x_SOURCE_DIR が指定されていなければアーカイブを取得して展開する
    # （これによって cocos2d-x_(SOURCE|BINARAY)_DIR が指定される）
    # NOTE: 外部から指定する場合は絶対パスで指定すること
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

    include(CocosBuildSet)

    if(WINDOWS)
        add_compile_options(/source-charset:utf-8 /EHs)
    endif()

    if(NOT GS2_SUBDIRECTORY_ALREADY_ADDED_cocos2d-x)
        option(BUILD_CPP_TESTS "Build TestCpp samples" OFF)
        option(BUILD_CPP_EMPTY_TEST "Build TestCpp samples" OFF)
        option(BUILD_LUA_LIBS "Build lua libraries" OFF)
        option(BUILD_JS_LIBS "Build js libraries" OFF)
        add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)
        # GS2_PREBUILT_COCOS2DX_LIBRARY_PATH が指定されていればライブラリの探索先に追加し、
        # そうでなければ cocos2d-x_SOURCE_DIR をビルド対象に含める
        if(GS2_PREBUILT_COCOS2DX_LIBRARY_PATH)
            add_library(gs2_cocos2d STATIC IMPORTED)
            set_target_properties(gs2_cocos2d
                    PROPERTIES
                    IMPORTED_LOCATION ${GS2_PREBUILT_COCOS2DX_LIBRARY_PATH}
                    )

            cmake_policy(SET CMP0079 NEW)
            target_link_libraries(cocos2d gs2_cocos2d)
            # Cocos2d-x 自体のビルドは不要なので、簡略化のために空のファイル一つに置き換える
            set_target_properties(cocos2d
                    PROPERTIES
                    SOURCES ${GS2_CURRENT_LIST_DIR_Gs2ImportCocos2dx}/dummy.cpp
                    )
        endif(GS2_PREBUILT_COCOS2DX_LIBRARY_PATH)
        set(GS2_SUBDIRECTORY_ALREADY_ADDED_cocos2d-x True PARENT_SCOPE)
    endif(NOT GS2_SUBDIRECTORY_ALREADY_ADDED_cocos2d-x)

    project(${GS2_PROJECT_NAME_Gs2ImportCocos2dx})
endif()
