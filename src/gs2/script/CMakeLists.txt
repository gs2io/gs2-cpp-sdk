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
project(gs2-cpp-sdk-script)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Script.hpp
        Gs2ScriptConst.hpp
        Gs2ScriptRestClient.hpp
        Gs2ScriptWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Script.hpp
        model/GitHubCheckoutSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeScriptsRequest.hpp
        request/CreateScriptRequest.hpp
        request/CreateScriptFromGitHubRequest.hpp
        request/GetScriptRequest.hpp
        request/UpdateScriptRequest.hpp
        request/UpdateScriptFromGitHubRequest.hpp
        request/DeleteScriptRequest.hpp
        request/DebugInvokeRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeScriptsResult.hpp
        result/CreateScriptResult.hpp
        result/CreateScriptFromGitHubResult.hpp
        result/GetScriptResult.hpp
        result/UpdateScriptResult.hpp
        result/UpdateScriptFromGitHubResult.hpp
        result/DeleteScriptResult.hpp
        result/DebugInvokeResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2ScriptRestClient.cpp
        Gs2ScriptWebSocketClient.cpp
        model/Namespace.cpp
        model/Script.cpp
        model/GitHubCheckoutSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeScriptsResult.cpp
        result/CreateScriptResult.cpp
        result/CreateScriptFromGitHubResult.cpp
        result/GetScriptResult.cpp
        result/UpdateScriptResult.cpp
        result/UpdateScriptFromGitHubResult.cpp
        result/DeleteScriptResult.cpp
        result/DebugInvokeResult.cpp
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