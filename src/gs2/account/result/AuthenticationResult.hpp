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
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"
#include <memory>

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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            body(data.body),
            signature(data.signature)
        {
            if (data.item)
            {
                item = data.item->deepCopy();
            }
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "item") == 0)
            {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = detail::json::getObject(jsonValue);
                    this->item.emplace();
                    detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
                }
            }
            else if (std::strcmp(name_, "body") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->body.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "signature") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->signature.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    AuthenticationResult() = default;
    AuthenticationResult(const AuthenticationResult& authenticationResult) = default;
    AuthenticationResult(AuthenticationResult&& authenticationResult) = default;
    ~AuthenticationResult() = default;

    AuthenticationResult& operator=(const AuthenticationResult& authenticationResult) = default;
    AuthenticationResult& operator=(AuthenticationResult&& authenticationResult) = default;

    AuthenticationResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(AuthenticationResult);
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
    void setItem(Account item)
    {
        ensureData().item.emplace(std::move(item));
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
    void setBody(StringHolder body)
    {
        ensureData().body.emplace(std::move(body));
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
    void setSignature(StringHolder signature)
    {
        ensureData().signature.emplace(std::move(signature));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<AuthenticationResult> AsyncAuthenticationResult;

} }

#endif //GS2_ACCOUNT_CONTROL_AUTHENTICATIONRESULT_HPP_