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
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            newPassword(data.newPassword)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            newPassword(std::move(data.newPassword))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "newPassword") == 0) {
                if (jsonValue.IsString())
                {
                    this->newPassword.emplace(jsonValue.GetString());
                }
            }
        }
    };

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    IssuePasswordResult() :
        m_pData(nullptr)
    {}

    IssuePasswordResult(const IssuePasswordResult& issuePasswordResult) :
        Gs2Object(issuePasswordResult),
        m_pData(issuePasswordResult.m_pData != nullptr ? new Data(*issuePasswordResult.m_pData) : nullptr)
    {}

    IssuePasswordResult(IssuePasswordResult&& issuePasswordResult) :
        Gs2Object(std::move(issuePasswordResult)),
        m_pData(issuePasswordResult.m_pData)
    {
        issuePasswordResult.m_pData = nullptr;
    }

    ~IssuePasswordResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    IssuePasswordResult& operator=(const IssuePasswordResult& issuePasswordResult)
    {
        Gs2Object::operator=(issuePasswordResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*issuePasswordResult.m_pData);

        return *this;
    }

    IssuePasswordResult& operator=(IssuePasswordResult&& issuePasswordResult)
    {
        Gs2Object::operator=(std::move(issuePasswordResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = issuePasswordResult.m_pData;
        issuePasswordResult.m_pData = nullptr;

        return *this;
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
    void setNewPassword(const Char* newPassword)
    {
        ensureData().newPassword.emplace(newPassword);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_PROJECT_CONTROL_ISSUEPASSWORDRESULT_HPP_