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

#ifndef GS2_ACCOUNT_GS2ACCOUNTCLIENT_HPP_
#define GS2_ACCOUNT_GS2ACCOUNTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace account {

typedef AsyncResult<AuthenticationResult> AsyncAuthenticationResult;
typedef AsyncResult<CreateAccountResult> AsyncCreateAccountResult;
typedef AsyncResult<void> AsyncDeleteAccountResult;
typedef AsyncResult<DescribeAccountResult> AsyncDescribeAccountResult;
typedef AsyncResult<CreateGameResult> AsyncCreateGameResult;
typedef AsyncResult<void> AsyncDeleteGameResult;
typedef AsyncResult<DescribeGameResult> AsyncDescribeGameResult;
typedef AsyncResult<DescribeServiceClassResult> AsyncDescribeServiceClassResult;
typedef AsyncResult<GetGameResult> AsyncGetGameResult;
typedef AsyncResult<GetGameStatusResult> AsyncGetGameStatusResult;
typedef AsyncResult<UpdateGameResult> AsyncUpdateGameResult;
typedef AsyncResult<CreateTakeOverResult> AsyncCreateTakeOverResult;
typedef AsyncResult<void> AsyncDeleteTakeOverResult;
typedef AsyncResult<DescribeTakeOverResult> AsyncDescribeTakeOverResult;
typedef AsyncResult<DoTakeOverResult> AsyncDoTakeOverResult;
typedef AsyncResult<GetTakeOverResult> AsyncGetTakeOverResult;
typedef AsyncResult<UpdateTakeOverResult> AsyncUpdateTakeOverResult;

class Gs2AccountClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "account";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Game& obj)
    {
        writer.writeObjectStart();
        if (obj.getGameId())
        {
            writer.writePropertyName("gameId");
            writer.write(*obj.getGameId());
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
        if (obj.getChangePasswordIfTakeOver())
        {
            writer.writePropertyName("changePasswordIfTakeOver");
            writer.write(*obj.getChangePasswordIfTakeOver());
        }
        if (obj.getCreateAccountTriggerScript())
        {
            writer.writePropertyName("createAccountTriggerScript");
            writer.write(*obj.getCreateAccountTriggerScript());
        }
        if (obj.getCreateAccountDoneTriggerScript())
        {
            writer.writePropertyName("createAccountDoneTriggerScript");
            writer.write(*obj.getCreateAccountDoneTriggerScript());
        }
        if (obj.getAuthenticationTriggerScript())
        {
            writer.writePropertyName("authenticationTriggerScript");
            writer.write(*obj.getAuthenticationTriggerScript());
        }
        if (obj.getAuthenticationDoneTriggerScript())
        {
            writer.writePropertyName("authenticationDoneTriggerScript");
            writer.write(*obj.getAuthenticationDoneTriggerScript());
        }
        if (obj.getCreateTakeOverTriggerScript())
        {
            writer.writePropertyName("createTakeOverTriggerScript");
            writer.write(*obj.getCreateTakeOverTriggerScript());
        }
        if (obj.getCreateTakeOverDoneTriggerScript())
        {
            writer.writePropertyName("createTakeOverDoneTriggerScript");
            writer.write(*obj.getCreateTakeOverDoneTriggerScript());
        }
        if (obj.getDoTakeOverTriggerScript())
        {
            writer.writePropertyName("doTakeOverTriggerScript");
            writer.write(*obj.getDoTakeOverTriggerScript());
        }
        if (obj.getDoTakeOverDoneTriggerScript())
        {
            writer.writePropertyName("doTakeOverDoneTriggerScript");
            writer.write(*obj.getDoTakeOverDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const Account& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getPassword())
        {
            writer.writePropertyName("password");
            writer.write(*obj.getPassword());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const TakeOver& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.write(*obj.getType());
        }
        if (obj.getUserIdentifier())
        {
            writer.writePropertyName("userIdentifier");
            writer.write(*obj.getUserIdentifier());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2AccountClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2AccountClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2AccountClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * 認証処理を行います<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void authentication(std::function<void(AsyncAuthenticationResult&)> callback, AuthenticationRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<AuthenticationResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/account/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyName())
        {
            writer.writePropertyName("keyName");
            writer.write(*request.getKeyName());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.write(*request.getPassword());
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
     * アカウントを登録します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createAccount(std::function<void(AsyncCreateAccountResult&)> callback, CreateAccountRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateAccountResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/account");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
     * アカウントを削除します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAccount(std::function<void(AsyncDeleteAccountResult&)> callback, DeleteAccountRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/account/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * アカウントを取得します<br>
     * <br>
     * - 消費クオータ: 50件あたり5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAccount(std::function<void(AsyncDescribeAccountResult&)> callback, DescribeAccountRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeAccountResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/account");
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
     * ゲームを新規作成します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGame(std::function<void(AsyncCreateGameResult&)> callback, CreateGameRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateGameResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game");
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
        if (request.getChangePasswordIfTakeOver())
        {
            writer.writePropertyName("changePasswordIfTakeOver");
            writer.write(*request.getChangePasswordIfTakeOver());
        }
        if (request.getCreateAccountTriggerScript())
        {
            writer.writePropertyName("createAccountTriggerScript");
            writer.write(*request.getCreateAccountTriggerScript());
        }
        if (request.getCreateAccountDoneTriggerScript())
        {
            writer.writePropertyName("createAccountDoneTriggerScript");
            writer.write(*request.getCreateAccountDoneTriggerScript());
        }
        if (request.getAuthenticationTriggerScript())
        {
            writer.writePropertyName("authenticationTriggerScript");
            writer.write(*request.getAuthenticationTriggerScript());
        }
        if (request.getAuthenticationDoneTriggerScript())
        {
            writer.writePropertyName("authenticationDoneTriggerScript");
            writer.write(*request.getAuthenticationDoneTriggerScript());
        }
        if (request.getCreateTakeOverTriggerScript())
        {
            writer.writePropertyName("createTakeOverTriggerScript");
            writer.write(*request.getCreateTakeOverTriggerScript());
        }
        if (request.getCreateTakeOverDoneTriggerScript())
        {
            writer.writePropertyName("createTakeOverDoneTriggerScript");
            writer.write(*request.getCreateTakeOverDoneTriggerScript());
        }
        if (request.getDoTakeOverTriggerScript())
        {
            writer.writePropertyName("doTakeOverTriggerScript");
            writer.write(*request.getDoTakeOverTriggerScript());
        }
        if (request.getDoTakeOverDoneTriggerScript())
        {
            writer.writePropertyName("doTakeOverDoneTriggerScript");
            writer.write(*request.getDoTakeOverDoneTriggerScript());
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
     * ゲームを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGame(std::function<void(AsyncDeleteGameResult&)> callback, DeleteGameRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゲームの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGame(std::function<void(AsyncDescribeGameResult&)> callback, DescribeGameRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeGameResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game");
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
            url.append("/game/serviceClass");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゲームを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGame(std::function<void(AsyncGetGameResult&)> callback, GetGameRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGameResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゲームのステータスを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGameStatus(std::function<void(AsyncGetGameStatusResult&)> callback, GetGameStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetGameStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ゲームを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGame(std::function<void(AsyncUpdateGameResult&)> callback, UpdateGameRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateGameResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getServiceClass())
        {
            writer.writePropertyName("serviceClass");
            writer.write(*request.getServiceClass());
        }
        if (request.getChangePasswordIfTakeOver())
        {
            writer.writePropertyName("changePasswordIfTakeOver");
            writer.write(*request.getChangePasswordIfTakeOver());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getCreateAccountTriggerScript())
        {
            writer.writePropertyName("createAccountTriggerScript");
            writer.write(*request.getCreateAccountTriggerScript());
        }
        if (request.getCreateAccountDoneTriggerScript())
        {
            writer.writePropertyName("createAccountDoneTriggerScript");
            writer.write(*request.getCreateAccountDoneTriggerScript());
        }
        if (request.getAuthenticationTriggerScript())
        {
            writer.writePropertyName("authenticationTriggerScript");
            writer.write(*request.getAuthenticationTriggerScript());
        }
        if (request.getAuthenticationDoneTriggerScript())
        {
            writer.writePropertyName("authenticationDoneTriggerScript");
            writer.write(*request.getAuthenticationDoneTriggerScript());
        }
        if (request.getCreateTakeOverTriggerScript())
        {
            writer.writePropertyName("createTakeOverTriggerScript");
            writer.write(*request.getCreateTakeOverTriggerScript());
        }
        if (request.getCreateTakeOverDoneTriggerScript())
        {
            writer.writePropertyName("createTakeOverDoneTriggerScript");
            writer.write(*request.getCreateTakeOverDoneTriggerScript());
        }
        if (request.getDoTakeOverTriggerScript())
        {
            writer.writePropertyName("doTakeOverTriggerScript");
            writer.write(*request.getDoTakeOverTriggerScript());
        }
        if (request.getDoTakeOverDoneTriggerScript())
        {
            writer.writePropertyName("doTakeOverDoneTriggerScript");
            writer.write(*request.getDoTakeOverDoneTriggerScript());
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
     * 引き継ぎ情報を登録します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTakeOver(std::function<void(AsyncCreateTakeOverResult&)> callback, CreateTakeOverRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateTakeOverResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/takeover");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getType())
        {
            writer.writePropertyName("type");
            writer.write(*request.getType());
        }
        if (request.getUserIdentifier())
        {
            writer.writePropertyName("userIdentifier");
            writer.write(*request.getUserIdentifier());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.write(*request.getPassword());
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
     * 引き継ぎ情報を削除します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTakeOver(std::function<void(AsyncDeleteTakeOverResult&)> callback, DeleteTakeOverRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/takeover/").append(detail::StringUtil::toStr(buffer, request.getType())).append("/").append(detail::StringUtil::toStr(buffer, request.getUserIdentifier())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 引き継ぎ情報を取得します<br>
     * <br>
     * - 消費クオータ: 50件あたり5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTakeOver(std::function<void(AsyncDescribeTakeOverResult&)> callback, DescribeTakeOverRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeTakeOverResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/takeover");
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
     * 引き継ぎを実行します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doTakeOver(std::function<void(AsyncDoTakeOverResult&)> callback, DoTakeOverRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DoTakeOverResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/takeover/").append(detail::StringUtil::toStr(buffer, request.getType())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getUserIdentifier())
        {
            writer.writePropertyName("userIdentifier");
            writer.write(*request.getUserIdentifier());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.write(*request.getPassword());
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
     * 引き継ぎ情報を取得します<br>
     * <br>
     * - 消費クオータ: 5<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTakeOver(std::function<void(AsyncGetTakeOverResult&)> callback, GetTakeOverRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetTakeOverResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/takeover/").append(detail::StringUtil::toStr(buffer, request.getType())).append("/").append(detail::StringUtil::toStr(buffer, request.getUserIdentifier())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 引き継ぎ情報を更新します<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTakeOver(std::function<void(AsyncUpdateTakeOverResult&)> callback, UpdateTakeOverRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateTakeOverResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/takeover/").append(detail::StringUtil::toStr(buffer, request.getType())).append("/").append(detail::StringUtil::toStr(buffer, request.getUserIdentifier())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getOldPassword())
        {
            writer.writePropertyName("oldPassword");
            writer.write(*request.getOldPassword());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.write(*request.getPassword());
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

#endif //GS2_ACCOUNT_GS2ACCOUNTCLIENT_HPP_