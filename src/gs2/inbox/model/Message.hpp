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

#ifndef GS2_INBOX_MODEL_MESSAGE_HPP_
#define GS2_INBOX_MODEL_MESSAGE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inbox {

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
        /** 受信ボックスGRN */
        optional<StringHolder> inboxId;
        /** 発言者ユーザID */
        optional<StringHolder> userId;
        /** メッセージ本文 */
        optional<StringHolder> message;
        /** 開封時に通知を出すか */
        optional<Bool> cooperation;
        /** 既読状態 */
        optional<Bool> read;
        /** 受信日時(エポック秒) */
        optional<Int32> date;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            messageId(data.messageId),
            inboxId(data.inboxId),
            userId(data.userId),
            message(data.message),
            cooperation(data.cooperation),
            read(data.read),
            date(data.date)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            messageId(std::move(data.messageId)),
            inboxId(std::move(data.inboxId)),
            userId(std::move(data.userId)),
            message(std::move(data.message)),
            cooperation(std::move(data.cooperation)),
            read(std::move(data.read)),
            date(std::move(data.date))
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
            else if (std::strcmp(name, "inboxId") == 0) {
                if (jsonValue.IsString())
                {
                    this->inboxId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "cooperation") == 0) {
                if (jsonValue.IsBool())
                {
                    this->cooperation = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "read") == 0) {
                if (jsonValue.IsBool())
                {
                    this->read = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "date") == 0) {
                if (jsonValue.IsInt())
                {
                    this->date = jsonValue.GetInt();
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
     * 受信ボックスGRNを取得
     *
     * @return 受信ボックスGRN
     */
    const optional<StringHolder>& getInboxId() const
    {
        return ensureData().inboxId;
    }

    /**
     * 受信ボックスGRNを設定
     *
     * @param inboxId 受信ボックスGRN
     */
    void setInboxId(const Char* inboxId)
    {
        ensureData().inboxId.emplace(inboxId);
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
     * メッセージ本文を取得
     *
     * @return メッセージ本文
     */
    const optional<StringHolder>& getMessage() const
    {
        return ensureData().message;
    }

    /**
     * メッセージ本文を設定
     *
     * @param message メッセージ本文
     */
    void setMessage(const Char* message)
    {
        ensureData().message.emplace(message);
    }

    /**
     * 開封時に通知を出すかを取得
     *
     * @return 開封時に通知を出すか
     */
    const optional<Bool>& getCooperation() const
    {
        return ensureData().cooperation;
    }

    /**
     * 開封時に通知を出すかを設定
     *
     * @param cooperation 開封時に通知を出すか
     */
    void setCooperation(Bool cooperation)
    {
        ensureData().cooperation.emplace(cooperation);
    }

    /**
     * 既読状態を取得
     *
     * @return 既読状態
     */
    const optional<Bool>& getRead() const
    {
        return ensureData().read;
    }

    /**
     * 既読状態を設定
     *
     * @param read 既読状態
     */
    void setRead(Bool read)
    {
        ensureData().read.emplace(read);
    }

    /**
     * 受信日時(エポック秒)を取得
     *
     * @return 受信日時(エポック秒)
     */
    const optional<Int32>& getDate() const
    {
        return ensureData().date;
    }

    /**
     * 受信日時(エポック秒)を設定
     *
     * @param date 受信日時(エポック秒)
     */
    void setDate(Int32 date)
    {
        ensureData().date.emplace(date);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INBOX_MODEL_MESSAGE_HPP_