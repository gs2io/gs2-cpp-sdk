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

#ifndef GS2_EZ_ACCOUNT_EZAUTHENTICATIONRESULT_HPP_
#define GS2_EZ_ACCOUNT_EZAUTHENTICATIONRESULT_HPP_

#include "../model/model.hpp"
#include <gs2/core/AsyncResult.hpp>
#include <gs2/account/result/AuthenticationResult.hpp>


namespace gs2 { namespace ez { namespace account {

class EzAuthenticationResult : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** ゲームプレイヤーアカウント */
        EzAccount item;
        /** 署名対象のアカウント情報 */
        StringHolder body;
        /** 署名 */
        StringHolder signature;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            body(data.body),
            signature(data.signature)
        {
            item = data.item.deepCopy();
        }

        Data(Data&& data) = default;

        Data(const gs2::account::AuthenticationResult& authenticationResult) :
            item(*authenticationResult.getItem()),
            body(*authenticationResult.getBody()),
            signature(*authenticationResult.getSignature())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzAuthenticationResult() = default;
    EzAuthenticationResult(const EzAuthenticationResult& result) = default;
    EzAuthenticationResult(EzAuthenticationResult&& result) = default;
    ~EzAuthenticationResult() = default;

    EzAuthenticationResult(gs2::account::AuthenticationResult result) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(result)
    {}

    EzAuthenticationResult& operator=(const EzAuthenticationResult& result) = default;
    EzAuthenticationResult& operator=(EzAuthenticationResult&& result) = default;

    EzAuthenticationResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzAuthenticationResult);
    }

    static bool isConvertible(const gs2::account::AuthenticationResult& result)
    {
        return
            result.getItem().has_value() &&
            result.getBody().has_value() &&
            result.getSignature().has_value();
    }

    // ========================================
    //   Getters
    // ========================================

    const EzAccount& getItem() const
    {
        return ensureData().item;
    }

    const StringHolder& getBody() const
    {
        return ensureData().body;
    }

    const StringHolder& getSignature() const
    {
        return ensureData().signature;
    }
};

typedef gs2::AsyncResult<EzAuthenticationResult> AsyncEzAuthenticationResult;

}}}

#endif //GS2_EZ_ACCOUNT_EZAUTHENTICATIONRESULT_HPP_