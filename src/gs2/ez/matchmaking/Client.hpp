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
#include "result/EzListRatingModelsResult.hpp"
#include "result/EzGetRatingModelResult.hpp"
#include "result/EzListRatingsResult.hpp"
#include "result/EzGetRatingResult.hpp"
#include "result/EzCreateVoteResult.hpp"
#include "result/EzVoteResult.hpp"
#include "result/EzVoteMultipleResult.hpp"


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
    ///    expiresAtを指定することでギャザリングの有効期限を設定することができます。<br />
    ///    有効期限を用いない場合、古いギャザリングが残り続けマッチングが成立したときには、<br />
    ///    ユーザーがゲームから離脱している可能性があります。<br />
    ///    有効期限を用いる場合は、有効期限が来るたびにユーザーにギャザリングの再作成を促す仕組みにしてください。<br />
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

    /// <summary>
    ///  レーティングモデルの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listRatingModels(
        std::function<void(AsyncEzListRatingModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  レーティング名を指定してレーティングモデルを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="ratingName">レーティングの種類名</param>
    void getRatingModel(
        std::function<void(AsyncEzGetRatingModelResult)> callback,
        StringHolder namespaceName,
        StringHolder ratingName
    );

    /// <summary>
    ///  レーティング名を指定してレーティングを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listRatings(
        std::function<void(AsyncEzListRatingsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  投票用紙を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="ratingName">レーティング名</param>
    void getRating(
        std::function<void(AsyncEzGetRatingResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder ratingName
    );

    /// <summary>
    ///  投票用紙を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="ratingName">レーティング名</param>
    /// <param name="gatheringName">投票対象のギャザリング名</param>
    void createVote(
        std::function<void(AsyncEzCreateVoteResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder ratingName,
        StringHolder gatheringName
    );

    /// <summary>
    ///  対戦結果を投票します。<br />
    ///    <br />
    ///    投票は最初の投票が行われてから5分以内に行う必要があります。<br />
    ///    つまり、結果は即座に反映されず、投票開始からおよそ5分後または全てのプレイヤーが投票を行った際に結果が反映されます。<br />
    ///    5分以内に全ての投票用紙を回収できなかった場合はその時点の投票内容で多数決をとって結果を決定します。<br />
    ///    各結果の投票数が同一だった場合は結果は捨てられます（スクリプトで挙動を変更可）。<br />
    ///    <br />
    ///    結果を即座に反映したい場合は、勝利した側の代表プレイヤーが投票用紙を各プレイヤーから集めて voteMultiple を呼び出すことで結果を即座に反映できます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="ballotBody">投票用紙の署名対象のデータ</param>
    /// <param name="ballotSignature">投票用紙の署名</param>
    /// <param name="gameResults">投票内容。対戦を行ったプレイヤーグループ1に所属するユーザIDのリスト</param>
    void vote(
        std::function<void(AsyncEzVoteResult)> callback,
        StringHolder namespaceName,
        StringHolder ballotBody,
        StringHolder ballotSignature,
        List<EzGameResult> gameResults
    );

    /// <summary>
    ///  対戦結果をまとめて投票します。<br />
    ///    <br />
    ///    ゲームに勝利した側が他プレイヤーの投票用紙を集めてまとめて投票するのに使用します。<br />
    ///    『勝利した側』としているのは、敗北した側が自分たちが勝ったことにして報告することにインセンティブはありますが、その逆はないためです。<br />
    ///    負けた側が投票用紙を渡してこない可能性がありますが、その場合も過半数の投票用紙があれば結果を通すことができます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="signedBallots">署名付の投票用紙リスト</param>
    /// <param name="gameResults">投票内容。対戦を行ったプレイヤーグループ1に所属するユーザIDのリスト</param>
    void voteMultiple(
        std::function<void(AsyncEzVoteMultipleResult)> callback,
        StringHolder namespaceName,
        List<EzSignedBallot> signedBallots,
        List<EzGameResult> gameResults
    );
};

}}}

#endif //GS2_EZ_MATCHMAKING_GS2MATCHMAKINGWEBSOCKETCLIENT_HPP_