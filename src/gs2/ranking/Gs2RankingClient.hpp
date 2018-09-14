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

#ifndef GS2_RANKING_GS2RANKINGCLIENT_HPP_
#define GS2_RANKING_GS2RANKINGCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace ranking {

typedef AsyncResult<CreateGameModeResult> AsyncCreateGameModeResult;
typedef AsyncResult<void> AsyncDeleteGameModeResult;
typedef AsyncResult<DescribeGameModeResult> AsyncDescribeGameModeResult;
typedef AsyncResult<GetGameModeResult> AsyncGetGameModeResult;
typedef AsyncResult<UpdateGameModeResult> AsyncUpdateGameModeResult;
typedef AsyncResult<CreateRankingTableResult> AsyncCreateRankingTableResult;
typedef AsyncResult<void> AsyncDeleteRankingTableResult;
typedef AsyncResult<DescribeRankingTableResult> AsyncDescribeRankingTableResult;
typedef AsyncResult<GetRankingTableResult> AsyncGetRankingTableResult;
typedef AsyncResult<UpdateRankingTableResult> AsyncUpdateRankingTableResult;
typedef AsyncResult<GetEstimateRankResult> AsyncGetEstimateRankResult;
typedef AsyncResult<GetMyRankResult> AsyncGetMyRankResult;
typedef AsyncResult<GetRankingResult> AsyncGetRankingResult;
typedef AsyncResult<PutScoreResult> AsyncPutScoreResult;

class Gs2RankingClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "ranking";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const RankingTable& obj)
    {
        writer.writeObjectStart();
        if (obj.getRankingTableId())
        {
            writer.writePropertyName("rankingTableId");
            writer.write(*obj.getRankingTableId());
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
        if (obj.getPutScoreTriggerScript())
        {
            writer.writePropertyName("putScoreTriggerScript");
            writer.write(*obj.getPutScoreTriggerScript());
        }
        if (obj.getPutScoreDoneTriggerScript())
        {
            writer.writePropertyName("putScoreDoneTriggerScript");
            writer.write(*obj.getPutScoreDoneTriggerScript());
        }
        if (obj.getCalculateRankingDoneTriggerScript())
        {
            writer.writePropertyName("calculateRankingDoneTriggerScript");
            writer.write(*obj.getCalculateRankingDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const GameMode& obj)
    {
        writer.writeObjectStart();
        if (obj.getGameModeId())
        {
            writer.writePropertyName("gameModeId");
            writer.write(*obj.getGameModeId());
        }
        if (obj.getRankingTableId())
        {
            writer.writePropertyName("rankingTableId");
            writer.write(*obj.getRankingTableId());
        }
        if (obj.getOwnerId())
        {
            writer.writePropertyName("ownerId");
            writer.write(*obj.getOwnerId());
        }
        if (obj.getGameMode())
        {
            writer.writePropertyName("gameMode");
            writer.write(*obj.getGameMode());
        }
        if (obj.getAsc())
        {
            writer.writePropertyName("asc");
            writer.write(*obj.getAsc());
        }
        if (obj.getCalcInterval())
        {
            writer.writePropertyName("calcInterval");
            writer.write(*obj.getCalcInterval());
        }
        if (obj.getCalculating())
        {
            writer.writePropertyName("calculating");
            writer.write(*obj.getCalculating());
        }
        if (obj.getPutScoreTriggerScript())
        {
            writer.writePropertyName("putScoreTriggerScript");
            writer.write(*obj.getPutScoreTriggerScript());
        }
        if (obj.getPutScoreDoneTriggerScript())
        {
            writer.writePropertyName("putScoreDoneTriggerScript");
            writer.write(*obj.getPutScoreDoneTriggerScript());
        }
        if (obj.getCalculateRankingDoneTriggerScript())
        {
            writer.writePropertyName("calculateRankingDoneTriggerScript");
            writer.write(*obj.getCalculateRankingDoneTriggerScript());
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
        if (obj.getLastCalcAt())
        {
            writer.writePropertyName("lastCalcAt");
            writer.write(*obj.getLastCalcAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Score& obj)
    {
        writer.writeObjectStart();
        if (obj.getRankingTableId())
        {
            writer.writePropertyName("rankingTableId");
            writer.write(*obj.getRankingTableId());
        }
        if (obj.getGameMode())
        {
            writer.writePropertyName("gameMode");
            writer.write(*obj.getGameMode());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getScore())
        {
            writer.writePropertyName("score");
            writer.write(*obj.getScore());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getUpdateAt())
        {
            writer.writePropertyName("updateAt");
            writer.write(*obj.getUpdateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const RankingScore& obj)
    {
        writer.writeObjectStart();
        if (obj.getIndex())
        {
            writer.writePropertyName("index");
            writer.write(*obj.getIndex());
        }
        if (obj.getRank())
        {
            writer.writePropertyName("rank");
            writer.write(*obj.getRank());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getScore())
        {
            writer.writePropertyName("score");
            writer.write(*obj.getScore());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
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
    Gs2RankingClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2RankingClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2RankingClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * ゲームモードを作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGameMode(std::function<void(AsyncCreateGameModeResult&)> callback, CreateGameModeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateGameModeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("/mode");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getGameMode())
        {
            writer.writePropertyName("gameMode");
            writer.write(*request.getGameMode());
        }
        if (request.getAsc())
        {
            writer.writePropertyName("asc");
            writer.write(*request.getAsc());
        }
        if (request.getCalcInterval())
        {
            writer.writePropertyName("calcInterval");
            writer.write(*request.getCalcInterval());
        }
        if (request.getPutScoreTriggerScript())
        {
            writer.writePropertyName("putScoreTriggerScript");
            writer.write(*request.getPutScoreTriggerScript());
        }
        if (request.getPutScoreDoneTriggerScript())
        {
            writer.writePropertyName("putScoreDoneTriggerScript");
            writer.write(*request.getPutScoreDoneTriggerScript());
        }
        if (request.getCalculateRankingDoneTriggerScript())
        {
            writer.writePropertyName("calculateRankingDoneTriggerScript");
            writer.write(*request.getCalculateRankingDoneTriggerScript());
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
     * ゲームモードを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGameMode(std::function<void(AsyncDeleteGameModeResult&)> callback, DeleteGameModeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("/mode/").append(detail::StringUtil::toStr(buffer, request.getGameMode())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゲームモードの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGameMode(std::function<void(AsyncDescribeGameModeResult&)> callback, DescribeGameModeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeGameModeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("/mode");
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
     * ゲームモードを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGameMode(std::function<void(AsyncGetGameModeResult&)> callback, GetGameModeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGameModeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("/mode/").append(detail::StringUtil::toStr(buffer, request.getGameMode())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゲームモードの設定を更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGameMode(std::function<void(AsyncUpdateGameModeResult&)> callback, UpdateGameModeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateGameModeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("/mode/").append(detail::StringUtil::toStr(buffer, request.getGameMode())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getCalcInterval())
        {
            writer.writePropertyName("calcInterval");
            writer.write(*request.getCalcInterval());
        }
        if (request.getPutScoreTriggerScript())
        {
            writer.writePropertyName("putScoreTriggerScript");
            writer.write(*request.getPutScoreTriggerScript());
        }
        if (request.getPutScoreDoneTriggerScript())
        {
            writer.writePropertyName("putScoreDoneTriggerScript");
            writer.write(*request.getPutScoreDoneTriggerScript());
        }
        if (request.getCalculateRankingDoneTriggerScript())
        {
            writer.writePropertyName("calculateRankingDoneTriggerScript");
            writer.write(*request.getCalculateRankingDoneTriggerScript());
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
     * ランキングテーブルを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRankingTable(std::function<void(AsyncCreateRankingTableResult&)> callback, CreateRankingTableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateRankingTableResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking");
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
        if (request.getPutScoreTriggerScript())
        {
            writer.writePropertyName("putScoreTriggerScript");
            writer.write(*request.getPutScoreTriggerScript());
        }
        if (request.getPutScoreDoneTriggerScript())
        {
            writer.writePropertyName("putScoreDoneTriggerScript");
            writer.write(*request.getPutScoreDoneTriggerScript());
        }
        if (request.getCalculateRankingDoneTriggerScript())
        {
            writer.writePropertyName("calculateRankingDoneTriggerScript");
            writer.write(*request.getCalculateRankingDoneTriggerScript());
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
     * ランキングテーブルを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRankingTable(std::function<void(AsyncDeleteRankingTableResult&)> callback, DeleteRankingTableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ランキングテーブルの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRankingTable(std::function<void(AsyncDescribeRankingTableResult&)> callback, DescribeRankingTableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeRankingTableResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking");
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
     * ランキングテーブルを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRankingTable(std::function<void(AsyncGetRankingTableResult&)> callback, GetRankingTableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetRankingTableResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ランキングテーブルを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateRankingTable(std::function<void(AsyncUpdateRankingTableResult&)> callback, UpdateRankingTableRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateRankingTableResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getPutScoreTriggerScript())
        {
            writer.writePropertyName("putScoreTriggerScript");
            writer.write(*request.getPutScoreTriggerScript());
        }
        if (request.getPutScoreDoneTriggerScript())
        {
            writer.writePropertyName("putScoreDoneTriggerScript");
            writer.write(*request.getPutScoreDoneTriggerScript());
        }
        if (request.getCalculateRankingDoneTriggerScript())
        {
            writer.writePropertyName("calculateRankingDoneTriggerScript");
            writer.write(*request.getCalculateRankingDoneTriggerScript());
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
     * 指定したスコアを取った時のおおよその順位を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getEstimateRank(std::function<void(AsyncGetEstimateRankResult&)> callback, GetEstimateRankRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetEstimateRankResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("/mode/").append(detail::StringUtil::toStr(buffer, request.getGameMode())).append("/ranking/estimate");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getScore()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getScore()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("score={value}").replace("{value}", encodeBuffer) + "&";
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
     * 現在の順位を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMyRank(std::function<void(AsyncGetMyRankResult&)> callback, GetMyRankRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMyRankResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("/mode/").append(detail::StringUtil::toStr(buffer, request.getGameMode())).append("/ranking/rank");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ランキングを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRanking(std::function<void(AsyncGetRankingResult&)> callback, GetRankingRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetRankingResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("/mode/").append(detail::StringUtil::toStr(buffer, request.getGameMode())).append("/ranking");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getOffset()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getOffset()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("offset={value}").replace("{value}", encodeBuffer) + "&";
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
     * スコアを登録します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void putScore(std::function<void(AsyncPutScoreResult&)> callback, PutScoreRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<PutScoreResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/ranking/").append(detail::StringUtil::toStr(buffer, request.getRankingTableName())).append("/mode/").append(detail::StringUtil::toStr(buffer, request.getGameMode())).append("/ranking");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getScore())
        {
            writer.writePropertyName("score");
            writer.write(*request.getScore());
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
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

#endif //GS2_RANKING_GS2RANKINGCLIENT_HPP_