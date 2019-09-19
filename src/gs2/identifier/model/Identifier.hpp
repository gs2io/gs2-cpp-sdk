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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            ownerId(data.ownerId),
            clientId(data.clientId),
            userName(data.userName),
            clientSecret(data.clientSecret),
            createdAt(data.createdAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "clientId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->clientId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "clientSecret") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->clientSecret.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Identifier() = default;
    Identifier(const Identifier& identifier) = default;
    Identifier(Identifier&& identifier) = default;
    ~Identifier() = default;

    Identifier& operator=(const Identifier& identifier) = default;
    Identifier& operator=(Identifier&& identifier) = default;

    Identifier deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Identifier);
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
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    Identifier& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
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
    void setClientId(StringHolder clientId)
    {
        ensureData().clientId.emplace(std::move(clientId));
    }

    /**
     * クライアントIDを設定
     *
     * @param clientId クライアントID
     */
    Identifier& withClientId(StringHolder clientId)
    {
        setClientId(std::move(clientId));
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
    void setUserName(StringHolder userName)
    {
        ensureData().userName.emplace(std::move(userName));
    }

    /**
     * ユーザー名を設定
     *
     * @param userName ユーザー名
     */
    Identifier& withUserName(StringHolder userName)
    {
        setUserName(std::move(userName));
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
    void setClientSecret(StringHolder clientSecret)
    {
        ensureData().clientSecret.emplace(std::move(clientSecret));
    }

    /**
     * クライアントシークレットを設定
     *
     * @param clientSecret クライアントシークレット
     */
    Identifier& withClientSecret(StringHolder clientSecret)
    {
        setClientSecret(std::move(clientSecret));
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
        if (!lhs.m_pData || !lhr.m_pData)
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