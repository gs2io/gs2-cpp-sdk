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

#ifndef GS2_EZ_GATEWAY_GS2GATEWAYWEBSOCKETCLIENT_HPP_
#define GS2_EZ_GATEWAY_GS2GATEWAYWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzSetUserIdResult.hpp"


namespace gs2 {

namespace gateway {

class Gs2GatewayWebSocketClient;
class Gs2GatewayRestClient;

}

namespace ez {

class Profile;
class GameSession;

namespace gateway {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::gateway::Gs2GatewayWebSocketClient* m_pWebSocketClient;
    gs2::gateway::Gs2GatewayRestClient* m_pRestClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  サーバからプッシュ通知を受けるためのユーザーIDを設定<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="allowConcurrentAccess">同時に異なるクライアントからの接続を許容するか</param>
    void setUserId(
        std::function<void(AsyncEzSetUserIdResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        Bool allowConcurrentAccess
    );
};

}}}

#endif //GS2_EZ_GATEWAY_GS2GATEWAYWEBSOCKETCLIENT_HPP_