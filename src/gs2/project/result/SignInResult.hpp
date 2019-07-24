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

#ifndef GS2_PROJECT_CONTROL_SIGNINRESULT_HPP_
#define GS2_PROJECT_CONTROL_SIGNINRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

namespace gs2 { namespace project
{

/**
 * サインインします のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class SignInResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** サインインしたGS2アカウント */
        optional<Account> item;
        /** GS2-Console にアクセスするのに使用するトークン */
        optional<StringHolder> accountToken;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            accountToken(data.accountToken)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            accountToken(std::move(data.accountToken))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "item") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "accountToken") == 0) {
                if (jsonValue.IsString())
                {
                    this->accountToken.emplace(jsonValue.GetString());
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
    SignInResult() :
        m_pData(nullptr)
    {}

    SignInResult(const SignInResult& signInResult) :
        Gs2Object(signInResult),
        m_pData(signInResult.m_pData != nullptr ? new Data(*signInResult.m_pData) : nullptr)
    {}

    SignInResult(SignInResult&& signInResult) :
        Gs2Object(std::move(signInResult)),
        m_pData(signInResult.m_pData)
    {
        signInResult.m_pData = nullptr;
    }

    ~SignInResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SignInResult& operator=(const SignInResult& signInResult)
    {
        Gs2Object::operator=(signInResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*signInResult.m_pData);

        return *this;
    }

    SignInResult& operator=(SignInResult&& signInResult)
    {
        Gs2Object::operator=(std::move(signInResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = signInResult.m_pData;
        signInResult.m_pData = nullptr;

        return *this;
    }

    const SignInResult* operator->() const
    {
        return this;
    }

    SignInResult* operator->()
    {
        return this;
    }
    /**
     * サインインしたGS2アカウントを取得
     *
     * @return サインインしたGS2アカウント
     */
    const optional<Account>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * サインインしたGS2アカウントを設定
     *
     * @param item サインインしたGS2アカウント
     */
    void setItem(const Account& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * GS2-Console にアクセスするのに使用するトークンを取得
     *
     * @return GS2-Console にアクセスするのに使用するトークン
     */
    const optional<StringHolder>& getAccountToken() const
    {
        return ensureData().accountToken;
    }

    /**
     * GS2-Console にアクセスするのに使用するトークンを設定
     *
     * @param accountToken GS2-Console にアクセスするのに使用するトークン
     */
    void setAccountToken(const Char* accountToken)
    {
        ensureData().accountToken.emplace(accountToken);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_PROJECT_CONTROL_SIGNINRESULT_HPP_