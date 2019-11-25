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
