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

#ifndef GS2_EXCHANGE_GS2EXCHANGEWEBSOCKETCLIENT_HPP_
#define GS2_EXCHANGE_GS2EXCHANGEWEBSOCKETCLIENT_HPP_

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
class Gs2ExchangeWebSocketClient : public AbstractGs2ClientBase
{
private:

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
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
            return "exchange";
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
            return "exchange";
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
            return "exchange";
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
            return "exchange";
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

    class GetRateModelTask : public detail::Gs2WebSocketSessionTask<GetRateModelResult>
    {
    private:
        GetRateModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "rateModel";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getRateModel";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetRateModelTask(
            GetRateModelRequest request,
            Gs2WebSocketSessionTask<GetRateModelResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetRateModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRateModelTask() GS2_OVERRIDE = default;
    };

    class CreateRateModelMasterTask : public detail::Gs2WebSocketSessionTask<CreateRateModelMasterResult>
    {
    private:
        CreateRateModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "rateModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createRateModelMaster";
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateRateModelMasterTask(
            CreateRateModelMasterRequest request,
            Gs2WebSocketSessionTask<CreateRateModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateRateModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateRateModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetRateModelMasterTask : public detail::Gs2WebSocketSessionTask<GetRateModelMasterResult>
    {
    private:
        GetRateModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "rateModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getRateModelMaster";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetRateModelMasterTask(
            GetRateModelMasterRequest request,
            Gs2WebSocketSessionTask<GetRateModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetRateModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetRateModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateRateModelMasterTask : public detail::Gs2WebSocketSessionTask<UpdateRateModelMasterResult>
    {
    private:
        UpdateRateModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "rateModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateRateModelMaster";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateRateModelMasterTask(
            UpdateRateModelMasterRequest request,
            Gs2WebSocketSessionTask<UpdateRateModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateRateModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateRateModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteRateModelMasterTask : public detail::Gs2WebSocketSessionTask<DeleteRateModelMasterResult>
    {
    private:
        DeleteRateModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "rateModelMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteRateModelMaster";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteRateModelMasterTask(
            DeleteRateModelMasterRequest request,
            Gs2WebSocketSessionTask<DeleteRateModelMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteRateModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteRateModelMasterTask() GS2_OVERRIDE = default;
    };

    class ExchangeByStampSheetTask : public detail::Gs2WebSocketSessionTask<ExchangeByStampSheetResult>
    {
    private:
        ExchangeByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "exchangeByStampSheet";
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
        ExchangeByStampSheetTask(
            ExchangeByStampSheetRequest request,
            Gs2WebSocketSessionTask<ExchangeByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<ExchangeByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~ExchangeByStampSheetTask() GS2_OVERRIDE = default;
    };

    class CreateAwaitByUserIdTask : public detail::Gs2WebSocketSessionTask<CreateAwaitByUserIdResult>
    {
    private:
        CreateAwaitByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createAwaitByUserId";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getCount())
            {
                jsonWriter.writePropertyName("count");
                jsonWriter.writeInt32(*m_Request.getCount());
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
        CreateAwaitByUserIdTask(
            CreateAwaitByUserIdRequest request,
            Gs2WebSocketSessionTask<CreateAwaitByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateAwaitByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateAwaitByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetAwaitTask : public detail::Gs2WebSocketSessionTask<GetAwaitResult>
    {
    private:
        GetAwaitRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getAwait";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getAwaitName())
            {
                jsonWriter.writePropertyName("awaitName");
                jsonWriter.writeCharArray(*m_Request.getAwaitName());
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
        GetAwaitTask(
            GetAwaitRequest request,
            Gs2WebSocketSessionTask<GetAwaitResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetAwaitResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetAwaitTask() GS2_OVERRIDE = default;
    };

    class GetAwaitByUserIdTask : public detail::Gs2WebSocketSessionTask<GetAwaitByUserIdResult>
    {
    private:
        GetAwaitByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getAwaitByUserId";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getAwaitName())
            {
                jsonWriter.writePropertyName("awaitName");
                jsonWriter.writeCharArray(*m_Request.getAwaitName());
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
        GetAwaitByUserIdTask(
            GetAwaitByUserIdRequest request,
            Gs2WebSocketSessionTask<GetAwaitByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetAwaitByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetAwaitByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcquireTask : public detail::Gs2WebSocketSessionTask<AcquireResult>
    {
    private:
        AcquireRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "acquire";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getAwaitName())
            {
                jsonWriter.writePropertyName("awaitName");
                jsonWriter.writeCharArray(*m_Request.getAwaitName());
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
        AcquireTask(
            AcquireRequest request,
            Gs2WebSocketSessionTask<AcquireResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcquireResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireTask() GS2_OVERRIDE = default;
    };

    class AcquireByUserIdTask : public detail::Gs2WebSocketSessionTask<AcquireByUserIdResult>
    {
    private:
        AcquireByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "acquireByUserId";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getAwaitName())
            {
                jsonWriter.writePropertyName("awaitName");
                jsonWriter.writeCharArray(*m_Request.getAwaitName());
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
        AcquireByUserIdTask(
            AcquireByUserIdRequest request,
            Gs2WebSocketSessionTask<AcquireByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcquireByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireByUserIdTask() GS2_OVERRIDE = default;
    };

    class AcquireForceByUserIdTask : public detail::Gs2WebSocketSessionTask<AcquireForceByUserIdResult>
    {
    private:
        AcquireForceByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "acquireForceByUserId";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getAwaitName())
            {
                jsonWriter.writePropertyName("awaitName");
                jsonWriter.writeCharArray(*m_Request.getAwaitName());
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
        AcquireForceByUserIdTask(
            AcquireForceByUserIdRequest request,
            Gs2WebSocketSessionTask<AcquireForceByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<AcquireForceByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AcquireForceByUserIdTask() GS2_OVERRIDE = default;
    };

    class SkipTask : public detail::Gs2WebSocketSessionTask<SkipResult>
    {
    private:
        SkipRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "skip";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getAwaitName())
            {
                jsonWriter.writePropertyName("awaitName");
                jsonWriter.writeCharArray(*m_Request.getAwaitName());
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
        SkipTask(
            SkipRequest request,
            Gs2WebSocketSessionTask<SkipResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SkipResult>(callback),
            m_Request(std::move(request))
        {}

        ~SkipTask() GS2_OVERRIDE = default;
    };

    class SkipByUserIdTask : public detail::Gs2WebSocketSessionTask<SkipByUserIdResult>
    {
    private:
        SkipByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "skipByUserId";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getAwaitName())
            {
                jsonWriter.writePropertyName("awaitName");
                jsonWriter.writeCharArray(*m_Request.getAwaitName());
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
        SkipByUserIdTask(
            SkipByUserIdRequest request,
            Gs2WebSocketSessionTask<SkipByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<SkipByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SkipByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteAwaitTask : public detail::Gs2WebSocketSessionTask<DeleteAwaitResult>
    {
    private:
        DeleteAwaitRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteAwait";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getAwaitName())
            {
                jsonWriter.writePropertyName("awaitName");
                jsonWriter.writeCharArray(*m_Request.getAwaitName());
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
        DeleteAwaitTask(
            DeleteAwaitRequest request,
            Gs2WebSocketSessionTask<DeleteAwaitResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteAwaitResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAwaitTask() GS2_OVERRIDE = default;
    };

    class DeleteAwaitByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteAwaitByUserIdResult>
    {
    private:
        DeleteAwaitByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteAwaitByUserId";
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
            if (m_Request.getRateName())
            {
                jsonWriter.writePropertyName("rateName");
                jsonWriter.writeCharArray(*m_Request.getRateName());
            }
            if (m_Request.getAwaitName())
            {
                jsonWriter.writePropertyName("awaitName");
                jsonWriter.writeCharArray(*m_Request.getAwaitName());
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
        DeleteAwaitByUserIdTask(
            DeleteAwaitByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteAwaitByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteAwaitByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteAwaitByUserIdTask() GS2_OVERRIDE = default;
    };

    class CreateAwaitByStampSheetTask : public detail::Gs2WebSocketSessionTask<CreateAwaitByStampSheetResult>
    {
    private:
        CreateAwaitByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createAwaitByStampSheet";
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
        CreateAwaitByStampSheetTask(
            CreateAwaitByStampSheetRequest request,
            Gs2WebSocketSessionTask<CreateAwaitByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateAwaitByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateAwaitByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DeleteAwaitByStampTaskTask : public detail::Gs2WebSocketSessionTask<DeleteAwaitByStampTaskResult>
    {
    private:
        DeleteAwaitByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "exchange";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "await";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteAwaitByStampTask";
        }

        void constructRequestImpl(detail::json::JsonWriter& jsonWriter) GS2_OVERRIDE
        {
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
        DeleteAwaitByStampTaskTask(
            DeleteAwaitByStampTaskRequest request,
            Gs2WebSocketSessionTask<DeleteAwaitByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteAwaitByStampTaskResult>(callback),
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
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2ExchangeWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
        AbstractGs2ClientBase(gs2WebSocketSession)
    {
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
	 * ネームスペースを取得<br>
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
	 * 交換レートモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRateModel(GetRateModelRequest request, std::function<void(AsyncGetRateModelResult)> callback)
    {
        GetRateModelTask& task = *new GetRateModelTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_EXCHANGE_GS2EXCHANGEWEBSOCKETCLIENT_HPP_