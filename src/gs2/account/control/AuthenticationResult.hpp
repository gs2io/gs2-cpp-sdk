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

#ifndef GS2_ACCOUNT_CONTROL_AUTHENTICATIONRESULT_HPP_
#define GS2_ACCOUNT_CONTROL_AUTHENTICATIONRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace account
{

/**
 * @author Game Server Services, Inc.
 */
class AuthenticationResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アクセストークン */
        optional<StringHolder> token;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            token(data.token)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            token(std::move(data.token))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "token") == 0) {
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
    AuthenticationResult() :
        m_pData(nullptr)
    {}

    AuthenticationResult(const AuthenticationResult& authenticationResult) :
        Gs2Object(authenticationResult),
        m_pData(authenticationResult.m_pData != nullptr ? new Data(*authenticationResult.m_pData) : nullptr)
    {}

    AuthenticationResult(AuthenticationResult&& authenticationResult) :
        Gs2Object(std::move(authenticationResult)),
        m_pData(authenticationResult.m_pData)
    {
        authenticationResult.m_pData = nullptr;
    }

    ~AuthenticationResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AuthenticationResult& operator=(const AuthenticationResult& authenticationResult)
    {
        Gs2Object::operator=(authenticationResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*authenticationResult.m_pData);

        return *this;
    }

    AuthenticationResult& operator=(AuthenticationResult&& authenticationResult)
    {
        Gs2Object::operator=(std::move(authenticationResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = authenticationResult.m_pData;
        authenticationResult.m_pData = nullptr;

        return *this;
    }

    const AuthenticationResult* operator->() const
    {
        return this;
    }

    AuthenticationResult* operator->()
    {
        return this;
    }


    /**
     * アクセストークンを取得
     *
     * @return アクセストークン
     */
    const optional<StringHolder>& getToken() const
    {
        return ensureData().token;
    }

    /**
     * アクセストークンを設定
     *
     * @param token アクセストークン
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

#endif //GS2_ACCOUNT_CONTROL_AUTHENTICATIONRESULT_HPP_