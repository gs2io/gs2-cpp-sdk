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

#ifndef GS2_PROJECT_CONTROL_ISSUEACCOUNTTOKENREQUEST_HPP_
#define GS2_PROJECT_CONTROL_ISSUEACCOUNTTOKENREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ProjectConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace project
{

/**
 * 指定したアカウント名のアカウントトークンを発行 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class IssueAccountTokenRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** GS2アカウントの名前 */
        optional<StringHolder> accountName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accountName(data.accountName)
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
    IssueAccountTokenRequest() = default;
    IssueAccountTokenRequest(const IssueAccountTokenRequest& issueAccountTokenRequest) = default;
    IssueAccountTokenRequest(IssueAccountTokenRequest&& issueAccountTokenRequest) = default;
    ~IssueAccountTokenRequest() GS2_OVERRIDE = default;

    IssueAccountTokenRequest& operator=(const IssueAccountTokenRequest& issueAccountTokenRequest) = default;
    IssueAccountTokenRequest& operator=(IssueAccountTokenRequest&& issueAccountTokenRequest) = default;

    IssueAccountTokenRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(IssueAccountTokenRequest);
    }

    const IssueAccountTokenRequest* operator->() const
    {
        return this;
    }

    IssueAccountTokenRequest* operator->()
    {
        return this;
    }

    /**
     * GS2アカウントの名前を取得
     *
     * @return GS2アカウントの名前
     */
    const optional<StringHolder>& getAccountName() const
    {
        return ensureData().accountName;
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param accountName GS2アカウントの名前
     */
    void setAccountName(StringHolder accountName)
    {
        ensureData().accountName.emplace(std::move(accountName));
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param accountName GS2アカウントの名前
     */
    IssueAccountTokenRequest& withAccountName(StringHolder accountName)
    {
        ensureData().accountName.emplace(std::move(accountName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    IssueAccountTokenRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    IssueAccountTokenRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_ISSUEACCOUNTTOKENREQUEST_HPP_