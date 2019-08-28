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

#ifndef GS2_ACCOUNT_GS2ACCOUNTRESTCLIENT_HPP_
#define GS2_ACCOUNT_GS2ACCOUNTRESTCLIENT_HPP_

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
#include "request/DescribeAccountsRequest.hpp"
#include "request/CreateAccountRequest.hpp"
#include "request/UpdateTimeOffsetRequest.hpp"
#include "request/GetAccountRequest.hpp"
#include "request/DeleteAccountRequest.hpp"
#include "request/AuthenticationRequest.hpp"
#include "request/DescribeTakeOversRequest.hpp"
#include "request/DescribeTakeOversByUserIdRequest.hpp"
#include "request/CreateTakeOverRequest.hpp"
#include "request/CreateTakeOverByUserIdRequest.hpp"
#include "request/GetTakeOverRequest.hpp"
#include "request/GetTakeOverByUserIdRequest.hpp"
#include "request/UpdateTakeOverRequest.hpp"
#include "request/UpdateTakeOverByUserIdRequest.hpp"
#include "request/DeleteTakeOverRequest.hpp"
#include "request/DeleteTakeOverByUserIdentifierRequest.hpp"
#include "request/DoTakeOverRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeAccountsResult.hpp"
#include "result/CreateAccountResult.hpp"
#include "result/UpdateTimeOffsetResult.hpp"
#include "result/GetAccountResult.hpp"
#include "result/DeleteAccountResult.hpp"
#include "result/AuthenticationResult.hpp"
#include "result/DescribeTakeOversResult.hpp"
#include "result/DescribeTakeOversByUserIdResult.hpp"
#include "result/CreateTakeOverResult.hpp"
#include "result/CreateTakeOverByUserIdResult.hpp"
#include "result/GetTakeOverResult.hpp"
#include "result/GetTakeOverByUserIdResult.hpp"
#include "result/UpdateTakeOverResult.hpp"
#include "result/UpdateTakeOverByUserIdResult.hpp"
#include "result/DeleteTakeOverResult.hpp"
#include "result/DeleteTakeOverByUserIdentifierResult.hpp"
#include "result/DoTakeOverResult.hpp"
#include <cstring>

namespace gs2 { namespace account {

/**
 * GS2 Account API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2AccountRestClient : public AbstractGs2ClientBase
{
private:
    static void write(detail::json::JsonWriter& writer, const Namespace& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceId())
        {
            writer.writePropertyName("namespaceId");
            writer.writeCharArray(*obj.getNamespaceId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getChangePasswordIfTakeOver())
        {
            writer.writePropertyName("changePasswordIfTakeOver");
            writer.writeBool(*obj.getChangePasswordIfTakeOver());
        }
        if (obj.getCreateAccountTriggerScriptId())
        {
            writer.writePropertyName("createAccountTriggerScriptId");
            writer.writeCharArray(*obj.getCreateAccountTriggerScriptId());
        }
        if (obj.getCreateAccountDoneTriggerScriptId())
        {
            writer.writePropertyName("createAccountDoneTriggerScriptId");
            writer.writeCharArray(*obj.getCreateAccountDoneTriggerScriptId());
        }
        if (obj.getCreateAccountDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("createAccountDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getCreateAccountDoneTriggerQueueNamespaceId());
        }
        if (obj.getAuthenticationTriggerScriptId())
        {
            writer.writePropertyName("authenticationTriggerScriptId");
            writer.writeCharArray(*obj.getAuthenticationTriggerScriptId());
        }
        if (obj.getAuthenticationDoneTriggerScriptId())
        {
            writer.writePropertyName("authenticationDoneTriggerScriptId");
            writer.writeCharArray(*obj.getAuthenticationDoneTriggerScriptId());
        }
        if (obj.getAuthenticationDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("authenticationDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getAuthenticationDoneTriggerQueueNamespaceId());
        }
        if (obj.getCreateTakeOverTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverTriggerScriptId");
            writer.writeCharArray(*obj.getCreateTakeOverTriggerScriptId());
        }
        if (obj.getCreateTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerScriptId");
            writer.writeCharArray(*obj.getCreateTakeOverDoneTriggerScriptId());
        }
        if (obj.getCreateTakeOverDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getCreateTakeOverDoneTriggerQueueNamespaceId());
        }
        if (obj.getDoTakeOverTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverTriggerScriptId");
            writer.writeCharArray(*obj.getDoTakeOverTriggerScriptId());
        }
        if (obj.getDoTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerScriptId");
            writer.writeCharArray(*obj.getDoTakeOverDoneTriggerScriptId());
        }
        if (obj.getDoTakeOverDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*obj.getDoTakeOverDoneTriggerQueueNamespaceId());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getUpdatedAt())
        {
            writer.writePropertyName("updatedAt");
            writer.writeInt64(*obj.getUpdatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Account& obj)
    {
        writer.writeObjectStart();
        if (obj.getAccountId())
        {
            writer.writePropertyName("accountId");
            writer.writeCharArray(*obj.getAccountId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*obj.getPassword());
        }
        if (obj.getTimeOffset())
        {
            writer.writePropertyName("timeOffset");
            writer.writeInt32(*obj.getTimeOffset());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const TakeOver& obj)
    {
        writer.writeObjectStart();
        if (obj.getTakeOverId())
        {
            writer.writePropertyName("takeOverId");
            writer.writeCharArray(*obj.getTakeOverId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeInt32(*obj.getType());
        }
        if (obj.getUserIdentifier())
        {
            writer.writePropertyName("userIdentifier");
            writer.writeCharArray(*obj.getUserIdentifier());
        }
        if (obj.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*obj.getPassword());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.writeCharArray(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.writeCharArray(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.writeCharArray(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.writeCharArray(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.writeCharArray(*obj.getResult());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2AccountRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(DescribeNamespacesRequest& request, std::function<void(AsyncDescribeNamespacesResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeNamespacesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(CreateNamespaceRequest& request, std::function<void(AsyncCreateNamespaceResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getChangePasswordIfTakeOver())
        {
            writer.writePropertyName("changePasswordIfTakeOver");
            writer.writeBool(*request.getChangePasswordIfTakeOver());
        }
        if (request.getCreateAccountTriggerScriptId())
        {
            writer.writePropertyName("createAccountTriggerScriptId");
            writer.writeCharArray(*request.getCreateAccountTriggerScriptId());
        }
        if (request.getCreateAccountDoneTriggerScriptId())
        {
            writer.writePropertyName("createAccountDoneTriggerScriptId");
            writer.writeCharArray(*request.getCreateAccountDoneTriggerScriptId());
        }
        if (request.getCreateAccountDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("createAccountDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getCreateAccountDoneTriggerQueueNamespaceId());
        }
        if (request.getAuthenticationTriggerScriptId())
        {
            writer.writePropertyName("authenticationTriggerScriptId");
            writer.writeCharArray(*request.getAuthenticationTriggerScriptId());
        }
        if (request.getAuthenticationDoneTriggerScriptId())
        {
            writer.writePropertyName("authenticationDoneTriggerScriptId");
            writer.writeCharArray(*request.getAuthenticationDoneTriggerScriptId());
        }
        if (request.getAuthenticationDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("authenticationDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getAuthenticationDoneTriggerQueueNamespaceId());
        }
        if (request.getCreateTakeOverTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverTriggerScriptId");
            writer.writeCharArray(*request.getCreateTakeOverTriggerScriptId());
        }
        if (request.getCreateTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerScriptId");
            writer.writeCharArray(*request.getCreateTakeOverDoneTriggerScriptId());
        }
        if (request.getCreateTakeOverDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getCreateTakeOverDoneTriggerQueueNamespaceId());
        }
        if (request.getDoTakeOverTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverTriggerScriptId");
            writer.writeCharArray(*request.getDoTakeOverTriggerScriptId());
        }
        if (request.getDoTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerScriptId");
            writer.writeCharArray(*request.getDoTakeOverDoneTriggerScriptId());
        }
        if (request.getDoTakeOverDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getDoTakeOverDoneTriggerQueueNamespaceId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(GetNamespaceStatusRequest& request, std::function<void(AsyncGetNamespaceStatusResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceStatusResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(GetNamespaceRequest& request, std::function<void(AsyncGetNamespaceResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(UpdateNamespaceRequest& request, std::function<void(AsyncUpdateNamespaceResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getChangePasswordIfTakeOver())
        {
            writer.writePropertyName("changePasswordIfTakeOver");
            writer.writeBool(*request.getChangePasswordIfTakeOver());
        }
        if (request.getCreateAccountTriggerScriptId())
        {
            writer.writePropertyName("createAccountTriggerScriptId");
            writer.writeCharArray(*request.getCreateAccountTriggerScriptId());
        }
        if (request.getCreateAccountDoneTriggerScriptId())
        {
            writer.writePropertyName("createAccountDoneTriggerScriptId");
            writer.writeCharArray(*request.getCreateAccountDoneTriggerScriptId());
        }
        if (request.getCreateAccountDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("createAccountDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getCreateAccountDoneTriggerQueueNamespaceId());
        }
        if (request.getAuthenticationTriggerScriptId())
        {
            writer.writePropertyName("authenticationTriggerScriptId");
            writer.writeCharArray(*request.getAuthenticationTriggerScriptId());
        }
        if (request.getAuthenticationDoneTriggerScriptId())
        {
            writer.writePropertyName("authenticationDoneTriggerScriptId");
            writer.writeCharArray(*request.getAuthenticationDoneTriggerScriptId());
        }
        if (request.getAuthenticationDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("authenticationDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getAuthenticationDoneTriggerQueueNamespaceId());
        }
        if (request.getCreateTakeOverTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverTriggerScriptId");
            writer.writeCharArray(*request.getCreateTakeOverTriggerScriptId());
        }
        if (request.getCreateTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerScriptId");
            writer.writeCharArray(*request.getCreateTakeOverDoneTriggerScriptId());
        }
        if (request.getCreateTakeOverDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getCreateTakeOverDoneTriggerQueueNamespaceId());
        }
        if (request.getDoTakeOverTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverTriggerScriptId");
            writer.writeCharArray(*request.getDoTakeOverTriggerScriptId());
        }
        if (request.getDoTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerScriptId");
            writer.writeCharArray(*request.getDoTakeOverDoneTriggerScriptId());
        }
        if (request.getDoTakeOverDoneTriggerQueueNamespaceId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerQueueNamespaceId");
            writer.writeCharArray(*request.getDoTakeOverDoneTriggerQueueNamespaceId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(DeleteNamespaceRequest& request, std::function<void(AsyncDeleteNamespaceResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ゲームプレイヤーアカウントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAccounts(DescribeAccountsRequest& request, std::function<void(AsyncDescribeAccountsResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeAccountsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ゲームプレイヤーアカウントを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createAccount(CreateAccountRequest& request, std::function<void(AsyncCreateAccountResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateAccountResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ゲームプレイヤーアカウントの現在時刻に対する補正値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTimeOffset(UpdateTimeOffsetRequest& request, std::function<void(AsyncUpdateTimeOffsetResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateTimeOffsetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/{userId}/time_offset";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getTimeOffset())
        {
            writer.writePropertyName("timeOffset");
            writer.writeInt32(*request.getTimeOffset());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ゲームプレイヤーアカウントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAccount(GetAccountRequest& request, std::function<void(AsyncGetAccountResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetAccountResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/{userId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ゲームプレイヤーアカウントを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAccount(DeleteAccountRequest& request, std::function<void(AsyncDeleteAccountResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/{userId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ゲームプレイヤーアカウントを認証<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void authentication(AuthenticationRequest& request, std::function<void(AsyncAuthenticationResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AuthenticationResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/{userId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*request.getPassword());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 引き継ぎ設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTakeOvers(DescribeTakeOversRequest& request, std::function<void(AsyncDescribeTakeOversResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeTakeOversResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/me/takeover";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTakeOversByUserId(DescribeTakeOversByUserIdRequest& request, std::function<void(AsyncDescribeTakeOversByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeTakeOversByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/{userId}/takeover";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getPageToken())
        {
            url += joint;
            url += "pageToken=";
            url += detail::StringVariable(*request.getPageToken(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getLimit())
        {
            url += joint;
            url += "limit=";
            url += detail::StringVariable(*request.getLimit()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 引き継ぎ設定を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTakeOver(CreateTakeOverRequest& request, std::function<void(AsyncCreateTakeOverResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateTakeOverResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/me/takeover";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getType())
        {
            writer.writePropertyName("type");
            writer.writeInt32(*request.getType());
        }
        if (request.getUserIdentifier())
        {
            writer.writePropertyName("userIdentifier");
            writer.writeCharArray(*request.getUserIdentifier());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*request.getPassword());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTakeOverByUserId(CreateTakeOverByUserIdRequest& request, std::function<void(AsyncCreateTakeOverByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateTakeOverByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/{userId}/takeover";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getType())
        {
            writer.writePropertyName("type");
            writer.writeInt32(*request.getType());
        }
        if (request.getUserIdentifier())
        {
            writer.writePropertyName("userIdentifier");
            writer.writeCharArray(*request.getUserIdentifier());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*request.getPassword());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 引き継ぎ設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTakeOver(GetTakeOverRequest& request, std::function<void(AsyncGetTakeOverResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetTakeOverResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/me/takeover/type/{type}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getType();
            if (value.has_value())
            {
                detail::StringVariable urlSafeValue(*value);
                url.replace("{type}", urlSafeValue.c_str());
            }
            else
            {
                url.replace("{type}", "null");
            }
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTakeOverByUserId(GetTakeOverByUserIdRequest& request, std::function<void(AsyncGetTakeOverByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetTakeOverByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/{userId}/takeover/type/{type}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getType();
            if (value.has_value())
            {
                detail::StringVariable urlSafeValue(*value);
                url.replace("{type}", urlSafeValue.c_str());
            }
            else
            {
                url.replace("{type}", "null");
            }
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTakeOver(UpdateTakeOverRequest& request, std::function<void(AsyncUpdateTakeOverResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateTakeOverResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/me/takeover/type/{type}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getType();
            if (value.has_value())
            {
                detail::StringVariable urlSafeValue(*value);
                url.replace("{type}", urlSafeValue.c_str());
            }
            else
            {
                url.replace("{type}", "null");
            }
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getOldPassword())
        {
            writer.writePropertyName("oldPassword");
            writer.writeCharArray(*request.getOldPassword());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*request.getPassword());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTakeOverByUserId(UpdateTakeOverByUserIdRequest& request, std::function<void(AsyncUpdateTakeOverByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateTakeOverByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/{userId}/takeover/type/{type}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getType();
            if (value.has_value())
            {
                detail::StringVariable urlSafeValue(*value);
                url.replace("{type}", urlSafeValue.c_str());
            }
            else
            {
                url.replace("{type}", "null");
            }
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getOldPassword())
        {
            writer.writePropertyName("oldPassword");
            writer.writeCharArray(*request.getOldPassword());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*request.getPassword());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 引き継ぎ設定を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTakeOver(DeleteTakeOverRequest& request, std::function<void(AsyncDeleteTakeOverResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/account/me/takeover/type/{type}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getType();
            if (value.has_value())
            {
                detail::StringVariable urlSafeValue(*value);
                url.replace("{type}", urlSafeValue.c_str());
            }
            else
            {
                url.replace("{type}", "null");
            }
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        if (request.getUserIdentifier())
        {
            url += joint;
            url += "userIdentifier=";
            url += detail::StringVariable(*request.getUserIdentifier(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 引き継ぎ設定を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTakeOverByUserIdentifier(DeleteTakeOverByUserIdentifierRequest& request, std::function<void(AsyncDeleteTakeOverByUserIdentifierResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/takeover/type/{type}/userIdentifier/{userIdentifier}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getType();
            if (value.has_value())
            {
                detail::StringVariable urlSafeValue(*value);
                url.replace("{type}", urlSafeValue.c_str());
            }
            else
            {
                url.replace("{type}", "null");
            }
        }
        {
            auto& value = request.getUserIdentifier();
            url.replace("{userIdentifier}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getContextStack())
        {
            url += joint;
            url += "contextStack=";
            url += detail::StringVariable(*request.getContextStack(), detail::StringVariable::UrlSafeEncode()).c_str();
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());
        {
            TArray<uint8> content(reinterpret_cast<const uint8*>("[]"), sizeof("[]") - 1);
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doTakeOver(DoTakeOverRequest& request, std::function<void(AsyncDoTakeOverResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DoTakeOverResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "account");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/takeover/type/{type}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getType();
            if (value.has_value())
            {
                detail::StringVariable urlSafeValue(*value);
                url.replace("{type}", urlSafeValue.c_str());
            }
            else
            {
                url.replace("{type}", "null");
            }
        }
        httpRequest.SetURL(url.c_str());
        detail::json::JsonWriter writer;

        writer.writeObjectStart();
        if (request.getContextStack())
        {
            writer.writePropertyName("contextStack");
            writer.writeCharArray(*request.getContextStack());
        }
        if (request.getUserIdentifier())
        {
            writer.writePropertyName("userIdentifier");
            writer.writeCharArray(*request.getUserIdentifier());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.writeCharArray(*request.getPassword());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        gs2RestSessionTask.execute();
    }

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_ACCOUNT_GS2ACCOUNTRESTCLIENT_HPP_