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

#ifndef GS2_EZ_STAMINA_GS2STAMINAWEBSOCKETCLIENT_HPP_
#define GS2_EZ_STAMINA_GS2STAMINAWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListStaminaModelsResult.hpp"
#include "result/EzGetStaminaModelResult.hpp"
#include "result/EzGetStaminaResult.hpp"
#include "result/EzConsumeResult.hpp"


namespace gs2 {

namespace stamina {

class Gs2StaminaWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace stamina {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::stamina::Gs2StaminaWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  スタミナモデルを認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listStaminaModels(
        std::function<void(AsyncEzListStaminaModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  スタミナモデルを認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="staminaName">スタミナの種類名</param>
    void getStaminaModel(
        std::function<void(AsyncEzGetStaminaModelResult)> callback,
        StringHolder namespaceName,
        StringHolder staminaName
    );

    /// <summary>
    ///  現在のスタミナを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="staminaName">スタミナの種類名</param>
    void getStamina(
        std::function<void(AsyncEzGetStaminaResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder staminaName
    );

    /// <summary>
    ///  スタミナを消費<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="staminaName">スタミナの種類名</param>
    /// <param name="consumeValue">消費するスタミナ量</param>
    void consume(
        std::function<void(AsyncEzConsumeResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder staminaName,
        Int32 consumeValue
    );
};

}}}

#endif //GS2_EZ_STAMINA_GS2STAMINAWEBSOCKETCLIENT_HPP_