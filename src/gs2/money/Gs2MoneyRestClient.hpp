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

#ifndef GS2_MONEY_GS2MONEYRESTCLIENT_HPP_
#define GS2_MONEY_GS2MONEYRESTCLIENT_HPP_

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
#include "request/DescribeWalletsRequest.hpp"
#include "request/DescribeWalletsByUserIdRequest.hpp"
#include "request/QueryWalletsRequest.hpp"
#include "request/GetWalletRequest.hpp"
#include "request/GetWalletByUserIdRequest.hpp"
#include "request/DepositByUserIdRequest.hpp"
#include "request/WithdrawRequest.hpp"
#include "request/WithdrawByUserIdRequest.hpp"
#include "request/DepositByStampSheetRequest.hpp"
#include "request/WithdrawByStampTaskRequest.hpp"
#include "request/DescribeWalletDetailsByUserIdRequest.hpp"
#include "request/DescribeReceiptsRequest.hpp"
#include "request/GetByUserIdAndTransactionIdRequest.hpp"
#include "request/RecordReceiptRequest.hpp"
#include "request/RecordReceiptByStampTaskRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeWalletsResult.hpp"
#include "result/DescribeWalletsByUserIdResult.hpp"
#include "result/QueryWalletsResult.hpp"
#include "result/GetWalletResult.hpp"
#include "result/GetWalletByUserIdResult.hpp"
#include "result/DepositByUserIdResult.hpp"
#include "result/WithdrawResult.hpp"
#include "result/WithdrawByUserIdResult.hpp"
#include "result/DepositByStampSheetResult.hpp"
#include "result/WithdrawByStampTaskResult.hpp"
#include "result/DescribeWalletDetailsByUserIdResult.hpp"
#include "result/DescribeReceiptsResult.hpp"
#include "result/GetByUserIdAndTransactionIdResult.hpp"
#include "result/RecordReceiptResult.hpp"
#include "result/RecordReceiptByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace money {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<void> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeWalletsResult> AsyncDescribeWalletsResult;
typedef AsyncResult<DescribeWalletsByUserIdResult> AsyncDescribeWalletsByUserIdResult;
typedef AsyncResult<QueryWalletsResult> AsyncQueryWalletsResult;
typedef AsyncResult<GetWalletResult> AsyncGetWalletResult;
typedef AsyncResult<GetWalletByUserIdResult> AsyncGetWalletByUserIdResult;
typedef AsyncResult<DepositByUserIdResult> AsyncDepositByUserIdResult;
typedef AsyncResult<WithdrawResult> AsyncWithdrawResult;
typedef AsyncResult<WithdrawByUserIdResult> AsyncWithdrawByUserIdResult;
typedef AsyncResult<DepositByStampSheetResult> AsyncDepositByStampSheetResult;
typedef AsyncResult<WithdrawByStampTaskResult> AsyncWithdrawByStampTaskResult;
typedef AsyncResult<DescribeWalletDetailsByUserIdResult> AsyncDescribeWalletDetailsByUserIdResult;
typedef AsyncResult<DescribeReceiptsResult> AsyncDescribeReceiptsResult;
typedef AsyncResult<GetByUserIdAndTransactionIdResult> AsyncGetByUserIdAndTransactionIdResult;
typedef AsyncResult<RecordReceiptResult> AsyncRecordReceiptResult;
typedef AsyncResult<RecordReceiptByStampTaskResult> AsyncRecordReceiptByStampTaskResult;

/**
 * GS2 Money API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MoneyRestClient : public AbstractGs2ClientBase
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
        if (obj.getCreateWalletDoneTriggerNamespaceId())
        {
            writer.writePropertyName("createWalletDoneTriggerNamespaceId");
            writer.writeCharArray(*obj.getCreateWalletDoneTriggerNamespaceId());
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
        if (obj.getDepositDoneTriggerNamespaceId())
        {
            writer.writePropertyName("depositDoneTriggerNamespaceId");
            writer.writeCharArray(*obj.getDepositDoneTriggerNamespaceId());
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
        if (obj.getWithdrawDoneTriggerNamespaceId())
        {
            writer.writePropertyName("withdrawDoneTriggerNamespaceId");
            writer.writeCharArray(*obj.getWithdrawDoneTriggerNamespaceId());
        }
        if (obj.getBalance())
        {
            writer.writePropertyName("balance");
            writer.writeDouble(*obj.getBalance());
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

    static void write(detail::json::JsonWriter& writer, const Wallet& obj)
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

    static void write(detail::json::JsonWriter& writer, const WalletDetail& obj)
    {
        writer.writeObjectStart();
        if (obj.getWalletDetailId())
        {
            writer.writePropertyName("walletDetailId");
            writer.writeCharArray(*obj.getWalletDetailId());
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

    static void write(detail::json::JsonWriter& writer, const Receipt& obj)
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
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
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
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2MoneyRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(std::function<void(AsyncDescribeNamespacesResult&)> callback, DescribeNamespacesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeNamespacesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
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
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(std::function<void(AsyncCreateNamespaceResult&)> callback, CreateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";
        httpRequest.SetURL(url.c_str());
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
        if (request.getCreateWalletDoneTriggerNamespaceId())
        {
            writer.writePropertyName("createWalletDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getCreateWalletDoneTriggerNamespaceId());
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
        if (request.getDepositDoneTriggerNamespaceId())
        {
            writer.writePropertyName("depositDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getDepositDoneTriggerNamespaceId());
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
        if (request.getWithdrawDoneTriggerNamespaceId())
        {
            writer.writePropertyName("withdrawDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getWithdrawDoneTriggerNamespaceId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースの状態を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(std::function<void(AsyncGetNamespaceStatusResult&)> callback, GetNamespaceStatusRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceStatusResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(std::function<void(AsyncGetNamespaceResult&)> callback, GetNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(std::function<void(AsyncUpdateNamespaceResult&)> callback, UpdateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
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
        if (request.getCreateWalletDoneTriggerNamespaceId())
        {
            writer.writePropertyName("createWalletDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getCreateWalletDoneTriggerNamespaceId());
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
        if (request.getDepositDoneTriggerNamespaceId())
        {
            writer.writePropertyName("depositDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getDepositDoneTriggerNamespaceId());
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
        if (request.getWithdrawDoneTriggerNamespaceId())
        {
            writer.writePropertyName("withdrawDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getWithdrawDoneTriggerNamespaceId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(std::function<void(AsyncDeleteNamespaceResult&)> callback, DeleteNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ウォレット一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWallets(std::function<void(AsyncDescribeWalletsResult&)> callback, DescribeWalletsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeWalletsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/wallet";
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
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ウォレット一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWalletsByUserId(std::function<void(AsyncDescribeWalletsByUserIdResult&)> callback, DescribeWalletsByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeWalletsByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/wallet";
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
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ウォレット一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryWallets(std::function<void(AsyncQueryWalletsResult&)> callback, QueryWalletsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<QueryWalletsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/wallet/query";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += joint;
            url += "userId=";
            url += urlSafeValue;
            joint[0] = '&';
        }
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
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ウォレットを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWallet(std::function<void(AsyncGetWalletResult&)> callback, GetWalletRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetWalletResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/wallet/{slot}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getSlot();
            if (value.has_value())
            {
                Char urlSafeValue[32];
                std::sprintf(urlSafeValue, "%d", *value);
                url.replace("{slot}", urlSafeValue);
            }
            else
            {
                url.replace("{slot}", "null");
            }
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザーIDを指定してウォレットを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWalletByUserId(std::function<void(AsyncGetWalletByUserIdResult&)> callback, GetWalletByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetWalletByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/wallet/{slot}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getSlot();
            if (value.has_value())
            {
                Char urlSafeValue[32];
                std::sprintf(urlSafeValue, "%d", *value);
                url.replace("{slot}", urlSafeValue);
            }
            else
            {
                url.replace("{slot}", "null");
            }
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザーIDを指定してウォレットに残高を加算します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositByUserId(std::function<void(AsyncDepositByUserIdResult&)> callback, DepositByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DepositByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/wallet/{slot}/deposit";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getSlot();
            if (value.has_value())
            {
                Char urlSafeValue[32];
                std::sprintf(urlSafeValue, "%d", *value);
                url.replace("{slot}", urlSafeValue);
            }
            else
            {
                url.replace("{slot}", "null");
            }
        }
        httpRequest.SetURL(url.c_str());
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
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ウォレットから残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdraw(std::function<void(AsyncWithdrawResult&)> callback, WithdrawRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<WithdrawResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/wallet/{slot}/withdraw";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getSlot();
            if (value.has_value())
            {
                Char urlSafeValue[32];
                std::sprintf(urlSafeValue, "%d", *value);
                url.replace("{slot}", urlSafeValue);
            }
            else
            {
                url.replace("{slot}", "null");
            }
        }
        httpRequest.SetURL(url.c_str());
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
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザーIDを指定してウォレットから残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawByUserId(std::function<void(AsyncWithdrawByUserIdResult&)> callback, WithdrawByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<WithdrawByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/wallet/{slot}/withdraw";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getSlot();
            if (value.has_value())
            {
                Char urlSafeValue[32];
                std::sprintf(urlSafeValue, "%d", *value);
                url.replace("{slot}", urlSafeValue);
            }
            else
            {
                url.replace("{slot}", "null");
            }
        }
        httpRequest.SetURL(url.c_str());
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
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * スタンプシートを使用してウォレットに残高を加算します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositByStampSheet(std::function<void(AsyncDepositByStampSheetResult&)> callback, DepositByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DepositByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/deposit";
        {
            auto& value = request.getStampSheet();
            url.replace("{stampSheet}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ウォレットから残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawByStampTask(std::function<void(AsyncWithdrawByStampTaskResult&)> callback, WithdrawByStampTaskRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<WithdrawByStampTaskResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/withdraw";
        httpRequest.SetURL(url.c_str());
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
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ウォレットの詳細を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWalletDetailsByUserId(std::function<void(AsyncDescribeWalletDetailsByUserIdResult&)> callback, DescribeWalletDetailsByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeWalletDetailsByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/wallet/{slot}/detail";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getSlot();
            if (value.has_value())
            {
                Char urlSafeValue[32];
                std::sprintf(urlSafeValue, "%d", *value);
                url.replace("{slot}", urlSafeValue);
            }
            else
            {
                url.replace("{slot}", "null");
            }
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
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * レシートの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceipts(std::function<void(AsyncDescribeReceiptsResult&)> callback, DescribeReceiptsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeReceiptsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/receipt";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getUserId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getUserId(), sizeof(urlSafeValue));
            url += joint;
            url += "userId=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getSlot()) {
            Char urlSafeValue[32];
            Int32 value = *request.getSlot();
            std::sprintf(urlSafeValue, "%d", value);
            url += joint;
            url += "slot=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getBegin()) {
            Char urlSafeValue[32];
            Int64 value = *request.getBegin();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "begin=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getEnd()) {
            Char urlSafeValue[32];
            Int64 value = *request.getEnd();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "end=";
            url += urlSafeValue;
            joint[0] = '&';
        }
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
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * レシートの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getByUserIdAndTransactionId(std::function<void(AsyncGetByUserIdAndTransactionIdResult&)> callback, GetByUserIdAndTransactionIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetByUserIdAndTransactionIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/receipt/{transactionId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getTransactionId();
            url.replace("{transactionId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * レシートを記録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recordReceipt(std::function<void(AsyncRecordReceiptResult&)> callback, RecordReceiptRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<RecordReceiptResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/receipt";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getContentsId())
        {
            writer.writePropertyName("contentsId");
            writer.writeCharArray(*request.getContentsId());
        }
        if (request.getReceipt())
        {
            writer.writePropertyName("receipt");
            writer.writeCharArray(*request.getReceipt());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * スタンプシートを使用してレシートを記録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recordReceiptByStampTask(std::function<void(AsyncRecordReceiptByStampTaskResult&)> callback, RecordReceiptByStampTaskRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<RecordReceiptByStampTaskResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "money");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/receipt/record";
        {
            auto& value = request.getStampTask();
            url.replace("{stampTask}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MONEY_GS2MONEYRESTCLIENT_HPP_