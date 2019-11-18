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
#include "request/OpenMessageRequest.hpp"
#include "request/OpenMessageByUserIdRequest.hpp"
#include "request/ReadMessageRequest.hpp"
#include "request/ReadMessageByUserIdRequest.hpp"
#include "request/DeleteMessageRequest.hpp"
#include "request/DeleteMessageByUserIdRequest.hpp"
#include "request/OpenByStampTaskRequest.hpp"
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
#include "result/OpenMessageResult.hpp"
#include "result/OpenMessageByUserIdResult.hpp"
#include "result/ReadMessageResult.hpp"
#include "result/ReadMessageByUserIdResult.hpp"
#include "result/DeleteMessageResult.hpp"
#include "result/DeleteMessageByUserIdResult.hpp"
#include "result/OpenByStampTaskResult.hpp"
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

    class DeleteNamespaceTask : public detail::Gs2RestSessionTask<void>
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

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_INBOX_GS2INBOXRESTCLIENT_HPP_