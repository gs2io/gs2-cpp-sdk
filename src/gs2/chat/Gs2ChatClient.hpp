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

#ifndef GS2_CHAT_GS2CHATCLIENT_HPP_
#define GS2_CHAT_GS2CHATCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace chat {

typedef AsyncResult<CreateLobbyResult> AsyncCreateLobbyResult;
typedef AsyncResult<void> AsyncDeleteLobbyResult;
typedef AsyncResult<DescribeLobbyResult> AsyncDescribeLobbyResult;
typedef AsyncResult<DescribeServiceClassResult> AsyncDescribeServiceClassResult;
typedef AsyncResult<GetLobbyResult> AsyncGetLobbyResult;
typedef AsyncResult<GetLobbyStatusResult> AsyncGetLobbyStatusResult;
typedef AsyncResult<UpdateLobbyResult> AsyncUpdateLobbyResult;
typedef AsyncResult<CheckEstimateScanByteByAllRoomResult> AsyncCheckEstimateScanByteByAllRoomResult;
typedef AsyncResult<CheckEstimateScanByteByRoomResult> AsyncCheckEstimateScanByteByRoomResult;
typedef AsyncResult<SearchLogByAllRoomResult> AsyncSearchLogByAllRoomResult;
typedef AsyncResult<SearchLogByRoomResult> AsyncSearchLogByRoomResult;
typedef AsyncResult<DescribeMessageResult> AsyncDescribeMessageResult;
typedef AsyncResult<DescribeMessageNoAuthResult> AsyncDescribeMessageNoAuthResult;
typedef AsyncResult<SendMessageResult> AsyncSendMessageResult;
typedef AsyncResult<SendMessageNoAuthResult> AsyncSendMessageNoAuthResult;
typedef AsyncResult<CreateRoomResult> AsyncCreateRoomResult;
typedef AsyncResult<void> AsyncDeleteRoomResult;
typedef AsyncResult<DescribeRoomResult> AsyncDescribeRoomResult;
typedef AsyncResult<GetRoomResult> AsyncGetRoomResult;
typedef AsyncResult<CreateMySubscribeResult> AsyncCreateMySubscribeResult;
typedef AsyncResult<CreateSubscribeResult> AsyncCreateSubscribeResult;
typedef AsyncResult<void> AsyncDeleteMySubscribeResult;
typedef AsyncResult<void> AsyncDeleteSubscribeResult;
typedef AsyncResult<DescribeMySubscribeResult> AsyncDescribeMySubscribeResult;
typedef AsyncResult<DescribeSubscribeByRoomIdResult> AsyncDescribeSubscribeByRoomIdResult;
typedef AsyncResult<DescribeSubscribeByUserIdResult> AsyncDescribeSubscribeByUserIdResult;
typedef AsyncResult<GetMySubscribeResult> AsyncGetMySubscribeResult;
typedef AsyncResult<GetSubscribeResult> AsyncGetSubscribeResult;

class Gs2ChatClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "chat";

    virtual const Char* getEndPoint() const
    {
        return ENDPOINT;
    }

private:

    void write(detail::json::JsonWriter& writer, const Lobby& obj)
    {
        writer.writeObjectStart();
        if (obj.getLobbyId())
        {
            writer.writePropertyName("lobbyId");
            writer.write(*obj.getLobbyId());
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
        if (obj.getNotificationType())
        {
            writer.writePropertyName("notificationType");
            writer.write(*obj.getNotificationType());
        }
        if (obj.getNotificationUrl())
        {
            writer.writePropertyName("notificationUrl");
            writer.write(*obj.getNotificationUrl());
        }
        if (obj.getNotificationGameName())
        {
            writer.writePropertyName("notificationGameName");
            writer.write(*obj.getNotificationGameName());
        }
        if (obj.getLogging())
        {
            writer.writePropertyName("logging");
            writer.write(*obj.getLogging());
        }
        if (obj.getLoggingDate())
        {
            writer.writePropertyName("loggingDate");
            writer.write(*obj.getLoggingDate());
        }
        if (obj.getCreateRoomTriggerScript())
        {
            writer.writePropertyName("createRoomTriggerScript");
            writer.write(*obj.getCreateRoomTriggerScript());
        }
        if (obj.getCreateRoomDoneTriggerScript())
        {
            writer.writePropertyName("createRoomDoneTriggerScript");
            writer.write(*obj.getCreateRoomDoneTriggerScript());
        }
        if (obj.getDeleteRoomTriggerScript())
        {
            writer.writePropertyName("deleteRoomTriggerScript");
            writer.write(*obj.getDeleteRoomTriggerScript());
        }
        if (obj.getDeleteRoomDoneTriggerScript())
        {
            writer.writePropertyName("deleteRoomDoneTriggerScript");
            writer.write(*obj.getDeleteRoomDoneTriggerScript());
        }
        if (obj.getCreateSubscribeTriggerScript())
        {
            writer.writePropertyName("createSubscribeTriggerScript");
            writer.write(*obj.getCreateSubscribeTriggerScript());
        }
        if (obj.getCreateSubscribeDoneTriggerScript())
        {
            writer.writePropertyName("createSubscribeDoneTriggerScript");
            writer.write(*obj.getCreateSubscribeDoneTriggerScript());
        }
        if (obj.getDeleteSubscribeTriggerScript())
        {
            writer.writePropertyName("deleteSubscribeTriggerScript");
            writer.write(*obj.getDeleteSubscribeTriggerScript());
        }
        if (obj.getDeleteSubscribeDoneTriggerScript())
        {
            writer.writePropertyName("deleteSubscribeDoneTriggerScript");
            writer.write(*obj.getDeleteSubscribeDoneTriggerScript());
        }
        if (obj.getSendMessageTriggerScript())
        {
            writer.writePropertyName("sendMessageTriggerScript");
            writer.write(*obj.getSendMessageTriggerScript());
        }
        if (obj.getSendMessageDoneTriggerScript())
        {
            writer.writePropertyName("sendMessageDoneTriggerScript");
            writer.write(*obj.getSendMessageDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const Room& obj)
    {
        writer.writeObjectStart();
        if (obj.getRoomId())
        {
            writer.writePropertyName("roomId");
            writer.write(*obj.getRoomId());
        }
        if (obj.getAllowUserIds())
        {
            writer.writePropertyName("allowUserIds");
            writer.writeArrayStart();
            auto& list = *obj.getAllowUserIds();
            for (Int32 i = 0; i < list.getCount(); ++i)
            {
                writer.write(list[i]);
            }
            writer.writeArrayEnd();
        }
        if (obj.getNeedPassword())
        {
            writer.writePropertyName("needPassword");
            writer.write(*obj.getNeedPassword());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Message& obj)
    {
        writer.writeObjectStart();
        if (obj.getMessageId())
        {
            writer.writePropertyName("messageId");
            writer.write(*obj.getMessageId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getMessage())
        {
            writer.writePropertyName("message");
            writer.write(*obj.getMessage());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const MessageLog& obj)
    {
        writer.writeObjectStart();
        if (obj.getMessageId())
        {
            writer.writePropertyName("messageId");
            writer.write(*obj.getMessageId());
        }
        if (obj.getRoomId())
        {
            writer.writePropertyName("roomId");
            writer.write(*obj.getRoomId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getMessage())
        {
            writer.writePropertyName("message");
            writer.write(*obj.getMessage());
        }
        if (obj.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*obj.getMeta());
        }
        if (obj.getCreateAt())
        {
            writer.writePropertyName("createAt");
            writer.write(*obj.getCreateAt());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Subscribe& obj)
    {
        writer.writeObjectStart();
        if (obj.getRoomId())
        {
            writer.writePropertyName("roomId");
            writer.write(*obj.getRoomId());
        }
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getEnableOfflineTransfer())
        {
            writer.writePropertyName("enableOfflineTransfer");
            writer.write(*obj.getEnableOfflineTransfer());
        }
        if (obj.getOfflineTransferSound())
        {
            writer.writePropertyName("offlineTransferSound");
            writer.write(*obj.getOfflineTransferSound());
        }
        if (obj.getSubscribeAt())
        {
            writer.writePropertyName("subscribeAt");
            writer.write(*obj.getSubscribeAt());
        }
        writer.writeObjectEnd();
    }



public:
    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
     */
    Gs2ChatClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ChatClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2ChatClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * ロビーを新規作成します<br>
     * <br>
     * GS2-Chat の使用を開始するには、まずはロビーを作成します。<br>
     * ロビーはチャットルームの集合体のような存在です。<br>
     * <br>
     * ロビーへの設定項目として購読しているルームに発言があったときの通知方式を指定できます。<br>
     * http/https を設定した場合は、新しい発言があるたびに指定されたURLに通知を出します。<br>
     * 通知は以下のフォーマットで通知されます。<br>
     * {<br>
     *   "_gs2_service": "GS2-Chat#Receive",<br>
     *   "notificationUserIds": [<br>
     *     通知先ユーザID<br>
     *   ],<br>
     *   "roomId": 発言されたルームID,<br>
     *   "userId": 発言したユーザのユーザID,<br>
     *   "message": {<br>
     *     "text": メッセージテキスト,<br>
     *     "meta": メタデータ,<br>
     *   }<br>
     * }<br>
     * GS2-InGamePushNotification を指定した場合は、新しい発言があるたびにプッシュ通知を出します。<br>
     * 通知は以下のフォーマットで通知されます。<br>
     * {<br>
     *   "subject": メッセージテキスト,<br>
     *   "body": {<br>
     *     "_gs2_service": "GS2-Chat#Receive",<br>
     *     "roomId": 発言されたルームID,<br>
     *     "userId": 発言したユーザのユーザID,<br>
     *     "message": {<br>
     *       "text": メッセージテキスト,<br>
     *       "meta": メタデータ,<br>
     *     }<br>
     *   }<br>
     * }<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createLobby(std::function<void(AsyncCreateLobbyResult&)> callback, CreateLobbyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateLobbyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby");
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
        if (request.getNotificationType())
        {
            writer.writePropertyName("notificationType");
            writer.write(*request.getNotificationType());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getNotificationUrl())
        {
            writer.writePropertyName("notificationUrl");
            writer.write(*request.getNotificationUrl());
        }
        if (request.getNotificationGameName())
        {
            writer.writePropertyName("notificationGameName");
            writer.write(*request.getNotificationGameName());
        }
        if (request.getLogging())
        {
            writer.writePropertyName("logging");
            writer.write(*request.getLogging());
        }
        if (request.getLoggingDate())
        {
            writer.writePropertyName("loggingDate");
            writer.write(*request.getLoggingDate());
        }
        if (request.getCreateRoomTriggerScript())
        {
            writer.writePropertyName("createRoomTriggerScript");
            writer.write(*request.getCreateRoomTriggerScript());
        }
        if (request.getCreateRoomDoneTriggerScript())
        {
            writer.writePropertyName("createRoomDoneTriggerScript");
            writer.write(*request.getCreateRoomDoneTriggerScript());
        }
        if (request.getDeleteRoomTriggerScript())
        {
            writer.writePropertyName("deleteRoomTriggerScript");
            writer.write(*request.getDeleteRoomTriggerScript());
        }
        if (request.getDeleteRoomDoneTriggerScript())
        {
            writer.writePropertyName("deleteRoomDoneTriggerScript");
            writer.write(*request.getDeleteRoomDoneTriggerScript());
        }
        if (request.getCreateSubscribeTriggerScript())
        {
            writer.writePropertyName("createSubscribeTriggerScript");
            writer.write(*request.getCreateSubscribeTriggerScript());
        }
        if (request.getCreateSubscribeDoneTriggerScript())
        {
            writer.writePropertyName("createSubscribeDoneTriggerScript");
            writer.write(*request.getCreateSubscribeDoneTriggerScript());
        }
        if (request.getDeleteSubscribeTriggerScript())
        {
            writer.writePropertyName("deleteSubscribeTriggerScript");
            writer.write(*request.getDeleteSubscribeTriggerScript());
        }
        if (request.getDeleteSubscribeDoneTriggerScript())
        {
            writer.writePropertyName("deleteSubscribeDoneTriggerScript");
            writer.write(*request.getDeleteSubscribeDoneTriggerScript());
        }
        if (request.getSendMessageTriggerScript())
        {
            writer.writePropertyName("sendMessageTriggerScript");
            writer.write(*request.getSendMessageTriggerScript());
        }
        if (request.getSendMessageDoneTriggerScript())
        {
            writer.writePropertyName("sendMessageDoneTriggerScript");
            writer.write(*request.getSendMessageDoneTriggerScript());
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
     * ロビーを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteLobby(std::function<void(AsyncDeleteLobbyResult&)> callback, DeleteLobbyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ロビーの一覧を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeLobby(std::function<void(AsyncDescribeLobbyResult&)> callback, DescribeLobbyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeLobbyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby");
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
            url.append("/lobby/serviceClass");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ロビーを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLobby(std::function<void(AsyncGetLobbyResult&)> callback, GetLobbyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLobbyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ロビーの状態を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getLobbyStatus(std::function<void(AsyncGetLobbyStatusResult&)> callback, GetLobbyStatusRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetLobbyStatusResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/status");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ロビーを更新します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void updateLobby(std::function<void(AsyncUpdateLobbyResult&)> callback, UpdateLobbyRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<UpdateLobbyResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getServiceClass())
        {
            writer.writePropertyName("serviceClass");
            writer.write(*request.getServiceClass());
        }
        if (request.getNotificationType())
        {
            writer.writePropertyName("notificationType");
            writer.write(*request.getNotificationType());
        }
        if (request.getLogging())
        {
            writer.writePropertyName("logging");
            writer.write(*request.getLogging());
        }
        if (request.getDescription())
        {
            writer.writePropertyName("description");
            writer.write(*request.getDescription());
        }
        if (request.getNotificationUrl())
        {
            writer.writePropertyName("notificationUrl");
            writer.write(*request.getNotificationUrl());
        }
        if (request.getNotificationGameName())
        {
            writer.writePropertyName("notificationGameName");
            writer.write(*request.getNotificationGameName());
        }
        if (request.getLoggingDate())
        {
            writer.writePropertyName("loggingDate");
            writer.write(*request.getLoggingDate());
        }
        if (request.getCreateRoomTriggerScript())
        {
            writer.writePropertyName("createRoomTriggerScript");
            writer.write(*request.getCreateRoomTriggerScript());
        }
        if (request.getCreateRoomDoneTriggerScript())
        {
            writer.writePropertyName("createRoomDoneTriggerScript");
            writer.write(*request.getCreateRoomDoneTriggerScript());
        }
        if (request.getDeleteRoomTriggerScript())
        {
            writer.writePropertyName("deleteRoomTriggerScript");
            writer.write(*request.getDeleteRoomTriggerScript());
        }
        if (request.getDeleteRoomDoneTriggerScript())
        {
            writer.writePropertyName("deleteRoomDoneTriggerScript");
            writer.write(*request.getDeleteRoomDoneTriggerScript());
        }
        if (request.getCreateSubscribeTriggerScript())
        {
            writer.writePropertyName("createSubscribeTriggerScript");
            writer.write(*request.getCreateSubscribeTriggerScript());
        }
        if (request.getCreateSubscribeDoneTriggerScript())
        {
            writer.writePropertyName("createSubscribeDoneTriggerScript");
            writer.write(*request.getCreateSubscribeDoneTriggerScript());
        }
        if (request.getDeleteSubscribeTriggerScript())
        {
            writer.writePropertyName("deleteSubscribeTriggerScript");
            writer.write(*request.getDeleteSubscribeTriggerScript());
        }
        if (request.getDeleteSubscribeDoneTriggerScript())
        {
            writer.writePropertyName("deleteSubscribeDoneTriggerScript");
            writer.write(*request.getDeleteSubscribeDoneTriggerScript());
        }
        if (request.getSendMessageTriggerScript())
        {
            writer.writePropertyName("sendMessageTriggerScript");
            writer.write(*request.getSendMessageTriggerScript());
        }
        if (request.getSendMessageDoneTriggerScript())
        {
            writer.writePropertyName("sendMessageDoneTriggerScript");
            writer.write(*request.getSendMessageDoneTriggerScript());
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
     * メッセージ検索時にスキャンするログサイズの予測値を取得します。<br>
     * <br>
     * 長期にわたる検索を行う場合、事前におおよそのログスキャン容量を把握したいと思うはずです。<br>
     * そのような場合にはこのAPIを使用することで、事前にログスキャン容量を把握することが出来ます。<br>
     * <br>
     * ただし、ここで得られる値はあくまで予測値であり、実際に実行した際の値とは異なる場合があります。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void checkEstimateScanByteByAllRoom(std::function<void(AsyncCheckEstimateScanByteByAllRoomResult&)> callback, CheckEstimateScanByteByAllRoomRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CheckEstimateScanByteByAllRoomResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/log/estimate");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("userId={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getMessage()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessage()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("message={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getMeta()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMeta()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("meta={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getBegin()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getBegin()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("begin={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getEnd()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEnd()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("end={value}").replace("{value}", encodeBuffer) + "&";
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
     * メッセージ検索時にスキャンするログサイズの予測値を取得します。<br>
     * <br>
     * 長期にわたる検索を行う場合、事前におおよそのログスキャン容量を把握したいと思うはずです。<br>
     * そのような場合にはこのAPIを使用することで、事前にログスキャン容量を把握することが出来ます。<br>
     * <br>
     * ただし、ここで得られる値はあくまで予測値であり、実際に実行した際の値とは異なる場合があります。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void checkEstimateScanByteByRoom(std::function<void(AsyncCheckEstimateScanByteByRoomResult&)> callback, CheckEstimateScanByteByRoomRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CheckEstimateScanByteByRoomResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/log/estimate");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("userId={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getMessage()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessage()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("message={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getMeta()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMeta()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("meta={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getBegin()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getBegin()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("begin={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getEnd()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEnd()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("end={value}").replace("{value}", encodeBuffer) + "&";
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
     * メッセージログを検索します。<br>
     * <br>
     * メッセージログの検索には以下のパラメータを使用できます。<br>
     * * ユーザID<br>
     * * メッセージテキスト<br>
     * * メッセージメタデータ<br>
     * いずれも部分一致で検索できます。<br>
     * たとえば、メッセージメタデータに JSON フォーマットを使用している場合は JSON 文字列に対する部分一致検索が適用できます。<br>
     * 一方で、BLOB データを Base64 かけたようなデータの場合は検索対象とするのは困難です。<br>
     * <br>
     * メッセージログ検索にかかる費用は、検索時にログデータを何バイトスキャンしたかで決定されます。<br>
     * そのため、発言者が滞在していたルームが特定できている場合は、本APIではなく『Gs2Chat:SearchLogByRoom』を使用する方が費用を節約できます。<br>
     * また、検索範囲を時間で指定できますが、ログデータは1日単位(UTC)で分割して保存されており、スキャン時には1日分全てがスキャン対象となります。<br>
     * つまり、特定の日付の5分間のログを検索するクエリを実行した場合、該当する1日分のログデータがスキャン対象となり、<br>
     * さらにその5分間が日付をまたぐような場合は2日分のログデータがスキャン対象となります。<br>
     * <br>
     * 検索結果が指定した取得最大件数以上の結果を持つ場合、実行後一定期間内であればページトークンを使用した続きのデータ取得が可能です。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void searchLogByAllRoom(std::function<void(AsyncSearchLogByAllRoomResult&)> callback, SearchLogByAllRoomRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SearchLogByAllRoomResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/log");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("userId={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getMessage()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessage()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("message={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getMeta()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMeta()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("meta={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getBegin()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getBegin()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("begin={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getEnd()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEnd()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("end={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getUseCache()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUseCache()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("useCache={value}").replace("{value}", encodeBuffer) + "&";
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
     * メッセージログを検索します。<br>
     * <br>
     * メッセージログの検索には以下のパラメータを使用できます。<br>
     * * ユーザID<br>
     * * メッセージテキスト<br>
     * * メッセージメタデータ<br>
     * いずれも部分一致で検索できます。<br>
     * たとえば、メッセージメタデータに JSON フォーマットを使用している場合は JSON 文字列に対する部分一致検索が適用できます。<br>
     * 一方で、BLOB データを Base64 かけたようなデータの場合は検索対象とするのは困難です。<br>
     * <br>
     * メッセージログ検索にかかる費用は、検索時にログデータを何バイトスキャンしたかで決定されます。<br>
     * 検索範囲を時間で指定できますが、ログデータは1日単位(UTC)で分割して保存されており、スキャン時には1日分全てがスキャン対象となります。<br>
     * つまり、特定の日付の5分間のログを検索するクエリを実行した場合、該当する1日分のログデータがスキャン対象となり、<br>
     * さらにその5分間が日付をまたぐような場合は2日分のログデータがスキャン対象となります。<br>
     * <br>
     * 検索結果が指定した取得最大件数以上の結果を持つ場合、実行後一定期間内であればページトークンを使用した続きのデータ取得が可能です。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void searchLogByRoom(std::function<void(AsyncSearchLogByRoomResult&)> callback, SearchLogByRoomRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SearchLogByRoomResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/log");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getUserId()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUserId()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("userId={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getMessage()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMessage()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("message={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getMeta()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getMeta()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("meta={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getBegin()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getBegin()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("begin={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getEnd()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getEnd()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("end={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getPageToken()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPageToken()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("pageToken={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getLimit()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getLimit()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("limit={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getUseCache()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getUseCache()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("useCache={value}").replace("{value}", encodeBuffer) + "&";
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
     * メッセージの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessage(std::function<void(AsyncDescribeMessageResult&)> callback, DescribeMessageRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeMessageResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/message");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getPassword()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getPassword()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("password={value}").replace("{value}", encodeBuffer) + "&";
        }
        if (request.getStartAt()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStartAt()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("startAt={value}").replace("{value}", encodeBuffer) + "&";
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
     * メッセージの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMessageNoAuth(std::function<void(AsyncDescribeMessageNoAuthResult&)> callback, DescribeMessageNoAuthRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeMessageNoAuthResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/message/force");
        }
        detail::StringVariable queryString("");
        Char encodeBuffer[1024];
        if (request.getStartAt()) {
            gs2::detail::encodeUrl(encodeBuffer, detail::StringVariable(*request.getStartAt()).c_str(), sizeof(encodeBuffer));
            queryString += detail::StringVariable("startAt={value}").replace("{value}", encodeBuffer) + "&";
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
     * メッセージを送信します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMessage(std::function<void(AsyncSendMessageResult&)> callback, SendMessageRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SendMessageResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/message");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getMessage())
        {
            writer.writePropertyName("message");
            writer.write(*request.getMessage());
        }
        if (request.getMeta())
        {
            writer.writePropertyName("meta");
            writer.write(*request.getMeta());
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
     * メッセージを送信します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void sendMessageNoAuth(std::function<void(AsyncSendMessageNoAuthResult&)> callback, SendMessageNoAuthRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SendMessageNoAuthResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/message/force");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*request.getUserId());
        }
        if (request.getMessage())
        {
            writer.writePropertyName("message");
            writer.write(*request.getMessage());
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

    /**
     * ルームを作成します<br>
     * <br>
     * ルームには参加可能なユーザIDリストを設定することが出来ます。<br>
     * ここで指定されたユーザID以外のユーザがメッセージ情報を取得したり、メッセージを書き込もうとしても失敗するようになります。<br>
     * 何も指定しなければ、誰でも読み書きの出来る部屋になります。<br>
     * ルームを作成する際に参加するユーザが確定している場合に使用するといいでしょう。<br>
     * <br>
     * ルームにはパスワードを設定することが出来ます。<br>
     * パスワードが設定されたルームのメッセージ情報を取得したり、メッセージを書き込もうとするさいにパスワードを指定する必要があります。<br>
     * パスワードが一致しない場合は失敗します。<br>
     * 何も指定しなければ、メッセージの読み書きにパスワードを要求しません。<br>
     * ルームを作成する際には参加するユーザが確定できないけれど、アクセスを制限したい場合に使用するといいでしょう。<br>
     * <br>
     * ルームIDには任意の値を指定することが出来ます。<br>
     * たとえば、マッチメイキングを実行し構築されたギャザリングのユーザ向けにチャットルームを提供したい場合、<br>
     * ギャザリングIDをキーとしてルームを作成することで、クライアントがチャットにアクセスする際にIDの特定が容易になります。<br>
     * ルームIDを省略するとUUIDv4に基づいて自動的に採番されます。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createRoom(std::function<void(AsyncCreateRoomResult&)> callback, CreateRoomRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateRoomResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getRoomId())
        {
            writer.writePropertyName("roomId");
            writer.write(*request.getRoomId());
        }
        if (request.getAllowUserIds())
        {
            writer.writePropertyName("allowUserIds");
            writer.write(*request.getAllowUserIds());
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
     * ルームを削除します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteRoom(std::function<void(AsyncDeleteRoomResult&)> callback, DeleteRoomRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ルームの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeRoom(std::function<void(AsyncDescribeRoomResult&)> callback, DescribeRoomRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeRoomResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room");
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
     * ルームを取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getRoom(std::function<void(AsyncGetRoomResult&)> callback, GetRoomRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetRoomResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ルームを購読します。<br>
     * <br>
     * ルームを購読すると、ルームに対する新着メッセージを受信したときに通知を受けることが出来ます。<br>
     * 通知方式はロビーの設定に依存します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createMySubscribe(std::function<void(AsyncCreateMySubscribeResult&)> callback, CreateMySubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateMySubscribeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/subscribe");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getEnableOfflineTransfer())
        {
            writer.writePropertyName("enableOfflineTransfer");
            writer.write(*request.getEnableOfflineTransfer());
        }
        if (request.getOfflineTransferSound())
        {
            writer.writePropertyName("offlineTransferSound");
            writer.write(*request.getOfflineTransferSound());
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
     * ルームを購読します。<br>
     * <br>
     * ルームを購読すると、ルームに対する新着メッセージを受信したときに通知を受けることが出来ます。<br>
     * 通知方式はロビーの設定に依存します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createSubscribe(std::function<void(AsyncCreateSubscribeResult&)> callback, CreateSubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateSubscribeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/subscribe");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getEnableOfflineTransfer())
        {
            writer.writePropertyName("enableOfflineTransfer");
            writer.write(*request.getEnableOfflineTransfer());
        }
        if (request.getOfflineTransferSound())
        {
            writer.writePropertyName("offlineTransferSound");
            writer.write(*request.getOfflineTransferSound());
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
     * 購読を解除する。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteMySubscribe(std::function<void(AsyncDeleteMySubscribeResult&)> callback, DeleteMySubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/user/self/subscribe");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 購読を解除する。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteSubscribe(std::function<void(AsyncDeleteSubscribeResult&)> callback, DeleteSubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/subscribe");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ユーザが購読しているルームの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeMySubscribe(std::function<void(AsyncDescribeMySubscribeResult&)> callback, DescribeMySubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeMySubscribeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/user/subscribe");
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
     * ルームを購読しているユーザの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribeByRoomId(std::function<void(AsyncDescribeSubscribeByRoomIdResult&)> callback, DescribeSubscribeByRoomIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeSubscribeByRoomIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/subscribe");
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
     * ユーザが購読しているルームの一覧を取得します。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void describeSubscribeByUserId(std::function<void(AsyncDescribeSubscribeByUserIdResult&)> callback, DescribeSubscribeByUserIdRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<DescribeSubscribeByUserIdResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/subscribe");
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
     * 購読情報を取得する。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMySubscribe(std::function<void(AsyncGetMySubscribeResult&)> callback, GetMySubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMySubscribeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/user/self/subscribe");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 購読情報を取得する。<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getSubscribe(std::function<void(AsyncGetSubscribeResult&)> callback, GetSubscribeRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetSubscribeResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/lobby/").append(detail::StringUtil::toStr(buffer, request.getLobbyName())).append("/room/").append(detail::StringUtil::toStr(buffer, request.getRoomId())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("/subscribe");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

};

} }

#endif //GS2_CHAT_GS2CHATCLIENT_HPP_