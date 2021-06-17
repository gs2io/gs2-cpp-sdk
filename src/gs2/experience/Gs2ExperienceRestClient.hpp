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

#ifndef GS2_EXPERIENCE_GS2EXPERIENCERESTCLIENT_HPP_
#define GS2_EXPERIENCE_GS2EXPERIENCERESTCLIENT_HPP_

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
#include "request/DescribeExperienceModelMastersRequest.hpp"
#include "request/CreateExperienceModelMasterRequest.hpp"
#include "request/GetExperienceModelMasterRequest.hpp"
#include "request/UpdateExperienceModelMasterRequest.hpp"
#include "request/DeleteExperienceModelMasterRequest.hpp"
#include "request/DescribeExperienceModelsRequest.hpp"
#include "request/GetExperienceModelRequest.hpp"
#include "request/DescribeThresholdMastersRequest.hpp"
#include "request/CreateThresholdMasterRequest.hpp"
#include "request/GetThresholdMasterRequest.hpp"
#include "request/UpdateThresholdMasterRequest.hpp"
#include "request/DeleteThresholdMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentExperienceMasterRequest.hpp"
#include "request/UpdateCurrentExperienceMasterRequest.hpp"
#include "request/UpdateCurrentExperienceMasterFromGitHubRequest.hpp"
#include "request/DescribeStatusesRequest.hpp"
#include "request/DescribeStatusesByUserIdRequest.hpp"
#include "request/GetStatusRequest.hpp"
#include "request/GetStatusByUserIdRequest.hpp"
#include "request/GetStatusWithSignatureRequest.hpp"
#include "request/AddExperienceByUserIdRequest.hpp"
#include "request/SetExperienceByUserIdRequest.hpp"
#include "request/AddRankCapByUserIdRequest.hpp"
#include "request/SetRankCapByUserIdRequest.hpp"
#include "request/DeleteStatusByUserIdRequest.hpp"
#include "request/AddExperienceByStampSheetRequest.hpp"
#include "request/AddRankCapByStampSheetRequest.hpp"
#include "request/SetRankCapByStampSheetRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeExperienceModelMastersResult.hpp"
#include "result/CreateExperienceModelMasterResult.hpp"
#include "result/GetExperienceModelMasterResult.hpp"
#include "result/UpdateExperienceModelMasterResult.hpp"
#include "result/DeleteExperienceModelMasterResult.hpp"
#include "result/DescribeExperienceModelsResult.hpp"
#include "result/GetExperienceModelResult.hpp"
#include "result/DescribeThresholdMastersResult.hpp"
#include "result/CreateThresholdMasterResult.hpp"
#include "result/GetThresholdMasterResult.hpp"
#include "result/UpdateThresholdMasterResult.hpp"
#include "result/DeleteThresholdMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentExperienceMasterResult.hpp"
#include "result/UpdateCurrentExperienceMasterResult.hpp"
#include "result/UpdateCurrentExperienceMasterFromGitHubResult.hpp"
#include "result/DescribeStatusesResult.hpp"
#include "result/DescribeStatusesByUserIdResult.hpp"
#include "result/GetStatusResult.hpp"
#include "result/GetStatusByUserIdResult.hpp"
#include "result/GetStatusWithSignatureResult.hpp"
#include "result/AddExperienceByUserIdResult.hpp"
#include "result/SetExperienceByUserIdResult.hpp"
#include "result/AddRankCapByUserIdResult.hpp"
#include "result/SetRankCapByUserIdResult.hpp"
#include "result/DeleteStatusByUserIdResult.hpp"
#include "result/AddExperienceByStampSheetResult.hpp"
#include "result/AddRankCapByStampSheetResult.hpp"
#include "result/SetRankCapByStampSheetResult.hpp"
#include <cstring>

namespace gs2 { namespace experience {

/**
 * GS2 Experience API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ExperienceRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
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
            return "experience";
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
            if (m_Request.getExperienceCapScriptId())
            {
                jsonWriter.writePropertyName("experienceCapScriptId");
                jsonWriter.writeCharArray(*m_Request.getExperienceCapScriptId());
            }
            if (m_Request.getChangeExperienceScript())
            {
                jsonWriter.writePropertyName("changeExperienceScript");
                write(jsonWriter, *m_Request.getChangeExperienceScript());
            }
            if (m_Request.getChangeRankScript())
            {
                jsonWriter.writePropertyName("changeRankScript");
                write(jsonWriter, *m_Request.getChangeRankScript());
            }
            if (m_Request.getChangeRankCapScript())
            {
                jsonWriter.writePropertyName("changeRankCapScript");
                write(jsonWriter, *m_Request.getChangeRankCapScript());
            }
            if (m_Request.getOverflowExperienceScript())
            {
                jsonWriter.writePropertyName("overflowExperienceScript");
                write(jsonWriter, *m_Request.getOverflowExperienceScript());
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
            return "experience";
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
            return "experience";
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
            return "experience";
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
            if (m_Request.getExperienceCapScriptId())
            {
                jsonWriter.writePropertyName("experienceCapScriptId");
                jsonWriter.writeCharArray(*m_Request.getExperienceCapScriptId());
            }
            if (m_Request.getChangeExperienceScript())
            {
                jsonWriter.writePropertyName("changeExperienceScript");
                write(jsonWriter, *m_Request.getChangeExperienceScript());
            }
            if (m_Request.getChangeRankScript())
            {
                jsonWriter.writePropertyName("changeRankScript");
                write(jsonWriter, *m_Request.getChangeRankScript());
            }
            if (m_Request.getChangeRankCapScript())
            {
                jsonWriter.writePropertyName("changeRankCapScript");
                write(jsonWriter, *m_Request.getChangeRankCapScript());
            }
            if (m_Request.getOverflowExperienceScript())
            {
                jsonWriter.writePropertyName("overflowExperienceScript");
                write(jsonWriter, *m_Request.getOverflowExperienceScript());
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
            return "experience";
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
                gs2HttpTask.setBody("{}");
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

    class DescribeExperienceModelMastersTask : public detail::Gs2RestSessionTask<DescribeExperienceModelMastersResult>
    {
    private:
        DescribeExperienceModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
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
        DescribeExperienceModelMastersTask(
            DescribeExperienceModelMastersRequest request,
            Gs2RestSessionTask<DescribeExperienceModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeExperienceModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeExperienceModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateExperienceModelMasterTask : public detail::Gs2RestSessionTask<CreateExperienceModelMasterResult>
    {
    private:
        CreateExperienceModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
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
            if (m_Request.getDefaultExperience())
            {
                jsonWriter.writePropertyName("defaultExperience");
                jsonWriter.writeInt64(*m_Request.getDefaultExperience());
            }
            if (m_Request.getDefaultRankCap())
            {
                jsonWriter.writePropertyName("defaultRankCap");
                jsonWriter.writeInt64(*m_Request.getDefaultRankCap());
            }
            if (m_Request.getMaxRankCap())
            {
                jsonWriter.writePropertyName("maxRankCap");
                jsonWriter.writeInt64(*m_Request.getMaxRankCap());
            }
            if (m_Request.getRankThresholdId())
            {
                jsonWriter.writePropertyName("rankThresholdId");
                jsonWriter.writeCharArray(*m_Request.getRankThresholdId());
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
        CreateExperienceModelMasterTask(
            CreateExperienceModelMasterRequest request,
            Gs2RestSessionTask<CreateExperienceModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateExperienceModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateExperienceModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetExperienceModelMasterTask : public detail::Gs2RestSessionTask<GetExperienceModelMasterResult>
    {
    private:
        GetExperienceModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{experienceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetExperienceModelMasterTask(
            GetExperienceModelMasterRequest request,
            Gs2RestSessionTask<GetExperienceModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetExperienceModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetExperienceModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateExperienceModelMasterTask : public detail::Gs2RestSessionTask<UpdateExperienceModelMasterResult>
    {
    private:
        UpdateExperienceModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{experienceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getDefaultExperience())
            {
                jsonWriter.writePropertyName("defaultExperience");
                jsonWriter.writeInt64(*m_Request.getDefaultExperience());
            }
            if (m_Request.getDefaultRankCap())
            {
                jsonWriter.writePropertyName("defaultRankCap");
                jsonWriter.writeInt64(*m_Request.getDefaultRankCap());
            }
            if (m_Request.getMaxRankCap())
            {
                jsonWriter.writePropertyName("maxRankCap");
                jsonWriter.writeInt64(*m_Request.getMaxRankCap());
            }
            if (m_Request.getRankThresholdId())
            {
                jsonWriter.writePropertyName("rankThresholdId");
                jsonWriter.writeCharArray(*m_Request.getRankThresholdId());
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
        UpdateExperienceModelMasterTask(
            UpdateExperienceModelMasterRequest request,
            Gs2RestSessionTask<UpdateExperienceModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateExperienceModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateExperienceModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteExperienceModelMasterTask : public detail::Gs2RestSessionTask<DeleteExperienceModelMasterResult>
    {
    private:
        DeleteExperienceModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{experienceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
                gs2HttpTask.setBody("{}");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteExperienceModelMasterTask(
            DeleteExperienceModelMasterRequest request,
            Gs2RestSessionTask<DeleteExperienceModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteExperienceModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteExperienceModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeExperienceModelsTask : public detail::Gs2RestSessionTask<DescribeExperienceModelsResult>
    {
    private:
        DescribeExperienceModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
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
        DescribeExperienceModelsTask(
            DescribeExperienceModelsRequest request,
            Gs2RestSessionTask<DescribeExperienceModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeExperienceModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeExperienceModelsTask() GS2_OVERRIDE = default;
    };

    class GetExperienceModelTask : public detail::Gs2RestSessionTask<GetExperienceModelResult>
    {
    private:
        GetExperienceModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/model/{experienceName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetExperienceModelTask(
            GetExperienceModelRequest request,
            Gs2RestSessionTask<GetExperienceModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetExperienceModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetExperienceModelTask() GS2_OVERRIDE = default;
    };

    class DescribeThresholdMastersTask : public detail::Gs2RestSessionTask<DescribeThresholdMastersResult>
    {
    private:
        DescribeThresholdMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/threshold";
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
        DescribeThresholdMastersTask(
            DescribeThresholdMastersRequest request,
            Gs2RestSessionTask<DescribeThresholdMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeThresholdMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeThresholdMastersTask() GS2_OVERRIDE = default;
    };

    class CreateThresholdMasterTask : public detail::Gs2RestSessionTask<CreateThresholdMasterResult>
    {
    private:
        CreateThresholdMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/threshold";
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
            if (m_Request.getValues())
            {
                jsonWriter.writePropertyName("values");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getValues();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeInt64(list[i]);
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
        CreateThresholdMasterTask(
            CreateThresholdMasterRequest request,
            Gs2RestSessionTask<CreateThresholdMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateThresholdMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateThresholdMasterTask() GS2_OVERRIDE = default;
    };

    class GetThresholdMasterTask : public detail::Gs2RestSessionTask<GetThresholdMasterResult>
    {
    private:
        GetThresholdMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/threshold/{thresholdName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getThresholdName();
                url.replace("{thresholdName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetThresholdMasterTask(
            GetThresholdMasterRequest request,
            Gs2RestSessionTask<GetThresholdMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetThresholdMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetThresholdMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateThresholdMasterTask : public detail::Gs2RestSessionTask<UpdateThresholdMasterResult>
    {
    private:
        UpdateThresholdMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/threshold/{thresholdName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getThresholdName();
                url.replace("{thresholdName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getValues())
            {
                jsonWriter.writePropertyName("values");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getValues();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeInt64(list[i]);
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
        UpdateThresholdMasterTask(
            UpdateThresholdMasterRequest request,
            Gs2RestSessionTask<UpdateThresholdMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateThresholdMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateThresholdMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteThresholdMasterTask : public detail::Gs2RestSessionTask<DeleteThresholdMasterResult>
    {
    private:
        DeleteThresholdMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/threshold/{thresholdName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getThresholdName();
                url.replace("{thresholdName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
                gs2HttpTask.setBody("{}");
            }
            gs2HttpTask.addHeaderEntry("Content-Type", "application/json");

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Delete;
        }

    public:
        DeleteThresholdMasterTask(
            DeleteThresholdMasterRequest request,
            Gs2RestSessionTask<DeleteThresholdMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteThresholdMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteThresholdMasterTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
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

    class GetCurrentExperienceMasterTask : public detail::Gs2RestSessionTask<GetCurrentExperienceMasterResult>
    {
    private:
        GetCurrentExperienceMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
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
        GetCurrentExperienceMasterTask(
            GetCurrentExperienceMasterRequest request,
            Gs2RestSessionTask<GetCurrentExperienceMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentExperienceMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentExperienceMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentExperienceMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentExperienceMasterResult>
    {
    private:
        UpdateCurrentExperienceMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
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
        UpdateCurrentExperienceMasterTask(
            UpdateCurrentExperienceMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentExperienceMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentExperienceMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentExperienceMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentExperienceMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentExperienceMasterFromGitHubResult>
    {
    private:
        UpdateCurrentExperienceMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
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
        UpdateCurrentExperienceMasterFromGitHubTask(
            UpdateCurrentExperienceMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentExperienceMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentExperienceMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentExperienceMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeStatusesTask : public detail::Gs2RestSessionTask<DescribeStatusesResult>
    {
    private:
        DescribeStatusesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/status";
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
            if (m_Request.getExperienceName())
            {
                url += joint;
                url += "experienceName=";
                url += detail::StringVariable(*m_Request.getExperienceName(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeStatusesTask(
            DescribeStatusesRequest request,
            Gs2RestSessionTask<DescribeStatusesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeStatusesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeStatusesTask() GS2_OVERRIDE = default;
    };

    class DescribeStatusesByUserIdTask : public detail::Gs2RestSessionTask<DescribeStatusesByUserIdResult>
    {
    private:
        DescribeStatusesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/status";
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
            if (m_Request.getExperienceName())
            {
                url += joint;
                url += "experienceName=";
                url += detail::StringVariable(*m_Request.getExperienceName(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeStatusesByUserIdTask(
            DescribeStatusesByUserIdRequest request,
            Gs2RestSessionTask<DescribeStatusesByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeStatusesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeStatusesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetStatusTask : public detail::Gs2RestSessionTask<GetStatusResult>
    {
    private:
        GetStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/status/model/{experienceName}/property/{propertyId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPropertyId();
                url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetStatusTask(
            GetStatusRequest request,
            Gs2RestSessionTask<GetStatusResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetStatusTask() GS2_OVERRIDE = default;
    };

    class GetStatusByUserIdTask : public detail::Gs2RestSessionTask<GetStatusByUserIdResult>
    {
    private:
        GetStatusByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPropertyId();
                url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetStatusByUserIdTask(
            GetStatusByUserIdRequest request,
            Gs2RestSessionTask<GetStatusByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetStatusByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetStatusByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetStatusWithSignatureTask : public detail::Gs2RestSessionTask<GetStatusWithSignatureResult>
    {
    private:
        GetStatusWithSignatureRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/status/model/{experienceName}/property/{propertyId}/signature";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPropertyId();
                url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetStatusWithSignatureTask(
            GetStatusWithSignatureRequest request,
            Gs2RestSessionTask<GetStatusWithSignatureResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetStatusWithSignatureResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetStatusWithSignatureTask() GS2_OVERRIDE = default;
    };

    class AddExperienceByUserIdTask : public detail::Gs2RestSessionTask<AddExperienceByUserIdResult>
    {
    private:
        AddExperienceByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPropertyId();
                url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getExperienceValue())
            {
                jsonWriter.writePropertyName("experienceValue");
                jsonWriter.writeInt64(*m_Request.getExperienceValue());
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
        AddExperienceByUserIdTask(
            AddExperienceByUserIdRequest request,
            Gs2RestSessionTask<AddExperienceByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AddExperienceByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddExperienceByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetExperienceByUserIdTask : public detail::Gs2RestSessionTask<SetExperienceByUserIdResult>
    {
    private:
        SetExperienceByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPropertyId();
                url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getExperienceValue())
            {
                jsonWriter.writePropertyName("experienceValue");
                jsonWriter.writeInt64(*m_Request.getExperienceValue());
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
        SetExperienceByUserIdTask(
            SetExperienceByUserIdRequest request,
            Gs2RestSessionTask<SetExperienceByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetExperienceByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetExperienceByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddRankCapByUserIdTask : public detail::Gs2RestSessionTask<AddRankCapByUserIdResult>
    {
    private:
        AddRankCapByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}/cap";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPropertyId();
                url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getRankCapValue())
            {
                jsonWriter.writePropertyName("rankCapValue");
                jsonWriter.writeInt64(*m_Request.getRankCapValue());
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
        AddRankCapByUserIdTask(
            AddRankCapByUserIdRequest request,
            Gs2RestSessionTask<AddRankCapByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AddRankCapByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddRankCapByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetRankCapByUserIdTask : public detail::Gs2RestSessionTask<SetRankCapByUserIdResult>
    {
    private:
        SetRankCapByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}/cap";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPropertyId();
                url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getRankCapValue())
            {
                jsonWriter.writePropertyName("rankCapValue");
                jsonWriter.writeInt64(*m_Request.getRankCapValue());
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
        SetRankCapByUserIdTask(
            SetRankCapByUserIdRequest request,
            Gs2RestSessionTask<SetRankCapByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetRankCapByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetRankCapByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteStatusByUserIdTask : public detail::Gs2RestSessionTask<DeleteStatusByUserIdResult>
    {
    private:
        DeleteStatusByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getExperienceName();
                url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPropertyId();
                url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
                gs2HttpTask.setBody("{}");
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
        DeleteStatusByUserIdTask(
            DeleteStatusByUserIdRequest request,
            Gs2RestSessionTask<DeleteStatusByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteStatusByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteStatusByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddExperienceByStampSheetTask : public detail::Gs2RestSessionTask<AddExperienceByStampSheetResult>
    {
    private:
        AddExperienceByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/experience/add";
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
        AddExperienceByStampSheetTask(
            AddExperienceByStampSheetRequest request,
            Gs2RestSessionTask<AddExperienceByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AddExperienceByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddExperienceByStampSheetTask() GS2_OVERRIDE = default;
    };

    class AddRankCapByStampSheetTask : public detail::Gs2RestSessionTask<AddRankCapByStampSheetResult>
    {
    private:
        AddRankCapByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/rankCap/add";
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
        AddRankCapByStampSheetTask(
            AddRankCapByStampSheetRequest request,
            Gs2RestSessionTask<AddRankCapByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AddRankCapByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddRankCapByStampSheetTask() GS2_OVERRIDE = default;
    };

    class SetRankCapByStampSheetTask : public detail::Gs2RestSessionTask<SetRankCapByStampSheetResult>
    {
    private:
        SetRankCapByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "experience";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/rankCap/set";
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
        SetRankCapByStampSheetTask(
            SetRankCapByStampSheetRequest request,
            Gs2RestSessionTask<SetRankCapByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetRankCapByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetRankCapByStampSheetTask() GS2_OVERRIDE = default;
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
        if (obj.getExperienceCapScriptId())
        {
            jsonWriter.writePropertyName("experienceCapScriptId");
            jsonWriter.writeCharArray(*obj.getExperienceCapScriptId());
        }
        if (obj.getChangeExperienceScript())
        {
            jsonWriter.writePropertyName("changeExperienceScript");
            write(jsonWriter, *obj.getChangeExperienceScript());
        }
        if (obj.getChangeRankScript())
        {
            jsonWriter.writePropertyName("changeRankScript");
            write(jsonWriter, *obj.getChangeRankScript());
        }
        if (obj.getChangeRankCapScript())
        {
            jsonWriter.writePropertyName("changeRankCapScript");
            write(jsonWriter, *obj.getChangeRankCapScript());
        }
        if (obj.getOverflowExperienceScript())
        {
            jsonWriter.writePropertyName("overflowExperienceScript");
            write(jsonWriter, *obj.getOverflowExperienceScript());
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

    static void write(detail::json::JsonWriter& jsonWriter, const ExperienceModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*obj.getExperienceModelId());
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
        if (obj.getDefaultExperience())
        {
            jsonWriter.writePropertyName("defaultExperience");
            jsonWriter.writeInt64(*obj.getDefaultExperience());
        }
        if (obj.getDefaultRankCap())
        {
            jsonWriter.writePropertyName("defaultRankCap");
            jsonWriter.writeInt64(*obj.getDefaultRankCap());
        }
        if (obj.getMaxRankCap())
        {
            jsonWriter.writePropertyName("maxRankCap");
            jsonWriter.writeInt64(*obj.getMaxRankCap());
        }
        if (obj.getRankThresholdId())
        {
            jsonWriter.writePropertyName("rankThresholdId");
            jsonWriter.writeCharArray(*obj.getRankThresholdId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const ExperienceModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*obj.getExperienceModelId());
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
        if (obj.getDefaultExperience())
        {
            jsonWriter.writePropertyName("defaultExperience");
            jsonWriter.writeInt64(*obj.getDefaultExperience());
        }
        if (obj.getDefaultRankCap())
        {
            jsonWriter.writePropertyName("defaultRankCap");
            jsonWriter.writeInt64(*obj.getDefaultRankCap());
        }
        if (obj.getMaxRankCap())
        {
            jsonWriter.writePropertyName("maxRankCap");
            jsonWriter.writeInt64(*obj.getMaxRankCap());
        }
        if (obj.getRankThreshold())
        {
            jsonWriter.writePropertyName("rankThreshold");
            write(jsonWriter, *obj.getRankThreshold());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ThresholdMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getThresholdId())
        {
            jsonWriter.writePropertyName("thresholdId");
            jsonWriter.writeCharArray(*obj.getThresholdId());
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
        if (obj.getValues())
        {
            jsonWriter.writePropertyName("values");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt64(list[i]);
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

    static void write(detail::json::JsonWriter& jsonWriter, const Threshold& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        if (obj.getValues())
        {
            jsonWriter.writePropertyName("values");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt64(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentExperienceMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const Status& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getStatusId())
        {
            jsonWriter.writePropertyName("statusId");
            jsonWriter.writeCharArray(*obj.getStatusId());
        }
        if (obj.getExperienceName())
        {
            jsonWriter.writePropertyName("experienceName");
            jsonWriter.writeCharArray(*obj.getExperienceName());
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
        if (obj.getExperienceValue())
        {
            jsonWriter.writePropertyName("experienceValue");
            jsonWriter.writeInt64(*obj.getExperienceValue());
        }
        if (obj.getRankValue())
        {
            jsonWriter.writePropertyName("rankValue");
            jsonWriter.writeInt64(*obj.getRankValue());
        }
        if (obj.getRankCapValue())
        {
            jsonWriter.writePropertyName("rankCapValue");
            jsonWriter.writeInt64(*obj.getRankCapValue());
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2ExperienceRestClient(Gs2RestSession& gs2RestSession) :
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
	 * 経験値の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeExperienceModelMasters(DescribeExperienceModelMastersRequest request, std::function<void(AsyncDescribeExperienceModelMastersResult)> callback)
    {
        DescribeExperienceModelMastersTask& task = *new DescribeExperienceModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 経験値の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createExperienceModelMaster(CreateExperienceModelMasterRequest request, std::function<void(AsyncCreateExperienceModelMasterResult)> callback)
    {
        CreateExperienceModelMasterTask& task = *new CreateExperienceModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 経験値の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperienceModelMaster(GetExperienceModelMasterRequest request, std::function<void(AsyncGetExperienceModelMasterResult)> callback)
    {
        GetExperienceModelMasterTask& task = *new GetExperienceModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 経験値の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateExperienceModelMaster(UpdateExperienceModelMasterRequest request, std::function<void(AsyncUpdateExperienceModelMasterResult)> callback)
    {
        UpdateExperienceModelMasterTask& task = *new UpdateExperienceModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 経験値の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteExperienceModelMaster(DeleteExperienceModelMasterRequest request, std::function<void(AsyncDeleteExperienceModelMasterResult)> callback)
    {
        DeleteExperienceModelMasterTask& task = *new DeleteExperienceModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 経験値・ランクアップ閾値モデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeExperienceModels(DescribeExperienceModelsRequest request, std::function<void(AsyncDescribeExperienceModelsResult)> callback)
    {
        DescribeExperienceModelsTask& task = *new DescribeExperienceModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 経験値・ランクアップ閾値モデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperienceModel(GetExperienceModelRequest request, std::function<void(AsyncGetExperienceModelResult)> callback)
    {
        GetExperienceModelTask& task = *new GetExperienceModelTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランクアップ閾値マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeThresholdMasters(DescribeThresholdMastersRequest request, std::function<void(AsyncDescribeThresholdMastersResult)> callback)
    {
        DescribeThresholdMastersTask& task = *new DescribeThresholdMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランクアップ閾値マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createThresholdMaster(CreateThresholdMasterRequest request, std::function<void(AsyncCreateThresholdMasterResult)> callback)
    {
        CreateThresholdMasterTask& task = *new CreateThresholdMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランクアップ閾値マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getThresholdMaster(GetThresholdMasterRequest request, std::function<void(AsyncGetThresholdMasterResult)> callback)
    {
        GetThresholdMasterTask& task = *new GetThresholdMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランクアップ閾値マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateThresholdMaster(UpdateThresholdMasterRequest request, std::function<void(AsyncUpdateThresholdMasterResult)> callback)
    {
        UpdateThresholdMasterTask& task = *new UpdateThresholdMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランクアップ閾値マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteThresholdMaster(DeleteThresholdMasterRequest request, std::function<void(AsyncDeleteThresholdMasterResult)> callback)
    {
        DeleteThresholdMasterTask& task = *new DeleteThresholdMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な経験値設定のマスターデータをエクスポートします<br>
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
	 * 現在有効な経験値設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentExperienceMaster(GetCurrentExperienceMasterRequest request, std::function<void(AsyncGetCurrentExperienceMasterResult)> callback)
    {
        GetCurrentExperienceMasterTask& task = *new GetCurrentExperienceMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な経験値設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentExperienceMaster(UpdateCurrentExperienceMasterRequest request, std::function<void(AsyncUpdateCurrentExperienceMasterResult)> callback)
    {
        UpdateCurrentExperienceMasterTask& task = *new UpdateCurrentExperienceMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な経験値設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentExperienceMasterFromGitHub(UpdateCurrentExperienceMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentExperienceMasterFromGitHubResult)> callback)
    {
        UpdateCurrentExperienceMasterFromGitHubTask& task = *new UpdateCurrentExperienceMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ステータスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatuses(DescribeStatusesRequest request, std::function<void(AsyncDescribeStatusesResult)> callback)
    {
        DescribeStatusesTask& task = *new DescribeStatusesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ステータスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatusesByUserId(DescribeStatusesByUserIdRequest request, std::function<void(AsyncDescribeStatusesByUserIdResult)> callback)
    {
        DescribeStatusesByUserIdTask& task = *new DescribeStatusesByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatus(GetStatusRequest request, std::function<void(AsyncGetStatusResult)> callback)
    {
        GetStatusTask& task = *new GetStatusTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusByUserId(GetStatusByUserIdRequest request, std::function<void(AsyncGetStatusByUserIdResult)> callback)
    {
        GetStatusByUserIdTask& task = *new GetStatusByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusWithSignature(GetStatusWithSignatureRequest request, std::function<void(AsyncGetStatusWithSignatureResult)> callback)
    {
        GetStatusWithSignatureTask& task = *new GetStatusWithSignatureTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 経験値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addExperienceByUserId(AddExperienceByUserIdRequest request, std::function<void(AsyncAddExperienceByUserIdResult)> callback)
    {
        AddExperienceByUserIdTask& task = *new AddExperienceByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 累計獲得経験値を設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setExperienceByUserId(SetExperienceByUserIdRequest request, std::function<void(AsyncSetExperienceByUserIdResult)> callback)
    {
        SetExperienceByUserIdTask& task = *new SetExperienceByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランクキャップを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addRankCapByUserId(AddRankCapByUserIdRequest request, std::function<void(AsyncAddRankCapByUserIdResult)> callback)
    {
        AddRankCapByUserIdTask& task = *new AddRankCapByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランクキャップを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRankCapByUserId(SetRankCapByUserIdRequest request, std::function<void(AsyncSetRankCapByUserIdResult)> callback)
    {
        SetRankCapByUserIdTask& task = *new SetRankCapByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ステータスを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStatusByUserId(DeleteStatusByUserIdRequest request, std::function<void(AsyncDeleteStatusByUserIdResult)> callback)
    {
        DeleteStatusByUserIdTask& task = *new DeleteStatusByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 経験値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addExperienceByStampSheet(AddExperienceByStampSheetRequest request, std::function<void(AsyncAddExperienceByStampSheetResult)> callback)
    {
        AddExperienceByStampSheetTask& task = *new AddExperienceByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランクキャップを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addRankCapByStampSheet(AddRankCapByStampSheetRequest request, std::function<void(AsyncAddRankCapByStampSheetResult)> callback)
    {
        AddRankCapByStampSheetTask& task = *new AddRankCapByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランクキャップを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRankCapByStampSheet(SetRankCapByStampSheetRequest request, std::function<void(AsyncSetRankCapByStampSheetResult)> callback)
    {
        SetRankCapByStampSheetTask& task = *new SetRankCapByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_EXPERIENCE_GS2EXPERIENCERESTCLIENT_HPP_