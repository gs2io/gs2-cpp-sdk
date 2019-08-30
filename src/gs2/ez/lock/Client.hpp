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

#ifndef GS2_EZ_LOCK_GS2LOCKRESTCLIENT_HPP_
#define GS2_EZ_LOCK_GS2LOCKRESTCLIENT_HPP_

#include <gs2/lock/Gs2LockRestClient.hpp>
#include "result/EzLockResult.hpp"
#include "result/EzUnlockResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace lock {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::lock::Gs2LockRestClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  ロックを取得<br />
    ///    <br />
    ///    ttl で指定した秒数 `プロパティID` のリソースをロックします。<br />
    ///    ロックする際には `トランザクションID` を指定する必要があります。<br />
    ///    異なる `トランザクションID` による同一 `プロパティID` に対するロック取得は失敗します。<br />
    ///    同一トランザクションからのロック取得リクエストの場合は参照カウントを増やします。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="propertyId">プロパティID</param>
    /// <param name="transactionId">ロックを取得するトランザクションID</param>
    /// <param name="ttl">ロックを取得する期限（秒）</param>
    void lock(
        std::function<void(AsyncEzLockResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* propertyId,
        const Char* transactionId,
        Int64 ttl
    );

    /// <summary>
    ///  ロックを解放<br />
    ///    <br />
    ///    ロックの解放には同一 `トランザクションID` から解放する必要があります。<br />
    ///    ロックの取得時に再入を行った場合は同一回数ロックの解放を行い、参照カウントが0になったタイミングで実際に解放が行われます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="propertyId">プロパティID</param>
    /// <param name="transactionId">ロックを取得したトランザクションID</param>
    void unlock(
        std::function<void(AsyncEzUnlockResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* propertyId,
        const Char* transactionId
    );
};

}}}

#endif //GS2_EZ_LOCK_GS2LOCKRESTCLIENT_HPP_