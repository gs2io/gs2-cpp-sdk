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

#ifndef GS2_LOG_GS2LOGRESTCLIENT_HPP_
#define GS2_LOG_GS2LOGRESTCLIENT_HPP_

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
#include "request/QueryAccessLogRequest.hpp"
#include "request/CountAccessLogRequest.hpp"
#include "request/QueryIssueStampSheetLogRequest.hpp"
#include "request/CountIssueStampSheetLogRequest.hpp"
#include "request/QueryExecuteStampSheetLogRequest.hpp"
#include "request/CountExecuteStampSheetLogRequest.hpp"
#include "request/QueryExecuteStampTaskLogRequest.hpp"
#include "request/CountExecuteStampTaskLogRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/QueryAccessLogResult.hpp"
#include "result/CountAccessLogResult.hpp"
#include "result/QueryIssueStampSheetLogResult.hpp"
#include "result/CountIssueStampSheetLogResult.hpp"
#include "result/QueryExecuteStampSheetLogResult.hpp"
#include "result/CountExecuteStampSheetLogResult.hpp"
#include "result/QueryExecuteStampTaskLogResult.hpp"
#include "result/CountExecuteStampTaskLogResult.hpp"
#include <cstring>

namespace gs2 { namespace log {

/**
 * GS2 Log API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LogRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
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
            return "log";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeCharArray(*m_Request.getType());
            }
            if (m_Request.getGcpCredentialJson())
            {
                jsonWriter.writePropertyName("gcpCredentialJson");
                jsonWriter.writeCharArray(*m_Request.getGcpCredentialJson());
            }
            if (m_Request.getBigQueryDatasetName())
            {
                jsonWriter.writePropertyName("bigQueryDatasetName");
                jsonWriter.writeCharArray(*m_Request.getBigQueryDatasetName());
            }
            if (m_Request.getLogExpireDays())
            {
                jsonWriter.writePropertyName("logExpireDays");
                jsonWriter.writeInt32(*m_Request.getLogExpireDays());
            }
            if (m_Request.getAwsRegion())
            {
                jsonWriter.writePropertyName("awsRegion");
                jsonWriter.writeCharArray(*m_Request.getAwsRegion());
            }
            if (m_Request.getAwsAccessKeyId())
            {
                jsonWriter.writePropertyName("awsAccessKeyId");
                jsonWriter.writeCharArray(*m_Request.getAwsAccessKeyId());
            }
            if (m_Request.getAwsSecretAccessKey())
            {
                jsonWriter.writePropertyName("awsSecretAccessKey");
                jsonWriter.writeCharArray(*m_Request.getAwsSecretAccessKey());
            }
            if (m_Request.getFirehoseStreamName())
            {
                jsonWriter.writePropertyName("firehoseStreamName");
                jsonWriter.writeCharArray(*m_Request.getFirehoseStreamName());
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
            return "log";
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
            return "log";
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
            return "log";
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
            if (m_Request.getType())
            {
                jsonWriter.writePropertyName("type");
                jsonWriter.writeCharArray(*m_Request.getType());
            }
            if (m_Request.getGcpCredentialJson())
            {
                jsonWriter.writePropertyName("gcpCredentialJson");
                jsonWriter.writeCharArray(*m_Request.getGcpCredentialJson());
            }
            if (m_Request.getBigQueryDatasetName())
            {
                jsonWriter.writePropertyName("bigQueryDatasetName");
                jsonWriter.writeCharArray(*m_Request.getBigQueryDatasetName());
            }
            if (m_Request.getLogExpireDays())
            {
                jsonWriter.writePropertyName("logExpireDays");
                jsonWriter.writeInt32(*m_Request.getLogExpireDays());
            }
            if (m_Request.getAwsRegion())
            {
                jsonWriter.writePropertyName("awsRegion");
                jsonWriter.writeCharArray(*m_Request.getAwsRegion());
            }
            if (m_Request.getAwsAccessKeyId())
            {
                jsonWriter.writePropertyName("awsAccessKeyId");
                jsonWriter.writeCharArray(*m_Request.getAwsAccessKeyId());
            }
            if (m_Request.getAwsSecretAccessKey())
            {
                jsonWriter.writePropertyName("awsSecretAccessKey");
                jsonWriter.writeCharArray(*m_Request.getAwsSecretAccessKey());
            }
            if (m_Request.getFirehoseStreamName())
            {
                jsonWriter.writePropertyName("firehoseStreamName");
                jsonWriter.writeCharArray(*m_Request.getFirehoseStreamName());
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
            return "log";
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

    class QueryAccessLogTask : public detail::Gs2RestSessionTask<QueryAccessLogResult>
    {
    private:
        QueryAccessLogRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/log/access";
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
            if (m_Request.getService())
            {
                url += joint;
                url += "service=";
                url += detail::StringVariable(*m_Request.getService(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getMethod())
            {
                url += joint;
                url += "method=";
                url += detail::StringVariable(*m_Request.getMethod(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        QueryAccessLogTask(
            QueryAccessLogRequest request,
            Gs2RestSessionTask<QueryAccessLogResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<QueryAccessLogResult>(callback),
            m_Request(std::move(request))
        {}

        ~QueryAccessLogTask() GS2_OVERRIDE = default;
    };

    class CountAccessLogTask : public detail::Gs2RestSessionTask<CountAccessLogResult>
    {
    private:
        CountAccessLogRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/log/access/count";
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
            if (m_Request.getService())
            {
                url += joint;
                url += "service=";
                url += detail::StringVariable(*m_Request.getService()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getMethod())
            {
                url += joint;
                url += "method=";
                url += detail::StringVariable(*m_Request.getMethod()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId()).c_str();
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
        CountAccessLogTask(
            CountAccessLogRequest request,
            Gs2RestSessionTask<CountAccessLogResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CountAccessLogResult>(callback),
            m_Request(std::move(request))
        {}

        ~CountAccessLogTask() GS2_OVERRIDE = default;
    };

    class QueryIssueStampSheetLogTask : public detail::Gs2RestSessionTask<QueryIssueStampSheetLogResult>
    {
    private:
        QueryIssueStampSheetLogRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/log/issue/stamp/sheet";
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
            if (m_Request.getService())
            {
                url += joint;
                url += "service=";
                url += detail::StringVariable(*m_Request.getService(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getMethod())
            {
                url += joint;
                url += "method=";
                url += detail::StringVariable(*m_Request.getMethod(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getAction())
            {
                url += joint;
                url += "action=";
                url += detail::StringVariable(*m_Request.getAction(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        QueryIssueStampSheetLogTask(
            QueryIssueStampSheetLogRequest request,
            Gs2RestSessionTask<QueryIssueStampSheetLogResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<QueryIssueStampSheetLogResult>(callback),
            m_Request(std::move(request))
        {}

        ~QueryIssueStampSheetLogTask() GS2_OVERRIDE = default;
    };

    class CountIssueStampSheetLogTask : public detail::Gs2RestSessionTask<CountIssueStampSheetLogResult>
    {
    private:
        CountIssueStampSheetLogRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/log/issue/stamp/sheet/count";
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
            if (m_Request.getService())
            {
                url += joint;
                url += "service=";
                url += detail::StringVariable(*m_Request.getService()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getMethod())
            {
                url += joint;
                url += "method=";
                url += detail::StringVariable(*m_Request.getMethod()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getAction())
            {
                url += joint;
                url += "action=";
                url += detail::StringVariable(*m_Request.getAction()).c_str();
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
        CountIssueStampSheetLogTask(
            CountIssueStampSheetLogRequest request,
            Gs2RestSessionTask<CountIssueStampSheetLogResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CountIssueStampSheetLogResult>(callback),
            m_Request(std::move(request))
        {}

        ~CountIssueStampSheetLogTask() GS2_OVERRIDE = default;
    };

    class QueryExecuteStampSheetLogTask : public detail::Gs2RestSessionTask<QueryExecuteStampSheetLogResult>
    {
    private:
        QueryExecuteStampSheetLogRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/log/execute/stamp/sheet";
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
            if (m_Request.getService())
            {
                url += joint;
                url += "service=";
                url += detail::StringVariable(*m_Request.getService(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getMethod())
            {
                url += joint;
                url += "method=";
                url += detail::StringVariable(*m_Request.getMethod(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getAction())
            {
                url += joint;
                url += "action=";
                url += detail::StringVariable(*m_Request.getAction(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        QueryExecuteStampSheetLogTask(
            QueryExecuteStampSheetLogRequest request,
            Gs2RestSessionTask<QueryExecuteStampSheetLogResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<QueryExecuteStampSheetLogResult>(callback),
            m_Request(std::move(request))
        {}

        ~QueryExecuteStampSheetLogTask() GS2_OVERRIDE = default;
    };

    class CountExecuteStampSheetLogTask : public detail::Gs2RestSessionTask<CountExecuteStampSheetLogResult>
    {
    private:
        CountExecuteStampSheetLogRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/log/execute/stamp/sheet/count";
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
            if (m_Request.getService())
            {
                url += joint;
                url += "service=";
                url += detail::StringVariable(*m_Request.getService()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getMethod())
            {
                url += joint;
                url += "method=";
                url += detail::StringVariable(*m_Request.getMethod()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getAction())
            {
                url += joint;
                url += "action=";
                url += detail::StringVariable(*m_Request.getAction()).c_str();
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
        CountExecuteStampSheetLogTask(
            CountExecuteStampSheetLogRequest request,
            Gs2RestSessionTask<CountExecuteStampSheetLogResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CountExecuteStampSheetLogResult>(callback),
            m_Request(std::move(request))
        {}

        ~CountExecuteStampSheetLogTask() GS2_OVERRIDE = default;
    };

    class QueryExecuteStampTaskLogTask : public detail::Gs2RestSessionTask<QueryExecuteStampTaskLogResult>
    {
    private:
        QueryExecuteStampTaskLogRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/log/execute/stamp/task";
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
            if (m_Request.getService())
            {
                url += joint;
                url += "service=";
                url += detail::StringVariable(*m_Request.getService(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getMethod())
            {
                url += joint;
                url += "method=";
                url += detail::StringVariable(*m_Request.getMethod(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getAction())
            {
                url += joint;
                url += "action=";
                url += detail::StringVariable(*m_Request.getAction(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        QueryExecuteStampTaskLogTask(
            QueryExecuteStampTaskLogRequest request,
            Gs2RestSessionTask<QueryExecuteStampTaskLogResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<QueryExecuteStampTaskLogResult>(callback),
            m_Request(std::move(request))
        {}

        ~QueryExecuteStampTaskLogTask() GS2_OVERRIDE = default;
    };

    class CountExecuteStampTaskLogTask : public detail::Gs2RestSessionTask<CountExecuteStampTaskLogResult>
    {
    private:
        CountExecuteStampTaskLogRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "log";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/log/execute/stamp/task/count";
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
            if (m_Request.getService())
            {
                url += joint;
                url += "service=";
                url += detail::StringVariable(*m_Request.getService()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getMethod())
            {
                url += joint;
                url += "method=";
                url += detail::StringVariable(*m_Request.getMethod()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getAction())
            {
                url += joint;
                url += "action=";
                url += detail::StringVariable(*m_Request.getAction()).c_str();
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
        CountExecuteStampTaskLogTask(
            CountExecuteStampTaskLogRequest request,
            Gs2RestSessionTask<CountExecuteStampTaskLogResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CountExecuteStampTaskLogResult>(callback),
            m_Request(std::move(request))
        {}

        ~CountExecuteStampTaskLogTask() GS2_OVERRIDE = default;
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
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeCharArray(*obj.getType());
        }
        if (obj.getGcpCredentialJson())
        {
            jsonWriter.writePropertyName("gcpCredentialJson");
            jsonWriter.writeCharArray(*obj.getGcpCredentialJson());
        }
        if (obj.getBigQueryDatasetName())
        {
            jsonWriter.writePropertyName("bigQueryDatasetName");
            jsonWriter.writeCharArray(*obj.getBigQueryDatasetName());
        }
        if (obj.getLogExpireDays())
        {
            jsonWriter.writePropertyName("logExpireDays");
            jsonWriter.writeInt32(*obj.getLogExpireDays());
        }
        if (obj.getAwsRegion())
        {
            jsonWriter.writePropertyName("awsRegion");
            jsonWriter.writeCharArray(*obj.getAwsRegion());
        }
        if (obj.getAwsAccessKeyId())
        {
            jsonWriter.writePropertyName("awsAccessKeyId");
            jsonWriter.writeCharArray(*obj.getAwsAccessKeyId());
        }
        if (obj.getAwsSecretAccessKey())
        {
            jsonWriter.writePropertyName("awsSecretAccessKey");
            jsonWriter.writeCharArray(*obj.getAwsSecretAccessKey());
        }
        if (obj.getFirehoseStreamName())
        {
            jsonWriter.writePropertyName("firehoseStreamName");
            jsonWriter.writeCharArray(*obj.getFirehoseStreamName());
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

    static void write(detail::json::JsonWriter& jsonWriter, const AccessLog& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTimestamp())
        {
            jsonWriter.writePropertyName("timestamp");
            jsonWriter.writeInt64(*obj.getTimestamp());
        }
        if (obj.getRequestId())
        {
            jsonWriter.writePropertyName("requestId");
            jsonWriter.writeCharArray(*obj.getRequestId());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getRequest())
        {
            jsonWriter.writePropertyName("request");
            jsonWriter.writeCharArray(*obj.getRequest());
        }
        if (obj.getResult())
        {
            jsonWriter.writePropertyName("result");
            jsonWriter.writeCharArray(*obj.getResult());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const AccessLogCount& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt64(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const IssueStampSheetLog& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTimestamp())
        {
            jsonWriter.writePropertyName("timestamp");
            jsonWriter.writeInt64(*obj.getTimestamp());
        }
        if (obj.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*obj.getTransactionId());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getArgs())
        {
            jsonWriter.writePropertyName("args");
            jsonWriter.writeCharArray(*obj.getArgs());
        }
        if (obj.getTasks())
        {
            jsonWriter.writePropertyName("tasks");
            jsonWriter.writeCharArray(*obj.getTasks());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const IssueStampSheetLogCount& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt64(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ExecuteStampSheetLog& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTimestamp())
        {
            jsonWriter.writePropertyName("timestamp");
            jsonWriter.writeInt64(*obj.getTimestamp());
        }
        if (obj.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*obj.getTransactionId());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getArgs())
        {
            jsonWriter.writePropertyName("args");
            jsonWriter.writeCharArray(*obj.getArgs());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ExecuteStampSheetLogCount& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt64(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ExecuteStampTaskLog& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTimestamp())
        {
            jsonWriter.writePropertyName("timestamp");
            jsonWriter.writeInt64(*obj.getTimestamp());
        }
        if (obj.getTaskId())
        {
            jsonWriter.writePropertyName("taskId");
            jsonWriter.writeCharArray(*obj.getTaskId());
        }
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getArgs())
        {
            jsonWriter.writePropertyName("args");
            jsonWriter.writeCharArray(*obj.getArgs());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ExecuteStampTaskLogCount& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getService())
        {
            jsonWriter.writePropertyName("service");
            jsonWriter.writeCharArray(*obj.getService());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getAction())
        {
            jsonWriter.writePropertyName("action");
            jsonWriter.writeCharArray(*obj.getAction());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt64(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2LogRestClient(Gs2RestSession& gs2RestSession) :
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
	 * アクセスログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryAccessLog(QueryAccessLogRequest request, std::function<void(AsyncQueryAccessLogResult)> callback)
    {
        QueryAccessLogTask& task = *new QueryAccessLogTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * アクセスログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countAccessLog(CountAccessLogRequest request, std::function<void(AsyncCountAccessLogResult)> callback)
    {
        CountAccessLogTask& task = *new CountAccessLogTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシート発行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryIssueStampSheetLog(QueryIssueStampSheetLogRequest request, std::function<void(AsyncQueryIssueStampSheetLogResult)> callback)
    {
        QueryIssueStampSheetLogTask& task = *new QueryIssueStampSheetLogTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシート発行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countIssueStampSheetLog(CountIssueStampSheetLogRequest request, std::function<void(AsyncCountIssueStampSheetLogResult)> callback)
    {
        CountIssueStampSheetLogTask& task = *new CountIssueStampSheetLogTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシート実行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryExecuteStampSheetLog(QueryExecuteStampSheetLogRequest request, std::function<void(AsyncQueryExecuteStampSheetLogResult)> callback)
    {
        QueryExecuteStampSheetLogTask& task = *new QueryExecuteStampSheetLogTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシート実行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countExecuteStampSheetLog(CountExecuteStampSheetLogRequest request, std::function<void(AsyncCountExecuteStampSheetLogResult)> callback)
    {
        CountExecuteStampSheetLogTask& task = *new CountExecuteStampSheetLogTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプタスク実行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryExecuteStampTaskLog(QueryExecuteStampTaskLogRequest request, std::function<void(AsyncQueryExecuteStampTaskLogResult)> callback)
    {
        QueryExecuteStampTaskLogTask& task = *new QueryExecuteStampTaskLogTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプタスク実行ログの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void countExecuteStampTaskLog(CountExecuteStampTaskLogRequest request, std::function<void(AsyncCountExecuteStampTaskLogResult)> callback)
    {
        CountExecuteStampTaskLogTask& task = *new CountExecuteStampTaskLogTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LOG_GS2LOGRESTCLIENT_HPP_