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

#ifndef GS2_EZ_DATASTORE_GS2DATASTOREWEBSOCKETCLIENT_HPP_
#define GS2_EZ_DATASTORE_GS2DATASTOREWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListMyDataObjectsResult.hpp"
#include "result/EzUpdateDataObjectResult.hpp"
#include "result/EzPrepareUploadResult.hpp"
#include "result/EzPrepareReUploadResult.hpp"
#include "result/EzDoneUploadResult.hpp"
#include "result/EzPrepareDownloadResult.hpp"
#include "result/EzPrepareDownloadOwnDataResult.hpp"
#include "result/EzDeleteDataObjectResult.hpp"
#include "result/EzListDataObhectHistoriesResult.hpp"


namespace gs2 {

namespace datastore {

class Gs2DatastoreWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace datastore {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::datastore::Gs2DatastoreWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  データのアップロード準備<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="status">状態</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listMyDataObjects(
        std::function<void(AsyncEzListMyDataObjectsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> status=gs2::nullopt,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  データのアップロード準備<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="scope">ファイルのアクセス権</param>
    /// <param name="allowUserIds">公開するユーザIDリスト</param>
    void updateDataObject(
        std::function<void(AsyncEzUpdateDataObjectResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder scope,
        List<StringHolder> allowUserIds
    );

    /// <summary>
    ///  データのアップロード準備<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="name">データの名前</param>
    /// <param name="scope">ファイルのアクセス権</param>
    /// <param name="allowUserIds">公開するユーザIDリスト</param>
    /// <param name="updateIfExists">既にデータが存在する場合にエラーとするか、データを更新するか</param>
    void prepareUpload(
        std::function<void(AsyncEzPrepareUploadResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder scope,
        List<StringHolder> allowUserIds,
        gs2::optional<StringHolder> name=gs2::nullopt,
        gs2::optional<Bool> updateIfExists=gs2::nullopt
    );

    /// <summary>
    ///  データの再アップロード準備<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="dataObjectName">データの名前</param>
    void prepareReUpload(
        std::function<void(AsyncEzPrepareReUploadResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder dataObjectName
    );

    /// <summary>
    ///  データのアップロード準備<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="dataObjectName">データの名前</param>
    void doneUpload(
        std::function<void(AsyncEzDoneUploadResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder dataObjectName
    );

    /// <summary>
    ///  データをダウンロード<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="dataObjectId">データオブジェクト</param>
    void prepareDownload(
        std::function<void(AsyncEzPrepareDownloadResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder dataObjectId
    );

    /// <summary>
    ///  自分のデータをダウンロード<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="dataObjectName">データの名前</param>
    void prepareDownloadOwnData(
        std::function<void(AsyncEzPrepareDownloadOwnDataResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder dataObjectName
    );

    /// <summary>
    ///  アップロードしたデータを削除<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="dataObjectName">データの名前</param>
    void deleteDataObject(
        std::function<void(AsyncEzDeleteDataObjectResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder dataObjectName
    );

    /// <summary>
    ///  データオブジェクト履歴の一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="dataObjectName">データの名前</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listDataObhectHistories(
        std::function<void(AsyncEzListDataObhectHistoriesResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder dataObjectName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );
};

}}}

#endif //GS2_EZ_DATASTORE_GS2DATASTOREWEBSOCKETCLIENT_HPP_