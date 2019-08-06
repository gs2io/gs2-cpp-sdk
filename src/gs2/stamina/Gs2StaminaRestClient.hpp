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

#ifndef GS2_STAMINA_GS2STAMINARESTCLIENT_HPP_
#define GS2_STAMINA_GS2STAMINARESTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2RestSessionTask.hpp>
#include <gs2/core/network/Gs2RestSession.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeNamespacesRequest.hpp"
#include "request/CreateNamespaceRequest.hpp"
#include "request/GetNamespaceStatusRequest.hpp"
#include "request/GetNamespaceRequest.hpp"
#include "request/UpdateNamespaceRequest.hpp"
#include "request/DeleteNamespaceRequest.hpp"
#include "request/DescribeStaminaModelMastersRequest.hpp"
#include "request/CreateStaminaModelMasterRequest.hpp"
#include "request/GetStaminaModelMasterRequest.hpp"
#include "request/UpdateStaminaModelMasterRequest.hpp"
#include "request/DeleteStaminaModelMasterRequest.hpp"
#include "request/DescribeMaxStaminaTableMastersRequest.hpp"
#include "request/CreateMaxStaminaTableMasterRequest.hpp"
#include "request/GetMaxStaminaTableMasterRequest.hpp"
#include "request/UpdateMaxStaminaTableMasterRequest.hpp"
#include "request/DeleteMaxStaminaTableMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentStaminaMasterRequest.hpp"
#include "request/UpdateCurrentStaminaMasterRequest.hpp"
#include "request/UpdateCurrentStaminaMasterFromGitHubRequest.hpp"
#include "request/DescribeStaminaModelsRequest.hpp"
#include "request/GetStaminaModelRequest.hpp"
#include "request/DescribeStaminasRequest.hpp"
#include "request/DescribeStaminasByUserIdRequest.hpp"
#include "request/GetStaminaRequest.hpp"
#include "request/GetStaminaByUserIdRequest.hpp"
#include "request/UpdateStaminaByUserIdRequest.hpp"
#include "request/ConsumeStaminaRequest.hpp"
#include "request/ConsumeStaminaByUserIdRequest.hpp"
#include "request/RecoverStaminaByUserIdRequest.hpp"
#include "request/RaiseMaxValueByUserIdRequest.hpp"
#include "request/SetMaxValueByUserIdRequest.hpp"
#include "request/SetMaxValueByStatusRequest.hpp"
#include "request/DeleteStaminaByUserIdRequest.hpp"
#include "request/RecoverStaminaByStampSheetRequest.hpp"
#include "request/RaiseMaxValueByStampSheetRequest.hpp"
#include "request/SetMaxValueByStampSheetRequest.hpp"
#include "request/ConsumeStaminaByStampTaskRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeStaminaModelMastersResult.hpp"
#include "result/CreateStaminaModelMasterResult.hpp"
#include "result/GetStaminaModelMasterResult.hpp"
#include "result/UpdateStaminaModelMasterResult.hpp"
#include "result/DeleteStaminaModelMasterResult.hpp"
#include "result/DescribeMaxStaminaTableMastersResult.hpp"
#include "result/CreateMaxStaminaTableMasterResult.hpp"
#include "result/GetMaxStaminaTableMasterResult.hpp"
#include "result/UpdateMaxStaminaTableMasterResult.hpp"
#include "result/DeleteMaxStaminaTableMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentStaminaMasterResult.hpp"
#include "result/UpdateCurrentStaminaMasterResult.hpp"
#include "result/UpdateCurrentStaminaMasterFromGitHubResult.hpp"
#include "result/DescribeStaminaModelsResult.hpp"
#include "result/GetStaminaModelResult.hpp"
#include "result/DescribeStaminasResult.hpp"
#include "result/DescribeStaminasByUserIdResult.hpp"
#include "result/GetStaminaResult.hpp"
#include "result/GetStaminaByUserIdResult.hpp"
#include "result/UpdateStaminaByUserIdResult.hpp"
#include "result/ConsumeStaminaResult.hpp"
#include "result/ConsumeStaminaByUserIdResult.hpp"
#include "result/RecoverStaminaByUserIdResult.hpp"
#include "result/RaiseMaxValueByUserIdResult.hpp"
#include "result/SetMaxValueByUserIdResult.hpp"
#include "result/SetMaxValueByStatusResult.hpp"
#include "result/DeleteStaminaByUserIdResult.hpp"
#include "result/RecoverStaminaByStampSheetResult.hpp"
#include "result/RaiseMaxValueByStampSheetResult.hpp"
#include "result/SetMaxValueByStampSheetResult.hpp"
#include "result/ConsumeStaminaByStampTaskResult.hpp"
#include <cstring>

namespace gs2 { namespace stamina {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeStaminaModelMastersResult> AsyncDescribeStaminaModelMastersResult;
typedef AsyncResult<CreateStaminaModelMasterResult> AsyncCreateStaminaModelMasterResult;
typedef AsyncResult<GetStaminaModelMasterResult> AsyncGetStaminaModelMasterResult;
typedef AsyncResult<UpdateStaminaModelMasterResult> AsyncUpdateStaminaModelMasterResult;
typedef AsyncResult<DeleteStaminaModelMasterResult> AsyncDeleteStaminaModelMasterResult;
typedef AsyncResult<DescribeMaxStaminaTableMastersResult> AsyncDescribeMaxStaminaTableMastersResult;
typedef AsyncResult<CreateMaxStaminaTableMasterResult> AsyncCreateMaxStaminaTableMasterResult;
typedef AsyncResult<GetMaxStaminaTableMasterResult> AsyncGetMaxStaminaTableMasterResult;
typedef AsyncResult<UpdateMaxStaminaTableMasterResult> AsyncUpdateMaxStaminaTableMasterResult;
typedef AsyncResult<DeleteMaxStaminaTableMasterResult> AsyncDeleteMaxStaminaTableMasterResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentStaminaMasterResult> AsyncGetCurrentStaminaMasterResult;
typedef AsyncResult<UpdateCurrentStaminaMasterResult> AsyncUpdateCurrentStaminaMasterResult;
typedef AsyncResult<UpdateCurrentStaminaMasterFromGitHubResult> AsyncUpdateCurrentStaminaMasterFromGitHubResult;
typedef AsyncResult<DescribeStaminaModelsResult> AsyncDescribeStaminaModelsResult;
typedef AsyncResult<GetStaminaModelResult> AsyncGetStaminaModelResult;
typedef AsyncResult<DescribeStaminasResult> AsyncDescribeStaminasResult;
typedef AsyncResult<DescribeStaminasByUserIdResult> AsyncDescribeStaminasByUserIdResult;
typedef AsyncResult<GetStaminaResult> AsyncGetStaminaResult;
typedef AsyncResult<GetStaminaByUserIdResult> AsyncGetStaminaByUserIdResult;
typedef AsyncResult<UpdateStaminaByUserIdResult> AsyncUpdateStaminaByUserIdResult;
typedef AsyncResult<ConsumeStaminaResult> AsyncConsumeStaminaResult;
typedef AsyncResult<ConsumeStaminaByUserIdResult> AsyncConsumeStaminaByUserIdResult;
typedef AsyncResult<RecoverStaminaByUserIdResult> AsyncRecoverStaminaByUserIdResult;
typedef AsyncResult<RaiseMaxValueByUserIdResult> AsyncRaiseMaxValueByUserIdResult;
typedef AsyncResult<SetMaxValueByUserIdResult> AsyncSetMaxValueByUserIdResult;
typedef AsyncResult<SetMaxValueByStatusResult> AsyncSetMaxValueByStatusResult;
typedef AsyncResult<void> AsyncDeleteStaminaByUserIdResult;
typedef AsyncResult<RecoverStaminaByStampSheetResult> AsyncRecoverStaminaByStampSheetResult;
typedef AsyncResult<RaiseMaxValueByStampSheetResult> AsyncRaiseMaxValueByStampSheetResult;
typedef AsyncResult<SetMaxValueByStampSheetResult> AsyncSetMaxValueByStampSheetResult;
typedef AsyncResult<ConsumeStaminaByStampTaskResult> AsyncConsumeStaminaByStampTaskResult;

/**
 * GS2 Stamina API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2StaminaRestClient : public AbstractGs2ClientBase
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
        if (obj.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.writeCharArray(*obj.getOverflowTriggerScriptId());
        }
        if (obj.getOverflowTriggerNamespaceId())
        {
            writer.writePropertyName("overflowTriggerNamespaceId");
            writer.writeCharArray(*obj.getOverflowTriggerNamespaceId());
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

    static void write(detail::json::JsonWriter& writer, const StaminaModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getStaminaModelId())
        {
            writer.writePropertyName("staminaModelId");
            writer.writeCharArray(*obj.getStaminaModelId());
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
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getRecoverIntervalMinutes())
        {
            writer.writePropertyName("recoverIntervalMinutes");
            writer.writeInt32(*obj.getRecoverIntervalMinutes());
        }
        if (obj.getRecoverValue())
        {
            writer.writePropertyName("recoverValue");
            writer.writeInt32(*obj.getRecoverValue());
        }
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getIsOverflow())
        {
            writer.writePropertyName("isOverflow");
            writer.writeBool(*obj.getIsOverflow());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*obj.getMaxCapacity());
        }
        if (obj.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*obj.getMaxStaminaTableId());
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

    static void write(detail::json::JsonWriter& writer, const MaxStaminaTableMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*obj.getMaxStaminaTableId());
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
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.writeCharArray(*obj.getDescription());
        }
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*obj.getExperienceModelId());
        }
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt32(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentStaminaMaster& obj)
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

    static void write(detail::json::JsonWriter& writer, const StaminaModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getStaminaModelId())
        {
            writer.writePropertyName("staminaModelId");
            writer.writeCharArray(*obj.getStaminaModelId());
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
        if (obj.getRecoverIntervalMinutes())
        {
            writer.writePropertyName("recoverIntervalMinutes");
            writer.writeInt32(*obj.getRecoverIntervalMinutes());
        }
        if (obj.getRecoverValue())
        {
            writer.writePropertyName("recoverValue");
            writer.writeInt32(*obj.getRecoverValue());
        }
        if (obj.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*obj.getInitialCapacity());
        }
        if (obj.getIsOverflow())
        {
            writer.writePropertyName("isOverflow");
            writer.writeBool(*obj.getIsOverflow());
        }
        if (obj.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*obj.getMaxCapacity());
        }
        if (obj.getMaxStaminaTable())
        {
            writer.writePropertyName("maxStaminaTable");
            write(writer, *obj.getMaxStaminaTable());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const MaxStaminaTable& obj)
    {
        writer.writeObjectStart();
        if (obj.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*obj.getMaxStaminaTableId());
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
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*obj.getExperienceModelId());
        }
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt32(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const Stamina& obj)
    {
        writer.writeObjectStart();
        if (obj.getStaminaId())
        {
            writer.writePropertyName("staminaId");
            writer.writeCharArray(*obj.getStaminaId());
        }
        if (obj.getStaminaName())
        {
            writer.writePropertyName("staminaName");
            writer.writeCharArray(*obj.getStaminaName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.writeInt32(*obj.getValue());
        }
        if (obj.getMaxValue())
        {
            writer.writePropertyName("maxValue");
            writer.writeInt32(*obj.getMaxValue());
        }
        if (obj.getOverflowValue())
        {
            writer.writePropertyName("overflowValue");
            writer.writeInt32(*obj.getOverflowValue());
        }
        if (obj.getNextRecoverAt())
        {
            writer.writePropertyName("nextRecoverAt");
            writer.writeInt64(*obj.getNextRecoverAt());
        }
        if (obj.getLastRecoveredAt())
        {
            writer.writePropertyName("lastRecoveredAt");
            writer.writeInt64(*obj.getLastRecoveredAt());
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
    explicit Gs2StaminaRestClient(Gs2RestSession& gs2RestSession) :
        AbstractGs2ClientBase(gs2RestSession)
    {
    }

	/**
	 * ネームスペースの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeNamespaces(std::function<void(AsyncDescribeNamespacesResult&)> callback, DescribeNamespacesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeNamespacesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";

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
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
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
	 * ネームスペースを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createNamespace(std::function<void(AsyncCreateNamespaceResult&)> callback, CreateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/";
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
        if (request.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.writeCharArray(*request.getOverflowTriggerScriptId());
        }
        if (request.getOverflowTriggerNamespaceId())
        {
            writer.writePropertyName("overflowTriggerNamespaceId");
            writer.writeCharArray(*request.getOverflowTriggerNamespaceId());
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
	 * ネームスペースの状態を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespaceStatus(std::function<void(AsyncGetNamespaceStatusResult&)> callback, GetNamespaceStatusRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceStatusResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * ネームスペースを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getNamespace(std::function<void(AsyncGetNamespaceResult&)> callback, GetNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * ネームスペースを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateNamespace(std::function<void(AsyncUpdateNamespaceResult&)> callback, UpdateNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getOverflowTriggerScriptId())
        {
            writer.writePropertyName("overflowTriggerScriptId");
            writer.writeCharArray(*request.getOverflowTriggerScriptId());
        }
        if (request.getOverflowTriggerNamespaceId())
        {
            writer.writePropertyName("overflowTriggerNamespaceId");
            writer.writeCharArray(*request.getOverflowTriggerNamespaceId());
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
	 * ネームスペースを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteNamespace(std::function<void(AsyncDeleteNamespaceResult&)> callback, DeleteNamespaceRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteNamespaceResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * スタミナモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModelMasters(std::function<void(AsyncDescribeStaminaModelMastersResult&)> callback, DescribeStaminaModelMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeStaminaModelMastersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/model";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
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
	 * スタミナモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStaminaModelMaster(std::function<void(AsyncCreateStaminaModelMasterResult&)> callback, CreateStaminaModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateStaminaModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/model";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
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
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getRecoverIntervalMinutes())
        {
            writer.writePropertyName("recoverIntervalMinutes");
            writer.writeInt32(*request.getRecoverIntervalMinutes());
        }
        if (request.getRecoverValue())
        {
            writer.writePropertyName("recoverValue");
            writer.writeInt32(*request.getRecoverValue());
        }
        if (request.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*request.getInitialCapacity());
        }
        if (request.getIsOverflow())
        {
            writer.writePropertyName("isOverflow");
            writer.writeBool(*request.getIsOverflow());
        }
        if (request.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*request.getMaxCapacity());
        }
        if (request.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*request.getMaxStaminaTableId());
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
	 * スタミナモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModelMaster(std::function<void(AsyncGetStaminaModelMasterResult&)> callback, GetStaminaModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetStaminaModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/model/{staminaName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * スタミナモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaModelMaster(std::function<void(AsyncUpdateStaminaModelMasterResult&)> callback, UpdateStaminaModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateStaminaModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/model/{staminaName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getRecoverIntervalMinutes())
        {
            writer.writePropertyName("recoverIntervalMinutes");
            writer.writeInt32(*request.getRecoverIntervalMinutes());
        }
        if (request.getRecoverValue())
        {
            writer.writePropertyName("recoverValue");
            writer.writeInt32(*request.getRecoverValue());
        }
        if (request.getInitialCapacity())
        {
            writer.writePropertyName("initialCapacity");
            writer.writeInt32(*request.getInitialCapacity());
        }
        if (request.getIsOverflow())
        {
            writer.writePropertyName("isOverflow");
            writer.writeBool(*request.getIsOverflow());
        }
        if (request.getMaxCapacity())
        {
            writer.writePropertyName("maxCapacity");
            writer.writeInt32(*request.getMaxCapacity());
        }
        if (request.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*request.getMaxStaminaTableId());
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
	 * スタミナモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaModelMaster(std::function<void(AsyncDeleteStaminaModelMasterResult&)> callback, DeleteStaminaModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteStaminaModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/model/{staminaName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * スタミナの最大値テーブルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMaxStaminaTableMasters(std::function<void(AsyncDescribeMaxStaminaTableMastersResult&)> callback, DescribeMaxStaminaTableMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeMaxStaminaTableMastersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/maxStaminaTable";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
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
	 * スタミナの最大値テーブルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMaxStaminaTableMaster(std::function<void(AsyncCreateMaxStaminaTableMasterResult&)> callback, CreateMaxStaminaTableMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateMaxStaminaTableMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/maxStaminaTable";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
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
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*request.getExperienceModelId());
        }
        if (request.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt32(list[i]);
            }
            writer.writeArrayEnd();
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
	 * スタミナの最大値テーブルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMaxStaminaTableMaster(std::function<void(AsyncGetMaxStaminaTableMasterResult&)> callback, GetMaxStaminaTableMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetMaxStaminaTableMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/maxStaminaTable/{maxStaminaTableName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getMaxStaminaTableName();
            url.replace("{maxStaminaTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * スタミナの最大値テーブルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMaxStaminaTableMaster(std::function<void(AsyncUpdateMaxStaminaTableMasterResult&)> callback, UpdateMaxStaminaTableMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateMaxStaminaTableMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/maxStaminaTable/{maxStaminaTableName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getMaxStaminaTableName();
            url.replace("{maxStaminaTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*request.getMetadata());
        }
        if (request.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*request.getExperienceModelId());
        }
        if (request.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt32(list[i]);
            }
            writer.writeArrayEnd();
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
	 * スタミナの最大値テーブルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMaxStaminaTableMaster(std::function<void(AsyncDeleteMaxStaminaTableMasterResult&)> callback, DeleteMaxStaminaTableMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteMaxStaminaTableMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/maxStaminaTable/{maxStaminaTableName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getMaxStaminaTableName();
            url.replace("{maxStaminaTableName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 現在有効なスタミナマスターのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ExportMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/export";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 現在有効な現在有効なスタミナマスターを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentStaminaMaster(std::function<void(AsyncGetCurrentStaminaMasterResult&)> callback, GetCurrentStaminaMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetCurrentStaminaMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * 現在有効な現在有効なスタミナマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentStaminaMaster(std::function<void(AsyncUpdateCurrentStaminaMasterResult&)> callback, UpdateCurrentStaminaMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentStaminaMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
        if (request.getAccessToken())
        {
            httpRequest.SetHeader("X-GS2-ACCESS-TOKEN", static_cast<const Char*>(*request.getAccessToken()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * 現在有効な現在有効なスタミナマスターを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentStaminaMasterFromGitHub(std::function<void(AsyncUpdateCurrentStaminaMasterFromGitHubResult&)> callback, UpdateCurrentStaminaMasterFromGitHubRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentStaminaMasterFromGitHubResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/from_git_hub";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
	 * スタミナモデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModels(std::function<void(AsyncDescribeStaminaModelsResult&)> callback, DescribeStaminaModelsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeStaminaModelsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/model";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * スタミナモデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModel(std::function<void(AsyncGetStaminaModelResult&)> callback, GetStaminaModelRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetStaminaModelResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/model/{staminaName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminas(std::function<void(AsyncDescribeStaminasResult&)> callback, DescribeStaminasRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeStaminasResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/stamina";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
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
	 * ユーザIDを指定してスタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminasByUserId(std::function<void(AsyncDescribeStaminasByUserIdResult&)> callback, DescribeStaminasByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeStaminasByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/stamina";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
            Char urlSafeValue[32];
            Int64 value = *request.getLimit();
            std::sprintf(urlSafeValue, "%lld", value);
            url += joint;
            url += "limit=";
            url += urlSafeValue;
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
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStamina(std::function<void(AsyncGetStaminaResult&)> callback, GetStaminaRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetStaminaResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/stamina/{staminaName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してスタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaByUserId(std::function<void(AsyncGetStaminaByUserIdResult&)> callback, GetStaminaByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetStaminaByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/stamina/{staminaName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * ユーザIDを指定してスタミナを作成・更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaByUserId(std::function<void(AsyncUpdateStaminaByUserIdResult&)> callback, UpdateStaminaByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateStaminaByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/stamina/{staminaName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getValue())
        {
            writer.writePropertyName("value");
            writer.writeInt32(*request.getValue());
        }
        if (request.getMaxValue())
        {
            writer.writePropertyName("maxValue");
            writer.writeInt32(*request.getMaxValue());
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
	 * スタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStamina(std::function<void(AsyncConsumeStaminaResult&)> callback, ConsumeStaminaRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ConsumeStaminaResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/stamina/{staminaName}/consume";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getConsumeValue())
        {
            writer.writePropertyName("consumeValue");
            writer.writeInt32(*request.getConsumeValue());
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
	 * ユーザIDを指定してスタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByUserId(std::function<void(AsyncConsumeStaminaByUserIdResult&)> callback, ConsumeStaminaByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ConsumeStaminaByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/consume";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getConsumeValue())
        {
            writer.writePropertyName("consumeValue");
            writer.writeInt32(*request.getConsumeValue());
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
	 * ユーザIDを指定してスタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByUserId(std::function<void(AsyncRecoverStaminaByUserIdResult&)> callback, RecoverStaminaByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<RecoverStaminaByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/recover";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getRecoverValue())
        {
            writer.writePropertyName("recoverValue");
            writer.writeInt32(*request.getRecoverValue());
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
	 * ユーザIDを指定してスタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByUserId(std::function<void(AsyncRaiseMaxValueByUserIdResult&)> callback, RaiseMaxValueByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<RaiseMaxValueByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/raise";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getRaiseValue())
        {
            writer.writePropertyName("raiseValue");
            writer.writeInt32(*request.getRaiseValue());
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
	 * ユーザIDを指定してスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByUserId(std::function<void(AsyncSetMaxValueByUserIdResult&)> callback, SetMaxValueByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetMaxValueByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/stamina/{staminaName}/set";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getMaxValue())
        {
            writer.writePropertyName("maxValue");
            writer.writeInt32(*request.getMaxValue());
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
	 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStatus(std::function<void(AsyncSetMaxValueByStatusResult&)> callback, SetMaxValueByStatusRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetMaxValueByStatusResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/stamina/{staminaName}/set";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
        }
        if (request.getSignedStatusBody())
        {
            writer.writePropertyName("signedStatusBody");
            writer.writeCharArray(*request.getSignedStatusBody());
        }
        if (request.getSignedStatusSignature())
        {
            writer.writePropertyName("signedStatusSignature");
            writer.writeCharArray(*request.getSignedStatusSignature());
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
	 * ユーザIDを指定してスタミナを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaByUserId(std::function<void(AsyncDeleteStaminaByUserIdResult&)> callback, DeleteStaminaByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<void>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/stamina/{staminaName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getStaminaName();
            url.replace("{staminaName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getDuplicationAvoider())
        {
            httpRequest.SetHeader("X-GS2-DUPLICATION-AVOIDER", static_cast<const Char*>(*request.getDuplicationAvoider()));
        }
        gs2RestSessionTask.execute();
    }

	/**
	 * スタンプシートを使用してスタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByStampSheet(std::function<void(AsyncRecoverStaminaByStampSheetResult&)> callback, RecoverStaminaByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<RecoverStaminaByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamina/recover";
        {
            auto& value = request.getStampSheet();
            url.replace("{stampSheet}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
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
	 * スタンプシートでスタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByStampSheet(std::function<void(AsyncRaiseMaxValueByStampSheetResult&)> callback, RaiseMaxValueByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<RaiseMaxValueByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamina/raise";
        {
            auto& value = request.getStampSheet();
            url.replace("{stampSheet}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
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
	 * スタンプシートでスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStampSheet(std::function<void(AsyncSetMaxValueByStampSheetResult&)> callback, SetMaxValueByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetMaxValueByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamina/max/set";
        {
            auto& value = request.getStampSheet();
            url.replace("{stampSheet}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
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
	 * スタンプタスクを使用してスタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByStampTask(std::function<void(AsyncConsumeStaminaByStampTaskResult&)> callback, ConsumeStaminaByStampTaskRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<ConsumeStaminaByStampTaskResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "stamina");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamina/consume";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampTask())
        {
            writer.writePropertyName("stampTask");
            writer.writeCharArray(*request.getStampTask());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
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

protected:
    Gs2RestSession& getGs2RestSession()
    {
        return static_cast<Gs2RestSession&>(getGs2Session());
    }
};

} }

#endif //GS2_STAMINA_GS2STAMINARESTCLIENT_HPP_