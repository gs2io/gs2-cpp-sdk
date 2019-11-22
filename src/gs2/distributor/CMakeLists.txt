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
project(gs2-cpp-sdk-distributor)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Distributor.hpp
        Gs2DistributorConst.hpp
        Gs2DistributorRestClient.hpp
        Gs2DistributorWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/DistributorModelMaster.hpp
        model/DistributorModel.hpp
        model/CurrentDistributorMaster.hpp
        model/ResponseCache.hpp
        model/GitHubCheckoutSetting.hpp
        model/DistributeResource.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeDistributorModelMastersRequest.hpp
        request/CreateDistributorModelMasterRequest.hpp
        request/GetDistributorModelMasterRequest.hpp
        request/UpdateDistributorModelMasterRequest.hpp
        request/DeleteDistributorModelMasterRequest.hpp
        request/DescribeDistributorModelsRequest.hpp
        request/GetDistributorModelRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentDistributorMasterRequest.hpp
        request/UpdateCurrentDistributorMasterRequest.hpp
        request/UpdateCurrentDistributorMasterFromGitHubRequest.hpp
        request/DistributeRequest.hpp
        request/RunStampTaskRequest.hpp
        request/RunStampSheetRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeDistributorModelMastersResult.hpp
        result/CreateDistributorModelMasterResult.hpp
        result/GetDistributorModelMasterResult.hpp
        result/UpdateDistributorModelMasterResult.hpp
        result/DeleteDistributorModelMasterResult.hpp
        result/DescribeDistributorModelsResult.hpp
        result/GetDistributorModelResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentDistributorMasterResult.hpp
        result/UpdateCurrentDistributorMasterResult.hpp
        result/UpdateCurrentDistributorMasterFromGitHubResult.hpp
        result/DistributeResult.hpp
        result/RunStampTaskResult.hpp
        result/RunStampSheetResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2DistributorRestClient.cpp
        Gs2DistributorWebSocketClient.cpp
        model/Namespace.cpp
        model/DistributorModelMaster.cpp
        model/DistributorModel.cpp
        model/CurrentDistributorMaster.cpp
        model/ResponseCache.cpp
        model/GitHubCheckoutSetting.cpp
        model/DistributeResource.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeDistributorModelMastersResult.cpp
        result/CreateDistributorModelMasterResult.cpp
        result/GetDistributorModelMasterResult.cpp
        result/UpdateDistributorModelMasterResult.cpp
        result/DeleteDistributorModelMasterResult.cpp
        result/DescribeDistributorModelsResult.cpp
        result/GetDistributorModelResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentDistributorMasterResult.cpp
        result/UpdateCurrentDistributorMasterResult.cpp
        result/UpdateCurrentDistributorMasterFromGitHubResult.cpp
        result/DistributeResult.cpp
        result/RunStampTaskResult.cpp
        result/RunStampSheetResult.cpp
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