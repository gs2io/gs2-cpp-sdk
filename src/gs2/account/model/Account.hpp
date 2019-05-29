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
 * アカウント
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
        /** アカウント のGRN */
        optional<StringHolder> accountId;
        /** アカウントID */
        optional<StringHolder> userId;
        /** パスワード */
        optional<StringHolder> password;
        /** 作成日時 */
        optional<Int64> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            accountId(data.accountId),
            userId(data.userId),
            password(data.password),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            accountId(std::move(data.accountId)),
            userId(std::move(data.userId)),
            password(std::move(data.password)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "accountId") == 0) {
                if (jsonValue.IsString())
                {
                    this->accountId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "password") == 0) {
                if (jsonValue.IsString())
                {
                    this->password.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
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
     * アカウント のGRNを取得
     *
     * @return アカウント のGRN
     */
    const optional<StringHolder>& getAccountId() const
    {
        return ensureData().accountId;
    }

    /**
     * アカウント のGRNを設定
     *
     * @param accountId アカウント のGRN
     */
    void setAccountId(const Char* accountId)
    {
        ensureData().accountId.emplace(accountId);
    }

    /**
     * アカウント のGRNを設定
     *
     * @param accountId アカウント のGRN
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
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    Account& withCreateAt(Int64 createAt)
    {
        setCreateAt(createAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Account& lhs, const Account& lhr)
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
        if (lhs.m_pData->createAt != lhr.m_pData->createAt)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const Account& lhs, const Account& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ACCOUNT_MODEL_ACCOUNT_HPP_