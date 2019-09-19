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

#ifndef GS2_EZ_SHOWCASE_GS2SHOWCASERESTCLIENT_HPP_
#define GS2_EZ_SHOWCASE_GS2SHOWCASERESTCLIENT_HPP_

#include <gs2/showcase/Gs2ShowcaseWebSocketClient.hpp>
#include "result/EzListResult.hpp"
#include "result/EzBuyResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace showcase {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::showcase::Gs2ShowcaseWebSocketClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  商品棚を取得します<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void list(
        std::function<void(AsyncEzListResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );

    /// <summary>
    ///  商品を購入します<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="displayItemId">陳列商品ID</param>
    void buy(
        std::function<void(AsyncEzBuyResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> displayItemId=gs2::nullopt
    );
};

}}}

#endif //GS2_EZ_SHOWCASE_GS2SHOWCASERESTCLIENT_HPP_