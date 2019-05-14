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
#include <gs2/core/network/HttpRequest.hpp>
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
            writer.write(*obj.getKeyId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const FullKey& obj)
    {
        writer.writeObjectStart();
        if (obj.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*obj.getKeyId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getSecret())
        {
            writer.writePropertyName("secret");
            writer.write(*obj.getSecret());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2KeyClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2KeyClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2KeyClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
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
        auto& httpRequest = *new detail::HttpRequest<DescribeKeysResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.describeKeys");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 暗号鍵を新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createKey(std::function<void(AsyncCreateKeyResult&)> callback, CreateKeyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateKeyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.createKey");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 暗号鍵を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getKey(std::function<void(AsyncGetKeyResult&)> callback, GetKeyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetKeyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.getKey");
        Char encodeBuffer[2048];
        if (request.getKeyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getKeyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("keyName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 暗号鍵を削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteKey(std::function<void(AsyncDeleteKeyResult&)> callback, DeleteKeyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.deleteKey");
        Char encodeBuffer[2048];
        if (request.getKeyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getKeyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("keyName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * データを暗号化します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void encrypt(std::function<void(AsyncEncryptResult&)> callback, EncryptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<EncryptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.encrypt");
        Char encodeBuffer[2048];
        if (request.getKeyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getKeyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("keyName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getData())
        {
            writer.writePropertyName("data");
            writer.write(*request.getData());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * データを復号します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void decrypt(std::function<void(AsyncDecryptResult&)> callback, DecryptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DecryptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/key-handler?handler=gs2_key%2Fhandler%2FKeyFunctionHandler.decrypt");
        Char encodeBuffer[2048];
        if (request.getKeyName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getKeyName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("keyName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getData())
        {
            writer.writePropertyName("data");
            writer.write(*request.getData());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }
};

} }

#endif //GS2_KEY_GS2KEYCLIENT_HPP_