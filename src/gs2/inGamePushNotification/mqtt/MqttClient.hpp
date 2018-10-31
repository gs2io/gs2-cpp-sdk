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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MQTT_MQTTCLIENT_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MQTT_MQTTCLIENT_HPP_

#include "../common.hpp"
#include <gs2/core/Gs2Object.hpp>
#include "EventHandler.hpp"
#include "../model/WebSocketHost.hpp"
#include <gs2/core/util/StringHolder.hpp>
#include <network/WebSocket.h>

GS2_IN_GAME_PUSH_NOTIFICATION_START_OF_NAMESPACE

namespace detail2 {
class AbstractRequest;
}

class MqttClient : public Gs2Object
{
public:
    typedef cocos2d::network::WebSocket::ErrorCode Error;

    /**
     * セッションが確立したときに呼ばれるコールバックへのエンドポイントです。<br>
     * <br>
     * += 演算子に、ラムダ式を含む std::function<void()> 型のオブジェクトを渡すことでコールバックを追加できます。
     * <br>
     */
    RootEventHandler<ConnectEventHandler> onConnect;

    /**
     * メッセージを受信したときに呼ばれるコールバックへのエンドポイントです。<br>
     * <br>
     * += 演算子に、ラムダ式を含む std::function<void(const char[])> 型のオブジェクトを渡すことでコールバックを追加できます。
     * <br>
     */
    RootEventHandler<ReceiveEventHandler, const char[]> onReceive;

    /**
     * セッションが切断されたときに呼ばれるコールバックへのエンドポイントです。<br>
     * <br>
     * += 演算子に、ラムダ式を含む std::function<void()> 型のオブジェクトを渡すことでコールバックを追加できます。
     * <br>
     */
    RootEventHandler<CloseEventHandler> onClose;

    /**
     * エラーが発生したときに呼ばれるコールバックへのエンドポイントです。<br>
     * <br>
     * += 演算子に、ラムダ式を含む std::function<void(Error)> 型のオブジェクトを渡すことでコールバックを追加できます。
     * <br>
     */
    RootEventHandler<EventHandler<ErrorEventHandlerTraits, Error>, Error> onError;

private:
    static const int KeepAliveIntervalInSeconds = 180;

    cocos2d::network::WebSocket m_WebSocket;

    class Delegate : public cocos2d::network::WebSocket::Delegate {
    private:
        MqttClient& m_MqttClient;

    public:
        Delegate(MqttClient& mqttClient)
                : m_MqttClient(mqttClient)
        {
        }

        void onOpen(cocos2d::network::WebSocket* pWebSocket) GS2_OVERRIDE;
        void onMessage(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::Data& data) GS2_OVERRIDE;
        void onClose(cocos2d::network::WebSocket* pWebSocket) GS2_OVERRIDE;
        void onError(cocos2d::network::WebSocket* pWebSocket, const cocos2d::network::WebSocket::ErrorCode& errorCode) GS2_OVERRIDE;
    } m_Delegate;

    WebSocketHost m_WebSocketHost;
    StringHolder m_UserId;
    std::string m_RootCertificateFilePath;

    void send(const detail2::AbstractRequest& request);

    void writeRootCaCallback(bool isSuccessful);

public:
    MqttClient();

    ~MqttClient();

    /**
     * 接続を開始します<br>
     * <br>
     * Cocos2d-x の制約により、内部でルート CA 証明書をファイルへ書き出します。
     * rootCertificateFilePath を指定しなかった場合、このファイルは cocos2d::FileUtils::getWritablePath() が返すディレクトリに
     * "root-ca" という名前で保存されます。
     * <br>
     *
     * @param webSocketHost コールバック関数
     * @param userId リクエストパラメータ
     * @param rootCertificateFilePath リクエストパラメータ
     */
    void connectAsync(const WebSocketHost& webSocketHost, const char userId[], const char rootCertificateFilePath[] = nullptr);

    /**
     * 接続を開始します<br>
     * <br>
     * Cocos2d-x の制約により、内部でルート CA 証明書をファイルへ書き出します。
     * rootCertificateFilePath を指定しなかった場合、このファイルは cocos2d::FileUtils::getWritablePath() が返すディレクトリに
     * "root-ca" という名前で保存されます。
     * <br>
     *
     * @param webSocketHost コールバック関数
     * @param userId リクエストパラメータ
     * @param rootCertificateFilePath リクエストパラメータ
     */
    void connectAsync(WebSocketHost&& webSocketHost, const char userId[], const char rootCertificateFilePath[] = nullptr);

    /**
     * 切断を開始します<br>
     */
    void disconnectAsync();
};

GS2_IN_GAME_PUSH_NOTIFICATION_END_OF_NAMESPACE

#endif //GS2_INGAMEPUSHNOTIFICATION_MQTT_MQTTCLIENT_HPP_
