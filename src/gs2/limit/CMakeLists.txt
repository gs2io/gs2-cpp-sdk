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
project(gs2-cpp-sdk-limit)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Limit.hpp
        Gs2LimitConst.hpp
        Gs2LimitRestClient.hpp
        Gs2LimitWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Counter.hpp
        model/LimitModelMaster.hpp
        model/CurrentLimitMaster.hpp
        model/ResponseCache.hpp
        model/GitHubCheckoutSetting.hpp
        model/LogSetting.hpp
        model/LimitModel.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeCountersRequest.hpp
        request/DescribeCountersByUserIdRequest.hpp
        request/GetCounterRequest.hpp
        request/GetCounterByUserIdRequest.hpp
        request/CountUpByUserIdRequest.hpp
        request/DeleteCounterByUserIdRequest.hpp
        request/CountUpByStampTaskRequest.hpp
        request/DeleteByStampSheetRequest.hpp
        request/DescribeLimitModelMastersRequest.hpp
        request/CreateLimitModelMasterRequest.hpp
        request/GetLimitModelMasterRequest.hpp
        request/UpdateLimitModelMasterRequest.hpp
        request/DeleteLimitModelMasterRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentLimitMasterRequest.hpp
        request/UpdateCurrentLimitMasterRequest.hpp
        request/UpdateCurrentLimitMasterFromGitHubRequest.hpp
        request/DescribeLimitModelsRequest.hpp
        request/GetLimitModelRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeCountersResult.hpp
        result/DescribeCountersByUserIdResult.hpp
        result/GetCounterResult.hpp
        result/GetCounterByUserIdResult.hpp
        result/CountUpByUserIdResult.hpp
        result/DeleteCounterByUserIdResult.hpp
        result/CountUpByStampTaskResult.hpp
        result/DeleteByStampSheetResult.hpp
        result/DescribeLimitModelMastersResult.hpp
        result/CreateLimitModelMasterResult.hpp
        result/GetLimitModelMasterResult.hpp
        result/UpdateLimitModelMasterResult.hpp
        result/DeleteLimitModelMasterResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentLimitMasterResult.hpp
        result/UpdateCurrentLimitMasterResult.hpp
        result/UpdateCurrentLimitMasterFromGitHubResult.hpp
        result/DescribeLimitModelsResult.hpp
        result/GetLimitModelResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2LimitRestClient.cpp
        Gs2LimitWebSocketClient.cpp
        model/Namespace.cpp
        model/Counter.cpp
        model/LimitModelMaster.cpp
        model/CurrentLimitMaster.cpp
        model/ResponseCache.cpp
        model/GitHubCheckoutSetting.cpp
        model/LogSetting.cpp
        model/LimitModel.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeCountersResult.cpp
        result/DescribeCountersByUserIdResult.cpp
        result/GetCounterResult.cpp
        result/GetCounterByUserIdResult.cpp
        result/CountUpByUserIdResult.cpp
        result/DeleteCounterByUserIdResult.cpp
        result/CountUpByStampTaskResult.cpp
        result/DeleteByStampSheetResult.cpp
        result/DescribeLimitModelMastersResult.cpp
        result/CreateLimitModelMasterResult.cpp
        result/GetLimitModelMasterResult.cpp
        result/UpdateLimitModelMasterResult.cpp
        result/DeleteLimitModelMasterResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentLimitMasterResult.cpp
        result/UpdateCurrentLimitMasterResult.cpp
        result/UpdateCurrentLimitMasterFromGitHubResult.cpp
        result/DescribeLimitModelsResult.cpp
        result/GetLimitModelResult.cpp
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