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

#ifndef GS2_IDENTIFIER_MODEL_FULLIDENTIFIER_HPP_
#define GS2_IDENTIFIER_MODEL_FULLIDENTIFIER_HPP_

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
class FullIdentifier : public Gs2Object
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
        /** クライアントシークレット */
        optional<StringHolder> clientSecret;
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
            clientSecret(data.clientSecret),
            createAt(data.createAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            identifierId(std::move(data.identifierId)),
            ownerId(std::move(data.ownerId)),
            userId(std::move(data.userId)),
            clientId(std::move(data.clientId)),
            clientSecret(std::move(data.clientSecret)),
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
            else if (std::strcmp(name, "clientSecret") == 0) {
                if (jsonValue.IsString())
                {
                    this->clientSecret.emplace(jsonValue.GetString());
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
    FullIdentifier() :
        m_pData(nullptr)
    {}

    FullIdentifier(const FullIdentifier& fullIdentifier) :
        Gs2Object(fullIdentifier),
        m_pData(fullIdentifier.m_pData != nullptr ? new Data(*fullIdentifier.m_pData) : nullptr)
    {}

    FullIdentifier(FullIdentifier&& fullIdentifier) :
        Gs2Object(std::move(fullIdentifier)),
        m_pData(fullIdentifier.m_pData)
    {
        fullIdentifier.m_pData = nullptr;
    }

    ~FullIdentifier()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    FullIdentifier& operator=(const FullIdentifier& fullIdentifier)
    {
        Gs2Object::operator=(fullIdentifier);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*fullIdentifier.m_pData);

        return *this;
    }

    FullIdentifier& operator=(FullIdentifier&& fullIdentifier)
    {
        Gs2Object::operator=(std::move(fullIdentifier));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = fullIdentifier.m_pData;
        fullIdentifier.m_pData = nullptr;

        return *this;
    }

    const FullIdentifier* operator->() const
    {
        return this;
    }

    FullIdentifier* operator->()
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
     * クライアントシークレットを取得
     *
     * @return クライアントシークレット
     */
    const optional<StringHolder>& getClientSecret() const
    {
        return ensureData().clientSecret;
    }

    /**
     * クライアントシークレットを設定
     *
     * @param clientSecret クライアントシークレット
     */
    void setClientSecret(const Char* clientSecret)
    {
        ensureData().clientSecret.emplace(clientSecret);
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

#endif //GS2_IDENTIFIER_MODEL_FULLIDENTIFIER_HPP_