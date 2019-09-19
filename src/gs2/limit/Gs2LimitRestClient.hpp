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

#ifndef GS2_LIMIT_GS2LIMITRESTCLIENT_HPP_
#define GS2_LIMIT_GS2LIMITRESTCLIENT_HPP_

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
#include "request/DescribeCountersRequest.hpp"
#include "request/DescribeCountersByUserIdRequest.hpp"
#include "request/GetCounterRequest.hpp"
#include "request/GetCounterByUserIdRequest.hpp"
#include "request/CountUpByUserIdRequest.hpp"
#include "request/DeleteCounterByUserIdRequest.hpp"
#include "request/CountUpByStampTaskRequest.hpp"
#include "request/DeleteByStampSheetRequest.hpp"
#include "request/DescribeLimitModelMastersRequest.hpp"
#include "request/CreateLimitModelMasterRequest.hpp"
#include "request/GetLimitModelMasterRequest.hpp"
#include "request/UpdateLimitModelMasterRequest.hpp"
#include "request/DeleteLimitModelMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentLimitMasterRequest.hpp"
#include "request/UpdateCurrentLimitMasterRequest.hpp"
#include "request/UpdateCurrentLimitMasterFromGitHubRequest.hpp"
#include "request/DescribeLimitModelsRequest.hpp"
#include "request/GetLimitModelRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeCountersResult.hpp"
#include "result/DescribeCountersByUserIdResult.hpp"
#include "result/GetCounterResult.hpp"
#include "result/GetCounterByUserIdResult.hpp"
#include "result/CountUpByUserIdResult.hpp"
#include "result/DeleteCounterByUserIdResult.hpp"
#include "result/CountUpByStampTaskResult.hpp"
#include "result/DeleteByStampSheetResult.hpp"
#include "result/DescribeLimitModelMastersResult.hpp"
#include "result/CreateLimitModelMasterResult.hpp"
#include "result/GetLimitModelMasterResult.hpp"
#include "result/UpdateLimitModelMasterResult.hpp"
#include "result/DeleteLimitModelMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentLimitMasterResult.hpp"
#include "result/UpdateCurrentLimitMasterResult.hpp"
#include "result/UpdateCurrentLimitMasterFromGitHubResult.hpp"
#include "result/DescribeLimitModelsResult.hpp"
#include "result/GetLimitModelResult.hpp"
#include <cstring>

namespace gs2 { namespace limit {

/**
 * GS2 Limit API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LimitRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
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
            return "limit";
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
            return "limit";
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
            return "limit";
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
            return "limit";
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
            return "limit";
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

    class DescribeCountersTask : public detail::Gs2RestSessionTask<DescribeCountersResult>
    {
    private:
        DescribeCountersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/counter";
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
            if (m_Request.getLimitName())
            {
                url += joint;
                url += "limitName=";
                url += detail::StringVariable(*m_Request.getLimitName(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeCountersTask(
            DescribeCountersRequest request,
            Gs2RestSessionTask<DescribeCountersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCountersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCountersTask() GS2_OVERRIDE = default;
    };

    class DescribeCountersByUserIdTask : public detail::Gs2RestSessionTask<DescribeCountersByUserIdResult>
    {
    private:
        DescribeCountersByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/counter";
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
            if (m_Request.getLimitName())
            {
                url += joint;
                url += "limitName=";
                url += detail::StringVariable(*m_Request.getLimitName(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeCountersByUserIdTask(
            DescribeCountersByUserIdRequest request,
            Gs2RestSessionTask<DescribeCountersByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCountersByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCountersByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetCounterTask : public detail::Gs2RestSessionTask<GetCounterResult>
    {
    private:
        GetCounterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/counter/{limitName}/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLimitName();
                url.replace("{limitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCounterTask(
            GetCounterRequest request,
            Gs2RestSessionTask<GetCounterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCounterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterTask() GS2_OVERRIDE = default;
    };

    class GetCounterByUserIdTask : public detail::Gs2RestSessionTask<GetCounterByUserIdResult>
    {
    private:
        GetCounterByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/counter/{limitName}/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLimitName();
                url.replace("{limitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCounterByUserIdTask(
            GetCounterByUserIdRequest request,
            Gs2RestSessionTask<GetCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCounterByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class CountUpByUserIdTask : public detail::Gs2RestSessionTask<CountUpByUserIdResult>
    {
    private:
        CountUpByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/counter/{limitName}/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLimitName();
                url.replace("{limitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getCountUpValue())
            {
                jsonWriter.writePropertyName("countUpValue");
                jsonWriter.writeInt32(*m_Request.getCountUpValue());
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
        CountUpByUserIdTask(
            CountUpByUserIdRequest request,
            Gs2RestSessionTask<CountUpByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CountUpByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CountUpByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteCounterByUserIdTask : public detail::Gs2RestSessionTask<DeleteCounterByUserIdResult>
    {
    private:
        DeleteCounterByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/counter/{limitName}/{counterName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLimitName();
                url.replace("{limitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCounterName();
                url.replace("{counterName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteCounterByUserIdTask(
            DeleteCounterByUserIdRequest request,
            Gs2RestSessionTask<DeleteCounterByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteCounterByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteCounterByUserIdTask() GS2_OVERRIDE = default;
    };

    class CountUpByStampTaskTask : public detail::Gs2RestSessionTask<CountUpByStampTaskResult>
    {
    private:
        CountUpByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/counter/increase";
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
        CountUpByStampTaskTask(
            CountUpByStampTaskRequest request,
            Gs2RestSessionTask<CountUpByStampTaskResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CountUpByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~CountUpByStampTaskTask() GS2_OVERRIDE = default;
    };

    class DeleteByStampSheetTask : public detail::Gs2RestSessionTask<DeleteByStampSheetResult>
    {
    private:
        DeleteByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/counter/delete";
            {
                auto& value = m_Request.getStampSheet();
                url.replace("{stampSheet}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteByStampSheetTask(
            DeleteByStampSheetRequest request,
            Gs2RestSessionTask<DeleteByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeLimitModelMastersTask : public detail::Gs2RestSessionTask<DescribeLimitModelMastersResult>
    {
    private:
        DescribeLimitModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/limit";
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
        DescribeLimitModelMastersTask(
            DescribeLimitModelMastersRequest request,
            Gs2RestSessionTask<DescribeLimitModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeLimitModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeLimitModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateLimitModelMasterTask : public detail::Gs2RestSessionTask<CreateLimitModelMasterResult>
    {
    private:
        CreateLimitModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/limit";
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
            if (m_Request.getResetType())
            {
                jsonWriter.writePropertyName("resetType");
                jsonWriter.writeCharArray(*m_Request.getResetType());
            }
            if (m_Request.getResetDayOfMonth())
            {
                jsonWriter.writePropertyName("resetDayOfMonth");
                jsonWriter.writeInt32(*m_Request.getResetDayOfMonth());
            }
            if (m_Request.getResetDayOfWeek())
            {
                jsonWriter.writePropertyName("resetDayOfWeek");
                jsonWriter.writeCharArray(*m_Request.getResetDayOfWeek());
            }
            if (m_Request.getResetHour())
            {
                jsonWriter.writePropertyName("resetHour");
                jsonWriter.writeInt32(*m_Request.getResetHour());
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
        CreateLimitModelMasterTask(
            CreateLimitModelMasterRequest request,
            Gs2RestSessionTask<CreateLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateLimitModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetLimitModelMasterTask : public detail::Gs2RestSessionTask<GetLimitModelMasterResult>
    {
    private:
        GetLimitModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/limit/{limitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLimitName();
                url.replace("{limitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetLimitModelMasterTask(
            GetLimitModelMasterRequest request,
            Gs2RestSessionTask<GetLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetLimitModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateLimitModelMasterTask : public detail::Gs2RestSessionTask<UpdateLimitModelMasterResult>
    {
    private:
        UpdateLimitModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/limit/{limitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLimitName();
                url.replace("{limitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getResetType())
            {
                jsonWriter.writePropertyName("resetType");
                jsonWriter.writeCharArray(*m_Request.getResetType());
            }
            if (m_Request.getResetDayOfMonth())
            {
                jsonWriter.writePropertyName("resetDayOfMonth");
                jsonWriter.writeInt32(*m_Request.getResetDayOfMonth());
            }
            if (m_Request.getResetDayOfWeek())
            {
                jsonWriter.writePropertyName("resetDayOfWeek");
                jsonWriter.writeCharArray(*m_Request.getResetDayOfWeek());
            }
            if (m_Request.getResetHour())
            {
                jsonWriter.writePropertyName("resetHour");
                jsonWriter.writeInt32(*m_Request.getResetHour());
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
        UpdateLimitModelMasterTask(
            UpdateLimitModelMasterRequest request,
            Gs2RestSessionTask<UpdateLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateLimitModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteLimitModelMasterTask : public detail::Gs2RestSessionTask<DeleteLimitModelMasterResult>
    {
    private:
        DeleteLimitModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/limit/{limitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLimitName();
                url.replace("{limitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteLimitModelMasterTask(
            DeleteLimitModelMasterRequest request,
            Gs2RestSessionTask<DeleteLimitModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteLimitModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteLimitModelMasterTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
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

    class GetCurrentLimitMasterTask : public detail::Gs2RestSessionTask<GetCurrentLimitMasterResult>
    {
    private:
        GetCurrentLimitMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
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
        GetCurrentLimitMasterTask(
            GetCurrentLimitMasterRequest request,
            Gs2RestSessionTask<GetCurrentLimitMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentLimitMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentLimitMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentLimitMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentLimitMasterResult>
    {
    private:
        UpdateCurrentLimitMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
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
        UpdateCurrentLimitMasterTask(
            UpdateCurrentLimitMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentLimitMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentLimitMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentLimitMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentLimitMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentLimitMasterFromGitHubResult>
    {
    private:
        UpdateCurrentLimitMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
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
        UpdateCurrentLimitMasterFromGitHubTask(
            UpdateCurrentLimitMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentLimitMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentLimitMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentLimitMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeLimitModelsTask : public detail::Gs2RestSessionTask<DescribeLimitModelsResult>
    {
    private:
        DescribeLimitModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/limit";
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
        DescribeLimitModelsTask(
            DescribeLimitModelsRequest request,
            Gs2RestSessionTask<DescribeLimitModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeLimitModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeLimitModelsTask() GS2_OVERRIDE = default;
    };

    class GetLimitModelTask : public detail::Gs2RestSessionTask<GetLimitModelResult>
    {
    private:
        GetLimitModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "limit";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/limit/{limitName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLimitName();
                url.replace("{limitName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetLimitModelTask(
            GetLimitModelRequest request,
            Gs2RestSessionTask<GetLimitModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetLimitModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetLimitModelTask() GS2_OVERRIDE = default;
    };

private:
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

    static void write(detail::json::JsonWriter& jsonWriter, const Counter& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCounterId())
        {
            jsonWriter.writePropertyName("counterId");
            jsonWriter.writeCharArray(*obj.getCounterId());
        }
        if (obj.getLimitName())
        {
            jsonWriter.writePropertyName("limitName");
            jsonWriter.writeCharArray(*obj.getLimitName());
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
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt32(*obj.getCount());
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

    static void write(detail::json::JsonWriter& jsonWriter, const LimitModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getLimitModelId())
        {
            jsonWriter.writePropertyName("limitModelId");
            jsonWriter.writeCharArray(*obj.getLimitModelId());
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
        if (obj.getResetType())
        {
            jsonWriter.writePropertyName("resetType");
            jsonWriter.writeCharArray(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            jsonWriter.writePropertyName("resetDayOfMonth");
            jsonWriter.writeInt32(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            jsonWriter.writePropertyName("resetDayOfWeek");
            jsonWriter.writeCharArray(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            jsonWriter.writePropertyName("resetHour");
            jsonWriter.writeInt32(*obj.getResetHour());
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentLimitMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const LimitModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getLimitModelId())
        {
            jsonWriter.writePropertyName("limitModelId");
            jsonWriter.writeCharArray(*obj.getLimitModelId());
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
        if (obj.getResetType())
        {
            jsonWriter.writePropertyName("resetType");
            jsonWriter.writeCharArray(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            jsonWriter.writePropertyName("resetDayOfMonth");
            jsonWriter.writeInt32(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            jsonWriter.writePropertyName("resetDayOfWeek");
            jsonWriter.writeCharArray(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            jsonWriter.writePropertyName("resetHour");
            jsonWriter.writeInt32(*obj.getResetHour());
        }
        jsonWriter.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2LimitRestClient(Gs2RestSession& gs2RestSession) :
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
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCounters(DescribeCountersRequest request, std::function<void(AsyncDescribeCountersResult)> callback)
    {
        DescribeCountersTask& task = *new DescribeCountersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * カウンターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCountersByUserId(DescribeCountersByUserIdRequest request, std::function<void(AsyncDescribeCountersByUserIdResult)> callback)
    {
        DescribeCountersByUserIdTask& task = *new DescribeCountersByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * カウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounter(GetCounterRequest request, std::function<void(AsyncGetCounterResult)> callback)
    {
        GetCounterTask& task = *new GetCounterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してカウンターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCounterByUserId(GetCounterByUserIdRequest request, std::function<void(AsyncGetCounterByUserIdResult)> callback)
    {
        GetCounterByUserIdTask& task = *new GetCounterByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してカウントアップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countUpByUserId(CountUpByUserIdRequest request, std::function<void(AsyncCountUpByUserIdResult)> callback)
    {
        CountUpByUserIdTask& task = *new CountUpByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してカウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCounterByUserId(DeleteCounterByUserIdRequest request, std::function<void(AsyncDeleteCounterByUserIdResult)> callback)
    {
        DeleteCounterByUserIdTask& task = *new DeleteCounterByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートでカウントアップ<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countUpByStampTask(CountUpByStampTaskRequest request, std::function<void(AsyncCountUpByStampTaskResult)> callback)
    {
        CountUpByStampTaskTask& task = *new CountUpByStampTaskTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートでカウンターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteByStampSheet(DeleteByStampSheetRequest request, std::function<void(AsyncDeleteByStampSheetResult)> callback)
    {
        DeleteByStampSheetTask& task = *new DeleteByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLimitModelMasters(DescribeLimitModelMastersRequest request, std::function<void(AsyncDescribeLimitModelMastersResult)> callback)
    {
        DescribeLimitModelMastersTask& task = *new DescribeLimitModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLimitModelMaster(CreateLimitModelMasterRequest request, std::function<void(AsyncCreateLimitModelMasterResult)> callback)
    {
        CreateLimitModelMasterTask& task = *new CreateLimitModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimitModelMaster(GetLimitModelMasterRequest request, std::function<void(AsyncGetLimitModelMasterResult)> callback)
    {
        GetLimitModelMasterTask& task = *new GetLimitModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLimitModelMaster(UpdateLimitModelMasterRequest request, std::function<void(AsyncUpdateLimitModelMasterResult)> callback)
    {
        UpdateLimitModelMasterTask& task = *new UpdateLimitModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 回数制限の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLimitModelMaster(DeleteLimitModelMasterRequest request, std::function<void(AsyncDeleteLimitModelMasterResult)> callback)
    {
        DeleteLimitModelMasterTask& task = *new DeleteLimitModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な回数制限設定のマスターデータをエクスポートします<br>
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
	 * 現在有効な現在有効な回数制限設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLimitMaster(GetCurrentLimitMasterRequest request, std::function<void(AsyncGetCurrentLimitMasterResult)> callback)
    {
        GetCurrentLimitMasterTask& task = *new GetCurrentLimitMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な現在有効な回数制限設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLimitMaster(UpdateCurrentLimitMasterRequest request, std::function<void(AsyncUpdateCurrentLimitMasterResult)> callback)
    {
        UpdateCurrentLimitMasterTask& task = *new UpdateCurrentLimitMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な現在有効な回数制限設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLimitMasterFromGitHub(UpdateCurrentLimitMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentLimitMasterFromGitHubResult)> callback)
    {
        UpdateCurrentLimitMasterFromGitHubTask& task = *new UpdateCurrentLimitMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 回数制限の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLimitModels(DescribeLimitModelsRequest request, std::function<void(AsyncDescribeLimitModelsResult)> callback)
    {
        DescribeLimitModelsTask& task = *new DescribeLimitModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 回数制限の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLimitModel(GetLimitModelRequest request, std::function<void(AsyncGetLimitModelResult)> callback)
    {
        GetLimitModelTask& task = *new GetLimitModelTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LIMIT_GS2LIMITRESTCLIENT_HPP_