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

#ifndef GS2_EXCHANGE_GS2EXCHANGERESTCLIENT_HPP_
#define GS2_EXCHANGE_GS2EXCHANGERESTCLIENT_HPP_

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
#include "request/ExchangeRequest.hpp"
#include "request/ExchangeByUserIdRequest.hpp"
#include "request/ExchangeByStampSheetRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentRateMasterRequest.hpp"
#include "request/UpdateCurrentRateMasterRequest.hpp"
#include "request/UpdateCurrentRateMasterFromGitHubRequest.hpp"
#include "request/CreateAwaitByUserIdRequest.hpp"
#include "request/DescribeAwaitsRequest.hpp"
#include "request/DescribeAwaitsByUserIdRequest.hpp"
#include "request/GetAwaitRequest.hpp"
#include "request/GetAwaitByUserIdRequest.hpp"
#include "request/AcquireRequest.hpp"
#include "request/AcquireByUserIdRequest.hpp"
#include "request/AcquireForceByUserIdRequest.hpp"
#include "request/SkipRequest.hpp"
#include "request/SkipByUserIdRequest.hpp"
#include "request/DeleteAwaitRequest.hpp"
#include "request/DeleteAwaitByUserIdRequest.hpp"
#include "request/CreateAwaitByStampSheetRequest.hpp"
#include "request/DeleteAwaitByStampTaskRequest.hpp"
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
#include "result/ExchangeResult.hpp"
#include "result/ExchangeByUserIdResult.hpp"
#include "result/ExchangeByStampSheetResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentRateMasterResult.hpp"
#include "result/UpdateCurrentRateMasterResult.hpp"
#include "result/UpdateCurrentRateMasterFromGitHubResult.hpp"
#include "result/CreateAwaitByUserIdResult.hpp"
#include "result/DescribeAwaitsResult.hpp"
#include "result/DescribeAwaitsByUserIdResult.hpp"
#include "result/GetAwaitResult.hpp"
#include "result/GetAwaitByUserIdResult.hpp"
#include "result/AcquireResult.hpp"
#include "result/AcquireByUserIdResult.hpp"
#include "result/AcquireForceByUserIdResult.hpp"
#include "result/SkipResult.hpp"
#include "result/SkipByUserIdResult.hpp"
#include "result/DeleteAwaitResult.hpp"
#include "result/DeleteAwaitByUserIdResult.hpp"
#include "result/CreateAwaitByStampSheetResult.hpp"
#include "result/DeleteAwaitByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace exchange {

/**
 * GS2 Exchange API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ExchangeRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
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
            return "exchange";
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
            if (m_Request.getEnableAwaitExchange())
            {
                jsonWriter.writePropertyName("enableAwaitExchange");
                jsonWriter.writeBool(*m_Request.getEnableAwaitExchange());
            }
            if (m_Request.getEnableDirectExchange())
            {
                jsonWriter.writePropertyName("enableDirectExchange");
                jsonWriter.writeBool(*m_Request.getEnableDirectExchange());
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
            return "exchange";
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
            return "exchange";
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
            return "exchange";
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
            if (m_Request.getEnableAwaitExchange())
            {
                jsonWriter.writePropertyName("enableAwaitExchange");
                jsonWriter.writeBool(*m_Request.getEnableAwaitExchange());
            }
            if (m_Request.getEnableDirectExchange())
            {
                jsonWriter.writePropertyName("enableDirectExchange");
                jsonWriter.writeBool(*m_Request.getEnableDirectExchange());
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
            return "exchange";
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
            return "exchange";
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
            return "exchange";
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
            return "exchange";
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
            return "exchange";
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
            if (m_Request.getTimingType())
            {
                jsonWriter.writePropertyName("timingType");
                jsonWriter.writeCharArray(*m_Request.getTimingType());
            }
            if (m_Request.getLockTime())
            {
                jsonWriter.writePropertyName("lockTime");
                jsonWriter.writeInt32(*m_Request.getLockTime());
            }
            if (m_Request.getEnableSkip())
            {
                jsonWriter.writePropertyName("enableSkip");
                jsonWriter.writeBool(*m_Request.getEnableSkip());
            }
            if (m_Request.getSkipConsumeActions())
            {
                jsonWriter.writePropertyName("skipConsumeActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getSkipConsumeActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getAcquireActions())
            {
                jsonWriter.writePropertyName("acquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getConsumeActions())
            {
                jsonWriter.writePropertyName("consumeActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getConsumeActions();
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
            return "exchange";
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
            return "exchange";
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
            if (m_Request.getTimingType())
            {
                jsonWriter.writePropertyName("timingType");
                jsonWriter.writeCharArray(*m_Request.getTimingType());
            }
            if (m_Request.getLockTime())
            {
                jsonWriter.writePropertyName("lockTime");
                jsonWriter.writeInt32(*m_Request.getLockTime());
            }
            if (m_Request.getEnableSkip())
            {
                jsonWriter.writePropertyName("enableSkip");
                jsonWriter.writeBool(*m_Request.getEnableSkip());
            }
            if (m_Request.getSkipConsumeActions())
            {
                jsonWriter.writePropertyName("skipConsumeActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getSkipConsumeActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getAcquireActions())
            {
                jsonWriter.writePropertyName("acquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getConsumeActions())
            {
                jsonWriter.writePropertyName("consumeActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getConsumeActions();
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
            return "exchange";
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

    class ExchangeTask : public detail::Gs2RestSessionTask<ExchangeResult>
    {
    private:
        ExchangeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/exchange/{rateName}";
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
            if (m_Request.getCount())
            {
                jsonWriter.writePropertyName("count");
                jsonWriter.writeInt32(*m_Request.getCount());
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
        ExchangeTask(
            ExchangeRequest request,
            Gs2RestSessionTask<ExchangeResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ExchangeResult>(callback),
            m_Request(std::move(request))
        {}

        ~ExchangeTask() GS2_OVERRIDE = default;
    };

    class ExchangeByUserIdTask : public detail::Gs2RestSessionTask<ExchangeByUserIdResult>
    {
    private:
        ExchangeByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/exchange/{rateName}";
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
            if (m_Request.getCount())
            {
                jsonWriter.writePropertyName("count");
                jsonWriter.writeInt32(*m_Request.getCount());
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
        ExchangeByUserIdTask(
            ExchangeByUserIdRequest request,
            Gs2RestSessionTask<ExchangeByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ExchangeByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~ExchangeByUserIdTask() GS2_OVERRIDE = default;
    };

    class ExchangeByStampSheetTask : public detail::Gs2RestSessionTask<ExchangeByStampSheetResult>
    {
    private:
        ExchangeByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/exchange";
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
        ExchangeByStampSheetTask(
            ExchangeByStampSheetRequest request,
            Gs2RestSessionTask<ExchangeByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ExchangeByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~ExchangeByStampSheetTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
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
            return "exchange";
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
            return "exchange";
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
            return "exchange";
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

    class CreateAwaitByUserIdTask : public detail::Gs2RestSessionTask<CreateAwaitByUserIdResult>
    {
    private:
        CreateAwaitByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/exchange/{rateName}/await";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getCount())
            {
                jsonWriter.writePropertyName("count");
                jsonWriter.writeInt32(*m_Request.getCount());
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
        CreateAwaitByUserIdTask(
            CreateAwaitByUserIdRequest request,
            Gs2RestSessionTask<CreateAwaitByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateAwaitByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateAwaitByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeAwaitsTask : public detail::Gs2RestSessionTask<DescribeAwaitsResult>
    {
    private:
        DescribeAwaitsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/exchange/await";
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
            if (m_Request.getRateName())
            {
                url += joint;
                url += "rateName=";
                url += detail::StringVariable(*m_Request.getRateName(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeAwaitsTask(
            DescribeAwaitsRequest request,
            Gs2RestSessionTask<DescribeAwaitsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeAwaitsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeAwaitsTask() GS2_OVERRIDE = default;
    };

    class DescribeAwaitsByUserIdTask : public detail::Gs2RestSessionTask<DescribeAwaitsByUserIdResult>
    {
    private:
        DescribeAwaitsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/exchange/await";
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
            if (m_Request.getRateName())
            {
                url += joint;
                url += "rateName=";
                url += detail::StringVariable(*m_Request.getRateName(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeAwaitsByUserIdTask(
            DescribeAwaitsByUserIdRequest request,
            Gs2RestSessionTask<DescribeAwaitsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeAwaitsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeAwaitsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetAwaitTask : public detail::Gs2RestSessionTask<GetAwaitResult>
    {
    private:
        GetAwaitRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/exchange/{rateName}/await/{awaitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getAwaitName();
                url.replace("{awaitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetAwaitTask(
            GetAwaitRequest request,
            Gs2RestSessionTask<GetAwaitResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetAwaitResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetAwaitTask() GS2_OVERRIDE = default;
    };

    class GetAwaitByUserIdTask : public detail::Gs2RestSessionTask<GetAwaitByUserIdResult>
    {
    private:
        GetAwaitByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/exchange/{rateName}/await/{awaitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getAwaitName();
                url.replace("{awaitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetAwaitByUserIdTask(
            GetAwaitByUserIdRequest request,
            Gs2RestSessionTask<GetAwaitByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetAwaitByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetAwaitByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcquireTask : public detail::Gs2RestSessionTask<AcquireResult>
    {
    private:
        AcquireRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/exchange/{rateName}/await/{awaitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getAwaitName();
                url.replace("{awaitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        AcquireTask(
            AcquireRequest request,
            Gs2RestSessionTask<AcquireResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AcquireResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireTask() GS2_OVERRIDE = default;
    };

    class AcquireByUserIdTask : public detail::Gs2RestSessionTask<AcquireByUserIdResult>
    {
    private:
        AcquireByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/exchange/{rateName}/await/{awaitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getAwaitName();
                url.replace("{awaitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        AcquireByUserIdTask(
            AcquireByUserIdRequest request,
            Gs2RestSessionTask<AcquireByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AcquireByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcquireForceByUserIdTask : public detail::Gs2RestSessionTask<AcquireForceByUserIdResult>
    {
    private:
        AcquireForceByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/exchange/{rateName}/await/{awaitName}/force";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getAwaitName();
                url.replace("{awaitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        AcquireForceByUserIdTask(
            AcquireForceByUserIdRequest request,
            Gs2RestSessionTask<AcquireForceByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AcquireForceByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireForceByUserIdTask() GS2_OVERRIDE = default;
    };

    class SkipTask : public detail::Gs2RestSessionTask<SkipResult>
    {
    private:
        SkipRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/exchange/{rateName}/await/{awaitName}/skip";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getAwaitName();
                url.replace("{awaitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        SkipTask(
            SkipRequest request,
            Gs2RestSessionTask<SkipResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SkipResult>(callback),
            m_Request(std::move(request))
        {}

        ~SkipTask() GS2_OVERRIDE = default;
    };

    class SkipByUserIdTask : public detail::Gs2RestSessionTask<SkipByUserIdResult>
    {
    private:
        SkipByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/exchange/{rateName}/await/{awaitName}/skip";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getAwaitName();
                url.replace("{awaitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        SkipByUserIdTask(
            SkipByUserIdRequest request,
            Gs2RestSessionTask<SkipByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SkipByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SkipByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteAwaitTask : public detail::Gs2RestSessionTask<DeleteAwaitResult>
    {
    private:
        DeleteAwaitRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/exchange/{rateName}/await/{awaitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getAwaitName();
                url.replace("{awaitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteAwaitTask(
            DeleteAwaitRequest request,
            Gs2RestSessionTask<DeleteAwaitResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteAwaitResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAwaitTask() GS2_OVERRIDE = default;
    };

    class DeleteAwaitByUserIdTask : public detail::Gs2RestSessionTask<DeleteAwaitByUserIdResult>
    {
    private:
        DeleteAwaitByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/exchange/{rateName}/await/{awaitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getRateName();
                url.replace("{rateName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getAwaitName();
                url.replace("{awaitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteAwaitByUserIdTask(
            DeleteAwaitByUserIdRequest request,
            Gs2RestSessionTask<DeleteAwaitByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteAwaitByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAwaitByUserIdTask() GS2_OVERRIDE = default;
    };

    class CreateAwaitByStampSheetTask : public detail::Gs2RestSessionTask<CreateAwaitByStampSheetResult>
    {
    private:
        CreateAwaitByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/await/create";
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
        CreateAwaitByStampSheetTask(
            CreateAwaitByStampSheetRequest request,
            Gs2RestSessionTask<CreateAwaitByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateAwaitByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateAwaitByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DeleteAwaitByStampTaskTask : public detail::Gs2RestSessionTask<DeleteAwaitByStampTaskResult>
    {
    private:
        DeleteAwaitByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/await/delete";
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
        DeleteAwaitByStampTaskTask(
            DeleteAwaitByStampTaskRequest request,
            Gs2RestSessionTask<DeleteAwaitByStampTaskResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteAwaitByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAwaitByStampTaskTask() GS2_OVERRIDE = default;
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
        if (obj.getEnableDirectExchange())
        {
            jsonWriter.writePropertyName("enableDirectExchange");
            jsonWriter.writeBool(*obj.getEnableDirectExchange());
        }
        if (obj.getEnableAwaitExchange())
        {
            jsonWriter.writePropertyName("enableAwaitExchange");
            jsonWriter.writeBool(*obj.getEnableAwaitExchange());
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
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        if (obj.getConsumeActions())
        {
            jsonWriter.writePropertyName("consumeActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getTimingType())
        {
            jsonWriter.writePropertyName("timingType");
            jsonWriter.writeCharArray(*obj.getTimingType());
        }
        if (obj.getLockTime())
        {
            jsonWriter.writePropertyName("lockTime");
            jsonWriter.writeInt32(*obj.getLockTime());
        }
        if (obj.getEnableSkip())
        {
            jsonWriter.writePropertyName("enableSkip");
            jsonWriter.writeBool(*obj.getEnableSkip());
        }
        if (obj.getSkipConsumeActions())
        {
            jsonWriter.writePropertyName("skipConsumeActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getSkipConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getAcquireActions())
        {
            jsonWriter.writePropertyName("acquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAcquireActions();
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
        if (obj.getConsumeActions())
        {
            jsonWriter.writePropertyName("consumeActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getTimingType())
        {
            jsonWriter.writePropertyName("timingType");
            jsonWriter.writeCharArray(*obj.getTimingType());
        }
        if (obj.getLockTime())
        {
            jsonWriter.writePropertyName("lockTime");
            jsonWriter.writeInt32(*obj.getLockTime());
        }
        if (obj.getEnableSkip())
        {
            jsonWriter.writePropertyName("enableSkip");
            jsonWriter.writeBool(*obj.getEnableSkip());
        }
        if (obj.getSkipConsumeActions())
        {
            jsonWriter.writePropertyName("skipConsumeActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getSkipConsumeActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getAcquireActions())
        {
            jsonWriter.writePropertyName("acquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAcquireActions();
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

    static void write(detail::json::JsonWriter& jsonWriter, const Await& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getAwaitId())
        {
            jsonWriter.writePropertyName("awaitId");
            jsonWriter.writeCharArray(*obj.getAwaitId());
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
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt32(*obj.getCount());
        }
        if (obj.getExchangedAt())
        {
            jsonWriter.writePropertyName("exchangedAt");
            jsonWriter.writeInt64(*obj.getExchangedAt());
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

    static void write(detail::json::JsonWriter& jsonWriter, const ConsumeAction& obj)
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
    explicit Gs2ExchangeRestClient(Gs2RestSession& gs2RestSession) :
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
	 * 交換レートモデルの一覧を取得<br>
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
	 * 交換レートモデルを取得<br>
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
	 * 交換レートマスターの一覧を取得<br>
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
	 * 交換レートマスターを新規作成<br>
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
	 * 交換レートマスターを取得<br>
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
	 * 交換レートマスターを更新<br>
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
	 * 交換レートマスターを削除<br>
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
	 * 交換を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exchange(ExchangeRequest request, std::function<void(AsyncExchangeResult)> callback)
    {
        ExchangeTask& task = *new ExchangeTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して交換を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exchangeByUserId(ExchangeByUserIdRequest request, std::function<void(AsyncExchangeByUserIdResult)> callback)
    {
        ExchangeByUserIdTask& task = *new ExchangeByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートで交換を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exchangeByStampSheet(ExchangeByStampSheetRequest request, std::function<void(AsyncExchangeByStampSheetResult)> callback)
    {
        ExchangeByStampSheetTask& task = *new ExchangeByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な交換レート設定のマスターデータをエクスポートします<br>
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
	 * 現在有効な交換レート設定を取得します<br>
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
	 * 現在有効な交換レート設定を更新します<br>
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
	 * 現在有効な交換レート設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentRateMasterFromGitHub(UpdateCurrentRateMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentRateMasterFromGitHubResult)> callback)
    {
        UpdateCurrentRateMasterFromGitHubTask& task = *new UpdateCurrentRateMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機を作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createAwaitByUserId(CreateAwaitByUserIdRequest request, std::function<void(AsyncCreateAwaitByUserIdResult)> callback)
    {
        CreateAwaitByUserIdTask& task = *new CreateAwaitByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAwaits(DescribeAwaitsRequest request, std::function<void(AsyncDescribeAwaitsResult)> callback)
    {
        DescribeAwaitsTask& task = *new DescribeAwaitsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAwaitsByUserId(DescribeAwaitsByUserIdRequest request, std::function<void(AsyncDescribeAwaitsByUserIdResult)> callback)
    {
        DescribeAwaitsByUserIdTask& task = *new DescribeAwaitsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAwait(GetAwaitRequest request, std::function<void(AsyncGetAwaitResult)> callback)
    {
        GetAwaitTask& task = *new GetAwaitTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAwaitByUserId(GetAwaitByUserIdRequest request, std::function<void(AsyncGetAwaitByUserIdResult)> callback)
    {
        GetAwaitByUserIdTask& task = *new GetAwaitByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機の報酬を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquire(AcquireRequest request, std::function<void(AsyncAcquireResult)> callback)
    {
        AcquireTask& task = *new AcquireTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機の報酬を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireByUserId(AcquireByUserIdRequest request, std::function<void(AsyncAcquireByUserIdResult)> callback)
    {
        AcquireByUserIdTask& task = *new AcquireByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機の報酬を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void acquireForceByUserId(AcquireForceByUserIdRequest request, std::function<void(AsyncAcquireForceByUserIdResult)> callback)
    {
        AcquireForceByUserIdTask& task = *new AcquireForceByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機を対価を払ってスキップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void skip(SkipRequest request, std::function<void(AsyncSkipResult)> callback)
    {
        SkipTask& task = *new SkipTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機を対価を払ってスキップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void skipByUserId(SkipByUserIdRequest request, std::function<void(AsyncSkipByUserIdResult)> callback)
    {
        SkipByUserIdTask& task = *new SkipByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAwait(DeleteAwaitRequest request, std::function<void(AsyncDeleteAwaitResult)> callback)
    {
        DeleteAwaitTask& task = *new DeleteAwaitTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 交換待機を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAwaitByUserId(DeleteAwaitByUserIdRequest request, std::function<void(AsyncDeleteAwaitByUserIdResult)> callback)
    {
        DeleteAwaitByUserIdTask& task = *new DeleteAwaitByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートで交換待機 を作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createAwaitByStampSheet(CreateAwaitByStampSheetRequest request, std::function<void(AsyncCreateAwaitByStampSheetResult)> callback)
    {
        CreateAwaitByStampSheetTask& task = *new CreateAwaitByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプタスクで 交換待機 を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAwaitByStampTask(DeleteAwaitByStampTaskRequest request, std::function<void(AsyncDeleteAwaitByStampTaskResult)> callback)
    {
        DeleteAwaitByStampTaskTask& task = *new DeleteAwaitByStampTaskTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_EXCHANGE_GS2EXCHANGERESTCLIENT_HPP_