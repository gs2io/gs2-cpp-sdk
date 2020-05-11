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
project(gs2-cpp-sdk-ez-mission)

include(../../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzNamespace.hpp
        model/EzCounter.hpp
        model/EzCounterModelMaster.hpp
        model/EzMissionTaskModelMaster.hpp
        model/EzConfig.hpp
        model/EzMissionTaskModel.hpp
        model/EzResponseCache.hpp
        model/EzCounterScopeModel.hpp
        model/EzCounterModel.hpp
        model/EzComplete.hpp
        model/EzAcquireAction.hpp
        model/EzLogSetting.hpp
        model/EzMissionGroupModelMaster.hpp
        model/EzScriptSetting.hpp
        model/EzMissionGroupModel.hpp
        model/EzCurrentMissionMaster.hpp
        model/EzScopedValue.hpp
        model/EzGitHubCheckoutSetting.hpp
        model/EzNotificationSetting.hpp
        result/EzListCountersResult.hpp
        result/EzGetCounterResult.hpp
        result/EzListMissionTaskModelsResult.hpp
        result/EzGetMissionTaskModelResult.hpp
        result/EzListCounterModelsResult.hpp
        result/EzGetCounterModelResult.hpp
        result/EzListCompletesResult.hpp
        result/EzGetCompleteResult.hpp
        result/EzReceiveRewardsResult.hpp
        result/EzListMissionGroupModelsResult.hpp
        result/EzGetMissionGroupModelResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
        model/EzNamespace.cpp
        model/EzCounter.cpp
        model/EzCounterModelMaster.cpp
        model/EzMissionTaskModelMaster.cpp
        model/EzConfig.cpp
        model/EzMissionTaskModel.cpp
        model/EzResponseCache.cpp
        model/EzCounterScopeModel.cpp
        model/EzCounterModel.cpp
        model/EzComplete.cpp
        model/EzAcquireAction.cpp
        model/EzLogSetting.cpp
        model/EzMissionGroupModelMaster.cpp
        model/EzScriptSetting.cpp
        model/EzMissionGroupModel.cpp
        model/EzCurrentMissionMaster.cpp
        model/EzScopedValue.cpp
        model/EzGitHubCheckoutSetting.cpp
        model/EzNotificationSetting.cpp
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