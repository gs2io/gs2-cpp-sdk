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

#ifndef GS2_EZ_MISSION_GS2MISSIONRESTCLIENT_HPP_
#define GS2_EZ_MISSION_GS2MISSIONRESTCLIENT_HPP_

#include <gs2/mission/Gs2MissionWebSocketClient.hpp>
#include "result/EzListCompletesResult.hpp"
#include "result/EzGetCompleteResult.hpp"
#include "result/EzReceiveRewardsResult.hpp"
#include "result/EzListMissionTaskModelsResult.hpp"
#include "result/EzGetMissionTaskModelResult.hpp"
#include "result/EzListCounterModelsResult.hpp"
#include "result/EzGetCounterModelResult.hpp"
#include "result/EzListMissionGroupModelsResult.hpp"
#include "result/EzGetMissionGroupModelResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace mission {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::mission::Gs2MissionWebSocketClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  達成したミッションの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listCompletes(
        std::function<void(AsyncEzListCompletesResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  ミッショングループを指定して達成したミッションを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="missionGroupName">ミッショングループ名</param>
    void getComplete(
        std::function<void(AsyncEzGetCompleteResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder missionGroupName
    );

    /// <summary>
    ///  ミッションの達成報酬を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="missionGroupName">ミッショングループ名</param>
    /// <param name="missionTaskName">タスク名</param>
    void receiveRewards(
        std::function<void(AsyncEzReceiveRewardsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder missionGroupName,
        StringHolder missionTaskName
    );

    /// <summary>
    ///  ミッションタスクモデルの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="missionGroupName">グループ名</param>
    void listMissionTaskModels(
        std::function<void(AsyncEzListMissionTaskModelsResult)> callback,
        StringHolder namespaceName,
        StringHolder missionGroupName
    );

    /// <summary>
    ///  ミッションタスク名を指定してミッションタスクモデルを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="missionGroupName">グループ名</param>
    /// <param name="missionTaskName">タスク名</param>
    void getMissionTaskModel(
        std::function<void(AsyncEzGetMissionTaskModelResult)> callback,
        StringHolder namespaceName,
        StringHolder missionGroupName,
        StringHolder missionTaskName
    );

    /// <summary>
    ///  カウンターの種類を認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listCounterModels(
        std::function<void(AsyncEzListCounterModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  カウンターの種類を認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="counterName">カウンター名</param>
    void getCounterModel(
        std::function<void(AsyncEzGetCounterModelResult)> callback,
        StringHolder namespaceName,
        StringHolder counterName
    );

    /// <summary>
    ///  ミッショングループモデルの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listMissionGroupModels(
        std::function<void(AsyncEzListMissionGroupModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  ミッショングループ名を指定してミッショングループモデルを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="missionGroupName">グループ名</param>
    void getMissionGroupModel(
        std::function<void(AsyncEzGetMissionGroupModelResult)> callback,
        StringHolder namespaceName,
        StringHolder missionGroupName
    );
};

}}}

#endif //GS2_EZ_MISSION_GS2MISSIONRESTCLIENT_HPP_