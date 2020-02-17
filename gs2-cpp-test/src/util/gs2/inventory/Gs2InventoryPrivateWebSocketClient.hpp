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

#ifndef GS2_INVENTORY_GS2INVENTORYPRIVATEWEBSOCKETCLIENT_HPP_
#define GS2_INVENTORY_GS2INVENTORYPRIVATEWEBSOCKETCLIENT_HPP_

#include <gs2/inventory/Gs2InventoryWebSocketClient.hpp>
#include "request/DescribeNamespacesByOwnerIdRequest.hpp"
#include "result/DescribeNamespacesByOwnerIdResult.hpp"

namespace gs2 { namespace inventory {

/**
 * GS2 Inventory API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2InventoryPrivateWebSocketClient : public Gs2InventoryWebSocketClient
{
private:

    class DescribeNamespacesByOwnerIdTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesByOwnerIdResult>
    {
    private:
        DescribeNamespacesByOwnerIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inventory";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeNamespacesByOwnerId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getOwnerId())
            {
                jsonWriter.writePropertyName("ownerId");
                jsonWriter.writeCharArray(*m_Request.getOwnerId());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DescribeNamespacesByOwnerIdTask(
            DescribeNamespacesByOwnerIdRequest request,
            Gs2WebSocketSessionTask<DescribeNamespacesByOwnerIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNamespacesByOwnerIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNamespacesByOwnerIdTask() GS2_OVERRIDE = default;
    };

public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2InventoryPrivateWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        Gs2InventoryWebSocketClient(gs2WebSocketSession)
    {
    }

	/**
	 * オーナーIDを指定してネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespacesByOwnerId(DescribeNamespacesByOwnerIdRequest request, std::function<void(AsyncDescribeNamespacesByOwnerIdResult)> callback)
    {
        DescribeNamespacesByOwnerIdTask& task = *new DescribeNamespacesByOwnerIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }
};

} }

#endif //GS2_INVENTORY_GS2INVENTORYPRIVATEWEBSOCKETCLIENT_HPP_