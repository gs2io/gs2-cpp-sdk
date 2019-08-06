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

#ifndef GS2_IDENTIFIER_CONTROL_LOGINRESULT_HPP_
#define GS2_IDENTIFIER_CONTROL_LOGINRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace identifier
{

/**
 * プロジェクトトークン を取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class LoginResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** プロジェクトトークン */
        optional<StringHolder> accessToken;
        /** Bearer */
        optional<StringHolder> tokenType;
        /** 有効期間(秒) */
        optional<Int32> expiresIn;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            accessToken(data.accessToken),
            tokenType(data.tokenType),
            expiresIn(data.expiresIn)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            accessToken(std::move(data.accessToken)),
            tokenType(std::move(data.tokenType)),
            expiresIn(std::move(data.expiresIn))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "accessToken") == 0) {
                if (jsonValue.IsString())
                {
                    this->accessToken.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "tokenType") == 0) {
                if (jsonValue.IsString())
                {
                    this->tokenType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "expiresIn") == 0) {
                if (jsonValue.IsInt())
                {
                    this->expiresIn = jsonValue.GetInt();
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
    LoginResult() :
        m_pData(nullptr)
    {}

    LoginResult(const LoginResult& loginResult) :
        Gs2Object(loginResult),
        m_pData(loginResult.m_pData != nullptr ? new Data(*loginResult.m_pData) : nullptr)
    {}

    LoginResult(LoginResult&& loginResult) :
        Gs2Object(std::move(loginResult)),
        m_pData(loginResult.m_pData)
    {
        loginResult.m_pData = nullptr;
    }

    ~LoginResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    LoginResult& operator=(const LoginResult& loginResult)
    {
        Gs2Object::operator=(loginResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*loginResult.m_pData);

        return *this;
    }

    LoginResult& operator=(LoginResult&& loginResult)
    {
        Gs2Object::operator=(std::move(loginResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = loginResult.m_pData;
        loginResult.m_pData = nullptr;

        return *this;
    }

    const LoginResult* operator->() const
    {
        return this;
    }

    LoginResult* operator->()
    {
        return this;
    }
    /**
     * プロジェクトトークンを取得
     *
     * @return プロジェクトトークン
     */
    const optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * プロジェクトトークンを設定
     *
     * @param accessToken プロジェクトトークン
     */
    void setAccessToken(const Char* accessToken)
    {
        ensureData().accessToken.emplace(accessToken);
    }

    /**
     * Bearerを取得
     *
     * @return Bearer
     */
    const optional<StringHolder>& getTokenType() const
    {
        return ensureData().tokenType;
    }

    /**
     * Bearerを設定
     *
     * @param tokenType Bearer
     */
    void setTokenType(const Char* tokenType)
    {
        ensureData().tokenType.emplace(tokenType);
    }

    /**
     * 有効期間(秒)を取得
     *
     * @return 有効期間(秒)
     */
    const optional<Int32>& getExpiresIn() const
    {
        return ensureData().expiresIn;
    }

    /**
     * 有効期間(秒)を設定
     *
     * @param expiresIn 有効期間(秒)
     */
    void setExpiresIn(Int32 expiresIn)
    {
        ensureData().expiresIn.emplace(expiresIn);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_LOGINRESULT_HPP_