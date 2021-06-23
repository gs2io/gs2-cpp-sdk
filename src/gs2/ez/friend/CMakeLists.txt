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
project(gs2-cpp-sdk-ez-friend)

include(../../Gs2Sdk.cmake)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Client.hpp
        model/model.hpp
        model/EzProfile.hpp
        model/EzBlackList.hpp
        model/EzFollowUser.hpp
        model/EzFriendUser.hpp
        model/EzFriendRequest.hpp
        model/EzPublicProfile.hpp
        result/EzGetProfileResult.hpp
        result/EzUpdateProfileResult.hpp
        result/EzGetPublicProfileResult.hpp
        result/EzDescribeFollowUsersResult.hpp
        result/EzFollowResult.hpp
        result/EzUnfollowResult.hpp
        result/EzDescribeFriendsResult.hpp
        result/EzGetFriendResult.hpp
        result/EzDeleteFriendResult.hpp
        result/EzDescribeSendRequestsResult.hpp
        result/EzSendRequestResult.hpp
        result/EzDeleteRequestResult.hpp
        result/EzDescribeReceiveRequestsResult.hpp
        result/EzAcceptResult.hpp
        result/EzRejectResult.hpp
        result/EzGetBlackListResult.hpp
        result/EzRegisterBlackListResult.hpp
        result/EzUnregisterBlackListResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2_Ez_Friend_Client.cpp
        model/Gs2_Ez_Friend_EzProfile.cpp
        model/Gs2_Ez_Friend_EzBlackList.cpp
        model/Gs2_Ez_Friend_EzFollowUser.cpp
        model/Gs2_Ez_Friend_EzFriendUser.cpp
        model/Gs2_Ez_Friend_EzFriendRequest.cpp
        model/Gs2_Ez_Friend_EzPublicProfile.cpp
        )

gs2_add_library(${PROJECT_NAME} STATIC
        "${${PROJECT_NAME}_SOURCE_FILES}"
        )

gs2_inherit_cocos2dx_settings(${PROJECT_NAME})

gs2_target_link_libraries(${PROJECT_NAME}
        PUBLIC gs2-cpp-sdk-ez
        )

gs2_add_dependencies(gs2-cpp-sdk-all
        ${PROJECT_NAME}
        )

set(GS2_ALL_LIBRARIES
        ${GS2_ALL_LIBRARIES}
        ${PROJECT_NAME}
        PARENT_SCOPE
        )