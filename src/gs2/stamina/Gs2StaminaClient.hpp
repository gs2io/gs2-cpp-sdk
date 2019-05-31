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

#ifndef GS2_STAMINA_GS2STAMINACLIENT_HPP_
#define GS2_STAMINA_GS2STAMINACLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeGroupsRequest.hpp"
#include "request/CreateGroupRequest.hpp"
#include "request/GetGroupStatusRequest.hpp"
#include "request/GetGroupRequest.hpp"
#include "request/UpdateGroupRequest.hpp"
#include "request/DeleteGroupRequest.hpp"
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
#include "request/DescribeStaminaModelsRequest.hpp"
#include "request/GetStaminaModelRequest.hpp"
#include "request/DescribeStaminasRequest.hpp"
#include "request/DescribeStaminasByUserIdRequest.hpp"
#include "request/GetStaminaRequest.hpp"
#include "request/GetStaminaByUserIdRequest.hpp"
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
#include "result/DescribeGroupsResult.hpp"
#include "result/CreateGroupResult.hpp"
#include "result/GetGroupStatusResult.hpp"
#include "result/GetGroupResult.hpp"
#include "result/UpdateGroupResult.hpp"
#include "result/DeleteGroupResult.hpp"
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
#include "result/DescribeStaminaModelsResult.hpp"
#include "result/GetStaminaModelResult.hpp"
#include "result/DescribeStaminasResult.hpp"
#include "result/DescribeStaminasByUserIdResult.hpp"
#include "result/GetStaminaResult.hpp"
#include "result/GetStaminaByUserIdResult.hpp"
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
#include <network/HttpRequest.h>

namespace gs2 { namespace stamina {

typedef AsyncResult<DescribeGroupsResult> AsyncDescribeGroupsResult;
typedef AsyncResult<CreateGroupResult> AsyncCreateGroupResult;
typedef AsyncResult<GetGroupStatusResult> AsyncGetGroupStatusResult;
typedef AsyncResult<GetGroupResult> AsyncGetGroupResult;
typedef AsyncResult<UpdateGroupResult> AsyncUpdateGroupResult;
typedef AsyncResult<DeleteGroupResult> AsyncDeleteGroupResult;
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
typedef AsyncResult<DescribeStaminaModelsResult> AsyncDescribeStaminaModelsResult;
typedef AsyncResult<GetStaminaModelResult> AsyncGetStaminaModelResult;
typedef AsyncResult<DescribeStaminasResult> AsyncDescribeStaminasResult;
typedef AsyncResult<DescribeStaminasByUserIdResult> AsyncDescribeStaminasByUserIdResult;
typedef AsyncResult<GetStaminaResult> AsyncGetStaminaResult;
typedef AsyncResult<GetStaminaByUserIdResult> AsyncGetStaminaByUserIdResult;
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
class Gs2StaminaClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "stamina";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:
    void write(detail::json::JsonWriter& writer, const Group& obj)
    {
        writer.writeObjectStart();
        if (obj.getGroupId())
        {
            writer.writePropertyName("groupId");
            writer.writeCharArray(*obj.getGroupId());
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
        if (obj.getOverflowTriggerQueueId())
        {
            writer.writePropertyName("overflowTriggerQueueId");
            writer.writeCharArray(*obj.getOverflowTriggerQueueId());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.writeInt64(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const StaminaModelMaster& obj)
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
        if (obj.getIsCollaborateGs2Experience())
        {
            writer.writePropertyName("isCollaborateGs2Experience");
            writer.writeBool(*obj.getIsCollaborateGs2Experience());
        }
        if (obj.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*obj.getMaxStaminaTableId());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.writeInt64(*obj.getCreateAt());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.writeInt64(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const MaxStaminaTableMaster& obj)
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

    void write(detail::json::JsonWriter& writer, const CurrentStaminaMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getGroupName())
        {
            writer.writePropertyName("groupName");
            writer.writeCharArray(*obj.getGroupName());
        }
        if (obj.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*obj.getSettings());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const StaminaModel& obj)
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

    void write(detail::json::JsonWriter& writer, const MaxStaminaTable& obj)
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

    void write(detail::json::JsonWriter& writer, const Stamina& obj)
    {
        writer.writeObjectStart();
        if (obj.getStaminaId())
        {
            writer.writePropertyName("staminaId");
            writer.writeCharArray(*obj.getStaminaId());
        }
        if (obj.getStaminaModelName())
        {
            writer.writePropertyName("staminaModelName");
            writer.writeCharArray(*obj.getStaminaModelName());
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

    void write(detail::json::JsonWriter& writer, const ResponseCache& obj)
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
     * @param credential 認証情報
     */
    Gs2StaminaClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2StaminaClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2StaminaClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }

	/**
	 * スタミナの種類の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGroups(std::function<void(AsyncDescribeGroupsResult&)> callback, DescribeGroupsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeGroupsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FGroupFunctionHandler.describeGroups");
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
	 * スタミナの種類を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGroup(std::function<void(AsyncCreateGroupResult&)> callback, CreateGroupRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateGroupResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FGroupFunctionHandler.createGroup");
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
        if (request.getOverflowTriggerQueueId())
        {
            writer.writePropertyName("overflowTriggerQueueId");
            writer.writeCharArray(*request.getOverflowTriggerQueueId());
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
	 * スタミナの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGroupStatus(std::function<void(AsyncGetGroupStatusResult&)> callback, GetGroupStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetGroupStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FGroupFunctionHandler.getGroupStatus");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナの種類を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGroup(std::function<void(AsyncGetGroupResult&)> callback, GetGroupRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetGroupResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FGroupFunctionHandler.getGroup");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナの種類を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGroup(std::function<void(AsyncUpdateGroupResult&)> callback, UpdateGroupRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateGroupResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FGroupFunctionHandler.updateGroup");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
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
        if (request.getOverflowTriggerQueueId())
        {
            writer.writePropertyName("overflowTriggerQueueId");
            writer.writeCharArray(*request.getOverflowTriggerQueueId());
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
	 * スタミナの種類を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGroup(std::function<void(AsyncDeleteGroupResult&)> callback, DeleteGroupRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteGroupResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FGroupFunctionHandler.deleteGroup");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModelMasters(std::function<void(AsyncDescribeStaminaModelMastersResult&)> callback, DescribeStaminaModelMastersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeStaminaModelMastersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaModelMasterFunctionHandler.describeStaminaModelMasters");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナモデルマスターを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStaminaModelMaster(std::function<void(AsyncCreateStaminaModelMasterResult&)> callback, CreateStaminaModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateStaminaModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaModelMasterFunctionHandler.createStaminaModelMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
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
        if (request.getIsCollaborateGs2Experience())
        {
            writer.writePropertyName("isCollaborateGs2Experience");
            writer.writeBool(*request.getIsCollaborateGs2Experience());
        }
        if (request.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*request.getMaxStaminaTableId());
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
	 * スタミナモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModelMaster(std::function<void(AsyncGetStaminaModelMasterResult&)> callback, GetStaminaModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetStaminaModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaModelMasterFunctionHandler.getStaminaModelMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナモデルマスターを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaModelMaster(std::function<void(AsyncUpdateStaminaModelMasterResult&)> callback, UpdateStaminaModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateStaminaModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaModelMasterFunctionHandler.updateStaminaModelMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
        }
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
        if (request.getIsCollaborateGs2Experience())
        {
            writer.writePropertyName("isCollaborateGs2Experience");
            writer.writeBool(*request.getIsCollaborateGs2Experience());
        }
        if (request.getMaxStaminaTableId())
        {
            writer.writePropertyName("maxStaminaTableId");
            writer.writeCharArray(*request.getMaxStaminaTableId());
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
	 * スタミナモデルマスターを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaModelMaster(std::function<void(AsyncDeleteStaminaModelMasterResult&)> callback, DeleteStaminaModelMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteStaminaModelMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaModelMasterFunctionHandler.deleteStaminaModelMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナ最大値テーブルの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMaxStaminaTableMasters(std::function<void(AsyncDescribeMaxStaminaTableMastersResult&)> callback, DescribeMaxStaminaTableMastersRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeMaxStaminaTableMastersResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FMaxStaminaTableMasterFunctionHandler.describeMaxStaminaTableMasters");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナ最大値テーブルを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMaxStaminaTableMaster(std::function<void(AsyncCreateMaxStaminaTableMasterResult&)> callback, CreateMaxStaminaTableMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateMaxStaminaTableMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FMaxStaminaTableMasterFunctionHandler.createMaxStaminaTableMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
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
	 * スタミナ最大値テーブルを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMaxStaminaTableMaster(std::function<void(AsyncGetMaxStaminaTableMasterResult&)> callback, GetMaxStaminaTableMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetMaxStaminaTableMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FMaxStaminaTableMasterFunctionHandler.getMaxStaminaTableMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMaxStaminaTableName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMaxStaminaTableName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("maxStaminaTableName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナ最大値テーブルを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateMaxStaminaTableMaster(std::function<void(AsyncUpdateMaxStaminaTableMasterResult&)> callback, UpdateMaxStaminaTableMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateMaxStaminaTableMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FMaxStaminaTableMasterFunctionHandler.updateMaxStaminaTableMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMaxStaminaTableName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMaxStaminaTableName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("maxStaminaTableName={value}").replace("{value}", encodeBuffer);
        }
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
	 * スタミナ最大値テーブルを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMaxStaminaTableMaster(std::function<void(AsyncDeleteMaxStaminaTableMasterResult&)> callback, DeleteMaxStaminaTableMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DeleteMaxStaminaTableMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FMaxStaminaTableMasterFunctionHandler.deleteMaxStaminaTableMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getMaxStaminaTableName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMaxStaminaTableName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("maxStaminaTableName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナマスターJSONのマスターデータをエクスポートします<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ExportMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FCurrentStaminaMasterFunctionHandler.exportMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 現在有効なスタミナマスターJSONを取得します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentStaminaMaster(std::function<void(AsyncGetCurrentStaminaMasterResult&)> callback, GetCurrentStaminaMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetCurrentStaminaMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FCurrentStaminaMasterFunctionHandler.getCurrentStaminaMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * 現在有効なスタミナマスターJSONを更新します<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentStaminaMaster(std::function<void(AsyncUpdateCurrentStaminaMasterResult&)> callback, UpdateCurrentStaminaMasterRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateCurrentStaminaMasterResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FCurrentStaminaMasterFunctionHandler.updateCurrentStaminaMaster");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSettings())
        {
            writer.writePropertyName("settings");
            writer.writeCharArray(*request.getSettings());
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
	 * スタミナモデルマスターの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaModels(std::function<void(AsyncDescribeStaminaModelsResult&)> callback, DescribeStaminaModelsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeStaminaModelsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaModelFunctionHandler.describeStaminaModels");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナモデルマスターを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaModel(std::function<void(AsyncGetStaminaModelResult&)> callback, GetStaminaModelRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetStaminaModelResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaModelFunctionHandler.getStaminaModel");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminas(std::function<void(AsyncDescribeStaminasResult&)> callback, DescribeStaminasRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeStaminasResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.describeStaminas");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminasByUserId(std::function<void(AsyncDescribeStaminasByUserIdResult&)> callback, DescribeStaminasByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeStaminasByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.describeStaminasByUserId");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStamina(std::function<void(AsyncGetStaminaResult&)> callback, GetStaminaRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetStaminaResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.getStamina");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
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
	 * スタミナを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaByUserId(std::function<void(AsyncGetStaminaByUserIdResult&)> callback, GetStaminaByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetStaminaByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.getStaminaByUserId");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
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
	 * スタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStamina(std::function<void(AsyncConsumeStaminaResult&)> callback, ConsumeStaminaRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ConsumeStaminaResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.consumeStamina");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getConsumeValue())
        {
            writer.writePropertyName("consumeValue");
            writer.writeInt32(*request.getConsumeValue());
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
	 * スタミナを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByUserId(std::function<void(AsyncConsumeStaminaByUserIdResult&)> callback, ConsumeStaminaByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ConsumeStaminaByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.consumeStaminaByUserId");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getConsumeValue())
        {
            writer.writePropertyName("consumeValue");
            writer.writeInt32(*request.getConsumeValue());
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
	 * スタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByUserId(std::function<void(AsyncRecoverStaminaByUserIdResult&)> callback, RecoverStaminaByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<RecoverStaminaByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.recoverStaminaByUserId");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getRecoverValue())
        {
            writer.writePropertyName("recoverValue");
            writer.writeInt32(*request.getRecoverValue());
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
	 * スタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByUserId(std::function<void(AsyncRaiseMaxValueByUserIdResult&)> callback, RaiseMaxValueByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<RaiseMaxValueByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.raiseMaxValueByUserId");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getRaiseValue())
        {
            writer.writePropertyName("raiseValue");
            writer.writeInt32(*request.getRaiseValue());
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
	 * スタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByUserId(std::function<void(AsyncSetMaxValueByUserIdResult&)> callback, SetMaxValueByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<SetMaxValueByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.setMaxValueByUserId");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getMaxValue())
        {
            writer.writePropertyName("maxValue");
            writer.writeInt32(*request.getMaxValue());
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
	 * スタミナの最大値をGS2-Experienceのステータスを使用して更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStatus(std::function<void(AsyncSetMaxValueByStatusResult&)> callback, SetMaxValueByStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<SetMaxValueByStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.setMaxValueByStatus");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
        }
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
	 * スタミナを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaByUserId(std::function<void(AsyncDeleteStaminaByUserIdResult&)> callback, DeleteStaminaByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.deleteStaminaByUserId");
        Char encodeBuffer[2048];
        if (request.getGroupName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGroupName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("groupName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getStaminaModelName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStaminaModelName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("staminaModelName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
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
	 * スタンプシートを使用してスタミナを回復<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void recoverStaminaByStampSheet(std::function<void(AsyncRecoverStaminaByStampSheetResult&)> callback, RecoverStaminaByStampSheetRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<RecoverStaminaByStampSheetResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.recoverStaminaByStampSheet");
        Char encodeBuffer[2048];
        if (request.getStampSheet()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStampSheet()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("stampSheet={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
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
	 * スタンプシートでスタミナの最大値を加算<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void raiseMaxValueByStampSheet(std::function<void(AsyncRaiseMaxValueByStampSheetResult&)> callback, RaiseMaxValueByStampSheetRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<RaiseMaxValueByStampSheetResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.raiseMaxValueByStampSheet");
        Char encodeBuffer[2048];
        if (request.getStampSheet()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStampSheet()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("stampSheet={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
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
	 * スタンプシートでスタミナの最大値を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setMaxValueByStampSheet(std::function<void(AsyncSetMaxValueByStampSheetResult&)> callback, SetMaxValueByStampSheetRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<SetMaxValueByStampSheetResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.setMaxValueByStampSheet");
        Char encodeBuffer[2048];
        if (request.getStampSheet()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStampSheet()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("stampSheet={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.writeCharArray(*request.getKeyId());
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
	 * スタンプタスクを使用してスタミナを消費<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByStampTask(std::function<void(AsyncConsumeStaminaByStampTaskResult&)> callback, ConsumeStaminaByStampTaskRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<ConsumeStaminaByStampTaskResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/stamina-handler?handler=gs2_stamina%2Fhandler%2FStaminaFunctionHandler.consumeStaminaByStampTask");
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

#endif //GS2_STAMINA_GS2STAMINACLIENT_HPP_