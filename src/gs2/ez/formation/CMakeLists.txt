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
project(gs2-cpp-sdk-ez-formation)

include(../../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzNamespace.hpp
        model/EzFormModel.hpp
        model/EzFormModelMaster.hpp
        model/EzMoldModel.hpp
        model/EzMoldModelMaster.hpp
        model/EzCurrentFormMaster.hpp
        model/EzMold.hpp
        model/EzForm.hpp
        model/EzSlot.hpp
        model/EzResponseCache.hpp
        model/EzSlotModel.hpp
        model/EzSlotWithSignature.hpp
        model/EzAcquireActionConfig.hpp
        model/EzConfig.hpp
        model/EzGitHubCheckoutSetting.hpp
        model/EzScriptSetting.hpp
        model/EzLogSetting.hpp
        model/EzAcquireAction.hpp
        result/EzListMoldModelsResult.hpp
        result/EzGetMoldModelResult.hpp
        result/EzListMoldsResult.hpp
        result/EzGetMoldResult.hpp
        result/EzListFormsResult.hpp
        result/EzGetFormResult.hpp
        result/EzSetFormResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
        model/EzNamespace.cpp
        model/EzFormModel.cpp
        model/EzFormModelMaster.cpp
        model/EzMoldModel.cpp
        model/EzMoldModelMaster.cpp
        model/EzCurrentFormMaster.cpp
        model/EzMold.cpp
        model/EzForm.cpp
        model/EzSlot.cpp
        model/EzResponseCache.cpp
        model/EzSlotModel.cpp
        model/EzSlotWithSignature.cpp
        model/EzAcquireActionConfig.cpp
        model/EzConfig.cpp
        model/EzGitHubCheckoutSetting.cpp
        model/EzScriptSetting.cpp
        model/EzLogSetting.cpp
        model/EzAcquireAction.cpp
        )

gs2_add_library(${PROJECT_NAME} STATIC
        "${${PROJECT_NAME}_SOURCE_FILES}"
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})

gs2_target_link_libraries(${PROJECT_NAME}
        PUBLIC gs2-cpp-sdk-ez
        )

gs2_add_dependencies(gs2-cpp-sdk-all
        ${PROJECT_NAME}
        )

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )