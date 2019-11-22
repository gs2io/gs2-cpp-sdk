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

#ifndef GS2_FRIEND_MODEL_INBOX_HPP_
#define GS2_FRIEND_MODEL_INBOX_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace friend_ {

/**
 * フレンドリクエストの受信ボックス
 *
 * @author Game Server Services, Inc.
 *
 */
class Inbox : public Gs2Object
{
    friend bool operator!=(const Inbox& lhs, const Inbox& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** フレンドリクエストの受信ボックス */
        optional<StringHolder> inboxId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** フレンドリクエストを送ってきたユーザーIDリスト */
        optional<List<StringHolder>> fromUserIds;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

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
    Inbox() = default;
    Inbox(const Inbox& inbox) = default;
    Inbox(Inbox&& inbox) = default;
    ~Inbox() = default;

    Inbox& operator=(const Inbox& inbox) = default;
    Inbox& operator=(Inbox&& inbox) = default;

    Inbox deepCopy() const;

    const Inbox* operator->() const
    {
        return this;
    }

    Inbox* operator->()
    {
        return this;
    }
    /**
     * フレンドリクエストの受信ボックスを取得
     *
     * @return フレンドリクエストの受信ボックス
     */
    const optional<StringHolder>& getInboxId() const
    {
        return ensureData().inboxId;
    }

    /**
     * フレンドリクエストの受信ボックスを設定
     *
     * @param inboxId フレンドリクエストの受信ボックス
     */
    void setInboxId(StringHolder inboxId)
    {
        ensureData().inboxId.emplace(std::move(inboxId));
    }

    /**
     * フレンドリクエストの受信ボックスを設定
     *
     * @param inboxId フレンドリクエストの受信ボックス
     */
    Inbox& withInboxId(StringHolder inboxId)
    {
        setInboxId(std::move(inboxId));
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
    Inbox& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * フレンドリクエストを送ってきたユーザーIDリストを取得
     *
     * @return フレンドリクエストを送ってきたユーザーIDリスト
     */
    const optional<List<StringHolder>>& getFromUserIds() const
    {
        return ensureData().fromUserIds;
    }

    /**
     * フレンドリクエストを送ってきたユーザーIDリストを設定
     *
     * @param fromUserIds フレンドリクエストを送ってきたユーザーIDリスト
     */
    void setFromUserIds(List<StringHolder> fromUserIds)
    {
        ensureData().fromUserIds.emplace(std::move(fromUserIds));
    }

    /**
     * フレンドリクエストを送ってきたユーザーIDリストを設定
     *
     * @param fromUserIds フレンドリクエストを送ってきたユーザーIDリスト
     */
    Inbox& withFromUserIds(List<StringHolder> fromUserIds)
    {
        setFromUserIds(std::move(fromUserIds));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Inbox& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Inbox& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Inbox& lhs, const Inbox& lhr);

inline bool operator==(const Inbox& lhs, const Inbox& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_FRIEND_MODEL_INBOX_HPP_