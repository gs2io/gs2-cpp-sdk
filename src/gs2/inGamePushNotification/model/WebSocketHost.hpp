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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MODEL_WEBSOCKETHOST_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MODEL_WEBSOCKETHOST_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inGamePushNotification {

/**
 * MQTT over WebSocketサーバ
 *
 * @author Game Server Services, Inc.
 *
 */
class WebSocketHost : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゲームGRN */
        optional<StringHolder> gameId;
        /** エンドポイント名 */
        optional<StringHolder> endpoint;
        /** ルート証明書 */
        optional<StringHolder> rootCertificate;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gameId(data.gameId),
            endpoint(data.endpoint),
            rootCertificate(data.rootCertificate)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gameId(std::move(data.gameId)),
            endpoint(std::move(data.endpoint)),
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
            else if (std::strcmp(name, "endpoint") == 0) {
                if (jsonValue.IsString())
                {
                    this->endpoint.emplace(jsonValue.GetString());
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
    WebSocketHost() :
        m_pData(nullptr)
    {}

    WebSocketHost(const WebSocketHost& webSocketHost) :
        Gs2Object(webSocketHost),
        m_pData(webSocketHost.m_pData != nullptr ? new Data(*webSocketHost.m_pData) : nullptr)
    {}

    WebSocketHost(WebSocketHost&& webSocketHost) :
        Gs2Object(std::move(webSocketHost)),
        m_pData(webSocketHost.m_pData)
    {
        webSocketHost.m_pData = nullptr;
    }

    ~WebSocketHost()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WebSocketHost& operator=(const WebSocketHost& webSocketHost)
    {
        Gs2Object::operator=(webSocketHost);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*webSocketHost.m_pData);

        return *this;
    }

    WebSocketHost& operator=(WebSocketHost&& webSocketHost)
    {
        Gs2Object::operator=(std::move(webSocketHost));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = webSocketHost.m_pData;
        webSocketHost.m_pData = nullptr;

        return *this;
    }

    const WebSocketHost* operator->() const
    {
        return this;
    }

    WebSocketHost* operator->()
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
     * エンドポイント名を取得
     *
     * @return エンドポイント名
     */
    const optional<StringHolder>& getEndpoint() const
    {
        return ensureData().endpoint;
    }

    /**
     * エンドポイント名を設定
     *
     * @param endpoint エンドポイント名
     */
    void setEndpoint(const Char* endpoint)
    {
        ensureData().endpoint.emplace(endpoint);
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

#endif //GS2_INGAMEPUSHNOTIFICATION_MODEL_WEBSOCKETHOST_HPP_