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

#ifndef GS2_WATCH_GS2WATCHCLIENT_HPP_
#define GS2_WATCH_GS2WATCHCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace watch {

typedef AsyncResult<CreateAlarmResult> AsyncCreateAlarmResult;
typedef AsyncResult<void> AsyncDeleteAlarmResult;
typedef AsyncResult<DescribeAlarmResult> AsyncDescribeAlarmResult;
typedef AsyncResult<DescribeAlarmEventResult> AsyncDescribeAlarmEventResult;
typedef AsyncResult<GetAlarmResult> AsyncGetAlarmResult;
typedef AsyncResult<UpdateAlarmResult> AsyncUpdateAlarmResult;
typedef AsyncResult<DescribeOperationResult> AsyncDescribeOperationResult;
typedef AsyncResult<DescribeServiceResult> AsyncDescribeServiceResult;
typedef AsyncResult<GetMetricResult> AsyncGetMetricResult;

class Gs2WatchClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "watch";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Alarm& obj)
    {
        writer.writeObjectStart();
        if (obj.getAlarmId())
        {
            writer.writePropertyName("alarmId");
            writer.write(*obj.getAlarmId());
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
        if (obj.getService())
        {
            writer.writePropertyName("service");
            writer.write(*obj.getService());
        }
        if (obj.getServiceId())
        {
            writer.writePropertyName("serviceId");
            writer.write(*obj.getServiceId());
        }
        if (obj.getOperation())
        {
            writer.writePropertyName("operation");
            writer.write(*obj.getOperation());
        }
        if (obj.getExpression())
        {
            writer.writePropertyName("expression");
            writer.write(*obj.getExpression());
        }
        if (obj.getThreshold())
        {
            writer.writePropertyName("threshold");
            writer.write(*obj.getThreshold());
        }
        if (obj.getNotificationId())
        {
            writer.writePropertyName("notificationId");
            writer.write(*obj.getNotificationId());
        }
        if (obj.getStatus())
        {
            writer.writePropertyName("status");
            writer.write(*obj.getStatus());
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
        if (obj.getLastStatusChangeAt())
        {
            writer.writePropertyName("lastStatusChangeAt");
            writer.write(*obj.getLastStatusChangeAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const AlarmEvent& obj)
    {
        writer.writeObjectStart();
        if (obj.getEventId())
        {
            writer.writePropertyName("eventId");
            writer.write(*obj.getEventId());
        }
        if (obj.getAlarmId())
        {
            writer.writePropertyName("alarmId");
            writer.write(*obj.getAlarmId());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.write(*obj.getType());
        }
        if (obj.getEventAt())
        {
            writer.writePropertyName("eventAt");
            writer.write(*obj.getEventAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Metric& obj)
    {
        writer.writeObjectStart();
        if (obj.getTimestamp())
        {
            writer.writePropertyName("timestamp");
            writer.write(*obj.getTimestamp());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*obj.getValue());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2WatchClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2WatchClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2WatchClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * アラームを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createAlarm(std::function<void(AsyncCreateAlarmResult&)> callback, CreateAlarmRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateAlarmResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/alarm");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getService())
        {
            writer.writePropertyName("service");
            writer.write(*request.getService());
        }
        if (request.getOperation())
        {
            writer.writePropertyName("operation");
            writer.write(*request.getOperation());
        }
        if (request.getExpression())
        {
            writer.writePropertyName("expression");
            writer.write(*request.getExpression());
        }
        if (request.getThreshold())
        {
            writer.writePropertyName("threshold");
            writer.write(*request.getThreshold());
        }
        if (request.getNotificationId())
        {
            writer.writePropertyName("notificationId");
            writer.write(*request.getNotificationId());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getServiceId())
        {
            writer.writePropertyName("serviceId");
            writer.write(*request.getServiceId());
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
     * アラームを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAlarm(std::function<void(AsyncDeleteAlarmResult&)> callback, DeleteAlarmRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/alarm/").append(detail::StringUtil::toStr(buffer, request.getAlarmName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * アラームの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAlarm(std::function<void(AsyncDescribeAlarmResult&)> callback, DescribeAlarmRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeAlarmResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/alarm");
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
     * アラームイベントの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAlarmEvent(std::function<void(AsyncDescribeAlarmEventResult&)> callback, DescribeAlarmEventRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeAlarmEventResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/alarm/").append(detail::StringUtil::toStr(buffer, request.getAlarmName())).append("/event");
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
     * アラームを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAlarm(std::function<void(AsyncGetAlarmResult&)> callback, GetAlarmRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetAlarmResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/alarm/").append(detail::StringUtil::toStr(buffer, request.getAlarmName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * アラームを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateAlarm(std::function<void(AsyncUpdateAlarmResult&)> callback, UpdateAlarmRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateAlarmResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/alarm/").append(detail::StringUtil::toStr(buffer, request.getAlarmName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getExpression())
        {
            writer.writePropertyName("expression");
            writer.write(*request.getExpression());
        }
        if (request.getThreshold())
        {
            writer.writePropertyName("threshold");
            writer.write(*request.getThreshold());
        }
        if (request.getNotificationId())
        {
            writer.writePropertyName("notificationId");
            writer.write(*request.getNotificationId());
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
     * 操作の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeOperation(std::function<void(AsyncDescribeOperationResult&)> callback, DescribeOperationRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeOperationResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/service/").append(detail::StringUtil::toStr(buffer, request.getService())).append("/operation");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * サービスの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeService(std::function<void(AsyncDescribeServiceResult&)> callback, DescribeServiceRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeServiceResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/service");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * メトリックを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMetric(std::function<void(AsyncGetMetricResult&)> callback, GetMetricRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMetricResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/metric/").append(detail::StringUtil::toStr(buffer, request.getServiceId())).append("/").append(detail::StringUtil::toStr(buffer, request.getOperation())).append("");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getBegin()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getBegin()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("begin={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getEnd()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEnd()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("end={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getAllowLongTerm()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getAllowLongTerm()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("allowLongTerm={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_WATCH_GS2WATCHCLIENT_HPP_