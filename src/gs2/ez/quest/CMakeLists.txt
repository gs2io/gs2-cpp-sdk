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

include(../../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzContents.hpp
        model/EzConsumeAction.hpp
        model/EzAcquireAction.hpp
        model/EzReward.hpp
        model/EzConfig.hpp
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
        Gs2_Ez_Quest_Client.cpp
        model/Gs2_Ez_Quest_EzContents.cpp
        model/Gs2_Ez_Quest_EzConsumeAction.cpp
        model/Gs2_Ez_Quest_EzAcquireAction.cpp
        model/Gs2_Ez_Quest_EzReward.cpp
        model/Gs2_Ez_Quest_EzConfig.cpp
        model/Gs2_Ez_Quest_EzProgress.cpp
        model/Gs2_Ez_Quest_EzCompletedQuestList.cpp
        model/Gs2_Ez_Quest_EzQuestGroupModel.cpp
        model/Gs2_Ez_Quest_EzQuestModel.cpp
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