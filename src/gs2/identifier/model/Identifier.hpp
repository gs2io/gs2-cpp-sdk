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

#ifndef GS2_IDENTIFIER_MODEL_IDENTIFIER_HPP_
#define GS2_IDENTIFIER_MODEL_IDENTIFIER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace  {

/**
 * GSI
 *
 * @author Game Server Services, Inc.
 *
 */
class Identifier : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** クライアントID */
        optional<StringHolder> clientId;
        /** ユーザー名 */
        optional<StringHolder> userName;
        /** 作成日時 */
        
        optional<Int64> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            ownerId(data.ownerId),
            clientId(data.clientId),
            userName(data.userName),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            ownerId(std::move(data.ownerId)),
            clientId(std::move(data.clientId)),
            userName(std::move(data.userName)),
            createAt(std::move(data.createAt))
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
            else if (std::strcmp(name, "clientId") == 0) {
                if (jsonValue.IsString())
                {
                    this->clientId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userName") == 0) {
                if (jsonValue.IsString())
                {
                    this->userName.emplace(jsonValue.GetString());
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
    Identifier() :
        m_pData(nullptr)
    {}

    Identifier(const Identifier& identifier) :
        Gs2Object(identifier),
        m_pData(identifier.m_pData != nullptr ? new Data(*identifier.m_pData) : nullptr)
    {}

    Identifier(Identifier&& identifier) :
        Gs2Object(std::move(identifier)),
        m_pData(identifier.m_pData)
    {
        identifier.m_pData = nullptr;
    }

    ~Identifier()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Identifier& operator=(const Identifier& identifier)
    {
        Gs2Object::operator=(identifier);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*identifier.m_pData);

        return *this;
    }

    Identifier& operator=(Identifier&& identifier)
    {
        Gs2Object::operator=(std::move(identifier));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = identifier.m_pData;
        identifier.m_pData = nullptr;

        return *this;
    }

    const Identifier* operator->() const
    {
        return this;
    }

    Identifier* operator->()
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
     * クライアントIDを取得
     *
     * @return クライアントID
     */
    const optional<StringHolder>& getClientId() const
    {
        return ensureData().clientId;
    }

    /**
     * クライアントIDを設定
     *
     * @param clientId クライアントID
     */
    void setClientId(const Char* clientId)
    {
        ensureData().clientId.emplace(clientId);
    }

    /**
     * ユーザー名を取得
     *
     * @return ユーザー名
     */
    const optional<StringHolder>& getUserName() const
    {
        return ensureData().userName;
    }

    /**
     * ユーザー名を設定
     *
     * @param userName ユーザー名
     */
    void setUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_IDENTIFIER_MODEL_IDENTIFIER_HPP_