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

#ifndef GS2_EZ_EXCHANGE_GS2EXCHANGERESTCLIENT_HPP_
#define GS2_EZ_EXCHANGE_GS2EXCHANGERESTCLIENT_HPP_

#include <gs2/exchange/Gs2ExchangeWebSocketClient.hpp>
#include "result/EzListRateModelsResult.hpp"
#include "result/EzGetRateModelResult.hpp"
#include "result/EzExchangeResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace exchange {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::exchange::Gs2ExchangeWebSocketClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

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
};

}}}

#endif //GS2_EZ_EXCHANGE_GS2EXCHANGERESTCLIENT_HPP_