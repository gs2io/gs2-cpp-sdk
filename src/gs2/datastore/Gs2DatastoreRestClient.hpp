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

#ifndef GS2_DATASTORE_GS2DATASTORERESTCLIENT_HPP_
#define GS2_DATASTORE_GS2DATASTORERESTCLIENT_HPP_

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
#include "request/DescribeDataObjectsRequest.hpp"
#include "request/DescribeDataObjectsByUserIdRequest.hpp"
#include "request/PrepareUploadRequest.hpp"
#include "request/PrepareUploadByUserIdRequest.hpp"
#include "request/UpdateDataObjectRequest.hpp"
#include "request/UpdateDataObjectByUserIdRequest.hpp"
#include "request/PrepareReUploadRequest.hpp"
#include "request/PrepareReUploadByUserIdRequest.hpp"
#include "request/DoneUploadRequest.hpp"
#include "request/DoneUploadByUserIdRequest.hpp"
#include "request/DeleteDataObjectRequest.hpp"
#include "request/DeleteDataObjectByUserIdRequest.hpp"
#include "request/PrepareDownloadRequest.hpp"
#include "request/PrepareDownloadByUserIdRequest.hpp"
#include "request/PrepareDownloadByGenerationRequest.hpp"
#include "request/PrepareDownloadByGenerationAndUserIdRequest.hpp"
#include "request/PrepareDownloadOwnDataRequest.hpp"
#include "request/PrepareDownloadOwnDataByGenerationRequest.hpp"
#include "request/PrepareDownloadOwnDataByGenerationAndUserIdRequest.hpp"
#include "request/DescribeDataObjectHistoriesRequest.hpp"
#include "request/DescribeDataObjectHistoriesByUserIdRequest.hpp"
#include "request/GetDataObjectHistoryRequest.hpp"
#include "request/GetDataObjectHistoryByUserIdRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeDataObjectsResult.hpp"
#include "result/DescribeDataObjectsByUserIdResult.hpp"
#include "result/PrepareUploadResult.hpp"
#include "result/PrepareUploadByUserIdResult.hpp"
#include "result/UpdateDataObjectResult.hpp"
#include "result/UpdateDataObjectByUserIdResult.hpp"
#include "result/PrepareReUploadResult.hpp"
#include "result/PrepareReUploadByUserIdResult.hpp"
#include "result/DoneUploadResult.hpp"
#include "result/DoneUploadByUserIdResult.hpp"
#include "result/DeleteDataObjectResult.hpp"
#include "result/DeleteDataObjectByUserIdResult.hpp"
#include "result/PrepareDownloadResult.hpp"
#include "result/PrepareDownloadByUserIdResult.hpp"
#include "result/PrepareDownloadByGenerationResult.hpp"
#include "result/PrepareDownloadByGenerationAndUserIdResult.hpp"
#include "result/PrepareDownloadOwnDataResult.hpp"
#include "result/PrepareDownloadOwnDataByGenerationResult.hpp"
#include "result/PrepareDownloadOwnDataByGenerationAndUserIdResult.hpp"
#include "result/DescribeDataObjectHistoriesResult.hpp"
#include "result/DescribeDataObjectHistoriesByUserIdResult.hpp"
#include "result/GetDataObjectHistoryResult.hpp"
#include "result/GetDataObjectHistoryByUserIdResult.hpp"
#include <cstring>

namespace gs2 { namespace datastore {

/**
 * GS2 Datastore API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DatastoreRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
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
            return "datastore";
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
            return "datastore";
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
            return "datastore";
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
            return "datastore";
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
            return "datastore";
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

    class DescribeDataObjectsTask : public detail::Gs2RestSessionTask<DescribeDataObjectsResult>
    {
    private:
        DescribeDataObjectsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/data";
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
            if (m_Request.getStatus())
            {
                url += joint;
                url += "status=";
                url += detail::StringVariable(*m_Request.getStatus(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeDataObjectsTask(
            DescribeDataObjectsRequest request,
            Gs2RestSessionTask<DescribeDataObjectsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeDataObjectsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeDataObjectsTask() GS2_OVERRIDE = default;
    };

    class DescribeDataObjectsByUserIdTask : public detail::Gs2RestSessionTask<DescribeDataObjectsByUserIdResult>
    {
    private:
        DescribeDataObjectsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/data";
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
            if (m_Request.getStatus())
            {
                url += joint;
                url += "status=";
                url += detail::StringVariable(*m_Request.getStatus(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        DescribeDataObjectsByUserIdTask(
            DescribeDataObjectsByUserIdRequest request,
            Gs2RestSessionTask<DescribeDataObjectsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeDataObjectsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeDataObjectsByUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareUploadTask : public detail::Gs2RestSessionTask<PrepareUploadResult>
    {
    private:
        PrepareUploadRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/data/file";
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
            if (m_Request.getContentType())
            {
                jsonWriter.writePropertyName("contentType");
                jsonWriter.writeCharArray(*m_Request.getContentType());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getUpdateIfExists())
            {
                jsonWriter.writePropertyName("updateIfExists");
                jsonWriter.writeBool(*m_Request.getUpdateIfExists());
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
        PrepareUploadTask(
            PrepareUploadRequest request,
            Gs2RestSessionTask<PrepareUploadResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareUploadResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareUploadTask() GS2_OVERRIDE = default;
    };

    class PrepareUploadByUserIdTask : public detail::Gs2RestSessionTask<PrepareUploadByUserIdResult>
    {
    private:
        PrepareUploadByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/data/file";
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
            if (m_Request.getName())
            {
                jsonWriter.writePropertyName("name");
                jsonWriter.writeCharArray(*m_Request.getName());
            }
            if (m_Request.getContentType())
            {
                jsonWriter.writePropertyName("contentType");
                jsonWriter.writeCharArray(*m_Request.getContentType());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
                for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
                {
                    jsonWriter.writeCharArray(list[i]);
                }
                jsonWriter.writeArrayEnd();
            }
            if (m_Request.getUpdateIfExists())
            {
                jsonWriter.writePropertyName("updateIfExists");
                jsonWriter.writeBool(*m_Request.getUpdateIfExists());
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
        PrepareUploadByUserIdTask(
            PrepareUploadByUserIdRequest request,
            Gs2RestSessionTask<PrepareUploadByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareUploadByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareUploadByUserIdTask() GS2_OVERRIDE = default;
    };

    class UpdateDataObjectTask : public detail::Gs2RestSessionTask<UpdateDataObjectResult>
    {
    private:
        UpdateDataObjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/data/{dataObjectName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
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
        UpdateDataObjectTask(
            UpdateDataObjectRequest request,
            Gs2RestSessionTask<UpdateDataObjectResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateDataObjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateDataObjectTask() GS2_OVERRIDE = default;
    };

    class UpdateDataObjectByUserIdTask : public detail::Gs2RestSessionTask<UpdateDataObjectByUserIdResult>
    {
    private:
        UpdateDataObjectByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/data/{dataObjectName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getAllowUserIds())
            {
                jsonWriter.writePropertyName("allowUserIds");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getAllowUserIds();
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
        UpdateDataObjectByUserIdTask(
            UpdateDataObjectByUserIdRequest request,
            Gs2RestSessionTask<UpdateDataObjectByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateDataObjectByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateDataObjectByUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareReUploadTask : public detail::Gs2RestSessionTask<PrepareReUploadResult>
    {
    private:
        PrepareReUploadRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/data/{dataObjectName}/file";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getContentType())
            {
                jsonWriter.writePropertyName("contentType");
                jsonWriter.writeCharArray(*m_Request.getContentType());
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
        PrepareReUploadTask(
            PrepareReUploadRequest request,
            Gs2RestSessionTask<PrepareReUploadResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareReUploadResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareReUploadTask() GS2_OVERRIDE = default;
    };

    class PrepareReUploadByUserIdTask : public detail::Gs2RestSessionTask<PrepareReUploadByUserIdResult>
    {
    private:
        PrepareReUploadByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/data/{dataObjectName}/file";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getContentType())
            {
                jsonWriter.writePropertyName("contentType");
                jsonWriter.writeCharArray(*m_Request.getContentType());
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
        PrepareReUploadByUserIdTask(
            PrepareReUploadByUserIdRequest request,
            Gs2RestSessionTask<PrepareReUploadByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareReUploadByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareReUploadByUserIdTask() GS2_OVERRIDE = default;
    };

    class DoneUploadTask : public detail::Gs2RestSessionTask<DoneUploadResult>
    {
    private:
        DoneUploadRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/data/{dataObjectName}/done";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DoneUploadTask(
            DoneUploadRequest request,
            Gs2RestSessionTask<DoneUploadResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DoneUploadResult>(callback),
            m_Request(std::move(request))
        {}

        ~DoneUploadTask() GS2_OVERRIDE = default;
    };

    class DoneUploadByUserIdTask : public detail::Gs2RestSessionTask<DoneUploadByUserIdResult>
    {
    private:
        DoneUploadByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/data/{dataObjectName}/done";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DoneUploadByUserIdTask(
            DoneUploadByUserIdRequest request,
            Gs2RestSessionTask<DoneUploadByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DoneUploadByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DoneUploadByUserIdTask() GS2_OVERRIDE = default;
    };

    class DeleteDataObjectTask : public detail::Gs2RestSessionTask<DeleteDataObjectResult>
    {
    private:
        DeleteDataObjectRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/data/{dataObjectName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteDataObjectTask(
            DeleteDataObjectRequest request,
            Gs2RestSessionTask<DeleteDataObjectResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteDataObjectResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteDataObjectTask() GS2_OVERRIDE = default;
    };

    class DeleteDataObjectByUserIdTask : public detail::Gs2RestSessionTask<DeleteDataObjectByUserIdResult>
    {
    private:
        DeleteDataObjectByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/data/{dataObjectName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteDataObjectByUserIdTask(
            DeleteDataObjectByUserIdRequest request,
            Gs2RestSessionTask<DeleteDataObjectByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteDataObjectByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteDataObjectByUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadTask : public detail::Gs2RestSessionTask<PrepareDownloadResult>
    {
    private:
        PrepareDownloadRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/file";
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
            if (m_Request.getDataObjectId())
            {
                jsonWriter.writePropertyName("dataObjectId");
                jsonWriter.writeCharArray(*m_Request.getDataObjectId());
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
        PrepareDownloadTask(
            PrepareDownloadRequest request,
            Gs2RestSessionTask<PrepareDownloadResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareDownloadResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadByUserIdTask : public detail::Gs2RestSessionTask<PrepareDownloadByUserIdResult>
    {
    private:
        PrepareDownloadByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/file";
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
            if (m_Request.getDataObjectId())
            {
                jsonWriter.writePropertyName("dataObjectId");
                jsonWriter.writeCharArray(*m_Request.getDataObjectId());
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
        PrepareDownloadByUserIdTask(
            PrepareDownloadByUserIdRequest request,
            Gs2RestSessionTask<PrepareDownloadByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareDownloadByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadByUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadByGenerationTask : public detail::Gs2RestSessionTask<PrepareDownloadByGenerationResult>
    {
    private:
        PrepareDownloadByGenerationRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/file/generation/{generation}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGeneration();
                url.replace("{generation}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getDataObjectId())
            {
                jsonWriter.writePropertyName("dataObjectId");
                jsonWriter.writeCharArray(*m_Request.getDataObjectId());
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
        PrepareDownloadByGenerationTask(
            PrepareDownloadByGenerationRequest request,
            Gs2RestSessionTask<PrepareDownloadByGenerationResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareDownloadByGenerationResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadByGenerationTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadByGenerationAndUserIdTask : public detail::Gs2RestSessionTask<PrepareDownloadByGenerationAndUserIdResult>
    {
    private:
        PrepareDownloadByGenerationAndUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/file/generation/{generation}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGeneration();
                url.replace("{generation}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getDataObjectId())
            {
                jsonWriter.writePropertyName("dataObjectId");
                jsonWriter.writeCharArray(*m_Request.getDataObjectId());
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
        PrepareDownloadByGenerationAndUserIdTask(
            PrepareDownloadByGenerationAndUserIdRequest request,
            Gs2RestSessionTask<PrepareDownloadByGenerationAndUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareDownloadByGenerationAndUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadByGenerationAndUserIdTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadOwnDataTask : public detail::Gs2RestSessionTask<PrepareDownloadOwnDataResult>
    {
    private:
        PrepareDownloadOwnDataRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/file";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        PrepareDownloadOwnDataTask(
            PrepareDownloadOwnDataRequest request,
            Gs2RestSessionTask<PrepareDownloadOwnDataResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareDownloadOwnDataResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadOwnDataTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadOwnDataByGenerationTask : public detail::Gs2RestSessionTask<PrepareDownloadOwnDataByGenerationResult>
    {
    private:
        PrepareDownloadOwnDataByGenerationRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/data/{dataObjectName}/generation/{generation}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGeneration();
                url.replace("{generation}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        PrepareDownloadOwnDataByGenerationTask(
            PrepareDownloadOwnDataByGenerationRequest request,
            Gs2RestSessionTask<PrepareDownloadOwnDataByGenerationResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareDownloadOwnDataByGenerationResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadOwnDataByGenerationTask() GS2_OVERRIDE = default;
    };

    class PrepareDownloadOwnDataByGenerationAndUserIdTask : public detail::Gs2RestSessionTask<PrepareDownloadOwnDataByGenerationAndUserIdResult>
    {
    private:
        PrepareDownloadOwnDataByGenerationAndUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/data/{dataObjectName}/generation/{generation}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGeneration();
                url.replace("{generation}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        PrepareDownloadOwnDataByGenerationAndUserIdTask(
            PrepareDownloadOwnDataByGenerationAndUserIdRequest request,
            Gs2RestSessionTask<PrepareDownloadOwnDataByGenerationAndUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PrepareDownloadOwnDataByGenerationAndUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PrepareDownloadOwnDataByGenerationAndUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeDataObjectHistoriesTask : public detail::Gs2RestSessionTask<DescribeDataObjectHistoriesResult>
    {
    private:
        DescribeDataObjectHistoriesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/data/{dataObjectName}/history";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeDataObjectHistoriesTask(
            DescribeDataObjectHistoriesRequest request,
            Gs2RestSessionTask<DescribeDataObjectHistoriesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeDataObjectHistoriesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeDataObjectHistoriesTask() GS2_OVERRIDE = default;
    };

    class DescribeDataObjectHistoriesByUserIdTask : public detail::Gs2RestSessionTask<DescribeDataObjectHistoriesByUserIdResult>
    {
    private:
        DescribeDataObjectHistoriesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/data/{dataObjectName}/history";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeDataObjectHistoriesByUserIdTask(
            DescribeDataObjectHistoriesByUserIdRequest request,
            Gs2RestSessionTask<DescribeDataObjectHistoriesByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeDataObjectHistoriesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeDataObjectHistoriesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetDataObjectHistoryTask : public detail::Gs2RestSessionTask<GetDataObjectHistoryResult>
    {
    private:
        GetDataObjectHistoryRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/data/{dataObjectName}/history/{generation}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGeneration();
                url.replace("{generation}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetDataObjectHistoryTask(
            GetDataObjectHistoryRequest request,
            Gs2RestSessionTask<GetDataObjectHistoryResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetDataObjectHistoryResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetDataObjectHistoryTask() GS2_OVERRIDE = default;
    };

    class GetDataObjectHistoryByUserIdTask : public detail::Gs2RestSessionTask<GetDataObjectHistoryByUserIdResult>
    {
    private:
        GetDataObjectHistoryByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "datastore";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/data/{dataObjectName}/history/{generation}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getDataObjectName();
                url.replace("{dataObjectName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getGeneration();
                url.replace("{generation}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetDataObjectHistoryByUserIdTask(
            GetDataObjectHistoryByUserIdRequest request,
            Gs2RestSessionTask<GetDataObjectHistoryByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetDataObjectHistoryByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetDataObjectHistoryByUserIdTask() GS2_OVERRIDE = default;
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

    static void write(detail::json::JsonWriter& jsonWriter, const DataObject& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getDataObjectId())
        {
            jsonWriter.writePropertyName("dataObjectId");
            jsonWriter.writeCharArray(*obj.getDataObjectId());
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
        if (obj.getScope())
        {
            jsonWriter.writePropertyName("scope");
            jsonWriter.writeCharArray(*obj.getScope());
        }
        if (obj.getAllowUserIds())
        {
            jsonWriter.writePropertyName("allowUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getAllowUserIds();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeCharArray(list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        if (obj.getPlatform())
        {
            jsonWriter.writePropertyName("platform");
            jsonWriter.writeCharArray(*obj.getPlatform());
        }
        if (obj.getStatus())
        {
            jsonWriter.writePropertyName("status");
            jsonWriter.writeCharArray(*obj.getStatus());
        }
        if (obj.getGeneration())
        {
            jsonWriter.writePropertyName("generation");
            jsonWriter.writeCharArray(*obj.getGeneration());
        }
        if (obj.getPreviousGeneration())
        {
            jsonWriter.writePropertyName("previousGeneration");
            jsonWriter.writeCharArray(*obj.getPreviousGeneration());
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

    static void write(detail::json::JsonWriter& jsonWriter, const DataObjectHistory& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getDataObjectHistoryId())
        {
            jsonWriter.writePropertyName("dataObjectHistoryId");
            jsonWriter.writeCharArray(*obj.getDataObjectHistoryId());
        }
        if (obj.getDataObjectName())
        {
            jsonWriter.writePropertyName("dataObjectName");
            jsonWriter.writeCharArray(*obj.getDataObjectName());
        }
        if (obj.getGeneration())
        {
            jsonWriter.writePropertyName("generation");
            jsonWriter.writeCharArray(*obj.getGeneration());
        }
        if (obj.getContentLength())
        {
            jsonWriter.writePropertyName("contentLength");
            jsonWriter.writeInt64(*obj.getContentLength());
        }
        if (obj.getCreatedAt())
        {
            jsonWriter.writePropertyName("createdAt");
            jsonWriter.writeInt64(*obj.getCreatedAt());
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
    explicit Gs2DatastoreRestClient(Gs2RestSession& gs2RestSession) :
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
	 * データオブジェクトの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDataObjects(DescribeDataObjectsRequest request, std::function<void(AsyncDescribeDataObjectsResult)> callback)
    {
        DescribeDataObjectsTask& task = *new DescribeDataObjectsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * オーナーIDを指定してデータオブジェクトの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDataObjectsByUserId(DescribeDataObjectsByUserIdRequest request, std::function<void(AsyncDescribeDataObjectsByUserIdResult)> callback)
    {
        DescribeDataObjectsByUserIdTask& task = *new DescribeDataObjectsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクトをアップロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareUpload(PrepareUploadRequest request, std::function<void(AsyncPrepareUploadResult)> callback)
    {
        PrepareUploadTask& task = *new PrepareUploadTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトをアップロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareUploadByUserId(PrepareUploadByUserIdRequest request, std::function<void(AsyncPrepareUploadByUserIdResult)> callback)
    {
        PrepareUploadByUserIdTask& task = *new PrepareUploadByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクトを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateDataObject(UpdateDataObjectRequest request, std::function<void(AsyncUpdateDataObjectResult)> callback)
    {
        UpdateDataObjectTask& task = *new UpdateDataObjectTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを更新する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateDataObjectByUserId(UpdateDataObjectByUserIdRequest request, std::function<void(AsyncUpdateDataObjectByUserIdResult)> callback)
    {
        UpdateDataObjectByUserIdTask& task = *new UpdateDataObjectByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクトを再アップロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareReUpload(PrepareReUploadRequest request, std::function<void(AsyncPrepareReUploadResult)> callback)
    {
        PrepareReUploadTask& task = *new PrepareReUploadTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを再アップロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareReUploadByUserId(PrepareReUploadByUserIdRequest request, std::function<void(AsyncPrepareReUploadByUserIdResult)> callback)
    {
        PrepareReUploadByUserIdTask& task = *new PrepareReUploadByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクトのアップロード完了を報告する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doneUpload(DoneUploadRequest request, std::function<void(AsyncDoneUploadResult)> callback)
    {
        DoneUploadTask& task = *new DoneUploadTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトのアップロード完了を報告する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doneUploadByUserId(DoneUploadByUserIdRequest request, std::function<void(AsyncDoneUploadByUserIdResult)> callback)
    {
        DoneUploadByUserIdTask& task = *new DoneUploadByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクトを削除する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDataObject(DeleteDataObjectRequest request, std::function<void(AsyncDeleteDataObjectResult)> callback)
    {
        DeleteDataObjectTask& task = *new DeleteDataObjectTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを削除する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteDataObjectByUserId(DeleteDataObjectByUserIdRequest request, std::function<void(AsyncDeleteDataObjectByUserIdResult)> callback)
    {
        DeleteDataObjectByUserIdTask& task = *new DeleteDataObjectByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクトをダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownload(PrepareDownloadRequest request, std::function<void(AsyncPrepareDownloadResult)> callback)
    {
        PrepareDownloadTask& task = *new PrepareDownloadTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトをダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadByUserId(PrepareDownloadByUserIdRequest request, std::function<void(AsyncPrepareDownloadByUserIdResult)> callback)
    {
        PrepareDownloadByUserIdTask& task = *new PrepareDownloadByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクトを世代を指定してダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadByGeneration(PrepareDownloadByGenerationRequest request, std::function<void(AsyncPrepareDownloadByGenerationResult)> callback)
    {
        PrepareDownloadByGenerationTask& task = *new PrepareDownloadByGenerationTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを世代を指定してダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadByGenerationAndUserId(PrepareDownloadByGenerationAndUserIdRequest request, std::function<void(AsyncPrepareDownloadByGenerationAndUserIdResult)> callback)
    {
        PrepareDownloadByGenerationAndUserIdTask& task = *new PrepareDownloadByGenerationAndUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクトをダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadOwnData(PrepareDownloadOwnDataRequest request, std::function<void(AsyncPrepareDownloadOwnDataResult)> callback)
    {
        PrepareDownloadOwnDataTask& task = *new PrepareDownloadOwnDataTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクトを世代を指定してダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadOwnDataByGeneration(PrepareDownloadOwnDataByGenerationRequest request, std::function<void(AsyncPrepareDownloadOwnDataByGenerationResult)> callback)
    {
        PrepareDownloadOwnDataByGenerationTask& task = *new PrepareDownloadOwnDataByGenerationTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクトを世代を指定してダウンロード準備する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void prepareDownloadOwnDataByGenerationAndUserId(PrepareDownloadOwnDataByGenerationAndUserIdRequest request, std::function<void(AsyncPrepareDownloadOwnDataByGenerationAndUserIdResult)> callback)
    {
        PrepareDownloadOwnDataByGenerationAndUserIdTask& task = *new PrepareDownloadOwnDataByGenerationAndUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクト履歴の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDataObjectHistories(DescribeDataObjectHistoriesRequest request, std::function<void(AsyncDescribeDataObjectHistoriesResult)> callback)
    {
        DescribeDataObjectHistoriesTask& task = *new DescribeDataObjectHistoriesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクト履歴の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeDataObjectHistoriesByUserId(DescribeDataObjectHistoriesByUserIdRequest request, std::function<void(AsyncDescribeDataObjectHistoriesByUserIdResult)> callback)
    {
        DescribeDataObjectHistoriesByUserIdTask& task = *new DescribeDataObjectHistoriesByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * データオブジェクト履歴を取得する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDataObjectHistory(GetDataObjectHistoryRequest request, std::function<void(AsyncGetDataObjectHistoryResult)> callback)
    {
        GetDataObjectHistoryTask& task = *new GetDataObjectHistoryTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してデータオブジェクト履歴を取得する<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getDataObjectHistoryByUserId(GetDataObjectHistoryByUserIdRequest request, std::function<void(AsyncGetDataObjectHistoryByUserIdResult)> callback)
    {
        GetDataObjectHistoryByUserIdTask& task = *new GetDataObjectHistoryByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_DATASTORE_GS2DATASTORERESTCLIENT_HPP_