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
project(gs2-cpp-sdk-project)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Project.hpp
        Gs2ProjectConst.hpp
        Gs2ProjectRestClient.hpp
        Gs2ProjectWebSocketClient.hpp
        model/model.hpp
        model/Account.hpp
        model/Project.hpp
        request/CreateAccountRequest.hpp
        request/VerifyRequest.hpp
        request/SignInRequest.hpp
        request/IssueAccountTokenRequest.hpp
        request/ForgetRequest.hpp
        request/IssuePasswordRequest.hpp
        request/UpdateAccountRequest.hpp
        request/DeleteAccountRequest.hpp
        request/DescribeProjectsRequest.hpp
        request/CreateProjectRequest.hpp
        request/GetProjectRequest.hpp
        request/GetProjectTokenRequest.hpp
        request/UpdateProjectRequest.hpp
        request/DeleteProjectRequest.hpp
        result/CreateAccountResult.hpp
        result/VerifyResult.hpp
        result/SignInResult.hpp
        result/IssueAccountTokenResult.hpp
        result/ForgetResult.hpp
        result/IssuePasswordResult.hpp
        result/UpdateAccountResult.hpp
        result/DeleteAccountResult.hpp
        result/DescribeProjectsResult.hpp
        result/CreateProjectResult.hpp
        result/GetProjectResult.hpp
        result/GetProjectTokenResult.hpp
        result/UpdateProjectResult.hpp
        result/DeleteProjectResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2ProjectRestClient.cpp
        Gs2ProjectWebSocketClient.cpp
        model/Account.cpp
        model/Project.cpp
        result/CreateAccountResult.cpp
        result/VerifyResult.cpp
        result/SignInResult.cpp
        result/IssueAccountTokenResult.cpp
        result/ForgetResult.cpp
        result/IssuePasswordResult.cpp
        result/UpdateAccountResult.cpp
        result/DeleteAccountResult.cpp
        result/DescribeProjectsResult.cpp
        result/CreateProjectResult.cpp
        result/GetProjectResult.cpp
        result/GetProjectTokenResult.cpp
        result/UpdateProjectResult.cpp
        result/DeleteProjectResult.cpp
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