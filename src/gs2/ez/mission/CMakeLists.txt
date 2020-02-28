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
        model/EzLogSetting.hpp
        model/EzNamespace.hpp
        model/EzMissionTaskModelMaster.hpp
        model/EzCurrentMissionMaster.hpp
        model/EzScopedValue.hpp
        model/EzNotificationSetting.hpp
        model/EzCounterModelMaster.hpp
        model/EzComplete.hpp
        model/EzCounter.hpp
        model/EzScriptSetting.hpp
        model/EzCounterScopeModel.hpp
        model/EzMissionTaskModel.hpp
        model/EzGitHubCheckoutSetting.hpp
        model/EzCounterModel.hpp
        model/EzResponseCache.hpp
        model/EzAcquireAction.hpp
        model/EzMissionGroupModel.hpp
        model/EzConfig.hpp
        model/EzMissionGroupModelMaster.hpp
        result/EzListCompletesResult.hpp
        result/EzGetCompleteResult.hpp
        result/EzReceiveRewardsResult.hpp
        result/EzListCountersResult.hpp
        result/EzGetCounterResult.hpp
        result/EzListMissionTaskModelsResult.hpp
        result/EzGetMissionTaskModelResult.hpp
        result/EzListCounterModelsResult.hpp
        result/EzGetCounterModelResult.hpp
        result/EzListMissionGroupModelsResult.hpp
        result/EzGetMissionGroupModelResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
        model/EzLogSetting.cpp
        model/EzNamespace.cpp
        model/EzMissionTaskModelMaster.cpp
        model/EzCurrentMissionMaster.cpp
        model/EzScopedValue.cpp
        model/EzNotificationSetting.cpp
        model/EzCounterModelMaster.cpp
        model/EzComplete.cpp
        model/EzCounter.cpp
        model/EzScriptSetting.cpp
        model/EzCounterScopeModel.cpp
        model/EzMissionTaskModel.cpp
        model/EzGitHubCheckoutSetting.cpp
        model/EzCounterModel.cpp
        model/EzResponseCache.cpp
        model/EzAcquireAction.cpp
        model/EzMissionGroupModel.cpp
        model/EzConfig.cpp
        model/EzMissionGroupModelMaster.cpp
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