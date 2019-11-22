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
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/identifier/model/model.hpp>
#include <memory>

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

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    LoginResult() = default;
    LoginResult(const LoginResult& loginResult) = default;
    LoginResult(LoginResult&& loginResult) = default;
    ~LoginResult() = default;

    LoginResult& operator=(const LoginResult& loginResult) = default;
    LoginResult& operator=(LoginResult&& loginResult) = default;

    LoginResult deepCopy() const;

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
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
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
    void setTokenType(StringHolder tokenType)
    {
        ensureData().tokenType.emplace(std::move(tokenType));
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

typedef AsyncResult<LoginResult> AsyncLoginResult;

} }

#endif //GS2_IDENTIFIER_CONTROL_LOGINRESULT_HPP_