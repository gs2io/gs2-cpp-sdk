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

#ifndef GS2_EZ_EXPERIENCE_GS2EXPERIENCERESTCLIENT_HPP_
#define GS2_EZ_EXPERIENCE_GS2EXPERIENCERESTCLIENT_HPP_

#include <gs2/experience/Gs2ExperienceWebSocketClient.hpp>
#include "result/EzListExperienceModelsResult.hpp"
#include "result/EzGetExperienceModelResult.hpp"
#include "result/EzListStatusesResult.hpp"
#include "result/EzGetStatusResult.hpp"


namespace gs2 { namespace ez {

class Profile;
class GameSession;

namespace experience {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::experience::Gs2ExperienceWebSocketClient m_Client;

public:
    Client(gs2::ez::Profile& profile);

    /// <summary>
    ///  経験値・ランクアップ閾値モデル情報の一覧を取得<br />
    ///    <br />
    ///    ランクキャップの情報やランクアップ閾値の情報を取得します。<br />
    ///    次のランクアップまでに必要な獲得経験値量などをゲーム内で表示したい場合はこのモデルデータを使ってください。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listExperienceModels(
        std::function<void(AsyncEzListExperienceModelsResult&)> callback,
        const Char* namespaceName
    );

    /// <summary>
    ///  経験値・ランクアップ閾値モデル情報を取得<br />
    ///    <br />
    ///    `経験値の種類名` を指定してランクキャップの情報やランクアップ閾値の情報を取得します。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="experienceName">経験値の種類名</param>
    void getExperienceModel(
        std::function<void(AsyncEzGetExperienceModelResult&)> callback,
        const Char* namespaceName,
        const Char* experienceName
    );

    /// <summary>
    ///  ステータス情報の一覧を取得<br />
    ///    <br />
    ///    経験値の種類名 は省略可能で、指定しなかった場合はゲームプレイヤーに属する全てのステータス情報が取得できます。<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="experienceName">経験値の種類名</param>
    /// <param name="pageToken">データの取得を開始する位置を指定するトークン</param>
    /// <param name="limit">データの取得件数</param>
    void listStatuses(
        std::function<void(AsyncEzListStatusesResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* experienceName=nullptr,
        const Char* pageToken=nullptr,
        gs2::optional<Int64> limit=gs2::nullopt
    );

    /// <summary>
    ///  `経験値の種類` と `プロパティID` を指定してステータス情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="callback">コールバックハンドラ</param>
    /// <param name="session">ゲームセッション</param>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="experienceName">経験値の種類の名前</param>
    /// <param name="propertyId">プロパティID</param>
    void getStatus(
        std::function<void(AsyncEzGetStatusResult&)> callback,
        GameSession& session,
        const Char* namespaceName,
        const Char* experienceName,
        const Char* propertyId
    );
};

}}}

#endif //GS2_EZ_EXPERIENCE_GS2EXPERIENCERESTCLIENT_HPP_