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
    friend bool operator!=(const Message& lhs, const Message& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** メッセージ */
        optional<StringHolder> messageId;
        /** メッセージID */
        optional<StringHolder> name;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** メッセージの内容に相当するメタデータ */
        optional<StringHolder> metadata;
        /** 既読状態 */
        optional<Bool> isRead;
        /** メッセージ開封時 に実行されるスクリプト のGRN */
        optional<StringHolder> readMessageTriggerScriptId;
        /** メッセージ開封時 に実行されるスクリプト に指定する引数 */
        optional<StringHolder> readMessageTriggerScriptArgs;
        /** 作成日時 */
        optional<Int64> receivedAt;
        /** 最終更新日時 */
        optional<Int64> readAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            messageId(data.messageId),
            name(data.name),
            userId(data.userId),
            metadata(data.metadata),
            isRead(data.isRead),
            readMessageTriggerScriptId(data.readMessageTriggerScriptId),
            readMessageTriggerScriptArgs(data.readMessageTriggerScriptArgs),
            receivedAt(data.receivedAt),
            readAt(data.readAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            messageId(std::move(data.messageId)),
            name(std::move(data.name)),
            userId(std::move(data.userId)),
            metadata(std::move(data.metadata)),
            isRead(std::move(data.isRead)),
            readMessageTriggerScriptId(std::move(data.readMessageTriggerScriptId)),
            readMessageTriggerScriptArgs(std::move(data.readMessageTriggerScriptArgs)),
            receivedAt(std::move(data.receivedAt)),
            readAt(std::move(data.readAt))
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
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "isRead") == 0) {
                if (jsonValue.IsBool())
                {
                    this->isRead = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "readMessageTriggerScriptId") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageTriggerScriptId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "readMessageTriggerScriptArgs") == 0) {
                if (jsonValue.IsString())
                {
                    this->readMessageTriggerScriptArgs.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "receivedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->receivedAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "readAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->readAt = jsonValue.GetInt64();
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
     * メッセージを取得
     *
     * @return メッセージ
     */
    const optional<StringHolder>& getMessageId() const
    {
        return ensureData().messageId;
    }

    /**
     * メッセージを設定
     *
     * @param messageId メッセージ
     */
    void setMessageId(const Char* messageId)
    {
        ensureData().messageId.emplace(messageId);
    }

    /**
     * メッセージを設定
     *
     * @param messageId メッセージ
     */
    Message& withMessageId(const Char* messageId)
    {
        setMessageId(messageId);
        return *this;
    }

    /**
     * メッセージIDを取得
     *
     * @return メッセージID
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * メッセージIDを設定
     *
     * @param name メッセージID
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * メッセージIDを設定
     *
     * @param name メッセージID
     */
    Message& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Message& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * メッセージの内容に相当するメタデータを取得
     *
     * @return メッセージの内容に相当するメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メッセージの内容に相当するメタデータを設定
     *
     * @param metadata メッセージの内容に相当するメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * メッセージの内容に相当するメタデータを設定
     *
     * @param metadata メッセージの内容に相当するメタデータ
     */
    Message& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * 既読状態を取得
     *
     * @return 既読状態
     */
    const optional<Bool>& getIsRead() const
    {
        return ensureData().isRead;
    }

    /**
     * 既読状態を設定
     *
     * @param isRead 既読状態
     */
    void setIsRead(Bool isRead)
    {
        ensureData().isRead.emplace(isRead);
    }

    /**
     * 既読状態を設定
     *
     * @param isRead 既読状態
     */
    Message& withIsRead(Bool isRead)
    {
        setIsRead(isRead);
        return *this;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを取得
     *
     * @return メッセージ開封時 に実行されるスクリプト のGRN
     */
    const optional<StringHolder>& getReadMessageTriggerScriptId() const
    {
        return ensureData().readMessageTriggerScriptId;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageTriggerScriptId メッセージ開封時 に実行されるスクリプト のGRN
     */
    void setReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
    {
        ensureData().readMessageTriggerScriptId.emplace(readMessageTriggerScriptId);
    }

    /**
     * メッセージ開封時 に実行されるスクリプト のGRNを設定
     *
     * @param readMessageTriggerScriptId メッセージ開封時 に実行されるスクリプト のGRN
     */
    Message& withReadMessageTriggerScriptId(const Char* readMessageTriggerScriptId)
    {
        setReadMessageTriggerScriptId(readMessageTriggerScriptId);
        return *this;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト に指定する引数を取得
     *
     * @return メッセージ開封時 に実行されるスクリプト に指定する引数
     */
    const optional<StringHolder>& getReadMessageTriggerScriptArgs() const
    {
        return ensureData().readMessageTriggerScriptArgs;
    }

    /**
     * メッセージ開封時 に実行されるスクリプト に指定する引数を設定
     *
     * @param readMessageTriggerScriptArgs メッセージ開封時 に実行されるスクリプト に指定する引数
     */
    void setReadMessageTriggerScriptArgs(const Char* readMessageTriggerScriptArgs)
    {
        ensureData().readMessageTriggerScriptArgs.emplace(readMessageTriggerScriptArgs);
    }

    /**
     * メッセージ開封時 に実行されるスクリプト に指定する引数を設定
     *
     * @param readMessageTriggerScriptArgs メッセージ開封時 に実行されるスクリプト に指定する引数
     */
    Message& withReadMessageTriggerScriptArgs(const Char* readMessageTriggerScriptArgs)
    {
        setReadMessageTriggerScriptArgs(readMessageTriggerScriptArgs);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getReceivedAt() const
    {
        return ensureData().receivedAt;
    }

    /**
     * 作成日時を設定
     *
     * @param receivedAt 作成日時
     */
    void setReceivedAt(Int64 receivedAt)
    {
        ensureData().receivedAt.emplace(receivedAt);
    }

    /**
     * 作成日時を設定
     *
     * @param receivedAt 作成日時
     */
    Message& withReceivedAt(Int64 receivedAt)
    {
        setReceivedAt(receivedAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getReadAt() const
    {
        return ensureData().readAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param readAt 最終更新日時
     */
    void setReadAt(Int64 readAt)
    {
        ensureData().readAt.emplace(readAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param readAt 最終更新日時
     */
    Message& withReadAt(Int64 readAt)
    {
        setReadAt(readAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Message& lhs, const Message& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->messageId != lhr.m_pData->messageId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->isRead != lhr.m_pData->isRead)
        {
            return true;
        }
        if (lhs.m_pData->readMessageTriggerScriptId != lhr.m_pData->readMessageTriggerScriptId)
        {
            return true;
        }
        if (lhs.m_pData->readMessageTriggerScriptArgs != lhr.m_pData->readMessageTriggerScriptArgs)
        {
            return true;
        }
        if (lhs.m_pData->receivedAt != lhr.m_pData->receivedAt)
        {
            return true;
        }
        if (lhs.m_pData->readAt != lhr.m_pData->readAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Message& lhs, const Message& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INBOX_MODEL_MESSAGE_HPP_