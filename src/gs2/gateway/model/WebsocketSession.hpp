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

#ifndef GS2_GATEWAY_MODEL_WEBSOCKETSESSION_HPP_
#define GS2_GATEWAY_MODEL_WEBSOCKETSESSION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace gateway {

/**
 * Websocketセッション
 *
 * @author Game Server Services, Inc.
 *
 */
class WebsocketSession : public Gs2Object
{
    friend bool operator!=(const WebsocketSession& lhs, const WebsocketSession& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** Websocketセッション のGRN */
        optional<StringHolder> websocketSessionId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** コネクションID */
        optional<StringHolder> connectionId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            websocketSessionId(data.websocketSessionId),
            ownerId(data.ownerId),
            connectionId(data.connectionId),
            userId(data.userId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            websocketSessionId(std::move(data.websocketSessionId)),
            ownerId(std::move(data.ownerId)),
            connectionId(std::move(data.connectionId)),
            userId(std::move(data.userId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "websocketSessionId") == 0) {
                if (jsonValue.IsString())
                {
                    this->websocketSessionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "connectionId") == 0) {
                if (jsonValue.IsString())
                {
                    this->connectionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    WebsocketSession() :
        m_pData(nullptr)
    {}

    WebsocketSession(const WebsocketSession& websocketSession) :
        Gs2Object(websocketSession),
        m_pData(websocketSession.m_pData != nullptr ? new Data(*websocketSession.m_pData) : nullptr)
    {}

    WebsocketSession(WebsocketSession&& websocketSession) :
        Gs2Object(std::move(websocketSession)),
        m_pData(websocketSession.m_pData)
    {
        websocketSession.m_pData = nullptr;
    }

    ~WebsocketSession()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WebsocketSession& operator=(const WebsocketSession& websocketSession)
    {
        Gs2Object::operator=(websocketSession);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*websocketSession.m_pData);

        return *this;
    }

    WebsocketSession& operator=(WebsocketSession&& websocketSession)
    {
        Gs2Object::operator=(std::move(websocketSession));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = websocketSession.m_pData;
        websocketSession.m_pData = nullptr;

        return *this;
    }

    const WebsocketSession* operator->() const
    {
        return this;
    }

    WebsocketSession* operator->()
    {
        return this;
    }
    /**
     * Websocketセッション のGRNを取得
     *
     * @return Websocketセッション のGRN
     */
    const optional<StringHolder>& getWebsocketSessionId() const
    {
        return ensureData().websocketSessionId;
    }

    /**
     * Websocketセッション のGRNを設定
     *
     * @param websocketSessionId Websocketセッション のGRN
     */
    void setWebsocketSessionId(const Char* websocketSessionId)
    {
        ensureData().websocketSessionId.emplace(websocketSessionId);
    }

    /**
     * Websocketセッション のGRNを設定
     *
     * @param websocketSessionId Websocketセッション のGRN
     */
    WebsocketSession& withWebsocketSessionId(const Char* websocketSessionId)
    {
        setWebsocketSessionId(websocketSessionId);
        return *this;
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    WebsocketSession& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * コネクションIDを取得
     *
     * @return コネクションID
     */
    const optional<StringHolder>& getConnectionId() const
    {
        return ensureData().connectionId;
    }

    /**
     * コネクションIDを設定
     *
     * @param connectionId コネクションID
     */
    void setConnectionId(const Char* connectionId)
    {
        ensureData().connectionId.emplace(connectionId);
    }

    /**
     * コネクションIDを設定
     *
     * @param connectionId コネクションID
     */
    WebsocketSession& withConnectionId(const Char* connectionId)
    {
        setConnectionId(connectionId);
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
    WebsocketSession& withUserId(const Char* userId)
    {
        setUserId(userId);
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
    WebsocketSession& withCreatedAt(Int64 createdAt)
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
    WebsocketSession& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const WebsocketSession& lhs, const WebsocketSession& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->websocketSessionId != lhr.m_pData->websocketSessionId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->connectionId != lhr.m_pData->connectionId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
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

bool operator==(const WebsocketSession& lhs, const WebsocketSession& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_GATEWAY_MODEL_WEBSOCKETSESSION_HPP_