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

#ifndef GS2_MONEY_GS2MONEYWEBSOCKETCLIENT_HPP_
#define GS2_MONEY_GS2MONEYWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
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
class Gs2MoneyWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("describeNamespaces");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeNamespacesTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeNamespacesRequest& request,
            Gs2WebSocketSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNamespacesResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getName())
            {
                writer.writePropertyName("name");
                writer.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getPriority())
            {
                writer.writePropertyName("priority");
                writer.writeCharArray(*m_Request.getPriority());
            }
            if (m_Request.getShareFree())
            {
                writer.writePropertyName("shareFree");
                writer.writeBool(*m_Request.getShareFree());
            }
            if (m_Request.getCurrency())
            {
                writer.writePropertyName("currency");
                writer.writeCharArray(*m_Request.getCurrency());
            }
            if (m_Request.getAppleKey())
            {
                writer.writePropertyName("appleKey");
                writer.writeCharArray(*m_Request.getAppleKey());
            }
            if (m_Request.getGoogleKey())
            {
                writer.writePropertyName("googleKey");
                writer.writeCharArray(*m_Request.getGoogleKey());
            }
            if (m_Request.getEnableFakeReceipt())
            {
                writer.writePropertyName("enableFakeReceipt");
                writer.writeBool(*m_Request.getEnableFakeReceipt());
            }
            if (m_Request.getCreateWalletTriggerScriptId())
            {
                writer.writePropertyName("createWalletTriggerScriptId");
                writer.writeCharArray(*m_Request.getCreateWalletTriggerScriptId());
            }
            if (m_Request.getCreateWalletDoneTriggerScriptId())
            {
                writer.writePropertyName("createWalletDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getCreateWalletDoneTriggerScriptId());
            }
            if (m_Request.getCreateWalletDoneTriggerNamespaceId())
            {
                writer.writePropertyName("createWalletDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getCreateWalletDoneTriggerNamespaceId());
            }
            if (m_Request.getDepositTriggerScriptId())
            {
                writer.writePropertyName("depositTriggerScriptId");
                writer.writeCharArray(*m_Request.getDepositTriggerScriptId());
            }
            if (m_Request.getDepositDoneTriggerScriptId())
            {
                writer.writePropertyName("depositDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getDepositDoneTriggerScriptId());
            }
            if (m_Request.getDepositDoneTriggerNamespaceId())
            {
                writer.writePropertyName("depositDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getDepositDoneTriggerNamespaceId());
            }
            if (m_Request.getWithdrawTriggerScriptId())
            {
                writer.writePropertyName("withdrawTriggerScriptId");
                writer.writeCharArray(*m_Request.getWithdrawTriggerScriptId());
            }
            if (m_Request.getWithdrawDoneTriggerScriptId())
            {
                writer.writePropertyName("withdrawDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getWithdrawDoneTriggerScriptId());
            }
            if (m_Request.getWithdrawDoneTriggerNamespaceId())
            {
                writer.writePropertyName("withdrawDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getWithdrawDoneTriggerNamespaceId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("createNamespace");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        CreateNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            CreateNamespaceRequest& request,
            Gs2WebSocketSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2WebSocketSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("getNamespaceStatus");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetNamespaceStatusTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetNamespaceStatusRequest& request,
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2WebSocketSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("getNamespace");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetNamespaceRequest& request,
            Gs2WebSocketSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2WebSocketSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDescription())
            {
                writer.writePropertyName("description");
                writer.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getPriority())
            {
                writer.writePropertyName("priority");
                writer.writeCharArray(*m_Request.getPriority());
            }
            if (m_Request.getAppleKey())
            {
                writer.writePropertyName("appleKey");
                writer.writeCharArray(*m_Request.getAppleKey());
            }
            if (m_Request.getGoogleKey())
            {
                writer.writePropertyName("googleKey");
                writer.writeCharArray(*m_Request.getGoogleKey());
            }
            if (m_Request.getEnableFakeReceipt())
            {
                writer.writePropertyName("enableFakeReceipt");
                writer.writeBool(*m_Request.getEnableFakeReceipt());
            }
            if (m_Request.getCreateWalletTriggerScriptId())
            {
                writer.writePropertyName("createWalletTriggerScriptId");
                writer.writeCharArray(*m_Request.getCreateWalletTriggerScriptId());
            }
            if (m_Request.getCreateWalletDoneTriggerScriptId())
            {
                writer.writePropertyName("createWalletDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getCreateWalletDoneTriggerScriptId());
            }
            if (m_Request.getCreateWalletDoneTriggerNamespaceId())
            {
                writer.writePropertyName("createWalletDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getCreateWalletDoneTriggerNamespaceId());
            }
            if (m_Request.getDepositTriggerScriptId())
            {
                writer.writePropertyName("depositTriggerScriptId");
                writer.writeCharArray(*m_Request.getDepositTriggerScriptId());
            }
            if (m_Request.getDepositDoneTriggerScriptId())
            {
                writer.writePropertyName("depositDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getDepositDoneTriggerScriptId());
            }
            if (m_Request.getDepositDoneTriggerNamespaceId())
            {
                writer.writePropertyName("depositDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getDepositDoneTriggerNamespaceId());
            }
            if (m_Request.getWithdrawTriggerScriptId())
            {
                writer.writePropertyName("withdrawTriggerScriptId");
                writer.writeCharArray(*m_Request.getWithdrawTriggerScriptId());
            }
            if (m_Request.getWithdrawDoneTriggerScriptId())
            {
                writer.writePropertyName("withdrawDoneTriggerScriptId");
                writer.writeCharArray(*m_Request.getWithdrawDoneTriggerScriptId());
            }
            if (m_Request.getWithdrawDoneTriggerNamespaceId())
            {
                writer.writePropertyName("withdrawDoneTriggerNamespaceId");
                writer.writeCharArray(*m_Request.getWithdrawDoneTriggerNamespaceId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("updateNamespace");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        UpdateNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            UpdateNamespaceRequest& request,
            Gs2WebSocketSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateNamespaceResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteNamespaceRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("namespace");
            writer.writePropertyName("function");
            writer.writeCharArray("deleteNamespace");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DeleteNamespaceTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DeleteNamespaceRequest& request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeWalletsTask : public detail::Gs2WebSocketSessionTask<DescribeWalletsResult>
    {
    private:
        DescribeWalletsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("describeWallets");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeWalletsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeWalletsRequest& request,
            Gs2WebSocketSessionTask<DescribeWalletsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeWalletsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeWalletsTask() GS2_OVERRIDE = default;
    };

    class DescribeWalletsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeWalletsByUserIdResult>
    {
    private:
        DescribeWalletsByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("describeWalletsByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeWalletsByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeWalletsByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeWalletsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeWalletsByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeWalletsByUserIdTask() GS2_OVERRIDE = default;
    };

    class QueryWalletsTask : public detail::Gs2WebSocketSessionTask<QueryWalletsResult>
    {
    private:
        QueryWalletsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("queryWallets");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        QueryWalletsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            QueryWalletsRequest& request,
            Gs2WebSocketSessionTask<QueryWalletsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<QueryWalletsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~QueryWalletsTask() GS2_OVERRIDE = default;
    };

    class GetWalletTask : public detail::Gs2WebSocketSessionTask<GetWalletResult>
    {
    private:
        GetWalletRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSlot())
            {
                writer.writePropertyName("slot");
                writer.writeInt32(*m_Request.getSlot());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("getWallet");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetWalletTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetWalletRequest& request,
            Gs2WebSocketSessionTask<GetWalletResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetWalletResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetWalletTask() GS2_OVERRIDE = default;
    };

    class GetWalletByUserIdTask : public detail::Gs2WebSocketSessionTask<GetWalletByUserIdResult>
    {
    private:
        GetWalletByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getSlot())
            {
                writer.writePropertyName("slot");
                writer.writeInt32(*m_Request.getSlot());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("getWalletByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetWalletByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetWalletByUserIdRequest& request,
            Gs2WebSocketSessionTask<GetWalletByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetWalletByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetWalletByUserIdTask() GS2_OVERRIDE = default;
    };

    class DepositByUserIdTask : public detail::Gs2WebSocketSessionTask<DepositByUserIdResult>
    {
    private:
        DepositByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getSlot())
            {
                writer.writePropertyName("slot");
                writer.writeInt32(*m_Request.getSlot());
            }
            if (m_Request.getPrice())
            {
                writer.writePropertyName("price");
                writer.writeFloat(*m_Request.getPrice());
            }
            if (m_Request.getCount())
            {
                writer.writePropertyName("count");
                writer.writeInt32(*m_Request.getCount());
            }
            if (m_Request.getTransactionId())
            {
                writer.writePropertyName("transactionId");
                writer.writeCharArray(*m_Request.getTransactionId());
            }
            if (m_Request.getContentsId())
            {
                writer.writePropertyName("contentsId");
                writer.writeCharArray(*m_Request.getContentsId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("depositByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DepositByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DepositByUserIdRequest& request,
            Gs2WebSocketSessionTask<DepositByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DepositByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DepositByUserIdTask() GS2_OVERRIDE = default;
    };

    class WithdrawTask : public detail::Gs2WebSocketSessionTask<WithdrawResult>
    {
    private:
        WithdrawRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getSlot())
            {
                writer.writePropertyName("slot");
                writer.writeInt32(*m_Request.getSlot());
            }
            if (m_Request.getCount())
            {
                writer.writePropertyName("count");
                writer.writeInt32(*m_Request.getCount());
            }
            if (m_Request.getPaidOnly())
            {
                writer.writePropertyName("paidOnly");
                writer.writeBool(*m_Request.getPaidOnly());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                writer.writePropertyName("xGs2AccessToken");
                writer.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("withdraw");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        WithdrawTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            WithdrawRequest& request,
            Gs2WebSocketSessionTask<WithdrawResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<WithdrawResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~WithdrawTask() GS2_OVERRIDE = default;
    };

    class WithdrawByUserIdTask : public detail::Gs2WebSocketSessionTask<WithdrawByUserIdResult>
    {
    private:
        WithdrawByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getSlot())
            {
                writer.writePropertyName("slot");
                writer.writeInt32(*m_Request.getSlot());
            }
            if (m_Request.getCount())
            {
                writer.writePropertyName("count");
                writer.writeInt32(*m_Request.getCount());
            }
            if (m_Request.getPaidOnly())
            {
                writer.writePropertyName("paidOnly");
                writer.writeBool(*m_Request.getPaidOnly());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("withdrawByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        WithdrawByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            WithdrawByUserIdRequest& request,
            Gs2WebSocketSessionTask<WithdrawByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<WithdrawByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~WithdrawByUserIdTask() GS2_OVERRIDE = default;
    };

    class DepositByStampSheetTask : public detail::Gs2WebSocketSessionTask<DepositByStampSheetResult>
    {
    private:
        DepositByStampSheetRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getStampSheet())
            {
                writer.writePropertyName("stampSheet");
                writer.writeCharArray(*m_Request.getStampSheet());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("depositByStampSheet");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DepositByStampSheetTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DepositByStampSheetRequest& request,
            Gs2WebSocketSessionTask<DepositByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DepositByStampSheetResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DepositByStampSheetTask() GS2_OVERRIDE = default;
    };

    class WithdrawByStampTaskTask : public detail::Gs2WebSocketSessionTask<WithdrawByStampTaskResult>
    {
    private:
        WithdrawByStampTaskRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getStampTask())
            {
                writer.writePropertyName("stampTask");
                writer.writeCharArray(*m_Request.getStampTask());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("wallet");
            writer.writePropertyName("function");
            writer.writeCharArray("withdrawByStampTask");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        WithdrawByStampTaskTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            WithdrawByStampTaskRequest& request,
            Gs2WebSocketSessionTask<WithdrawByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<WithdrawByStampTaskResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~WithdrawByStampTaskTask() GS2_OVERRIDE = default;
    };

    class DescribeWalletDetailsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeWalletDetailsByUserIdResult>
    {
    private:
        DescribeWalletDetailsByUserIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getSlot())
            {
                writer.writePropertyName("slot");
                writer.writeInt32(*m_Request.getSlot());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("walletDetail");
            writer.writePropertyName("function");
            writer.writeCharArray("describeWalletDetailsByUserId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeWalletDetailsByUserIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeWalletDetailsByUserIdRequest& request,
            Gs2WebSocketSessionTask<DescribeWalletDetailsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeWalletDetailsByUserIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeWalletDetailsByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeReceiptsTask : public detail::Gs2WebSocketSessionTask<DescribeReceiptsResult>
    {
    private:
        DescribeReceiptsRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getSlot())
            {
                writer.writePropertyName("slot");
                writer.writeInt32(*m_Request.getSlot());
            }
            if (m_Request.getBegin())
            {
                writer.writePropertyName("begin");
                writer.writeInt64(*m_Request.getBegin());
            }
            if (m_Request.getEnd())
            {
                writer.writePropertyName("end");
                writer.writeInt64(*m_Request.getEnd());
            }
            if (m_Request.getPageToken())
            {
                writer.writePropertyName("pageToken");
                writer.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                writer.writePropertyName("limit");
                writer.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("receipt");
            writer.writePropertyName("function");
            writer.writeCharArray("describeReceipts");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        DescribeReceiptsTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            DescribeReceiptsRequest& request,
            Gs2WebSocketSessionTask<DescribeReceiptsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeReceiptsResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~DescribeReceiptsTask() GS2_OVERRIDE = default;
    };

    class GetByUserIdAndTransactionIdTask : public detail::Gs2WebSocketSessionTask<GetByUserIdAndTransactionIdResult>
    {
    private:
        GetByUserIdAndTransactionIdRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getTransactionId())
            {
                writer.writePropertyName("transactionId");
                writer.writeCharArray(*m_Request.getTransactionId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("receipt");
            writer.writePropertyName("function");
            writer.writeCharArray("getByUserIdAndTransactionId");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        GetByUserIdAndTransactionIdTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            GetByUserIdAndTransactionIdRequest& request,
            Gs2WebSocketSessionTask<GetByUserIdAndTransactionIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetByUserIdAndTransactionIdResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~GetByUserIdAndTransactionIdTask() GS2_OVERRIDE = default;
    };

    class RecordReceiptTask : public detail::Gs2WebSocketSessionTask<RecordReceiptResult>
    {
    private:
        RecordReceiptRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getNamespaceName())
            {
                writer.writePropertyName("namespaceName");
                writer.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                writer.writePropertyName("userId");
                writer.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getContentsId())
            {
                writer.writePropertyName("contentsId");
                writer.writeCharArray(*m_Request.getContentsId());
            }
            if (m_Request.getReceipt())
            {
                writer.writePropertyName("receipt");
                writer.writeCharArray(*m_Request.getReceipt());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("receipt");
            writer.writePropertyName("function");
            writer.writeCharArray("recordReceipt");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        RecordReceiptTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            RecordReceiptRequest& request,
            Gs2WebSocketSessionTask<RecordReceiptResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RecordReceiptResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~RecordReceiptTask() GS2_OVERRIDE = default;
    };

    class RecordReceiptByStampTaskTask : public detail::Gs2WebSocketSessionTask<RecordReceiptByStampTaskResult>
    {
    private:
        RecordReceiptByStampTaskRequest& m_Request;

        void sendImpl(
            const StringHolder& clientId,
            const StringHolder& projectToken,
            const detail::Gs2SessionTaskId& gs2SessionTaskId
        ) GS2_OVERRIDE
        {
            detail::json::JsonWriter writer;

            writer.writeObjectStart();

            if (m_Request.getStampTask())
            {
                writer.writePropertyName("stampTask");
                writer.writeCharArray(*m_Request.getStampTask());
            }
            if (m_Request.getKeyId())
            {
                writer.writePropertyName("keyId");
                writer.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getRequestId())
            {
                writer.writePropertyName("xGs2RequestId");
                writer.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                writer.writePropertyName("xGs2DuplicationAvoider");
                writer.writeCharArray(*m_Request.getDuplicationAvoider());
            }

            writer.writePropertyName("xGs2ClientId");
            writer.writeCharArray(clientId);
            writer.writePropertyName("xGs2ProjectToken");
            writer.writeCharArray(projectToken);

            writer.writePropertyName("x_gs2");
            writer.writeObjectStart();
            writer.writePropertyName("service");
            writer.writeCharArray("money");
            writer.writePropertyName("component");
            writer.writeCharArray("receipt");
            writer.writePropertyName("function");
            writer.writeCharArray("recordReceiptByStampTask");
            writer.writePropertyName("contentType");
            writer.writeCharArray("application/json");
            writer.writePropertyName("requestId");
            {
                char buffer[16];
                gs2SessionTaskId.exportTo(buffer, sizeof(buffer));
                writer.writeCharArray(buffer);
            }
            writer.writeObjectEnd();

            writer.writeObjectEnd();

            auto body = writer.toString();
            send(body);
        }

    public:
        RecordReceiptByStampTaskTask(
            Gs2WebSocketSession& gs2WebSocketSession,
            RecordReceiptByStampTaskRequest& request,
            Gs2WebSocketSessionTask<RecordReceiptByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RecordReceiptByStampTaskResult>(gs2WebSocketSession, callback),
            m_Request(request)
        {}

        ~RecordReceiptByStampTaskTask() GS2_OVERRIDE = default;
    };

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
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2MoneyWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
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
        DescribeNamespacesTask& task = *new DescribeNamespacesTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(std::function<void(AsyncCreateNamespaceResult&)> callback, CreateNamespaceRequest& request)
    {
        CreateNamespaceTask& task = *new CreateNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースの状態を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(std::function<void(AsyncGetNamespaceStatusResult&)> callback, GetNamespaceStatusRequest& request)
    {
        GetNamespaceStatusTask& task = *new GetNamespaceStatusTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(std::function<void(AsyncGetNamespaceResult&)> callback, GetNamespaceRequest& request)
    {
        GetNamespaceTask& task = *new GetNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(std::function<void(AsyncUpdateNamespaceResult&)> callback, UpdateNamespaceRequest& request)
    {
        UpdateNamespaceTask& task = *new UpdateNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ネームスペースを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(std::function<void(AsyncDeleteNamespaceResult&)> callback, DeleteNamespaceRequest& request)
    {
        DeleteNamespaceTask& task = *new DeleteNamespaceTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ウォレット一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWallets(std::function<void(AsyncDescribeWalletsResult&)> callback, DescribeWalletsRequest& request)
    {
        DescribeWalletsTask& task = *new DescribeWalletsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ウォレット一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWalletsByUserId(std::function<void(AsyncDescribeWalletsByUserIdResult&)> callback, DescribeWalletsByUserIdRequest& request)
    {
        DescribeWalletsByUserIdTask& task = *new DescribeWalletsByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ウォレット一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryWallets(std::function<void(AsyncQueryWalletsResult&)> callback, QueryWalletsRequest& request)
    {
        QueryWalletsTask& task = *new QueryWalletsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ウォレットを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWallet(std::function<void(AsyncGetWalletResult&)> callback, GetWalletRequest& request)
    {
        GetWalletTask& task = *new GetWalletTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定してウォレットを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWalletByUserId(std::function<void(AsyncGetWalletByUserIdResult&)> callback, GetWalletByUserIdRequest& request)
    {
        GetWalletByUserIdTask& task = *new GetWalletByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定してウォレットに残高を加算します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositByUserId(std::function<void(AsyncDepositByUserIdResult&)> callback, DepositByUserIdRequest& request)
    {
        DepositByUserIdTask& task = *new DepositByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ウォレットから残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdraw(std::function<void(AsyncWithdrawResult&)> callback, WithdrawRequest& request)
    {
        WithdrawTask& task = *new WithdrawTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ユーザーIDを指定してウォレットから残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawByUserId(std::function<void(AsyncWithdrawByUserIdResult&)> callback, WithdrawByUserIdRequest& request)
    {
        WithdrawByUserIdTask& task = *new WithdrawByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートを使用してウォレットに残高を加算します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositByStampSheet(std::function<void(AsyncDepositByStampSheetResult&)> callback, DepositByStampSheetRequest& request)
    {
        DepositByStampSheetTask& task = *new DepositByStampSheetTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ウォレットから残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawByStampTask(std::function<void(AsyncWithdrawByStampTaskResult&)> callback, WithdrawByStampTaskRequest& request)
    {
        WithdrawByStampTaskTask& task = *new WithdrawByStampTaskTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * ウォレットの詳細を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWalletDetailsByUserId(std::function<void(AsyncDescribeWalletDetailsByUserIdResult&)> callback, DescribeWalletDetailsByUserIdRequest& request)
    {
        DescribeWalletDetailsByUserIdTask& task = *new DescribeWalletDetailsByUserIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * レシートの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceipts(std::function<void(AsyncDescribeReceiptsResult&)> callback, DescribeReceiptsRequest& request)
    {
        DescribeReceiptsTask& task = *new DescribeReceiptsTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * レシートの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getByUserIdAndTransactionId(std::function<void(AsyncGetByUserIdAndTransactionIdResult&)> callback, GetByUserIdAndTransactionIdRequest& request)
    {
        GetByUserIdAndTransactionIdTask& task = *new GetByUserIdAndTransactionIdTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * レシートを記録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recordReceipt(std::function<void(AsyncRecordReceiptResult&)> callback, RecordReceiptRequest& request)
    {
        RecordReceiptTask& task = *new RecordReceiptTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

	/**
	 * スタンプシートを使用してレシートを記録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recordReceiptByStampTask(std::function<void(AsyncRecordReceiptByStampTaskResult&)> callback, RecordReceiptByStampTaskRequest& request)
    {
        RecordReceiptByStampTaskTask& task = *new RecordReceiptByStampTaskTask(getGs2WebSocketSession(), request, callback);
        task.execute();
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MONEY_GS2MONEYWEBSOCKETCLIENT_HPP_