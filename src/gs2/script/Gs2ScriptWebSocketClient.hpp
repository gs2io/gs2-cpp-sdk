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

#ifndef GS2_SCRIPT_GS2SCRIPTWEBSOCKETCLIENT_HPP_
#define GS2_SCRIPT_GS2SCRIPTWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeScriptsRequest.hpp"
#include "request/CreateScriptRequest.hpp"
#include "request/CreateScriptFromGitHubRequest.hpp"
#include "request/GetScriptRequest.hpp"
#include "request/UpdateScriptRequest.hpp"
#include "request/UpdateScriptFromGitHubRequest.hpp"
#include "request/DeleteScriptRequest.hpp"
#include "request/DebugInvokeRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeScriptsResult.hpp"
#include "result/CreateScriptResult.hpp"
#include "result/CreateScriptFromGitHubResult.hpp"
#include "result/GetScriptResult.hpp"
#include "result/UpdateScriptResult.hpp"
#include "result/UpdateScriptFromGitHubResult.hpp"
#include "result/DeleteScriptResult.hpp"
#include "result/DebugInvokeResult.hpp"

namespace gs2 { namespace script {

/**
 * GS2 Script API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ScriptWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2ScriptWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * スクリプトの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeScripts(DescribeScriptsRequest request, std::function<void(AsyncDescribeScriptsResult)> callback);

	/**
	 * スクリプトを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createScript(CreateScriptRequest request, std::function<void(AsyncCreateScriptResult)> callback);

	/**
	 * GitHubリポジトリのコードからスクリプトを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createScriptFromGitHub(CreateScriptFromGitHubRequest request, std::function<void(AsyncCreateScriptFromGitHubResult)> callback);

	/**
	 * スクリプトを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getScript(GetScriptRequest request, std::function<void(AsyncGetScriptResult)> callback);

	/**
	 * スクリプトを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateScript(UpdateScriptRequest request, std::function<void(AsyncUpdateScriptResult)> callback);

	/**
	 * GithHub をデータソースとしてスクリプトを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateScriptFromGitHub(UpdateScriptFromGitHubRequest request, std::function<void(AsyncUpdateScriptFromGitHubResult)> callback);

	/**
	 * スクリプトを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteScript(DeleteScriptRequest request, std::function<void(AsyncDeleteScriptResult)> callback);

	/**
	 * スクリプトを実行します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void debugInvoke(DebugInvokeRequest request, std::function<void(AsyncDebugInvokeResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_SCRIPT_GS2SCRIPTWEBSOCKETCLIENT_HPP_