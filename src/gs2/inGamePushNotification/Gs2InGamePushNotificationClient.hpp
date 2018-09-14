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

#ifndef GS2_INGAMEPUSHNOTIFICATION_GS2INGAMEPUSHNOTIFICATIONCLIENT_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_GS2INGAMEPUSHNOTIFICATIONCLIENT_HPP_

#include <gs2/core/AbstractGs2Client.hpp>
#include <gs2/core/json/JsonWriter.hpp>
#include <gs2/core/network/HttpRequest.hpp>
#include <gs2/core/util/StringUtil.hpp>
#include <gs2/core/util/StringVariable.hpp>
#include <gs2/core/util/UrlEncoder.hpp>
#include "control/controller.hpp"
#include "model/model.hpp"
#include <cstring>

namespace gs2 { namespace inGamePushNotification {

typedef AsyncResult<CreateGameResult> AsyncCreateGameResult;
typedef AsyncResult<void> AsyncDeleteGameResult;
typedef AsyncResult<DescribeGameResult> AsyncDescribeGameResult;
typedef AsyncResult<DescribeServiceClassResult> AsyncDescribeServiceClassResult;
typedef AsyncResult<GetGameResult> AsyncGetGameResult;
typedef AsyncResult<GetGameStatusResult> AsyncGetGameStatusResult;
typedef AsyncResult<UpdateGameResult> AsyncUpdateGameResult;
typedef AsyncResult<GetMqttHostResult> AsyncGetMqttHostResult;
typedef AsyncResult<GetWebSocketHostResult> AsyncGetWebSocketHostResult;
typedef AsyncResult<PublishResult> AsyncPublishResult;
typedef AsyncResult<CreateCertificateResult> AsyncCreateCertificateResult;
typedef AsyncResult<void> AsyncDeleteCertificateResult;
typedef AsyncResult<DescribeStatusResult> AsyncDescribeStatusResult;
typedef AsyncResult<SetFirebaseTokenResult> AsyncSetFirebaseTokenResult;

class Gs2InGamePushNotificationClient : public AbstractGs2ClientBase
{
private:
    constexpr static const Char* ENDPOINT = "in-game-push-notification";

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
        if (obj.getOfflineTransfer())
        {
            writer.writePropertyName("offlineTransfer");
            writer.write(*obj.getOfflineTransfer());
        }
        if (obj.getNotificationUrl())
        {
            writer.writePropertyName("notificationUrl");
            writer.write(*obj.getNotificationUrl());
        }
        if (obj.getNotificationFirebaseServerKey())
        {
            writer.writePropertyName("notificationFirebaseServerKey");
            writer.write(*obj.getNotificationFirebaseServerKey());
        }
        if (obj.getCreateCertificateTriggerScript())
        {
            writer.writePropertyName("createCertificateTriggerScript");
            writer.write(*obj.getCreateCertificateTriggerScript());
        }
        if (obj.getCreateCertificateDoneTriggerScript())
        {
            writer.writePropertyName("createCertificateDoneTriggerScript");
            writer.write(*obj.getCreateCertificateDoneTriggerScript());
        }
        if (obj.getDeleteCertificateTriggerScript())
        {
            writer.writePropertyName("deleteCertificateTriggerScript");
            writer.write(*obj.getDeleteCertificateTriggerScript());
        }
        if (obj.getDeleteCertificateDoneTriggerScript())
        {
            writer.writePropertyName("deleteCertificateDoneTriggerScript");
            writer.write(*obj.getDeleteCertificateDoneTriggerScript());
        }
        if (obj.getPublishTriggerScript())
        {
            writer.writePropertyName("publishTriggerScript");
            writer.write(*obj.getPublishTriggerScript());
        }
        if (obj.getPublishDoneTriggerScript())
        {
            writer.writePropertyName("publishDoneTriggerScript");
            writer.write(*obj.getPublishDoneTriggerScript());
        }
        if (obj.getSetFirebaseTokenTriggerScript())
        {
            writer.writePropertyName("setFirebaseTokenTriggerScript");
            writer.write(*obj.getSetFirebaseTokenTriggerScript());
        }
        if (obj.getSetFirebaseTokenDoneTriggerScript())
        {
            writer.writePropertyName("setFirebaseTokenDoneTriggerScript");
            writer.write(*obj.getSetFirebaseTokenDoneTriggerScript());
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

    void write(detail::json::JsonWriter& writer, const Certificate& obj)
    {
        writer.writeObjectStart();
        if (obj.getCertificateId())
        {
            writer.writePropertyName("certificateId");
            writer.write(*obj.getCertificateId());
        }
        if (obj.getCertificate())
        {
            writer.writePropertyName("certificate");
            writer.write(*obj.getCertificate());
        }
        if (obj.getPrivateKey())
        {
            writer.writePropertyName("privateKey");
            writer.write(*obj.getPrivateKey());
        }
        if (obj.getPfx())
        {
            writer.writePropertyName("pfx");
            writer.write(*obj.getPfx());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const FirebaseToken& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getToken())
        {
            writer.writePropertyName("token");
            writer.write(*obj.getToken());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const PublishResponse& obj)
    {
        writer.writeObjectStart();
        if (obj.getType())
        {
            writer.writePropertyName("type");
            writer.write(*obj.getType());
        }
        if (obj.getSubject())
        {
            writer.writePropertyName("subject");
            writer.write(*obj.getSubject());
        }
        if (obj.getBody())
        {
            writer.writePropertyName("body");
            writer.write(*obj.getBody());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const MqttHost& obj)
    {
        writer.writeObjectStart();
        if (obj.getGameId())
        {
            writer.writePropertyName("gameId");
            writer.write(*obj.getGameId());
        }
        if (obj.getHost())
        {
            writer.writePropertyName("host");
            writer.write(*obj.getHost());
        }
        if (obj.getPort())
        {
            writer.writePropertyName("port");
            writer.write(*obj.getPort());
        }
        if (obj.getRootCertificate())
        {
            writer.writePropertyName("rootCertificate");
            writer.write(*obj.getRootCertificate());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const WebSocketHost& obj)
    {
        writer.writeObjectStart();
        if (obj.getGameId())
        {
            writer.writePropertyName("gameId");
            writer.write(*obj.getGameId());
        }
        if (obj.getEndpoint())
        {
            writer.writePropertyName("endpoint");
            writer.write(*obj.getEndpoint());
        }
        if (obj.getRootCertificate())
        {
            writer.writePropertyName("rootCertificate");
            writer.write(*obj.getRootCertificate());
        }
        writer.writeObjectEnd();
    }

    void write(detail::json::JsonWriter& writer, const Status& obj)
    {
        writer.writeObjectStart();
        if (obj.getUserId())
        {
            writer.writePropertyName("userId");
            writer.write(*obj.getUserId());
        }
        if (obj.getStatus())
        {
            writer.writePropertyName("status");
            writer.write(*obj.getStatus());
        }
        if (obj.getFcmToken())
        {
            writer.writePropertyName("fcmToken");
            writer.write(*obj.getFcmToken());
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
    Gs2InGamePushNotificationClient(IGs2Credential& credential) :
        AbstractGs2ClientBase(credential)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2InGamePushNotificationClient(IGs2Credential& credential, const Region& region) :
        AbstractGs2ClientBase(credential, region)
    {
    }

    /**
     * コンストラクタ。
     *
     * @param credential 認証情報
	 * @param region アクセス先リージョン
     */
    Gs2InGamePushNotificationClient(IGs2Credential& credential, const Char region[]) :
        AbstractGs2ClientBase(credential, region)
    {
    }


    /**
     * ゲームを新規作成します<br>
     * <br>
     * GS2-InGamePushNotification の使用を開始するには、まずはゲームを作成します。<br>
     * その後、ゲームに対してMQTTに接続するためのクライアント証明書の発行を依頼をします。<br>
     * 応答されたクライアント証明書と秘密鍵をデバイスに保存し、MQTTサーバへの接続に使用します。<br>
     * <br>
     * サーバサイドから ユーザに対してプッシュ通知を出すことが出来ます。<br>
     * その際にユーザがMQTTに接続している場合はMQTTを使用して通知を出します。<br>
     * もし、ユーザがMQTTに接続していない場合の挙動は ゲームの設定で変更できます。<br>
     * <br>
     * 1つ目は何もしない。<br>
     * 2つ目は指定したURLに通知する。<br>
     * 3つ目は Firebase Cloud Messaging を使用してモバイルプッシュ通知する。です。<br>
     * <br>
     * http/https を指定した場合、以下のフォーマットでURLにPOSTします。<br>
     * {<br>
     *   "_gs2_service": "gs2-in-game-push-notification",<br>
     *   "userId": ユーザID<br>
     *   "subject": サブジェクト,<br>
     *   "body": ボディ,<br>
     * }<br>
     * <br>
     * APIリクエスト以外に各デバイスがMQTTサーバに新しく接続する際に クオータを10消費する点にご注意ください。<br>
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
        if (request.getOfflineTransfer())
        {
            writer.writePropertyName("offlineTransfer");
            writer.write(*request.getOfflineTransfer());
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
        if (request.getNotificationFirebaseServerKey())
        {
            writer.writePropertyName("notificationFirebaseServerKey");
            writer.write(*request.getNotificationFirebaseServerKey());
        }
        if (request.getCreateCertificateTriggerScript())
        {
            writer.writePropertyName("createCertificateTriggerScript");
            writer.write(*request.getCreateCertificateTriggerScript());
        }
        if (request.getCreateCertificateDoneTriggerScript())
        {
            writer.writePropertyName("createCertificateDoneTriggerScript");
            writer.write(*request.getCreateCertificateDoneTriggerScript());
        }
        if (request.getDeleteCertificateTriggerScript())
        {
            writer.writePropertyName("deleteCertificateTriggerScript");
            writer.write(*request.getDeleteCertificateTriggerScript());
        }
        if (request.getDeleteCertificateDoneTriggerScript())
        {
            writer.writePropertyName("deleteCertificateDoneTriggerScript");
            writer.write(*request.getDeleteCertificateDoneTriggerScript());
        }
        if (request.getPublishTriggerScript())
        {
            writer.writePropertyName("publishTriggerScript");
            writer.write(*request.getPublishTriggerScript());
        }
        if (request.getPublishDoneTriggerScript())
        {
            writer.writePropertyName("publishDoneTriggerScript");
            writer.write(*request.getPublishDoneTriggerScript());
        }
        if (request.getSetFirebaseTokenTriggerScript())
        {
            writer.writePropertyName("setFirebaseTokenTriggerScript");
            writer.write(*request.getSetFirebaseTokenTriggerScript());
        }
        if (request.getSetFirebaseTokenDoneTriggerScript())
        {
            writer.writePropertyName("setFirebaseTokenDoneTriggerScript");
            writer.write(*request.getSetFirebaseTokenDoneTriggerScript());
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
     * ゲームの状態を取得します<br>
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
        if (request.getOfflineTransfer())
        {
            writer.writePropertyName("offlineTransfer");
            writer.write(*request.getOfflineTransfer());
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
        if (request.getNotificationFirebaseServerKey())
        {
            writer.writePropertyName("notificationFirebaseServerKey");
            writer.write(*request.getNotificationFirebaseServerKey());
        }
        if (request.getCreateCertificateTriggerScript())
        {
            writer.writePropertyName("createCertificateTriggerScript");
            writer.write(*request.getCreateCertificateTriggerScript());
        }
        if (request.getCreateCertificateDoneTriggerScript())
        {
            writer.writePropertyName("createCertificateDoneTriggerScript");
            writer.write(*request.getCreateCertificateDoneTriggerScript());
        }
        if (request.getDeleteCertificateTriggerScript())
        {
            writer.writePropertyName("deleteCertificateTriggerScript");
            writer.write(*request.getDeleteCertificateTriggerScript());
        }
        if (request.getDeleteCertificateDoneTriggerScript())
        {
            writer.writePropertyName("deleteCertificateDoneTriggerScript");
            writer.write(*request.getDeleteCertificateDoneTriggerScript());
        }
        if (request.getPublishTriggerScript())
        {
            writer.writePropertyName("publishTriggerScript");
            writer.write(*request.getPublishTriggerScript());
        }
        if (request.getPublishDoneTriggerScript())
        {
            writer.writePropertyName("publishDoneTriggerScript");
            writer.write(*request.getPublishDoneTriggerScript());
        }
        if (request.getSetFirebaseTokenTriggerScript())
        {
            writer.writePropertyName("setFirebaseTokenTriggerScript");
            writer.write(*request.getSetFirebaseTokenTriggerScript());
        }
        if (request.getSetFirebaseTokenDoneTriggerScript())
        {
            writer.writePropertyName("setFirebaseTokenDoneTriggerScript");
            writer.write(*request.getSetFirebaseTokenDoneTriggerScript());
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
     * MQTTサーバ情報を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getMqttHost(std::function<void(AsyncGetMqttHostResult&)> callback, GetMqttHostRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetMqttHostResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/server/mqtt");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * MQTT over Websocketサーバ情報を取得します<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void getWebSocketHost(std::function<void(AsyncGetWebSocketHostResult&)> callback, GetWebSocketHostRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<GetWebSocketHostResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::GET);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/server/webSocket");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * 通知を送信します。<br>
     * <br>
     * - 消費クオータ: 3<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void publish(std::function<void(AsyncPublishResult&)> callback, PublishRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<PublishResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/user/").append(detail::StringUtil::toStr(buffer, request.getUserId())).append("");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getSubject())
        {
            writer.writePropertyName("subject");
            writer.write(*request.getSubject());
        }
        if (request.getBody())
        {
            writer.writePropertyName("body");
            writer.write(*request.getBody());
        }
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
     * クライアント証明書を新規作成します<br>
     * <br>
     * MQTTサーバに接続するためのクライアント証明書の発行を行います。<br>
     * 1ユーザに対して発行できるクライアント証明書は同時に1つのみです。<br>
     * 異なるデバイスでMQTTサーバにアクセスする場合、クライアント証明書を削除して取り直すようにしてください。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void createCertificate(std::function<void(AsyncCreateCertificateResult&)> callback, CreateCertificateRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<CreateCertificateResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::POST);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/certificate");
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
     * クライアント証明書を削除します。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void deleteCertificate(std::function<void(AsyncDeleteCertificateResult&)> callback, DeleteCertificateRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<void>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::DELETE);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/certificate");
        }
        setUrl(httpRequest, url.c_str());
        setHeaders(httpRequest, request);
        httpRequest.setCallback(callback);
        send(httpRequest);
    }

    /**
     * ユーザステータスの一覧を取得します<br>
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
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/user");
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
     * Firebase のデバイストークンを設定します。<br>
     * <br>
     * - 消費クオータ: 10<br>
     * <br>
     *
     * @param callback コールバック関数
     * @param request リクエストパラメータ
     */
    void setFirebaseToken(std::function<void(AsyncSetFirebaseTokenResult&)> callback, SetFirebaseTokenRequest& request)
    {
        auto& httpRequest = *new detail::HttpRequest<SetFirebaseTokenResult>;
        httpRequest.setRequestType(::cocos2d::network::HttpRequest::Type::PUT);
        detail::StringVariable url(Gs2Constant::ENDPOINT_HOST);
        {
            char buffer[128];
            url.append("/game/").append(detail::StringUtil::toStr(buffer, request.getGameName())).append("/user");
        }
        auto& writer = detail::json::JsonWriter::getInstance();
        writer.reset();
        writer.writeObjectStart();
        if (request.getToken())
        {
            writer.writePropertyName("token");
            writer.write(*request.getToken());
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

#endif //GS2_INGAMEPUSHNOTIFICATION_GS2INGAMEPUSHNOTIFICATIONCLIENT_HPP_