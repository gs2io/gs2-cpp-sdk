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
project(gs2-cpp-sdk-schedule)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Schedule.hpp
        Gs2ScheduleConst.hpp
        Gs2ScheduleRestClient.hpp
        Gs2ScheduleWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/EventMaster.hpp
        model/Trigger.hpp
        model/Event.hpp
        model/CurrentEventMaster.hpp
        model/ResponseCache.hpp
        model/GitHubCheckoutSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeEventMastersRequest.hpp
        request/CreateEventMasterRequest.hpp
        request/GetEventMasterRequest.hpp
        request/UpdateEventMasterRequest.hpp
        request/DeleteEventMasterRequest.hpp
        request/DescribeTriggersRequest.hpp
        request/DescribeTriggersByUserIdRequest.hpp
        request/GetTriggerRequest.hpp
        request/GetTriggerByUserIdRequest.hpp
        request/TriggerByUserIdRequest.hpp
        request/DeleteTriggerRequest.hpp
        request/DeleteTriggerByUserIdRequest.hpp
        request/DescribeEventsRequest.hpp
        request/DescribeEventsByUserIdRequest.hpp
        request/DescribeRawEventsRequest.hpp
        request/GetEventRequest.hpp
        request/GetEventByUserIdRequest.hpp
        request/GetRawEventRequest.hpp
        request/ExportMasterRequest.hpp
        request/GetCurrentEventMasterRequest.hpp
        request/UpdateCurrentEventMasterRequest.hpp
        request/UpdateCurrentEventMasterFromGitHubRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeEventMastersResult.hpp
        result/CreateEventMasterResult.hpp
        result/GetEventMasterResult.hpp
        result/UpdateEventMasterResult.hpp
        result/DeleteEventMasterResult.hpp
        result/DescribeTriggersResult.hpp
        result/DescribeTriggersByUserIdResult.hpp
        result/GetTriggerResult.hpp
        result/GetTriggerByUserIdResult.hpp
        result/TriggerByUserIdResult.hpp
        result/DeleteTriggerResult.hpp
        result/DeleteTriggerByUserIdResult.hpp
        result/DescribeEventsResult.hpp
        result/DescribeEventsByUserIdResult.hpp
        result/DescribeRawEventsResult.hpp
        result/GetEventResult.hpp
        result/GetEventByUserIdResult.hpp
        result/GetRawEventResult.hpp
        result/ExportMasterResult.hpp
        result/GetCurrentEventMasterResult.hpp
        result/UpdateCurrentEventMasterResult.hpp
        result/UpdateCurrentEventMasterFromGitHubResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2ScheduleRestClient.cpp
        Gs2ScheduleWebSocketClient.cpp
        model/Namespace.cpp
        model/EventMaster.cpp
        model/Trigger.cpp
        model/Event.cpp
        model/CurrentEventMaster.cpp
        model/ResponseCache.cpp
        model/GitHubCheckoutSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeEventMastersResult.cpp
        result/CreateEventMasterResult.cpp
        result/GetEventMasterResult.cpp
        result/UpdateEventMasterResult.cpp
        result/DeleteEventMasterResult.cpp
        result/DescribeTriggersResult.cpp
        result/DescribeTriggersByUserIdResult.cpp
        result/GetTriggerResult.cpp
        result/GetTriggerByUserIdResult.cpp
        result/TriggerByUserIdResult.cpp
        result/DeleteTriggerResult.cpp
        result/DeleteTriggerByUserIdResult.cpp
        result/DescribeEventsResult.cpp
        result/DescribeEventsByUserIdResult.cpp
        result/DescribeRawEventsResult.cpp
        result/GetEventResult.cpp
        result/GetEventByUserIdResult.cpp
        result/GetRawEventResult.cpp
        result/ExportMasterResult.cpp
        result/GetCurrentEventMasterResult.cpp
        result/UpdateCurrentEventMasterResult.cpp
        result/UpdateCurrentEventMasterFromGitHubResult.cpp
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