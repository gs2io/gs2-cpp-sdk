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

#ifndef GS2_LOG_GS2LOGWEBSOCKETCLIENT_HPP_
#define GS2_LOG_GS2LOGWEBSOCKETCLIENT_HPP_

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
#include "request/QueryAccessLogRequest.hpp"
#include "request/CountAccessLogRequest.hpp"
#include "request/QueryIssueStampSheetLogRequest.hpp"
#include "request/CountIssueStampSheetLogRequest.hpp"
#include "request/QueryExecuteStampSheetLogRequest.hpp"
#include "request/CountExecuteStampSheetLogRequest.hpp"
#include "request/QueryExecuteStampTaskLogRequest.hpp"
#include "request/CountExecuteStampTaskLogRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/QueryAccessLogResult.hpp"
#include "result/CountAccessLogResult.hpp"
#include "result/QueryIssueStampSheetLogResult.hpp"
#include "result/CountIssueStampSheetLogResult.hpp"
#include "result/QueryExecuteStampSheetLogResult.hpp"
#include "result/CountExecuteStampSheetLogResult.hpp"
#include "result/QueryExecuteStampTaskLogResult.hpp"
#include "result/CountExecuteStampTaskLogResult.hpp"

namespace gs2 { namespace log {

/**
 * GS2 Log API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LogWebSocketClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2LogWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * ネームスペースの状態を取得<br>
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
	 * アクセスログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryAccessLog(QueryAccessLogRequest request, std::function<void(AsyncQueryAccessLogResult)> callback);

	/**
	 * アクセスログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countAccessLog(CountAccessLogRequest request, std::function<void(AsyncCountAccessLogResult)> callback);

	/**
	 * スタンプシート発行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryIssueStampSheetLog(QueryIssueStampSheetLogRequest request, std::function<void(AsyncQueryIssueStampSheetLogResult)> callback);

	/**
	 * スタンプシート発行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countIssueStampSheetLog(CountIssueStampSheetLogRequest request, std::function<void(AsyncCountIssueStampSheetLogResult)> callback);

	/**
	 * スタンプシート実行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryExecuteStampSheetLog(QueryExecuteStampSheetLogRequest request, std::function<void(AsyncQueryExecuteStampSheetLogResult)> callback);

	/**
	 * スタンプシート実行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countExecuteStampSheetLog(CountExecuteStampSheetLogRequest request, std::function<void(AsyncCountExecuteStampSheetLogResult)> callback);

	/**
	 * スタンプタスク実行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryExecuteStampTaskLog(QueryExecuteStampTaskLogRequest request, std::function<void(AsyncQueryExecuteStampTaskLogResult)> callback);

	/**
	 * スタンプタスク実行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countExecuteStampTaskLog(CountExecuteStampTaskLogRequest request, std::function<void(AsyncCountExecuteStampTaskLogResult)> callback);

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LOG_GS2LOGWEBSOCKETCLIENT_HPP_