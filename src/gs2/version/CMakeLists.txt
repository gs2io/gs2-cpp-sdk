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
project(gs2-cpp-sdk-version)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Version.hpp
        Gs2VersionConst.hpp
        Gs2VersionRestClient.hpp
        Gs2VersionWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/VersionModelMaster.hpp
        model/Version.hpp
        model/VersionModel.hpp
        model/AcceptVersion.hpp
        model/Status.hpp
        model/TargetVersion.hpp
        model/SignTargetVersion.hpp
        model/ResponseCache.hpp
        model/CurrentVersionMaster.hpp
        model/ScriptSetting.hpp
        model/GitHubCheckoutSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeVersionModelMastersRequest.hpp
        request/CreateVersionModelMasterRequest.hpp
        request/GetVersionModelMasterRequest.hpp
        request/UpdateVersionModelMasterRequest.hpp
        request/DeleteVersionModelMasterRequest.hpp
        request/DescribeVersionModelsRequest.hpp
        request/GetVersionModelRequest.hpp
        request/DescribeAcceptVersionsRequest.hpp
        request/DescribeAcceptVersionsByUserIdRequest.hpp
        request/AcceptRequest.hpp
        request/AcceptByUserIdRequest.hpp
        request/GetAcceptVersionRequest.hpp
        request/GetAcceptVersionByUserIdRequest.hpp
        request/DeleteAcceptVersionRequest.hpp
        request/DeleteAcceptVersionByUserIdRequest.hpp
        request/CheckVersionRequest.hpp
        request/CheckVersionByUserIdRequest.hpp
        request/CalculateSignatureRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentVersionMasterRequest.hpp
        request/UpdateCurrentVersionMasterRequest.hpp
        request/UpdateCurrentVersionMasterFromGitHubRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeVersionModelMastersResult.hpp
        result/CreateVersionModelMasterResult.hpp
        result/GetVersionModelMasterResult.hpp
        result/UpdateVersionModelMasterResult.hpp
        result/DeleteVersionModelMasterResult.hpp
        result/DescribeVersionModelsResult.hpp
        result/GetVersionModelResult.hpp
        result/DescribeAcceptVersionsResult.hpp
        result/DescribeAcceptVersionsByUserIdResult.hpp
        result/AcceptResult.hpp
        result/AcceptByUserIdResult.hpp
        result/GetAcceptVersionResult.hpp
        result/GetAcceptVersionByUserIdResult.hpp
        result/DeleteAcceptVersionResult.hpp
        result/DeleteAcceptVersionByUserIdResult.hpp
        result/CheckVersionResult.hpp
        result/CheckVersionByUserIdResult.hpp
        result/CalculateSignatureResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentVersionMasterResult.hpp
        result/UpdateCurrentVersionMasterResult.hpp
        result/UpdateCurrentVersionMasterFromGitHubResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2VersionRestClient.cpp
        Gs2VersionWebSocketClient.cpp
        model/Namespace.cpp
        model/VersionModelMaster.cpp
        model/Version.cpp
        model/VersionModel.cpp
        model/AcceptVersion.cpp
        model/Status.cpp
        model/TargetVersion.cpp
        model/SignTargetVersion.cpp
        model/ResponseCache.cpp
        model/CurrentVersionMaster.cpp
        model/ScriptSetting.cpp
        model/GitHubCheckoutSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeVersionModelMastersResult.cpp
        result/CreateVersionModelMasterResult.cpp
        result/GetVersionModelMasterResult.cpp
        result/UpdateVersionModelMasterResult.cpp
        result/DeleteVersionModelMasterResult.cpp
        result/DescribeVersionModelsResult.cpp
        result/GetVersionModelResult.cpp
        result/DescribeAcceptVersionsResult.cpp
        result/DescribeAcceptVersionsByUserIdResult.cpp
        result/AcceptResult.cpp
        result/AcceptByUserIdResult.cpp
        result/GetAcceptVersionResult.cpp
        result/GetAcceptVersionByUserIdResult.cpp
        result/DeleteAcceptVersionResult.cpp
        result/DeleteAcceptVersionByUserIdResult.cpp
        result/CheckVersionResult.cpp
        result/CheckVersionByUserIdResult.cpp
        result/CalculateSignatureResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentVersionMasterResult.cpp
        result/UpdateCurrentVersionMasterResult.cpp
        result/UpdateCurrentVersionMasterFromGitHubResult.cpp
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