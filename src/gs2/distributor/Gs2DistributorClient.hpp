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

#ifndef GS2_DISTRIBUTOR_GS2DISTRIBUTORCLIENT_HPP_
#define GS2_DISTRIBUTOR_GS2DISTRIBUTORCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeDistributorsRequest.hpp"
#include "request/CreateDistributorRequest.hpp"
#include "request/GetDistributorStatusRequest.hpp"
#include "request/GetDistributorRequest.hpp"
#include "request/UpdateDistributorRequest.hpp"
#include "request/DeleteDistributorRequest.hpp"
#include "request/DescribeDistributorModelMastersRequest.hpp"
#include "request/CreateDistributorModelMasterRequest.hpp"
#include "request/GetDistributorModelMasterRequest.hpp"
#include "request/UpdateDistributorModelMasterRequest.hpp"
#include "request/DeleteDistributorModelMasterRequest.hpp"
#include "request/DescribeDistributorModelsRequest.hpp"
#include "request/GetDistributorModelRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentDistributorMasterRequest.hpp"
#include "request/UpdateCurrentDistributorMasterRequest.hpp"
#include "request/DistributeRequest.hpp"
#include "request/DistributeByUserIdRequest.hpp"
#include "request/RunStampTaskRequest.hpp"
#include "request/RunStampSheetRequest.hpp"
#include "result/DescribeDistributorsResult.hpp"
#include "result/CreateDistributorResult.hpp"
#include "result/GetDistributorStatusResult.hpp"
#include "result/GetDistributorResult.hpp"
#include "result/UpdateDistributorResult.hpp"
#include "result/DeleteDistributorResult.hpp"
#include "result/DescribeDistributorModelMastersResult.hpp"
#include "result/CreateDistributorModelMasterResult.hpp"
#include "result/GetDistributorModelMasterResult.hpp"
#include "result/UpdateDistributorModelMasterResult.hpp"
#include "result/DeleteDistributorModelMasterResult.hpp"
#include "result/DescribeDistributorModelsResult.hpp"
#include "result/GetDistributorModelResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentDistributorMasterResult.hpp"
#include "result/UpdateCurrentDistributorMasterResult.hpp"
#include "result/DistributeResult.hpp"
#include "result/DistributeByUserIdResult.hpp"
#include "result/RunStampTaskResult.hpp"
#include "result/RunStampSheetResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace distributor {

typedef AsyncResult<DescribeDistributorsResult> AsyncDescribeDistributorsResult;
typedef AsyncResult<CreateDistributorResult> AsyncCreateDistributorResult;
typedef AsyncResult<GetDistributorStatusResult> AsyncGetDistributorStatusResult;
typedef AsyncResult<GetDistributorResult> AsyncGetDistributorResult;
typedef AsyncResult<UpdateDistributorResult> AsyncUpdateDistributorResult;
typedef AsyncResult<DeleteDistributorResult> AsyncDeleteDistributorResult;
typedef AsyncResult<DescribeDistributorModelMastersResult> AsyncDescribeDistributorModelMastersResult;
typedef AsyncResult<CreateDistributorModelMasterResult> AsyncCreateDistributorModelMasterResult;
typedef AsyncResult<GetDistributorModelMasterResult> AsyncGetDistributorModelMasterResult;
typedef AsyncResult<UpdateDistributorModelMasterResult> AsyncUpdateDistributorModelMasterResult;
typedef AsyncResult<DeleteDistributorModelMasterResult> AsyncDeleteDistributorModelMasterResult;
typedef AsyncResult<DescribeDistributorModelsResult> AsyncDescribeDistributorModelsResult;
typedef AsyncResult<GetDistributorModelResult> AsyncGetDistributorModelResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentDistributorMasterResult> AsyncGetCurrentDistributorMasterResult;
typedef AsyncResult<UpdateCurrentDistributorMasterResult> AsyncUpdateCurrentDistributorMasterResult;
typedef AsyncResult<DistributeResult> AsyncDistributeResult;
typedef AsyncResult<DistributeByUserIdResult> AsyncDistributeByUserIdResult;
typedef AsyncResult<RunStampTaskResult> AsyncRunStampTaskResult;
typedef AsyncResult<RunStampSheetResult> AsyncRunStampSheetResult;

/**
 * GS2 Distributor API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DistributorClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "distributor";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const Distributor& obj)
    {
        writer.writeObjectStart();
        if (obj.getDistributorId())
        {
            writer.writePropertyName("distributorId");
            writer.writeCharArray(*obj.getDistributorId());
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

    void write(detail::json::JsonWriter& writer, const DistributorModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getDistributorModelId())
        {
            writer.writePropertyName("distributorModelId");
            writer.writeCharArray(*obj.getDistributorModelId());
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
        if (obj.getAssumeUserId())
        {
            writer.writePropertyName("assumeUserId");
            writer.writeCharArray(*obj.getAssumeUserId());
        }
        if (obj.getInboxId())
        {
            writer.writePropertyName("inboxId");
            writer.writeCharArray(*obj.getInboxId());
        }
        if (obj.getWhiteListTargetIds())
        {
            writer.writePropertyName("whiteListTargetIds");
            writer.writeArrayStart();
            auto& list = *obj.getWhiteListTargetIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
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

    void write(detail::json::JsonWriter& writer, const DistributorModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getDistributorModelId())
        {
            writer.writePropertyName("distributorModelId");
            writer.writeCharArray(*obj.getDistributorModelId());
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
        if (obj.getAssumeUserId())
        {
            writer.writePropertyName("assumeUserId");
            writer.writeCharArray(*obj.getAssumeUserId());
        }
        if (obj.getInboxId())
        {
            writer.writePropertyName("inboxId");
            writer.writeCharArray(*obj.getInboxId());
        }
        if (obj.getWhiteListTargetIds())
        {
            writer.writePropertyName("whiteListTargetIds");
            writer.writeArrayStart();
            auto& list = *obj.getWhiteListTargetIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const CurrentDistributorMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getDistributorName())
        {
            writer.writePropertyName("distributorName");
            writer.writeCharArray(*obj.getDistributorName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Distribute& obj)
    {
        writer.writeObjectStart();
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

    void write(detail::json::JsonWriter& writer, const DistributeResource& obj)
    {
        writer.writeObjectStart();
        if (obj.getAction())
        {
            writer.writePropertyName("action");
            writer.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    Gs2DistributorClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
	 * @param region アクセス先リージョン
     */
    Gs2DistributorClient(Gs2RestSession& gs2RestSession, const Region& region) :
        AbstractGs2ClientBase(gs2RestSession, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
	 * @param region アクセス先リージョン
     */
    Gs2DistributorClient(Gs2RestSession& gs2RestSession, const Char region[]) :
        AbstractGs2ClientBase(gs2RestSession, region)
    {
    }

	/**
	 * ディストリビュータの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDistributors(std::function<void(AsyncDescribeDistributorsResult&)> callback, DescribeDistributorsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeDistributorsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorFunctionHandler.describeDistributors");
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", urlSafeValue);
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createDistributor(std::function<void(AsyncCreateDistributorResult&)> callback, CreateDistributorRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateDistributorResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorFunctionHandler.createDistributor");
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDistributorStatus(std::function<void(AsyncGetDistributorStatusResult&)> callback, GetDistributorStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetDistributorStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorFunctionHandler.getDistributorStatus");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDistributor(std::function<void(AsyncGetDistributorResult&)> callback, GetDistributorRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetDistributorResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorFunctionHandler.getDistributor");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateDistributor(std::function<void(AsyncUpdateDistributorResult&)> callback, UpdateDistributorRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateDistributorResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorFunctionHandler.updateDistributor");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDistributor(std::function<void(AsyncDeleteDistributorResult&)> callback, DeleteDistributorRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteDistributorResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorFunctionHandler.deleteDistributor");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータの種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDistributorModelMasters(std::function<void(AsyncDescribeDistributorModelMastersResult&)> callback, DescribeDistributorModelMastersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeDistributorModelMastersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorModelMasterFunctionHandler.describeDistributorModelMasters");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", urlSafeValue);
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータの種類を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createDistributorModelMaster(std::function<void(AsyncCreateDistributorModelMasterResult&)> callback, CreateDistributorModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateDistributorModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorModelMasterFunctionHandler.createDistributorModelMaster");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
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
        if (request.getAssumeUserId())
        {
            writer.writePropertyName("assumeUserId");
            writer.writeCharArray(*request.getAssumeUserId());
        }
        if (request.getInboxId())
        {
            writer.writePropertyName("inboxId");
            writer.writeCharArray(*request.getInboxId());
        }
        if (request.getWhiteListTargetIds())
        {
            writer.writePropertyName("whiteListTargetIds");
            writer.writeArrayStart();
            auto& list = *request.getWhiteListTargetIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDistributorModelMaster(std::function<void(AsyncGetDistributorModelMasterResult&)> callback, GetDistributorModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetDistributorModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorModelMasterFunctionHandler.getDistributorModelMaster");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getDistributorModelName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorModelName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorModelName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータの種類を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateDistributorModelMaster(std::function<void(AsyncUpdateDistributorModelMasterResult&)> callback, UpdateDistributorModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateDistributorModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorModelMasterFunctionHandler.updateDistributorModelMaster");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getDistributorModelName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorModelName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorModelName={value}").replace("{value}", urlSafeValue);
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
        if (request.getAssumeUserId())
        {
            writer.writePropertyName("assumeUserId");
            writer.writeCharArray(*request.getAssumeUserId());
        }
        if (request.getInboxId())
        {
            writer.writePropertyName("inboxId");
            writer.writeCharArray(*request.getInboxId());
        }
        if (request.getWhiteListTargetIds())
        {
            writer.writePropertyName("whiteListTargetIds");
            writer.writeArrayStart();
            auto& list = *request.getWhiteListTargetIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータの種類を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDistributorModelMaster(std::function<void(AsyncDeleteDistributorModelMasterResult&)> callback, DeleteDistributorModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteDistributorModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorModelMasterFunctionHandler.deleteDistributorModelMaster");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getDistributorModelName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorModelName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorModelName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータの種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDistributorModels(std::function<void(AsyncDescribeDistributorModelsResult&)> callback, DescribeDistributorModelsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeDistributorModelsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorModelFunctionHandler.describeDistributorModels");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビュータの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDistributorModel(std::function<void(AsyncGetDistributorModelResult&)> callback, GetDistributorModelRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetDistributorModelResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributorModelFunctionHandler.getDistributorModel");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getDistributorModelName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorModelName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorModelName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ディストリビューターマスターJSONのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ExportMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FCurrentDistributorMasterFunctionHandler.exportMaster");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 現在有効なディストリビューターマスターJSONを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentDistributorMaster(std::function<void(AsyncGetCurrentDistributorMasterResult&)> callback, GetCurrentDistributorMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetCurrentDistributorMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FCurrentDistributorMasterFunctionHandler.getCurrentDistributorMaster");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 現在有効なディストリビューターマスターJSONを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentDistributorMaster(std::function<void(AsyncUpdateCurrentDistributorMasterResult&)> callback, UpdateCurrentDistributorMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateCurrentDistributorMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FCurrentDistributorMasterFunctionHandler.updateCurrentDistributorMaster");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 所持品を配布する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void distribute(std::function<void(AsyncDistributeResult&)> callback, DistributeRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DistributeResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributeFunctionHandler.distribute");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getDistributorModelName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorModelName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorModelName={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDistributeResource())
        {
            writer.writePropertyName("distributeResource");
            write(writer, *request.getDistributeResource());
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーIDを指定して所持品を配布する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void distributeByUserId(std::function<void(AsyncDistributeByUserIdResult&)> callback, DistributeByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DistributeByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributeFunctionHandler.distributeByUserId");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getDistributorModelName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorModelName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorModelName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDistributeResource())
        {
            writer.writePropertyName("distributeResource");
            write(writer, *request.getDistributeResource());
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 所持品を配布する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void runStampTask(std::function<void(AsyncRunStampTaskResult&)> callback, RunStampTaskRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<RunStampTaskResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributeFunctionHandler.runStampTask");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getDistributorModelName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorModelName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorModelName={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampTask())
        {
            writer.writePropertyName("stampTask");
            writer.writeCharArray(*request.getStampTask());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 所持品を配布する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void runStampSheet(std::function<void(AsyncRunStampSheetResult&)> callback, RunStampSheetRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<RunStampSheetResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/distributor-handler?handler=gs2_distributor%2Fhandler%2FDistributeFunctionHandler.runStampSheet");
        if (request.getDistributorName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getDistributorModelName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getDistributorModelName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("distributorModelName={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.writeCharArray(*request.getStampSheet());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
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
        authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_DISTRIBUTOR_GS2DISTRIBUTORCLIENT_HPP_