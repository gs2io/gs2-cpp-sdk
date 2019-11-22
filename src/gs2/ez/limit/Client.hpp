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

#ifndef GS2_EZ_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_
#define GS2_EZ_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListCountersResult.hpp"
#include "result/EzGetCounterResult.hpp"
#include "result/EzListLimitModelsResult.hpp"
#include "result/EzGetLimitModelResult.hpp"


namespace gs2 {

namespace limit {

class Gs2LimitWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace limit {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::limit::Gs2LimitWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  ゲームプレイヤーに紐づく回数制限カウンターの一覧を取得<br />
    ///    <br />
    ///    回数制限名は省略可能です。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="limitName">回数制限の種類の名前</param>
    void listCounters(
        std::function<void(AsyncEzListCountersResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> limitName=gs2::nullopt
    );

    /// <summary>
    ///  回数制限名とカウンター名を指定してゲームプレイヤーに紐づく回数制限カウンターを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="limitName">回数制限の種類の名前</param>
    /// <param name="counterName">カウンターの名前</param>
    void getCounter(
        std::function<void(AsyncEzGetCounterResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder limitName,
        StringHolder counterName
    );

    /// <summary>
    ///  回数制限モデルの一覧を取得<br />
    ///    <br />
    ///    近日実施する予定のイベントに関する回数制限設定をしたことで、イベントの情報などが露呈する可能性があります。<br />
    ///    回数制限モデルの持つ情報をゲーム内から使用しない場合は 本APIへのアクセス権を剥奪しておく方が安全です。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listLimitModels(
        std::function<void(AsyncEzListLimitModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  回数制限名を指定して回数制限モデルを取得<br />
    ///    <br />
    ///    近日実施する予定のイベントに関する回数制限設定をしたことで、イベントの情報などが露呈する可能性があります。<br />
    ///    回数制限モデルの持つ情報をゲーム内から使用しない場合は 本APIへのアクセス権を剥奪しておく方が安全です。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="limitName">回数制限の種類名</param>
    void getLimitModel(
        std::function<void(AsyncEzGetLimitModelResult)> callback,
        StringHolder namespaceName,
        StringHolder limitName
    );
};

}}}

#endif //GS2_EZ_LIMIT_GS2LIMITWEBSOCKETCLIENT_HPP_