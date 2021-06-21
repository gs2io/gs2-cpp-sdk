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

#ifndef GS2_ENHANCE_GS2ENHANCEWEBSOCKETCLIENT_HPP_
#define GS2_ENHANCE_GS2ENHANCEWEBSOCKETCLIENT_HPP_

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
class Gs2EnhanceWebSocketClient : public AbstractGs2ClientBase
{
private:

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
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
            return "enhance";
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
            return "enhance";
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
            return "enhance";
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
            return "enhance";
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
            return "enhance";
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
            return "enhance";
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
            return "enhance";
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
            return "enhance";
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
            return "enhance";
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

    class DirectEnhanceByStampSheetTask : public detail::Gs2WebSocketSessionTask<DirectEnhanceByStampSheetResult>
    {
    private:
        DirectEnhanceByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "directEnhanceByStampSheet";
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
        DirectEnhanceByStampSheetTask(
            DirectEnhanceByStampSheetRequest request,
            Gs2WebSocketSessionTask<DirectEnhanceByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DirectEnhanceByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~DirectEnhanceByStampSheetTask() GS2_OVERRIDE = default;
    };

    class CreateProgressByUserIdTask : public detail::Gs2WebSocketSessionTask<CreateProgressByUserIdResult>
    {
    private:
        CreateProgressByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "progress";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createProgressByUserId";
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
        CreateProgressByUserIdTask(
            CreateProgressByUserIdRequest request,
            Gs2WebSocketSessionTask<CreateProgressByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateProgressByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateProgressByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetProgressTask : public detail::Gs2WebSocketSessionTask<GetProgressResult>
    {
    private:
        GetProgressRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "progress";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getProgress";
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
        GetProgressTask(
            GetProgressRequest request,
            Gs2WebSocketSessionTask<GetProgressResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProgressResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProgressTask() GS2_OVERRIDE = default;
    };

    class GetProgressByUserIdTask : public detail::Gs2WebSocketSessionTask<GetProgressByUserIdResult>
    {
    private:
        GetProgressByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "progress";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getProgressByUserId";
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
        GetProgressByUserIdTask(
            GetProgressByUserIdRequest request,
            Gs2WebSocketSessionTask<GetProgressByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetProgressByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetProgressByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteProgressTask : public detail::Gs2WebSocketSessionTask<DeleteProgressResult>
    {
    private:
        DeleteProgressRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "progress";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteProgress";
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
        DeleteProgressTask(
            DeleteProgressRequest request,
            Gs2WebSocketSessionTask<DeleteProgressResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteProgressResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProgressTask() GS2_OVERRIDE = default;
    };

    class DeleteProgressByUserIdTask : public detail::Gs2WebSocketSessionTask<DeleteProgressByUserIdResult>
    {
    private:
        DeleteProgressByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "progress";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteProgressByUserId";
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
        DeleteProgressByUserIdTask(
            DeleteProgressByUserIdRequest request,
            Gs2WebSocketSessionTask<DeleteProgressByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteProgressByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProgressByUserIdTask() GS2_OVERRIDE = default;
    };

    class CreateProgressByStampSheetTask : public detail::Gs2WebSocketSessionTask<CreateProgressByStampSheetResult>
    {
    private:
        CreateProgressByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "progress";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createProgressByStampSheet";
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
        CreateProgressByStampSheetTask(
            CreateProgressByStampSheetRequest request,
            Gs2WebSocketSessionTask<CreateProgressByStampSheetResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateProgressByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateProgressByStampSheetTask() GS2_OVERRIDE = default;
    };

    class DeleteProgressByStampTaskTask : public detail::Gs2WebSocketSessionTask<DeleteProgressByStampTaskResult>
    {
    private:
        DeleteProgressByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "enhance";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "progress";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteProgressByStampTask";
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
        DeleteProgressByStampTaskTask(
            DeleteProgressByStampTaskRequest request,
            Gs2WebSocketSessionTask<DeleteProgressByStampTaskResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteProgressByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteProgressByStampTaskTask() GS2_OVERRIDE = default;
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
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2EnhanceWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * 強化レートモデルを取得<br>
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
	 * 強化レートマスターを新規作成<br>
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
	 * 強化レートマスターを取得<br>
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
	 * 強化レートマスターを更新<br>
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
	 * 強化レートマスターを削除<br>
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
	 * スタンプシートで強化を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void directEnhanceByStampSheet(DirectEnhanceByStampSheetRequest request, std::function<void(AsyncDirectEnhanceByStampSheetResult)> callback)
    {
        DirectEnhanceByStampSheetTask& task = *new DirectEnhanceByStampSheetTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
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
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_ENHANCE_GS2ENHANCEWEBSOCKETCLIENT_HPP_