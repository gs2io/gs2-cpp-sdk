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

#ifndef GS2_ACCOUNT_MODEL_FULLTAKEOVER_HPP_
#define GS2_ACCOUNT_MODEL_FULLTAKEOVER_HPP_

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
class FullTakeOver : public Gs2Object
{
    friend bool operator!=(const FullTakeOver& lhs, const FullTakeOver& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 引き継ぎ設定 のGRN */
        optional<StringHolder> takeOverId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** スロット番号 */
        optional<Int32> type;
        /** 引き継ぎ用ユーザーID */
        optional<StringHolder> userIdentifier;
        /** 作成日時 */
        optional<Int64> createAt;
        /** パスワード */
        optional<StringHolder> password;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            takeOverId(data.takeOverId),
            userId(data.userId),
            type(data.type),
            userIdentifier(data.userIdentifier),
            createAt(data.createAt),
            password(data.password)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            takeOverId(std::move(data.takeOverId)),
            userId(std::move(data.userId)),
            type(std::move(data.type)),
            userIdentifier(std::move(data.userIdentifier)),
            createAt(std::move(data.createAt)),
            password(std::move(data.password))
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
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "password") == 0) {
                if (jsonValue.IsString())
                {
                    this->password.emplace(jsonValue.GetString());
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
    FullTakeOver() :
        m_pData(nullptr)
    {}

    FullTakeOver(const FullTakeOver& fullTakeOver) :
        Gs2Object(fullTakeOver),
        m_pData(fullTakeOver.m_pData != nullptr ? new Data(*fullTakeOver.m_pData) : nullptr)
    {}

    FullTakeOver(FullTakeOver&& fullTakeOver) :
        Gs2Object(std::move(fullTakeOver)),
        m_pData(fullTakeOver.m_pData)
    {
        fullTakeOver.m_pData = nullptr;
    }

    ~FullTakeOver()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    FullTakeOver& operator=(const FullTakeOver& fullTakeOver)
    {
        Gs2Object::operator=(fullTakeOver);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*fullTakeOver.m_pData);

        return *this;
    }

    FullTakeOver& operator=(FullTakeOver&& fullTakeOver)
    {
        Gs2Object::operator=(std::move(fullTakeOver));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = fullTakeOver.m_pData;
        fullTakeOver.m_pData = nullptr;

        return *this;
    }

    const FullTakeOver* operator->() const
    {
        return this;
    }

    FullTakeOver* operator->()
    {
        return this;
    }
    /**
     * 引き継ぎ設定 のGRNを取得
     *
     * @return 引き継ぎ設定 のGRN
     */
    const optional<StringHolder>& getTakeOverId() const
    {
        return ensureData().takeOverId;
    }

    /**
     * 引き継ぎ設定 のGRNを設定
     *
     * @param takeOverId 引き継ぎ設定 のGRN
     */
    void setTakeOverId(const Char* takeOverId)
    {
        ensureData().takeOverId.emplace(takeOverId);
    }

    /**
     * 引き継ぎ設定 のGRNを設定
     *
     * @param takeOverId 引き継ぎ設定 のGRN
     */
    FullTakeOver& withTakeOverId(const Char* takeOverId)
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
    FullTakeOver& withUserId(const Char* userId)
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
    FullTakeOver& withType(Int32 type)
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
    FullTakeOver& withUserIdentifier(const Char* userIdentifier)
    {
        setUserIdentifier(userIdentifier);
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
    FullTakeOver& withCreateAt(Int64 createAt)
    {
        setCreateAt(createAt);
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
    FullTakeOver& withPassword(const Char* password)
    {
        setPassword(password);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const FullTakeOver& lhs, const FullTakeOver& lhr)
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
        if (lhs.m_pData->createAt != lhr.m_pData->createAt)
        {
            return true;
        }
        if (lhs.m_pData->password != lhr.m_pData->password)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const FullTakeOver& lhs, const FullTakeOver& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ACCOUNT_MODEL_FULLTAKEOVER_HPP_