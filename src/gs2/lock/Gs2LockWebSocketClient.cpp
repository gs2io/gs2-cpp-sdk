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

#include "Gs2LockWebSocketClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeMutexesRequest.hpp"
#include "request/DescribeMutexesByUserIdRequest.hpp"
#include "request/LockRequest.hpp"
#include "request/LockByUserIdRequest.hpp"
#include "request/UnlockRequest.hpp"
#include "request/UnlockByUserIdRequest.hpp"
#include "request/GetMutexRequest.hpp"
#include "request/GetMutexByUserIdRequest.hpp"
#include "request/DeleteMutexByUserIdRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace lock {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const Mutex& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj);

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

void write(detail::json::JsonWriter& jsonWriter, const Mutex& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getMutexId())
    {
        jsonWriter.writePropertyName("mutexId");
        jsonWriter.writeCharArray(*obj.getMutexId());
    }
    if (obj.getUserId())
    {
        jsonWriter.writePropertyName("userId");
        jsonWriter.writeCharArray(*obj.getUserId());
    }
    if (obj.getPropertyId())
    {
        jsonWriter.writePropertyName("propertyId");
        jsonWriter.writeCharArray(*obj.getPropertyId());
    }
    if (obj.getTransactionId())
    {
        jsonWriter.writePropertyName("transactionId");
        jsonWriter.writeCharArray(*obj.getTransactionId());
    }
    if (obj.getReferenceCount())
    {
        jsonWriter.writePropertyName("referenceCount");
        jsonWriter.writeInt32(*obj.getReferenceCount());
    }
    if (obj.getCreatedAt())
    {
        jsonWriter.writePropertyName("createdAt");
        jsonWriter.writeInt64(*obj.getCreatedAt());
    }
    if (obj.getTtlAt())
    {
        jsonWriter.writePropertyName("ttlAt");
        jsonWriter.writeInt64(*obj.getTtlAt());
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


class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
{
private:
    DescribeNamespacesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
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
        return "lock";
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
        return "lock";
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
        return "lock";
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
        return "lock";
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
        return "lock";
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

class DescribeMutexesTask : public detail::Gs2WebSocketSessionTask<DescribeMutexesResult>
{
private:
    DescribeMutexesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "mutex";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeMutexes";
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
    DescribeMutexesTask(
        DescribeMutexesRequest request,
        Gs2WebSocketSessionTask<DescribeMutexesResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeMutexesResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeMutexesTask() GS2_OVERRIDE = default;
};

class DescribeMutexesByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeMutexesByUserIdResult>
{
private:
    DescribeMutexesByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "mutex";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeMutexesByUserId";
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
    DescribeMutexesByUserIdTask(
        DescribeMutexesByUserIdRequest request,
        Gs2WebSocketSessionTask<DescribeMutexesByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeMutexesByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeMutexesByUserIdTask() GS2_OVERRIDE = default;
};

class LockTask : public detail::Gs2WebSocketSessionTask<LockResult>
{
private:
    LockRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "mutex";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "lock";
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
        if (m_Request.getPropertyId())
        {
            jsonWriter.writePropertyName("propertyId");
            jsonWriter.writeCharArray(*m_Request.getPropertyId());
        }
        if (m_Request.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*m_Request.getTransactionId());
        }
        if (m_Request.getTtl())
        {
            jsonWriter.writePropertyName("ttl");
            jsonWriter.writeInt64(*m_Request.getTtl());
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
    LockTask(
        LockRequest request,
        Gs2WebSocketSessionTask<LockResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<LockResult>(callback),
        m_Request(std::move(request))
    {}

    ~LockTask() GS2_OVERRIDE = default;
};

class LockByUserIdTask : public detail::Gs2WebSocketSessionTask<LockByUserIdResult>
{
private:
    LockByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "mutex";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "lockByUserId";
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
        if (m_Request.getPropertyId())
        {
            jsonWriter.writePropertyName("propertyId");
            jsonWriter.writeCharArray(*m_Request.getPropertyId());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*m_Request.getTransactionId());
        }
        if (m_Request.getTtl())
        {
            jsonWriter.writePropertyName("ttl");
            jsonWriter.writeInt64(*m_Request.getTtl());
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
    LockByUserIdTask(
        LockByUserIdRequest request,
        Gs2WebSocketSessionTask<LockByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<LockByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~LockByUserIdTask() GS2_OVERRIDE = default;
};

class UnlockTask : public detail::Gs2WebSocketSessionTask<UnlockResult>
{
private:
    UnlockRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "mutex";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "unlock";
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
        if (m_Request.getPropertyId())
        {
            jsonWriter.writePropertyName("propertyId");
            jsonWriter.writeCharArray(*m_Request.getPropertyId());
        }
        if (m_Request.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*m_Request.getTransactionId());
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
    UnlockTask(
        UnlockRequest request,
        Gs2WebSocketSessionTask<UnlockResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UnlockResult>(callback),
        m_Request(std::move(request))
    {}

    ~UnlockTask() GS2_OVERRIDE = default;
};

class UnlockByUserIdTask : public detail::Gs2WebSocketSessionTask<UnlockByUserIdResult>
{
private:
    UnlockByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "mutex";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "unlockByUserId";
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
        if (m_Request.getPropertyId())
        {
            jsonWriter.writePropertyName("propertyId");
            jsonWriter.writeCharArray(*m_Request.getPropertyId());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*m_Request.getTransactionId());
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
    UnlockByUserIdTask(
        UnlockByUserIdRequest request,
        Gs2WebSocketSessionTask<UnlockByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UnlockByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~UnlockByUserIdTask() GS2_OVERRIDE = default;
};

class GetMutexTask : public detail::Gs2WebSocketSessionTask<GetMutexResult>
{
private:
    GetMutexRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "mutex";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getMutex";
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
        if (m_Request.getPropertyId())
        {
            jsonWriter.writePropertyName("propertyId");
            jsonWriter.writeCharArray(*m_Request.getPropertyId());
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
    GetMutexTask(
        GetMutexRequest request,
        Gs2WebSocketSessionTask<GetMutexResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetMutexResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetMutexTask() GS2_OVERRIDE = default;
};

class GetMutexByUserIdTask : public detail::Gs2WebSocketSessionTask<GetMutexByUserIdResult>
{
private:
    GetMutexByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "mutex";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getMutexByUserId";
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
        if (m_Request.getPropertyId())
        {
            jsonWriter.writePropertyName("propertyId");
            jsonWriter.writeCharArray(*m_Request.getPropertyId());
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
    GetMutexByUserIdTask(
        GetMutexByUserIdRequest request,
        Gs2WebSocketSessionTask<GetMutexByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetMutexByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetMutexByUserIdTask() GS2_OVERRIDE = default;
};

class DeleteMutexByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteMutexByUserIdResult>
{
private:
    DeleteMutexByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "lock";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "mutex";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteMutexByUserId";
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
        if (m_Request.getPropertyId())
        {
            jsonWriter.writePropertyName("propertyId");
            jsonWriter.writeCharArray(*m_Request.getPropertyId());
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
    DeleteMutexByUserIdTask(
        DeleteMutexByUserIdRequest request,
        Gs2WebSocketSessionTask<DeleteMutexByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteMutexByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteMutexByUserIdTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
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
void Gs2LockWebSocketClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
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
void Gs2LockWebSocketClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
void Gs2LockWebSocketClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
void Gs2LockWebSocketClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
void Gs2LockWebSocketClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ミューテックスの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::describeMutexes(DescribeMutexesRequest request, std::function<void(AsyncDescribeMutexesResult)> callback)
{
    DescribeMutexesTask& task = *new DescribeMutexesTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ミューテックスの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::describeMutexesByUserId(DescribeMutexesByUserIdRequest request, std::function<void(AsyncDescribeMutexesByUserIdResult)> callback)
{
    DescribeMutexesByUserIdTask& task = *new DescribeMutexesByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ミューテックスを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::lock(LockRequest request, std::function<void(AsyncLockResult)> callback)
{
    LockTask& task = *new LockTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してミューテックスを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::lockByUserId(LockByUserIdRequest request, std::function<void(AsyncLockByUserIdResult)> callback)
{
    LockByUserIdTask& task = *new LockByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ミューテックスを解放<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::unlock(UnlockRequest request, std::function<void(AsyncUnlockResult)> callback)
{
    UnlockTask& task = *new UnlockTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してミューテックスを解放<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::unlockByUserId(UnlockByUserIdRequest request, std::function<void(AsyncUnlockByUserIdResult)> callback)
{
    UnlockByUserIdTask& task = *new UnlockByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ミューテックスを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::getMutex(GetMutexRequest request, std::function<void(AsyncGetMutexResult)> callback)
{
    GetMutexTask& task = *new GetMutexTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してミューテックスを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::getMutexByUserId(GetMutexByUserIdRequest request, std::function<void(AsyncGetMutexByUserIdResult)> callback)
{
    GetMutexByUserIdTask& task = *new GetMutexByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ミューテックスを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2LockWebSocketClient::deleteMutexByUserId(DeleteMutexByUserIdRequest request, std::function<void(AsyncDeleteMutexByUserIdResult)> callback)
{
    DeleteMutexByUserIdTask& task = *new DeleteMutexByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

} }