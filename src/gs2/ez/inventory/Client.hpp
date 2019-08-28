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

#ifndef GS2_EZ_INVENTORY_GS2INVENTORYRESTCLIENT_HPP_
#define GS2_EZ_INVENTORY_GS2INVENTORYRESTCLIENT_HPP_

#include <gs2/inventory/Gs2InventoryRestClient.hpp>
#include "result/EzListInventoryModelsResult.hpp"
#include "result/EzGetInventoryModelResult.hpp"
#include "result/EzListItemModelsResult.hpp"
#include "result/EzGetItemModelResult.hpp"
#include "result/EzListInventoriesResult.hpp"
#include "result/EzGetInventoryResult.hpp"
#include "result/EzListItemsResult.hpp"
#include "result/EzGetItemResult.hpp"
#include "result/EzConsumeResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace inventory {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::inventory::Gs2InventoryRestClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  インベントリモデルの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリー名</param>
    void ListInventoryModels(
        std::function<void(gs2::AsyncResult<EzListInventoryModelsResult>&)> callback,
        const Char* namespaceName
    );

    /// <summary>
    ///  インベントリ名を指定してインベントリモデルを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    void GetInventoryModel(
        std::function<void(gs2::AsyncResult<EzGetInventoryModelResult>&)> callback,
        const Char* namespaceName,
        const Char* inventoryName
    );

    /// <summary>
    ///  インベントリ名を指定してアイテムモデルの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    void ListItemModels(
        std::function<void(gs2::AsyncResult<EzListItemModelsResult>&)> callback,
        const Char* namespaceName,
        const Char* inventoryName
    );

    /// <summary>
    ///  インベントリ名とアイテム名を指定してアイテムモデルを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    /// <param name="itemName">アイテムモデルの種類名</param>
    void GetItemModel(
        std::function<void(gs2::AsyncResult<EzGetItemModelResult>&)> callback,
        const Char* namespaceName,
        const Char* inventoryName,
        const Char* itemName
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
    void ListInventories(
        std::function<void(gs2::AsyncResult<EzListInventoriesResult>&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* pageToken=nullptr,
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
    void GetInventory(
        std::function<void(gs2::AsyncResult<EzGetInventoryResult>&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* inventoryName
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
    void ListItems(
        std::function<void(gs2::AsyncResult<EzListItemsResult>&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* inventoryName,
        const Char* pageToken=nullptr,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  インベントリ名とアイテム名を指定してアイテムを取得<br />
    ///    <br />
    ///    `このAPIはあなたの意図に反して複数のアイテムを返すかもしれません。`<br />
    ///    <br />
    ///    複数のアイテムが応答された場合はそれは同一アイテムでありながら、有効期限が異なるアイテムです。<br />
    ///    逆に言えば、有効期限さえ設定しなければこのAPIは常に1つのアイテムを応答します。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">カテゴリー名</param>
    /// <param name="inventoryName">インベントリの種類名</param>
    /// <param name="itemName">アイテムモデルの種類名</param>
    void GetItem(
        std::function<void(gs2::AsyncResult<EzGetItemResult>&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* inventoryName,
        const Char* itemName
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
    void Consume(
        std::function<void(gs2::AsyncResult<EzConsumeResult>&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* inventoryName,
        const Char* itemName,
        Int64 consumeCount
    );
};

}}}

#endif //GS2_EZ_INVENTORY_GS2INVENTORYRESTCLIENT_HPP_