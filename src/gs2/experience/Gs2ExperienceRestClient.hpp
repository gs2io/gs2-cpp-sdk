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

#ifndef GS2_EXPERIENCE_GS2EXPERIENCERESTCLIENT_HPP_
#define GS2_EXPERIENCE_GS2EXPERIENCERESTCLIENT_HPP_

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
#include "request/DescribeExperienceModelMastersRequest.hpp"
#include "request/CreateExperienceModelMasterRequest.hpp"
#include "request/GetExperienceModelMasterRequest.hpp"
#include "request/UpdateExperienceModelMasterRequest.hpp"
#include "request/DeleteExperienceModelMasterRequest.hpp"
#include "request/DescribeExperienceModelsRequest.hpp"
#include "request/GetExperienceModelRequest.hpp"
#include "request/DescribeThresholdMastersRequest.hpp"
#include "request/CreateThresholdMasterRequest.hpp"
#include "request/GetThresholdMasterRequest.hpp"
#include "request/UpdateThresholdMasterRequest.hpp"
#include "request/DeleteThresholdMasterRequest.hpp"
#include "request/ExportMasterRequest.hpp"
#include "request/GetCurrentExperienceMasterRequest.hpp"
#include "request/UpdateCurrentExperienceMasterRequest.hpp"
#include "request/DescribeStatusesRequest.hpp"
#include "request/DescribeStatusesByUserIdRequest.hpp"
#include "request/GetStatusRequest.hpp"
#include "request/GetStatusByUserIdRequest.hpp"
#include "request/GetStatusWithSignatureRequest.hpp"
#include "request/AddExperienceByUserIdRequest.hpp"
#include "request/SetExperienceByUserIdRequest.hpp"
#include "request/AddRankCapByUserIdRequest.hpp"
#include "request/SetRankCapByUserIdRequest.hpp"
#include "request/DeleteStatusByUserIdRequest.hpp"
#include "request/AddExperienceByStampSheetRequest.hpp"
#include "request/AddRankCapByStampSheetRequest.hpp"
#include "request/SetRankCapByStampSheetRequest.hpp"
#include "result/DescribeNamespacesResult.hpp"
#include "result/CreateNamespaceResult.hpp"
#include "result/GetNamespaceStatusResult.hpp"
#include "result/GetNamespaceResult.hpp"
#include "result/UpdateNamespaceResult.hpp"
#include "result/DeleteNamespaceResult.hpp"
#include "result/DescribeExperienceModelMastersResult.hpp"
#include "result/CreateExperienceModelMasterResult.hpp"
#include "result/GetExperienceModelMasterResult.hpp"
#include "result/UpdateExperienceModelMasterResult.hpp"
#include "result/DeleteExperienceModelMasterResult.hpp"
#include "result/DescribeExperienceModelsResult.hpp"
#include "result/GetExperienceModelResult.hpp"
#include "result/DescribeThresholdMastersResult.hpp"
#include "result/CreateThresholdMasterResult.hpp"
#include "result/GetThresholdMasterResult.hpp"
#include "result/UpdateThresholdMasterResult.hpp"
#include "result/DeleteThresholdMasterResult.hpp"
#include "result/ExportMasterResult.hpp"
#include "result/GetCurrentExperienceMasterResult.hpp"
#include "result/UpdateCurrentExperienceMasterResult.hpp"
#include "result/DescribeStatusesResult.hpp"
#include "result/DescribeStatusesByUserIdResult.hpp"
#include "result/GetStatusResult.hpp"
#include "result/GetStatusByUserIdResult.hpp"
#include "result/GetStatusWithSignatureResult.hpp"
#include "result/AddExperienceByUserIdResult.hpp"
#include "result/SetExperienceByUserIdResult.hpp"
#include "result/AddRankCapByUserIdResult.hpp"
#include "result/SetRankCapByUserIdResult.hpp"
#include "result/DeleteStatusByUserIdResult.hpp"
#include "result/AddExperienceByStampSheetResult.hpp"
#include "result/AddRankCapByStampSheetResult.hpp"
#include "result/SetRankCapByStampSheetResult.hpp"
#include <cstring>

namespace gs2 { namespace experience {

typedef AsyncResult<DescribeNamespacesResult> AsyncDescribeNamespacesResult;
typedef AsyncResult<CreateNamespaceResult> AsyncCreateNamespaceResult;
typedef AsyncResult<GetNamespaceStatusResult> AsyncGetNamespaceStatusResult;
typedef AsyncResult<GetNamespaceResult> AsyncGetNamespaceResult;
typedef AsyncResult<UpdateNamespaceResult> AsyncUpdateNamespaceResult;
typedef AsyncResult<DeleteNamespaceResult> AsyncDeleteNamespaceResult;
typedef AsyncResult<DescribeExperienceModelMastersResult> AsyncDescribeExperienceModelMastersResult;
typedef AsyncResult<CreateExperienceModelMasterResult> AsyncCreateExperienceModelMasterResult;
typedef AsyncResult<GetExperienceModelMasterResult> AsyncGetExperienceModelMasterResult;
typedef AsyncResult<UpdateExperienceModelMasterResult> AsyncUpdateExperienceModelMasterResult;
typedef AsyncResult<DeleteExperienceModelMasterResult> AsyncDeleteExperienceModelMasterResult;
typedef AsyncResult<DescribeExperienceModelsResult> AsyncDescribeExperienceModelsResult;
typedef AsyncResult<GetExperienceModelResult> AsyncGetExperienceModelResult;
typedef AsyncResult<DescribeThresholdMastersResult> AsyncDescribeThresholdMastersResult;
typedef AsyncResult<CreateThresholdMasterResult> AsyncCreateThresholdMasterResult;
typedef AsyncResult<GetThresholdMasterResult> AsyncGetThresholdMasterResult;
typedef AsyncResult<UpdateThresholdMasterResult> AsyncUpdateThresholdMasterResult;
typedef AsyncResult<DeleteThresholdMasterResult> AsyncDeleteThresholdMasterResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetCurrentExperienceMasterResult> AsyncGetCurrentExperienceMasterResult;
typedef AsyncResult<UpdateCurrentExperienceMasterResult> AsyncUpdateCurrentExperienceMasterResult;
typedef AsyncResult<DescribeStatusesResult> AsyncDescribeStatusesResult;
typedef AsyncResult<DescribeStatusesByUserIdResult> AsyncDescribeStatusesByUserIdResult;
typedef AsyncResult<GetStatusResult> AsyncGetStatusResult;
typedef AsyncResult<GetStatusByUserIdResult> AsyncGetStatusByUserIdResult;
typedef AsyncResult<GetStatusWithSignatureResult> AsyncGetStatusWithSignatureResult;
typedef AsyncResult<AddExperienceByUserIdResult> AsyncAddExperienceByUserIdResult;
typedef AsyncResult<SetExperienceByUserIdResult> AsyncSetExperienceByUserIdResult;
typedef AsyncResult<AddRankCapByUserIdResult> AsyncAddRankCapByUserIdResult;
typedef AsyncResult<SetRankCapByUserIdResult> AsyncSetRankCapByUserIdResult;
typedef AsyncResult<DeleteStatusByUserIdResult> AsyncDeleteStatusByUserIdResult;
typedef AsyncResult<AddExperienceByStampSheetResult> AsyncAddExperienceByStampSheetResult;
typedef AsyncResult<AddRankCapByStampSheetResult> AsyncAddRankCapByStampSheetResult;
typedef AsyncResult<SetRankCapByStampSheetResult> AsyncSetRankCapByStampSheetResult;

/**
 * GS2 Experience API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
class Gs2ExperienceRestClient : public AbstractGs2ClientBase
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
        if (obj.getExperienceCapScriptId())
        {
            writer.writePropertyName("experienceCapScriptId");
            writer.writeCharArray(*obj.getExperienceCapScriptId());
        }
        if (obj.getChangeExperienceTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceTriggerScriptId");
            writer.writeCharArray(*obj.getChangeExperienceTriggerScriptId());
        }
        if (obj.getChangeExperienceDoneTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerScriptId");
            writer.writeCharArray(*obj.getChangeExperienceDoneTriggerScriptId());
        }
        if (obj.getChangeExperienceDoneTriggerNamespaceId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerNamespaceId");
            writer.writeCharArray(*obj.getChangeExperienceDoneTriggerNamespaceId());
        }
        if (obj.getChangeRankTriggerScriptId())
        {
            writer.writePropertyName("changeRankTriggerScriptId");
            writer.writeCharArray(*obj.getChangeRankTriggerScriptId());
        }
        if (obj.getChangeRankTriggerNamespaceId())
        {
            writer.writePropertyName("changeRankTriggerNamespaceId");
            writer.writeCharArray(*obj.getChangeRankTriggerNamespaceId());
        }
        if (obj.getChangeRankCapTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapTriggerScriptId");
            writer.writeCharArray(*obj.getChangeRankCapTriggerScriptId());
        }
        if (obj.getChangeRankCapDoneTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerScriptId");
            writer.writeCharArray(*obj.getChangeRankCapDoneTriggerScriptId());
        }
        if (obj.getChangeRankCapDoneTriggerNamespaceId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerNamespaceId");
            writer.writeCharArray(*obj.getChangeRankCapDoneTriggerNamespaceId());
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

    static void write(detail::json::JsonWriter& writer, const ExperienceModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*obj.getExperienceModelId());
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
        if (obj.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.writeInt64(*obj.getDefaultExperience());
        }
        if (obj.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.writeInt64(*obj.getDefaultRankCap());
        }
        if (obj.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.writeInt64(*obj.getMaxRankCap());
        }
        if (obj.getRankThresholdId())
        {
            writer.writePropertyName("rankThresholdId");
            writer.writeCharArray(*obj.getRankThresholdId());
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

    static void write(detail::json::JsonWriter& writer, const ExperienceModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.writeCharArray(*obj.getExperienceModelId());
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
        if (obj.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.writeInt64(*obj.getDefaultExperience());
        }
        if (obj.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.writeInt64(*obj.getDefaultRankCap());
        }
        if (obj.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.writeInt64(*obj.getMaxRankCap());
        }
        if (obj.getRankThreshold())
        {
            writer.writePropertyName("rankThreshold");
            write(writer, *obj.getRankThreshold());
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const ThresholdMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getThresholdId())
        {
            writer.writePropertyName("thresholdId");
            writer.writeCharArray(*obj.getThresholdId());
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
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt64(list[i]);
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

    static void write(detail::json::JsonWriter& writer, const Threshold& obj)
    {
        writer.writeObjectStart();
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.writeCharArray(*obj.getMetadata());
        }
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt64(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    static void write(detail::json::JsonWriter& writer, const CurrentExperienceMaster& obj)
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

    static void write(detail::json::JsonWriter& writer, const Status& obj)
    {
        writer.writeObjectStart();
        if (obj.getStatusId())
        {
            writer.writePropertyName("statusId");
            writer.writeCharArray(*obj.getStatusId());
        }
        if (obj.getExperienceName())
        {
            writer.writePropertyName("experienceName");
            writer.writeCharArray(*obj.getExperienceName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.writeCharArray(*obj.getUserId());
        }
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.writeCharArray(*obj.getPropertyId());
        }
        if (obj.getExperienceValue())
        {
            writer.writePropertyName("experienceValue");
            writer.writeInt64(*obj.getExperienceValue());
        }
        if (obj.getRankValue())
        {
            writer.writePropertyName("rankValue");
            writer.writeInt64(*obj.getRankValue());
        }
        if (obj.getRankCapValue())
        {
            writer.writePropertyName("rankCapValue");
            writer.writeInt64(*obj.getRankCapValue());
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



public:
    /**
     * コンストラクタ。
     *
     * @param gs2RestSession REST API 用セッション
     */
    explicit Gs2ExperienceRestClient(Gs2RestSession& gs2RestSession) :
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
        url.replace("{service}", "experience");
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

        std::vector<std::string> headerEntries;
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
        url.replace("{service}", "experience");
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
        if (request.getExperienceCapScriptId())
        {
            writer.writePropertyName("experienceCapScriptId");
            writer.writeCharArray(*request.getExperienceCapScriptId());
        }
        if (request.getChangeExperienceTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceTriggerScriptId");
            writer.writeCharArray(*request.getChangeExperienceTriggerScriptId());
        }
        if (request.getChangeExperienceDoneTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerScriptId");
            writer.writeCharArray(*request.getChangeExperienceDoneTriggerScriptId());
        }
        if (request.getChangeExperienceDoneTriggerNamespaceId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getChangeExperienceDoneTriggerNamespaceId());
        }
        if (request.getChangeRankTriggerScriptId())
        {
            writer.writePropertyName("changeRankTriggerScriptId");
            writer.writeCharArray(*request.getChangeRankTriggerScriptId());
        }
        if (request.getChangeRankTriggerNamespaceId())
        {
            writer.writePropertyName("changeRankTriggerNamespaceId");
            writer.writeCharArray(*request.getChangeRankTriggerNamespaceId());
        }
        if (request.getChangeRankCapTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapTriggerScriptId");
            writer.writeCharArray(*request.getChangeRankCapTriggerScriptId());
        }
        if (request.getChangeRankCapDoneTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerScriptId");
            writer.writeCharArray(*request.getChangeRankCapDoneTriggerScriptId());
        }
        if (request.getChangeRankCapDoneTriggerNamespaceId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getChangeRankCapDoneTriggerNamespaceId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
    void getNamespaceStatus(std::function<void(AsyncGetNamespaceStatusResult&)> callback, GetNamespaceStatusRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetNamespaceStatusResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
        url.replace("{service}", "experience");
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
        if (request.getExperienceCapScriptId())
        {
            writer.writePropertyName("experienceCapScriptId");
            writer.writeCharArray(*request.getExperienceCapScriptId());
        }
        if (request.getChangeExperienceTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceTriggerScriptId");
            writer.writeCharArray(*request.getChangeExperienceTriggerScriptId());
        }
        if (request.getChangeExperienceDoneTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerScriptId");
            writer.writeCharArray(*request.getChangeExperienceDoneTriggerScriptId());
        }
        if (request.getChangeExperienceDoneTriggerNamespaceId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getChangeExperienceDoneTriggerNamespaceId());
        }
        if (request.getChangeRankTriggerScriptId())
        {
            writer.writePropertyName("changeRankTriggerScriptId");
            writer.writeCharArray(*request.getChangeRankTriggerScriptId());
        }
        if (request.getChangeRankTriggerNamespaceId())
        {
            writer.writePropertyName("changeRankTriggerNamespaceId");
            writer.writeCharArray(*request.getChangeRankTriggerNamespaceId());
        }
        if (request.getChangeRankCapTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapTriggerScriptId");
            writer.writeCharArray(*request.getChangeRankCapTriggerScriptId());
        }
        if (request.getChangeRankCapDoneTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerScriptId");
            writer.writeCharArray(*request.getChangeRankCapDoneTriggerScriptId());
        }
        if (request.getChangeRankCapDoneTriggerNamespaceId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerNamespaceId");
            writer.writeCharArray(*request.getChangeRankCapDoneTriggerNamespaceId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * 経験値の種類マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeExperienceModelMasters(std::function<void(AsyncDescribeExperienceModelMastersResult&)> callback, DescribeExperienceModelMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeExperienceModelMastersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
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

        std::vector<std::string> headerEntries;
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
	 * 経験値の種類マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createExperienceModelMaster(std::function<void(AsyncCreateExperienceModelMasterResult&)> callback, CreateExperienceModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateExperienceModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
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
        if (request.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.writeInt64(*request.getDefaultExperience());
        }
        if (request.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.writeInt64(*request.getDefaultRankCap());
        }
        if (request.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.writeInt64(*request.getMaxRankCap());
        }
        if (request.getRankThresholdId())
        {
            writer.writePropertyName("rankThresholdId");
            writer.writeCharArray(*request.getRankThresholdId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * 経験値の種類マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperienceModelMaster(std::function<void(AsyncGetExperienceModelMasterResult&)> callback, GetExperienceModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetExperienceModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/model/{experienceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * 経験値の種類マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateExperienceModelMaster(std::function<void(AsyncUpdateExperienceModelMasterResult&)> callback, UpdateExperienceModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateExperienceModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/model/{experienceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.writeInt64(*request.getDefaultExperience());
        }
        if (request.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.writeInt64(*request.getDefaultRankCap());
        }
        if (request.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.writeInt64(*request.getMaxRankCap());
        }
        if (request.getRankThresholdId())
        {
            writer.writePropertyName("rankThresholdId");
            writer.writeCharArray(*request.getRankThresholdId());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * 経験値の種類マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteExperienceModelMaster(std::function<void(AsyncDeleteExperienceModelMasterResult&)> callback, DeleteExperienceModelMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteExperienceModelMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/model/{experienceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * 経験値・ランクアップ閾値モデルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeExperienceModels(std::function<void(AsyncDescribeExperienceModelsResult&)> callback, DescribeExperienceModelsRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeExperienceModelsResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/model";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * 経験値・ランクアップ閾値モデルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperienceModel(std::function<void(AsyncGetExperienceModelResult&)> callback, GetExperienceModelRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetExperienceModelResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/model/{experienceName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * ランクアップ閾値マスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeThresholdMasters(std::function<void(AsyncDescribeThresholdMastersResult&)> callback, DescribeThresholdMastersRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeThresholdMastersResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/threshold";
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

        std::vector<std::string> headerEntries;
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
	 * ランクアップ閾値マスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createThresholdMaster(std::function<void(AsyncCreateThresholdMasterResult&)> callback, CreateThresholdMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<CreateThresholdMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/threshold";
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
        if (request.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt64(list[i]);
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

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * ランクアップ閾値マスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getThresholdMaster(std::function<void(AsyncGetThresholdMasterResult&)> callback, GetThresholdMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetThresholdMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/threshold/{thresholdName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getThresholdName();
            url.replace("{thresholdName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * ランクアップ閾値マスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateThresholdMaster(std::function<void(AsyncUpdateThresholdMasterResult&)> callback, UpdateThresholdMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateThresholdMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/threshold/{thresholdName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getThresholdName();
            url.replace("{thresholdName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
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
        if (request.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *request.getValues();
            for (Int32 i = 0; i < detail::getCountOfListElements(list); ++i)
            {
                writer.writeInt64(list[i]);
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

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * ランクアップ閾値マスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteThresholdMaster(std::function<void(AsyncDeleteThresholdMasterResult&)> callback, DeleteThresholdMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteThresholdMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/threshold/{thresholdName}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getThresholdName();
            url.replace("{thresholdName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * 現在有効な経験値設定のマスターデータをエクスポートします<br>
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
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master/export";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * 現在有効な現在有効な経験値設定を取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentExperienceMaster(std::function<void(AsyncGetCurrentExperienceMasterResult&)> callback, GetCurrentExperienceMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetCurrentExperienceMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/master";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * 現在有効な現在有効な経験値設定を更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentExperienceMaster(std::function<void(AsyncUpdateCurrentExperienceMasterResult&)> callback, UpdateCurrentExperienceMasterRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<UpdateCurrentExperienceMasterResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
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

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * ステータスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatuses(std::function<void(AsyncDescribeStatusesResult&)> callback, DescribeStatusesRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeStatusesResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getExperienceName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getExperienceName(), sizeof(urlSafeValue));
            url += joint;
            url += "experienceName=";
            url += urlSafeValue;
            joint[0] = '&';
        }
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

        std::vector<std::string> headerEntries;
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
	 * ステータスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatusesByUserId(std::function<void(AsyncDescribeStatusesByUserIdResult&)> callback, DescribeStatusesByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DescribeStatusesByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/status";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getExperienceName()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getExperienceName(), sizeof(urlSafeValue));
            url += joint;
            url += "experienceName=";
            url += urlSafeValue;
            joint[0] = '&';
        }
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

        std::vector<std::string> headerEntries;
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
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatus(std::function<void(AsyncGetStatusResult&)> callback, GetStatusRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetStatusResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/status/model/{experienceName}/property/{propertyId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPropertyId();
            url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusByUserId(std::function<void(AsyncGetStatusByUserIdResult&)> callback, GetStatusByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetStatusByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPropertyId();
            url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusWithSignature(std::function<void(AsyncGetStatusWithSignatureResult&)> callback, GetStatusWithSignatureRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<GetStatusWithSignatureResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("GET");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/me/status/model/{experienceName}/property/{propertyId}/signature";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPropertyId();
            url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        if (request.getKeyId()) {
            Char urlSafeValue[2048];
            gs2::detail::encodeUrl(urlSafeValue, *request.getKeyId(), sizeof(urlSafeValue));
            url += joint;
            url += "keyId=";
            url += urlSafeValue;
            joint[0] = '&';
        }
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * 経験値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addExperienceByUserId(std::function<void(AsyncAddExperienceByUserIdResult&)> callback, AddExperienceByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AddExperienceByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPropertyId();
            url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getExperienceValue())
        {
            writer.writePropertyName("experienceValue");
            writer.writeInt64(*request.getExperienceValue());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * 累計獲得経験値を設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setExperienceByUserId(std::function<void(AsyncSetExperienceByUserIdResult&)> callback, SetExperienceByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetExperienceByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPropertyId();
            url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getExperienceValue())
        {
            writer.writePropertyName("experienceValue");
            writer.writeInt64(*request.getExperienceValue());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * ランクキャップを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addRankCapByUserId(std::function<void(AsyncAddRankCapByUserIdResult&)> callback, AddRankCapByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AddRankCapByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}/cap";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPropertyId();
            url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getRankCapValue())
        {
            writer.writePropertyName("rankCapValue");
            writer.writeInt64(*request.getRankCapValue());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * ランクキャップを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRankCapByUserId(std::function<void(AsyncSetRankCapByUserIdResult&)> callback, SetRankCapByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetRankCapByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("PUT");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}/cap";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPropertyId();
            url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getRankCapValue())
        {
            writer.writePropertyName("rankCapValue");
            writer.writeInt64(*request.getRankCapValue());
        }
        writer.writeObjectEnd();
        {
            auto body = writer.toString();
            TArray<uint8> content(reinterpret_cast<const uint8*>(body), std::strlen(body));
            httpRequest.SetContent(content);
        }
        httpRequest.SetHeader("Content-Type", "application/json");

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * ステータスを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStatusByUserId(std::function<void(AsyncDeleteStatusByUserIdResult&)> callback, DeleteStatusByUserIdRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<DeleteStatusByUserIdResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("DELETE");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/{namespaceName}/user/{userId}/status/model/{experienceName}/property/{propertyId}";
        {
            auto& value = request.getNamespaceName();
            url.replace("{namespaceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getUserId();
            url.replace("{userId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getExperienceName();
            url.replace("{experienceName}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }
        {
            auto& value = request.getPropertyId();
            url.replace("{propertyId}", value.has_value() && (*value)[0] != '\0' ? *value : "null");
        }

        Char joint[] = { '?', '\0' };
        httpRequest.SetURL(url.c_str());

        std::vector<std::string> headerEntries;
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
	 * 経験値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addExperienceByStampSheet(std::function<void(AsyncAddExperienceByStampSheetResult&)> callback, AddExperienceByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AddExperienceByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/experience/add";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.writeCharArray(*request.getStampSheet());
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

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * ランクキャップを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addRankCapByStampSheet(std::function<void(AsyncAddRankCapByStampSheetResult&)> callback, AddRankCapByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<AddRankCapByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/rankCap/add";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.writeCharArray(*request.getStampSheet());
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

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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
	 * ランクキャップを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRankCapByStampSheet(std::function<void(AsyncSetRankCapByStampSheetResult&)> callback, SetRankCapByStampSheetRequest& request)
    {
        auto& gs2RestSessionTask = *new detail::Gs2RestSessionTask<SetRankCapByStampSheetResult>(getGs2RestSession(), callback);
        auto& httpRequest = gs2RestSessionTask.getGs2HttpTask().getHttpRequest();
        httpRequest.SetVerb("POST");
        detail::StringVariable url(Gs2RestSession::EndpointHost);
        url.replace("{service}", "experience");
        url.replace("{region}", getGs2RestSession().getRegion().getName());
        url += "/stamp/rankCap/set";
        httpRequest.SetURL(url.c_str());
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.writeCharArray(*request.getStampSheet());
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

        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
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

#endif //GS2_EXPERIENCE_GS2EXPERIENCERESTCLIENT_HPP_