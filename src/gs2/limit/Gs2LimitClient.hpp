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

#ifndef GS2_LIMIT_GS2LIMITCLIENT_HPP_
#define GS2_LIMIT_GS2LIMITCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace limit {

typedef AsyncResult<CreateCounterMasterResult> AsyncCreateCounterMasterResult;
typedef AsyncResult<void> AsyncDeleteCounterMasterResult;
typedef AsyncResult<DescribeCounterMasterResult> AsyncDescribeCounterMasterResult;
typedef AsyncResult<GetCounterMasterResult> AsyncGetCounterMasterResult;
typedef AsyncResult<UpdateCounterMasterResult> AsyncUpdateCounterMasterResult;
typedef AsyncResult<void> AsyncDeleteCounterResult;
typedef AsyncResult<DescribeCounterResult> AsyncDescribeCounterResult;
typedef AsyncResult<DescribeCounterByUserIdResult> AsyncDescribeCounterByUserIdResult;
typedef AsyncResult<GetCounterResult> AsyncGetCounterResult;
typedef AsyncResult<GetMyCounterResult> AsyncGetMyCounterResult;
typedef AsyncResult<UpCounterResult> AsyncUpCounterResult;
typedef AsyncResult<UpCounterByStampTaskResult> AsyncUpCounterByStampTaskResult;
typedef AsyncResult<UpMyCounterResult> AsyncUpMyCounterResult;
typedef AsyncResult<GetCurrentCounterMasterResult> AsyncGetCurrentCounterMasterResult;
typedef AsyncResult<UpdateCurrentCounterMasterResult> AsyncUpdateCurrentCounterMasterResult;
typedef AsyncResult<CreateLimitResult> AsyncCreateLimitResult;
typedef AsyncResult<void> AsyncDeleteLimitResult;
typedef AsyncResult<DescribeLimitResult> AsyncDescribeLimitResult;
typedef AsyncResult<GetLimitResult> AsyncGetLimitResult;
typedef AsyncResult<GetLimitStatusResult> AsyncGetLimitStatusResult;
typedef AsyncResult<UpdateLimitResult> AsyncUpdateLimitResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;

class Gs2LimitClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "limit";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Limit& obj)
    {
        writer.writeObjectStart();
        if (obj.getLimitId())
        {
            writer.writePropertyName("limitId");
            writer.write(*obj.getLimitId());
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

    void write(detail::json::JsonWriter& writer, const CounterMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getCounterMasterId())
        {
            writer.writePropertyName("counterMasterId");
            writer.write(*obj.getCounterMasterId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMax())
        {
            writer.writePropertyName("max");
            writer.write(*obj.getMax());
        }
        if (obj.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.write(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.write(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.write(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.write(*obj.getResetHour());
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

    void write(detail::json::JsonWriter& writer, const Counter& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getCounterName())
        {
            writer.writePropertyName("counterName");
            writer.write(*obj.getCounterName());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*obj.getCount());
        }
        if (obj.getLimit())
        {
            writer.writePropertyName("limit");
            writer.write(*obj.getLimit());
        }
        if (obj.getNextResetAt())
        {
            writer.writePropertyName("nextResetAt");
            writer.write(*obj.getNextResetAt());
        }
        if (obj.getCountAt())
        {
            writer.writePropertyName("countAt");
            writer.write(*obj.getCountAt());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2LimitClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2LimitClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2LimitClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * カウンターマスターを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createCounterMaster(std::function<void(AsyncCreateCounterMasterResult&)> callback, CreateCounterMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateCounterMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/master/counter");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getMax())
        {
            writer.writePropertyName("max");
            writer.write(*request.getMax());
        }
        if (request.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.write(*request.getResetType());
        }
        if (request.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.write(*request.getResetDayOfMonth());
        }
        if (request.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.write(*request.getResetDayOfWeek());
        }
        if (request.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.write(*request.getResetHour());
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
     * カウンターマスターを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterMaster(std::function<void(AsyncDeleteCounterMasterResult&)> callback, DeleteCounterMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/master/counter/").append(detail::StringUtil::toStr(buffer, request.getCounterName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * カウンターマスターの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounterMaster(std::function<void(AsyncDescribeCounterMasterResult&)> callback, DescribeCounterMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeCounterMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/master/counter");
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
     * カウンターマスターを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterMaster(std::function<void(AsyncGetCounterMasterResult&)> callback, GetCounterMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCounterMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/master/counter/").append(detail::StringUtil::toStr(buffer, request.getCounterName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * カウンターマスターを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCounterMaster(std::function<void(AsyncUpdateCounterMasterResult&)> callback, UpdateCounterMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCounterMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/master/counter/").append(detail::StringUtil::toStr(buffer, request.getCounterName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getMax())
        {
            writer.writePropertyName("max");
            writer.write(*request.getMax());
        }
        if (request.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.write(*request.getResetType());
        }
        if (request.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.write(*request.getResetDayOfMonth());
        }
        if (request.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.write(*request.getResetDayOfWeek());
        }
        if (request.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.write(*request.getResetHour());
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
     * カウンターを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounter(std::function<void(AsyncDeleteCounterResult&)> callback, DeleteCounterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/counter/").append(detail::StringUtil::toStr(buffer, request.getCounterName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * カウンターの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounter(std::function<void(AsyncDescribeCounterResult&)> callback, DescribeCounterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeCounterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/counter");
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
     * ユーザのカウンターの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounterByUserId(std::function<void(AsyncDescribeCounterByUserIdResult&)> callback, DescribeCounterByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeCounterByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/counter");
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
     * カウンターを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounter(std::function<void(AsyncGetCounterResult&)> callback, GetCounterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCounterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/counter/").append(detail::StringUtil::toStr(buffer, request.getCounterName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * カウンターを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMyCounter(std::function<void(AsyncGetMyCounterResult&)> callback, GetMyCounterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMyCounterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/counter/").append(detail::StringUtil::toStr(buffer, request.getCounterName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * カウンターを進めます<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void upCounter(std::function<void(AsyncUpCounterResult&)> callback, UpCounterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpCounterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/counter/").append(detail::StringUtil::toStr(buffer, request.getCounterName())).append("");
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
     * カウンターを進めます<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void upCounterByStampTask(std::function<void(AsyncUpCounterByStampTaskResult&)> callback, UpCounterByStampTaskRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpCounterByStampTaskResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/counter");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getTask())
        {
            writer.writePropertyName("task");
            writer.write(*request.getTask());
        }
        if (request.getKeyName())
        {
            writer.writePropertyName("keyName");
            writer.write(*request.getKeyName());
        }
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
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
     * カウンターを進めます<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void upMyCounter(std::function<void(AsyncUpMyCounterResult&)> callback, UpMyCounterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpMyCounterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/counter/").append(detail::StringUtil::toStr(buffer, request.getCounterName())).append("");
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
     * 現在適用されている回数制限マスターを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentCounterMaster(std::function<void(AsyncGetCurrentCounterMasterResult&)> callback, GetCurrentCounterMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCurrentCounterMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/counter/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 回数制限マスターをインポートします<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentCounterMaster(std::function<void(AsyncUpdateCurrentCounterMasterResult&)> callback, UpdateCurrentCounterMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCurrentCounterMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/counter/master");
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
     * 回数制限を新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLimit(std::function<void(AsyncCreateLimitResult&)> callback, CreateLimitRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateLimitResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit");
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
     * 回数制限を削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLimit(std::function<void(AsyncDeleteLimitResult&)> callback, DeleteLimitRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 回数制限の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLimit(std::function<void(AsyncDescribeLimitResult&)> callback, DescribeLimitRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeLimitResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit");
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
     * 回数制限を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimit(std::function<void(AsyncGetLimitResult&)> callback, GetLimitRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLimitResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 回数制限の状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimitStatus(std::function<void(AsyncGetLimitStatusResult&)> callback, GetLimitStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLimitStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 回数制限を更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLimit(std::function<void(AsyncUpdateLimitResult&)> callback, UpdateLimitRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateLimitResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("");
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
     * カウンターマスターをエクスポートします<br>
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
            url.append("/limit/").append(detail::StringUtil::toStr(buffer, request.getLimitName())).append("/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_LIMIT_GS2LIMITCLIENT_HPP_