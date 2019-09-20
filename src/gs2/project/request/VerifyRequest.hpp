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

#ifndef GS2_PROJECT_CONTROL_VERIFYREQUEST_HPP_
#define GS2_PROJECT_CONTROL_VERIFYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/project/Gs2ProjectConst.hpp>
#include <gs2/project/model/model.hpp>
#include <memory>

namespace gs2 { namespace project
{

/**
 * GS2アカウントを有効化します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class VerifyRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** 有効化に使用するトークン */
        optional<StringHolder> verifyToken;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            verifyToken(data.verifyToken)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    VerifyRequest() = default;
    VerifyRequest(const VerifyRequest& verifyRequest) = default;
    VerifyRequest(VerifyRequest&& verifyRequest) = default;
    ~VerifyRequest() GS2_OVERRIDE = default;

    VerifyRequest& operator=(const VerifyRequest& verifyRequest) = default;
    VerifyRequest& operator=(VerifyRequest&& verifyRequest) = default;

    VerifyRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(VerifyRequest);
    }

    const VerifyRequest* operator->() const
    {
        return this;
    }

    VerifyRequest* operator->()
    {
        return this;
    }

    /**
     * 有効化に使用するトークンを取得
     *
     * @return 有効化に使用するトークン
     */
    const optional<StringHolder>& getVerifyToken() const
    {
        return ensureData().verifyToken;
    }

    /**
     * 有効化に使用するトークンを設定
     *
     * @param verifyToken 有効化に使用するトークン
     */
    void setVerifyToken(StringHolder verifyToken)
    {
        ensureData().verifyToken.emplace(std::move(verifyToken));
    }

    /**
     * 有効化に使用するトークンを設定
     *
     * @param verifyToken 有効化に使用するトークン
     */
    VerifyRequest& withVerifyToken(StringHolder verifyToken)
    {
        ensureData().verifyToken.emplace(std::move(verifyToken));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    VerifyRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    VerifyRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_VERIFYREQUEST_HPP_