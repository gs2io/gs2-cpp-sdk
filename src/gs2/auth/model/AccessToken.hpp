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

#ifndef GS2_AUTH_MODEL_ACCESSTOKEN_HPP_
#define GS2_AUTH_MODEL_ACCESSTOKEN_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace auth {

/**
 * アクセストークン
 *
 * @author Game Server Services, Inc.
 *
 */
class AccessToken : public Gs2Object
{
    friend bool operator!=(const AccessToken& lhs, const AccessToken& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** アクセストークン */
        optional<StringHolder> token;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 有効期限 */
        optional<Int64> expire;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            ownerId(data.ownerId),
            token(data.token),
            userId(data.userId),
            expire(data.expire)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            ownerId(std::move(data.ownerId)),
            token(std::move(data.token)),
            userId(std::move(data.userId)),
            expire(std::move(data.expire))
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
            else if (std::strcmp(name, "token") == 0) {
                if (jsonValue.IsString())
                {
                    this->token.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "expire") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->expire = jsonValue.GetInt64();
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
    AccessToken() :
        m_pData(nullptr)
    {}

    AccessToken(const AccessToken& accessToken) :
        Gs2Object(accessToken),
        m_pData(accessToken.m_pData != nullptr ? new Data(*accessToken.m_pData) : nullptr)
    {}

    AccessToken(AccessToken&& accessToken) :
        Gs2Object(std::move(accessToken)),
        m_pData(accessToken.m_pData)
    {
        accessToken.m_pData = nullptr;
    }

    ~AccessToken()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AccessToken& operator=(const AccessToken& accessToken)
    {
        Gs2Object::operator=(accessToken);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*accessToken.m_pData);

        return *this;
    }

    AccessToken& operator=(AccessToken&& accessToken)
    {
        Gs2Object::operator=(std::move(accessToken));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = accessToken.m_pData;
        accessToken.m_pData = nullptr;

        return *this;
    }

    const AccessToken* operator->() const
    {
        return this;
    }

    AccessToken* operator->()
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
    AccessToken& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * アクセストークンを取得
     *
     * @return アクセストークン
     */
    const optional<StringHolder>& getToken() const
    {
        return ensureData().token;
    }

    /**
     * アクセストークンを設定
     *
     * @param token アクセストークン
     */
    void setToken(const Char* token)
    {
        ensureData().token.emplace(token);
    }

    /**
     * アクセストークンを設定
     *
     * @param token アクセストークン
     */
    AccessToken& withToken(const Char* token)
    {
        setToken(token);
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
    AccessToken& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * 有効期限を取得
     *
     * @return 有効期限
     */
    const optional<Int64>& getExpire() const
    {
        return ensureData().expire;
    }

    /**
     * 有効期限を設定
     *
     * @param expire 有効期限
     */
    void setExpire(Int64 expire)
    {
        ensureData().expire.emplace(expire);
    }

    /**
     * 有効期限を設定
     *
     * @param expire 有効期限
     */
    AccessToken& withExpire(Int64 expire)
    {
        setExpire(expire);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const AccessToken& lhs, const AccessToken& lhr)
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
        if (lhs.m_pData->token != lhr.m_pData->token)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->expire != lhr.m_pData->expire)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const AccessToken& lhs, const AccessToken& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_AUTH_MODEL_ACCESSTOKEN_HPP_