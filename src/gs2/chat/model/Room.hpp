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

#ifndef GS2_CHAT_MODEL_ROOM_HPP_
#define GS2_CHAT_MODEL_ROOM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace chat {

/**
 * ルーム
 *
 * @author Game Server Services, Inc.
 *
 */
class Room : public Gs2Object
{
    friend bool operator!=(const Room& lhs, const Room& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ルーム */
        optional<StringHolder> roomId;
        /** ルーム名 */
        optional<StringHolder> name;
        /** ルームを作成したユーザID */
        optional<StringHolder> userId;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** メッセージを投稿するために必要となるパスワード */
        optional<StringHolder> password;
        /** ルームに参加可能なユーザIDリスト */
        optional<List<StringHolder>> whiteListUserIds;
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
    Room() = default;
    Room(const Room& room) = default;
    Room(Room&& room) = default;
    ~Room() = default;

    Room& operator=(const Room& room) = default;
    Room& operator=(Room&& room) = default;

    Room deepCopy() const;

    const Room* operator->() const
    {
        return this;
    }

    Room* operator->()
    {
        return this;
    }
    /**
     * ルームを取得
     *
     * @return ルーム
     */
    const optional<StringHolder>& getRoomId() const
    {
        return ensureData().roomId;
    }

    /**
     * ルームを設定
     *
     * @param roomId ルーム
     */
    void setRoomId(StringHolder roomId)
    {
        ensureData().roomId.emplace(std::move(roomId));
    }

    /**
     * ルームを設定
     *
     * @param roomId ルーム
     */
    Room& withRoomId(StringHolder roomId)
    {
        setRoomId(std::move(roomId));
        return *this;
    }

    /**
     * ルーム名を取得
     *
     * @return ルーム名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ルーム名を設定
     *
     * @param name ルーム名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ルーム名を設定
     *
     * @param name ルーム名
     */
    Room& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * ルームを作成したユーザIDを取得
     *
     * @return ルームを作成したユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ルームを作成したユーザIDを設定
     *
     * @param userId ルームを作成したユーザID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ルームを作成したユーザIDを設定
     *
     * @param userId ルームを作成したユーザID
     */
    Room& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    Room& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * メッセージを投稿するために必要となるパスワードを取得
     *
     * @return メッセージを投稿するために必要となるパスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * メッセージを投稿するために必要となるパスワードを設定
     *
     * @param password メッセージを投稿するために必要となるパスワード
     */
    void setPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
    }

    /**
     * メッセージを投稿するために必要となるパスワードを設定
     *
     * @param password メッセージを投稿するために必要となるパスワード
     */
    Room& withPassword(StringHolder password)
    {
        setPassword(std::move(password));
        return *this;
    }

    /**
     * ルームに参加可能なユーザIDリストを取得
     *
     * @return ルームに参加可能なユーザIDリスト
     */
    const optional<List<StringHolder>>& getWhiteListUserIds() const
    {
        return ensureData().whiteListUserIds;
    }

    /**
     * ルームに参加可能なユーザIDリストを設定
     *
     * @param whiteListUserIds ルームに参加可能なユーザIDリスト
     */
    void setWhiteListUserIds(List<StringHolder> whiteListUserIds)
    {
        ensureData().whiteListUserIds.emplace(std::move(whiteListUserIds));
    }

    /**
     * ルームに参加可能なユーザIDリストを設定
     *
     * @param whiteListUserIds ルームに参加可能なユーザIDリスト
     */
    Room& withWhiteListUserIds(List<StringHolder> whiteListUserIds)
    {
        setWhiteListUserIds(std::move(whiteListUserIds));
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
    Room& withCreatedAt(Int64 createdAt)
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
    Room& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Room& lhs, const Room& lhr);

inline bool operator==(const Room& lhs, const Room& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_CHAT_MODEL_ROOM_HPP_