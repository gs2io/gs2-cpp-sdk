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

#ifndef GS2_CHAT_CONTROL_SENDMESSAGENOAUTHRESULT_HPP_
#define GS2_CHAT_CONTROL_SENDMESSAGENOAUTHRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace chat
{

/**
 * @author Game Server Services, Inc.
 */
class SendMessageNoAuthResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージ */
        optional<Message> item;

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
    SendMessageNoAuthResult() :
        m_pData(nullptr)
    {}

    SendMessageNoAuthResult(const SendMessageNoAuthResult& sendMessageNoAuthResult) :
        Gs2Object(sendMessageNoAuthResult),
        m_pData(sendMessageNoAuthResult.m_pData != nullptr ? new Data(*sendMessageNoAuthResult.m_pData) : nullptr)
    {}

    SendMessageNoAuthResult(SendMessageNoAuthResult&& sendMessageNoAuthResult) :
        Gs2Object(std::move(sendMessageNoAuthResult)),
        m_pData(sendMessageNoAuthResult.m_pData)
    {
        sendMessageNoAuthResult.m_pData = nullptr;
    }

    ~SendMessageNoAuthResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SendMessageNoAuthResult& operator=(const SendMessageNoAuthResult& sendMessageNoAuthResult)
    {
        Gs2Object::operator=(sendMessageNoAuthResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*sendMessageNoAuthResult.m_pData);

        return *this;
    }

    SendMessageNoAuthResult& operator=(SendMessageNoAuthResult&& sendMessageNoAuthResult)
    {
        Gs2Object::operator=(std::move(sendMessageNoAuthResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = sendMessageNoAuthResult.m_pData;
        sendMessageNoAuthResult.m_pData = nullptr;

        return *this;
    }

    const SendMessageNoAuthResult* operator->() const
    {
        return this;
    }

    SendMessageNoAuthResult* operator->()
    {
        return this;
    }


    /**
     * メッセージを取得
     *
     * @return メッセージ
     */
    const optional<Message>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * メッセージを設定
     *
     * @param item メッセージ
     */
    void setItem(const Message& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CHAT_CONTROL_SENDMESSAGENOAUTHRESULT_HPP_