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

#ifndef GS2_INGAMEPUSHNOTIFICATION_CONTROL_GETWEBSOCKETHOSTRESULT_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_CONTROL_GETWEBSOCKETHOSTRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inGamePushNotification
{

/**
 * @author Game Server Services, Inc.
 */
class GetWebSocketHostResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** MQTT over WebSocketサーバ */
        optional<WebSocketHost> item;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
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
    GetWebSocketHostResult() :
        m_pData(nullptr)
    {}

    GetWebSocketHostResult(const GetWebSocketHostResult& getWebSocketHostResult) :
        Gs2Object(getWebSocketHostResult),
        m_pData(getWebSocketHostResult.m_pData != nullptr ? new Data(*getWebSocketHostResult.m_pData) : nullptr)
    {}

    GetWebSocketHostResult(GetWebSocketHostResult&& getWebSocketHostResult) :
        Gs2Object(std::move(getWebSocketHostResult)),
        m_pData(getWebSocketHostResult.m_pData)
    {
        getWebSocketHostResult.m_pData = nullptr;
    }

    ~GetWebSocketHostResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetWebSocketHostResult& operator=(const GetWebSocketHostResult& getWebSocketHostResult)
    {
        Gs2Object::operator=(getWebSocketHostResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getWebSocketHostResult.m_pData);

        return *this;
    }

    GetWebSocketHostResult& operator=(GetWebSocketHostResult&& getWebSocketHostResult)
    {
        Gs2Object::operator=(std::move(getWebSocketHostResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getWebSocketHostResult.m_pData;
        getWebSocketHostResult.m_pData = nullptr;

        return *this;
    }

    const GetWebSocketHostResult* operator->() const
    {
        return this;
    }

    GetWebSocketHostResult* operator->()
    {
        return this;
    }


    /**
     * MQTT over WebSocketサーバを取得
     *
     * @return MQTT over WebSocketサーバ
     */
    const optional<WebSocketHost>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * MQTT over WebSocketサーバを設定
     *
     * @param item MQTT over WebSocketサーバ
     */
    void setItem(const WebSocketHost& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INGAMEPUSHNOTIFICATION_CONTROL_GETWEBSOCKETHOSTRESULT_HPP_