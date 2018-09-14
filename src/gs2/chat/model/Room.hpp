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

#ifndef GS2_CHAT_MODEL_ROOM_HPP_
#define GS2_CHAT_MODEL_ROOM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace chat {

/**
 * ルーム
 *
 * @author Game Server Services, Inc.
 *
 */
class Room : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ルームID */
        optional<StringHolder> roomId;
        /** 参加可能なユーザIDリスト */
        optional<List<StringHolder>> allowUserIds;
        /** メッセージの送受信にパスワードが必要か */
        optional<Bool> needPassword;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            roomId(data.roomId),
            allowUserIds(data.allowUserIds),
            needPassword(data.needPassword),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            roomId(std::move(data.roomId)),
            allowUserIds(std::move(data.allowUserIds)),
            needPassword(std::move(data.needPassword)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "roomId") == 0) {
                if (jsonValue.IsString())
                {
                    this->roomId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "allowUserIds") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->allowUserIds.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        auto valueStr = json->GetString();
                        StringHolder stringHolder(valueStr);
                        *this->allowUserIds += std::move(stringHolder);
                    }
                }
            }
            else if (std::strcmp(name, "needPassword") == 0) {
                if (jsonValue.IsBool())
                {
                    this->needPassword = jsonValue.GetBool();
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
    Room() :
        m_pData(nullptr)
    {}

    Room(const Room& room) :
        Gs2Object(room),
        m_pData(room.m_pData != nullptr ? new Data(*room.m_pData) : nullptr)
    {}

    Room(Room&& room) :
        Gs2Object(std::move(room)),
        m_pData(room.m_pData)
    {
        room.m_pData = nullptr;
    }

    ~Room()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Room& operator=(const Room& room)
    {
        Gs2Object::operator=(room);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*room.m_pData);

        return *this;
    }

    Room& operator=(Room&& room)
    {
        Gs2Object::operator=(std::move(room));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = room.m_pData;
        room.m_pData = nullptr;

        return *this;
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
     * ルームIDを取得
     *
     * @return ルームID
     */
    const optional<StringHolder>& getRoomId() const
    {
        return ensureData().roomId;
    }

    /**
     * ルームIDを設定
     *
     * @param roomId ルームID
     */
    void setRoomId(const Char* roomId)
    {
        ensureData().roomId.emplace(roomId);
    }

    /**
     * 参加可能なユーザIDリストを取得
     *
     * @return 参加可能なユーザIDリスト
     */
    const optional<List<StringHolder>>& getAllowUserIds() const
    {
        return ensureData().allowUserIds;
    }

    /**
     * 参加可能なユーザIDリストを設定
     *
     * @param allowUserIds 参加可能なユーザIDリスト
     */
    void setAllowUserIds(const List<StringHolder>& allowUserIds)
    {
        ensureData().allowUserIds.emplace(allowUserIds);
    }

    /**
     * メッセージの送受信にパスワードが必要かを取得
     *
     * @return メッセージの送受信にパスワードが必要か
     */
    const optional<Bool>& getNeedPassword() const
    {
        return ensureData().needPassword;
    }

    /**
     * メッセージの送受信にパスワードが必要かを設定
     *
     * @param needPassword メッセージの送受信にパスワードが必要か
     */
    void setNeedPassword(Bool needPassword)
    {
        ensureData().needPassword.emplace(needPassword);
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

#endif //GS2_CHAT_MODEL_ROOM_HPP_