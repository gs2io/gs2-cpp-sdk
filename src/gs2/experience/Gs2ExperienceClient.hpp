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

#ifndef GS2_EXPERIENCE_GS2EXPERIENCECLIENT_HPP_
#define GS2_EXPERIENCE_GS2EXPERIENCECLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeExperiencesRequest.hpp"
#include "request/CreateExperienceRequest.hpp"
#include "request/GetExperienceStatusRequest.hpp"
#include "request/GetExperienceRequest.hpp"
#include "request/UpdateExperienceRequest.hpp"
#include "request/DeleteExperienceRequest.hpp"
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
#include "request/GetStatusesRequest.hpp"
#include "request/GetStatusesByUserIdRequest.hpp"
#include "request/AddExperienceByUserIdRequest.hpp"
#include "request/SetExperienceByUserIdRequest.hpp"
#include "request/AddRankCapByUserIdRequest.hpp"
#include "request/SetRankCapByUserIdRequest.hpp"
#include "request/DeleteStatusByUserIdRequest.hpp"
#include "request/AddExperienceByStampSheetRequest.hpp"
#include "request/AddRankCapByStampSheetRequest.hpp"
#include "request/SetRankCapByStampSheetRequest.hpp"
#include "result/DescribeExperiencesResult.hpp"
#include "result/CreateExperienceResult.hpp"
#include "result/GetExperienceStatusResult.hpp"
#include "result/GetExperienceResult.hpp"
#include "result/UpdateExperienceResult.hpp"
#include "result/DeleteExperienceResult.hpp"
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
#include "result/GetStatusesResult.hpp"
#include "result/GetStatusesByUserIdResult.hpp"
#include "result/AddExperienceByUserIdResult.hpp"
#include "result/SetExperienceByUserIdResult.hpp"
#include "result/AddRankCapByUserIdResult.hpp"
#include "result/SetRankCapByUserIdResult.hpp"
#include "result/DeleteStatusByUserIdResult.hpp"
#include "result/AddExperienceByStampSheetResult.hpp"
#include "result/AddRankCapByStampSheetResult.hpp"
#include "result/SetRankCapByStampSheetResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace experience {

typedef AsyncResult<DescribeExperiencesResult> AsyncDescribeExperiencesResult;
typedef AsyncResult<CreateExperienceResult> AsyncCreateExperienceResult;
typedef AsyncResult<GetExperienceStatusResult> AsyncGetExperienceStatusResult;
typedef AsyncResult<GetExperienceResult> AsyncGetExperienceResult;
typedef AsyncResult<UpdateExperienceResult> AsyncUpdateExperienceResult;
typedef AsyncResult<DeleteExperienceResult> AsyncDeleteExperienceResult;
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
typedef AsyncResult<GetStatusesResult> AsyncGetStatusesResult;
typedef AsyncResult<GetStatusesByUserIdResult> AsyncGetStatusesByUserIdResult;
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
class Gs2ExperienceClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "experience";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const Experience& obj)
    {
        writer.writeObjectStart();
        if (obj.getExperienceId())
        {
            writer.writePropertyName("experienceId");
            writer.write(*obj.getExperienceId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getExperienceCapScriptId())
        {
            writer.writePropertyName("experienceCapScriptId");
            writer.write(*obj.getExperienceCapScriptId());
        }
        if (obj.getChangeExperienceTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceTriggerScriptId");
            writer.write(*obj.getChangeExperienceTriggerScriptId());
        }
        if (obj.getChangeExperienceDoneTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerScriptId");
            writer.write(*obj.getChangeExperienceDoneTriggerScriptId());
        }
        if (obj.getChangeExperienceDoneTriggerQueueId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerQueueId");
            writer.write(*obj.getChangeExperienceDoneTriggerQueueId());
        }
        if (obj.getChangeRankTriggerScriptId())
        {
            writer.writePropertyName("changeRankTriggerScriptId");
            writer.write(*obj.getChangeRankTriggerScriptId());
        }
        if (obj.getChangeRankTriggerQueueId())
        {
            writer.writePropertyName("changeRankTriggerQueueId");
            writer.write(*obj.getChangeRankTriggerQueueId());
        }
        if (obj.getChangeRankCapTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapTriggerScriptId");
            writer.write(*obj.getChangeRankCapTriggerScriptId());
        }
        if (obj.getChangeRankCapDoneTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerScriptId");
            writer.write(*obj.getChangeRankCapDoneTriggerScriptId());
        }
        if (obj.getChangeRankCapDoneTriggerQueueId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerQueueId");
            writer.write(*obj.getChangeRankCapDoneTriggerQueueId());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ExperienceModelMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.write(*obj.getExperienceModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.write(*obj.getDefaultExperience());
        }
        if (obj.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.write(*obj.getDefaultRankCap());
        }
        if (obj.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.write(*obj.getMaxRankCap());
        }
        if (obj.getRankThresholdId())
        {
            writer.writePropertyName("rankThresholdId");
            writer.write(*obj.getRankThresholdId());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ExperienceModel& obj)
    {
        writer.writeObjectStart();
        if (obj.getExperienceModelId())
        {
            writer.writePropertyName("experienceModelId");
            writer.write(*obj.getExperienceModelId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.write(*obj.getDefaultExperience());
        }
        if (obj.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.write(*obj.getDefaultRankCap());
        }
        if (obj.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.write(*obj.getMaxRankCap());
        }
        if (obj.getRankThreshold())
        {
            writer.writePropertyName("rankThreshold");
            write(writer, *obj.getRankThreshold());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ThresholdMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getThresholdId())
        {
            writer.writePropertyName("thresholdId");
            writer.write(*obj.getThresholdId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*obj.getDescription());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Threshold& obj)
    {
        writer.writeObjectStart();
        if (obj.getThresholdId())
        {
            writer.writePropertyName("thresholdId");
            writer.write(*obj.getThresholdId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*obj.getMetadata());
        }
        if (obj.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *obj.getValues();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const CurrentExperienceMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getExperienceName())
        {
            writer.writePropertyName("experienceName");
            writer.write(*obj.getExperienceName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.write(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Status& obj)
    {
        writer.writeObjectStart();
        if (obj.getStatusId())
        {
            writer.writePropertyName("statusId");
            writer.write(*obj.getStatusId());
        }
        if (obj.getExperienceModelName())
        {
            writer.writePropertyName("experienceModelName");
            writer.write(*obj.getExperienceModelName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.write(*obj.getPropertyId());
        }
        if (obj.getExperienceValue())
        {
            writer.writePropertyName("experienceValue");
            writer.write(*obj.getExperienceValue());
        }
        if (obj.getRankValue())
        {
            writer.writePropertyName("rankValue");
            writer.write(*obj.getRankValue());
        }
        if (obj.getRankCapValue())
        {
            writer.writePropertyName("rankCapValue");
            writer.write(*obj.getRankCapValue());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
    {
        writer.writeObjectStart();
        if (obj.getRegion())
        {
            writer.writePropertyName("region");
            writer.write(*obj.getRegion());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getResponseCacheId())
        {
            writer.writePropertyName("responseCacheId");
            writer.write(*obj.getResponseCacheId());
        }
        if (obj.getRequestHash())
        {
            writer.writePropertyName("requestHash");
            writer.write(*obj.getRequestHash());
        }
        if (obj.getResult())
        {
            writer.writePropertyName("result");
            writer.write(*obj.getResult());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Property& obj)
    {
        writer.writeObjectStart();
        if (obj.getExperienceModelName())
        {
            writer.writePropertyName("experienceModelName");
            writer.write(*obj.getExperienceModelName());
        }
        if (obj.getPropertyId())
        {
            writer.writePropertyName("propertyId");
            writer.write(*obj.getPropertyId());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2ExperienceClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ExperienceClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ExperienceClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }

	/**
	 * 経験値の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeExperiences(std::function<void(AsyncDescribeExperiencesResult&)> callback, DescribeExperiencesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeExperiencesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceFunctionHandler.describeExperiences");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createExperience(std::function<void(AsyncCreateExperienceResult&)> callback, CreateExperienceRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateExperienceResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceFunctionHandler.createExperience");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getExperienceCapScriptId())
        {
            writer.writePropertyName("experienceCapScriptId");
            writer.write(*request.getExperienceCapScriptId());
        }
        if (request.getChangeExperienceTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceTriggerScriptId");
            writer.write(*request.getChangeExperienceTriggerScriptId());
        }
        if (request.getChangeExperienceDoneTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerScriptId");
            writer.write(*request.getChangeExperienceDoneTriggerScriptId());
        }
        if (request.getChangeExperienceDoneTriggerQueueId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerQueueId");
            writer.write(*request.getChangeExperienceDoneTriggerQueueId());
        }
        if (request.getChangeRankTriggerScriptId())
        {
            writer.writePropertyName("changeRankTriggerScriptId");
            writer.write(*request.getChangeRankTriggerScriptId());
        }
        if (request.getChangeRankTriggerQueueId())
        {
            writer.writePropertyName("changeRankTriggerQueueId");
            writer.write(*request.getChangeRankTriggerQueueId());
        }
        if (request.getChangeRankCapTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapTriggerScriptId");
            writer.write(*request.getChangeRankCapTriggerScriptId());
        }
        if (request.getChangeRankCapDoneTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerScriptId");
            writer.write(*request.getChangeRankCapDoneTriggerScriptId());
        }
        if (request.getChangeRankCapDoneTriggerQueueId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerQueueId");
            writer.write(*request.getChangeRankCapDoneTriggerQueueId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperienceStatus(std::function<void(AsyncGetExperienceStatusResult&)> callback, GetExperienceStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetExperienceStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceFunctionHandler.getExperienceStatus");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperience(std::function<void(AsyncGetExperienceResult&)> callback, GetExperienceRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetExperienceResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceFunctionHandler.getExperience");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateExperience(std::function<void(AsyncUpdateExperienceResult&)> callback, UpdateExperienceRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateExperienceResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceFunctionHandler.updateExperience");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getExperienceCapScriptId())
        {
            writer.writePropertyName("experienceCapScriptId");
            writer.write(*request.getExperienceCapScriptId());
        }
        if (request.getChangeExperienceTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceTriggerScriptId");
            writer.write(*request.getChangeExperienceTriggerScriptId());
        }
        if (request.getChangeExperienceDoneTriggerScriptId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerScriptId");
            writer.write(*request.getChangeExperienceDoneTriggerScriptId());
        }
        if (request.getChangeExperienceDoneTriggerQueueId())
        {
            writer.writePropertyName("changeExperienceDoneTriggerQueueId");
            writer.write(*request.getChangeExperienceDoneTriggerQueueId());
        }
        if (request.getChangeRankTriggerScriptId())
        {
            writer.writePropertyName("changeRankTriggerScriptId");
            writer.write(*request.getChangeRankTriggerScriptId());
        }
        if (request.getChangeRankTriggerQueueId())
        {
            writer.writePropertyName("changeRankTriggerQueueId");
            writer.write(*request.getChangeRankTriggerQueueId());
        }
        if (request.getChangeRankCapTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapTriggerScriptId");
            writer.write(*request.getChangeRankCapTriggerScriptId());
        }
        if (request.getChangeRankCapDoneTriggerScriptId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerScriptId");
            writer.write(*request.getChangeRankCapDoneTriggerScriptId());
        }
        if (request.getChangeRankCapDoneTriggerQueueId())
        {
            writer.writePropertyName("changeRankCapDoneTriggerQueueId");
            writer.write(*request.getChangeRankCapDoneTriggerQueueId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteExperience(std::function<void(AsyncDeleteExperienceResult&)> callback, DeleteExperienceRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteExperienceResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceFunctionHandler.deleteExperience");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeExperienceModelMasters(std::function<void(AsyncDescribeExperienceModelMastersResult&)> callback, DescribeExperienceModelMastersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeExperienceModelMastersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceModelMasterFunctionHandler.describeExperienceModelMasters");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値の種類を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createExperienceModelMaster(std::function<void(AsyncCreateExperienceModelMasterResult&)> callback, CreateExperienceModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateExperienceModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceModelMasterFunctionHandler.createExperienceModelMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.write(*request.getDefaultExperience());
        }
        if (request.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.write(*request.getDefaultRankCap());
        }
        if (request.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.write(*request.getMaxRankCap());
        }
        if (request.getRankThresholdId())
        {
            writer.writePropertyName("rankThresholdId");
            writer.write(*request.getRankThresholdId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperienceModelMaster(std::function<void(AsyncGetExperienceModelMasterResult&)> callback, GetExperienceModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetExperienceModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceModelMasterFunctionHandler.getExperienceModelMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値の種類を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateExperienceModelMaster(std::function<void(AsyncUpdateExperienceModelMasterResult&)> callback, UpdateExperienceModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateExperienceModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceModelMasterFunctionHandler.updateExperienceModelMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.write(*request.getDefaultExperience());
        }
        if (request.getDefaultRankCap())
        {
            writer.writePropertyName("defaultRankCap");
            writer.write(*request.getDefaultRankCap());
        }
        if (request.getMaxRankCap())
        {
            writer.writePropertyName("maxRankCap");
            writer.write(*request.getMaxRankCap());
        }
        if (request.getRankThresholdId())
        {
            writer.writePropertyName("rankThresholdId");
            writer.write(*request.getRankThresholdId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値の種類を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteExperienceModelMaster(std::function<void(AsyncDeleteExperienceModelMasterResult&)> callback, DeleteExperienceModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteExperienceModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceModelMasterFunctionHandler.deleteExperienceModelMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値の種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeExperienceModels(std::function<void(AsyncDescribeExperienceModelsResult&)> callback, DescribeExperienceModelsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeExperienceModelsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceModelFunctionHandler.describeExperienceModels");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値の種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getExperienceModel(std::function<void(AsyncGetExperienceModelResult&)> callback, GetExperienceModelRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetExperienceModelResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FExperienceModelFunctionHandler.getExperienceModel");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ランクアップ閾値の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeThresholdMasters(std::function<void(AsyncDescribeThresholdMastersResult&)> callback, DescribeThresholdMastersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeThresholdMastersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FThresholdMasterFunctionHandler.describeThresholdMasters");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ランクアップ閾値を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createThresholdMaster(std::function<void(AsyncCreateThresholdMasterResult&)> callback, CreateThresholdMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateThresholdMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FThresholdMasterFunctionHandler.createThresholdMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *request.getValues();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ランクアップ閾値を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getThresholdMaster(std::function<void(AsyncGetThresholdMasterResult&)> callback, GetThresholdMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetThresholdMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FThresholdMasterFunctionHandler.getThresholdMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getThresholdName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getThresholdName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("thresholdName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ランクアップ閾値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateThresholdMaster(std::function<void(AsyncUpdateThresholdMasterResult&)> callback, UpdateThresholdMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateThresholdMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FThresholdMasterFunctionHandler.updateThresholdMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getThresholdName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getThresholdName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("thresholdName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getMetadata())
        {
            writer.writePropertyName("metadata");
            writer.write(*request.getMetadata());
        }
        if (request.getValues())
        {
            writer.writePropertyName("values");
            writer.writeArrayStart();
            auto& list = *request.getValues();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ランクアップ閾値を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteThresholdMaster(std::function<void(AsyncDeleteThresholdMasterResult&)> callback, DeleteThresholdMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteThresholdMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FThresholdMasterFunctionHandler.deleteThresholdMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getThresholdName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getThresholdName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("thresholdName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値マスターJSONのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ExportMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FCurrentExperienceMasterFunctionHandler.exportMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 現在有効な経験値マスターJSONを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentExperienceMaster(std::function<void(AsyncGetCurrentExperienceMasterResult&)> callback, GetCurrentExperienceMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetCurrentExperienceMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FCurrentExperienceMasterFunctionHandler.getCurrentExperienceMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 現在有効な経験値マスターJSONを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentExperienceMaster(std::function<void(AsyncUpdateCurrentExperienceMasterResult&)> callback, UpdateCurrentExperienceMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateCurrentExperienceMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FCurrentExperienceMasterFunctionHandler.updateCurrentExperienceMaster");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSettings())
        {
            writer.writePropertyName("settings");
            writer.write(*request.getSettings());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ステータスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatuses(std::function<void(AsyncDescribeStatusesResult&)> callback, DescribeStatusesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeStatusesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.describeStatuses");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ステータスの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatusesByUserId(std::function<void(AsyncDescribeStatusesByUserIdResult&)> callback, DescribeStatusesByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeStatusesByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.describeStatusesByUserId");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer);
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("limit={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatus(std::function<void(AsyncGetStatusResult&)> callback, GetStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.getStatus");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusByUserId(std::function<void(AsyncGetStatusByUserIdResult&)> callback, GetStatusByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetStatusByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.getStatusByUserId");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusWithSignature(std::function<void(AsyncGetStatusWithSignatureResult&)> callback, GetStatusWithSignatureRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetStatusWithSignatureResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.getStatusWithSignature");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getKeyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getKeyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("keyId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatuses(std::function<void(AsyncGetStatusesResult&)> callback, GetStatusesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetStatusesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.getStatuses");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getProperties())
        {
            writer.writePropertyName("properties");
            writer.writeArrayStart();
            auto& list = *request.getProperties();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ステータスを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusesByUserId(std::function<void(AsyncGetStatusesByUserIdResult&)> callback, GetStatusesByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetStatusesByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.getStatusesByUserId");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getProperties())
        {
            writer.writePropertyName("properties");
            writer.writeArrayStart();
            auto& list = *request.getProperties();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                write(writer, list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addExperienceByUserId(std::function<void(AsyncAddExperienceByUserIdResult&)> callback, AddExperienceByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<AddExperienceByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.addExperienceByUserId");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getExperienceValue())
        {
            writer.writePropertyName("experienceValue");
            writer.write(*request.getExperienceValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 累計獲得経験値を設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setExperienceByUserId(std::function<void(AsyncSetExperienceByUserIdResult&)> callback, SetExperienceByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<SetExperienceByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.setExperienceByUserId");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getExperienceValue())
        {
            writer.writePropertyName("experienceValue");
            writer.write(*request.getExperienceValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ランクキャップを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addRankCapByUserId(std::function<void(AsyncAddRankCapByUserIdResult&)> callback, AddRankCapByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<AddRankCapByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.addRankCapByUserId");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getRankCapValue())
        {
            writer.writePropertyName("rankCapValue");
            writer.write(*request.getRankCapValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ランクキャップを設定<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRankCapByUserId(std::function<void(AsyncSetRankCapByUserIdResult&)> callback, SetRankCapByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<SetRankCapByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.setRankCapByUserId");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getRankCapValue())
        {
            writer.writePropertyName("rankCapValue");
            writer.write(*request.getRankCapValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ステータスを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStatusByUserId(std::function<void(AsyncDeleteStatusByUserIdResult&)> callback, DeleteStatusByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteStatusByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.deleteStatusByUserId");
        Char encodeBuffer[2048];
        if (request.getExperienceName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getExperienceModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getExperienceModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("experienceModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getPropertyId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPropertyId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("propertyId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 経験値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addExperienceByStampSheet(std::function<void(AsyncAddExperienceByStampSheetResult&)> callback, AddExperienceByStampSheetRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<AddExperienceByStampSheetResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.addExperienceByStampSheet");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.write(*request.getStampSheet());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*request.getKeyId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ランクキャップを加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void addRankCapByStampSheet(std::function<void(AsyncAddRankCapByStampSheetResult&)> callback, AddRankCapByStampSheetRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<AddRankCapByStampSheetResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.addRankCapByStampSheet");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.write(*request.getStampSheet());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*request.getKeyId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ランクキャップを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setRankCapByStampSheet(std::function<void(AsyncSetRankCapByStampSheetResult&)> callback, SetRankCapByStampSheetRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<SetRankCapByStampSheetResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/experience-handler?handler=gs2_experience%2Fhandler%2FStatusFunctionHandler.setRankCapByStampSheet");
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getStampSheet())
        {
            writer.writePropertyName("stampSheet");
            writer.write(*request.getStampSheet());
        }
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*request.getKeyId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        headerEntries.push_back("Content-Type: application/json");
        if (request.getRequestId())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-REQUEST-ID", *request.getRequestId());
        }
        if (request.getAccessToken())
        {
            detail::HttpTask::addHeaderEntry(headerEntries, "X-GS2-ACCESS-TOKEN", *request.getAccessToken());
        }
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_EXPERIENCE_GS2EXPERIENCECLIENT_HPP_