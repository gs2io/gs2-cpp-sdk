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
project(gs2-cpp-sdk-ez)

include(../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Authenticator.hpp
        Client.hpp
        EzStampSheet.hpp
        EzStampTask.hpp
        GameSession.hpp
        Gs2AccountAuthenticator.hpp
        Gs2BasicReopener.hpp
        Gs2Ez.hpp
        Profile.hpp
        Reopener.hpp
        StampSheetStateMachine.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2_Ez_EzStampSheet.cpp
        Gs2_Ez_EzStampTask.cpp
        Gs2_Ez_Gs2AccountAuthenticator.cpp
        Gs2_Ez_Gs2BasicReopener.cpp
        Gs2_Ez_Profile.cpp
        Gs2_Ez_StampSheetStateMachine.cpp
        )

gs2_add_library(${PROJECT_NAME} STATIC
        "${${PROJECT_NAME}_SOURCE_FILES}"
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})

gs2_target_link_libraries(${PROJECT_NAME}
        PUBLIC gs2-cpp-sdk-core
        )

gs2_add_dependencies(gs2-cpp-sdk-all
        ${PROJECT_NAME}
        )

set(gs2-cpp-sdk_FILES
        ${gs2-cpp-sdk_FILES}
        ${${PROJECT_NAME}_FILES}
        PARENT_SCOPE
        )

add_subdirectory(account)
add_subdirectory(auth)
add_subdirectory(chat)
add_subdirectory(datastore)
add_subdirectory(distributor)
add_subdirectory(exchange)
add_subdirectory(experience)
add_subdirectory(formation)
add_subdirectory(friend)
add_subdirectory(gateway)
add_subdirectory(inbox)
add_subdirectory(inventory)
add_subdirectory(jobQueue)
add_subdirectory(limit)
add_subdirectory(lock)
add_subdirectory(lottery)
add_subdirectory(matchmaking)
add_subdirectory(mission)
add_subdirectory(money)
add_subdirectory(news)
add_subdirectory(quest)
add_subdirectory(ranking)
add_subdirectory(realtime)
add_subdirectory(schedule)
add_subdirectory(showcase)
add_subdirectory(stamina)
add_subdirectory(version)

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )
