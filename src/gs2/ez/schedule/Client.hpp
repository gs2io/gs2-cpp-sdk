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

#ifndef GS2_EZ_SCHEDULE_GS2SCHEDULERESTCLIENT_HPP_
#define GS2_EZ_SCHEDULE_GS2SCHEDULERESTCLIENT_HPP_

#include <gs2/schedule/Gs2ScheduleRestClient.hpp>
#include "result/EzListTriggersResult.hpp"
#include "result/EzGetTriggerResult.hpp"
#include "result/EzListEventsResult.hpp"
#include "result/EzGetEventResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace schedule {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::schedule::Gs2ScheduleRestClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  引かれているトリガーの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void ListTriggers(
        std::function<void(AsyncEzListTriggersResult&)> callback,
        GameSession& session,
        const Char* namespaceName
    );

    /// <summary>
    ///  引かれているトリガーを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="triggerName">トリガーの名前</param>
    void GetTrigger(
        std::function<void(AsyncEzGetTriggerResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* triggerName
    );

    /// <summary>
    ///  開催中のイベント一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void ListEvents(
        std::function<void(AsyncEzListEventsResult&)> callback,
        GameSession& session,
        const Char* namespaceName
    );

    /// <summary>
    ///  開催中のイベントを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="eventName">イベントの種類名</param>
    void GetEvent(
        std::function<void(AsyncEzGetEventResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* eventName
    );
};

}}}

#endif //GS2_EZ_SCHEDULE_GS2SCHEDULERESTCLIENT_HPP_