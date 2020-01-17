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

#ifndef GS2_EZ_INVENTORY_GS2INVENTORYWEBSOCKETCLIENT_HPP_
#define GS2_EZ_INVENTORY_GS2INVENTORYWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListInventoryModelsResult.hpp"
#include "result/EzGetInventoryModelResult.hpp"
#include "result/EzListItemModelsResult.hpp"
#include "result/EzGetItemModelResult.hpp"
#include "result/EzListInventoriesResult.hpp"
#include "result/EzGetInventoryResult.hpp"
#include "result/EzListItemsResult.hpp"
#include "result/EzGetItemResult.hpp"
#include "result/EzGetItemWithSignatureResult.hpp"
#include "result/EzConsumeResult.hpp"


namespace gs2 {

namespace inventory {

class Gs2InventoryWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace inventory {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::inventory::Gs2InventoryWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  インベントリモデルの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリー名</param>
    void listInventoryModels(
        std::function<void(AsyncEzListInventoryModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  インベントリ名を指定してインベントリモデルを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    void getInventoryModel(
        std::function<void(AsyncEzGetInventoryModelResult)> callback,
        StringHolder namespaceName,
        StringHolder inventoryName
    );

    /// <summary>
    ///  インベントリ名を指定してアイテムモデルの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    void listItemModels(
        std::function<void(AsyncEzListItemModelsResult)> callback,
        StringHolder namespaceName,
        StringHolder inventoryName
    );

    /// <summary>
    ///  インベントリ名とアイテム名を指定してアイテムモデルを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    /// <param name="itemName">アイテムモデルの種類名</param>
    void getItemModel(
        std::function<void(AsyncEzGetItemModelResult)> callback,
        StringHolder namespaceName,
        StringHolder inventoryName,
        StringHolder itemName
    );

    /// <summary>
    ///  インベントリの一覧を取得<br />
    ///    <br />
    ///    ゲームプレイヤーに紐付いたインベントリの一覧を取得します。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listInventories(
        std::function<void(AsyncEzListInventoriesResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  インベントリ名を指定してインベントリの情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    void getInventory(
        std::function<void(AsyncEzGetInventoryResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder inventoryName
    );

    /// <summary>
    ///  指定したインベントリ内の所有しているアイテム一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listItems(
        std::function<void(AsyncEzListItemsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder inventoryName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  インベントリ名とアイテム名を指定してアイテムを取得<br />
    ///    <br />
    ///    アイテムは複数のスタックに分割されて応答されることがあります。<br />
    ///    また、有効期限の異なるアイテムは、必ず別のスタックになります。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    /// <param name="itemName">アイテムモデルの種類名</param>
    void getItem(
        std::function<void(AsyncEzGetItemResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder inventoryName,
        StringHolder itemName
    );

    /// <summary>
    ///  インベントリ名とアイテム名を指定して署名付きアイテムを取得<br />
    ///    <br />
    ///    このAPIによって、APIを呼び出した瞬間に該当アイテムを所有していることを証明することができる<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    /// <param name="itemName">アイテムモデルの種類名</param>
    /// <param name="keyId">署名の発行に使用する暗号鍵 のGRN</param>
    void getItemWithSignature(
        std::function<void(AsyncEzGetItemWithSignatureResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder inventoryName,
        StringHolder itemName,
        StringHolder keyId
    );

    /// <summary>
    ///  アイテムを消費<br />
    ///    <br />
    ///    ゲーム内からアイテムを消費したい場合に使用します。<br />
    ///    <br />
    ///    GS2のシステムと連携してアイテムの増減を行う場合はこのAPIを使用することはありません。<br />
    ///    なぜなら、商品を購入するためや、クエストに参加するために必要な対価の場合は GS2-Showcase や GS2-Quest 上で対価を設定し、<br />
    ///    商品の購入時やクエスト参加時に自動的に対価としてアイテムやその他のリソースが消費されるためです。<br />
    ///    <br />
    ///    そのため、このAPIはGS2を介さない要素のためにアイテムを消費する場合に使用してください。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの名前</param>
    /// <param name="itemName">アイテムマスターの名前</param>
    /// <param name="consumeCount">消費する量</param>
    void consume(
        std::function<void(AsyncEzConsumeResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder inventoryName,
        StringHolder itemName,
        Int64 consumeCount
    );
};

}}}

#endif //GS2_EZ_INVENTORY_GS2INVENTORYWEBSOCKETCLIENT_HPP_