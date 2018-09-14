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

#ifndef GS2_IDENTIFIER_MODEL_USER_HPP_
#define GS2_IDENTIFIER_MODEL_USER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace identifier {

/**
 * ユーザ
 *
 * @author Game Server Services, Inc.
 *
 */
class User : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザGRN */
        optional<StringHolder> userId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ユーザ名 */
        optional<StringHolder> name;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            ownerId(data.ownerId),
            name(data.name),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
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
    User() :
        m_pData(nullptr)
    {}

    User(const User& user) :
        Gs2Object(user),
        m_pData(user.m_pData != nullptr ? new Data(*user.m_pData) : nullptr)
    {}

    User(User&& user) :
        Gs2Object(std::move(user)),
        m_pData(user.m_pData)
    {
        user.m_pData = nullptr;
    }

    ~User()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    User& operator=(const User& user)
    {
        Gs2Object::operator=(user);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*user.m_pData);

        return *this;
    }

    User& operator=(User&& user)
    {
        Gs2Object::operator=(std::move(user));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = user.m_pData;
        user.m_pData = nullptr;

        return *this;
    }

    const User* operator->() const
    {
        return this;
    }

    User* operator->()
    {
        return this;
    }


    /**
     * ユーザGRNを取得
     *
     * @return ユーザGRN
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザGRNを設定
     *
     * @param userId ユーザGRN
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
     * ユーザ名を取得
     *
     * @return ユーザ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ユーザ名を設定
     *
     * @param name ユーザ名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_IDENTIFIER_MODEL_USER_HPP_