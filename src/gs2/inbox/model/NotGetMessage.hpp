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

#ifndef GS2_INBOX_MODEL_NOTGETMESSAGE_HPP_
#define GS2_INBOX_MODEL_NOTGETMESSAGE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inbox {

/**
 * None
 *
 * @author Game Server Services, Inc.
 *
 */
class NotGetMessage : public Gs2Object
{
    friend bool operator!=(const NotGetMessage& lhs, const NotGetMessage& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 取得できなかったメッセージのID */
        optional<StringHolder> messageName;
        /** 取得できなかった理由 */
        optional<StringHolder> reason;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            messageName(data.messageName),
            reason(data.reason)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            messageName(std::move(data.messageName)),
            reason(std::move(data.reason))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "messageName") == 0) {
                if (jsonValue.IsString())
                {
                    this->messageName.emplace(jsonValue.GetString());
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
    NotGetMessage() :
        m_pData(nullptr)
    {}

    NotGetMessage(const NotGetMessage& notGetMessage) :
        Gs2Object(notGetMessage),
        m_pData(notGetMessage.m_pData != nullptr ? new Data(*notGetMessage.m_pData) : nullptr)
    {}

    NotGetMessage(NotGetMessage&& notGetMessage) :
        Gs2Object(std::move(notGetMessage)),
        m_pData(notGetMessage.m_pData)
    {
        notGetMessage.m_pData = nullptr;
    }

    ~NotGetMessage()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    NotGetMessage& operator=(const NotGetMessage& notGetMessage)
    {
        Gs2Object::operator=(notGetMessage);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*notGetMessage.m_pData);

        return *this;
    }

    NotGetMessage& operator=(NotGetMessage&& notGetMessage)
    {
        Gs2Object::operator=(std::move(notGetMessage));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = notGetMessage.m_pData;
        notGetMessage.m_pData = nullptr;

        return *this;
    }

    const NotGetMessage* operator->() const
    {
        return this;
    }

    NotGetMessage* operator->()
    {
        return this;
    }
    /**
     * 取得できなかったメッセージのIDを取得
     *
     * @return 取得できなかったメッセージのID
     */
    const optional<StringHolder>& getMessageName() const
    {
        return ensureData().messageName;
    }

    /**
     * 取得できなかったメッセージのIDを設定
     *
     * @param messageName 取得できなかったメッセージのID
     */
    void setMessageName(const Char* messageName)
    {
        ensureData().messageName.emplace(messageName);
    }

    /**
     * 取得できなかったメッセージのIDを設定
     *
     * @param messageName 取得できなかったメッセージのID
     */
    NotGetMessage& withMessageName(const Char* messageName)
    {
        setMessageName(messageName);
        return *this;
    }

    /**
     * 取得できなかった理由を取得
     *
     * @return 取得できなかった理由
     */
    const optional<StringHolder>& getReason() const
    {
        return ensureData().reason;
    }

    /**
     * 取得できなかった理由を設定
     *
     * @param reason 取得できなかった理由
     */
    void setReason(const Char* reason)
    {
        ensureData().reason.emplace(reason);
    }

    /**
     * 取得できなかった理由を設定
     *
     * @param reason 取得できなかった理由
     */
    NotGetMessage& withReason(const Char* reason)
    {
        setReason(reason);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const NotGetMessage& lhs, const NotGetMessage& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->messageName != lhr.m_pData->messageName)
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

bool operator==(const NotGetMessage& lhs, const NotGetMessage& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INBOX_MODEL_NOTGETMESSAGE_HPP_