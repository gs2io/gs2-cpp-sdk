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

#ifndef GS2_EZ_DISTRIBUTOR_GS2DISTRIBUTORWEBSOCKETCLIENT_HPP_
#define GS2_EZ_DISTRIBUTOR_GS2DISTRIBUTORWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListDistributorModelsResult.hpp"
#include "result/EzGetDistributorModelResult.hpp"
#include "result/EzRunStampTaskResult.hpp"
#include "result/EzRunStampSheetResult.hpp"
#include "result/EzRunStampSheetExpressResult.hpp"
#include "result/EzRunStampTaskWithoutNamespaceResult.hpp"
#include "result/EzRunStampSheetWithoutNamespaceResult.hpp"
#include "result/EzRunStampSheetExpressWithoutNamespaceResult.hpp"


namespace gs2 {

namespace distributor {

class Gs2DistributorWebSocketClient;
class Gs2DistributorRestClient;

}

namespace ez {

class Profile;
class GameSession;

namespace distributor {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::distributor::Gs2DistributorWebSocketClient* m_pWebSocketClient;
    gs2::distributor::Gs2DistributorRestClient* m_pRestClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  配信設定を認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listDistributorModels(
        std::function<void(AsyncEzListDistributorModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  配信設定を認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="distributorName">配信設定名</param>
    void getDistributorModel(
        std::function<void(AsyncEzGetDistributorModelResult)> callback,
        StringHolder namespaceName,
        StringHolder distributorName
    );

    /// <summary>
    ///  スタンプタスクを実行<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="stampTask">実行するスタンプタスク</param>
    /// <param name="keyId">スタンプシートの暗号化に使用した暗号鍵GRN</param>
    /// <param name="contextStack">スタンプシートの実行状況を記録するスタックメモリ</param>
    void runStampTask(
        std::function<void(AsyncEzRunStampTaskResult)> callback,
        StringHolder namespaceName,
        StringHolder stampTask,
        StringHolder keyId,
        gs2::optional<StringHolder> contextStack=gs2::nullopt
    );

    /// <summary>
    ///  スタンプシートを実行<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="stampSheet">実行するスタンプタスク</param>
    /// <param name="keyId">スタンプシートの暗号化に使用した暗号鍵GRN</param>
    /// <param name="contextStack">スタンプシートの実行状況を記録するスタックメモリ</param>
    void runStampSheet(
        std::function<void(AsyncEzRunStampSheetResult)> callback,
        StringHolder namespaceName,
        StringHolder stampSheet,
        StringHolder keyId,
        gs2::optional<StringHolder> contextStack=gs2::nullopt
    );

    /// <summary>
    ///  スタンプタスク・スタンプシートを一括実行<br />
    ///    <br />
    ///    一括実行をすることで、レスポンスタイムを短縮できます。<br />
    ///    ただし、スタンプシートの実行の過程で失敗した際には正しくリトライできる保証はありません。<br />
    ///    実行に失敗した時に備えて GS2-Log　でスタンプシートの実行ログを残しておき、カスタマーサポートの際に適切な対応ができるようにしておくことを強く推奨します。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="stampSheet">実行するスタンプタスク</param>
    /// <param name="keyId">スタンプシートの暗号化に使用した暗号鍵GRN</param>
    void runStampSheetExpress(
        std::function<void(AsyncEzRunStampSheetExpressResult)> callback,
        StringHolder namespaceName,
        StringHolder stampSheet,
        StringHolder keyId
    );

    /// <summary>
    ///  スタンプタスクを実行<br />
    ///    <br />
    ///    ネームスペースの指定を省略することで、<br />
    ///    ログが記録できない・リソース溢れ処理が実行されないなどの副作用があります。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="stampTask">実行するスタンプタスク</param>
    /// <param name="keyId">スタンプシートの暗号化に使用した暗号鍵GRN</param>
    /// <param name="contextStack">スタンプシートの実行状況を記録するスタックメモリ</param>
    void runStampTaskWithoutNamespace(
        std::function<void(AsyncEzRunStampTaskWithoutNamespaceResult)> callback,
        StringHolder stampTask,
        StringHolder keyId,
        gs2::optional<StringHolder> contextStack=gs2::nullopt
    );

    /// <summary>
    ///  スタンプシートを実行<br />
    ///    <br />
    ///    ネームスペースの指定を省略することで、<br />
    ///    ログが記録できない・リソース溢れ処理が実行されないなどの副作用があります。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="stampSheet">実行するスタンプタスク</param>
    /// <param name="keyId">スタンプシートの暗号化に使用した暗号鍵GRN</param>
    /// <param name="contextStack">スタンプシートの実行状況を記録するスタックメモリ</param>
    void runStampSheetWithoutNamespace(
        std::function<void(AsyncEzRunStampSheetWithoutNamespaceResult)> callback,
        StringHolder stampSheet,
        StringHolder keyId,
        gs2::optional<StringHolder> contextStack=gs2::nullopt
    );

    /// <summary>
    ///  スタンプタスク・スタンプシートを一括実行<br />
    ///    <br />
    ///     一括実行をすることで、レスポンスタイムを短縮できます。<br />
    ///     ただし、スタンプシートの実行の過程で失敗した際には正しくリトライできる保証はありません。<br />
    ///     実行に失敗した時に備えて GS2-Log　でスタンプシートの実行ログを残しておき、カスタマーサポートの際に適切な対応ができるようにしておくことを強く推奨します。<br />
    ///    <br />
    ///    ネームスペースの指定を省略することで、<br />
    ///    ログが記録できない・リソース溢れ処理が実行されないなどの副作用があります。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="stampSheet">実行するスタンプタスク</param>
    /// <param name="keyId">スタンプシートの暗号化に使用した暗号鍵GRN</param>
    void runStampSheetExpressWithoutNamespace(
        std::function<void(AsyncEzRunStampSheetExpressWithoutNamespaceResult)> callback,
        StringHolder stampSheet,
        StringHolder keyId
    );
};

}}}

#endif //GS2_EZ_DISTRIBUTOR_GS2DISTRIBUTORWEBSOCKETCLIENT_HPP_