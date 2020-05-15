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

#ifndef GS2_DICTIONARY_GS2DICTIONARYRESTCLIENT_HPP_
#define GS2_DICTIONARY_GS2DICTIONARYRESTCLIENT_HPP_

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
#include "request/DescribeEntryModelsRequest.hpp"
#include "request/GetEntryModelRequest.hpp"
#include "request/DescribeEntryModelMastersRequest.hpp"
#include "request/CreateEntryModelMasterRequest.hpp"
#include "request/GetEntryModelMasterRequest.hpp"
#include "request/UpdateEntryModelMasterRequest.hpp"
#include "request/DeleteEntryModelMasterRequest.hpp"
#include "request/DescribeEntriesRequest.hpp"
#include "request/DescribeEntriesByUserIdRequest.hpp"
#include "request/AddEntriesByUserIdRequest.hpp"
#include "request/GetEntryRequest.hpp"
#include "request/GetEntryByUserIdRequest.hpp"
#include "request/GetEntryWithSignatureRequest.hpp"
#include "request/GetEntryWithSignatureByUserIdRequest.hpp"
#include "request/ResetByUserIdRequest.hpp"
#include "request/AddEntriesByStampSheetRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentEntryMasterRequest.hpp"
#include "request/UpdateCurrentEntryMasterRequest.hpp"
#include "request/UpdateCurrentEntryMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeEntryModelsResult.hpp"
#include "result/GetEntryModelResult.hpp"
#include "result/DescribeEntryModelMastersResult.hpp"
#include "result/CreateEntryModelMasterResult.hpp"
#include "result/GetEntryModelMasterResult.hpp"
#include "result/UpdateEntryModelMasterResult.hpp"
#include "result/DeleteEntryModelMasterResult.hpp"
#include "result/DescribeEntriesResult.hpp"
#include "result/DescribeEntriesByUserIdResult.hpp"
#include "result/AddEntriesByUserIdResult.hpp"
#include "result/GetEntryResult.hpp"
#include "result/GetEntryByUserIdResult.hpp"
#include "result/GetEntryWithSignatureResult.hpp"
#include "result/GetEntryWithSignatureByUserIdResult.hpp"
#include "result/ResetByUserIdResult.hpp"
#include "result/AddEntriesByStampSheetResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentEntryMasterResult.hpp"
#include "result/UpdateCurrentEntryMasterResult.hpp"
#include "result/UpdateCurrentEntryMasterFromGitHubResult.hpp"
#include <cstring>

namespace gs2 { namespace dictionary {

/**
 * GS2 Dictionary API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DictionaryRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
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
            return "dictionary";
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
            return "dictionary";
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
            return "dictionary";
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
            return "dictionary";
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

    class DeleteNamespaceTask : public detail::Gs2RestSessionTask<DeleteNamespaceResult>
    {
    private:
        DeleteNamespaceRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
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

    class DescribeEntryModelsTask : public detail::Gs2RestSessionTask<DescribeEntryModelsResult>
    {
    private:
        DescribeEntryModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/model";
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
        DescribeEntryModelsTask(
            DescribeEntryModelsRequest request,
            Gs2RestSessionTask<DescribeEntryModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeEntryModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeEntryModelsTask() GS2_OVERRIDE = default;
    };

    class GetEntryModelTask : public detail::Gs2RestSessionTask<GetEntryModelResult>
    {
    private:
        GetEntryModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/model/{entryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getEntryName();
                url.replace("{entryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetEntryModelTask(
            GetEntryModelRequest request,
            Gs2RestSessionTask<GetEntryModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetEntryModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryModelTask() GS2_OVERRIDE = default;
    };

    class DescribeEntryModelMastersTask : public detail::Gs2RestSessionTask<DescribeEntryModelMastersResult>
    {
    private:
        DescribeEntryModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model";
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
        DescribeEntryModelMastersTask(
            DescribeEntryModelMastersRequest request,
            Gs2RestSessionTask<DescribeEntryModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeEntryModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeEntryModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateEntryModelMasterTask : public detail::Gs2RestSessionTask<CreateEntryModelMasterResult>
    {
    private:
        CreateEntryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model";
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
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
        CreateEntryModelMasterTask(
            CreateEntryModelMasterRequest request,
            Gs2RestSessionTask<CreateEntryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateEntryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateEntryModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetEntryModelMasterTask : public detail::Gs2RestSessionTask<GetEntryModelMasterResult>
    {
    private:
        GetEntryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{entryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getEntryName();
                url.replace("{entryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetEntryModelMasterTask(
            GetEntryModelMasterRequest request,
            Gs2RestSessionTask<GetEntryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetEntryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateEntryModelMasterTask : public detail::Gs2RestSessionTask<UpdateEntryModelMasterResult>
    {
    private:
        UpdateEntryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{entryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getEntryName();
                url.replace("{entryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getMetadata())
            {
                jsonWriter.writePropertyName("metadata");
                jsonWriter.writeCharArray(*m_Request.getMetadata());
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
        UpdateEntryModelMasterTask(
            UpdateEntryModelMasterRequest request,
            Gs2RestSessionTask<UpdateEntryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateEntryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateEntryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteEntryModelMasterTask : public detail::Gs2RestSessionTask<DeleteEntryModelMasterResult>
    {
    private:
        DeleteEntryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/model/{entryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getEntryName();
                url.replace("{entryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteEntryModelMasterTask(
            DeleteEntryModelMasterRequest request,
            Gs2RestSessionTask<DeleteEntryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteEntryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteEntryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeEntriesTask : public detail::Gs2RestSessionTask<DescribeEntriesResult>
    {
    private:
        DescribeEntriesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/entry";
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
        DescribeEntriesTask(
            DescribeEntriesRequest request,
            Gs2RestSessionTask<DescribeEntriesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeEntriesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeEntriesTask() GS2_OVERRIDE = default;
    };

    class DescribeEntriesByUserIdTask : public detail::Gs2RestSessionTask<DescribeEntriesByUserIdResult>
    {
    private:
        DescribeEntriesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/entry";
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
        DescribeEntriesByUserIdTask(
            DescribeEntriesByUserIdRequest request,
            Gs2RestSessionTask<DescribeEntriesByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeEntriesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeEntriesByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddEntriesByUserIdTask : public detail::Gs2RestSessionTask<AddEntriesByUserIdResult>
    {
    private:
        AddEntriesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/entry";
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
            if (m_Request.getEntryModelNames())
            {
                jsonWriter.writePropertyName("entryModelNames");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getEntryModelNames();
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

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        AddEntriesByUserIdTask(
            AddEntriesByUserIdRequest request,
            Gs2RestSessionTask<AddEntriesByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AddEntriesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddEntriesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetEntryTask : public detail::Gs2RestSessionTask<GetEntryResult>
    {
    private:
        GetEntryRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/entry/{entryModelName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getEntryModelName();
                url.replace("{entryModelName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetEntryTask(
            GetEntryRequest request,
            Gs2RestSessionTask<GetEntryResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetEntryResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryTask() GS2_OVERRIDE = default;
    };

    class GetEntryByUserIdTask : public detail::Gs2RestSessionTask<GetEntryByUserIdResult>
    {
    private:
        GetEntryByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/entry/{entryModelName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getEntryModelName();
                url.replace("{entryModelName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetEntryByUserIdTask(
            GetEntryByUserIdRequest request,
            Gs2RestSessionTask<GetEntryByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetEntryByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetEntryWithSignatureTask : public detail::Gs2RestSessionTask<GetEntryWithSignatureResult>
    {
    private:
        GetEntryWithSignatureRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/entry/{entryModelName}/signature";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getEntryModelName();
                url.replace("{entryModelName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getKeyId())
            {
                url += joint;
                url += "keyId=";
                url += detail::StringVariable(*m_Request.getKeyId(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        GetEntryWithSignatureTask(
            GetEntryWithSignatureRequest request,
            Gs2RestSessionTask<GetEntryWithSignatureResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetEntryWithSignatureResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryWithSignatureTask() GS2_OVERRIDE = default;
    };

    class GetEntryWithSignatureByUserIdTask : public detail::Gs2RestSessionTask<GetEntryWithSignatureByUserIdResult>
    {
    private:
        GetEntryWithSignatureByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/entry/{entryModelName}/signature";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getEntryModelName();
                url.replace("{entryModelName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getKeyId())
            {
                url += joint;
                url += "keyId=";
                url += detail::StringVariable(*m_Request.getKeyId(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        GetEntryWithSignatureByUserIdTask(
            GetEntryWithSignatureByUserIdRequest request,
            Gs2RestSessionTask<GetEntryWithSignatureByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetEntryWithSignatureByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetEntryWithSignatureByUserIdTask() GS2_OVERRIDE = default;
    };

    class ResetByUserIdTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        ResetByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/entry";
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
        ResetByUserIdTask(
            ResetByUserIdRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~ResetByUserIdTask() GS2_OVERRIDE = default;
    };

    class AddEntriesByStampSheetTask : public detail::Gs2RestSessionTask<AddEntriesByStampSheetResult>
    {
    private:
        AddEntriesByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/entry/add";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
        AddEntriesByStampSheetTask(
            AddEntriesByStampSheetRequest request,
            Gs2RestSessionTask<AddEntriesByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<AddEntriesByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~AddEntriesByStampSheetTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
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

    class GetCurrentEntryMasterTask : public detail::Gs2RestSessionTask<GetCurrentEntryMasterResult>
    {
    private:
        GetCurrentEntryMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
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
        GetCurrentEntryMasterTask(
            GetCurrentEntryMasterRequest request,
            Gs2RestSessionTask<GetCurrentEntryMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentEntryMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentEntryMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentEntryMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentEntryMasterResult>
    {
    private:
        UpdateCurrentEntryMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
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
        UpdateCurrentEntryMasterTask(
            UpdateCurrentEntryMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentEntryMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentEntryMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentEntryMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentEntryMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentEntryMasterFromGitHubResult>
    {
    private:
        UpdateCurrentEntryMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "dictionary";
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
        UpdateCurrentEntryMasterFromGitHubTask(
            UpdateCurrentEntryMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentEntryMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentEntryMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentEntryMasterFromGitHubTask() GS2_OVERRIDE = default;
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

    static void write(detail::json::JsonWriter& jsonWriter, const EntryModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getEntryModelId())
        {
            jsonWriter.writePropertyName("entryModelId");
            jsonWriter.writeCharArray(*obj.getEntryModelId());
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
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const EntryModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getEntryModelId())
        {
            jsonWriter.writePropertyName("entryModelId");
            jsonWriter.writeCharArray(*obj.getEntryModelId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Entry& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getEntryId())
        {
            jsonWriter.writePropertyName("entryId");
            jsonWriter.writeCharArray(*obj.getEntryId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getName())
        {
            jsonWriter.writePropertyName("name");
            jsonWriter.writeCharArray(*obj.getName());
        }
        if (obj.getAcquiredAt())
        {
            jsonWriter.writePropertyName("acquiredAt");
            jsonWriter.writeInt64(*obj.getAcquiredAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Toc& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTocId())
        {
            jsonWriter.writePropertyName("tocId");
            jsonWriter.writeCharArray(*obj.getTocId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getIndex())
        {
            jsonWriter.writePropertyName("index");
            jsonWriter.writeInt32(*obj.getIndex());
        }
        if (obj.getEntries())
        {
            jsonWriter.writePropertyName("entries");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getEntries();
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentEntryMaster& obj)
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2DictionaryRestClient(Gs2RestSession& gs2RestSession) :
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
	 * エントリーモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEntryModels(DescribeEntryModelsRequest request, std::function<void(AsyncDescribeEntryModelsResult)> callback)
    {
        DescribeEntryModelsTask& task = *new DescribeEntryModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryModel(GetEntryModelRequest request, std::function<void(AsyncGetEntryModelResult)> callback)
    {
        GetEntryModelTask& task = *new GetEntryModelTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEntryModelMasters(DescribeEntryModelMastersRequest request, std::function<void(AsyncDescribeEntryModelMastersResult)> callback)
    {
        DescribeEntryModelMastersTask& task = *new DescribeEntryModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createEntryModelMaster(CreateEntryModelMasterRequest request, std::function<void(AsyncCreateEntryModelMasterResult)> callback)
    {
        CreateEntryModelMasterTask& task = *new CreateEntryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryModelMaster(GetEntryModelMasterRequest request, std::function<void(AsyncGetEntryModelMasterResult)> callback)
    {
        GetEntryModelMasterTask& task = *new GetEntryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateEntryModelMaster(UpdateEntryModelMasterRequest request, std::function<void(AsyncUpdateEntryModelMasterResult)> callback)
    {
        UpdateEntryModelMasterTask& task = *new UpdateEntryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteEntryModelMaster(DeleteEntryModelMasterRequest request, std::function<void(AsyncDeleteEntryModelMasterResult)> callback)
    {
        DeleteEntryModelMasterTask& task = *new DeleteEntryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEntries(DescribeEntriesRequest request, std::function<void(AsyncDescribeEntriesResult)> callback)
    {
        DescribeEntriesTask& task = *new DescribeEntriesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してエントリーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEntriesByUserId(DescribeEntriesByUserIdRequest request, std::function<void(AsyncDescribeEntriesByUserIdResult)> callback)
    {
        DescribeEntriesByUserIdTask& task = *new DescribeEntriesByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してエントリーを入手済みとして登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addEntriesByUserId(AddEntriesByUserIdRequest request, std::function<void(AsyncAddEntriesByUserIdResult)> callback)
    {
        AddEntriesByUserIdTask& task = *new AddEntriesByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntry(GetEntryRequest request, std::function<void(AsyncGetEntryResult)> callback)
    {
        GetEntryTask& task = *new GetEntryTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してエントリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryByUserId(GetEntryByUserIdRequest request, std::function<void(AsyncGetEntryByUserIdResult)> callback)
    {
        GetEntryByUserIdTask& task = *new GetEntryByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryWithSignature(GetEntryWithSignatureRequest request, std::function<void(AsyncGetEntryWithSignatureResult)> callback)
    {
        GetEntryWithSignatureTask& task = *new GetEntryWithSignatureTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してエントリーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEntryWithSignatureByUserId(GetEntryWithSignatureByUserIdRequest request, std::function<void(AsyncGetEntryWithSignatureByUserIdResult)> callback)
    {
        GetEntryWithSignatureByUserIdTask& task = *new GetEntryWithSignatureByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * エントリーをリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetByUserId(ResetByUserIdRequest request, std::function<void(AsyncResetByUserIdResult)> callback)
    {
        ResetByUserIdTask& task = *new ResetByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートでエントリーを追加<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addEntriesByStampSheet(AddEntriesByStampSheetRequest request, std::function<void(AsyncAddEntriesByStampSheetResult)> callback)
    {
        AddEntriesByStampSheetTask& task = *new AddEntriesByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なエントリー設定のマスターデータをエクスポートします<br>
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
	 * 現在有効なエントリー設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentEntryMaster(GetCurrentEntryMasterRequest request, std::function<void(AsyncGetCurrentEntryMasterResult)> callback)
    {
        GetCurrentEntryMasterTask& task = *new GetCurrentEntryMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なエントリー設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEntryMaster(UpdateCurrentEntryMasterRequest request, std::function<void(AsyncUpdateCurrentEntryMasterResult)> callback)
    {
        UpdateCurrentEntryMasterTask& task = *new UpdateCurrentEntryMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なエントリー設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEntryMasterFromGitHub(UpdateCurrentEntryMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentEntryMasterFromGitHubResult)> callback)
    {
        UpdateCurrentEntryMasterFromGitHubTask& task = *new UpdateCurrentEntryMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_DICTIONARY_GS2DICTIONARYRESTCLIENT_HPP_