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

#ifndef GS2_LOTTERY_GS2LOTTERYRESTCLIENT_HPP_
#define GS2_LOTTERY_GS2LOTTERYRESTCLIENT_HPP_

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
#include "request/DescribeLotteryModelMastersRequest.hpp"
#include "request/CreateLotteryModelMasterRequest.hpp"
#include "request/GetLotteryModelMasterRequest.hpp"
#include "request/UpdateLotteryModelMasterRequest.hpp"
#include "request/DeleteLotteryModelMasterRequest.hpp"
#include "request/DescribePrizeTableMastersRequest.hpp"
#include "request/CreatePrizeTableMasterRequest.hpp"
#include "request/GetPrizeTableMasterRequest.hpp"
#include "request/UpdatePrizeTableMasterRequest.hpp"
#include "request/DeletePrizeTableMasterRequest.hpp"
#include "request/DescribeBoxesRequest.hpp"
#include "request/DescribeBoxesByUserIdRequest.hpp"
#include "request/GetBoxRequest.hpp"
#include "request/GetBoxByUserIdRequest.hpp"
#include "request/ResetBoxRequest.hpp"
#include "request/ResetBoxByUserIdRequest.hpp"
#include "request/DescribeLotteryModelsRequest.hpp"
#include "request/GetLotteryModelRequest.hpp"
#include "request/DescribePrizeTablesRequest.hpp"
#include "request/GetPrizeTableRequest.hpp"
#include "request/DrawByUserIdRequest.hpp"
#include "request/DescribeProbabilitiesRequest.hpp"
#include "request/DescribeProbabilitiesByUserIdRequest.hpp"
#include "request/DrawByStampSheetRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentLotteryMasterRequest.hpp"
#include "request/UpdateCurrentLotteryMasterRequest.hpp"
#include "request/UpdateCurrentLotteryMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeLotteryModelMastersResult.hpp"
#include "result/CreateLotteryModelMasterResult.hpp"
#include "result/GetLotteryModelMasterResult.hpp"
#include "result/UpdateLotteryModelMasterResult.hpp"
#include "result/DeleteLotteryModelMasterResult.hpp"
#include "result/DescribePrizeTableMastersResult.hpp"
#include "result/CreatePrizeTableMasterResult.hpp"
#include "result/GetPrizeTableMasterResult.hpp"
#include "result/UpdatePrizeTableMasterResult.hpp"
#include "result/DeletePrizeTableMasterResult.hpp"
#include "result/DescribeBoxesResult.hpp"
#include "result/DescribeBoxesByUserIdResult.hpp"
#include "result/GetBoxResult.hpp"
#include "result/GetBoxByUserIdResult.hpp"
#include "result/ResetBoxResult.hpp"
#include "result/ResetBoxByUserIdResult.hpp"
#include "result/DescribeLotteryModelsResult.hpp"
#include "result/GetLotteryModelResult.hpp"
#include "result/DescribePrizeTablesResult.hpp"
#include "result/GetPrizeTableResult.hpp"
#include "result/DrawByUserIdResult.hpp"
#include "result/DescribeProbabilitiesResult.hpp"
#include "result/DescribeProbabilitiesByUserIdResult.hpp"
#include "result/DrawByStampSheetResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentLotteryMasterResult.hpp"
#include "result/UpdateCurrentLotteryMasterResult.hpp"
#include "result/UpdateCurrentLotteryMasterFromGitHubResult.hpp"
#include <cstring>

namespace gs2 { namespace lottery {

/**
 * GS2 Lottery API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2LotteryRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
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
            return "lottery";
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
            if (m_Request.getLotteryTriggerScriptId())
            {
                jsonWriter.writePropertyName("lotteryTriggerScriptId");
                jsonWriter.writeCharArray(*m_Request.getLotteryTriggerScriptId());
            }
            if (m_Request.getChoicePrizeTableScriptId())
            {
                jsonWriter.writePropertyName("choicePrizeTableScriptId");
                jsonWriter.writeCharArray(*m_Request.getChoicePrizeTableScriptId());
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
            return "lottery";
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
            return "lottery";
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
            return "lottery";
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
            if (m_Request.getLotteryTriggerScriptId())
            {
                jsonWriter.writePropertyName("lotteryTriggerScriptId");
                jsonWriter.writeCharArray(*m_Request.getLotteryTriggerScriptId());
            }
            if (m_Request.getChoicePrizeTableScriptId())
            {
                jsonWriter.writePropertyName("choicePrizeTableScriptId");
                jsonWriter.writeCharArray(*m_Request.getChoicePrizeTableScriptId());
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
            return "lottery";
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

    class DescribeLotteryModelMastersTask : public detail::Gs2RestSessionTask<DescribeLotteryModelMastersResult>
    {
    private:
        DescribeLotteryModelMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/lottery";
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
        DescribeLotteryModelMastersTask(
            DescribeLotteryModelMastersRequest request,
            Gs2RestSessionTask<DescribeLotteryModelMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeLotteryModelMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeLotteryModelMastersTask() GS2_OVERRIDE = default;
    };

    class CreateLotteryModelMasterTask : public detail::Gs2RestSessionTask<CreateLotteryModelMasterResult>
    {
    private:
        CreateLotteryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/lottery";
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
            if (m_Request.getMode())
            {
                jsonWriter.writePropertyName("mode");
                jsonWriter.writeCharArray(*m_Request.getMode());
            }
            if (m_Request.getMethod())
            {
                jsonWriter.writePropertyName("method");
                jsonWriter.writeCharArray(*m_Request.getMethod());
            }
            if (m_Request.getPrizeTableName())
            {
                jsonWriter.writePropertyName("prizeTableName");
                jsonWriter.writeCharArray(*m_Request.getPrizeTableName());
            }
            if (m_Request.getChoicePrizeTableScriptId())
            {
                jsonWriter.writePropertyName("choicePrizeTableScriptId");
                jsonWriter.writeCharArray(*m_Request.getChoicePrizeTableScriptId());
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
        CreateLotteryModelMasterTask(
            CreateLotteryModelMasterRequest request,
            Gs2RestSessionTask<CreateLotteryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreateLotteryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreateLotteryModelMasterTask() GS2_OVERRIDE = default;
    };

    class GetLotteryModelMasterTask : public detail::Gs2RestSessionTask<GetLotteryModelMasterResult>
    {
    private:
        GetLotteryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/lottery/{lotteryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetLotteryModelMasterTask(
            GetLotteryModelMasterRequest request,
            Gs2RestSessionTask<GetLotteryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetLotteryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetLotteryModelMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateLotteryModelMasterTask : public detail::Gs2RestSessionTask<UpdateLotteryModelMasterResult>
    {
    private:
        UpdateLotteryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/lottery/{lotteryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getMode())
            {
                jsonWriter.writePropertyName("mode");
                jsonWriter.writeCharArray(*m_Request.getMode());
            }
            if (m_Request.getMethod())
            {
                jsonWriter.writePropertyName("method");
                jsonWriter.writeCharArray(*m_Request.getMethod());
            }
            if (m_Request.getPrizeTableName())
            {
                jsonWriter.writePropertyName("prizeTableName");
                jsonWriter.writeCharArray(*m_Request.getPrizeTableName());
            }
            if (m_Request.getChoicePrizeTableScriptId())
            {
                jsonWriter.writePropertyName("choicePrizeTableScriptId");
                jsonWriter.writeCharArray(*m_Request.getChoicePrizeTableScriptId());
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
        UpdateLotteryModelMasterTask(
            UpdateLotteryModelMasterRequest request,
            Gs2RestSessionTask<UpdateLotteryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateLotteryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateLotteryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DeleteLotteryModelMasterTask : public detail::Gs2RestSessionTask<DeleteLotteryModelMasterResult>
    {
    private:
        DeleteLotteryModelMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/lottery/{lotteryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeleteLotteryModelMasterTask(
            DeleteLotteryModelMasterRequest request,
            Gs2RestSessionTask<DeleteLotteryModelMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeleteLotteryModelMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeleteLotteryModelMasterTask() GS2_OVERRIDE = default;
    };

    class DescribePrizeTableMastersTask : public detail::Gs2RestSessionTask<DescribePrizeTableMastersResult>
    {
    private:
        DescribePrizeTableMastersRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/table";
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
        DescribePrizeTableMastersTask(
            DescribePrizeTableMastersRequest request,
            Gs2RestSessionTask<DescribePrizeTableMastersResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribePrizeTableMastersResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribePrizeTableMastersTask() GS2_OVERRIDE = default;
    };

    class CreatePrizeTableMasterTask : public detail::Gs2RestSessionTask<CreatePrizeTableMasterResult>
    {
    private:
        CreatePrizeTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/table";
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
            if (m_Request.getPrizes())
            {
                jsonWriter.writePropertyName("prizes");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getPrizes();
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

            return detail::Gs2HttpTask::Verb::Post;
        }

    public:
        CreatePrizeTableMasterTask(
            CreatePrizeTableMasterRequest request,
            Gs2RestSessionTask<CreatePrizeTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<CreatePrizeTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~CreatePrizeTableMasterTask() GS2_OVERRIDE = default;
    };

    class GetPrizeTableMasterTask : public detail::Gs2RestSessionTask<GetPrizeTableMasterResult>
    {
    private:
        GetPrizeTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/table/{prizeTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPrizeTableName();
                url.replace("{prizeTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetPrizeTableMasterTask(
            GetPrizeTableMasterRequest request,
            Gs2RestSessionTask<GetPrizeTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetPrizeTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetPrizeTableMasterTask() GS2_OVERRIDE = default;
    };

    class UpdatePrizeTableMasterTask : public detail::Gs2RestSessionTask<UpdatePrizeTableMasterResult>
    {
    private:
        UpdatePrizeTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/table/{prizeTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPrizeTableName();
                url.replace("{prizeTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            if (m_Request.getPrizes())
            {
                jsonWriter.writePropertyName("prizes");
                jsonWriter.writeArrayStart();
                auto& list = *m_Request.getPrizes();
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

            return detail::Gs2HttpTask::Verb::Put;
        }

    public:
        UpdatePrizeTableMasterTask(
            UpdatePrizeTableMasterRequest request,
            Gs2RestSessionTask<UpdatePrizeTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdatePrizeTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdatePrizeTableMasterTask() GS2_OVERRIDE = default;
    };

    class DeletePrizeTableMasterTask : public detail::Gs2RestSessionTask<DeletePrizeTableMasterResult>
    {
    private:
        DeletePrizeTableMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/master/table/{prizeTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPrizeTableName();
                url.replace("{prizeTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DeletePrizeTableMasterTask(
            DeletePrizeTableMasterRequest request,
            Gs2RestSessionTask<DeletePrizeTableMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DeletePrizeTableMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~DeletePrizeTableMasterTask() GS2_OVERRIDE = default;
    };

    class DescribeBoxesTask : public detail::Gs2RestSessionTask<DescribeBoxesResult>
    {
    private:
        DescribeBoxesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/box";
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
        DescribeBoxesTask(
            DescribeBoxesRequest request,
            Gs2RestSessionTask<DescribeBoxesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeBoxesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeBoxesTask() GS2_OVERRIDE = default;
    };

    class DescribeBoxesByUserIdTask : public detail::Gs2RestSessionTask<DescribeBoxesByUserIdResult>
    {
    private:
        DescribeBoxesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/box";
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
        DescribeBoxesByUserIdTask(
            DescribeBoxesByUserIdRequest request,
            Gs2RestSessionTask<DescribeBoxesByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeBoxesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeBoxesByUserIdTask() GS2_OVERRIDE = default;
    };

    class GetBoxTask : public detail::Gs2RestSessionTask<GetBoxResult>
    {
    private:
        GetBoxRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/box/{lotteryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetBoxTask(
            GetBoxRequest request,
            Gs2RestSessionTask<GetBoxResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetBoxResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetBoxTask() GS2_OVERRIDE = default;
    };

    class GetBoxByUserIdTask : public detail::Gs2RestSessionTask<GetBoxByUserIdResult>
    {
    private:
        GetBoxByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/box/{lotteryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetBoxByUserIdTask(
            GetBoxByUserIdRequest request,
            Gs2RestSessionTask<GetBoxByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetBoxByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetBoxByUserIdTask() GS2_OVERRIDE = default;
    };

    class ResetBoxTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        ResetBoxRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/box/{lotteryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        ResetBoxTask(
            ResetBoxRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~ResetBoxTask() GS2_OVERRIDE = default;
    };

    class ResetBoxByUserIdTask : public detail::Gs2RestSessionTask<void>
    {
    private:
        ResetBoxByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/box/{lotteryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        ResetBoxByUserIdTask(
            ResetBoxByUserIdRequest request,
            Gs2RestSessionTask<void>::CallbackType callback
        ) :
            Gs2RestSessionTask<void>(callback),
            m_Request(std::move(request))
        {}

        ~ResetBoxByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeLotteryModelsTask : public detail::Gs2RestSessionTask<DescribeLotteryModelsResult>
    {
    private:
        DescribeLotteryModelsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/lottery";
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
        DescribeLotteryModelsTask(
            DescribeLotteryModelsRequest request,
            Gs2RestSessionTask<DescribeLotteryModelsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeLotteryModelsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeLotteryModelsTask() GS2_OVERRIDE = default;
    };

    class GetLotteryModelTask : public detail::Gs2RestSessionTask<GetLotteryModelResult>
    {
    private:
        GetLotteryModelRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/lottery/{lotteryName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetLotteryModelTask(
            GetLotteryModelRequest request,
            Gs2RestSessionTask<GetLotteryModelResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetLotteryModelResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetLotteryModelTask() GS2_OVERRIDE = default;
    };

    class DescribePrizeTablesTask : public detail::Gs2RestSessionTask<DescribePrizeTablesResult>
    {
    private:
        DescribePrizeTablesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/table";
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
        DescribePrizeTablesTask(
            DescribePrizeTablesRequest request,
            Gs2RestSessionTask<DescribePrizeTablesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribePrizeTablesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribePrizeTablesTask() GS2_OVERRIDE = default;
    };

    class GetPrizeTableTask : public detail::Gs2RestSessionTask<GetPrizeTableResult>
    {
    private:
        GetPrizeTableRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/table/{prizeTableName}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getPrizeTableName();
                url.replace("{prizeTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetPrizeTableTask(
            GetPrizeTableRequest request,
            Gs2RestSessionTask<GetPrizeTableResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetPrizeTableResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetPrizeTableTask() GS2_OVERRIDE = default;
    };

    class DrawByUserIdTask : public detail::Gs2RestSessionTask<DrawByUserIdResult>
    {
    private:
        DrawByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/lottery/{lotteryName}/draw";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getCount();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{count}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{count}", "null");
                }
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
        DrawByUserIdTask(
            DrawByUserIdRequest request,
            Gs2RestSessionTask<DrawByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DrawByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DrawByUserIdTask() GS2_OVERRIDE = default;
    };

    class DescribeProbabilitiesTask : public detail::Gs2RestSessionTask<DescribeProbabilitiesResult>
    {
    private:
        DescribeProbabilitiesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/lottery/{lotteryName}/probability";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeProbabilitiesTask(
            DescribeProbabilitiesRequest request,
            Gs2RestSessionTask<DescribeProbabilitiesResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeProbabilitiesResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeProbabilitiesTask() GS2_OVERRIDE = default;
    };

    class DescribeProbabilitiesByUserIdTask : public detail::Gs2RestSessionTask<DescribeProbabilitiesByUserIdResult>
    {
    private:
        DescribeProbabilitiesByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/lottery/{lotteryName}/probability";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getLotteryName();
                url.replace("{lotteryName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        DescribeProbabilitiesByUserIdTask(
            DescribeProbabilitiesByUserIdRequest request,
            Gs2RestSessionTask<DescribeProbabilitiesByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeProbabilitiesByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeProbabilitiesByUserIdTask() GS2_OVERRIDE = default;
    };

    class DrawByStampSheetTask : public detail::Gs2RestSessionTask<DrawByStampSheetResult>
    {
    private:
        DrawByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/draw";
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
        DrawByStampSheetTask(
            DrawByStampSheetRequest request,
            Gs2RestSessionTask<DrawByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DrawByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~DrawByStampSheetTask() GS2_OVERRIDE = default;
    };

    class ExportMasterTask : public detail::Gs2RestSessionTask<ExportMasterResult>
    {
    private:
        ExportMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
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

    class GetCurrentLotteryMasterTask : public detail::Gs2RestSessionTask<GetCurrentLotteryMasterResult>
    {
    private:
        GetCurrentLotteryMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
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
        GetCurrentLotteryMasterTask(
            GetCurrentLotteryMasterRequest request,
            Gs2RestSessionTask<GetCurrentLotteryMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetCurrentLotteryMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetCurrentLotteryMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentLotteryMasterTask : public detail::Gs2RestSessionTask<UpdateCurrentLotteryMasterResult>
    {
    private:
        UpdateCurrentLotteryMasterRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
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
        UpdateCurrentLotteryMasterTask(
            UpdateCurrentLotteryMasterRequest request,
            Gs2RestSessionTask<UpdateCurrentLotteryMasterResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentLotteryMasterResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentLotteryMasterTask() GS2_OVERRIDE = default;
    };

    class UpdateCurrentLotteryMasterFromGitHubTask : public detail::Gs2RestSessionTask<UpdateCurrentLotteryMasterFromGitHubResult>
    {
    private:
        UpdateCurrentLotteryMasterFromGitHubRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "lottery";
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
        UpdateCurrentLotteryMasterFromGitHubTask(
            UpdateCurrentLotteryMasterFromGitHubRequest request,
            Gs2RestSessionTask<UpdateCurrentLotteryMasterFromGitHubResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<UpdateCurrentLotteryMasterFromGitHubResult>(callback),
            m_Request(std::move(request))
        {}

        ~UpdateCurrentLotteryMasterFromGitHubTask() GS2_OVERRIDE = default;
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
        if (obj.getLotteryTriggerScriptId())
        {
            jsonWriter.writePropertyName("lotteryTriggerScriptId");
            jsonWriter.writeCharArray(*obj.getLotteryTriggerScriptId());
        }
        if (obj.getChoicePrizeTableScriptId())
        {
            jsonWriter.writePropertyName("choicePrizeTableScriptId");
            jsonWriter.writeCharArray(*obj.getChoicePrizeTableScriptId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const LotteryModelMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getLotteryModelId())
        {
            jsonWriter.writePropertyName("lotteryModelId");
            jsonWriter.writeCharArray(*obj.getLotteryModelId());
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
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
        }
        if (obj.getMode())
        {
            jsonWriter.writePropertyName("mode");
            jsonWriter.writeCharArray(*obj.getMode());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getChoicePrizeTableScriptId())
        {
            jsonWriter.writePropertyName("choicePrizeTableScriptId");
            jsonWriter.writeCharArray(*obj.getChoicePrizeTableScriptId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const PrizeTableMaster& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getPrizeTableId())
        {
            jsonWriter.writePropertyName("prizeTableId");
            jsonWriter.writeCharArray(*obj.getPrizeTableId());
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
        if (obj.getDescription())
        {
            jsonWriter.writePropertyName("description");
            jsonWriter.writeCharArray(*obj.getDescription());
        }
        if (obj.getPrizes())
        {
            jsonWriter.writePropertyName("prizes");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getPrizes();
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

    static void write(detail::json::JsonWriter& jsonWriter, const Box& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getBoxId())
        {
            jsonWriter.writePropertyName("boxId");
            jsonWriter.writeCharArray(*obj.getBoxId());
        }
        if (obj.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getDrawnIndexes())
        {
            jsonWriter.writePropertyName("drawnIndexes");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getDrawnIndexes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                jsonWriter.writeInt32(list[i]);
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

    static void write(detail::json::JsonWriter& jsonWriter, const LotteryModel& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getLotteryModelId())
        {
            jsonWriter.writePropertyName("lotteryModelId");
            jsonWriter.writeCharArray(*obj.getLotteryModelId());
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
        if (obj.getMode())
        {
            jsonWriter.writePropertyName("mode");
            jsonWriter.writeCharArray(*obj.getMode());
        }
        if (obj.getMethod())
        {
            jsonWriter.writePropertyName("method");
            jsonWriter.writeCharArray(*obj.getMethod());
        }
        if (obj.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getChoicePrizeTableScriptId())
        {
            jsonWriter.writePropertyName("choicePrizeTableScriptId");
            jsonWriter.writeCharArray(*obj.getChoicePrizeTableScriptId());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const PrizeTable& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getPrizeTableId())
        {
            jsonWriter.writePropertyName("prizeTableId");
            jsonWriter.writeCharArray(*obj.getPrizeTableId());
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
        if (obj.getPrizes())
        {
            jsonWriter.writePropertyName("prizes");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getPrizes();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const Probability& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getPrize())
        {
            jsonWriter.writePropertyName("prize");
            write(jsonWriter, *obj.getPrize());
        }
        if (obj.getRate())
        {
            jsonWriter.writePropertyName("rate");
            jsonWriter.writeFloat(*obj.getRate());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const CurrentLotteryMaster& obj)
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

    static void write(detail::json::JsonWriter& jsonWriter, const Prize& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getPrizeId())
        {
            jsonWriter.writePropertyName("prizeId");
            jsonWriter.writeCharArray(*obj.getPrizeId());
        }
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeCharArray(*obj.getType());
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
        if (obj.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getWeight())
        {
            jsonWriter.writePropertyName("weight");
            jsonWriter.writeInt32(*obj.getWeight());
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

    static void write(detail::json::JsonWriter& jsonWriter, const DrawnPrize& obj)
    {
        jsonWriter.writeObjectStart();
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

    static void write(detail::json::JsonWriter& jsonWriter, const BoxItem& obj)
    {
        jsonWriter.writeObjectStart();
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
        if (obj.getRemaining())
        {
            jsonWriter.writePropertyName("remaining");
            jsonWriter.writeInt32(*obj.getRemaining());
        }
        if (obj.getInitial())
        {
            jsonWriter.writePropertyName("initial");
            jsonWriter.writeInt32(*obj.getInitial());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const BoxItems& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getBoxId())
        {
            jsonWriter.writePropertyName("boxId");
            jsonWriter.writeCharArray(*obj.getBoxId());
        }
        if (obj.getPrizeTableName())
        {
            jsonWriter.writePropertyName("prizeTableName");
            jsonWriter.writeCharArray(*obj.getPrizeTableName());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getItems())
        {
            jsonWriter.writePropertyName("items");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getItems();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(jsonWriter, list[i]);
            }
            jsonWriter.writeArrayEnd();
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2LotteryRestClient(Gs2RestSession& gs2RestSession) :
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
	 * 抽選の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModelMasters(DescribeLotteryModelMastersRequest request, std::function<void(AsyncDescribeLotteryModelMastersResult)> callback)
    {
        DescribeLotteryModelMastersTask& task = *new DescribeLotteryModelMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 抽選の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLotteryModelMaster(CreateLotteryModelMasterRequest request, std::function<void(AsyncCreateLotteryModelMasterResult)> callback)
    {
        CreateLotteryModelMasterTask& task = *new CreateLotteryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 抽選の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModelMaster(GetLotteryModelMasterRequest request, std::function<void(AsyncGetLotteryModelMasterResult)> callback)
    {
        GetLotteryModelMasterTask& task = *new GetLotteryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 抽選の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLotteryModelMaster(UpdateLotteryModelMasterRequest request, std::function<void(AsyncUpdateLotteryModelMasterResult)> callback)
    {
        UpdateLotteryModelMasterTask& task = *new UpdateLotteryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 抽選の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLotteryModelMaster(DeleteLotteryModelMasterRequest request, std::function<void(AsyncDeleteLotteryModelMasterResult)> callback)
    {
        DeleteLotteryModelMasterTask& task = *new DeleteLotteryModelMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 排出確率テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeTableMasters(DescribePrizeTableMastersRequest request, std::function<void(AsyncDescribePrizeTableMastersResult)> callback)
    {
        DescribePrizeTableMastersTask& task = *new DescribePrizeTableMastersTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 排出確率テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createPrizeTableMaster(CreatePrizeTableMasterRequest request, std::function<void(AsyncCreatePrizeTableMasterResult)> callback)
    {
        CreatePrizeTableMasterTask& task = *new CreatePrizeTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 排出確率テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeTableMaster(GetPrizeTableMasterRequest request, std::function<void(AsyncGetPrizeTableMasterResult)> callback)
    {
        GetPrizeTableMasterTask& task = *new GetPrizeTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 排出確率テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updatePrizeTableMaster(UpdatePrizeTableMasterRequest request, std::function<void(AsyncUpdatePrizeTableMasterResult)> callback)
    {
        UpdatePrizeTableMasterTask& task = *new UpdatePrizeTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 排出確率テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deletePrizeTableMaster(DeletePrizeTableMasterRequest request, std::function<void(AsyncDeletePrizeTableMasterResult)> callback)
    {
        DeletePrizeTableMasterTask& task = *new DeletePrizeTableMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ボックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBoxes(DescribeBoxesRequest request, std::function<void(AsyncDescribeBoxesResult)> callback)
    {
        DescribeBoxesTask& task = *new DescribeBoxesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してボックスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeBoxesByUserId(DescribeBoxesByUserIdRequest request, std::function<void(AsyncDescribeBoxesByUserIdResult)> callback)
    {
        DescribeBoxesByUserIdTask& task = *new DescribeBoxesByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ボックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBox(GetBoxRequest request, std::function<void(AsyncGetBoxResult)> callback)
    {
        GetBoxTask& task = *new GetBoxTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してボックスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getBoxByUserId(GetBoxByUserIdRequest request, std::function<void(AsyncGetBoxByUserIdResult)> callback)
    {
        GetBoxByUserIdTask& task = *new GetBoxByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ボックスをリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBox(ResetBoxRequest request, std::function<void(AsyncResetBoxResult)> callback)
    {
        ResetBoxTask& task = *new ResetBoxTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定してボックスをリセット<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void resetBoxByUserId(ResetBoxByUserIdRequest request, std::function<void(AsyncResetBoxByUserIdResult)> callback)
    {
        ResetBoxByUserIdTask& task = *new ResetBoxByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 抽選の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLotteryModels(DescribeLotteryModelsRequest request, std::function<void(AsyncDescribeLotteryModelsResult)> callback)
    {
        DescribeLotteryModelsTask& task = *new DescribeLotteryModelsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 抽選の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLotteryModel(GetLotteryModelRequest request, std::function<void(AsyncGetLotteryModelResult)> callback)
    {
        GetLotteryModelTask& task = *new GetLotteryModelTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 排出確率テーブルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeTables(DescribePrizeTablesRequest request, std::function<void(AsyncDescribePrizeTablesResult)> callback)
    {
        DescribePrizeTablesTask& task = *new DescribePrizeTablesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 排出確率テーブルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeTable(GetPrizeTableRequest request, std::function<void(AsyncGetPrizeTableResult)> callback)
    {
        GetPrizeTableTask& task = *new GetPrizeTableTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザIDを指定して抽選を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void drawByUserId(DrawByUserIdRequest request, std::function<void(AsyncDrawByUserIdResult)> callback)
    {
        DrawByUserIdTask& task = *new DrawByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 排出確率を取得<br>
	 *   <br>
	 *   通常抽選ではすべてのゲームプレイヤーに対して同じ確率を応答します。<br>
	 *   ボックス抽選ではボックスの中身の残りを考慮したゲームプレイヤーごとに異なる確率を応答します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProbabilities(DescribeProbabilitiesRequest request, std::function<void(AsyncDescribeProbabilitiesResult)> callback)
    {
        DescribeProbabilitiesTask& task = *new DescribeProbabilitiesTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 排出確率を取得<br>
	 *   <br>
	 *   通常抽選ではすべてのゲームプレイヤーに対して同じ確率を応答します。<br>
	 *   ボックス抽選ではボックスの中身の残りを考慮したゲームプレイヤーごとに異なる確率を応答します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeProbabilitiesByUserId(DescribeProbabilitiesByUserIdRequest request, std::function<void(AsyncDescribeProbabilitiesByUserIdResult)> callback)
    {
        DescribeProbabilitiesByUserIdTask& task = *new DescribeProbabilitiesByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートを使用して抽選処理を実行<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void drawByStampSheet(DrawByStampSheetRequest request, std::function<void(AsyncDrawByStampSheetResult)> callback)
    {
        DrawByStampSheetTask& task = *new DrawByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な抽選設定のマスターデータをエクスポートします<br>
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
	 * 現在有効な抽選設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLotteryMaster(GetCurrentLotteryMasterRequest request, std::function<void(AsyncGetCurrentLotteryMasterResult)> callback)
    {
        GetCurrentLotteryMasterTask& task = *new GetCurrentLotteryMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な抽選設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLotteryMaster(UpdateCurrentLotteryMasterRequest request, std::function<void(AsyncUpdateCurrentLotteryMasterResult)> callback)
    {
        UpdateCurrentLotteryMasterTask& task = *new UpdateCurrentLotteryMasterTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * 現在有効な抽選設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLotteryMasterFromGitHub(UpdateCurrentLotteryMasterFromGitHubRequest request, std::function<void(AsyncUpdateCurrentLotteryMasterFromGitHubResult)> callback)
    {
        UpdateCurrentLotteryMasterFromGitHubTask& task = *new UpdateCurrentLotteryMasterFromGitHubTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_LOTTERY_GS2LOTTERYRESTCLIENT_HPP_