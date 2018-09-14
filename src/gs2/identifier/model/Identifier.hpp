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

#ifndef GS2_IDENTIFIER_MODEL_IDENTIFIER_HPP_
#define GS2_IDENTIFIER_MODEL_IDENTIFIER_HPP_

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
class Identifier : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザGRN */
        optional<StringHolder> identifierId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ユーザID */
        optional<StringHolder> userId;
        /** クライアントID */
        optional<StringHolder> clientId;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            identifierId(data.identifierId),
            ownerId(data.ownerId),
            userId(data.userId),
            clientId(data.clientId),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            identifierId(std::move(data.identifierId)),
            ownerId(std::move(data.ownerId)),
            userId(std::move(data.userId)),
            clientId(std::move(data.clientId)),
            createAt(std::move(data.createAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "identifierId") == 0) {
                if (jsonValue.IsString())
                {
                    this->identifierId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "clientId") == 0) {
                if (jsonValue.IsString())
                {
                    this->clientId.emplace(jsonValue.GetString());
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
     * ユーザGRNを取得
     *
     * @return ユーザGRN
     */
    const optional<StringHolder>& getIdentifierId() const
    {
        return ensureData().identifierId;
    }

    /**
     * ユーザGRNを設定
     *
     * @param identifierId ユーザGRN
     */
    void setIdentifierId(const Char* identifierId)
    {
        ensureData().identifierId.emplace(identifierId);
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
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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

#endif //GS2_IDENTIFIER_MODEL_IDENTIFIER_HPP_