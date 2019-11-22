/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef GS2_FRIEND_GS2FRIENDRESTCLIENT_HPP_
#define GS2_FRIEND_GS2FRIENDRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeProfilesRequest.hpp"
#include "request/GetProfileRequest.hpp"
#include "request/GetProfileByUserIdRequest.hpp"
#include "request/UpdateProfileRequest.hpp"
#include "request/UpdateProfileByUserIdRequest.hpp"
#include "request/DeleteProfileByUserIdRequest.hpp"
#include "request/GetPublicProfileRequest.hpp"
#include "request/DescribeFollowsRequest.hpp"
#include "request/DescribeFollowsByUserIdRequest.hpp"
#include "request/GetFollowRequest.hpp"
#include "request/GetFollowByUserIdRequest.hpp"
#include "request/FollowRequest.hpp"
#include "request/FollowByUserIdRequest.hpp"
#include "request/UnfollowRequest.hpp"
#include "request/UnfollowByUserIdRequest.hpp"
#include "request/DescribeFriendsRequest.hpp"
#include "request/DescribeFriendsByUserIdRequest.hpp"
#include "request/GetFriendRequest.hpp"
#include "request/GetFriendByUserIdRequest.hpp"
#include "request/DeleteFriendRequest.hpp"
#include "request/DeleteFriendByUserIdRequest.hpp"
#include "request/DescribeSendRequestsRequest.hpp"
#include "request/DescribeSendRequestsByUserIdRequest.hpp"
#include "request/GetSendRequestRequest.hpp"
#include "request/GetSendRequestByUserIdRequest.hpp"
#include "request/SendRequestRequest.hpp"
#include "request/SendRequestByUserIdRequest.hpp"
#include "request/DeleteRequestRequest.hpp"
#include "request/DeleteRequestByUserIdRequest.hpp"
#include "request/DescribeReceiveRequestsRequest.hpp"
#include "request/DescribeReceiveRequestsByUserIdRequest.hpp"
#include "request/GetReceiveRequestRequest.hpp"
#include "request/GetReceiveRequestByUserIdRequest.hpp"
#include "request/AcceptRequestRequest.hpp"
#include "request/AcceptRequestByUserIdRequest.hpp"
#include "request/RejectRequestRequest.hpp"
#include "request/RejectRequestByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeProfilesResult.hpp"
#include "result/GetProfileResult.hpp"
#include "result/GetProfileByUserIdResult.hpp"
#include "result/UpdateProfileResult.hpp"
#include "result/UpdateProfileByUserIdResult.hpp"
#include "result/DeleteProfileByUserIdResult.hpp"
#include "result/GetPublicProfileResult.hpp"
#include "result/DescribeFollowsResult.hpp"
#include "result/DescribeFollowsByUserIdResult.hpp"
#include "result/GetFollowResult.hpp"
#include "result/GetFollowByUserIdResult.hpp"
#include "result/FollowResult.hpp"
#include "result/FollowByUserIdResult.hpp"
#include "result/UnfollowResult.hpp"
#include "result/UnfollowByUserIdResult.hpp"
#include "result/DescribeFriendsResult.hpp"
#include "result/DescribeFriendsByUserIdResult.hpp"
#include "result/GetFriendResult.hpp"
#include "result/GetFriendByUserIdResult.hpp"
#include "result/DeleteFriendResult.hpp"
#include "result/DeleteFriendByUserIdResult.hpp"
#include "result/DescribeSendRequestsResult.hpp"
#include "result/DescribeSendRequestsByUserIdResult.hpp"
#include "result/GetSendRequestResult.hpp"
#include "result/GetSendRequestByUserIdResult.hpp"
#include "result/SendRequestResult.hpp"
#include "result/SendRequestByUserIdResult.hpp"
#include "result/DeleteRequestResult.hpp"
#include "result/DeleteRequestByUserIdResult.hpp"
#include "result/DescribeReceiveRequestsResult.hpp"
#include "result/DescribeReceiveRequestsByUserIdResult.hpp"
#include "result/GetReceiveRequestResult.hpp"
#include "result/GetReceiveRequestByUserIdResult.hpp"
#include "result/AcceptRequestResult.hpp"
#include "result/AcceptRequestByUserIdResult.hpp"
#include "result/RejectRequestResult.hpp"
#include "result/RejectRequestByUserIdResult.hpp"

namespace gs2 { namespace friend_ {

/**
 * GS2 Friend API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2FriendRestClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2FriendRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback);

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback);

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback);

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback);

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback);

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback);

	/**
	 * ユーザーIDを指定してプロフィールの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProfiles(DescribeProfilesRequest request, std::function<void(AsyncDescribeProfilesResult)> callback);

	/**
	 * プロフィールを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProfile(GetProfileRequest request, std::function<void(AsyncGetProfileResult)> callback);

	/**
	 * ユーザーIDを指定してプロフィールを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProfileByUserId(GetProfileByUserIdRequest request, std::function<void(AsyncGetProfileByUserIdResult)> callback);

	/**
	 * プロフィールを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateProfile(UpdateProfileRequest request, std::function<void(AsyncUpdateProfileResult)> callback);

	/**
	 * ユーザーIDを指定してプロフィールを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateProfileByUserId(UpdateProfileByUserIdRequest request, std::function<void(AsyncUpdateProfileByUserIdResult)> callback);

	/**
	 * プロフィールを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProfileByUserId(DeleteProfileByUserIdRequest request, std::function<void(AsyncDeleteProfileByUserIdResult)> callback);

	/**
	 * 公開プロフィールを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPublicProfile(GetPublicProfileRequest request, std::function<void(AsyncGetPublicProfileResult)> callback);

	/**
	 * フォローの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFollows(DescribeFollowsRequest request, std::function<void(AsyncDescribeFollowsResult)> callback);

	/**
	 * ユーザーIDを指定してフォローの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFollowsByUserId(DescribeFollowsByUserIdRequest request, std::function<void(AsyncDescribeFollowsByUserIdResult)> callback);

	/**
	 * フォローを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFollow(GetFollowRequest request, std::function<void(AsyncGetFollowResult)> callback);

	/**
	 * ユーザーIDを指定してフォローを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFollowByUserId(GetFollowByUserIdRequest request, std::function<void(AsyncGetFollowByUserIdResult)> callback);

	/**
	 * フォロー<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void follow(FollowRequest request, std::function<void(AsyncFollowResult)> callback);

	/**
	 * ユーザーIDを指定してフォロー<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void followByUserId(FollowByUserIdRequest request, std::function<void(AsyncFollowByUserIdResult)> callback);

	/**
	 * アンフォロー<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unfollow(UnfollowRequest request, std::function<void(AsyncUnfollowResult)> callback);

	/**
	 * ユーザーIDを指定してアンフォロー<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unfollowByUserId(UnfollowByUserIdRequest request, std::function<void(AsyncUnfollowByUserIdResult)> callback);

	/**
	 * フレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFriends(DescribeFriendsRequest request, std::function<void(AsyncDescribeFriendsResult)> callback);

	/**
	 * ユーザーIDを指定してフレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFriendsByUserId(DescribeFriendsByUserIdRequest request, std::function<void(AsyncDescribeFriendsByUserIdResult)> callback);

	/**
	 * フレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFriend(GetFriendRequest request, std::function<void(AsyncGetFriendResult)> callback);

	/**
	 * ユーザーIDを指定してフレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFriendByUserId(GetFriendByUserIdRequest request, std::function<void(AsyncGetFriendByUserIdResult)> callback);

	/**
	 * フレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFriend(DeleteFriendRequest request, std::function<void(AsyncDeleteFriendResult)> callback);

	/**
	 * ユーザーIDを指定してフレンドを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFriendByUserId(DeleteFriendByUserIdRequest request, std::function<void(AsyncDeleteFriendByUserIdResult)> callback);

	/**
	 * 送信したフレンドリクエストの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSendRequests(DescribeSendRequestsRequest request, std::function<void(AsyncDescribeSendRequestsResult)> callback);

	/**
	 * ユーザーIDを指定して送信したフレンドリクエストの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSendRequestsByUserId(DescribeSendRequestsByUserIdRequest request, std::function<void(AsyncDescribeSendRequestsByUserIdResult)> callback);

	/**
	 * 送信したフレンドリクエストを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSendRequest(GetSendRequestRequest request, std::function<void(AsyncGetSendRequestResult)> callback);

	/**
	 * ユーザーIDを指定して送信したフレンドリクエストを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSendRequestByUserId(GetSendRequestByUserIdRequest request, std::function<void(AsyncGetSendRequestByUserIdResult)> callback);

	/**
	 * フレンドリクエストを送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendRequest(SendRequestRequest request, std::function<void(AsyncSendRequestResult)> callback);

	/**
	 * ユーザーIDを指定してフレンドリクエストを送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendRequestByUserId(SendRequestByUserIdRequest request, std::function<void(AsyncSendRequestByUserIdResult)> callback);

	/**
	 * フレンドリクエストを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRequest(DeleteRequestRequest request, std::function<void(AsyncDeleteRequestResult)> callback);

	/**
	 * ユーザーIDを指定してフレンドリクエストを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRequestByUserId(DeleteRequestByUserIdRequest request, std::function<void(AsyncDeleteRequestByUserIdResult)> callback);

	/**
	 * 受信したフレンドリクエストの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceiveRequests(DescribeReceiveRequestsRequest request, std::function<void(AsyncDescribeReceiveRequestsResult)> callback);

	/**
	 * ユーザーIDを指定して受信したフレンドリクエストの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceiveRequestsByUserId(DescribeReceiveRequestsByUserIdRequest request, std::function<void(AsyncDescribeReceiveRequestsByUserIdResult)> callback);

	/**
	 * 受信したフレンドリクエストを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getReceiveRequest(GetReceiveRequestRequest request, std::function<void(AsyncGetReceiveRequestResult)> callback);

	/**
	 * ユーザーIDを指定して受信したフレンドリクエストを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getReceiveRequestByUserId(GetReceiveRequestByUserIdRequest request, std::function<void(AsyncGetReceiveRequestByUserIdResult)> callback);

	/**
	 * フレンドリクエストを承諾<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acceptRequest(AcceptRequestRequest request, std::function<void(AsyncAcceptRequestResult)> callback);

	/**
	 * ユーザーIDを指定してフレンドリクエストを承諾<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acceptRequestByUserId(AcceptRequestByUserIdRequest request, std::function<void(AsyncAcceptRequestByUserIdResult)> callback);

	/**
	 * フレンドリクエストを拒否<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void rejectRequest(RejectRequestRequest request, std::function<void(AsyncRejectRequestResult)> callback);

	/**
	 * ユーザーIDを指定してフレンドリクエストを拒否<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void rejectRequestByUserId(RejectRequestByUserIdRequest request, std::function<void(AsyncRejectRequestByUserIdResult)> callback);

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_FRIEND_GS2FRIENDRESTCLIENT_HPP_