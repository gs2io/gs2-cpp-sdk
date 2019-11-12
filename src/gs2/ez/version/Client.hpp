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

#ifndef GS2_EZ_VERSION_GS2VERSIONRESTCLIENT_HPP_
#define GS2_EZ_VERSION_GS2VERSIONRESTCLIENT_HPP_

#include <gs2/version/Gs2VersionWebSocketClient.hpp>
#include "result/EzListVersionModelsResult.hpp"
#include "result/EzGetVersionModelResult.hpp"
#include "result/EzListResult.hpp"
#include "result/EzDeleteResult.hpp"
#include "result/EzCheckVersionResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace version {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::version::Gs2VersionWebSocketClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  バージョン設定を認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listVersionModels(
        std::function<void(AsyncEzListVersionModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  バージョン設定を認証<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="versionName">バージョン名</param>
    void getVersionModel(
        std::function<void(AsyncEzGetVersionModelResult)> callback,
        StringHolder namespaceName,
        StringHolder versionName
    );

    /// <summary>
    ///  承認したバージョンの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void list(
        std::function<void(AsyncEzListResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<StringHolder> pageToken=gs2::nullopt,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  承認したバージョンを削除する<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="versionName">承認したバージョン名</param>
    void delete_(
        std::function<void(AsyncEzDeleteResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        StringHolder versionName
    );

    /// <summary>
    ///  スタンプタスクを実行<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="targetVersions">加算するリソース</param>
    void checkVersion(
        std::function<void(AsyncEzCheckVersionResult)> callback,
        GameSession& session,
        StringHolder namespaceName,
        gs2::optional<List<EzTargetVersion>> targetVersions=gs2::nullopt
    );
};

}}}

#endif //GS2_EZ_VERSION_GS2VERSIONRESTCLIENT_HPP_