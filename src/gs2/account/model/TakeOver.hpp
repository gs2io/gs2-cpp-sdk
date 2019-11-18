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

#ifndef GS2_ACCOUNT_MODEL_TAKEOVER_HPP_
#define GS2_ACCOUNT_MODEL_TAKEOVER_HPP_

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
 * 引き継ぎ設定
 *
 * @author Game Server Services, Inc.
 *
 */
class TakeOver : public Gs2Object
{
    friend bool operator!=(const TakeOver& lhs, const TakeOver& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 引き継ぎ設定 */
        optional<StringHolder> takeOverId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** スロット番号 */
        optional<Int32> type;
        /** 引き継ぎ用ユーザーID */
        optional<StringHolder> userIdentifier;
        /** パスワード */
        optional<StringHolder> password;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            takeOverId(data.takeOverId),
            userId(data.userId),
            type(data.type),
            userIdentifier(data.userIdentifier),
            password(data.password),
            createdAt(data.createdAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "takeOverId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->takeOverId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "type") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->type = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "userIdentifier") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userIdentifier.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "password") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->password.emplace(jsonValue.GetString());
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
    TakeOver() = default;
    TakeOver(const TakeOver& takeOver) = default;
    TakeOver(TakeOver&& takeOver) = default;
    ~TakeOver() = default;

    TakeOver& operator=(const TakeOver& takeOver) = default;
    TakeOver& operator=(TakeOver&& takeOver) = default;

    TakeOver deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(TakeOver);
    }

    const TakeOver* operator->() const
    {
        return this;
    }

    TakeOver* operator->()
    {
        return this;
    }
    /**
     * 引き継ぎ設定を取得
     *
     * @return 引き継ぎ設定
     */
    const optional<StringHolder>& getTakeOverId() const
    {
        return ensureData().takeOverId;
    }

    /**
     * 引き継ぎ設定を設定
     *
     * @param takeOverId 引き継ぎ設定
     */
    void setTakeOverId(StringHolder takeOverId)
    {
        ensureData().takeOverId.emplace(std::move(takeOverId));
    }

    /**
     * 引き継ぎ設定を設定
     *
     * @param takeOverId 引き継ぎ設定
     */
    TakeOver& withTakeOverId(StringHolder takeOverId)
    {
        setTakeOverId(std::move(takeOverId));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    TakeOver& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * スロット番号を取得
     *
     * @return スロット番号
     */
    const optional<Int32>& getType() const
    {
        return ensureData().type;
    }

    /**
     * スロット番号を設定
     *
     * @param type スロット番号
     */
    void setType(Int32 type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * スロット番号を設定
     *
     * @param type スロット番号
     */
    TakeOver& withType(Int32 type)
    {
        setType(type);
        return *this;
    }

    /**
     * 引き継ぎ用ユーザーIDを取得
     *
     * @return 引き継ぎ用ユーザーID
     */
    const optional<StringHolder>& getUserIdentifier() const
    {
        return ensureData().userIdentifier;
    }

    /**
     * 引き継ぎ用ユーザーIDを設定
     *
     * @param userIdentifier 引き継ぎ用ユーザーID
     */
    void setUserIdentifier(StringHolder userIdentifier)
    {
        ensureData().userIdentifier.emplace(std::move(userIdentifier));
    }

    /**
     * 引き継ぎ用ユーザーIDを設定
     *
     * @param userIdentifier 引き継ぎ用ユーザーID
     */
    TakeOver& withUserIdentifier(StringHolder userIdentifier)
    {
        setUserIdentifier(std::move(userIdentifier));
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
    TakeOver& withPassword(StringHolder password)
    {
        setPassword(std::move(password));
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
    TakeOver& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const TakeOver& lhs, const TakeOver& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->takeOverId != lhr.m_pData->takeOverId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->type != lhr.m_pData->type)
        {
            return true;
        }
        if (lhs.m_pData->userIdentifier != lhr.m_pData->userIdentifier)
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

inline bool operator==(const TakeOver& lhs, const TakeOver& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ACCOUNT_MODEL_TAKEOVER_HPP_