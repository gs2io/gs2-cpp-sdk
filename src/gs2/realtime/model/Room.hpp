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

#ifndef GS2_REALTIME_MODEL_ROOM_HPP_
#define GS2_REALTIME_MODEL_ROOM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace realtime {

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
        /** IPアドレス */
        optional<StringHolder> ipAddress;
        /** 待受ポート */
        optional<Int32> port;
        /** 暗号鍵 */
        optional<StringHolder> encryptionKey;
        /** ルームの作成が終わったときに通知を受けるユーザIDリスト */
        optional<List<StringHolder>> notificationUserIds;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            roomId(data.roomId),
            name(data.name),
            ipAddress(data.ipAddress),
            port(data.port),
            encryptionKey(data.encryptionKey),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.notificationUserIds)
            {
                notificationUserIds = data.notificationUserIds->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "roomId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->roomId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ipAddress") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ipAddress.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "port") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->port = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "encryptionKey") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->encryptionKey.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "notificationUserIds") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->notificationUserIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->notificationUserIds += std::move(stringHolder);
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Room() = default;
    Room(const Room& room) = default;
    Room(Room&& room) = default;
    ~Room() = default;

    Room& operator=(const Room& room) = default;
    Room& operator=(Room&& room) = default;

    Room deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Room);
    }

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
     * IPアドレスを取得
     *
     * @return IPアドレス
     */
    const optional<StringHolder>& getIpAddress() const
    {
        return ensureData().ipAddress;
    }

    /**
     * IPアドレスを設定
     *
     * @param ipAddress IPアドレス
     */
    void setIpAddress(StringHolder ipAddress)
    {
        ensureData().ipAddress.emplace(std::move(ipAddress));
    }

    /**
     * IPアドレスを設定
     *
     * @param ipAddress IPアドレス
     */
    Room& withIpAddress(StringHolder ipAddress)
    {
        setIpAddress(std::move(ipAddress));
        return *this;
    }

    /**
     * 待受ポートを取得
     *
     * @return 待受ポート
     */
    const optional<Int32>& getPort() const
    {
        return ensureData().port;
    }

    /**
     * 待受ポートを設定
     *
     * @param port 待受ポート
     */
    void setPort(Int32 port)
    {
        ensureData().port.emplace(port);
    }

    /**
     * 待受ポートを設定
     *
     * @param port 待受ポート
     */
    Room& withPort(Int32 port)
    {
        setPort(port);
        return *this;
    }

    /**
     * 暗号鍵を取得
     *
     * @return 暗号鍵
     */
    const optional<StringHolder>& getEncryptionKey() const
    {
        return ensureData().encryptionKey;
    }

    /**
     * 暗号鍵を設定
     *
     * @param encryptionKey 暗号鍵
     */
    void setEncryptionKey(StringHolder encryptionKey)
    {
        ensureData().encryptionKey.emplace(std::move(encryptionKey));
    }

    /**
     * 暗号鍵を設定
     *
     * @param encryptionKey 暗号鍵
     */
    Room& withEncryptionKey(StringHolder encryptionKey)
    {
        setEncryptionKey(std::move(encryptionKey));
        return *this;
    }

    /**
     * ルームの作成が終わったときに通知を受けるユーザIDリストを取得
     *
     * @return ルームの作成が終わったときに通知を受けるユーザIDリスト
     */
    const optional<List<StringHolder>>& getNotificationUserIds() const
    {
        return ensureData().notificationUserIds;
    }

    /**
     * ルームの作成が終わったときに通知を受けるユーザIDリストを設定
     *
     * @param notificationUserIds ルームの作成が終わったときに通知を受けるユーザIDリスト
     */
    void setNotificationUserIds(List<StringHolder> notificationUserIds)
    {
        ensureData().notificationUserIds.emplace(std::move(notificationUserIds));
    }

    /**
     * ルームの作成が終わったときに通知を受けるユーザIDリストを設定
     *
     * @param notificationUserIds ルームの作成が終わったときに通知を受けるユーザIDリスト
     */
    Room& withNotificationUserIds(List<StringHolder> notificationUserIds)
    {
        setNotificationUserIds(std::move(notificationUserIds));
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

inline bool operator!=(const Room& lhs, const Room& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->roomId != lhr.m_pData->roomId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->ipAddress != lhr.m_pData->ipAddress)
        {
            return true;
        }
        if (lhs.m_pData->port != lhr.m_pData->port)
        {
            return true;
        }
        if (lhs.m_pData->encryptionKey != lhr.m_pData->encryptionKey)
        {
            return true;
        }
        if (lhs.m_pData->notificationUserIds != lhr.m_pData->notificationUserIds)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Room& lhs, const Room& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_REALTIME_MODEL_ROOM_HPP_