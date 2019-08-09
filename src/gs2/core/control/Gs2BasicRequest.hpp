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

#ifndef GS2_CORE_CONTROL_GS2BASICREQUEST_HPP_
#define GS2_CORE_CONTROL_GS2BASICREQUEST_HPP_

#include "../Gs2Object.hpp"
#include "../util/StringHolder.hpp"
#include "../external/optional/optional.hpp"

GS2_START_OF_NAMESPACE

class Gs2BasicRequest : public Gs2Object
{
private:
    class Data : public Gs2Object
    {
    public:
        /** GS2認証クライアントID */
        gs2::optional<StringHolder> gs2ClientId;
        /** タイムスタンプ */
        gs2::optional<Int64> gs2Timestamp;
        /** GS2認証署名 */
        gs2::optional<StringHolder> gs2RequestSign;
        /** GS2リクエストID */
        gs2::optional<StringHolder> gs2RequestId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gs2ClientId(data.gs2ClientId),
            gs2Timestamp(data.gs2Timestamp),
            gs2RequestSign(data.gs2RequestSign),
            gs2RequestId(data.gs2RequestId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gs2ClientId(std::move(data.gs2ClientId)),
            gs2Timestamp(std::move(data.gs2Timestamp)),
            gs2RequestSign(std::move(data.gs2RequestSign)),
            gs2RequestId(std::move(data.gs2RequestId))
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
    Gs2BasicRequest() :
        m_pData(nullptr)
    {}

    Gs2BasicRequest(const Gs2BasicRequest& gs2BasicRequest) :
        Gs2Object(gs2BasicRequest),
        m_pData(gs2BasicRequest.m_pData != nullptr ? new Data(*gs2BasicRequest.m_pData) : nullptr)
    {}

    Gs2BasicRequest(Gs2BasicRequest&& gs2BasicRequest) :
        Gs2Object(std::move(gs2BasicRequest)),
        m_pData(gs2BasicRequest.m_pData)
    {
        gs2BasicRequest.m_pData = nullptr;
    }

    virtual ~Gs2BasicRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Gs2BasicRequest& operator=(const Gs2BasicRequest& gs2BasicRequest)
    {
        Gs2Object::operator=(gs2BasicRequest);

        if (&gs2BasicRequest != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = new Data(*gs2BasicRequest.m_pData);
        }

        return *this;
    }

    Gs2BasicRequest& operator=(Gs2BasicRequest&& gs2BasicRequest)
    {
        Gs2Object::operator=(std::move(gs2BasicRequest));

        if (&gs2BasicRequest != this)
        {
            if (m_pData != nullptr)
            {
                delete m_pData;
            }
            m_pData = gs2BasicRequest.m_pData;
            gs2BasicRequest.m_pData = nullptr;
        }

        return *this;
    }

    /**
     * GS2認証クライアントIDを取得。
     *
     * @return GS2認証クライアントID
     */
    const gs2::optional<StringHolder>& getGs2ClientId() const
    {
        return ensureData().gs2ClientId;
    }

    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    void setGs2ClientId(const Char* gs2ClientId)
    {
        ensureData().gs2ClientId.emplace(gs2ClientId);
    }

    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    Gs2BasicRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを取得。
     *
     * @return タイムスタンプ
     */
    const gs2::optional<Int64>& getGs2Timestamp() const
    {
        return ensureData().gs2Timestamp;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    void setGs2Timestamp(Int64 gs2Timestamp)
    {
        ensureData().gs2Timestamp = gs2Timestamp;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    Gs2BasicRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を取得。
     *
     * @return GS2認証署名
     */
    const gs2::optional<StringHolder>& getGs2RequestSign() const
    {
        return ensureData().gs2RequestSign;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    void setGs2RequestSign(const Char* gs2RequestSign)
    {
        ensureData().gs2RequestSign.emplace(gs2RequestSign);
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    Gs2BasicRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを取得。
     *
     * @return GS2リクエストID
     */
    const gs2::optional<StringHolder>& getRequestId() const
    {
        return ensureData().gs2RequestId;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    void setRequestId(const Char* gs2RequestId)
    {
        ensureData().gs2RequestId.emplace(gs2RequestId);
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    Gs2BasicRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const = 0;

    virtual const Char* getFunctionName() const = 0;
};

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_CONTROL_GS2BASICREQUEST_HPP_
