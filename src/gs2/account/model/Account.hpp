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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
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
        /** 現在時刻に対する補正値（現在時刻を起点とした秒数） */
        optional<Int32> timeOffset;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            accountId(data.accountId),
            userId(data.userId),
            password(data.password),
            timeOffset(data.timeOffset),
            createdAt(data.createdAt)
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
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "password") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->password.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "timeOffset") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->timeOffset = jsonValue.GetInt();
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
    void setAccountId(StringHolder accountId)
    {
        ensureData().accountId.emplace(std::move(accountId));
    }

    /**
     * ゲームプレイヤーアカウントを設定
     *
     * @param accountId ゲームプレイヤーアカウント
     */
    Account& withAccountId(StringHolder accountId)
    {
        setAccountId(std::move(accountId));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * アカウントIDを設定
     *
     * @param userId アカウントID
     */
    Account& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
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
     * 現在時刻に対する補正値（現在時刻を起点とした秒数）を取得
     *
     * @return 現在時刻に対する補正値（現在時刻を起点とした秒数）
     */
    const optional<Int32>& getTimeOffset() const
    {
        return ensureData().timeOffset;
    }

    /**
     * 現在時刻に対する補正値（現在時刻を起点とした秒数）を設定
     *
     * @param timeOffset 現在時刻に対する補正値（現在時刻を起点とした秒数）
     */
    void setTimeOffset(Int32 timeOffset)
    {
        ensureData().timeOffset.emplace(timeOffset);
    }

    /**
     * 現在時刻に対する補正値（現在時刻を起点とした秒数）を設定
     *
     * @param timeOffset 現在時刻に対する補正値（現在時刻を起点とした秒数）
     */
    Account& withTimeOffset(Int32 timeOffset)
    {
        setTimeOffset(timeOffset);
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
        if (!lhs.m_pData || !lhr.m_pData)
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
        if (lhs.m_pData->timeOffset != lhr.m_pData->timeOffset)
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