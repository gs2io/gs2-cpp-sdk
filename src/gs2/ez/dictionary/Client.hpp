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

#ifndef GS2_EZ_DICTIONARY_GS2DICTIONARYWEBSOCKETCLIENT_HPP_
#define GS2_EZ_DICTIONARY_GS2DICTIONARYWEBSOCKETCLIENT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include "result/EzListEntryModelsResult.hpp"
#include "result/EzGetEntryModelResult.hpp"
#include "result/EzListEntriesResult.hpp"
#include "result/EzGetEntryResult.hpp"


namespace gs2 {

namespace dictionary {

class Gs2DictionaryWebSocketClient;

}

namespace ez {

class Profile;
class GameSession;

namespace dictionary {

class Client : public gs2::Gs2Object
{
private:
    gs2::ez::Profile& m_Profile;
    gs2::dictionary::Gs2DictionaryWebSocketClient* m_pClient;

public:
    Client(gs2::ez::Profile& profile);
    ~Client();

    /// <summary>
    ///  エントリーモデル情報の一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listEntryModels(
        std::function<void(AsyncEzListEntryModelsResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  エントリーモデル情報を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="entryName">エントリーモデル名</param>
    void getEntryModel(
        std::function<void(AsyncEzGetEntryModelResult)> callback,
        StringHolder namespaceName,
        StringHolder entryName
    );

    /// <summary>
    ///  エントリーの一覧を取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    void listEntries(
        std::function<void(AsyncEzListEntriesResult)> callback,
        StringHolder namespaceName
    );

    /// <summary>
    ///  エントリーを取得<br />
    /// </summary>
    ///
    /// <returns>IEnumerator</returns>
    /// <param name="namespaceName">ネームスペース名</param>
    /// <param name="entryModelName">エントリー名</param>
    void getEntry(
        std::function<void(AsyncEzGetEntryResult)> callback,
        StringHolder namespaceName,
        StringHolder entryModelName
    );
};

}}}

#endif //GS2_EZ_DICTIONARY_GS2DICTIONARYWEBSOCKETCLIENT_HPP_