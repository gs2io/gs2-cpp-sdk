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

#ifndef GS2_EZ_REALTIME_GS2REALTIMEWEBSOCKETCLIENT_HPP_
#define GS2_EZ_REALTIME_GS2REALTIMEWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzGetRoomResult.hpp"


namespace gs2 {

namespace realtime {

class Gs2RealtimeWebSocketClient;
class Gs2RealtimeRestClient;

}

namespace ez {

class Profile;
class GameSession;

namespace realtime {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::realtime::Gs2RealtimeWebSocketClient* m_pWebSocketClient;
    gs2::realtime::Gs2RealtimeRestClient* m_pRestClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  ルームの情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="roomName">ルーム名</param>
    void getRoom(
        std::function<void(AsyncEzGetRoomResult)> callback,
        StringHolder namespaceName,
        StringHolder roomName
    );
};

}}}

#endif //GS2_EZ_REALTIME_GS2REALTIMEWEBSOCKETCLIENT_HPP_