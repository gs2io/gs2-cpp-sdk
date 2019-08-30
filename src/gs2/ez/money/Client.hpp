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

#ifndef GS2_EZ_MONEY_GS2MONEYRESTCLIENT_HPP_
#define GS2_EZ_MONEY_GS2MONEYRESTCLIENT_HPP_

#include <gs2/money/Gs2MoneyRestClient.hpp>
#include "result/EzGetResult.hpp"
#include "result/EzWithdrawResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace money {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::money::Gs2MoneyRestClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  ウォレットを取得します<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペースの名前</param>
    /// <param name="slot">スロット番号</param>
    void get(
        std::function<void(AsyncEzGetResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        Int32 slot
    );

    /// <summary>
    ///  ウォレットから残高を消費します<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペースの名前</param>
    /// <param name="slot">スロット番号</param>
    /// <param name="count">消費する課金通貨の数量</param>
    /// <param name="paidOnly">有償課金通貨のみを対象とするか</param>
    void withdraw(
        std::function<void(AsyncEzWithdrawResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        Int32 slot,
        Int32 count,
        Bool paidOnly
    );
};

}}}

#endif //GS2_EZ_MONEY_GS2MONEYRESTCLIENT_HPP_