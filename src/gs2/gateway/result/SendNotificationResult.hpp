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

#ifndef GS2_GATEWAY_CONTROL_SENDNOTIFICATIONRESULT_HPP_
#define GS2_GATEWAY_CONTROL_SENDNOTIFICATIONRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace gateway
{

/**
 * 通知を送信 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class SendNotificationResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 通知に使用したプロトコル */
        optional<StringHolder> protocol;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            protocol(data.protocol)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            protocol(std::move(data.protocol))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "protocol") == 0) {
                if (jsonValue.IsString())
                {
                    this->protocol.emplace(jsonValue.GetString());
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
    SendNotificationResult() :
        m_pData(nullptr)
    {}

    SendNotificationResult(const SendNotificationResult& sendNotificationResult) :
        Gs2Object(sendNotificationResult),
        m_pData(sendNotificationResult.m_pData != nullptr ? new Data(*sendNotificationResult.m_pData) : nullptr)
    {}

    SendNotificationResult(SendNotificationResult&& sendNotificationResult) :
        Gs2Object(std::move(sendNotificationResult)),
        m_pData(sendNotificationResult.m_pData)
    {
        sendNotificationResult.m_pData = nullptr;
    }

    ~SendNotificationResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SendNotificationResult& operator=(const SendNotificationResult& sendNotificationResult)
    {
        Gs2Object::operator=(sendNotificationResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*sendNotificationResult.m_pData);

        return *this;
    }

    SendNotificationResult& operator=(SendNotificationResult&& sendNotificationResult)
    {
        Gs2Object::operator=(std::move(sendNotificationResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = sendNotificationResult.m_pData;
        sendNotificationResult.m_pData = nullptr;

        return *this;
    }

    const SendNotificationResult* operator->() const
    {
        return this;
    }

    SendNotificationResult* operator->()
    {
        return this;
    }
    /**
     * 通知に使用したプロトコルを取得
     *
     * @return 通知に使用したプロトコル
     */
    const optional<StringHolder>& getProtocol() const
    {
        return ensureData().protocol;
    }

    /**
     * 通知に使用したプロトコルを設定
     *
     * @param protocol 通知に使用したプロトコル
     */
    void setProtocol(const Char* protocol)
    {
        ensureData().protocol.emplace(protocol);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_GATEWAY_CONTROL_SENDNOTIFICATIONRESULT_HPP_