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

#ifndef GS2_PROJECT_CONTROL_VERIFYREQUEST_HPP_
#define GS2_PROJECT_CONTROL_VERIFYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ProjectConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace project
{

/**
 * GS2アカウントを有効化します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class VerifyRequest : public Gs2BasicRequest, public Gs2Project
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 有効化に使用するトークン */
        optional<StringHolder> verifyToken;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            verifyToken(data.verifyToken)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            verifyToken(std::move(data.verifyToken))
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
    VerifyRequest() :
        m_pData(nullptr)
    {}

    VerifyRequest(const VerifyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Project(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    VerifyRequest(VerifyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Project(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~VerifyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    VerifyRequest& operator=(const VerifyRequest& verifyRequest)
    {
        Gs2BasicRequest::operator=(verifyRequest);
        Gs2Project::operator=(verifyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*verifyRequest.m_pData);

        return *this;
    }

    VerifyRequest& operator=(VerifyRequest&& verifyRequest)
    {
        Gs2BasicRequest::operator=(std::move(verifyRequest));
        Gs2Project::operator=(std::move(verifyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = verifyRequest.m_pData;
        verifyRequest.m_pData = nullptr;

        return *this;
    }

    const VerifyRequest* operator->() const
    {
        return this;
    }

    VerifyRequest* operator->()
    {
        return this;
    }

    /**
     * 有効化に使用するトークンを取得
     *
     * @return 有効化に使用するトークン
     */
    const optional<StringHolder>& getVerifyToken() const
    {
        return ensureData().verifyToken;
    }

    /**
     * 有効化に使用するトークンを設定
     *
     * @param verifyToken 有効化に使用するトークン
     */
    void setVerifyToken(const Char* verifyToken)
    {
        ensureData().verifyToken.emplace(verifyToken);
    }

    /**
     * 有効化に使用するトークンを設定
     *
     * @param verifyToken 有効化に使用するトークン
     */
    VerifyRequest& withVerifyToken(const Char* verifyToken)
    {
        ensureData().verifyToken.emplace(verifyToken);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    VerifyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    VerifyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    VerifyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    VerifyRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_PROJECT_CONTROL_VERIFYREQUEST_HPP_