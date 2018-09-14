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

#ifndef GS2_AUTH_CONTROL_CREATEONCEONETIMETOKENRESULT_HPP_
#define GS2_AUTH_CONTROL_CREATEONCEONETIMETOKENRESULT_HPP_

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
class CreateOnceOnetimeTokenResult : public Gs2Object
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
    CreateOnceOnetimeTokenResult() :
        m_pData(nullptr)
    {}

    CreateOnceOnetimeTokenResult(const CreateOnceOnetimeTokenResult& createOnceOnetimeTokenResult) :
        Gs2Object(createOnceOnetimeTokenResult),
        m_pData(createOnceOnetimeTokenResult.m_pData != nullptr ? new Data(*createOnceOnetimeTokenResult.m_pData) : nullptr)
    {}

    CreateOnceOnetimeTokenResult(CreateOnceOnetimeTokenResult&& createOnceOnetimeTokenResult) :
        Gs2Object(std::move(createOnceOnetimeTokenResult)),
        m_pData(createOnceOnetimeTokenResult.m_pData)
    {
        createOnceOnetimeTokenResult.m_pData = nullptr;
    }

    ~CreateOnceOnetimeTokenResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateOnceOnetimeTokenResult& operator=(const CreateOnceOnetimeTokenResult& createOnceOnetimeTokenResult)
    {
        Gs2Object::operator=(createOnceOnetimeTokenResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createOnceOnetimeTokenResult.m_pData);

        return *this;
    }

    CreateOnceOnetimeTokenResult& operator=(CreateOnceOnetimeTokenResult&& createOnceOnetimeTokenResult)
    {
        Gs2Object::operator=(std::move(createOnceOnetimeTokenResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createOnceOnetimeTokenResult.m_pData;
        createOnceOnetimeTokenResult.m_pData = nullptr;

        return *this;
    }

    const CreateOnceOnetimeTokenResult* operator->() const
    {
        return this;
    }

    CreateOnceOnetimeTokenResult* operator->()
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

#endif //GS2_AUTH_CONTROL_CREATEONCEONETIMETOKENRESULT_HPP_