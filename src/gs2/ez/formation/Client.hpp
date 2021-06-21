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

#ifndef GS2_EZ_FORMATION_GS2FORMATIONWEBSOCKETCLIENT_HPP_
#define GS2_EZ_FORMATION_GS2FORMATIONWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListMoldModelsResult.hpp"
#include "result/EzGetMoldModelResult.hpp"
#include "result/EzListMoldsResult.hpp"
#include "result/EzGetMoldResult.hpp"
#include "result/EzListFormsResult.hpp"
#include "result/EzGetFormResult.hpp"
#include "result/EzGetFormWithSignatureResult.hpp"
#include "result/EzSetFormResult.hpp"


namespace gs2 {

namespace formation {

class Gs2FormationWebSocketClient;
class Gs2FormationRestClient;

}

namespace ez {

class Profile;
class GameSession;

namespace formation {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::formation::Gs2FormationWebSocketClient* m_pWebSocketClient;
    gs2::formation::Gs2FormationRestClient* m_pRestClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  フォームモデル情報の一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listMoldModels(
        std::function<void(AsyncEzListMoldModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  フォームモデル情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="moldName">フォームの保存領域名</param>
    void getMoldModel(
        std::function<void(AsyncEzGetMoldModelResult)> callback,
        StringHolder namespaceName,
        StringHolder moldName
    );

    /// <summary>
    ///  保存したフォーム情報の一覧を取得<br />
    ///    <br />
    ///    フォームの保存領域名 は省略可能で、指定しなかった場合はゲームプレイヤーに属する全ての保存したフォーム情報が取得できます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listMolds(
        std::function<void(AsyncEzListMoldsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  `フォームの保存領域` と `プロパティID` を指定して保存したフォーム情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="moldName">フォームの保存領域の名前</param>
    void getMold(
        std::function<void(AsyncEzGetMoldResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder moldName
    );

    /// <summary>
    ///  フォームの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="moldName">フォームの保存領域の名前</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listForms(
        std::function<void(AsyncEzListFormsResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> moldName=gs2::nullopt,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  フォームを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="moldName">フォームの保存領域の名前</param>
    /// <param name="index">保存領域のインデックス</param>
    void getForm(
        std::function<void(AsyncEzGetFormResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder moldName,
        Int32 index
    );

    /// <summary>
    ///  フォームを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="moldName">フォームの保存領域の名前</param>
    /// <param name="index">保存領域のインデックス</param>
    /// <param name="keyId">署名の発行に使用する暗号鍵 のGRN</param>
    void getFormWithSignature(
        std::function<void(AsyncEzGetFormWithSignatureResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder moldName,
        Int32 index,
        StringHolder keyId
    );

    /// <summary>
    ///  フォームを更新<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="moldName">フォームの保存領域の名前</param>
    /// <param name="index">保存領域のインデックス</param>
    /// <param name="slots">編成するスロットのリスト</param>
    /// <param name="keyId">署名の発行に使用した GS2-Key の暗号鍵GRN</param>
    void setForm(
        std::function<void(AsyncEzSetFormResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder moldName,
        Int32 index,
        List<EzSlotWithSignature> slots,
        StringHolder keyId
    );
};

}}}

#endif //GS2_EZ_FORMATION_GS2FORMATIONWEBSOCKETCLIENT_HPP_