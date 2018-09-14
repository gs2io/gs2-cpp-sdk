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

#ifndef GS2_AUTH_CONTROL_CREATETIMEONETIMETOKENRESULT_HPP_
#define GS2_AUTH_CONTROL_CREATETIMEONETIMETOKENRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace auth
{

/**
 * @author Game Server Services, Inc.
 */
class CreateTimeOnetimeTokenResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アクセストークン */
        optional<StringHolder> token;
        /** アクセストークンの有効期限 */
        optional<Int32> expire;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            token(data.token),
            expire(data.expire)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            token(std::move(data.token)),
            expire(std::move(data.expire))
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
            else if (std::strcmp(name, "expire") == 0) {
                if (jsonValue.IsInt())
                {
                    this->expire = jsonValue.GetInt();
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
    CreateTimeOnetimeTokenResult() :
        m_pData(nullptr)
    {}

    CreateTimeOnetimeTokenResult(const CreateTimeOnetimeTokenResult& createTimeOnetimeTokenResult) :
        Gs2Object(createTimeOnetimeTokenResult),
        m_pData(createTimeOnetimeTokenResult.m_pData != nullptr ? new Data(*createTimeOnetimeTokenResult.m_pData) : nullptr)
    {}

    CreateTimeOnetimeTokenResult(CreateTimeOnetimeTokenResult&& createTimeOnetimeTokenResult) :
        Gs2Object(std::move(createTimeOnetimeTokenResult)),
        m_pData(createTimeOnetimeTokenResult.m_pData)
    {
        createTimeOnetimeTokenResult.m_pData = nullptr;
    }

    ~CreateTimeOnetimeTokenResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateTimeOnetimeTokenResult& operator=(const CreateTimeOnetimeTokenResult& createTimeOnetimeTokenResult)
    {
        Gs2Object::operator=(createTimeOnetimeTokenResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createTimeOnetimeTokenResult.m_pData);

        return *this;
    }

    CreateTimeOnetimeTokenResult& operator=(CreateTimeOnetimeTokenResult&& createTimeOnetimeTokenResult)
    {
        Gs2Object::operator=(std::move(createTimeOnetimeTokenResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createTimeOnetimeTokenResult.m_pData;
        createTimeOnetimeTokenResult.m_pData = nullptr;

        return *this;
    }

    const CreateTimeOnetimeTokenResult* operator->() const
    {
        return this;
    }

    CreateTimeOnetimeTokenResult* operator->()
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
     * アクセストークンの有効期限を取得
     *
     * @return アクセストークンの有効期限
     */
    const optional<Int32>& getExpire() const
    {
        return ensureData().expire;
    }

    /**
     * アクセストークンの有効期限を設定
     *
     * @param expire アクセストークンの有効期限
     */
    void setExpire(Int32 expire)
    {
        ensureData().expire.emplace(expire);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_AUTH_CONTROL_CREATETIMEONETIMETOKENRESULT_HPP_