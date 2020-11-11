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

#ifndef GS2_ENHANCE_GS2ENHANCERESTCLIENT_HPP_
#define GS2_ENHANCE_GS2ENHANCERESTCLIENT_HPP_

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
#include "request/DescribeRateModelsRequest.hpp"
#include "request/GetRateModelRequest.hpp"
#include "request/DescribeRateModelMastersRequest.hpp"
#include "request/CreateRateModelMasterRequest.hpp"
#include "request/GetRateModelMasterRequest.hpp"
#include "request/UpdateRateModelMasterRequest.hpp"
#include "request/DeleteRateModelMasterRequest.hpp"
#include "request/DirectEnhanceRequest.hpp"
#include "request/DirectEnhanceByUserIdRequest.hpp"
#include "request/DirectEnhanceByStampSheetRequest.hpp"
#include "request/DescribeProgressesByUserIdRequest.hpp"
#include "request/CreateProgressByUserIdRequest.hpp"
#include "request/GetProgressRequest.hpp"
#include "request/GetProgressByUserIdRequest.hpp"
#include "request/StartRequest.hpp"
#include "request/StartByUserIdRequest.hpp"
#include "request/EndRequest.hpp"
#include "request/EndByUserIdRequest.hpp"
#include "request/DeleteProgressRequest.hpp"
#include "request/DeleteProgressByUserIdRequest.hpp"
#include "request/CreateProgressByStampSheetRequest.hpp"
#include "request/DeleteProgressByStampTaskRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentRateMasterRequest.hpp"
#include "request/UpdateCurrentRateMasterRequest.hpp"
#include "request/UpdateCurrentRateMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeRateModelsResult.hpp"
#include "result/GetRateModelResult.hpp"
#include "result/DescribeRateModelMastersResult.hpp"
#include "result/CreateRateModelMasterResult.hpp"
#include "result/GetRateModelMasterResult.hpp"
#include "result/UpdateRateModelMasterResult.hpp"
#include "result/DeleteRateModelMasterResult.hpp"
#include "result/DirectEnhanceResult.hpp"
#include "result/DirectEnhanceByUserIdResult.hpp"
#include "result/DirectEnhanceByStampSheetResult.hpp"
#include "result/DescribeProgressesByUserIdResult.hpp"
#include "result/CreateProgressByUserIdResult.hpp"
#include "result/GetProgressResult.hpp"
#include "result/GetProgressByUserIdResult.hpp"
#include "result/StartResult.hpp"
#include "result/StartByUserIdResult.hpp"
#include "result/EndResult.hpp"
#include "result/EndByUserIdResult.hpp"
#include "result/DeleteProgressResult.hpp"
#include "result/DeleteProgressByUserIdResult.hpp"
#include "result/CreateProgressByStampSheetResult.hpp"
#include "result/DeleteProgressByStampTaskResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentRateMasterResult.hpp"
#include "result/UpdateCurrentRateMasterResult.hpp"
#include "result/UpdateCurrentRateMasterFromGitHubResult.hpp"
#include <cstring>

namespace gs2 { namespace enhance {

/**
 * GS2 Enhance API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2EnhanceRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
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
            return "enhance";
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
            if (m_Request.getEnableDirectEnhance())
            {
                jsonWriter.writePropertyName("enableDirectEnhance");
                jsonWriter.writeBool(*m_Request.getEnableDirectEnhance());
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
            return "enhance";
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
            return "enhance";
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
            return "enhance";
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
            if (m_Request.getEnableDirectEnhance())
            {
                jsonWriter.writePropertyName("enableDirectEnhance");
                jsonWriter.writeBool(*m_Request.getEnableDirectEnhance());
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
            return "enhance";
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

    class DescribeRateModelsTask : public detail::Gs2RestSessionTask<DescribeRateModelsResult>
    {
    private:
        DescribeRateModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
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
        DescribeRateModelsTask(
            DescribeRateModelsRequest request,
            Gs2RestSessionTask<DescribeRateModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRateModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRateModelsTask() GS2_OVERRIDE = default;
    };

    class GetRateModelTask : public detail::Gs2RestSessionTask<GetRateModelResult>
    {
    private:
        GetRateModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/model/{rateName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetRateModelTask(
            GetRateModelRequest request,
            Gs2RestSessionTask<GetRateModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetRateModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRateModelTask() GS2_OVERRIDE = default;
    };

    class DescribeRateModelMastersTask : public detail::Gs2RestSessionTask<DescribeRateModelMastersResult>
    {
    private:
        DescribeRateModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
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
        DescribeRateModelMastersTask(
            DescribeRateModelMastersRequest request,
            Gs2RestSessionTask<DescribeRateModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRateModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRateModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateRateModelMasterTask : public detail::Gs2RestSessionTask<CreateRateModelMasterResult>
    {
    private:
        CreateRateModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
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
            if (m_Request.getTargetInventoryModelId())
            {
                jsonWriter.writePropertyName("targetInventoryModelId");
                jsonWriter.writeCharArray(*m_Request.getTargetInventoryModelId());
            }
            if (m_Request.getAcquireExperienceSuffix())
            {
                jsonWriter.writePropertyName("acquireExperienceSuffix");
                jsonWriter.writeCharArray(*m_Request.getAcquireExperienceSuffix());
            }
            if (m_Request.getMaterialInventoryModelId())
            {
                jsonWriter.writePropertyName("materialInventoryModelId");
                jsonWriter.writeCharArray(*m_Request.getMaterialInventoryModelId());
            }
            if (m_Request.getAcquireExperienceHierarchy())
            {
                jsonWriter.writePropertyName("acquireExperienceHierarchy");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAcquireExperienceHierarchy();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExperienceModelId())
            {
                jsonWriter.writePropertyName("experienceModelId");
                jsonWriter.writeCharArray(*m_Request.getExperienceModelId());
            }
            if (m_Request.getBonusRates())
            {
                jsonWriter.writePropertyName("bonusRates");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getBonusRates();
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
        CreateRateModelMasterTask(
            CreateRateModelMasterRequest request,
            Gs2RestSessionTask<CreateRateModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateRateModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateRateModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetRateModelMasterTask : public detail::Gs2RestSessionTask<GetRateModelMasterResult>
    {
    private:
        GetRateModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{rateName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetRateModelMasterTask(
            GetRateModelMasterRequest request,
            Gs2RestSessionTask<GetRateModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetRateModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRateModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateRateModelMasterTask : public detail::Gs2RestSessionTask<UpdateRateModelMasterResult>
    {
    private:
        UpdateRateModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{rateName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getTargetInventoryModelId())
            {
                jsonWriter.writePropertyName("targetInventoryModelId");
                jsonWriter.writeCharArray(*m_Request.getTargetInventoryModelId());
            }
            if (m_Request.getAcquireExperienceSuffix())
            {
                jsonWriter.writePropertyName("acquireExperienceSuffix");
                jsonWriter.writeCharArray(*m_Request.getAcquireExperienceSuffix());
            }
            if (m_Request.getMaterialInventoryModelId())
            {
                jsonWriter.writePropertyName("materialInventoryModelId");
                jsonWriter.writeCharArray(*m_Request.getMaterialInventoryModelId());
            }
            if (m_Request.getAcquireExperienceHierarchy())
            {
                jsonWriter.writePropertyName("acquireExperienceHierarchy");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAcquireExperienceHierarchy();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExperienceModelId())
            {
                jsonWriter.writePropertyName("experienceModelId");
                jsonWriter.writeCharArray(*m_Request.getExperienceModelId());
            }
            if (m_Request.getBonusRates())
            {
                jsonWriter.writePropertyName("bonusRates");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getBonusRates();
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
        UpdateRateModelMasterTask(
            UpdateRateModelMasterRequest request,
            Gs2RestSessionTask<UpdateRateModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateRateModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateRateModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteRateModelMasterTask : public detail::Gs2RestSessionTask<DeleteRateModelMasterResult>
    {
    private:
        DeleteRateModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{rateName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteRateModelMasterTask(
            DeleteRateModelMasterRequest request,
            Gs2RestSessionTask<DeleteRateModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteRateModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRateModelMasterTask() GS2_OVERRIDE = default;
    };

    class DirectEnhanceTask : public detail::Gs2RestSessionTask<DirectEnhanceResult>
    {
    private:
        DirectEnhanceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/enhance/{rateName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getTargetItemSetId())
            {
                jsonWriter.writePropertyName("targetItemSetId");
                jsonWriter.writeCharArray(*m_Request.getTargetItemSetId());
            }
            if (m_Request.getMaterials())
            {
                jsonWriter.writePropertyName("materials");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getMaterials();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
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
        DirectEnhanceTask(
            DirectEnhanceRequest request,
            Gs2RestSessionTask<DirectEnhanceResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DirectEnhanceResult>(callback),
            m_Request(std::move(request))
        {}

        ~DirectEnhanceTask() GS2_OVERRIDE = default;
    };

    class DirectEnhanceByUserIdTask : public detail::Gs2RestSessionTask<DirectEnhanceByUserIdResult>
    {
    private:
        DirectEnhanceByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/enhance/{rateName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getTargetItemSetId())
            {
                jsonWriter.writePropertyName("targetItemSetId");
                jsonWriter.writeCharArray(*m_Request.getTargetItemSetId());
            }
            if (m_Request.getMaterials())
            {
                jsonWriter.writePropertyName("materials");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getMaterials();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
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
        DirectEnhanceByUserIdTask(
            DirectEnhanceByUserIdRequest request,
            Gs2RestSessionTask<DirectEnhanceByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DirectEnhanceByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DirectEnhanceByUserIdTask() GS2_OVERRIDE = default;
    };

    class DirectEnhanceByStampSheetTask : public detail::Gs2RestSessionTask<DirectEnhanceByStampSheetResult>
    {
    private:
        DirectEnhanceByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/enhance/direct";
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
        DirectEnhanceByStampSheetTask(
            DirectEnhanceByStampSheetRequest request,
            Gs2RestSessionTask<DirectEnhanceByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DirectEnhanceByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~DirectEnhanceByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeProgressesByUserIdTask : public detail::Gs2RestSessionTask<DescribeProgressesByUserIdResult>
    {
    private:
        DescribeProgressesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/progress";
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
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeProgressesByUserIdTask(
            DescribeProgressesByUserIdRequest request,
            Gs2RestSessionTask<DescribeProgressesByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeProgressesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeProgressesByUserIdTask() GS2_OVERRIDE = default;
    };

    class CreateProgressByUserIdTask : public detail::Gs2RestSessionTask<CreateProgressByUserIdResult>
    {
    private:
        CreateProgressByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/progress";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getTargetItemSetId())
            {
                jsonWriter.writePropertyName("targetItemSetId");
                jsonWriter.writeCharArray(*m_Request.getTargetItemSetId());
            }
            if (m_Request.getMaterials())
            {
                jsonWriter.writePropertyName("materials");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getMaterials();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getForce())
            {
                jsonWriter.writePropertyName("force");
                jsonWriter.writeBool(*m_Request.getForce());
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
        CreateProgressByUserIdTask(
            CreateProgressByUserIdRequest request,
            Gs2RestSessionTask<CreateProgressByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateProgressByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateProgressByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetProgressTask : public detail::Gs2RestSessionTask<GetProgressResult>
    {
    private:
        GetProgressRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/progress";
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
        GetProgressTask(
            GetProgressRequest request,
            Gs2RestSessionTask<GetProgressResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetProgressResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProgressTask() GS2_OVERRIDE = default;
    };

    class GetProgressByUserIdTask : public detail::Gs2RestSessionTask<GetProgressByUserIdResult>
    {
    private:
        GetProgressByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/progress";
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
        GetProgressByUserIdTask(
            GetProgressByUserIdRequest request,
            Gs2RestSessionTask<GetProgressByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetProgressByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProgressByUserIdTask() GS2_OVERRIDE = default;
    };

    class StartTask : public detail::Gs2RestSessionTask<StartResult>
    {
    private:
        StartRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/progress/rate/{rateName}/start";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getTargetItemSetId())
            {
                jsonWriter.writePropertyName("targetItemSetId");
                jsonWriter.writeCharArray(*m_Request.getTargetItemSetId());
            }
            if (m_Request.getMaterials())
            {
                jsonWriter.writePropertyName("materials");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getMaterials();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getForce())
            {
                jsonWriter.writePropertyName("force");
                jsonWriter.writeBool(*m_Request.getForce());
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
        StartTask(
            StartRequest request,
            Gs2RestSessionTask<StartResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<StartResult>(callback),
            m_Request(std::move(request))
        {}

        ~StartTask() GS2_OVERRIDE = default;
    };

    class StartByUserIdTask : public detail::Gs2RestSessionTask<StartByUserIdResult>
    {
    private:
        StartByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/progress/rate/{rateName}/start";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getTargetItemSetId())
            {
                jsonWriter.writePropertyName("targetItemSetId");
                jsonWriter.writeCharArray(*m_Request.getTargetItemSetId());
            }
            if (m_Request.getMaterials())
            {
                jsonWriter.writePropertyName("materials");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getMaterials();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getForce())
            {
                jsonWriter.writePropertyName("force");
                jsonWriter.writeBool(*m_Request.getForce());
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
        StartByUserIdTask(
            StartByUserIdRequest request,
            Gs2RestSessionTask<StartByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<StartByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~StartByUserIdTask() GS2_OVERRIDE = default;
    };

    class EndTask : public detail::Gs2RestSessionTask<EndResult>
    {
    private:
        EndRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/progress/end";
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
        EndTask(
            EndRequest request,
            Gs2RestSessionTask<EndResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<EndResult>(callback),
            m_Request(std::move(request))
        {}

        ~EndTask() GS2_OVERRIDE = default;
    };

    class EndByUserIdTask : public detail::Gs2RestSessionTask<EndByUserIdResult>
    {
    private:
        EndByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/progress/end";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        EndByUserIdTask(
            EndByUserIdRequest request,
            Gs2RestSessionTask<EndByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<EndByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~EndByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteProgressTask : public detail::Gs2RestSessionTask<DeleteProgressResult>
    {
    private:
        DeleteProgressRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/progress";
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
        DeleteProgressTask(
            DeleteProgressRequest request,
            Gs2RestSessionTask<DeleteProgressResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteProgressResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProgressTask() GS2_OVERRIDE = default;
    };

    class DeleteProgressByUserIdTask : public detail::Gs2RestSessionTask<DeleteProgressByUserIdResult>
    {
    private:
        DeleteProgressByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/progress";
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
        DeleteProgressByUserIdTask(
            DeleteProgressByUserIdRequest request,
            Gs2RestSessionTask<DeleteProgressByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteProgressByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProgressByUserIdTask() GS2_OVERRIDE = default;
    };

    class CreateProgressByStampSheetTask : public detail::Gs2RestSessionTask<CreateProgressByStampSheetResult>
    {
    private:
        CreateProgressByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/progress/create";
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
        CreateProgressByStampSheetTask(
            CreateProgressByStampSheetRequest request,
            Gs2RestSessionTask<CreateProgressByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateProgressByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateProgressByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DeleteProgressByStampTaskTask : public detail::Gs2RestSessionTask<DeleteProgressByStampTaskResult>
    {
    private:
        DeleteProgressByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/progress/delete";
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
        DeleteProgressByStampTaskTask(
            DeleteProgressByStampTaskRequest request,
            Gs2RestSessionTask<DeleteProgressByStampTaskResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteProgressByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProgressByStampTaskTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
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

    class GetCurrentRateMasterTask : public detail::Gs2RestSessionTask<GetCurrentRateMasterResult>
    {
    private:
        GetCurrentRateMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
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
        GetCurrentRateMasterTask(
            GetCurrentRateMasterRequest request,
            Gs2RestSessionTask<GetCurrentRateMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentRateMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentRateMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentRateMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentRateMasterResult>
    {
    private:
        UpdateCurrentRateMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
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
        UpdateCurrentRateMasterTask(
            UpdateCurrentRateMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentRateMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentRateMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentRateMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentRateMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentRateMasterFromGitHubResult>
    {
    private:
        UpdateCurrentRateMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
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
        UpdateCurrentRateMasterFromGitHubTask(
            UpdateCurrentRateMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentRateMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentRateMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentRateMasterFromGitHubTask() GS2_OVERRIDE = default;
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
        if (obj.getEnableDirectEnhance())
        {
            jsonWriter.writePropertyName("enableDirectEnhance");
            jsonWriter.writeBool(*obj.getEnableDirectEnhance());
        }
        if (obj.getQueueNamespaceId())
        {
            jsonWriter.writePropertyName("queueNamespaceId");
            jsonWriter.writeCharArray(*obj.getQueueNamespaceId());
        }
        if (obj.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*obj.getKeyId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const RateModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRateModelId())
        {
            jsonWriter.writePropertyName("rateModelId");
            jsonWriter.writeCharArray(*obj.getRateModelId());
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
        if (obj.getTargetInventoryModelId())
        {
            jsonWriter.writePropertyName("targetInventoryModelId");
            jsonWriter.writeCharArray(*obj.getTargetInventoryModelId());
        }
        if (obj.getAcquireExperienceSuffix())
        {
            jsonWriter.writePropertyName("acquireExperienceSuffix");
            jsonWriter.writeCharArray(*obj.getAcquireExperienceSuffix());
        }
        if (obj.getMaterialInventoryModelId())
        {
            jsonWriter.writePropertyName("materialInventoryModelId");
            jsonWriter.writeCharArray(*obj.getMaterialInventoryModelId());
        }
        if (obj.getAcquireExperienceHierarchy())
        {
            jsonWriter.writePropertyName("acquireExperienceHierarchy");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAcquireExperienceHierarchy();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*obj.getExperienceModelId());
        }
        if (obj.getBonusRates())
        {
            jsonWriter.writePropertyName("bonusRates");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getBonusRates();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const RateModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRateModelId())
        {
            jsonWriter.writePropertyName("rateModelId");
            jsonWriter.writeCharArray(*obj.getRateModelId());
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
        if (obj.getTargetInventoryModelId())
        {
            jsonWriter.writePropertyName("targetInventoryModelId");
            jsonWriter.writeCharArray(*obj.getTargetInventoryModelId());
        }
        if (obj.getAcquireExperienceSuffix())
        {
            jsonWriter.writePropertyName("acquireExperienceSuffix");
            jsonWriter.writeCharArray(*obj.getAcquireExperienceSuffix());
        }
        if (obj.getMaterialInventoryModelId())
        {
            jsonWriter.writePropertyName("materialInventoryModelId");
            jsonWriter.writeCharArray(*obj.getMaterialInventoryModelId());
        }
        if (obj.getAcquireExperienceHierarchy())
        {
            jsonWriter.writePropertyName("acquireExperienceHierarchy");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAcquireExperienceHierarchy();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getExperienceModelId())
        {
            jsonWriter.writePropertyName("experienceModelId");
            jsonWriter.writeCharArray(*obj.getExperienceModelId());
        }
        if (obj.getBonusRates())
        {
            jsonWriter.writePropertyName("bonusRates");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getBonusRates();
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

    static void write(detail::json::JsonWriter& jsonWriter, const Progress& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getProgressId())
        {
            jsonWriter.writePropertyName("progressId");
            jsonWriter.writeCharArray(*obj.getProgressId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getRateName())
        {
            jsonWriter.writePropertyName("rateName");
            jsonWriter.writeCharArray(*obj.getRateName());
        }
        if (obj.getPropertyId())
        {
            jsonWriter.writePropertyName("propertyId");
            jsonWriter.writeCharArray(*obj.getPropertyId());
        }
        if (obj.getExperienceValue())
        {
            jsonWriter.writePropertyName("experienceValue");
            jsonWriter.writeInt32(*obj.getExperienceValue());
        }
        if (obj.getRate())
        {
            jsonWriter.writePropertyName("rate");
            jsonWriter.writeFloat(*obj.getRate());
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentRateMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const BonusRate& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRate())
        {
            jsonWriter.writePropertyName("rate");
            jsonWriter.writeFloat(*obj.getRate());
        }
        if (obj.getWeight())
        {
            jsonWriter.writePropertyName("weight");
            jsonWriter.writeInt32(*obj.getWeight());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Material& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMaterialItemSetId())
        {
            jsonWriter.writePropertyName("materialItemSetId");
            jsonWriter.writeCharArray(*obj.getMaterialItemSetId());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt32(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2EnhanceRestClient(Gs2RestSession& gs2RestSession) :
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
	 * 強化レートモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRateModels(DescribeRateModelsRequest request, std::function<void(AsyncDescribeRateModelsResult)> callback)
    {
        DescribeRateModelsTask& task = *new DescribeRateModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化レートモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRateModel(GetRateModelRequest request, std::function<void(AsyncGetRateModelResult)> callback)
    {
        GetRateModelTask& task = *new GetRateModelTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化レートマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRateModelMasters(DescribeRateModelMastersRequest request, std::function<void(AsyncDescribeRateModelMastersResult)> callback)
    {
        DescribeRateModelMastersTask& task = *new DescribeRateModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化レートマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRateModelMaster(CreateRateModelMasterRequest request, std::function<void(AsyncCreateRateModelMasterResult)> callback)
    {
        CreateRateModelMasterTask& task = *new CreateRateModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化レートマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRateModelMaster(GetRateModelMasterRequest request, std::function<void(AsyncGetRateModelMasterResult)> callback)
    {
        GetRateModelMasterTask& task = *new GetRateModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化レートマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRateModelMaster(UpdateRateModelMasterRequest request, std::function<void(AsyncUpdateRateModelMasterResult)> callback)
    {
        UpdateRateModelMasterTask& task = *new UpdateRateModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化レートマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRateModelMaster(DeleteRateModelMasterRequest request, std::function<void(AsyncDeleteRateModelMasterResult)> callback)
    {
        DeleteRateModelMasterTask& task = *new DeleteRateModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化を実行<br>
	 *   <br>
	 *   このAPIは実行速度を最適化する代わりにセキュリティ的に課題を抱えています。<br>
	 *   <br>
	 *   スタンプシートの発行と同時に「成功」「大成功」を表現するためのボーナスレートも応答していますが、<br>
	 *   それによって、スタンプシートを発行だけして実行しないことで、選別が可能となっています。<br>
	 *   選別を出来ないようにするには、Progress にある Start / End APIを利用することで、<br>
	 *   Start を呼び出したタイミングで強化素材を消費し、ボーナスレートを確定し<br>
	 *   End を呼び出したタイミングで経験値を得るためのスタンプシートを発行するようにすることができます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void directEnhance(DirectEnhanceRequest request, std::function<void(AsyncDirectEnhanceResult)> callback)
    {
        DirectEnhanceTask& task = *new DirectEnhanceTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して強化を実行<br>
	 *   <br>
	 *   このAPIは実行速度を最適化する代わりにセキュリティ的に課題を抱えています。<br>
	 *   <br>
	 *   スタンプシートの発行と同時に「成功」「大成功」を表現するためのボーナスレートも応答していますが、<br>
	 *   それによって、スタンプシートを発行だけして実行しないことで、選別が可能となっています。<br>
	 *   選別を出来ないようにするには、Progress にある Start / End APIを利用することで、<br>
	 *   Start を呼び出したタイミングで強化素材を消費し、ボーナスレートを確定し<br>
	 *   End を呼び出したタイミングで経験値を得るためのスタンプシートを発行するようにすることができます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void directEnhanceByUserId(DirectEnhanceByUserIdRequest request, std::function<void(AsyncDirectEnhanceByUserIdResult)> callback)
    {
        DirectEnhanceByUserIdTask& task = *new DirectEnhanceByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートで強化を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void directEnhanceByStampSheet(DirectEnhanceByStampSheetRequest request, std::function<void(AsyncDirectEnhanceByStampSheetResult)> callback)
    {
        DirectEnhanceByStampSheetTask& task = *new DirectEnhanceByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化実行の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProgressesByUserId(DescribeProgressesByUserIdRequest request, std::function<void(AsyncDescribeProgressesByUserIdResult)> callback)
    {
        DescribeProgressesByUserIdTask& task = *new DescribeProgressesByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して強化実行を作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProgressByUserId(CreateProgressByUserIdRequest request, std::function<void(AsyncCreateProgressByUserIdResult)> callback)
    {
        CreateProgressByUserIdTask& task = *new CreateProgressByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化実行を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProgress(GetProgressRequest request, std::function<void(AsyncGetProgressResult)> callback)
    {
        GetProgressTask& task = *new GetProgressTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して強化実行を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProgressByUserId(GetProgressByUserIdRequest request, std::function<void(AsyncGetProgressByUserIdResult)> callback)
    {
        GetProgressByUserIdTask& task = *new GetProgressByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化を開始<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void start(StartRequest request, std::function<void(AsyncStartResult)> callback)
    {
        StartTask& task = *new StartTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して強化を開始<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void startByUserId(StartByUserIdRequest request, std::function<void(AsyncStartByUserIdResult)> callback)
    {
        StartByUserIdTask& task = *new StartByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化を完了<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void end(EndRequest request, std::function<void(AsyncEndResult)> callback)
    {
        EndTask& task = *new EndTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して強化を完了<br>
	 *   <br>
	 *   開始時に受け取った強化において入手可能な報酬とその数量の"最大値"のうち、強化内で実際に入手した報酬を rewards で報告します。<br>
	 *   isComplete には強化をクリアできたかを報告します。強化に失敗した場合、rewards の値は無視して強化に設定された失敗した場合の報酬が付与されます。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void endByUserId(EndByUserIdRequest request, std::function<void(AsyncEndByUserIdResult)> callback)
    {
        EndByUserIdTask& task = *new EndByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 強化実行を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgress(DeleteProgressRequest request, std::function<void(AsyncDeleteProgressResult)> callback)
    {
        DeleteProgressTask& task = *new DeleteProgressTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して強化実行を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgressByUserId(DeleteProgressByUserIdRequest request, std::function<void(AsyncDeleteProgressByUserIdResult)> callback)
    {
        DeleteProgressByUserIdTask& task = *new DeleteProgressByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートで強化を開始<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createProgressByStampSheet(CreateProgressByStampSheetRequest request, std::function<void(AsyncCreateProgressByStampSheetResult)> callback)
    {
        CreateProgressByStampSheetTask& task = *new CreateProgressByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプタスクで 強化実行 を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteProgressByStampTask(DeleteProgressByStampTaskRequest request, std::function<void(AsyncDeleteProgressByStampTaskResult)> callback)
    {
        DeleteProgressByStampTaskTask& task = *new DeleteProgressByStampTaskTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な強化レート設定のマスターデータをエクスポートします<br>
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
	 * 現在有効な強化レート設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentRateMaster(GetCurrentRateMasterRequest request, std::function<void(AsyncGetCurrentRateMasterResult)> callback)
    {
        GetCurrentRateMasterTask& task = *new GetCurrentRateMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な強化レート設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentRateMaster(UpdateCurrentRateMasterRequest request, std::function<void(AsyncUpdateCurrentRateMasterResult)> callback)
    {
        UpdateCurrentRateMasterTask& task = *new UpdateCurrentRateMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な強化レート設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentRateMasterFromGitHub(UpdateCurrentRateMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentRateMasterFromGitHubResult)> callback)
    {
        UpdateCurrentRateMasterFromGitHubTask& task = *new UpdateCurrentRateMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_ENHANCE_GS2ENHANCERESTCLIENT_HPP_