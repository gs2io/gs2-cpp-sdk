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

#ifndef GS2_CHAT_GS2CHATWEBSOCKETCLIENT_HPP_
#define GS2_CHAT_GS2CHATWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeRoomsRequest.hpp"
#include "request/CreateRoomRequest.hpp"
#include "request/CreateRoomFromBackendRequest.hpp"
#include "request/GetRoomRequest.hpp"
#include "request/UpdateRoomRequest.hpp"
#include "request/DeleteRoomRequest.hpp"
#include "request/DeleteRoomFromBackendRequest.hpp"
#include "request/DescribeMessagesRequest.hpp"
#include "request/PostRequest.hpp"
#include "request/PostByUserIdRequest.hpp"
#include "request/GetMessageRequest.hpp"
#include "request/DeleteMessageRequest.hpp"
#include "request/DescribeSubscribesRequest.hpp"
#include "request/DescribeSubscribesByUserIdRequest.hpp"
#include "request/DescribeSubscribesByRoomNameRequest.hpp"
#include "request/SubscribeRequest.hpp"
#include "request/SubscribeByUserIdRequest.hpp"
#include "request/GetSubscribeRequest.hpp"
#include "request/GetSubscribeByUserIdRequest.hpp"
#include "request/UpdateNotificationTypeRequest.hpp"
#include "request/UpdateNotificationTypeByUserIdRequest.hpp"
#include "request/UnsubscribeRequest.hpp"
#include "request/UnsubscribeByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeRoomsResult.hpp"
#include "result/CreateRoomResult.hpp"
#include "result/CreateRoomFromBackendResult.hpp"
#include "result/GetRoomResult.hpp"
#include "result/UpdateRoomResult.hpp"
#include "result/DeleteRoomResult.hpp"
#include "result/DeleteRoomFromBackendResult.hpp"
#include "result/DescribeMessagesResult.hpp"
#include "result/PostResult.hpp"
#include "result/PostByUserIdResult.hpp"
#include "result/GetMessageResult.hpp"
#include "result/DeleteMessageResult.hpp"
#include "result/DescribeSubscribesResult.hpp"
#include "result/DescribeSubscribesByUserIdResult.hpp"
#include "result/DescribeSubscribesByRoomNameResult.hpp"
#include "result/SubscribeResult.hpp"
#include "result/SubscribeByUserIdResult.hpp"
#include "result/GetSubscribeResult.hpp"
#include "result/GetSubscribeByUserIdResult.hpp"
#include "result/UpdateNotificationTypeResult.hpp"
#include "result/UpdateNotificationTypeByUserIdResult.hpp"
#include "result/UnsubscribeResult.hpp"
#include "result/UnsubscribeByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace chat {

/**
 * GS2 Chat API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ChatWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeNamespaces";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        DescribeNamespacesTask(
            DescribeNamespacesRequest request,
            Gs2WebSocketSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNamespacesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getName())
            {
                jsonWriter.writePropertyName("name");
                jsonWriter.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getAllowCreateRoom())
            {
                jsonWriter.writePropertyName("allowCreateRoom");
                jsonWriter.writeBool(*m_Request.getAllowCreateRoom());
            }
            if (m_Request.getPostMessageScript())
            {
                jsonWriter.writePropertyName("postMessageScript");
                write(jsonWriter, *m_Request.getPostMessageScript());
            }
            if (m_Request.getCreateRoomScript())
            {
                jsonWriter.writePropertyName("createRoomScript");
                write(jsonWriter, *m_Request.getCreateRoomScript());
            }
            if (m_Request.getDeleteRoomScript())
            {
                jsonWriter.writePropertyName("deleteRoomScript");
                write(jsonWriter, *m_Request.getDeleteRoomScript());
            }
            if (m_Request.getSubscribeRoomScript())
            {
                jsonWriter.writePropertyName("subscribeRoomScript");
                write(jsonWriter, *m_Request.getSubscribeRoomScript());
            }
            if (m_Request.getUnsubscribeRoomScript())
            {
                jsonWriter.writePropertyName("unsubscribeRoomScript");
                write(jsonWriter, *m_Request.getUnsubscribeRoomScript());
            }
            if (m_Request.getPostNotification())
            {
                jsonWriter.writePropertyName("postNotification");
                write(jsonWriter, *m_Request.getPostNotification());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateNamespaceTask(
            CreateNamespaceRequest request,
            Gs2WebSocketSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2WebSocketSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getNamespaceStatus";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetNamespaceStatusTask(
            GetNamespaceStatusRequest request,
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2WebSocketSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetNamespaceTask(
            GetNamespaceRequest request,
            Gs2WebSocketSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2WebSocketSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getAllowCreateRoom())
            {
                jsonWriter.writePropertyName("allowCreateRoom");
                jsonWriter.writeBool(*m_Request.getAllowCreateRoom());
            }
            if (m_Request.getPostMessageScript())
            {
                jsonWriter.writePropertyName("postMessageScript");
                write(jsonWriter, *m_Request.getPostMessageScript());
            }
            if (m_Request.getCreateRoomScript())
            {
                jsonWriter.writePropertyName("createRoomScript");
                write(jsonWriter, *m_Request.getCreateRoomScript());
            }
            if (m_Request.getDeleteRoomScript())
            {
                jsonWriter.writePropertyName("deleteRoomScript");
                write(jsonWriter, *m_Request.getDeleteRoomScript());
            }
            if (m_Request.getSubscribeRoomScript())
            {
                jsonWriter.writePropertyName("subscribeRoomScript");
                write(jsonWriter, *m_Request.getSubscribeRoomScript());
            }
            if (m_Request.getUnsubscribeRoomScript())
            {
                jsonWriter.writePropertyName("unsubscribeRoomScript");
                write(jsonWriter, *m_Request.getUnsubscribeRoomScript());
            }
            if (m_Request.getPostNotification())
            {
                jsonWriter.writePropertyName("postNotification");
                write(jsonWriter, *m_Request.getPostNotification());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateNamespaceTask(
            UpdateNamespaceRequest request,
            Gs2WebSocketSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteNamespaceTask(
            DeleteNamespaceRequest request,
            Gs2WebSocketSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeRoomsTask : public detail::Gs2WebSocketSessionTask<DescribeRoomsResult>
    {
    private:
        DescribeRoomsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "room";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeRooms";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
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
        DescribeRoomsTask(
            DescribeRoomsRequest request,
            Gs2WebSocketSessionTask<DescribeRoomsResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeRoomsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRoomsTask() GS2_OVERRIDE = default;
    };

    class CreateRoomTask : public detail::Gs2WebSocketSessionTask<CreateRoomResult>
    {
    private:
        CreateRoomRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "room";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createRoom";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
            }
            if (m_Request.getWhiteListUserIds())
            {
                jsonWriter.writePropertyName("whiteListUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getWhiteListUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        CreateRoomTask(
            CreateRoomRequest request,
            Gs2WebSocketSessionTask<CreateRoomResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateRoomResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateRoomTask() GS2_OVERRIDE = default;
    };

    class CreateRoomFromBackendTask : public detail::Gs2WebSocketSessionTask<CreateRoomFromBackendResult>
    {
    private:
        CreateRoomFromBackendRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "room";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createRoomFromBackend";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
            }
            if (m_Request.getWhiteListUserIds())
            {
                jsonWriter.writePropertyName("whiteListUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getWhiteListUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        CreateRoomFromBackendTask(
            CreateRoomFromBackendRequest request,
            Gs2WebSocketSessionTask<CreateRoomFromBackendResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateRoomFromBackendResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateRoomFromBackendTask() GS2_OVERRIDE = default;
    };

    class GetRoomTask : public detail::Gs2WebSocketSessionTask<GetRoomResult>
    {
    private:
        GetRoomRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "room";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getRoom";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetRoomTask(
            GetRoomRequest request,
            Gs2WebSocketSessionTask<GetRoomResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetRoomResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRoomTask() GS2_OVERRIDE = default;
    };

    class UpdateRoomTask : public detail::Gs2WebSocketSessionTask<UpdateRoomResult>
    {
    private:
        UpdateRoomRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "room";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateRoom";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
            }
            if (m_Request.getWhiteListUserIds())
            {
                jsonWriter.writePropertyName("whiteListUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getWhiteListUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateRoomTask(
            UpdateRoomRequest request,
            Gs2WebSocketSessionTask<UpdateRoomResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateRoomResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateRoomTask() GS2_OVERRIDE = default;
    };

    class DeleteRoomTask : public detail::Gs2WebSocketSessionTask<DeleteRoomResult>
    {
    private:
        DeleteRoomRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "room";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteRoom";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteRoomTask(
            DeleteRoomRequest request,
            Gs2WebSocketSessionTask<DeleteRoomResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteRoomResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRoomTask() GS2_OVERRIDE = default;
    };

    class DeleteRoomFromBackendTask : public detail::Gs2WebSocketSessionTask<DeleteRoomFromBackendResult>
    {
    private:
        DeleteRoomFromBackendRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "room";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteRoomFromBackend";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteRoomFromBackendTask(
            DeleteRoomFromBackendRequest request,
            Gs2WebSocketSessionTask<DeleteRoomFromBackendResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteRoomFromBackendResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRoomFromBackendTask() GS2_OVERRIDE = default;
    };

    class DescribeMessagesTask : public detail::Gs2WebSocketSessionTask<DescribeMessagesResult>
    {
    private:
        DescribeMessagesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeMessages";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
            }
            if (m_Request.getStartAt())
            {
                jsonWriter.writePropertyName("startAt");
                jsonWriter.writeInt64(*m_Request.getStartAt());
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
        DescribeMessagesTask(
            DescribeMessagesRequest request,
            Gs2WebSocketSessionTask<DescribeMessagesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeMessagesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMessagesTask() GS2_OVERRIDE = default;
    };

    class PostTask : public detail::Gs2WebSocketSessionTask<PostResult>
    {
    private:
        PostRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "post";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getCategory())
            {
                jsonWriter.writePropertyName("category");
                jsonWriter.writeInt32(*m_Request.getCategory());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PostTask(
            PostRequest request,
            Gs2WebSocketSessionTask<PostResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PostResult>(callback),
            m_Request(std::move(request))
        {}

        ~PostTask() GS2_OVERRIDE = default;
    };

    class PostByUserIdTask : public detail::Gs2WebSocketSessionTask<PostByUserIdResult>
    {
    private:
        PostByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "postByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getCategory())
            {
                jsonWriter.writePropertyName("category");
                jsonWriter.writeInt32(*m_Request.getCategory());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getPassword())
            {
                jsonWriter.writePropertyName("password");
                jsonWriter.writeCharArray(*m_Request.getPassword());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PostByUserIdTask(
            PostByUserIdRequest request,
            Gs2WebSocketSessionTask<PostByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PostByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PostByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetMessageTask : public detail::Gs2WebSocketSessionTask<GetMessageResult>
    {
    private:
        GetMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getMessage";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetMessageTask(
            GetMessageRequest request,
            Gs2WebSocketSessionTask<GetMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMessageTask() GS2_OVERRIDE = default;
    };

    class DeleteMessageTask : public detail::Gs2WebSocketSessionTask<DeleteMessageResult>
    {
    private:
        DeleteMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "message";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteMessage";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getMessageName())
            {
                jsonWriter.writePropertyName("messageName");
                jsonWriter.writeCharArray(*m_Request.getMessageName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteMessageTask(
            DeleteMessageRequest request,
            Gs2WebSocketSessionTask<DeleteMessageResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMessageTask() GS2_OVERRIDE = default;
    };

    class DescribeSubscribesTask : public detail::Gs2WebSocketSessionTask<DescribeSubscribesResult>
    {
    private:
        DescribeSubscribesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeSubscribes";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
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
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeSubscribesTask(
            DescribeSubscribesRequest request,
            Gs2WebSocketSessionTask<DescribeSubscribesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeSubscribesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSubscribesTask() GS2_OVERRIDE = default;
    };

    class DescribeSubscribesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeSubscribesByUserIdResult>
    {
    private:
        DescribeSubscribesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeSubscribesByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
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
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeSubscribesByUserIdTask(
            DescribeSubscribesByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeSubscribesByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeSubscribesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSubscribesByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeSubscribesByRoomNameTask : public detail::Gs2WebSocketSessionTask<DescribeSubscribesByRoomNameResult>
    {
    private:
        DescribeSubscribesByRoomNameRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeSubscribesByRoomName";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
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
        DescribeSubscribesByRoomNameTask(
            DescribeSubscribesByRoomNameRequest request,
            Gs2WebSocketSessionTask<DescribeSubscribesByRoomNameResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeSubscribesByRoomNameResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSubscribesByRoomNameTask() GS2_OVERRIDE = default;
    };

    class SubscribeTask : public detail::Gs2WebSocketSessionTask<SubscribeResult>
    {
    private:
        SubscribeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getNotificationTypes())
            {
                jsonWriter.writePropertyName("notificationTypes");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getNotificationTypes();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        SubscribeTask(
            SubscribeRequest request,
            Gs2WebSocketSessionTask<SubscribeResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SubscribeResult>(callback),
            m_Request(std::move(request))
        {}

        ~SubscribeTask() GS2_OVERRIDE = default;
    };

    class SubscribeByUserIdTask : public detail::Gs2WebSocketSessionTask<SubscribeByUserIdResult>
    {
    private:
        SubscribeByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "subscribeByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getNotificationTypes())
            {
                jsonWriter.writePropertyName("notificationTypes");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getNotificationTypes();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        SubscribeByUserIdTask(
            SubscribeByUserIdRequest request,
            Gs2WebSocketSessionTask<SubscribeByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SubscribeByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SubscribeByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetSubscribeTask : public detail::Gs2WebSocketSessionTask<GetSubscribeResult>
    {
    private:
        GetSubscribeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getSubscribe";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetSubscribeTask(
            GetSubscribeRequest request,
            Gs2WebSocketSessionTask<GetSubscribeResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSubscribeResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSubscribeTask() GS2_OVERRIDE = default;
    };

    class GetSubscribeByUserIdTask : public detail::Gs2WebSocketSessionTask<GetSubscribeByUserIdResult>
    {
    private:
        GetSubscribeByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getSubscribeByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetSubscribeByUserIdTask(
            GetSubscribeByUserIdRequest request,
            Gs2WebSocketSessionTask<GetSubscribeByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSubscribeByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSubscribeByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateNotificationTypeTask : public detail::Gs2WebSocketSessionTask<UpdateNotificationTypeResult>
    {
    private:
        UpdateNotificationTypeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateNotificationType";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getNotificationTypes())
            {
                jsonWriter.writePropertyName("notificationTypes");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getNotificationTypes();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UpdateNotificationTypeTask(
            UpdateNotificationTypeRequest request,
            Gs2WebSocketSessionTask<UpdateNotificationTypeResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateNotificationTypeResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateNotificationTypeTask() GS2_OVERRIDE = default;
    };

    class UpdateNotificationTypeByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateNotificationTypeByUserIdResult>
    {
    private:
        UpdateNotificationTypeByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateNotificationTypeByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getNotificationTypes())
            {
                jsonWriter.writePropertyName("notificationTypes");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getNotificationTypes();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UpdateNotificationTypeByUserIdTask(
            UpdateNotificationTypeByUserIdRequest request,
            Gs2WebSocketSessionTask<UpdateNotificationTypeByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateNotificationTypeByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateNotificationTypeByUserIdTask() GS2_OVERRIDE = default;
    };

    class UnsubscribeTask : public detail::Gs2WebSocketSessionTask<UnsubscribeResult>
    {
    private:
        UnsubscribeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "unsubscribe";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UnsubscribeTask(
            UnsubscribeRequest request,
            Gs2WebSocketSessionTask<UnsubscribeResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UnsubscribeResult>(callback),
            m_Request(std::move(request))
        {}

        ~UnsubscribeTask() GS2_OVERRIDE = default;
    };

    class UnsubscribeByUserIdTask : public detail::Gs2WebSocketSessionTask<UnsubscribeByUserIdResult>
    {
    private:
        UnsubscribeByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "chat";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "subscribe";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "unsubscribeByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRoomName())
            {
                jsonWriter.writePropertyName("roomName");
                jsonWriter.writeCharArray(*m_Request.getRoomName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        UnsubscribeByUserIdTask(
            UnsubscribeByUserIdRequest request,
            Gs2WebSocketSessionTask<UnsubscribeByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UnsubscribeByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UnsubscribeByUserIdTask() GS2_OVERRIDE = default;
    };

protected:
    static void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getNamespaceId())
        {
            jsonWriter.writePropertyName("namespaceId");
            jsonWriter.writeCharArray(*obj.getNamespaceId());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
        }
        if (obj.getAllowCreateRoom())
        {
            jsonWriter.writePropertyName("allowCreateRoom");
            jsonWriter.writeBool(*obj.getAllowCreateRoom());
        }
        if (obj.getPostMessageScript())
        {
            jsonWriter.writePropertyName("postMessageScript");
            write(jsonWriter, *obj.getPostMessageScript());
        }
        if (obj.getCreateRoomScript())
        {
            jsonWriter.writePropertyName("createRoomScript");
            write(jsonWriter, *obj.getCreateRoomScript());
        }
        if (obj.getDeleteRoomScript())
        {
            jsonWriter.writePropertyName("deleteRoomScript");
            write(jsonWriter, *obj.getDeleteRoomScript());
        }
        if (obj.getSubscribeRoomScript())
        {
            jsonWriter.writePropertyName("subscribeRoomScript");
            write(jsonWriter, *obj.getSubscribeRoomScript());
        }
        if (obj.getUnsubscribeRoomScript())
        {
            jsonWriter.writePropertyName("unsubscribeRoomScript");
            write(jsonWriter, *obj.getUnsubscribeRoomScript());
        }
        if (obj.getPostNotification())
        {
            jsonWriter.writePropertyName("postNotification");
            write(jsonWriter, *obj.getPostNotification());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Room& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRoomId())
        {
            jsonWriter.writePropertyName("roomId");
            jsonWriter.writeCharArray(*obj.getRoomId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        if (obj.getPassword())
        {
            jsonWriter.writePropertyName("password");
            jsonWriter.writeCharArray(*obj.getPassword());
        }
        if (obj.getWhiteListUserIds())
        {
            jsonWriter.writePropertyName("whiteListUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getWhiteListUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Message& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMessageId())
        {
            jsonWriter.writePropertyName("messageId");
            jsonWriter.writeCharArray(*obj.getMessageId());
        }
        if (obj.getRoomName())
        {
            jsonWriter.writePropertyName("roomName");
            jsonWriter.writeCharArray(*obj.getRoomName());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getCategory())
        {
            jsonWriter.writePropertyName("category");
            jsonWriter.writeInt32(*obj.getCategory());
        }
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Subscribe& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getSubscribeId())
        {
            jsonWriter.writePropertyName("subscribeId");
            jsonWriter.writeCharArray(*obj.getSubscribeId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getRoomName())
        {
            jsonWriter.writePropertyName("roomName");
            jsonWriter.writeCharArray(*obj.getRoomName());
        }
        if (obj.getNotificationTypes())
        {
            jsonWriter.writePropertyName("notificationTypes");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getNotificationTypes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRegion())
        {
            jsonWriter.writePropertyName("region");
            jsonWriter.writeCharArray(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            jsonWriter.writePropertyName("responseCacheId");
            jsonWriter.writeCharArray(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            jsonWriter.writePropertyName("requestHash");
            jsonWriter.writeCharArray(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            jsonWriter.writePropertyName("result");
            jsonWriter.writeCharArray(*obj.getResult());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const NotificationType& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCategory())
        {
            jsonWriter.writePropertyName("category");
            jsonWriter.writeInt32(*obj.getCategory());
        }
        if (obj.getEnableTransferMobilePushNotification())
        {
            jsonWriter.writePropertyName("enableTransferMobilePushNotification");
            jsonWriter.writeBool(*obj.getEnableTransferMobilePushNotification());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTriggerScriptId())
        {
            jsonWriter.writePropertyName("triggerScriptId");
            jsonWriter.writeCharArray(*obj.getTriggerScriptId());
        }
        if (obj.getDoneTriggerScriptId())
        {
            jsonWriter.writePropertyName("doneTriggerScriptId");
            jsonWriter.writeCharArray(*obj.getDoneTriggerScriptId());
        }
        if (obj.getDoneTriggerQueueNamespaceId())
        {
            jsonWriter.writePropertyName("doneTriggerQueueNamespaceId");
            jsonWriter.writeCharArray(*obj.getDoneTriggerQueueNamespaceId());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const NotificationSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGatewayNamespaceId())
        {
            jsonWriter.writePropertyName("gatewayNamespaceId");
            jsonWriter.writeCharArray(*obj.getGatewayNamespaceId());
        }
        if (obj.getEnableTransferMobileNotification())
        {
            jsonWriter.writePropertyName("enableTransferMobileNotification");
            jsonWriter.writeBool(*obj.getEnableTransferMobileNotification());
        }
        if (obj.getSound())
        {
            jsonWriter.writePropertyName("sound");
            jsonWriter.writeCharArray(*obj.getSound());
        }
        jsonWriter.writeObjectEnd();
    }


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2ChatWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
    {
        DescribeNamespacesTask& task = *new DescribeNamespacesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
    {
        CreateNamespaceTask& task = *new CreateNamespaceTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
    {
        GetNamespaceStatusTask& task = *new GetNamespaceStatusTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
    {
        GetNamespaceTask& task = *new GetNamespaceTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
    {
        UpdateNamespaceTask& task = *new UpdateNamespaceTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
    {
        DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ルームの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRooms(DescribeRoomsRequest request, std::function<void(AsyncDescribeRoomsResult)> callback)
    {
        DescribeRoomsTask& task = *new DescribeRoomsTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ルームを作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRoom(CreateRoomRequest request, std::function<void(AsyncCreateRoomResult)> callback)
    {
        CreateRoomTask& task = *new CreateRoomTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ルームを作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRoomFromBackend(CreateRoomFromBackendRequest request, std::function<void(AsyncCreateRoomFromBackendResult)> callback)
    {
        CreateRoomFromBackendTask& task = *new CreateRoomFromBackendTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ルームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRoom(GetRoomRequest request, std::function<void(AsyncGetRoomResult)> callback)
    {
        GetRoomTask& task = *new GetRoomTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ルームを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRoom(UpdateRoomRequest request, std::function<void(AsyncUpdateRoomResult)> callback)
    {
        UpdateRoomTask& task = *new UpdateRoomTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ルームを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRoom(DeleteRoomRequest request, std::function<void(AsyncDeleteRoomResult)> callback)
    {
        DeleteRoomTask& task = *new DeleteRoomTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ルームを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRoomFromBackend(DeleteRoomFromBackendRequest request, std::function<void(AsyncDeleteRoomFromBackendResult)> callback)
    {
        DeleteRoomFromBackendTask& task = *new DeleteRoomFromBackendTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessages(DescribeMessagesRequest request, std::function<void(AsyncDescribeMessagesResult)> callback)
    {
        DescribeMessagesTask& task = *new DescribeMessagesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージを投稿<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void post(PostRequest request, std::function<void(AsyncPostResult)> callback)
    {
        PostTask& task = *new PostTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してメッセージを投稿<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void postByUserId(PostByUserIdRequest request, std::function<void(AsyncPostByUserIdResult)> callback)
    {
        PostByUserIdTask& task = *new PostByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessage(GetMessageRequest request, std::function<void(AsyncGetMessageResult)> callback)
    {
        GetMessageTask& task = *new GetMessageTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * メッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessage(DeleteMessageRequest request, std::function<void(AsyncDeleteMessageResult)> callback)
    {
        DeleteMessageTask& task = *new DeleteMessageTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 購読しているルームの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribes(DescribeSubscribesRequest request, std::function<void(AsyncDescribeSubscribesResult)> callback)
    {
        DescribeSubscribesTask& task = *new DescribeSubscribesTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定して購読しているルームの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribesByUserId(DescribeSubscribesByUserIdRequest request, std::function<void(AsyncDescribeSubscribesByUserIdResult)> callback)
    {
        DescribeSubscribesByUserIdTask& task = *new DescribeSubscribesByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ルーム名を指定して購読しているユーザの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribesByRoomName(DescribeSubscribesByRoomNameRequest request, std::function<void(AsyncDescribeSubscribesByRoomNameResult)> callback)
    {
        DescribeSubscribesByRoomNameTask& task = *new DescribeSubscribesByRoomNameTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ルームを購読<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void subscribe(SubscribeRequest request, std::function<void(AsyncSubscribeResult)> callback)
    {
        SubscribeTask& task = *new SubscribeTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してルームを購読<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void subscribeByUserId(SubscribeByUserIdRequest request, std::function<void(AsyncSubscribeByUserIdResult)> callback)
    {
        SubscribeByUserIdTask& task = *new SubscribeByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 購読を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribe(GetSubscribeRequest request, std::function<void(AsyncGetSubscribeResult)> callback)
    {
        GetSubscribeTask& task = *new GetSubscribeTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定して購読を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribeByUserId(GetSubscribeByUserIdRequest request, std::function<void(AsyncGetSubscribeByUserIdResult)> callback)
    {
        GetSubscribeByUserIdTask& task = *new GetSubscribeByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 通知方法を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNotificationType(UpdateNotificationTypeRequest request, std::function<void(AsyncUpdateNotificationTypeResult)> callback)
    {
        UpdateNotificationTypeTask& task = *new UpdateNotificationTypeTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定して通知方法を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNotificationTypeByUserId(UpdateNotificationTypeByUserIdRequest request, std::function<void(AsyncUpdateNotificationTypeByUserIdResult)> callback)
    {
        UpdateNotificationTypeByUserIdTask& task = *new UpdateNotificationTypeByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 購読の購読を解除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unsubscribe(UnsubscribeRequest request, std::function<void(AsyncUnsubscribeResult)> callback)
    {
        UnsubscribeTask& task = *new UnsubscribeTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定して購読の購読を解除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unsubscribeByUserId(UnsubscribeByUserIdRequest request, std::function<void(AsyncUnsubscribeByUserIdResult)> callback)
    {
        UnsubscribeByUserIdTask& task = *new UnsubscribeByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_CHAT_GS2CHATWEBSOCKETCLIENT_HPP_