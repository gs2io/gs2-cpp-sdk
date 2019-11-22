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
project(gs2-cpp-sdk-lottery)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Lottery.hpp
        Gs2LotteryConst.hpp
        Gs2LotteryRestClient.hpp
        Gs2LotteryWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/LotteryModelMaster.hpp
        model/PrizeTableMaster.hpp
        model/Box.hpp
        model/LotteryModel.hpp
        model/PrizeTable.hpp
        model/Probability.hpp
        model/CurrentLotteryMaster.hpp
        model/ResponseCache.hpp
        model/GitHubCheckoutSetting.hpp
        model/LogSetting.hpp
        model/Prize.hpp
        model/AcquireAction.hpp
        model/DrawnPrize.hpp
        model/BoxItem.hpp
        model/BoxItems.hpp
        model/Config.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeLotteryModelMastersRequest.hpp
        request/CreateLotteryModelMasterRequest.hpp
        request/GetLotteryModelMasterRequest.hpp
        request/UpdateLotteryModelMasterRequest.hpp
        request/DeleteLotteryModelMasterRequest.hpp
        request/DescribePrizeTableMastersRequest.hpp
        request/CreatePrizeTableMasterRequest.hpp
        request/GetPrizeTableMasterRequest.hpp
        request/UpdatePrizeTableMasterRequest.hpp
        request/DeletePrizeTableMasterRequest.hpp
        request/DescribeBoxesRequest.hpp
        request/DescribeBoxesByUserIdRequest.hpp
        request/GetBoxRequest.hpp
        request/GetBoxByUserIdRequest.hpp
        request/ResetBoxRequest.hpp
        request/ResetBoxByUserIdRequest.hpp
        request/DescribeLotteryModelsRequest.hpp
        request/GetLotteryModelRequest.hpp
        request/DescribePrizeTablesRequest.hpp
        request/GetPrizeTableRequest.hpp
        request/DrawByUserIdRequest.hpp
        request/DescribeProbabilitiesRequest.hpp
        request/DescribeProbabilitiesByUserIdRequest.hpp
        request/DrawByStampSheetRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentLotteryMasterRequest.hpp
        request/UpdateCurrentLotteryMasterRequest.hpp
        request/UpdateCurrentLotteryMasterFromGitHubRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeLotteryModelMastersResult.hpp
        result/CreateLotteryModelMasterResult.hpp
        result/GetLotteryModelMasterResult.hpp
        result/UpdateLotteryModelMasterResult.hpp
        result/DeleteLotteryModelMasterResult.hpp
        result/DescribePrizeTableMastersResult.hpp
        result/CreatePrizeTableMasterResult.hpp
        result/GetPrizeTableMasterResult.hpp
        result/UpdatePrizeTableMasterResult.hpp
        result/DeletePrizeTableMasterResult.hpp
        result/DescribeBoxesResult.hpp
        result/DescribeBoxesByUserIdResult.hpp
        result/GetBoxResult.hpp
        result/GetBoxByUserIdResult.hpp
        result/ResetBoxResult.hpp
        result/ResetBoxByUserIdResult.hpp
        result/DescribeLotteryModelsResult.hpp
        result/GetLotteryModelResult.hpp
        result/DescribePrizeTablesResult.hpp
        result/GetPrizeTableResult.hpp
        result/DrawByUserIdResult.hpp
        result/DescribeProbabilitiesResult.hpp
        result/DescribeProbabilitiesByUserIdResult.hpp
        result/DrawByStampSheetResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentLotteryMasterResult.hpp
        result/UpdateCurrentLotteryMasterResult.hpp
        result/UpdateCurrentLotteryMasterFromGitHubResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2LotteryRestClient.cpp
        Gs2LotteryWebSocketClient.cpp
        model/Namespace.cpp
        model/LotteryModelMaster.cpp
        model/PrizeTableMaster.cpp
        model/Box.cpp
        model/LotteryModel.cpp
        model/PrizeTable.cpp
        model/Probability.cpp
        model/CurrentLotteryMaster.cpp
        model/ResponseCache.cpp
        model/GitHubCheckoutSetting.cpp
        model/LogSetting.cpp
        model/Prize.cpp
        model/AcquireAction.cpp
        model/DrawnPrize.cpp
        model/BoxItem.cpp
        model/BoxItems.cpp
        model/Config.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeLotteryModelMastersResult.cpp
        result/CreateLotteryModelMasterResult.cpp
        result/GetLotteryModelMasterResult.cpp
        result/UpdateLotteryModelMasterResult.cpp
        result/DeleteLotteryModelMasterResult.cpp
        result/DescribePrizeTableMastersResult.cpp
        result/CreatePrizeTableMasterResult.cpp
        result/GetPrizeTableMasterResult.cpp
        result/UpdatePrizeTableMasterResult.cpp
        result/DeletePrizeTableMasterResult.cpp
        result/DescribeBoxesResult.cpp
        result/DescribeBoxesByUserIdResult.cpp
        result/GetBoxResult.cpp
        result/GetBoxByUserIdResult.cpp
        result/ResetBoxResult.cpp
        result/ResetBoxByUserIdResult.cpp
        result/DescribeLotteryModelsResult.cpp
        result/GetLotteryModelResult.cpp
        result/DescribePrizeTablesResult.cpp
        result/GetPrizeTableResult.cpp
        result/DrawByUserIdResult.cpp
        result/DescribeProbabilitiesResult.cpp
        result/DescribeProbabilitiesByUserIdResult.cpp
        result/DrawByStampSheetResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentLotteryMasterResult.cpp
        result/UpdateCurrentLotteryMasterResult.cpp
        result/UpdateCurrentLotteryMasterFromGitHubResult.cpp
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