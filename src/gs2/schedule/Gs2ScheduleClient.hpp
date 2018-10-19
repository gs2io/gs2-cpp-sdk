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

#ifndef GS2_SCHEDULE_GS2SCHEDULECLIENT_HPP_
#define GS2_SCHEDULE_GS2SCHEDULECLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace schedule {

typedef AsyncResult<GetCurrentEventMasterResult> AsyncGetCurrentEventMasterResult;
typedef AsyncResult<UpdateCurrentEventMasterResult> AsyncUpdateCurrentEventMasterResult;
typedef AsyncResult<CreateEventMasterResult> AsyncCreateEventMasterResult;
typedef AsyncResult<void> AsyncDeleteEventMasterResult;
typedef AsyncResult<DescribeEventMasterResult> AsyncDescribeEventMasterResult;
typedef AsyncResult<GetEventMasterResult> AsyncGetEventMasterResult;
typedef AsyncResult<UpdateEventMasterResult> AsyncUpdateEventMasterResult;
typedef AsyncResult<DescribeEventResult> AsyncDescribeEventResult;
typedef AsyncResult<DescribeEventByUserIdResult> AsyncDescribeEventByUserIdResult;
typedef AsyncResult<GetEventResult> AsyncGetEventResult;
typedef AsyncResult<GetEventByUserIdResult> AsyncGetEventByUserIdResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<CreateScheduleResult> AsyncCreateScheduleResult;
typedef AsyncResult<void> AsyncDeleteScheduleResult;
typedef AsyncResult<DescribeScheduleResult> AsyncDescribeScheduleResult;
typedef AsyncResult<GetScheduleResult> AsyncGetScheduleResult;
typedef AsyncResult<GetScheduleStatusResult> AsyncGetScheduleStatusResult;
typedef AsyncResult<UpdateScheduleResult> AsyncUpdateScheduleResult;
typedef AsyncResult<void> AsyncDeleteTriggerResult;
typedef AsyncResult<DescribeTriggerResult> AsyncDescribeTriggerResult;
typedef AsyncResult<DescribeTriggerByUserIdResult> AsyncDescribeTriggerByUserIdResult;
typedef AsyncResult<GetTriggerResult> AsyncGetTriggerResult;
typedef AsyncResult<PullTriggerResult> AsyncPullTriggerResult;

class Gs2ScheduleClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "schedule";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Schedule& obj)
    {
        writer.writeObjectStart();
        if (obj.getScheduleId())
        {
            writer.writePropertyName("scheduleId");
            writer.write(*obj.getScheduleId());
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

    void write(detail::json::JsonWriter& writer, const EventMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getEventMasterId())
        {
            writer.writePropertyName("eventMasterId");
            writer.write(*obj.getEventMasterId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.write(*obj.getType());
        }
        if (obj.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.write(*obj.getAbsoluteBegin());
        }
        if (obj.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.write(*obj.getAbsoluteEnd());
        }
        if (obj.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.write(*obj.getRelativeTriggerName());
        }
        if (obj.getRelativeSpan())
        {
            writer.writePropertyName("relativeSpan");
            writer.write(*obj.getRelativeSpan());
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

    void write(detail::json::JsonWriter& writer, const Trigger& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getTriggerName())
        {
            writer.writePropertyName("triggerName");
            writer.write(*obj.getTriggerName());
        }
        if (obj.getTriggerAt())
        {
            writer.writePropertyName("triggerAt");
            writer.write(*obj.getTriggerAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Event& obj)
    {
        writer.writeObjectStart();
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getBegin())
        {
            writer.writePropertyName("begin");
            writer.write(*obj.getBegin());
        }
        if (obj.getEnd())
        {
            writer.writePropertyName("end");
            writer.write(*obj.getEnd());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2ScheduleClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ScheduleClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ScheduleClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * 現在適用されているイベントマスターを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentEventMaster(std::function<void(AsyncGetCurrentEventMasterResult&)> callback, GetCurrentEventMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCurrentEventMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/event/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * イベントマスターを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEventMaster(std::function<void(AsyncUpdateCurrentEventMasterResult&)> callback, UpdateCurrentEventMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCurrentEventMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/event/master");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSettings())
        {
            writer.writePropertyName("settings");
            writer.write(*request.getSettings());
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
     * イベントマスターを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createEventMaster(std::function<void(AsyncCreateEventMasterResult&)> callback, CreateEventMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateEventMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/master/event");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getType())
        {
            writer.writePropertyName("type");
            writer.write(*request.getType());
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.write(*request.getAbsoluteBegin());
        }
        if (request.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.write(*request.getAbsoluteEnd());
        }
        if (request.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.write(*request.getRelativeTriggerName());
        }
        if (request.getRelativeSpan())
        {
            writer.writePropertyName("relativeSpan");
            writer.write(*request.getRelativeSpan());
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
     * イベントマスターを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteEventMaster(std::function<void(AsyncDeleteEventMasterResult&)> callback, DeleteEventMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/master/event/").append(detail::StringUtil::toStr(buffer, request.getEventName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * イベントマスターの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEventMaster(std::function<void(AsyncDescribeEventMasterResult&)> callback, DescribeEventMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeEventMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/master/event");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
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
     * イベントマスターを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEventMaster(std::function<void(AsyncGetEventMasterResult&)> callback, GetEventMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetEventMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/master/event/").append(detail::StringUtil::toStr(buffer, request.getEventName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * イベントマスターを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateEventMaster(std::function<void(AsyncUpdateEventMasterResult&)> callback, UpdateEventMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateEventMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/master/event/").append(detail::StringUtil::toStr(buffer, request.getEventName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getType())
        {
            writer.writePropertyName("type");
            writer.write(*request.getType());
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.write(*request.getAbsoluteBegin());
        }
        if (request.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.write(*request.getAbsoluteEnd());
        }
        if (request.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.write(*request.getRelativeTriggerName());
        }
        if (request.getRelativeSpan())
        {
            writer.writePropertyName("relativeSpan");
            writer.write(*request.getRelativeSpan());
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
     * 開催中のイベントの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEvent(std::function<void(AsyncDescribeEventResult&)> callback, DescribeEventRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeEventResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/event");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getEventNames()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEventNames()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("eventNames={value}").replace("{value}", encodeBuffer) + "&";
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
     * 開催中のイベントの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEventByUserId(std::function<void(AsyncDescribeEventByUserIdResult&)> callback, DescribeEventByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeEventByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/event/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getEventNames()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEventNames()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("eventNames={value}").replace("{value}", encodeBuffer) + "&";
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
     * 開催中のイベントを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEvent(std::function<void(AsyncGetEventResult&)> callback, GetEventRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetEventResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/event/").append(detail::StringUtil::toStr(buffer, request.getEventName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 開催中のイベントを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEventByUserId(std::function<void(AsyncGetEventByUserIdResult&)> callback, GetEventByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetEventByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/event/").append(detail::StringUtil::toStr(buffer, request.getEventName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * イベントマスターをエクスポートします<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ExportMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スケジュールを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSchedule(std::function<void(AsyncCreateScheduleResult&)> callback, CreateScheduleRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateScheduleResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule");
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
     * スケジュールを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSchedule(std::function<void(AsyncDeleteScheduleResult&)> callback, DeleteScheduleRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スケジュールの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSchedule(std::function<void(AsyncDescribeScheduleResult&)> callback, DescribeScheduleRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeScheduleResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
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
     * スケジュールを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSchedule(std::function<void(AsyncGetScheduleResult&)> callback, GetScheduleRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetScheduleResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スケジュールの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getScheduleStatus(std::function<void(AsyncGetScheduleStatusResult&)> callback, GetScheduleStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetScheduleStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スケジュールを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSchedule(std::function<void(AsyncUpdateScheduleResult&)> callback, UpdateScheduleRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateScheduleResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("");
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
     * トリガーを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTrigger(std::function<void(AsyncDeleteTriggerResult&)> callback, DeleteTriggerRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/trigger/").append(detail::StringUtil::toStr(buffer, request.getTriggerName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * トリガーの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTrigger(std::function<void(AsyncDescribeTriggerResult&)> callback, DescribeTriggerRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeTriggerResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/trigger");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
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
     * ユーザのトリガーの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTriggerByUserId(std::function<void(AsyncDescribeTriggerByUserIdResult&)> callback, DescribeTriggerByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeTriggerByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/trigger");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
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
     * トリガーを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTrigger(std::function<void(AsyncGetTriggerResult&)> callback, GetTriggerRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetTriggerResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/trigger/").append(detail::StringUtil::toStr(buffer, request.getTriggerName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * トリガーを引きます<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void pullTrigger(std::function<void(AsyncPullTriggerResult&)> callback, PullTriggerRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<PullTriggerResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/schedule/").append(detail::StringUtil::toStr(buffer, request.getScheduleName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/trigger/").append(detail::StringUtil::toStr(buffer, request.getTriggerName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getAction())
        {
            writer.writePropertyName("action");
            writer.write(*request.getAction());
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

#endif //GS2_SCHEDULE_GS2SCHEDULECLIENT_HPP_