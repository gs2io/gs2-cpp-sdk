/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_LEVEL_GS2LEVELCLIENT_HPP_
#define GS2_LEVEL_GS2LEVELCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace level {

typedef AsyncResult<GetCurrentLevelMasterResult> AsyncGetCurrentLevelMasterResult;
typedef AsyncResult<UpdateCurrentLevelMasterResult> AsyncUpdateCurrentLevelMasterResult;
typedef AsyncResult<CreateLevelTableMasterResult> AsyncCreateLevelTableMasterResult;
typedef AsyncResult<void> AsyncDeleteLevelTableMasterResult;
typedef AsyncResult<DescribeLevelTableMasterResult> AsyncDescribeLevelTableMasterResult;
typedef AsyncResult<GetLevelTableMasterResult> AsyncGetLevelTableMasterResult;
typedef AsyncResult<CreateLevelThresholdMasterResult> AsyncCreateLevelThresholdMasterResult;
typedef AsyncResult<void> AsyncDeleteLevelThresholdMasterResult;
typedef AsyncResult<DescribeLevelThresholdMasterResult> AsyncDescribeLevelThresholdMasterResult;
typedef AsyncResult<GetLevelThresholdMasterResult> AsyncGetLevelThresholdMasterResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<CreateResourcePoolResult> AsyncCreateResourcePoolResult;
typedef AsyncResult<void> AsyncDeleteResourcePoolResult;
typedef AsyncResult<DescribeResourcePoolResult> AsyncDescribeResourcePoolResult;
typedef AsyncResult<GetResourcePoolResult> AsyncGetResourcePoolResult;
typedef AsyncResult<GetResourcePoolStatusResult> AsyncGetResourcePoolStatusResult;
typedef AsyncResult<UpdateResourcePoolResult> AsyncUpdateResourcePoolResult;
typedef AsyncResult<CreateResourceTypeMasterResult> AsyncCreateResourceTypeMasterResult;
typedef AsyncResult<void> AsyncDeleteResourceTypeMasterResult;
typedef AsyncResult<DescribeResourceTypeMasterResult> AsyncDescribeResourceTypeMasterResult;
typedef AsyncResult<GetResourceTypeMasterResult> AsyncGetResourceTypeMasterResult;
typedef AsyncResult<UpdateResourceTypeMasterResult> AsyncUpdateResourceTypeMasterResult;
typedef AsyncResult<ChangeLevelCapByStampSheetResult> AsyncChangeLevelCapByStampSheetResult;
typedef AsyncResult<ChangeLevelCapByUserIdResult> AsyncChangeLevelCapByUserIdResult;
typedef AsyncResult<ChangeLevelCapByUserIdAndResourceTypeResult> AsyncChangeLevelCapByUserIdAndResourceTypeResult;
typedef AsyncResult<DescribeStatusResult> AsyncDescribeStatusResult;
typedef AsyncResult<DescribeStatusByUserIdResult> AsyncDescribeStatusByUserIdResult;
typedef AsyncResult<GetStatusResult> AsyncGetStatusResult;
typedef AsyncResult<GetStatusByResourceTypeResult> AsyncGetStatusByResourceTypeResult;
typedef AsyncResult<GetStatusByUserIdResult> AsyncGetStatusByUserIdResult;
typedef AsyncResult<GetStatusByUserIdAndResourceTypeResult> AsyncGetStatusByUserIdAndResourceTypeResult;
typedef AsyncResult<IncreaseExperienceByStampSheetResult> AsyncIncreaseExperienceByStampSheetResult;
typedef AsyncResult<IncreaseExperienceByUserIdResult> AsyncIncreaseExperienceByUserIdResult;
typedef AsyncResult<IncreaseExperienceByUserIdAndResourceTypeResult> AsyncIncreaseExperienceByUserIdAndResourceTypeResult;
typedef AsyncResult<SetExperienceByUserIdResult> AsyncSetExperienceByUserIdResult;
typedef AsyncResult<SetExperienceByUserIdAndResourceTypeResult> AsyncSetExperienceByUserIdAndResourceTypeResult;

class Gs2LevelClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "level";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const ResourcePool& obj)
    {
        writer.writeObjectStart();
        if (obj.getResourcePoolId())
        {
            writer.writePropertyName("resourcePoolId");
            writer.write(*obj.getResourcePoolId());
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
        if (obj.getServiceClass())
        {
            writer.writePropertyName("serviceClass");
            writer.write(*obj.getServiceClass());
        }
        if (obj.getLevelCapScript())
        {
            writer.writePropertyName("levelCapScript");
            writer.write(*obj.getLevelCapScript());
        }
        if (obj.getChangeExperienceTriggerScript())
        {
            writer.writePropertyName("changeExperienceTriggerScript");
            writer.write(*obj.getChangeExperienceTriggerScript());
        }
        if (obj.getChangeExperienceDoneTriggerScript())
        {
            writer.writePropertyName("changeExperienceDoneTriggerScript");
            writer.write(*obj.getChangeExperienceDoneTriggerScript());
        }
        if (obj.getChangeLevelTriggerScript())
        {
            writer.writePropertyName("changeLevelTriggerScript");
            writer.write(*obj.getChangeLevelTriggerScript());
        }
        if (obj.getChangeLevelDoneTriggerScript())
        {
            writer.writePropertyName("changeLevelDoneTriggerScript");
            writer.write(*obj.getChangeLevelDoneTriggerScript());
        }
        if (obj.getChangeLevelCapTriggerScript())
        {
            writer.writePropertyName("changeLevelCapTriggerScript");
            writer.write(*obj.getChangeLevelCapTriggerScript());
        }
        if (obj.getChangeLevelCapDoneTriggerScript())
        {
            writer.writePropertyName("changeLevelCapDoneTriggerScript");
            writer.write(*obj.getChangeLevelCapDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const ResourceTypeMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getResourceTypeId())
        {
            writer.writePropertyName("resourceTypeId");
            writer.write(*obj.getResourceTypeId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getLevelTableName())
        {
            writer.writePropertyName("levelTableName");
            writer.write(*obj.getLevelTableName());
        }
        if (obj.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.write(*obj.getDefaultExperience());
        }
        if (obj.getDefaultLevelCap())
        {
            writer.writePropertyName("defaultLevelCap");
            writer.write(*obj.getDefaultLevelCap());
        }
        if (obj.getMaxLevelCap())
        {
            writer.writePropertyName("maxLevelCap");
            writer.write(*obj.getMaxLevelCap());
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

    void write(detail::json::JsonWriter& writer, const LevelTableMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getLevelTableId())
        {
            writer.writePropertyName("levelTableId");
            writer.write(*obj.getLevelTableId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
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

    void write(detail::json::JsonWriter& writer, const LevelThresholdMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getThresholdId())
        {
            writer.writePropertyName("thresholdId");
            writer.write(*obj.getThresholdId());
        }
        if (obj.getThreshold())
        {
            writer.writePropertyName("threshold");
            writer.write(*obj.getThreshold());
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

    void write(detail::json::JsonWriter& writer, const Status& obj)
    {
        writer.writeObjectStart();
        if (obj.getStatusId())
        {
            writer.writePropertyName("statusId");
            writer.write(*obj.getStatusId());
        }
        if (obj.getResourceTypeName())
        {
            writer.writePropertyName("resourceTypeName");
            writer.write(*obj.getResourceTypeName());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getResourceId())
        {
            writer.writePropertyName("resourceId");
            writer.write(*obj.getResourceId());
        }
        if (obj.getLevel())
        {
            writer.writePropertyName("level");
            writer.write(*obj.getLevel());
        }
        if (obj.getLevelCap())
        {
            writer.writePropertyName("levelCap");
            writer.write(*obj.getLevelCap());
        }
        if (obj.getExperience())
        {
            writer.writePropertyName("experience");
            writer.write(*obj.getExperience());
        }
        if (obj.getNextLevelExperience())
        {
            writer.writePropertyName("nextLevelExperience");
            writer.write(*obj.getNextLevelExperience());
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



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2LevelClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2LevelClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2LevelClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * レベルマスタを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentLevelMaster(std::function<void(AsyncGetCurrentLevelMasterResult&)> callback, GetCurrentLevelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCurrentLevelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/status/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルマスタを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentLevelMaster(std::function<void(AsyncUpdateCurrentLevelMasterResult&)> callback, UpdateCurrentLevelMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCurrentLevelMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/status/master");
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
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルテーブルを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLevelTableMaster(std::function<void(AsyncCreateLevelTableMasterResult&)> callback, CreateLevelTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateLevelTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/levelTable");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルテーブルを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLevelTableMaster(std::function<void(AsyncDeleteLevelTableMasterResult&)> callback, DeleteLevelTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/levelTable/").append(detail::StringUtil::toStr(buffer, request.getLevelTableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルテーブルの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLevelTableMaster(std::function<void(AsyncDescribeLevelTableMasterResult&)> callback, DescribeLevelTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeLevelTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/levelTable");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルテーブルを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLevelTableMaster(std::function<void(AsyncGetLevelTableMasterResult&)> callback, GetLevelTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLevelTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/levelTable/").append(detail::StringUtil::toStr(buffer, request.getLevelTableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルアップ経験値閾値を新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLevelThresholdMaster(std::function<void(AsyncCreateLevelThresholdMasterResult&)> callback, CreateLevelThresholdMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateLevelThresholdMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/levelTable/").append(detail::StringUtil::toStr(buffer, request.getLevelTableName())).append("/threshold");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getThreshold())
        {
            writer.writePropertyName("threshold");
            writer.write(*request.getThreshold());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルアップ経験値閾値を削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLevelThresholdMaster(std::function<void(AsyncDeleteLevelThresholdMasterResult&)> callback, DeleteLevelThresholdMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/levelTable/").append(detail::StringUtil::toStr(buffer, request.getLevelTableName())).append("/threshold/").append(detail::StringUtil::toStr(buffer, request.getThreshold())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルアップ経験値閾値の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLevelThresholdMaster(std::function<void(AsyncDescribeLevelThresholdMasterResult&)> callback, DescribeLevelThresholdMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeLevelThresholdMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/levelTable/").append(detail::StringUtil::toStr(buffer, request.getLevelTableName())).append("/threshold");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルアップ経験値閾値を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLevelThresholdMaster(std::function<void(AsyncGetLevelThresholdMasterResult&)> callback, GetLevelThresholdMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLevelThresholdMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/levelTable/").append(detail::StringUtil::toStr(buffer, request.getLevelTableName())).append("/threshold/").append(detail::StringUtil::toStr(buffer, request.getThreshold())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルマスターデータをエクスポートする<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void exportMaster(std::function<void(AsyncExportMasterResult&)> callback, ExportMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ExportMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースプールを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createResourcePool(std::function<void(AsyncCreateResourcePoolResult&)> callback, CreateResourcePoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateResourcePoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getServiceClass())
        {
            writer.writePropertyName("serviceClass");
            writer.write(*request.getServiceClass());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getLevelCapScript())
        {
            writer.writePropertyName("levelCapScript");
            writer.write(*request.getLevelCapScript());
        }
        if (request.getChangeExperienceTriggerScript())
        {
            writer.writePropertyName("changeExperienceTriggerScript");
            writer.write(*request.getChangeExperienceTriggerScript());
        }
        if (request.getChangeExperienceDoneTriggerScript())
        {
            writer.writePropertyName("changeExperienceDoneTriggerScript");
            writer.write(*request.getChangeExperienceDoneTriggerScript());
        }
        if (request.getChangeLevelTriggerScript())
        {
            writer.writePropertyName("changeLevelTriggerScript");
            writer.write(*request.getChangeLevelTriggerScript());
        }
        if (request.getChangeLevelDoneTriggerScript())
        {
            writer.writePropertyName("changeLevelDoneTriggerScript");
            writer.write(*request.getChangeLevelDoneTriggerScript());
        }
        if (request.getChangeLevelCapTriggerScript())
        {
            writer.writePropertyName("changeLevelCapTriggerScript");
            writer.write(*request.getChangeLevelCapTriggerScript());
        }
        if (request.getChangeLevelCapDoneTriggerScript())
        {
            writer.writePropertyName("changeLevelCapDoneTriggerScript");
            writer.write(*request.getChangeLevelCapDoneTriggerScript());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースプールを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteResourcePool(std::function<void(AsyncDeleteResourcePoolResult&)> callback, DeleteResourcePoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースプールの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeResourcePool(std::function<void(AsyncDescribeResourcePoolResult&)> callback, DescribeResourcePoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeResourcePoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースプールを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getResourcePool(std::function<void(AsyncGetResourcePoolResult&)> callback, GetResourcePoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetResourcePoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースプールの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getResourcePoolStatus(std::function<void(AsyncGetResourcePoolStatusResult&)> callback, GetResourcePoolStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetResourcePoolStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースプールを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateResourcePool(std::function<void(AsyncUpdateResourcePoolResult&)> callback, UpdateResourcePoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateResourcePoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getServiceClass())
        {
            writer.writePropertyName("serviceClass");
            writer.write(*request.getServiceClass());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getLevelCapScript())
        {
            writer.writePropertyName("levelCapScript");
            writer.write(*request.getLevelCapScript());
        }
        if (request.getChangeExperienceTriggerScript())
        {
            writer.writePropertyName("changeExperienceTriggerScript");
            writer.write(*request.getChangeExperienceTriggerScript());
        }
        if (request.getChangeExperienceDoneTriggerScript())
        {
            writer.writePropertyName("changeExperienceDoneTriggerScript");
            writer.write(*request.getChangeExperienceDoneTriggerScript());
        }
        if (request.getChangeLevelTriggerScript())
        {
            writer.writePropertyName("changeLevelTriggerScript");
            writer.write(*request.getChangeLevelTriggerScript());
        }
        if (request.getChangeLevelDoneTriggerScript())
        {
            writer.writePropertyName("changeLevelDoneTriggerScript");
            writer.write(*request.getChangeLevelDoneTriggerScript());
        }
        if (request.getChangeLevelCapTriggerScript())
        {
            writer.writePropertyName("changeLevelCapTriggerScript");
            writer.write(*request.getChangeLevelCapTriggerScript());
        }
        if (request.getChangeLevelCapDoneTriggerScript())
        {
            writer.writePropertyName("changeLevelCapDoneTriggerScript");
            writer.write(*request.getChangeLevelCapDoneTriggerScript());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースタイプを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createResourceTypeMaster(std::function<void(AsyncCreateResourceTypeMasterResult&)> callback, CreateResourceTypeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateResourceTypeMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/resourceType");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getLevelTableName())
        {
            writer.writePropertyName("levelTableName");
            writer.write(*request.getLevelTableName());
        }
        if (request.getDefaultLevelCap())
        {
            writer.writePropertyName("defaultLevelCap");
            writer.write(*request.getDefaultLevelCap());
        }
        if (request.getMaxLevelCap())
        {
            writer.writePropertyName("maxLevelCap");
            writer.write(*request.getMaxLevelCap());
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.write(*request.getDefaultExperience());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースタイプを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteResourceTypeMaster(std::function<void(AsyncDeleteResourceTypeMasterResult&)> callback, DeleteResourceTypeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/resourceType/").append(detail::StringUtil::toStr(buffer, request.getResourceTypeName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースタイプの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeResourceTypeMaster(std::function<void(AsyncDescribeResourceTypeMasterResult&)> callback, DescribeResourceTypeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeResourceTypeMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/resourceType");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースタイプを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getResourceTypeMaster(std::function<void(AsyncGetResourceTypeMasterResult&)> callback, GetResourceTypeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetResourceTypeMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/resourceType/").append(detail::StringUtil::toStr(buffer, request.getResourceTypeName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソースタイプを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateResourceTypeMaster(std::function<void(AsyncUpdateResourceTypeMasterResult&)> callback, UpdateResourceTypeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateResourceTypeMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/master/resourceType/").append(detail::StringUtil::toStr(buffer, request.getResourceTypeName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getLevelTableName())
        {
            writer.writePropertyName("levelTableName");
            writer.write(*request.getLevelTableName());
        }
        if (request.getDefaultLevelCap())
        {
            writer.writePropertyName("defaultLevelCap");
            writer.write(*request.getDefaultLevelCap());
        }
        if (request.getMaxLevelCap())
        {
            writer.writePropertyName("maxLevelCap");
            writer.write(*request.getMaxLevelCap());
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getDefaultExperience())
        {
            writer.writePropertyName("defaultExperience");
            writer.write(*request.getDefaultExperience());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スタンプシートを使用してレベルキャップを変更します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void changeLevelCapByStampSheet(std::function<void(AsyncChangeLevelCapByStampSheetResult&)> callback, ChangeLevelCapByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ChangeLevelCapByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/status/levelCap");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSheet())
        {
            writer.writePropertyName("sheet");
            writer.write(*request.getSheet());
        }
        if (request.getKeyName())
        {
            writer.writePropertyName("keyName");
            writer.write(*request.getKeyName());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルキャップを変更します<br>
     * <br>
     * 消費クォーター: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void changeLevelCapByUserId(std::function<void(AsyncChangeLevelCapByUserIdResult&)> callback, ChangeLevelCapByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ChangeLevelCapByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/status/").append(detail::StringUtil::toStr(buffer, request.getStatusId())).append("/levelCap");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getLevelCap())
        {
            writer.writePropertyName("levelCap");
            writer.write(*request.getLevelCap());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レベルキャップを変更します<br>
     * <br>
     * 消費クォーター: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void changeLevelCapByUserIdAndResourceType(std::function<void(AsyncChangeLevelCapByUserIdAndResourceTypeResult&)> callback, ChangeLevelCapByUserIdAndResourceTypeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ChangeLevelCapByUserIdAndResourceTypeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/status/resourceType/").append(detail::StringUtil::toStr(buffer, request.getResourceTypeName())).append("/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("/levelCap");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getLevelCap())
        {
            writer.writePropertyName("levelCap");
            writer.write(*request.getLevelCap());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ステータス一覧を取得します<br>
     * <br>
     * 本APIは statusIds に取得するリソースIDのリストを指定出来ます。<br>
     * リソースIDリストを指定しない場合は全てのリソースのステータスを応答しますが、IDを指定する場合と比較して2倍のクォーターを消費します。<br>
     * ステータスを取得する段階でリソースIDが明らかな場合はリソースIDのリストを指定することをお勧めします。<br>
     * <br>
     * 消費クォーター: 取得件数 × 3(リソースIDを省略した場合は2倍)<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatus(std::function<void(AsyncDescribeStatusResult&)> callback, DescribeStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/my/status");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getStatusIds()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStatusIds()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("statusIds={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ステータスを一覧を取得します<br>
     * <br>
     * 本APIは statusIds に取得するリソースIDのリストを指定出来ます。<br>
     * リソースIDリストを指定しない場合は全てのリソースのステータスを応答しますが、IDを指定する場合と比較して2倍のクォーターを消費します。<br>
     * ステータスを取得する段階でリソースIDが明らかな場合はリソースIDのリストを指定することをお勧めします。<br>
     * <br>
     * 消費クォーター: 取得件数 × 3(リソースIDを省略した場合は2倍)<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStatusByUserId(std::function<void(AsyncDescribeStatusByUserIdResult&)> callback, DescribeStatusByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeStatusByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/status");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[2048];
        if (request.getStatusIds()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStatusIds()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("statusIds={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ステータスを取得します<br>
     * <br>
     * 消費クォーター: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatus(std::function<void(AsyncGetStatusResult&)> callback, GetStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/my/status/").append(detail::StringUtil::toStr(buffer, request.getStatusId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ステータスを取得します<br>
     * <br>
     * 消費クォーター: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusByResourceType(std::function<void(AsyncGetStatusByResourceTypeResult&)> callback, GetStatusByResourceTypeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetStatusByResourceTypeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/my/status/resourceType/").append(detail::StringUtil::toStr(buffer, request.getResourceTypeName())).append("/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ステータスを取得します<br>
     * <br>
     * 消費クォーター: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusByUserId(std::function<void(AsyncGetStatusByUserIdResult&)> callback, GetStatusByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetStatusByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/status/").append(detail::StringUtil::toStr(buffer, request.getStatusId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ステータスを取得します<br>
     * <br>
     * 消費クォーター: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStatusByUserIdAndResourceType(std::function<void(AsyncGetStatusByUserIdAndResourceTypeResult&)> callback, GetStatusByUserIdAndResourceTypeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetStatusByUserIdAndResourceTypeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/status/resourceType/").append(detail::StringUtil::toStr(buffer, request.getResourceTypeName())).append("/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スタンプシートを使用して経験値を加算します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void increaseExperienceByStampSheet(std::function<void(AsyncIncreaseExperienceByStampSheetResult&)> callback, IncreaseExperienceByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<IncreaseExperienceByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/status");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSheet())
        {
            writer.writePropertyName("sheet");
            writer.write(*request.getSheet());
        }
        if (request.getKeyName())
        {
            writer.writePropertyName("keyName");
            writer.write(*request.getKeyName());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 経験値を加算します<br>
     * <br>
     * 消費クォーター: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void increaseExperienceByUserId(std::function<void(AsyncIncreaseExperienceByUserIdResult&)> callback, IncreaseExperienceByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<IncreaseExperienceByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/status/").append(detail::StringUtil::toStr(buffer, request.getStatusId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*request.getValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 経験値を加算します<br>
     * <br>
     * 消費クォーター: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void increaseExperienceByUserIdAndResourceType(std::function<void(AsyncIncreaseExperienceByUserIdAndResourceTypeResult&)> callback, IncreaseExperienceByUserIdAndResourceTypeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<IncreaseExperienceByUserIdAndResourceTypeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/status/resourceType/").append(detail::StringUtil::toStr(buffer, request.getResourceTypeName())).append("/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*request.getValue());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 経験値を設定します<br>
     * <br>
     * 消費クォーター: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setExperienceByUserId(std::function<void(AsyncSetExperienceByUserIdResult&)> callback, SetExperienceByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SetExperienceByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/status/").append(detail::StringUtil::toStr(buffer, request.getStatusId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getExperience())
        {
            writer.writePropertyName("experience");
            writer.write(*request.getExperience());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 経験値を設定します<br>
     * <br>
     * 消費クォーター: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setExperienceByUserIdAndResourceType(std::function<void(AsyncSetExperienceByUserIdAndResourceTypeResult&)> callback, SetExperienceByUserIdAndResourceTypeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SetExperienceByUserIdAndResourceTypeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/resourcePool/").append(detail::StringUtil::toStr(buffer, request.getResourcePoolName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/status/resourceType/").append(detail::StringUtil::toStr(buffer, request.getResourceTypeName())).append("/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getExperience())
        {
            writer.writePropertyName("experience");
            writer.write(*request.getExperience());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        httpRequest.setRequestData(body, bodySize);
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_LEVEL_GS2LEVELCLIENT_HPP_