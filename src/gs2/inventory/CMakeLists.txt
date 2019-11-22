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
project(gs2-cpp-sdk-inventory)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Inventory.hpp
        Gs2InventoryConst.hpp
        Gs2InventoryRestClient.hpp
        Gs2InventoryWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/InventoryModelMaster.hpp
        model/InventoryModel.hpp
        model/ItemModelMaster.hpp
        model/ItemModel.hpp
        model/CurrentItemModelMaster.hpp
        model/Inventory.hpp
        model/ItemSet.hpp
        model/ResponseCache.hpp
        model/GitHubCheckoutSetting.hpp
        model/ScriptSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeInventoryModelMastersRequest.hpp
        request/CreateInventoryModelMasterRequest.hpp
        request/GetInventoryModelMasterRequest.hpp
        request/UpdateInventoryModelMasterRequest.hpp
        request/DeleteInventoryModelMasterRequest.hpp
        request/DescribeInventoryModelsRequest.hpp
        request/GetInventoryModelRequest.hpp
        request/DescribeItemModelMastersRequest.hpp
        request/CreateItemModelMasterRequest.hpp
        request/GetItemModelMasterRequest.hpp
        request/UpdateItemModelMasterRequest.hpp
        request/DeleteItemModelMasterRequest.hpp
        request/DescribeItemModelsRequest.hpp
        request/GetItemModelRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentItemModelMasterRequest.hpp
        request/UpdateCurrentItemModelMasterRequest.hpp
        request/UpdateCurrentItemModelMasterFromGitHubRequest.hpp
        request/DescribeInventoriesRequest.hpp
        request/DescribeInventoriesByUserIdRequest.hpp
        request/GetInventoryRequest.hpp
        request/GetInventoryByUserIdRequest.hpp
        request/AddCapacityByUserIdRequest.hpp
        request/SetCapacityByUserIdRequest.hpp
        request/DeleteInventoryByUserIdRequest.hpp
        request/AddCapacityByStampSheetRequest.hpp
        request/SetCapacityByStampSheetRequest.hpp
        request/DescribeItemSetsRequest.hpp
        request/DescribeItemSetsByUserIdRequest.hpp
        request/GetItemSetRequest.hpp
        request/GetItemSetByUserIdRequest.hpp
        request/GetItemWithSignatureRequest.hpp
        request/GetItemWithSignatureByUserIdRequest.hpp
        request/AcquireItemSetByUserIdRequest.hpp
        request/ConsumeItemSetRequest.hpp
        request/ConsumeItemSetByUserIdRequest.hpp
        request/DeleteItemSetByUserIdRequest.hpp
        request/AcquireItemSetByStampSheetRequest.hpp
        request/ConsumeItemSetByStampTaskRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeInventoryModelMastersResult.hpp
        result/CreateInventoryModelMasterResult.hpp
        result/GetInventoryModelMasterResult.hpp
        result/UpdateInventoryModelMasterResult.hpp
        result/DeleteInventoryModelMasterResult.hpp
        result/DescribeInventoryModelsResult.hpp
        result/GetInventoryModelResult.hpp
        result/DescribeItemModelMastersResult.hpp
        result/CreateItemModelMasterResult.hpp
        result/GetItemModelMasterResult.hpp
        result/UpdateItemModelMasterResult.hpp
        result/DeleteItemModelMasterResult.hpp
        result/DescribeItemModelsResult.hpp
        result/GetItemModelResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentItemModelMasterResult.hpp
        result/UpdateCurrentItemModelMasterResult.hpp
        result/UpdateCurrentItemModelMasterFromGitHubResult.hpp
        result/DescribeInventoriesResult.hpp
        result/DescribeInventoriesByUserIdResult.hpp
        result/GetInventoryResult.hpp
        result/GetInventoryByUserIdResult.hpp
        result/AddCapacityByUserIdResult.hpp
        result/SetCapacityByUserIdResult.hpp
        result/DeleteInventoryByUserIdResult.hpp
        result/AddCapacityByStampSheetResult.hpp
        result/SetCapacityByStampSheetResult.hpp
        result/DescribeItemSetsResult.hpp
        result/DescribeItemSetsByUserIdResult.hpp
        result/GetItemSetResult.hpp
        result/GetItemSetByUserIdResult.hpp
        result/GetItemWithSignatureResult.hpp
        result/GetItemWithSignatureByUserIdResult.hpp
        result/AcquireItemSetByUserIdResult.hpp
        result/ConsumeItemSetResult.hpp
        result/ConsumeItemSetByUserIdResult.hpp
        result/DeleteItemSetByUserIdResult.hpp
        result/AcquireItemSetByStampSheetResult.hpp
        result/ConsumeItemSetByStampTaskResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2InventoryRestClient.cpp
        Gs2InventoryWebSocketClient.cpp
        model/Namespace.cpp
        model/InventoryModelMaster.cpp
        model/InventoryModel.cpp
        model/ItemModelMaster.cpp
        model/ItemModel.cpp
        model/CurrentItemModelMaster.cpp
        model/Inventory.cpp
        model/ItemSet.cpp
        model/ResponseCache.cpp
        model/GitHubCheckoutSetting.cpp
        model/ScriptSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeInventoryModelMastersResult.cpp
        result/CreateInventoryModelMasterResult.cpp
        result/GetInventoryModelMasterResult.cpp
        result/UpdateInventoryModelMasterResult.cpp
        result/DeleteInventoryModelMasterResult.cpp
        result/DescribeInventoryModelsResult.cpp
        result/GetInventoryModelResult.cpp
        result/DescribeItemModelMastersResult.cpp
        result/CreateItemModelMasterResult.cpp
        result/GetItemModelMasterResult.cpp
        result/UpdateItemModelMasterResult.cpp
        result/DeleteItemModelMasterResult.cpp
        result/DescribeItemModelsResult.cpp
        result/GetItemModelResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentItemModelMasterResult.cpp
        result/UpdateCurrentItemModelMasterResult.cpp
        result/UpdateCurrentItemModelMasterFromGitHubResult.cpp
        result/DescribeInventoriesResult.cpp
        result/DescribeInventoriesByUserIdResult.cpp
        result/GetInventoryResult.cpp
        result/GetInventoryByUserIdResult.cpp
        result/AddCapacityByUserIdResult.cpp
        result/SetCapacityByUserIdResult.cpp
        result/DeleteInventoryByUserIdResult.cpp
        result/AddCapacityByStampSheetResult.cpp
        result/SetCapacityByStampSheetResult.cpp
        result/DescribeItemSetsResult.cpp
        result/DescribeItemSetsByUserIdResult.cpp
        result/GetItemSetResult.cpp
        result/GetItemSetByUserIdResult.cpp
        result/GetItemWithSignatureResult.cpp
        result/GetItemWithSignatureByUserIdResult.cpp
        result/AcquireItemSetByUserIdResult.cpp
        result/ConsumeItemSetResult.cpp
        result/ConsumeItemSetByUserIdResult.cpp
        result/DeleteItemSetByUserIdResult.cpp
        result/AcquireItemSetByStampSheetResult.cpp
        result/ConsumeItemSetByStampTaskResult.cpp
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