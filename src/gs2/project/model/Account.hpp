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

#ifndef GS2_PROJECT_MODEL_ACCOUNT_HPP_
#define GS2_PROJECT_MODEL_ACCOUNT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace project {

/**
 * GS2アカウント
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
        /** GS2アカウント */
        optional<StringHolder> accountId;
        /** None */
        optional<StringHolder> ownerId;
        /** GS2アカウントの名前 */
        optional<StringHolder> name;
        /** メールアドレス */
        optional<StringHolder> email;
        /** フルネーム */
        optional<StringHolder> fullName;
        /** 会社名 */
        optional<StringHolder> companyName;
        /** パスワード */
        optional<StringHolder> password;
        /** ステータス */
        optional<StringHolder> status;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            accountId(data.accountId),
            ownerId(data.ownerId),
            name(data.name),
            email(data.email),
            fullName(data.fullName),
            companyName(data.companyName),
            password(data.password),
            status(data.status),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            accountId(std::move(data.accountId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            email(std::move(data.email)),
            fullName(std::move(data.fullName)),
            companyName(std::move(data.companyName)),
            password(std::move(data.password)),
            status(std::move(data.status)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
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
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "email") == 0) {
                if (jsonValue.IsString())
                {
                    this->email.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "fullName") == 0) {
                if (jsonValue.IsString())
                {
                    this->fullName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "companyName") == 0) {
                if (jsonValue.IsString())
                {
                    this->companyName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "password") == 0) {
                if (jsonValue.IsString())
                {
                    this->password.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "status") == 0) {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
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
     * GS2アカウントを取得
     *
     * @return GS2アカウント
     */
    const optional<StringHolder>& getAccountId() const
    {
        return ensureData().accountId;
    }

    /**
     * GS2アカウントを設定
     *
     * @param accountId GS2アカウント
     */
    void setAccountId(const Char* accountId)
    {
        ensureData().accountId.emplace(accountId);
    }

    /**
     * GS2アカウントを設定
     *
     * @param accountId GS2アカウント
     */
    Account& withAccountId(const Char* accountId)
    {
        setAccountId(accountId);
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * Noneを設定
     *
     * @param ownerId None
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * Noneを設定
     *
     * @param ownerId None
     */
    Account& withOwnerId(const Char* ownerId)
    {
        setOwnerId(ownerId);
        return *this;
    }

    /**
     * GS2アカウントの名前を取得
     *
     * @return GS2アカウントの名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param name GS2アカウントの名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param name GS2アカウントの名前
     */
    Account& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * メールアドレスを取得
     *
     * @return メールアドレス
     */
    const optional<StringHolder>& getEmail() const
    {
        return ensureData().email;
    }

    /**
     * メールアドレスを設定
     *
     * @param email メールアドレス
     */
    void setEmail(const Char* email)
    {
        ensureData().email.emplace(email);
    }

    /**
     * メールアドレスを設定
     *
     * @param email メールアドレス
     */
    Account& withEmail(const Char* email)
    {
        setEmail(email);
        return *this;
    }

    /**
     * フルネームを取得
     *
     * @return フルネーム
     */
    const optional<StringHolder>& getFullName() const
    {
        return ensureData().fullName;
    }

    /**
     * フルネームを設定
     *
     * @param fullName フルネーム
     */
    void setFullName(const Char* fullName)
    {
        ensureData().fullName.emplace(fullName);
    }

    /**
     * フルネームを設定
     *
     * @param fullName フルネーム
     */
    Account& withFullName(const Char* fullName)
    {
        setFullName(fullName);
        return *this;
    }

    /**
     * 会社名を取得
     *
     * @return 会社名
     */
    const optional<StringHolder>& getCompanyName() const
    {
        return ensureData().companyName;
    }

    /**
     * 会社名を設定
     *
     * @param companyName 会社名
     */
    void setCompanyName(const Char* companyName)
    {
        ensureData().companyName.emplace(companyName);
    }

    /**
     * 会社名を設定
     *
     * @param companyName 会社名
     */
    Account& withCompanyName(const Char* companyName)
    {
        setCompanyName(companyName);
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
     * ステータスを取得
     *
     * @return ステータス
     */
    const optional<StringHolder>& getStatus() const
    {
        return ensureData().status;
    }

    /**
     * ステータスを設定
     *
     * @param status ステータス
     */
    void setStatus(const Char* status)
    {
        ensureData().status.emplace(status);
    }

    /**
     * ステータスを設定
     *
     * @param status ステータス
     */
    Account& withStatus(const Char* status)
    {
        setStatus(status);
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
    Account& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
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
        if (lhs.m_pData->ownerId != lhr.m_pData->ownerId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->email != lhr.m_pData->email)
        {
            return true;
        }
        if (lhs.m_pData->fullName != lhr.m_pData->fullName)
        {
            return true;
        }
        if (lhs.m_pData->companyName != lhr.m_pData->companyName)
        {
            return true;
        }
        if (lhs.m_pData->password != lhr.m_pData->password)
        {
            return true;
        }
        if (lhs.m_pData->status != lhr.m_pData->status)
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

inline bool operator==(const Account& lhs, const Account& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_PROJECT_MODEL_ACCOUNT_HPP_