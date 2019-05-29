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

#ifndef GS2_INBOX_MODEL_NOTSENDMESSAGE_HPP_
#define GS2_INBOX_MODEL_NOTSENDMESSAGE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "Body.hpp"
#include <cstring>

namespace gs2 { namespace inbox {

/**
 * None
 *
 * @author Game Server Services, Inc.
 *
 */
class NotSendMessage : public Gs2Object
{
    friend bool operator!=(const NotSendMessage& lhs, const NotSendMessage& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 送信できなかったメッセージのボディ */
        optional<Body> body;
        /** 送信できなかった理由 */
        optional<StringHolder> reason;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            body(data.body),
            reason(data.reason)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            body(std::move(data.body)),
            reason(std::move(data.reason))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "body") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->body.emplace();
                    detail::json::JsonParser::parse(&this->body->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "reason") == 0) {
                if (jsonValue.IsString())
                {
                    this->reason.emplace(jsonValue.GetString());
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
    NotSendMessage() :
        m_pData(nullptr)
    {}

    NotSendMessage(const NotSendMessage& notSendMessage) :
        Gs2Object(notSendMessage),
        m_pData(notSendMessage.m_pData != nullptr ? new Data(*notSendMessage.m_pData) : nullptr)
    {}

    NotSendMessage(NotSendMessage&& notSendMessage) :
        Gs2Object(std::move(notSendMessage)),
        m_pData(notSendMessage.m_pData)
    {
        notSendMessage.m_pData = nullptr;
    }

    ~NotSendMessage()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    NotSendMessage& operator=(const NotSendMessage& notSendMessage)
    {
        Gs2Object::operator=(notSendMessage);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*notSendMessage.m_pData);

        return *this;
    }

    NotSendMessage& operator=(NotSendMessage&& notSendMessage)
    {
        Gs2Object::operator=(std::move(notSendMessage));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = notSendMessage.m_pData;
        notSendMessage.m_pData = nullptr;

        return *this;
    }

    const NotSendMessage* operator->() const
    {
        return this;
    }

    NotSendMessage* operator->()
    {
        return this;
    }
    /**
     * 送信できなかったメッセージのボディを取得
     *
     * @return 送信できなかったメッセージのボディ
     */
    const optional<Body>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * 送信できなかったメッセージのボディを設定
     *
     * @param body 送信できなかったメッセージのボディ
     */
    void setBody(const Body& body)
    {
        ensureData().body.emplace(body);
    }

    /**
     * 送信できなかったメッセージのボディを設定
     *
     * @param body 送信できなかったメッセージのボディ
     */
    NotSendMessage& withBody(const Body& body)
    {
        setBody(body);
        return *this;
    }

    /**
     * 送信できなかった理由を取得
     *
     * @return 送信できなかった理由
     */
    const optional<StringHolder>& getReason() const
    {
        return ensureData().reason;
    }

    /**
     * 送信できなかった理由を設定
     *
     * @param reason 送信できなかった理由
     */
    void setReason(const Char* reason)
    {
        ensureData().reason.emplace(reason);
    }

    /**
     * 送信できなかった理由を設定
     *
     * @param reason 送信できなかった理由
     */
    NotSendMessage& withReason(const Char* reason)
    {
        setReason(reason);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const NotSendMessage& lhs, const NotSendMessage& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->body != lhr.m_pData->body)
        {
            return true;
        }
        if (lhs.m_pData->reason != lhr.m_pData->reason)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const NotSendMessage& lhs, const NotSendMessage& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INBOX_MODEL_NOTSENDMESSAGE_HPP_