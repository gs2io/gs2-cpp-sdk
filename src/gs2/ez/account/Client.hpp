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

#ifndef GS2_EZ_ACCOUNT_GS2ACCOUNTRESTCLIENT_HPP_
#define GS2_EZ_ACCOUNT_GS2ACCOUNTRESTCLIENT_HPP_

#include <gs2/account/Gs2AccountRestClient.hpp>
#include "result/EzCreateResult.hpp"
#include "result/EzAuthenticationResult.hpp"
#include "result/EzAddTakeOverSettingResult.hpp"
#include "result/EzListTakeOverSettingsResult.hpp"
#include "result/EzUpdateTakeOverSettingResult.hpp"
#include "result/EzDeleteTakeOverSettingResult.hpp"
#include "result/EzDoTakeOverResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace account {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::account::Gs2AccountRestClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  ゲームプレイヤーを識別するアカウントを新規作成<br />
    ///    <br />
    ///    このAPIの実行に成功すると、作成したアカウントの情報が返ります。<br />
    ///    返ったアカウント情報のうち、認証処理に使用するユーザIDとパスワードを永続化してください。<br />
    ///    <br />
    ///    ここで発行されるパスワードはランダム値であり、ゲームプレイヤーの任意の値を指定することはできません。<br />
    ///    `引き継ぎ設定` としてゲームプレイヤーにとってわかりやすい識別子を登録することができます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void Create(
        std::function<void(AsyncEzCreateResult&)> callback,
        const Char* namespaceName
    );

    /// <summary>
    ///  アカウントの認証<br />
    ///    <br />
    ///    create 関数で発行したユーザID・パスワードを使用してゲームプレイヤーの認証を行います。<br />
    ///    認証が完了すると `アカウント認証情報` と `署名` が発行されます。<br />
    ///    `アカウント認証情報` と `署名` を GS2-Auth の loginBySignature にわたすことで、GS2の各サービスにアクセスするための `アクセストークン` を得ることができます。<br />
    ///    <br />
    ///    `アカウント認証情報` と `署名` は1時間の有効期限が存在します。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="userId">アカウントID</param>
    /// <param name="keyId">認証トークンの暗号化に使用する暗号鍵 のGRN</param>
    /// <param name="password">パスワード</param>
    void Authentication(
        std::function<void(AsyncEzAuthenticationResult&)> callback,
        const Char* namespaceName,
        const Char* userId,
        const Char* keyId,
        const Char* password
    );

    /// <summary>
    ///  `引き継ぎ設定` を追加<br />
    ///    <br />
    ///    `引き継ぎ設定` は機種変更などを行ったときにアカウントの引き継ぎをできるようにする設定です。<br />
    ///    `引き継ぎ設定` は `引き継ぎ用ユーザーID` と `引き継ぎ用パスワード` の組み合わせで実行できるようにします。<br />
    ///    <br />
    ///    `スロット番号` に異なる値を指定することで、1つのアカウントに対して複数の ``引き継ぎ設定` ` を保持できます。<br />
    ///    たとえば、 `スロット番号:0` にメールアドレス・パスワード を、 `スロット番号:1` にソーシャルメディアのID情報を格納するようにし、<br />
    ///    ゲームプレイヤーは好みの引き継ぎ手段を選択できるようにする。といった運用が可能です。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="type">スロット番号</param>
    /// <param name="userIdentifier">引き継ぎ用ユーザーID</param>
    /// <param name="password">パスワード</param>
    void AddTakeOverSetting(
        std::function<void(AsyncEzAddTakeOverSettingResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        Int32 type,
        const Char* userIdentifier,
        const Char* password
    );

    /// <summary>
    ///  設定されている `引き継ぎ設定` の一覧を取得<br />
    ///    <br />
    ///    ゲームプレイヤーが設定した `引き継ぎ設定` の一覧を取得できます。<br />
    ///    設定されている `引き継ぎ用パスワード` の値は取得できません。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void ListTakeOverSettings(
        std::function<void(AsyncEzListTakeOverSettingsResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* pageToken=nullptr,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  ``引き継ぎ設定` ` のパスワードを変更する<br />
    ///    <br />
    ///    このAPIを経由して `引き継ぎ用パスワード` を更新するためには、すでに設定されている `引き継ぎ用パスワード` を知っていなければ実行できません。<br />
    ///    セキュアな `引き継ぎ設定` の更新を実現したい場合に使用します。<br />
    ///    <br />
    ///    このAPIを使用する際には、 `引き継ぎ設定` の削除APIのアクセス権限を剥奪することを忘れないようにしてください。<br />
    ///    ゲームプレイヤーが自分の `引き継ぎ設定` の削除するにはパスワードの認証が必要ありません。<br />
    ///    削除して再作成することで、実質的に `引き継ぎ用パスワード` の変更ができてしまいます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="type">スロット番号</param>
    /// <param name="oldPassword">古いパスワード</param>
    /// <param name="password">新しいパスワード</param>
    void UpdateTakeOverSetting(
        std::function<void(AsyncEzUpdateTakeOverSettingResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        Int32 type,
        const Char* oldPassword,
        const Char* password
    );

    /// <summary>
    ///  `引き継ぎ設定` の削除<br />
    ///    <br />
    ///    設定されている `引き継ぎ設定` を削除します。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="type">スロット番号</param>
    void DeleteTakeOverSetting(
        std::function<void(AsyncEzDeleteTakeOverSettingResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        Int32 type
    );

    /// <summary>
    ///  引き継ぎを実行<br />
    ///    <br />
    ///    指定された `引き継ぎ用ユーザID` と `引き継ぎ用パスワード` が一致していた場合、設定されたアカウント情報を応答します。<br />
    ///    応答されたアカウント情報から `ユーザID` と `パスワード` を永続化して利用してください。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="type">スロット番号</param>
    /// <param name="userIdentifier">引き継ぎ用ユーザーID</param>
    /// <param name="password">パスワード</param>
    void DoTakeOver(
        std::function<void(AsyncEzDoTakeOverResult&)> callback,
        const Char* namespaceName,
        Int32 type,
        const Char* userIdentifier,
        const Char* password
    );
};

}}}

#endif //GS2_EZ_ACCOUNT_GS2ACCOUNTRESTCLIENT_HPP_