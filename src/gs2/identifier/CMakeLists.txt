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
project(gs2-cpp-sdk-identifier)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Identifier.hpp
        Gs2IdentifierConst.hpp
        Gs2IdentifierRestClient.hpp
        Gs2IdentifierWebSocketClient.hpp
        model/model.hpp
        model/User.hpp
        model/SecurityPolicy.hpp
        model/Identifier.hpp
        model/AttachSecurityPolicy.hpp
        model/ProjectToken.hpp
        request/DescribeUsersRequest.hpp
        request/CreateUserRequest.hpp
        request/UpdateUserRequest.hpp
        request/GetUserRequest.hpp
        request/DeleteUserRequest.hpp
        request/DescribeSecurityPoliciesRequest.hpp
        request/DescribeCommonSecurityPoliciesRequest.hpp
        request/CreateSecurityPolicyRequest.hpp
        request/UpdateSecurityPolicyRequest.hpp
        request/GetSecurityPolicyRequest.hpp
        request/DeleteSecurityPolicyRequest.hpp
        request/DescribeIdentifiersRequest.hpp
        request/CreateIdentifierRequest.hpp
        request/GetIdentifierRequest.hpp
        request/DeleteIdentifierRequest.hpp
        request/GetHasSecurityPolicyRequest.hpp
        request/AttachSecurityPolicyRequest.hpp
        request/DetachSecurityPolicyRequest.hpp
        request/LoginRequest.hpp
        result/DescribeUsersResult.hpp
        result/CreateUserResult.hpp
        result/UpdateUserResult.hpp
        result/GetUserResult.hpp
        result/DeleteUserResult.hpp
        result/DescribeSecurityPoliciesResult.hpp
        result/DescribeCommonSecurityPoliciesResult.hpp
        result/CreateSecurityPolicyResult.hpp
        result/UpdateSecurityPolicyResult.hpp
        result/GetSecurityPolicyResult.hpp
        result/DeleteSecurityPolicyResult.hpp
        result/DescribeIdentifiersResult.hpp
        result/CreateIdentifierResult.hpp
        result/GetIdentifierResult.hpp
        result/DeleteIdentifierResult.hpp
        result/GetHasSecurityPolicyResult.hpp
        result/AttachSecurityPolicyResult.hpp
        result/DetachSecurityPolicyResult.hpp
        result/LoginResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2IdentifierRestClient.cpp
        Gs2IdentifierWebSocketClient.cpp
        model/User.cpp
        model/SecurityPolicy.cpp
        model/Identifier.cpp
        model/AttachSecurityPolicy.cpp
        model/ProjectToken.cpp
        result/DescribeUsersResult.cpp
        result/CreateUserResult.cpp
        result/UpdateUserResult.cpp
        result/GetUserResult.cpp
        result/DeleteUserResult.cpp
        result/DescribeSecurityPoliciesResult.cpp
        result/DescribeCommonSecurityPoliciesResult.cpp
        result/CreateSecurityPolicyResult.cpp
        result/UpdateSecurityPolicyResult.cpp
        result/GetSecurityPolicyResult.cpp
        result/DeleteSecurityPolicyResult.cpp
        result/DescribeIdentifiersResult.cpp
        result/CreateIdentifierResult.cpp
        result/GetIdentifierResult.cpp
        result/DeleteIdentifierResult.cpp
        result/GetHasSecurityPolicyResult.cpp
        result/AttachSecurityPolicyResult.cpp
        result/DetachSecurityPolicyResult.cpp
        result/LoginResult.cpp
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