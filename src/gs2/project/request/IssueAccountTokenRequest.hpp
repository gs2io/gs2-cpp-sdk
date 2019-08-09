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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ProjectConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
    {
    public:
        /** GS2アカウントの名前 */
        optional<StringHolder> accountName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            accountName(data.accountName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            accountName(std::move(data.accountName))
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
    IssueAccountTokenRequest() :
        m_pData(nullptr)
    {}

    IssueAccountTokenRequest(const IssueAccountTokenRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Project(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    IssueAccountTokenRequest(IssueAccountTokenRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Project(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~IssueAccountTokenRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    IssueAccountTokenRequest& operator=(const IssueAccountTokenRequest& issueAccountTokenRequest)
    {
        Gs2BasicRequest::operator=(issueAccountTokenRequest);
        Gs2Project::operator=(issueAccountTokenRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*issueAccountTokenRequest.m_pData);

        return *this;
    }

    IssueAccountTokenRequest& operator=(IssueAccountTokenRequest&& issueAccountTokenRequest)
    {
        Gs2BasicRequest::operator=(std::move(issueAccountTokenRequest));
        Gs2Project::operator=(std::move(issueAccountTokenRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = issueAccountTokenRequest.m_pData;
        issueAccountTokenRequest.m_pData = nullptr;

        return *this;
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
    void setAccountName(const Char* accountName)
    {
        ensureData().accountName.emplace(accountName);
    }

    /**
     * GS2アカウントの名前を設定
     *
     * @param accountName GS2アカウントの名前
     */
    IssueAccountTokenRequest& withAccountName(const Char* accountName)
    {
        ensureData().accountName.emplace(accountName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    IssueAccountTokenRequest& withGs2ClientId(const Char* gs2ClientId)
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
    IssueAccountTokenRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    IssueAccountTokenRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    IssueAccountTokenRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_ISSUEACCOUNTTOKENREQUEST_HPP_