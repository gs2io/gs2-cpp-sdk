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

#ifndef GS2_JOBQUEUE_GS2JOBQUEUEWEBSOCKETCLIENT_HPP_
#define GS2_JOBQUEUE_GS2JOBQUEUEWEBSOCKETCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2WebSocketSessionTask.hpp>
#include <gs2/core/network/Gs2WebSocketSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeJobsByUserIdRequest.hpp"
#include "request/GetJobByUserIdRequest.hpp"
#include "request/PushByUserIdRequest.hpp"
#include "request/RunRequest.hpp"
#include "request/RunByUserIdRequest.hpp"
#include "request/DeleteJobByUserIdRequest.hpp"
#include "request/PushByStampSheetRequest.hpp"
#include "request/DescribeDeadLetterJobsByUserIdRequest.hpp"
#include "request/GetDeadLetterJobByUserIdRequest.hpp"
#include "request/DeleteDeadLetterJobByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeJobsByUserIdResult.hpp"
#include "result/GetJobByUserIdResult.hpp"
#include "result/PushByUserIdResult.hpp"
#include "result/RunResult.hpp"
#include "result/RunByUserIdResult.hpp"
#include "result/DeleteJobByUserIdResult.hpp"
#include "result/PushByStampSheetResult.hpp"
#include "result/DescribeDeadLetterJobsByUserIdResult.hpp"
#include "result/GetDeadLetterJobByUserIdResult.hpp"
#include "result/DeleteDeadLetterJobByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace jobQueue {

/**
 * GS2 JobQueue API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2JobQueueWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeNamespaces";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DescribeNamespacesTask(
            DescribeNamespacesRequest request,
            Gs2WebSocketSessionTask<DescribeNamespacesResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeNamespacesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNamespacesTask() GS2_OVERRIDE = default;
    };

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
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
            if (m_Request.getPushNotification())
            {
                jsonWriter.writePropertyName("pushNotification");
                write(jsonWriter, *m_Request.getPushNotification());
            }
            if (m_Request.getLogSetting())
            {
                jsonWriter.writePropertyName("logSetting");
                write(jsonWriter, *m_Request.getLogSetting());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateNamespaceTask(
            CreateNamespaceRequest request,
            Gs2WebSocketSessionTask<CreateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateNamespaceTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceStatusTask : public detail::Gs2WebSocketSessionTask<GetNamespaceStatusResult>
    {
    private:
        GetNamespaceStatusRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getNamespaceStatus";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetNamespaceStatusTask(
            GetNamespaceStatusRequest request,
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceStatusResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceStatusTask() GS2_OVERRIDE = default;
    };

    class GetNamespaceTask : public detail::Gs2WebSocketSessionTask<GetNamespaceResult>
    {
    private:
        GetNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetNamespaceTask(
            GetNamespaceRequest request,
            Gs2WebSocketSessionTask<GetNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetNamespaceTask() GS2_OVERRIDE = default;
    };

    class UpdateNamespaceTask : public detail::Gs2WebSocketSessionTask<UpdateNamespaceResult>
    {
    private:
        UpdateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getPushNotification())
            {
                jsonWriter.writePropertyName("pushNotification");
                write(jsonWriter, *m_Request.getPushNotification());
            }
            if (m_Request.getLogSetting())
            {
                jsonWriter.writePropertyName("logSetting");
                write(jsonWriter, *m_Request.getLogSetting());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateNamespaceTask(
            UpdateNamespaceRequest request,
            Gs2WebSocketSessionTask<UpdateNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateNamespaceTask() GS2_OVERRIDE = default;
    };

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "namespace";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteNamespace";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteNamespaceTask(
            DeleteNamespaceRequest request,
            Gs2WebSocketSessionTask<DeleteNamespaceResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteNamespaceResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeJobsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeJobsByUserIdResult>
    {
    private:
        DescribeJobsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "job";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeJobsByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeJobsByUserIdTask(
            DescribeJobsByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeJobsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeJobsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeJobsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetJobByUserIdTask : public detail::Gs2WebSocketSessionTask<GetJobByUserIdResult>
    {
    private:
        GetJobByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "job";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getJobByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getJobName())
            {
                jsonWriter.writePropertyName("jobName");
                jsonWriter.writeCharArray(*m_Request.getJobName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetJobByUserIdTask(
            GetJobByUserIdRequest request,
            Gs2WebSocketSessionTask<GetJobByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetJobByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetJobByUserIdTask() GS2_OVERRIDE = default;
    };

    class PushByUserIdTask : public detail::Gs2WebSocketSessionTask<PushByUserIdResult>
    {
    private:
        PushByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "job";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "pushByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getJobs())
            {
                jsonWriter.writePropertyName("jobs");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getJobs();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PushByUserIdTask(
            PushByUserIdRequest request,
            Gs2WebSocketSessionTask<PushByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PushByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PushByUserIdTask() GS2_OVERRIDE = default;
    };

    class RunTask : public detail::Gs2WebSocketSessionTask<RunResult>
    {
    private:
        RunRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "job";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "run";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getAccessToken())
            {
                jsonWriter.writePropertyName("xGs2AccessToken");
                jsonWriter.writeCharArray(*m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        RunTask(
            RunRequest request,
            Gs2WebSocketSessionTask<RunResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RunResult>(callback),
            m_Request(std::move(request))
        {}

        ~RunTask() GS2_OVERRIDE = default;
    };

    class RunByUserIdTask : public detail::Gs2WebSocketSessionTask<RunByUserIdResult>
    {
    private:
        RunByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "job";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "runByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        RunByUserIdTask(
            RunByUserIdRequest request,
            Gs2WebSocketSessionTask<RunByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<RunByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~RunByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteJobByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteJobByUserIdResult>
    {
    private:
        DeleteJobByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "job";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteJobByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getJobName())
            {
                jsonWriter.writePropertyName("jobName");
                jsonWriter.writeCharArray(*m_Request.getJobName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteJobByUserIdTask(
            DeleteJobByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteJobByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteJobByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteJobByUserIdTask() GS2_OVERRIDE = default;
    };

    class PushByStampSheetTask : public detail::Gs2WebSocketSessionTask<PushByStampSheetResult>
    {
    private:
        PushByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "job";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "pushByStampSheet";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        PushByStampSheetTask(
            PushByStampSheetRequest request,
            Gs2WebSocketSessionTask<PushByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<PushByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~PushByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DescribeDeadLetterJobsByUserIdTask : public detail::Gs2WebSocketSessionTask<DescribeDeadLetterJobsByUserIdResult>
    {
    private:
        DescribeDeadLetterJobsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "deadLetterJob";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeDeadLetterJobsByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getPageToken())
            {
                jsonWriter.writePropertyName("pageToken");
                jsonWriter.writeCharArray(*m_Request.getPageToken());
            }
            if (m_Request.getLimit())
            {
                jsonWriter.writePropertyName("limit");
                jsonWriter.writeInt64(*m_Request.getLimit());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DescribeDeadLetterJobsByUserIdTask(
            DescribeDeadLetterJobsByUserIdRequest request,
            Gs2WebSocketSessionTask<DescribeDeadLetterJobsByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeDeadLetterJobsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeDeadLetterJobsByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetDeadLetterJobByUserIdTask : public detail::Gs2WebSocketSessionTask<GetDeadLetterJobByUserIdResult>
    {
    private:
        GetDeadLetterJobByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "deadLetterJob";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getDeadLetterJobByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getDeadLetterJobName())
            {
                jsonWriter.writePropertyName("deadLetterJobName");
                jsonWriter.writeCharArray(*m_Request.getDeadLetterJobName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        GetDeadLetterJobByUserIdTask(
            GetDeadLetterJobByUserIdRequest request,
            Gs2WebSocketSessionTask<GetDeadLetterJobByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetDeadLetterJobByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetDeadLetterJobByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteDeadLetterJobByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteDeadLetterJobByUserIdResult>
    {
    private:
        DeleteDeadLetterJobByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "jobQueue";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "deadLetterJob";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteDeadLetterJobByUserId";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getNamespaceName())
            {
                jsonWriter.writePropertyName("namespaceName");
                jsonWriter.writeCharArray(*m_Request.getNamespaceName());
            }
            if (m_Request.getUserId())
            {
                jsonWriter.writePropertyName("userId");
                jsonWriter.writeCharArray(*m_Request.getUserId());
            }
            if (m_Request.getDeadLetterJobName())
            {
                jsonWriter.writePropertyName("deadLetterJobName");
                jsonWriter.writeCharArray(*m_Request.getDeadLetterJobName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
            if (m_Request.getDuplicationAvoider())
            {
                jsonWriter.writePropertyName("xGs2DuplicationAvoider");
                jsonWriter.writeCharArray(*m_Request.getDuplicationAvoider());
            }
        }

    public:
        DeleteDeadLetterJobByUserIdTask(
            DeleteDeadLetterJobByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteDeadLetterJobByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteDeadLetterJobByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteDeadLetterJobByUserIdTask() GS2_OVERRIDE = default;
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
        if (obj.getPushNotification())
        {
            jsonWriter.writePropertyName("pushNotification");
            write(jsonWriter, *obj.getPushNotification());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Job& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getJobId())
        {
            jsonWriter.writePropertyName("jobId");
            jsonWriter.writeCharArray(*obj.getJobId());
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
        if (obj.getScriptId())
        {
            jsonWriter.writePropertyName("scriptId");
            jsonWriter.writeCharArray(*obj.getScriptId());
        }
        if (obj.getArgs())
        {
            jsonWriter.writePropertyName("args");
            jsonWriter.writeCharArray(*obj.getArgs());
        }
        if (obj.getCurrentRetryCount())
        {
            jsonWriter.writePropertyName("currentRetryCount");
            jsonWriter.writeInt32(*obj.getCurrentRetryCount());
        }
        if (obj.getMaxTryCount())
        {
            jsonWriter.writePropertyName("maxTryCount");
            jsonWriter.writeInt32(*obj.getMaxTryCount());
        }
        if (obj.getIndex())
        {
            jsonWriter.writePropertyName("index");
            jsonWriter.writeDouble(*obj.getIndex());
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

    static void write(detail::json::JsonWriter& jsonWriter, const JobResult& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getJobResultId())
        {
            jsonWriter.writePropertyName("jobResultId");
            jsonWriter.writeCharArray(*obj.getJobResultId());
        }
        if (obj.getJobId())
        {
            jsonWriter.writePropertyName("jobId");
            jsonWriter.writeCharArray(*obj.getJobId());
        }
        if (obj.getTryNumber())
        {
            jsonWriter.writePropertyName("tryNumber");
            jsonWriter.writeInt32(*obj.getTryNumber());
        }
        if (obj.getStatusCode())
        {
            jsonWriter.writePropertyName("statusCode");
            jsonWriter.writeInt32(*obj.getStatusCode());
        }
        if (obj.getResult())
        {
            jsonWriter.writePropertyName("result");
            jsonWriter.writeCharArray(*obj.getResult());
        }
        if (obj.getTryAt())
        {
            jsonWriter.writePropertyName("tryAt");
            jsonWriter.writeInt64(*obj.getTryAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const DeadLetterJob& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getDeadLetterJobId())
        {
            jsonWriter.writePropertyName("deadLetterJobId");
            jsonWriter.writeCharArray(*obj.getDeadLetterJobId());
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
        if (obj.getScriptId())
        {
            jsonWriter.writePropertyName("scriptId");
            jsonWriter.writeCharArray(*obj.getScriptId());
        }
        if (obj.getArgs())
        {
            jsonWriter.writePropertyName("args");
            jsonWriter.writeCharArray(*obj.getArgs());
        }
        if (obj.getResult())
        {
            jsonWriter.writePropertyName("result");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getResult();
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

    static void write(detail::json::JsonWriter& jsonWriter, const JobEntry& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getScriptId())
        {
            jsonWriter.writePropertyName("scriptId");
            jsonWriter.writeCharArray(*obj.getScriptId());
        }
        if (obj.getArgs())
        {
            jsonWriter.writePropertyName("args");
            jsonWriter.writeCharArray(*obj.getArgs());
        }
        if (obj.getMaxTryCount())
        {
            jsonWriter.writePropertyName("maxTryCount");
            jsonWriter.writeInt32(*obj.getMaxTryCount());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const JobResultBody& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTryNumber())
        {
            jsonWriter.writePropertyName("tryNumber");
            jsonWriter.writeInt32(*obj.getTryNumber());
        }
        if (obj.getStatusCode())
        {
            jsonWriter.writePropertyName("statusCode");
            jsonWriter.writeInt32(*obj.getStatusCode());
        }
        if (obj.getResult())
        {
            jsonWriter.writePropertyName("result");
            jsonWriter.writeCharArray(*obj.getResult());
        }
        if (obj.getTryAt())
        {
            jsonWriter.writePropertyName("tryAt");
            jsonWriter.writeInt64(*obj.getTryAt());
        }
        jsonWriter.writeObjectEnd();
    }


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2JobQueueWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ジョブの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeJobsByUserId(DescribeJobsByUserIdRequest request, std::function<void(AsyncDescribeJobsByUserIdResult)> callback)
    {
        DescribeJobsByUserIdTask& task = *new DescribeJobsByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ジョブを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getJobByUserId(GetJobByUserIdRequest request, std::function<void(AsyncGetJobByUserIdResult)> callback)
    {
        GetJobByUserIdTask& task = *new GetJobByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してジョブを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void pushByUserId(PushByUserIdRequest request, std::function<void(AsyncPushByUserIdResult)> callback)
    {
        PushByUserIdTask& task = *new PushByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ジョブを実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void run(RunRequest request, std::function<void(AsyncRunResult)> callback)
    {
        RunTask& task = *new RunTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定してジョブを実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void runByUserId(RunByUserIdRequest request, std::function<void(AsyncRunByUserIdResult)> callback)
    {
        RunByUserIdTask& task = *new RunByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ジョブを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteJobByUserId(DeleteJobByUserIdRequest request, std::function<void(AsyncDeleteJobByUserIdResult)> callback)
    {
        DeleteJobByUserIdTask& task = *new DeleteJobByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * スタンプシートでジョブを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void pushByStampSheet(PushByStampSheetRequest request, std::function<void(AsyncPushByStampSheetResult)> callback)
    {
        PushByStampSheetTask& task = *new PushByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * デッドレタージョブの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDeadLetterJobsByUserId(DescribeDeadLetterJobsByUserIdRequest request, std::function<void(AsyncDescribeDeadLetterJobsByUserIdResult)> callback)
    {
        DescribeDeadLetterJobsByUserIdTask& task = *new DescribeDeadLetterJobsByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * デッドレタージョブを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDeadLetterJobByUserId(GetDeadLetterJobByUserIdRequest request, std::function<void(AsyncGetDeadLetterJobByUserIdResult)> callback)
    {
        GetDeadLetterJobByUserIdTask& task = *new GetDeadLetterJobByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * デッドレタージョブを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDeadLetterJobByUserId(DeleteDeadLetterJobByUserIdRequest request, std::function<void(AsyncDeleteDeadLetterJobByUserIdResult)> callback)
    {
        DeleteDeadLetterJobByUserIdTask& task = *new DeleteDeadLetterJobByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_JOBQUEUE_GS2JOBQUEUEWEBSOCKETCLIENT_HPP_