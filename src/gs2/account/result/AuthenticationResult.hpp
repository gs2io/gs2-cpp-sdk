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
 * ゲームプレイヤーアカウントを認証 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class AuthenticationResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゲームプレイヤーアカウント */
        optional<Account> item;
        /** 署名対象のアカウント情報 */
        optional<StringHolder> body;
        /** 署名 */
        optional<StringHolder> signature;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            item(data.item),
            body(data.body),
            signature(data.signature)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            item(std::move(data.item)),
            body(std::move(data.body)),
            signature(std::move(data.signature))
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
                    const auto& jsonObject = jsonValue.GetObject();
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name, "body") == 0) {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "signature") == 0) {
                if (jsonValue.IsString())
                {
                    this->signature.emplace(jsonValue.GetString());
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
     * ゲームプレイヤーアカウントを取得
     *
     * @return ゲームプレイヤーアカウント
     */
    const optional<Account>& getItem() const
    {
        return ensureData().item;
    }

    /**
     * ゲームプレイヤーアカウントを設定
     *
     * @param item ゲームプレイヤーアカウント
     */
    void setItem(const Account& item)
    {
        ensureData().item.emplace(item);
    }

    /**
     * 署名対象のアカウント情報を取得
     *
     * @return 署名対象のアカウント情報
     */
    const optional<StringHolder>& getBody() const
    {
        return ensureData().body;
    }

    /**
     * 署名対象のアカウント情報を設定
     *
     * @param body 署名対象のアカウント情報
     */
    void setBody(const Char* body)
    {
        ensureData().body.emplace(body);
    }

    /**
     * 署名を取得
     *
     * @return 署名
     */
    const optional<StringHolder>& getSignature() const
    {
        return ensureData().signature;
    }

    /**
     * 署名を設定
     *
     * @param signature 署名
     */
    void setSignature(const Char* signature)
    {
        ensureData().signature.emplace(signature);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_AUTHENTICATIONRESULT_HPP_