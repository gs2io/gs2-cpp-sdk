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

#ifndef GS2_MATCHMAKING_MODEL_ROOMGATHERING_HPP_
#define GS2_MATCHMAKING_MODEL_ROOMGATHERING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace matchmaking {

/**
 * Roomマッチメイキング ギャザリング
 *
 * @author Game Server Services, Inc.
 *
 */
class RoomGathering : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ギャザリングID */
        optional<StringHolder> gatheringId;
        /** ギャザリングを作成したユーザID */
        optional<StringHolder> ownerUserId;
        /** ギャザリングメタデータ */
        optional<StringHolder> meta;
        /** 参加プレイヤー数 */
        optional<Int32> joinPlayer;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gatheringId(data.gatheringId),
            ownerUserId(data.ownerUserId),
            meta(data.meta),
            joinPlayer(data.joinPlayer),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gatheringId(std::move(data.gatheringId)),
            ownerUserId(std::move(data.ownerUserId)),
            meta(std::move(data.meta)),
            joinPlayer(std::move(data.joinPlayer)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gatheringId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gatheringId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerUserId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerUserId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "joinPlayer") == 0) {
                if (jsonValue.IsInt())
                {
                    this->joinPlayer = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    RoomGathering() :
        m_pData(nullptr)
    {}

    RoomGathering(const RoomGathering& roomGathering) :
        Gs2Object(roomGathering),
        m_pData(roomGathering.m_pData != nullptr ? new Data(*roomGathering.m_pData) : nullptr)
    {}

    RoomGathering(RoomGathering&& roomGathering) :
        Gs2Object(std::move(roomGathering)),
        m_pData(roomGathering.m_pData)
    {
        roomGathering.m_pData = nullptr;
    }

    ~RoomGathering()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RoomGathering& operator=(const RoomGathering& roomGathering)
    {
        Gs2Object::operator=(roomGathering);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*roomGathering.m_pData);

        return *this;
    }

    RoomGathering& operator=(RoomGathering&& roomGathering)
    {
        Gs2Object::operator=(std::move(roomGathering));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = roomGathering.m_pData;
        roomGathering.m_pData = nullptr;

        return *this;
    }

    const RoomGathering* operator->() const
    {
        return this;
    }

    RoomGathering* operator->()
    {
        return this;
    }


    /**
     * ギャザリングIDを取得
     *
     * @return ギャザリングID
     */
    const optional<StringHolder>& getGatheringId() const
    {
        return ensureData().gatheringId;
    }

    /**
     * ギャザリングIDを設定
     *
     * @param gatheringId ギャザリングID
     */
    void setGatheringId(const Char* gatheringId)
    {
        ensureData().gatheringId.emplace(gatheringId);
    }

    /**
     * ギャザリングを作成したユーザIDを取得
     *
     * @return ギャザリングを作成したユーザID
     */
    const optional<StringHolder>& getOwnerUserId() const
    {
        return ensureData().ownerUserId;
    }

    /**
     * ギャザリングを作成したユーザIDを設定
     *
     * @param ownerUserId ギャザリングを作成したユーザID
     */
    void setOwnerUserId(const Char* ownerUserId)
    {
        ensureData().ownerUserId.emplace(ownerUserId);
    }

    /**
     * ギャザリングメタデータを取得
     *
     * @return ギャザリングメタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * ギャザリングメタデータを設定
     *
     * @param meta ギャザリングメタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * 参加プレイヤー数を取得
     *
     * @return 参加プレイヤー数
     */
    const optional<Int32>& getJoinPlayer() const
    {
        return ensureData().joinPlayer;
    }

    /**
     * 参加プレイヤー数を設定
     *
     * @param joinPlayer 参加プレイヤー数
     */
    void setJoinPlayer(Int32 joinPlayer)
    {
        ensureData().joinPlayer.emplace(joinPlayer);
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

    /**
     * 更新日時(エポック秒)を取得
     *
     * @return 更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 更新日時(エポック秒)を設定
     *
     * @param updateAt 更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_MATCHMAKING_MODEL_ROOMGATHERING_HPP_