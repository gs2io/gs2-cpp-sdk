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
project(gs2-cpp-sdk-log)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Log.hpp
        Gs2LogConst.hpp
        Gs2LogRestClient.hpp
        Gs2LogWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/AccessLog.hpp
        model/AccessLogCount.hpp
        model/IssueStampSheetLog.hpp
        model/IssueStampSheetLogCount.hpp
        model/ExecuteStampSheetLog.hpp
        model/ExecuteStampSheetLogCount.hpp
        model/ExecuteStampTaskLog.hpp
        model/ExecuteStampTaskLogCount.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/QueryAccessLogRequest.hpp
        request/CountAccessLogRequest.hpp
        request/QueryIssueStampSheetLogRequest.hpp
        request/CountIssueStampSheetLogRequest.hpp
        request/QueryExecuteStampSheetLogRequest.hpp
        request/CountExecuteStampSheetLogRequest.hpp
        request/QueryExecuteStampTaskLogRequest.hpp
        request/CountExecuteStampTaskLogRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/QueryAccessLogResult.hpp
        result/CountAccessLogResult.hpp
        result/QueryIssueStampSheetLogResult.hpp
        result/CountIssueStampSheetLogResult.hpp
        result/QueryExecuteStampSheetLogResult.hpp
        result/CountExecuteStampSheetLogResult.hpp
        result/QueryExecuteStampTaskLogResult.hpp
        result/CountExecuteStampTaskLogResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2LogRestClient.cpp
        Gs2LogWebSocketClient.cpp
        model/Namespace.cpp
        model/AccessLog.cpp
        model/AccessLogCount.cpp
        model/IssueStampSheetLog.cpp
        model/IssueStampSheetLogCount.cpp
        model/ExecuteStampSheetLog.cpp
        model/ExecuteStampSheetLogCount.cpp
        model/ExecuteStampTaskLog.cpp
        model/ExecuteStampTaskLogCount.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/QueryAccessLogResult.cpp
        result/CountAccessLogResult.cpp
        result/QueryIssueStampSheetLogResult.cpp
        result/CountIssueStampSheetLogResult.cpp
        result/QueryExecuteStampSheetLogResult.cpp
        result/CountExecuteStampSheetLogResult.cpp
        result/QueryExecuteStampTaskLogResult.cpp
        result/CountExecuteStampTaskLogResult.cpp
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