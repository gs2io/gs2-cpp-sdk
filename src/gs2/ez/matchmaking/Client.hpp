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

#ifndef GS2_EZ_MATCHMAKING_GS2MATCHMAKINGWEBSOCKETCLIENT_HPP_
#define GS2_EZ_MATCHMAKING_GS2MATCHMAKINGWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzCreateGatheringResult.hpp"
#include "result/EzUpdateGatheringResult.hpp"
#include "result/EzDoMatchmakingResult.hpp"
#include "result/EzGetGatheringResult.hpp"
#include "result/EzCancelMatchmakingResult.hpp"


namespace gs2 {

namespace matchmaking {

class Gs2MatchmakingWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace matchmaking {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::matchmaking::Gs2MatchmakingWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  ギャザリングを新規作成<br />
    ///    <br />
    ///    Player に指定する自身のプレイヤー情報のユーザIDは省略できます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="player">自身のプレイヤー情報</param>
    /// <param name="attributeRanges">募集条件</param>
    /// <param name="capacityOfRoles">参加者</param>
    /// <param name="allowUserIds">参加を許可するユーザIDリスト</param>
    /// <param name="expiresAt">ギャザリングの有効期限</param>
    void createGathering(
        std::function<void(AsyncEzCreateGatheringResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        EzPlayer player,
        List<EzCapacityOfRole> capacityOfRoles,
        List<StringHolder> allowUserIds,
        gs2::optional<List<EzAttributeRange>> attributeRanges=gs2::nullopt,
        gs2::optional<Int64> expiresAt=gs2::nullopt
    );

    /// <summary>
    ///  ギャザリングの募集条件を変更<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="gatheringName">ギャザリング名</param>
    /// <param name="attributeRanges">募集条件</param>
    void updateGathering(
        std::function<void(AsyncEzUpdateGatheringResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder gatheringName,
        gs2::optional<List<EzAttributeRange>> attributeRanges=gs2::nullopt
    );

    /// <summary>
    ///  すでに存在する中で、自分が参加できるギャザリングを探して参加<br />
    ///    <br />
    ///    一定時間 検索を行い、対象が見つからなかったときには `マッチメイキングの状態を保持するトークン` を返す。<br />
    ///    次回 `マッチメイキングの状態を保持するトークン` をつけて再度リクエストを出すことで、前回の続きから検索処理を再開できる。<br />
    ///    すべてのギャザリングを検索したが、参加できるギャザリングが存在しなかった場合はギャザリングもトークンもどちらも `null` が応答される。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="player">自身のプレイヤー情報</param>
    /// <param name="matchmakingContextToken">検索の再開に使用する マッチメイキングの状態を保持するトークン</param>
    void doMatchmaking(
        std::function<void(AsyncEzDoMatchmakingResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        EzPlayer player,
        gs2::optional<StringHolder> matchmakingContextToken=gs2::nullopt
    );

    /// <summary>
    ///  最新のギャザリングの状態を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="gatheringName">ギャザリング名</param>
    void getGathering(
        std::function<void(AsyncEzGetGatheringResult)> callback,
        StringHolder namespaceName,
        StringHolder gatheringName
    );

    /// <summary>
    ///  マッチメイキングをキャンセルし、参加中のギャザリングから離脱。<br />
    ///    <br />
    ///    ギャザリングから離脱する前にマッチメイキングが完了した場合は、NotFoundException(404エラー) が発生し失敗します。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="gatheringName">ギャザリング名</param>
    void cancelMatchmaking(
        std::function<void(AsyncEzCancelMatchmakingResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder gatheringName
    );
};

}}}

#endif //GS2_EZ_MATCHMAKING_GS2MATCHMAKINGWEBSOCKETCLIENT_HPP_