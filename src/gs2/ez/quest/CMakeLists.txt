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
project(gs2-cpp-sdk-ez-quest)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzNamespace.hpp
        model/EzQuestGroupModelMaster.hpp
        model/EzQuestModelMaster.hpp
        model/EzCurrentQuestMaster.hpp
        model/EzResponseCache.hpp
        model/EzContents.hpp
        model/EzConsumeAction.hpp
        model/EzAcquireAction.hpp
        model/EzReward.hpp
        model/EzConfig.hpp
        model/EzGitHubCheckoutSetting.hpp
        model/EzScriptSetting.hpp
        model/EzLogSetting.hpp
        model/EzProgress.hpp
        model/EzCompletedQuestList.hpp
        model/EzQuestGroupModel.hpp
        model/EzQuestModel.hpp
        result/EzStartResult.hpp
        result/EzEndResult.hpp
        result/EzGetProgressResult.hpp
        result/EzDeleteProgressResult.hpp
        result/EzDescribeCompletedQuestListsResult.hpp
        result/EzGetCompletedQuestListResult.hpp
        result/EzListQuestGroupsResult.hpp
        result/EzGetQuestGroupResult.hpp
        result/EzListQuestsResult.hpp
        result/EzGetQuestResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Client.cpp
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