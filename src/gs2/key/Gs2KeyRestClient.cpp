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

#include "Gs2KeyRestClient.hpp"
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
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <cstring>

namespace gs2 { namespace key {

namespace {

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj);
void write(detail::json::JsonWriter& jsonWriter, const Key& obj);
void write(detail::json::JsonWriter& jsonWriter, const GitHubApiKey& obj);
void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj);

void write(detail::json::JsonWriter& jsonWriter, const Namespace& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const Key& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const GitHubApiKey& obj)
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

void write(detail::json::JsonWriter& jsonWriter, const LogSetting& obj)
{
    jsonWriter.writeObjectStart();
    if (obj.getLoggingNamespaceId())
    {
        jsonWriter.writePropertyName("loggingNamespaceId");
        jsonWriter.writeCharArray(*obj.getLoggingNamespaceId());
    }
    jsonWriter.writeObjectEnd();
}


class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
{
private:
    DescribeNamespacesRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
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
        return "key";
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
        return "key";
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
        return "key";
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
        return "key";
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
        return "key";
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

class DescribeKeysTask : public detail::Gs2RestSessionTask<DescribeKeysResult>
{
private:
    DescribeKeysRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/key";
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
    DescribeKeysTask(
        DescribeKeysRequest request,
        Gs2RestSessionTask<DescribeKeysResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeKeysResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeKeysTask() GS2_OVERRIDE = default;
};

class CreateKeyTask : public detail::Gs2RestSessionTask<CreateKeyResult>
{
private:
    CreateKeyRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/key";
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
    CreateKeyTask(
        CreateKeyRequest request,
        Gs2RestSessionTask<CreateKeyResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<CreateKeyResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateKeyTask() GS2_OVERRIDE = default;
};

class UpdateKeyTask : public detail::Gs2RestSessionTask<UpdateKeyResult>
{
private:
    UpdateKeyRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/key/{keyName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    UpdateKeyTask(
        UpdateKeyRequest request,
        Gs2RestSessionTask<UpdateKeyResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateKeyResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateKeyTask() GS2_OVERRIDE = default;
};

class GetKeyTask : public detail::Gs2RestSessionTask<GetKeyResult>
{
private:
    GetKeyRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/key/{keyName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetKeyTask(
        GetKeyRequest request,
        Gs2RestSessionTask<GetKeyResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetKeyResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetKeyTask() GS2_OVERRIDE = default;
};

class DeleteKeyTask : public detail::Gs2RestSessionTask<void>
{
private:
    DeleteKeyRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/key/{keyName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    DeleteKeyTask(
        DeleteKeyRequest request,
        Gs2RestSessionTask<void>::CallbackType callback
    ) :
        Gs2RestSessionTask<void>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteKeyTask() GS2_OVERRIDE = default;
};

class EncryptTask : public detail::Gs2RestSessionTask<EncryptResult>
{
private:
    EncryptRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/key/{keyName}/encrypt";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getData())
        {
            jsonWriter.writePropertyName("data");
            jsonWriter.writeCharArray(*m_Request.getData());
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
    EncryptTask(
        EncryptRequest request,
        Gs2RestSessionTask<EncryptResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<EncryptResult>(callback),
        m_Request(std::move(request))
    {}

    ~EncryptTask() GS2_OVERRIDE = default;
};

class DecryptTask : public detail::Gs2RestSessionTask<DecryptResult>
{
private:
    DecryptRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/key/{keyName}/decrypt";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getKeyName();
            url.replace("{keyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        detail::json::JsonWriter jsonWriter;

        jsonWriter.writeObjectStart();
        if (m_Request.getContextStack())
        {
            jsonWriter.writePropertyName("contextStack");
            jsonWriter.writeCharArray(*m_Request.getContextStack());
        }
        if (m_Request.getData())
        {
            jsonWriter.writePropertyName("data");
            jsonWriter.writeCharArray(*m_Request.getData());
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
    DecryptTask(
        DecryptRequest request,
        Gs2RestSessionTask<DecryptResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DecryptResult>(callback),
        m_Request(std::move(request))
    {}

    ~DecryptTask() GS2_OVERRIDE = default;
};

class DescribeGitHubApiKeysTask : public detail::Gs2RestSessionTask<DescribeGitHubApiKeysResult>
{
private:
    DescribeGitHubApiKeysRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/github";
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
    DescribeGitHubApiKeysTask(
        DescribeGitHubApiKeysRequest request,
        Gs2RestSessionTask<DescribeGitHubApiKeysResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<DescribeGitHubApiKeysResult>(callback),
        m_Request(std::move(request))
    {}

    ~DescribeGitHubApiKeysTask() GS2_OVERRIDE = default;
};

class CreateGitHubApiKeyTask : public detail::Gs2RestSessionTask<CreateGitHubApiKeyResult>
{
private:
    CreateGitHubApiKeyRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/github";
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
    CreateGitHubApiKeyTask(
        CreateGitHubApiKeyRequest request,
        Gs2RestSessionTask<CreateGitHubApiKeyResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<CreateGitHubApiKeyResult>(callback),
        m_Request(std::move(request))
    {}

    ~CreateGitHubApiKeyTask() GS2_OVERRIDE = default;
};

class UpdateGitHubApiKeyTask : public detail::Gs2RestSessionTask<UpdateGitHubApiKeyResult>
{
private:
    UpdateGitHubApiKeyRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/github/{apiKeyName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getApiKeyName();
            url.replace("{apiKeyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    UpdateGitHubApiKeyTask(
        UpdateGitHubApiKeyRequest request,
        Gs2RestSessionTask<UpdateGitHubApiKeyResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<UpdateGitHubApiKeyResult>(callback),
        m_Request(std::move(request))
    {}

    ~UpdateGitHubApiKeyTask() GS2_OVERRIDE = default;
};

class GetGitHubApiKeyTask : public detail::Gs2RestSessionTask<GetGitHubApiKeyResult>
{
private:
    GetGitHubApiKeyRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/github/{apiKeyName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getApiKeyName();
            url.replace("{apiKeyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    GetGitHubApiKeyTask(
        GetGitHubApiKeyRequest request,
        Gs2RestSessionTask<GetGitHubApiKeyResult>::CallbackType callback
    ) :
        Gs2RestSessionTask<GetGitHubApiKeyResult>(callback),
        m_Request(std::move(request))
    {}

    ~GetGitHubApiKeyTask() GS2_OVERRIDE = default;
};

class DeleteGitHubApiKeyTask : public detail::Gs2RestSessionTask<void>
{
private:
    DeleteGitHubApiKeyRequest m_Request;

    const char* getServiceName() const GS2_OVERRIDE
    {
        return "key";
    }

    detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
    {
        url += "/{namespaceName}/github/{apiKeyName}";
        {
            auto& value = m_Request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = m_Request.getApiKeyName();
            url.replace("{apiKeyName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
    DeleteGitHubApiKeyTask(
        DeleteGitHubApiKeyRequest request,
        Gs2RestSessionTask<void>::CallbackType callback
    ) :
        Gs2RestSessionTask<void>(callback),
        m_Request(std::move(request))
    {}

    ~DeleteGitHubApiKeyTask() GS2_OVERRIDE = default;
};
}

/**
 * ネームスペースの一覧を取得<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::describeNamespaces(DescribeNamespacesRequest request, std::function<void(AsyncDescribeNamespacesResult)> callback)
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
void Gs2KeyRestClient::createNamespace(CreateNamespaceRequest request, std::function<void(AsyncCreateNamespaceResult)> callback)
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
void Gs2KeyRestClient::getNamespaceStatus(GetNamespaceStatusRequest request, std::function<void(AsyncGetNamespaceStatusResult)> callback)
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
void Gs2KeyRestClient::getNamespace(GetNamespaceRequest request, std::function<void(AsyncGetNamespaceResult)> callback)
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
void Gs2KeyRestClient::updateNamespace(UpdateNamespaceRequest request, std::function<void(AsyncUpdateNamespaceResult)> callback)
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
void Gs2KeyRestClient::deleteNamespace(DeleteNamespaceRequest request, std::function<void(AsyncDeleteNamespaceResult)> callback)
{
    DeleteNamespaceTask& task = *new DeleteNamespaceTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 暗号鍵の一覧を取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::describeKeys(DescribeKeysRequest request, std::function<void(AsyncDescribeKeysResult)> callback)
{
    DescribeKeysTask& task = *new DescribeKeysTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 暗号鍵を新規作成します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::createKey(CreateKeyRequest request, std::function<void(AsyncCreateKeyResult)> callback)
{
    CreateKeyTask& task = *new CreateKeyTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 暗号鍵を更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::updateKey(UpdateKeyRequest request, std::function<void(AsyncUpdateKeyResult)> callback)
{
    UpdateKeyTask& task = *new UpdateKeyTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 暗号鍵を取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::getKey(GetKeyRequest request, std::function<void(AsyncGetKeyResult)> callback)
{
    GetKeyTask& task = *new GetKeyTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * 暗号鍵を削除します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::deleteKey(DeleteKeyRequest request, std::function<void(AsyncDeleteKeyResult)> callback)
{
    DeleteKeyTask& task = *new DeleteKeyTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * データを暗号化します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::encrypt(EncryptRequest request, std::function<void(AsyncEncryptResult)> callback)
{
    EncryptTask& task = *new EncryptTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * データを復号します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::decrypt(DecryptRequest request, std::function<void(AsyncDecryptResult)> callback)
{
    DecryptTask& task = *new DecryptTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * GitHub のAPIキーの一覧を取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::describeGitHubApiKeys(DescribeGitHubApiKeysRequest request, std::function<void(AsyncDescribeGitHubApiKeysResult)> callback)
{
    DescribeGitHubApiKeysTask& task = *new DescribeGitHubApiKeysTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * GitHub のAPIキーを新規作成します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::createGitHubApiKey(CreateGitHubApiKeyRequest request, std::function<void(AsyncCreateGitHubApiKeyResult)> callback)
{
    CreateGitHubApiKeyTask& task = *new CreateGitHubApiKeyTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * GitHub のAPIキーを更新<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::updateGitHubApiKey(UpdateGitHubApiKeyRequest request, std::function<void(AsyncUpdateGitHubApiKeyResult)> callback)
{
    UpdateGitHubApiKeyTask& task = *new UpdateGitHubApiKeyTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * GitHub のAPIキーを取得します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::getGitHubApiKey(GetGitHubApiKeyRequest request, std::function<void(AsyncGetGitHubApiKeyResult)> callback)
{
    GetGitHubApiKeyTask& task = *new GetGitHubApiKeyTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

/**
 * GitHub のAPIキーを削除します<br>
 *
 * @param callback コールバック関数
 * @param request リクエストパラメータ
 */
void Gs2KeyRestClient::deleteGitHubApiKey(DeleteGitHubApiKeyRequest request, std::function<void(AsyncDeleteGitHubApiKeyResult)> callback)
{
    DeleteGitHubApiKeyTask& task = *new DeleteGitHubApiKeyTask(std::move(request), callback);
    getGs2RestSession().execute(task);
}

} }