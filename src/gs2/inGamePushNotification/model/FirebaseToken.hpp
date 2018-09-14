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

#ifndef GS2_INGAMEPUSHNOTIFICATION_MODEL_FIREBASETOKEN_HPP_
#define GS2_INGAMEPUSHNOTIFICATION_MODEL_FIREBASETOKEN_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace inGamePushNotification {

/**
 * Firebase 通知トークン
 *
 * @author Game Server Services, Inc.
 *
 */
class FirebaseToken : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザID */
        optional<StringHolder> userId;
        /** トークン */
        optional<StringHolder> token;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            token(data.token)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            token(std::move(data.token))
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
            else if (std::strcmp(name, "token") == 0) {
                if (jsonValue.IsString())
                {
                    this->token.emplace(jsonValue.GetString());
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
    FirebaseToken() :
        m_pData(nullptr)
    {}

    FirebaseToken(const FirebaseToken& firebaseToken) :
        Gs2Object(firebaseToken),
        m_pData(firebaseToken.m_pData != nullptr ? new Data(*firebaseToken.m_pData) : nullptr)
    {}

    FirebaseToken(FirebaseToken&& firebaseToken) :
        Gs2Object(std::move(firebaseToken)),
        m_pData(firebaseToken.m_pData)
    {
        firebaseToken.m_pData = nullptr;
    }

    ~FirebaseToken()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    FirebaseToken& operator=(const FirebaseToken& firebaseToken)
    {
        Gs2Object::operator=(firebaseToken);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*firebaseToken.m_pData);

        return *this;
    }

    FirebaseToken& operator=(FirebaseToken&& firebaseToken)
    {
        Gs2Object::operator=(std::move(firebaseToken));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = firebaseToken.m_pData;
        firebaseToken.m_pData = nullptr;

        return *this;
    }

    const FirebaseToken* operator->() const
    {
        return this;
    }

    FirebaseToken* operator->()
    {
        return this;
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
     * トークンを取得
     *
     * @return トークン
     */
    const optional<StringHolder>& getToken() const
    {
        return ensureData().token;
    }

    /**
     * トークンを設定
     *
     * @param token トークン
     */
    void setToken(const Char* token)
    {
        ensureData().token.emplace(token);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_INGAMEPUSHNOTIFICATION_MODEL_FIREBASETOKEN_HPP_