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
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "AcquireAction.hpp"
#include <memory>

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
        /** 開封時に実行する入手アクション */
        optional<List<AcquireAction>> readAcquireActions;
        /** 作成日時 */
        optional<Int64> receivedAt;
        /** 最終更新日時 */
        optional<Int64> readAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Message() = default;
    Message(const Message& message) = default;
    Message(Message&& message) = default;
    ~Message() = default;

    Message& operator=(const Message& message) = default;
    Message& operator=(Message&& message) = default;

    Message deepCopy() const;

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
    void setMessageId(StringHolder messageId)
    {
        ensureData().messageId.emplace(std::move(messageId));
    }

    /**
     * メッセージを設定
     *
     * @param messageId メッセージ
     */
    Message& withMessageId(StringHolder messageId)
    {
        setMessageId(std::move(messageId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * メッセージIDを設定
     *
     * @param name メッセージID
     */
    Message& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Message& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メッセージの内容に相当するメタデータを設定
     *
     * @param metadata メッセージの内容に相当するメタデータ
     */
    Message& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
     * 開封時に実行する入手アクションを取得
     *
     * @return 開封時に実行する入手アクション
     */
    const optional<List<AcquireAction>>& getReadAcquireActions() const
    {
        return ensureData().readAcquireActions;
    }

    /**
     * 開封時に実行する入手アクションを設定
     *
     * @param readAcquireActions 開封時に実行する入手アクション
     */
    void setReadAcquireActions(List<AcquireAction> readAcquireActions)
    {
        ensureData().readAcquireActions.emplace(std::move(readAcquireActions));
    }

    /**
     * 開封時に実行する入手アクションを設定
     *
     * @param readAcquireActions 開封時に実行する入手アクション
     */
    Message& withReadAcquireActions(List<AcquireAction> readAcquireActions)
    {
        setReadAcquireActions(std::move(readAcquireActions));
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

bool operator!=(const Message& lhs, const Message& lhr);

inline bool operator==(const Message& lhs, const Message& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_INBOX_MODEL_MESSAGE_HPP_