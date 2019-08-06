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
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
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
#include <cstring>

namespace gs2 { namespace gateway {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<void> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeWebSocketSessionsResult> AsyncDescribeWebSocketSessionsResult;
typedef AsyncResult<DescribeWebSocketSessionsByUserIdResult> AsyncDescribeWebSocketSessionsByUserIdResult;
typedef AsyncResult<SetUserIdResult> AsyncSetUserIdResult;
typedef AsyncResult<SetUserIdByUserIdResult> AsyncSetUserIdByUserIdResult;
typedef AsyncResult<GetWebSocketSessionResult> AsyncGetWebSocketSessionResult;
typedef AsyncResult<GetWebSocketSessionByConnectionIdResult> AsyncGetWebSocketSessionByConnectionIdResult;
typedef AsyncResult<SendNotificationResult> AsyncSendNotificationResult;
typedef AsyncResult<SetFirebaseTokenResult> AsyncSetFirebaseTokenResult;
typedef AsyncResult<SetFirebaseTokenByUserIdResult> AsyncSetFirebaseTokenByUserIdResult;
typedef AsyncResult<GetFirebaseTokenResult> AsyncGetFirebaseTokenResult;
typedef AsyncResult<GetFirebaseTokenByUserIdResult> AsyncGetFirebaseTokenByUserIdResult;
typedef AsyncResult<DeleteFirebaseTokenResult> AsyncDeleteFirebaseTokenResult;
typedef AsyncResult<DeleteFirebaseTokenByUserIdResult> AsyncDeleteFirebaseTokenByUserIdResult;
typedef AsyncResult<void> AsyncSendMobileNotificationByUserIdResult;

/**
 * GS2 Gateway API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2GatewayRestClient : public AbstractGs2ClientBase
{
private:
    static void write(detail::json::JsonWriter& writer, const Namespace& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceId())
        {
            writer.writePropertyName("namespaceId");
            writer.writeCharArray(*obj.getNamespaceId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getFirebaseSecret())
        {
            writer.writePropertyName("firebaseSecret");
            writer.writeCharArray(*obj.getFirebaseSecret());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const WebSocketSession& obj)
    {
        writer.writeObjectStart();
        if (obj.getConnectionId())
        {
            writer.writePropertyName("connectionId");
            writer.writeCharArray(*obj.getConnectionId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getNamespaceName())
        {
            writer.writePropertyName("namespaceName");
            writer.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const FirebaseToken& obj)
    {
        writer.writeObjectStart();
        if (obj.getFirebaseTokenId())
        {
            writer.writePropertyName("firebaseTokenId");
            writer.writeCharArray(*obj.getFirebaseTokenId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getToken())
        {
            writer.writePropertyName("token");
            writer.writeCharArray(*obj.getToken());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.writeCharArray(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.writeCharArray(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.writeCharArray(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.writeCharArray(*obj.getResult());
        }
        writer.writeObjectEnd();
    }



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
    void describeNamespaces(std::function<void(AsyncDescribeNamespacesResult&)> callback, DescribeNamespacesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeNamespacesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(std::function<void(AsyncCreateNamespaceResult&)> callback, CreateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getFirebaseSecret())
        {
            writer.writePropertyName("firebaseSecret");
            writer.writeCharArray(*request.getFirebaseSecret());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(std::function<void(AsyncGetNamespaceStatusResult&)> callback, GetNamespaceStatusRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceStatusResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(std::function<void(AsyncGetNamespaceResult&)> callback, GetNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(std::function<void(AsyncUpdateNamespaceResult&)> callback, UpdateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getFirebaseSecret())
        {
            writer.writePropertyName("firebaseSecret");
            writer.writeCharArray(*request.getFirebaseSecret());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(std::function<void(AsyncDeleteNamespaceResult&)> callback, DeleteNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * Websocketセッションの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebSocketSessions(std::function<void(AsyncDescribeWebSocketSessionsResult&)> callback, DescribeWebSocketSessionsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeWebSocketSessionsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/session/user/me";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してWebsocketセッションの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebSocketSessionsByUserId(std::function<void(AsyncDescribeWebSocketSessionsByUserIdResult&)> callback, DescribeWebSocketSessionsByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeWebSocketSessionsByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/session/user/{userId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * WebsocketセッションにユーザIDを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setUserId(std::function<void(AsyncSetUserIdResult&)> callback, SetUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/session/user/me/user";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getAllowConcurrentAccess())
        {
            writer.writePropertyName("allowConcurrentAccess");
            writer.writeBool(*request.getAllowConcurrentAccess());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * WebsocketセッションにユーザIDを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setUserIdByUserId(std::function<void(AsyncSetUserIdByUserIdResult&)> callback, SetUserIdByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetUserIdByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/session/user/{userId}/user";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getAllowConcurrentAccess())
        {
            writer.writePropertyName("allowConcurrentAccess");
            writer.writeBool(*request.getAllowConcurrentAccess());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * Websocketセッションを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWebSocketSession(std::function<void(AsyncGetWebSocketSessionResult&)> callback, GetWebSocketSessionRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetWebSocketSessionResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/session";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してWebsocketセッションを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWebSocketSessionByConnectionId(std::function<void(AsyncGetWebSocketSessionByConnectionIdResult&)> callback, GetWebSocketSessionByConnectionIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetWebSocketSessionByConnectionIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/session/{connectionId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getConnectionId();
            url.replace("{connectionId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 通知を送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendNotification(std::function<void(AsyncSendNotificationResult&)> callback, SendNotificationRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SendNotificationResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/session/user/{userId}/notification";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSubject())
        {
            writer.writePropertyName("subject");
            writer.writeCharArray(*request.getSubject());
        }
        if (request.getPayload())
        {
            writer.writePropertyName("payload");
            writer.writeCharArray(*request.getPayload());
        }
        if (request.getEnableTransferMobileNotification())
        {
            writer.writePropertyName("enableTransferMobileNotification");
            writer.writeBool(*request.getEnableTransferMobileNotification());
        }
        if (request.getSound())
        {
            writer.writePropertyName("sound");
            writer.writeCharArray(*request.getSound());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * デバイストークンを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFirebaseToken(std::function<void(AsyncSetFirebaseTokenResult&)> callback, SetFirebaseTokenRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetFirebaseTokenResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/firebase/token";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getToken())
        {
            writer.writePropertyName("token");
            writer.writeCharArray(*request.getToken());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してデバイストークンを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFirebaseTokenByUserId(std::function<void(AsyncSetFirebaseTokenByUserIdResult&)> callback, SetFirebaseTokenByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetFirebaseTokenByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/firebase/token";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getToken())
        {
            writer.writePropertyName("token");
            writer.writeCharArray(*request.getToken());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * Firebaseデバイストークンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFirebaseToken(std::function<void(AsyncGetFirebaseTokenResult&)> callback, GetFirebaseTokenRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetFirebaseTokenResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/firebase/token";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してFirebaseデバイストークンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFirebaseTokenByUserId(std::function<void(AsyncGetFirebaseTokenByUserIdResult&)> callback, GetFirebaseTokenByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetFirebaseTokenByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/firebase/token";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * Firebaseデバイストークンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFirebaseToken(std::function<void(AsyncDeleteFirebaseTokenResult&)> callback, DeleteFirebaseTokenRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteFirebaseTokenResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/firebase/token";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してFirebaseデバイストークンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFirebaseTokenByUserId(std::function<void(AsyncDeleteFirebaseTokenByUserIdResult&)> callback, DeleteFirebaseTokenByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteFirebaseTokenByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/firebase/token";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * モバイルプッシュ通知を送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMobileNotificationByUserId(std::function<void(AsyncSendMobileNotificationByUserIdResult&)> callback, SendMobileNotificationByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "gateway");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/firebase/token/notification";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSubject())
        {
            writer.writePropertyName("subject");
            writer.writeCharArray(*request.getSubject());
        }
        if (request.getPayload())
        {
            writer.writePropertyName("payload");
            writer.writeCharArray(*request.getPayload());
        }
        if (request.getSound())
        {
            writer.writePropertyName("sound");
            writer.writeCharArray(*request.getSound());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_GATEWAY_GS2GATEWAYRESTCLIENT_HPP_