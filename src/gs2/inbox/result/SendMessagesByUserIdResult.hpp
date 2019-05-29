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

#ifndef GS2_INBOX_CONTROL_SENDMESSAGESBYUSERIDRESULT_HPP_
#define GS2_INBOX_CONTROL_SENDMESSAGESBYUSERIDRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace inbox
{

/**
 * メッセージを複数まとめて新規作成 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class SendMessagesByUserIdResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 送信したメッセージのリスト */
        optional<List<Message>> sendItems;
        /** Noneのリスト */
        optional<List<NotSendMessage>> notSendItems;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            sendItems(data.sendItems),
            notSendItems(data.notSendItems)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            sendItems(std::move(data.sendItems)),
            notSendItems(std::move(data.notSendItems))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "sendItems") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->sendItems.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        Message item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->sendItems += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name, "notSendItems") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->notSendItems.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        NotSendMessage item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(json->GetObject()));
                        *this->notSendItems += std::move(item);
                    }
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
    SendMessagesByUserIdResult() :
        m_pData(nullptr)
    {}

    SendMessagesByUserIdResult(const SendMessagesByUserIdResult& sendMessagesByUserIdResult) :
        Gs2Object(sendMessagesByUserIdResult),
        m_pData(sendMessagesByUserIdResult.m_pData != nullptr ? new Data(*sendMessagesByUserIdResult.m_pData) : nullptr)
    {}

    SendMessagesByUserIdResult(SendMessagesByUserIdResult&& sendMessagesByUserIdResult) :
        Gs2Object(std::move(sendMessagesByUserIdResult)),
        m_pData(sendMessagesByUserIdResult.m_pData)
    {
        sendMessagesByUserIdResult.m_pData = nullptr;
    }

    ~SendMessagesByUserIdResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SendMessagesByUserIdResult& operator=(const SendMessagesByUserIdResult& sendMessagesByUserIdResult)
    {
        Gs2Object::operator=(sendMessagesByUserIdResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*sendMessagesByUserIdResult.m_pData);

        return *this;
    }

    SendMessagesByUserIdResult& operator=(SendMessagesByUserIdResult&& sendMessagesByUserIdResult)
    {
        Gs2Object::operator=(std::move(sendMessagesByUserIdResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = sendMessagesByUserIdResult.m_pData;
        sendMessagesByUserIdResult.m_pData = nullptr;

        return *this;
    }

    const SendMessagesByUserIdResult* operator->() const
    {
        return this;
    }

    SendMessagesByUserIdResult* operator->()
    {
        return this;
    }
    /**
     * 送信したメッセージのリストを取得
     *
     * @return 送信したメッセージのリスト
     */
    const optional<List<Message>>& getSendItems() const
    {
        return ensureData().sendItems;
    }

    /**
     * 送信したメッセージのリストを設定
     *
     * @param sendItems 送信したメッセージのリスト
     */
    void setSendItems(const List<Message>& sendItems)
    {
        ensureData().sendItems.emplace(sendItems);
    }

    /**
     * Noneのリストを取得
     *
     * @return Noneのリスト
     */
    const optional<List<NotSendMessage>>& getNotSendItems() const
    {
        return ensureData().notSendItems;
    }

    /**
     * Noneのリストを設定
     *
     * @param notSendItems Noneのリスト
     */
    void setNotSendItems(const List<NotSendMessage>& notSendItems)
    {
        ensureData().notSendItems.emplace(notSendItems);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INBOX_CONTROL_SENDMESSAGESBYUSERIDRESULT_HPP_