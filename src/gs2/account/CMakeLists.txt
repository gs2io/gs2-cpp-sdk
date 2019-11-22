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
project(gs2-cpp-sdk-account)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Account.hpp
        Gs2AccountConst.hpp
        Gs2AccountRestClient.hpp
        Gs2AccountWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Account.hpp
        model/TakeOver.hpp
        model/ResponseCache.hpp
        model/ScriptSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeAccountsRequest.hpp
        request/CreateAccountRequest.hpp
        request/UpdateTimeOffsetRequest.hpp
        request/GetAccountRequest.hpp
        request/DeleteAccountRequest.hpp
        request/AuthenticationRequest.hpp
        request/DescribeTakeOversRequest.hpp
        request/DescribeTakeOversByUserIdRequest.hpp
        request/CreateTakeOverRequest.hpp
        request/CreateTakeOverByUserIdRequest.hpp
        request/GetTakeOverRequest.hpp
        request/GetTakeOverByUserIdRequest.hpp
        request/UpdateTakeOverRequest.hpp
        request/UpdateTakeOverByUserIdRequest.hpp
        request/DeleteTakeOverRequest.hpp
        request/DeleteTakeOverByUserIdentifierRequest.hpp
        request/DoTakeOverRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeAccountsResult.hpp
        result/CreateAccountResult.hpp
        result/UpdateTimeOffsetResult.hpp
        result/GetAccountResult.hpp
        result/DeleteAccountResult.hpp
        result/AuthenticationResult.hpp
        result/DescribeTakeOversResult.hpp
        result/DescribeTakeOversByUserIdResult.hpp
        result/CreateTakeOverResult.hpp
        result/CreateTakeOverByUserIdResult.hpp
        result/GetTakeOverResult.hpp
        result/GetTakeOverByUserIdResult.hpp
        result/UpdateTakeOverResult.hpp
        result/UpdateTakeOverByUserIdResult.hpp
        result/DeleteTakeOverResult.hpp
        result/DeleteTakeOverByUserIdentifierResult.hpp
        result/DoTakeOverResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2AccountRestClient.cpp
        Gs2AccountWebSocketClient.cpp
        model/Namespace.cpp
        model/Account.cpp
        model/TakeOver.cpp
        model/ResponseCache.cpp
        model/ScriptSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeAccountsResult.cpp
        result/CreateAccountResult.cpp
        result/UpdateTimeOffsetResult.cpp
        result/GetAccountResult.cpp
        result/DeleteAccountResult.cpp
        result/AuthenticationResult.cpp
        result/DescribeTakeOversResult.cpp
        result/DescribeTakeOversByUserIdResult.cpp
        result/CreateTakeOverResult.cpp
        result/CreateTakeOverByUserIdResult.cpp
        result/GetTakeOverResult.cpp
        result/GetTakeOverByUserIdResult.cpp
        result/UpdateTakeOverResult.cpp
        result/UpdateTakeOverByUserIdResult.cpp
        result/DeleteTakeOverResult.cpp
        result/DeleteTakeOverByUserIdentifierResult.cpp
        result/DoTakeOverResult.cpp
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