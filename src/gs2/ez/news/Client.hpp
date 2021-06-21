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

#ifndef GS2_EZ_NEWS_GS2NEWSWEBSOCKETCLIENT_HPP_
#define GS2_EZ_NEWS_GS2NEWSWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListNewsesResult.hpp"
#include "result/EzGetContentsUrlResult.hpp"


namespace gs2 {

namespace news {

class Gs2NewsWebSocketClient;
class Gs2NewsRestClient;

}

namespace ez {

class Profile;
class GameSession;

namespace news {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::news::Gs2NewsWebSocketClient* m_pWebSocketClient;
    gs2::news::Gs2NewsRestClient* m_pRestClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  達成したミッションの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペースの名前</param>
    void listNewses(
        std::function<void(AsyncEzListNewsesResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );

    /// <summary>
    ///  達成したミッションの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペースの名前</param>
    void getContentsUrl(
        std::function<void(AsyncEzGetContentsUrlResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );
};

}}}

#endif //GS2_EZ_NEWS_GS2NEWSWEBSOCKETCLIENT_HPP_