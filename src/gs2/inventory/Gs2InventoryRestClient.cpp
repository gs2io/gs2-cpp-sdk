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

#include "Gs2InventoryRestClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeInventoryModelMastersRequest.hpp"
#include "request/CreateInventoryModelMasterRequest.hpp"
#include "request/GetInventoryModelMasterRequest.hpp"
#include "request/UpdateInventoryModelMasterRequest.hpp"
#include "request/DeleteInventoryModelMasterRequest.hpp"
#include "request/DescribeInventoryModelsRequest.hpp"
#include "request/GetInventoryModelRequest.hpp"
#include "request/DescribeItemModelMastersRequest.hpp"
#include "request/CreateItemModelMasterRequest.hpp"
#include "request/GetItemModelMasterRequest.hpp"
#include "request/UpdateItemModelMasterRequest.hpp"
#include "request/DeleteItemModelMasterRequest.hpp"
#include "request/DescribeItemModelsRequest.hpp"
#include "request/GetItemModelRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentItemModelMasterRequest.hpp"
#include "request/UpdateCurrentItemModelMasterRequest.hpp"
#include "request/UpdateCurrentItemModelMasterFromGitHubRequest.hpp"
#include "request/DescribeInventoriesRequest.hpp"
#include "request/DescribeInventoriesByUserIdRequest.hpp"
#include "request/GetInventoryRequest.hpp"
#include "request/GetInventoryByUserIdRequest.hpp"
#include "request/AddCapacityByUserIdRequest.hpp"
#include "request/SetCapacityByUserIdRequest.hpp"
#include "request/DeleteInventoryByUserIdRequest.hpp"
#include "request/AddCapacityByStampSheetRequest.hpp"
#include "request/SetCapacityByStampSheetRequest.hpp"
#include "request/DescribeItemSetsRequest.hpp"
#include "request/DescribeItemSetsByUserIdRequest.hpp"
#include "request/GetItemSetRequest.hpp"
#include "request/GetItemSetByUserIdRequest.hpp"
#include "request/GetItemWithSignatureRequest.hpp"
#include "request/GetItemWithSignatureByUserIdRequest.hpp"
#include "request/AcquireItemSetByUserIdRequest.hpp"
#include "request/ConsumeItemSetRequest.hpp"
#include "request/ConsumeItemSetByUserIdRequest.hpp"
#include "request/DeleteItemSetByUserIdRequest.hpp"
#include "request/AcquireItemSetByStampSheetRequest.hpp"
#include "request/ConsumeItemSetByStampTaskRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace inventory {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const InventoryModelMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const InventoryModel& obj);
void write(detail::json::JsonWriter& jsonWriter, const ItemModelMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const ItemModel& obj);
void write(detail::json::JsonWriter& jsonWriter, const CurrentItemModelMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const Inventory& obj);
void write(detail::json::JsonWriter& jsonWriter, const ItemSet& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj);
void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj);
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
    if (obj.getAcquireScript())
    {
        jsonWriter.writePropertyName("acquireScript");
        write(jsonWriter, *obj.getAcquireScript());
    }
    if (obj.getOverflowScript())
    {
        jsonWriter.writePropertyName("overflowScript");
        write(jsonWriter, *obj.getOverflowScript());
    }
    if (obj.getConsumeScript())
    {
        jsonWriter.writePropertyName("consumeScript");
        write(jsonWriter, *obj.getConsumeScript());
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

void write(detail::json::JsonWriter& jsonWriter, const InventoryModelMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getInventoryModelId())
    {
        jsonWriter.writePropertyName("inventoryModelId");
        jsonWriter.writeCharArray(*obj.getInventoryModelId());
    }
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getMetadata())
    {
        jsonWriter.writePropertyName("metadata");
        jsonWriter.writeCharArray(*obj.getMetadata());
    }
    if (obj.getDescription())
    {
        jsonWriter.writePropertyName("description");
        jsonWriter.writeCharArray(*obj.getDescription());
    }
    if (obj.getInitialCapacity())
    {
        jsonWriter.writePropertyName("initialCapacity");
        jsonWriter.writeInt32(*obj.getInitialCapacity());
    }
    if (obj.getMaxCapacity())
    {
        jsonWriter.writePropertyName("maxCapacity");
        jsonWriter.writeInt32(*obj.getMaxCapacity());
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

void write(detail::json::JsonWriter& jsonWriter, const InventoryModel& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getInventoryModelId())
    {
        jsonWriter.writePropertyName("inventoryModelId");
        jsonWriter.writeCharArray(*obj.getInventoryModelId());
    }
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getMetadata())
    {
        jsonWriter.writePropertyName("metadata");
        jsonWriter.writeCharArray(*obj.getMetadata());
    }
    if (obj.getInitialCapacity())
    {
        jsonWriter.writePropertyName("initialCapacity");
        jsonWriter.writeInt32(*obj.getInitialCapacity());
    }
    if (obj.getMaxCapacity())
    {
        jsonWriter.writePropertyName("maxCapacity");
        jsonWriter.writeInt32(*obj.getMaxCapacity());
    }
    if (obj.getItemModels())
    {
        jsonWriter.writePropertyName("itemModels");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getItemModels();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            write(jsonWriter, list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const ItemModelMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getItemModelId())
    {
        jsonWriter.writePropertyName("itemModelId");
        jsonWriter.writeCharArray(*obj.getItemModelId());
    }
    if (obj.getInventoryName())
    {
        jsonWriter.writePropertyName("inventoryName");
        jsonWriter.writeCharArray(*obj.getInventoryName());
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
    if (obj.getMetadata())
    {
        jsonWriter.writePropertyName("metadata");
        jsonWriter.writeCharArray(*obj.getMetadata());
    }
    if (obj.getStackingLimit())
    {
        jsonWriter.writePropertyName("stackingLimit");
        jsonWriter.writeInt64(*obj.getStackingLimit());
    }
    if (obj.getAllowMultipleStacks())
    {
        jsonWriter.writePropertyName("allowMultipleStacks");
        jsonWriter.writeBool(*obj.getAllowMultipleStacks());
    }
    if (obj.getSortValue())
    {
        jsonWriter.writePropertyName("sortValue");
        jsonWriter.writeInt32(*obj.getSortValue());
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

void write(detail::json::JsonWriter& jsonWriter, const ItemModel& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getItemModelId())
    {
        jsonWriter.writePropertyName("itemModelId");
        jsonWriter.writeCharArray(*obj.getItemModelId());
    }
    if (obj.getName())
    {
        jsonWriter.writePropertyName("name");
        jsonWriter.writeCharArray(*obj.getName());
    }
    if (obj.getMetadata())
    {
        jsonWriter.writePropertyName("metadata");
        jsonWriter.writeCharArray(*obj.getMetadata());
    }
    if (obj.getStackingLimit())
    {
        jsonWriter.writePropertyName("stackingLimit");
        jsonWriter.writeInt64(*obj.getStackingLimit());
    }
    if (obj.getAllowMultipleStacks())
    {
        jsonWriter.writePropertyName("allowMultipleStacks");
        jsonWriter.writeBool(*obj.getAllowMultipleStacks());
    }
    if (obj.getSortValue())
    {
        jsonWriter.writePropertyName("sortValue");
        jsonWriter.writeInt32(*obj.getSortValue());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const CurrentItemModelMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getNamespaceName())
    {
        jsonWriter.writePropertyName("namespaceName");
        jsonWriter.writeCharArray(*obj.getNamespaceName());
    }
    if (obj.getSettings())
    {
        jsonWriter.writePropertyName("settings");
        jsonWriter.writeCharArray(*obj.getSettings());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const Inventory& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getInventoryId())
    {
        jsonWriter.writePropertyName("inventoryId");
        jsonWriter.writeCharArray(*obj.getInventoryId());
    }
    if (obj.getInventoryName())
    {
        jsonWriter.writePropertyName("inventoryName");
        jsonWriter.writeCharArray(*obj.getInventoryName());
    }
    if (obj.getUserId())
    {
        jsonWriter.writePropertyName("userId");
        jsonWriter.writeCharArray(*obj.getUserId());
    }
    if (obj.getCurrentInventoryCapacityUsage())
    {
        jsonWriter.writePropertyName("currentInventoryCapacityUsage");
        jsonWriter.writeInt32(*obj.getCurrentInventoryCapacityUsage());
    }
    if (obj.getCurrentInventoryMaxCapacity())
    {
        jsonWriter.writePropertyName("currentInventoryMaxCapacity");
        jsonWriter.writeInt32(*obj.getCurrentInventoryMaxCapacity());
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

void write(detail::json::JsonWriter& jsonWriter, const ItemSet& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getItemSetId())
    {
        jsonWriter.writePropertyName("itemSetId");
        jsonWriter.writeCharArray(*obj.getItemSetId());
    }
    if (obj.getInventoryName())
    {
        jsonWriter.writePropertyName("inventoryName");
        jsonWriter.writeCharArray(*obj.getInventoryName());
    }
    if (obj.getUserId())
    {
        jsonWriter.writePropertyName("userId");
        jsonWriter.writeCharArray(*obj.getUserId());
    }
    if (obj.getItemName())
    {
        jsonWriter.writePropertyName("itemName");
        jsonWriter.writeCharArray(*obj.getItemName());
    }
    if (obj.getCount())
    {
        jsonWriter.writePropertyName("count");
        jsonWriter.writeInt64(*obj.getCount());
    }
    if (obj.getSortValue())
    {
        jsonWriter.writePropertyName("sortValue");
        jsonWriter.writeInt32(*obj.getSortValue());
    }
    if (obj.getExpiresAt())
    {
        jsonWriter.writePropertyName("expiresAt");
        jsonWriter.writeInt64(*obj.getExpiresAt());
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

void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj)
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


class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
{
private:
    DescribeNamespacesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/";

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*m_Request.getLimit()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    DescribeNamespacesTask(
        DescribeNamespacesRequest request,
        Gs2RestSessionTask<DescribeNamespacesResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeNamespacesResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeNamespacesTask() GS2_OVERRIDE = default;
};

class CreateNamespaceTask : public detail::Gs2RestSessionTask<CreateNamespaceResult>
{
private:
    CreateNamespaceRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/";
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
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
        if (m_Request.getAcquireScript())
        {
            jsonWriter.writePropertyName("acquireScript");
            write(jsonWriter, *m_Request.getAcquireScript());
        }
        if (m_Request.getOverflowScript())
        {
            jsonWriter.writePropertyName("overflowScript");
            write(jsonWriter, *m_Request.getOverflowScript());
        }
        if (m_Request.getConsumeScript())
        {
            jsonWriter.writePropertyName("consumeScript");
            write(jsonWriter, *m_Request.getConsumeScript());
        }
        if (m_Request.getLogSetting())
        {
            jsonWriter.writePropertyName("logSetting");
            write(jsonWriter, *m_Request.getLogSetting());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    CreateNamespaceTask(
        CreateNamespaceRequest request,
        Gs2RestSessionTask<CreateNamespaceResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<CreateNamespaceResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateNamespaceTask() GS2_OVERRIDE = default;
};

class GetNamespaceStatusTask : public detail::Gs2RestSessionTask<GetNamespaceStatusResult>
{
private:
    GetNamespaceStatusRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/status";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetNamespaceStatusTask(
        GetNamespaceStatusRequest request,
        Gs2RestSessionTask<GetNamespaceStatusResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetNamespaceStatusResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
};

class GetNamespaceTask : public detail::Gs2RestSessionTask<GetNamespaceResult>
{
private:
    GetNamespaceRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetNamespaceTask(
        GetNamespaceRequest request,
        Gs2RestSessionTask<GetNamespaceResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetNamespaceResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetNamespaceTask() GS2_OVERRIDE = default;
};

class UpdateNamespaceTask : public detail::Gs2RestSessionTask<UpdateNamespaceResult>
{
private:
    UpdateNamespaceRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*m_Request.getDescription());
        }
        if (m_Request.getAcquireScript())
        {
            jsonWriter.writePropertyName("acquireScript");
            write(jsonWriter, *m_Request.getAcquireScript());
        }
        if (m_Request.getOverflowScript())
        {
            jsonWriter.writePropertyName("overflowScript");
            write(jsonWriter, *m_Request.getOverflowScript());
        }
        if (m_Request.getConsumeScript())
        {
            jsonWriter.writePropertyName("consumeScript");
            write(jsonWriter, *m_Request.getConsumeScript());
        }
        if (m_Request.getLogSetting())
        {
            jsonWriter.writePropertyName("logSetting");
            write(jsonWriter, *m_Request.getLogSetting());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Put;
    }

public:
    UpdateNamespaceTask(
        UpdateNamespaceRequest request,
        Gs2RestSessionTask<UpdateNamespaceResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateNamespaceResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateNamespaceTask() GS2_OVERRIDE = default;
};

class DeleteNamespaceTask : public detail::Gs2RestSessionTask<DeleteNamespaceResult>
{
private:
    DeleteNamespaceRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        {
            gs2HttpTask.setBody("[]");
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Delete;
    }

public:
    DeleteNamespaceTask(
        DeleteNamespaceRequest request,
        Gs2RestSessionTask<DeleteNamespaceResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteNamespaceResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteNamespaceTask() GS2_OVERRIDE = default;
};

class DescribeInventoryModelMastersTask : public detail::Gs2RestSessionTask<DescribeInventoryModelMastersResult>
{
private:
    DescribeInventoryModelMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*m_Request.getLimit()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    DescribeInventoryModelMastersTask(
        DescribeInventoryModelMastersRequest request,
        Gs2RestSessionTask<DescribeInventoryModelMastersResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeInventoryModelMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeInventoryModelMastersTask() GS2_OVERRIDE = default;
};

class CreateInventoryModelMasterTask : public detail::Gs2RestSessionTask<CreateInventoryModelMasterResult>
{
private:
    CreateInventoryModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
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
        if (m_Request.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*m_Request.getMetadata());
        }
        if (m_Request.getInitialCapacity())
        {
            jsonWriter.writePropertyName("initialCapacity");
            jsonWriter.writeInt32(*m_Request.getInitialCapacity());
        }
        if (m_Request.getMaxCapacity())
        {
            jsonWriter.writePropertyName("maxCapacity");
            jsonWriter.writeInt32(*m_Request.getMaxCapacity());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    CreateInventoryModelMasterTask(
        CreateInventoryModelMasterRequest request,
        Gs2RestSessionTask<CreateInventoryModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<CreateInventoryModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateInventoryModelMasterTask() GS2_OVERRIDE = default;
};

class GetInventoryModelMasterTask : public detail::Gs2RestSessionTask<GetInventoryModelMasterResult>
{
private:
    GetInventoryModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory/{inventoryName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetInventoryModelMasterTask(
        GetInventoryModelMasterRequest request,
        Gs2RestSessionTask<GetInventoryModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetInventoryModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetInventoryModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateInventoryModelMasterTask : public detail::Gs2RestSessionTask<UpdateInventoryModelMasterResult>
{
private:
    UpdateInventoryModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory/{inventoryName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*m_Request.getDescription());
        }
        if (m_Request.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*m_Request.getMetadata());
        }
        if (m_Request.getInitialCapacity())
        {
            jsonWriter.writePropertyName("initialCapacity");
            jsonWriter.writeInt32(*m_Request.getInitialCapacity());
        }
        if (m_Request.getMaxCapacity())
        {
            jsonWriter.writePropertyName("maxCapacity");
            jsonWriter.writeInt32(*m_Request.getMaxCapacity());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Put;
    }

public:
    UpdateInventoryModelMasterTask(
        UpdateInventoryModelMasterRequest request,
        Gs2RestSessionTask<UpdateInventoryModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateInventoryModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateInventoryModelMasterTask() GS2_OVERRIDE = default;
};

class DeleteInventoryModelMasterTask : public detail::Gs2RestSessionTask<DeleteInventoryModelMasterResult>
{
private:
    DeleteInventoryModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory/{inventoryName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        {
            gs2HttpTask.setBody("[]");
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Delete;
    }

public:
    DeleteInventoryModelMasterTask(
        DeleteInventoryModelMasterRequest request,
        Gs2RestSessionTask<DeleteInventoryModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteInventoryModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteInventoryModelMasterTask() GS2_OVERRIDE = default;
};

class DescribeInventoryModelsTask : public detail::Gs2RestSessionTask<DescribeInventoryModelsResult>
{
private:
    DescribeInventoryModelsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/inventory";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    DescribeInventoryModelsTask(
        DescribeInventoryModelsRequest request,
        Gs2RestSessionTask<DescribeInventoryModelsResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeInventoryModelsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeInventoryModelsTask() GS2_OVERRIDE = default;
};

class GetInventoryModelTask : public detail::Gs2RestSessionTask<GetInventoryModelResult>
{
private:
    GetInventoryModelRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/inventory/{inventoryName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetInventoryModelTask(
        GetInventoryModelRequest request,
        Gs2RestSessionTask<GetInventoryModelResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetInventoryModelResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetInventoryModelTask() GS2_OVERRIDE = default;
};

class DescribeItemModelMastersTask : public detail::Gs2RestSessionTask<DescribeItemModelMastersResult>
{
private:
    DescribeItemModelMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory/{inventoryName}/item";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*m_Request.getLimit()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    DescribeItemModelMastersTask(
        DescribeItemModelMastersRequest request,
        Gs2RestSessionTask<DescribeItemModelMastersResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeItemModelMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeItemModelMastersTask() GS2_OVERRIDE = default;
};

class CreateItemModelMasterTask : public detail::Gs2RestSessionTask<CreateItemModelMasterResult>
{
private:
    CreateItemModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory/{inventoryName}/item";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
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
        if (m_Request.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*m_Request.getMetadata());
        }
        if (m_Request.getStackingLimit())
        {
            jsonWriter.writePropertyName("stackingLimit");
            jsonWriter.writeInt64(*m_Request.getStackingLimit());
        }
        if (m_Request.getAllowMultipleStacks())
        {
            jsonWriter.writePropertyName("allowMultipleStacks");
            jsonWriter.writeBool(*m_Request.getAllowMultipleStacks());
        }
        if (m_Request.getSortValue())
        {
            jsonWriter.writePropertyName("sortValue");
            jsonWriter.writeInt32(*m_Request.getSortValue());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    CreateItemModelMasterTask(
        CreateItemModelMasterRequest request,
        Gs2RestSessionTask<CreateItemModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<CreateItemModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateItemModelMasterTask() GS2_OVERRIDE = default;
};

class GetItemModelMasterTask : public detail::Gs2RestSessionTask<GetItemModelMasterResult>
{
private:
    GetItemModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetItemModelMasterTask(
        GetItemModelMasterRequest request,
        Gs2RestSessionTask<GetItemModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetItemModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetItemModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateItemModelMasterTask : public detail::Gs2RestSessionTask<UpdateItemModelMasterResult>
{
private:
    UpdateItemModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*m_Request.getDescription());
        }
        if (m_Request.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*m_Request.getMetadata());
        }
        if (m_Request.getStackingLimit())
        {
            jsonWriter.writePropertyName("stackingLimit");
            jsonWriter.writeInt64(*m_Request.getStackingLimit());
        }
        if (m_Request.getAllowMultipleStacks())
        {
            jsonWriter.writePropertyName("allowMultipleStacks");
            jsonWriter.writeBool(*m_Request.getAllowMultipleStacks());
        }
        if (m_Request.getSortValue())
        {
            jsonWriter.writePropertyName("sortValue");
            jsonWriter.writeInt32(*m_Request.getSortValue());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Put;
    }

public:
    UpdateItemModelMasterTask(
        UpdateItemModelMasterRequest request,
        Gs2RestSessionTask<UpdateItemModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateItemModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateItemModelMasterTask() GS2_OVERRIDE = default;
};

class DeleteItemModelMasterTask : public detail::Gs2RestSessionTask<DeleteItemModelMasterResult>
{
private:
    DeleteItemModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        {
            gs2HttpTask.setBody("[]");
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Delete;
    }

public:
    DeleteItemModelMasterTask(
        DeleteItemModelMasterRequest request,
        Gs2RestSessionTask<DeleteItemModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteItemModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteItemModelMasterTask() GS2_OVERRIDE = default;
};

class DescribeItemModelsTask : public detail::Gs2RestSessionTask<DescribeItemModelsResult>
{
private:
    DescribeItemModelsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/inventory/{inventoryName}/item";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    DescribeItemModelsTask(
        DescribeItemModelsRequest request,
        Gs2RestSessionTask<DescribeItemModelsResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeItemModelsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeItemModelsTask() GS2_OVERRIDE = default;
};

class GetItemModelTask : public detail::Gs2RestSessionTask<GetItemModelResult>
{
private:
    GetItemModelRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetItemModelTask(
        GetItemModelRequest request,
        Gs2RestSessionTask<GetItemModelResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetItemModelResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetItemModelTask() GS2_OVERRIDE = default;
};

class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
{
private:
    ExportMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/export";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    ExportMasterTask(
        ExportMasterRequest request,
        Gs2RestSessionTask<ExportMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<ExportMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~ExportMasterTask() GS2_OVERRIDE = default;
};

class GetCurrentItemModelMasterTask : public detail::Gs2RestSessionTask<GetCurrentItemModelMasterResult>
{
private:
    GetCurrentItemModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetCurrentItemModelMasterTask(
        GetCurrentItemModelMasterRequest request,
        Gs2RestSessionTask<GetCurrentItemModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetCurrentItemModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetCurrentItemModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentItemModelMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentItemModelMasterResult>
{
private:
    UpdateCurrentItemModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getSettings())
        {
            jsonWriter.writePropertyName("settings");
            jsonWriter.writeCharArray(*m_Request.getSettings());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Put;
    }

public:
    UpdateCurrentItemModelMasterTask(
        UpdateCurrentItemModelMasterRequest request,
        Gs2RestSessionTask<UpdateCurrentItemModelMasterResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateCurrentItemModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentItemModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentItemModelMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentItemModelMasterFromGitHubResult>
{
private:
    UpdateCurrentItemModelMasterFromGitHubRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/master/from_git_hub";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getCheckoutSetting())
        {
            jsonWriter.writePropertyName("checkoutSetting");
            write(jsonWriter, *m_Request.getCheckoutSetting());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }

        return detail::Gs2HttpTask::Verb::Put;
    }

public:
    UpdateCurrentItemModelMasterFromGitHubTask(
        UpdateCurrentItemModelMasterFromGitHubRequest request,
        Gs2RestSessionTask<UpdateCurrentItemModelMasterFromGitHubResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateCurrentItemModelMasterFromGitHubResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentItemModelMasterFromGitHubTask() GS2_OVERRIDE = default;
};

class DescribeInventoriesTask : public detail::Gs2RestSessionTask<DescribeInventoriesResult>
{
private:
    DescribeInventoriesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/inventory";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*m_Request.getLimit()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getAccessToken())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    DescribeInventoriesTask(
        DescribeInventoriesRequest request,
        Gs2RestSessionTask<DescribeInventoriesResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeInventoriesResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeInventoriesTask() GS2_OVERRIDE = default;
};

class DescribeInventoriesByUserIdTask : public detail::Gs2RestSessionTask<DescribeInventoriesByUserIdResult>
{
private:
    DescribeInventoriesByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*m_Request.getLimit()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    DescribeInventoriesByUserIdTask(
        DescribeInventoriesByUserIdRequest request,
        Gs2RestSessionTask<DescribeInventoriesByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeInventoriesByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeInventoriesByUserIdTask() GS2_OVERRIDE = default;
};

class GetInventoryTask : public detail::Gs2RestSessionTask<GetInventoryResult>
{
private:
    GetInventoryRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/inventory/{inventoryName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getAccessToken())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetInventoryTask(
        GetInventoryRequest request,
        Gs2RestSessionTask<GetInventoryResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetInventoryResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetInventoryTask() GS2_OVERRIDE = default;
};

class GetInventoryByUserIdTask : public detail::Gs2RestSessionTask<GetInventoryByUserIdResult>
{
private:
    GetInventoryByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetInventoryByUserIdTask(
        GetInventoryByUserIdRequest request,
        Gs2RestSessionTask<GetInventoryByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetInventoryByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetInventoryByUserIdTask() GS2_OVERRIDE = default;
};

class AddCapacityByUserIdTask : public detail::Gs2RestSessionTask<AddCapacityByUserIdResult>
{
private:
    AddCapacityByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/capacity";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getAddCapacityValue())
        {
            jsonWriter.writePropertyName("addCapacityValue");
            jsonWriter.writeInt32(*m_Request.getAddCapacityValue());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    AddCapacityByUserIdTask(
        AddCapacityByUserIdRequest request,
        Gs2RestSessionTask<AddCapacityByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<AddCapacityByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~AddCapacityByUserIdTask() GS2_OVERRIDE = default;
};

class SetCapacityByUserIdTask : public detail::Gs2RestSessionTask<SetCapacityByUserIdResult>
{
private:
    SetCapacityByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/capacity";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getNewCapacityValue())
        {
            jsonWriter.writePropertyName("newCapacityValue");
            jsonWriter.writeInt32(*m_Request.getNewCapacityValue());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Put;
    }

public:
    SetCapacityByUserIdTask(
        SetCapacityByUserIdRequest request,
        Gs2RestSessionTask<SetCapacityByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<SetCapacityByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetCapacityByUserIdTask() GS2_OVERRIDE = default;
};

class DeleteInventoryByUserIdTask : public detail::Gs2RestSessionTask<DeleteInventoryByUserIdResult>
{
private:
    DeleteInventoryByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        {
            gs2HttpTask.setBody("[]");
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Delete;
    }

public:
    DeleteInventoryByUserIdTask(
        DeleteInventoryByUserIdRequest request,
        Gs2RestSessionTask<DeleteInventoryByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteInventoryByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteInventoryByUserIdTask() GS2_OVERRIDE = default;
};

class AddCapacityByStampSheetTask : public detail::Gs2RestSessionTask<AddCapacityByStampSheetResult>
{
private:
    AddCapacityByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/stamp/inventory/capacity/add";
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStampSheet())
        {
            jsonWriter.writePropertyName("stampSheet");
            jsonWriter.writeCharArray(*m_Request.getStampSheet());
        }
        if (m_Request.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*m_Request.getKeyId());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    AddCapacityByStampSheetTask(
        AddCapacityByStampSheetRequest request,
        Gs2RestSessionTask<AddCapacityByStampSheetResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<AddCapacityByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~AddCapacityByStampSheetTask() GS2_OVERRIDE = default;
};

class SetCapacityByStampSheetTask : public detail::Gs2RestSessionTask<SetCapacityByStampSheetResult>
{
private:
    SetCapacityByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/stamp/inventory/capacity/set";
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStampSheet())
        {
            jsonWriter.writePropertyName("stampSheet");
            jsonWriter.writeCharArray(*m_Request.getStampSheet());
        }
        if (m_Request.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*m_Request.getKeyId());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    SetCapacityByStampSheetTask(
        SetCapacityByStampSheetRequest request,
        Gs2RestSessionTask<SetCapacityByStampSheetResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<SetCapacityByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetCapacityByStampSheetTask() GS2_OVERRIDE = default;
};

class DescribeItemSetsTask : public detail::Gs2RestSessionTask<DescribeItemSetsResult>
{
private:
    DescribeItemSetsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/inventory/{inventoryName}/item";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*m_Request.getLimit()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getAccessToken())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    DescribeItemSetsTask(
        DescribeItemSetsRequest request,
        Gs2RestSessionTask<DescribeItemSetsResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeItemSetsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeItemSetsTask() GS2_OVERRIDE = default;
};

class DescribeItemSetsByUserIdTask : public detail::Gs2RestSessionTask<DescribeItemSetsByUserIdResult>
{
private:
    DescribeItemSetsByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*m_Request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*m_Request.getLimit()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    DescribeItemSetsByUserIdTask(
        DescribeItemSetsByUserIdRequest request,
        Gs2RestSessionTask<DescribeItemSetsByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeItemSetsByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeItemSetsByUserIdTask() GS2_OVERRIDE = default;
};

class GetItemSetTask : public detail::Gs2RestSessionTask<GetItemSetResult>
{
private:
    GetItemSetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getExpiresAt())
        {
            url += joint;
            url += "expiresAt=";
            url += detail::StringVariable(*m_Request.getExpiresAt()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getAccessToken())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetItemSetTask(
        GetItemSetRequest request,
        Gs2RestSessionTask<GetItemSetResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetItemSetResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetItemSetTask() GS2_OVERRIDE = default;
};

class GetItemSetByUserIdTask : public detail::Gs2RestSessionTask<GetItemSetByUserIdResult>
{
private:
    GetItemSetByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getExpiresAt())
        {
            url += joint;
            url += "expiresAt=";
            url += detail::StringVariable(*m_Request.getExpiresAt()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetItemSetByUserIdTask(
        GetItemSetByUserIdRequest request,
        Gs2RestSessionTask<GetItemSetByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetItemSetByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetItemSetByUserIdTask() GS2_OVERRIDE = default;
};

class GetItemWithSignatureTask : public detail::Gs2RestSessionTask<GetItemWithSignatureResult>
{
private:
    GetItemWithSignatureRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/inventory/{inventoryName}/item/{itemName}/signature";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getExpiresAt())
        {
            url += joint;
            url += "expiresAt=";
            url += detail::StringVariable(*m_Request.getExpiresAt()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getKeyId())
        {
            url += joint;
            url += "keyId=";
            url += detail::StringVariable(*m_Request.getKeyId(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getAccessToken())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetItemWithSignatureTask(
        GetItemWithSignatureRequest request,
        Gs2RestSessionTask<GetItemWithSignatureResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetItemWithSignatureResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetItemWithSignatureTask() GS2_OVERRIDE = default;
};

class GetItemWithSignatureByUserIdTask : public detail::Gs2RestSessionTask<GetItemWithSignatureByUserIdResult>
{
private:
    GetItemWithSignatureByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item/{itemName}/signature";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getExpiresAt())
        {
            url += joint;
            url += "expiresAt=";
            url += detail::StringVariable(*m_Request.getExpiresAt()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getKeyId())
        {
            url += joint;
            url += "keyId=";
            url += detail::StringVariable(*m_Request.getKeyId(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Get;
    }

public:
    GetItemWithSignatureByUserIdTask(
        GetItemWithSignatureByUserIdRequest request,
        Gs2RestSessionTask<GetItemWithSignatureByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetItemWithSignatureByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetItemWithSignatureByUserIdTask() GS2_OVERRIDE = default;
};

class AcquireItemSetByUserIdTask : public detail::Gs2RestSessionTask<AcquireItemSetByUserIdResult>
{
private:
    AcquireItemSetByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item/{itemName}/acquire";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getAcquireCount())
        {
            jsonWriter.writePropertyName("acquireCount");
            jsonWriter.writeInt64(*m_Request.getAcquireCount());
        }
        if (m_Request.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*m_Request.getExpiresAt());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    AcquireItemSetByUserIdTask(
        AcquireItemSetByUserIdRequest request,
        Gs2RestSessionTask<AcquireItemSetByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<AcquireItemSetByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~AcquireItemSetByUserIdTask() GS2_OVERRIDE = default;
};

class ConsumeItemSetTask : public detail::Gs2RestSessionTask<ConsumeItemSetResult>
{
private:
    ConsumeItemSetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/me/inventory/{inventoryName}/item/{itemName}/consume";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getConsumeCount())
        {
            jsonWriter.writePropertyName("consumeCount");
            jsonWriter.writeInt64(*m_Request.getConsumeCount());
        }
        if (m_Request.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*m_Request.getExpiresAt());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getAccessToken())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    ConsumeItemSetTask(
        ConsumeItemSetRequest request,
        Gs2RestSessionTask<ConsumeItemSetResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<ConsumeItemSetResult>(callback),
        m_Request(std::move(request))
    {}

    ~ConsumeItemSetTask() GS2_OVERRIDE = default;
};

class ConsumeItemSetByUserIdTask : public detail::Gs2RestSessionTask<ConsumeItemSetByUserIdResult>
{
private:
    ConsumeItemSetByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item/{itemName}/consume";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getConsumeCount())
        {
            jsonWriter.writePropertyName("consumeCount");
            jsonWriter.writeInt64(*m_Request.getConsumeCount());
        }
        if (m_Request.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*m_Request.getExpiresAt());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    ConsumeItemSetByUserIdTask(
        ConsumeItemSetByUserIdRequest request,
        Gs2RestSessionTask<ConsumeItemSetByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<ConsumeItemSetByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~ConsumeItemSetByUserIdTask() GS2_OVERRIDE = default;
};

class DeleteItemSetByUserIdTask : public detail::Gs2RestSessionTask<DeleteItemSetByUserIdResult>
{
private:
    DeleteItemSetByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/user/{userId}/inventory/{inventoryName}/item/{itemName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getInventoryName();
            url.replace("{inventoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getItemName();
            url.replace("{itemName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (m_Request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (m_Request.getExpiresAt())
        {
            url += joint;
            url += "expiresAt=";
            url += detail::StringVariable(*m_Request.getExpiresAt()).c_str();
            joint[0] = '&';
        }
        {
            gs2HttpTask.setBody("[]");
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Delete;
    }

public:
    DeleteItemSetByUserIdTask(
        DeleteItemSetByUserIdRequest request,
        Gs2RestSessionTask<DeleteItemSetByUserIdResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DeleteItemSetByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteItemSetByUserIdTask() GS2_OVERRIDE = default;
};

class AcquireItemSetByStampSheetTask : public detail::Gs2RestSessionTask<AcquireItemSetByStampSheetResult>
{
private:
    AcquireItemSetByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/stamp/item/acquire";
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStampSheet())
        {
            jsonWriter.writePropertyName("stampSheet");
            jsonWriter.writeCharArray(*m_Request.getStampSheet());
        }
        if (m_Request.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*m_Request.getKeyId());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    AcquireItemSetByStampSheetTask(
        AcquireItemSetByStampSheetRequest request,
        Gs2RestSessionTask<AcquireItemSetByStampSheetResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<AcquireItemSetByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~AcquireItemSetByStampSheetTask() GS2_OVERRIDE = default;
};

class ConsumeItemSetByStampTaskTask : public detail::Gs2RestSessionTask<ConsumeItemSetByStampTaskResult>
{
private:
    ConsumeItemSetByStampTaskRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "inventory";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/stamp/item/consume";
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getStampTask())
        {
            jsonWriter.writePropertyName("stampTask");
            jsonWriter.writeCharArray(*m_Request.getStampTask());
        }
        if (m_Request.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*m_Request.getKeyId());
        }
        jsonWriter.writeObjectEnd();
        {
            gs2HttpTask.setBody(jsonWriter.toString());
        }
        gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

        if (m_Request.getRequestId())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
        }
        if (m_Request.getDuplicationAvoider())
        {
            gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
        }

        return detail::Gs2HttpTask::Verb::Post;
    }

public:
    ConsumeItemSetByStampTaskTask(
        ConsumeItemSetByStampTaskRequest request,
        Gs2RestSessionTask<ConsumeItemSetByStampTaskResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<ConsumeItemSetByStampTaskResult>(callback),
        m_Request(std::move(request))
    {}

    ~ConsumeItemSetByStampTaskTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
{
    DescribeNamespacesTask& task = *new DescribeNamespacesTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ネームスペースを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
{
    CreateNamespaceTask& task = *new CreateNamespaceTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ネームスペースの状態を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
{
    GetNamespaceStatusTask& task = *new GetNamespaceStatusTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ネームスペースを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
{
    GetNamespaceTask& task = *new GetNamespaceTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ネームスペースを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
{
    UpdateNamespaceTask& task = *new UpdateNamespaceTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * ネームスペースを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリモデルマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::describeInventoryModelMasters(DescribeInventoryModelMastersRequest request, std::function<void(AsyncDescribeInventoryModelMastersResult)> callback)
{
    DescribeInventoryModelMastersTask& task = *new DescribeInventoryModelMastersTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリモデルマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::createInventoryModelMaster(CreateInventoryModelMasterRequest request, std::function<void(AsyncCreateInventoryModelMasterResult)> callback)
{
    CreateInventoryModelMasterTask& task = *new CreateInventoryModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリモデルマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getInventoryModelMaster(GetInventoryModelMasterRequest request, std::function<void(AsyncGetInventoryModelMasterResult)> callback)
{
    GetInventoryModelMasterTask& task = *new GetInventoryModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリモデルマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::updateInventoryModelMaster(UpdateInventoryModelMasterRequest request, std::function<void(AsyncUpdateInventoryModelMasterResult)> callback)
{
    UpdateInventoryModelMasterTask& task = *new UpdateInventoryModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリモデルマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::deleteInventoryModelMaster(DeleteInventoryModelMasterRequest request, std::function<void(AsyncDeleteInventoryModelMasterResult)> callback)
{
    DeleteInventoryModelMasterTask& task = *new DeleteInventoryModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリモデルの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::describeInventoryModels(DescribeInventoryModelsRequest request, std::function<void(AsyncDescribeInventoryModelsResult)> callback)
{
    DescribeInventoryModelsTask& task = *new DescribeInventoryModelsTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリモデルを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getInventoryModel(GetInventoryModelRequest request, std::function<void(AsyncGetInventoryModelResult)> callback)
{
    GetInventoryModelTask& task = *new GetInventoryModelTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * アイテムモデルマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::describeItemModelMasters(DescribeItemModelMastersRequest request, std::function<void(AsyncDescribeItemModelMastersResult)> callback)
{
    DescribeItemModelMastersTask& task = *new DescribeItemModelMastersTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * アイテムモデルマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::createItemModelMaster(CreateItemModelMasterRequest request, std::function<void(AsyncCreateItemModelMasterResult)> callback)
{
    CreateItemModelMasterTask& task = *new CreateItemModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * アイテムモデルマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getItemModelMaster(GetItemModelMasterRequest request, std::function<void(AsyncGetItemModelMasterResult)> callback)
{
    GetItemModelMasterTask& task = *new GetItemModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * アイテムモデルマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::updateItemModelMaster(UpdateItemModelMasterRequest request, std::function<void(AsyncUpdateItemModelMasterResult)> callback)
{
    UpdateItemModelMasterTask& task = *new UpdateItemModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * アイテムモデルマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::deleteItemModelMaster(DeleteItemModelMasterRequest request, std::function<void(AsyncDeleteItemModelMasterResult)> callback)
{
    DeleteItemModelMasterTask& task = *new DeleteItemModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * Noneの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::describeItemModels(DescribeItemModelsRequest request, std::function<void(AsyncDescribeItemModelsResult)> callback)
{
    DescribeItemModelsTask& task = *new DescribeItemModelsTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * Noneを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getItemModel(GetItemModelRequest request, std::function<void(AsyncGetItemModelResult)> callback)
{
    GetItemModelTask& task = *new GetItemModelTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効な所持品マスターのマスターデータをエクスポートします<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
{
    ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効な所持品マスターを取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getCurrentItemModelMaster(GetCurrentItemModelMasterRequest request, std::function<void(AsyncGetCurrentItemModelMasterResult)> callback)
{
    GetCurrentItemModelMasterTask& task = *new GetCurrentItemModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効な所持品マスターを更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::updateCurrentItemModelMaster(UpdateCurrentItemModelMasterRequest request, std::function<void(AsyncUpdateCurrentItemModelMasterResult)> callback)
{
    UpdateCurrentItemModelMasterTask& task = *new UpdateCurrentItemModelMasterTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 現在有効な所持品マスターを更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::updateCurrentItemModelMasterFromGitHub(UpdateCurrentItemModelMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentItemModelMasterFromGitHubResult)> callback)
{
    UpdateCurrentItemModelMasterFromGitHubTask& task = *new UpdateCurrentItemModelMasterFromGitHubTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::describeInventories(DescribeInventoriesRequest request, std::function<void(AsyncDescribeInventoriesResult)> callback)
{
    DescribeInventoriesTask& task = *new DescribeInventoriesTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::describeInventoriesByUserId(DescribeInventoriesByUserIdRequest request, std::function<void(AsyncDescribeInventoriesByUserIdResult)> callback)
{
    DescribeInventoriesByUserIdTask& task = *new DescribeInventoriesByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getInventory(GetInventoryRequest request, std::function<void(AsyncGetInventoryResult)> callback)
{
    GetInventoryTask& task = *new GetInventoryTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getInventoryByUserId(GetInventoryByUserIdRequest request, std::function<void(AsyncGetInventoryByUserIdResult)> callback)
{
    GetInventoryByUserIdTask& task = *new GetInventoryByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * キャパシティサイズを加算<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::addCapacityByUserId(AddCapacityByUserIdRequest request, std::function<void(AsyncAddCapacityByUserIdResult)> callback)
{
    AddCapacityByUserIdTask& task = *new AddCapacityByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * キャパシティサイズを設定<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::setCapacityByUserId(SetCapacityByUserIdRequest request, std::function<void(AsyncSetCapacityByUserIdResult)> callback)
{
    SetCapacityByUserIdTask& task = *new SetCapacityByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::deleteInventoryByUserId(DeleteInventoryByUserIdRequest request, std::function<void(AsyncDeleteInventoryByUserIdResult)> callback)
{
    DeleteInventoryByUserIdTask& task = *new DeleteInventoryByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * スタンプシートでキャパシティサイズを加算<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::addCapacityByStampSheet(AddCapacityByStampSheetRequest request, std::function<void(AsyncAddCapacityByStampSheetResult)> callback)
{
    AddCapacityByStampSheetTask& task = *new AddCapacityByStampSheetTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * スタンプシートでキャパシティサイズを設定<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::setCapacityByStampSheet(SetCapacityByStampSheetRequest request, std::function<void(AsyncSetCapacityByStampSheetResult)> callback)
{
    SetCapacityByStampSheetTask& task = *new SetCapacityByStampSheetTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 有効期限ごとのアイテム所持数量の一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::describeItemSets(DescribeItemSetsRequest request, std::function<void(AsyncDescribeItemSetsResult)> callback)
{
    DescribeItemSetsTask& task = *new DescribeItemSetsTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 有効期限ごとのアイテム所持数量の一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::describeItemSetsByUserId(DescribeItemSetsByUserIdRequest request, std::function<void(AsyncDescribeItemSetsByUserIdResult)> callback)
{
    DescribeItemSetsByUserIdTask& task = *new DescribeItemSetsByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 有効期限ごとのアイテム所持数量を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getItemSet(GetItemSetRequest request, std::function<void(AsyncGetItemSetResult)> callback)
{
    GetItemSetTask& task = *new GetItemSetTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 有効期限ごとのアイテム所持数量を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getItemSetByUserId(GetItemSetByUserIdRequest request, std::function<void(AsyncGetItemSetByUserIdResult)> callback)
{
    GetItemSetByUserIdTask& task = *new GetItemSetByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 有効期限ごとのアイテム所持数量を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getItemWithSignature(GetItemWithSignatureRequest request, std::function<void(AsyncGetItemWithSignatureResult)> callback)
{
    GetItemWithSignatureTask& task = *new GetItemWithSignatureTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 有効期限ごとのアイテム所持数量を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::getItemWithSignatureByUserId(GetItemWithSignatureByUserIdRequest request, std::function<void(AsyncGetItemWithSignatureByUserIdResult)> callback)
{
    GetItemWithSignatureByUserIdTask& task = *new GetItemWithSignatureByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * アイテムをインベントリに追加<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::acquireItemSetByUserId(AcquireItemSetByUserIdRequest request, std::function<void(AsyncAcquireItemSetByUserIdResult)> callback)
{
    AcquireItemSetByUserIdTask& task = *new AcquireItemSetByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリのアイテムを消費<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::consumeItemSet(ConsumeItemSetRequest request, std::function<void(AsyncConsumeItemSetResult)> callback)
{
    ConsumeItemSetTask& task = *new ConsumeItemSetTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * インベントリのアイテムを消費<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::consumeItemSetByUserId(ConsumeItemSetByUserIdRequest request, std::function<void(AsyncConsumeItemSetByUserIdResult)> callback)
{
    ConsumeItemSetByUserIdTask& task = *new ConsumeItemSetByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 有効期限ごとのアイテム所持数量を削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::deleteItemSetByUserId(DeleteItemSetByUserIdRequest request, std::function<void(AsyncDeleteItemSetByUserIdResult)> callback)
{
    DeleteItemSetByUserIdTask& task = *new DeleteItemSetByUserIdTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * スタンプシートでアイテムをインベントリに追加<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::acquireItemSetByStampSheet(AcquireItemSetByStampSheetRequest request, std::function<void(AsyncAcquireItemSetByStampSheetResult)> callback)
{
    AcquireItemSetByStampSheetTask& task = *new AcquireItemSetByStampSheetTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * スタンプシートでインベントリのアイテムを消費<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2InventoryRestClient::consumeItemSetByStampTask(ConsumeItemSetByStampTaskRequest request, std::function<void(AsyncConsumeItemSetByStampTaskResult)> callback)
{
    ConsumeItemSetByStampTaskTask& task = *new ConsumeItemSetByStampTaskTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

} }