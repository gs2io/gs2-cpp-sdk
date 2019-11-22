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
project(gs2-cpp-sdk-ranking)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Ranking.hpp
        Gs2RankingConst.hpp
        Gs2RankingRestClient.hpp
        Gs2RankingWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/CategoryModel.hpp
        model/CategoryModelMaster.hpp
        model/Subscribe.hpp
        model/Score.hpp
        model/Ranking.hpp
        model/ResponseCache.hpp
        model/CurrentRankingMaster.hpp
        model/CalculatedAt.hpp
        model/SubscribeUser.hpp
        model/GitHubCheckoutSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeCategoryModelsRequest.hpp
        request/GetCategoryModelRequest.hpp
        request/DescribeCategoryModelMastersRequest.hpp
        request/CreateCategoryModelMasterRequest.hpp
        request/GetCategoryModelMasterRequest.hpp
        request/UpdateCategoryModelMasterRequest.hpp
        request/DeleteCategoryModelMasterRequest.hpp
        request/DescribeSubscribesByCategoryNameRequest.hpp
        request/DescribeSubscribesByCategoryNameAndUserIdRequest.hpp
        request/SubscribeRequest.hpp
        request/SubscribeByUserIdRequest.hpp
        request/GetSubscribeRequest.hpp
        request/GetSubscribeByUserIdRequest.hpp
        request/UnsubscribeRequest.hpp
        request/UnsubscribeByUserIdRequest.hpp
        request/DescribeRankingsRequest.hpp
        request/DescribeRankingssByUserIdRequest.hpp
        request/DescribeNearRankingsRequest.hpp
        request/PutScoreRequest.hpp
        request/PutScoreByUserIdRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentRankingMasterRequest.hpp
        request/UpdateCurrentRankingMasterRequest.hpp
        request/UpdateCurrentRankingMasterFromGitHubRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeCategoryModelsResult.hpp
        result/GetCategoryModelResult.hpp
        result/DescribeCategoryModelMastersResult.hpp
        result/CreateCategoryModelMasterResult.hpp
        result/GetCategoryModelMasterResult.hpp
        result/UpdateCategoryModelMasterResult.hpp
        result/DeleteCategoryModelMasterResult.hpp
        result/DescribeSubscribesByCategoryNameResult.hpp
        result/DescribeSubscribesByCategoryNameAndUserIdResult.hpp
        result/SubscribeResult.hpp
        result/SubscribeByUserIdResult.hpp
        result/GetSubscribeResult.hpp
        result/GetSubscribeByUserIdResult.hpp
        result/UnsubscribeResult.hpp
        result/UnsubscribeByUserIdResult.hpp
        result/DescribeRankingsResult.hpp
        result/DescribeRankingssByUserIdResult.hpp
        result/DescribeNearRankingsResult.hpp
        result/PutScoreResult.hpp
        result/PutScoreByUserIdResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentRankingMasterResult.hpp
        result/UpdateCurrentRankingMasterResult.hpp
        result/UpdateCurrentRankingMasterFromGitHubResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2RankingRestClient.cpp
        Gs2RankingWebSocketClient.cpp
        model/Namespace.cpp
        model/CategoryModel.cpp
        model/CategoryModelMaster.cpp
        model/Subscribe.cpp
        model/Score.cpp
        model/Ranking.cpp
        model/ResponseCache.cpp
        model/CurrentRankingMaster.cpp
        model/CalculatedAt.cpp
        model/SubscribeUser.cpp
        model/GitHubCheckoutSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeCategoryModelsResult.cpp
        result/GetCategoryModelResult.cpp
        result/DescribeCategoryModelMastersResult.cpp
        result/CreateCategoryModelMasterResult.cpp
        result/GetCategoryModelMasterResult.cpp
        result/UpdateCategoryModelMasterResult.cpp
        result/DeleteCategoryModelMasterResult.cpp
        result/DescribeSubscribesByCategoryNameResult.cpp
        result/DescribeSubscribesByCategoryNameAndUserIdResult.cpp
        result/SubscribeResult.cpp
        result/SubscribeByUserIdResult.cpp
        result/GetSubscribeResult.cpp
        result/GetSubscribeByUserIdResult.cpp
        result/UnsubscribeResult.cpp
        result/UnsubscribeByUserIdResult.cpp
        result/DescribeRankingsResult.cpp
        result/DescribeRankingssByUserIdResult.cpp
        result/DescribeNearRankingsResult.cpp
        result/PutScoreResult.cpp
        result/PutScoreByUserIdResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentRankingMasterResult.cpp
        result/UpdateCurrentRankingMasterResult.cpp
        result/UpdateCurrentRankingMasterFromGitHubResult.cpp
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