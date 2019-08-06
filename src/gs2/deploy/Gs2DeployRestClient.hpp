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

#ifndef GS2_DEPLOY_GS2DEPLOYRESTCLIENT_HPP_
#define GS2_DEPLOY_GS2DEPLOYRESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeStacksRequest.hpp"
#include "request/CreateStackRequest.hpp"
#include "request/CreateStackFromGitHubRequest.hpp"
#include "request/GetStackStatusRequest.hpp"
#include "request/GetStackRequest.hpp"
#include "request/UpdateStackRequest.hpp"
#include "request/UpdateStackFromGitHubRequest.hpp"
#include "request/DeleteStackRequest.hpp"
#include "request/ForceDeleteStackRequest.hpp"
#include "request/DescribeResourcesRequest.hpp"
#include "request/GetResourceRequest.hpp"
#include "request/DescribeEventsRequest.hpp"
#include "request/GetEventRequest.hpp"
#include "request/DescribeOutputsRequest.hpp"
#include "request/GetOutputRequest.hpp"
#include "result/DescribeStacksResult.hpp"
#include "result/CreateStackResult.hpp"
#include "result/CreateStackFromGitHubResult.hpp"
#include "result/GetStackStatusResult.hpp"
#include "result/GetStackResult.hpp"
#include "result/UpdateStackResult.hpp"
#include "result/UpdateStackFromGitHubResult.hpp"
#include "result/DeleteStackResult.hpp"
#include "result/ForceDeleteStackResult.hpp"
#include "result/DescribeResourcesResult.hpp"
#include "result/GetResourceResult.hpp"
#include "result/DescribeEventsResult.hpp"
#include "result/GetEventResult.hpp"
#include "result/DescribeOutputsResult.hpp"
#include "result/GetOutputResult.hpp"
#include <cstring>

namespace gs2 { namespace deploy {

typedef AsyncResult<DescribeStacksResult> AsyncDescribeStacksResult;
typedef AsyncResult<CreateStackResult> AsyncCreateStackResult;
typedef AsyncResult<CreateStackFromGitHubResult> AsyncCreateStackFromGitHubResult;
typedef AsyncResult<GetStackStatusResult> AsyncGetStackStatusResult;
typedef AsyncResult<GetStackResult> AsyncGetStackResult;
typedef AsyncResult<UpdateStackResult> AsyncUpdateStackResult;
typedef AsyncResult<UpdateStackFromGitHubResult> AsyncUpdateStackFromGitHubResult;
typedef AsyncResult<DeleteStackResult> AsyncDeleteStackResult;
typedef AsyncResult<ForceDeleteStackResult> AsyncForceDeleteStackResult;
typedef AsyncResult<DescribeResourcesResult> AsyncDescribeResourcesResult;
typedef AsyncResult<GetResourceResult> AsyncGetResourceResult;
typedef AsyncResult<DescribeEventsResult> AsyncDescribeEventsResult;
typedef AsyncResult<GetEventResult> AsyncGetEventResult;
typedef AsyncResult<DescribeOutputsResult> AsyncDescribeOutputsResult;
typedef AsyncResult<GetOutputResult> AsyncGetOutputResult;

/**
 * GS2 Deploy API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2DeployRestClient : public AbstractGs2ClientBase
{
private:
    static void write(detail::json::JsonWriter& writer, const Stack& obj)
    {
        writer.writeObjectStart();
        if (obj.getStackId())
        {
            writer.writePropertyName("stackId");
            writer.writeCharArray(*obj.getStackId());
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
        if (obj.getTemplate())
        {
            writer.writePropertyName("template");
            writer.writeCharArray(*obj.getTemplate());
        }
        if (obj.getStatus())
        {
            writer.writePropertyName("status");
            writer.writeCharArray(*obj.getStatus());
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

    static void write(detail::json::JsonWriter& writer, const Resource& obj)
    {
        writer.writeObjectStart();
        if (obj.getResourceId())
        {
            writer.writePropertyName("resourceId");
            writer.writeCharArray(*obj.getResourceId());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        if (obj.getResponse())
        {
            writer.writePropertyName("response");
            writer.writeCharArray(*obj.getResponse());
        }
        if (obj.getRollbackContext())
        {
            writer.writePropertyName("rollbackContext");
            writer.writeCharArray(*obj.getRollbackContext());
        }
        if (obj.getRollbackRequest())
        {
            writer.writePropertyName("rollbackRequest");
            writer.writeCharArray(*obj.getRollbackRequest());
        }
        if (obj.getRollbackAfter())
        {
            writer.writePropertyName("rollbackAfter");
            writer.writeArrayStart();
            auto& list = *obj.getRollbackAfter();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getOutputKeys())
        {
            writer.writePropertyName("outputKeys");
            writer.writeArrayStart();
            auto& list = *obj.getOutputKeys();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const WorkingStack& obj)
    {
        writer.writeObjectStart();
        if (obj.getStackId())
        {
            writer.writePropertyName("stackId");
            writer.writeCharArray(*obj.getStackId());
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

    static void write(detail::json::JsonWriter& writer, const WorkingResource& obj)
    {
        writer.writeObjectStart();
        if (obj.getResourceId())
        {
            writer.writePropertyName("resourceId");
            writer.writeCharArray(*obj.getResourceId());
        }
        if (obj.getContext())
        {
            writer.writePropertyName("context");
            writer.writeCharArray(*obj.getContext());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getRequest())
        {
            writer.writePropertyName("request");
            writer.writeCharArray(*obj.getRequest());
        }
        if (obj.getAfter())
        {
            writer.writePropertyName("after");
            writer.writeArrayStart();
            auto& list = *obj.getAfter();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getRollbackContext())
        {
            writer.writePropertyName("rollbackContext");
            writer.writeCharArray(*obj.getRollbackContext());
        }
        if (obj.getRollbackRequest())
        {
            writer.writePropertyName("rollbackRequest");
            writer.writeCharArray(*obj.getRollbackRequest());
        }
        if (obj.getRollbackAfter())
        {
            writer.writePropertyName("rollbackAfter");
            writer.writeArrayStart();
            auto& list = *obj.getRollbackAfter();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeCharArray(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getOutputFields())
        {
            writer.writePropertyName("outputFields");
            writer.writeArrayStart();
            auto& list = *obj.getOutputFields();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
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
        if (obj.getResourceName())
        {
            writer.writePropertyName("resourceName");
            writer.writeCharArray(*obj.getResourceName());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.writeCharArray(*obj.getType());
        }
        if (obj.getMessage())
        {
            writer.writePropertyName("message");
            writer.writeCharArray(*obj.getMessage());
        }
        if (obj.getEventAt())
        {
            writer.writePropertyName("eventAt");
            writer.writeInt64(*obj.getEventAt());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Output& obj)
    {
        writer.writeObjectStart();
        if (obj.getOutputId())
        {
            writer.writePropertyName("outputId");
            writer.writeCharArray(*obj.getOutputId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeCharArray(*obj.getValue());
        }
        if (obj.getCreatedAt())
        {
            writer.writePropertyName("createdAt");
            writer.writeInt64(*obj.getCreatedAt());
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

    static void write(detail::json::JsonWriter& writer, const OutputField& obj)
    {
        writer.writeObjectStart();
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.writeCharArray(*obj.getName());
        }
        if (obj.getFieldName())
        {
            writer.writePropertyName("fieldName");
            writer.writeCharArray(*obj.getFieldName());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2DeployRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * スタックの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStacks(std::function<void(AsyncDescribeStacksResult&)> callback, DescribeStacksRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeStacksResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack";

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
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
        gs2RestSessionTask.execute();
    }

	/**
	 * スタックを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStack(std::function<void(AsyncCreateStackResult&)> callback, CreateStackRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateStackResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
        if (request.getTemplate())
        {
            writer.writePropertyName("template");
            writer.writeCharArray(*request.getTemplate());
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
        gs2RestSessionTask.execute();
    }

	/**
	 * スタックを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStackFromGitHub(std::function<void(AsyncCreateStackFromGitHubResult&)> callback, CreateStackFromGitHubRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateStackFromGitHubResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * スタックを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStackStatus(std::function<void(AsyncGetStackStatusResult&)> callback, GetStackStatusRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetStackStatusResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}/status";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * スタックを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStack(std::function<void(AsyncGetStackResult&)> callback, GetStackRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetStackResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * スタックを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStack(std::function<void(AsyncUpdateStackResult&)> callback, UpdateStackRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateStackResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
        }
        if (request.getTemplate())
        {
            writer.writePropertyName("template");
            writer.writeCharArray(*request.getTemplate());
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
        gs2RestSessionTask.execute();
    }

	/**
	 * スタックを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStackFromGitHub(std::function<void(AsyncUpdateStackFromGitHubResult&)> callback, UpdateStackFromGitHubRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateStackFromGitHubResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}/from_git_hub";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*request.getDescription());
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * スタックを削除<br>
	 *   <br>
	 *   スタックの削除は2段階で行われます。<br>
	 *   DELETE_COMPLETED ステータスではないスタックを削除すると、まずはスタックによって作成されたリソースの削除を行います。<br>
	 *   DELETE_COMPLETED ステータスのスタックを削除すると、完全にエンティティを削除します。<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStack(std::function<void(AsyncDeleteStackResult&)> callback, DeleteStackRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteStackResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
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
        gs2RestSessionTask.execute();
    }

	/**
	 * スタックを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void forceDeleteStack(std::function<void(AsyncForceDeleteStackResult&)> callback, ForceDeleteStackRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ForceDeleteStackResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}/force";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
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
        gs2RestSessionTask.execute();
    }

	/**
	 * 作成されたのリソースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeResources(std::function<void(AsyncDescribeResourcesResult&)> callback, DescribeResourcesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeResourcesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}/resource";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
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
        gs2RestSessionTask.execute();
    }

	/**
	 * 作成されたのリソースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getResource(std::function<void(AsyncGetResourceResult&)> callback, GetResourceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetResourceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}/resource/{resourceName}";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getResourceName();
            url.replace("{resourceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 発生したイベントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeEvents(std::function<void(AsyncDescribeEventsResult&)> callback, DescribeEventsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeEventsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}/event";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
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
        gs2RestSessionTask.execute();
    }

	/**
	 * 発生したイベントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEvent(std::function<void(AsyncGetEventResult&)> callback, GetEventRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetEventResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}/event/{eventName}";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getEventName();
            url.replace("{eventName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * アウトプットの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeOutputs(std::function<void(AsyncDescribeOutputsResult&)> callback, DescribeOutputsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeOutputsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}/output";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getPageToken()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getPageToken(), sizeof(urlSafeValue));
            url += joint;
            url += "pageToken=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        if (request.getLimit()) {
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
        gs2RestSessionTask.execute();
    }

	/**
	 * アウトプットを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getOutput(std::function<void(AsyncGetOutputResult&)> callback, GetOutputRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetOutputResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "deploy");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stack/{stackName}/output/{outputName}";
        {
            auto& value = request.getStackName();
            url.replace("{stackName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getOutputName();
            url.replace("{outputName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());
        if (request.getRequestId())
        {
            httpRequest.SetHeader("X-GS2-REQUEST-ID", static_cast<const Char*>(*request.getRequestId()));
        }
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
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

#endif //GS2_DEPLOY_GS2DEPLOYRESTCLIENT_HPP_