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

#include "Gs2StaminaWebSocketClient.hpp"
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeStaminaModelMastersRequest.hpp"
#include "request/CreateStaminaModelMasterRequest.hpp"
#include "request/GetStaminaModelMasterRequest.hpp"
#include "request/UpdateStaminaModelMasterRequest.hpp"
#include "request/DeleteStaminaModelMasterRequest.hpp"
#include "request/DescribeMaxStaminaTableMastersRequest.hpp"
#include "request/CreateMaxStaminaTableMasterRequest.hpp"
#include "request/GetMaxStaminaTableMasterRequest.hpp"
#include "request/UpdateMaxStaminaTableMasterRequest.hpp"
#include "request/DeleteMaxStaminaTableMasterRequest.hpp"
#include "request/DescribeRecoverIntervalTableMastersRequest.hpp"
#include "request/CreateRecoverIntervalTableMasterRequest.hpp"
#include "request/GetRecoverIntervalTableMasterRequest.hpp"
#include "request/UpdateRecoverIntervalTableMasterRequest.hpp"
#include "request/DeleteRecoverIntervalTableMasterRequest.hpp"
#include "request/DescribeRecoverValueTableMastersRequest.hpp"
#include "request/CreateRecoverValueTableMasterRequest.hpp"
#include "request/GetRecoverValueTableMasterRequest.hpp"
#include "request/UpdateRecoverValueTableMasterRequest.hpp"
#include "request/DeleteRecoverValueTableMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentStaminaMasterRequest.hpp"
#include "request/UpdateCurrentStaminaMasterRequest.hpp"
#include "request/UpdateCurrentStaminaMasterFromGitHubRequest.hpp"
#include "request/DescribeStaminaModelsRequest.hpp"
#include "request/GetStaminaModelRequest.hpp"
#include "request/DescribeStaminasRequest.hpp"
#include "request/DescribeStaminasByUserIdRequest.hpp"
#include "request/GetStaminaRequest.hpp"
#include "request/GetStaminaByUserIdRequest.hpp"
#include "request/UpdateStaminaByUserIdRequest.hpp"
#include "request/ConsumeStaminaRequest.hpp"
#include "request/ConsumeStaminaByUserIdRequest.hpp"
#include "request/RecoverStaminaByUserIdRequest.hpp"
#include "request/RaiseMaxValueByUserIdRequest.hpp"
#include "request/SetMaxValueByUserIdRequest.hpp"
#include "request/SetRecoverIntervalByUserIdRequest.hpp"
#include "request/SetRecoverValueByUserIdRequest.hpp"
#include "request/SetMaxValueByStatusRequest.hpp"
#include "request/SetRecoverIntervalByStatusRequest.hpp"
#include "request/SetRecoverValueByStatusRequest.hpp"
#include "request/DeleteStaminaByUserIdRequest.hpp"
#include "request/RecoverStaminaByStampSheetRequest.hpp"
#include "request/RaiseMaxValueByStampSheetRequest.hpp"
#include "request/SetMaxValueByStampSheetRequest.hpp"
#include "request/SetRecoverIntervalByStampSheetRequest.hpp"
#include "request/SetRecoverValueByStampSheetRequest.hpp"
#include "request/ConsumeStaminaByStampTaskRequest.hpp"
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const StaminaModelMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const MaxStaminaTableMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const RecoverIntervalTableMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const RecoverValueTableMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const CurrentStaminaMaster& obj);
void write(detail::json::JsonWriter& jsonWriter, const StaminaModel& obj);
void write(detail::json::JsonWriter& jsonWriter, const MaxStaminaTable& obj);
void write(detail::json::JsonWriter& jsonWriter, const RecoverIntervalTable& obj);
void write(detail::json::JsonWriter& jsonWriter, const RecoverValueTable& obj);
void write(detail::json::JsonWriter& jsonWriter, const Stamina& obj);
void write(detail::json::JsonWriter& jsonWriter, const ResponseCache& obj);
void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj);
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
    if (obj.getOverflowTriggerScriptId())
    {
        jsonWriter.writePropertyName("overflowTriggerScriptId");
        jsonWriter.writeCharArray(*obj.getOverflowTriggerScriptId());
    }
    if (obj.getOverflowTriggerNamespaceId())
    {
        jsonWriter.writePropertyName("overflowTriggerNamespaceId");
        jsonWriter.writeCharArray(*obj.getOverflowTriggerNamespaceId());
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

void write(detail::json::JsonWriter& jsonWriter, const StaminaModelMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getStaminaModelId())
    {
        jsonWriter.writePropertyName("staminaModelId");
        jsonWriter.writeCharArray(*obj.getStaminaModelId());
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
    if (obj.getRecoverIntervalMinutes())
    {
        jsonWriter.writePropertyName("recoverIntervalMinutes");
        jsonWriter.writeInt32(*obj.getRecoverIntervalMinutes());
    }
    if (obj.getRecoverValue())
    {
        jsonWriter.writePropertyName("recoverValue");
        jsonWriter.writeInt32(*obj.getRecoverValue());
    }
    if (obj.getInitialCapacity())
    {
        jsonWriter.writePropertyName("initialCapacity");
        jsonWriter.writeInt32(*obj.getInitialCapacity());
    }
    if (obj.getIsOverflow())
    {
        jsonWriter.writePropertyName("isOverflow");
        jsonWriter.writeBool(*obj.getIsOverflow());
    }
    if (obj.getMaxCapacity())
    {
        jsonWriter.writePropertyName("maxCapacity");
        jsonWriter.writeInt32(*obj.getMaxCapacity());
    }
    if (obj.getMaxStaminaTableId())
    {
        jsonWriter.writePropertyName("maxStaminaTableId");
        jsonWriter.writeCharArray(*obj.getMaxStaminaTableId());
    }
    if (obj.getRecoverIntervalTableId())
    {
        jsonWriter.writePropertyName("recoverIntervalTableId");
        jsonWriter.writeCharArray(*obj.getRecoverIntervalTableId());
    }
    if (obj.getRecoverValueTableId())
    {
        jsonWriter.writePropertyName("recoverValueTableId");
        jsonWriter.writeCharArray(*obj.getRecoverValueTableId());
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

void write(detail::json::JsonWriter& jsonWriter, const MaxStaminaTableMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getMaxStaminaTableId())
    {
        jsonWriter.writePropertyName("maxStaminaTableId");
        jsonWriter.writeCharArray(*obj.getMaxStaminaTableId());
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
    if (obj.getExperienceModelId())
    {
        jsonWriter.writePropertyName("experienceModelId");
        jsonWriter.writeCharArray(*obj.getExperienceModelId());
    }
    if (obj.getValues())
    {
        jsonWriter.writePropertyName("values");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getValues();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeInt32(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const RecoverIntervalTableMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getRecoverIntervalTableId())
    {
        jsonWriter.writePropertyName("recoverIntervalTableId");
        jsonWriter.writeCharArray(*obj.getRecoverIntervalTableId());
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
    if (obj.getExperienceModelId())
    {
        jsonWriter.writePropertyName("experienceModelId");
        jsonWriter.writeCharArray(*obj.getExperienceModelId());
    }
    if (obj.getValues())
    {
        jsonWriter.writePropertyName("values");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getValues();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeInt32(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const RecoverValueTableMaster& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getRecoverValueTableId())
    {
        jsonWriter.writePropertyName("recoverValueTableId");
        jsonWriter.writeCharArray(*obj.getRecoverValueTableId());
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
    if (obj.getExperienceModelId())
    {
        jsonWriter.writePropertyName("experienceModelId");
        jsonWriter.writeCharArray(*obj.getExperienceModelId());
    }
    if (obj.getValues())
    {
        jsonWriter.writePropertyName("values");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getValues();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeInt32(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const CurrentStaminaMaster& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const StaminaModel& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getStaminaModelId())
    {
        jsonWriter.writePropertyName("staminaModelId");
        jsonWriter.writeCharArray(*obj.getStaminaModelId());
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
    if (obj.getRecoverIntervalMinutes())
    {
        jsonWriter.writePropertyName("recoverIntervalMinutes");
        jsonWriter.writeInt32(*obj.getRecoverIntervalMinutes());
    }
    if (obj.getRecoverValue())
    {
        jsonWriter.writePropertyName("recoverValue");
        jsonWriter.writeInt32(*obj.getRecoverValue());
    }
    if (obj.getInitialCapacity())
    {
        jsonWriter.writePropertyName("initialCapacity");
        jsonWriter.writeInt32(*obj.getInitialCapacity());
    }
    if (obj.getIsOverflow())
    {
        jsonWriter.writePropertyName("isOverflow");
        jsonWriter.writeBool(*obj.getIsOverflow());
    }
    if (obj.getMaxCapacity())
    {
        jsonWriter.writePropertyName("maxCapacity");
        jsonWriter.writeInt32(*obj.getMaxCapacity());
    }
    if (obj.getMaxStaminaTable())
    {
        jsonWriter.writePropertyName("maxStaminaTable");
        write(jsonWriter, *obj.getMaxStaminaTable());
    }
    if (obj.getRecoverIntervalTable())
    {
        jsonWriter.writePropertyName("recoverIntervalTable");
        write(jsonWriter, *obj.getRecoverIntervalTable());
    }
    if (obj.getRecoverValueTable())
    {
        jsonWriter.writePropertyName("recoverValueTable");
        write(jsonWriter, *obj.getRecoverValueTable());
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const MaxStaminaTable& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getMaxStaminaTableId())
    {
        jsonWriter.writePropertyName("maxStaminaTableId");
        jsonWriter.writeCharArray(*obj.getMaxStaminaTableId());
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
    if (obj.getExperienceModelId())
    {
        jsonWriter.writePropertyName("experienceModelId");
        jsonWriter.writeCharArray(*obj.getExperienceModelId());
    }
    if (obj.getValues())
    {
        jsonWriter.writePropertyName("values");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getValues();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeInt32(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const RecoverIntervalTable& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getRecoverIntervalTableId())
    {
        jsonWriter.writePropertyName("recoverIntervalTableId");
        jsonWriter.writeCharArray(*obj.getRecoverIntervalTableId());
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
    if (obj.getExperienceModelId())
    {
        jsonWriter.writePropertyName("experienceModelId");
        jsonWriter.writeCharArray(*obj.getExperienceModelId());
    }
    if (obj.getValues())
    {
        jsonWriter.writePropertyName("values");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getValues();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeInt32(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const RecoverValueTable& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getRecoverValueTableId())
    {
        jsonWriter.writePropertyName("recoverValueTableId");
        jsonWriter.writeCharArray(*obj.getRecoverValueTableId());
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
    if (obj.getExperienceModelId())
    {
        jsonWriter.writePropertyName("experienceModelId");
        jsonWriter.writeCharArray(*obj.getExperienceModelId());
    }
    if (obj.getValues())
    {
        jsonWriter.writePropertyName("values");
        jsonWriter.writeArrayStart();
        auto& list = *obj.getValues();
        for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
        {
            jsonWriter.writeInt32(list[i]);
        }
        jsonWriter.writeArrayEnd();
    }
    jsonWriter.writeObjectEnd();
}

void write(detail::json::JsonWriter& jsonWriter, const Stamina& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getStaminaId())
    {
        jsonWriter.writePropertyName("staminaId");
        jsonWriter.writeCharArray(*obj.getStaminaId());
    }
    if (obj.getStaminaName())
    {
        jsonWriter.writePropertyName("staminaName");
        jsonWriter.writeCharArray(*obj.getStaminaName());
    }
    if (obj.getUserId())
    {
        jsonWriter.writePropertyName("userId");
        jsonWriter.writeCharArray(*obj.getUserId());
    }
    if (obj.getValue())
    {
        jsonWriter.writePropertyName("value");
        jsonWriter.writeInt32(*obj.getValue());
    }
    if (obj.getMaxValue())
    {
        jsonWriter.writePropertyName("maxValue");
        jsonWriter.writeInt32(*obj.getMaxValue());
    }
    if (obj.getRecoverIntervalMinutes())
    {
        jsonWriter.writePropertyName("recoverIntervalMinutes");
        jsonWriter.writeInt32(*obj.getRecoverIntervalMinutes());
    }
    if (obj.getRecoverValue())
    {
        jsonWriter.writePropertyName("recoverValue");
        jsonWriter.writeInt32(*obj.getRecoverValue());
    }
    if (obj.getOverflowValue())
    {
        jsonWriter.writePropertyName("overflowValue");
        jsonWriter.writeInt32(*obj.getOverflowValue());
    }
    if (obj.getNextRecoverAt())
    {
        jsonWriter.writePropertyName("nextRecoverAt");
        jsonWriter.writeInt64(*obj.getNextRecoverAt());
    }
    if (obj.getLastRecoveredAt())
    {
        jsonWriter.writePropertyName("lastRecoveredAt");
        jsonWriter.writeInt64(*obj.getLastRecoveredAt());
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
        return "stamina";
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
        return "stamina";
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
        if (m_Request.getOverflowTriggerScriptId())
        {
            jsonWriter.writePropertyName("overflowTriggerScriptId");
            jsonWriter.writeCharArray(*m_Request.getOverflowTriggerScriptId());
        }
        if (m_Request.getOverflowTriggerNamespaceId())
        {
            jsonWriter.writePropertyName("overflowTriggerNamespaceId");
            jsonWriter.writeCharArray(*m_Request.getOverflowTriggerNamespaceId());
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
        return "stamina";
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
        return "stamina";
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
        return "stamina";
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
        if (m_Request.getOverflowTriggerScriptId())
        {
            jsonWriter.writePropertyName("overflowTriggerScriptId");
            jsonWriter.writeCharArray(*m_Request.getOverflowTriggerScriptId());
        }
        if (m_Request.getOverflowTriggerNamespaceId())
        {
            jsonWriter.writePropertyName("overflowTriggerNamespaceId");
            jsonWriter.writeCharArray(*m_Request.getOverflowTriggerNamespaceId());
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
        return "stamina";
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

class DescribeStaminaModelMastersTask : public detail::Gs2WebSocketSessionTask<DescribeStaminaModelMastersResult>
{
private:
    DescribeStaminaModelMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "staminaModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeStaminaModelMasters";
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
    DescribeStaminaModelMastersTask(
        DescribeStaminaModelMastersRequest request,
        Gs2WebSocketSessionTask<DescribeStaminaModelMastersResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeStaminaModelMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeStaminaModelMastersTask() GS2_OVERRIDE = default;
};

class CreateStaminaModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateStaminaModelMasterResult>
{
private:
    CreateStaminaModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "staminaModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createStaminaModelMaster";
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
        if (m_Request.getRecoverIntervalMinutes())
        {
            jsonWriter.writePropertyName("recoverIntervalMinutes");
            jsonWriter.writeInt32(*m_Request.getRecoverIntervalMinutes());
        }
        if (m_Request.getRecoverValue())
        {
            jsonWriter.writePropertyName("recoverValue");
            jsonWriter.writeInt32(*m_Request.getRecoverValue());
        }
        if (m_Request.getInitialCapacity())
        {
            jsonWriter.writePropertyName("initialCapacity");
            jsonWriter.writeInt32(*m_Request.getInitialCapacity());
        }
        if (m_Request.getIsOverflow())
        {
            jsonWriter.writePropertyName("isOverflow");
            jsonWriter.writeBool(*m_Request.getIsOverflow());
        }
        if (m_Request.getMaxCapacity())
        {
            jsonWriter.writePropertyName("maxCapacity");
            jsonWriter.writeInt32(*m_Request.getMaxCapacity());
        }
        if (m_Request.getMaxStaminaTableId())
        {
            jsonWriter.writePropertyName("maxStaminaTableId");
            jsonWriter.writeCharArray(*m_Request.getMaxStaminaTableId());
        }
        if (m_Request.getRecoverIntervalTableId())
        {
            jsonWriter.writePropertyName("recoverIntervalTableId");
            jsonWriter.writeCharArray(*m_Request.getRecoverIntervalTableId());
        }
        if (m_Request.getRecoverValueTableId())
        {
            jsonWriter.writePropertyName("recoverValueTableId");
            jsonWriter.writeCharArray(*m_Request.getRecoverValueTableId());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    CreateStaminaModelMasterTask(
        CreateStaminaModelMasterRequest request,
        Gs2WebSocketSessionTask<CreateStaminaModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateStaminaModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateStaminaModelMasterTask() GS2_OVERRIDE = default;
};

class GetStaminaModelMasterTask : public detail::Gs2WebSocketSessionTask<GetStaminaModelMasterResult>
{
private:
    GetStaminaModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "staminaModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getStaminaModelMaster";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetStaminaModelMasterTask(
        GetStaminaModelMasterRequest request,
        Gs2WebSocketSessionTask<GetStaminaModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetStaminaModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetStaminaModelMasterTask() GS2_OVERRIDE = default;
};

class UpdateStaminaModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateStaminaModelMasterResult>
{
private:
    UpdateStaminaModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "staminaModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateStaminaModelMaster";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
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
        if (m_Request.getRecoverIntervalMinutes())
        {
            jsonWriter.writePropertyName("recoverIntervalMinutes");
            jsonWriter.writeInt32(*m_Request.getRecoverIntervalMinutes());
        }
        if (m_Request.getRecoverValue())
        {
            jsonWriter.writePropertyName("recoverValue");
            jsonWriter.writeInt32(*m_Request.getRecoverValue());
        }
        if (m_Request.getInitialCapacity())
        {
            jsonWriter.writePropertyName("initialCapacity");
            jsonWriter.writeInt32(*m_Request.getInitialCapacity());
        }
        if (m_Request.getIsOverflow())
        {
            jsonWriter.writePropertyName("isOverflow");
            jsonWriter.writeBool(*m_Request.getIsOverflow());
        }
        if (m_Request.getMaxCapacity())
        {
            jsonWriter.writePropertyName("maxCapacity");
            jsonWriter.writeInt32(*m_Request.getMaxCapacity());
        }
        if (m_Request.getMaxStaminaTableId())
        {
            jsonWriter.writePropertyName("maxStaminaTableId");
            jsonWriter.writeCharArray(*m_Request.getMaxStaminaTableId());
        }
        if (m_Request.getRecoverIntervalTableId())
        {
            jsonWriter.writePropertyName("recoverIntervalTableId");
            jsonWriter.writeCharArray(*m_Request.getRecoverIntervalTableId());
        }
        if (m_Request.getRecoverValueTableId())
        {
            jsonWriter.writePropertyName("recoverValueTableId");
            jsonWriter.writeCharArray(*m_Request.getRecoverValueTableId());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    UpdateStaminaModelMasterTask(
        UpdateStaminaModelMasterRequest request,
        Gs2WebSocketSessionTask<UpdateStaminaModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateStaminaModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateStaminaModelMasterTask() GS2_OVERRIDE = default;
};

class DeleteStaminaModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteStaminaModelMasterResult>
{
private:
    DeleteStaminaModelMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "staminaModelMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteStaminaModelMaster";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteStaminaModelMasterTask(
        DeleteStaminaModelMasterRequest request,
        Gs2WebSocketSessionTask<DeleteStaminaModelMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteStaminaModelMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteStaminaModelMasterTask() GS2_OVERRIDE = default;
};

class DescribeMaxStaminaTableMastersTask : public detail::Gs2WebSocketSessionTask<DescribeMaxStaminaTableMastersResult>
{
private:
    DescribeMaxStaminaTableMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "maxStaminaTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeMaxStaminaTableMasters";
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
    DescribeMaxStaminaTableMastersTask(
        DescribeMaxStaminaTableMastersRequest request,
        Gs2WebSocketSessionTask<DescribeMaxStaminaTableMastersResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeMaxStaminaTableMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeMaxStaminaTableMastersTask() GS2_OVERRIDE = default;
};

class CreateMaxStaminaTableMasterTask : public detail::Gs2WebSocketSessionTask<CreateMaxStaminaTableMasterResult>
{
private:
    CreateMaxStaminaTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "maxStaminaTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createMaxStaminaTableMaster";
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
        if (m_Request.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*m_Request.getExperienceModelId());
        }
        if (m_Request.getValues())
        {
            jsonWriter.writePropertyName("values");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt32(list[i]);
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
    CreateMaxStaminaTableMasterTask(
        CreateMaxStaminaTableMasterRequest request,
        Gs2WebSocketSessionTask<CreateMaxStaminaTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateMaxStaminaTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
};

class GetMaxStaminaTableMasterTask : public detail::Gs2WebSocketSessionTask<GetMaxStaminaTableMasterResult>
{
private:
    GetMaxStaminaTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "maxStaminaTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getMaxStaminaTableMaster";
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
        if (m_Request.getMaxStaminaTableName())
        {
            jsonWriter.writePropertyName("maxStaminaTableName");
            jsonWriter.writeCharArray(*m_Request.getMaxStaminaTableName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetMaxStaminaTableMasterTask(
        GetMaxStaminaTableMasterRequest request,
        Gs2WebSocketSessionTask<GetMaxStaminaTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetMaxStaminaTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
};

class UpdateMaxStaminaTableMasterTask : public detail::Gs2WebSocketSessionTask<UpdateMaxStaminaTableMasterResult>
{
private:
    UpdateMaxStaminaTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "maxStaminaTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateMaxStaminaTableMaster";
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
        if (m_Request.getMaxStaminaTableName())
        {
            jsonWriter.writePropertyName("maxStaminaTableName");
            jsonWriter.writeCharArray(*m_Request.getMaxStaminaTableName());
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
        if (m_Request.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*m_Request.getExperienceModelId());
        }
        if (m_Request.getValues())
        {
            jsonWriter.writePropertyName("values");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt32(list[i]);
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
    UpdateMaxStaminaTableMasterTask(
        UpdateMaxStaminaTableMasterRequest request,
        Gs2WebSocketSessionTask<UpdateMaxStaminaTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateMaxStaminaTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
};

class DeleteMaxStaminaTableMasterTask : public detail::Gs2WebSocketSessionTask<DeleteMaxStaminaTableMasterResult>
{
private:
    DeleteMaxStaminaTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "maxStaminaTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteMaxStaminaTableMaster";
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
        if (m_Request.getMaxStaminaTableName())
        {
            jsonWriter.writePropertyName("maxStaminaTableName");
            jsonWriter.writeCharArray(*m_Request.getMaxStaminaTableName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteMaxStaminaTableMasterTask(
        DeleteMaxStaminaTableMasterRequest request,
        Gs2WebSocketSessionTask<DeleteMaxStaminaTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteMaxStaminaTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
};

class DescribeRecoverIntervalTableMastersTask : public detail::Gs2WebSocketSessionTask<DescribeRecoverIntervalTableMastersResult>
{
private:
    DescribeRecoverIntervalTableMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverIntervalTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeRecoverIntervalTableMasters";
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
    DescribeRecoverIntervalTableMastersTask(
        DescribeRecoverIntervalTableMastersRequest request,
        Gs2WebSocketSessionTask<DescribeRecoverIntervalTableMastersResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeRecoverIntervalTableMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeRecoverIntervalTableMastersTask() GS2_OVERRIDE = default;
};

class CreateRecoverIntervalTableMasterTask : public detail::Gs2WebSocketSessionTask<CreateRecoverIntervalTableMasterResult>
{
private:
    CreateRecoverIntervalTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverIntervalTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createRecoverIntervalTableMaster";
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
        if (m_Request.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*m_Request.getExperienceModelId());
        }
        if (m_Request.getValues())
        {
            jsonWriter.writePropertyName("values");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt32(list[i]);
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
    CreateRecoverIntervalTableMasterTask(
        CreateRecoverIntervalTableMasterRequest request,
        Gs2WebSocketSessionTask<CreateRecoverIntervalTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateRecoverIntervalTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateRecoverIntervalTableMasterTask() GS2_OVERRIDE = default;
};

class GetRecoverIntervalTableMasterTask : public detail::Gs2WebSocketSessionTask<GetRecoverIntervalTableMasterResult>
{
private:
    GetRecoverIntervalTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverIntervalTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getRecoverIntervalTableMaster";
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
        if (m_Request.getRecoverIntervalTableName())
        {
            jsonWriter.writePropertyName("recoverIntervalTableName");
            jsonWriter.writeCharArray(*m_Request.getRecoverIntervalTableName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetRecoverIntervalTableMasterTask(
        GetRecoverIntervalTableMasterRequest request,
        Gs2WebSocketSessionTask<GetRecoverIntervalTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetRecoverIntervalTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetRecoverIntervalTableMasterTask() GS2_OVERRIDE = default;
};

class UpdateRecoverIntervalTableMasterTask : public detail::Gs2WebSocketSessionTask<UpdateRecoverIntervalTableMasterResult>
{
private:
    UpdateRecoverIntervalTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverIntervalTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateRecoverIntervalTableMaster";
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
        if (m_Request.getRecoverIntervalTableName())
        {
            jsonWriter.writePropertyName("recoverIntervalTableName");
            jsonWriter.writeCharArray(*m_Request.getRecoverIntervalTableName());
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
        if (m_Request.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*m_Request.getExperienceModelId());
        }
        if (m_Request.getValues())
        {
            jsonWriter.writePropertyName("values");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt32(list[i]);
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
    UpdateRecoverIntervalTableMasterTask(
        UpdateRecoverIntervalTableMasterRequest request,
        Gs2WebSocketSessionTask<UpdateRecoverIntervalTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateRecoverIntervalTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateRecoverIntervalTableMasterTask() GS2_OVERRIDE = default;
};

class DeleteRecoverIntervalTableMasterTask : public detail::Gs2WebSocketSessionTask<DeleteRecoverIntervalTableMasterResult>
{
private:
    DeleteRecoverIntervalTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverIntervalTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteRecoverIntervalTableMaster";
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
        if (m_Request.getRecoverIntervalTableName())
        {
            jsonWriter.writePropertyName("recoverIntervalTableName");
            jsonWriter.writeCharArray(*m_Request.getRecoverIntervalTableName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteRecoverIntervalTableMasterTask(
        DeleteRecoverIntervalTableMasterRequest request,
        Gs2WebSocketSessionTask<DeleteRecoverIntervalTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteRecoverIntervalTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteRecoverIntervalTableMasterTask() GS2_OVERRIDE = default;
};

class DescribeRecoverValueTableMastersTask : public detail::Gs2WebSocketSessionTask<DescribeRecoverValueTableMastersResult>
{
private:
    DescribeRecoverValueTableMastersRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverValueTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeRecoverValueTableMasters";
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
    DescribeRecoverValueTableMastersTask(
        DescribeRecoverValueTableMastersRequest request,
        Gs2WebSocketSessionTask<DescribeRecoverValueTableMastersResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeRecoverValueTableMastersResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeRecoverValueTableMastersTask() GS2_OVERRIDE = default;
};

class CreateRecoverValueTableMasterTask : public detail::Gs2WebSocketSessionTask<CreateRecoverValueTableMasterResult>
{
private:
    CreateRecoverValueTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverValueTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "createRecoverValueTableMaster";
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
        if (m_Request.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*m_Request.getExperienceModelId());
        }
        if (m_Request.getValues())
        {
            jsonWriter.writePropertyName("values");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt32(list[i]);
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
    CreateRecoverValueTableMasterTask(
        CreateRecoverValueTableMasterRequest request,
        Gs2WebSocketSessionTask<CreateRecoverValueTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<CreateRecoverValueTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateRecoverValueTableMasterTask() GS2_OVERRIDE = default;
};

class GetRecoverValueTableMasterTask : public detail::Gs2WebSocketSessionTask<GetRecoverValueTableMasterResult>
{
private:
    GetRecoverValueTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverValueTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getRecoverValueTableMaster";
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
        if (m_Request.getRecoverValueTableName())
        {
            jsonWriter.writePropertyName("recoverValueTableName");
            jsonWriter.writeCharArray(*m_Request.getRecoverValueTableName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetRecoverValueTableMasterTask(
        GetRecoverValueTableMasterRequest request,
        Gs2WebSocketSessionTask<GetRecoverValueTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetRecoverValueTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetRecoverValueTableMasterTask() GS2_OVERRIDE = default;
};

class UpdateRecoverValueTableMasterTask : public detail::Gs2WebSocketSessionTask<UpdateRecoverValueTableMasterResult>
{
private:
    UpdateRecoverValueTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverValueTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateRecoverValueTableMaster";
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
        if (m_Request.getRecoverValueTableName())
        {
            jsonWriter.writePropertyName("recoverValueTableName");
            jsonWriter.writeCharArray(*m_Request.getRecoverValueTableName());
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
        if (m_Request.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*m_Request.getExperienceModelId());
        }
        if (m_Request.getValues())
        {
            jsonWriter.writePropertyName("values");
            jsonWriter.writeArrayStart();
            auto& list = *m_Request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt32(list[i]);
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
    UpdateRecoverValueTableMasterTask(
        UpdateRecoverValueTableMasterRequest request,
        Gs2WebSocketSessionTask<UpdateRecoverValueTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateRecoverValueTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateRecoverValueTableMasterTask() GS2_OVERRIDE = default;
};

class DeleteRecoverValueTableMasterTask : public detail::Gs2WebSocketSessionTask<DeleteRecoverValueTableMasterResult>
{
private:
    DeleteRecoverValueTableMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "recoverValueTableMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteRecoverValueTableMaster";
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
        if (m_Request.getRecoverValueTableName())
        {
            jsonWriter.writePropertyName("recoverValueTableName");
            jsonWriter.writeCharArray(*m_Request.getRecoverValueTableName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    DeleteRecoverValueTableMasterTask(
        DeleteRecoverValueTableMasterRequest request,
        Gs2WebSocketSessionTask<DeleteRecoverValueTableMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DeleteRecoverValueTableMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteRecoverValueTableMasterTask() GS2_OVERRIDE = default;
};

class ExportMasterTask : public detail::Gs2WebSocketSessionTask<ExportMasterResult>
{
private:
    ExportMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentStaminaMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "exportMaster";
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
    ExportMasterTask(
        ExportMasterRequest request,
        Gs2WebSocketSessionTask<ExportMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<ExportMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~ExportMasterTask() GS2_OVERRIDE = default;
};

class GetCurrentStaminaMasterTask : public detail::Gs2WebSocketSessionTask<GetCurrentStaminaMasterResult>
{
private:
    GetCurrentStaminaMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentStaminaMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getCurrentStaminaMaster";
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
    GetCurrentStaminaMasterTask(
        GetCurrentStaminaMasterRequest request,
        Gs2WebSocketSessionTask<GetCurrentStaminaMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetCurrentStaminaMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetCurrentStaminaMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentStaminaMasterTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterResult>
{
private:
    UpdateCurrentStaminaMasterRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentStaminaMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateCurrentStaminaMaster";
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
        if (m_Request.getSettings())
        {
            jsonWriter.writePropertyName("settings");
            jsonWriter.writeCharArray(*m_Request.getSettings());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    UpdateCurrentStaminaMasterTask(
        UpdateCurrentStaminaMasterRequest request,
        Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentStaminaMasterTask() GS2_OVERRIDE = default;
};

class UpdateCurrentStaminaMasterFromGitHubTask : public detail::Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>
{
private:
    UpdateCurrentStaminaMasterFromGitHubRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "currentStaminaMaster";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateCurrentStaminaMasterFromGitHub";
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
    UpdateCurrentStaminaMasterFromGitHubTask(
        UpdateCurrentStaminaMasterFromGitHubRequest request,
        Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateCurrentStaminaMasterFromGitHubTask() GS2_OVERRIDE = default;
};

class DescribeStaminaModelsTask : public detail::Gs2WebSocketSessionTask<DescribeStaminaModelsResult>
{
private:
    DescribeStaminaModelsRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "staminaModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeStaminaModels";
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
    DescribeStaminaModelsTask(
        DescribeStaminaModelsRequest request,
        Gs2WebSocketSessionTask<DescribeStaminaModelsResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeStaminaModelsResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeStaminaModelsTask() GS2_OVERRIDE = default;
};

class GetStaminaModelTask : public detail::Gs2WebSocketSessionTask<GetStaminaModelResult>
{
private:
    GetStaminaModelRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "staminaModel";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getStaminaModel";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getRequestId())
        {
            jsonWriter.writePropertyName("xGs2RequestId");
            jsonWriter.writeCharArray(*m_Request.getRequestId());
        }
    }

public:
    GetStaminaModelTask(
        GetStaminaModelRequest request,
        Gs2WebSocketSessionTask<GetStaminaModelResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetStaminaModelResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetStaminaModelTask() GS2_OVERRIDE = default;
};

class DescribeStaminasTask : public detail::Gs2WebSocketSessionTask<DescribeStaminasResult>
{
private:
    DescribeStaminasRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeStaminas";
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
    DescribeStaminasTask(
        DescribeStaminasRequest request,
        Gs2WebSocketSessionTask<DescribeStaminasResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeStaminasResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeStaminasTask() GS2_OVERRIDE = default;
};

class DescribeStaminasByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeStaminasByUserIdResult>
{
private:
    DescribeStaminasByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "describeStaminasByUserId";
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
    DescribeStaminasByUserIdTask(
        DescribeStaminasByUserIdRequest request,
        Gs2WebSocketSessionTask<DescribeStaminasByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<DescribeStaminasByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeStaminasByUserIdTask() GS2_OVERRIDE = default;
};

class GetStaminaTask : public detail::Gs2WebSocketSessionTask<GetStaminaResult>
{
private:
    GetStaminaRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getStamina";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
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
    GetStaminaTask(
        GetStaminaRequest request,
        Gs2WebSocketSessionTask<GetStaminaResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetStaminaResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetStaminaTask() GS2_OVERRIDE = default;
};

class GetStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<GetStaminaByUserIdResult>
{
private:
    GetStaminaByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "getStaminaByUserId";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
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
    GetStaminaByUserIdTask(
        GetStaminaByUserIdRequest request,
        Gs2WebSocketSessionTask<GetStaminaByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<GetStaminaByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetStaminaByUserIdTask() GS2_OVERRIDE = default;
};

class UpdateStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<UpdateStaminaByUserIdResult>
{
private:
    UpdateStaminaByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "updateStaminaByUserId";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getValue())
        {
            jsonWriter.writePropertyName("value");
            jsonWriter.writeInt32(*m_Request.getValue());
        }
        if (m_Request.getMaxValue())
        {
            jsonWriter.writePropertyName("maxValue");
            jsonWriter.writeInt32(*m_Request.getMaxValue());
        }
        if (m_Request.getRecoverIntervalMinutes())
        {
            jsonWriter.writePropertyName("recoverIntervalMinutes");
            jsonWriter.writeInt32(*m_Request.getRecoverIntervalMinutes());
        }
        if (m_Request.getRecoverValue())
        {
            jsonWriter.writePropertyName("recoverValue");
            jsonWriter.writeInt32(*m_Request.getRecoverValue());
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
    UpdateStaminaByUserIdTask(
        UpdateStaminaByUserIdRequest request,
        Gs2WebSocketSessionTask<UpdateStaminaByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<UpdateStaminaByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateStaminaByUserIdTask() GS2_OVERRIDE = default;
};

class ConsumeStaminaTask : public detail::Gs2WebSocketSessionTask<ConsumeStaminaResult>
{
private:
    ConsumeStaminaRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "consumeStamina";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getConsumeValue())
        {
            jsonWriter.writePropertyName("consumeValue");
            jsonWriter.writeInt32(*m_Request.getConsumeValue());
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
    ConsumeStaminaTask(
        ConsumeStaminaRequest request,
        Gs2WebSocketSessionTask<ConsumeStaminaResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<ConsumeStaminaResult>(callback),
        m_Request(std::move(request))
    {}

    ~ConsumeStaminaTask() GS2_OVERRIDE = default;
};

class ConsumeStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<ConsumeStaminaByUserIdResult>
{
private:
    ConsumeStaminaByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "consumeStaminaByUserId";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getConsumeValue())
        {
            jsonWriter.writePropertyName("consumeValue");
            jsonWriter.writeInt32(*m_Request.getConsumeValue());
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
    ConsumeStaminaByUserIdTask(
        ConsumeStaminaByUserIdRequest request,
        Gs2WebSocketSessionTask<ConsumeStaminaByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<ConsumeStaminaByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~ConsumeStaminaByUserIdTask() GS2_OVERRIDE = default;
};

class RecoverStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<RecoverStaminaByUserIdResult>
{
private:
    RecoverStaminaByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "recoverStaminaByUserId";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getRecoverValue())
        {
            jsonWriter.writePropertyName("recoverValue");
            jsonWriter.writeInt32(*m_Request.getRecoverValue());
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
    RecoverStaminaByUserIdTask(
        RecoverStaminaByUserIdRequest request,
        Gs2WebSocketSessionTask<RecoverStaminaByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<RecoverStaminaByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~RecoverStaminaByUserIdTask() GS2_OVERRIDE = default;
};

class RaiseMaxValueByUserIdTask : public detail::Gs2WebSocketSessionTask<RaiseMaxValueByUserIdResult>
{
private:
    RaiseMaxValueByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "raiseMaxValueByUserId";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getRaiseValue())
        {
            jsonWriter.writePropertyName("raiseValue");
            jsonWriter.writeInt32(*m_Request.getRaiseValue());
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
    RaiseMaxValueByUserIdTask(
        RaiseMaxValueByUserIdRequest request,
        Gs2WebSocketSessionTask<RaiseMaxValueByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<RaiseMaxValueByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~RaiseMaxValueByUserIdTask() GS2_OVERRIDE = default;
};

class SetMaxValueByUserIdTask : public detail::Gs2WebSocketSessionTask<SetMaxValueByUserIdResult>
{
private:
    SetMaxValueByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "setMaxValueByUserId";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getMaxValue())
        {
            jsonWriter.writePropertyName("maxValue");
            jsonWriter.writeInt32(*m_Request.getMaxValue());
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
    SetMaxValueByUserIdTask(
        SetMaxValueByUserIdRequest request,
        Gs2WebSocketSessionTask<SetMaxValueByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<SetMaxValueByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetMaxValueByUserIdTask() GS2_OVERRIDE = default;
};

class SetRecoverIntervalByUserIdTask : public detail::Gs2WebSocketSessionTask<SetRecoverIntervalByUserIdResult>
{
private:
    SetRecoverIntervalByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "setRecoverIntervalByUserId";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getRecoverIntervalMinutes())
        {
            jsonWriter.writePropertyName("recoverIntervalMinutes");
            jsonWriter.writeInt32(*m_Request.getRecoverIntervalMinutes());
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
    SetRecoverIntervalByUserIdTask(
        SetRecoverIntervalByUserIdRequest request,
        Gs2WebSocketSessionTask<SetRecoverIntervalByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<SetRecoverIntervalByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetRecoverIntervalByUserIdTask() GS2_OVERRIDE = default;
};

class SetRecoverValueByUserIdTask : public detail::Gs2WebSocketSessionTask<SetRecoverValueByUserIdResult>
{
private:
    SetRecoverValueByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "setRecoverValueByUserId";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*m_Request.getUserId());
        }
        if (m_Request.getRecoverValue())
        {
            jsonWriter.writePropertyName("recoverValue");
            jsonWriter.writeInt32(*m_Request.getRecoverValue());
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
    SetRecoverValueByUserIdTask(
        SetRecoverValueByUserIdRequest request,
        Gs2WebSocketSessionTask<SetRecoverValueByUserIdResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<SetRecoverValueByUserIdResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetRecoverValueByUserIdTask() GS2_OVERRIDE = default;
};

class SetMaxValueByStatusTask : public detail::Gs2WebSocketSessionTask<SetMaxValueByStatusResult>
{
private:
    SetMaxValueByStatusRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "setMaxValueByStatus";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*m_Request.getKeyId());
        }
        if (m_Request.getSignedStatusBody())
        {
            jsonWriter.writePropertyName("signedStatusBody");
            jsonWriter.writeCharArray(*m_Request.getSignedStatusBody());
        }
        if (m_Request.getSignedStatusSignature())
        {
            jsonWriter.writePropertyName("signedStatusSignature");
            jsonWriter.writeCharArray(*m_Request.getSignedStatusSignature());
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
    SetMaxValueByStatusTask(
        SetMaxValueByStatusRequest request,
        Gs2WebSocketSessionTask<SetMaxValueByStatusResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<SetMaxValueByStatusResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetMaxValueByStatusTask() GS2_OVERRIDE = default;
};

class SetRecoverIntervalByStatusTask : public detail::Gs2WebSocketSessionTask<SetRecoverIntervalByStatusResult>
{
private:
    SetRecoverIntervalByStatusRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "setRecoverIntervalByStatus";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*m_Request.getKeyId());
        }
        if (m_Request.getSignedStatusBody())
        {
            jsonWriter.writePropertyName("signedStatusBody");
            jsonWriter.writeCharArray(*m_Request.getSignedStatusBody());
        }
        if (m_Request.getSignedStatusSignature())
        {
            jsonWriter.writePropertyName("signedStatusSignature");
            jsonWriter.writeCharArray(*m_Request.getSignedStatusSignature());
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
    SetRecoverIntervalByStatusTask(
        SetRecoverIntervalByStatusRequest request,
        Gs2WebSocketSessionTask<SetRecoverIntervalByStatusResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<SetRecoverIntervalByStatusResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetRecoverIntervalByStatusTask() GS2_OVERRIDE = default;
};

class SetRecoverValueByStatusTask : public detail::Gs2WebSocketSessionTask<SetRecoverValueByStatusResult>
{
private:
    SetRecoverValueByStatusRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "setRecoverValueByStatus";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
        }
        if (m_Request.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*m_Request.getKeyId());
        }
        if (m_Request.getSignedStatusBody())
        {
            jsonWriter.writePropertyName("signedStatusBody");
            jsonWriter.writeCharArray(*m_Request.getSignedStatusBody());
        }
        if (m_Request.getSignedStatusSignature())
        {
            jsonWriter.writePropertyName("signedStatusSignature");
            jsonWriter.writeCharArray(*m_Request.getSignedStatusSignature());
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
    SetRecoverValueByStatusTask(
        SetRecoverValueByStatusRequest request,
        Gs2WebSocketSessionTask<SetRecoverValueByStatusResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<SetRecoverValueByStatusResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetRecoverValueByStatusTask() GS2_OVERRIDE = default;
};

class DeleteStaminaByUserIdTask : public detail::Gs2WebSocketSessionTask<void>
{
private:
    DeleteStaminaByUserIdRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "deleteStaminaByUserId";
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
        if (m_Request.getStaminaName())
        {
            jsonWriter.writePropertyName("staminaName");
            jsonWriter.writeCharArray(*m_Request.getStaminaName());
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
    DeleteStaminaByUserIdTask(
        DeleteStaminaByUserIdRequest request,
        Gs2WebSocketSessionTask<void>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<void>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteStaminaByUserIdTask() GS2_OVERRIDE = default;
};

class RecoverStaminaByStampSheetTask : public detail::Gs2WebSocketSessionTask<RecoverStaminaByStampSheetResult>
{
private:
    RecoverStaminaByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "recoverStaminaByStampSheet";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
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
    RecoverStaminaByStampSheetTask(
        RecoverStaminaByStampSheetRequest request,
        Gs2WebSocketSessionTask<RecoverStaminaByStampSheetResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<RecoverStaminaByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~RecoverStaminaByStampSheetTask() GS2_OVERRIDE = default;
};

class RaiseMaxValueByStampSheetTask : public detail::Gs2WebSocketSessionTask<RaiseMaxValueByStampSheetResult>
{
private:
    RaiseMaxValueByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "raiseMaxValueByStampSheet";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
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
    RaiseMaxValueByStampSheetTask(
        RaiseMaxValueByStampSheetRequest request,
        Gs2WebSocketSessionTask<RaiseMaxValueByStampSheetResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<RaiseMaxValueByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~RaiseMaxValueByStampSheetTask() GS2_OVERRIDE = default;
};

class SetMaxValueByStampSheetTask : public detail::Gs2WebSocketSessionTask<SetMaxValueByStampSheetResult>
{
private:
    SetMaxValueByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "setMaxValueByStampSheet";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
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
    SetMaxValueByStampSheetTask(
        SetMaxValueByStampSheetRequest request,
        Gs2WebSocketSessionTask<SetMaxValueByStampSheetResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<SetMaxValueByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetMaxValueByStampSheetTask() GS2_OVERRIDE = default;
};

class SetRecoverIntervalByStampSheetTask : public detail::Gs2WebSocketSessionTask<SetRecoverIntervalByStampSheetResult>
{
private:
    SetRecoverIntervalByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "setRecoverIntervalByStampSheet";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
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
    SetRecoverIntervalByStampSheetTask(
        SetRecoverIntervalByStampSheetRequest request,
        Gs2WebSocketSessionTask<SetRecoverIntervalByStampSheetResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<SetRecoverIntervalByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetRecoverIntervalByStampSheetTask() GS2_OVERRIDE = default;
};

class SetRecoverValueByStampSheetTask : public detail::Gs2WebSocketSessionTask<SetRecoverValueByStampSheetResult>
{
private:
    SetRecoverValueByStampSheetRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "setRecoverValueByStampSheet";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
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
    SetRecoverValueByStampSheetTask(
        SetRecoverValueByStampSheetRequest request,
        Gs2WebSocketSessionTask<SetRecoverValueByStampSheetResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<SetRecoverValueByStampSheetResult>(callback),
        m_Request(std::move(request))
    {}

    ~SetRecoverValueByStampSheetTask() GS2_OVERRIDE = default;
};

class ConsumeStaminaByStampTaskTask : public detail::Gs2WebSocketSessionTask<ConsumeStaminaByStampTaskResult>
{
private:
    ConsumeStaminaByStampTaskRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getComponentName() const GS2_OVERRIDE
    {
        return "stamina";
    }

    const char* getFunctionName() const GS2_OVERRIDE
    {
        return "consumeStaminaByStampTask";
    }

    void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
    {
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
    ConsumeStaminaByStampTaskTask(
        ConsumeStaminaByStampTaskRequest request,
        Gs2WebSocketSessionTask<ConsumeStaminaByStampTaskResult>::CallbackType callback
    ) :
        Gs2WebSocketSessionTask<ConsumeStaminaByStampTaskResult>(callback),
        m_Request(std::move(request))
    {}

    ~ConsumeStaminaByStampTaskTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
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
void Gs2StaminaWebSocketClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
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
void Gs2StaminaWebSocketClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
void Gs2StaminaWebSocketClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
void Gs2StaminaWebSocketClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
void Gs2StaminaWebSocketClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナモデルマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::describeStaminaModelMasters(DescribeStaminaModelMastersRequest request, std::function<void(AsyncDescribeStaminaModelMastersResult)> callback)
{
    DescribeStaminaModelMastersTask& task = *new DescribeStaminaModelMastersTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナモデルマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::createStaminaModelMaster(CreateStaminaModelMasterRequest request, std::function<void(AsyncCreateStaminaModelMasterResult)> callback)
{
    CreateStaminaModelMasterTask& task = *new CreateStaminaModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナモデルマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::getStaminaModelMaster(GetStaminaModelMasterRequest request, std::function<void(AsyncGetStaminaModelMasterResult)> callback)
{
    GetStaminaModelMasterTask& task = *new GetStaminaModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナモデルマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::updateStaminaModelMaster(UpdateStaminaModelMasterRequest request, std::function<void(AsyncUpdateStaminaModelMasterResult)> callback)
{
    UpdateStaminaModelMasterTask& task = *new UpdateStaminaModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナモデルマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::deleteStaminaModelMaster(DeleteStaminaModelMasterRequest request, std::function<void(AsyncDeleteStaminaModelMasterResult)> callback)
{
    DeleteStaminaModelMasterTask& task = *new DeleteStaminaModelMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナの最大値テーブルマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::describeMaxStaminaTableMasters(DescribeMaxStaminaTableMastersRequest request, std::function<void(AsyncDescribeMaxStaminaTableMastersResult)> callback)
{
    DescribeMaxStaminaTableMastersTask& task = *new DescribeMaxStaminaTableMastersTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナの最大値テーブルマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::createMaxStaminaTableMaster(CreateMaxStaminaTableMasterRequest request, std::function<void(AsyncCreateMaxStaminaTableMasterResult)> callback)
{
    CreateMaxStaminaTableMasterTask& task = *new CreateMaxStaminaTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナの最大値テーブルマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::getMaxStaminaTableMaster(GetMaxStaminaTableMasterRequest request, std::function<void(AsyncGetMaxStaminaTableMasterResult)> callback)
{
    GetMaxStaminaTableMasterTask& task = *new GetMaxStaminaTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナの最大値テーブルマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::updateMaxStaminaTableMaster(UpdateMaxStaminaTableMasterRequest request, std::function<void(AsyncUpdateMaxStaminaTableMasterResult)> callback)
{
    UpdateMaxStaminaTableMasterTask& task = *new UpdateMaxStaminaTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナの最大値テーブルマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::deleteMaxStaminaTableMaster(DeleteMaxStaminaTableMasterRequest request, std::function<void(AsyncDeleteMaxStaminaTableMasterResult)> callback)
{
    DeleteMaxStaminaTableMasterTask& task = *new DeleteMaxStaminaTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復間隔テーブルマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::describeRecoverIntervalTableMasters(DescribeRecoverIntervalTableMastersRequest request, std::function<void(AsyncDescribeRecoverIntervalTableMastersResult)> callback)
{
    DescribeRecoverIntervalTableMastersTask& task = *new DescribeRecoverIntervalTableMastersTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復間隔テーブルマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::createRecoverIntervalTableMaster(CreateRecoverIntervalTableMasterRequest request, std::function<void(AsyncCreateRecoverIntervalTableMasterResult)> callback)
{
    CreateRecoverIntervalTableMasterTask& task = *new CreateRecoverIntervalTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復間隔テーブルマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::getRecoverIntervalTableMaster(GetRecoverIntervalTableMasterRequest request, std::function<void(AsyncGetRecoverIntervalTableMasterResult)> callback)
{
    GetRecoverIntervalTableMasterTask& task = *new GetRecoverIntervalTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復間隔テーブルマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::updateRecoverIntervalTableMaster(UpdateRecoverIntervalTableMasterRequest request, std::function<void(AsyncUpdateRecoverIntervalTableMasterResult)> callback)
{
    UpdateRecoverIntervalTableMasterTask& task = *new UpdateRecoverIntervalTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復間隔テーブルマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::deleteRecoverIntervalTableMaster(DeleteRecoverIntervalTableMasterRequest request, std::function<void(AsyncDeleteRecoverIntervalTableMasterResult)> callback)
{
    DeleteRecoverIntervalTableMasterTask& task = *new DeleteRecoverIntervalTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復量テーブルマスターの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::describeRecoverValueTableMasters(DescribeRecoverValueTableMastersRequest request, std::function<void(AsyncDescribeRecoverValueTableMastersResult)> callback)
{
    DescribeRecoverValueTableMastersTask& task = *new DescribeRecoverValueTableMastersTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復量テーブルマスターを新規作成<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::createRecoverValueTableMaster(CreateRecoverValueTableMasterRequest request, std::function<void(AsyncCreateRecoverValueTableMasterResult)> callback)
{
    CreateRecoverValueTableMasterTask& task = *new CreateRecoverValueTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復量テーブルマスターを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::getRecoverValueTableMaster(GetRecoverValueTableMasterRequest request, std::function<void(AsyncGetRecoverValueTableMasterResult)> callback)
{
    GetRecoverValueTableMasterTask& task = *new GetRecoverValueTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復量テーブルマスターを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::updateRecoverValueTableMaster(UpdateRecoverValueTableMasterRequest request, std::function<void(AsyncUpdateRecoverValueTableMasterResult)> callback)
{
    UpdateRecoverValueTableMasterTask& task = *new UpdateRecoverValueTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナ回復量テーブルマスターを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::deleteRecoverValueTableMaster(DeleteRecoverValueTableMasterRequest request, std::function<void(AsyncDeleteRecoverValueTableMasterResult)> callback)
{
    DeleteRecoverValueTableMasterTask& task = *new DeleteRecoverValueTableMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効なスタミナマスターのマスターデータをエクスポートします<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
{
    ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効なスタミナマスターを取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::getCurrentStaminaMaster(GetCurrentStaminaMasterRequest request, std::function<void(AsyncGetCurrentStaminaMasterResult)> callback)
{
    GetCurrentStaminaMasterTask& task = *new GetCurrentStaminaMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効なスタミナマスターを更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::updateCurrentStaminaMaster(UpdateCurrentStaminaMasterRequest request, std::function<void(AsyncUpdateCurrentStaminaMasterResult)> callback)
{
    UpdateCurrentStaminaMasterTask& task = *new UpdateCurrentStaminaMasterTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * 現在有効なスタミナマスターを更新します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::updateCurrentStaminaMasterFromGitHub(UpdateCurrentStaminaMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentStaminaMasterFromGitHubResult)> callback)
{
    UpdateCurrentStaminaMasterFromGitHubTask& task = *new UpdateCurrentStaminaMasterFromGitHubTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナモデルの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::describeStaminaModels(DescribeStaminaModelsRequest request, std::function<void(AsyncDescribeStaminaModelsResult)> callback)
{
    DescribeStaminaModelsTask& task = *new DescribeStaminaModelsTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナモデルを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::getStaminaModel(GetStaminaModelRequest request, std::function<void(AsyncGetStaminaModelResult)> callback)
{
    GetStaminaModelTask& task = *new GetStaminaModelTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::describeStaminas(DescribeStaminasRequest request, std::function<void(AsyncDescribeStaminasResult)> callback)
{
    DescribeStaminasTask& task = *new DescribeStaminasTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::describeStaminasByUserId(DescribeStaminasByUserIdRequest request, std::function<void(AsyncDescribeStaminasByUserIdResult)> callback)
{
    DescribeStaminasByUserIdTask& task = *new DescribeStaminasByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::getStamina(GetStaminaRequest request, std::function<void(AsyncGetStaminaResult)> callback)
{
    GetStaminaTask& task = *new GetStaminaTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナを取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::getStaminaByUserId(GetStaminaByUserIdRequest request, std::function<void(AsyncGetStaminaByUserIdResult)> callback)
{
    GetStaminaByUserIdTask& task = *new GetStaminaByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナを作成・更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::updateStaminaByUserId(UpdateStaminaByUserIdRequest request, std::function<void(AsyncUpdateStaminaByUserIdResult)> callback)
{
    UpdateStaminaByUserIdTask& task = *new UpdateStaminaByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナを消費<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::consumeStamina(ConsumeStaminaRequest request, std::function<void(AsyncConsumeStaminaResult)> callback)
{
    ConsumeStaminaTask& task = *new ConsumeStaminaTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナを消費<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::consumeStaminaByUserId(ConsumeStaminaByUserIdRequest request, std::function<void(AsyncConsumeStaminaByUserIdResult)> callback)
{
    ConsumeStaminaByUserIdTask& task = *new ConsumeStaminaByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナを回復<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::recoverStaminaByUserId(RecoverStaminaByUserIdRequest request, std::function<void(AsyncRecoverStaminaByUserIdResult)> callback)
{
    RecoverStaminaByUserIdTask& task = *new RecoverStaminaByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナの最大値を加算<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::raiseMaxValueByUserId(RaiseMaxValueByUserIdRequest request, std::function<void(AsyncRaiseMaxValueByUserIdResult)> callback)
{
    RaiseMaxValueByUserIdTask& task = *new RaiseMaxValueByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナの最大値を更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::setMaxValueByUserId(SetMaxValueByUserIdRequest request, std::function<void(AsyncSetMaxValueByUserIdResult)> callback)
{
    SetMaxValueByUserIdTask& task = *new SetMaxValueByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナの回復間隔(分)を更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::setRecoverIntervalByUserId(SetRecoverIntervalByUserIdRequest request, std::function<void(AsyncSetRecoverIntervalByUserIdResult)> callback)
{
    SetRecoverIntervalByUserIdTask& task = *new SetRecoverIntervalByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナの回復間隔(分)を更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::setRecoverValueByUserId(SetRecoverValueByUserIdRequest request, std::function<void(AsyncSetRecoverValueByUserIdResult)> callback)
{
    SetRecoverValueByUserIdTask& task = *new SetRecoverValueByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::setMaxValueByStatus(SetMaxValueByStatusRequest request, std::function<void(AsyncSetMaxValueByStatusResult)> callback)
{
    SetMaxValueByStatusTask& task = *new SetMaxValueByStatusTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::setRecoverIntervalByStatus(SetRecoverIntervalByStatusRequest request, std::function<void(AsyncSetRecoverIntervalByStatusResult)> callback)
{
    SetRecoverIntervalByStatusTask& task = *new SetRecoverIntervalByStatusTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::setRecoverValueByStatus(SetRecoverValueByStatusRequest request, std::function<void(AsyncSetRecoverValueByStatusResult)> callback)
{
    SetRecoverValueByStatusTask& task = *new SetRecoverValueByStatusTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * ユーザIDを指定してスタミナを削除<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::deleteStaminaByUserId(DeleteStaminaByUserIdRequest request, std::function<void(AsyncDeleteStaminaByUserIdResult)> callback)
{
    DeleteStaminaByUserIdTask& task = *new DeleteStaminaByUserIdTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタンプシートを使用してスタミナを回復<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::recoverStaminaByStampSheet(RecoverStaminaByStampSheetRequest request, std::function<void(AsyncRecoverStaminaByStampSheetResult)> callback)
{
    RecoverStaminaByStampSheetTask& task = *new RecoverStaminaByStampSheetTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタンプシートでスタミナの最大値を加算<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::raiseMaxValueByStampSheet(RaiseMaxValueByStampSheetRequest request, std::function<void(AsyncRaiseMaxValueByStampSheetResult)> callback)
{
    RaiseMaxValueByStampSheetTask& task = *new RaiseMaxValueByStampSheetTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタンプシートでスタミナの最大値を更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::setMaxValueByStampSheet(SetMaxValueByStampSheetRequest request, std::function<void(AsyncSetMaxValueByStampSheetResult)> callback)
{
    SetMaxValueByStampSheetTask& task = *new SetMaxValueByStampSheetTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタンプシートでスタミナの最大値を更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::setRecoverIntervalByStampSheet(SetRecoverIntervalByStampSheetRequest request, std::function<void(AsyncSetRecoverIntervalByStampSheetResult)> callback)
{
    SetRecoverIntervalByStampSheetTask& task = *new SetRecoverIntervalByStampSheetTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタンプシートでスタミナの最大値を更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::setRecoverValueByStampSheet(SetRecoverValueByStampSheetRequest request, std::function<void(AsyncSetRecoverValueByStampSheetResult)> callback)
{
    SetRecoverValueByStampSheetTask& task = *new SetRecoverValueByStampSheetTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

/**
 * スタンプタスクを使用してスタミナを消費<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2StaminaWebSocketClient::consumeStaminaByStampTask(ConsumeStaminaByStampTaskRequest request, std::function<void(AsyncConsumeStaminaByStampTaskResult)> callback)
{
    ConsumeStaminaByStampTaskTask& task = *new ConsumeStaminaByStampTaskTask(std::move(request), callback);
    getGs2WebSocketSession().execute(task);
}

} }