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

#ifndef GS2_SHOWCASE_GS2SHOWCASEWEBSOCKETCLIENT_HPP_
#define GS2_SHOWCASE_GS2SHOWCASEWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeSalesItemMastersRequest.hpp"
#include "request/CreateSalesItemMasterRequest.hpp"
#include "request/GetSalesItemMasterRequest.hpp"
#include "request/UpdateSalesItemMasterRequest.hpp"
#include "request/DeleteSalesItemMasterRequest.hpp"
#include "request/DescribeSalesItemGroupMastersRequest.hpp"
#include "request/CreateSalesItemGroupMasterRequest.hpp"
#include "request/GetSalesItemGroupMasterRequest.hpp"
#include "request/UpdateSalesItemGroupMasterRequest.hpp"
#include "request/DeleteSalesItemGroupMasterRequest.hpp"
#include "request/DescribeShowcaseMastersRequest.hpp"
#include "request/CreateShowcaseMasterRequest.hpp"
#include "request/GetShowcaseMasterRequest.hpp"
#include "request/UpdateShowcaseMasterRequest.hpp"
#include "request/DeleteShowcaseMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentShowcaseMasterRequest.hpp"
#include "request/UpdateCurrentShowcaseMasterRequest.hpp"
#include "request/UpdateCurrentShowcaseMasterFromGitHubRequest.hpp"
#include "request/DescribeShowcasesRequest.hpp"
#include "request/DescribeShowcasesByUserIdRequest.hpp"
#include "request/GetShowcaseRequest.hpp"
#include "request/GetShowcaseByUserIdRequest.hpp"
#include "request/BuyRequest.hpp"
#include "request/BuyByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeSalesItemMastersResult.hpp"
#include "result/CreateSalesItemMasterResult.hpp"
#include "result/GetSalesItemMasterResult.hpp"
#include "result/UpdateSalesItemMasterResult.hpp"
#include "result/DeleteSalesItemMasterResult.hpp"
#include "result/DescribeSalesItemGroupMastersResult.hpp"
#include "result/CreateSalesItemGroupMasterResult.hpp"
#include "result/GetSalesItemGroupMasterResult.hpp"
#include "result/UpdateSalesItemGroupMasterResult.hpp"
#include "result/DeleteSalesItemGroupMasterResult.hpp"
#include "result/DescribeShowcaseMastersResult.hpp"
#include "result/CreateShowcaseMasterResult.hpp"
#include "result/GetShowcaseMasterResult.hpp"
#include "result/UpdateShowcaseMasterResult.hpp"
#include "result/DeleteShowcaseMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentShowcaseMasterResult.hpp"
#include "result/UpdateCurrentShowcaseMasterResult.hpp"
#include "result/UpdateCurrentShowcaseMasterFromGitHubResult.hpp"
#include "result/DescribeShowcasesResult.hpp"
#include "result/DescribeShowcasesByUserIdResult.hpp"
#include "result/GetShowcaseResult.hpp"
#include "result/GetShowcaseByUserIdResult.hpp"
#include "result/BuyResult.hpp"
#include "result/BuyByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace showcase {

/**
 * GS2 Showcase API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ShowcaseWebSocketClient : public AbstractGs2ClientBase
{
private:

    class CreateNamespaceTask : public detail::Gs2WebSocketSessionTask<CreateNamespaceResult>
    {
    private:
        CreateNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
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
            return "showcase";
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
            return "showcase";
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
            return "showcase";
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
            return "showcase";
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

    class CreateSalesItemMasterTask : public detail::Gs2WebSocketSessionTask<CreateSalesItemMasterResult>
    {
    private:
        CreateSalesItemMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "salesItemMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createSalesItemMaster";
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateSalesItemMasterTask(
            CreateSalesItemMasterRequest request,
            Gs2WebSocketSessionTask<CreateSalesItemMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateSalesItemMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateSalesItemMasterTask() GS2_OVERRIDE = default;
    };

    class GetSalesItemMasterTask : public detail::Gs2WebSocketSessionTask<GetSalesItemMasterResult>
    {
    private:
        GetSalesItemMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "salesItemMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getSalesItemMaster";
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
            if (m_Request.getSalesItemName())
            {
                jsonWriter.writePropertyName("salesItemName");
                jsonWriter.writeCharArray(*m_Request.getSalesItemName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetSalesItemMasterTask(
            GetSalesItemMasterRequest request,
            Gs2WebSocketSessionTask<GetSalesItemMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSalesItemMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSalesItemMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateSalesItemMasterTask : public detail::Gs2WebSocketSessionTask<UpdateSalesItemMasterResult>
    {
    private:
        UpdateSalesItemMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "salesItemMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateSalesItemMaster";
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
            if (m_Request.getSalesItemName())
            {
                jsonWriter.writePropertyName("salesItemName");
                jsonWriter.writeCharArray(*m_Request.getSalesItemName());
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateSalesItemMasterTask(
            UpdateSalesItemMasterRequest request,
            Gs2WebSocketSessionTask<UpdateSalesItemMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateSalesItemMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateSalesItemMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteSalesItemMasterTask : public detail::Gs2WebSocketSessionTask<DeleteSalesItemMasterResult>
    {
    private:
        DeleteSalesItemMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "salesItemMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteSalesItemMaster";
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
            if (m_Request.getSalesItemName())
            {
                jsonWriter.writePropertyName("salesItemName");
                jsonWriter.writeCharArray(*m_Request.getSalesItemName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteSalesItemMasterTask(
            DeleteSalesItemMasterRequest request,
            Gs2WebSocketSessionTask<DeleteSalesItemMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteSalesItemMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteSalesItemMasterTask() GS2_OVERRIDE = default;
    };

    class CreateSalesItemGroupMasterTask : public detail::Gs2WebSocketSessionTask<CreateSalesItemGroupMasterResult>
    {
    private:
        CreateSalesItemGroupMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "salesItemGroupMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createSalesItemGroupMaster";
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
            if (m_Request.getSalesItemNames())
            {
                jsonWriter.writePropertyName("salesItemNames");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getSalesItemNames();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
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
        CreateSalesItemGroupMasterTask(
            CreateSalesItemGroupMasterRequest request,
            Gs2WebSocketSessionTask<CreateSalesItemGroupMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateSalesItemGroupMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateSalesItemGroupMasterTask() GS2_OVERRIDE = default;
    };

    class GetSalesItemGroupMasterTask : public detail::Gs2WebSocketSessionTask<GetSalesItemGroupMasterResult>
    {
    private:
        GetSalesItemGroupMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "salesItemGroupMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getSalesItemGroupMaster";
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
            if (m_Request.getSalesItemGroupName())
            {
                jsonWriter.writePropertyName("salesItemGroupName");
                jsonWriter.writeCharArray(*m_Request.getSalesItemGroupName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetSalesItemGroupMasterTask(
            GetSalesItemGroupMasterRequest request,
            Gs2WebSocketSessionTask<GetSalesItemGroupMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetSalesItemGroupMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSalesItemGroupMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateSalesItemGroupMasterTask : public detail::Gs2WebSocketSessionTask<UpdateSalesItemGroupMasterResult>
    {
    private:
        UpdateSalesItemGroupMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "salesItemGroupMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateSalesItemGroupMaster";
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
            if (m_Request.getSalesItemGroupName())
            {
                jsonWriter.writePropertyName("salesItemGroupName");
                jsonWriter.writeCharArray(*m_Request.getSalesItemGroupName());
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
            if (m_Request.getSalesItemNames())
            {
                jsonWriter.writePropertyName("salesItemNames");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getSalesItemNames();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
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
        UpdateSalesItemGroupMasterTask(
            UpdateSalesItemGroupMasterRequest request,
            Gs2WebSocketSessionTask<UpdateSalesItemGroupMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateSalesItemGroupMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateSalesItemGroupMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteSalesItemGroupMasterTask : public detail::Gs2WebSocketSessionTask<DeleteSalesItemGroupMasterResult>
    {
    private:
        DeleteSalesItemGroupMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "salesItemGroupMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteSalesItemGroupMaster";
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
            if (m_Request.getSalesItemGroupName())
            {
                jsonWriter.writePropertyName("salesItemGroupName");
                jsonWriter.writeCharArray(*m_Request.getSalesItemGroupName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteSalesItemGroupMasterTask(
            DeleteSalesItemGroupMasterRequest request,
            Gs2WebSocketSessionTask<DeleteSalesItemGroupMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteSalesItemGroupMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteSalesItemGroupMasterTask() GS2_OVERRIDE = default;
    };

    class CreateShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<CreateShowcaseMasterResult>
    {
    private:
        CreateShowcaseMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "showcaseMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createShowcaseMaster";
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
            if (m_Request.getDisplayItems())
            {
                jsonWriter.writePropertyName("displayItems");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getDisplayItems();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getSalesPeriodEventId())
            {
                jsonWriter.writePropertyName("salesPeriodEventId");
                jsonWriter.writeCharArray(*m_Request.getSalesPeriodEventId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateShowcaseMasterTask(
            CreateShowcaseMasterRequest request,
            Gs2WebSocketSessionTask<CreateShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateShowcaseMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateShowcaseMasterTask() GS2_OVERRIDE = default;
    };

    class GetShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<GetShowcaseMasterResult>
    {
    private:
        GetShowcaseMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "showcaseMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getShowcaseMaster";
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
            if (m_Request.getShowcaseName())
            {
                jsonWriter.writePropertyName("showcaseName");
                jsonWriter.writeCharArray(*m_Request.getShowcaseName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetShowcaseMasterTask(
            GetShowcaseMasterRequest request,
            Gs2WebSocketSessionTask<GetShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetShowcaseMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetShowcaseMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<UpdateShowcaseMasterResult>
    {
    private:
        UpdateShowcaseMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "showcaseMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateShowcaseMaster";
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
            if (m_Request.getShowcaseName())
            {
                jsonWriter.writePropertyName("showcaseName");
                jsonWriter.writeCharArray(*m_Request.getShowcaseName());
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
            if (m_Request.getDisplayItems())
            {
                jsonWriter.writePropertyName("displayItems");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getDisplayItems();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    write(jsonWriter, list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getSalesPeriodEventId())
            {
                jsonWriter.writePropertyName("salesPeriodEventId");
                jsonWriter.writeCharArray(*m_Request.getSalesPeriodEventId());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateShowcaseMasterTask(
            UpdateShowcaseMasterRequest request,
            Gs2WebSocketSessionTask<UpdateShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateShowcaseMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateShowcaseMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteShowcaseMasterTask : public detail::Gs2WebSocketSessionTask<DeleteShowcaseMasterResult>
    {
    private:
        DeleteShowcaseMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "showcaseMaster";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteShowcaseMaster";
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
            if (m_Request.getShowcaseName())
            {
                jsonWriter.writePropertyName("showcaseName");
                jsonWriter.writeCharArray(*m_Request.getShowcaseName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteShowcaseMasterTask(
            DeleteShowcaseMasterRequest request,
            Gs2WebSocketSessionTask<DeleteShowcaseMasterResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DeleteShowcaseMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteShowcaseMasterTask() GS2_OVERRIDE = default;
    };

    class GetShowcaseTask : public detail::Gs2WebSocketSessionTask<GetShowcaseResult>
    {
    private:
        GetShowcaseRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getShowcase";
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
            if (m_Request.getShowcaseName())
            {
                jsonWriter.writePropertyName("showcaseName");
                jsonWriter.writeCharArray(*m_Request.getShowcaseName());
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
        GetShowcaseTask(
            GetShowcaseRequest request,
            Gs2WebSocketSessionTask<GetShowcaseResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetShowcaseResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetShowcaseTask() GS2_OVERRIDE = default;
    };

    class GetShowcaseByUserIdTask : public detail::Gs2WebSocketSessionTask<GetShowcaseByUserIdResult>
    {
    private:
        GetShowcaseByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "showcase";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getShowcaseByUserId";
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
            if (m_Request.getShowcaseName())
            {
                jsonWriter.writePropertyName("showcaseName");
                jsonWriter.writeCharArray(*m_Request.getShowcaseName());
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
        GetShowcaseByUserIdTask(
            GetShowcaseByUserIdRequest request,
            Gs2WebSocketSessionTask<GetShowcaseByUserIdResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetShowcaseByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetShowcaseByUserIdTask() GS2_OVERRIDE = default;
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
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
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

    static void write(detail::json::JsonWriter& jsonWriter, const SalesItemMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getSalesItemId())
        {
            jsonWriter.writePropertyName("salesItemId");
            jsonWriter.writeCharArray(*obj.getSalesItemId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const SalesItemGroupMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getSalesItemGroupId())
        {
            jsonWriter.writePropertyName("salesItemGroupId");
            jsonWriter.writeCharArray(*obj.getSalesItemGroupId());
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
        if (obj.getSalesItemNames())
        {
            jsonWriter.writePropertyName("salesItemNames");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getSalesItemNames();
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

    static void write(detail::json::JsonWriter& jsonWriter, const ShowcaseMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getShowcaseId())
        {
            jsonWriter.writePropertyName("showcaseId");
            jsonWriter.writeCharArray(*obj.getShowcaseId());
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
        if (obj.getSalesPeriodEventId())
        {
            jsonWriter.writePropertyName("salesPeriodEventId");
            jsonWriter.writeCharArray(*obj.getSalesPeriodEventId());
        }
        if (obj.getDisplayItems())
        {
            jsonWriter.writePropertyName("displayItems");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getDisplayItems();
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentShowcaseMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const SalesItem& obj)
    {
        jsonWriter.writeObjectStart();
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

    static void write(detail::json::JsonWriter& jsonWriter, const SalesItemGroup& obj)
    {
        jsonWriter.writeObjectStart();
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
        if (obj.getSalesItems())
        {
            jsonWriter.writePropertyName("salesItems");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getSalesItems();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Showcase& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getShowcaseId())
        {
            jsonWriter.writePropertyName("showcaseId");
            jsonWriter.writeCharArray(*obj.getShowcaseId());
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
        if (obj.getSalesPeriodEventId())
        {
            jsonWriter.writePropertyName("salesPeriodEventId");
            jsonWriter.writeCharArray(*obj.getSalesPeriodEventId());
        }
        if (obj.getDisplayItems())
        {
            jsonWriter.writePropertyName("displayItems");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getDisplayItems();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const DisplayItem& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getDisplayItemId())
        {
            jsonWriter.writePropertyName("displayItemId");
            jsonWriter.writeCharArray(*obj.getDisplayItemId());
        }
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeCharArray(*obj.getType());
        }
        if (obj.getSalesItem())
        {
            jsonWriter.writePropertyName("salesItem");
            write(jsonWriter, *obj.getSalesItem());
        }
        if (obj.getSalesItemGroup())
        {
            jsonWriter.writePropertyName("salesItemGroup");
            write(jsonWriter, *obj.getSalesItemGroup());
        }
        if (obj.getSalesPeriodEventId())
        {
            jsonWriter.writePropertyName("salesPeriodEventId");
            jsonWriter.writeCharArray(*obj.getSalesPeriodEventId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const DisplayItemMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getDisplayItemId())
        {
            jsonWriter.writePropertyName("displayItemId");
            jsonWriter.writeCharArray(*obj.getDisplayItemId());
        }
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeCharArray(*obj.getType());
        }
        if (obj.getSalesItemName())
        {
            jsonWriter.writePropertyName("salesItemName");
            jsonWriter.writeCharArray(*obj.getSalesItemName());
        }
        if (obj.getSalesItemGroupName())
        {
            jsonWriter.writePropertyName("salesItemGroupName");
            jsonWriter.writeCharArray(*obj.getSalesItemGroupName());
        }
        if (obj.getSalesPeriodEventId())
        {
            jsonWriter.writePropertyName("salesPeriodEventId");
            jsonWriter.writeCharArray(*obj.getSalesPeriodEventId());
        }
        jsonWriter.writeObjectEnd();
    }


public:
    /**
     * コンストラクタ。
     *
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2ShowcaseWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * 商品マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSalesItemMaster(CreateSalesItemMasterRequest request, std::function<void(AsyncCreateSalesItemMasterResult)> callback)
    {
        CreateSalesItemMasterTask& task = *new CreateSalesItemMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 商品マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSalesItemMaster(GetSalesItemMasterRequest request, std::function<void(AsyncGetSalesItemMasterResult)> callback)
    {
        GetSalesItemMasterTask& task = *new GetSalesItemMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 商品マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSalesItemMaster(UpdateSalesItemMasterRequest request, std::function<void(AsyncUpdateSalesItemMasterResult)> callback)
    {
        UpdateSalesItemMasterTask& task = *new UpdateSalesItemMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 商品マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSalesItemMaster(DeleteSalesItemMasterRequest request, std::function<void(AsyncDeleteSalesItemMasterResult)> callback)
    {
        DeleteSalesItemMasterTask& task = *new DeleteSalesItemMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 商品グループマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSalesItemGroupMaster(CreateSalesItemGroupMasterRequest request, std::function<void(AsyncCreateSalesItemGroupMasterResult)> callback)
    {
        CreateSalesItemGroupMasterTask& task = *new CreateSalesItemGroupMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 商品グループマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSalesItemGroupMaster(GetSalesItemGroupMasterRequest request, std::function<void(AsyncGetSalesItemGroupMasterResult)> callback)
    {
        GetSalesItemGroupMasterTask& task = *new GetSalesItemGroupMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 商品グループマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateSalesItemGroupMaster(UpdateSalesItemGroupMasterRequest request, std::function<void(AsyncUpdateSalesItemGroupMasterResult)> callback)
    {
        UpdateSalesItemGroupMasterTask& task = *new UpdateSalesItemGroupMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 商品グループマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSalesItemGroupMaster(DeleteSalesItemGroupMasterRequest request, std::function<void(AsyncDeleteSalesItemGroupMasterResult)> callback)
    {
        DeleteSalesItemGroupMasterTask& task = *new DeleteSalesItemGroupMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 陳列棚マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createShowcaseMaster(CreateShowcaseMasterRequest request, std::function<void(AsyncCreateShowcaseMasterResult)> callback)
    {
        CreateShowcaseMasterTask& task = *new CreateShowcaseMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 陳列棚マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcaseMaster(GetShowcaseMasterRequest request, std::function<void(AsyncGetShowcaseMasterResult)> callback)
    {
        GetShowcaseMasterTask& task = *new GetShowcaseMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 陳列棚マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateShowcaseMaster(UpdateShowcaseMasterRequest request, std::function<void(AsyncUpdateShowcaseMasterResult)> callback)
    {
        UpdateShowcaseMasterTask& task = *new UpdateShowcaseMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 陳列棚マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteShowcaseMaster(DeleteShowcaseMasterRequest request, std::function<void(AsyncDeleteShowcaseMasterResult)> callback)
    {
        DeleteShowcaseMasterTask& task = *new DeleteShowcaseMasterTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcase(GetShowcaseRequest request, std::function<void(AsyncGetShowcaseResult)> callback)
    {
        GetShowcaseTask& task = *new GetShowcaseTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * ユーザIDを指定して陳列棚を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getShowcaseByUserId(GetShowcaseByUserIdRequest request, std::function<void(AsyncGetShowcaseByUserIdResult)> callback)
    {
        GetShowcaseByUserIdTask& task = *new GetShowcaseByUserIdTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_SHOWCASE_GS2SHOWCASEWEBSOCKETCLIENT_HPP_