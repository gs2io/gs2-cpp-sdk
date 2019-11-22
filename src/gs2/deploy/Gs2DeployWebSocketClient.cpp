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

#include "Gs2DeployWebSocketClient.hpp"
#include "model/model.hpp"
#include "request/DescribeStacksRequest.hpp"
#include "request/CreateStackRequest.hpp"
#include "request/CreateStackFromGitHubRequest.hpp"
#include "request/GetStackStatusRequest.hpp"
#include "request/GetStackRequest.hpp"
#include "request/UpdateStackRequest.hpp"
#include "request/UpdateStackFromGitHubRequest.hpp"
#include "request/DeleteStackRequest.hpp"
#include "request/ForceDeleteStackRequest.hpp"
#include "request/DescribeResourcesRequest.hpp"
#include "request/GetResourceRequest.hpp"
#include "request/DescribeEventsRequest.hpp"
#include "request/GetEventRequest.hpp"
#include "request/DescribeOutputsRequest.hpp"
#include "request/GetOutputRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace deploy {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Stack& obj);
void write(detail::json::JsonWriter& jsonWriter, const Resource& obj);
void write(detail::json::JsonWriter& jsonWriter, const WorkingStack& obj);
void write(detail::json::JsonWriter& jsonWriter, const WorkingResource& obj);
void write(detail::json::JsonWriter& jsonWriter, const Event& obj);
void write(detail::json::JsonWriter& jsonWriter, const Output& obj);
void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const OutputField& obj);

void write(detail::json::JsonWriter& jsonWriter, const Stack& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getStackId())
    {
        jsonWriter.writePropertyName("stackId");
        jsonWriter.writeCharArray(*obj.getStackId());
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
    if (obj.getTemplate())
    {
        jsonWriter.writePropertyName("template");
        jsonWriter.writeCharArray(*obj.getTemplate());
    }
    if (obj.getStatus())
    {
        jsonWriter.writePropertyName("status");
        jsonWriter.writeCharArray(*obj.getStatus());
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

void write(detail::json::JsonWriter& jsonWriter, const Resource& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getResourceId())
    {
        jsonWriter.writePropertyName("resourceId");
        jsonWriter.writeCharArray(*obj.getResourceId());
    }
    if (obj.getType())
    {
        jsonWriter.writePropertyName("type");
        jsonWriter.writeCharArray(*obj.getType());
    }
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getRequest())
    {
        jsonWriter.writePropertyName("request");
        jsonWriter.writeCharArray(*obj.getRequest());
    }
    if (obj.getResponse())
    {
        jsonWriter.writePropertyName("response");
        jsonWriter.writeCharArray(*obj.getResponse());
    }
    if (obj.getRollbackContext())
    {
        jsonWriter.writePropertyName("rollbackContext");
        jsonWriter.writeCharArray(*obj.getRollbackContext());
    }
    if (obj.getRollbackRequest())
    {
        jsonWriter.writePropertyName("rollbackRequest");
        jsonWriter.writeCharArray(*obj.getRollbackRequest());
    }
    if (obj.getRollbackAfter())
    {
        jsonWriter.writePropertyName("rollbackAfter");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getRollbackAfter();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeCharArray(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getOutputFields())
    {
        jsonWriter.writePropertyName("outputFields");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getOutputFields();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getWorkId())
    {
        jsonWriter.writePropertyName("workId");
        jsonWriter.writeCharArray(*obj.getWorkId());
    }
    if (obj.getCreatedAt())
    {
        jsonWriter.writePropertyName("createdAt");
        jsonWriter.writeInt64(*obj.getCreatedAt());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const WorkingStack& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getStackId())
    {
        jsonWriter.writePropertyName("stackId");
        jsonWriter.writeCharArray(*obj.getStackId());
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
    if (obj.getWorkId())
    {
        jsonWriter.writePropertyName("workId");
        jsonWriter.writeCharArray(*obj.getWorkId());
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

void write(detail::json::JsonWriter& jsonWriter, const WorkingResource& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getResourceId())
    {
        jsonWriter.writePropertyName("resourceId");
        jsonWriter.writeCharArray(*obj.getResourceId());
    }
    if (obj.getContext())
    {
        jsonWriter.writePropertyName("context");
        jsonWriter.writeCharArray(*obj.getContext());
    }
    if (obj.getType())
    {
        jsonWriter.writePropertyName("type");
        jsonWriter.writeCharArray(*obj.getType());
    }
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getRequest())
    {
        jsonWriter.writePropertyName("request");
        jsonWriter.writeCharArray(*obj.getRequest());
    }
    if (obj.getAfter())
    {
        jsonWriter.writePropertyName("after");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getAfter();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeCharArray(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getRollbackContext())
    {
        jsonWriter.writePropertyName("rollbackContext");
        jsonWriter.writeCharArray(*obj.getRollbackContext());
    }
    if (obj.getRollbackRequest())
    {
        jsonWriter.writePropertyName("rollbackRequest");
        jsonWriter.writeCharArray(*obj.getRollbackRequest());
    }
    if (obj.getRollbackAfter())
    {
        jsonWriter.writePropertyName("rollbackAfter");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getRollbackAfter();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeCharArray(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getOutputFields())
    {
        jsonWriter.writePropertyName("outputFields");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getOutputFields();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    if (obj.getWorkId())
    {
        jsonWriter.writePropertyName("workId");
        jsonWriter.writeCharArray(*obj.getWorkId());
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

void write(detail::json::JsonWriter& jsonWriter, const Event& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getEventId())
    {
        jsonWriter.writePropertyName("eventId");
        jsonWriter.writeCharArray(*obj.getEventId());
    }
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getResourceName())
    {
        jsonWriter.writePropertyName("resourceName");
        jsonWriter.writeCharArray(*obj.getResourceName());
    }
    if (obj.getType())
    {
        jsonWriter.writePropertyName("type");
        jsonWriter.writeCharArray(*obj.getType());
    }
    if (obj.getMessage())
    {
        jsonWriter.writePropertyName("message");
        jsonWriter.writeCharArray(*obj.getMessage());
    }
    if (obj.getEventAt())
    {
        jsonWriter.writePropertyName("eventAt");
        jsonWriter.writeInt64(*obj.getEventAt());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const Output& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getOutputId())
    {
        jsonWriter.writePropertyName("outputId");
        jsonWriter.writeCharArray(*obj.getOutputId());
    }
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getValue())
    {
        jsonWriter.writePropertyName("value");
        jsonWriter.writeCharArray(*obj.getValue());
    }
    if (obj.getCreatedAt())
    {
        jsonWriter.writePropertyName("createdAt");
        jsonWriter.writeInt64(*obj.getCreatedAt());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getGitHubApiKeyId())
    {
        jsonWriter.writePropertyName("gitHubApiKeyId");
        jsonWriter.writeCharArray(*obj.getGitHubApiKeyId());
    }
    if (obj.getRepositoryName())
    {
        jsonWriter.writePropertyName("repositoryName");
        jsonWriter.writeCharArray(*obj.getRepositoryName());
    }
    if (obj.getSourcePath())
    {
        jsonWriter.writePropertyName("sourcePath");
        jsonWriter.writeCharArray(*obj.getSourcePath());
    }
    if (obj.getReferenceType())
    {
        jsonWriter.writePropertyName("referenceType");
        jsonWriter.writeCharArray(*obj.getReferenceType());
    }
    if (obj.getCommitHash())
    {
        jsonWriter.writePropertyName("commitHash");
        jsonWriter.writeCharArray(*obj.getCommitHash());
    }
    if (obj.getBranchName())
    {
        jsonWriter.writePropertyName("branchName");
        jsonWriter.writeCharArray(*obj.getBranchName());
    }
    if (obj.getTagName())
    {
        jsonWriter.writePropertyName("tagName");
        jsonWriter.writeCharArray(*obj.getTagName());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const OutputField& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getFieldName())
    {
        jsonWriter.writePropertyName("fieldName");
        jsonWriter.writeCharArray(*obj.getFieldName());
    }
    jsonWriter.writeObjectEnd();
}


class DescribeStacksTask : public detail::Gs2WebSocketSessionTask<DescribeStacksResult>
{
private:
    DescribeStacksRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stack";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeStacks";
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
    DescribeStacksTask(
        DescribeStacksRequest request,
        Gs2WebSocketSessionTask<DescribeStacksResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeStacksResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeStacksTask() GS2_OVERRIDE = default;
};

class CreateStackTask : public detail::Gs2WebSocketSessionTask<CreateStackResult>
{
private:
    CreateStackRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stack";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createStack";
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
        if (m_Request.getTemplate())
        {
            jsonWriter.writePropertyName("template");
            jsonWriter.writeCharArray(*m_Request.getTemplate());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    CreateStackTask(
        CreateStackRequest request,
        Gs2WebSocketSessionTask<CreateStackResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateStackResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateStackTask() GS2_OVERRIDE = default;
};

class CreateStackFromGitHubTask : public detail::Gs2WebSocketSessionTask<CreateStackFromGitHubResult>
{
private:
    CreateStackFromGitHubRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stack";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createStackFromGitHub";
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
        if (m_Request.getCheckoutSetting())
        {
            jsonWriter.writePropertyName("checkoutSetting");
            write(jsonWriter, *m_Request.getCheckoutSetting());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    CreateStackFromGitHubTask(
        CreateStackFromGitHubRequest request,
        Gs2WebSocketSessionTask<CreateStackFromGitHubResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateStackFromGitHubResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateStackFromGitHubTask() GS2_OVERRIDE = default;
};

class GetStackStatusTask : public detail::Gs2WebSocketSessionTask<GetStackStatusResult>
{
private:
    GetStackStatusRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stack";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getStackStatus";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetStackStatusTask(
        GetStackStatusRequest request,
        Gs2WebSocketSessionTask<GetStackStatusResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetStackStatusResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetStackStatusTask() GS2_OVERRIDE = default;
};

class GetStackTask : public detail::Gs2WebSocketSessionTask<GetStackResult>
{
private:
    GetStackRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stack";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getStack";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetStackTask(
        GetStackRequest request,
        Gs2WebSocketSessionTask<GetStackResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetStackResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetStackTask() GS2_OVERRIDE = default;
};

class UpdateStackTask : public detail::Gs2WebSocketSessionTask<UpdateStackResult>
{
private:
    UpdateStackRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stack";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateStack";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
        }
        if (m_Request.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*m_Request.getDescription());
        }
        if (m_Request.getTemplate())
        {
            jsonWriter.writePropertyName("template");
            jsonWriter.writeCharArray(*m_Request.getTemplate());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    UpdateStackTask(
        UpdateStackRequest request,
        Gs2WebSocketSessionTask<UpdateStackResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateStackResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateStackTask() GS2_OVERRIDE = default;
};

class UpdateStackFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateStackFromGitHubResult>
{
private:
    UpdateStackFromGitHubRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stack";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateStackFromGitHub";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
        }
        if (m_Request.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*m_Request.getDescription());
        }
        if (m_Request.getCheckoutSetting())
        {
            jsonWriter.writePropertyName("checkoutSetting");
            write(jsonWriter, *m_Request.getCheckoutSetting());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    UpdateStackFromGitHubTask(
        UpdateStackFromGitHubRequest request,
        Gs2WebSocketSessionTask<UpdateStackFromGitHubResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateStackFromGitHubResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateStackFromGitHubTask() GS2_OVERRIDE = default;
};

class DeleteStackTask : public detail::Gs2WebSocketSessionTask<DeleteStackResult>
{
private:
    DeleteStackRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stack";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteStack";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteStackTask(
        DeleteStackRequest request,
        Gs2WebSocketSessionTask<DeleteStackResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteStackResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteStackTask() GS2_OVERRIDE = default;
};

class ForceDeleteStackTask : public detail::Gs2WebSocketSessionTask<ForceDeleteStackResult>
{
private:
    ForceDeleteStackRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stack";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "forceDeleteStack";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    ForceDeleteStackTask(
        ForceDeleteStackRequest request,
        Gs2WebSocketSessionTask<ForceDeleteStackResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<ForceDeleteStackResult>(callback),
        m_Request(std::move(request))
    {}

    ~ForceDeleteStackTask() GS2_OVERRIDE = default;
};

class DescribeResourcesTask : public detail::Gs2WebSocketSessionTask<DescribeResourcesResult>
{
private:
    DescribeResourcesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "resource";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeResources";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
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
    DescribeResourcesTask(
        DescribeResourcesRequest request,
        Gs2WebSocketSessionTask<DescribeResourcesResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeResourcesResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeResourcesTask() GS2_OVERRIDE = default;
};

class GetResourceTask : public detail::Gs2WebSocketSessionTask<GetResourceResult>
{
private:
    GetResourceRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "resource";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getResource";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
        }
        if (m_Request.getResourceName())
        {
            jsonWriter.writePropertyName("resourceName");
            jsonWriter.writeCharArray(*m_Request.getResourceName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetResourceTask(
        GetResourceRequest request,
        Gs2WebSocketSessionTask<GetResourceResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetResourceResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetResourceTask() GS2_OVERRIDE = default;
};

class DescribeEventsTask : public detail::Gs2WebSocketSessionTask<DescribeEventsResult>
{
private:
    DescribeEventsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "event";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeEvents";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
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
    DescribeEventsTask(
        DescribeEventsRequest request,
        Gs2WebSocketSessionTask<DescribeEventsResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeEventsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeEventsTask() GS2_OVERRIDE = default;
};

class GetEventTask : public detail::Gs2WebSocketSessionTask<GetEventResult>
{
private:
    GetEventRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "event";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getEvent";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
        }
        if (m_Request.getEventName())
        {
            jsonWriter.writePropertyName("eventName");
            jsonWriter.writeCharArray(*m_Request.getEventName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetEventTask(
        GetEventRequest request,
        Gs2WebSocketSessionTask<GetEventResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetEventResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetEventTask() GS2_OVERRIDE = default;
};

class DescribeOutputsTask : public detail::Gs2WebSocketSessionTask<DescribeOutputsResult>
{
private:
    DescribeOutputsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "output";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeOutputs";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
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
    DescribeOutputsTask(
        DescribeOutputsRequest request,
        Gs2WebSocketSessionTask<DescribeOutputsResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeOutputsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeOutputsTask() GS2_OVERRIDE = default;
};

class GetOutputTask : public detail::Gs2WebSocketSessionTask<GetOutputResult>
{
private:
    GetOutputRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "deploy";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "output";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getOutput";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStackName())
        {
            jsonWriter.writePropertyName("stackName");
            jsonWriter.writeCharArray(*m_Request.getStackName());
        }
        if (m_Request.getOutputName())
        {
            jsonWriter.writePropertyName("outputName");
            jsonWriter.writeCharArray(*m_Request.getOutputName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetOutputTask(
        GetOutputRequest request,
        Gs2WebSocketSessionTask<GetOutputResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetOutputResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetOutputTask() GS2_OVERRIDE = default;
};
}

/**
 * スタックの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::describeStacks(DescribeStacksRequest request, std::function<void(AsyncDescribeStacksResult)> callback)
{
    DescribeStacksTask& task = *new DescribeStacksTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタックを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::createStack(CreateStackRequest request, std::function<void(AsyncCreateStackResult)> callback)
{
    CreateStackTask& task = *new CreateStackTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタックを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::createStackFromGitHub(CreateStackFromGitHubRequest request, std::function<void(AsyncCreateStackFromGitHubResult)> callback)
{
    CreateStackFromGitHubTask& task = *new CreateStackFromGitHubTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタックを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::getStackStatus(GetStackStatusRequest request, std::function<void(AsyncGetStackStatusResult)> callback)
{
    GetStackStatusTask& task = *new GetStackStatusTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタックを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::getStack(GetStackRequest request, std::function<void(AsyncGetStackResult)> callback)
{
    GetStackTask& task = *new GetStackTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタックを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::updateStack(UpdateStackRequest request, std::function<void(AsyncUpdateStackResult)> callback)
{
    UpdateStackTask& task = *new UpdateStackTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタックを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::updateStackFromGitHub(UpdateStackFromGitHubRequest request, std::function<void(AsyncUpdateStackFromGitHubResult)> callback)
{
    UpdateStackFromGitHubTask& task = *new UpdateStackFromGitHubTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタックを削除<br>
 *   <br>
 *   スタックの削除は2段階で行われます。<br>
 *   DELETE_COMPLETED ステータスではないスタックを削除すると、まずはスタックによって作成されたリソースの削除を行います。<br>
 *   DELETE_COMPLETED ステータスのスタックを削除すると、完全にエンティティを削除します。<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::deleteStack(DeleteStackRequest request, std::function<void(AsyncDeleteStackResult)> callback)
{
    DeleteStackTask& task = *new DeleteStackTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタックを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::forceDeleteStack(ForceDeleteStackRequest request, std::function<void(AsyncForceDeleteStackResult)> callback)
{
    ForceDeleteStackTask& task = *new ForceDeleteStackTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 作成されたのリソースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::describeResources(DescribeResourcesRequest request, std::function<void(AsyncDescribeResourcesResult)> callback)
{
    DescribeResourcesTask& task = *new DescribeResourcesTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 作成されたのリソースを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::getResource(GetResourceRequest request, std::function<void(AsyncGetResourceResult)> callback)
{
    GetResourceTask& task = *new GetResourceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 発生したイベントの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::describeEvents(DescribeEventsRequest request, std::function<void(AsyncDescribeEventsResult)> callback)
{
    DescribeEventsTask& task = *new DescribeEventsTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 発生したイベントを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::getEvent(GetEventRequest request, std::function<void(AsyncGetEventResult)> callback)
{
    GetEventTask& task = *new GetEventTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * アウトプットの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::describeOutputs(DescribeOutputsRequest request, std::function<void(AsyncDescribeOutputsResult)> callback)
{
    DescribeOutputsTask& task = *new DescribeOutputsTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * アウトプットを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2DeployWebSocketClient::getOutput(GetOutputRequest request, std::function<void(AsyncGetOutputResult)> callback)
{
    GetOutputTask& task = *new GetOutputTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

} }