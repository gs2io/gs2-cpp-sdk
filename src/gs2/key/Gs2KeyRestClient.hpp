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

#ifndef GS2_KEY_GS2KEYRESTCLIENT_HPP_
#define GS2_KEY_GS2KEYRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
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
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace key {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<void> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeKeysResult> AsyncDescribeKeysResult;
typedef AsyncResult<CreateKeyResult> AsyncCreateKeyResult;
typedef AsyncResult<UpdateKeyResult> AsyncUpdateKeyResult;
typedef AsyncResult<GetKeyResult> AsyncGetKeyResult;
typedef AsyncResult<void> AsyncDeleteKeyResult;
typedef AsyncResult<EncryptResult> AsyncEncryptResult;
typedef AsyncResult<DecryptResult> AsyncDecryptResult;

/**
 * GS2 Key API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2KeyRestClient : public AbstractGs2ClientBase
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

    static void write(detail::json::JsonWriter& writer, const Key& obj)
    {
        writer.writeObjectStart();
        if (obj.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*obj.getKeyId());
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
        if (obj.getSecret())
        {
            writer.writePropertyName("secret");
            writer.writeCharArray(*obj.getSecret());
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2KeyRestClient(Gs2RestSession& gs2RestSession) :
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
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
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
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
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 暗号鍵の一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeKeys(std::function<void(AsyncDescribeKeysResult&)> callback, DescribeKeysRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeKeysResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/key";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

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
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 暗号鍵を新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createKey(std::function<void(AsyncCreateKeyResult&)> callback, CreateKeyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateKeyResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/key";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
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
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 暗号鍵を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateKey(std::function<void(AsyncUpdateKeyResult&)> callback, UpdateKeyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateKeyResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/key/{keyName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 暗号鍵を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getKey(std::function<void(AsyncGetKeyResult&)> callback, GetKeyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetKeyResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/key/{keyName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 暗号鍵を削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteKey(std::function<void(AsyncDeleteKeyResult&)> callback, DeleteKeyRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/key/{keyName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * データを暗号化します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void encrypt(std::function<void(AsyncEncryptResult&)> callback, EncryptRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<EncryptResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/key/{keyName}/encrypt";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getData())
        {
            writer.writePropertyName("data");
            writer.writeCharArray(*request.getData());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * データを復号します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void decrypt(std::function<void(AsyncDecryptResult&)> callback, DecryptRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DecryptResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "key");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/key/{keyName}/decrypt";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getData())
        {
            writer.writePropertyName("data");
            writer.writeCharArray(*request.getData());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_KEY_GS2KEYRESTCLIENT_HPP_