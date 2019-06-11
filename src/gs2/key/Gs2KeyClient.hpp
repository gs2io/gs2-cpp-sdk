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

#ifndef GS2_KEY_GS2KEYCLIENT_HPP_
#define GS2_KEY_GS2KEYCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeKeysRequest.hpp"
#include "request/CreateKeyRequest.hpp"
#include "request/GetKeyRequest.hpp"
#include "request/DeleteKeyRequest.hpp"
#include "request/EncryptRequest.hpp"
#include "request/DecryptRequest.hpp"
#include "result/DescribeKeysResult.hpp"
#include "result/CreateKeyResult.hpp"
#include "result/GetKeyResult.hpp"
#include "result/DeleteKeyResult.hpp"
#include "result/EncryptResult.hpp"
#include "result/DecryptResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace key {

typedef AsyncResult<DescribeKeysResult> AsyncDescribeKeysResult;
typedef AsyncResult<CreateKeyResult> AsyncCreateKeyResult;
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
class Gs2KeyClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "key";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const Key& obj)
    {
        writer.writeObjectStart();
        if (obj.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*obj.getKeyId());
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
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const FullKey& obj)
    {
        writer.writeObjectStart();
        if (obj.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*obj.getKeyId());
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
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getSecret())
        {
            writer.writePropertyName("secret");
            writer.writeCharArray(*obj.getSecret());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    Gs2KeyClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
	 * @param region アクセス先リージョン
     */
    Gs2KeyClient(Gs2RestSession& gs2RestSession, const Region& region) :
        AbstractGs2ClientBase(gs2RestSession, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
	 * @param region アクセス先リージョン
     */
    Gs2KeyClient(Gs2RestSession& gs2RestSession, const Char region[]) :
        AbstractGs2ClientBase(gs2RestSession, region)
    {
    }

	/**
	 * 暗号鍵の一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeKeys(std::function<void(AsyncDescribeKeysResult&)> callback, DescribeKeysRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeKeysResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.describeKeys");
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", urlSafeValue);
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 暗号鍵を新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createKey(std::function<void(AsyncCreateKeyResult&)> callback, CreateKeyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateKeyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.createKey");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*request.getName());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
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
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 暗号鍵を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getKey(std::function<void(AsyncGetKeyResult&)> callback, GetKeyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetKeyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.getKey");
        if (request.getKeyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getKeyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("keyName={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 暗号鍵を削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteKey(std::function<void(AsyncDeleteKeyResult&)> callback, DeleteKeyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.deleteKey");
        if (request.getKeyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getKeyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("keyName={value}").replace("{value}", urlSafeValue);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * データを暗号化します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void encrypt(std::function<void(AsyncEncryptResult&)> callback, EncryptRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<EncryptResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.encrypt");
        if (request.getKeyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getKeyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("keyName={value}").replace("{value}", urlSafeValue);
        }
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
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
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
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * データを復号します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void decrypt(std::function<void(AsyncDecryptResult&)> callback, DecryptRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DecryptResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.decrypt");
        if (request.getKeyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getKeyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("keyName={value}").replace("{value}", urlSafeValue);
        }
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
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
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
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_KEY_GS2KEYCLIENT_HPP_