/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace script {

typedef AsyncResult<CreateScriptResult> AsyncCreateScriptResult;
typedef AsyncResult<void> AsyncDeleteScriptResult;
typedef AsyncResult<DescribeScriptResult> AsyncDescribeScriptResult;
typedef AsyncResult<GetScriptResult> AsyncGetScriptResult;
typedef AsyncResult<UpdateScriptResult> AsyncUpdateScriptResult;

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
     * スクリプトを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createScript(std::function<void(AsyncCreateScriptResult&)> callback, CreateScriptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateScriptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/script");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getScript())
        {
            writer.writePropertyName("script");
            writer.write(*request.getScript());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
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
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteScript(std::function<void(AsyncDeleteScriptResult&)> callback, DeleteScriptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/script/").append(detail::StringUtil::toStr(buffer, request.getScriptName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スクリプトの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeScript(std::function<void(AsyncDescribeScriptResult&)> callback, DescribeScriptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeScriptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/script");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スクリプトを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getScript(std::function<void(AsyncGetScriptResult&)> callback, GetScriptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetScriptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/script/").append(detail::StringUtil::toStr(buffer, request.getScriptName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スクリプトを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateScript(std::function<void(AsyncUpdateScriptResult&)> callback, UpdateScriptRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateScriptResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/script/").append(detail::StringUtil::toStr(buffer, request.getScriptName())).append("");
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

};

} }

#endif //GS2_SCRIPT_GS2SCRIPTCLIENT_HPP_