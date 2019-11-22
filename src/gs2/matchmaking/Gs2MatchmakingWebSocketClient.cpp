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

#include "Gs2MatchmakingWebSocketClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeGatheringsRequest.hpp"
#include "request/CreateGatheringRequest.hpp"
#include "request/CreateGatheringByUserIdRequest.hpp"
#include "request/UpdateGatheringRequest.hpp"
#include "request/UpdateGatheringByUserIdRequest.hpp"
#include "request/DoMatchmakingByPlayerRequest.hpp"
#include "request/DoMatchmakingRequest.hpp"
#include "request/GetGatheringRequest.hpp"
#include "request/CancelMatchmakingRequest.hpp"
#include "request/CancelMatchmakingByUserIdRequest.hpp"
#include "request/DeleteGatheringRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const Gathering& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const NotificationSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const AttributeRange& obj);
void write(detail::json::JsonWriter& jsonWriter, const CapacityOfRole& obj);
void write(detail::json::JsonWriter& jsonWriter, const Attribute& obj);
void write(detail::json::JsonWriter& jsonWriter, const Player& obj);

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj)
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
    if (obj.getCreateGatheringTriggerType())
    {
        jsonWriter.writePropertyName("createGatheringTriggerType");
        jsonWriter.writeCharArray(*obj.getCreateGatheringTriggerType());
    }
    if (obj.getCreateGatheringTriggerRealtimeNamespaceId())
    {
        jsonWriter.writePropertyName("createGatheringTriggerRealtimeNamespaceId");
        jsonWriter.writeCharArray(*obj.getCreateGatheringTriggerRealtimeNamespaceId());
    }
    if (obj.getCreateGatheringTriggerScriptId())
    {
        jsonWriter.writePropertyName("createGatheringTriggerScriptId");
        jsonWriter.writeCharArray(*obj.getCreateGatheringTriggerScriptId());
    }
    if (obj.getCompleteMatchmakingTriggerType())
    {
        jsonWriter.writePropertyName("completeMatchmakingTriggerType");
        jsonWriter.writeCharArray(*obj.getCompleteMatchmakingTriggerType());
    }
    if (obj.getCompleteMatchmakingTriggerRealtimeNamespaceId())
    {
        jsonWriter.writePropertyName("completeMatchmakingTriggerRealtimeNamespaceId");
        jsonWriter.writeCharArray(*obj.getCompleteMatchmakingTriggerRealtimeNamespaceId());
    }
    if (obj.getCompleteMatchmakingTriggerScriptId())
    {
        jsonWriter.writePropertyName("completeMatchmakingTriggerScriptId");
        jsonWriter.writeCharArray(*obj.getCompleteMatchmakingTriggerScriptId());
    }
    if (obj.getJoinNotification())
    {
        jsonWriter.writePropertyName("joinNotification");
        write(jsonWriter, *obj.getJoinNotification());
    }
    if (obj.getLeaveNotification())
    {
        jsonWriter.writePropertyName("leaveNotification");
        write(jsonWriter, *obj.getLeaveNotification());
    }
    if (obj.getCompleteNotification())
    {
        jsonWriter.writePropertyName("completeNotification");
        write(jsonWriter, *obj.getCompleteNotification());
    }
    if (obj.getLogSetting())
    {
        jsonWriter.writePropertyName("logSetting");
        write(jsonWriter, *obj.getLogSetting());
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

void write(detail::json::JsonWriter& jsonWriter, const Gathering& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getGatheringId())
    {
        jsonWriter.writePropertyName("gatheringId");
        jsonWriter.writeCharArray(*obj.getGatheringId());
    }
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getAttributeRanges())
    {
        jsonWriter.writePropertyName("attributeRanges");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getAttributeRanges();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getCapacityOfRoles())
    {
        jsonWriter.writePropertyName("capacityOfRoles");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getCapacityOfRoles();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getAllowUserIds())
    {
        jsonWriter.writePropertyName("allowUserIds");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getAllowUserIds();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeCharArray(list[i]);
        }
        jsonWriter.writeArrayEnd();
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
    if (obj.getUpdatedAt())
    {
        jsonWriter.writePropertyName("updatedAt");
        jsonWriter.writeInt64(*obj.getUpdatedAt());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const NotificationSetting& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getLoggingNamespaceId())
    {
        jsonWriter.writePropertyName("loggingNamespaceId");
        jsonWriter.writeCharArray(*obj.getLoggingNamespaceId());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const AttributeRange& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getMin())
    {
        jsonWriter.writePropertyName("min");
        jsonWriter.writeInt32(*obj.getMin());
    }
    if (obj.getMax())
    {
        jsonWriter.writePropertyName("max");
        jsonWriter.writeInt32(*obj.getMax());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const CapacityOfRole& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getRoleName())
    {
        jsonWriter.writePropertyName("roleName");
        jsonWriter.writeCharArray(*obj.getRoleName());
    }
    if (obj.getRoleAliases())
    {
        jsonWriter.writePropertyName("roleAliases");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getRoleAliases();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeCharArray(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getCapacity())
    {
        jsonWriter.writePropertyName("capacity");
        jsonWriter.writeInt32(*obj.getCapacity());
    }
    if (obj.getParticipants())
    {
        jsonWriter.writePropertyName("participants");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getParticipants();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const Attribute& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getValue())
    {
        jsonWriter.writePropertyName("value");
        jsonWriter.writeInt32(*obj.getValue());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const Player& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getUserId())
    {
        jsonWriter.writePropertyName("userId");
        jsonWriter.writeCharArray(*obj.getUserId());
    }
    if (obj.getAttributes())
    {
        jsonWriter.writePropertyName("attributes");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getAttributes();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getRoleName())
    {
        jsonWriter.writePropertyName("roleName");
        jsonWriter.writeCharArray(*obj.getRoleName());
    }
    if (obj.getDenyUserIds())
    {
        jsonWriter.writePropertyName("denyUserIds");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getDenyUserIds();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeCharArray(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}


class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
{
private:
    DescribeNamespacesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
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
        return "matchmaking";
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
        if (m_Request.getCreateGatheringTriggerType())
        {
            jsonWriter.writePropertyName("createGatheringTriggerType");
            jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerType());
        }
        if (m_Request.getCreateGatheringTriggerRealtimeNamespaceId())
        {
            jsonWriter.writePropertyName("createGatheringTriggerRealtimeNamespaceId");
            jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerRealtimeNamespaceId());
        }
        if (m_Request.getCreateGatheringTriggerScriptId())
        {
            jsonWriter.writePropertyName("createGatheringTriggerScriptId");
            jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerScriptId());
        }
        if (m_Request.getCompleteMatchmakingTriggerType())
        {
            jsonWriter.writePropertyName("completeMatchmakingTriggerType");
            jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerType());
        }
        if (m_Request.getCompleteMatchmakingTriggerRealtimeNamespaceId())
        {
            jsonWriter.writePropertyName("completeMatchmakingTriggerRealtimeNamespaceId");
            jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerRealtimeNamespaceId());
        }
        if (m_Request.getCompleteMatchmakingTriggerScriptId())
        {
            jsonWriter.writePropertyName("completeMatchmakingTriggerScriptId");
            jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerScriptId());
        }
        if (m_Request.getJoinNotification())
        {
            jsonWriter.writePropertyName("joinNotification");
            write(jsonWriter, *m_Request.getJoinNotification());
        }
        if (m_Request.getLeaveNotification())
        {
            jsonWriter.writePropertyName("leaveNotification");
            write(jsonWriter, *m_Request.getLeaveNotification());
        }
        if (m_Request.getCompleteNotification())
        {
            jsonWriter.writePropertyName("completeNotification");
            write(jsonWriter, *m_Request.getCompleteNotification());
        }
        if (m_Request.getLogSetting())
        {
            jsonWriter.writePropertyName("logSetting");
            write(jsonWriter, *m_Request.getLogSetting());
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
        return "matchmaking";
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
        return "matchmaking";
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
        return "matchmaking";
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
        if (m_Request.getCreateGatheringTriggerType())
        {
            jsonWriter.writePropertyName("createGatheringTriggerType");
            jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerType());
        }
        if (m_Request.getCreateGatheringTriggerRealtimeNamespaceId())
        {
            jsonWriter.writePropertyName("createGatheringTriggerRealtimeNamespaceId");
            jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerRealtimeNamespaceId());
        }
        if (m_Request.getCreateGatheringTriggerScriptId())
        {
            jsonWriter.writePropertyName("createGatheringTriggerScriptId");
            jsonWriter.writeCharArray(*m_Request.getCreateGatheringTriggerScriptId());
        }
        if (m_Request.getCompleteMatchmakingTriggerType())
        {
            jsonWriter.writePropertyName("completeMatchmakingTriggerType");
            jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerType());
        }
        if (m_Request.getCompleteMatchmakingTriggerRealtimeNamespaceId())
        {
            jsonWriter.writePropertyName("completeMatchmakingTriggerRealtimeNamespaceId");
            jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerRealtimeNamespaceId());
        }
        if (m_Request.getCompleteMatchmakingTriggerScriptId())
        {
            jsonWriter.writePropertyName("completeMatchmakingTriggerScriptId");
            jsonWriter.writeCharArray(*m_Request.getCompleteMatchmakingTriggerScriptId());
        }
        if (m_Request.getJoinNotification())
        {
            jsonWriter.writePropertyName("joinNotification");
            write(jsonWriter, *m_Request.getJoinNotification());
        }
        if (m_Request.getLeaveNotification())
        {
            jsonWriter.writePropertyName("leaveNotification");
            write(jsonWriter, *m_Request.getLeaveNotification());
        }
        if (m_Request.getCompleteNotification())
        {
            jsonWriter.writePropertyName("completeNotification");
            write(jsonWriter, *m_Request.getCompleteNotification());
        }
        if (m_Request.getLogSetting())
        {
            jsonWriter.writePropertyName("logSetting");
            write(jsonWriter, *m_Request.getLogSetting());
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
        return "matchmaking";
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

class DescribeGatheringsTask : public detail::Gs2WebSocketSessionTask<DescribeGatheringsResult>
{
private:
    DescribeGatheringsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeGatherings";
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
    DescribeGatheringsTask(
        DescribeGatheringsRequest request,
        Gs2WebSocketSessionTask<DescribeGatheringsResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeGatheringsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeGatheringsTask() GS2_OVERRIDE = default;
};

class CreateGatheringTask : public detail::Gs2WebSocketSessionTask<CreateGatheringResult>
{
private:
    CreateGatheringRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createGathering";
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
        if (m_Request.getPlayer())
        {
            jsonWriter.writePropertyName("player");
            write(jsonWriter, *m_Request.getPlayer());
        }
        if (m_Request.getAttributeRanges())
        {
            jsonWriter.writePropertyName("attributeRanges");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getAttributeRanges();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getCapacityOfRoles())
        {
            jsonWriter.writePropertyName("capacityOfRoles");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getCapacityOfRoles();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getAllowUserIds())
        {
            jsonWriter.writePropertyName("allowUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getAllowUserIds();
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
    CreateGatheringTask(
        CreateGatheringRequest request,
        Gs2WebSocketSessionTask<CreateGatheringResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateGatheringResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateGatheringTask() GS2_OVERRIDE = default;
};

class CreateGatheringByUserIdTask : public detail::Gs2WebSocketSessionTask<CreateGatheringByUserIdResult>
{
private:
    CreateGatheringByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createGatheringByUserId";
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
        if (m_Request.getPlayer())
        {
            jsonWriter.writePropertyName("player");
            write(jsonWriter, *m_Request.getPlayer());
        }
        if (m_Request.getAttributeRanges())
        {
            jsonWriter.writePropertyName("attributeRanges");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getAttributeRanges();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getCapacityOfRoles())
        {
            jsonWriter.writePropertyName("capacityOfRoles");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getCapacityOfRoles();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (m_Request.getAllowUserIds())
        {
            jsonWriter.writePropertyName("allowUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getAllowUserIds();
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
    CreateGatheringByUserIdTask(
        CreateGatheringByUserIdRequest request,
        Gs2WebSocketSessionTask<CreateGatheringByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateGatheringByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateGatheringByUserIdTask() GS2_OVERRIDE = default;
};

class UpdateGatheringTask : public detail::Gs2WebSocketSessionTask<UpdateGatheringResult>
{
private:
    UpdateGatheringRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateGathering";
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
        if (m_Request.getGatheringName())
        {
            jsonWriter.writePropertyName("gatheringName");
            jsonWriter.writeCharArray(*m_Request.getGatheringName());
        }
        if (m_Request.getAttributeRanges())
        {
            jsonWriter.writePropertyName("attributeRanges");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getAttributeRanges();
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
    UpdateGatheringTask(
        UpdateGatheringRequest request,
        Gs2WebSocketSessionTask<UpdateGatheringResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateGatheringResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateGatheringTask() GS2_OVERRIDE = default;
};

class UpdateGatheringByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateGatheringByUserIdResult>
{
private:
    UpdateGatheringByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateGatheringByUserId";
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
        if (m_Request.getGatheringName())
        {
            jsonWriter.writePropertyName("gatheringName");
            jsonWriter.writeCharArray(*m_Request.getGatheringName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getAttributeRanges())
        {
            jsonWriter.writePropertyName("attributeRanges");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getAttributeRanges();
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
    UpdateGatheringByUserIdTask(
        UpdateGatheringByUserIdRequest request,
        Gs2WebSocketSessionTask<UpdateGatheringByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateGatheringByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateGatheringByUserIdTask() GS2_OVERRIDE = default;
};

class DoMatchmakingByPlayerTask : public detail::Gs2WebSocketSessionTask<DoMatchmakingByPlayerResult>
{
private:
    DoMatchmakingByPlayerRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "doMatchmakingByPlayer";
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
        if (m_Request.getPlayer())
        {
            jsonWriter.writePropertyName("player");
            write(jsonWriter, *m_Request.getPlayer());
        }
        if (m_Request.getMatchmakingContextToken())
        {
            jsonWriter.writePropertyName("matchmakingContextToken");
            jsonWriter.writeCharArray(*m_Request.getMatchmakingContextToken());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DoMatchmakingByPlayerTask(
        DoMatchmakingByPlayerRequest request,
        Gs2WebSocketSessionTask<DoMatchmakingByPlayerResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DoMatchmakingByPlayerResult>(callback),
        m_Request(std::move(request))
    {}

    ~DoMatchmakingByPlayerTask() GS2_OVERRIDE = default;
};

class DoMatchmakingTask : public detail::Gs2WebSocketSessionTask<DoMatchmakingResult>
{
private:
    DoMatchmakingRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "doMatchmaking";
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
        if (m_Request.getPlayer())
        {
            jsonWriter.writePropertyName("player");
            write(jsonWriter, *m_Request.getPlayer());
        }
        if (m_Request.getMatchmakingContextToken())
        {
            jsonWriter.writePropertyName("matchmakingContextToken");
            jsonWriter.writeCharArray(*m_Request.getMatchmakingContextToken());
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
    DoMatchmakingTask(
        DoMatchmakingRequest request,
        Gs2WebSocketSessionTask<DoMatchmakingResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DoMatchmakingResult>(callback),
        m_Request(std::move(request))
    {}

    ~DoMatchmakingTask() GS2_OVERRIDE = default;
};

class GetGatheringTask : public detail::Gs2WebSocketSessionTask<GetGatheringResult>
{
private:
    GetGatheringRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getGathering";
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
        if (m_Request.getGatheringName())
        {
            jsonWriter.writePropertyName("gatheringName");
            jsonWriter.writeCharArray(*m_Request.getGatheringName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetGatheringTask(
        GetGatheringRequest request,
        Gs2WebSocketSessionTask<GetGatheringResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetGatheringResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetGatheringTask() GS2_OVERRIDE = default;
};

class CancelMatchmakingTask : public detail::Gs2WebSocketSessionTask<CancelMatchmakingResult>
{
private:
    CancelMatchmakingRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "cancelMatchmaking";
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
        if (m_Request.getGatheringName())
        {
            jsonWriter.writePropertyName("gatheringName");
            jsonWriter.writeCharArray(*m_Request.getGatheringName());
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
    CancelMatchmakingTask(
        CancelMatchmakingRequest request,
        Gs2WebSocketSessionTask<CancelMatchmakingResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CancelMatchmakingResult>(callback),
        m_Request(std::move(request))
    {}

    ~CancelMatchmakingTask() GS2_OVERRIDE = default;
};

class CancelMatchmakingByUserIdTask : public detail::Gs2WebSocketSessionTask<CancelMatchmakingByUserIdResult>
{
private:
    CancelMatchmakingByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "cancelMatchmakingByUserId";
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
        if (m_Request.getGatheringName())
        {
            jsonWriter.writePropertyName("gatheringName");
            jsonWriter.writeCharArray(*m_Request.getGatheringName());
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
    CancelMatchmakingByUserIdTask(
        CancelMatchmakingByUserIdRequest request,
        Gs2WebSocketSessionTask<CancelMatchmakingByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CancelMatchmakingByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~CancelMatchmakingByUserIdTask() GS2_OVERRIDE = default;
};

class DeleteGatheringTask : public detail::Gs2WebSocketSessionTask<DeleteGatheringResult>
{
private:
    DeleteGatheringRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "matchmaking";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "gathering";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteGathering";
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
        if (m_Request.getGatheringName())
        {
            jsonWriter.writePropertyName("gatheringName");
            jsonWriter.writeCharArray(*m_Request.getGatheringName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteGatheringTask(
        DeleteGatheringRequest request,
        Gs2WebSocketSessionTask<DeleteGatheringResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteGatheringResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteGatheringTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
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
void Gs2MatchmakingWebSocketClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
{
    CreateNamespaceTask& task = *new CreateNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ネームスペースの状態を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
void Gs2MatchmakingWebSocketClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
void Gs2MatchmakingWebSocketClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
void Gs2MatchmakingWebSocketClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ギャザリングの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::describeGatherings(DescribeGatheringsRequest request, std::function<void(AsyncDescribeGatheringsResult)> callback)
{
    DescribeGatheringsTask& task = *new DescribeGatheringsTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ギャザリングを作成して募集を開始<br>
 *   <br>
 *   `募集条件` には、作成したギャザリングに参加を許可する各属性値の範囲を指定します。<br>
 *   <br>
 *   たとえば、同一ゲームモードを希望するプレイヤーを募集したい場合は、ゲームモードに対応した属性値が完全一致する参加条件プレイヤーとマッチメイキングするように<br>
 *   `属性名：ゲームモード` `属性最小値: ゲームモードを表す数値` `属性最大値: ゲームモードを表す数値`<br>
 *   とすることで、同一ゲームモードを希望するプレイヤー同士をマッチメイキングできます。<br>
 *   <br>
 *   他にレーティングをベースにしたマッチメイキングを実施したい場合は、<br>
 *   ルーム作成者のレーティング値を中心とした属性値の範囲を指定することで、レーティング値の近いプレイヤー同士をマッチメイキングできます。<br>
 *   この `募集条件` はあとで更新することができますので、徐々に条件を緩和していくことができます。<br>
 *   <br>
 *   ロール とは 盾役1人・回復役1人・攻撃役2人 などの役割ごとに募集人数を設定したい場合に使用します。<br>
 *   ロールにはエイリアスを指定できます。<br>
 *   たとえば、盾役は パラディン と ナイト の2種類の `ジョブ` に更に分類できるとします。<br>
 *   この場合、ロール名 に `盾役` エイリアス に `パラディン` `ナイト` として募集を出すようにゲームを実装します。<br>
 *   そして、プレイヤーは自分自身の `ジョブ` を自身のプレイヤー情報のロールに指定します。<br>
 *   <br>
 *   こうすることで、募集条件が `盾役` になっているギャザリングには `パラディン` も `ナイト` も参加できます。<br>
 *   一方で、ギャザリングを作成するときに、 `パラディン` だけ募集したくて、 `ナイト` を募集したくない場合は、<br>
 *   募集するロール名に `パラディン` を直接指定したり、エイリアスに `ナイト` を含めないようにすることで実現できます。<br>
 *   <br>
 *   `参加者` の `募集人数` はプレイヤーの募集人数を指定します。ロール名を指定することで、ロール名ごとの募集人数を設定できます。<br>
 *   <br>
 *   `参加者` の `参加者のプレイヤー情報リスト` には事前にプレイヤー間でパーティを構築している場合や、参加者が離脱したあとの追加募集で使用します。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::createGathering(CreateGatheringRequest request, std::function<void(AsyncCreateGatheringResult)> callback)
{
    CreateGatheringTask& task = *new CreateGatheringTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ギャザリングを作成して募集を開始<br>
 *   <br>
 *   `募集条件` には、作成したギャザリングに参加を許可する各属性値の範囲を指定します。<br>
 *   <br>
 *   たとえば、同一ゲームモードを希望するプレイヤーを募集したい場合は、ゲームモードに対応した属性値が完全一致する参加条件プレイヤーとマッチメイキングするように<br>
 *   `属性名：ゲームモード` `属性最小値: ゲームモードを表す数値` `属性最大値: ゲームモードを表す数値`<br>
 *   とすることで、同一ゲームモードを希望するプレイヤー同士をマッチメイキングできます。<br>
 *   <br>
 *   他にレーティングをベースにしたマッチメイキングを実施したい場合は、<br>
 *   ルーム作成者のレーティング値を中心とした属性値の範囲を指定することで、レーティング値の近いプレイヤー同士をマッチメイキングできます。<br>
 *   この `募集条件` はあとで更新することができますので、徐々に条件を緩和していくことができます。<br>
 *   <br>
 *   ロール とは 盾役1人・回復役1人・攻撃役2人 などの役割ごとに募集人数を設定したい場合に使用します。<br>
 *   ロールにはエイリアスを指定できます。<br>
 *   たとえば、盾役は パラディン と ナイト の2種類の `ジョブ` に更に分類できるとします。<br>
 *   この場合、ロール名 に `盾役` エイリアス に `パラディン` `ナイト` として募集を出すようにゲームを実装します。<br>
 *   そして、プレイヤーは自分自身の `ジョブ` を自身のプレイヤー情報のロールに指定します。<br>
 *   <br>
 *   こうすることで、募集条件が `盾役` になっているギャザリングには `パラディン` も `ナイト` も参加できます。<br>
 *   一方で、ギャザリングを作成するときに、 `パラディン` だけ募集したくて、 `ナイト` を募集したくない場合は、<br>
 *   募集するロール名に `パラディン` を直接指定したり、エイリアスに `ナイト` を含めないようにすることで実現できます。<br>
 *   <br>
 *   `参加者` の `募集人数` はプレイヤーの募集人数を指定します。ロール名を指定することで、ロール名ごとの募集人数を設定できます。<br>
 *   <br>
 *   `参加者` の `参加者のプレイヤー情報リスト` には事前にプレイヤー間でパーティを構築している場合や、参加者が離脱したあとの追加募集で使用します。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::createGatheringByUserId(CreateGatheringByUserIdRequest request, std::function<void(AsyncCreateGatheringByUserIdResult)> callback)
{
    CreateGatheringByUserIdTask& task = *new CreateGatheringByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ギャザリングを更新する<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::updateGathering(UpdateGatheringRequest request, std::function<void(AsyncUpdateGatheringResult)> callback)
{
    UpdateGatheringTask& task = *new UpdateGatheringTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ギャザリングを更新する<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::updateGatheringByUserId(UpdateGatheringByUserIdRequest request, std::function<void(AsyncUpdateGatheringByUserIdResult)> callback)
{
    UpdateGatheringByUserIdTask& task = *new UpdateGatheringByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * Player が参加できるギャザリングを探して参加する<br>
 *   <br>
 *   一定時間 検索を行い、対象が見つからなかったときには `マッチメイキングの状態を保持するトークン` を返す。<br>
 *   次回 `マッチメイキングの状態を保持するトークン` をつけて再度リクエストを出すことで、前回の続きから検索処理を再開できる。<br>
 *   すべてのギャザリングを検索したが、参加できるギャザリングが存在しなかった場合はギャザリングもトークンもどちらも null が応答される。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::doMatchmakingByPlayer(DoMatchmakingByPlayerRequest request, std::function<void(AsyncDoMatchmakingByPlayerResult)> callback)
{
    DoMatchmakingByPlayerTask& task = *new DoMatchmakingByPlayerTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 自分が参加できるギャザリングを探して参加する<br>
 *   <br>
 *   一定時間 検索を行い、対象が見つからなかったときには `マッチメイキングの状態を保持するトークン` を返す。<br>
 *   次回 `マッチメイキングの状態を保持するトークン` をつけて再度リクエストを出すことで、前回の続きから検索処理を再開できる。<br>
 *   すべてのギャザリングを検索したが、参加できるギャザリングが存在しなかった場合はギャザリングもトークンもどちらも null が応答される。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::doMatchmaking(DoMatchmakingRequest request, std::function<void(AsyncDoMatchmakingResult)> callback)
{
    DoMatchmakingTask& task = *new DoMatchmakingTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ギャザリングを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::getGathering(GetGatheringRequest request, std::function<void(AsyncGetGatheringResult)> callback)
{
    GetGatheringTask& task = *new GetGatheringTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * マッチメイキングをキャンセルする<br>
 *   <br>
 *   ギャザリングから離脱する前にマッチメイキングが完了した場合は、NotFoundException(404エラー) が発生し失敗します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::cancelMatchmaking(CancelMatchmakingRequest request, std::function<void(AsyncCancelMatchmakingResult)> callback)
{
    CancelMatchmakingTask& task = *new CancelMatchmakingTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してマッチメイキングをキャンセルする<br>
 *   <br>
 *   ギャザリングから離脱する前にマッチメイキングが完了した場合は、NotFoundException(404エラー) が発生し失敗します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::cancelMatchmakingByUserId(CancelMatchmakingByUserIdRequest request, std::function<void(AsyncCancelMatchmakingByUserIdResult)> callback)
{
    CancelMatchmakingByUserIdTask& task = *new CancelMatchmakingByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ギャザリングを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2MatchmakingWebSocketClient::deleteGathering(DeleteGatheringRequest request, std::function<void(AsyncDeleteGatheringResult)> callback)
{
    DeleteGatheringTask& task = *new DeleteGatheringTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

} }