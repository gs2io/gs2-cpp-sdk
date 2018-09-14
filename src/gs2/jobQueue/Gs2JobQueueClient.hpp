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

#ifndef GS2_JOBQUEUE_GS2JOBQUEUECLIENT_HPP_
#define GS2_JOBQUEUE_GS2JOBQUEUECLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace jobQueue {

typedef AsyncResult<void> AsyncDeleteDeadJobResult;
typedef AsyncResult<DescribeDeadJobResult> AsyncDescribeDeadJobResult;
typedef AsyncResult<DescribeDeadJobByScriptNameResult> AsyncDescribeDeadJobByScriptNameResult;
typedef AsyncResult<DescribeDeadJobByUserIdResult> AsyncDescribeDeadJobByUserIdResult;
typedef AsyncResult<GetDeadJobResult> AsyncGetDeadJobResult;
typedef AsyncResult<DescribeJobResultResult> AsyncDescribeJobResultResult;
typedef AsyncResult<DescribeJobResult> AsyncDescribeJobResult;
typedef AsyncResult<DescribeJobByUserIdResult> AsyncDescribeJobByUserIdResult;
typedef AsyncResult<PushResult> AsyncPushResult;
typedef AsyncResult<RunResult> AsyncRunResult;
typedef AsyncResult<RunByUserIdResult> AsyncRunByUserIdResult;
typedef AsyncResult<CreateQueueResult> AsyncCreateQueueResult;
typedef AsyncResult<void> AsyncDeleteQueueResult;
typedef AsyncResult<DescribeQueueResult> AsyncDescribeQueueResult;
typedef AsyncResult<GetQueueResult> AsyncGetQueueResult;
typedef AsyncResult<GetQueueStatusResult> AsyncGetQueueStatusResult;
typedef AsyncResult<UpdateQueueResult> AsyncUpdateQueueResult;

class Gs2JobQueueClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "job-queue";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Queue& obj)
    {
        writer.writeObjectStart();
        if (obj.getQueueId())
        {
            writer.writePropertyName("queueId");
            writer.write(*obj.getQueueId());
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
        if (obj.getNotificationType())
        {
            writer.writePropertyName("notificationType");
            writer.write(*obj.getNotificationType());
        }
        if (obj.getNotificationUrl())
        {
            writer.writePropertyName("notificationUrl");
            writer.write(*obj.getNotificationUrl());
        }
        if (obj.getNotificationGameName())
        {
            writer.writePropertyName("notificationGameName");
            writer.write(*obj.getNotificationGameName());
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

    void write(detail::json::JsonWriter& writer, const Job& obj)
    {
        writer.writeObjectStart();
        if (obj.getJobId())
        {
            writer.writePropertyName("jobId");
            writer.write(*obj.getJobId());
        }
        if (obj.getQueueId())
        {
            writer.writePropertyName("queueId");
            writer.write(*obj.getQueueId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getScriptName())
        {
            writer.writePropertyName("scriptName");
            writer.write(*obj.getScriptName());
        }
        if (obj.getArgs())
        {
            writer.writePropertyName("args");
            writer.write(*obj.getArgs());
        }
        if (obj.getCurrentRetry())
        {
            writer.writePropertyName("currentRetry");
            writer.write(*obj.getCurrentRetry());
        }
        if (obj.getMaxRetry())
        {
            writer.writePropertyName("maxRetry");
            writer.write(*obj.getMaxRetry());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const DeadJob& obj)
    {
        writer.writeObjectStart();
        if (obj.getJobId())
        {
            writer.writePropertyName("jobId");
            writer.write(*obj.getJobId());
        }
        if (obj.getQueueId())
        {
            writer.writePropertyName("queueId");
            writer.write(*obj.getQueueId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getScriptName())
        {
            writer.writePropertyName("scriptName");
            writer.write(*obj.getScriptName());
        }
        if (obj.getArgs())
        {
            writer.writePropertyName("args");
            writer.write(*obj.getArgs());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const JobResult& obj)
    {
        writer.writeObjectStart();
        if (obj.getJobId())
        {
            writer.writePropertyName("jobId");
            writer.write(*obj.getJobId());
        }
        if (obj.getQueueId())
        {
            writer.writePropertyName("queueId");
            writer.write(*obj.getQueueId());
        }
        if (obj.getStatusCode())
        {
            writer.writePropertyName("statusCode");
            writer.write(*obj.getStatusCode());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.write(*obj.getResult());
        }
        if (obj.getEndOfJob())
        {
            writer.writePropertyName("endOfJob");
            writer.write(*obj.getEndOfJob());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const PushJob& obj)
    {
        writer.writeObjectStart();
        if (obj.getScriptName())
        {
            writer.writePropertyName("scriptName");
            writer.write(*obj.getScriptName());
        }
        if (obj.getArgs())
        {
            writer.writePropertyName("args");
            writer.write(*obj.getArgs());
        }
        if (obj.getMaxRetry())
        {
            writer.writePropertyName("maxRetry");
            writer.write(*obj.getMaxRetry());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2JobQueueClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2JobQueueClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2JobQueueClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * デッドジョブを削除します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDeadJob(std::function<void(AsyncDeleteDeadJobResult&)> callback, DeleteDeadJobRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/deadJob/").append(detail::StringUtil::toStr(buffer, request.getJobId())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * デッドジョブの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDeadJob(std::function<void(AsyncDescribeDeadJobResult&)> callback, DescribeDeadJobRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeDeadJobResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/deadJob");
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
     * スクリプト名で絞り込んでデッドジョブの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDeadJobByScriptName(std::function<void(AsyncDescribeDeadJobByScriptNameResult&)> callback, DescribeDeadJobByScriptNameRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeDeadJobByScriptNameResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/deadJob/script/").append(detail::StringUtil::toStr(buffer, request.getScriptName())).append("");
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
     * ユーザIDで絞り込んでデッドジョブの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDeadJobByUserId(std::function<void(AsyncDescribeDeadJobByUserIdResult&)> callback, DescribeDeadJobByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeDeadJobByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/deadJob/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
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
     * デッドジョブを取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDeadJob(std::function<void(AsyncGetDeadJobResult&)> callback, GetDeadJobRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetDeadJobResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/deadJob/").append(detail::StringUtil::toStr(buffer, request.getJobId())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ジョブの実行結果の一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeJobResult(std::function<void(AsyncDescribeJobResultResult&)> callback, DescribeJobResultRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeJobResultResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/deadJob/").append(detail::StringUtil::toStr(buffer, request.getJobId())).append("/result");
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
     * ジョブの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeJob(std::function<void(AsyncDescribeJobResult&)> callback, DescribeJobRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeJobResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/job");
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
     * ジョブの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeJobByUserId(std::function<void(AsyncDescribeJobByUserIdResult&)> callback, DescribeJobByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeJobByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/job/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
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
     * ジョブキューにジョブを登録します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void push(std::function<void(AsyncPushResult&)> callback, PushRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<PushResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/job/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getJobs())
        {
            writer.writePropertyName("jobs");
            writer.writeArrayStart();
            auto& list = *request.getJobs();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
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
     * ジョブキューを実行します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void run(std::function<void(AsyncRunResult&)> callback, RunRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<RunResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
     * ジョブキューを実行します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void runByUserId(std::function<void(AsyncRunByUserIdResult&)> callback, RunByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<RunByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/job/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/run");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
     * ジョブキューを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createQueue(std::function<void(AsyncCreateQueueResult&)> callback, CreateQueueRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateQueueResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue");
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
        if (request.getNotificationType())
        {
            writer.writePropertyName("notificationType");
            writer.write(*request.getNotificationType());
        }
        if (request.getNotificationUrl())
        {
            writer.writePropertyName("notificationUrl");
            writer.write(*request.getNotificationUrl());
        }
        if (request.getNotificationGameName())
        {
            writer.writePropertyName("notificationGameName");
            writer.write(*request.getNotificationGameName());
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
     * ジョブキューを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteQueue(std::function<void(AsyncDeleteQueueResult&)> callback, DeleteQueueRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ジョブキューの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeQueue(std::function<void(AsyncDescribeQueueResult&)> callback, DescribeQueueRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeQueueResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue");
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
     * ジョブキューを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQueue(std::function<void(AsyncGetQueueResult&)> callback, GetQueueRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetQueueResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ジョブキューの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getQueueStatus(std::function<void(AsyncGetQueueStatusResult&)> callback, GetQueueStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetQueueStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ジョブキューを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateQueue(std::function<void(AsyncUpdateQueueResult&)> callback, UpdateQueueRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateQueueResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/queue/").append(detail::StringUtil::toStr(buffer, request.getQueueName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getNotificationType())
        {
            writer.writePropertyName("notificationType");
            writer.write(*request.getNotificationType());
        }
        if (request.getNotificationUrl())
        {
            writer.writePropertyName("notificationUrl");
            writer.write(*request.getNotificationUrl());
        }
        if (request.getNotificationGameName())
        {
            writer.writePropertyName("notificationGameName");
            writer.write(*request.getNotificationGameName());
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

#endif //GS2_JOBQUEUE_GS2JOBQUEUECLIENT_HPP_