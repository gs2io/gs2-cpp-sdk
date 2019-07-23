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

#ifndef GS2_DISTRIBUTOR_GS2DISTRIBUTORRESTCLIENT_HPP_
#define GS2_DISTRIBUTOR_GS2DISTRIBUTORRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
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
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
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
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace distributor {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
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

/**
 * GS2 Distributor API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DistributorRestClient : public AbstractGs2ClientBase
{
private:
    static void write(detail::json::JsonWriter& writer, const Namespace& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceId())
        {
            writer.writePropertyName("namespaceId");
            writer.writeCharArray(*obj.getNamespaceId());
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
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const DistributorModelMaster& obj)
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
        if (obj.getInboxNamespaceId())
        {
            writer.writePropertyName("inboxNamespaceId");
            writer.writeCharArray(*obj.getInboxNamespaceId());
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
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const DistributorModel& obj)
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
        if (obj.getInboxNamespaceId())
        {
            writer.writePropertyName("inboxNamespaceId");
            writer.writeCharArray(*obj.getInboxNamespaceId());
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

    static void write(detail::json::JsonWriter& writer, const CurrentDistributorMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceName())
        {
            writer.writePropertyName("namespaceName");
            writer.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
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

    static void write(detail::json::JsonWriter& writer, const DistributeResource& obj)
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
    explicit Gs2DistributorRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(std::function<void(AsyncDescribeNamespacesResult&)> callback, DescribeNamespacesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeNamespacesResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(std::function<void(AsyncCreateNamespaceResult&)> callback, CreateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateNamespaceResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースの状態を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(std::function<void(AsyncGetNamespaceStatusResult&)> callback, GetNamespaceStatusRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceStatusResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(std::function<void(AsyncGetNamespaceResult&)> callback, GetNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(std::function<void(AsyncUpdateNamespaceResult&)> callback, UpdateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateNamespaceResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(std::function<void(AsyncDeleteNamespaceResult&)> callback, DeleteNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteNamespaceResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 配信設定マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDistributorModelMasters(std::function<void(AsyncDescribeDistributorModelMastersResult&)> callback, DescribeDistributorModelMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeDistributorModelMastersResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/distributor";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 配信設定マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createDistributorModelMaster(std::function<void(AsyncCreateDistributorModelMasterResult&)> callback, CreateDistributorModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateDistributorModelMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/distributor";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
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
        if (request.getInboxNamespaceId())
        {
            writer.writePropertyName("inboxNamespaceId");
            writer.writeCharArray(*request.getInboxNamespaceId());
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 配信設定マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDistributorModelMaster(std::function<void(AsyncGetDistributorModelMasterResult&)> callback, GetDistributorModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetDistributorModelMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/distributor/{distributorName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getDistributorName();
            url.replace("{distributorName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 配信設定マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateDistributorModelMaster(std::function<void(AsyncUpdateDistributorModelMasterResult&)> callback, UpdateDistributorModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateDistributorModelMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/distributor/{distributorName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getDistributorName();
            url.replace("{distributorName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
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
        if (request.getInboxNamespaceId())
        {
            writer.writePropertyName("inboxNamespaceId");
            writer.writeCharArray(*request.getInboxNamespaceId());
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 配信設定マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDistributorModelMaster(std::function<void(AsyncDeleteDistributorModelMasterResult&)> callback, DeleteDistributorModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteDistributorModelMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/distributor/{distributorName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getDistributorName();
            url.replace("{distributorName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 配信設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDistributorModels(std::function<void(AsyncDescribeDistributorModelsResult&)> callback, DescribeDistributorModelsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeDistributorModelsResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/distributor";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 配信設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDistributorModel(std::function<void(AsyncGetDistributorModelResult&)> callback, GetDistributorModelRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetDistributorModelResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/distributor/{distributorName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getDistributorName();
            url.replace("{distributorName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な配信設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ExportMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/export";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な現在有効な配信設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentDistributorMaster(std::function<void(AsyncGetCurrentDistributorMasterResult&)> callback, GetCurrentDistributorMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetCurrentDistributorMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());

        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な現在有効な配信設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentDistributorMaster(std::function<void(AsyncUpdateCurrentDistributorMasterResult&)> callback, UpdateCurrentDistributorMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentDistributorMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "distributor");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setUrl(url.c_str());
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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestData(body, bodySize);

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
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_DISTRIBUTOR_GS2DISTRIBUTORRESTCLIENT_HPP_