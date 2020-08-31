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

#ifndef GS2_EZ_RANKING_GS2RANKINGWEBSOCKETCLIENT_HPP_
#define GS2_EZ_RANKING_GS2RANKINGWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListCategoriesResult.hpp"
#include "result/EzGetCategoryResult.hpp"
#include "result/EzListSubscribesResult.hpp"
#include "result/EzSubscribeResult.hpp"
#include "result/EzUnsubscribeResult.hpp"
#include "result/EzListScoresResult.hpp"
#include "result/EzGetScoreResult.hpp"
#include "result/EzPutScoreResult.hpp"
#include "result/EzGetRankingResult.hpp"
#include "result/EzGetNearRankingResult.hpp"
#include "result/EzGetRankResult.hpp"


namespace gs2 {

namespace ranking {

class Gs2RankingWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace ranking {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::ranking::Gs2RankingWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  カテゴリの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listCategories(
        std::function<void(AsyncEzListCategoriesResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  カテゴリの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリモデル名</param>
    void getCategory(
        std::function<void(AsyncEzGetCategoryResult)> callback,
        StringHolder namespaceName,
        StringHolder categoryName
    );

    /// <summary>
    ///  購読しているユーザIDの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリ名</param>
    void listSubscribes(
        std::function<void(AsyncEzListSubscribesResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder categoryName
    );

    /// <summary>
    ///  ユーザIDを購読<br />
    ///    <br />
    ///    ユーザIDを購読することで、そのユーザIDに関する新着メッセージ投稿の通知を受けることができます<br />
    ///    購読する際のオプションとして、「メッセージに付加されたカテゴリが特定の値のものだけ通知する」といった設定や<br />
    ///    「通知を受けたときにオフラインだった場合、モバイルプッシュ通知に転送する」といった設定ができます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリ名</param>
    /// <param name="targetUserId">購読されるユーザID</param>
    void subscribe(
        std::function<void(AsyncEzSubscribeResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder categoryName,
        StringHolder targetUserId
    );

    /// <summary>
    ///  購読の解除<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリ名</param>
    /// <param name="targetUserId">購読されるユーザID</param>
    void unsubscribe(
        std::function<void(AsyncEzUnsubscribeResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder categoryName,
        StringHolder targetUserId
    );

    /// <summary>
    ///  ゲームプレイヤーが登録したスコアの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリ名</param>
    /// <param name="scorerUserId">スコアを獲得したユーザID</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listScores(
        std::function<void(AsyncEzListScoresResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder categoryName,
        StringHolder scorerUserId,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  ゲームプレイヤーが登録したスコアを取得<br />
    ///    <br />
    ///    ユーザID毎にスコアを1つしか登録できないカテゴリを指定する場合、ユニークIDは省略可能です<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリ名</param>
    /// <param name="scorerUserId">スコアを獲得したユーザID</param>
    /// <param name="uniqueId">スコアのユニークID</param>
    void getScore(
        std::function<void(AsyncEzGetScoreResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder categoryName,
        StringHolder scorerUserId,
        gs2::optional<StringHolder> uniqueId=gs2::nullopt
    );

    /// <summary>
    ///  ランキングの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリ名</param>
    /// <param name="score">スコア</param>
    /// <param name="metadata">メタデータ</param>
    void putScore(
        std::function<void(AsyncEzPutScoreResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder categoryName,
        Int64 score,
        gs2::optional<StringHolder> metadata=gs2::nullopt
    );

    /// <summary>
    ///  ランキングの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリ名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    /// <param name="startIndex">ランキングの取得を開始するインデックス</param>
    void getRanking(
        std::function<void(AsyncEzGetRankingResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder categoryName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt,
        gs2::optional<Int64> startIndex=gs2::nullopt
    );

    /// <summary>
    ///  ランキングの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリ名</param>
    /// <param name="score">スコア</param>
    void getNearRanking(
        std::function<void(AsyncEzGetNearRankingResult)> callback,
        StringHolder namespaceName,
        StringHolder categoryName,
        Int64 score
    );

    /// <summary>
    ///  ランキングを取得<br />
    ///    <br />
    ///    ユーザID毎にスコアを1つしか登録できないカテゴリを指定する場合、ユニークIDは省略可能です<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="categoryName">カテゴリ名</param>
    /// <param name="scorerUserId">スコアを獲得したユーザID</param>
    /// <param name="uniqueId">スコアのユニークID</param>
    void getRank(
        std::function<void(AsyncEzGetRankResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder categoryName,
        StringHolder scorerUserId,
        gs2::optional<StringHolder> uniqueId=gs2::nullopt
    );
};

}}}

#endif //GS2_EZ_RANKING_GS2RANKINGWEBSOCKETCLIENT_HPP_