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

#ifndef GS2_KEY_GS2KEYWEBSOCKETCLIENT_HPP_
#define GS2_KEY_GS2KEYWEBSOCKETCLIENT_HPP_

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
#include "request/DescribeKeysRequest.hpp"
#include "request/CreateKeyRequest.hpp"
#include "request/UpdateKeyRequest.hpp"
#include "request/GetKeyRequest.hpp"
#include "request/DeleteKeyRequest.hpp"
#include "request/EncryptRequest.hpp"
#include "request/DecryptRequest.hpp"
#include "request/DescribeGitHubApiKeysRequest.hpp"
#include "request/CreateGitHubApiKeyRequest.hpp"
#include "request/UpdateGitHubApiKeyRequest.hpp"
#include "request/GetGitHubApiKeyRequest.hpp"
#include "request/DeleteGitHubApiKeyRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeKeysResult.hpp"
#include "result/CreateKeyResult.hpp"
#include "result/UpdateKeyResult.hpp"
#include "result/GetKeyResult.hpp"
#include "result/DeleteKeyResult.hpp"
#include "result/EncryptResult.hpp"
#include "result/DecryptResult.hpp"
#include "result/DescribeGitHubApiKeysResult.hpp"
#include "result/CreateGitHubApiKeyResult.hpp"
#include "result/UpdateGitHubApiKeyResult.hpp"
#include "result/GetGitHubApiKeyResult.hpp"
#include "result/DeleteGitHubApiKeyResult.hpp"
#include <cstring>

namespace gs2 { namespace key {

/**
 * GS2 Key API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2KeyWebSocketClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2WebSocketSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
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
            return "key";
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
            return "key";
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
            return "key";
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
            return "key";
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

    class DeleteNamespaceTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
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
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteNamespaceTask() GS2_OVERRIDE = default;
    };

    class DescribeKeysTask : public detail::Gs2WebSocketSessionTask<DescribeKeysResult>
    {
    private:
        DescribeKeysRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeKeys";
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
        DescribeKeysTask(
            DescribeKeysRequest request,
            Gs2WebSocketSessionTask<DescribeKeysResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeKeysResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeKeysTask() GS2_OVERRIDE = default;
    };

    class CreateKeyTask : public detail::Gs2WebSocketSessionTask<CreateKeyResult>
    {
    private:
        CreateKeyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createKey";
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
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateKeyTask(
            CreateKeyRequest request,
            Gs2WebSocketSessionTask<CreateKeyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateKeyResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateKeyTask() GS2_OVERRIDE = default;
    };

    class UpdateKeyTask : public detail::Gs2WebSocketSessionTask<UpdateKeyResult>
    {
    private:
        UpdateKeyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateKey";
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
            if (m_Request.getKeyName())
            {
                jsonWriter.writePropertyName("keyName");
                jsonWriter.writeCharArray(*m_Request.getKeyName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateKeyTask(
            UpdateKeyRequest request,
            Gs2WebSocketSessionTask<UpdateKeyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateKeyResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateKeyTask() GS2_OVERRIDE = default;
    };

    class GetKeyTask : public detail::Gs2WebSocketSessionTask<GetKeyResult>
    {
    private:
        GetKeyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getKey";
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
            if (m_Request.getKeyName())
            {
                jsonWriter.writePropertyName("keyName");
                jsonWriter.writeCharArray(*m_Request.getKeyName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetKeyTask(
            GetKeyRequest request,
            Gs2WebSocketSessionTask<GetKeyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetKeyResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetKeyTask() GS2_OVERRIDE = default;
    };

    class DeleteKeyTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteKeyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteKey";
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
            if (m_Request.getKeyName())
            {
                jsonWriter.writePropertyName("keyName");
                jsonWriter.writeCharArray(*m_Request.getKeyName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteKeyTask(
            DeleteKeyRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteKeyTask() GS2_OVERRIDE = default;
    };

    class EncryptTask : public detail::Gs2WebSocketSessionTask<EncryptResult>
    {
    private:
        EncryptRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "encrypt";
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
            if (m_Request.getKeyName())
            {
                jsonWriter.writePropertyName("keyName");
                jsonWriter.writeCharArray(*m_Request.getKeyName());
            }
            if (m_Request.getData())
            {
                jsonWriter.writePropertyName("data");
                jsonWriter.writeCharArray(*m_Request.getData());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        EncryptTask(
            EncryptRequest request,
            Gs2WebSocketSessionTask<EncryptResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<EncryptResult>(callback),
            m_Request(std::move(request))
        {}

        ~EncryptTask() GS2_OVERRIDE = default;
    };

    class DecryptTask : public detail::Gs2WebSocketSessionTask<DecryptResult>
    {
    private:
        DecryptRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "decrypt";
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
            if (m_Request.getKeyName())
            {
                jsonWriter.writePropertyName("keyName");
                jsonWriter.writeCharArray(*m_Request.getKeyName());
            }
            if (m_Request.getData())
            {
                jsonWriter.writePropertyName("data");
                jsonWriter.writeCharArray(*m_Request.getData());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DecryptTask(
            DecryptRequest request,
            Gs2WebSocketSessionTask<DecryptResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DecryptResult>(callback),
            m_Request(std::move(request))
        {}

        ~DecryptTask() GS2_OVERRIDE = default;
    };

    class DescribeGitHubApiKeysTask : public detail::Gs2WebSocketSessionTask<DescribeGitHubApiKeysResult>
    {
    private:
        DescribeGitHubApiKeysRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gitHubApiKey";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "describeGitHubApiKeys";
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
        DescribeGitHubApiKeysTask(
            DescribeGitHubApiKeysRequest request,
            Gs2WebSocketSessionTask<DescribeGitHubApiKeysResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<DescribeGitHubApiKeysResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeGitHubApiKeysTask() GS2_OVERRIDE = default;
    };

    class CreateGitHubApiKeyTask : public detail::Gs2WebSocketSessionTask<CreateGitHubApiKeyResult>
    {
    private:
        CreateGitHubApiKeyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gitHubApiKey";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "createGitHubApiKey";
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
            if (m_Request.getApiKey())
            {
                jsonWriter.writePropertyName("apiKey");
                jsonWriter.writeCharArray(*m_Request.getApiKey());
            }
            if (m_Request.getEncryptionKeyName())
            {
                jsonWriter.writePropertyName("encryptionKeyName");
                jsonWriter.writeCharArray(*m_Request.getEncryptionKeyName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        CreateGitHubApiKeyTask(
            CreateGitHubApiKeyRequest request,
            Gs2WebSocketSessionTask<CreateGitHubApiKeyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<CreateGitHubApiKeyResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateGitHubApiKeyTask() GS2_OVERRIDE = default;
    };

    class UpdateGitHubApiKeyTask : public detail::Gs2WebSocketSessionTask<UpdateGitHubApiKeyResult>
    {
    private:
        UpdateGitHubApiKeyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gitHubApiKey";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "updateGitHubApiKey";
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
            if (m_Request.getApiKeyName())
            {
                jsonWriter.writePropertyName("apiKeyName");
                jsonWriter.writeCharArray(*m_Request.getApiKeyName());
            }
            if (m_Request.getDescription())
            {
                jsonWriter.writePropertyName("description");
                jsonWriter.writeCharArray(*m_Request.getDescription());
            }
            if (m_Request.getApiKey())
            {
                jsonWriter.writePropertyName("apiKey");
                jsonWriter.writeCharArray(*m_Request.getApiKey());
            }
            if (m_Request.getEncryptionKeyName())
            {
                jsonWriter.writePropertyName("encryptionKeyName");
                jsonWriter.writeCharArray(*m_Request.getEncryptionKeyName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        UpdateGitHubApiKeyTask(
            UpdateGitHubApiKeyRequest request,
            Gs2WebSocketSessionTask<UpdateGitHubApiKeyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<UpdateGitHubApiKeyResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateGitHubApiKeyTask() GS2_OVERRIDE = default;
    };

    class GetGitHubApiKeyTask : public detail::Gs2WebSocketSessionTask<GetGitHubApiKeyResult>
    {
    private:
        GetGitHubApiKeyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gitHubApiKey";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "getGitHubApiKey";
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
            if (m_Request.getApiKeyName())
            {
                jsonWriter.writePropertyName("apiKeyName");
                jsonWriter.writeCharArray(*m_Request.getApiKeyName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        GetGitHubApiKeyTask(
            GetGitHubApiKeyRequest request,
            Gs2WebSocketSessionTask<GetGitHubApiKeyResult>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<GetGitHubApiKeyResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetGitHubApiKeyTask() GS2_OVERRIDE = default;
    };

    class DeleteGitHubApiKeyTask : public detail::Gs2WebSocketSessionTask<void>
    {
    private:
        DeleteGitHubApiKeyRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "key";
        }

        const char* getComponentName() const GS2_OVERRIDE
        {
            return "gitHubApiKey";
        }

        const char* getFunctionName() const GS2_OVERRIDE
        {
            return "deleteGitHubApiKey";
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
            if (m_Request.getApiKeyName())
            {
                jsonWriter.writePropertyName("apiKeyName");
                jsonWriter.writeCharArray(*m_Request.getApiKeyName());
            }
            if (m_Request.getRequestId())
            {
                jsonWriter.writePropertyName("xGs2RequestId");
                jsonWriter.writeCharArray(*m_Request.getRequestId());
            }
        }

    public:
        DeleteGitHubApiKeyTask(
            DeleteGitHubApiKeyRequest request,
            Gs2WebSocketSessionTask<void>::CallbackType callback
        ) :
            Gs2WebSocketSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteGitHubApiKeyTask() GS2_OVERRIDE = default;
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

    static void write(detail::json::JsonWriter& jsonWriter, const Key& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getKeyId())
        {
            jsonWriter.writePropertyName("keyId");
            jsonWriter.writeCharArray(*obj.getKeyId());
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
        if (obj.getSecret())
        {
            jsonWriter.writePropertyName("secret");
            jsonWriter.writeCharArray(*obj.getSecret());
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

    static void write(detail::json::JsonWriter& jsonWriter, const GitHubApiKey& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getApiKeyId())
        {
            jsonWriter.writePropertyName("apiKeyId");
            jsonWriter.writeCharArray(*obj.getApiKeyId());
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
        if (obj.getApiKey())
        {
            jsonWriter.writePropertyName("apiKey");
            jsonWriter.writeCharArray(*obj.getApiKey());
        }
        if (obj.getEncryptionKeyName())
        {
            jsonWriter.writePropertyName("encryptionKeyName");
            jsonWriter.writeCharArray(*obj.getEncryptionKeyName());
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
     * @param gs2WebSocketSession WebSocket API 用セッション
     */
    explicit Gs2KeyWebSocketClient(Gs2WebSocketSession& gs2WebSocketSession) :
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
	 * 暗号鍵の一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeKeys(DescribeKeysRequest request, std::function<void(AsyncDescribeKeysResult)> callback)
    {
        DescribeKeysTask& task = *new DescribeKeysTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 暗号鍵を新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createKey(CreateKeyRequest request, std::function<void(AsyncCreateKeyResult)> callback)
    {
        CreateKeyTask& task = *new CreateKeyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 暗号鍵を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateKey(UpdateKeyRequest request, std::function<void(AsyncUpdateKeyResult)> callback)
    {
        UpdateKeyTask& task = *new UpdateKeyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 暗号鍵を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getKey(GetKeyRequest request, std::function<void(AsyncGetKeyResult)> callback)
    {
        GetKeyTask& task = *new GetKeyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * 暗号鍵を削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteKey(DeleteKeyRequest request, std::function<void(AsyncDeleteKeyResult)> callback)
    {
        DeleteKeyTask& task = *new DeleteKeyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データを暗号化します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void encrypt(EncryptRequest request, std::function<void(AsyncEncryptResult)> callback)
    {
        EncryptTask& task = *new EncryptTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * データを復号します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void decrypt(DecryptRequest request, std::function<void(AsyncDecryptResult)> callback)
    {
        DecryptTask& task = *new DecryptTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * GitHub のAPIキーの一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGitHubApiKeys(DescribeGitHubApiKeysRequest request, std::function<void(AsyncDescribeGitHubApiKeysResult)> callback)
    {
        DescribeGitHubApiKeysTask& task = *new DescribeGitHubApiKeysTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * GitHub のAPIキーを新規作成します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGitHubApiKey(CreateGitHubApiKeyRequest request, std::function<void(AsyncCreateGitHubApiKeyResult)> callback)
    {
        CreateGitHubApiKeyTask& task = *new CreateGitHubApiKeyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * GitHub のAPIキーを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGitHubApiKey(UpdateGitHubApiKeyRequest request, std::function<void(AsyncUpdateGitHubApiKeyResult)> callback)
    {
        UpdateGitHubApiKeyTask& task = *new UpdateGitHubApiKeyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * GitHub のAPIキーを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGitHubApiKey(GetGitHubApiKeyRequest request, std::function<void(AsyncGetGitHubApiKeyResult)> callback)
    {
        GetGitHubApiKeyTask& task = *new GetGitHubApiKeyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

	/**
	 * GitHub のAPIキーを削除します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGitHubApiKey(DeleteGitHubApiKeyRequest request, std::function<void(AsyncDeleteGitHubApiKeyResult)> callback)
    {
        DeleteGitHubApiKeyTask& task = *new DeleteGitHubApiKeyTask(std::move(request), callback);
        getGs2WebSocketSession().execute(task);
    }

protected:
    Gs2WebSocketSession& getGs2WebSocketSession()
    {
        return static_cast<Gs2WebSocketSession&>(getGs2Session());
    }
};

} }

#endif //GS2_KEY_GS2KEYWEBSOCKETCLIENT_HPP_