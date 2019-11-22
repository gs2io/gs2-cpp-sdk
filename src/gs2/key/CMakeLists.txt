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
project(gs2-cpp-sdk-key)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Key.hpp
        Gs2KeyConst.hpp
        Gs2KeyRestClient.hpp
        Gs2KeyWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Key.hpp
        model/GitHubApiKey.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeKeysRequest.hpp
        request/CreateKeyRequest.hpp
        request/UpdateKeyRequest.hpp
        request/GetKeyRequest.hpp
        request/DeleteKeyRequest.hpp
        request/EncryptRequest.hpp
        request/DecryptRequest.hpp
        request/DescribeGitHubApiKeysRequest.hpp
        request/CreateGitHubApiKeyRequest.hpp
        request/UpdateGitHubApiKeyRequest.hpp
        request/GetGitHubApiKeyRequest.hpp
        request/DeleteGitHubApiKeyRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeKeysResult.hpp
        result/CreateKeyResult.hpp
        result/UpdateKeyResult.hpp
        result/GetKeyResult.hpp
        result/DeleteKeyResult.hpp
        result/EncryptResult.hpp
        result/DecryptResult.hpp
        result/DescribeGitHubApiKeysResult.hpp
        result/CreateGitHubApiKeyResult.hpp
        result/UpdateGitHubApiKeyResult.hpp
        result/GetGitHubApiKeyResult.hpp
        result/DeleteGitHubApiKeyResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2KeyRestClient.cpp
        Gs2KeyWebSocketClient.cpp
        model/Namespace.cpp
        model/Key.cpp
        model/GitHubApiKey.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeKeysResult.cpp
        result/CreateKeyResult.cpp
        result/UpdateKeyResult.cpp
        result/GetKeyResult.cpp
        result/DeleteKeyResult.cpp
        result/EncryptResult.cpp
        result/DecryptResult.cpp
        result/DescribeGitHubApiKeysResult.cpp
        result/CreateGitHubApiKeyResult.cpp
        result/UpdateGitHubApiKeyResult.cpp
        result/GetGitHubApiKeyResult.cpp
        result/DeleteGitHubApiKeyResult.cpp
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