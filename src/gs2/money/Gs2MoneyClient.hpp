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

#ifndef GS2_MONEY_GS2MONEYCLIENT_HPP_
#define GS2_MONEY_GS2MONEYCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeMoneysRequest.hpp"
#include "request/CreateMoneyRequest.hpp"
#include "request/GetMoneyStatusRequest.hpp"
#include "request/GetMoneyRequest.hpp"
#include "request/UpdateMoneyRequest.hpp"
#include "request/DeleteMoneyRequest.hpp"
#include "request/DescribeWalletsRequest.hpp"
#include "request/GetWalletRequest.hpp"
#include "request/GetWalletByUserIdRequest.hpp"
#include "request/GetWalletDetailRequest.hpp"
#include "request/DepositByUserIdRequest.hpp"
#include "request/WithdrawRequest.hpp"
#include "request/WithdrawByUserIdRequest.hpp"
#include "request/DepositByStampSheetRequest.hpp"
#include "request/DepositWithReceiptByStampSheetRequest.hpp"
#include "request/WithdrawByStampTaskRequest.hpp"
#include "request/DescribeReceiptsRequest.hpp"
#include "request/DescribeReceiptsByUserIdAndSlotRequest.hpp"
#include "request/GetByUserIdAndTransactionIdRequest.hpp"
#include "result/DescribeMoneysResult.hpp"
#include "result/CreateMoneyResult.hpp"
#include "result/GetMoneyStatusResult.hpp"
#include "result/GetMoneyResult.hpp"
#include "result/UpdateMoneyResult.hpp"
#include "result/DeleteMoneyResult.hpp"
#include "result/DescribeWalletsResult.hpp"
#include "result/GetWalletResult.hpp"
#include "result/GetWalletByUserIdResult.hpp"
#include "result/GetWalletDetailResult.hpp"
#include "result/DepositByUserIdResult.hpp"
#include "result/WithdrawResult.hpp"
#include "result/WithdrawByUserIdResult.hpp"
#include "result/DepositByStampSheetResult.hpp"
#include "result/DepositWithReceiptByStampSheetResult.hpp"
#include "result/WithdrawByStampTaskResult.hpp"
#include "result/DescribeReceiptsResult.hpp"
#include "result/DescribeReceiptsByUserIdAndSlotResult.hpp"
#include "result/GetByUserIdAndTransactionIdResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace money {

typedef AsyncResult<DescribeMoneysResult> AsyncDescribeMoneysResult;
typedef AsyncResult<CreateMoneyResult> AsyncCreateMoneyResult;
typedef AsyncResult<GetMoneyStatusResult> AsyncGetMoneyStatusResult;
typedef AsyncResult<GetMoneyResult> AsyncGetMoneyResult;
typedef AsyncResult<UpdateMoneyResult> AsyncUpdateMoneyResult;
typedef AsyncResult<void> AsyncDeleteMoneyResult;
typedef AsyncResult<DescribeWalletsResult> AsyncDescribeWalletsResult;
typedef AsyncResult<GetWalletResult> AsyncGetWalletResult;
typedef AsyncResult<GetWalletByUserIdResult> AsyncGetWalletByUserIdResult;
typedef AsyncResult<GetWalletDetailResult> AsyncGetWalletDetailResult;
typedef AsyncResult<DepositByUserIdResult> AsyncDepositByUserIdResult;
typedef AsyncResult<WithdrawResult> AsyncWithdrawResult;
typedef AsyncResult<WithdrawByUserIdResult> AsyncWithdrawByUserIdResult;
typedef AsyncResult<DepositByStampSheetResult> AsyncDepositByStampSheetResult;
typedef AsyncResult<DepositWithReceiptByStampSheetResult> AsyncDepositWithReceiptByStampSheetResult;
typedef AsyncResult<WithdrawByStampTaskResult> AsyncWithdrawByStampTaskResult;
typedef AsyncResult<DescribeReceiptsResult> AsyncDescribeReceiptsResult;
typedef AsyncResult<DescribeReceiptsByUserIdAndSlotResult> AsyncDescribeReceiptsByUserIdAndSlotResult;
typedef AsyncResult<GetByUserIdAndTransactionIdResult> AsyncGetByUserIdAndTransactionIdResult;

/**
 * GS2 Money API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MoneyClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "money";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const Money& obj)
    {
        writer.writeObjectStart();
        if (obj.getMoneyId())
        {
            writer.writePropertyName("moneyId");
            writer.writeCharArray(*obj.getMoneyId());
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
        if (obj.getPriority())
        {
            writer.writePropertyName("priority");
            writer.writeCharArray(*obj.getPriority());
        }
        if (obj.getShareFree())
        {
            writer.writePropertyName("shareFree");
            writer.writeBool(*obj.getShareFree());
        }
        if (obj.getCurrency())
        {
            writer.writePropertyName("currency");
            writer.writeCharArray(*obj.getCurrency());
        }
        if (obj.getAppleKey())
        {
            writer.writePropertyName("appleKey");
            writer.writeCharArray(*obj.getAppleKey());
        }
        if (obj.getGoogleKey())
        {
            writer.writePropertyName("googleKey");
            writer.writeCharArray(*obj.getGoogleKey());
        }
        if (obj.getEnableFakeReceipt())
        {
            writer.writePropertyName("enableFakeReceipt");
            writer.writeBool(*obj.getEnableFakeReceipt());
        }
        if (obj.getCreateWalletTriggerScriptId())
        {
            writer.writePropertyName("createWalletTriggerScriptId");
            writer.writeCharArray(*obj.getCreateWalletTriggerScriptId());
        }
        if (obj.getCreateWalletDoneTriggerScriptId())
        {
            writer.writePropertyName("createWalletDoneTriggerScriptId");
            writer.writeCharArray(*obj.getCreateWalletDoneTriggerScriptId());
        }
        if (obj.getCreateWalletDoneTriggerQueueId())
        {
            writer.writePropertyName("createWalletDoneTriggerQueueId");
            writer.writeCharArray(*obj.getCreateWalletDoneTriggerQueueId());
        }
        if (obj.getDepositTriggerScriptId())
        {
            writer.writePropertyName("depositTriggerScriptId");
            writer.writeCharArray(*obj.getDepositTriggerScriptId());
        }
        if (obj.getDepositDoneTriggerScriptId())
        {
            writer.writePropertyName("depositDoneTriggerScriptId");
            writer.writeCharArray(*obj.getDepositDoneTriggerScriptId());
        }
        if (obj.getDepositDoneTriggerQueueId())
        {
            writer.writePropertyName("depositDoneTriggerQueueId");
            writer.writeCharArray(*obj.getDepositDoneTriggerQueueId());
        }
        if (obj.getWithdrawTriggerScriptId())
        {
            writer.writePropertyName("withdrawTriggerScriptId");
            writer.writeCharArray(*obj.getWithdrawTriggerScriptId());
        }
        if (obj.getWithdrawDoneTriggerScriptId())
        {
            writer.writePropertyName("withdrawDoneTriggerScriptId");
            writer.writeCharArray(*obj.getWithdrawDoneTriggerScriptId());
        }
        if (obj.getWithdrawDoneTriggerQueueId())
        {
            writer.writePropertyName("withdrawDoneTriggerQueueId");
            writer.writeCharArray(*obj.getWithdrawDoneTriggerQueueId());
        }
        if (obj.getBalance())
        {
            writer.writePropertyName("balance");
            writer.writeDouble(*obj.getBalance());
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

    void write(detail::json::JsonWriter& writer, const Summary& obj)
    {
        writer.writeObjectStart();
        if (obj.getSummaryId())
        {
            writer.writePropertyName("summaryId");
            writer.writeCharArray(*obj.getSummaryId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getSlot())
        {
            writer.writePropertyName("slot");
            writer.writeInt32(*obj.getSlot());
        }
        if (obj.getPaid())
        {
            writer.writePropertyName("paid");
            writer.writeInt32(*obj.getPaid());
        }
        if (obj.getFree())
        {
            writer.writePropertyName("free");
            writer.writeInt32(*obj.getFree());
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

    void write(detail::json::JsonWriter& writer, const Wallet& obj)
    {
        writer.writeObjectStart();
        if (obj.getWalletId())
        {
            writer.writePropertyName("walletId");
            writer.writeCharArray(*obj.getWalletId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getSlot())
        {
            writer.writePropertyName("slot");
            writer.writeInt32(*obj.getSlot());
        }
        if (obj.getPrice())
        {
            writer.writePropertyName("price");
            writer.writeFloat(*obj.getPrice());
        }
        if (obj.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt32(*obj.getCount());
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

    void write(detail::json::JsonWriter& writer, const Receipt& obj)
    {
        writer.writeObjectStart();
        if (obj.getReceiptId())
        {
            writer.writePropertyName("receiptId");
            writer.writeCharArray(*obj.getReceiptId());
        }
        if (obj.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.writeCharArray(*obj.getTransactionId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getSlot())
        {
            writer.writePropertyName("slot");
            writer.writeInt32(*obj.getSlot());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getPrice())
        {
            writer.writePropertyName("price");
            writer.writeFloat(*obj.getPrice());
        }
        if (obj.getPaid())
        {
            writer.writePropertyName("paid");
            writer.writeInt32(*obj.getPaid());
        }
        if (obj.getFree())
        {
            writer.writePropertyName("free");
            writer.writeInt32(*obj.getFree());
        }
        if (obj.getTotal())
        {
            writer.writePropertyName("total");
            writer.writeInt32(*obj.getTotal());
        }
        if (obj.getContentsId())
        {
            writer.writePropertyName("contentsId");
            writer.writeCharArray(*obj.getContentsId());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
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
     * @param gs2RestSession REST API 用セッション
     */
    Gs2MoneyClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
	 * @param region アクセス先リージョン
     */
    Gs2MoneyClient(Gs2RestSession& gs2RestSession, const Region& region) :
        AbstractGs2ClientBase(gs2RestSession, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
	 * @param region アクセス先リージョン
     */
    Gs2MoneyClient(Gs2RestSession& gs2RestSession, const Char region[]) :
        AbstractGs2ClientBase(gs2RestSession, region)
    {
    }

	/**
	 * 課金通貨の一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMoneys(std::function<void(AsyncDescribeMoneysResult&)> callback, DescribeMoneysRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeMoneysResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FMoneyFunctionHandler.describeMoneys");
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
	 * 課金通貨を新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMoney(std::function<void(AsyncCreateMoneyResult&)> callback, CreateMoneyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateMoneyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FMoneyFunctionHandler.createMoney");
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
        if (request.getPriority())
        {
            writer.writePropertyName("priority");
            writer.writeCharArray(*request.getPriority());
        }
        if (request.getShareFree())
        {
            writer.writePropertyName("shareFree");
            writer.writeBool(*request.getShareFree());
        }
        if (request.getCurrency())
        {
            writer.writePropertyName("currency");
            writer.writeCharArray(*request.getCurrency());
        }
        if (request.getAppleKey())
        {
            writer.writePropertyName("appleKey");
            writer.writeCharArray(*request.getAppleKey());
        }
        if (request.getGoogleKey())
        {
            writer.writePropertyName("googleKey");
            writer.writeCharArray(*request.getGoogleKey());
        }
        if (request.getEnableFakeReceipt())
        {
            writer.writePropertyName("enableFakeReceipt");
            writer.writeBool(*request.getEnableFakeReceipt());
        }
        if (request.getCreateWalletTriggerScriptId())
        {
            writer.writePropertyName("createWalletTriggerScriptId");
            writer.writeCharArray(*request.getCreateWalletTriggerScriptId());
        }
        if (request.getCreateWalletDoneTriggerScriptId())
        {
            writer.writePropertyName("createWalletDoneTriggerScriptId");
            writer.writeCharArray(*request.getCreateWalletDoneTriggerScriptId());
        }
        if (request.getCreateWalletDoneTriggerQueueId())
        {
            writer.writePropertyName("createWalletDoneTriggerQueueId");
            writer.writeCharArray(*request.getCreateWalletDoneTriggerQueueId());
        }
        if (request.getDepositTriggerScriptId())
        {
            writer.writePropertyName("depositTriggerScriptId");
            writer.writeCharArray(*request.getDepositTriggerScriptId());
        }
        if (request.getDepositDoneTriggerScriptId())
        {
            writer.writePropertyName("depositDoneTriggerScriptId");
            writer.writeCharArray(*request.getDepositDoneTriggerScriptId());
        }
        if (request.getDepositDoneTriggerQueueId())
        {
            writer.writePropertyName("depositDoneTriggerQueueId");
            writer.writeCharArray(*request.getDepositDoneTriggerQueueId());
        }
        if (request.getWithdrawTriggerScriptId())
        {
            writer.writePropertyName("withdrawTriggerScriptId");
            writer.writeCharArray(*request.getWithdrawTriggerScriptId());
        }
        if (request.getWithdrawDoneTriggerScriptId())
        {
            writer.writePropertyName("withdrawDoneTriggerScriptId");
            writer.writeCharArray(*request.getWithdrawDoneTriggerScriptId());
        }
        if (request.getWithdrawDoneTriggerQueueId())
        {
            writer.writePropertyName("withdrawDoneTriggerQueueId");
            writer.writeCharArray(*request.getWithdrawDoneTriggerQueueId());
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
	 * 課金通貨を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMoneyStatus(std::function<void(AsyncGetMoneyStatusResult&)> callback, GetMoneyStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetMoneyStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FMoneyFunctionHandler.getMoneyStatus");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
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
	 * 課金通貨を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMoney(std::function<void(AsyncGetMoneyResult&)> callback, GetMoneyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetMoneyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FMoneyFunctionHandler.getMoney");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
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
	 * 課金通貨を新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMoney(std::function<void(AsyncUpdateMoneyResult&)> callback, UpdateMoneyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateMoneyResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FMoneyFunctionHandler.updateMoney");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getPriority())
        {
            writer.writePropertyName("priority");
            writer.writeCharArray(*request.getPriority());
        }
        if (request.getAppleKey())
        {
            writer.writePropertyName("appleKey");
            writer.writeCharArray(*request.getAppleKey());
        }
        if (request.getGoogleKey())
        {
            writer.writePropertyName("googleKey");
            writer.writeCharArray(*request.getGoogleKey());
        }
        if (request.getEnableFakeReceipt())
        {
            writer.writePropertyName("enableFakeReceipt");
            writer.writeBool(*request.getEnableFakeReceipt());
        }
        if (request.getCreateWalletTriggerScriptId())
        {
            writer.writePropertyName("createWalletTriggerScriptId");
            writer.writeCharArray(*request.getCreateWalletTriggerScriptId());
        }
        if (request.getCreateWalletDoneTriggerScriptId())
        {
            writer.writePropertyName("createWalletDoneTriggerScriptId");
            writer.writeCharArray(*request.getCreateWalletDoneTriggerScriptId());
        }
        if (request.getCreateWalletDoneTriggerQueueId())
        {
            writer.writePropertyName("createWalletDoneTriggerQueueId");
            writer.writeCharArray(*request.getCreateWalletDoneTriggerQueueId());
        }
        if (request.getDepositTriggerScriptId())
        {
            writer.writePropertyName("depositTriggerScriptId");
            writer.writeCharArray(*request.getDepositTriggerScriptId());
        }
        if (request.getDepositDoneTriggerScriptId())
        {
            writer.writePropertyName("depositDoneTriggerScriptId");
            writer.writeCharArray(*request.getDepositDoneTriggerScriptId());
        }
        if (request.getDepositDoneTriggerQueueId())
        {
            writer.writePropertyName("depositDoneTriggerQueueId");
            writer.writeCharArray(*request.getDepositDoneTriggerQueueId());
        }
        if (request.getWithdrawTriggerScriptId())
        {
            writer.writePropertyName("withdrawTriggerScriptId");
            writer.writeCharArray(*request.getWithdrawTriggerScriptId());
        }
        if (request.getWithdrawDoneTriggerScriptId())
        {
            writer.writePropertyName("withdrawDoneTriggerScriptId");
            writer.writeCharArray(*request.getWithdrawDoneTriggerScriptId());
        }
        if (request.getWithdrawDoneTriggerQueueId())
        {
            writer.writePropertyName("withdrawDoneTriggerQueueId");
            writer.writeCharArray(*request.getWithdrawDoneTriggerQueueId());
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
	 * 課金通貨を削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMoney(std::function<void(AsyncDeleteMoneyResult&)> callback, DeleteMoneyRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FMoneyFunctionHandler.deleteMoney");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
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
	 * ウォレットの概要一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWallets(std::function<void(AsyncDescribeWalletsResult&)> callback, DescribeWalletsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeWalletsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.describeWallets");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ウォレットの概要を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWallet(std::function<void(AsyncGetWalletResult&)> callback, GetWalletRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetWalletResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.getWallet");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getSlot()) {
            Char urlSafeValue[32];
            Int32 value = *request.getSlot();
            std::sprintf(urlSafeValue, "%d", value);
            url += "&" + detail::StringVariable("slot={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーIDを指定してウォレットの概要を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWalletByUserId(std::function<void(AsyncGetWalletByUserIdResult&)> callback, GetWalletByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetWalletByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.getWalletByUserId");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getSlot()) {
            Char urlSafeValue[32];
            Int32 value = *request.getSlot();
            std::sprintf(urlSafeValue, "%d", value);
            url += "&" + detail::StringVariable("slot={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ウォレットの詳細を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWalletDetail(std::function<void(AsyncGetWalletDetailResult&)> callback, GetWalletDetailRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetWalletDetailResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.getWalletDetail");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getSlot()) {
            Char urlSafeValue[32];
            Int32 value = *request.getSlot();
            std::sprintf(urlSafeValue, "%d", value);
            url += "&" + detail::StringVariable("slot={value}").replace("{value}", urlSafeValue);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーIDを指定してウォレットの概要に残高を加算します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositByUserId(std::function<void(AsyncDepositByUserIdResult&)> callback, DepositByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DepositByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.depositByUserId");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getSlot()) {
            Char urlSafeValue[32];
            Int32 value = *request.getSlot();
            std::sprintf(urlSafeValue, "%d", value);
            url += "&" + detail::StringVariable("slot={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getPrice())
        {
            writer.writePropertyName("price");
            writer.writeFloat(*request.getPrice());
        }
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt32(*request.getCount());
        }
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.writeCharArray(*request.getTransactionId());
        }
        if (request.getContentsId())
        {
            writer.writePropertyName("contentsId");
            writer.writeCharArray(*request.getContentsId());
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
	 * ウォレットの概要から残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdraw(std::function<void(AsyncWithdrawResult&)> callback, WithdrawRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<WithdrawResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.withdraw");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getSlot()) {
            Char urlSafeValue[32];
            Int32 value = *request.getSlot();
            std::sprintf(urlSafeValue, "%d", value);
            url += "&" + detail::StringVariable("slot={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt32(*request.getCount());
        }
        if (request.getPaidOnly())
        {
            writer.writePropertyName("paidOnly");
            writer.writeBool(*request.getPaidOnly());
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
	 * ユーザーIDを指定してウォレットの概要から残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawByUserId(std::function<void(AsyncWithdrawByUserIdResult&)> callback, WithdrawByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<WithdrawByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.withdrawByUserId");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getSlot()) {
            Char urlSafeValue[32];
            Int32 value = *request.getSlot();
            std::sprintf(urlSafeValue, "%d", value);
            url += "&" + detail::StringVariable("slot={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCount())
        {
            writer.writePropertyName("count");
            writer.writeInt32(*request.getCount());
        }
        if (request.getPaidOnly())
        {
            writer.writePropertyName("paidOnly");
            writer.writeBool(*request.getPaidOnly());
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
	 * スタンプシートを使用してウォレットの概要に残高を加算します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositByStampSheet(std::function<void(AsyncDepositByStampSheetResult&)> callback, DepositByStampSheetRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DepositByStampSheetResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.depositByStampSheet");
        if (request.getStampSheet()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getStampSheet(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("stampSheet={value}").replace("{value}", urlSafeValue);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
	 * スタンプシートを使用してウォレットの概要に残高を加算します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositWithReceiptByStampSheet(std::function<void(AsyncDepositWithReceiptByStampSheetResult&)> callback, DepositWithReceiptByStampSheetRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DepositWithReceiptByStampSheetResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.depositWithReceiptByStampSheet");
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
        if (request.getReceipt())
        {
            writer.writePropertyName("receipt");
            writer.writeCharArray(*request.getReceipt());
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
	 * ウォレットの概要から残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawByStampTask(std::function<void(AsyncWithdrawByStampTaskResult&)> callback, WithdrawByStampTaskRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<WithdrawByStampTaskResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FWalletFunctionHandler.withdrawByStampTask");
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
	 * レシートの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceipts(std::function<void(AsyncDescribeReceiptsResult&)> callback, DescribeReceiptsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeReceiptsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FReceiptFunctionHandler.describeReceipts");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getBegin()) {
            Char urlSafeValue[32];
            Int64 value = *request.getBegin();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("begin={value}").replace("{value}", urlSafeValue);
        }
        if (request.getEnd()) {
            Char urlSafeValue[32];
            Int64 value = *request.getEnd();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("end={value}").replace("{value}", urlSafeValue);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * レシートの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceiptsByUserIdAndSlot(std::function<void(AsyncDescribeReceiptsByUserIdAndSlotResult&)> callback, DescribeReceiptsByUserIdAndSlotRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeReceiptsByUserIdAndSlotResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FReceiptFunctionHandler.describeReceiptsByUserIdAndSlot");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getSlot()) {
            Char urlSafeValue[32];
            Int32 value = *request.getSlot();
            std::sprintf(urlSafeValue, "%d", value);
            url += "&" + detail::StringVariable("slot={value}").replace("{value}", urlSafeValue);
        }
        if (request.getBegin()) {
            Char urlSafeValue[32];
            Int64 value = *request.getBegin();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("begin={value}").replace("{value}", urlSafeValue);
        }
        if (request.getEnd()) {
            Char urlSafeValue[32];
            Int64 value = *request.getEnd();
            std::sprintf(urlSafeValue, "%lld", value);
            url += "&" + detail::StringVariable("end={value}").replace("{value}", urlSafeValue);
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
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * レシートの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getByUserIdAndTransactionId(std::function<void(AsyncGetByUserIdAndTransactionIdResult&)> callback, GetByUserIdAndTransactionIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetByUserIdAndTransactionIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/money-handler?handler=gs2_money%2Fhandler%2FReceiptFunctionHandler.getByUserIdAndTransactionId");
        if (request.getMoneyName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getMoneyName(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("moneyName={value}").replace("{value}", urlSafeValue);
        }
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", urlSafeValue);
        }
        if (request.getTransactionId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getTransactionId(), sizeof(urlSafeValue));
            url += "&" + detail::StringVariable("transactionId={value}").replace("{value}", urlSafeValue);
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
        authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_MONEY_GS2MONEYCLIENT_HPP_