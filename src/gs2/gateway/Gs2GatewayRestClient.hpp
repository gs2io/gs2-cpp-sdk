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

#ifndef GS2_GATEWAY_GS2GATEWAYRESTCLIENT_HPP_
#define GS2_GATEWAY_GS2GATEWAYRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeWebSocketSessionsRequest.hpp"
#include "request/DescribeWebSocketSessionsByUserIdRequest.hpp"
#include "request/SetUserIdRequest.hpp"
#include "request/SetUserIdByUserIdRequest.hpp"
#include "request/GetWebSocketSessionRequest.hpp"
#include "request/GetWebSocketSessionByConnectionIdRequest.hpp"
#include "request/SendNotificationRequest.hpp"
#include "request/SetFirebaseTokenRequest.hpp"
#include "request/SetFirebaseTokenByUserIdRequest.hpp"
#include "request/GetFirebaseTokenRequest.hpp"
#include "request/GetFirebaseTokenByUserIdRequest.hpp"
#include "request/DeleteFirebaseTokenRequest.hpp"
#include "request/DeleteFirebaseTokenByUserIdRequest.hpp"
#include "request/SendMobileNotificationByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeWebSocketSessionsResult.hpp"
#include "result/DescribeWebSocketSessionsByUserIdResult.hpp"
#include "result/SetUserIdResult.hpp"
#include "result/SetUserIdByUserIdResult.hpp"
#include "result/GetWebSocketSessionResult.hpp"
#include "result/GetWebSocketSessionByConnectionIdResult.hpp"
#include "result/SendNotificationResult.hpp"
#include "result/SetFirebaseTokenResult.hpp"
#include "result/SetFirebaseTokenByUserIdResult.hpp"
#include "result/GetFirebaseTokenResult.hpp"
#include "result/GetFirebaseTokenByUserIdResult.hpp"
#include "result/DeleteFirebaseTokenResult.hpp"
#include "result/DeleteFirebaseTokenByUserIdResult.hpp"
#include "result/SendMobileNotificationByUserIdResult.hpp"

namespace gs2 { namespace gateway {

/**
 * GS2 Gateway API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2GatewayRestClient : public AbstractGs2ClientBase
{
public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2GatewayRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
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
	 * Websocketセッションの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebSocketSessions(DescribeWebSocketSessionsRequest request, std::function<void(AsyncDescribeWebSocketSessionsResult)> callback);

	/**
	 * ユーザIDを指定してWebsocketセッションの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebSocketSessionsByUserId(DescribeWebSocketSessionsByUserIdRequest request, std::function<void(AsyncDescribeWebSocketSessionsByUserIdResult)> callback);

	/**
	 * WebsocketセッションにユーザIDを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setUserId(SetUserIdRequest request, std::function<void(AsyncSetUserIdResult)> callback);

	/**
	 * WebsocketセッションにユーザIDを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setUserIdByUserId(SetUserIdByUserIdRequest request, std::function<void(AsyncSetUserIdByUserIdResult)> callback);

	/**
	 * Websocketセッションを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWebSocketSession(GetWebSocketSessionRequest request, std::function<void(AsyncGetWebSocketSessionResult)> callback);

	/**
	 * ユーザIDを指定してWebsocketセッションを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWebSocketSessionByConnectionId(GetWebSocketSessionByConnectionIdRequest request, std::function<void(AsyncGetWebSocketSessionByConnectionIdResult)> callback);

	/**
	 * 通知を送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendNotification(SendNotificationRequest request, std::function<void(AsyncSendNotificationResult)> callback);

	/**
	 * デバイストークンを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFirebaseToken(SetFirebaseTokenRequest request, std::function<void(AsyncSetFirebaseTokenResult)> callback);

	/**
	 * ユーザIDを指定してデバイストークンを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFirebaseTokenByUserId(SetFirebaseTokenByUserIdRequest request, std::function<void(AsyncSetFirebaseTokenByUserIdResult)> callback);

	/**
	 * Firebaseデバイストークンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFirebaseToken(GetFirebaseTokenRequest request, std::function<void(AsyncGetFirebaseTokenResult)> callback);

	/**
	 * ユーザIDを指定してFirebaseデバイストークンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFirebaseTokenByUserId(GetFirebaseTokenByUserIdRequest request, std::function<void(AsyncGetFirebaseTokenByUserIdResult)> callback);

	/**
	 * Firebaseデバイストークンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFirebaseToken(DeleteFirebaseTokenRequest request, std::function<void(AsyncDeleteFirebaseTokenResult)> callback);

	/**
	 * ユーザIDを指定してFirebaseデバイストークンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFirebaseTokenByUserId(DeleteFirebaseTokenByUserIdRequest request, std::function<void(AsyncDeleteFirebaseTokenByUserIdResult)> callback);

	/**
	 * モバイルプッシュ通知を送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMobileNotificationByUserId(SendMobileNotificationByUserIdRequest request, std::function<void(AsyncSendMobileNotificationByUserIdResult)> callback);

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_GATEWAY_GS2GATEWAYRESTCLIENT_HPP_