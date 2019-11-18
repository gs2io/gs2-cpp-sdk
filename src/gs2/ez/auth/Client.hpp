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

#ifndef GS2_EZ_AUTH_GS2AUTHRESTCLIENT_HPP_
#define GS2_EZ_AUTH_GS2AUTHRESTCLIENT_HPP_

#include <gs2/auth/Gs2AuthWebSocketClient.hpp>
#include "result/EzLoginResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace auth {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::auth::Gs2AuthWebSocketClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  指定したユーザIDでGS2にログイン<br />
    ///    <br />
    ///    body と signature には GS2-Account::Authentication の結果を指定します。<br />
    ///    body と signature の検証に成功すると、 `アクセストークン` を応答します。<br />
    ///    `アクセストークン` は有効期限が1時間の一時的な認証情報で、GS2内の各サービスでゲームプレイヤーを識別するために使用されます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="userId">ユーザーID</param>
    /// <param name="keyId">署名の作成に使用した暗号鍵 のGRN</param>
    /// <param name="body">アカウント認証情報の署名対象</param>
    /// <param name="signature">署名</param>
    void login(
        std::function<void(AsyncEzLoginResult)> callback,
        StringHolder userId,
        StringHolder keyId,
        StringHolder body,
        StringHolder signature
    );
};

}}}

#endif //GS2_EZ_AUTH_GS2AUTHRESTCLIENT_HPP_