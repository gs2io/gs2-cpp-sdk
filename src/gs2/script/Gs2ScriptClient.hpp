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

#ifndef GS2_SCRIPT_GS2SCRIPTCLIENT_HPP_
#define GS2_SCRIPT_GS2SCRIPTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeScriptsRequest.hpp"
#include "request/CreateScriptRequest.hpp"
#include "request/GetScriptStatusRequest.hpp"
#include "request/GetScriptRequest.hpp"
#include "request/UpdateScriptRequest.hpp"
#include "request/DeleteScriptRequest.hpp"
#include "result/DescribeScriptsResult.hpp"
#include "result/CreateScriptResult.hpp"
#include "result/GetScriptStatusResult.hpp"
#include "result/GetScriptResult.hpp"
#include "result/UpdateScriptResult.hpp"
#include "result/DeleteScriptResult.hpp"
#include <cstring>

namespace gs2 { namespace script {

typedef AsyncResult<DescribeScriptsResult> AsyncDescribeScriptsResult;
typedef AsyncResult<CreateScriptResult> AsyncCreateScriptResult;
typedef AsyncResult<GetScriptStatusResult> AsyncGetScriptStatusResult;
typedef AsyncResult<GetScriptResult> AsyncGetScriptResult;
typedef AsyncResult<UpdateScriptResult> AsyncUpdateScriptResult;
typedef AsyncResult<void> AsyncDeleteScriptResult;

/**
 * GS2 Script API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ScriptClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "script";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Script& obj)
    {
        writer.writeObjectStart();
        if (obj.getScriptId())
        {
            writer.writePropertyName("scriptId");
            writer.write(*obj.getScriptId());
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
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getScript())
        {
            writer.writePropertyName("script");
            writer.write(*obj.getScript());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2ScriptClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ScriptClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ScriptClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }

	/**
	 * スクリプトの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeScripts(std::function<void(AsyncDescribeScriptsResult&)> callback, DescribeScriptsRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeScriptsResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/script-handler?handler=gs2_script%2Fhandler%2FScriptFunctionHandler.describeScripts");
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
	 * スクリプトを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createScript(std::function<void(AsyncCreateScriptResult&)> callback, CreateScriptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateScriptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/script-handler?handler=gs2_script%2Fhandler%2FScriptFunctionHandler.createScript");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getScript())
        {
            writer.writePropertyName("script");
            writer.write(*request.getScript());
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
	 * スクリプトを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getScriptStatus(std::function<void(AsyncGetScriptStatusResult&)> callback, GetScriptStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetScriptStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/script-handler?handler=gs2_script%2Fhandler%2FScriptFunctionHandler.getScriptStatus");
        Char encodeBuffer[2048];
        if (request.getScriptName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScriptName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scriptName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * スクリプトを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getScript(std::function<void(AsyncGetScriptResult&)> callback, GetScriptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetScriptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/script-handler?handler=gs2_script%2Fhandler%2FScriptFunctionHandler.getScript");
        Char encodeBuffer[2048];
        if (request.getScriptName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScriptName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scriptName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * スクリプトを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateScript(std::function<void(AsyncUpdateScriptResult&)> callback, UpdateScriptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateScriptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/script-handler?handler=gs2_script%2Fhandler%2FScriptFunctionHandler.updateScript");
        Char encodeBuffer[2048];
        if (request.getScriptName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScriptName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scriptName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getScript())
        {
            writer.writePropertyName("script");
            writer.write(*request.getScript());
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
	 * スクリプトを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteScript(std::function<void(AsyncDeleteScriptResult&)> callback, DeleteScriptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/script-handler?handler=gs2_script%2Fhandler%2FScriptFunctionHandler.deleteScript");
        Char encodeBuffer[2048];
        if (request.getScriptName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScriptName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scriptName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }
};

} }

#endif //GS2_SCRIPT_GS2SCRIPTCLIENT_HPP_