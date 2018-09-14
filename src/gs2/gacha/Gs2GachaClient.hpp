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

#ifndef GS2_GACHA_GS2GACHACLIENT_HPP_
#define GS2_GACHA_GS2GACHACLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace gacha {

typedef AsyncResult<GetCurrentGachaMasterResult> AsyncGetCurrentGachaMasterResult;
typedef AsyncResult<UpdateCurrentGachaMasterResult> AsyncUpdateCurrentGachaMasterResult;
typedef AsyncResult<CreateGachaMasterResult> AsyncCreateGachaMasterResult;
typedef AsyncResult<void> AsyncDeleteGachaMasterResult;
typedef AsyncResult<DescribeGachaMasterResult> AsyncDescribeGachaMasterResult;
typedef AsyncResult<GetGachaMasterResult> AsyncGetGachaMasterResult;
typedef AsyncResult<UpdateGachaMasterResult> AsyncUpdateGachaMasterResult;
typedef AsyncResult<CreateGachaPoolResult> AsyncCreateGachaPoolResult;
typedef AsyncResult<void> AsyncDeleteGachaPoolResult;
typedef AsyncResult<DescribeGachaPoolResult> AsyncDescribeGachaPoolResult;
typedef AsyncResult<GetGachaPoolResult> AsyncGetGachaPoolResult;
typedef AsyncResult<GetGachaPoolStatusResult> AsyncGetGachaPoolStatusResult;
typedef AsyncResult<UpdateGachaPoolResult> AsyncUpdateGachaPoolResult;
typedef AsyncResult<DescribeGachaResult> AsyncDescribeGachaResult;
typedef AsyncResult<DetailProbabilityResult> AsyncDetailProbabilityResult;
typedef AsyncResult<DoGachaResult> AsyncDoGachaResult;
typedef AsyncResult<DoGachaByStampSheetResult> AsyncDoGachaByStampSheetResult;
typedef AsyncResult<GetGachaResult> AsyncGetGachaResult;
typedef AsyncResult<GetProbabilityResult> AsyncGetProbabilityResult;
typedef AsyncResult<ExportMasterResult> AsyncExportMasterResult;
typedef AsyncResult<CreatePrizeMasterResult> AsyncCreatePrizeMasterResult;
typedef AsyncResult<void> AsyncDeletePrizeMasterResult;
typedef AsyncResult<DescribePrizeMasterResult> AsyncDescribePrizeMasterResult;
typedef AsyncResult<GetPrizeMasterResult> AsyncGetPrizeMasterResult;
typedef AsyncResult<UpdatePrizeMasterResult> AsyncUpdatePrizeMasterResult;
typedef AsyncResult<CreatePrizeTableMasterResult> AsyncCreatePrizeTableMasterResult;
typedef AsyncResult<void> AsyncDeletePrizeTableMasterResult;
typedef AsyncResult<DescribePrizeTableMasterResult> AsyncDescribePrizeTableMasterResult;
typedef AsyncResult<GetPrizeTableMasterResult> AsyncGetPrizeTableMasterResult;
typedef AsyncResult<CreateRarityMasterResult> AsyncCreateRarityMasterResult;
typedef AsyncResult<void> AsyncDeleteRarityMasterResult;
typedef AsyncResult<DescribeRarityMasterResult> AsyncDescribeRarityMasterResult;
typedef AsyncResult<GetRarityMasterResult> AsyncGetRarityMasterResult;
typedef AsyncResult<UpdateRarityMasterResult> AsyncUpdateRarityMasterResult;

class Gs2GachaClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "gacha";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const GachaPool& obj)
    {
        writer.writeObjectStart();
        if (obj.getGachaPoolId())
        {
            writer.writePropertyName("gachaPoolId");
            writer.write(*obj.getGachaPoolId());
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
        if (obj.getPublicDrawRate())
        {
            writer.writePropertyName("publicDrawRate");
            writer.write(*obj.getPublicDrawRate());
        }
        if (obj.getAllowAccessGachaInfo())
        {
            writer.writePropertyName("allowAccessGachaInfo");
            writer.write(*obj.getAllowAccessGachaInfo());
        }
        if (obj.getRestrict())
        {
            writer.writePropertyName("restrict");
            writer.write(*obj.getRestrict());
        }
        if (obj.getDrawPrizeTriggerScript())
        {
            writer.writePropertyName("drawPrizeTriggerScript");
            writer.write(*obj.getDrawPrizeTriggerScript());
        }
        if (obj.getDrawPrizeDoneTriggerScript())
        {
            writer.writePropertyName("drawPrizeDoneTriggerScript");
            writer.write(*obj.getDrawPrizeDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const GachaMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getGachaId())
        {
            writer.writePropertyName("gachaId");
            writer.write(*obj.getGachaId());
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
        if (obj.getPrizeTableNames())
        {
            writer.writePropertyName("prizeTableNames");
            writer.writeArrayStart();
            auto& list = *obj.getPrizeTableNames();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getPrizeJobQueueName())
        {
            writer.writePropertyName("prizeJobQueueName");
            writer.write(*obj.getPrizeJobQueueName());
        }
        if (obj.getPrizeJobQueueScriptName())
        {
            writer.writePropertyName("prizeJobQueueScriptName");
            writer.write(*obj.getPrizeJobQueueScriptName());
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

    void write(detail::json::JsonWriter& writer, const PrizeTableMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getPrizeTableId())
        {
            writer.writePropertyName("prizeTableId");
            writer.write(*obj.getPrizeTableId());
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

    void write(detail::json::JsonWriter& writer, const RarityMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getRarityId())
        {
            writer.writePropertyName("rarityId");
            writer.write(*obj.getRarityId());
        }
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getWeight())
        {
            writer.writePropertyName("weight");
            writer.write(*obj.getWeight());
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

    void write(detail::json::JsonWriter& writer, const PrizeMaster& obj)
    {
        writer.writeObjectStart();
        if (obj.getPrizeId())
        {
            writer.writePropertyName("prizeId");
            writer.write(*obj.getPrizeId());
        }
        if (obj.getResourceId())
        {
            writer.writePropertyName("resourceId");
            writer.write(*obj.getResourceId());
        }
        if (obj.getWeight())
        {
            writer.writePropertyName("weight");
            writer.write(*obj.getWeight());
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

    void write(detail::json::JsonWriter& writer, const Gacha& obj)
    {
        writer.writeObjectStart();
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
        if (obj.getDrawCount())
        {
            writer.writePropertyName("drawCount");
            writer.write(*obj.getDrawCount());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Prize& obj)
    {
        writer.writeObjectStart();
        if (obj.getGachaPoolName())
        {
            writer.writePropertyName("gachaPoolName");
            writer.write(*obj.getGachaPoolName());
        }
        if (obj.getGachaName())
        {
            writer.writePropertyName("gachaName");
            writer.write(*obj.getGachaName());
        }
        if (obj.getResourceIds())
        {
            writer.writePropertyName("resourceIds");
            writer.writeArrayStart();
            auto& list = *obj.getResourceIds();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Probability& obj)
    {
        writer.writeObjectStart();
        if (obj.getName())
        {
            writer.writePropertyName("name");
            writer.write(*obj.getName());
        }
        if (obj.getRate())
        {
            writer.writePropertyName("rate");
            writer.write(*obj.getRate());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const ProbabilityDetail& obj)
    {
        writer.writeObjectStart();
        if (obj.getRarityName())
        {
            writer.writePropertyName("rarityName");
            writer.write(*obj.getRarityName());
        }
        if (obj.getResourceId())
        {
            writer.writePropertyName("resourceId");
            writer.write(*obj.getResourceId());
        }
        if (obj.getRate())
        {
            writer.writePropertyName("rate");
            writer.write(*obj.getRate());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2GachaClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2GachaClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2GachaClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * 公開されているガチャマスタを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getCurrentGachaMaster(std::function<void(AsyncGetCurrentGachaMasterResult&)> callback, GetCurrentGachaMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetCurrentGachaMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/gacha/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 公開するガチャマスタを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateCurrentGachaMaster(std::function<void(AsyncUpdateCurrentGachaMasterResult&)> callback, UpdateCurrentGachaMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateCurrentGachaMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/gacha/master");
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
     * ガチャを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGachaMaster(std::function<void(AsyncCreateGachaMasterResult&)> callback, CreateGachaMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateGachaMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/gacha");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getPrizeTableNames())
        {
            writer.writePropertyName("prizeTableNames");
            writer.writeArrayStart();
            auto& list = *request.getPrizeTableNames();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getPrizeJobQueueName())
        {
            writer.writePropertyName("prizeJobQueueName");
            writer.write(*request.getPrizeJobQueueName());
        }
        if (request.getPrizeJobQueueScriptName())
        {
            writer.writePropertyName("prizeJobQueueScriptName");
            writer.write(*request.getPrizeJobQueueScriptName());
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
     * ガチャを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGachaMaster(std::function<void(AsyncDeleteGachaMasterResult&)> callback, DeleteGachaMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/gacha/").append(detail::StringUtil::toStr(buffer, request.getGachaName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ガチャの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGachaMaster(std::function<void(AsyncDescribeGachaMasterResult&)> callback, DescribeGachaMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeGachaMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/gacha");
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
     * ガチャを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGachaMaster(std::function<void(AsyncGetGachaMasterResult&)> callback, GetGachaMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGachaMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/gacha/").append(detail::StringUtil::toStr(buffer, request.getGachaName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ガチャを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGachaMaster(std::function<void(AsyncUpdateGachaMasterResult&)> callback, UpdateGachaMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateGachaMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/gacha/").append(detail::StringUtil::toStr(buffer, request.getGachaName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getPrizeTableNames())
        {
            writer.writePropertyName("prizeTableNames");
            writer.writeArrayStart();
            auto& list = *request.getPrizeTableNames();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
        }
        if (request.getPrizeJobQueueName())
        {
            writer.writePropertyName("prizeJobQueueName");
            writer.write(*request.getPrizeJobQueueName());
        }
        if (request.getPrizeJobQueueScriptName())
        {
            writer.writePropertyName("prizeJobQueueScriptName");
            writer.write(*request.getPrizeJobQueueScriptName());
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
     * ガチャプールを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGachaPool(std::function<void(AsyncCreateGachaPoolResult&)> callback, CreateGachaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateGachaPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool");
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
        if (request.getPublicDrawRate())
        {
            writer.writePropertyName("publicDrawRate");
            writer.write(*request.getPublicDrawRate());
        }
        if (request.getAllowAccessGachaInfo())
        {
            writer.writePropertyName("allowAccessGachaInfo");
            writer.write(*request.getAllowAccessGachaInfo());
        }
        if (request.getRestrict())
        {
            writer.writePropertyName("restrict");
            writer.write(*request.getRestrict());
        }
        if (request.getDrawPrizeTriggerScript())
        {
            writer.writePropertyName("drawPrizeTriggerScript");
            writer.write(*request.getDrawPrizeTriggerScript());
        }
        if (request.getDrawPrizeDoneTriggerScript())
        {
            writer.writePropertyName("drawPrizeDoneTriggerScript");
            writer.write(*request.getDrawPrizeDoneTriggerScript());
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
     * ガチャプールを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGachaPool(std::function<void(AsyncDeleteGachaPoolResult&)> callback, DeleteGachaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ガチャプールの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGachaPool(std::function<void(AsyncDescribeGachaPoolResult&)> callback, DescribeGachaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeGachaPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool");
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
     * ガチャプールを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGachaPool(std::function<void(AsyncGetGachaPoolResult&)> callback, GetGachaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGachaPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ガチャプールの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGachaPoolStatus(std::function<void(AsyncGetGachaPoolStatusResult&)> callback, GetGachaPoolStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGachaPoolStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ガチャプールを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGachaPool(std::function<void(AsyncUpdateGachaPoolResult&)> callback, UpdateGachaPoolRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateGachaPoolResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getPublicDrawRate())
        {
            writer.writePropertyName("publicDrawRate");
            writer.write(*request.getPublicDrawRate());
        }
        if (request.getAllowAccessGachaInfo())
        {
            writer.writePropertyName("allowAccessGachaInfo");
            writer.write(*request.getAllowAccessGachaInfo());
        }
        if (request.getRestrict())
        {
            writer.writePropertyName("restrict");
            writer.write(*request.getRestrict());
        }
        if (request.getDrawPrizeTriggerScript())
        {
            writer.writePropertyName("drawPrizeTriggerScript");
            writer.write(*request.getDrawPrizeTriggerScript());
        }
        if (request.getDrawPrizeDoneTriggerScript())
        {
            writer.writePropertyName("drawPrizeDoneTriggerScript");
            writer.write(*request.getDrawPrizeDoneTriggerScript());
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
     * 公開されているガチャ一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGacha(std::function<void(AsyncDescribeGachaResult&)> callback, DescribeGachaRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeGachaResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/gacha");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * リソース毎のガチャの排出確率を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void detailProbability(std::function<void(AsyncDetailProbabilityResult&)> callback, DetailProbabilityRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DetailProbabilityResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/gacha/").append(detail::StringUtil::toStr(buffer, request.getGachaName())).append("/probability/").append(detail::StringUtil::toStr(buffer, request.getDrawTime())).append("/detail");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ガチャを実行します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doGacha(std::function<void(AsyncDoGachaResult&)> callback, DoGachaRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DoGachaResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/gacha/").append(detail::StringUtil::toStr(buffer, request.getGachaName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
     * スタンプシートを使用してガチャを実行します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doGachaByStampSheet(std::function<void(AsyncDoGachaByStampSheetResult&)> callback, DoGachaByStampSheetRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DoGachaByStampSheetResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gacha");
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
     * 公開されているガチャを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGacha(std::function<void(AsyncGetGachaResult&)> callback, GetGachaRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGachaResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/gacha/").append(detail::StringUtil::toStr(buffer, request.getGachaName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * レアリティ毎のガチャの排出確率を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getProbability(std::function<void(AsyncGetProbabilityResult&)> callback, GetProbabilityRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetProbabilityResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/gacha/").append(detail::StringUtil::toStr(buffer, request.getGachaName())).append("/probability/").append(detail::StringUtil::toStr(buffer, request.getDrawTime())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ガチャマスターデータをエクスポートする<br>
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
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 景品を新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createPrizeMaster(std::function<void(AsyncCreatePrizeMasterResult&)> callback, CreatePrizeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreatePrizeMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity/").append(detail::StringUtil::toStr(buffer, request.getRarityName())).append("/prize");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getResourceId())
        {
            writer.writePropertyName("resourceId");
            writer.write(*request.getResourceId());
        }
        if (request.getWeight())
        {
            writer.writePropertyName("weight");
            writer.write(*request.getWeight());
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
     * 景品を削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deletePrizeMaster(std::function<void(AsyncDeletePrizeMasterResult&)> callback, DeletePrizeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity/").append(detail::StringUtil::toStr(buffer, request.getRarityName())).append("/prize/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 景品の一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeMaster(std::function<void(AsyncDescribePrizeMasterResult&)> callback, DescribePrizeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribePrizeMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity/").append(detail::StringUtil::toStr(buffer, request.getRarityName())).append("/prize");
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
     * 景品を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeMaster(std::function<void(AsyncGetPrizeMasterResult&)> callback, GetPrizeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetPrizeMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity/").append(detail::StringUtil::toStr(buffer, request.getRarityName())).append("/prize/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 景品を更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updatePrizeMaster(std::function<void(AsyncUpdatePrizeMasterResult&)> callback, UpdatePrizeMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdatePrizeMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity/").append(detail::StringUtil::toStr(buffer, request.getRarityName())).append("/prize/").append(detail::StringUtil::toStr(buffer, request.getResourceId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getWeight())
        {
            writer.writePropertyName("weight");
            writer.write(*request.getWeight());
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
     * 排出確率テーブルを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createPrizeTableMaster(std::function<void(AsyncCreatePrizeTableMasterResult&)> callback, CreatePrizeTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreatePrizeTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable");
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
     * 排出確率テーブルを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deletePrizeTableMaster(std::function<void(AsyncDeletePrizeTableMasterResult&)> callback, DeletePrizeTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 排出確率テーブルの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describePrizeTableMaster(std::function<void(AsyncDescribePrizeTableMasterResult&)> callback, DescribePrizeTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribePrizeTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable");
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
     * 排出確率テーブルを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getPrizeTableMaster(std::function<void(AsyncGetPrizeTableMasterResult&)> callback, GetPrizeTableMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetPrizeTableMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 景品レアリティを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRarityMaster(std::function<void(AsyncCreateRarityMasterResult&)> callback, CreateRarityMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateRarityMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getName())
        {
            writer.writePropertyName("name");
            writer.write(*request.getName());
        }
        if (request.getWeight())
        {
            writer.writePropertyName("weight");
            writer.write(*request.getWeight());
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
     * 景品レアリティを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRarityMaster(std::function<void(AsyncDeleteRarityMasterResult&)> callback, DeleteRarityMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity/").append(detail::StringUtil::toStr(buffer, request.getRarityName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 景品レアリティの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRarityMaster(std::function<void(AsyncDescribeRarityMasterResult&)> callback, DescribeRarityMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeRarityMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity");
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
     * 景品レアリティを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRarityMaster(std::function<void(AsyncGetRarityMasterResult&)> callback, GetRarityMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetRarityMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity/").append(detail::StringUtil::toStr(buffer, request.getRarityName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 景品レアリティを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRarityMaster(std::function<void(AsyncUpdateRarityMasterResult&)> callback, UpdateRarityMasterRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateRarityMasterResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/gachaPool/").append(detail::StringUtil::toStr(buffer, request.getGachaPoolName())).append("/master/prizeTable/").append(detail::StringUtil::toStr(buffer, request.getPrizeTableName())).append("/rarity/").append(detail::StringUtil::toStr(buffer, request.getRarityName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getWeight())
        {
            writer.writePropertyName("weight");
            writer.write(*request.getWeight());
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

#endif //GS2_GACHA_GS2GACHACLIENT_HPP_