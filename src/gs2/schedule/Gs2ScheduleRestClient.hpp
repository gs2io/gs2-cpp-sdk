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

#ifndef GS2_SCHEDULE_GS2SCHEDULERESTCLIENT_HPP_
#define GS2_SCHEDULE_GS2SCHEDULERESTCLIENT_HPP_

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
#include "request/DescribeEventMastersRequest.hpp"
#include "request/CreateEventMasterRequest.hpp"
#include "request/GetEventMasterRequest.hpp"
#include "request/UpdateEventMasterRequest.hpp"
#include "request/DeleteEventMasterRequest.hpp"
#include "request/DescribeTriggersRequest.hpp"
#include "request/DescribeTriggersByUserIdRequest.hpp"
#include "request/GetTriggerRequest.hpp"
#include "request/GetTriggerByUserIdRequest.hpp"
#include "request/TriggerByUserIdRequest.hpp"
#include "request/DeleteTriggerRequest.hpp"
#include "request/DeleteTriggerByUserIdRequest.hpp"
#include "request/DescribeEventsRequest.hpp"
#include "request/DescribeEventsByUserIdRequest.hpp"
#include "request/DescribeRawEventsRequest.hpp"
#include "request/GetEventRequest.hpp"
#include "request/GetEventByUserIdRequest.hpp"
#include "request/GetRawEventRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentEventMasterRequest.hpp"
#include "request/UpdateCurrentEventMasterRequest.hpp"
#include "request/UpdateCurrentEventMasterFromGitHubRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeEventMastersResult.hpp"
#include "result/CreateEventMasterResult.hpp"
#include "result/GetEventMasterResult.hpp"
#include "result/UpdateEventMasterResult.hpp"
#include "result/DeleteEventMasterResult.hpp"
#include "result/DescribeTriggersResult.hpp"
#include "result/DescribeTriggersByUserIdResult.hpp"
#include "result/GetTriggerResult.hpp"
#include "result/GetTriggerByUserIdResult.hpp"
#include "result/TriggerByUserIdResult.hpp"
#include "result/DeleteTriggerResult.hpp"
#include "result/DeleteTriggerByUserIdResult.hpp"
#include "result/DescribeEventsResult.hpp"
#include "result/DescribeEventsByUserIdResult.hpp"
#include "result/DescribeRawEventsResult.hpp"
#include "result/GetEventResult.hpp"
#include "result/GetEventByUserIdResult.hpp"
#include "result/GetRawEventResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentEventMasterResult.hpp"
#include "result/UpdateCurrentEventMasterResult.hpp"
#include "result/UpdateCurrentEventMasterFromGitHubResult.hpp"
#include <cstring>

namespace gs2 { namespace schedule {

/**
 * GS2 Schedule API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ScheduleRestClient : public AbstractGs2ClientBase
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

    static void write(detail::json::JsonWriter& writer, const EventMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getEventId())
        {
            writer.writePropertyName("eventId");
            writer.writeCharArray(*obj.getEventId());
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
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*obj.getScheduleType());
        }
        if (obj.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*obj.getAbsoluteBegin());
        }
        if (obj.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*obj.getAbsoluteEnd());
        }
        if (obj.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*obj.getRelativeTriggerName());
        }
        if (obj.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*obj.getRelativeDuration());
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

    static void write(detail::json::JsonWriter& writer, const Trigger& obj)
    {
        writer.writeObjectStart();
        if (obj.getTriggerId())
        {
            writer.writePropertyName("triggerId");
            writer.writeCharArray(*obj.getTriggerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        if (obj.getExpiresAt())
        {
            writer.writePropertyName("expiresAt");
            writer.writeInt64(*obj.getExpiresAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Event& obj)
    {
        writer.writeObjectStart();
        if (obj.getEventId())
        {
            writer.writePropertyName("eventId");
            writer.writeCharArray(*obj.getEventId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*obj.getScheduleType());
        }
        if (obj.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*obj.getAbsoluteBegin());
        }
        if (obj.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*obj.getAbsoluteEnd());
        }
        if (obj.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*obj.getRelativeTriggerName());
        }
        if (obj.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*obj.getRelativeDuration());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentEventMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getNamespaceName())
        {
            writer.writePropertyName("namespaceName");
            writer.writeCharArray(*obj.getNamespaceName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*obj.getSettings());
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

    static void write(detail::json::JsonWriter& writer, const GitHubCheckoutSetting& obj)
    {
        writer.writeObjectStart();
        if (obj.getGitHubApiKeyId())
        {
            writer.writePropertyName("gitHubApiKeyId");
            writer.writeCharArray(*obj.getGitHubApiKeyId());
        }
        if (obj.getRepositoryName())
        {
            writer.writePropertyName("repositoryName");
            writer.writeCharArray(*obj.getRepositoryName());
        }
        if (obj.getSourcePath())
        {
            writer.writePropertyName("sourcePath");
            writer.writeCharArray(*obj.getSourcePath());
        }
        if (obj.getReferenceType())
        {
            writer.writePropertyName("referenceType");
            writer.writeCharArray(*obj.getReferenceType());
        }
        if (obj.getCommitHash())
        {
            writer.writePropertyName("commitHash");
            writer.writeCharArray(*obj.getCommitHash());
        }
        if (obj.getBranchName())
        {
            writer.writePropertyName("branchName");
            writer.writeCharArray(*obj.getBranchName());
        }
        if (obj.getTagName())
        {
            writer.writePropertyName("tagName");
            writer.writeCharArray(*obj.getTagName());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2ScheduleRestClient(Gs2RestSession& gs2RestSession) :
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
        url.replace("{service}", "schedule");
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
        url.replace("{service}", "schedule");
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
	 * ネームスペースの状態を取得<br>
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
        url.replace("{service}", "schedule");
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
        url.replace("{service}", "schedule");
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
        url.replace("{service}", "schedule");
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
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
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
	 * イベントマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEventMasters(DescribeEventMastersRequest& request, std::function<void(AsyncDescribeEventMastersResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeEventMastersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/event";
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
	 * イベントマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createEventMaster(CreateEventMasterRequest& request, std::function<void(AsyncCreateEventMasterResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateEventMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/event";
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
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*request.getScheduleType());
        }
        if (request.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*request.getAbsoluteBegin());
        }
        if (request.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*request.getAbsoluteEnd());
        }
        if (request.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*request.getRelativeTriggerName());
        }
        if (request.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*request.getRelativeDuration());
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
	 * イベントマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEventMaster(GetEventMasterRequest& request, std::function<void(AsyncGetEventMasterResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetEventMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/event/{eventName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * イベントマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateEventMaster(UpdateEventMasterRequest& request, std::function<void(AsyncUpdateEventMasterResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateEventMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/event/{eventName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getScheduleType())
        {
            writer.writePropertyName("scheduleType");
            writer.writeCharArray(*request.getScheduleType());
        }
        if (request.getAbsoluteBegin())
        {
            writer.writePropertyName("absoluteBegin");
            writer.writeInt64(*request.getAbsoluteBegin());
        }
        if (request.getAbsoluteEnd())
        {
            writer.writePropertyName("absoluteEnd");
            writer.writeInt64(*request.getAbsoluteEnd());
        }
        if (request.getRelativeTriggerName())
        {
            writer.writePropertyName("relativeTriggerName");
            writer.writeCharArray(*request.getRelativeTriggerName());
        }
        if (request.getRelativeDuration())
        {
            writer.writePropertyName("relativeDuration");
            writer.writeInt32(*request.getRelativeDuration());
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
	 * イベントマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteEventMaster(DeleteEventMasterRequest& request, std::function<void(AsyncDeleteEventMasterResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteEventMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/event/{eventName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * トリガーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTriggers(DescribeTriggersRequest& request, std::function<void(AsyncDescribeTriggersResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeTriggersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/trigger";
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
	 * ユーザIDを指定してトリガーの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTriggersByUserId(DescribeTriggersByUserIdRequest& request, std::function<void(AsyncDescribeTriggersByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeTriggersByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/trigger";
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
	 * トリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTrigger(GetTriggerRequest& request, std::function<void(AsyncGetTriggerResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetTriggerResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/trigger/{triggerName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * ユーザIDを指定してトリガーを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTriggerByUserId(GetTriggerByUserIdRequest& request, std::function<void(AsyncGetTriggerByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetTriggerByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/trigger/{triggerName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * ユーザIDを指定してトリガーを登録<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void triggerByUserId(TriggerByUserIdRequest& request, std::function<void(AsyncTriggerByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<TriggerByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/trigger/{triggerName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getTriggerStrategy())
        {
            writer.writePropertyName("triggerStrategy");
            writer.writeCharArray(*request.getTriggerStrategy());
        }
        if (request.getTtl())
        {
            writer.writePropertyName("ttl");
            writer.writeInt32(*request.getTtl());
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
	 * トリガーを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTrigger(DeleteTriggerRequest& request, std::function<void(AsyncDeleteTriggerResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteTriggerResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/trigger/{triggerName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * ユーザIDを指定してトリガーを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTriggerByUserId(DeleteTriggerByUserIdRequest& request, std::function<void(AsyncDeleteTriggerByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteTriggerByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/trigger/{triggerName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getTriggerName();
            url.replace("{triggerName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * イベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEvents(DescribeEventsRequest& request, std::function<void(AsyncDescribeEventsResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeEventsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/event";
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
	 * ユーザIDを指定してイベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEventsByUserId(DescribeEventsByUserIdRequest& request, std::function<void(AsyncDescribeEventsByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeEventsByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/event";
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
	 * イベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRawEvents(DescribeRawEventsRequest& request, std::function<void(AsyncDescribeRawEventsResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeRawEventsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/event";
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
	 * イベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEvent(GetEventRequest& request, std::function<void(AsyncGetEventResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetEventResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/event/{eventName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * ユーザIDを指定してイベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEventByUserId(GetEventByUserIdRequest& request, std::function<void(AsyncGetEventByUserIdResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetEventByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/event/{eventName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * イベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRawEvent(GetRawEventRequest& request, std::function<void(AsyncGetRawEventResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetRawEventResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/event/{eventName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 現在有効なイベントスケジュールマスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(ExportMasterRequest& request, std::function<void(AsyncExportMasterResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ExportMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/export";
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
	 * 現在有効な現在有効なイベントスケジュールマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentEventMaster(GetCurrentEventMasterRequest& request, std::function<void(AsyncGetCurrentEventMasterResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetCurrentEventMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
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
	 * 現在有効な現在有効なイベントスケジュールマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEventMaster(UpdateCurrentEventMasterRequest& request, std::function<void(AsyncUpdateCurrentEventMasterResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentEventMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
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
        if (request.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*request.getSettings());
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
	 * 現在有効な現在有効なイベントスケジュールマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentEventMasterFromGitHub(UpdateCurrentEventMasterFromGitHubRequest& request, std::function<void(AsyncUpdateCurrentEventMasterFromGitHubResult&)> callback)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentEventMasterFromGitHubResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "schedule");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/from_git_hub";
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
        if (request.getCheckoutSetting())
        {
            writer.writePropertyName("checkoutSetting");
            write(writer, *request.getCheckoutSetting());
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

#endif //GS2_SCHEDULE_GS2SCHEDULERESTCLIENT_HPP_