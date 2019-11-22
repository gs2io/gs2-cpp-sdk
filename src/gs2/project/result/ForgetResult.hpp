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

#ifndef GS2_PROJECT_CONTROL_FORGETRESULT_HPP_
#define GS2_PROJECT_CONTROL_FORGETRESULT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/AsyncResult.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/project/model/model.hpp>
#include <memory>

namespace gs2 { namespace project
{

/**
 * パスワード再発行トークンを取得 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class ForgetResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** パスワードを再発行するために必要なトークン */
        optional<StringHolder> issuePasswordToken;

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
    ForgetResult() = default;
    ForgetResult(const ForgetResult& forgetResult) = default;
    ForgetResult(ForgetResult&& forgetResult) = default;
    ~ForgetResult() = default;

    ForgetResult& operator=(const ForgetResult& forgetResult) = default;
    ForgetResult& operator=(ForgetResult&& forgetResult) = default;

    ForgetResult deepCopy() const;

    const ForgetResult* operator->() const
    {
        return this;
    }

    ForgetResult* operator->()
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


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<ForgetResult> AsyncForgetResult;

} }

#endif //GS2_PROJECT_CONTROL_FORGETRESULT_HPP_