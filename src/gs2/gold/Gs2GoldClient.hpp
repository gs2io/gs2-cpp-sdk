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

#ifndef GS2_GOLD_GS2GOLDCLIENT_HPP_
#define GS2_GOLD_GS2GOLDCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace gold {

typedef AsyncResult<GetCurrentGoldMasterResult> AsyncGetCurrentGoldMasterResult;
typedef AsyncResult<UpdateCurrentGoldMasterResult> AsyncUpdateCurrentGoldMasterResult;
typedef AsyncResult<CreateGoldMasterResult> AsyncCreateGoldMasterResult;
typedef AsyncResult<void> AsyncDeleteGoldMasterResult;
typedef AsyncResult<DescribeGoldMasterResult> AsyncDescribeGoldMasterResult;
typedef AsyncResult<GetGoldMasterResult> AsyncGetGoldMasterResult;
typedef AsyncResult<UpdateGoldMasterResult> AsyncUpdateGoldMasterResult;
typedef AsyncResult<CreateGoldPoolResult> AsyncCreateGoldPoolResult;
typedef AsyncResult<void> AsyncDeleteGoldPoolResult;
typedef AsyncResult<DescribeGoldPoolResult> AsyncDescribeGoldPoolResult;
typedef AsyncResult<DescribeServiceClassResult> AsyncDescribeServiceClassResult;
typedef AsyncResult<GetGoldPoolResult> AsyncGetGoldPoolResult;
typedef AsyncResult<GetGoldPoolStatusResult> AsyncGetGoldPoolStatusResult;
typedef AsyncResult<UpdateGoldPoolResult> AsyncUpdateGoldPoolResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<GetWalletSettingsResult> AsyncGetWalletSettingsResult;
typedef AsyncResult<void> AsyncDeleteWalletByUserIdResult;
typedef AsyncResult<DepositIntoWalletResult> AsyncDepositIntoWalletResult;
typedef AsyncResult<DepositIntoWalletByStampSheetResult> AsyncDepositIntoWalletByStampSheetResult;
typedef AsyncResult<DepositIntoWalletByUserIdResult> AsyncDepositIntoWalletByUserIdResult;
typedef AsyncResult<DescribeWalletResult> AsyncDescribeWalletResult;
typedef AsyncResult<DescribeWalletByUserIdResult> AsyncDescribeWalletByUserIdResult;
typedef AsyncResult<GetWalletResult> AsyncGetWalletResult;
typedef AsyncResult<GetWalletByUserIdResult> AsyncGetWalletByUserIdResult;
typedef AsyncResult<SetLatestGainResult> AsyncSetLatestGainResult;
typedef AsyncResult<WithdrawFromWalletResult> AsyncWithdrawFromWalletResult;
typedef AsyncResult<WithdrawFromWalletByStampTaskResult> AsyncWithdrawFromWalletByStampTaskResult;
typedef AsyncResult<WithdrawFromWalletByUserIdResult> AsyncWithdrawFromWalletByUserIdResult;

class Gs2GoldClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "gold";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const GoldPool& obj)
    {
        writer.writeObjectStart();
        if (obj.getGoldPoolId())
        {
            writer.writePropertyName("goldPoolId");
            writer.write(*obj.getGoldPoolId());
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
        if (obj.getCreateWalletTriggerScript())
        {
            writer.writePropertyName("createWalletTriggerScript");
            writer.write(*obj.getCreateWalletTriggerScript());
        }
        if (obj.getCreateWalletDoneTriggerScript())
        {
            writer.writePropertyName("createWalletDoneTriggerScript");
            writer.write(*obj.getCreateWalletDoneTriggerScript());
        }
        if (obj.getDepositIntoWalletTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletTriggerScript");
            writer.write(*obj.getDepositIntoWalletTriggerScript());
        }
        if (obj.getDepositIntoWalletDoneTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletDoneTriggerScript");
            writer.write(*obj.getDepositIntoWalletDoneTriggerScript());
        }
        if (obj.getWithdrawFromWalletTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletTriggerScript");
            writer.write(*obj.getWithdrawFromWalletTriggerScript());
        }
        if (obj.getWithdrawFromWalletDoneTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletDoneTriggerScript");
            writer.write(*obj.getWithdrawFromWalletDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const GoldMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getGoldId())
        {
            writer.writePropertyName("goldId");
            writer.write(*obj.getGoldId());
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
        if (obj.getBalanceMax())
        {
            writer.writePropertyName("balanceMax");
            writer.write(*obj.getBalanceMax());
        }
        if (obj.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.write(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.write(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.write(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.write(*obj.getResetHour());
        }
        if (obj.getLatestGainMax())
        {
            writer.writePropertyName("latestGainMax");
            writer.write(*obj.getLatestGainMax());
        }
        if (obj.getCreateWalletTriggerScript())
        {
            writer.writePropertyName("createWalletTriggerScript");
            writer.write(*obj.getCreateWalletTriggerScript());
        }
        if (obj.getCreateWalletDoneTriggerScript())
        {
            writer.writePropertyName("createWalletDoneTriggerScript");
            writer.write(*obj.getCreateWalletDoneTriggerScript());
        }
        if (obj.getDepositIntoWalletTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletTriggerScript");
            writer.write(*obj.getDepositIntoWalletTriggerScript());
        }
        if (obj.getDepositIntoWalletDoneTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletDoneTriggerScript");
            writer.write(*obj.getDepositIntoWalletDoneTriggerScript());
        }
        if (obj.getWithdrawFromWalletTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletTriggerScript");
            writer.write(*obj.getWithdrawFromWalletTriggerScript());
        }
        if (obj.getWithdrawFromWalletDoneTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletDoneTriggerScript");
            writer.write(*obj.getWithdrawFromWalletDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const Wallet& obj)
    {
        writer.writeObjectStart();
        if (obj.getWalletId())
        {
            writer.writePropertyName("walletId");
            writer.write(*obj.getWalletId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getGoldName())
        {
            writer.writePropertyName("goldName");
            writer.write(*obj.getGoldName());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getBalance())
        {
            writer.writePropertyName("balance");
            writer.write(*obj.getBalance());
        }
        if (obj.getLatestGain())
        {
            writer.writePropertyName("latestGain");
            writer.write(*obj.getLatestGain());
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

    void write(detail::json::JsonWriter& writer, const WalletSettings& obj)
    {
        writer.writeObjectStart();
        if (obj.getGoldName())
        {
            writer.writePropertyName("goldName");
            writer.write(*obj.getGoldName());
        }
        if (obj.getBalanceMax())
        {
            writer.writePropertyName("balanceMax");
            writer.write(*obj.getBalanceMax());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.write(*obj.getResetType());
        }
        if (obj.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.write(*obj.getResetDayOfMonth());
        }
        if (obj.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.write(*obj.getResetDayOfWeek());
        }
        if (obj.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.write(*obj.getResetHour());
        }
        if (obj.getLatestGainMax())
        {
            writer.writePropertyName("latestGainMax");
            writer.write(*obj.getLatestGainMax());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2GoldClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2GoldClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2GoldClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * 公開されているゴールドマスタを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentGoldMaster(std::function<void(AsyncGetCurrentGoldMasterResult&)> callback, GetCurrentGoldMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCurrentGoldMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 公開するゴールドマスタを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentGoldMaster(std::function<void(AsyncUpdateCurrentGoldMasterResult&)> callback, UpdateCurrentGoldMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCurrentGoldMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/master");
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
     * ゴールドマスターを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGoldMaster(std::function<void(AsyncCreateGoldMasterResult&)> callback, CreateGoldMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateGoldMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/master/gold");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getBalanceMax())
        {
            writer.writePropertyName("balanceMax");
            writer.write(*request.getBalanceMax());
        }
        if (request.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.write(*request.getResetType());
        }
        if (request.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.write(*request.getResetDayOfMonth());
        }
        if (request.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.write(*request.getResetDayOfWeek());
        }
        if (request.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.write(*request.getResetHour());
        }
        if (request.getLatestGainMax())
        {
            writer.writePropertyName("latestGainMax");
            writer.write(*request.getLatestGainMax());
        }
        if (request.getCreateWalletTriggerScript())
        {
            writer.writePropertyName("createWalletTriggerScript");
            writer.write(*request.getCreateWalletTriggerScript());
        }
        if (request.getCreateWalletDoneTriggerScript())
        {
            writer.writePropertyName("createWalletDoneTriggerScript");
            writer.write(*request.getCreateWalletDoneTriggerScript());
        }
        if (request.getDepositIntoWalletTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletTriggerScript");
            writer.write(*request.getDepositIntoWalletTriggerScript());
        }
        if (request.getDepositIntoWalletDoneTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletDoneTriggerScript");
            writer.write(*request.getDepositIntoWalletDoneTriggerScript());
        }
        if (request.getWithdrawFromWalletTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletTriggerScript");
            writer.write(*request.getWithdrawFromWalletTriggerScript());
        }
        if (request.getWithdrawFromWalletDoneTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletDoneTriggerScript");
            writer.write(*request.getWithdrawFromWalletDoneTriggerScript());
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
     * ゴールドマスターを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGoldMaster(std::function<void(AsyncDeleteGoldMasterResult&)> callback, DeleteGoldMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/master/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゴールドマスターの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGoldMaster(std::function<void(AsyncDescribeGoldMasterResult&)> callback, DescribeGoldMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeGoldMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/master/gold");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
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
     * ゴールドマスターを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGoldMaster(std::function<void(AsyncGetGoldMasterResult&)> callback, GetGoldMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGoldMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/master/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゴールドマスターを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGoldMaster(std::function<void(AsyncUpdateGoldMasterResult&)> callback, UpdateGoldMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateGoldMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/master/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getBalanceMax())
        {
            writer.writePropertyName("balanceMax");
            writer.write(*request.getBalanceMax());
        }
        if (request.getResetType())
        {
            writer.writePropertyName("resetType");
            writer.write(*request.getResetType());
        }
        if (request.getResetDayOfMonth())
        {
            writer.writePropertyName("resetDayOfMonth");
            writer.write(*request.getResetDayOfMonth());
        }
        if (request.getResetDayOfWeek())
        {
            writer.writePropertyName("resetDayOfWeek");
            writer.write(*request.getResetDayOfWeek());
        }
        if (request.getResetHour())
        {
            writer.writePropertyName("resetHour");
            writer.write(*request.getResetHour());
        }
        if (request.getLatestGainMax())
        {
            writer.writePropertyName("latestGainMax");
            writer.write(*request.getLatestGainMax());
        }
        if (request.getCreateWalletTriggerScript())
        {
            writer.writePropertyName("createWalletTriggerScript");
            writer.write(*request.getCreateWalletTriggerScript());
        }
        if (request.getCreateWalletDoneTriggerScript())
        {
            writer.writePropertyName("createWalletDoneTriggerScript");
            writer.write(*request.getCreateWalletDoneTriggerScript());
        }
        if (request.getDepositIntoWalletTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletTriggerScript");
            writer.write(*request.getDepositIntoWalletTriggerScript());
        }
        if (request.getDepositIntoWalletDoneTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletDoneTriggerScript");
            writer.write(*request.getDepositIntoWalletDoneTriggerScript());
        }
        if (request.getWithdrawFromWalletTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletTriggerScript");
            writer.write(*request.getWithdrawFromWalletTriggerScript());
        }
        if (request.getWithdrawFromWalletDoneTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletDoneTriggerScript");
            writer.write(*request.getWithdrawFromWalletDoneTriggerScript());
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
     * ゴールドプールを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGoldPool(std::function<void(AsyncCreateGoldPoolResult&)> callback, CreateGoldPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateGoldPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool");
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
        if (request.getCreateWalletTriggerScript())
        {
            writer.writePropertyName("createWalletTriggerScript");
            writer.write(*request.getCreateWalletTriggerScript());
        }
        if (request.getCreateWalletDoneTriggerScript())
        {
            writer.writePropertyName("createWalletDoneTriggerScript");
            writer.write(*request.getCreateWalletDoneTriggerScript());
        }
        if (request.getDepositIntoWalletTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletTriggerScript");
            writer.write(*request.getDepositIntoWalletTriggerScript());
        }
        if (request.getDepositIntoWalletDoneTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletDoneTriggerScript");
            writer.write(*request.getDepositIntoWalletDoneTriggerScript());
        }
        if (request.getWithdrawFromWalletTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletTriggerScript");
            writer.write(*request.getWithdrawFromWalletTriggerScript());
        }
        if (request.getWithdrawFromWalletDoneTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletDoneTriggerScript");
            writer.write(*request.getWithdrawFromWalletDoneTriggerScript());
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
     * ゴールドプールを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGoldPool(std::function<void(AsyncDeleteGoldPoolResult&)> callback, DeleteGoldPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゴールドプールの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGoldPool(std::function<void(AsyncDescribeGoldPoolResult&)> callback, DescribeGoldPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeGoldPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
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
     * サービスクラスの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeServiceClass(std::function<void(AsyncDescribeServiceClassResult&)> callback, DescribeServiceClassRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeServiceClassResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/serviceClass");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゴールドプールを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGoldPool(std::function<void(AsyncGetGoldPoolResult&)> callback, GetGoldPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGoldPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゴールドプールの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGoldPoolStatus(std::function<void(AsyncGetGoldPoolStatusResult&)> callback, GetGoldPoolStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGoldPoolStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゴールドプールを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGoldPool(std::function<void(AsyncUpdateGoldPoolResult&)> callback, UpdateGoldPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateGoldPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("");
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
        if (request.getCreateWalletTriggerScript())
        {
            writer.writePropertyName("createWalletTriggerScript");
            writer.write(*request.getCreateWalletTriggerScript());
        }
        if (request.getCreateWalletDoneTriggerScript())
        {
            writer.writePropertyName("createWalletDoneTriggerScript");
            writer.write(*request.getCreateWalletDoneTriggerScript());
        }
        if (request.getDepositIntoWalletTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletTriggerScript");
            writer.write(*request.getDepositIntoWalletTriggerScript());
        }
        if (request.getDepositIntoWalletDoneTriggerScript())
        {
            writer.writePropertyName("depositIntoWalletDoneTriggerScript");
            writer.write(*request.getDepositIntoWalletDoneTriggerScript());
        }
        if (request.getWithdrawFromWalletTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletTriggerScript");
            writer.write(*request.getWithdrawFromWalletTriggerScript());
        }
        if (request.getWithdrawFromWalletDoneTriggerScript())
        {
            writer.writePropertyName("withdrawFromWalletDoneTriggerScript");
            writer.write(*request.getWithdrawFromWalletDoneTriggerScript());
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
     * ゴールドマスターデータをエクスポートする<br>
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
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ウォレットの設定を取得します<br>
     * <br>
     * - 消費クオータ: 2<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWalletSettings(std::function<void(AsyncGetWalletSettingsResult&)> callback, GetWalletSettingsRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetWalletSettingsResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("/wallet/settings");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ウォレットを削除します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteWalletByUserId(std::function<void(AsyncDeleteWalletByUserIdResult&)> callback, DeleteWalletByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("/wallet/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ウォレットの残高を加算します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositIntoWallet(std::function<void(AsyncDepositIntoWalletResult&)> callback, DepositIntoWalletRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DepositIntoWalletResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("/wallet/user/self/action/deposit");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*request.getValue());
        }
        if (request.getContext())
        {
            writer.writePropertyName("context");
            writer.write(*request.getContext());
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
     * スタンプタスクを使用してウォレットの残高を加算します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositIntoWalletByStampSheet(std::function<void(AsyncDepositIntoWalletByStampSheetResult&)> callback, DepositIntoWalletByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DepositIntoWalletByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/wallet/action/deposit");
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
     * ウォレットの残高を加算します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void depositIntoWalletByUserId(std::function<void(AsyncDepositIntoWalletByUserIdResult&)> callback, DepositIntoWalletByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DepositIntoWalletByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("/wallet/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/action/deposit");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*request.getValue());
        }
        if (request.getContext())
        {
            writer.writePropertyName("context");
            writer.write(*request.getContext());
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
     * ウォレットの一覧を取得します<br>
     * <br>
     * - 消費クオータ: 30件あたり10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWallet(std::function<void(AsyncDescribeWalletResult&)> callback, DescribeWalletRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeWalletResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
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
     * ウォレットの一覧を取得します<br>
     * <br>
     * - 消費クオータ: 30件あたり10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeWalletByUserId(std::function<void(AsyncDescribeWalletByUserIdResult&)> callback, DescribeWalletByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeWalletByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
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
     * ウォレットを取得します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWallet(std::function<void(AsyncGetWalletResult&)> callback, GetWalletRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetWalletResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("/wallet/user/self");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ウォレットを取得します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWalletByUserId(std::function<void(AsyncGetWalletByUserIdResult&)> callback, GetWalletByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetWalletByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("/wallet/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ウォレットの残高を加算します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setLatestGain(std::function<void(AsyncSetLatestGainResult&)> callback, SetLatestGainRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SetLatestGainResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("/wallet/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/action/set");
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
     * ウォレットの残高を減算します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawFromWallet(std::function<void(AsyncWithdrawFromWalletResult&)> callback, WithdrawFromWalletRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<WithdrawFromWalletResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("/wallet/user/self/action/withdraw");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*request.getValue());
        }
        if (request.getContext())
        {
            writer.writePropertyName("context");
            writer.write(*request.getContext());
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
     * スタンプタスクを使用してウォレットの減算を加算します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawFromWalletByStampTask(std::function<void(AsyncWithdrawFromWalletByStampTaskResult&)> callback, WithdrawFromWalletByStampTaskRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<WithdrawFromWalletByStampTaskResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/wallet/action/withdraw");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getTask())
        {
            writer.writePropertyName("task");
            writer.write(*request.getTask());
        }
        if (request.getKeyName())
        {
            writer.writePropertyName("keyName");
            writer.write(*request.getKeyName());
        }
        if (request.getTransactionId())
        {
            writer.writePropertyName("transactionId");
            writer.write(*request.getTransactionId());
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
     * ウォレットの残高を減算します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void withdrawFromWalletByUserId(std::function<void(AsyncWithdrawFromWalletByUserIdResult&)> callback, WithdrawFromWalletByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<WithdrawFromWalletByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/goldPool/").append(detail::StringUtil::toStr(buffer, request.getGoldPoolName())).append("/gold/").append(detail::StringUtil::toStr(buffer, request.getGoldName())).append("/wallet/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/action/withdraw");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*request.getValue());
        }
        if (request.getContext())
        {
            writer.writePropertyName("context");
            writer.write(*request.getContext());
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

#endif //GS2_GOLD_GS2GOLDCLIENT_HPP_