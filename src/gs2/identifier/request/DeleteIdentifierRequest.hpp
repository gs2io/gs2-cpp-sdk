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

#ifndef GS2_IDENTIFIER_CONTROL_DELETEIDENTIFIERREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_DELETEIDENTIFIERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2IdentifierConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace identifier
{

/**
 * クレデンシャルを削除します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteIdentifierRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ユーザー名 */
        optional<StringHolder> userName;
        /** クライアントID */
        optional<StringHolder> clientId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            userName(data.userName),
            clientId(data.clientId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            userName(std::move(data.userName)),
            clientId(std::move(data.clientId))
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
    DeleteIdentifierRequest() :
        m_pData(nullptr)
    {}

    DeleteIdentifierRequest(const DeleteIdentifierRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Identifier(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteIdentifierRequest(DeleteIdentifierRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Identifier(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteIdentifierRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteIdentifierRequest& operator=(const DeleteIdentifierRequest& deleteIdentifierRequest)
    {
        Gs2BasicRequest::operator=(deleteIdentifierRequest);
        Gs2Identifier::operator=(deleteIdentifierRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteIdentifierRequest.m_pData);

        return *this;
    }

    DeleteIdentifierRequest& operator=(DeleteIdentifierRequest&& deleteIdentifierRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteIdentifierRequest));
        Gs2Identifier::operator=(std::move(deleteIdentifierRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteIdentifierRequest.m_pData;
        deleteIdentifierRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteIdentifierRequest* operator->() const
    {
        return this;
    }

    DeleteIdentifierRequest* operator->()
    {
        return this;
    }

    /**
     * ユーザー名を取得
     *
     * @return ユーザー名
     */
    const optional<StringHolder>& getUserName() const
    {
        return ensureData().userName;
    }

    /**
     * ユーザー名を設定
     *
     * @param userName ユーザー名
     */
    void setUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
    }

    /**
     * ユーザー名を設定
     *
     * @param userName ユーザー名
     */
    DeleteIdentifierRequest& withUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
        return *this;
    }

    /**
     * クライアントIDを取得
     *
     * @return クライアントID
     */
    const optional<StringHolder>& getClientId() const
    {
        return ensureData().clientId;
    }

    /**
     * クライアントIDを設定
     *
     * @param clientId クライアントID
     */
    void setClientId(const Char* clientId)
    {
        ensureData().clientId.emplace(clientId);
    }

    /**
     * クライアントIDを設定
     *
     * @param clientId クライアントID
     */
    DeleteIdentifierRequest& withClientId(const Char* clientId)
    {
        ensureData().clientId.emplace(clientId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteIdentifierRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteIdentifierRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteIdentifierRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteIdentifierRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_IDENTIFIER_CONTROL_DELETEIDENTIFIERREQUEST_HPP_