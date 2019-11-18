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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
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

        Data() = default;

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
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "accountId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->accountId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "ownerId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "email") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->email.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "fullName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->fullName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "companyName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->companyName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "password") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->password.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "status") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Account() = default;
    Account(const Account& account) = default;
    Account(Account&& account) = default;
    ~Account() = default;

    Account& operator=(const Account& account) = default;
    Account& operator=(Account&& account) = default;

    Account deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Account);
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
    void setAccountId(StringHolder accountId)
    {
        ensureData().accountId.emplace(std::move(accountId));
    }

    /**
     * GS2アカウントを設定
     *
     * @param accountId GS2アカウント
     */
    Account& withAccountId(StringHolder accountId)
    {
        setAccountId(std::move(accountId));
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
    void setOwnerId(StringHolder ownerId)
    {
        ensureData().ownerId.emplace(std::move(ownerId));
    }

    /**
     * Noneを設定
     *
     * @param ownerId None
     */
    Account& withOwnerId(StringHolder ownerId)
    {
        setOwnerId(std::move(ownerId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param name GS2アカウントの名前
     */
    Account& withName(StringHolder name)
    {
        setName(std::move(name));
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
    void setEmail(StringHolder email)
    {
        ensureData().email.emplace(std::move(email));
    }

    /**
     * メールアドレスを設定
     *
     * @param email メールアドレス
     */
    Account& withEmail(StringHolder email)
    {
        setEmail(std::move(email));
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
    void setFullName(StringHolder fullName)
    {
        ensureData().fullName.emplace(std::move(fullName));
    }

    /**
     * フルネームを設定
     *
     * @param fullName フルネーム
     */
    Account& withFullName(StringHolder fullName)
    {
        setFullName(std::move(fullName));
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
    void setCompanyName(StringHolder companyName)
    {
        ensureData().companyName.emplace(std::move(companyName));
    }

    /**
     * 会社名を設定
     *
     * @param companyName 会社名
     */
    Account& withCompanyName(StringHolder companyName)
    {
        setCompanyName(std::move(companyName));
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
    void setPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    Account& withPassword(StringHolder password)
    {
        setPassword(std::move(password));
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
    void setStatus(StringHolder status)
    {
        ensureData().status.emplace(std::move(status));
    }

    /**
     * ステータスを設定
     *
     * @param status ステータス
     */
    Account& withStatus(StringHolder status)
    {
        setStatus(std::move(status));
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
        if (!lhs.m_pData || !lhr.m_pData)
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