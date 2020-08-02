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

#ifndef GS2_FORMATION_GS2FORMATIONRESTCLIENT_HPP_
#define GS2_FORMATION_GS2FORMATIONRESTCLIENT_HPP_

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
#include "request/DescribeFormModelMastersRequest.hpp"
#include "request/CreateFormModelMasterRequest.hpp"
#include "request/GetFormModelMasterRequest.hpp"
#include "request/UpdateFormModelMasterRequest.hpp"
#include "request/DeleteFormModelMasterRequest.hpp"
#include "request/DescribeMoldModelsRequest.hpp"
#include "request/GetMoldModelRequest.hpp"
#include "request/DescribeMoldModelMastersRequest.hpp"
#include "request/CreateMoldModelMasterRequest.hpp"
#include "request/GetMoldModelMasterRequest.hpp"
#include "request/UpdateMoldModelMasterRequest.hpp"
#include "request/DeleteMoldModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentFormMasterRequest.hpp"
#include "request/UpdateCurrentFormMasterRequest.hpp"
#include "request/UpdateCurrentFormMasterFromGitHubRequest.hpp"
#include "request/DescribeMoldsRequest.hpp"
#include "request/DescribeMoldsByUserIdRequest.hpp"
#include "request/GetMoldRequest.hpp"
#include "request/GetMoldByUserIdRequest.hpp"
#include "request/SetMoldCapacityByUserIdRequest.hpp"
#include "request/AddMoldCapacityByUserIdRequest.hpp"
#include "request/DeleteMoldRequest.hpp"
#include "request/DeleteMoldByUserIdRequest.hpp"
#include "request/AddCapacityByStampSheetRequest.hpp"
#include "request/SetCapacityByStampSheetRequest.hpp"
#include "request/DescribeFormsRequest.hpp"
#include "request/DescribeFormsByUserIdRequest.hpp"
#include "request/GetFormRequest.hpp"
#include "request/GetFormByUserIdRequest.hpp"
#include "request/GetFormWithSignatureRequest.hpp"
#include "request/GetFormWithSignatureByUserIdRequest.hpp"
#include "request/SetFormByUserIdRequest.hpp"
#include "request/SetFormWithSignatureRequest.hpp"
#include "request/AcquireActionsToFormPropertiesRequest.hpp"
#include "request/DeleteFormRequest.hpp"
#include "request/DeleteFormByUserIdRequest.hpp"
#include "request/AcquireActionToFormPropertiesByStampSheetRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeFormModelMastersResult.hpp"
#include "result/CreateFormModelMasterResult.hpp"
#include "result/GetFormModelMasterResult.hpp"
#include "result/UpdateFormModelMasterResult.hpp"
#include "result/DeleteFormModelMasterResult.hpp"
#include "result/DescribeMoldModelsResult.hpp"
#include "result/GetMoldModelResult.hpp"
#include "result/DescribeMoldModelMastersResult.hpp"
#include "result/CreateMoldModelMasterResult.hpp"
#include "result/GetMoldModelMasterResult.hpp"
#include "result/UpdateMoldModelMasterResult.hpp"
#include "result/DeleteMoldModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentFormMasterResult.hpp"
#include "result/UpdateCurrentFormMasterResult.hpp"
#include "result/UpdateCurrentFormMasterFromGitHubResult.hpp"
#include "result/DescribeMoldsResult.hpp"
#include "result/DescribeMoldsByUserIdResult.hpp"
#include "result/GetMoldResult.hpp"
#include "result/GetMoldByUserIdResult.hpp"
#include "result/SetMoldCapacityByUserIdResult.hpp"
#include "result/AddMoldCapacityByUserIdResult.hpp"
#include "result/DeleteMoldResult.hpp"
#include "result/DeleteMoldByUserIdResult.hpp"
#include "result/AddCapacityByStampSheetResult.hpp"
#include "result/SetCapacityByStampSheetResult.hpp"
#include "result/DescribeFormsResult.hpp"
#include "result/DescribeFormsByUserIdResult.hpp"
#include "result/GetFormResult.hpp"
#include "result/GetFormByUserIdResult.hpp"
#include "result/GetFormWithSignatureResult.hpp"
#include "result/GetFormWithSignatureByUserIdResult.hpp"
#include "result/SetFormByUserIdResult.hpp"
#include "result/SetFormWithSignatureResult.hpp"
#include "result/AcquireActionsToFormPropertiesResult.hpp"
#include "result/DeleteFormResult.hpp"
#include "result/DeleteFormByUserIdResult.hpp"
#include "result/AcquireActionToFormPropertiesByStampSheetResult.hpp"
#include <cstring>

namespace gs2 { namespace formation {

/**
 * GS2 Formation API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2FormationRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
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
            return "formation";
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
            if (m_Request.getUpdateMoldScript())
            {
                jsonWriter.writePropertyName("updateMoldScript");
                write(jsonWriter, *m_Request.getUpdateMoldScript());
            }
            if (m_Request.getUpdateFormScript())
            {
                jsonWriter.writePropertyName("updateFormScript");
                write(jsonWriter, *m_Request.getUpdateFormScript());
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
            return "formation";
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
            return "formation";
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
            return "formation";
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
            if (m_Request.getUpdateMoldScript())
            {
                jsonWriter.writePropertyName("updateMoldScript");
                write(jsonWriter, *m_Request.getUpdateMoldScript());
            }
            if (m_Request.getUpdateFormScript())
            {
                jsonWriter.writePropertyName("updateFormScript");
                write(jsonWriter, *m_Request.getUpdateFormScript());
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
            return "formation";
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

    class DescribeFormModelMastersTask : public detail::Gs2RestSessionTask<DescribeFormModelMastersResult>
    {
    private:
        DescribeFormModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/form";
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
        DescribeFormModelMastersTask(
            DescribeFormModelMastersRequest request,
            Gs2RestSessionTask<DescribeFormModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeFormModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFormModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateFormModelMasterTask : public detail::Gs2RestSessionTask<CreateFormModelMasterResult>
    {
    private:
        CreateFormModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/form";
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
            if (m_Request.getSlots())
            {
                jsonWriter.writePropertyName("slots");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getSlots();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
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
        CreateFormModelMasterTask(
            CreateFormModelMasterRequest request,
            Gs2RestSessionTask<CreateFormModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateFormModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateFormModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetFormModelMasterTask : public detail::Gs2RestSessionTask<GetFormModelMasterResult>
    {
    private:
        GetFormModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/form/{formModelName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getFormModelName();
                url.replace("{formModelName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetFormModelMasterTask(
            GetFormModelMasterRequest request,
            Gs2RestSessionTask<GetFormModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFormModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFormModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateFormModelMasterTask : public detail::Gs2RestSessionTask<UpdateFormModelMasterResult>
    {
    private:
        UpdateFormModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/form/{formModelName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getFormModelName();
                url.replace("{formModelName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getSlots())
            {
                jsonWriter.writePropertyName("slots");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getSlots();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
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
        UpdateFormModelMasterTask(
            UpdateFormModelMasterRequest request,
            Gs2RestSessionTask<UpdateFormModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateFormModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateFormModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteFormModelMasterTask : public detail::Gs2RestSessionTask<DeleteFormModelMasterResult>
    {
    private:
        DeleteFormModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/form/{formModelName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getFormModelName();
                url.replace("{formModelName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteFormModelMasterTask(
            DeleteFormModelMasterRequest request,
            Gs2RestSessionTask<DeleteFormModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteFormModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteFormModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeMoldModelsTask : public detail::Gs2RestSessionTask<DescribeMoldModelsResult>
    {
    private:
        DescribeMoldModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/model/mold";
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
        DescribeMoldModelsTask(
            DescribeMoldModelsRequest request,
            Gs2RestSessionTask<DescribeMoldModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMoldModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMoldModelsTask() GS2_OVERRIDE = default;
    };

    class GetMoldModelTask : public detail::Gs2RestSessionTask<GetMoldModelResult>
    {
    private:
        GetMoldModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/model/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMoldModelTask(
            GetMoldModelRequest request,
            Gs2RestSessionTask<GetMoldModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMoldModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMoldModelTask() GS2_OVERRIDE = default;
    };

    class DescribeMoldModelMastersTask : public detail::Gs2RestSessionTask<DescribeMoldModelMastersResult>
    {
    private:
        DescribeMoldModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/mold";
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
        DescribeMoldModelMastersTask(
            DescribeMoldModelMastersRequest request,
            Gs2RestSessionTask<DescribeMoldModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMoldModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMoldModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateMoldModelMasterTask : public detail::Gs2RestSessionTask<CreateMoldModelMasterResult>
    {
    private:
        CreateMoldModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/mold";
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
            if (m_Request.getFormModelName())
            {
                jsonWriter.writePropertyName("formModelName");
                jsonWriter.writeCharArray(*m_Request.getFormModelName());
            }
            if (m_Request.getInitialMaxCapacity())
            {
                jsonWriter.writePropertyName("initialMaxCapacity");
                jsonWriter.writeInt32(*m_Request.getInitialMaxCapacity());
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
        CreateMoldModelMasterTask(
            CreateMoldModelMasterRequest request,
            Gs2RestSessionTask<CreateMoldModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateMoldModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateMoldModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetMoldModelMasterTask : public detail::Gs2RestSessionTask<GetMoldModelMasterResult>
    {
    private:
        GetMoldModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMoldModelMasterTask(
            GetMoldModelMasterRequest request,
            Gs2RestSessionTask<GetMoldModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMoldModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMoldModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateMoldModelMasterTask : public detail::Gs2RestSessionTask<UpdateMoldModelMasterResult>
    {
    private:
        UpdateMoldModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getFormModelName())
            {
                jsonWriter.writePropertyName("formModelName");
                jsonWriter.writeCharArray(*m_Request.getFormModelName());
            }
            if (m_Request.getInitialMaxCapacity())
            {
                jsonWriter.writePropertyName("initialMaxCapacity");
                jsonWriter.writeInt32(*m_Request.getInitialMaxCapacity());
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
        UpdateMoldModelMasterTask(
            UpdateMoldModelMasterRequest request,
            Gs2RestSessionTask<UpdateMoldModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateMoldModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateMoldModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteMoldModelMasterTask : public detail::Gs2RestSessionTask<DeleteMoldModelMasterResult>
    {
    private:
        DeleteMoldModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteMoldModelMasterTask(
            DeleteMoldModelMasterRequest request,
            Gs2RestSessionTask<DeleteMoldModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteMoldModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMoldModelMasterTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
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

    class GetCurrentFormMasterTask : public detail::Gs2RestSessionTask<GetCurrentFormMasterResult>
    {
    private:
        GetCurrentFormMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
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
        GetCurrentFormMasterTask(
            GetCurrentFormMasterRequest request,
            Gs2RestSessionTask<GetCurrentFormMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentFormMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentFormMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentFormMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentFormMasterResult>
    {
    private:
        UpdateCurrentFormMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
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
        UpdateCurrentFormMasterTask(
            UpdateCurrentFormMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentFormMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentFormMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentFormMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentFormMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentFormMasterFromGitHubResult>
    {
    private:
        UpdateCurrentFormMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
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
        UpdateCurrentFormMasterFromGitHubTask(
            UpdateCurrentFormMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentFormMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentFormMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentFormMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeMoldsTask : public detail::Gs2RestSessionTask<DescribeMoldsResult>
    {
    private:
        DescribeMoldsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/mold";
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
        DescribeMoldsTask(
            DescribeMoldsRequest request,
            Gs2RestSessionTask<DescribeMoldsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMoldsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMoldsTask() GS2_OVERRIDE = default;
    };

    class DescribeMoldsByUserIdTask : public detail::Gs2RestSessionTask<DescribeMoldsByUserIdResult>
    {
    private:
        DescribeMoldsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold";
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
        DescribeMoldsByUserIdTask(
            DescribeMoldsByUserIdRequest request,
            Gs2RestSessionTask<DescribeMoldsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMoldsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMoldsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetMoldTask : public detail::Gs2RestSessionTask<GetMoldResult>
    {
    private:
        GetMoldRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMoldTask(
            GetMoldRequest request,
            Gs2RestSessionTask<GetMoldResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMoldResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMoldTask() GS2_OVERRIDE = default;
    };

    class GetMoldByUserIdTask : public detail::Gs2RestSessionTask<GetMoldByUserIdResult>
    {
    private:
        GetMoldByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMoldByUserIdTask(
            GetMoldByUserIdRequest request,
            Gs2RestSessionTask<GetMoldByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMoldByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMoldByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetMoldCapacityByUserIdTask : public detail::Gs2RestSessionTask<SetMoldCapacityByUserIdResult>
    {
    private:
        SetMoldCapacityByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getCapacity())
            {
                jsonWriter.writePropertyName("capacity");
                jsonWriter.writeInt32(*m_Request.getCapacity());
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
        SetMoldCapacityByUserIdTask(
            SetMoldCapacityByUserIdRequest request,
            Gs2RestSessionTask<SetMoldCapacityByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetMoldCapacityByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetMoldCapacityByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddMoldCapacityByUserIdTask : public detail::Gs2RestSessionTask<AddMoldCapacityByUserIdResult>
    {
    private:
        AddMoldCapacityByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getCapacity())
            {
                jsonWriter.writePropertyName("capacity");
                jsonWriter.writeInt32(*m_Request.getCapacity());
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
        AddMoldCapacityByUserIdTask(
            AddMoldCapacityByUserIdRequest request,
            Gs2RestSessionTask<AddMoldCapacityByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AddMoldCapacityByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddMoldCapacityByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteMoldTask : public detail::Gs2RestSessionTask<DeleteMoldResult>
    {
    private:
        DeleteMoldRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteMoldTask(
            DeleteMoldRequest request,
            Gs2RestSessionTask<DeleteMoldResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteMoldResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMoldTask() GS2_OVERRIDE = default;
    };

    class DeleteMoldByUserIdTask : public detail::Gs2RestSessionTask<DeleteMoldByUserIdResult>
    {
    private:
        DeleteMoldByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteMoldByUserIdTask(
            DeleteMoldByUserIdRequest request,
            Gs2RestSessionTask<DeleteMoldByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteMoldByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMoldByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddCapacityByStampSheetTask : public detail::Gs2RestSessionTask<AddCapacityByStampSheetResult>
    {
    private:
        AddCapacityByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/mold/capacity/add";
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
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/mold/capacity/set";
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

    class DescribeFormsTask : public detail::Gs2RestSessionTask<DescribeFormsResult>
    {
    private:
        DescribeFormsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/mold/{moldName}/form";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeFormsTask(
            DescribeFormsRequest request,
            Gs2RestSessionTask<DescribeFormsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeFormsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFormsTask() GS2_OVERRIDE = default;
    };

    class DescribeFormsByUserIdTask : public detail::Gs2RestSessionTask<DescribeFormsByUserIdResult>
    {
    private:
        DescribeFormsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}/form";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeFormsByUserIdTask(
            DescribeFormsByUserIdRequest request,
            Gs2RestSessionTask<DescribeFormsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeFormsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeFormsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetFormTask : public detail::Gs2RestSessionTask<GetFormResult>
    {
    private:
        GetFormRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/mold/{moldName}/form/{index}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getIndex();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{index}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{index}", "null");
                }
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
        GetFormTask(
            GetFormRequest request,
            Gs2RestSessionTask<GetFormResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFormResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFormTask() GS2_OVERRIDE = default;
    };

    class GetFormByUserIdTask : public detail::Gs2RestSessionTask<GetFormByUserIdResult>
    {
    private:
        GetFormByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}/form/{index}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getIndex();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{index}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{index}", "null");
                }
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
        GetFormByUserIdTask(
            GetFormByUserIdRequest request,
            Gs2RestSessionTask<GetFormByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFormByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFormByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetFormWithSignatureTask : public detail::Gs2RestSessionTask<GetFormWithSignatureResult>
    {
    private:
        GetFormWithSignatureRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/mold/{moldName}/form/{index}/signature";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getIndex();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{index}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{index}", "null");
                }
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        GetFormWithSignatureTask(
            GetFormWithSignatureRequest request,
            Gs2RestSessionTask<GetFormWithSignatureResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFormWithSignatureResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFormWithSignatureTask() GS2_OVERRIDE = default;
    };

    class GetFormWithSignatureByUserIdTask : public detail::Gs2RestSessionTask<GetFormWithSignatureByUserIdResult>
    {
    private:
        GetFormWithSignatureByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}/form/{index}/signature";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getIndex();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{index}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{index}", "null");
                }
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        GetFormWithSignatureByUserIdTask(
            GetFormWithSignatureByUserIdRequest request,
            Gs2RestSessionTask<GetFormWithSignatureByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFormWithSignatureByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFormWithSignatureByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetFormByUserIdTask : public detail::Gs2RestSessionTask<SetFormByUserIdResult>
    {
    private:
        SetFormByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}/form/{index}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getIndex();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{index}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{index}", "null");
                }
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getSlots())
            {
                jsonWriter.writePropertyName("slots");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getSlots();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        SetFormByUserIdTask(
            SetFormByUserIdRequest request,
            Gs2RestSessionTask<SetFormByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetFormByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetFormByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetFormWithSignatureTask : public detail::Gs2RestSessionTask<SetFormWithSignatureResult>
    {
    private:
        SetFormWithSignatureRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/mold/{moldName}/form/{index}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getIndex();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{index}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{index}", "null");
                }
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getSlots())
            {
                jsonWriter.writePropertyName("slots");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getSlots();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        SetFormWithSignatureTask(
            SetFormWithSignatureRequest request,
            Gs2RestSessionTask<SetFormWithSignatureResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetFormWithSignatureResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetFormWithSignatureTask() GS2_OVERRIDE = default;
    };

    class AcquireActionsToFormPropertiesTask : public detail::Gs2RestSessionTask<AcquireActionsToFormPropertiesResult>
    {
    private:
        AcquireActionsToFormPropertiesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}/form/{index}/stamp/delegate";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getIndex();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{index}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{index}", "null");
                }
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getAcquireAction())
            {
                jsonWriter.writePropertyName("acquireAction");
                write(jsonWriter, *m_Request.getAcquireAction());
            }
            if (m_Request.getQueueNamespaceId())
            {
                jsonWriter.writePropertyName("queueNamespaceId");
                jsonWriter.writeCharArray(*m_Request.getQueueNamespaceId());
            }
            if (m_Request.getKeyId())
            {
                jsonWriter.writePropertyName("keyId");
                jsonWriter.writeCharArray(*m_Request.getKeyId());
            }
            if (m_Request.getConfig())
            {
                jsonWriter.writePropertyName("config");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getConfig();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        AcquireActionsToFormPropertiesTask(
            AcquireActionsToFormPropertiesRequest request,
            Gs2RestSessionTask<AcquireActionsToFormPropertiesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AcquireActionsToFormPropertiesResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireActionsToFormPropertiesTask() GS2_OVERRIDE = default;
    };

    class DeleteFormTask : public detail::Gs2RestSessionTask<DeleteFormResult>
    {
    private:
        DeleteFormRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/mold/{moldName}/form/{index}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getIndex();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{index}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{index}", "null");
                }
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteFormTask(
            DeleteFormRequest request,
            Gs2RestSessionTask<DeleteFormResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteFormResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteFormTask() GS2_OVERRIDE = default;
    };

    class DeleteFormByUserIdTask : public detail::Gs2RestSessionTask<DeleteFormByUserIdResult>
    {
    private:
        DeleteFormByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/mold/{moldName}/form/{index}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMoldName();
                url.replace("{moldName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getIndex();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{index}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{index}", "null");
                }
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
        DeleteFormByUserIdTask(
            DeleteFormByUserIdRequest request,
            Gs2RestSessionTask<DeleteFormByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteFormByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteFormByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcquireActionToFormPropertiesByStampSheetTask : public detail::Gs2RestSessionTask<AcquireActionToFormPropertiesByStampSheetResult>
    {
    private:
        AcquireActionToFormPropertiesByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "formation";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/form/acquire";
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
        AcquireActionToFormPropertiesByStampSheetTask(
            AcquireActionToFormPropertiesByStampSheetRequest request,
            Gs2RestSessionTask<AcquireActionToFormPropertiesByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AcquireActionToFormPropertiesByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireActionToFormPropertiesByStampSheetTask() GS2_OVERRIDE = default;
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
        if (obj.getUpdateMoldScript())
        {
            jsonWriter.writePropertyName("updateMoldScript");
            write(jsonWriter, *obj.getUpdateMoldScript());
        }
        if (obj.getUpdateFormScript())
        {
            jsonWriter.writePropertyName("updateFormScript");
            write(jsonWriter, *obj.getUpdateFormScript());
        }
        if (obj.getLogSetting())
        {
            jsonWriter.writePropertyName("logSetting");
            write(jsonWriter, *obj.getLogSetting());
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

    static void write(detail::json::JsonWriter& jsonWriter, const FormModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getFormModelId())
        {
            jsonWriter.writePropertyName("formModelId");
            jsonWriter.writeCharArray(*obj.getFormModelId());
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
        if (obj.getSlots())
        {
            jsonWriter.writePropertyName("slots");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getSlots();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const FormModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getFormModelId())
        {
            jsonWriter.writePropertyName("formModelId");
            jsonWriter.writeCharArray(*obj.getFormModelId());
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
        if (obj.getSlots())
        {
            jsonWriter.writePropertyName("slots");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getSlots();
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
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const MoldModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMoldModelId())
        {
            jsonWriter.writePropertyName("moldModelId");
            jsonWriter.writeCharArray(*obj.getMoldModelId());
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
        if (obj.getFormModel())
        {
            jsonWriter.writePropertyName("formModel");
            write(jsonWriter, *obj.getFormModel());
        }
        if (obj.getInitialMaxCapacity())
        {
            jsonWriter.writePropertyName("initialMaxCapacity");
            jsonWriter.writeInt32(*obj.getInitialMaxCapacity());
        }
        if (obj.getMaxCapacity())
        {
            jsonWriter.writePropertyName("maxCapacity");
            jsonWriter.writeInt32(*obj.getMaxCapacity());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const MoldModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMoldModelId())
        {
            jsonWriter.writePropertyName("moldModelId");
            jsonWriter.writeCharArray(*obj.getMoldModelId());
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
        if (obj.getFormModelName())
        {
            jsonWriter.writePropertyName("formModelName");
            jsonWriter.writeCharArray(*obj.getFormModelName());
        }
        if (obj.getInitialMaxCapacity())
        {
            jsonWriter.writePropertyName("initialMaxCapacity");
            jsonWriter.writeInt32(*obj.getInitialMaxCapacity());
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentFormMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const Mold& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMoldId())
        {
            jsonWriter.writePropertyName("moldId");
            jsonWriter.writeCharArray(*obj.getMoldId());
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
        if (obj.getCapacity())
        {
            jsonWriter.writePropertyName("capacity");
            jsonWriter.writeInt32(*obj.getCapacity());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Form& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getFormId())
        {
            jsonWriter.writePropertyName("formId");
            jsonWriter.writeCharArray(*obj.getFormId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getIndex())
        {
            jsonWriter.writePropertyName("index");
            jsonWriter.writeInt32(*obj.getIndex());
        }
        if (obj.getSlots())
        {
            jsonWriter.writePropertyName("slots");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getSlots();
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
        if (obj.getUpdatedAt())
        {
            jsonWriter.writePropertyName("updatedAt");
            jsonWriter.writeInt64(*obj.getUpdatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Slot& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getPropertyId())
        {
            jsonWriter.writePropertyName("propertyId");
            jsonWriter.writeCharArray(*obj.getPropertyId());
        }
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
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

    static void write(detail::json::JsonWriter& jsonWriter, const SlotModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getPropertyRegex())
        {
            jsonWriter.writePropertyName("propertyRegex");
            jsonWriter.writeCharArray(*obj.getPropertyRegex());
        }
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const SlotWithSignature& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getPropertyType())
        {
            jsonWriter.writePropertyName("propertyType");
            jsonWriter.writeCharArray(*obj.getPropertyType());
        }
        if (obj.getBody())
        {
            jsonWriter.writePropertyName("body");
            jsonWriter.writeCharArray(*obj.getBody());
        }
        if (obj.getSignature())
        {
            jsonWriter.writePropertyName("signature");
            jsonWriter.writeCharArray(*obj.getSignature());
        }
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const AcquireActionConfig& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getConfig())
        {
            jsonWriter.writePropertyName("config");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getConfig();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Config& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getKey())
        {
            jsonWriter.writePropertyName("key");
            jsonWriter.writeCharArray(*obj.getKey());
        }
        if (obj.getValue())
        {
            jsonWriter.writePropertyName("value");
            jsonWriter.writeCharArray(*obj.getValue());
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

    static void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTriggerScriptId())
        {
            jsonWriter.writePropertyName("triggerScriptId");
            jsonWriter.writeCharArray(*obj.getTriggerScriptId());
        }
        if (obj.getDoneTriggerTargetType())
        {
            jsonWriter.writePropertyName("doneTriggerTargetType");
            jsonWriter.writeCharArray(*obj.getDoneTriggerTargetType());
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

    static void write(detail::json::JsonWriter& jsonWriter, const AcquireAction& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getRequest())
        {
            jsonWriter.writePropertyName("request");
            jsonWriter.writeCharArray(*obj.getRequest());
        }
        jsonWriter.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2FormationRestClient(Gs2RestSession& gs2RestSession) :
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
	 * ネームスペースを取得<br>
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
	 * フォームマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFormModelMasters(DescribeFormModelMastersRequest request, std::function<void(AsyncDescribeFormModelMastersResult)> callback)
    {
        DescribeFormModelMastersTask& task = *new DescribeFormModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createFormModelMaster(CreateFormModelMasterRequest request, std::function<void(AsyncCreateFormModelMasterResult)> callback)
    {
        CreateFormModelMasterTask& task = *new CreateFormModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFormModelMaster(GetFormModelMasterRequest request, std::function<void(AsyncGetFormModelMasterResult)> callback)
    {
        GetFormModelMasterTask& task = *new GetFormModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateFormModelMaster(UpdateFormModelMasterRequest request, std::function<void(AsyncUpdateFormModelMasterResult)> callback)
    {
        UpdateFormModelMasterTask& task = *new UpdateFormModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFormModelMaster(DeleteFormModelMasterRequest request, std::function<void(AsyncDeleteFormModelMasterResult)> callback)
    {
        DeleteFormModelMasterTask& task = *new DeleteFormModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームの保存領域の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMoldModels(DescribeMoldModelsRequest request, std::function<void(AsyncDescribeMoldModelsResult)> callback)
    {
        DescribeMoldModelsTask& task = *new DescribeMoldModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームの保存領域を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMoldModel(GetMoldModelRequest request, std::function<void(AsyncGetMoldModelResult)> callback)
    {
        GetMoldModelTask& task = *new GetMoldModelTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームの保存領域マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMoldModelMasters(DescribeMoldModelMastersRequest request, std::function<void(AsyncDescribeMoldModelMastersResult)> callback)
    {
        DescribeMoldModelMastersTask& task = *new DescribeMoldModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームの保存領域マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMoldModelMaster(CreateMoldModelMasterRequest request, std::function<void(AsyncCreateMoldModelMasterResult)> callback)
    {
        CreateMoldModelMasterTask& task = *new CreateMoldModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームの保存領域マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMoldModelMaster(GetMoldModelMasterRequest request, std::function<void(AsyncGetMoldModelMasterResult)> callback)
    {
        GetMoldModelMasterTask& task = *new GetMoldModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームの保存領域マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMoldModelMaster(UpdateMoldModelMasterRequest request, std::function<void(AsyncUpdateMoldModelMasterResult)> callback)
    {
        UpdateMoldModelMasterTask& task = *new UpdateMoldModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームの保存領域マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMoldModelMaster(DeleteMoldModelMasterRequest request, std::function<void(AsyncDeleteMoldModelMasterResult)> callback)
    {
        DeleteMoldModelMasterTask& task = *new DeleteMoldModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なフォーム設定のマスターデータをエクスポートします<br>
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
	 * 現在有効なフォーム設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentFormMaster(GetCurrentFormMasterRequest request, std::function<void(AsyncGetCurrentFormMasterResult)> callback)
    {
        GetCurrentFormMasterTask& task = *new GetCurrentFormMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なフォーム設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentFormMaster(UpdateCurrentFormMasterRequest request, std::function<void(AsyncUpdateCurrentFormMasterResult)> callback)
    {
        UpdateCurrentFormMasterTask& task = *new UpdateCurrentFormMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なフォーム設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentFormMasterFromGitHub(UpdateCurrentFormMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentFormMasterFromGitHubResult)> callback)
    {
        UpdateCurrentFormMasterFromGitHubTask& task = *new UpdateCurrentFormMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 保存したフォームの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMolds(DescribeMoldsRequest request, std::function<void(AsyncDescribeMoldsResult)> callback)
    {
        DescribeMoldsTask& task = *new DescribeMoldsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して保存したフォームの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMoldsByUserId(DescribeMoldsByUserIdRequest request, std::function<void(AsyncDescribeMoldsByUserIdResult)> callback)
    {
        DescribeMoldsByUserIdTask& task = *new DescribeMoldsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 保存したフォームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMold(GetMoldRequest request, std::function<void(AsyncGetMoldResult)> callback)
    {
        GetMoldTask& task = *new GetMoldTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して保存したフォームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMoldByUserId(GetMoldByUserIdRequest request, std::function<void(AsyncGetMoldByUserIdResult)> callback)
    {
        GetMoldByUserIdTask& task = *new GetMoldByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して保存したフォームのキャパシティを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMoldCapacityByUserId(SetMoldCapacityByUserIdRequest request, std::function<void(AsyncSetMoldCapacityByUserIdResult)> callback)
    {
        SetMoldCapacityByUserIdTask& task = *new SetMoldCapacityByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して保存したフォームのキャパシティを追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addMoldCapacityByUserId(AddMoldCapacityByUserIdRequest request, std::function<void(AsyncAddMoldCapacityByUserIdResult)> callback)
    {
        AddMoldCapacityByUserIdTask& task = *new AddMoldCapacityByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 保存したフォームを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMold(DeleteMoldRequest request, std::function<void(AsyncDeleteMoldResult)> callback)
    {
        DeleteMoldTask& task = *new DeleteMoldTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して保存したフォームを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMoldByUserId(DeleteMoldByUserIdRequest request, std::function<void(AsyncDeleteMoldByUserIdResult)> callback)
    {
        DeleteMoldByUserIdTask& task = *new DeleteMoldByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートでキャパシティサイズを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addCapacityByStampSheet(AddCapacityByStampSheetRequest request, std::function<void(AsyncAddCapacityByStampSheetResult)> callback)
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
    void setCapacityByStampSheet(SetCapacityByStampSheetRequest request, std::function<void(AsyncSetCapacityByStampSheetResult)> callback)
    {
        SetCapacityByStampSheetTask& task = *new SetCapacityByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeForms(DescribeFormsRequest request, std::function<void(AsyncDescribeFormsResult)> callback)
    {
        DescribeFormsTask& task = *new DescribeFormsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してフォームの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeFormsByUserId(DescribeFormsByUserIdRequest request, std::function<void(AsyncDescribeFormsByUserIdResult)> callback)
    {
        DescribeFormsByUserIdTask& task = *new DescribeFormsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getForm(GetFormRequest request, std::function<void(AsyncGetFormResult)> callback)
    {
        GetFormTask& task = *new GetFormTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してフォームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFormByUserId(GetFormByUserIdRequest request, std::function<void(AsyncGetFormByUserIdResult)> callback)
    {
        GetFormByUserIdTask& task = *new GetFormByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 署名付きフォームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFormWithSignature(GetFormWithSignatureRequest request, std::function<void(AsyncGetFormWithSignatureResult)> callback)
    {
        GetFormWithSignatureTask& task = *new GetFormWithSignatureTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して署名付きフォームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFormWithSignatureByUserId(GetFormWithSignatureByUserIdRequest request, std::function<void(AsyncGetFormWithSignatureByUserIdResult)> callback)
    {
        GetFormWithSignatureByUserIdTask& task = *new GetFormWithSignatureByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してフォームを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFormByUserId(SetFormByUserIdRequest request, std::function<void(AsyncSetFormByUserIdResult)> callback)
    {
        SetFormByUserIdTask& task = *new SetFormByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 署名付きスロットを使ってフォームを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFormWithSignature(SetFormWithSignatureRequest request, std::function<void(AsyncSetFormWithSignatureResult)> callback)
    {
        SetFormWithSignatureTask& task = *new SetFormWithSignatureTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 署名付きスロットを使ってフォームを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireActionsToFormProperties(AcquireActionsToFormPropertiesRequest request, std::function<void(AsyncAcquireActionsToFormPropertiesResult)> callback)
    {
        AcquireActionsToFormPropertiesTask& task = *new AcquireActionsToFormPropertiesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * フォームを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteForm(DeleteFormRequest request, std::function<void(AsyncDeleteFormResult)> callback)
    {
        DeleteFormTask& task = *new DeleteFormTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してフォームを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFormByUserId(DeleteFormByUserIdRequest request, std::function<void(AsyncDeleteFormByUserIdResult)> callback)
    {
        DeleteFormByUserIdTask& task = *new DeleteFormByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートでアイテムをインベントリに追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireActionToFormPropertiesByStampSheet(AcquireActionToFormPropertiesByStampSheetRequest request, std::function<void(AsyncAcquireActionToFormPropertiesByStampSheetResult)> callback)
    {
        AcquireActionToFormPropertiesByStampSheetTask& task = *new AcquireActionToFormPropertiesByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_FORMATION_GS2FORMATIONRESTCLIENT_HPP_