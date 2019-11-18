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

#ifndef GS2_PROJECT_CONTROL_ISSUEACCOUNTTOKENRESULT_HPP_
#define GS2_PROJECT_CONTROL_ISSUEACCOUNTTOKENRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/project/model/model.hpp>
#include <memory>

namespace gs2 { namespace project
{

/**
 * 指定したアカウント名のアカウントトークンを発行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class IssueAccountTokenResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** GS2-Console にアクセスするのに使用するトークン */
        optional<StringHolder> accountToken;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            accountToken(data.accountToken)
        {
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "accountToken") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->accountToken.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    IssueAccountTokenResult() = default;
    IssueAccountTokenResult(const IssueAccountTokenResult& issueAccountTokenResult) = default;
    IssueAccountTokenResult(IssueAccountTokenResult&& issueAccountTokenResult) = default;
    ~IssueAccountTokenResult() = default;

    IssueAccountTokenResult& operator=(const IssueAccountTokenResult& issueAccountTokenResult) = default;
    IssueAccountTokenResult& operator=(IssueAccountTokenResult&& issueAccountTokenResult) = default;

    IssueAccountTokenResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(IssueAccountTokenResult);
    }

    const IssueAccountTokenResult* operator->() const
    {
        return this;
    }

    IssueAccountTokenResult* operator->()
    {
        return this;
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
    void setAccountToken(StringHolder accountToken)
    {
        ensureData().accountToken.emplace(std::move(accountToken));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<IssueAccountTokenResult> AsyncIssueAccountTokenResult;

} }

#endif //GS2_PROJECT_CONTROL_ISSUEACCOUNTTOKENRESULT_HPP_