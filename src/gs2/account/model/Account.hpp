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

#ifndef GS2_ACCOUNT_MODEL_ACCOUNT_HPP_
#define GS2_ACCOUNT_MODEL_ACCOUNT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace account {

/**
 * ゲームプレイヤーアカウント
 *
 * @author Game Server Services, Inc.
 *
 */
class Account : public Gs2Object
{
    friend bool operator!=(const Account& lhs, const Account& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゲームプレイヤーアカウント */
        optional<StringHolder> accountId;
        /** アカウントID */
        optional<StringHolder> userId;
        /** パスワード */
        optional<StringHolder> password;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            accountId(data.accountId),
            userId(data.userId),
            password(data.password),
            createdAt(data.createdAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            accountId(std::move(data.accountId)),
            userId(std::move(data.userId)),
            password(std::move(data.password)),
            createdAt(std::move(data.createdAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "accountId") == 0) {
                if (jsonValue.IsString())
                {
                    this->accountId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "password") == 0) {
                if (jsonValue.IsString())
                {
                    this->password.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
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
    Account() :
        m_pData(nullptr)
    {}

    Account(const Account& account) :
        Gs2Object(account),
        m_pData(account.m_pData != nullptr ? new Data(*account.m_pData) : nullptr)
    {}

    Account(Account&& account) :
        Gs2Object(std::move(account)),
        m_pData(account.m_pData)
    {
        account.m_pData = nullptr;
    }

    ~Account()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Account& operator=(const Account& account)
    {
        Gs2Object::operator=(account);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*account.m_pData);

        return *this;
    }

    Account& operator=(Account&& account)
    {
        Gs2Object::operator=(std::move(account));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = account.m_pData;
        account.m_pData = nullptr;

        return *this;
    }

    const Account* operator->() const
    {
        return this;
    }

    Account* operator->()
    {
        return this;
    }
    /**
     * ゲームプレイヤーアカウントを取得
     *
     * @return ゲームプレイヤーアカウント
     */
    const optional<StringHolder>& getAccountId() const
    {
        return ensureData().accountId;
    }

    /**
     * ゲームプレイヤーアカウントを設定
     *
     * @param accountId ゲームプレイヤーアカウント
     */
    void setAccountId(const Char* accountId)
    {
        ensureData().accountId.emplace(accountId);
    }

    /**
     * ゲームプレイヤーアカウントを設定
     *
     * @param accountId ゲームプレイヤーアカウント
     */
    Account& withAccountId(const Char* accountId)
    {
        setAccountId(accountId);
        return *this;
    }

    /**
     * アカウントIDを取得
     *
     * @return アカウントID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * アカウントIDを設定
     *
     * @param userId アカウントID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * アカウントIDを設定
     *
     * @param userId アカウントID
     */
    Account& withUserId(const Char* userId)
    {
        setUserId(userId);
        return *this;
    }

    /**
     * パスワードを取得
     *
     * @return パスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    void setPassword(const Char* password)
    {
        ensureData().password.emplace(password);
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    Account& withPassword(const Char* password)
    {
        setPassword(password);
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
    Account& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Account& lhs, const Account& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->accountId != lhr.m_pData->accountId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->password != lhr.m_pData->password)
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

inline bool operator==(const Account& lhs, const Account& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ACCOUNT_MODEL_ACCOUNT_HPP_