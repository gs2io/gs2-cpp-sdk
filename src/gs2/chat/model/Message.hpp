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

#ifndef GS2_CHAT_MODEL_MESSAGE_HPP_
#define GS2_CHAT_MODEL_MESSAGE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace chat {

/**
 * メッセージ
 *
 * @author Game Server Services, Inc.
 *
 */
class Message : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージID */
        optional<StringHolder> messageId;
        /** 発言者ユーザID */
        optional<StringHolder> userId;
        /** メッセージテキスト */
        optional<StringHolder> message;
        /** メッセージメタデータ */
        optional<StringHolder> meta;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            messageId(data.messageId),
            userId(data.userId),
            message(data.message),
            meta(data.meta),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            messageId(std::move(data.messageId)),
            userId(std::move(data.userId)),
            message(std::move(data.message)),
            meta(std::move(data.meta)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "messageId") == 0) {
                if (jsonValue.IsString())
                {
                    this->messageId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "message") == 0) {
                if (jsonValue.IsString())
                {
                    this->message.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
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
    Message() :
        m_pData(nullptr)
    {}

    Message(const Message& message) :
        Gs2Object(message),
        m_pData(message.m_pData != nullptr ? new Data(*message.m_pData) : nullptr)
    {}

    Message(Message&& message) :
        Gs2Object(std::move(message)),
        m_pData(message.m_pData)
    {
        message.m_pData = nullptr;
    }

    ~Message()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Message& operator=(const Message& message)
    {
        Gs2Object::operator=(message);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*message.m_pData);

        return *this;
    }

    Message& operator=(Message&& message)
    {
        Gs2Object::operator=(std::move(message));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = message.m_pData;
        message.m_pData = nullptr;

        return *this;
    }

    const Message* operator->() const
    {
        return this;
    }

    Message* operator->()
    {
        return this;
    }


    /**
     * メッセージIDを取得
     *
     * @return メッセージID
     */
    const optional<StringHolder>& getMessageId() const
    {
        return ensureData().messageId;
    }

    /**
     * メッセージIDを設定
     *
     * @param messageId メッセージID
     */
    void setMessageId(const Char* messageId)
    {
        ensureData().messageId.emplace(messageId);
    }

    /**
     * 発言者ユーザIDを取得
     *
     * @return 発言者ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * 発言者ユーザIDを設定
     *
     * @param userId 発言者ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * メッセージテキストを取得
     *
     * @return メッセージテキスト
     */
    const optional<StringHolder>& getMessage() const
    {
        return ensureData().message;
    }

    /**
     * メッセージテキストを設定
     *
     * @param message メッセージテキスト
     */
    void setMessage(const Char* message)
    {
        ensureData().message.emplace(message);
    }

    /**
     * メッセージメタデータを取得
     *
     * @return メッセージメタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メッセージメタデータを設定
     *
     * @param meta メッセージメタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CHAT_MODEL_MESSAGE_HPP_