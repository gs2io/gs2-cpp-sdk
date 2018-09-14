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

#ifndef GS2_AUTH_MODEL_ACCOUNTTOKEN_HPP_
#define GS2_AUTH_MODEL_ACCOUNTTOKEN_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace auth {

/**
 * アカウントトークン
 *
 * @author Game Server Services, Inc.
 *
 */
class AccountToken : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** GS2-Accountゲーム名 */
        optional<StringHolder> gameName;
        /** ユーザID */
        optional<StringHolder> userId;
        /** 認証日時(エポック秒) */
        optional<Int32> timestamp;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            ownerId(data.ownerId),
            gameName(data.gameName),
            userId(data.userId),
            timestamp(data.timestamp)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            ownerId(std::move(data.ownerId)),
            gameName(std::move(data.gameName)),
            userId(std::move(data.userId)),
            timestamp(std::move(data.timestamp))
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
            else if (std::strcmp(name, "gameName") == 0) {
                if (jsonValue.IsString())
                {
                    this->gameName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "timestamp") == 0) {
                if (jsonValue.IsInt())
                {
                    this->timestamp = jsonValue.GetInt();
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
    AccountToken() :
        m_pData(nullptr)
    {}

    AccountToken(const AccountToken& accountToken) :
        Gs2Object(accountToken),
        m_pData(accountToken.m_pData != nullptr ? new Data(*accountToken.m_pData) : nullptr)
    {}

    AccountToken(AccountToken&& accountToken) :
        Gs2Object(std::move(accountToken)),
        m_pData(accountToken.m_pData)
    {
        accountToken.m_pData = nullptr;
    }

    ~AccountToken()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AccountToken& operator=(const AccountToken& accountToken)
    {
        Gs2Object::operator=(accountToken);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*accountToken.m_pData);

        return *this;
    }

    AccountToken& operator=(AccountToken&& accountToken)
    {
        Gs2Object::operator=(std::move(accountToken));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = accountToken.m_pData;
        accountToken.m_pData = nullptr;

        return *this;
    }

    const AccountToken* operator->() const
    {
        return this;
    }

    AccountToken* operator->()
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
     * GS2-Accountゲーム名を取得
     *
     * @return GS2-Accountゲーム名
     */
    const optional<StringHolder>& getGameName() const
    {
        return ensureData().gameName;
    }

    /**
     * GS2-Accountゲーム名を設定
     *
     * @param gameName GS2-Accountゲーム名
     */
    void setGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
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
     * 認証日時(エポック秒)を取得
     *
     * @return 認証日時(エポック秒)
     */
    const optional<Int32>& getTimestamp() const
    {
        return ensureData().timestamp;
    }

    /**
     * 認証日時(エポック秒)を設定
     *
     * @param timestamp 認証日時(エポック秒)
     */
    void setTimestamp(Int32 timestamp)
    {
        ensureData().timestamp.emplace(timestamp);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_AUTH_MODEL_ACCOUNTTOKEN_HPP_