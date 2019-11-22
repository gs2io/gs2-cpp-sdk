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
project(gs2-cpp-sdk-exchange)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Exchange.hpp
        Gs2ExchangeConst.hpp
        Gs2ExchangeRestClient.hpp
        Gs2ExchangeWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/RateModel.hpp
        model/RateModelMaster.hpp
        model/CurrentRateMaster.hpp
        model/ResponseCache.hpp
        model/Config.hpp
        model/GitHubCheckoutSetting.hpp
        model/LogSetting.hpp
        model/AcquireAction.hpp
        model/ConsumeAction.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeRateModelsRequest.hpp
        request/GetRateModelRequest.hpp
        request/DescribeRateModelMastersRequest.hpp
        request/CreateRateModelMasterRequest.hpp
        request/GetRateModelMasterRequest.hpp
        request/UpdateRateModelMasterRequest.hpp
        request/DeleteRateModelMasterRequest.hpp
        request/ExchangeRequest.hpp
        request/ExchangeByUserIdRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentRateMasterRequest.hpp
        request/UpdateCurrentRateMasterRequest.hpp
        request/UpdateCurrentRateMasterFromGitHubRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeRateModelsResult.hpp
        result/GetRateModelResult.hpp
        result/DescribeRateModelMastersResult.hpp
        result/CreateRateModelMasterResult.hpp
        result/GetRateModelMasterResult.hpp
        result/UpdateRateModelMasterResult.hpp
        result/DeleteRateModelMasterResult.hpp
        result/ExchangeResult.hpp
        result/ExchangeByUserIdResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentRateMasterResult.hpp
        result/UpdateCurrentRateMasterResult.hpp
        result/UpdateCurrentRateMasterFromGitHubResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2ExchangeRestClient.cpp
        Gs2ExchangeWebSocketClient.cpp
        model/Namespace.cpp
        model/RateModel.cpp
        model/RateModelMaster.cpp
        model/CurrentRateMaster.cpp
        model/ResponseCache.cpp
        model/Config.cpp
        model/GitHubCheckoutSetting.cpp
        model/LogSetting.cpp
        model/AcquireAction.cpp
        model/ConsumeAction.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeRateModelsResult.cpp
        result/GetRateModelResult.cpp
        result/DescribeRateModelMastersResult.cpp
        result/CreateRateModelMasterResult.cpp
        result/GetRateModelMasterResult.cpp
        result/UpdateRateModelMasterResult.cpp
        result/DeleteRateModelMasterResult.cpp
        result/ExchangeResult.cpp
        result/ExchangeByUserIdResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentRateMasterResult.cpp
        result/UpdateCurrentRateMasterResult.cpp
        result/UpdateCurrentRateMasterFromGitHubResult.cpp
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