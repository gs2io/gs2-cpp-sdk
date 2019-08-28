

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

#ifndef GS2_EZ_INBOX_MODEL_EZMESSAGE_HPP_
#define GS2_EZ_INBOX_MODEL_EZMESSAGE_HPP_

#include <gs2/inbox/model/Message.hpp>
#include "EzAcquireAction.hpp"


namespace gs2 { namespace ez { namespace inbox {

class EzMessage : public gs2::Gs2Object
{
private:
    /** メッセージ */
    gs2::optional<StringHolder> m_MessageId;
    /** メッセージID */
    gs2::optional<StringHolder> m_Name;
    /** メッセージの内容に相当するメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** 既読状態 */
    gs2::optional<Bool> m_IsRead;
    /** 開封時に実行する入手アクション */
    gs2::optional<List<EzAcquireAction>> m_ReadAcquireActions;
    /** 作成日時 */
    gs2::optional<Int64> m_ReceivedAt;
    /** 最終更新日時 */
    gs2::optional<Int64> m_ReadAt;

public:
    EzMessage() = default;

    EzMessage(gs2::inbox::Message message) :
        m_MessageId(message.getMessageId()),
        m_Name(message.getName()),
        m_Metadata(message.getMetadata()),
        m_IsRead(message.getIsRead() ? *message.getIsRead() : false),
        m_ReceivedAt(message.getReceivedAt() ? *message.getReceivedAt() : 0),
        m_ReadAt(message.getReadAt() ? *message.getReadAt() : 0)
    {
        m_ReadAcquireActions.emplace();
        if (message.getReadAcquireActions())
        {
            for (int i = 0; i < message.getReadAcquireActions()->getCount(); ++i)
            {
                *m_ReadAcquireActions += EzAcquireAction((*message.getReadAcquireActions())[i]);
            }
        }
    }

    gs2::inbox::Message ToModel() const
    {
        gs2::inbox::Message message;
        message.setMessageId(*m_MessageId);
        message.setName(*m_Name);
        message.setMetadata(*m_Metadata);
        message.setIsRead(*m_IsRead);
        {
            gs2::List<gs2::inbox::AcquireAction> list;
            auto& readAcquireActions = *m_ReadAcquireActions;
            for (int i = 0; i < readAcquireActions.getCount(); ++i)
            {
                list += readAcquireActions[i].ToModel();
            }
            message.setReadAcquireActions(list);
        }
        message.setReceivedAt(*m_ReceivedAt);
        message.setReadAt(*m_ReadAt);
        return message;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getMessageId() const
    {
        return *m_MessageId;
    }

    gs2::StringHolder& getMessageId()
    {
        return *m_MessageId;
    }

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    Bool getIsRead() const
    {
        return *m_IsRead;
    }

    const List<EzAcquireAction>& getReadAcquireActions() const
    {
        return *m_ReadAcquireActions;
    }

    List<EzAcquireAction>& getReadAcquireActions()
    {
        return *m_ReadAcquireActions;
    }

    Int64 getReceivedAt() const
    {
        return *m_ReceivedAt;
    }

    Int64 getReadAt() const
    {
        return *m_ReadAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setMessageId(Char* messageId)
    {
        m_MessageId.emplace(messageId);
    }

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setIsRead(Bool isRead)
    {
        m_IsRead = isRead;
    }

    void setReadAcquireActions(const List<EzAcquireAction>& readAcquireActions)
    {
        m_ReadAcquireActions = readAcquireActions;
    }

    void setReadAcquireActions(List<EzAcquireAction>&& readAcquireActions)
    {
        m_ReadAcquireActions = std::move(readAcquireActions);
    }

    void setReceivedAt(Int64 receivedAt)
    {
        m_ReceivedAt = receivedAt;
    }

    void setReadAt(Int64 readAt)
    {
        m_ReadAt = readAt;
    }

    EzMessage& withMessageId(Char* messageId)
    {
        setMessageId(messageId);
        return *this;
    }

    EzMessage& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzMessage& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzMessage& withIsRead(Bool isRead)
    {
        setIsRead(isRead);
        return *this;
    }

    EzMessage& withReadAcquireActions(const List<EzAcquireAction>& readAcquireActions)
    {
        setReadAcquireActions(readAcquireActions);
        return *this;
    }

    EzMessage& withReadAcquireActions(List<EzAcquireAction>&& readAcquireActions)
    {
        setReadAcquireActions(std::move(readAcquireActions));
        return *this;
    }

    EzMessage& withReceivedAt(Int64 receivedAt)
    {
        setReceivedAt(receivedAt);
        return *this;
    }

    EzMessage& withReadAt(Int64 readAt)
    {
        setReadAt(readAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_INBOX_EZMESSAGE_HPP_