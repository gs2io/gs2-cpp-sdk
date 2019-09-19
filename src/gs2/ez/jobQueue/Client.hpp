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

#ifndef GS2_EZ_JOBQUEUE_GS2JOBQUEUERESTCLIENT_HPP_
#define GS2_EZ_JOBQUEUE_GS2JOBQUEUERESTCLIENT_HPP_

#include <gs2/jobQueue/Gs2JobQueueWebSocketClient.hpp>
#include "result/EzRunResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace jobQueue {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::jobQueue::Gs2JobQueueWebSocketClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  タスクキューのジョブを実行します。<br />
    ///    <br />
    ///    タスクキューのプッシュ通知設定をすることでタスクキューに新しくジョブが追加されたときにプッシュ通知を受けることができます。<br />
    ///    定期的にこのAPIを呼び出すか、プッシュ通知をトリガーしてこのAPIを呼び出してください。<br />
    ///    `isLastJob` が false を返している間は繰り返し実行してください。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void run(
        std::function<void(AsyncEzRunResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );
};

}}}

#endif //GS2_EZ_JOBQUEUE_GS2JOBQUEUERESTCLIENT_HPP_