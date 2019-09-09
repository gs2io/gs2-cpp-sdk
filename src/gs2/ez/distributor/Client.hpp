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

#ifndef GS2_EZ_DISTRIBUTOR_GS2DISTRIBUTORRESTCLIENT_HPP_
#define GS2_EZ_DISTRIBUTOR_GS2DISTRIBUTORRESTCLIENT_HPP_

#include <gs2/distributor/Gs2DistributorWebSocketClient.hpp>
#include "result/EzListDistributorModelsResult.hpp"
#include "result/EzGetDistributorModelResult.hpp"
#include "result/EzRunStampTaskResult.hpp"
#include "result/EzRunStampSheetResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace distributor {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::distributor::Gs2DistributorWebSocketClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  配信設定を認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listDistributorModels(
        std::function<void(AsyncEzListDistributorModelsResult&)> callback,
        const Char* namespaceName
    );

    /// <summary>
    ///  配信設定を認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="distributorName">配信設定名</param>
    void getDistributorModel(
        std::function<void(AsyncEzGetDistributorModelResult&)> callback,
        const Char* namespaceName,
        const Char* distributorName
    );

    /// <summary>
    ///  スタンプタスクを実行<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="distributorName">ディストリビューターの種類名</param>
    /// <param name="stampTask">実行するスタンプタスク</param>
    /// <param name="keyId">スタンプシートの暗号化に使用した暗号鍵GRN</param>
    /// <param name="contextStack">スタンプシートの実行状況を記録するスタックメモリ</param>
    void runStampTask(
        std::function<void(AsyncEzRunStampTaskResult&)> callback,
        const Char* namespaceName,
        const Char* distributorName,
        const Char* stampTask,
        const Char* keyId,
        const Char* contextStack=nullptr
    );

    /// <summary>
    ///  スタンプシートを実行<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="distributorName">ディストリビューターの種類名</param>
    /// <param name="stampSheet">実行するスタンプタスク</param>
    /// <param name="keyId">スタンプシートの暗号化に使用した暗号鍵GRN</param>
    /// <param name="contextStack">スタンプシートの実行状況を記録するスタックメモリ</param>
    void runStampSheet(
        std::function<void(AsyncEzRunStampSheetResult&)> callback,
        const Char* namespaceName,
        const Char* distributorName,
        const Char* stampSheet,
        const Char* keyId,
        const Char* contextStack=nullptr
    );
};

}}}

#endif //GS2_EZ_DISTRIBUTOR_GS2DISTRIBUTORRESTCLIENT_HPP_