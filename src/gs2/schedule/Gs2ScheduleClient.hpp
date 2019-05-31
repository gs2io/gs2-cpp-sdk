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

#ifndef GS2_SCHEDULE_GS2SCHEDULECLIENT_HPP_
#define GS2_SCHEDULE_GS2SCHEDULECLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeSchedulesRequest.hpp"
#include "request/CreateScheduleRequest.hpp"
#include "request/GetScheduleStatusRequest.hpp"
#include "request/GetScheduleRequest.hpp"
#include "request/UpdateScheduleRequest.hpp"
#include "request/DeleteScheduleRequest.hpp"
#include "request/DescribeEventMastersRequest.hpp"
#include "request/CreateEventMasterRequest.hpp"
#include "request/GetEventMasterRequest.hpp"
#include "request/UpdateEventMasterRequest.hpp"
#include "request/DeleteEventMasterRequest.hpp"
#include "request/DescribeTriggersRequest.hpp"
#include "request/DescribeTriggersByUserIdRequest.hpp"
#include "request/GetTriggerRequest.hpp"
#include "request/GetTriggerByUserIdRequest.hpp"
#include "request/TriggerByUserIdRequest.hpp"
#include "request/DeleteTriggerRequest.hpp"
#include "request/DeleteTriggerByUserIdRequest.hpp"
#include "request/DescribeEventsRequest.hpp"
#include "request/GetEventRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentEventMasterRequest.hpp"
#include "request/UpdateCurrentEventMasterRequest.hpp"
#include "result/DescribeSchedulesResult.hpp"
#include "result/CreateScheduleResult.hpp"
#include "result/GetScheduleStatusResult.hpp"
#include "result/GetScheduleResult.hpp"
#include "result/UpdateScheduleResult.hpp"
#include "result/DeleteScheduleResult.hpp"
#include "result/DescribeEventMastersResult.hpp"
#include "result/CreateEventMasterResult.hpp"
#include "result/GetEventMasterResult.hpp"
#include "result/UpdateEventMasterResult.hpp"
#include "result/DeleteEventMasterResult.hpp"
#include "result/DescribeTriggersResult.hpp"
#include "result/DescribeTriggersByUserIdResult.hpp"
#include "result/GetTriggerResult.hpp"
#include "result/GetTriggerByUserIdResult.hpp"
#include "result/TriggerByUserIdResult.hpp"
#include "result/DeleteTriggerResult.hpp"
#include "result/DeleteTriggerByUserIdResult.hpp"
#include "result/DescribeEventsResult.hpp"
#include "result/GetEventResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentEventMasterResult.hpp"
#include "result/UpdateCurrentEventMasterResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace schedule {

typedef AsyncResult<DescribeSchedulesResult> AsyncDescribeSchedulesResult;
typedef AsyncResult<CreateScheduleResult> AsyncCreateScheduleResult;
typedef AsyncResult<GetScheduleStatusResult> AsyncGetScheduleStatusResult;
typedef AsyncResult<GetScheduleResult> AsyncGetScheduleResult;
typedef AsyncResult<UpdateScheduleResult> AsyncUpdateScheduleResult;
typedef AsyncResult<DeleteScheduleResult> AsyncDeleteScheduleResult;
typedef AsyncResult<DescribeEventMastersResult> AsyncDescribeEventMastersResult;
typedef AsyncResult<CreateEventMasterResult> AsyncCreateEventMasterResult;
typedef AsyncResult<GetEventMasterResult> AsyncGetEventMasterResult;
typedef AsyncResult<UpdateEventMasterResult> AsyncUpdateEventMasterResult;
typedef AsyncResult<DeleteEventMasterResult> AsyncDeleteEventMasterResult;
typedef AsyncResult<DescribeTriggersResult> AsyncDescribeTriggersResult;
typedef AsyncResult<DescribeTriggersByUserIdResult> AsyncDescribeTriggersByUserIdResult;
typedef AsyncResult<GetTriggerResult> AsyncGetTriggerResult;
typedef AsyncResult<GetTriggerByUserIdResult> AsyncGetTriggerByUserIdResult;
typedef AsyncResult<TriggerByUserIdResult> AsyncTriggerByUserIdResult;
typedef AsyncResult<DeleteTriggerResult> AsyncDeleteTriggerResult;
typedef AsyncResult<DeleteTriggerByUserIdResult> AsyncDeleteTriggerByUserIdResult;
typedef AsyncResult<DescribeEventsResult> AsyncDescribeEventsResult;
typedef AsyncResult<GetEventResult> AsyncGetEventResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentEventMasterResult> AsyncGetCurrentEventMasterResult;
typedef AsyncResult<UpdateCurrentEventMasterResult> AsyncUpdateCurrentEventMasterResult;

/**
 * GS2 Schedule API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
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
            writer.writeCharArray(*obj.getScheduleId());
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
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.writeInt64(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const EventMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getEventId())
        {
            writer.writePropertyName("eventId");
            writer.writeCharArray(*obj.getEventId());
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
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*obj.getScheduleType());
        }
        if (obj.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*obj.getAbsoluteBegin());
        }
        if (obj.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*obj.getAbsoluteEnd());
        }
        if (obj.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*obj.getRelativeTriggerName());
        }
        if (obj.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*obj.getRelativeDuration());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.writeInt64(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Trigger& obj)
    {
        writer.writeObjectStart();
        if (obj.getTriggerId())
        {
            writer.writePropertyName("triggerId");
            writer.writeCharArray(*obj.getTriggerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.writeInt64(*obj.getExpiresAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Event& obj)
    {
        writer.writeObjectStart();
        if (obj.getEventId())
        {
            writer.writePropertyName("eventId");
            writer.writeCharArray(*obj.getEventId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*obj.getScheduleType());
        }
        if (obj.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*obj.getAbsoluteBegin());
        }
        if (obj.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*obj.getAbsoluteEnd());
        }
        if (obj.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*obj.getRelativeTriggerName());
        }
        if (obj.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*obj.getRelativeDuration());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const CurrentEventMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getScheduleName())
        {
            writer.writePropertyName("scheduleName");
            writer.writeCharArray(*obj.getScheduleName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
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
	 * スケジュールの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSchedules(std::function<void(AsyncDescribeSchedulesResult&)> callback, DescribeSchedulesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeSchedulesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FScheduleFunctionHandler.describeSchedules");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * スケジュールを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSchedule(std::function<void(AsyncCreateScheduleResult&)> callback, CreateScheduleRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateScheduleResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FScheduleFunctionHandler.createSchedule");
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * スケジュールを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getScheduleStatus(std::function<void(AsyncGetScheduleStatusResult&)> callback, GetScheduleStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetScheduleStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FScheduleFunctionHandler.getScheduleStatus");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * スケジュールを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSchedule(std::function<void(AsyncGetScheduleResult&)> callback, GetScheduleRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetScheduleResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FScheduleFunctionHandler.getSchedule");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * スケジュールを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSchedule(std::function<void(AsyncUpdateScheduleResult&)> callback, UpdateScheduleRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateScheduleResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FScheduleFunctionHandler.updateSchedule");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * スケジュールを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSchedule(std::function<void(AsyncDeleteScheduleResult&)> callback, DeleteScheduleRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteScheduleResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FScheduleFunctionHandler.deleteSchedule");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * イベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEventMasters(std::function<void(AsyncDescribeEventMastersResult&)> callback, DescribeEventMastersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeEventMastersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FEventMasterFunctionHandler.describeEventMasters");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * イベントを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createEventMaster(std::function<void(AsyncCreateEventMasterResult&)> callback, CreateEventMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateEventMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FEventMasterFunctionHandler.createEventMaster");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
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
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*request.getScheduleType());
        }
        if (request.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*request.getAbsoluteBegin());
        }
        if (request.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*request.getAbsoluteEnd());
        }
        if (request.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*request.getRelativeTriggerName());
        }
        if (request.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*request.getRelativeDuration());
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * イベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEventMaster(std::function<void(AsyncGetEventMasterResult&)> callback, GetEventMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetEventMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FEventMasterFunctionHandler.getEventMaster");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getEventName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEventName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("eventName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * イベントを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateEventMaster(std::function<void(AsyncUpdateEventMasterResult&)> callback, UpdateEventMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateEventMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FEventMasterFunctionHandler.updateEventMaster");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getEventName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEventName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("eventName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*request.getScheduleType());
        }
        if (request.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*request.getAbsoluteBegin());
        }
        if (request.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*request.getAbsoluteEnd());
        }
        if (request.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*request.getRelativeTriggerName());
        }
        if (request.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*request.getRelativeDuration());
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * イベントを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteEventMaster(std::function<void(AsyncDeleteEventMasterResult&)> callback, DeleteEventMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteEventMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FEventMasterFunctionHandler.deleteEventMaster");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getEventName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEventName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("eventName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * トリガーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTriggers(std::function<void(AsyncDescribeTriggersResult&)> callback, DescribeTriggersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeTriggersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FTriggerFunctionHandler.describeTriggers");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * トリガーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTriggersByUserId(std::function<void(AsyncDescribeTriggersByUserIdResult&)> callback, DescribeTriggersByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeTriggersByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FTriggerFunctionHandler.describeTriggersByUserId");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * トリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTrigger(std::function<void(AsyncGetTriggerResult&)> callback, GetTriggerRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetTriggerResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FTriggerFunctionHandler.getTrigger");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getTriggerName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getTriggerName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("triggerName={value}").replace("{value}", encodeBuffer);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * トリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTriggerByUserId(std::function<void(AsyncGetTriggerByUserIdResult&)> callback, GetTriggerByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetTriggerByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FTriggerFunctionHandler.getTriggerByUserId");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getTriggerName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getTriggerName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("triggerName={value}").replace("{value}", encodeBuffer);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザIDを指定してトリガーを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void triggerByUserId(std::function<void(AsyncTriggerByUserIdResult&)> callback, TriggerByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<TriggerByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FTriggerFunctionHandler.triggerByUserId");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getTriggerName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getTriggerName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("triggerName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getTriggerStrategy())
        {
            writer.writePropertyName("triggerStrategy");
            writer.writeCharArray(*request.getTriggerStrategy());
        }
        if (request.getTtl())
        {
            writer.writePropertyName("ttl");
            writer.writeInt32(*request.getTtl());
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * トリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTrigger(std::function<void(AsyncDeleteTriggerResult&)> callback, DeleteTriggerRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteTriggerResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FTriggerFunctionHandler.deleteTrigger");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getTriggerName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getTriggerName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("triggerName={value}").replace("{value}", encodeBuffer);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * トリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTriggerByUserId(std::function<void(AsyncDeleteTriggerByUserIdResult&)> callback, DeleteTriggerByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteTriggerByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FTriggerFunctionHandler.deleteTriggerByUserId");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getTriggerName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getTriggerName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("triggerName={value}").replace("{value}", encodeBuffer);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * イベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEvents(std::function<void(AsyncDescribeEventsResult&)> callback, DescribeEventsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeEventsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FEventFunctionHandler.describeEvents");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * イベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEvent(std::function<void(AsyncGetEventResult&)> callback, GetEventRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetEventResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FEventFunctionHandler.getEvent");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getEventName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEventName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("eventName={value}").replace("{value}", encodeBuffer);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * イベントマスターJSONのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ExportMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FCurrentEventMasterFunctionHandler.exportMaster");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 現在有効なイベントマスターJSONを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentEventMaster(std::function<void(AsyncGetCurrentEventMasterResult&)> callback, GetCurrentEventMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetCurrentEventMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FCurrentEventMasterFunctionHandler.getCurrentEventMaster");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 現在有効なイベントマスターJSONを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEventMaster(std::function<void(AsyncUpdateCurrentEventMasterResult&)> callback, UpdateCurrentEventMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateCurrentEventMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/schedule-handler?handler=gs2_schedule%2Fhandler%2FCurrentEventMasterFunctionHandler.updateCurrentEventMaster");
        Char encodeBuffer[2048];
        if (request.getScheduleName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScheduleName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("scheduleName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*request.getSettings());
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
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_SCHEDULE_GS2SCHEDULECLIENT_HPP_