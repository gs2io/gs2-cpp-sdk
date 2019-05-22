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

#ifndef GS2_ACCOUNT_GS2ACCOUNTCLIENT_HPP_
#define GS2_ACCOUNT_GS2ACCOUNTCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/Gs2StandardHttpTask.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "model/model.hpp"
#include "request/DescribeGamesRequest.hpp"
#include "request/CreateGameRequest.hpp"
#include "request/GetGameStatusRequest.hpp"
#include "request/GetGameRequest.hpp"
#include "request/UpdateGameRequest.hpp"
#include "request/DeleteGameRequest.hpp"
#include "request/DescribeAccountsRequest.hpp"
#include "request/CreateAccountRequest.hpp"
#include "request/GetAccountRequest.hpp"
#include "request/DeleteAccountRequest.hpp"
#include "request/AuthenticationRequest.hpp"
#include "request/DescribeTakeOversRequest.hpp"
#include "request/CreateTakeOverRequest.hpp"
#include "request/CreateTakeOverByUserIdRequest.hpp"
#include "request/GetTakeOverRequest.hpp"
#include "request/GetTakeOverByUserIdRequest.hpp"
#include "request/UpdateTakeOverRequest.hpp"
#include "request/UpdateTakeOverByUserIdRequest.hpp"
#include "request/DeleteTakeOverRequest.hpp"
#include "request/DeleteTakeOverByUserIdentifierRequest.hpp"
#include "request/DoTakeOverRequest.hpp"
#include "result/DescribeGamesResult.hpp"
#include "result/CreateGameResult.hpp"
#include "result/GetGameStatusResult.hpp"
#include "result/GetGameResult.hpp"
#include "result/UpdateGameResult.hpp"
#include "result/DeleteGameResult.hpp"
#include "result/DescribeAccountsResult.hpp"
#include "result/CreateAccountResult.hpp"
#include "result/GetAccountResult.hpp"
#include "result/DeleteAccountResult.hpp"
#include "result/AuthenticationResult.hpp"
#include "result/DescribeTakeOversResult.hpp"
#include "result/CreateTakeOverResult.hpp"
#include "result/CreateTakeOverByUserIdResult.hpp"
#include "result/GetTakeOverResult.hpp"
#include "result/GetTakeOverByUserIdResult.hpp"
#include "result/UpdateTakeOverResult.hpp"
#include "result/UpdateTakeOverByUserIdResult.hpp"
#include "result/DeleteTakeOverResult.hpp"
#include "result/DeleteTakeOverByUserIdentifierResult.hpp"
#include "result/DoTakeOverResult.hpp"
#include <cstring>
#include <network/HttpRequest.h>

namespace gs2 { namespace account {

typedef AsyncResult<DescribeGamesResult> AsyncDescribeGamesResult;
typedef AsyncResult<CreateGameResult> AsyncCreateGameResult;
typedef AsyncResult<GetGameStatusResult> AsyncGetGameStatusResult;
typedef AsyncResult<GetGameResult> AsyncGetGameResult;
typedef AsyncResult<UpdateGameResult> AsyncUpdateGameResult;
typedef AsyncResult<void> AsyncDeleteGameResult;
typedef AsyncResult<DescribeAccountsResult> AsyncDescribeAccountsResult;
typedef AsyncResult<CreateAccountResult> AsyncCreateAccountResult;
typedef AsyncResult<GetAccountResult> AsyncGetAccountResult;
typedef AsyncResult<void> AsyncDeleteAccountResult;
typedef AsyncResult<AuthenticationResult> AsyncAuthenticationResult;
typedef AsyncResult<DescribeTakeOversResult> AsyncDescribeTakeOversResult;
typedef AsyncResult<CreateTakeOverResult> AsyncCreateTakeOverResult;
typedef AsyncResult<CreateTakeOverByUserIdResult> AsyncCreateTakeOverByUserIdResult;
typedef AsyncResult<GetTakeOverResult> AsyncGetTakeOverResult;
typedef AsyncResult<GetTakeOverByUserIdResult> AsyncGetTakeOverByUserIdResult;
typedef AsyncResult<UpdateTakeOverResult> AsyncUpdateTakeOverResult;
typedef AsyncResult<UpdateTakeOverByUserIdResult> AsyncUpdateTakeOverByUserIdResult;
typedef AsyncResult<void> AsyncDeleteTakeOverResult;
typedef AsyncResult<void> AsyncDeleteTakeOverByUserIdentifierResult;
typedef AsyncResult<DoTakeOverResult> AsyncDoTakeOverResult;

/**
 * GS2 Account API クライアント
 *
 * @author Game Server Services, Inc.
 *
 */
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
        if (obj.getChangePasswordIfTakeOver())
        {
            writer.writePropertyName("changePasswordIfTakeOver");
            writer.write(*obj.getChangePasswordIfTakeOver());
        }
        if (obj.getCreateAccountTriggerScriptId())
        {
            writer.writePropertyName("createAccountTriggerScriptId");
            writer.write(*obj.getCreateAccountTriggerScriptId());
        }
        if (obj.getCreateAccountDoneTriggerScriptId())
        {
            writer.writePropertyName("createAccountDoneTriggerScriptId");
            writer.write(*obj.getCreateAccountDoneTriggerScriptId());
        }
        if (obj.getCreateAccountDoneTriggerQueueId())
        {
            writer.writePropertyName("createAccountDoneTriggerQueueId");
            writer.write(*obj.getCreateAccountDoneTriggerQueueId());
        }
        if (obj.getAuthenticationTriggerScriptId())
        {
            writer.writePropertyName("authenticationTriggerScriptId");
            writer.write(*obj.getAuthenticationTriggerScriptId());
        }
        if (obj.getAuthenticationDoneTriggerScriptId())
        {
            writer.writePropertyName("authenticationDoneTriggerScriptId");
            writer.write(*obj.getAuthenticationDoneTriggerScriptId());
        }
        if (obj.getAuthenticationDoneTriggerQueueId())
        {
            writer.writePropertyName("authenticationDoneTriggerQueueId");
            writer.write(*obj.getAuthenticationDoneTriggerQueueId());
        }
        if (obj.getCreateTakeOverTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverTriggerScriptId");
            writer.write(*obj.getCreateTakeOverTriggerScriptId());
        }
        if (obj.getCreateTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerScriptId");
            writer.write(*obj.getCreateTakeOverDoneTriggerScriptId());
        }
        if (obj.getCreateTakeOverDoneTriggerQueueId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerQueueId");
            writer.write(*obj.getCreateTakeOverDoneTriggerQueueId());
        }
        if (obj.getDoTakeOverTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverTriggerScriptId");
            writer.write(*obj.getDoTakeOverTriggerScriptId());
        }
        if (obj.getDoTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerScriptId");
            writer.write(*obj.getDoTakeOverDoneTriggerScriptId());
        }
        if (obj.getDoTakeOverDoneTriggerQueueId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerQueueId");
            writer.write(*obj.getDoTakeOverDoneTriggerQueueId());
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
        if (obj.getAccountId())
        {
            writer.writePropertyName("accountId");
            writer.write(*obj.getAccountId());
        }
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
        if (obj.getTakeOverId())
        {
            writer.writePropertyName("takeOverId");
            writer.write(*obj.getTakeOverId());
        }
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

    void write(detail::json::JsonWriter& writer, const FullTakeOver& obj)
    {
        writer.writeObjectStart();
        if (obj.getTakeOverId())
        {
            writer.writePropertyName("takeOverId");
            writer.write(*obj.getTakeOverId());
        }
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
        if (obj.getPassword())
        {
            writer.writePropertyName("password");
            writer.write(*obj.getPassword());
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
	 * ゲームの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeGames(std::function<void(AsyncDescribeGamesResult&)> callback, DescribeGamesRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeGamesResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FGameFunctionHandler.describeGames");
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
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ゲームを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createGame(std::function<void(AsyncCreateGameResult&)> callback, CreateGameRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateGameResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FGameFunctionHandler.createGame");
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
        if (request.getChangePasswordIfTakeOver())
        {
            writer.writePropertyName("changePasswordIfTakeOver");
            writer.write(*request.getChangePasswordIfTakeOver());
        }
        if (request.getCreateAccountTriggerScriptId())
        {
            writer.writePropertyName("createAccountTriggerScriptId");
            writer.write(*request.getCreateAccountTriggerScriptId());
        }
        if (request.getCreateAccountDoneTriggerScriptId())
        {
            writer.writePropertyName("createAccountDoneTriggerScriptId");
            writer.write(*request.getCreateAccountDoneTriggerScriptId());
        }
        if (request.getCreateAccountDoneTriggerQueueId())
        {
            writer.writePropertyName("createAccountDoneTriggerQueueId");
            writer.write(*request.getCreateAccountDoneTriggerQueueId());
        }
        if (request.getAuthenticationTriggerScriptId())
        {
            writer.writePropertyName("authenticationTriggerScriptId");
            writer.write(*request.getAuthenticationTriggerScriptId());
        }
        if (request.getAuthenticationDoneTriggerScriptId())
        {
            writer.writePropertyName("authenticationDoneTriggerScriptId");
            writer.write(*request.getAuthenticationDoneTriggerScriptId());
        }
        if (request.getAuthenticationDoneTriggerQueueId())
        {
            writer.writePropertyName("authenticationDoneTriggerQueueId");
            writer.write(*request.getAuthenticationDoneTriggerQueueId());
        }
        if (request.getCreateTakeOverTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverTriggerScriptId");
            writer.write(*request.getCreateTakeOverTriggerScriptId());
        }
        if (request.getCreateTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerScriptId");
            writer.write(*request.getCreateTakeOverDoneTriggerScriptId());
        }
        if (request.getCreateTakeOverDoneTriggerQueueId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerQueueId");
            writer.write(*request.getCreateTakeOverDoneTriggerQueueId());
        }
        if (request.getDoTakeOverTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverTriggerScriptId");
            writer.write(*request.getDoTakeOverTriggerScriptId());
        }
        if (request.getDoTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerScriptId");
            writer.write(*request.getDoTakeOverDoneTriggerScriptId());
        }
        if (request.getDoTakeOverDoneTriggerQueueId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerQueueId");
            writer.write(*request.getDoTakeOverDoneTriggerQueueId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ゲームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGameStatus(std::function<void(AsyncGetGameStatusResult&)> callback, GetGameStatusRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetGameStatusResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FGameFunctionHandler.getGameStatus");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ゲームを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getGame(std::function<void(AsyncGetGameResult&)> callback, GetGameRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetGameResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FGameFunctionHandler.getGame");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ゲームを更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateGame(std::function<void(AsyncUpdateGameResult&)> callback, UpdateGameRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateGameResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FGameFunctionHandler.updateGame");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
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
        if (request.getCreateAccountTriggerScriptId())
        {
            writer.writePropertyName("createAccountTriggerScriptId");
            writer.write(*request.getCreateAccountTriggerScriptId());
        }
        if (request.getCreateAccountDoneTriggerScriptId())
        {
            writer.writePropertyName("createAccountDoneTriggerScriptId");
            writer.write(*request.getCreateAccountDoneTriggerScriptId());
        }
        if (request.getCreateAccountDoneTriggerQueueId())
        {
            writer.writePropertyName("createAccountDoneTriggerQueueId");
            writer.write(*request.getCreateAccountDoneTriggerQueueId());
        }
        if (request.getAuthenticationTriggerScriptId())
        {
            writer.writePropertyName("authenticationTriggerScriptId");
            writer.write(*request.getAuthenticationTriggerScriptId());
        }
        if (request.getAuthenticationDoneTriggerScriptId())
        {
            writer.writePropertyName("authenticationDoneTriggerScriptId");
            writer.write(*request.getAuthenticationDoneTriggerScriptId());
        }
        if (request.getAuthenticationDoneTriggerQueueId())
        {
            writer.writePropertyName("authenticationDoneTriggerQueueId");
            writer.write(*request.getAuthenticationDoneTriggerQueueId());
        }
        if (request.getCreateTakeOverTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverTriggerScriptId");
            writer.write(*request.getCreateTakeOverTriggerScriptId());
        }
        if (request.getCreateTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerScriptId");
            writer.write(*request.getCreateTakeOverDoneTriggerScriptId());
        }
        if (request.getCreateTakeOverDoneTriggerQueueId())
        {
            writer.writePropertyName("createTakeOverDoneTriggerQueueId");
            writer.write(*request.getCreateTakeOverDoneTriggerQueueId());
        }
        if (request.getDoTakeOverTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverTriggerScriptId");
            writer.write(*request.getDoTakeOverTriggerScriptId());
        }
        if (request.getDoTakeOverDoneTriggerScriptId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerScriptId");
            writer.write(*request.getDoTakeOverDoneTriggerScriptId());
        }
        if (request.getDoTakeOverDoneTriggerQueueId())
        {
            writer.writePropertyName("doTakeOverDoneTriggerQueueId");
            writer.write(*request.getDoTakeOverDoneTriggerQueueId());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ゲームを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteGame(std::function<void(AsyncDeleteGameResult&)> callback, DeleteGameRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FGameFunctionHandler.deleteGame");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * アカウントの一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeAccounts(std::function<void(AsyncDescribeAccountsResult&)> callback, DescribeAccountsRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeAccountsResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FAccountFunctionHandler.describeAccounts");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
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
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * アカウントを新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createAccount(std::function<void(AsyncCreateAccountResult&)> callback, CreateAccountRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateAccountResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FAccountFunctionHandler.createAccount");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * アカウントを取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getAccount(std::function<void(AsyncGetAccountResult&)> callback, GetAccountRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetAccountResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FAccountFunctionHandler.getAccount");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * アカウントを削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteAccount(std::function<void(AsyncDeleteAccountResult&)> callback, DeleteAccountRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FAccountFunctionHandler.deleteAccount");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * アカウントを認証<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void authentication(std::function<void(AsyncAuthenticationResult&)> callback, AuthenticationRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<AuthenticationResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FAccountFunctionHandler.authentication");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getKeyId())
        {
            writer.writePropertyName("keyId");
            writer.write(*request.getKeyId());
        }
        if (request.getPassword())
        {
            writer.writePropertyName("password");
            writer.write(*request.getPassword());
        }
        writer.writeObjectEnd();
        auto body = writer.toString();
        auto bodySize = strlen(body);
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 引き継ぎ設定の一覧を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeTakeOvers(std::function<void(AsyncDescribeTakeOversResult&)> callback, DescribeTakeOversRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DescribeTakeOversResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.describeTakeOvers");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
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
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 引き継ぎ設定を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTakeOver(std::function<void(AsyncCreateTakeOverResult&)> callback, CreateTakeOverRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateTakeOverResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.createTakeOver");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
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
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定を新規作成<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createTakeOverByUserId(std::function<void(AsyncCreateTakeOverByUserIdResult&)> callback, CreateTakeOverByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<CreateTakeOverByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.createTakeOverByUserId");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
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
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 引き継ぎ設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTakeOver(std::function<void(AsyncGetTakeOverResult&)> callback, GetTakeOverRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetTakeOverResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.getTakeOver");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getType()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getType()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("type={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserIdentifier()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserIdentifier()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userIdentifier={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * ユーザーIDを指定して引き継ぎ設定を取得<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getTakeOverByUserId(std::function<void(AsyncGetTakeOverByUserIdResult&)> callback, GetTakeOverByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<GetTakeOverByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.getTakeOverByUserId");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getType()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getType()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("type={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserIdentifier()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserIdentifier()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userIdentifier={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTakeOver(std::function<void(AsyncUpdateTakeOverResult&)> callback, UpdateTakeOverRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateTakeOverResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.updateTakeOver");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getType()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getType()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("type={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserIdentifier()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserIdentifier()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userIdentifier={value}").replace("{value}", encodeBuffer);
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
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateTakeOverByUserId(std::function<void(AsyncUpdateTakeOverByUserIdResult&)> callback, UpdateTakeOverByUserIdRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<UpdateTakeOverByUserIdResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.updateTakeOverByUserId");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userId={value}").replace("{value}", encodeBuffer);
        }
        if (request.getType()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getType()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("type={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserIdentifier()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserIdentifier()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userIdentifier={value}").replace("{value}", encodeBuffer);
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
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 引き継ぎ設定を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTakeOver(std::function<void(AsyncDeleteTakeOverResult&)> callback, DeleteTakeOverRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.deleteTakeOver");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getType()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getType()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("type={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserIdentifier()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserIdentifier()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userIdentifier={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 引き継ぎ設定を削除<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteTakeOverByUserIdentifier(std::function<void(AsyncDeleteTakeOverByUserIdentifierResult&)> callback, DeleteTakeOverByUserIdentifierRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<void>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.deleteTakeOverByUserIdentifier");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getType()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getType()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("type={value}").replace("{value}", encodeBuffer);
        }
        if (request.getUserIdentifier()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserIdentifier()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("userIdentifier={value}").replace("{value}", encodeBuffer);
        }

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        if (request.getDuplicationAvoider())
        {
            detail::Gs2HttpTask::addHeaderEntry(headerEntries, "X-GS2-DUPLICATION-AVOIDER", *request.getDuplicationAvoider());
        }
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }

	/**
	 * 引き継ぎ設定を更新<br>
	 *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void doTakeOver(std::function<void(AsyncDoTakeOverResult&)> callback, DoTakeOverRequest& request)
    {
        auto& gs2StandardHttpTask = *new detail::Gs2StandardHttpTask<DoTakeOverResult>(callback);
        gs2StandardHttpTask.getHttpRequest().setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        url.append("/account-handler?handler=gs2_account%2Fhandler%2FTakeOverFunctionHandler.doTakeOver");
        Char encodeBuffer[2048];
        if (request.getGameName()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getGameName()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("gameName={value}").replace("{value}", encodeBuffer);
        }
        if (request.getType()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getType()).c_str(), sizeof(encodeBuffer));
            url += "&" + detail::StringVariable("type={value}").replace("{value}", encodeBuffer);
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
        gs2StandardHttpTask.getHttpRequest().setRequestData(body, bodySize);

        setUrl(gs2StandardHttpTask.getHttpRequest(), url.c_str());
        std::vector<std::string> headerEntries;
        setHeaderEntries(headerEntries, request);
        gs2StandardHttpTask.getHttpRequest().setHeaders(headerEntries);
        getCredential().authorizeAndExecute(gs2StandardHttpTask);
    }
};

} }

#endif //GS2_ACCOUNT_GS2ACCOUNTCLIENT_HPP_