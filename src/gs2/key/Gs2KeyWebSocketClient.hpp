/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
 * Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
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

#ifndef GS2_KEY_GS2KEYWEBSOCKETCLIENT_HPP_
#define GS2_KEY_GS2KEYWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeKeysRequest.hpp"
#include "request/CreateKeyRequest.hpp"
#include "request/UpdateKeyRequest.hpp"
#include "request/GetKeyRequest.hpp"
#include "request/DeleteKeyRequest.hpp"
#include "request/EncryptRequest.hpp"
#include "request/DecryptRequest.hpp"
#include "request/DescribeGitHubApiKeysRequest.hpp"
#include "request/CreateGitHubApiKeyRequest.hpp"
#include "request/UpdateGitHubApiKeyRequest.hpp"
#include "request/GetGitHubApiKeyRequest.hpp"
#include "request/DeleteGitHubApiKeyRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeKeysResult.hpp"
#include "result/CreateKeyResult.hpp"
#include "result/UpdateKeyResult.hpp"
#include "result/GetKeyResult.hpp"
#include "result/DeleteKeyResult.hpp"
#include "result/EncryptResult.hpp"
#include "result/DecryptResult.hpp"
#include "result/DescribeGitHubApiKeysResult.hpp"
#include "result/CreateGitHubApiKeyResult.hpp"
#include "result/UpdateGitHubApiKeyResult.hpp"
#include "result/GetGitHubApiKeyResult.hpp"
#include "result/DeleteGitHubApiKeyResult.hpp"

namespace gs2 { namespace key {

/**
 * GS2 Key API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2KeyWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2KeyWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback);

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback);

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback);

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback);

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback);

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback);

	/**
	 * 暗号鍵の一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeKeys(DescribeKeysRequest request, std::function<void(AsyncDescribeKeysResult)> callback);

	/**
	 * 暗号鍵を新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createKey(CreateKeyRequest request, std::function<void(AsyncCreateKeyResult)> callback);

	/**
	 * 暗号鍵を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateKey(UpdateKeyRequest request, std::function<void(AsyncUpdateKeyResult)> callback);

	/**
	 * 暗号鍵を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getKey(GetKeyRequest request, std::function<void(AsyncGetKeyResult)> callback);

	/**
	 * 暗号鍵を削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteKey(DeleteKeyRequest request, std::function<void(AsyncDeleteKeyResult)> callback);

	/**
	 * データを暗号化します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void encrypt(EncryptRequest request, std::function<void(AsyncEncryptResult)> callback);

	/**
	 * データを復号します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void decrypt(DecryptRequest request, std::function<void(AsyncDecryptResult)> callback);

	/**
	 * GitHub のAPIキーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGitHubApiKeys(DescribeGitHubApiKeysRequest request, std::function<void(AsyncDescribeGitHubApiKeysResult)> callback);

	/**
	 * GitHub のAPIキーを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGitHubApiKey(CreateGitHubApiKeyRequest request, std::function<void(AsyncCreateGitHubApiKeyResult)> callback);

	/**
	 * GitHub のAPIキーを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGitHubApiKey(UpdateGitHubApiKeyRequest request, std::function<void(AsyncUpdateGitHubApiKeyResult)> callback);

	/**
	 * GitHub のAPIキーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGitHubApiKey(GetGitHubApiKeyRequest request, std::function<void(AsyncGetGitHubApiKeyResult)> callback);

	/**
	 * GitHub のAPIキーを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGitHubApiKey(DeleteGitHubApiKeyRequest request, std::function<void(AsyncDeleteGitHubApiKeyResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_KEY_GS2KEYWEBSOCKETCLIENT_HPP_