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

#ifndef GS2_EZ_QUEST_GS2QUESTWEBSOCKETCLIENT_HPP_
#define GS2_EZ_QUEST_GS2QUESTWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzStartResult.hpp"
#include "result/EzEndResult.hpp"
#include "result/EzGetProgressResult.hpp"
#include "result/EzDeleteProgressResult.hpp"
#include "result/EzDescribeCompletedQuestListsResult.hpp"
#include "result/EzGetCompletedQuestListResult.hpp"
#include "result/EzListQuestGroupsResult.hpp"
#include "result/EzGetQuestGroupResult.hpp"
#include "result/EzListQuestsResult.hpp"
#include "result/EzGetQuestResult.hpp"


namespace gs2 {

namespace quest {

class Gs2QuestWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace quest {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::quest::Gs2QuestWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  クエストの開始を宣言<br />
    ///    <br />
    ///    すでに同一ゲームプレイヤーで開始済みのクエストがある場合は失敗します。<br />
    ///    それでも強制的に開始したい場合は `force` オプションに true を指定してください。<br />
    ///    <br />
    ///    クエストの開始が完了すると、そのクエストで得られる最大報酬に関する情報が応答されます。<br />
    ///    その内容をクエスト内の演出で排出してください。<br />
    ///    その際に、応答に含まれる乱数シードを使用してゲームプレイに再現性があるように設計しておくと、アプリで乱数起因の不具合が発生したときに調査しやすくなります。<br />
    ///    <br />
    ///    進行中のクエストを一意に特定するためのIDとして `クエストトランザクションID` が応答されます。<br />
    ///    クエストの完了を報告する際には `クエストトランザクションID` を指定することで、どのクエストに対する完了報告かを識別します。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリ名</param>
    /// <param name="questGroupName">クエストグループ名</param>
    /// <param name="questName">クエストモデル名</param>
    /// <param name="force">すでに開始しているクエストがある場合にそれを破棄して開始するか</param>
    /// <param name="config">スタンプシートの変数に適用する設定値</param>
    void start(
        std::function<void(AsyncEzStartResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder questGroupName,
        StringHolder questName,
        gs2::optional<Bool> force=gs2::nullopt,
        gs2::optional<List<EzConfig>> config=gs2::nullopt
    );

    /// <summary>
    ///  クエストの完了を報告<br />
    ///    <br />
    ///    クエストが完了したことを報告します。その際に `isComplete` にクエストに成功したか、失敗したかを渡します。<br />
    ///    クエストに成功した場合は `rewards` にクエスト内で入手した報酬を報告する必要があります。<br />
    ///    <br />
    ///    `rewards` で報告された内容は評価され、開始時に渡した数量以上や入手できないリソースを入手したと報告してきた場合はエラーとなります。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリ名</param>
    /// <param name="rewards">実際にクエストで得た報酬</param>
    /// <param name="transactionId">トランザクションID</param>
    /// <param name="isComplete">クエストをクリアしたか</param>
    /// <param name="config">スタンプシートの変数に適用する設定値</param>
    void end(
        std::function<void(AsyncEzEndResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder transactionId,
        gs2::optional<List<EzReward>> rewards=gs2::nullopt,
        gs2::optional<Bool> isComplete=gs2::nullopt,
        gs2::optional<List<EzConfig>> config=gs2::nullopt
    );

    /// <summary>
    ///  クエストの進行情報を取得。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリ名</param>
    void getProgress(
        std::function<void(AsyncEzGetProgressResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );

    /// <summary>
    ///  クエストの進行情報を削除。<br />
    ///    <br />
    ///    クエストの開始時に `force` オプションを使うのではなく、明示的に進行情報を削除したい場合に使用してください。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリ名</param>
    void deleteProgress(
        std::function<void(AsyncEzDeleteProgressResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );

    /// <summary>
    ///  クエスト進行情報の一覧を取得<br />
    ///    <br />
    ///    クエストグループごとに1つの `クエスト進行情報` として登録されており、<br />
    ///    `クエスト進行情報` にはクエストグループ内でクリア済みのクエスト名の一覧が記録されています。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリ名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void describeCompletedQuestLists(
        std::function<void(AsyncEzDescribeCompletedQuestListsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  クエスト進行情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリ名</param>
    /// <param name="questGroupName">クエストグループモデル名</param>
    void getCompletedQuestList(
        std::function<void(AsyncEzGetCompletedQuestListResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder questGroupName
    );

    /// <summary>
    ///  クエストグループの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリ名</param>
    void listQuestGroups(
        std::function<void(AsyncEzListQuestGroupsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  クエストグループの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリ名</param>
    /// <param name="questGroupName">クエストグループモデル名</param>
    void getQuestGroup(
        std::function<void(AsyncEzGetQuestGroupResult)> callback,
        StringHolder namespaceName,
        StringHolder questGroupName
    );

    /// <summary>
    ///  クエストモデルの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリ名</param>
    /// <param name="questGroupName">クエストグループモデル名</param>
    void listQuests(
        std::function<void(AsyncEzListQuestsResult)> callback,
        StringHolder namespaceName,
        StringHolder questGroupName
    );

    /// <summary>
    ///  クエストモデルの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリ名</param>
    /// <param name="questGroupName">クエストグループモデル名</param>
    /// <param name="questName">クエスト名</param>
    void getQuest(
        std::function<void(AsyncEzGetQuestResult)> callback,
        StringHolder namespaceName,
        StringHolder questGroupName,
        StringHolder questName
    );
};

}}}

#endif //GS2_EZ_QUEST_GS2QUESTWEBSOCKETCLIENT_HPP_