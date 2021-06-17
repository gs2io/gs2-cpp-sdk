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

#ifndef GS2_INBOX_GS2INBOXRESTCLIENT_HPP_
#define GS2_INBOX_GS2INBOXRESTCLIENT_HPP_

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
#include "request/DescribeMessagesRequest.hpp"
#include "request/DescribeMessagesByUserIdRequest.hpp"
#include "request/SendMessageByUserIdRequest.hpp"
#include "request/GetMessageRequest.hpp"
#include "request/GetMessageByUserIdRequest.hpp"
#include "request/ReceiveGlobalMessageRequest.hpp"
#include "request/ReceiveGlobalMessageByUserIdRequest.hpp"
#include "request/OpenMessageRequest.hpp"
#include "request/OpenMessageByUserIdRequest.hpp"
#include "request/ReadMessageRequest.hpp"
#include "request/ReadMessageByUserIdRequest.hpp"
#include "request/DeleteMessageRequest.hpp"
#include "request/DeleteMessageByUserIdRequest.hpp"
#include "request/OpenByStampTaskRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentMessageMasterRequest.hpp"
#include "request/UpdateCurrentMessageMasterRequest.hpp"
#include "request/UpdateCurrentMessageMasterFromGitHubRequest.hpp"
#include "request/DescribeGlobalMessageMastersRequest.hpp"
#include "request/CreateGlobalMessageMasterRequest.hpp"
#include "request/GetGlobalMessageMasterRequest.hpp"
#include "request/UpdateGlobalMessageMasterRequest.hpp"
#include "request/DeleteGlobalMessageMasterRequest.hpp"
#include "request/DescribeGlobalMessagesRequest.hpp"
#include "request/GetGlobalMessageRequest.hpp"
#include "request/GetReceivedByUserIdRequest.hpp"
#include "request/UpdateReceivedByUserIdRequest.hpp"
#include "request/DeleteReceivedByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeMessagesResult.hpp"
#include "result/DescribeMessagesByUserIdResult.hpp"
#include "result/SendMessageByUserIdResult.hpp"
#include "result/GetMessageResult.hpp"
#include "result/GetMessageByUserIdResult.hpp"
#include "result/ReceiveGlobalMessageResult.hpp"
#include "result/ReceiveGlobalMessageByUserIdResult.hpp"
#include "result/OpenMessageResult.hpp"
#include "result/OpenMessageByUserIdResult.hpp"
#include "result/ReadMessageResult.hpp"
#include "result/ReadMessageByUserIdResult.hpp"
#include "result/DeleteMessageResult.hpp"
#include "result/DeleteMessageByUserIdResult.hpp"
#include "result/OpenByStampTaskResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentMessageMasterResult.hpp"
#include "result/UpdateCurrentMessageMasterResult.hpp"
#include "result/UpdateCurrentMessageMasterFromGitHubResult.hpp"
#include "result/DescribeGlobalMessageMastersResult.hpp"
#include "result/CreateGlobalMessageMasterResult.hpp"
#include "result/GetGlobalMessageMasterResult.hpp"
#include "result/UpdateGlobalMessageMasterResult.hpp"
#include "result/DeleteGlobalMessageMasterResult.hpp"
#include "result/DescribeGlobalMessagesResult.hpp"
#include "result/GetGlobalMessageResult.hpp"
#include "result/GetReceivedByUserIdResult.hpp"
#include "result/UpdateReceivedByUserIdResult.hpp"
#include "result/DeleteReceivedByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace inbox {

/**
 * GS2 Inbox API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2InboxRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
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
            return "inbox";
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
            if (m_Request.getIsAutomaticDeletingEnabled())
            {
                jsonWriter.writePropertyName("isAutomaticDeletingEnabled");
                jsonWriter.writeBool(*m_Request.getIsAutomaticDeletingEnabled());
            }
            if (m_Request.getReceiveMessageScript())
            {
                jsonWriter.writePropertyName("receiveMessageScript");
                write(jsonWriter, *m_Request.getReceiveMessageScript());
            }
            if (m_Request.getReadMessageScript())
            {
                jsonWriter.writePropertyName("readMessageScript");
                write(jsonWriter, *m_Request.getReadMessageScript());
            }
            if (m_Request.getDeleteMessageScript())
            {
                jsonWriter.writePropertyName("deleteMessageScript");
                write(jsonWriter, *m_Request.getDeleteMessageScript());
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
            if (m_Request.getReceiveNotification())
            {
                jsonWriter.writePropertyName("receiveNotification");
                write(jsonWriter, *m_Request.getReceiveNotification());
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
            return "inbox";
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
            return "inbox";
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
            return "inbox";
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
            if (m_Request.getIsAutomaticDeletingEnabled())
            {
                jsonWriter.writePropertyName("isAutomaticDeletingEnabled");
                jsonWriter.writeBool(*m_Request.getIsAutomaticDeletingEnabled());
            }
            if (m_Request.getReceiveMessageScript())
            {
                jsonWriter.writePropertyName("receiveMessageScript");
                write(jsonWriter, *m_Request.getReceiveMessageScript());
            }
            if (m_Request.getReadMessageScript())
            {
                jsonWriter.writePropertyName("readMessageScript");
                write(jsonWriter, *m_Request.getReadMessageScript());
            }
            if (m_Request.getDeleteMessageScript())
            {
                jsonWriter.writePropertyName("deleteMessageScript");
                write(jsonWriter, *m_Request.getDeleteMessageScript());
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
            if (m_Request.getReceiveNotification())
            {
                jsonWriter.writePropertyName("receiveNotification");
                write(jsonWriter, *m_Request.getReceiveNotification());
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
            return "inbox";
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

    class DescribeMessagesTask : public detail::Gs2RestSessionTask<DescribeMessagesResult>
    {
    private:
        DescribeMessagesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/message";
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
        DescribeMessagesTask(
            DescribeMessagesRequest request,
            Gs2RestSessionTask<DescribeMessagesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMessagesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMessagesTask() GS2_OVERRIDE = default;
    };

    class DescribeMessagesByUserIdTask : public detail::Gs2RestSessionTask<DescribeMessagesByUserIdResult>
    {
    private:
        DescribeMessagesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/message";
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
        DescribeMessagesByUserIdTask(
            DescribeMessagesByUserIdRequest request,
            Gs2RestSessionTask<DescribeMessagesByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeMessagesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeMessagesByUserIdTask() GS2_OVERRIDE = default;
    };

    class SendMessageByUserIdTask : public detail::Gs2RestSessionTask<SendMessageByUserIdResult>
    {
    private:
        SendMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/message";
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getReadAcquireActions())
            {
                jsonWriter.writePropertyName("readAcquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getReadAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExpiresAt())
            {
                jsonWriter.writePropertyName("expiresAt");
                jsonWriter.writeInt64(*m_Request.getExpiresAt());
            }
            if (m_Request.getExpiresTimeSpan())
            {
                jsonWriter.writePropertyName("expiresTimeSpan");
                write(jsonWriter, *m_Request.getExpiresTimeSpan());
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
        SendMessageByUserIdTask(
            SendMessageByUserIdRequest request,
            Gs2RestSessionTask<SendMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SendMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SendMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetMessageTask : public detail::Gs2RestSessionTask<GetMessageResult>
    {
    private:
        GetMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/{messageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMessageName();
                url.replace("{messageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMessageTask(
            GetMessageRequest request,
            Gs2RestSessionTask<GetMessageResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMessageTask() GS2_OVERRIDE = default;
    };

    class GetMessageByUserIdTask : public detail::Gs2RestSessionTask<GetMessageByUserIdResult>
    {
    private:
        GetMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/{messageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMessageName();
                url.replace("{messageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetMessageByUserIdTask(
            GetMessageByUserIdRequest request,
            Gs2RestSessionTask<GetMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReceiveGlobalMessageTask : public detail::Gs2RestSessionTask<ReceiveGlobalMessageResult>
    {
    private:
        ReceiveGlobalMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/{messageName}/globalMessage/receive";
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
        ReceiveGlobalMessageTask(
            ReceiveGlobalMessageRequest request,
            Gs2RestSessionTask<ReceiveGlobalMessageResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ReceiveGlobalMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReceiveGlobalMessageTask() GS2_OVERRIDE = default;
    };

    class ReceiveGlobalMessageByUserIdTask : public detail::Gs2RestSessionTask<ReceiveGlobalMessageByUserIdResult>
    {
    private:
        ReceiveGlobalMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/{messageName}/globalMessage/receive";
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
        ReceiveGlobalMessageByUserIdTask(
            ReceiveGlobalMessageByUserIdRequest request,
            Gs2RestSessionTask<ReceiveGlobalMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ReceiveGlobalMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReceiveGlobalMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class OpenMessageTask : public detail::Gs2RestSessionTask<OpenMessageResult>
    {
    private:
        OpenMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/{messageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMessageName();
                url.replace("{messageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        OpenMessageTask(
            OpenMessageRequest request,
            Gs2RestSessionTask<OpenMessageResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<OpenMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~OpenMessageTask() GS2_OVERRIDE = default;
    };

    class OpenMessageByUserIdTask : public detail::Gs2RestSessionTask<OpenMessageByUserIdResult>
    {
    private:
        OpenMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/{messageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMessageName();
                url.replace("{messageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        OpenMessageByUserIdTask(
            OpenMessageByUserIdRequest request,
            Gs2RestSessionTask<OpenMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<OpenMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~OpenMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class ReadMessageTask : public detail::Gs2RestSessionTask<ReadMessageResult>
    {
    private:
        ReadMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/{messageName}/read";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMessageName();
                url.replace("{messageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        ReadMessageTask(
            ReadMessageRequest request,
            Gs2RestSessionTask<ReadMessageResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ReadMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReadMessageTask() GS2_OVERRIDE = default;
    };

    class ReadMessageByUserIdTask : public detail::Gs2RestSessionTask<ReadMessageByUserIdResult>
    {
    private:
        ReadMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/{messageName}/read";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMessageName();
                url.replace("{messageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        ReadMessageByUserIdTask(
            ReadMessageByUserIdRequest request,
            Gs2RestSessionTask<ReadMessageByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<ReadMessageByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~ReadMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteMessageTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/{messageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMessageName();
                url.replace("{messageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteMessageTask(
            DeleteMessageRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMessageTask() GS2_OVERRIDE = default;
    };

    class DeleteMessageByUserIdTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteMessageByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/{messageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getMessageName();
                url.replace("{messageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteMessageByUserIdTask(
            DeleteMessageByUserIdRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteMessageByUserIdTask() GS2_OVERRIDE = default;
    };

    class OpenByStampTaskTask : public detail::Gs2RestSessionTask<OpenByStampTaskResult>
    {
    private:
        OpenByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/open";
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
        OpenByStampTaskTask(
            OpenByStampTaskRequest request,
            Gs2RestSessionTask<OpenByStampTaskResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<OpenByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~OpenByStampTaskTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
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

    class GetCurrentMessageMasterTask : public detail::Gs2RestSessionTask<GetCurrentMessageMasterResult>
    {
    private:
        GetCurrentMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
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
        GetCurrentMessageMasterTask(
            GetCurrentMessageMasterRequest request,
            Gs2RestSessionTask<GetCurrentMessageMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentMessageMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMessageMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentMessageMasterResult>
    {
    private:
        UpdateCurrentMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
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
        UpdateCurrentMessageMasterTask(
            UpdateCurrentMessageMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentMessageMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentMessageMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentMessageMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentMessageMasterFromGitHubResult>
    {
    private:
        UpdateCurrentMessageMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
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
        UpdateCurrentMessageMasterFromGitHubTask(
            UpdateCurrentMessageMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentMessageMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentMessageMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentMessageMasterFromGitHubTask() GS2_OVERRIDE = default;
    };

    class DescribeGlobalMessageMastersTask : public detail::Gs2RestSessionTask<DescribeGlobalMessageMastersResult>
    {
    private:
        DescribeGlobalMessageMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/globalMessage";
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
        DescribeGlobalMessageMastersTask(
            DescribeGlobalMessageMastersRequest request,
            Gs2RestSessionTask<DescribeGlobalMessageMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeGlobalMessageMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeGlobalMessageMastersTask() GS2_OVERRIDE = default;
    };

    class CreateGlobalMessageMasterTask : public detail::Gs2RestSessionTask<CreateGlobalMessageMasterResult>
    {
    private:
        CreateGlobalMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/globalMessage";
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getReadAcquireActions())
            {
                jsonWriter.writePropertyName("readAcquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getReadAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExpiresTimeSpan())
            {
                jsonWriter.writePropertyName("expiresTimeSpan");
                write(jsonWriter, *m_Request.getExpiresTimeSpan());
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

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CreateGlobalMessageMasterTask(
            CreateGlobalMessageMasterRequest request,
            Gs2RestSessionTask<CreateGlobalMessageMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateGlobalMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateGlobalMessageMasterTask() GS2_OVERRIDE = default;
    };

    class GetGlobalMessageMasterTask : public detail::Gs2RestSessionTask<GetGlobalMessageMasterResult>
    {
    private:
        GetGlobalMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/globalMessage/{globalMessageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGlobalMessageName();
                url.replace("{globalMessageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetGlobalMessageMasterTask(
            GetGlobalMessageMasterRequest request,
            Gs2RestSessionTask<GetGlobalMessageMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetGlobalMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetGlobalMessageMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateGlobalMessageMasterTask : public detail::Gs2RestSessionTask<UpdateGlobalMessageMasterResult>
    {
    private:
        UpdateGlobalMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/globalMessage/{globalMessageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGlobalMessageName();
                url.replace("{globalMessageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
            }
            if (m_Request.getReadAcquireActions())
            {
                jsonWriter.writePropertyName("readAcquireActions");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getReadAcquireActions();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getExpiresTimeSpan())
            {
                jsonWriter.writePropertyName("expiresTimeSpan");
                write(jsonWriter, *m_Request.getExpiresTimeSpan());
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

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdateGlobalMessageMasterTask(
            UpdateGlobalMessageMasterRequest request,
            Gs2RestSessionTask<UpdateGlobalMessageMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateGlobalMessageMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateGlobalMessageMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteGlobalMessageMasterTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteGlobalMessageMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/globalMessage/{globalMessageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGlobalMessageName();
                url.replace("{globalMessageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteGlobalMessageMasterTask(
            DeleteGlobalMessageMasterRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteGlobalMessageMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeGlobalMessagesTask : public detail::Gs2RestSessionTask<DescribeGlobalMessagesResult>
    {
    private:
        DescribeGlobalMessagesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/globalMessage";
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
        DescribeGlobalMessagesTask(
            DescribeGlobalMessagesRequest request,
            Gs2RestSessionTask<DescribeGlobalMessagesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeGlobalMessagesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeGlobalMessagesTask() GS2_OVERRIDE = default;
    };

    class GetGlobalMessageTask : public detail::Gs2RestSessionTask<GetGlobalMessageResult>
    {
    private:
        GetGlobalMessageRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/globalMessage/{globalMessageName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGlobalMessageName();
                url.replace("{globalMessageName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetGlobalMessageTask(
            GetGlobalMessageRequest request,
            Gs2RestSessionTask<GetGlobalMessageResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetGlobalMessageResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetGlobalMessageTask() GS2_OVERRIDE = default;
    };

    class GetReceivedByUserIdTask : public detail::Gs2RestSessionTask<GetReceivedByUserIdResult>
    {
    private:
        GetReceivedByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/received";
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
        GetReceivedByUserIdTask(
            GetReceivedByUserIdRequest request,
            Gs2RestSessionTask<GetReceivedByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetReceivedByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetReceivedByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateReceivedByUserIdTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        UpdateReceivedByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/received";
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
            if (m_Request.getReceivedGlobalMessageNames())
            {
                jsonWriter.writePropertyName("receivedGlobalMessageNames");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getReceivedGlobalMessageNames();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
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
        UpdateReceivedByUserIdTask(
            UpdateReceivedByUserIdRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateReceivedByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteReceivedByUserIdTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        DeleteReceivedByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "inbox";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/received";
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
        DeleteReceivedByUserIdTask(
            DeleteReceivedByUserIdRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteReceivedByUserIdTask() GS2_OVERRIDE = default;
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
        if (obj.getIsAutomaticDeletingEnabled())
        {
            jsonWriter.writePropertyName("isAutomaticDeletingEnabled");
            jsonWriter.writeBool(*obj.getIsAutomaticDeletingEnabled());
        }
        if (obj.getReceiveMessageScript())
        {
            jsonWriter.writePropertyName("receiveMessageScript");
            write(jsonWriter, *obj.getReceiveMessageScript());
        }
        if (obj.getReadMessageScript())
        {
            jsonWriter.writePropertyName("readMessageScript");
            write(jsonWriter, *obj.getReadMessageScript());
        }
        if (obj.getDeleteMessageScript())
        {
            jsonWriter.writePropertyName("deleteMessageScript");
            write(jsonWriter, *obj.getDeleteMessageScript());
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
        if (obj.getReceiveNotification())
        {
            jsonWriter.writePropertyName("receiveNotification");
            write(jsonWriter, *obj.getReceiveNotification());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Message& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getMessageId())
        {
            jsonWriter.writePropertyName("messageId");
            jsonWriter.writeCharArray(*obj.getMessageId());
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
        if (obj.getMetadata())
        {
            jsonWriter.writePropertyName("metadata");
            jsonWriter.writeCharArray(*obj.getMetadata());
        }
        if (obj.getIsRead())
        {
            jsonWriter.writePropertyName("isRead");
            jsonWriter.writeBool(*obj.getIsRead());
        }
        if (obj.getReadAcquireActions())
        {
            jsonWriter.writePropertyName("readAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReadAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getReceivedAt())
        {
            jsonWriter.writePropertyName("receivedAt");
            jsonWriter.writeInt64(*obj.getReceivedAt());
        }
        if (obj.getReadAt())
        {
            jsonWriter.writePropertyName("readAt");
            jsonWriter.writeInt64(*obj.getReadAt());
        }
        if (obj.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*obj.getExpiresAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentMessageMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const GlobalMessageMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGlobalMessageId())
        {
            jsonWriter.writePropertyName("globalMessageId");
            jsonWriter.writeCharArray(*obj.getGlobalMessageId());
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
        if (obj.getReadAcquireActions())
        {
            jsonWriter.writePropertyName("readAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReadAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getExpiresTimeSpan())
        {
            jsonWriter.writePropertyName("expiresTimeSpan");
            write(jsonWriter, *obj.getExpiresTimeSpan());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*obj.getExpiresAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const GlobalMessage& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGlobalMessageId())
        {
            jsonWriter.writePropertyName("globalMessageId");
            jsonWriter.writeCharArray(*obj.getGlobalMessageId());
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
        if (obj.getReadAcquireActions())
        {
            jsonWriter.writePropertyName("readAcquireActions");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReadAcquireActions();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getExpiresTimeSpan())
        {
            jsonWriter.writePropertyName("expiresTimeSpan");
            write(jsonWriter, *obj.getExpiresTimeSpan());
        }
        if (obj.getExpiresAt())
        {
            jsonWriter.writePropertyName("expiresAt");
            jsonWriter.writeInt64(*obj.getExpiresAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Received& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getReceivedId())
        {
            jsonWriter.writePropertyName("receivedId");
            jsonWriter.writeCharArray(*obj.getReceivedId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getReceivedGlobalMessageNames())
        {
            jsonWriter.writePropertyName("receivedGlobalMessageNames");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getReceivedGlobalMessageNames();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
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

    static void write(detail::json::JsonWriter& jsonWriter, const NotificationSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getGatewayNamespaceId())
        {
            jsonWriter.writePropertyName("gatewayNamespaceId");
            jsonWriter.writeCharArray(*obj.getGatewayNamespaceId());
        }
        if (obj.getEnableTransferMobileNotification())
        {
            jsonWriter.writePropertyName("enableTransferMobileNotification");
            jsonWriter.writeBool(*obj.getEnableTransferMobileNotification());
        }
        if (obj.getSound())
        {
            jsonWriter.writePropertyName("sound");
            jsonWriter.writeCharArray(*obj.getSound());
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

    static void write(detail::json::JsonWriter& jsonWriter, const TimeSpan& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getDays())
        {
            jsonWriter.writePropertyName("days");
            jsonWriter.writeInt32(*obj.getDays());
        }
        if (obj.getHours())
        {
            jsonWriter.writePropertyName("hours");
            jsonWriter.writeInt32(*obj.getHours());
        }
        if (obj.getMinutes())
        {
            jsonWriter.writePropertyName("minutes");
            jsonWriter.writeInt32(*obj.getMinutes());
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
    explicit Gs2InboxRestClient(Gs2RestSession& gs2RestSession) :
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
	 * メッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessages(DescribeMessagesRequest request, std::function<void(AsyncDescribeMessagesResult)> callback)
    {
        DescribeMessagesTask& task = *new DescribeMessagesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * メッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessagesByUserId(DescribeMessagesByUserIdRequest request, std::function<void(AsyncDescribeMessagesByUserIdResult)> callback)
    {
        DescribeMessagesByUserIdTask& task = *new DescribeMessagesByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * メッセージを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMessageByUserId(SendMessageByUserIdRequest request, std::function<void(AsyncSendMessageByUserIdResult)> callback)
    {
        SendMessageByUserIdTask& task = *new SendMessageByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * メッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessage(GetMessageRequest request, std::function<void(AsyncGetMessageResult)> callback)
    {
        GetMessageTask& task = *new GetMessageTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してメッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMessageByUserId(GetMessageByUserIdRequest request, std::function<void(AsyncGetMessageByUserIdResult)> callback)
    {
        GetMessageByUserIdTask& task = *new GetMessageByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * グローバルメッセージのうちまだ受け取っていないメッセージを受信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveGlobalMessage(ReceiveGlobalMessageRequest request, std::function<void(AsyncReceiveGlobalMessageResult)> callback)
    {
        ReceiveGlobalMessageTask& task = *new ReceiveGlobalMessageTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してグローバルメッセージのうちまだ受け取っていないメッセージを受信<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void receiveGlobalMessageByUserId(ReceiveGlobalMessageByUserIdRequest request, std::function<void(AsyncReceiveGlobalMessageByUserIdResult)> callback)
    {
        ReceiveGlobalMessageByUserIdTask& task = *new ReceiveGlobalMessageByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * メッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void openMessage(OpenMessageRequest request, std::function<void(AsyncOpenMessageResult)> callback)
    {
        OpenMessageTask& task = *new OpenMessageTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してメッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void openMessageByUserId(OpenMessageByUserIdRequest request, std::function<void(AsyncOpenMessageByUserIdResult)> callback)
    {
        OpenMessageByUserIdTask& task = *new OpenMessageByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * メッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessage(ReadMessageRequest request, std::function<void(AsyncReadMessageResult)> callback)
    {
        ReadMessageTask& task = *new ReadMessageTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してメッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void readMessageByUserId(ReadMessageByUserIdRequest request, std::function<void(AsyncReadMessageByUserIdResult)> callback)
    {
        ReadMessageByUserIdTask& task = *new ReadMessageByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * メッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessage(DeleteMessageRequest request, std::function<void(AsyncDeleteMessageResult)> callback)
    {
        DeleteMessageTask& task = *new DeleteMessageTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してメッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMessageByUserId(DeleteMessageByUserIdRequest request, std::function<void(AsyncDeleteMessageByUserIdResult)> callback)
    {
        DeleteMessageByUserIdTask& task = *new DeleteMessageByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * メッセージを作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void openByStampTask(OpenByStampTaskRequest request, std::function<void(AsyncOpenByStampTaskResult)> callback)
    {
        OpenByStampTaskTask& task = *new OpenByStampTaskTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なグローバルメッセージ設定のマスターデータをエクスポートします<br>
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
	 * 現在有効なグローバルメッセージ設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentMessageMaster(GetCurrentMessageMasterRequest request, std::function<void(AsyncGetCurrentMessageMasterResult)> callback)
    {
        GetCurrentMessageMasterTask& task = *new GetCurrentMessageMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なグローバルメッセージ設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMessageMaster(UpdateCurrentMessageMasterRequest request, std::function<void(AsyncUpdateCurrentMessageMasterResult)> callback)
    {
        UpdateCurrentMessageMasterTask& task = *new UpdateCurrentMessageMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なグローバルメッセージ設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentMessageMasterFromGitHub(UpdateCurrentMessageMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentMessageMasterFromGitHubResult)> callback)
    {
        UpdateCurrentMessageMasterFromGitHubTask& task = *new UpdateCurrentMessageMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGlobalMessageMasters(DescribeGlobalMessageMastersRequest request, std::function<void(AsyncDescribeGlobalMessageMastersResult)> callback)
    {
        DescribeGlobalMessageMastersTask& task = *new DescribeGlobalMessageMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGlobalMessageMaster(CreateGlobalMessageMasterRequest request, std::function<void(AsyncCreateGlobalMessageMasterResult)> callback)
    {
        CreateGlobalMessageMasterTask& task = *new CreateGlobalMessageMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGlobalMessageMaster(GetGlobalMessageMasterRequest request, std::function<void(AsyncGetGlobalMessageMasterResult)> callback)
    {
        GetGlobalMessageMasterTask& task = *new GetGlobalMessageMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを開封<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGlobalMessageMaster(UpdateGlobalMessageMasterRequest request, std::function<void(AsyncUpdateGlobalMessageMasterResult)> callback)
    {
        UpdateGlobalMessageMasterTask& task = *new UpdateGlobalMessageMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGlobalMessageMaster(DeleteGlobalMessageMasterRequest request, std::function<void(AsyncDeleteGlobalMessageMasterResult)> callback)
    {
        DeleteGlobalMessageMasterTask& task = *new DeleteGlobalMessageMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGlobalMessages(DescribeGlobalMessagesRequest request, std::function<void(AsyncDescribeGlobalMessagesResult)> callback)
    {
        DescribeGlobalMessagesTask& task = *new DescribeGlobalMessagesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 全ユーザに向けたメッセージを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGlobalMessage(GetGlobalMessageRequest request, std::function<void(AsyncGetGlobalMessageResult)> callback)
    {
        GetGlobalMessageTask& task = *new GetGlobalMessageTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して受信済みグローバルメッセージ名を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getReceivedByUserId(GetReceivedByUserIdRequest request, std::function<void(AsyncGetReceivedByUserIdResult)> callback)
    {
        GetReceivedByUserIdTask& task = *new GetReceivedByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して受信済みグローバルメッセージ名を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateReceivedByUserId(UpdateReceivedByUserIdRequest request, std::function<void(AsyncUpdateReceivedByUserIdResult)> callback)
    {
        UpdateReceivedByUserIdTask& task = *new UpdateReceivedByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定して受信済みグローバルメッセージ名を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteReceivedByUserId(DeleteReceivedByUserIdRequest request, std::function<void(AsyncDeleteReceivedByUserIdResult)> callback)
    {
        DeleteReceivedByUserIdTask& task = *new DeleteReceivedByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_INBOX_GS2INBOXRESTCLIENT_HPP_