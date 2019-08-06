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
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            accountToken(data.accountToken)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            accountToken(std::move(data.accountToken))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "accountToken") == 0) {
                if (jsonValue.IsString())
                {
                    this->accountToken.emplace(jsonValue.GetString());
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
    IssueAccountTokenResult() :
        m_pData(nullptr)
    {}

    IssueAccountTokenResult(const IssueAccountTokenResult& issueAccountTokenResult) :
        Gs2Object(issueAccountTokenResult),
        m_pData(issueAccountTokenResult.m_pData != nullptr ? new Data(*issueAccountTokenResult.m_pData) : nullptr)
    {}

    IssueAccountTokenResult(IssueAccountTokenResult&& issueAccountTokenResult) :
        Gs2Object(std::move(issueAccountTokenResult)),
        m_pData(issueAccountTokenResult.m_pData)
    {
        issueAccountTokenResult.m_pData = nullptr;
    }

    ~IssueAccountTokenResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    IssueAccountTokenResult& operator=(const IssueAccountTokenResult& issueAccountTokenResult)
    {
        Gs2Object::operator=(issueAccountTokenResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*issueAccountTokenResult.m_pData);

        return *this;
    }

    IssueAccountTokenResult& operator=(IssueAccountTokenResult&& issueAccountTokenResult)
    {
        Gs2Object::operator=(std::move(issueAccountTokenResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = issueAccountTokenResult.m_pData;
        issueAccountTokenResult.m_pData = nullptr;

        return *this;
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
    void setAccountToken(const Char* accountToken)
    {
        ensureData().accountToken.emplace(accountToken);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_PROJECT_CONTROL_ISSUEACCOUNTTOKENRESULT_HPP_