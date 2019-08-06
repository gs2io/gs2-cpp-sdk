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
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../model/model.hpp"

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            issuePasswordToken(data.issuePasswordToken)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            issuePasswordToken(std::move(data.issuePasswordToken))
        {}

        virtual ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "issuePasswordToken") == 0) {
                if (jsonValue.IsString())
                {
                    this->issuePasswordToken.emplace(jsonValue.GetString());
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
    ForgetResult() :
        m_pData(nullptr)
    {}

    ForgetResult(const ForgetResult& forgetResult) :
        Gs2Object(forgetResult),
        m_pData(forgetResult.m_pData != nullptr ? new Data(*forgetResult.m_pData) : nullptr)
    {}

    ForgetResult(ForgetResult&& forgetResult) :
        Gs2Object(std::move(forgetResult)),
        m_pData(forgetResult.m_pData)
    {
        forgetResult.m_pData = nullptr;
    }

    ~ForgetResult()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    ForgetResult& operator=(const ForgetResult& forgetResult)
    {
        Gs2Object::operator=(forgetResult);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*forgetResult.m_pData);

        return *this;
    }

    ForgetResult& operator=(ForgetResult&& forgetResult)
    {
        Gs2Object::operator=(std::move(forgetResult));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = forgetResult.m_pData;
        forgetResult.m_pData = nullptr;

        return *this;
    }

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
    void setIssuePasswordToken(const Char* issuePasswordToken)
    {
        ensureData().issuePasswordToken.emplace(issuePasswordToken);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_PROJECT_CONTROL_FORGETRESULT_HPP_