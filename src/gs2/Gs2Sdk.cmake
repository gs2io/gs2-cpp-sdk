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

if(NOT GS2_ALREADY_INCLUDED_Gs2Sdk)
    set(GS2_ALREADY_INCLUDED_Gs2Sdk True)
    set(GS2_CURRENT_LIST_DIR_Gs2Sdk ${CMAKE_CURRENT_LIST_DIR})

    add_custom_target(gs2-cpp-sdk-all)

    set(GS2_SDK_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
    set(GS2_SDK_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

    if(NOT GS2_SDK_LIBRARY_IMPORT_DIRECTORY)
        set(GS2_SDK_LIBRARY_IMPORT_DIRECTORY "${GS2_SDK_LIBRARY_OUTPUT_DIRECTORY}")
    endif(NOT GS2_SDK_LIBRARY_IMPORT_DIRECTORY)
    set(GS2_LIBRARY_PREFIX ${CMAKE_STATIC_LIBRARY_PREFIX})
    set(GS2_LIBRARY_SUFFIX ${CMAKE_STATIC_LIBRARY_SUFFIX})

    function(gs2_add_library target_name type source_files)
        if(GS2_SDK_PREBUILT)
            add_library(${target_name} ${type} IMPORTED GLOBAL)
            set_target_properties(${PROJECT_NAME} PROPERTIES
                    IMPORTED_LOCATION "${GS2_SDK_LIBRARY_IMPORT_DIRECTORY}/${GS2_LIBRARY_PREFIX}${target_name}${GS2_LIBRARY_SUFFIX}"
                    )
        else(GS2_SDK_PREBUILT)
            add_library(${target_name} ${type}
                    ${source_files}
                    )
            set_target_properties(${PROJECT_NAME} PROPERTIES
                    ARCHIVE_OUTPUT_DIRECTORY "${GS2_SDK_ARCHIVE_OUTPUT_DIRECTORY}"
                    LIBRARY_OUTPUT_DIRECTORY "${GS2_SDK_LIBRARY_OUTPUT_DIRECTORY}"
                    )

        endif(GS2_SDK_PREBUILT)
    endfunction()

    function(gs2_target_include_directories target_name type include_directories)
        if(GS2_SDK_PREBUILT)
            if(NOT (${type} STREQUAL "PRIVATE"))
                target_include_directories(${target_name}
                        INTERFACE ${include_directories}
                        )
            endif()
        else(GS2_SDK_PREBUILT)
            target_include_directories(${target_name}
                    ${type} ${include_directories}
                    )
        endif(GS2_SDK_PREBUILT)
    endfunction()

    function(gs2_target_link_libraries target_name type link_libraries)
        if(GS2_SDK_PREBUILT)
            if(NOT (${type} STREQUAL "PRIVATE"))
                target_link_libraries(${target_name}
                        INTERFACE ${link_libraries}
                        )
            endif()
        else(GS2_SDK_PREBUILT)
            target_link_libraries(${target_name}
                    ${type} ${link_libraries}
                    )
        endif(GS2_SDK_PREBUILT)
    endfunction()

    function(gs2_add_dependencies target_name dependencies)
        if(NOT GS2_SDK_PREBUILT)
            add_dependencies(${target_name}
                    ${dependencies}
                    )
        endif(NOT GS2_SDK_PREBUILT)
    endfunction()

    include(CheckFunctionExists)

    function(gs2_inherit_cocos2dx_settings target_name)
        # 以下の関数が存在しないバージョンでは CocosCompileOptions.cmake でグローバルに設定が反映されているので、個別設定は不要
        check_function_exists(use_cocos2dx_compile_define function_exists)
        if(${function_exists})
            use_cocos2dx_compile_define(${target_name})
        endif()
        check_function_exists(use_cocos2dx_compile_options function_exists)
        if(${function_exists})
            use_cocos2dx_compile_options(${target_name})
        endif()
    endfunction()
endif()
