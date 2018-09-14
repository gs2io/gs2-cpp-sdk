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

#ifndef GS2_TIMER_GS2TIMERCLIENT_HPP_
#define GS2_TIMER_GS2TIMERCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace timer {

typedef AsyncResult<CreateTimerPoolResult> AsyncCreateTimerPoolResult;
typedef AsyncResult<void> AsyncDeleteTimerPoolResult;
typedef AsyncResult<DescribeTimerPoolResult> AsyncDescribeTimerPoolResult;
typedef AsyncResult<GetTimerPoolResult> AsyncGetTimerPoolResult;
typedef AsyncResult<UpdateTimerPoolResult> AsyncUpdateTimerPoolResult;
typedef AsyncResult<CreateTimerResult> AsyncCreateTimerResult;
typedef AsyncResult<void> AsyncDeleteTimerResult;
typedef AsyncResult<DescribeTimerResult> AsyncDescribeTimerResult;
typedef AsyncResult<GetTimerResult> AsyncGetTimerResult;

class Gs2TimerClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "timer";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const TimerPool& obj)
    {
        writer.writeObjectStart();
        if (obj.getTimerPoolId())
        {
            writer.writePropertyName("timerPoolId");
            writer.write(*obj.getTimerPoolId());
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

    void write(detail::json::JsonWriter& writer, const Timer& obj)
    {
        writer.writeObjectStart();
        if (obj.getTimerId())
        {
            writer.writePropertyName("timerId");
            writer.write(*obj.getTimerId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getTimerPoolId())
        {
            writer.writePropertyName("timerPoolId");
            writer.write(*obj.getTimerPoolId());
        }
        if (obj.getCallbackMethod())
        {
            writer.writePropertyName("callbackMethod");
            writer.write(*obj.getCallbackMethod());
        }
        if (obj.getCallbackUrl())
        {
            writer.writePropertyName("callbackUrl");
            writer.write(*obj.getCallbackUrl());
        }
        if (obj.getCallbackBody())
        {
            writer.writePropertyName("callbackBody");
            writer.write(*obj.getCallbackBody());
        }
        if (obj.getExecuteTime())
        {
            writer.writePropertyName("executeTime");
            writer.write(*obj.getExecuteTime());
        }
        if (obj.getRetryMax())
        {
            writer.writePropertyName("retryMax");
            writer.write(*obj.getRetryMax());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2TimerClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2TimerClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2TimerClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * タイマープールを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTimerPool(std::function<void(AsyncCreateTimerPoolResult&)> callback, CreateTimerPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateTimerPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/timerPool");
        }
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
     * タイマープールを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTimerPool(std::function<void(AsyncDeleteTimerPoolResult&)> callback, DeleteTimerPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/timerPool/").append(detail::StringUtil::toStr(buffer, request.getTimerPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * タイマープールの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTimerPool(std::function<void(AsyncDescribeTimerPoolResult&)> callback, DescribeTimerPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeTimerPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/timerPool");
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
     * タイマープールを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTimerPool(std::function<void(AsyncGetTimerPoolResult&)> callback, GetTimerPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetTimerPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/timerPool/").append(detail::StringUtil::toStr(buffer, request.getTimerPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * タイマープールを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTimerPool(std::function<void(AsyncUpdateTimerPoolResult&)> callback, UpdateTimerPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateTimerPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/timerPool/").append(detail::StringUtil::toStr(buffer, request.getTimerPoolName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
     * タイマーを新規作成します<br>
     * <br>
     * タイマーの timestamp は秒単位で指定できますが、<br>
     * 指定した時刻以降で通常1分以内にコールバックURLは呼び出されます<br>
     * <br>
     * 混雑時などには数分の遅れが出ることがあります<br>
     * <br>
     * タイマーによるコールバックは指定されたリトライ回数試行します<br>
     * タイムアウトなどの理由により、実際には通信が到達しているにもかかわらず、リトライが発生する可能性があります<br>
     * <br>
     * コールバックは同等のリクエストが複数回呼び出されても問題なく動作するように設計してください<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTimer(std::function<void(AsyncCreateTimerResult&)> callback, CreateTimerRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateTimerResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/timerPool/").append(detail::StringUtil::toStr(buffer, request.getTimerPoolName())).append("/timer");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCallbackMethod())
        {
            writer.writePropertyName("callbackMethod");
            writer.write(*request.getCallbackMethod());
        }
        if (request.getCallbackUrl())
        {
            writer.writePropertyName("callbackUrl");
            writer.write(*request.getCallbackUrl());
        }
        if (request.getExecuteTime())
        {
            writer.writePropertyName("executeTime");
            writer.write(*request.getExecuteTime());
        }
        if (request.getCallbackBody())
        {
            writer.writePropertyName("callbackBody");
            writer.write(*request.getCallbackBody());
        }
        if (request.getRetryMax())
        {
            writer.writePropertyName("retryMax");
            writer.write(*request.getRetryMax());
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
     * タイマーを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTimer(std::function<void(AsyncDeleteTimerResult&)> callback, DeleteTimerRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/timerPool/").append(detail::StringUtil::toStr(buffer, request.getTimerPoolName())).append("/timer/").append(detail::StringUtil::toStr(buffer, request.getTimerId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * タイマーの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTimer(std::function<void(AsyncDescribeTimerResult&)> callback, DescribeTimerRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeTimerResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/timerPool/").append(detail::StringUtil::toStr(buffer, request.getTimerPoolName())).append("/timer");
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
     * タイマーを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTimer(std::function<void(AsyncGetTimerResult&)> callback, GetTimerRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetTimerResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/timerPool/").append(detail::StringUtil::toStr(buffer, request.getTimerPoolName())).append("/timer/").append(detail::StringUtil::toStr(buffer, request.getTimerId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_TIMER_GS2TIMERCLIENT_HPP_