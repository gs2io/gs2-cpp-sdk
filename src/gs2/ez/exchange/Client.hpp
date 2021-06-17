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

#ifndef GS2_EZ_EXCHANGE_GS2EXCHANGEWEBSOCKETCLIENT_HPP_
#define GS2_EZ_EXCHANGE_GS2EXCHANGEWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListRateModelsResult.hpp"
#include "result/EzGetRateModelResult.hpp"
#include "result/EzExchangeResult.hpp"
#include "result/EzListAwaitsResult.hpp"
#include "result/EzGetAwaitResult.hpp"
#include "result/EzAcquireResult.hpp"
#include "result/EzSkipResult.hpp"
#include "result/EzDeleteAwaitResult.hpp"


namespace gs2 {

namespace exchange {

class Gs2ExchangeWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace exchange {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::exchange::Gs2ExchangeWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  交換レートモデル情報の一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listRateModels(
        std::function<void(AsyncEzListRateModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  交換レートモデル情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">交換レート名</param>
    void getRateModel(
        std::function<void(AsyncEzGetRateModelResult)> callback,
        StringHolder namespaceName,
        StringHolder rateName
    );

    /// <summary>
    ///  交換を実行<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">交換レートの種類名</param>
    /// <param name="count">交換するロット数</param>
    /// <param name="config">設定値</param>
    void exchange(
        std::function<void(AsyncEzExchangeResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder rateName,
        Int32 count,
        gs2::optional<List<EzConfig>> config=gs2::nullopt
    );

    /// <summary>
    ///  交換待機情報の一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">交換レート名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    void listAwaits(
        std::function<void(AsyncEzListAwaitsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> rateName=gs2::nullopt,
        gs2::optional<StringHolder> pageToken=gs2::nullopt
    );

    /// <summary>
    ///  交換待機情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">交換レート名</param>
    /// <param name="awaitName">交換待機の名前</param>
    void getAwait(
        std::function<void(AsyncEzGetAwaitResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder rateName,
        StringHolder awaitName
    );

    /// <summary>
    ///  交換待機の報酬を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">交換レート名</param>
    /// <param name="awaitName">交換待機の名前</param>
    void acquire(
        std::function<void(AsyncEzAcquireResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder rateName,
        StringHolder awaitName
    );

    /// <summary>
    ///  交換待機を対価を払ってスキップ<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">交換レート名</param>
    /// <param name="awaitName">交換待機の名前</param>
    void skip(
        std::function<void(AsyncEzSkipResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder rateName,
        StringHolder awaitName
    );

    /// <summary>
    ///  交換待機情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">交換レート名</param>
    /// <param name="awaitName">交換待機の名前</param>
    void deleteAwait(
        std::function<void(AsyncEzDeleteAwaitResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder rateName,
        StringHolder awaitName
    );
};

}}}

#endif //GS2_EZ_EXCHANGE_GS2EXCHANGEWEBSOCKETCLIENT_HPP_