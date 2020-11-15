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

#ifndef GS2_STAMINA_GS2STAMINARESTCLIENT_HPP_
#define GS2_STAMINA_GS2STAMINARESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
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
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeStaminaModelMastersResult.hpp"
#include "result/CreateStaminaModelMasterResult.hpp"
#include "result/GetStaminaModelMasterResult.hpp"
#include "result/UpdateStaminaModelMasterResult.hpp"
#include "result/DeleteStaminaModelMasterResult.hpp"
#include "result/DescribeMaxStaminaTableMastersResult.hpp"
#include "result/CreateMaxStaminaTableMasterResult.hpp"
#include "result/GetMaxStaminaTableMasterResult.hpp"
#include "result/UpdateMaxStaminaTableMasterResult.hpp"
#include "result/DeleteMaxStaminaTableMasterResult.hpp"
#include "result/DescribeRecoverIntervalTableMastersResult.hpp"
#include "result/CreateRecoverIntervalTableMasterResult.hpp"
#include "result/GetRecoverIntervalTableMasterResult.hpp"
#include "result/UpdateRecoverIntervalTableMasterResult.hpp"
#include "result/DeleteRecoverIntervalTableMasterResult.hpp"
#include "result/DescribeRecoverValueTableMastersResult.hpp"
#include "result/CreateRecoverValueTableMasterResult.hpp"
#include "result/GetRecoverValueTableMasterResult.hpp"
#include "result/UpdateRecoverValueTableMasterResult.hpp"
#include "result/DeleteRecoverValueTableMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentStaminaMasterResult.hpp"
#include "result/UpdateCurrentStaminaMasterResult.hpp"
#include "result/UpdateCurrentStaminaMasterFromGitHubResult.hpp"
#include "result/DescribeStaminaModelsResult.hpp"
#include "result/GetStaminaModelResult.hpp"
#include "result/DescribeStaminasResult.hpp"
#include "result/DescribeStaminasByUserIdResult.hpp"
#include "result/GetStaminaResult.hpp"
#include "result/GetStaminaByUserIdResult.hpp"
#include "result/UpdateStaminaByUserIdResult.hpp"
#include "result/ConsumeStaminaResult.hpp"
#include "result/ConsumeStaminaByUserIdResult.hpp"
#include "result/RecoverStaminaByUserIdResult.hpp"
#include "result/RaiseMaxValueByUserIdResult.hpp"
#include "result/SetMaxValueByUserIdResult.hpp"
#include "result/SetRecoverIntervalByUserIdResult.hpp"
#include "result/SetRecoverValueByUserIdResult.hpp"
#include "result/SetMaxValueByStatusResult.hpp"
#include "result/SetRecoverIntervalByStatusResult.hpp"
#include "result/SetRecoverValueByStatusResult.hpp"
#include "result/DeleteStaminaByUserIdResult.hpp"
#include "result/RecoverStaminaByStampSheetResult.hpp"
#include "result/RaiseMaxValueByStampSheetResult.hpp"
#include "result/SetMaxValueByStampSheetResult.hpp"
#include "result/SetRecoverIntervalByStampSheetResult.hpp"
#include "result/SetRecoverValueByStampSheetResult.hpp"
#include "result/ConsumeStaminaByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * GS2 Stamina API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2StaminaRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
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
            return "stamina";
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
            return "stamina";
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
            return "stamina";
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
            return "stamina";
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
            return "stamina";
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

    class DescribeStaminaModelMastersTask : public detail::Gs2RestSessionTask<DescribeStaminaModelMastersResult>
    {
    private:
        DescribeStaminaModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model";
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
        DescribeStaminaModelMastersTask(
            DescribeStaminaModelMastersRequest request,
            Gs2RestSessionTask<DescribeStaminaModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeStaminaModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeStaminaModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateStaminaModelMasterTask : public detail::Gs2RestSessionTask<CreateStaminaModelMasterResult>
    {
    private:
        CreateStaminaModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model";
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
            if (m_Request.getMaxStaminaTableName())
            {
                jsonWriter.writePropertyName("maxStaminaTableName");
                jsonWriter.writeCharArray(*m_Request.getMaxStaminaTableName());
            }
            if (m_Request.getRecoverIntervalTableName())
            {
                jsonWriter.writePropertyName("recoverIntervalTableName");
                jsonWriter.writeCharArray(*m_Request.getRecoverIntervalTableName());
            }
            if (m_Request.getRecoverValueTableName())
            {
                jsonWriter.writePropertyName("recoverValueTableName");
                jsonWriter.writeCharArray(*m_Request.getRecoverValueTableName());
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
        CreateStaminaModelMasterTask(
            CreateStaminaModelMasterRequest request,
            Gs2RestSessionTask<CreateStaminaModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateStaminaModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateStaminaModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetStaminaModelMasterTask : public detail::Gs2RestSessionTask<GetStaminaModelMasterResult>
    {
    private:
        GetStaminaModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{staminaName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetStaminaModelMasterTask(
            GetStaminaModelMasterRequest request,
            Gs2RestSessionTask<GetStaminaModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetStaminaModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetStaminaModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateStaminaModelMasterTask : public detail::Gs2RestSessionTask<UpdateStaminaModelMasterResult>
    {
    private:
        UpdateStaminaModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{staminaName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getMaxStaminaTableName())
            {
                jsonWriter.writePropertyName("maxStaminaTableName");
                jsonWriter.writeCharArray(*m_Request.getMaxStaminaTableName());
            }
            if (m_Request.getRecoverIntervalTableName())
            {
                jsonWriter.writePropertyName("recoverIntervalTableName");
                jsonWriter.writeCharArray(*m_Request.getRecoverIntervalTableName());
            }
            if (m_Request.getRecoverValueTableName())
            {
                jsonWriter.writePropertyName("recoverValueTableName");
                jsonWriter.writeCharArray(*m_Request.getRecoverValueTableName());
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
        UpdateStaminaModelMasterTask(
            UpdateStaminaModelMasterRequest request,
            Gs2RestSessionTask<UpdateStaminaModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateStaminaModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateStaminaModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteStaminaModelMasterTask : public detail::Gs2RestSessionTask<DeleteStaminaModelMasterResult>
    {
    private:
        DeleteStaminaModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{staminaName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteStaminaModelMasterTask(
            DeleteStaminaModelMasterRequest request,
            Gs2RestSessionTask<DeleteStaminaModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteStaminaModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteStaminaModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeMaxStaminaTableMastersTask : public detail::Gs2RestSessionTask<DescribeMaxStaminaTableMastersResult>
    {
    private:
        DescribeMaxStaminaTableMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/maxStaminaTable";
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
        DescribeMaxStaminaTableMastersTask(
            DescribeMaxStaminaTableMastersRequest request,
            Gs2RestSessionTask<DescribeMaxStaminaTableMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMaxStaminaTableMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMaxStaminaTableMastersTask() GS2_OVERRIDE = default;
    };

    class CreateMaxStaminaTableMasterTask : public detail::Gs2RestSessionTask<CreateMaxStaminaTableMasterResult>
    {
    private:
        CreateMaxStaminaTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/maxStaminaTable";
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
        CreateMaxStaminaTableMasterTask(
            CreateMaxStaminaTableMasterRequest request,
            Gs2RestSessionTask<CreateMaxStaminaTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateMaxStaminaTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
    };

    class GetMaxStaminaTableMasterTask : public detail::Gs2RestSessionTask<GetMaxStaminaTableMasterResult>
    {
    private:
        GetMaxStaminaTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/maxStaminaTable/{maxStaminaTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMaxStaminaTableName();
                url.replace("{maxStaminaTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMaxStaminaTableMasterTask(
            GetMaxStaminaTableMasterRequest request,
            Gs2RestSessionTask<GetMaxStaminaTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMaxStaminaTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateMaxStaminaTableMasterTask : public detail::Gs2RestSessionTask<UpdateMaxStaminaTableMasterResult>
    {
    private:
        UpdateMaxStaminaTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/maxStaminaTable/{maxStaminaTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMaxStaminaTableName();
                url.replace("{maxStaminaTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        UpdateMaxStaminaTableMasterTask(
            UpdateMaxStaminaTableMasterRequest request,
            Gs2RestSessionTask<UpdateMaxStaminaTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateMaxStaminaTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteMaxStaminaTableMasterTask : public detail::Gs2RestSessionTask<DeleteMaxStaminaTableMasterResult>
    {
    private:
        DeleteMaxStaminaTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/maxStaminaTable/{maxStaminaTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMaxStaminaTableName();
                url.replace("{maxStaminaTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteMaxStaminaTableMasterTask(
            DeleteMaxStaminaTableMasterRequest request,
            Gs2RestSessionTask<DeleteMaxStaminaTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteMaxStaminaTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMaxStaminaTableMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeRecoverIntervalTableMastersTask : public detail::Gs2RestSessionTask<DescribeRecoverIntervalTableMastersResult>
    {
    private:
        DescribeRecoverIntervalTableMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverIntervalTable";
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
        DescribeRecoverIntervalTableMastersTask(
            DescribeRecoverIntervalTableMastersRequest request,
            Gs2RestSessionTask<DescribeRecoverIntervalTableMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRecoverIntervalTableMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRecoverIntervalTableMastersTask() GS2_OVERRIDE = default;
    };

    class CreateRecoverIntervalTableMasterTask : public detail::Gs2RestSessionTask<CreateRecoverIntervalTableMasterResult>
    {
    private:
        CreateRecoverIntervalTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverIntervalTable";
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
        CreateRecoverIntervalTableMasterTask(
            CreateRecoverIntervalTableMasterRequest request,
            Gs2RestSessionTask<CreateRecoverIntervalTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateRecoverIntervalTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateRecoverIntervalTableMasterTask() GS2_OVERRIDE = default;
    };

    class GetRecoverIntervalTableMasterTask : public detail::Gs2RestSessionTask<GetRecoverIntervalTableMasterResult>
    {
    private:
        GetRecoverIntervalTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverIntervalTable/{recoverIntervalTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRecoverIntervalTableName();
                url.replace("{recoverIntervalTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetRecoverIntervalTableMasterTask(
            GetRecoverIntervalTableMasterRequest request,
            Gs2RestSessionTask<GetRecoverIntervalTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetRecoverIntervalTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRecoverIntervalTableMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateRecoverIntervalTableMasterTask : public detail::Gs2RestSessionTask<UpdateRecoverIntervalTableMasterResult>
    {
    private:
        UpdateRecoverIntervalTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverIntervalTable/{recoverIntervalTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRecoverIntervalTableName();
                url.replace("{recoverIntervalTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        UpdateRecoverIntervalTableMasterTask(
            UpdateRecoverIntervalTableMasterRequest request,
            Gs2RestSessionTask<UpdateRecoverIntervalTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateRecoverIntervalTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateRecoverIntervalTableMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteRecoverIntervalTableMasterTask : public detail::Gs2RestSessionTask<DeleteRecoverIntervalTableMasterResult>
    {
    private:
        DeleteRecoverIntervalTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverIntervalTable/{recoverIntervalTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRecoverIntervalTableName();
                url.replace("{recoverIntervalTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteRecoverIntervalTableMasterTask(
            DeleteRecoverIntervalTableMasterRequest request,
            Gs2RestSessionTask<DeleteRecoverIntervalTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteRecoverIntervalTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRecoverIntervalTableMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeRecoverValueTableMastersTask : public detail::Gs2RestSessionTask<DescribeRecoverValueTableMastersResult>
    {
    private:
        DescribeRecoverValueTableMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverValueTable";
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
        DescribeRecoverValueTableMastersTask(
            DescribeRecoverValueTableMastersRequest request,
            Gs2RestSessionTask<DescribeRecoverValueTableMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRecoverValueTableMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRecoverValueTableMastersTask() GS2_OVERRIDE = default;
    };

    class CreateRecoverValueTableMasterTask : public detail::Gs2RestSessionTask<CreateRecoverValueTableMasterResult>
    {
    private:
        CreateRecoverValueTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverValueTable";
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
        CreateRecoverValueTableMasterTask(
            CreateRecoverValueTableMasterRequest request,
            Gs2RestSessionTask<CreateRecoverValueTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateRecoverValueTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateRecoverValueTableMasterTask() GS2_OVERRIDE = default;
    };

    class GetRecoverValueTableMasterTask : public detail::Gs2RestSessionTask<GetRecoverValueTableMasterResult>
    {
    private:
        GetRecoverValueTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverValueTable/{recoverValueTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRecoverValueTableName();
                url.replace("{recoverValueTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetRecoverValueTableMasterTask(
            GetRecoverValueTableMasterRequest request,
            Gs2RestSessionTask<GetRecoverValueTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetRecoverValueTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRecoverValueTableMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateRecoverValueTableMasterTask : public detail::Gs2RestSessionTask<UpdateRecoverValueTableMasterResult>
    {
    private:
        UpdateRecoverValueTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverValueTable/{recoverValueTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRecoverValueTableName();
                url.replace("{recoverValueTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        UpdateRecoverValueTableMasterTask(
            UpdateRecoverValueTableMasterRequest request,
            Gs2RestSessionTask<UpdateRecoverValueTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateRecoverValueTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateRecoverValueTableMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteRecoverValueTableMasterTask : public detail::Gs2RestSessionTask<DeleteRecoverValueTableMasterResult>
    {
    private:
        DeleteRecoverValueTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/recoverValueTable/{recoverValueTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRecoverValueTableName();
                url.replace("{recoverValueTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteRecoverValueTableMasterTask(
            DeleteRecoverValueTableMasterRequest request,
            Gs2RestSessionTask<DeleteRecoverValueTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteRecoverValueTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRecoverValueTableMasterTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
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

    class GetCurrentStaminaMasterTask : public detail::Gs2RestSessionTask<GetCurrentStaminaMasterResult>
    {
    private:
        GetCurrentStaminaMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
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
        GetCurrentStaminaMasterTask(
            GetCurrentStaminaMasterRequest request,
            Gs2RestSessionTask<GetCurrentStaminaMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentStaminaMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentStaminaMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentStaminaMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentStaminaMasterResult>
    {
    private:
        UpdateCurrentStaminaMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
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
        UpdateCurrentStaminaMasterTask(
            UpdateCurrentStaminaMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentStaminaMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentStaminaMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentStaminaMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentStaminaMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>
    {
    private:
        UpdateCurrentStaminaMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
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
        UpdateCurrentStaminaMasterFromGitHubTask(
            UpdateCurrentStaminaMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentStaminaMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeStaminaModelsTask : public detail::Gs2RestSessionTask<DescribeStaminaModelsResult>
    {
    private:
        DescribeStaminaModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/model";
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
        DescribeStaminaModelsTask(
            DescribeStaminaModelsRequest request,
            Gs2RestSessionTask<DescribeStaminaModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeStaminaModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeStaminaModelsTask() GS2_OVERRIDE = default;
    };

    class GetStaminaModelTask : public detail::Gs2RestSessionTask<GetStaminaModelResult>
    {
    private:
        GetStaminaModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/model/{staminaName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetStaminaModelTask(
            GetStaminaModelRequest request,
            Gs2RestSessionTask<GetStaminaModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetStaminaModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetStaminaModelTask() GS2_OVERRIDE = default;
    };

    class DescribeStaminasTask : public detail::Gs2RestSessionTask<DescribeStaminasResult>
    {
    private:
        DescribeStaminasRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/stamina";
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
        DescribeStaminasTask(
            DescribeStaminasRequest request,
            Gs2RestSessionTask<DescribeStaminasResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeStaminasResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeStaminasTask() GS2_OVERRIDE = default;
    };

    class DescribeStaminasByUserIdTask : public detail::Gs2RestSessionTask<DescribeStaminasByUserIdResult>
    {
    private:
        DescribeStaminasByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina";
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
        DescribeStaminasByUserIdTask(
            DescribeStaminasByUserIdRequest request,
            Gs2RestSessionTask<DescribeStaminasByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeStaminasByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeStaminasByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetStaminaTask : public detail::Gs2RestSessionTask<GetStaminaResult>
    {
    private:
        GetStaminaRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/stamina/{staminaName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetStaminaTask(
            GetStaminaRequest request,
            Gs2RestSessionTask<GetStaminaResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetStaminaResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetStaminaTask() GS2_OVERRIDE = default;
    };

    class GetStaminaByUserIdTask : public detail::Gs2RestSessionTask<GetStaminaByUserIdResult>
    {
    private:
        GetStaminaByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina/{staminaName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetStaminaByUserIdTask(
            GetStaminaByUserIdRequest request,
            Gs2RestSessionTask<GetStaminaByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetStaminaByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateStaminaByUserIdTask : public detail::Gs2RestSessionTask<UpdateStaminaByUserIdResult>
    {
    private:
        UpdateStaminaByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina/{staminaName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        UpdateStaminaByUserIdTask(
            UpdateStaminaByUserIdRequest request,
            Gs2RestSessionTask<UpdateStaminaByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateStaminaByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class ConsumeStaminaTask : public detail::Gs2RestSessionTask<ConsumeStaminaResult>
    {
    private:
        ConsumeStaminaRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/stamina/{staminaName}/consume";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getConsumeValue())
            {
                jsonWriter.writePropertyName("consumeValue");
                jsonWriter.writeInt32(*m_Request.getConsumeValue());
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
        ConsumeStaminaTask(
            ConsumeStaminaRequest request,
            Gs2RestSessionTask<ConsumeStaminaResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ConsumeStaminaResult>(callback),
            m_Request(std::move(request))
        {}

        ~ConsumeStaminaTask() GS2_OVERRIDE = default;
    };

    class ConsumeStaminaByUserIdTask : public detail::Gs2RestSessionTask<ConsumeStaminaByUserIdResult>
    {
    private:
        ConsumeStaminaByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/consume";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getConsumeValue())
            {
                jsonWriter.writePropertyName("consumeValue");
                jsonWriter.writeInt32(*m_Request.getConsumeValue());
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
        ConsumeStaminaByUserIdTask(
            ConsumeStaminaByUserIdRequest request,
            Gs2RestSessionTask<ConsumeStaminaByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ConsumeStaminaByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~ConsumeStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class RecoverStaminaByUserIdTask : public detail::Gs2RestSessionTask<RecoverStaminaByUserIdResult>
    {
    private:
        RecoverStaminaByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/recover";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getRecoverValue())
            {
                jsonWriter.writePropertyName("recoverValue");
                jsonWriter.writeInt32(*m_Request.getRecoverValue());
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
        RecoverStaminaByUserIdTask(
            RecoverStaminaByUserIdRequest request,
            Gs2RestSessionTask<RecoverStaminaByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<RecoverStaminaByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~RecoverStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class RaiseMaxValueByUserIdTask : public detail::Gs2RestSessionTask<RaiseMaxValueByUserIdResult>
    {
    private:
        RaiseMaxValueByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/raise";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getRaiseValue())
            {
                jsonWriter.writePropertyName("raiseValue");
                jsonWriter.writeInt32(*m_Request.getRaiseValue());
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
        RaiseMaxValueByUserIdTask(
            RaiseMaxValueByUserIdRequest request,
            Gs2RestSessionTask<RaiseMaxValueByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<RaiseMaxValueByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~RaiseMaxValueByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetMaxValueByUserIdTask : public detail::Gs2RestSessionTask<SetMaxValueByUserIdResult>
    {
    private:
        SetMaxValueByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/set";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getMaxValue())
            {
                jsonWriter.writePropertyName("maxValue");
                jsonWriter.writeInt32(*m_Request.getMaxValue());
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
        SetMaxValueByUserIdTask(
            SetMaxValueByUserIdRequest request,
            Gs2RestSessionTask<SetMaxValueByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetMaxValueByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetMaxValueByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetRecoverIntervalByUserIdTask : public detail::Gs2RestSessionTask<SetRecoverIntervalByUserIdResult>
    {
    private:
        SetRecoverIntervalByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/recoverInterval/set";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getRecoverIntervalMinutes())
            {
                jsonWriter.writePropertyName("recoverIntervalMinutes");
                jsonWriter.writeInt32(*m_Request.getRecoverIntervalMinutes());
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
        SetRecoverIntervalByUserIdTask(
            SetRecoverIntervalByUserIdRequest request,
            Gs2RestSessionTask<SetRecoverIntervalByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetRecoverIntervalByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetRecoverIntervalByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetRecoverValueByUserIdTask : public detail::Gs2RestSessionTask<SetRecoverValueByUserIdResult>
    {
    private:
        SetRecoverValueByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/recoverValue/set";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getRecoverValue())
            {
                jsonWriter.writePropertyName("recoverValue");
                jsonWriter.writeInt32(*m_Request.getRecoverValue());
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
        SetRecoverValueByUserIdTask(
            SetRecoverValueByUserIdRequest request,
            Gs2RestSessionTask<SetRecoverValueByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetRecoverValueByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetRecoverValueByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetMaxValueByStatusTask : public detail::Gs2RestSessionTask<SetMaxValueByStatusResult>
    {
    private:
        SetMaxValueByStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/stamina/{staminaName}/set";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        SetMaxValueByStatusTask(
            SetMaxValueByStatusRequest request,
            Gs2RestSessionTask<SetMaxValueByStatusResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetMaxValueByStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetMaxValueByStatusTask() GS2_OVERRIDE = default;
    };

    class SetRecoverIntervalByStatusTask : public detail::Gs2RestSessionTask<SetRecoverIntervalByStatusResult>
    {
    private:
        SetRecoverIntervalByStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/stamina/{staminaName}/recoverInterval/set";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        SetRecoverIntervalByStatusTask(
            SetRecoverIntervalByStatusRequest request,
            Gs2RestSessionTask<SetRecoverIntervalByStatusResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetRecoverIntervalByStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetRecoverIntervalByStatusTask() GS2_OVERRIDE = default;
    };

    class SetRecoverValueByStatusTask : public detail::Gs2RestSessionTask<SetRecoverValueByStatusResult>
    {
    private:
        SetRecoverValueByStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/stamina/{staminaName}/reoverValue/set";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
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
        SetRecoverValueByStatusTask(
            SetRecoverValueByStatusRequest request,
            Gs2RestSessionTask<SetRecoverValueByStatusResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetRecoverValueByStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetRecoverValueByStatusTask() GS2_OVERRIDE = default;
    };

    class DeleteStaminaByUserIdTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteStaminaByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/stamina/{staminaName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getStaminaName();
                url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteStaminaByUserIdTask(
            DeleteStaminaByUserIdRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteStaminaByUserIdTask() GS2_OVERRIDE = default;
    };

    class RecoverStaminaByStampSheetTask : public detail::Gs2RestSessionTask<RecoverStaminaByStampSheetResult>
    {
    private:
        RecoverStaminaByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamina/recover";
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
        RecoverStaminaByStampSheetTask(
            RecoverStaminaByStampSheetRequest request,
            Gs2RestSessionTask<RecoverStaminaByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<RecoverStaminaByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~RecoverStaminaByStampSheetTask() GS2_OVERRIDE = default;
    };

    class RaiseMaxValueByStampSheetTask : public detail::Gs2RestSessionTask<RaiseMaxValueByStampSheetResult>
    {
    private:
        RaiseMaxValueByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamina/raise";
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
        RaiseMaxValueByStampSheetTask(
            RaiseMaxValueByStampSheetRequest request,
            Gs2RestSessionTask<RaiseMaxValueByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<RaiseMaxValueByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~RaiseMaxValueByStampSheetTask() GS2_OVERRIDE = default;
    };

    class SetMaxValueByStampSheetTask : public detail::Gs2RestSessionTask<SetMaxValueByStampSheetResult>
    {
    private:
        SetMaxValueByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamina/max/set";
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
        SetMaxValueByStampSheetTask(
            SetMaxValueByStampSheetRequest request,
            Gs2RestSessionTask<SetMaxValueByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetMaxValueByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetMaxValueByStampSheetTask() GS2_OVERRIDE = default;
    };

    class SetRecoverIntervalByStampSheetTask : public detail::Gs2RestSessionTask<SetRecoverIntervalByStampSheetResult>
    {
    private:
        SetRecoverIntervalByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamina/recoverInterval/set";
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
        SetRecoverIntervalByStampSheetTask(
            SetRecoverIntervalByStampSheetRequest request,
            Gs2RestSessionTask<SetRecoverIntervalByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetRecoverIntervalByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetRecoverIntervalByStampSheetTask() GS2_OVERRIDE = default;
    };

    class SetRecoverValueByStampSheetTask : public detail::Gs2RestSessionTask<SetRecoverValueByStampSheetResult>
    {
    private:
        SetRecoverValueByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamina/recoverValue/set";
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
        SetRecoverValueByStampSheetTask(
            SetRecoverValueByStampSheetRequest request,
            Gs2RestSessionTask<SetRecoverValueByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetRecoverValueByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetRecoverValueByStampSheetTask() GS2_OVERRIDE = default;
    };

    class ConsumeStaminaByStampTaskTask : public detail::Gs2RestSessionTask<ConsumeStaminaByStampTaskResult>
    {
    private:
        ConsumeStaminaByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "stamina";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamina/consume";
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
        ConsumeStaminaByStampTaskTask(
            ConsumeStaminaByStampTaskRequest request,
            Gs2RestSessionTask<ConsumeStaminaByStampTaskResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ConsumeStaminaByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~ConsumeStaminaByStampTaskTask() GS2_OVERRIDE = default;
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

    static void write(detail::json::JsonWriter& jsonWriter, const StaminaModelMaster& obj)
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
        if (obj.getMaxStaminaTableName())
        {
            jsonWriter.writePropertyName("maxStaminaTableName");
            jsonWriter.writeCharArray(*obj.getMaxStaminaTableName());
        }
        if (obj.getRecoverIntervalTableName())
        {
            jsonWriter.writePropertyName("recoverIntervalTableName");
            jsonWriter.writeCharArray(*obj.getRecoverIntervalTableName());
        }
        if (obj.getRecoverValueTableName())
        {
            jsonWriter.writePropertyName("recoverValueTableName");
            jsonWriter.writeCharArray(*obj.getRecoverValueTableName());
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

    static void write(detail::json::JsonWriter& jsonWriter, const MaxStaminaTableMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const RecoverIntervalTableMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const RecoverValueTableMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentStaminaMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const StaminaModel& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const MaxStaminaTable& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const RecoverIntervalTable& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const RecoverValueTable& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const Stamina& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const GitHubCheckoutSetting& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getLoggingNamespaceId())
        {
            jsonWriter.writePropertyName("loggingNamespaceId");
            jsonWriter.writeCharArray(*obj.getLoggingNamespaceId());
        }
        jsonWriter.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2StaminaRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
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
        getGs2RestSession().execute(task);
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
        getGs2RestSession().execute(task);
    }

	/**
	 * ネームスペースの状態を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
    void getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
    void updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
    void deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
    {
        DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModelMasters(DescribeStaminaModelMastersRequest request, std::function<void(AsyncDescribeStaminaModelMastersResult)> callback)
    {
        DescribeStaminaModelMastersTask& task = *new DescribeStaminaModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStaminaModelMaster(CreateStaminaModelMasterRequest request, std::function<void(AsyncCreateStaminaModelMasterResult)> callback)
    {
        CreateStaminaModelMasterTask& task = *new CreateStaminaModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModelMaster(GetStaminaModelMasterRequest request, std::function<void(AsyncGetStaminaModelMasterResult)> callback)
    {
        GetStaminaModelMasterTask& task = *new GetStaminaModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaModelMaster(UpdateStaminaModelMasterRequest request, std::function<void(AsyncUpdateStaminaModelMasterResult)> callback)
    {
        UpdateStaminaModelMasterTask& task = *new UpdateStaminaModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaModelMaster(DeleteStaminaModelMasterRequest request, std::function<void(AsyncDeleteStaminaModelMasterResult)> callback)
    {
        DeleteStaminaModelMasterTask& task = *new DeleteStaminaModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナの最大値テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMaxStaminaTableMasters(DescribeMaxStaminaTableMastersRequest request, std::function<void(AsyncDescribeMaxStaminaTableMastersResult)> callback)
    {
        DescribeMaxStaminaTableMastersTask& task = *new DescribeMaxStaminaTableMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナの最大値テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMaxStaminaTableMaster(CreateMaxStaminaTableMasterRequest request, std::function<void(AsyncCreateMaxStaminaTableMasterResult)> callback)
    {
        CreateMaxStaminaTableMasterTask& task = *new CreateMaxStaminaTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナの最大値テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMaxStaminaTableMaster(GetMaxStaminaTableMasterRequest request, std::function<void(AsyncGetMaxStaminaTableMasterResult)> callback)
    {
        GetMaxStaminaTableMasterTask& task = *new GetMaxStaminaTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナの最大値テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMaxStaminaTableMaster(UpdateMaxStaminaTableMasterRequest request, std::function<void(AsyncUpdateMaxStaminaTableMasterResult)> callback)
    {
        UpdateMaxStaminaTableMasterTask& task = *new UpdateMaxStaminaTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナの最大値テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMaxStaminaTableMaster(DeleteMaxStaminaTableMasterRequest request, std::function<void(AsyncDeleteMaxStaminaTableMasterResult)> callback)
    {
        DeleteMaxStaminaTableMasterTask& task = *new DeleteMaxStaminaTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復間隔テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRecoverIntervalTableMasters(DescribeRecoverIntervalTableMastersRequest request, std::function<void(AsyncDescribeRecoverIntervalTableMastersResult)> callback)
    {
        DescribeRecoverIntervalTableMastersTask& task = *new DescribeRecoverIntervalTableMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復間隔テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRecoverIntervalTableMaster(CreateRecoverIntervalTableMasterRequest request, std::function<void(AsyncCreateRecoverIntervalTableMasterResult)> callback)
    {
        CreateRecoverIntervalTableMasterTask& task = *new CreateRecoverIntervalTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復間隔テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRecoverIntervalTableMaster(GetRecoverIntervalTableMasterRequest request, std::function<void(AsyncGetRecoverIntervalTableMasterResult)> callback)
    {
        GetRecoverIntervalTableMasterTask& task = *new GetRecoverIntervalTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復間隔テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRecoverIntervalTableMaster(UpdateRecoverIntervalTableMasterRequest request, std::function<void(AsyncUpdateRecoverIntervalTableMasterResult)> callback)
    {
        UpdateRecoverIntervalTableMasterTask& task = *new UpdateRecoverIntervalTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復間隔テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRecoverIntervalTableMaster(DeleteRecoverIntervalTableMasterRequest request, std::function<void(AsyncDeleteRecoverIntervalTableMasterResult)> callback)
    {
        DeleteRecoverIntervalTableMasterTask& task = *new DeleteRecoverIntervalTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復量テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRecoverValueTableMasters(DescribeRecoverValueTableMastersRequest request, std::function<void(AsyncDescribeRecoverValueTableMastersResult)> callback)
    {
        DescribeRecoverValueTableMastersTask& task = *new DescribeRecoverValueTableMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復量テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRecoverValueTableMaster(CreateRecoverValueTableMasterRequest request, std::function<void(AsyncCreateRecoverValueTableMasterResult)> callback)
    {
        CreateRecoverValueTableMasterTask& task = *new CreateRecoverValueTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復量テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRecoverValueTableMaster(GetRecoverValueTableMasterRequest request, std::function<void(AsyncGetRecoverValueTableMasterResult)> callback)
    {
        GetRecoverValueTableMasterTask& task = *new GetRecoverValueTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復量テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRecoverValueTableMaster(UpdateRecoverValueTableMasterRequest request, std::function<void(AsyncUpdateRecoverValueTableMasterResult)> callback)
    {
        UpdateRecoverValueTableMasterTask& task = *new UpdateRecoverValueTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナ回復量テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRecoverValueTableMaster(DeleteRecoverValueTableMasterRequest request, std::function<void(AsyncDeleteRecoverValueTableMasterResult)> callback)
    {
        DeleteRecoverValueTableMasterTask& task = *new DeleteRecoverValueTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なスタミナマスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest request, std::function<void(AsyncExportMasterResult)> callback)
    {
        ExportMasterTask& task = *new ExportMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なスタミナマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentStaminaMaster(GetCurrentStaminaMasterRequest request, std::function<void(AsyncGetCurrentStaminaMasterResult)> callback)
    {
        GetCurrentStaminaMasterTask& task = *new GetCurrentStaminaMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なスタミナマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentStaminaMaster(UpdateCurrentStaminaMasterRequest request, std::function<void(AsyncUpdateCurrentStaminaMasterResult)> callback)
    {
        UpdateCurrentStaminaMasterTask& task = *new UpdateCurrentStaminaMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なスタミナマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentStaminaMasterFromGitHub(UpdateCurrentStaminaMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentStaminaMasterFromGitHubResult)> callback)
    {
        UpdateCurrentStaminaMasterFromGitHubTask& task = *new UpdateCurrentStaminaMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModels(DescribeStaminaModelsRequest request, std::function<void(AsyncDescribeStaminaModelsResult)> callback)
    {
        DescribeStaminaModelsTask& task = *new DescribeStaminaModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModel(GetStaminaModelRequest request, std::function<void(AsyncGetStaminaModelResult)> callback)
    {
        GetStaminaModelTask& task = *new GetStaminaModelTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminas(DescribeStaminasRequest request, std::function<void(AsyncDescribeStaminasResult)> callback)
    {
        DescribeStaminasTask& task = *new DescribeStaminasTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminasByUserId(DescribeStaminasByUserIdRequest request, std::function<void(AsyncDescribeStaminasByUserIdResult)> callback)
    {
        DescribeStaminasByUserIdTask& task = *new DescribeStaminasByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStamina(GetStaminaRequest request, std::function<void(AsyncGetStaminaResult)> callback)
    {
        GetStaminaTask& task = *new GetStaminaTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaByUserId(GetStaminaByUserIdRequest request, std::function<void(AsyncGetStaminaByUserIdResult)> callback)
    {
        GetStaminaByUserIdTask& task = *new GetStaminaByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナを作成・更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaByUserId(UpdateStaminaByUserIdRequest request, std::function<void(AsyncUpdateStaminaByUserIdResult)> callback)
    {
        UpdateStaminaByUserIdTask& task = *new UpdateStaminaByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStamina(ConsumeStaminaRequest request, std::function<void(AsyncConsumeStaminaResult)> callback)
    {
        ConsumeStaminaTask& task = *new ConsumeStaminaTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByUserId(ConsumeStaminaByUserIdRequest request, std::function<void(AsyncConsumeStaminaByUserIdResult)> callback)
    {
        ConsumeStaminaByUserIdTask& task = *new ConsumeStaminaByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByUserId(RecoverStaminaByUserIdRequest request, std::function<void(AsyncRecoverStaminaByUserIdResult)> callback)
    {
        RecoverStaminaByUserIdTask& task = *new RecoverStaminaByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByUserId(RaiseMaxValueByUserIdRequest request, std::function<void(AsyncRaiseMaxValueByUserIdResult)> callback)
    {
        RaiseMaxValueByUserIdTask& task = *new RaiseMaxValueByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByUserId(SetMaxValueByUserIdRequest request, std::function<void(AsyncSetMaxValueByUserIdResult)> callback)
    {
        SetMaxValueByUserIdTask& task = *new SetMaxValueByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナの回復間隔(分)を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverIntervalByUserId(SetRecoverIntervalByUserIdRequest request, std::function<void(AsyncSetRecoverIntervalByUserIdResult)> callback)
    {
        SetRecoverIntervalByUserIdTask& task = *new SetRecoverIntervalByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナの回復間隔(分)を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverValueByUserId(SetRecoverValueByUserIdRequest request, std::function<void(AsyncSetRecoverValueByUserIdResult)> callback)
    {
        SetRecoverValueByUserIdTask& task = *new SetRecoverValueByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStatus(SetMaxValueByStatusRequest request, std::function<void(AsyncSetMaxValueByStatusResult)> callback)
    {
        SetMaxValueByStatusTask& task = *new SetMaxValueByStatusTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverIntervalByStatus(SetRecoverIntervalByStatusRequest request, std::function<void(AsyncSetRecoverIntervalByStatusResult)> callback)
    {
        SetRecoverIntervalByStatusTask& task = *new SetRecoverIntervalByStatusTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverValueByStatus(SetRecoverValueByStatusRequest request, std::function<void(AsyncSetRecoverValueByStatusResult)> callback)
    {
        SetRecoverValueByStatusTask& task = *new SetRecoverValueByStatusTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してスタミナを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaByUserId(DeleteStaminaByUserIdRequest request, std::function<void(AsyncDeleteStaminaByUserIdResult)> callback)
    {
        DeleteStaminaByUserIdTask& task = *new DeleteStaminaByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートを使用してスタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByStampSheet(RecoverStaminaByStampSheetRequest request, std::function<void(AsyncRecoverStaminaByStampSheetResult)> callback)
    {
        RecoverStaminaByStampSheetTask& task = *new RecoverStaminaByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートでスタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByStampSheet(RaiseMaxValueByStampSheetRequest request, std::function<void(AsyncRaiseMaxValueByStampSheetResult)> callback)
    {
        RaiseMaxValueByStampSheetTask& task = *new RaiseMaxValueByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートでスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStampSheet(SetMaxValueByStampSheetRequest request, std::function<void(AsyncSetMaxValueByStampSheetResult)> callback)
    {
        SetMaxValueByStampSheetTask& task = *new SetMaxValueByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートでスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverIntervalByStampSheet(SetRecoverIntervalByStampSheetRequest request, std::function<void(AsyncSetRecoverIntervalByStampSheetResult)> callback)
    {
        SetRecoverIntervalByStampSheetTask& task = *new SetRecoverIntervalByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートでスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRecoverValueByStampSheet(SetRecoverValueByStampSheetRequest request, std::function<void(AsyncSetRecoverValueByStampSheetResult)> callback)
    {
        SetRecoverValueByStampSheetTask& task = *new SetRecoverValueByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプタスクを使用してスタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByStampTask(ConsumeStaminaByStampTaskRequest request, std::function<void(AsyncConsumeStaminaByStampTaskResult)> callback)
    {
        ConsumeStaminaByStampTaskTask& task = *new ConsumeStaminaByStampTaskTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_STAMINA_GS2STAMINARESTCLIENT_HPP_