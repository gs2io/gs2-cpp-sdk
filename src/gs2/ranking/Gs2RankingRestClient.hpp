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

#ifndef GS2_RANKING_GS2RANKINGRESTCLIENT_HPP_
#define GS2_RANKING_GS2RANKINGRESTCLIENT_HPP_

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
#include "request/DescribeCategoryModelsRequest.hpp"
#include "request/GetCategoryModelRequest.hpp"
#include "request/DescribeCategoryModelMastersRequest.hpp"
#include "request/CreateCategoryModelMasterRequest.hpp"
#include "request/GetCategoryModelMasterRequest.hpp"
#include "request/UpdateCategoryModelMasterRequest.hpp"
#include "request/DeleteCategoryModelMasterRequest.hpp"
#include "request/DescribeSubscribesByCategoryNameRequest.hpp"
#include "request/DescribeSubscribesByCategoryNameAndUserIdRequest.hpp"
#include "request/SubscribeRequest.hpp"
#include "request/SubscribeByUserIdRequest.hpp"
#include "request/GetSubscribeRequest.hpp"
#include "request/GetSubscribeByUserIdRequest.hpp"
#include "request/UnsubscribeRequest.hpp"
#include "request/UnsubscribeByUserIdRequest.hpp"
#include "request/DescribeRankingsRequest.hpp"
#include "request/DescribeRankingssByUserIdRequest.hpp"
#include "request/DescribeNearRankingsRequest.hpp"
#include "request/PutScoreRequest.hpp"
#include "request/PutScoreByUserIdRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentRankingMasterRequest.hpp"
#include "request/UpdateCurrentRankingMasterRequest.hpp"
#include "request/UpdateCurrentRankingMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeCategoryModelsResult.hpp"
#include "result/GetCategoryModelResult.hpp"
#include "result/DescribeCategoryModelMastersResult.hpp"
#include "result/CreateCategoryModelMasterResult.hpp"
#include "result/GetCategoryModelMasterResult.hpp"
#include "result/UpdateCategoryModelMasterResult.hpp"
#include "result/DeleteCategoryModelMasterResult.hpp"
#include "result/DescribeSubscribesByCategoryNameResult.hpp"
#include "result/DescribeSubscribesByCategoryNameAndUserIdResult.hpp"
#include "result/SubscribeResult.hpp"
#include "result/SubscribeByUserIdResult.hpp"
#include "result/GetSubscribeResult.hpp"
#include "result/GetSubscribeByUserIdResult.hpp"
#include "result/UnsubscribeResult.hpp"
#include "result/UnsubscribeByUserIdResult.hpp"
#include "result/DescribeRankingsResult.hpp"
#include "result/DescribeRankingssByUserIdResult.hpp"
#include "result/DescribeNearRankingsResult.hpp"
#include "result/PutScoreResult.hpp"
#include "result/PutScoreByUserIdResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentRankingMasterResult.hpp"
#include "result/UpdateCurrentRankingMasterResult.hpp"
#include "result/UpdateCurrentRankingMasterFromGitHubResult.hpp"
#include <cstring>

namespace gs2 { namespace ranking {

/**
 * GS2 Ranking API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2RankingRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
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
            return "ranking";
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
            return "ranking";
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
            return "ranking";
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
            return "ranking";
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
            return "ranking";
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

    class DescribeCategoryModelsTask : public detail::Gs2RestSessionTask<DescribeCategoryModelsResult>
    {
    private:
        DescribeCategoryModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/category";
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
        DescribeCategoryModelsTask(
            DescribeCategoryModelsRequest request,
            Gs2RestSessionTask<DescribeCategoryModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCategoryModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCategoryModelsTask() GS2_OVERRIDE = default;
    };

    class GetCategoryModelTask : public detail::Gs2RestSessionTask<GetCategoryModelResult>
    {
    private:
        GetCategoryModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/category/{categoryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCategoryModelTask(
            GetCategoryModelRequest request,
            Gs2RestSessionTask<GetCategoryModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCategoryModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCategoryModelTask() GS2_OVERRIDE = default;
    };

    class DescribeCategoryModelMastersTask : public detail::Gs2RestSessionTask<DescribeCategoryModelMastersResult>
    {
    private:
        DescribeCategoryModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/category";
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
        DescribeCategoryModelMastersTask(
            DescribeCategoryModelMastersRequest request,
            Gs2RestSessionTask<DescribeCategoryModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeCategoryModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeCategoryModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateCategoryModelMasterTask : public detail::Gs2RestSessionTask<CreateCategoryModelMasterResult>
    {
    private:
        CreateCategoryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/category";
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
            if (m_Request.getMinimumValue())
            {
                jsonWriter.writePropertyName("minimumValue");
                jsonWriter.writeInt64(*m_Request.getMinimumValue());
            }
            if (m_Request.getMaximumValue())
            {
                jsonWriter.writePropertyName("maximumValue");
                jsonWriter.writeInt64(*m_Request.getMaximumValue());
            }
            if (m_Request.getOrderDirection())
            {
                jsonWriter.writePropertyName("orderDirection");
                jsonWriter.writeCharArray(*m_Request.getOrderDirection());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getUniqueByUserId())
            {
                jsonWriter.writePropertyName("uniqueByUserId");
                jsonWriter.writeBool(*m_Request.getUniqueByUserId());
            }
            if (m_Request.getCalculateIntervalMinutes())
            {
                jsonWriter.writePropertyName("calculateIntervalMinutes");
                jsonWriter.writeInt32(*m_Request.getCalculateIntervalMinutes());
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
        CreateCategoryModelMasterTask(
            CreateCategoryModelMasterRequest request,
            Gs2RestSessionTask<CreateCategoryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateCategoryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateCategoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetCategoryModelMasterTask : public detail::Gs2RestSessionTask<GetCategoryModelMasterResult>
    {
    private:
        GetCategoryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/category/{categoryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetCategoryModelMasterTask(
            GetCategoryModelMasterRequest request,
            Gs2RestSessionTask<GetCategoryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCategoryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCategoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCategoryModelMasterTask : public detail::Gs2RestSessionTask<UpdateCategoryModelMasterResult>
    {
    private:
        UpdateCategoryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/category/{categoryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getMinimumValue())
            {
                jsonWriter.writePropertyName("minimumValue");
                jsonWriter.writeInt64(*m_Request.getMinimumValue());
            }
            if (m_Request.getMaximumValue())
            {
                jsonWriter.writePropertyName("maximumValue");
                jsonWriter.writeInt64(*m_Request.getMaximumValue());
            }
            if (m_Request.getOrderDirection())
            {
                jsonWriter.writePropertyName("orderDirection");
                jsonWriter.writeCharArray(*m_Request.getOrderDirection());
            }
            if (m_Request.getScope())
            {
                jsonWriter.writePropertyName("scope");
                jsonWriter.writeCharArray(*m_Request.getScope());
            }
            if (m_Request.getUniqueByUserId())
            {
                jsonWriter.writePropertyName("uniqueByUserId");
                jsonWriter.writeBool(*m_Request.getUniqueByUserId());
            }
            if (m_Request.getCalculateIntervalMinutes())
            {
                jsonWriter.writePropertyName("calculateIntervalMinutes");
                jsonWriter.writeInt32(*m_Request.getCalculateIntervalMinutes());
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
        UpdateCategoryModelMasterTask(
            UpdateCategoryModelMasterRequest request,
            Gs2RestSessionTask<UpdateCategoryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCategoryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCategoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteCategoryModelMasterTask : public detail::Gs2RestSessionTask<DeleteCategoryModelMasterResult>
    {
    private:
        DeleteCategoryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/category/{categoryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteCategoryModelMasterTask(
            DeleteCategoryModelMasterRequest request,
            Gs2RestSessionTask<DeleteCategoryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteCategoryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteCategoryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeSubscribesByCategoryNameTask : public detail::Gs2RestSessionTask<DescribeSubscribesByCategoryNameResult>
    {
    private:
        DescribeSubscribesByCategoryNameRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/subscribe/category/{categoryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeSubscribesByCategoryNameTask(
            DescribeSubscribesByCategoryNameRequest request,
            Gs2RestSessionTask<DescribeSubscribesByCategoryNameResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeSubscribesByCategoryNameResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSubscribesByCategoryNameTask() GS2_OVERRIDE = default;
    };

    class DescribeSubscribesByCategoryNameAndUserIdTask : public detail::Gs2RestSessionTask<DescribeSubscribesByCategoryNameAndUserIdResult>
    {
    private:
        DescribeSubscribesByCategoryNameAndUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/subscribe/category/{categoryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeSubscribesByCategoryNameAndUserIdTask(
            DescribeSubscribesByCategoryNameAndUserIdRequest request,
            Gs2RestSessionTask<DescribeSubscribesByCategoryNameAndUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeSubscribesByCategoryNameAndUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeSubscribesByCategoryNameAndUserIdTask() GS2_OVERRIDE = default;
    };

    class SubscribeTask : public detail::Gs2RestSessionTask<SubscribeResult>
    {
    private:
        SubscribeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/subscribe/category/{categoryName}/target/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        SubscribeTask(
            SubscribeRequest request,
            Gs2RestSessionTask<SubscribeResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SubscribeResult>(callback),
            m_Request(std::move(request))
        {}

        ~SubscribeTask() GS2_OVERRIDE = default;
    };

    class SubscribeByUserIdTask : public detail::Gs2RestSessionTask<SubscribeByUserIdResult>
    {
    private:
        SubscribeByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/subscribe/category/{categoryName}/target/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        SubscribeByUserIdTask(
            SubscribeByUserIdRequest request,
            Gs2RestSessionTask<SubscribeByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<SubscribeByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~SubscribeByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetSubscribeTask : public detail::Gs2RestSessionTask<GetSubscribeResult>
    {
    private:
        GetSubscribeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/subscribe/category/{categoryName}/target/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetSubscribeTask(
            GetSubscribeRequest request,
            Gs2RestSessionTask<GetSubscribeResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetSubscribeResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSubscribeTask() GS2_OVERRIDE = default;
    };

    class GetSubscribeByUserIdTask : public detail::Gs2RestSessionTask<GetSubscribeByUserIdResult>
    {
    private:
        GetSubscribeByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/subscribe/category/{categoryName}/target/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetSubscribeByUserIdTask(
            GetSubscribeByUserIdRequest request,
            Gs2RestSessionTask<GetSubscribeByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetSubscribeByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetSubscribeByUserIdTask() GS2_OVERRIDE = default;
    };

    class UnsubscribeTask : public detail::Gs2RestSessionTask<UnsubscribeResult>
    {
    private:
        UnsubscribeRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/subscribe/category/{categoryName}/target/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        UnsubscribeTask(
            UnsubscribeRequest request,
            Gs2RestSessionTask<UnsubscribeResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UnsubscribeResult>(callback),
            m_Request(std::move(request))
        {}

        ~UnsubscribeTask() GS2_OVERRIDE = default;
    };

    class UnsubscribeByUserIdTask : public detail::Gs2RestSessionTask<UnsubscribeByUserIdResult>
    {
    private:
        UnsubscribeByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/subscribe/category/{categoryName}/target/{targetUserId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTargetUserId();
                url.replace("{targetUserId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        UnsubscribeByUserIdTask(
            UnsubscribeByUserIdRequest request,
            Gs2RestSessionTask<UnsubscribeByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UnsubscribeByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~UnsubscribeByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeRankingsTask : public detail::Gs2RestSessionTask<DescribeRankingsResult>
    {
    private:
        DescribeRankingsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/category/{categoryName}/ranking";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeRankingsTask(
            DescribeRankingsRequest request,
            Gs2RestSessionTask<DescribeRankingsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRankingsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRankingsTask() GS2_OVERRIDE = default;
    };

    class DescribeRankingssByUserIdTask : public detail::Gs2RestSessionTask<DescribeRankingssByUserIdResult>
    {
    private:
        DescribeRankingssByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/category/{categoryName}/ranking";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeRankingssByUserIdTask(
            DescribeRankingssByUserIdRequest request,
            Gs2RestSessionTask<DescribeRankingssByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeRankingssByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeRankingssByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeNearRankingsTask : public detail::Gs2RestSessionTask<DescribeNearRankingsResult>
    {
    private:
        DescribeNearRankingsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/category/{categoryName}/ranking/near";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }

            Char joint[] = { '?', '\0' };
            if (m_Request.getContextStack())
            {
                url += joint;
                url += "contextStack=";
                url += detail::StringVariable(*m_Request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getScore())
            {
                url += joint;
                url += "score=";
                url += detail::StringVariable(*m_Request.getScore()).c_str();
                joint[0] = '&';
            }

            if (m_Request.getRequestId())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-REQUEST-ID", *m_Request.getRequestId());
            }

            return detail::Gs2HttpTask::Verb::Get;
        }

    public:
        DescribeNearRankingsTask(
            DescribeNearRankingsRequest request,
            Gs2RestSessionTask<DescribeNearRankingsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeNearRankingsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeNearRankingsTask() GS2_OVERRIDE = default;
    };

    class PutScoreTask : public detail::Gs2RestSessionTask<PutScoreResult>
    {
    private:
        PutScoreRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/category/{categoryName}/ranking";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getScore())
            {
                jsonWriter.writePropertyName("score");
                jsonWriter.writeInt64(*m_Request.getScore());
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
            if (m_Request.getAccessToken())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-ACCESS-TOKEN", *m_Request.getAccessToken());
            }
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        PutScoreTask(
            PutScoreRequest request,
            Gs2RestSessionTask<PutScoreResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PutScoreResult>(callback),
            m_Request(std::move(request))
        {}

        ~PutScoreTask() GS2_OVERRIDE = default;
    };

    class PutScoreByUserIdTask : public detail::Gs2RestSessionTask<PutScoreByUserIdResult>
    {
    private:
        PutScoreByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/category/{categoryName}/ranking";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCategoryName();
                url.replace("{categoryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getScore())
            {
                jsonWriter.writePropertyName("score");
                jsonWriter.writeInt64(*m_Request.getScore());
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
            if (m_Request.getDuplicationAvoider())
            {
                gs2HttpTask.addHeaderEntry("X-GS2-DUPLICATION-AVOIDER", *m_Request.getDuplicationAvoider());
            }

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        PutScoreByUserIdTask(
            PutScoreByUserIdRequest request,
            Gs2RestSessionTask<PutScoreByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<PutScoreByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~PutScoreByUserIdTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
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

    class GetCurrentRankingMasterTask : public detail::Gs2RestSessionTask<GetCurrentRankingMasterResult>
    {
    private:
        GetCurrentRankingMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
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
        GetCurrentRankingMasterTask(
            GetCurrentRankingMasterRequest request,
            Gs2RestSessionTask<GetCurrentRankingMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentRankingMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentRankingMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentRankingMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentRankingMasterResult>
    {
    private:
        UpdateCurrentRankingMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
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
        UpdateCurrentRankingMasterTask(
            UpdateCurrentRankingMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentRankingMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentRankingMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentRankingMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentRankingMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentRankingMasterFromGitHubResult>
    {
    private:
        UpdateCurrentRankingMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "ranking";
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
        UpdateCurrentRankingMasterFromGitHubTask(
            UpdateCurrentRankingMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentRankingMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentRankingMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentRankingMasterFromGitHubTask() GS2_OVERRIDE = default;
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
        if (obj.getLastCalculatedAts())
        {
            jsonWriter.writePropertyName("lastCalculatedAts");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getLastCalculatedAts();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
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

    static void write(detail::json::JsonWriter& jsonWriter, const CategoryModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCategoryModelId())
        {
            jsonWriter.writePropertyName("categoryModelId");
            jsonWriter.writeCharArray(*obj.getCategoryModelId());
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
        if (obj.getMinimumValue())
        {
            jsonWriter.writePropertyName("minimumValue");
            jsonWriter.writeInt64(*obj.getMinimumValue());
        }
        if (obj.getMaximumValue())
        {
            jsonWriter.writePropertyName("maximumValue");
            jsonWriter.writeInt64(*obj.getMaximumValue());
        }
        if (obj.getOrderDirection())
        {
            jsonWriter.writePropertyName("orderDirection");
            jsonWriter.writeCharArray(*obj.getOrderDirection());
        }
        if (obj.getScope())
        {
            jsonWriter.writePropertyName("scope");
            jsonWriter.writeCharArray(*obj.getScope());
        }
        if (obj.getUniqueByUserId())
        {
            jsonWriter.writePropertyName("uniqueByUserId");
            jsonWriter.writeBool(*obj.getUniqueByUserId());
        }
        if (obj.getCalculateIntervalMinutes())
        {
            jsonWriter.writePropertyName("calculateIntervalMinutes");
            jsonWriter.writeInt32(*obj.getCalculateIntervalMinutes());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CategoryModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCategoryModelId())
        {
            jsonWriter.writePropertyName("categoryModelId");
            jsonWriter.writeCharArray(*obj.getCategoryModelId());
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
        if (obj.getMinimumValue())
        {
            jsonWriter.writePropertyName("minimumValue");
            jsonWriter.writeInt64(*obj.getMinimumValue());
        }
        if (obj.getMaximumValue())
        {
            jsonWriter.writePropertyName("maximumValue");
            jsonWriter.writeInt64(*obj.getMaximumValue());
        }
        if (obj.getOrderDirection())
        {
            jsonWriter.writePropertyName("orderDirection");
            jsonWriter.writeCharArray(*obj.getOrderDirection());
        }
        if (obj.getScope())
        {
            jsonWriter.writePropertyName("scope");
            jsonWriter.writeCharArray(*obj.getScope());
        }
        if (obj.getUniqueByUserId())
        {
            jsonWriter.writePropertyName("uniqueByUserId");
            jsonWriter.writeBool(*obj.getUniqueByUserId());
        }
        if (obj.getCalculateIntervalMinutes())
        {
            jsonWriter.writePropertyName("calculateIntervalMinutes");
            jsonWriter.writeInt32(*obj.getCalculateIntervalMinutes());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Subscribe& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getSubscribeId())
        {
            jsonWriter.writePropertyName("subscribeId");
            jsonWriter.writeCharArray(*obj.getSubscribeId());
        }
        if (obj.getCategoryName())
        {
            jsonWriter.writePropertyName("categoryName");
            jsonWriter.writeCharArray(*obj.getCategoryName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getTargetUserIds())
        {
            jsonWriter.writePropertyName("targetUserIds");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getTargetUserIds();
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
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Score& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getScoreId())
        {
            jsonWriter.writePropertyName("scoreId");
            jsonWriter.writeCharArray(*obj.getScoreId());
        }
        if (obj.getCategoryName())
        {
            jsonWriter.writePropertyName("categoryName");
            jsonWriter.writeCharArray(*obj.getCategoryName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getUniqueId())
        {
            jsonWriter.writePropertyName("uniqueId");
            jsonWriter.writeCharArray(*obj.getUniqueId());
        }
        if (obj.getScorerUserId())
        {
            jsonWriter.writePropertyName("scorerUserId");
            jsonWriter.writeCharArray(*obj.getScorerUserId());
        }
        if (obj.getScore())
        {
            jsonWriter.writePropertyName("score");
            jsonWriter.writeInt64(*obj.getScore());
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
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Ranking& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getRank())
        {
            jsonWriter.writePropertyName("rank");
            jsonWriter.writeInt64(*obj.getRank());
        }
        if (obj.getIndex())
        {
            jsonWriter.writePropertyName("index");
            jsonWriter.writeInt64(*obj.getIndex());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getScore())
        {
            jsonWriter.writePropertyName("score");
            jsonWriter.writeInt64(*obj.getScore());
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

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentRankingMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const CalculatedAt& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCategoryName())
        {
            jsonWriter.writePropertyName("categoryName");
            jsonWriter.writeCharArray(*obj.getCategoryName());
        }
        if (obj.getCalculatedAt())
        {
            jsonWriter.writePropertyName("calculatedAt");
            jsonWriter.writeInt64(*obj.getCalculatedAt());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const SubscribeUser& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getCategoryName())
        {
            jsonWriter.writePropertyName("categoryName");
            jsonWriter.writeCharArray(*obj.getCategoryName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getTargetUserId())
        {
            jsonWriter.writePropertyName("targetUserId");
            jsonWriter.writeCharArray(*obj.getTargetUserId());
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
    explicit Gs2RankingRestClient(Gs2RestSession& gs2RestSession) :
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
	 * カテゴリの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCategoryModels(DescribeCategoryModelsRequest request, std::function<void(AsyncDescribeCategoryModelsResult)> callback)
    {
        DescribeCategoryModelsTask& task = *new DescribeCategoryModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * カテゴリを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCategoryModel(GetCategoryModelRequest request, std::function<void(AsyncGetCategoryModelResult)> callback)
    {
        GetCategoryModelTask& task = *new GetCategoryModelTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * カテゴリマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeCategoryModelMasters(DescribeCategoryModelMastersRequest request, std::function<void(AsyncDescribeCategoryModelMastersResult)> callback)
    {
        DescribeCategoryModelMastersTask& task = *new DescribeCategoryModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * カテゴリマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createCategoryModelMaster(CreateCategoryModelMasterRequest request, std::function<void(AsyncCreateCategoryModelMasterResult)> callback)
    {
        CreateCategoryModelMasterTask& task = *new CreateCategoryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * カテゴリマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCategoryModelMaster(GetCategoryModelMasterRequest request, std::function<void(AsyncGetCategoryModelMasterResult)> callback)
    {
        GetCategoryModelMasterTask& task = *new GetCategoryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * カテゴリマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCategoryModelMaster(UpdateCategoryModelMasterRequest request, std::function<void(AsyncUpdateCategoryModelMasterResult)> callback)
    {
        UpdateCategoryModelMasterTask& task = *new UpdateCategoryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * カテゴリマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCategoryModelMaster(DeleteCategoryModelMasterRequest request, std::function<void(AsyncDeleteCategoryModelMasterResult)> callback)
    {
        DeleteCategoryModelMasterTask& task = *new DeleteCategoryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 購読しているユーザIDの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribesByCategoryName(DescribeSubscribesByCategoryNameRequest request, std::function<void(AsyncDescribeSubscribesByCategoryNameResult)> callback)
    {
        DescribeSubscribesByCategoryNameTask& task = *new DescribeSubscribesByCategoryNameTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して購読しているユーザIDの一覧取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribesByCategoryNameAndUserId(DescribeSubscribesByCategoryNameAndUserIdRequest request, std::function<void(AsyncDescribeSubscribesByCategoryNameAndUserIdResult)> callback)
    {
        DescribeSubscribesByCategoryNameAndUserIdTask& task = *new DescribeSubscribesByCategoryNameAndUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを購読<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void subscribe(SubscribeRequest request, std::function<void(AsyncSubscribeResult)> callback)
    {
        SubscribeTask& task = *new SubscribeTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してユーザIDを購読<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void subscribeByUserId(SubscribeByUserIdRequest request, std::function<void(AsyncSubscribeByUserIdResult)> callback)
    {
        SubscribeByUserIdTask& task = *new SubscribeByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 購読を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribe(GetSubscribeRequest request, std::function<void(AsyncGetSubscribeResult)> callback)
    {
        GetSubscribeTask& task = *new GetSubscribeTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して購読を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribeByUserId(GetSubscribeByUserIdRequest request, std::function<void(AsyncGetSubscribeByUserIdResult)> callback)
    {
        GetSubscribeByUserIdTask& task = *new GetSubscribeByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 購読の購読を解除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unsubscribe(UnsubscribeRequest request, std::function<void(AsyncUnsubscribeResult)> callback)
    {
        UnsubscribeTask& task = *new UnsubscribeTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して購読の購読を解除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void unsubscribeByUserId(UnsubscribeByUserIdRequest request, std::function<void(AsyncUnsubscribeByUserIdResult)> callback)
    {
        UnsubscribeByUserIdTask& task = *new UnsubscribeByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ランキングを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRankings(DescribeRankingsRequest request, std::function<void(AsyncDescribeRankingsResult)> callback)
    {
        DescribeRankingsTask& task = *new DescribeRankingsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してランキングを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRankingssByUserId(DescribeRankingssByUserIdRequest request, std::function<void(AsyncDescribeRankingssByUserIdResult)> callback)
    {
        DescribeRankingssByUserIdTask& task = *new DescribeRankingssByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 指定したスコア付近のランキングを取得<br>
	 *   <br>
	 *   このAPIはグローバルランキングのときのみ使用できます<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNearRankings(DescribeNearRankingsRequest request, std::function<void(AsyncDescribeNearRankingsResult)> callback)
    {
        DescribeNearRankingsTask& task = *new DescribeNearRankingsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スコアを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void putScore(PutScoreRequest request, std::function<void(AsyncPutScoreResult)> callback)
    {
        PutScoreTask& task = *new PutScoreTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してスコアを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void putScoreByUserId(PutScoreByUserIdRequest request, std::function<void(AsyncPutScoreByUserIdResult)> callback)
    {
        PutScoreByUserIdTask& task = *new PutScoreByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なランキング設定のマスターデータをエクスポートします<br>
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
	 * 現在有効なランキング設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentRankingMaster(GetCurrentRankingMasterRequest request, std::function<void(AsyncGetCurrentRankingMasterResult)> callback)
    {
        GetCurrentRankingMasterTask& task = *new GetCurrentRankingMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なランキング設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentRankingMaster(UpdateCurrentRankingMasterRequest request, std::function<void(AsyncUpdateCurrentRankingMasterResult)> callback)
    {
        UpdateCurrentRankingMasterTask& task = *new UpdateCurrentRankingMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効なランキング設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentRankingMasterFromGitHub(UpdateCurrentRankingMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentRankingMasterFromGitHubResult)> callback)
    {
        UpdateCurrentRankingMasterFromGitHubTask& task = *new UpdateCurrentRankingMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_RANKING_GS2RANKINGRESTCLIENT_HPP_