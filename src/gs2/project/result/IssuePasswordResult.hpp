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

#ifndef GS2_PROJECT_CONTROL_ISSUEPASSWORDRESULT_HPP_
#define GS2_PROJECT_CONTROL_ISSUEPASSWORDRESULT_HPP_

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

namespace gs2 { namespace project
{

/**
 * パスワードを再発行 のレスポンスモデル
 *
 * @author Game Server Services, Inc.
 */
class IssuePasswordResult : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 新しいパスワード */
        optional<StringHolder> newPassword;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            newPassword(data.newPassword)
        {
        }

        Data(Data&& data) = default;

        virtual ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "newPassword") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->newPassword.emplace(jsonValue.GetString());
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    IssuePasswordResult() = default;
    IssuePasswordResult(const IssuePasswordResult& issuePasswordResult) = default;
    IssuePasswordResult(IssuePasswordResult&& issuePasswordResult) = default;
    ~IssuePasswordResult() = default;

    IssuePasswordResult& operator=(const IssuePasswordResult& issuePasswordResult) = default;
    IssuePasswordResult& operator=(IssuePasswordResult&& issuePasswordResult) = default;

    IssuePasswordResult deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(IssuePasswordResult);
    }

    const IssuePasswordResult* operator->() const
    {
        return this;
    }

    IssuePasswordResult* operator->()
    {
        return this;
    }
    /**
     * 新しいパスワードを取得
     *
     * @return 新しいパスワード
     */
    const optional<StringHolder>& getNewPassword() const
    {
        return ensureData().newPassword;
    }

    /**
     * 新しいパスワードを設定
     *
     * @param newPassword 新しいパスワード
     */
    void setNewPassword(StringHolder newPassword)
    {
        ensureData().newPassword.emplace(std::move(newPassword));
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

typedef AsyncResult<IssuePasswordResult> AsyncIssuePasswordResult;

} }

#endif //GS2_PROJECT_CONTROL_ISSUEPASSWORDRESULT_HPP_