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

#ifndef GS2_GATEWAY_GS2GATEWAYRESTCLIENT_HPP_
#define GS2_GATEWAY_GS2GATEWAYRESTCLIENT_HPP_

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
#include "request/DescribeWebSocketSessionsRequest.hpp"
#include "request/DescribeWebSocketSessionsByUserIdRequest.hpp"
#include "request/SetUserIdRequest.hpp"
#include "request/SetUserIdByUserIdRequest.hpp"
#include "request/GetWebSocketSessionRequest.hpp"
#include "request/GetWebSocketSessionByConnectionIdRequest.hpp"
#include "request/SendNotificationRequest.hpp"
#include "request/SetFirebaseTokenRequest.hpp"
#include "request/SetFirebaseTokenByUserIdRequest.hpp"
#include "request/GetFirebaseTokenRequest.hpp"
#include "request/GetFirebaseTokenByUserIdRequest.hpp"
#include "request/DeleteFirebaseTokenRequest.hpp"
#include "request/DeleteFirebaseTokenByUserIdRequest.hpp"
#include "request/SendMobileNotificationByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeWebSocketSessionsResult.hpp"
#include "result/DescribeWebSocketSessionsByUserIdResult.hpp"
#include "result/SetUserIdResult.hpp"
#include "result/SetUserIdByUserIdResult.hpp"
#include "result/GetWebSocketSessionResult.hpp"
#include "result/GetWebSocketSessionByConnectionIdResult.hpp"
#include "result/SendNotificationResult.hpp"
#include "result/SetFirebaseTokenResult.hpp"
#include "result/SetFirebaseTokenByUserIdResult.hpp"
#include "result/GetFirebaseTokenResult.hpp"
#include "result/GetFirebaseTokenByUserIdResult.hpp"
#include "result/DeleteFirebaseTokenResult.hpp"
#include "result/DeleteFirebaseTokenByUserIdResult.hpp"
#include "result/SendMobileNotificationByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace gateway {

/**
 * GS2 Gateway API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2GatewayRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
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
            return "gateway";
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
            if (m_Request.getFirebaseSecret())
            {
                jsonWriter.writePropertyName("firebaseSecret");
                jsonWriter.writeCharArray(*m_Request.getFirebaseSecret());
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
            return "gateway";
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
            return "gateway";
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
            return "gateway";
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
            if (m_Request.getFirebaseSecret())
            {
                jsonWriter.writePropertyName("firebaseSecret");
                jsonWriter.writeCharArray(*m_Request.getFirebaseSecret());
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

    class DeleteNamespaceTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
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
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeWebSocketSessionsTask : public detail::Gs2RestSessionTask<DescribeWebSocketSessionsResult>
    {
    private:
        DescribeWebSocketSessionsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/session/user/me";
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
        DescribeWebSocketSessionsTask(
            DescribeWebSocketSessionsRequest request,
            Gs2RestSessionTask<DescribeWebSocketSessionsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeWebSocketSessionsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeWebSocketSessionsTask() GS2_OVERRIDE = default;
    };

    class DescribeWebSocketSessionsByUserIdTask : public detail::Gs2RestSessionTask<DescribeWebSocketSessionsByUserIdResult>
    {
    private:
        DescribeWebSocketSessionsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/session/user/{userId}";
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
        DescribeWebSocketSessionsByUserIdTask(
            DescribeWebSocketSessionsByUserIdRequest request,
            Gs2RestSessionTask<DescribeWebSocketSessionsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeWebSocketSessionsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeWebSocketSessionsByUserIdTask() GS2_OVERRIDE = default;
    };

    class SetUserIdTask : public detail::Gs2RestSessionTask<SetUserIdResult>
    {
    private:
        SetUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/session/user/me/user";
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
            if (m_Request.getAllowConcurrentAccess())
            {
                jsonWriter.writePropertyName("allowConcurrentAccess");
                jsonWriter.writeBool(*m_Request.getAllowConcurrentAccess());
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
        SetUserIdTask(
            SetUserIdRequest request,
            Gs2RestSessionTask<SetUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetUserIdTask() GS2_OVERRIDE = default;
    };

    class SetUserIdByUserIdTask : public detail::Gs2RestSessionTask<SetUserIdByUserIdResult>
    {
    private:
        SetUserIdByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/session/user/{userId}/user";
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
            if (m_Request.getAllowConcurrentAccess())
            {
                jsonWriter.writePropertyName("allowConcurrentAccess");
                jsonWriter.writeBool(*m_Request.getAllowConcurrentAccess());
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
        SetUserIdByUserIdTask(
            SetUserIdByUserIdRequest request,
            Gs2RestSessionTask<SetUserIdByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetUserIdByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetUserIdByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetWebSocketSessionTask : public detail::Gs2RestSessionTask<GetWebSocketSessionResult>
    {
    private:
        GetWebSocketSessionRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/session";
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
        GetWebSocketSessionTask(
            GetWebSocketSessionRequest request,
            Gs2RestSessionTask<GetWebSocketSessionResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetWebSocketSessionResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetWebSocketSessionTask() GS2_OVERRIDE = default;
    };

    class GetWebSocketSessionByConnectionIdTask : public detail::Gs2RestSessionTask<GetWebSocketSessionByConnectionIdResult>
    {
    private:
        GetWebSocketSessionByConnectionIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/session/{connectionId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getConnectionId();
                url.replace("{connectionId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetWebSocketSessionByConnectionIdTask(
            GetWebSocketSessionByConnectionIdRequest request,
            Gs2RestSessionTask<GetWebSocketSessionByConnectionIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetWebSocketSessionByConnectionIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetWebSocketSessionByConnectionIdTask() GS2_OVERRIDE = default;
    };

    class SendNotificationTask : public detail::Gs2RestSessionTask<SendNotificationResult>
    {
    private:
        SendNotificationRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/session/user/{userId}/notification";
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
            if (m_Request.getSubject())
            {
                jsonWriter.writePropertyName("subject");
                jsonWriter.writeCharArray(*m_Request.getSubject());
            }
            if (m_Request.getPayload())
            {
                jsonWriter.writePropertyName("payload");
                jsonWriter.writeCharArray(*m_Request.getPayload());
            }
            if (m_Request.getEnableTransferMobileNotification())
            {
                jsonWriter.writePropertyName("enableTransferMobileNotification");
                jsonWriter.writeBool(*m_Request.getEnableTransferMobileNotification());
            }
            if (m_Request.getSound())
            {
                jsonWriter.writePropertyName("sound");
                jsonWriter.writeCharArray(*m_Request.getSound());
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
        SendNotificationTask(
            SendNotificationRequest request,
            Gs2RestSessionTask<SendNotificationResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SendNotificationResult>(callback),
            m_Request(std::move(request))
        {}

        ~SendNotificationTask() GS2_OVERRIDE = default;
    };

    class SetFirebaseTokenTask : public detail::Gs2RestSessionTask<SetFirebaseTokenResult>
    {
    private:
        SetFirebaseTokenRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/firebase/token";
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
            if (m_Request.getToken())
            {
                jsonWriter.writePropertyName("token");
                jsonWriter.writeCharArray(*m_Request.getToken());
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
        SetFirebaseTokenTask(
            SetFirebaseTokenRequest request,
            Gs2RestSessionTask<SetFirebaseTokenResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetFirebaseTokenResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetFirebaseTokenTask() GS2_OVERRIDE = default;
    };

    class SetFirebaseTokenByUserIdTask : public detail::Gs2RestSessionTask<SetFirebaseTokenByUserIdResult>
    {
    private:
        SetFirebaseTokenByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/firebase/token";
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
            if (m_Request.getToken())
            {
                jsonWriter.writePropertyName("token");
                jsonWriter.writeCharArray(*m_Request.getToken());
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
        SetFirebaseTokenByUserIdTask(
            SetFirebaseTokenByUserIdRequest request,
            Gs2RestSessionTask<SetFirebaseTokenByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SetFirebaseTokenByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SetFirebaseTokenByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetFirebaseTokenTask : public detail::Gs2RestSessionTask<GetFirebaseTokenResult>
    {
    private:
        GetFirebaseTokenRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/firebase/token";
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
        GetFirebaseTokenTask(
            GetFirebaseTokenRequest request,
            Gs2RestSessionTask<GetFirebaseTokenResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFirebaseTokenResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFirebaseTokenTask() GS2_OVERRIDE = default;
    };

    class GetFirebaseTokenByUserIdTask : public detail::Gs2RestSessionTask<GetFirebaseTokenByUserIdResult>
    {
    private:
        GetFirebaseTokenByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/firebase/token";
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
        GetFirebaseTokenByUserIdTask(
            GetFirebaseTokenByUserIdRequest request,
            Gs2RestSessionTask<GetFirebaseTokenByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetFirebaseTokenByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetFirebaseTokenByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteFirebaseTokenTask : public detail::Gs2RestSessionTask<DeleteFirebaseTokenResult>
    {
    private:
        DeleteFirebaseTokenRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/firebase/token";
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
        DeleteFirebaseTokenTask(
            DeleteFirebaseTokenRequest request,
            Gs2RestSessionTask<DeleteFirebaseTokenResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteFirebaseTokenResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteFirebaseTokenTask() GS2_OVERRIDE = default;
    };

    class DeleteFirebaseTokenByUserIdTask : public detail::Gs2RestSessionTask<DeleteFirebaseTokenByUserIdResult>
    {
    private:
        DeleteFirebaseTokenByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/firebase/token";
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
        DeleteFirebaseTokenByUserIdTask(
            DeleteFirebaseTokenByUserIdRequest request,
            Gs2RestSessionTask<DeleteFirebaseTokenByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteFirebaseTokenByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteFirebaseTokenByUserIdTask() GS2_OVERRIDE = default;
    };

    class SendMobileNotificationByUserIdTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        SendMobileNotificationByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "gateway";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/firebase/token/notification";
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
            if (m_Request.getSubject())
            {
                jsonWriter.writePropertyName("subject");
                jsonWriter.writeCharArray(*m_Request.getSubject());
            }
            if (m_Request.getPayload())
            {
                jsonWriter.writePropertyName("payload");
                jsonWriter.writeCharArray(*m_Request.getPayload());
            }
            if (m_Request.getSound())
            {
                jsonWriter.writePropertyName("sound");
                jsonWriter.writeCharArray(*m_Request.getSound());
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
        SendMobileNotificationByUserIdTask(
            SendMobileNotificationByUserIdRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~SendMobileNotificationByUserIdTask() GS2_OVERRIDE = default;
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
        if (obj.getFirebaseSecret())
        {
            jsonWriter.writePropertyName("firebaseSecret");
            jsonWriter.writeCharArray(*obj.getFirebaseSecret());
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

    static void write(detail::json::JsonWriter& jsonWriter, const WebSocketSession& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getConnectionId())
        {
            jsonWriter.writePropertyName("connectionId");
            jsonWriter.writeCharArray(*obj.getConnectionId());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getNamespaceName())
        {
            jsonWriter.writePropertyName("namespaceName");
            jsonWriter.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const FirebaseToken& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getFirebaseTokenId())
        {
            jsonWriter.writePropertyName("firebaseTokenId");
            jsonWriter.writeCharArray(*obj.getFirebaseTokenId());
        }
        if (obj.getOwnerId())
        {
            jsonWriter.writePropertyName("ownerId");
            jsonWriter.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getToken())
        {
            jsonWriter.writePropertyName("token");
            jsonWriter.writeCharArray(*obj.getToken());
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2GatewayRestClient(Gs2RestSession& gs2RestSession) :
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
	 * Websocketセッションの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebSocketSessions(DescribeWebSocketSessionsRequest request, std::function<void(AsyncDescribeWebSocketSessionsResult)> callback)
    {
        DescribeWebSocketSessionsTask& task = *new DescribeWebSocketSessionsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してWebsocketセッションの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWebSocketSessionsByUserId(DescribeWebSocketSessionsByUserIdRequest request, std::function<void(AsyncDescribeWebSocketSessionsByUserIdResult)> callback)
    {
        DescribeWebSocketSessionsByUserIdTask& task = *new DescribeWebSocketSessionsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * WebsocketセッションにユーザIDを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setUserId(SetUserIdRequest request, std::function<void(AsyncSetUserIdResult)> callback)
    {
        SetUserIdTask& task = *new SetUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * WebsocketセッションにユーザIDを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setUserIdByUserId(SetUserIdByUserIdRequest request, std::function<void(AsyncSetUserIdByUserIdResult)> callback)
    {
        SetUserIdByUserIdTask& task = *new SetUserIdByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * Websocketセッションを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWebSocketSession(GetWebSocketSessionRequest request, std::function<void(AsyncGetWebSocketSessionResult)> callback)
    {
        GetWebSocketSessionTask& task = *new GetWebSocketSessionTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してWebsocketセッションを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWebSocketSessionByConnectionId(GetWebSocketSessionByConnectionIdRequest request, std::function<void(AsyncGetWebSocketSessionByConnectionIdResult)> callback)
    {
        GetWebSocketSessionByConnectionIdTask& task = *new GetWebSocketSessionByConnectionIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 通知を送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendNotification(SendNotificationRequest request, std::function<void(AsyncSendNotificationResult)> callback)
    {
        SendNotificationTask& task = *new SendNotificationTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * デバイストークンを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFirebaseToken(SetFirebaseTokenRequest request, std::function<void(AsyncSetFirebaseTokenResult)> callback)
    {
        SetFirebaseTokenTask& task = *new SetFirebaseTokenTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデバイストークンを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFirebaseTokenByUserId(SetFirebaseTokenByUserIdRequest request, std::function<void(AsyncSetFirebaseTokenByUserIdResult)> callback)
    {
        SetFirebaseTokenByUserIdTask& task = *new SetFirebaseTokenByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * Firebaseデバイストークンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFirebaseToken(GetFirebaseTokenRequest request, std::function<void(AsyncGetFirebaseTokenResult)> callback)
    {
        GetFirebaseTokenTask& task = *new GetFirebaseTokenTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してFirebaseデバイストークンを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getFirebaseTokenByUserId(GetFirebaseTokenByUserIdRequest request, std::function<void(AsyncGetFirebaseTokenByUserIdResult)> callback)
    {
        GetFirebaseTokenByUserIdTask& task = *new GetFirebaseTokenByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * Firebaseデバイストークンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFirebaseToken(DeleteFirebaseTokenRequest request, std::function<void(AsyncDeleteFirebaseTokenResult)> callback)
    {
        DeleteFirebaseTokenTask& task = *new DeleteFirebaseTokenTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してFirebaseデバイストークンを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteFirebaseTokenByUserId(DeleteFirebaseTokenByUserIdRequest request, std::function<void(AsyncDeleteFirebaseTokenByUserIdResult)> callback)
    {
        DeleteFirebaseTokenByUserIdTask& task = *new DeleteFirebaseTokenByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * モバイルプッシュ通知を送信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMobileNotificationByUserId(SendMobileNotificationByUserIdRequest request, std::function<void(AsyncSendMobileNotificationByUserIdResult)> callback)
    {
        SendMobileNotificationByUserIdTask& task = *new SendMobileNotificationByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_GATEWAY_GS2GATEWAYRESTCLIENT_HPP_