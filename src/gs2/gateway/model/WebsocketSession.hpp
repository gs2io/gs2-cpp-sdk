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
class WebSocketSession : public Gs2Object
{
    friend bool operator!=(const WebSocketSession& lhs, const WebSocketSession& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** コネクションID */
        optional<StringHolder> connectionId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
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
            connectionId(data.connectionId),
            ownerId(data.ownerId),
            namespaceName(data.namespaceName),
            userId(data.userId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            connectionId(std::move(data.connectionId)),
            ownerId(std::move(data.ownerId)),
            namespaceName(std::move(data.namespaceName)),
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
            if (std::strcmp(name, "connectionId") == 0) {
                if (jsonValue.IsString())
                {
                    this->connectionId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "namespaceName") == 0) {
                if (jsonValue.IsString())
                {
                    this->namespaceName.emplace(jsonValue.GetString());
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
    WebSocketSession() :
        m_pData(nullptr)
    {}

    WebSocketSession(const WebSocketSession& webSocketSession) :
        Gs2Object(webSocketSession),
        m_pData(webSocketSession.m_pData != nullptr ? new Data(*webSocketSession.m_pData) : nullptr)
    {}

    WebSocketSession(WebSocketSession&& webSocketSession) :
        Gs2Object(std::move(webSocketSession)),
        m_pData(webSocketSession.m_pData)
    {
        webSocketSession.m_pData = nullptr;
    }

    ~WebSocketSession()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    WebSocketSession& operator=(const WebSocketSession& webSocketSession)
    {
        Gs2Object::operator=(webSocketSession);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*webSocketSession.m_pData);

        return *this;
    }

    WebSocketSession& operator=(WebSocketSession&& webSocketSession)
    {
        Gs2Object::operator=(std::move(webSocketSession));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = webSocketSession.m_pData;
        webSocketSession.m_pData = nullptr;

        return *this;
    }

    const WebSocketSession* operator->() const
    {
        return this;
    }

    WebSocketSession* operator->()
    {
        return this;
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
    WebSocketSession& withConnectionId(const Char* connectionId)
    {
        setConnectionId(connectionId);
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
    WebSocketSession& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    WebSocketSession& withNamespaceName(const Char* namespaceName)
    {
        setNamespaceName(namespaceName);
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
    WebSocketSession& withUserId(const Char* userId)
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
    WebSocketSession& withCreatedAt(Int64 createdAt)
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
    WebSocketSession& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const WebSocketSession& lhs, const WebSocketSession& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->connectionId != lhr.m_pData->connectionId)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->namespaceName != lhr.m_pData->namespaceName)
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

inline bool operator==(const WebSocketSession& lhs, const WebSocketSession& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_GATEWAY_MODEL_WEBSOCKETSESSION_HPP_