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
project(gs2-cpp-sdk-quest)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Quest.hpp
        Gs2QuestConst.hpp
        Gs2QuestRestClient.hpp
        Gs2QuestWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/QuestGroupModelMaster.hpp
        model/QuestModelMaster.hpp
        model/CurrentQuestMaster.hpp
        model/ResponseCache.hpp
        model/Contents.hpp
        model/ConsumeAction.hpp
        model/AcquireAction.hpp
        model/Reward.hpp
        model/Config.hpp
        model/GitHubCheckoutSetting.hpp
        model/ScriptSetting.hpp
        model/LogSetting.hpp
        model/Progress.hpp
        model/CompletedQuestList.hpp
        model/QuestGroupModel.hpp
        model/QuestModel.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeQuestGroupModelMastersRequest.hpp
        request/CreateQuestGroupModelMasterRequest.hpp
        request/GetQuestGroupModelMasterRequest.hpp
        request/UpdateQuestGroupModelMasterRequest.hpp
        request/DeleteQuestGroupModelMasterRequest.hpp
        request/DescribeQuestModelMastersRequest.hpp
        request/CreateQuestModelMasterRequest.hpp
        request/GetQuestModelMasterRequest.hpp
        request/UpdateQuestModelMasterRequest.hpp
        request/DeleteQuestModelMasterRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentQuestMasterRequest.hpp
        request/UpdateCurrentQuestMasterRequest.hpp
        request/UpdateCurrentQuestMasterFromGitHubRequest.hpp
        request/DescribeProgressesByUserIdRequest.hpp
        request/CreateProgressByUserIdRequest.hpp
        request/GetProgressRequest.hpp
        request/GetProgressByUserIdRequest.hpp
        request/StartRequest.hpp
        request/StartByUserIdRequest.hpp
        request/EndRequest.hpp
        request/EndByUserIdRequest.hpp
        request/DeleteProgressRequest.hpp
        request/DeleteProgressByUserIdRequest.hpp
        request/CreateProgressByStampSheetRequest.hpp
        request/DeleteProgressByStampTaskRequest.hpp
        request/DescribeCompletedQuestListsRequest.hpp
        request/DescribeCompletedQuestListsByUserIdRequest.hpp
        request/GetCompletedQuestListRequest.hpp
        request/GetCompletedQuestListByUserIdRequest.hpp
        request/DeleteCompletedQuestListByUserIdRequest.hpp
        request/DescribeQuestGroupModelsRequest.hpp
        request/GetQuestGroupModelRequest.hpp
        request/DescribeQuestModelsRequest.hpp
        request/GetQuestModelRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeQuestGroupModelMastersResult.hpp
        result/CreateQuestGroupModelMasterResult.hpp
        result/GetQuestGroupModelMasterResult.hpp
        result/UpdateQuestGroupModelMasterResult.hpp
        result/DeleteQuestGroupModelMasterResult.hpp
        result/DescribeQuestModelMastersResult.hpp
        result/CreateQuestModelMasterResult.hpp
        result/GetQuestModelMasterResult.hpp
        result/UpdateQuestModelMasterResult.hpp
        result/DeleteQuestModelMasterResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentQuestMasterResult.hpp
        result/UpdateCurrentQuestMasterResult.hpp
        result/UpdateCurrentQuestMasterFromGitHubResult.hpp
        result/DescribeProgressesByUserIdResult.hpp
        result/CreateProgressByUserIdResult.hpp
        result/GetProgressResult.hpp
        result/GetProgressByUserIdResult.hpp
        result/StartResult.hpp
        result/StartByUserIdResult.hpp
        result/EndResult.hpp
        result/EndByUserIdResult.hpp
        result/DeleteProgressResult.hpp
        result/DeleteProgressByUserIdResult.hpp
        result/CreateProgressByStampSheetResult.hpp
        result/DeleteProgressByStampTaskResult.hpp
        result/DescribeCompletedQuestListsResult.hpp
        result/DescribeCompletedQuestListsByUserIdResult.hpp
        result/GetCompletedQuestListResult.hpp
        result/GetCompletedQuestListByUserIdResult.hpp
        result/DeleteCompletedQuestListByUserIdResult.hpp
        result/DescribeQuestGroupModelsResult.hpp
        result/GetQuestGroupModelResult.hpp
        result/DescribeQuestModelsResult.hpp
        result/GetQuestModelResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2QuestRestClient.cpp
        Gs2QuestWebSocketClient.cpp
        model/Namespace.cpp
        model/QuestGroupModelMaster.cpp
        model/QuestModelMaster.cpp
        model/CurrentQuestMaster.cpp
        model/ResponseCache.cpp
        model/Contents.cpp
        model/ConsumeAction.cpp
        model/AcquireAction.cpp
        model/Reward.cpp
        model/Config.cpp
        model/GitHubCheckoutSetting.cpp
        model/ScriptSetting.cpp
        model/LogSetting.cpp
        model/Progress.cpp
        model/CompletedQuestList.cpp
        model/QuestGroupModel.cpp
        model/QuestModel.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeQuestGroupModelMastersResult.cpp
        result/CreateQuestGroupModelMasterResult.cpp
        result/GetQuestGroupModelMasterResult.cpp
        result/UpdateQuestGroupModelMasterResult.cpp
        result/DeleteQuestGroupModelMasterResult.cpp
        result/DescribeQuestModelMastersResult.cpp
        result/CreateQuestModelMasterResult.cpp
        result/GetQuestModelMasterResult.cpp
        result/UpdateQuestModelMasterResult.cpp
        result/DeleteQuestModelMasterResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentQuestMasterResult.cpp
        result/UpdateCurrentQuestMasterResult.cpp
        result/UpdateCurrentQuestMasterFromGitHubResult.cpp
        result/DescribeProgressesByUserIdResult.cpp
        result/CreateProgressByUserIdResult.cpp
        result/GetProgressResult.cpp
        result/GetProgressByUserIdResult.cpp
        result/StartResult.cpp
        result/StartByUserIdResult.cpp
        result/EndResult.cpp
        result/EndByUserIdResult.cpp
        result/DeleteProgressResult.cpp
        result/DeleteProgressByUserIdResult.cpp
        result/CreateProgressByStampSheetResult.cpp
        result/DeleteProgressByStampTaskResult.cpp
        result/DescribeCompletedQuestListsResult.cpp
        result/DescribeCompletedQuestListsByUserIdResult.cpp
        result/GetCompletedQuestListResult.cpp
        result/GetCompletedQuestListByUserIdResult.cpp
        result/DeleteCompletedQuestListByUserIdResult.cpp
        result/DescribeQuestGroupModelsResult.cpp
        result/GetQuestGroupModelResult.cpp
        result/DescribeQuestModelsResult.cpp
        result/GetQuestModelResult.cpp
        )

add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCE_FILES}
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} gs2-cpp-sdk-core)

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )