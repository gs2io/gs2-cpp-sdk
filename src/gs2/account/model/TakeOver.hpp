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
#include <gs2/core/external/optional/optional.hpp>
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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            takeOverId(data.takeOverId),
            userId(data.userId),
            type(data.type),
            userIdentifier(data.userIdentifier),
            password(data.password),
            createdAt(data.createdAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            takeOverId(std::move(data.takeOverId)),
            userId(std::move(data.userId)),
            type(std::move(data.type)),
            userIdentifier(std::move(data.userIdentifier)),
            password(std::move(data.password)),
            createdAt(std::move(data.createdAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "takeOverId") == 0) {
                if (jsonValue.IsString())
                {
                    this->takeOverId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "type") == 0) {
                if (jsonValue.IsInt())
                {
                    this->type = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "userIdentifier") == 0) {
                if (jsonValue.IsString())
                {
                    this->userIdentifier.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "password") == 0) {
                if (jsonValue.IsString())
                {
                    this->password.emplace(jsonValue.GetString());
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
    TakeOver() :
        m_pData(nullptr)
    {}

    TakeOver(const TakeOver& takeOver) :
        Gs2Object(takeOver),
        m_pData(takeOver.m_pData != nullptr ? new Data(*takeOver.m_pData) : nullptr)
    {}

    TakeOver(TakeOver&& takeOver) :
        Gs2Object(std::move(takeOver)),
        m_pData(takeOver.m_pData)
    {
        takeOver.m_pData = nullptr;
    }

    ~TakeOver()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    TakeOver& operator=(const TakeOver& takeOver)
    {
        Gs2Object::operator=(takeOver);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*takeOver.m_pData);

        return *this;
    }

    TakeOver& operator=(TakeOver&& takeOver)
    {
        Gs2Object::operator=(std::move(takeOver));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = takeOver.m_pData;
        takeOver.m_pData = nullptr;

        return *this;
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
    void setTakeOverId(const Char* takeOverId)
    {
        ensureData().takeOverId.emplace(takeOverId);
    }

    /**
     * 引き継ぎ設定を設定
     *
     * @param takeOverId 引き継ぎ設定
     */
    TakeOver& withTakeOverId(const Char* takeOverId)
    {
        setTakeOverId(takeOverId);
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
    TakeOver& withUserId(const Char* userId)
    {
        setUserId(userId);
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
    void setUserIdentifier(const Char* userIdentifier)
    {
        ensureData().userIdentifier.emplace(userIdentifier);
    }

    /**
     * 引き継ぎ用ユーザーIDを設定
     *
     * @param userIdentifier 引き継ぎ用ユーザーID
     */
    TakeOver& withUserIdentifier(const Char* userIdentifier)
    {
        setUserIdentifier(userIdentifier);
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
    TakeOver& withPassword(const Char* password)
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

bool operator!=(const TakeOver& lhs, const TakeOver& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
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

bool operator==(const TakeOver& lhs, const TakeOver& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ACCOUNT_MODEL_TAKEOVER_HPP_