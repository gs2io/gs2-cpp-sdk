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
project(gs2-cpp-sdk-showcase)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Showcase.hpp
        Gs2ShowcaseConst.hpp
        Gs2ShowcaseRestClient.hpp
        Gs2ShowcaseWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/SalesItemMaster.hpp
        model/SalesItemGroupMaster.hpp
        model/ShowcaseMaster.hpp
        model/CurrentShowcaseMaster.hpp
        model/ResponseCache.hpp
        model/GitHubCheckoutSetting.hpp
        model/LogSetting.hpp
        model/SalesItem.hpp
        model/SalesItemGroup.hpp
        model/Showcase.hpp
        model/DisplayItem.hpp
        model/Config.hpp
        model/ConsumeAction.hpp
        model/AcquireAction.hpp
        model/DisplayItemMaster.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeSalesItemMastersRequest.hpp
        request/CreateSalesItemMasterRequest.hpp
        request/GetSalesItemMasterRequest.hpp
        request/UpdateSalesItemMasterRequest.hpp
        request/DeleteSalesItemMasterRequest.hpp
        request/DescribeSalesItemGroupMastersRequest.hpp
        request/CreateSalesItemGroupMasterRequest.hpp
        request/GetSalesItemGroupMasterRequest.hpp
        request/UpdateSalesItemGroupMasterRequest.hpp
        request/DeleteSalesItemGroupMasterRequest.hpp
        request/DescribeShowcaseMastersRequest.hpp
        request/CreateShowcaseMasterRequest.hpp
        request/GetShowcaseMasterRequest.hpp
        request/UpdateShowcaseMasterRequest.hpp
        request/DeleteShowcaseMasterRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentShowcaseMasterRequest.hpp
        request/UpdateCurrentShowcaseMasterRequest.hpp
        request/UpdateCurrentShowcaseMasterFromGitHubRequest.hpp
        request/DescribeShowcasesRequest.hpp
        request/DescribeShowcasesByUserIdRequest.hpp
        request/GetShowcaseRequest.hpp
        request/GetShowcaseByUserIdRequest.hpp
        request/BuyRequest.hpp
        request/BuyByUserIdRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeSalesItemMastersResult.hpp
        result/CreateSalesItemMasterResult.hpp
        result/GetSalesItemMasterResult.hpp
        result/UpdateSalesItemMasterResult.hpp
        result/DeleteSalesItemMasterResult.hpp
        result/DescribeSalesItemGroupMastersResult.hpp
        result/CreateSalesItemGroupMasterResult.hpp
        result/GetSalesItemGroupMasterResult.hpp
        result/UpdateSalesItemGroupMasterResult.hpp
        result/DeleteSalesItemGroupMasterResult.hpp
        result/DescribeShowcaseMastersResult.hpp
        result/CreateShowcaseMasterResult.hpp
        result/GetShowcaseMasterResult.hpp
        result/UpdateShowcaseMasterResult.hpp
        result/DeleteShowcaseMasterResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentShowcaseMasterResult.hpp
        result/UpdateCurrentShowcaseMasterResult.hpp
        result/UpdateCurrentShowcaseMasterFromGitHubResult.hpp
        result/DescribeShowcasesResult.hpp
        result/DescribeShowcasesByUserIdResult.hpp
        result/GetShowcaseResult.hpp
        result/GetShowcaseByUserIdResult.hpp
        result/BuyResult.hpp
        result/BuyByUserIdResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2ShowcaseRestClient.cpp
        Gs2ShowcaseWebSocketClient.cpp
        model/Namespace.cpp
        model/SalesItemMaster.cpp
        model/SalesItemGroupMaster.cpp
        model/ShowcaseMaster.cpp
        model/CurrentShowcaseMaster.cpp
        model/ResponseCache.cpp
        model/GitHubCheckoutSetting.cpp
        model/LogSetting.cpp
        model/SalesItem.cpp
        model/SalesItemGroup.cpp
        model/Showcase.cpp
        model/DisplayItem.cpp
        model/Config.cpp
        model/ConsumeAction.cpp
        model/AcquireAction.cpp
        model/DisplayItemMaster.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeSalesItemMastersResult.cpp
        result/CreateSalesItemMasterResult.cpp
        result/GetSalesItemMasterResult.cpp
        result/UpdateSalesItemMasterResult.cpp
        result/DeleteSalesItemMasterResult.cpp
        result/DescribeSalesItemGroupMastersResult.cpp
        result/CreateSalesItemGroupMasterResult.cpp
        result/GetSalesItemGroupMasterResult.cpp
        result/UpdateSalesItemGroupMasterResult.cpp
        result/DeleteSalesItemGroupMasterResult.cpp
        result/DescribeShowcaseMastersResult.cpp
        result/CreateShowcaseMasterResult.cpp
        result/GetShowcaseMasterResult.cpp
        result/UpdateShowcaseMasterResult.cpp
        result/DeleteShowcaseMasterResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentShowcaseMasterResult.cpp
        result/UpdateCurrentShowcaseMasterResult.cpp
        result/UpdateCurrentShowcaseMasterFromGitHubResult.cpp
        result/DescribeShowcasesResult.cpp
        result/DescribeShowcasesByUserIdResult.cpp
        result/GetShowcaseResult.cpp
        result/GetShowcaseByUserIdResult.cpp
        result/BuyResult.cpp
        result/BuyByUserIdResult.cpp
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