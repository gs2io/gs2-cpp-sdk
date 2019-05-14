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
        optional<ProjectToken> item;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
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
    const optional<ProjectToken>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * プロジェクトトークンを設定
     *
     * @param item プロジェクトトークン
     */
    void setItem(const ProjectToken& item)
    {
        ensureData().item.emplace(item);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_LOGINRESULT_HPP_