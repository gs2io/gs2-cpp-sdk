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

#ifndef GS2_EZ_ENHANCE_GS2ENHANCEWEBSOCKETCLIENT_HPP_
#define GS2_EZ_ENHANCE_GS2ENHANCEWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListRateModelsResult.hpp"
#include "result/EzGetRateModelResult.hpp"
#include "result/EzEnhanceResult.hpp"
#include "result/EzStartResult.hpp"
#include "result/EzEndResult.hpp"
#include "result/EzGetProgressResult.hpp"
#include "result/EzDeleteProgressResult.hpp"


namespace gs2 {

namespace enhance {

class Gs2EnhanceWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace enhance {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::enhance::Gs2EnhanceWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  強化レートモデル情報の一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listRateModels(
        std::function<void(AsyncEzListRateModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  強化レートモデル情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">強化レート名</param>
    void getRateModel(
        std::function<void(AsyncEzGetRateModelResult)> callback,
        StringHolder namespaceName,
        StringHolder rateName
    );

    /// <summary>
    ///  強化を実行<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">強化レート名</param>
    /// <param name="targetItemSetId">強化対象の GS2-Inventory アイテムセットGRN</param>
    /// <param name="materials">強化素材リスト</param>
    /// <param name="config">設定値</param>
    void enhance(
        std::function<void(AsyncEzEnhanceResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder rateName,
        StringHolder targetItemSetId,
        List<EzMaterial> materials,
        gs2::optional<List<EzConfig>> config=gs2::nullopt
    );

    /// <summary>
    ///  強化の開始を宣言<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="rateName">強化レート名</param>
    /// <param name="targetItemSetId">強化対象の GS2-Inventory アイテムセットGRN</param>
    /// <param name="materials">強化素材リスト</param>
    /// <param name="force">すでに開始している強化がある場合にそれを破棄して開始するか</param>
    /// <param name="config">スタンプシートの変数に適用する設定値</param>
    void start(
        std::function<void(AsyncEzStartResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder rateName,
        StringHolder targetItemSetId,
        List<EzMaterial> materials,
        gs2::optional<Bool> force=gs2::nullopt,
        gs2::optional<List<EzConfig>> config=gs2::nullopt
    );

    /// <summary>
    ///  強化の完了を報告<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="config">スタンプシートの変数に適用する設定値</param>
    void end(
        std::function<void(AsyncEzEndResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<List<EzConfig>> config=gs2::nullopt
    );

    /// <summary>
    ///  強化の進行情報を取得。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void getProgress(
        std::function<void(AsyncEzGetProgressResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );

    /// <summary>
    ///  強化の進行情報を削除。<br />
    ///    <br />
    ///    強化の開始時に `force` オプションを使うのではなく、明示的に進行情報を削除したい場合に使用してください。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    void deleteProgress(
        std::function<void(AsyncEzDeleteProgressResult)> callback,
        GameSession& session,
        StringHolder namespaceName
    );
};

}}}

#endif //GS2_EZ_ENHANCE_GS2ENHANCEWEBSOCKETCLIENT_HPP_