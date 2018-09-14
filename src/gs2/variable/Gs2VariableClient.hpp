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

#ifndef GS2_VARIABLE_GS2VARIABLECLIENT_HPP_
#define GS2_VARIABLE_GS2VARIABLECLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace variable {

typedef AsyncResult<void> AsyncDeleteMyVariableResult;
typedef AsyncResult<void> AsyncDeleteVariableResult;
typedef AsyncResult<GetMyVariableResult> AsyncGetMyVariableResult;
typedef AsyncResult<GetVariableResult> AsyncGetVariableResult;
typedef AsyncResult<SetMyVariableResult> AsyncSetMyVariableResult;
typedef AsyncResult<SetVariableResult> AsyncSetVariableResult;

class Gs2VariableClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "variable";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2VariableClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2VariableClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2VariableClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * 変数を削除する<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMyVariable(std::function<void(AsyncDeleteMyVariableResult&)> callback, DeleteMyVariableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/variable/").append(detail::StringUtil::toStr(buffer, request.getVariableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 変数を削除する<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteVariable(std::function<void(AsyncDeleteVariableResult&)> callback, DeleteVariableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/variable/").append(detail::StringUtil::toStr(buffer, request.getVariableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 変数を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMyVariable(std::function<void(AsyncGetMyVariableResult&)> callback, GetMyVariableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMyVariableResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/variable/").append(detail::StringUtil::toStr(buffer, request.getVariableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 変数を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getVariable(std::function<void(AsyncGetVariableResult&)> callback, GetVariableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetVariableResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/variable/").append(detail::StringUtil::toStr(buffer, request.getVariableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 変数を格納する<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMyVariable(std::function<void(AsyncSetMyVariableResult&)> callback, SetMyVariableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SetMyVariableResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/variable/").append(detail::StringUtil::toStr(buffer, request.getVariableName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*request.getValue());
        }
        if (request.getTtl())
        {
            writer.writePropertyName("ttl");
            writer.write(*request.getTtl());
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
     * 変数を格納する<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setVariable(std::function<void(AsyncSetVariableResult&)> callback, SetVariableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SetVariableResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/variable/").append(detail::StringUtil::toStr(buffer, request.getVariableName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*request.getValue());
        }
        if (request.getTtl())
        {
            writer.writePropertyName("ttl");
            writer.write(*request.getTtl());
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

#endif //GS2_VARIABLE_GS2VARIABLECLIENT_HPP_