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
project(gs2-cpp-sdk-job-queue)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2JobQueue.hpp
        Gs2JobQueueConst.hpp
        Gs2JobQueueRestClient.hpp
        Gs2JobQueueWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Job.hpp
        model/JobResult.hpp
        model/DeadLetterJob.hpp
        model/ResponseCache.hpp
        model/NotificationSetting.hpp
        model/LogSetting.hpp
        model/JobEntry.hpp
        model/JobResultBody.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeJobsByUserIdRequest.hpp
        request/GetJobByUserIdRequest.hpp
        request/PushByUserIdRequest.hpp
        request/RunRequest.hpp
        request/RunByUserIdRequest.hpp
        request/DeleteJobByUserIdRequest.hpp
        request/PushByStampSheetRequest.hpp
        request/DescribeDeadLetterJobsByUserIdRequest.hpp
        request/GetDeadLetterJobByUserIdRequest.hpp
        request/DeleteDeadLetterJobByUserIdRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeJobsByUserIdResult.hpp
        result/GetJobByUserIdResult.hpp
        result/PushByUserIdResult.hpp
        result/RunResult.hpp
        result/RunByUserIdResult.hpp
        result/DeleteJobByUserIdResult.hpp
        result/PushByStampSheetResult.hpp
        result/DescribeDeadLetterJobsByUserIdResult.hpp
        result/GetDeadLetterJobByUserIdResult.hpp
        result/DeleteDeadLetterJobByUserIdResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2JobQueueRestClient.cpp
        Gs2JobQueueWebSocketClient.cpp
        model/Namespace.cpp
        model/Job.cpp
        model/JobResult.cpp
        model/DeadLetterJob.cpp
        model/ResponseCache.cpp
        model/NotificationSetting.cpp
        model/LogSetting.cpp
        model/JobEntry.cpp
        model/JobResultBody.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeJobsByUserIdResult.cpp
        result/GetJobByUserIdResult.cpp
        result/PushByUserIdResult.cpp
        result/RunResult.cpp
        result/RunByUserIdResult.cpp
        result/DeleteJobByUserIdResult.cpp
        result/PushByStampSheetResult.cpp
        result/DescribeDeadLetterJobsByUserIdResult.cpp
        result/GetDeadLetterJobByUserIdResult.cpp
        result/DeleteDeadLetterJobByUserIdResult.cpp
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