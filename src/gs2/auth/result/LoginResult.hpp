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

#ifndef GS2_AUTH_CONTROL_LOGINRESULT_HPP_
#define GS2_AUTH_CONTROL_LOGINRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace auth
{

/**
 * 指定したユーザIDでGS2にログインし、アクセストークンを取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class LoginResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アクセストークン */
        optional<StringHolder> token;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** 有効期限 */
        optional<Int64> expire;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            token(data.token),
            userId(data.userId),
            expire(data.expire)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            token(std::move(data.token)),
            userId(std::move(data.userId)),
            expire(std::move(data.expire))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "token") == 0) {
                if (jsonValue.IsString())
                {
                    this->token.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "expire") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->expire = jsonValue.GetInt64();
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
     * 有効期限を取得
     *
     * @return 有効期限
     */
    const optional<Int64>& getExpire() const
    {
        return ensureData().expire;
    }

    /**
     * 有効期限を設定
     *
     * @param expire 有効期限
     */
    void setExpire(Int64 expire)
    {
        ensureData().expire.emplace(expire);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<LoginResult> AsyncLoginResult;

} }

#endif //GS2_AUTH_CONTROL_LOGINRESULT_HPP_