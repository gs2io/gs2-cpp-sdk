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
project(gs2-cpp-sdk-lock)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Lock.hpp
        Gs2LockConst.hpp
        Gs2LockRestClient.hpp
        Gs2LockWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Mutex.hpp
        model/ResponseCache.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeMutexesRequest.hpp
        request/DescribeMutexesByUserIdRequest.hpp
        request/LockRequest.hpp
        request/LockByUserIdRequest.hpp
        request/UnlockRequest.hpp
        request/UnlockByUserIdRequest.hpp
        request/GetMutexRequest.hpp
        request/GetMutexByUserIdRequest.hpp
        request/DeleteMutexByUserIdRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeMutexesResult.hpp
        result/DescribeMutexesByUserIdResult.hpp
        result/LockResult.hpp
        result/LockByUserIdResult.hpp
        result/UnlockResult.hpp
        result/UnlockByUserIdResult.hpp
        result/GetMutexResult.hpp
        result/GetMutexByUserIdResult.hpp
        result/DeleteMutexByUserIdResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2LockRestClient.cpp
        Gs2LockWebSocketClient.cpp
        model/Namespace.cpp
        model/Mutex.cpp
        model/ResponseCache.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeMutexesResult.cpp
        result/DescribeMutexesByUserIdResult.cpp
        result/LockResult.cpp
        result/LockByUserIdResult.cpp
        result/UnlockResult.cpp
        result/UnlockByUserIdResult.cpp
        result/GetMutexResult.cpp
        result/GetMutexByUserIdResult.cpp
        result/DeleteMutexByUserIdResult.cpp
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