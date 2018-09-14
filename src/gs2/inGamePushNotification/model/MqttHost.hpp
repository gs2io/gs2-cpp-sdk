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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MODEL_MQTTHOST_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MODEL_MQTTHOST_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inGamePushNotification {

/**
 * MQTTサーバ
 *
 * @author Game Server Services, Inc.
 *
 */
class MqttHost : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゲームGRN */
        optional<StringHolder> gameId;
        /** ホスト名 */
        optional<StringHolder> host;
        /** 待受ポート */
        optional<Int32> port;
        /** ルート証明書 */
        optional<StringHolder> rootCertificate;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gameId(data.gameId),
            host(data.host),
            port(data.port),
            rootCertificate(data.rootCertificate)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gameId(std::move(data.gameId)),
            host(std::move(data.host)),
            port(std::move(data.port)),
            rootCertificate(std::move(data.rootCertificate))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gameId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gameId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "host") == 0) {
                if (jsonValue.IsString())
                {
                    this->host.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "port") == 0) {
                if (jsonValue.IsInt())
                {
                    this->port = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "rootCertificate") == 0) {
                if (jsonValue.IsString())
                {
                    this->rootCertificate.emplace(jsonValue.GetString());
                }
            }
        }
    };
    
    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    MqttHost() :
        m_pData(nullptr)
    {}

    MqttHost(const MqttHost& mqttHost) :
        Gs2Object(mqttHost),
        m_pData(mqttHost.m_pData != nullptr ? new Data(*mqttHost.m_pData) : nullptr)
    {}

    MqttHost(MqttHost&& mqttHost) :
        Gs2Object(std::move(mqttHost)),
        m_pData(mqttHost.m_pData)
    {
        mqttHost.m_pData = nullptr;
    }

    ~MqttHost()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    MqttHost& operator=(const MqttHost& mqttHost)
    {
        Gs2Object::operator=(mqttHost);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*mqttHost.m_pData);

        return *this;
    }

    MqttHost& operator=(MqttHost&& mqttHost)
    {
        Gs2Object::operator=(std::move(mqttHost));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = mqttHost.m_pData;
        mqttHost.m_pData = nullptr;

        return *this;
    }

    const MqttHost* operator->() const
    {
        return this;
    }

    MqttHost* operator->()
    {
        return this;
    }


    /**
     * ゲームGRNを取得
     *
     * @return ゲームGRN
     */
    const optional<StringHolder>& getGameId() const
    {
        return ensureData().gameId;
    }

    /**
     * ゲームGRNを設定
     *
     * @param gameId ゲームGRN
     */
    void setGameId(const Char* gameId)
    {
        ensureData().gameId.emplace(gameId);
    }

    /**
     * ホスト名を取得
     *
     * @return ホスト名
     */
    const optional<StringHolder>& getHost() const
    {
        return ensureData().host;
    }

    /**
     * ホスト名を設定
     *
     * @param host ホスト名
     */
    void setHost(const Char* host)
    {
        ensureData().host.emplace(host);
    }

    /**
     * 待受ポートを取得
     *
     * @return 待受ポート
     */
    const optional<Int32>& getPort() const
    {
        return ensureData().port;
    }

    /**
     * 待受ポートを設定
     *
     * @param port 待受ポート
     */
    void setPort(Int32 port)
    {
        ensureData().port.emplace(port);
    }

    /**
     * ルート証明書を取得
     *
     * @return ルート証明書
     */
    const optional<StringHolder>& getRootCertificate() const
    {
        return ensureData().rootCertificate;
    }

    /**
     * ルート証明書を設定
     *
     * @param rootCertificate ルート証明書
     */
    void setRootCertificate(const Char* rootCertificate)
    {
        ensureData().rootCertificate.emplace(rootCertificate);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INGAMEPUSHNOTIFICATION_MODEL_MQTTHOST_HPP_