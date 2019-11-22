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

#ifndef GS2_EZ_CHAT_GS2CHATWEBSOCKETCLIENT_HPP_
#define GS2_EZ_CHAT_GS2CHATWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzCreateRoomResult.hpp"
#include "result/EzGetRoomResult.hpp"
#include "result/EzDeleteRoomResult.hpp"
#include "result/EzPostResult.hpp"
#include "result/EzListMessagesResult.hpp"
#include "result/EzListSubscribeRoomsResult.hpp"
#include "result/EzSubscribeResult.hpp"
#include "result/EzUpdateSubscribeSettingResult.hpp"
#include "result/EzUnsubscribeResult.hpp"


namespace gs2 {

namespace chat {

class Gs2ChatWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace chat {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::chat::Gs2ChatWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  ルームの作成<br />
    ///    <br />
    ///    ネームスペースの設定でゲームプレイヤーによるルーム作成が許可されていない場合、失敗します。<br />
    ///    ルームにパスワードを設定すると発言する際にパスワードが一致しなければ発言できません。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="metadata">メタデータ</param>
    /// <param name="password">メッセージを投稿するために必要となるパスワード</param>
    /// <param name="whiteListUserIds">ルームに参加可能なユーザIDリスト</param>
    void createRoom(
        std::function<void(AsyncEzCreateRoomResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> metadata=gs2::nullopt,
        gs2::optional<StringHolder> password=gs2::nullopt,
        gs2::optional<List<StringHolder>> whiteListUserIds=gs2::nullopt
    );

    /// <summary>
    ///  ルームの取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="roomName">ルーム名</param>
    void getRoom(
        std::function<void(AsyncEzGetRoomResult)> callback,
        StringHolder namespaceName,
        StringHolder roomName
    );

    /// <summary>
    ///  ルームの削除<br />
    ///    <br />
    ///    自分が作成したルームに対してしか実行できません。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="roomName">ルーム名</param>
    void deleteRoom(
        std::function<void(AsyncEzDeleteRoomResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder roomName
    );

    /// <summary>
    ///  メッセージを投稿します<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="roomName">ルーム名</param>
    /// <param name="category">メッセージの種類を分類したい時の種類番号</param>
    /// <param name="metadata">メタデータ</param>
    /// <param name="password">メッセージを投稿するために必要となるパスワード</param>
    void post(
        std::function<void(AsyncEzPostResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder roomName,
        Int32 category,
        StringHolder metadata,
        gs2::optional<StringHolder> password=gs2::nullopt
    );

    /// <summary>
    ///  ルーム内のメッセージ一覧を取得<br />
    ///    <br />
    ///    startAt にしていた時刻以降に投稿されたメッセージを取得できます<br />
    ///    startAt と完全一致するメッセージも対象に含まれます<br />
    ///    <br />
    ///    メッセージは投稿の古いものから順番に取得されます<br />
    ///    <br />
    ///    メッセージは過去1時間分まで遡れます<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="roomName">ルーム名</param>
    /// <param name="startAt">メッセージの取得を開始する時間</param>
    /// <param name="limit">データの取得件数</param>
    void listMessages(
        std::function<void(AsyncEzListMessagesResult)> callback,
        StringHolder namespaceName,
        StringHolder roomName,
        gs2::optional<Int64> startAt=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  購読しているルームの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listSubscribeRooms(
        std::function<void(AsyncEzListSubscribeRoomsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  ルームを購読<br />
    ///    <br />
    ///    ルームを購読することで、そのルームに関する新着メッセージ投稿の通知を受けることができます<br />
    ///    購読する際のオプションとして、「メッセージに付加されたカテゴリが特定の値のものだけ通知する」といった設定や<br />
    ///    「通知を受けたときにオフラインだった場合、モバイルプッシュ通知に転送する」といった設定ができます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="roomName">ルーム名</param>
    /// <param name="notificationTypes">新着メッセージ通知を受け取るカテゴリリスト</param>
    void subscribe(
        std::function<void(AsyncEzSubscribeResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder roomName,
        gs2::optional<List<EzNotificationType>> notificationTypes=gs2::nullopt
    );

    /// <summary>
    ///  購読設定の更新<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="roomName">ルーム名</param>
    /// <param name="notificationTypes">新着メッセージ通知を受け取るカテゴリリスト</param>
    void updateSubscribeSetting(
        std::function<void(AsyncEzUpdateSubscribeSettingResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder roomName,
        gs2::optional<List<EzNotificationType>> notificationTypes=gs2::nullopt
    );

    /// <summary>
    ///  購読の解除<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="roomName">ルーム名</param>
    void unsubscribe(
        std::function<void(AsyncEzUnsubscribeResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder roomName
    );
};

}}}

#endif //GS2_EZ_CHAT_GS2CHATWEBSOCKETCLIENT_HPP_