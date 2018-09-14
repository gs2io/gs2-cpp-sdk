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

#ifndef GS2_CHAT_MODEL_SUBSCRIBE_HPP_
#define GS2_CHAT_MODEL_SUBSCRIBE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace chat {

/**
 * 購読
 *
 * @author Game Server Services, Inc.
 *
 */
class Subscribe : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ルームID */
        optional<StringHolder> roomId;
        /** ユーザID */
        optional<StringHolder> userId;
        /** オフライン転送を使用するか */
        optional<Bool> enableOfflineTransfer;
        /** 通知音 */
        optional<StringHolder> offlineTransferSound;
        /** 購読日時(エポック秒) */
        optional<Int32> subscribeAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            roomId(data.roomId),
            userId(data.userId),
            enableOfflineTransfer(data.enableOfflineTransfer),
            offlineTransferSound(data.offlineTransferSound),
            subscribeAt(data.subscribeAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            roomId(std::move(data.roomId)),
            userId(std::move(data.userId)),
            enableOfflineTransfer(std::move(data.enableOfflineTransfer)),
            offlineTransferSound(std::move(data.offlineTransferSound)),
            subscribeAt(std::move(data.subscribeAt))
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
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "enableOfflineTransfer") == 0) {
                if (jsonValue.IsBool())
                {
                    this->enableOfflineTransfer = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "offlineTransferSound") == 0) {
                if (jsonValue.IsString())
                {
                    this->offlineTransferSound.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "subscribeAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->subscribeAt = jsonValue.GetInt();
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
    Subscribe() :
        m_pData(nullptr)
    {}

    Subscribe(const Subscribe& subscribe) :
        Gs2Object(subscribe),
        m_pData(subscribe.m_pData != nullptr ? new Data(*subscribe.m_pData) : nullptr)
    {}

    Subscribe(Subscribe&& subscribe) :
        Gs2Object(std::move(subscribe)),
        m_pData(subscribe.m_pData)
    {
        subscribe.m_pData = nullptr;
    }

    ~Subscribe()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Subscribe& operator=(const Subscribe& subscribe)
    {
        Gs2Object::operator=(subscribe);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*subscribe.m_pData);

        return *this;
    }

    Subscribe& operator=(Subscribe&& subscribe)
    {
        Gs2Object::operator=(std::move(subscribe));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = subscribe.m_pData;
        subscribe.m_pData = nullptr;

        return *this;
    }

    const Subscribe* operator->() const
    {
        return this;
    }

    Subscribe* operator->()
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
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * オフライン転送を使用するかを取得
     *
     * @return オフライン転送を使用するか
     */
    const optional<Bool>& getEnableOfflineTransfer() const
    {
        return ensureData().enableOfflineTransfer;
    }

    /**
     * オフライン転送を使用するかを設定
     *
     * @param enableOfflineTransfer オフライン転送を使用するか
     */
    void setEnableOfflineTransfer(Bool enableOfflineTransfer)
    {
        ensureData().enableOfflineTransfer.emplace(enableOfflineTransfer);
    }

    /**
     * 通知音を取得
     *
     * @return 通知音
     */
    const optional<StringHolder>& getOfflineTransferSound() const
    {
        return ensureData().offlineTransferSound;
    }

    /**
     * 通知音を設定
     *
     * @param offlineTransferSound 通知音
     */
    void setOfflineTransferSound(const Char* offlineTransferSound)
    {
        ensureData().offlineTransferSound.emplace(offlineTransferSound);
    }

    /**
     * 購読日時(エポック秒)を取得
     *
     * @return 購読日時(エポック秒)
     */
    const optional<Int32>& getSubscribeAt() const
    {
        return ensureData().subscribeAt;
    }

    /**
     * 購読日時(エポック秒)を設定
     *
     * @param subscribeAt 購読日時(エポック秒)
     */
    void setSubscribeAt(Int32 subscribeAt)
    {
        ensureData().subscribeAt.emplace(subscribeAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_CHAT_MODEL_SUBSCRIBE_HPP_