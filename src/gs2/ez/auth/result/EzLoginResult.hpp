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

#ifndef GS2_EZ_AUTH_EZLOGINRESULT_HPP_
#define GS2_EZ_AUTH_EZLOGINRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/auth/result/LoginBySignatureResult.hpp>


namespace gs2 { namespace ez { namespace auth {

class EzLoginResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** アクセストークン */
        StringHolder token;
        /** ユーザーID */
        StringHolder userId;
        /** 有効期限 */
        Int64 expire;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            token(data.token),
            userId(data.userId),
            expire(data.expire)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::auth::LoginBySignatureResult& loginBySignatureResult) :
            token(loginBySignatureResult.getToken() ? *loginBySignatureResult.getToken() : StringHolder()),
            userId(loginBySignatureResult.getUserId() ? *loginBySignatureResult.getUserId() : StringHolder()),
            expire(loginBySignatureResult.getExpire() ? *loginBySignatureResult.getExpire() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzLoginResult() = default;
    EzLoginResult(const EzLoginResult& result) = default;
    EzLoginResult(EzLoginResult&& result) = default;
    ~EzLoginResult() = default;

    EzLoginResult(gs2::auth::LoginBySignatureResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzLoginResult& operator=(const EzLoginResult& result) = default;
    EzLoginResult& operator=(EzLoginResult&& result) = default;

    EzLoginResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzLoginResult);
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getToken() const
    {
        return ensureData().token;
    }

    const StringHolder& getUserId() const
    {
        return ensureData().userId;
    }

    Int64 getExpire() const
    {
        return ensureData().expire;
    }
};

typedef gs2::AsyncResult<EzLoginResult> AsyncEzLoginResult;

}}}

#endif //GS2_EZ_AUTH_EZLOGINRESULT_HPP_