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
#include <gs2/core/network/HttpRequest.hpp>
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
            writer.write(*obj.getGroupId());
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

    void write(detail::json::JsonWriter& writer, const LotteryModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getLotteryModelId())
        {
            writer.writePropertyName("lotteryModelId");
            writer.write(*obj.getLotteryModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getMode())
        {
            writer.writePropertyName("mode");
            writer.write(*obj.getMode());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*obj.getCount());
        }
        if (obj.getMethod())
        {
            writer.writePropertyName("method");
            writer.write(*obj.getMethod());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.write(*obj.getPrizeTableName());
        }
        if (obj.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.write(*obj.getChoicePrizeTableScriptId());
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

    void write(detail::json::JsonWriter& writer, const PrizeTableMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getPrizeTableId())
        {
            writer.writePropertyName("prizeTableId");
            writer.write(*obj.getPrizeTableId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getPrizes())
        {
            writer.writePropertyName("prizes");
            writer.writeArrayStart();
            auto& list = *obj.getPrizes();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
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

    void write(detail::json::JsonWriter& writer, const Box& obj)
    {
        writer.writeObjectStart();
        if (obj.getBoxId())
        {
            writer.writePropertyName("boxId");
            writer.write(*obj.getBoxId());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.write(*obj.getPrizeTableName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getDrawnIndexes())
        {
            writer.writePropertyName("drawnIndexes");
            writer.writeArrayStart();
            auto& list = *obj.getDrawnIndexes();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
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

    void write(detail::json::JsonWriter& writer, const LotteryModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getLotteryModelId())
        {
            writer.writePropertyName("lotteryModelId");
            writer.write(*obj.getLotteryModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getMode())
        {
            writer.writePropertyName("mode");
            writer.write(*obj.getMode());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*obj.getCount());
        }
        if (obj.getMethod())
        {
            writer.writePropertyName("method");
            writer.write(*obj.getMethod());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.write(*obj.getPrizeTableName());
        }
        if (obj.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.write(*obj.getChoicePrizeTableScriptId());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const PrizeTable& obj)
    {
        writer.writeObjectStart();
        if (obj.getPrizeTableId())
        {
            writer.writePropertyName("prizeTableId");
            writer.write(*obj.getPrizeTableId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getPrizes())
        {
            writer.writePropertyName("prizes");
            writer.writeArrayStart();
            auto& list = *obj.getPrizes();
            for (Int32 i = 0; i < list.getCount(); ++i)
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
            writer.write(*obj.getRate());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const CurrentLotteryMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getGroupName())
        {
            writer.writePropertyName("groupName");
            writer.write(*obj.getGroupName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.write(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.write(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.write(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.write(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.write(*obj.getResult());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const PrizeMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.write(*obj.getType());
        }
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.write(*obj.getPropertyId());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.write(*obj.getPrizeTableName());
        }
        if (obj.getWeight())
        {
            writer.writePropertyName("weight");
            writer.write(*obj.getWeight());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Prize& obj)
    {
        writer.writeObjectStart();
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.write(*obj.getType());
        }
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.write(*obj.getPropertyId());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.write(*obj.getPrizeTableName());
        }
        if (obj.getWeight())
        {
            writer.writePropertyName("weight");
            writer.write(*obj.getWeight());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const DrawnPrize& obj)
    {
        writer.writeObjectStart();
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.write(*obj.getPropertyId());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const BoxItem& obj)
    {
        writer.writeObjectStart();
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.write(*obj.getPropertyId());
        }
        if (obj.getRemaining())
        {
            writer.writePropertyName("remaining");
            writer.write(*obj.getRemaining());
        }
        if (obj.getInitial())
        {
            writer.writePropertyName("initial");
            writer.write(*obj.getInitial());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const BoxItems& obj)
    {
        writer.writeObjectStart();
        if (obj.getBoxId())
        {
            writer.writePropertyName("boxId");
            writer.write(*obj.getBoxId());
        }
        if (obj.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.write(*obj.getPrizeTableName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getItems())
        {
            writer.writePropertyName("items");
            writer.writeArrayStart();
            auto& list = *obj.getItems();
            for (Int32 i = 0; i < list.getCount(); ++i)
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
        auto& httpRequest = *new detail::HttpRequest<DescribeGroupsResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * グループの種類を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGroup(std::function<void(AsyncCreateGroupResult&)> callback, CreateGroupRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateGroupResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.createGroup");
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
	 * グループの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGroupStatus(std::function<void(AsyncGetGroupStatusResult&)> callback, GetGroupStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGroupStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.getGroupStatus");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * グループの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGroup(std::function<void(AsyncGetGroupResult&)> callback, GetGroupRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGroupResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.getGroup");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * グループの種類を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGroup(std::function<void(AsyncUpdateGroupResult&)> callback, UpdateGroupRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateGroupResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
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
	 * グループの種類を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGroup(std::function<void(AsyncDeleteGroupResult&)> callback, DeleteGroupRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DeleteGroupResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FGroupFunctionHandler.deleteGroup");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 抽選の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModelMasters(std::function<void(AsyncDescribeLotteryModelMastersResult&)> callback, DescribeLotteryModelMastersRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeLotteryModelMastersResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 抽選の種類を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLotteryModelMaster(std::function<void(AsyncCreateLotteryModelMasterResult&)> callback, CreateLotteryModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateLotteryModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
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
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getMode())
        {
            writer.writePropertyName("mode");
            writer.write(*request.getMode());
        }
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getMethod())
        {
            writer.writePropertyName("method");
            writer.write(*request.getMethod());
        }
        if (request.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.write(*request.getPrizeTableName());
        }
        if (request.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.write(*request.getChoicePrizeTableScriptId());
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
	 * 抽選の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModelMaster(std::function<void(AsyncGetLotteryModelMasterResult&)> callback, GetLotteryModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLotteryModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 抽選の種類を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLotteryModelMaster(std::function<void(AsyncUpdateLotteryModelMasterResult&)> callback, UpdateLotteryModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateLotteryModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
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
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getMode())
        {
            writer.writePropertyName("mode");
            writer.write(*request.getMode());
        }
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.write(*request.getCount());
        }
        if (request.getMethod())
        {
            writer.writePropertyName("method");
            writer.write(*request.getMethod());
        }
        if (request.getPrizeTableName())
        {
            writer.writePropertyName("prizeTableName");
            writer.write(*request.getPrizeTableName());
        }
        if (request.getChoicePrizeTableScriptId())
        {
            writer.writePropertyName("choicePrizeTableScriptId");
            writer.write(*request.getChoicePrizeTableScriptId());
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
	 * 抽選の種類を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLotteryModelMaster(std::function<void(AsyncDeleteLotteryModelMasterResult&)> callback, DeleteLotteryModelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DeleteLotteryModelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 景品の排出確率テーブルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeTableMasters(std::function<void(AsyncDescribePrizeTableMastersResult&)> callback, DescribePrizeTableMastersRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribePrizeTableMastersResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 景品の排出確率テーブルを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createPrizeTableMaster(std::function<void(AsyncCreatePrizeTableMasterResult&)> callback, CreatePrizeTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreatePrizeTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
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
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getPrizes())
        {
            writer.writePropertyName("prizes");
            writer.writeArrayStart();
            auto& list = *request.getPrizes();
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
	 * 景品の排出確率テーブルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeTableMaster(std::function<void(AsyncGetPrizeTableMasterResult&)> callback, GetPrizeTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetPrizeTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 景品の排出確率テーブルを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updatePrizeTableMaster(std::function<void(AsyncUpdatePrizeTableMasterResult&)> callback, UpdatePrizeTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdatePrizeTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
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
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getPrizes())
        {
            writer.writePropertyName("prizes");
            writer.writeArrayStart();
            auto& list = *request.getPrizes();
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
	 * 景品の排出確率テーブルを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deletePrizeTableMaster(std::function<void(AsyncDeletePrizeTableMasterResult&)> callback, DeletePrizeTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DeletePrizeTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 排出済みの景品情報の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBoxes(std::function<void(AsyncDescribeBoxesResult&)> callback, DescribeBoxesRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeBoxesResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 排出済みの景品情報を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBox(std::function<void(AsyncGetBoxResult&)> callback, GetBoxRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetBoxResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 排出済みの景品情報を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBoxByUserId(std::function<void(AsyncGetBoxByUserIdResult&)> callback, GetBoxByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetBoxByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 排出済みの景品情報をリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBox(std::function<void(AsyncResetBoxResult&)> callback, ResetBoxRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 排出済みの景品情報をリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBoxByUserId(std::function<void(AsyncResetBoxByUserIdResult&)> callback, ResetBoxByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 抽選の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModels(std::function<void(AsyncDescribeLotteryModelsResult&)> callback, DescribeLotteryModelsRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeLotteryModelsResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FLotteryModelFunctionHandler.describeLotteryModels");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 抽選の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModel(std::function<void(AsyncGetLotteryModelResult&)> callback, GetLotteryModelRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLotteryModelResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 抽選を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void draw(std::function<void(AsyncDrawResult&)> callback, DrawRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DrawResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        if (request.getDuplicationAvoider())
        {
            httpRequest.addHeader("X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 排出確率を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProbabilities(std::function<void(AsyncDescribeProbabilitiesResult&)> callback, DescribeProbabilitiesRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeProbabilitiesResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
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

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 抽選マスターJSONのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ExportMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FCurrentLotteryMasterFunctionHandler.exportMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 現在有効な抽選マスターJSONを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLotteryMaster(std::function<void(AsyncGetCurrentLotteryMasterResult&)> callback, GetCurrentLotteryMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCurrentLotteryMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/lottery-handler?handler=gs2_lottery%2Fhandler%2FCurrentLotteryMasterFunctionHandler.getCurrentLotteryMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

	/**
	 * 現在有効な抽選マスターJSONを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLotteryMaster(std::function<void(AsyncUpdateCurrentLotteryMasterResult&)> callback, UpdateCurrentLotteryMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCurrentLotteryMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
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
};

} }

#endif //GS2_LOTTERY_GS2LOTTERYCLIENT_HPP_