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
project(gs2-cpp-sdk-ez-version)

include(../../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzNamespace.hpp
        model/EzVersionModelMaster.hpp
        model/EzVersion.hpp
        model/EzVersionModel.hpp
        model/EzAcceptVersion.hpp
        model/EzStatus.hpp
        model/EzTargetVersion.hpp
        model/EzSignTargetVersion.hpp
        model/EzResponseCache.hpp
        model/EzCurrentVersionMaster.hpp
        model/EzScriptSetting.hpp
        model/EzGitHubCheckoutSetting.hpp
        model/EzLogSetting.hpp
        result/EzListVersionModelsResult.hpp
        result/EzGetVersionModelResult.hpp
        result/EzListResult.hpp
        result/EzDeleteResult.hpp
        result/EzCheckVersionResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
        model/EzNamespace.cpp
        model/EzVersionModelMaster.cpp
        model/EzVersion.cpp
        model/EzVersionModel.cpp
        model/EzAcceptVersion.cpp
        model/EzStatus.cpp
        model/EzTargetVersion.cpp
        model/EzSignTargetVersion.cpp
        model/EzResponseCache.cpp
        model/EzCurrentVersionMaster.cpp
        model/EzScriptSetting.cpp
        model/EzGitHubCheckoutSetting.cpp
        model/EzLogSetting.cpp
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