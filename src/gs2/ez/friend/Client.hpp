/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0(the "License").
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

#ifndef GS2_EZ_FRIEND_GS2FRIENDWEBSOCKETCLIENT_HPP_
#define GS2_EZ_FRIEND_GS2FRIENDWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzGetProfileResult.hpp"
#include "result/EzUpdateProfileResult.hpp"
#include "result/EzGetPublicProfileResult.hpp"
#include "result/EzDescribeFollowUsersResult.hpp"
#include "result/EzFollowResult.hpp"
#include "result/EzUnfollowResult.hpp"
#include "result/EzDescribeFriendsResult.hpp"
#include "result/EzGetFriendResult.hpp"
#include "result/EzDeleteFriendResult.hpp"
#include "result/EzDescribeSendRequestsResult.hpp"
#include "result/EzSendRequestResult.hpp"
#include "result/EzDeleteRequestResult.hpp"
#include "result/EzDescribeReceiveRequestsResult.hpp"
#include "result/EzAcceptResult.hpp"
#include "result/EzRejectResult.hpp"


namespace gs2 {

namespace friend_ {

class Gs2FriendWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace friend_ {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::friend_::Gs2FriendWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  自分のプロフィールを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void getProfile(
        std::function<void(AsyncEzGetProfileResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );

    /// <summary>
    ///  自分のプロフィールを更新<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="publicProfile">公開されるプロフィール</param>
    /// <param name="followerProfile">フォロワー向けに公開されるプロフィール</param>
    /// <param name="friendProfile">フレンド向けに公開されるプロフィール</param>
    void updateProfile(
        std::function<void(AsyncEzUpdateProfileResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> publicProfile=gs2::nullopt,
        gs2::optional<StringHolder> followerProfile=gs2::nullopt,
        gs2::optional<StringHolder> friendProfile=gs2::nullopt
    );

    /// <summary>
    ///  他人の公開プロフィールを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="userId">ユーザーID</param>
    void getPublicProfile(
        std::function<void(AsyncEzGetPublicProfileResult)> callback,
        StringHolder namespaceName,
        StringHolder userId
    );

    /// <summary>
    ///  他プレイヤーをフォローする<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="withProfile">プロフィールも一緒に取得するか</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void describeFollowUsers(
        std::function<void(AsyncEzDescribeFollowUsersResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        Bool withProfile,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  他プレイヤーをフォローする<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="targetUserId">フォローされるユーザID</param>
    void follow(
        std::function<void(AsyncEzFollowResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder targetUserId
    );

    /// <summary>
    ///  フォローしている相手をアンフォローする<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="targetUserId">フォローされているユーザID</param>
    void unfollow(
        std::function<void(AsyncEzUnfollowResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder targetUserId
    );

    /// <summary>
    ///  フレンドの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="withProfile">プロフィールも一緒に取得するか</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void describeFriends(
        std::function<void(AsyncEzDescribeFriendsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        Bool withProfile,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  フレンドを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="targetUserId">ユーザーID</param>
    /// <param name="withProfile">プロフィールも一緒に取得するか</param>
    void getFriend(
        std::function<void(AsyncEzGetFriendResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder targetUserId,
        Bool withProfile
    );

    /// <summary>
    ///  フレンドを削除<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="targetUserId">ユーザーID</param>
    void deleteFriend(
        std::function<void(AsyncEzDeleteFriendResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder targetUserId
    );

    /// <summary>
    ///  送信したフレンドリクエストの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void describeSendRequests(
        std::function<void(AsyncEzDescribeSendRequestsResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );

    /// <summary>
    ///  <br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="targetUserId">リクエストの送信先ユーザID</param>
    void sendRequest(
        std::function<void(AsyncEzSendRequestResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder targetUserId
    );

    /// <summary>
    ///  <br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="targetUserId">リクエストの送信先ユーザID</param>
    void deleteRequest(
        std::function<void(AsyncEzDeleteRequestResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder targetUserId
    );

    /// <summary>
    ///  受信したフレンドリクエスト一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void describeReceiveRequests(
        std::function<void(AsyncEzDescribeReceiveRequestsResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );

    /// <summary>
    ///  フレンドリクエストを承認<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="fromUserId">フレンドリクエストを送信したユーザID</param>
    void accept(
        std::function<void(AsyncEzAcceptResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder fromUserId
    );

    /// <summary>
    ///  フレンドリクエストを拒否<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="fromUserId">フレンドリクエストを送信したユーザID</param>
    void reject(
        std::function<void(AsyncEzRejectResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder fromUserId
    );
};

}}}

#endif //GS2_EZ_FRIEND_GS2FRIENDWEBSOCKETCLIENT_HPP_