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

#ifndef GS2_IDENTIFIER_MODEL_IDENTIFIER_HPP_
#define GS2_IDENTIFIER_MODEL_IDENTIFIER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace identifier {

/**
 * クレデンシャル
 *
 * @author Game Server Services, Inc.
 *
 */
class Identifier : public Gs2Object
{
    friend bool operator!=(const Identifier& lhs, const Identifier& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** クライアントID */
        optional<StringHolder> clientId;
        /** ユーザー名 */
        optional<StringHolder> userName;
        /** クライアントシークレット */
        optional<StringHolder> clientSecret;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            ownerId(data.ownerId),
            clientId(data.clientId),
            userName(data.userName),
            clientSecret(data.clientSecret),
            createdAt(data.createdAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            ownerId(std::move(data.ownerId)),
            clientId(std::move(data.clientId)),
            userName(std::move(data.userName)),
            clientSecret(std::move(data.clientSecret)),
            createdAt(std::move(data.createdAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "clientId") == 0) {
                if (jsonValue.IsString())
                {
                    this->clientId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userName") == 0) {
                if (jsonValue.IsString())
                {
                    this->userName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "clientSecret") == 0) {
                if (jsonValue.IsString())
                {
                    this->clientSecret.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
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
    Identifier() :
        m_pData(nullptr)
    {}

    Identifier(const Identifier& identifier) :
        Gs2Object(identifier),
        m_pData(identifier.m_pData != nullptr ? new Data(*identifier.m_pData) : nullptr)
    {}

    Identifier(Identifier&& identifier) :
        Gs2Object(std::move(identifier)),
        m_pData(identifier.m_pData)
    {
        identifier.m_pData = nullptr;
    }

    ~Identifier()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Identifier& operator=(const Identifier& identifier)
    {
        Gs2Object::operator=(identifier);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*identifier.m_pData);

        return *this;
    }

    Identifier& operator=(Identifier&& identifier)
    {
        Gs2Object::operator=(std::move(identifier));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = identifier.m_pData;
        identifier.m_pData = nullptr;

        return *this;
    }

    const Identifier* operator->() const
    {
        return this;
    }

    Identifier* operator->()
    {
        return this;
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
    Identifier& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * クライアントIDを取得
     *
     * @return クライアントID
     */
    const optional<StringHolder>& getClientId() const
    {
        return ensureData().clientId;
    }

    /**
     * クライアントIDを設定
     *
     * @param clientId クライアントID
     */
    void setClientId(const Char* clientId)
    {
        ensureData().clientId.emplace(clientId);
    }

    /**
     * クライアントIDを設定
     *
     * @param clientId クライアントID
     */
    Identifier& withClientId(const Char* clientId)
    {
        setClientId(clientId);
        return *this;
    }

    /**
     * ユーザー名を取得
     *
     * @return ユーザー名
     */
    const optional<StringHolder>& getUserName() const
    {
        return ensureData().userName;
    }

    /**
     * ユーザー名を設定
     *
     * @param userName ユーザー名
     */
    void setUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
    }

    /**
     * ユーザー名を設定
     *
     * @param userName ユーザー名
     */
    Identifier& withUserName(const Char* userName)
    {
        setUserName(userName);
        return *this;
    }

    /**
     * クライアントシークレットを取得
     *
     * @return クライアントシークレット
     */
    const optional<StringHolder>& getClientSecret() const
    {
        return ensureData().clientSecret;
    }

    /**
     * クライアントシークレットを設定
     *
     * @param clientSecret クライアントシークレット
     */
    void setClientSecret(const Char* clientSecret)
    {
        ensureData().clientSecret.emplace(clientSecret);
    }

    /**
     * クライアントシークレットを設定
     *
     * @param clientSecret クライアントシークレット
     */
    Identifier& withClientSecret(const Char* clientSecret)
    {
        setClientSecret(clientSecret);
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
    Identifier& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Identifier& lhs, const Identifier& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->clientId != lhr.m_pData->clientId)
        {
            return true;
        }
        if (lhs.m_pData->userName != lhr.m_pData->userName)
        {
            return true;
        }
        if (lhs.m_pData->clientSecret != lhr.m_pData->clientSecret)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Identifier& lhs, const Identifier& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_IDENTIFIER_MODEL_IDENTIFIER_HPP_