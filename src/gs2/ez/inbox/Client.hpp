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

#ifndef GS2_EZ_INBOX_GS2INBOXWEBSOCKETCLIENT_HPP_
#define GS2_EZ_INBOX_GS2INBOXWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListResult.hpp"
#include "result/EzReceiveGlobalMessageResult.hpp"
#include "result/EzReadResult.hpp"
#include "result/EzDeleteResult.hpp"


namespace gs2 {

namespace inbox {

class Gs2InboxWebSocketClient;
class Gs2InboxRestClient;

}

namespace ez {

class Profile;
class GameSession;

namespace inbox {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::inbox::Gs2InboxWebSocketClient* m_pWebSocketClient;
    gs2::inbox::Gs2InboxRestClient* m_pRestClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  プレゼントボックス に届いているメッセージの一覧を取得<br />
    ///    <br />
    ///    メッセージは最新のメッセージから順番に取得できます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void list(
        std::function<void(AsyncEzListResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  グローバルメッセージを受信する<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void receiveGlobalMessage(
        std::function<void(AsyncEzReceiveGlobalMessageResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );

    /// <summary>
    ///  メッセージを既読にする<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="messageName">メッセージID</param>
    void read(
        std::function<void(AsyncEzReadResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> messageName=gs2::nullopt
    );

    /// <summary>
    ///  メッセージを削除する<br />
    ///    <br />
    ///    プレゼントボックスの設定でメッセージを開封したときに自動的に削除するオプションを付けていない場合は、このAPIを使用して明示的にメッセージを削除する必要があります。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="messageName">メッセージID</param>
    void delete_(
        std::function<void(AsyncEzDeleteResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder messageName
    );
};

}}}

#endif //GS2_EZ_INBOX_GS2INBOXWEBSOCKETCLIENT_HPP_