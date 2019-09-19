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

#ifndef GS2_PROJECT_CONTROL_ISSUEPASSWORDREQUEST_HPP_
#define GS2_PROJECT_CONTROL_ISSUEPASSWORDREQUEST_HPP_

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
 * パスワードを再発行 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class IssuePasswordRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** パスワードを再発行するために必要なトークン */
        optional<StringHolder> issuePasswordToken;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            issuePasswordToken(data.issuePasswordToken)
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
    IssuePasswordRequest() = default;
    IssuePasswordRequest(const IssuePasswordRequest& issuePasswordRequest) = default;
    IssuePasswordRequest(IssuePasswordRequest&& issuePasswordRequest) = default;
    ~IssuePasswordRequest() GS2_OVERRIDE = default;

    IssuePasswordRequest& operator=(const IssuePasswordRequest& issuePasswordRequest) = default;
    IssuePasswordRequest& operator=(IssuePasswordRequest&& issuePasswordRequest) = default;

    IssuePasswordRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(IssuePasswordRequest);
    }

    const IssuePasswordRequest* operator->() const
    {
        return this;
    }

    IssuePasswordRequest* operator->()
    {
        return this;
    }

    /**
     * パスワードを再発行するために必要なトークンを取得
     *
     * @return パスワードを再発行するために必要なトークン
     */
    const optional<StringHolder>& getIssuePasswordToken() const
    {
        return ensureData().issuePasswordToken;
    }

    /**
     * パスワードを再発行するために必要なトークンを設定
     *
     * @param issuePasswordToken パスワードを再発行するために必要なトークン
     */
    void setIssuePasswordToken(StringHolder issuePasswordToken)
    {
        ensureData().issuePasswordToken.emplace(std::move(issuePasswordToken));
    }

    /**
     * パスワードを再発行するために必要なトークンを設定
     *
     * @param issuePasswordToken パスワードを再発行するために必要なトークン
     */
    IssuePasswordRequest& withIssuePasswordToken(StringHolder issuePasswordToken)
    {
        ensureData().issuePasswordToken.emplace(std::move(issuePasswordToken));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    IssuePasswordRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    IssuePasswordRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_ISSUEPASSWORDREQUEST_HPP_