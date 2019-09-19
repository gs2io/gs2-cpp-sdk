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

#ifndef GS2_AUTH_CONTROL_LOGINBYSIGNATURERESULT_HPP_
#define GS2_AUTH_CONTROL_LOGINBYSIGNATURERESULT_HPP_

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

namespace gs2 { namespace auth
{

/**
 * 指定したユーザIDでGS2にログインし、アクセストークンを取得します のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class LoginBySignatureResult : public Gs2Object
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

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            token(data.token),
            userId(data.userId),
            expire(data.expire)
        {
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "token") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->token.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "expire") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->expire = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    LoginBySignatureResult() = default;
    LoginBySignatureResult(const LoginBySignatureResult& loginBySignatureResult) = default;
    LoginBySignatureResult(LoginBySignatureResult&& loginBySignatureResult) = default;
    ~LoginBySignatureResult() = default;

    LoginBySignatureResult& operator=(const LoginBySignatureResult& loginBySignatureResult) = default;
    LoginBySignatureResult& operator=(LoginBySignatureResult&& loginBySignatureResult) = default;

    LoginBySignatureResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(LoginBySignatureResult);
    }

    const LoginBySignatureResult* operator->() const
    {
        return this;
    }

    LoginBySignatureResult* operator->()
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
    void setToken(StringHolder token)
    {
        ensureData().token.emplace(std::move(token));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
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

typedef AsyncResult<LoginBySignatureResult> AsyncLoginBySignatureResult;

} }

#endif //GS2_AUTH_CONTROL_LOGINBYSIGNATURERESULT_HPP_