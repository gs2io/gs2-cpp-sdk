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

#ifndef GS2_MONEY_GS2MONEYRESTCLIENT_HPP_
#define GS2_MONEY_GS2MONEYRESTCLIENT_HPP_

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
#include "request/DescribeWalletsRequest.hpp"
#include "request/DescribeWalletsByUserIdRequest.hpp"
#include "request/QueryWalletsRequest.hpp"
#include "request/GetWalletRequest.hpp"
#include "request/GetWalletByUserIdRequest.hpp"
#include "request/DepositByUserIdRequest.hpp"
#include "request/WithdrawRequest.hpp"
#include "request/WithdrawByUserIdRequest.hpp"
#include "request/DepositByStampSheetRequest.hpp"
#include "request/WithdrawByStampTaskRequest.hpp"
#include "request/DescribeReceiptsRequest.hpp"
#include "request/GetByUserIdAndTransactionIdRequest.hpp"
#include "request/RecordReceiptRequest.hpp"
#include "request/RecordReceiptByStampTaskRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeWalletsResult.hpp"
#include "result/DescribeWalletsByUserIdResult.hpp"
#include "result/QueryWalletsResult.hpp"
#include "result/GetWalletResult.hpp"
#include "result/GetWalletByUserIdResult.hpp"
#include "result/DepositByUserIdResult.hpp"
#include "result/WithdrawResult.hpp"
#include "result/WithdrawByUserIdResult.hpp"
#include "result/DepositByStampSheetResult.hpp"
#include "result/WithdrawByStampTaskResult.hpp"
#include "result/DescribeReceiptsResult.hpp"
#include "result/GetByUserIdAndTransactionIdResult.hpp"
#include "result/RecordReceiptResult.hpp"
#include "result/RecordReceiptByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace money {

/**
 * GS2 Money API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2MoneyRestClient : public AbstractGs2ClientBase
{
private:

    class DescribeNamespacesTask : public detail::Gs2RestSessionTask<DescribeNamespacesResult>
    {
    private:
        DescribeNamespacesRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
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
            return "money";
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
            if (m_Request.getPriority())
            {
                jsonWriter.writePropertyName("priority");
                jsonWriter.writeCharArray(*m_Request.getPriority());
            }
            if (m_Request.getShareFree())
            {
                jsonWriter.writePropertyName("shareFree");
                jsonWriter.writeBool(*m_Request.getShareFree());
            }
            if (m_Request.getCurrency())
            {
                jsonWriter.writePropertyName("currency");
                jsonWriter.writeCharArray(*m_Request.getCurrency());
            }
            if (m_Request.getAppleKey())
            {
                jsonWriter.writePropertyName("appleKey");
                jsonWriter.writeCharArray(*m_Request.getAppleKey());
            }
            if (m_Request.getGoogleKey())
            {
                jsonWriter.writePropertyName("googleKey");
                jsonWriter.writeCharArray(*m_Request.getGoogleKey());
            }
            if (m_Request.getEnableFakeReceipt())
            {
                jsonWriter.writePropertyName("enableFakeReceipt");
                jsonWriter.writeBool(*m_Request.getEnableFakeReceipt());
            }
            if (m_Request.getCreateWalletScript())
            {
                jsonWriter.writePropertyName("createWalletScript");
                write(jsonWriter, *m_Request.getCreateWalletScript());
            }
            if (m_Request.getDepositScript())
            {
                jsonWriter.writePropertyName("depositScript");
                write(jsonWriter, *m_Request.getDepositScript());
            }
            if (m_Request.getWithdrawScript())
            {
                jsonWriter.writePropertyName("withdrawScript");
                write(jsonWriter, *m_Request.getWithdrawScript());
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
            return "money";
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
            return "money";
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
            return "money";
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
            if (m_Request.getPriority())
            {
                jsonWriter.writePropertyName("priority");
                jsonWriter.writeCharArray(*m_Request.getPriority());
            }
            if (m_Request.getAppleKey())
            {
                jsonWriter.writePropertyName("appleKey");
                jsonWriter.writeCharArray(*m_Request.getAppleKey());
            }
            if (m_Request.getGoogleKey())
            {
                jsonWriter.writePropertyName("googleKey");
                jsonWriter.writeCharArray(*m_Request.getGoogleKey());
            }
            if (m_Request.getEnableFakeReceipt())
            {
                jsonWriter.writePropertyName("enableFakeReceipt");
                jsonWriter.writeBool(*m_Request.getEnableFakeReceipt());
            }
            if (m_Request.getCreateWalletScript())
            {
                jsonWriter.writePropertyName("createWalletScript");
                write(jsonWriter, *m_Request.getCreateWalletScript());
            }
            if (m_Request.getDepositScript())
            {
                jsonWriter.writePropertyName("depositScript");
                write(jsonWriter, *m_Request.getDepositScript());
            }
            if (m_Request.getWithdrawScript())
            {
                jsonWriter.writePropertyName("withdrawScript");
                write(jsonWriter, *m_Request.getWithdrawScript());
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
            return "money";
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

    class DescribeWalletsTask : public detail::Gs2RestSessionTask<DescribeWalletsResult>
    {
    private:
        DescribeWalletsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/wallet";
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
        DescribeWalletsTask(
            DescribeWalletsRequest request,
            Gs2RestSessionTask<DescribeWalletsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeWalletsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeWalletsTask() GS2_OVERRIDE = default;
    };

    class DescribeWalletsByUserIdTask : public detail::Gs2RestSessionTask<DescribeWalletsByUserIdResult>
    {
    private:
        DescribeWalletsByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/wallet";
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
        DescribeWalletsByUserIdTask(
            DescribeWalletsByUserIdRequest request,
            Gs2RestSessionTask<DescribeWalletsByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeWalletsByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeWalletsByUserIdTask() GS2_OVERRIDE = default;
    };

    class QueryWalletsTask : public detail::Gs2RestSessionTask<QueryWalletsResult>
    {
    private:
        QueryWalletsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/wallet/query";
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
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId(), detail::StringVariable::UrlSafeEncode()).c_str();
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
        QueryWalletsTask(
            QueryWalletsRequest request,
            Gs2RestSessionTask<QueryWalletsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<QueryWalletsResult>(callback),
            m_Request(std::move(request))
        {}

        ~QueryWalletsTask() GS2_OVERRIDE = default;
    };

    class GetWalletTask : public detail::Gs2RestSessionTask<GetWalletResult>
    {
    private:
        GetWalletRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/wallet/{slot}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getSlot();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{slot}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{slot}", "null");
                }
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
        GetWalletTask(
            GetWalletRequest request,
            Gs2RestSessionTask<GetWalletResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetWalletResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetWalletTask() GS2_OVERRIDE = default;
    };

    class GetWalletByUserIdTask : public detail::Gs2RestSessionTask<GetWalletByUserIdResult>
    {
    private:
        GetWalletByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/wallet/{slot}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getSlot();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{slot}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{slot}", "null");
                }
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
        GetWalletByUserIdTask(
            GetWalletByUserIdRequest request,
            Gs2RestSessionTask<GetWalletByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetWalletByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetWalletByUserIdTask() GS2_OVERRIDE = default;
    };

    class DepositByUserIdTask : public detail::Gs2RestSessionTask<DepositByUserIdResult>
    {
    private:
        DepositByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/wallet/{slot}/deposit";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getSlot();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{slot}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{slot}", "null");
                }
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getPrice())
            {
                jsonWriter.writePropertyName("price");
                jsonWriter.writeFloat(*m_Request.getPrice());
            }
            if (m_Request.getCount())
            {
                jsonWriter.writePropertyName("count");
                jsonWriter.writeInt32(*m_Request.getCount());
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
        DepositByUserIdTask(
            DepositByUserIdRequest request,
            Gs2RestSessionTask<DepositByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DepositByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~DepositByUserIdTask() GS2_OVERRIDE = default;
    };

    class WithdrawTask : public detail::Gs2RestSessionTask<WithdrawResult>
    {
    private:
        WithdrawRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/me/wallet/{slot}/withdraw";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getSlot();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{slot}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{slot}", "null");
                }
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getCount())
            {
                jsonWriter.writePropertyName("count");
                jsonWriter.writeInt32(*m_Request.getCount());
            }
            if (m_Request.getPaidOnly())
            {
                jsonWriter.writePropertyName("paidOnly");
                jsonWriter.writeBool(*m_Request.getPaidOnly());
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
        WithdrawTask(
            WithdrawRequest request,
            Gs2RestSessionTask<WithdrawResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<WithdrawResult>(callback),
            m_Request(std::move(request))
        {}

        ~WithdrawTask() GS2_OVERRIDE = default;
    };

    class WithdrawByUserIdTask : public detail::Gs2RestSessionTask<WithdrawByUserIdResult>
    {
    private:
        WithdrawByUserIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/wallet/{slot}/withdraw";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getSlot();
                if (value.has_value())
                {
                    detail::StringVariable urlSafeValue(*value);
                    url.replace("{slot}", urlSafeValue.c_str());
                }
                else
                {
                    url.replace("{slot}", "null");
                }
            }
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
            if (m_Request.getContextStack())
            {
                jsonWriter.writePropertyName("contextStack");
                jsonWriter.writeCharArray(*m_Request.getContextStack());
            }
            if (m_Request.getCount())
            {
                jsonWriter.writePropertyName("count");
                jsonWriter.writeInt32(*m_Request.getCount());
            }
            if (m_Request.getPaidOnly())
            {
                jsonWriter.writePropertyName("paidOnly");
                jsonWriter.writeBool(*m_Request.getPaidOnly());
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
        WithdrawByUserIdTask(
            WithdrawByUserIdRequest request,
            Gs2RestSessionTask<WithdrawByUserIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<WithdrawByUserIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~WithdrawByUserIdTask() GS2_OVERRIDE = default;
    };

    class DepositByStampSheetTask : public detail::Gs2RestSessionTask<DepositByStampSheetResult>
    {
    private:
        DepositByStampSheetRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/deposit";
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
        DepositByStampSheetTask(
            DepositByStampSheetRequest request,
            Gs2RestSessionTask<DepositByStampSheetResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DepositByStampSheetResult>(callback),
            m_Request(std::move(request))
        {}

        ~DepositByStampSheetTask() GS2_OVERRIDE = default;
    };

    class WithdrawByStampTaskTask : public detail::Gs2RestSessionTask<WithdrawByStampTaskResult>
    {
    private:
        WithdrawByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/withdraw";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
        WithdrawByStampTaskTask(
            WithdrawByStampTaskRequest request,
            Gs2RestSessionTask<WithdrawByStampTaskResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<WithdrawByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~WithdrawByStampTaskTask() GS2_OVERRIDE = default;
    };

    class DescribeReceiptsTask : public detail::Gs2RestSessionTask<DescribeReceiptsResult>
    {
    private:
        DescribeReceiptsRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/receipt";
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
            if (m_Request.getUserId())
            {
                url += joint;
                url += "userId=";
                url += detail::StringVariable(*m_Request.getUserId(), detail::StringVariable::UrlSafeEncode()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getSlot())
            {
                url += joint;
                url += "slot=";
                url += detail::StringVariable(*m_Request.getSlot()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getBegin())
            {
                url += joint;
                url += "begin=";
                url += detail::StringVariable(*m_Request.getBegin()).c_str();
                joint[0] = '&';
            }
            if (m_Request.getEnd())
            {
                url += joint;
                url += "end=";
                url += detail::StringVariable(*m_Request.getEnd()).c_str();
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
        DescribeReceiptsTask(
            DescribeReceiptsRequest request,
            Gs2RestSessionTask<DescribeReceiptsResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<DescribeReceiptsResult>(callback),
            m_Request(std::move(request))
        {}

        ~DescribeReceiptsTask() GS2_OVERRIDE = default;
    };

    class GetByUserIdAndTransactionIdTask : public detail::Gs2RestSessionTask<GetByUserIdAndTransactionIdResult>
    {
    private:
        GetByUserIdAndTransactionIdRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/receipt/{transactionId}";
            {
                auto& value = m_Request.getNamespaceName();
                url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getUserId();
                url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
            }
            {
                auto& value = m_Request.getTransactionId();
                url.replace("{transactionId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        GetByUserIdAndTransactionIdTask(
            GetByUserIdAndTransactionIdRequest request,
            Gs2RestSessionTask<GetByUserIdAndTransactionIdResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<GetByUserIdAndTransactionIdResult>(callback),
            m_Request(std::move(request))
        {}

        ~GetByUserIdAndTransactionIdTask() GS2_OVERRIDE = default;
    };

    class RecordReceiptTask : public detail::Gs2RestSessionTask<RecordReceiptResult>
    {
    private:
        RecordReceiptRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/{namespaceName}/user/{userId}/receipt";
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
            if (m_Request.getContentsId())
            {
                jsonWriter.writePropertyName("contentsId");
                jsonWriter.writeCharArray(*m_Request.getContentsId());
            }
            if (m_Request.getReceipt())
            {
                jsonWriter.writePropertyName("receipt");
                jsonWriter.writeCharArray(*m_Request.getReceipt());
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
        RecordReceiptTask(
            RecordReceiptRequest request,
            Gs2RestSessionTask<RecordReceiptResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<RecordReceiptResult>(callback),
            m_Request(std::move(request))
        {}

        ~RecordReceiptTask() GS2_OVERRIDE = default;
    };

    class RecordReceiptByStampTaskTask : public detail::Gs2RestSessionTask<RecordReceiptByStampTaskResult>
    {
    private:
        RecordReceiptByStampTaskRequest m_Request;

        const char* getServiceName() const GS2_OVERRIDE
        {
            return "money";
        }

        detail::Gs2HttpTask::Verb constructRequestImpl(detail::StringVariable& url, detail::Gs2HttpTask& gs2HttpTask) GS2_OVERRIDE
        {
            url += "/stamp/receipt/record";
            detail::json::JsonWriter jsonWriter;

            jsonWriter.writeObjectStart();
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
        RecordReceiptByStampTaskTask(
            RecordReceiptByStampTaskRequest request,
            Gs2RestSessionTask<RecordReceiptByStampTaskResult>::CallbackType callback
        ) :
            Gs2RestSessionTask<RecordReceiptByStampTaskResult>(callback),
            m_Request(std::move(request))
        {}

        ~RecordReceiptByStampTaskTask() GS2_OVERRIDE = default;
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
        if (obj.getPriority())
        {
            jsonWriter.writePropertyName("priority");
            jsonWriter.writeCharArray(*obj.getPriority());
        }
        if (obj.getShareFree())
        {
            jsonWriter.writePropertyName("shareFree");
            jsonWriter.writeBool(*obj.getShareFree());
        }
        if (obj.getCurrency())
        {
            jsonWriter.writePropertyName("currency");
            jsonWriter.writeCharArray(*obj.getCurrency());
        }
        if (obj.getAppleKey())
        {
            jsonWriter.writePropertyName("appleKey");
            jsonWriter.writeCharArray(*obj.getAppleKey());
        }
        if (obj.getGoogleKey())
        {
            jsonWriter.writePropertyName("googleKey");
            jsonWriter.writeCharArray(*obj.getGoogleKey());
        }
        if (obj.getEnableFakeReceipt())
        {
            jsonWriter.writePropertyName("enableFakeReceipt");
            jsonWriter.writeBool(*obj.getEnableFakeReceipt());
        }
        if (obj.getCreateWalletScript())
        {
            jsonWriter.writePropertyName("createWalletScript");
            write(jsonWriter, *obj.getCreateWalletScript());
        }
        if (obj.getDepositScript())
        {
            jsonWriter.writePropertyName("depositScript");
            write(jsonWriter, *obj.getDepositScript());
        }
        if (obj.getWithdrawScript())
        {
            jsonWriter.writePropertyName("withdrawScript");
            write(jsonWriter, *obj.getWithdrawScript());
        }
        if (obj.getBalance())
        {
            jsonWriter.writePropertyName("balance");
            jsonWriter.writeDouble(*obj.getBalance());
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

    static void write(detail::json::JsonWriter& jsonWriter, const Wallet& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getWalletId())
        {
            jsonWriter.writePropertyName("walletId");
            jsonWriter.writeCharArray(*obj.getWalletId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getSlot())
        {
            jsonWriter.writePropertyName("slot");
            jsonWriter.writeInt32(*obj.getSlot());
        }
        if (obj.getPaid())
        {
            jsonWriter.writePropertyName("paid");
            jsonWriter.writeInt32(*obj.getPaid());
        }
        if (obj.getFree())
        {
            jsonWriter.writePropertyName("free");
            jsonWriter.writeInt32(*obj.getFree());
        }
        if (obj.getDetail())
        {
            jsonWriter.writePropertyName("detail");
            jsonWriter.writeArrayStart();
            auto& list = *obj.getDetail();
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

    static void write(detail::json::JsonWriter& jsonWriter, const Receipt& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getReceiptId())
        {
            jsonWriter.writePropertyName("receiptId");
            jsonWriter.writeCharArray(*obj.getReceiptId());
        }
        if (obj.getTransactionId())
        {
            jsonWriter.writePropertyName("transactionId");
            jsonWriter.writeCharArray(*obj.getTransactionId());
        }
        if (obj.getUserId())
        {
            jsonWriter.writePropertyName("userId");
            jsonWriter.writeCharArray(*obj.getUserId());
        }
        if (obj.getType())
        {
            jsonWriter.writePropertyName("type");
            jsonWriter.writeCharArray(*obj.getType());
        }
        if (obj.getSlot())
        {
            jsonWriter.writePropertyName("slot");
            jsonWriter.writeInt32(*obj.getSlot());
        }
        if (obj.getPrice())
        {
            jsonWriter.writePropertyName("price");
            jsonWriter.writeFloat(*obj.getPrice());
        }
        if (obj.getPaid())
        {
            jsonWriter.writePropertyName("paid");
            jsonWriter.writeInt32(*obj.getPaid());
        }
        if (obj.getFree())
        {
            jsonWriter.writePropertyName("free");
            jsonWriter.writeInt32(*obj.getFree());
        }
        if (obj.getTotal())
        {
            jsonWriter.writePropertyName("total");
            jsonWriter.writeInt32(*obj.getTotal());
        }
        if (obj.getContentsId())
        {
            jsonWriter.writePropertyName("contentsId");
            jsonWriter.writeCharArray(*obj.getContentsId());
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

    static void write(detail::json::JsonWriter& jsonWriter, const WalletDetail& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getPrice())
        {
            jsonWriter.writePropertyName("price");
            jsonWriter.writeFloat(*obj.getPrice());
        }
        if (obj.getCount())
        {
            jsonWriter.writePropertyName("count");
            jsonWriter.writeInt32(*obj.getCount());
        }
        jsonWriter.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& jsonWriter, const ScriptSetting& obj)
    {
        jsonWriter.writeObjectStart();
        if (obj.getTriggerScriptId())
        {
            jsonWriter.writePropertyName("triggerScriptId");
            jsonWriter.writeCharArray(*obj.getTriggerScriptId());
        }
        if (obj.getDoneTriggerTargetType())
        {
            jsonWriter.writePropertyName("doneTriggerTargetType");
            jsonWriter.writeCharArray(*obj.getDoneTriggerTargetType());
        }
        if (obj.getDoneTriggerScriptId())
        {
            jsonWriter.writePropertyName("doneTriggerScriptId");
            jsonWriter.writeCharArray(*obj.getDoneTriggerScriptId());
        }
        if (obj.getDoneTriggerQueueNamespaceId())
        {
            jsonWriter.writePropertyName("doneTriggerQueueNamespaceId");
            jsonWriter.writeCharArray(*obj.getDoneTriggerQueueNamespaceId());
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
    explicit Gs2MoneyRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得します<br>
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
	 * ネームスペースを新規作成します<br>
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
	 * ネームスペースの状態を取得します<br>
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
	 * ネームスペースを取得します<br>
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
	 * ネームスペースを更新します<br>
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
	 * ネームスペースを削除します<br>
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
	 * ウォレット一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWallets(DescribeWalletsRequest request, std::function<void(AsyncDescribeWalletsResult)> callback)
    {
        DescribeWalletsTask& task = *new DescribeWalletsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ウォレット一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWalletsByUserId(DescribeWalletsByUserIdRequest request, std::function<void(AsyncDescribeWalletsByUserIdResult)> callback)
    {
        DescribeWalletsByUserIdTask& task = *new DescribeWalletsByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ウォレット一覧を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void queryWallets(QueryWalletsRequest request, std::function<void(AsyncQueryWalletsResult)> callback)
    {
        QueryWalletsTask& task = *new QueryWalletsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ウォレットを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWallet(GetWalletRequest request, std::function<void(AsyncGetWalletResult)> callback)
    {
        GetWalletTask& task = *new GetWalletTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してウォレットを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWalletByUserId(GetWalletByUserIdRequest request, std::function<void(AsyncGetWalletByUserIdResult)> callback)
    {
        GetWalletByUserIdTask& task = *new GetWalletByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してウォレットに残高を加算します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositByUserId(DepositByUserIdRequest request, std::function<void(AsyncDepositByUserIdResult)> callback)
    {
        DepositByUserIdTask& task = *new DepositByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ウォレットから残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdraw(WithdrawRequest request, std::function<void(AsyncWithdrawResult)> callback)
    {
        WithdrawTask& task = *new WithdrawTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ユーザーIDを指定してウォレットから残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawByUserId(WithdrawByUserIdRequest request, std::function<void(AsyncWithdrawByUserIdResult)> callback)
    {
        WithdrawByUserIdTask& task = *new WithdrawByUserIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートを使用してウォレットに残高を加算します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositByStampSheet(DepositByStampSheetRequest request, std::function<void(AsyncDepositByStampSheetResult)> callback)
    {
        DepositByStampSheetTask& task = *new DepositByStampSheetTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * ウォレットから残高を消費します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawByStampTask(WithdrawByStampTaskRequest request, std::function<void(AsyncWithdrawByStampTaskResult)> callback)
    {
        WithdrawByStampTaskTask& task = *new WithdrawByStampTaskTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * レシートの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeReceipts(DescribeReceiptsRequest request, std::function<void(AsyncDescribeReceiptsResult)> callback)
    {
        DescribeReceiptsTask& task = *new DescribeReceiptsTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * レシートの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getByUserIdAndTransactionId(GetByUserIdAndTransactionIdRequest request, std::function<void(AsyncGetByUserIdAndTransactionIdResult)> callback)
    {
        GetByUserIdAndTransactionIdTask& task = *new GetByUserIdAndTransactionIdTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * レシートを記録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recordReceipt(RecordReceiptRequest request, std::function<void(AsyncRecordReceiptResult)> callback)
    {
        RecordReceiptTask& task = *new RecordReceiptTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

	/**
	 * スタンプシートを使用してレシートを記録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recordReceiptByStampTask(RecordReceiptByStampTaskRequest request, std::function<void(AsyncRecordReceiptByStampTaskResult)> callback)
    {
        RecordReceiptByStampTaskTask& task = *new RecordReceiptByStampTaskTask(std::move(request), callback);
        getGs2RestSession().execute(task);
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_MONEY_GS2MONEYRESTCLIENT_HPP_