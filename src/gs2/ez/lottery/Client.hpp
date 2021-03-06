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

#ifndef GS2_EZ_LOTTERY_GS2LOTTERYWEBSOCKETCLIENT_HPP_
#define GS2_EZ_LOTTERY_GS2LOTTERYWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzDescribeBoxesResult.hpp"
#include "result/EzGetBoxResult.hpp"
#include "result/EzResetBoxResult.hpp"
#include "result/EzListProbabilitiesResult.hpp"


namespace gs2 {

namespace lottery {

class Gs2LotteryWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace lottery {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::lottery::Gs2LotteryWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  ボックスの排出済みアイテム情報一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void describeBoxes(
        std::function<void(AsyncEzDescribeBoxesResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  ボックスの排出済みアイテム情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="prizeTableName">排出確率テーブル名</param>
    void getBox(
        std::function<void(AsyncEzGetBoxResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder prizeTableName
    );

    /// <summary>
    ///  ボックスのリセット<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="prizeTableName">排出確率テーブル名</param>
    void resetBox(
        std::function<void(AsyncEzResetBoxResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder prizeTableName
    );

    /// <summary>
    ///  排出確率を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="lotteryName">抽選モデルの種類名</param>
    void listProbabilities(
        std::function<void(AsyncEzListProbabilitiesResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder lotteryName
    );
};

}}}

#endif //GS2_EZ_LOTTERY_GS2LOTTERYWEBSOCKETCLIENT_HPP_