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
project(gs2-cpp-sdk-deploy)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Deploy.hpp
        Gs2DeployConst.hpp
        Gs2DeployRestClient.hpp
        Gs2DeployWebSocketClient.hpp
        model/model.hpp
        model/Stack.hpp
        model/Resource.hpp
        model/WorkingStack.hpp
        model/WorkingResource.hpp
        model/Event.hpp
        model/Output.hpp
        model/GitHubCheckoutSetting.hpp
        model/OutputField.hpp
        request/DescribeStacksRequest.hpp
        request/CreateStackRequest.hpp
        request/CreateStackFromGitHubRequest.hpp
        request/GetStackStatusRequest.hpp
        request/GetStackRequest.hpp
        request/UpdateStackRequest.hpp
        request/UpdateStackFromGitHubRequest.hpp
        request/DeleteStackRequest.hpp
        request/ForceDeleteStackRequest.hpp
        request/DescribeResourcesRequest.hpp
        request/GetResourceRequest.hpp
        request/DescribeEventsRequest.hpp
        request/GetEventRequest.hpp
        request/DescribeOutputsRequest.hpp
        request/GetOutputRequest.hpp
        result/DescribeStacksResult.hpp
        result/CreateStackResult.hpp
        result/CreateStackFromGitHubResult.hpp
        result/GetStackStatusResult.hpp
        result/GetStackResult.hpp
        result/UpdateStackResult.hpp
        result/UpdateStackFromGitHubResult.hpp
        result/DeleteStackResult.hpp
        result/ForceDeleteStackResult.hpp
        result/DescribeResourcesResult.hpp
        result/GetResourceResult.hpp
        result/DescribeEventsResult.hpp
        result/GetEventResult.hpp
        result/DescribeOutputsResult.hpp
        result/GetOutputResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2DeployRestClient.cpp
        Gs2DeployWebSocketClient.cpp
        model/Stack.cpp
        model/Resource.cpp
        model/WorkingStack.cpp
        model/WorkingResource.cpp
        model/Event.cpp
        model/Output.cpp
        model/GitHubCheckoutSetting.cpp
        model/OutputField.cpp
        result/DescribeStacksResult.cpp
        result/CreateStackResult.cpp
        result/CreateStackFromGitHubResult.cpp
        result/GetStackStatusResult.cpp
        result/GetStackResult.cpp
        result/UpdateStackResult.cpp
        result/UpdateStackFromGitHubResult.cpp
        result/DeleteStackResult.cpp
        result/ForceDeleteStackResult.cpp
        result/DescribeResourcesResult.cpp
        result/GetResourceResult.cpp
        result/DescribeEventsResult.cpp
        result/GetEventResult.cpp
        result/DescribeOutputsResult.cpp
        result/GetOutputResult.cpp
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