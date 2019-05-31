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

#ifndef GS2_LOTTERY_GS2LOTTERYCLIENT_HPP_
#define GS2_LOTTERY_GS2LOTTERYCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeGroupsRequest.hpp"
#include "request/CreateGroupRequest.hpp"
#include "request/GetGroupStatusRequest.hpp"
#include "request/GetGroupRequest.hpp"
#include "request/UpdateGroupRequest.hpp"
#include "request/DeleteGroupRequest.hpp"
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
#include "request/GetBoxRequest.hpp"
#include "request/GetBoxByUserIdRequest.hpp"
#include "request/ResetBoxRequest.hpp"
#include "request/ResetBoxByUserIdRequest.hpp"
#include "request/DescribeLotteryModelsRequest.hpp"
#include "request/GetLotteryModelRequest.hpp"
#include "request/DrawRequest.hpp"
#include "request/DescribeProbabilitiesRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentLotteryMasterRequest.hpp"
#include "request/UpdateCurrentLotteryMasterRequest.hpp"
#include "result/DescribeGroupsResult.hpp"
#include "result/CreateGroupResult.hpp"
#include "result/GetGroupStatusResult.hpp"
#include "result/GetGroupResult.hpp"
#include "result/UpdateGroupResult.hpp"
#include "result/DeleteGroupResult.hpp"
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
#include "result/GetBoxResult.hpp"
#include "result/GetBoxByUserIdResult.hpp"
#include "result/ResetBoxResult.hpp"
#include "result/ResetBoxByUserIdResult.hpp"
#include "result/DescribeLotteryModelsResult.hpp"
#include "result/GetLotteryModelResult.hpp"
#include "result/DrawResult.hpp"
#include "result/DescribeProbabilitiesResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentLotteryMasterResult.hpp"
#include "result/UpdateCurrentLotteryMasterResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace lottery {

typedef AsyncResult<DescribeGroupsResult> AsyncDescribeGroupsResult;
typedef AsyncResult<CreateGroupResult> AsyncCreateGroupResult;
typedef AsyncResult<GetGroupStatusResult> AsyncGetGroupStatusResult;
typedef AsyncResult<GetGroupResult> AsyncGetGroupResult;
typedef AsyncResult<UpdateGroupResult> AsyncUpdateGroupResult;
typedef AsyncResult<DeleteGroupResult> AsyncDeleteGroupResult;
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
typedef AsyncResult<GetBoxResult> AsyncGetBoxResult;
typedef AsyncResult<GetBoxByUserIdResult> AsyncGetBoxByUserIdResult;
typedef AsyncResult<void> AsyncResetBoxResult;
typedef AsyncResult<void> AsyncResetBoxByUserIdResult;
typedef AsyncResult<DescribeLotteryModelsResult> AsyncDescribeLotteryModelsResult;
typedef AsyncResult<GetLotteryModelResult> AsyncGetLotteryModelResult;
typedef AsyncResult<DrawResult> AsyncDrawResult;
typedef AsyncResult<DescribeProbabilitiesResult> AsyncDescribeProbabilitiesResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentLotteryMasterResult> AsyncGetCurrentLotteryMasterResult;
typedef AsyncResult<UpdateCurrentLotteryMasterResult> AsyncUpdateCurrentLotteryMasterResult;

/**
 * GS2 Lottery API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LotteryClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "lottery";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const Group& obj)
    {
        writer.writeObjectStart();
        if (obj.getGroupId())
        {
            writer.writePropertyName("groupId");
            writer.writeCharArray(*obj.getGroupId());
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

    void write(detail::json::JsonWriter& writer, const LotteryModelMaster& obj)
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

    void write(detail::json::JsonWriter& writer, const PrizeTableMaster& obj)
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

    void write(detail::json::JsonWriter& writer, const Box& obj)
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

    void write(detail::json::JsonWriter& writer, const LotteryModel& obj)
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

    void write(detail::json::JsonWriter& writer, const PrizeTable& obj)
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

    void write(detail::json::JsonWriter& writer, const Lottery& obj)
    {
        writer.writeObjectStart();
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Probability& obj)
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

    void write(detail::json::JsonWriter& writer, const CurrentLotteryMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getGroupName())
        {
            writer.writePropertyName("groupName");
            writer.writeCharArray(*obj.getGroupName());
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

    void write(detail::json::JsonWriter& writer, const PrizeMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.writeCharArray(*obj.getPropertyId());
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

    void write(detail::json::JsonWriter& writer, const Prize& obj)
    {
        writer.writeObjectStart();
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.writeCharArray(*obj.getPropertyId());
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

    void write(detail::json::JsonWriter& writer, const DrawnPrize& obj)
    {
        writer.writeObjectStart();
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.writeCharArray(*obj.getPropertyId());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const BoxItem& obj)
    {
        writer.writeObjectStart();
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.writeCharArray(*obj.getPropertyId());
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

    void write(detail::json::JsonWriter& writer, const BoxItems& obj)
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



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2LotteryClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2LotteryClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2LotteryClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }

	/**
	 * グループの種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGroups(std::function<void(AsyncDescribeGroupsResult&)> callback, DescribeGroupsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeGroupsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.describeGroups");
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
	 * グループの種類を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGroup(std::function<void(AsyncCreateGroupResult&)> callback, CreateGroupRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateGroupResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.createGroup");
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
	 * グループの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGroupStatus(std::function<void(AsyncGetGroupStatusResult&)> callback, GetGroupStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetGroupStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.getGroupStatus");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * グループの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGroup(std::function<void(AsyncGetGroupResult&)> callback, GetGroupRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetGroupResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.getGroup");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * グループの種類を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGroup(std::function<void(AsyncUpdateGroupResult&)> callback, UpdateGroupRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateGroupResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.updateGroup");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * グループの種類を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGroup(std::function<void(AsyncDeleteGroupResult&)> callback, DeleteGroupRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteGroupResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.deleteGroup");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 抽選の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModelMasters(std::function<void(AsyncDescribeLotteryModelMastersResult&)> callback, DescribeLotteryModelMastersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeLotteryModelMastersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryModelMasterFunctionHandler.describeLotteryModelMasters");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 抽選の種類を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLotteryModelMaster(std::function<void(AsyncCreateLotteryModelMasterResult&)> callback, CreateLotteryModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateLotteryModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryModelMasterFunctionHandler.createLotteryModelMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 抽選の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModelMaster(std::function<void(AsyncGetLotteryModelMasterResult&)> callback, GetLotteryModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetLotteryModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryModelMasterFunctionHandler.getLotteryModelMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
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
	 * 抽選の種類を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLotteryModelMaster(std::function<void(AsyncUpdateLotteryModelMasterResult&)> callback, UpdateLotteryModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateLotteryModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryModelMasterFunctionHandler.updateLotteryModelMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
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
	 * 抽選の種類を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLotteryModelMaster(std::function<void(AsyncDeleteLotteryModelMasterResult&)> callback, DeleteLotteryModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteLotteryModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryModelMasterFunctionHandler.deleteLotteryModelMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
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
	 * 景品の排出確率テーブルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeTableMasters(std::function<void(AsyncDescribePrizeTableMastersResult&)> callback, DescribePrizeTableMastersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribePrizeTableMastersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FPrizeTableMasterFunctionHandler.describePrizeTableMasters");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 景品の排出確率テーブルを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createPrizeTableMaster(std::function<void(AsyncCreatePrizeTableMasterResult&)> callback, CreatePrizeTableMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreatePrizeTableMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FPrizeTableMasterFunctionHandler.createPrizeTableMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 景品の排出確率テーブルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeTableMaster(std::function<void(AsyncGetPrizeTableMasterResult&)> callback, GetPrizeTableMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetPrizeTableMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FPrizeTableMasterFunctionHandler.getPrizeTableMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPrizeTableName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPrizeTableName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("prizeTableName={value}").replace("{value}", encodeBuffer);
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
	 * 景品の排出確率テーブルを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updatePrizeTableMaster(std::function<void(AsyncUpdatePrizeTableMasterResult&)> callback, UpdatePrizeTableMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdatePrizeTableMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FPrizeTableMasterFunctionHandler.updatePrizeTableMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPrizeTableName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPrizeTableName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("prizeTableName={value}").replace("{value}", encodeBuffer);
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
	 * 景品の排出確率テーブルを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deletePrizeTableMaster(std::function<void(AsyncDeletePrizeTableMasterResult&)> callback, DeletePrizeTableMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeletePrizeTableMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FPrizeTableMasterFunctionHandler.deletePrizeTableMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPrizeTableName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPrizeTableName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("prizeTableName={value}").replace("{value}", encodeBuffer);
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
	 * 排出済みの景品情報の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBoxes(std::function<void(AsyncDescribeBoxesResult&)> callback, DescribeBoxesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeBoxesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FBoxFunctionHandler.describeBoxes");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
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
	 * 排出済みの景品情報を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBox(std::function<void(AsyncGetBoxResult&)> callback, GetBoxRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetBoxResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FBoxFunctionHandler.getBox");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
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
	 * 排出済みの景品情報を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBoxByUserId(std::function<void(AsyncGetBoxByUserIdResult&)> callback, GetBoxByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetBoxByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FBoxFunctionHandler.getBoxByUserId");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
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
	 * 排出済みの景品情報をリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBox(std::function<void(AsyncResetBoxResult&)> callback, ResetBoxRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FBoxFunctionHandler.resetBox");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
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
	 * 排出済みの景品情報をリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBoxByUserId(std::function<void(AsyncResetBoxByUserIdResult&)> callback, ResetBoxByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FBoxFunctionHandler.resetBoxByUserId");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
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
	 * 抽選の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModels(std::function<void(AsyncDescribeLotteryModelsResult&)> callback, DescribeLotteryModelsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeLotteryModelsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryModelFunctionHandler.describeLotteryModels");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 抽選の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModel(std::function<void(AsyncGetLotteryModelResult&)> callback, GetLotteryModelRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetLotteryModelResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryModelFunctionHandler.getLotteryModel");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
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
	 * 抽選を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void draw(std::function<void(AsyncDrawResult&)> callback, DrawRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DrawResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryFunctionHandler.draw");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
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
	 * 排出確率を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProbabilities(std::function<void(AsyncDescribeProbabilitiesResult&)> callback, DescribeProbabilitiesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeProbabilitiesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryFunctionHandler.describeProbabilities");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLotteryModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLotteryModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("lotteryModelName={value}").replace("{value}", encodeBuffer);
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
	 * 抽選マスターJSONのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ExportMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FCurrentLotteryMasterFunctionHandler.exportMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 現在有効な抽選マスターJSONを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLotteryMaster(std::function<void(AsyncGetCurrentLotteryMasterResult&)> callback, GetCurrentLotteryMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetCurrentLotteryMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FCurrentLotteryMasterFunctionHandler.getCurrentLotteryMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 現在有効な抽選マスターJSONを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLotteryMaster(std::function<void(AsyncUpdateCurrentLotteryMasterResult&)> callback, UpdateCurrentLotteryMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateCurrentLotteryMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FCurrentLotteryMasterFunctionHandler.updateCurrentLotteryMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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

#endif //GS2_LOTTERY_GS2LOTTERYCLIENT_HPP_