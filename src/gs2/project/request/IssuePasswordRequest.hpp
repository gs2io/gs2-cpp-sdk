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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ProjectConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
    {
    public:
        /** パスワードを再発行するために必要なトークン */
        optional<StringHolder> issuePasswordToken;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            issuePasswordToken(data.issuePasswordToken)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            issuePasswordToken(std::move(data.issuePasswordToken))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    IssuePasswordRequest() :
        m_pData(nullptr)
    {}

    IssuePasswordRequest(const IssuePasswordRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Project(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    IssuePasswordRequest(IssuePasswordRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Project(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~IssuePasswordRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    IssuePasswordRequest& operator=(const IssuePasswordRequest& issuePasswordRequest)
    {
        Gs2BasicRequest::operator=(issuePasswordRequest);
        Gs2Project::operator=(issuePasswordRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*issuePasswordRequest.m_pData);

        return *this;
    }

    IssuePasswordRequest& operator=(IssuePasswordRequest&& issuePasswordRequest)
    {
        Gs2BasicRequest::operator=(std::move(issuePasswordRequest));
        Gs2Project::operator=(std::move(issuePasswordRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = issuePasswordRequest.m_pData;
        issuePasswordRequest.m_pData = nullptr;

        return *this;
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
    void setIssuePasswordToken(const Char* issuePasswordToken)
    {
        ensureData().issuePasswordToken.emplace(issuePasswordToken);
    }

    /**
     * パスワードを再発行するために必要なトークンを設定
     *
     * @param issuePasswordToken パスワードを再発行するために必要なトークン
     */
    IssuePasswordRequest& withIssuePasswordToken(const Char* issuePasswordToken)
    {
        ensureData().issuePasswordToken.emplace(issuePasswordToken);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    IssuePasswordRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    IssuePasswordRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    IssuePasswordRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    IssuePasswordRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_ISSUEPASSWORDREQUEST_HPP_