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

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzNamespace.hpp
        model/EzComplete.hpp
        model/EzAcquireAction.hpp
        model/EzGitHubCheckoutSetting.hpp
        model/EzCounterModelMaster.hpp
        model/EzCounterModel.hpp
        model/EzScopedValue.hpp
        model/EzNotificationSetting.hpp
        model/EzMissionGroupModel.hpp
        model/EzResponseCache.hpp
        model/EzMissionTaskModel.hpp
        model/EzMissionGroupModelMaster.hpp
        model/EzLogSetting.hpp
        model/EzConfig.hpp
        model/EzCounterScopeModel.hpp
        model/EzCounter.hpp
        model/EzMissionTaskModelMaster.hpp
        model/EzCurrentMissionMaster.hpp
        result/EzListCompletesResult.hpp
        result/EzGetCompleteResult.hpp
        result/EzReceiveRewardsResult.hpp
        result/EzListCounterModelsResult.hpp
        result/EzGetCounterModelResult.hpp
        result/EzListMissionGroupModelsResult.hpp
        result/EzGetMissionGroupModelResult.hpp
        result/EzListMissionTaskModelsResult.hpp
        result/EzGetMissionTaskModelResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
        model/EzNamespace.cpp
        model/EzComplete.cpp
        model/EzAcquireAction.cpp
        model/EzGitHubCheckoutSetting.cpp
        model/EzCounterModelMaster.cpp
        model/EzCounterModel.cpp
        model/EzScopedValue.cpp
        model/EzNotificationSetting.cpp
        model/EzMissionGroupModel.cpp
        model/EzResponseCache.cpp
        model/EzMissionTaskModel.cpp
        model/EzMissionGroupModelMaster.cpp
        model/EzLogSetting.cpp
        model/EzConfig.cpp
        model/EzCounterScopeModel.cpp
        model/EzCounter.cpp
        model/EzMissionTaskModelMaster.cpp
        model/EzCurrentMissionMaster.cpp
        )

add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} gs2-cpp-sdk-ez)

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )