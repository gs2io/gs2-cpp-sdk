/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#ifndef GS2_CORE_CONTROL_GS2USERREQUEST_HPP_
#define GS2_CORE_CONTROL_GS2USERREQUEST_HPP_

#include "Gs2BasicRequest.hpp"

GS2_START_OF_NAMESPACE

class Gs2UserRequest : public Gs2BasicRequest
{
private:
    class Data : public Gs2Object
    {
    public:
        /** アクセストークン */
        gs2::optional<StringHolder> accessToken;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            accessToken(data.accessToken)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            accessToken(std::move(data.accessToken))
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
    Gs2UserRequest() :
        m_pData(nullptr)
    {}

    Gs2UserRequest(const Gs2UserRequest& gs2UserRequest) :
        Gs2BasicRequest(gs2UserRequest),
        m_pData(gs2UserRequest.m_pData != nullptr ? new Data(*gs2UserRequest.m_pData) : nullptr)
    {}

    Gs2UserRequest(Gs2UserRequest&& gs2UserRequest) :
        Gs2BasicRequest(std::move(gs2UserRequest)),
        m_pData(gs2UserRequest.m_pData)
    {
        gs2UserRequest.m_pData = nullptr;
    }

    ~Gs2UserRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Gs2UserRequest& operator=(const Gs2UserRequest& gs2UserRequest)
    {
        Gs2UserRequest::operator=(gs2UserRequest);

        if (&gs2UserRequest != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = new Data(*gs2UserRequest.m_pData);
        }

        return *this;
    }

    Gs2UserRequest& operator=(Gs2UserRequest&& gs2UserRequest)
    {
        Gs2UserRequest::operator=(std::move(gs2UserRequest));

        if (&gs2UserRequest != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = gs2UserRequest.m_pData;
            gs2UserRequest.m_pData = nullptr;
        }

        return *this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    virtual const gs2::optional<StringHolder>& getAccessToken() const {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(const Char* accessToken) {
        ensureData().accessToken.emplace(accessToken);
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    Gs2UserRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    Gs2UserRequest& withGs2ClientId(const Char* gs2ClientId)
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
    Gs2UserRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    Gs2UserRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    Gs2UserRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_CONTROL_GS2USERREQUEST_HPP_
