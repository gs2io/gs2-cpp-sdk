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

#ifndef GS2_STAMINA_GS2STAMINACLIENT_HPP_
#define GS2_STAMINA_GS2STAMINACLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace stamina {

typedef AsyncResult<CreateStaminaPoolResult> AsyncCreateStaminaPoolResult;
typedef AsyncResult<void> AsyncDeleteStaminaPoolResult;
typedef AsyncResult<DescribeServiceClassResult> AsyncDescribeServiceClassResult;
typedef AsyncResult<DescribeStaminaPoolResult> AsyncDescribeStaminaPoolResult;
typedef AsyncResult<GetStaminaPoolResult> AsyncGetStaminaPoolResult;
typedef AsyncResult<GetStaminaPoolStatusResult> AsyncGetStaminaPoolStatusResult;
typedef AsyncResult<UpdateStaminaPoolResult> AsyncUpdateStaminaPoolResult;
typedef AsyncResult<ChangeStaminaResult> AsyncChangeStaminaResult;
typedef AsyncResult<ChangeStaminaByStampSheetResult> AsyncChangeStaminaByStampSheetResult;
typedef AsyncResult<ConsumeStaminaResult> AsyncConsumeStaminaResult;
typedef AsyncResult<ConsumeStaminaByStampTaskResult> AsyncConsumeStaminaByStampTaskResult;
typedef AsyncResult<GetStaminaResult> AsyncGetStaminaResult;

class Gs2StaminaClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "stamina";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const StaminaPool& obj)
    {
        writer.writeObjectStart();
        if (obj.getStaminaPoolId())
        {
            writer.writePropertyName("staminaPoolId");
            writer.write(*obj.getStaminaPoolId());
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
        if (obj.getIncreaseInterval())
        {
            writer.writePropertyName("increaseInterval");
            writer.write(*obj.getIncreaseInterval());
        }
        if (obj.getConsumeStaminaTriggerScript())
        {
            writer.writePropertyName("consumeStaminaTriggerScript");
            writer.write(*obj.getConsumeStaminaTriggerScript());
        }
        if (obj.getConsumeStaminaDoneTriggerScript())
        {
            writer.writePropertyName("consumeStaminaDoneTriggerScript");
            writer.write(*obj.getConsumeStaminaDoneTriggerScript());
        }
        if (obj.getAddStaminaTriggerScript())
        {
            writer.writePropertyName("addStaminaTriggerScript");
            writer.write(*obj.getAddStaminaTriggerScript());
        }
        if (obj.getAddStaminaDoneTriggerScript())
        {
            writer.writePropertyName("addStaminaDoneTriggerScript");
            writer.write(*obj.getAddStaminaDoneTriggerScript());
        }
        if (obj.getGetMaxStaminaTriggerScript())
        {
            writer.writePropertyName("getMaxStaminaTriggerScript");
            writer.write(*obj.getGetMaxStaminaTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const Stamina& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getValue())
        {
            writer.writePropertyName("value");
            writer.write(*obj.getValue());
        }
        if (obj.getOverflow())
        {
            writer.writePropertyName("overflow");
            writer.write(*obj.getOverflow());
        }
        if (obj.getLastUpdateAt())
        {
            writer.writePropertyName("lastUpdateAt");
            writer.write(*obj.getLastUpdateAt());
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
     * スタミナプールを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createStaminaPool(std::function<void(AsyncCreateStaminaPoolResult&)> callback, CreateStaminaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateStaminaPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/staminaPool");
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
        if (request.getIncreaseInterval())
        {
            writer.writePropertyName("increaseInterval");
            writer.write(*request.getIncreaseInterval());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getConsumeStaminaTriggerScript())
        {
            writer.writePropertyName("consumeStaminaTriggerScript");
            writer.write(*request.getConsumeStaminaTriggerScript());
        }
        if (request.getConsumeStaminaDoneTriggerScript())
        {
            writer.writePropertyName("consumeStaminaDoneTriggerScript");
            writer.write(*request.getConsumeStaminaDoneTriggerScript());
        }
        if (request.getAddStaminaTriggerScript())
        {
            writer.writePropertyName("addStaminaTriggerScript");
            writer.write(*request.getAddStaminaTriggerScript());
        }
        if (request.getAddStaminaDoneTriggerScript())
        {
            writer.writePropertyName("addStaminaDoneTriggerScript");
            writer.write(*request.getAddStaminaDoneTriggerScript());
        }
        if (request.getGetMaxStaminaTriggerScript())
        {
            writer.writePropertyName("getMaxStaminaTriggerScript");
            writer.write(*request.getGetMaxStaminaTriggerScript());
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
     * スタミナプールを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteStaminaPool(std::function<void(AsyncDeleteStaminaPoolResult&)> callback, DeleteStaminaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/staminaPool/").append(detail::StringUtil::toStr(buffer, request.getStaminaPoolName())).append("");
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
            url.append("/staminaPool/serviceClass");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スタミナプールの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeStaminaPool(std::function<void(AsyncDescribeStaminaPoolResult&)> callback, DescribeStaminaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeStaminaPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/staminaPool");
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
     * スタミナプールを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaPool(std::function<void(AsyncGetStaminaPoolResult&)> callback, GetStaminaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetStaminaPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/staminaPool/").append(detail::StringUtil::toStr(buffer, request.getStaminaPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スタミナプールの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStaminaPoolStatus(std::function<void(AsyncGetStaminaPoolStatusResult&)> callback, GetStaminaPoolStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetStaminaPoolStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/staminaPool/").append(detail::StringUtil::toStr(buffer, request.getStaminaPoolName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * スタミナプールを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateStaminaPool(std::function<void(AsyncUpdateStaminaPoolResult&)> callback, UpdateStaminaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateStaminaPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/staminaPool/").append(detail::StringUtil::toStr(buffer, request.getStaminaPoolName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getServiceClass())
        {
            writer.writePropertyName("serviceClass");
            writer.write(*request.getServiceClass());
        }
        if (request.getIncreaseInterval())
        {
            writer.writePropertyName("increaseInterval");
            writer.write(*request.getIncreaseInterval());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getConsumeStaminaTriggerScript())
        {
            writer.writePropertyName("consumeStaminaTriggerScript");
            writer.write(*request.getConsumeStaminaTriggerScript());
        }
        if (request.getConsumeStaminaDoneTriggerScript())
        {
            writer.writePropertyName("consumeStaminaDoneTriggerScript");
            writer.write(*request.getConsumeStaminaDoneTriggerScript());
        }
        if (request.getAddStaminaTriggerScript())
        {
            writer.writePropertyName("addStaminaTriggerScript");
            writer.write(*request.getAddStaminaTriggerScript());
        }
        if (request.getAddStaminaDoneTriggerScript())
        {
            writer.writePropertyName("addStaminaDoneTriggerScript");
            writer.write(*request.getAddStaminaDoneTriggerScript());
        }
        if (request.getGetMaxStaminaTriggerScript())
        {
            writer.writePropertyName("getMaxStaminaTriggerScript");
            writer.write(*request.getGetMaxStaminaTriggerScript());
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
     * スタミナを増減します<br>
     * <br>
     * - 消費クオータ: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void changeStamina(std::function<void(AsyncChangeStaminaResult&)> callback, ChangeStaminaRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ChangeStaminaResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/staminaPool/").append(detail::StringUtil::toStr(buffer, request.getStaminaPoolName())).append("/stamina");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getVariation())
        {
            writer.writePropertyName("variation");
            writer.write(*request.getVariation());
        }
        if (request.getMaxValue())
        {
            writer.writePropertyName("maxValue");
            writer.write(*request.getMaxValue());
        }
        if (request.getOverflow())
        {
            writer.writePropertyName("overflow");
            writer.write(*request.getOverflow());
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
     * スタンプシートを使用してスタミナを増減します<br>
     * <br>
     * - 消費クオータ: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void changeStaminaByStampSheet(std::function<void(AsyncChangeStaminaByStampSheetResult&)> callback, ChangeStaminaByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ChangeStaminaByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/stamina");
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
        if (request.getMaxValue())
        {
            writer.writePropertyName("maxValue");
            writer.write(*request.getMaxValue());
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
     * スタミナを消費します。<br>
     * このエンドポイントは回復に使用できません。<br>
     * ポリシーで消費と回復を分けて管理したい場合に使用してください。<br>
     * <br>
     * - 消費クオータ: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStamina(std::function<void(AsyncConsumeStaminaResult&)> callback, ConsumeStaminaRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeStaminaResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/staminaPool/").append(detail::StringUtil::toStr(buffer, request.getStaminaPoolName())).append("/stamina/consume");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getVariation())
        {
            writer.writePropertyName("variation");
            writer.write(*request.getVariation());
        }
        if (request.getMaxValue())
        {
            writer.writePropertyName("maxValue");
            writer.write(*request.getMaxValue());
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
     * スタンプタスクを使用してスタミナを消費します。<br>
     * <br>
     * - 消費クオータ: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void consumeStaminaByStampTask(std::function<void(AsyncConsumeStaminaByStampTaskResult&)> callback, ConsumeStaminaByStampTaskRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<ConsumeStaminaByStampTaskResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/stamina/consume");
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
        if (request.getMaxValue())
        {
            writer.writePropertyName("maxValue");
            writer.write(*request.getMaxValue());
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
     * 現在のスタミナ値を取得します<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getStamina(std::function<void(AsyncGetStaminaResult&)> callback, GetStaminaRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetStaminaResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/staminaPool/").append(detail::StringUtil::toStr(buffer, request.getStaminaPoolName())).append("/stamina");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getMaxValue()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMaxValue()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("maxValue={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (queryString.endsWith("&")) {
            url += "?" + queryString.substr(0, queryString.size() - 1);
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_STAMINA_GS2STAMINACLIENT_HPP_