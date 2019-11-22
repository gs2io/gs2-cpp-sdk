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
project(gs2-cpp-sdk-friend)

file(GLOB ${PROJECT_NAME}_HEADER_FILES
        Gs2Friend.hpp
        Gs2FriendConst.hpp
        Gs2FriendRestClient.hpp
        Gs2FriendWebSocketClient.hpp
        model/model.hpp
        model/Namespace.hpp
        model/Profile.hpp
        model/Follow.hpp
        model/Friend.hpp
        model/SendBox.hpp
        model/Inbox.hpp
        model/ResponseCache.hpp
        model/FollowUser.hpp
        model/FriendUser.hpp
        model/FriendRequest.hpp
        model/PublicProfile.hpp
        model/ScriptSetting.hpp
        model/NotificationSetting.hpp
        model/LogSetting.hpp
        request/DescribeNamespacesRequest.hpp
        request/CreateNamespaceRequest.hpp
        request/GetNamespaceStatusRequest.hpp
        request/GetNamespaceRequest.hpp
        request/UpdateNamespaceRequest.hpp
        request/DeleteNamespaceRequest.hpp
        request/DescribeProfilesRequest.hpp
        request/GetProfileRequest.hpp
        request/GetProfileByUserIdRequest.hpp
        request/UpdateProfileRequest.hpp
        request/UpdateProfileByUserIdRequest.hpp
        request/DeleteProfileByUserIdRequest.hpp
        request/GetPublicProfileRequest.hpp
        request/DescribeFollowsRequest.hpp
        request/DescribeFollowsByUserIdRequest.hpp
        request/GetFollowRequest.hpp
        request/GetFollowByUserIdRequest.hpp
        request/FollowRequest.hpp
        request/FollowByUserIdRequest.hpp
        request/UnfollowRequest.hpp
        request/UnfollowByUserIdRequest.hpp
        request/DescribeFriendsRequest.hpp
        request/DescribeFriendsByUserIdRequest.hpp
        request/GetFriendRequest.hpp
        request/GetFriendByUserIdRequest.hpp
        request/DeleteFriendRequest.hpp
        request/DeleteFriendByUserIdRequest.hpp
        request/DescribeSendRequestsRequest.hpp
        request/DescribeSendRequestsByUserIdRequest.hpp
        request/GetSendRequestRequest.hpp
        request/GetSendRequestByUserIdRequest.hpp
        request/SendRequestRequest.hpp
        request/SendRequestByUserIdRequest.hpp
        request/DeleteRequestRequest.hpp
        request/DeleteRequestByUserIdRequest.hpp
        request/DescribeReceiveRequestsRequest.hpp
        request/DescribeReceiveRequestsByUserIdRequest.hpp
        request/GetReceiveRequestRequest.hpp
        request/GetReceiveRequestByUserIdRequest.hpp
        request/AcceptRequestRequest.hpp
        request/AcceptRequestByUserIdRequest.hpp
        request/RejectRequestRequest.hpp
        request/RejectRequestByUserIdRequest.hpp
        result/DescribeNamespacesResult.hpp
        result/CreateNamespaceResult.hpp
        result/GetNamespaceStatusResult.hpp
        result/GetNamespaceResult.hpp
        result/UpdateNamespaceResult.hpp
        result/DeleteNamespaceResult.hpp
        result/DescribeProfilesResult.hpp
        result/GetProfileResult.hpp
        result/GetProfileByUserIdResult.hpp
        result/UpdateProfileResult.hpp
        result/UpdateProfileByUserIdResult.hpp
        result/DeleteProfileByUserIdResult.hpp
        result/GetPublicProfileResult.hpp
        result/DescribeFollowsResult.hpp
        result/DescribeFollowsByUserIdResult.hpp
        result/GetFollowResult.hpp
        result/GetFollowByUserIdResult.hpp
        result/FollowResult.hpp
        result/FollowByUserIdResult.hpp
        result/UnfollowResult.hpp
        result/UnfollowByUserIdResult.hpp
        result/DescribeFriendsResult.hpp
        result/DescribeFriendsByUserIdResult.hpp
        result/GetFriendResult.hpp
        result/GetFriendByUserIdResult.hpp
        result/DeleteFriendResult.hpp
        result/DeleteFriendByUserIdResult.hpp
        result/DescribeSendRequestsResult.hpp
        result/DescribeSendRequestsByUserIdResult.hpp
        result/GetSendRequestResult.hpp
        result/GetSendRequestByUserIdResult.hpp
        result/SendRequestResult.hpp
        result/SendRequestByUserIdResult.hpp
        result/DeleteRequestResult.hpp
        result/DeleteRequestByUserIdResult.hpp
        result/DescribeReceiveRequestsResult.hpp
        result/DescribeReceiveRequestsByUserIdResult.hpp
        result/GetReceiveRequestResult.hpp
        result/GetReceiveRequestByUserIdResult.hpp
        result/AcceptRequestResult.hpp
        result/AcceptRequestByUserIdResult.hpp
        result/RejectRequestResult.hpp
        result/RejectRequestByUserIdResult.hpp
        )

file(GLOB ${PROJECT_NAME}_SOURCE_FILES
        Gs2FriendRestClient.cpp
        Gs2FriendWebSocketClient.cpp
        model/Namespace.cpp
        model/Profile.cpp
        model/Follow.cpp
        model/Friend.cpp
        model/SendBox.cpp
        model/Inbox.cpp
        model/ResponseCache.cpp
        model/FollowUser.cpp
        model/FriendUser.cpp
        model/FriendRequest.cpp
        model/PublicProfile.cpp
        model/ScriptSetting.cpp
        model/NotificationSetting.cpp
        model/LogSetting.cpp
        result/DescribeNamespacesResult.cpp
        result/CreateNamespaceResult.cpp
        result/GetNamespaceStatusResult.cpp
        result/GetNamespaceResult.cpp
        result/UpdateNamespaceResult.cpp
        result/DeleteNamespaceResult.cpp
        result/DescribeProfilesResult.cpp
        result/GetProfileResult.cpp
        result/GetProfileByUserIdResult.cpp
        result/UpdateProfileResult.cpp
        result/UpdateProfileByUserIdResult.cpp
        result/DeleteProfileByUserIdResult.cpp
        result/GetPublicProfileResult.cpp
        result/DescribeFollowsResult.cpp
        result/DescribeFollowsByUserIdResult.cpp
        result/GetFollowResult.cpp
        result/GetFollowByUserIdResult.cpp
        result/FollowResult.cpp
        result/FollowByUserIdResult.cpp
        result/UnfollowResult.cpp
        result/UnfollowByUserIdResult.cpp
        result/DescribeFriendsResult.cpp
        result/DescribeFriendsByUserIdResult.cpp
        result/GetFriendResult.cpp
        result/GetFriendByUserIdResult.cpp
        result/DeleteFriendResult.cpp
        result/DeleteFriendByUserIdResult.cpp
        result/DescribeSendRequestsResult.cpp
        result/DescribeSendRequestsByUserIdResult.cpp
        result/GetSendRequestResult.cpp
        result/GetSendRequestByUserIdResult.cpp
        result/SendRequestResult.cpp
        result/SendRequestByUserIdResult.cpp
        result/DeleteRequestResult.cpp
        result/DeleteRequestByUserIdResult.cpp
        result/DescribeReceiveRequestsResult.cpp
        result/DescribeReceiveRequestsByUserIdResult.cpp
        result/GetReceiveRequestResult.cpp
        result/GetReceiveRequestByUserIdResult.cpp
        result/AcceptRequestResult.cpp
        result/AcceptRequestByUserIdResult.cpp
        result/RejectRequestResult.cpp
        result/RejectRequestByUserIdResult.cpp
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