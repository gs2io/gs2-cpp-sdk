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

#ifndef GS2_LOTTERY_GS2LOTTERYRESTCLIENT_HPP_
#define GS2_LOTTERY_GS2LOTTERYRESTCLIENT_HPP_

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
#include "request/DescribeLotteryModelMastersRequest.hpp"
#include "request/CreateLotteryModelMasterRequest.hpp"
#include "request/GetLotteryModelMasterRequest.hpp"
#include "request/UpdateLotteryModelMasterRequest.hpp"
#include "request/DeleteLotteryModelMasterRequest.hpp"
#include "request/DescribePrizeTableMastersRequest.hpp"
#include "request/CreatePrizeTableMasterRequest.hpp"
#include "request/GetPrizeTableMasterRequest.hpp"
#include "request/UpdatePrizeTableMasterRequest.hpp"
#include "request/DeletePrizeTableMasterRequest.hpp"
#include "request/DescribeBoxesRequest.hpp"
#include "request/DescribeBoxesByUserIdRequest.hpp"
#include "request/GetBoxRequest.hpp"
#include "request/GetBoxByUserIdRequest.hpp"
#include "request/ResetBoxRequest.hpp"
#include "request/ResetBoxByUserIdRequest.hpp"
#include "request/DescribeLotteryModelsRequest.hpp"
#include "request/GetLotteryModelRequest.hpp"
#include "request/DescribePrizeTablesRequest.hpp"
#include "request/GetPrizeTableRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentLotteryMasterRequest.hpp"
#include "request/UpdateCurrentLotteryMasterRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeLotteryModelMastersResult.hpp"
#include "result/CreateLotteryModelMasterResult.hpp"
#include "result/GetLotteryModelMasterResult.hpp"
#include "result/UpdateLotteryModelMasterResult.hpp"
#include "result/DeleteLotteryModelMasterResult.hpp"
#include "result/DescribePrizeTableMastersResult.hpp"
#include "result/CreatePrizeTableMasterResult.hpp"
#include "result/GetPrizeTableMasterResult.hpp"
#include "result/UpdatePrizeTableMasterResult.hpp"
#include "result/DeletePrizeTableMasterResult.hpp"
#include "result/DescribeBoxesResult.hpp"
#include "result/DescribeBoxesByUserIdResult.hpp"
#include "result/GetBoxResult.hpp"
#include "result/GetBoxByUserIdResult.hpp"
#include "result/ResetBoxResult.hpp"
#include "result/ResetBoxByUserIdResult.hpp"
#include "result/DescribeLotteryModelsResult.hpp"
#include "result/GetLotteryModelResult.hpp"
#include "result/DescribePrizeTablesResult.hpp"
#include "result/GetPrizeTableResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentLotteryMasterResult.hpp"
#include "result/UpdateCurrentLotteryMasterResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace lottery {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeLotteryModelMastersResult> AsyncDescribeLotteryModelMastersResult;
typedef AsyncResult<CreateLotteryModelMasterResult> AsyncCreateLotteryModelMasterResult;
typedef AsyncResult<GetLotteryModelMasterResult> AsyncGetLotteryModelMasterResult;
typedef AsyncResult<UpdateLotteryModelMasterResult> AsyncUpdateLotteryModelMasterResult;
typedef AsyncResult<DeleteLotteryModelMasterResult> AsyncDeleteLotteryModelMasterResult;
typedef AsyncResult<DescribePrizeTableMastersResult> AsyncDescribePrizeTableMastersResult;
typedef AsyncResult<CreatePrizeTableMasterResult> AsyncCreatePrizeTableMasterResult;
typedef AsyncResult<GetPrizeTableMasterResult> AsyncGetPrizeTableMasterResult;
typedef AsyncResult<UpdatePrizeTableMasterResult> AsyncUpdatePrizeTableMasterResult;
typedef AsyncResult<DeletePrizeTableMasterResult> AsyncDeletePrizeTableMasterResult;
typedef AsyncResult<DescribeBoxesResult> AsyncDescribeBoxesResult;
typedef AsyncResult<DescribeBoxesByUserIdResult> AsyncDescribeBoxesByUserIdResult;
typedef AsyncResult<GetBoxResult> AsyncGetBoxResult;
typedef AsyncResult<GetBoxByUserIdResult> AsyncGetBoxByUserIdResult;
typedef AsyncResult<void> AsyncResetBoxResult;
typedef AsyncResult<void> AsyncResetBoxByUserIdResult;
typedef AsyncResult<DescribeLotteryModelsResult> AsyncDescribeLotteryModelsResult;
typedef AsyncResult<GetLotteryModelResult> AsyncGetLotteryModelResult;
typedef AsyncResult<DescribePrizeTablesResult> AsyncDescribePrizeTablesResult;
typedef AsyncResult<GetPrizeTableResult> AsyncGetPrizeTableResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentLotteryMasterResult> AsyncGetCurrentLotteryMasterResult;
typedef AsyncResult<UpdateCurrentLotteryMasterResult> AsyncUpdateCurrentLotteryMasterResult;

/**
 * GS2 Lottery API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LotteryRestClient : public AbstractGs2ClientBase
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
        if (obj.getQueueNamespaceId())
        {
            writer.writePropertyName("queueNamespaceId");
            writer.writeCharArray(*obj.getQueueNamespaceId());
        }
        if (obj.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*obj.getKeyId());
        }
        if (obj.getLotteryTriggerScriptId())
        {
            writer.writePropertyName("lotteryTriggerScriptId");
            writer.writeCharArray(*obj.getLotteryTriggerScriptId());
        }
        if (obj.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.writeCharArray(*obj.getChoicePrizeTableScriptId());
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

    static void write(detail::json::JsonWriter& writer, const LotteryModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getLotteryModelId())
        {
            writer.writePropertyName("lotteryModelId");
            writer.writeCharArray(*obj.getLotteryModelId());
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
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getMode())
        {
            writer.writePropertyName("mode");
            writer.writeCharArray(*obj.getMode());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt32(*obj.getCount());
        }
        if (obj.getMethod())
        {
            writer.writePropertyName("method");
            writer.writeCharArray(*obj.getMethod());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.writeCharArray(*obj.getChoicePrizeTableScriptId());
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

    static void write(detail::json::JsonWriter& writer, const PrizeTableMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getPrizeTableId())
        {
            writer.writePropertyName("prizeTableId");
            writer.writeCharArray(*obj.getPrizeTableId());
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
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getPrizes())
        {
            writer.writePropertyName("prizes");
            writer.writeArrayStart();
            auto& list = *obj.getPrizes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
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

    static void write(detail::json::JsonWriter& writer, const Box& obj)
    {
        writer.writeObjectStart();
        if (obj.getBoxId())
        {
            writer.writePropertyName("boxId");
            writer.writeCharArray(*obj.getBoxId());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getDrawnIndexes())
        {
            writer.writePropertyName("drawnIndexes");
            writer.writeArrayStart();
            auto& list = *obj.getDrawnIndexes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt32(list[i]);
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

    static void write(detail::json::JsonWriter& writer, const LotteryModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getLotteryModelId())
        {
            writer.writePropertyName("lotteryModelId");
            writer.writeCharArray(*obj.getLotteryModelId());
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
        if (obj.getMode())
        {
            writer.writePropertyName("mode");
            writer.writeCharArray(*obj.getMode());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt32(*obj.getCount());
        }
        if (obj.getMethod())
        {
            writer.writePropertyName("method");
            writer.writeCharArray(*obj.getMethod());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.writeCharArray(*obj.getChoicePrizeTableScriptId());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const PrizeTable& obj)
    {
        writer.writeObjectStart();
        if (obj.getPrizeTableId())
        {
            writer.writePropertyName("prizeTableId");
            writer.writeCharArray(*obj.getPrizeTableId());
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
        if (obj.getPrizes())
        {
            writer.writePropertyName("prizes");
            writer.writeArrayStart();
            auto& list = *obj.getPrizes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Probability& obj)
    {
        writer.writeObjectStart();
        if (obj.getPrize())
        {
            writer.writePropertyName("prize");
            write(writer, *obj.getPrize());
        }
        if (obj.getRate())
        {
            writer.writePropertyName("rate");
            writer.writeFloat(*obj.getRate());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentLotteryMaster& obj)
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

    static void write(detail::json::JsonWriter& writer, const Prize& obj)
    {
        writer.writeObjectStart();
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getAcquireActions())
        {
            writer.writePropertyName("acquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getWeight())
        {
            writer.writePropertyName("weight");
            writer.writeInt32(*obj.getWeight());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const AcquireAction& obj)
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

    static void write(detail::json::JsonWriter& writer, const DrawnPrize& obj)
    {
        writer.writeObjectStart();
        if (obj.getAcquireActions())
        {
            writer.writePropertyName("acquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const BoxItem& obj)
    {
        writer.writeObjectStart();
        if (obj.getAcquireActions())
        {
            writer.writePropertyName("acquireActions");
            writer.writeArrayStart();
            auto& list = *obj.getAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getRemaining())
        {
            writer.writePropertyName("remaining");
            writer.writeInt32(*obj.getRemaining());
        }
        if (obj.getInitial())
        {
            writer.writePropertyName("initial");
            writer.writeInt32(*obj.getInitial());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const BoxItems& obj)
    {
        writer.writeObjectStart();
        if (obj.getBoxId())
        {
            writer.writePropertyName("boxId");
            writer.writeCharArray(*obj.getBoxId());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getItems())
        {
            writer.writePropertyName("items");
            writer.writeArrayStart();
            auto& list = *obj.getItems();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Config& obj)
    {
        writer.writeObjectStart();
        if (obj.getKey())
        {
            writer.writePropertyName("key");
            writer.writeCharArray(*obj.getKey());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeCharArray(*obj.getValue());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2LotteryRestClient(Gs2RestSession& gs2RestSession) :
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
        url.replace("{service}", "lottery");
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
        url.replace("{service}", "lottery");
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
        if (request.getQueueNamespaceId())
        {
            writer.writePropertyName("queueNamespaceId");
            writer.writeCharArray(*request.getQueueNamespaceId());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        if (request.getLotteryTriggerScriptId())
        {
            writer.writePropertyName("lotteryTriggerScriptId");
            writer.writeCharArray(*request.getLotteryTriggerScriptId());
        }
        if (request.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.writeCharArray(*request.getChoicePrizeTableScriptId());
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
        url.replace("{service}", "lottery");
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
        url.replace("{service}", "lottery");
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
        url.replace("{service}", "lottery");
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
        if (request.getQueueNamespaceId())
        {
            writer.writePropertyName("queueNamespaceId");
            writer.writeCharArray(*request.getQueueNamespaceId());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        if (request.getLotteryTriggerScriptId())
        {
            writer.writePropertyName("lotteryTriggerScriptId");
            writer.writeCharArray(*request.getLotteryTriggerScriptId());
        }
        if (request.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.writeCharArray(*request.getChoicePrizeTableScriptId());
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
        url.replace("{service}", "lottery");
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
	 * 抽選の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModelMasters(std::function<void(AsyncDescribeLotteryModelMastersResult&)> callback, DescribeLotteryModelMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeLotteryModelMastersResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/lottery";
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
	 * 抽選の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLotteryModelMaster(std::function<void(AsyncCreateLotteryModelMasterResult&)> callback, CreateLotteryModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateLotteryModelMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/lottery";
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
        if (request.getMode())
        {
            writer.writePropertyName("mode");
            writer.writeCharArray(*request.getMode());
        }
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt32(*request.getCount());
        }
        if (request.getMethod())
        {
            writer.writePropertyName("method");
            writer.writeCharArray(*request.getMethod());
        }
        if (request.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.writeCharArray(*request.getPrizeTableName());
        }
        if (request.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.writeCharArray(*request.getChoicePrizeTableScriptId());
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
	 * 抽選の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModelMaster(std::function<void(AsyncGetLotteryModelMasterResult&)> callback, GetLotteryModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetLotteryModelMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/lottery/{lotteryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getLotteryName();
            url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 抽選の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLotteryModelMaster(std::function<void(AsyncUpdateLotteryModelMasterResult&)> callback, UpdateLotteryModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateLotteryModelMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/lottery/{lotteryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getLotteryName();
            url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getMode())
        {
            writer.writePropertyName("mode");
            writer.writeCharArray(*request.getMode());
        }
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt32(*request.getCount());
        }
        if (request.getMethod())
        {
            writer.writePropertyName("method");
            writer.writeCharArray(*request.getMethod());
        }
        if (request.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.writeCharArray(*request.getPrizeTableName());
        }
        if (request.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.writeCharArray(*request.getChoicePrizeTableScriptId());
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
	 * 抽選の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLotteryModelMaster(std::function<void(AsyncDeleteLotteryModelMasterResult&)> callback, DeleteLotteryModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteLotteryModelMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/lottery/{lotteryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getLotteryName();
            url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 排出確率テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeTableMasters(std::function<void(AsyncDescribePrizeTableMastersResult&)> callback, DescribePrizeTableMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribePrizeTableMastersResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/table";
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
	 * 排出確率テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createPrizeTableMaster(std::function<void(AsyncCreatePrizeTableMasterResult&)> callback, CreatePrizeTableMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreatePrizeTableMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/table";
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
        if (request.getPrizes())
        {
            writer.writePropertyName("prizes");
            writer.writeArrayStart();
            auto& list = *request.getPrizes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
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
	 * 排出確率テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeTableMaster(std::function<void(AsyncGetPrizeTableMasterResult&)> callback, GetPrizeTableMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetPrizeTableMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/table/{prizeTableName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPrizeTableName();
            url.replace("{prizeTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 排出確率テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updatePrizeTableMaster(std::function<void(AsyncUpdatePrizeTableMasterResult&)> callback, UpdatePrizeTableMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdatePrizeTableMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/table/{prizeTableName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPrizeTableName();
            url.replace("{prizeTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getPrizes())
        {
            writer.writePropertyName("prizes");
            writer.writeArrayStart();
            auto& list = *request.getPrizes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
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
	 * 排出確率テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deletePrizeTableMaster(std::function<void(AsyncDeletePrizeTableMasterResult&)> callback, DeletePrizeTableMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeletePrizeTableMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/table/{prizeTableName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPrizeTableName();
            url.replace("{prizeTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * ボックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBoxes(std::function<void(AsyncDescribeBoxesResult&)> callback, DescribeBoxesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeBoxesResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/box";
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してボックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBoxesByUserId(std::function<void(AsyncDescribeBoxesByUserIdResult&)> callback, DescribeBoxesByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeBoxesByUserIdResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/box";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ボックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBox(std::function<void(AsyncGetBoxResult&)> callback, GetBoxRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetBoxResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/box/{lotteryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getLotteryName();
            url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してボックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBoxByUserId(std::function<void(AsyncGetBoxByUserIdResult&)> callback, GetBoxByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetBoxByUserIdResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/box/{lotteryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getLotteryName();
            url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ボックスをリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBox(std::function<void(AsyncResetBoxResult&)> callback, ResetBoxRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/box/{lotteryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getLotteryName();
            url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してボックスをリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBoxByUserId(std::function<void(AsyncResetBoxByUserIdResult&)> callback, ResetBoxByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/box/{lotteryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getLotteryName();
            url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setHeaders(headerEntries);
        gs2RestSessionTask.execute();
    }

	/**
	 * 抽選の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModels(std::function<void(AsyncDescribeLotteryModelsResult&)> callback, DescribeLotteryModelsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeLotteryModelsResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/lottery";
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
	 * 抽選の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModel(std::function<void(AsyncGetLotteryModelResult&)> callback, GetLotteryModelRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetLotteryModelResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/lottery/{lotteryName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getLotteryName();
            url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 排出確率テーブルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeTables(std::function<void(AsyncDescribePrizeTablesResult&)> callback, DescribePrizeTablesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribePrizeTablesResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/table";
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
	 * 排出確率テーブルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeTable(std::function<void(AsyncGetPrizeTableResult&)> callback, GetPrizeTableRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetPrizeTableResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/table/{prizeTableName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPrizeTableName();
            url.replace("{prizeTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 現在有効な抽選設定のマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ExportMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
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
	 * 現在有効な現在有効な抽選設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLotteryMaster(std::function<void(AsyncGetCurrentLotteryMasterResult&)> callback, GetCurrentLotteryMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetCurrentLotteryMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
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
	 * 現在有効な現在有効な抽選設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLotteryMaster(std::function<void(AsyncUpdateCurrentLotteryMasterResult&)> callback, UpdateCurrentLotteryMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentLotteryMasterResult>(getGs2RestSession(), callback);
        gs2RestSessionTask.getGs2HttpTask().getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "lottery");
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

#endif //GS2_LOTTERY_GS2LOTTERYRESTCLIENT_HPP_