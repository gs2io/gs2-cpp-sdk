/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_IDENTIFIER_CONTROL_DELETEUSERREQUEST_HPP_
#define GS2_IDENTIFIER_CONTROL_DELETEUSERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2IdentifierConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace identifier
{

/**
 * @author Game Server Services, Inc.
 */
class DeleteUserRequest : public Gs2BasicRequest, public Gs2Identifier
{
public:
    constexpr static const Char* const FUNCTION = "DeleteUser";

private:
    class Data : public Gs2Object
    {
    public:
        /** ユーザの名前 */
        optional<StringHolder> userName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            userName(data.userName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            userName(std::move(data.userName))
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
    DeleteUserRequest() :
        m_pData(nullptr)
    {}

    DeleteUserRequest(const DeleteUserRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Identifier(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteUserRequest(DeleteUserRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Identifier(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteUserRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteUserRequest& operator=(const DeleteUserRequest& deleteUserRequest)
    {
        Gs2BasicRequest::operator=(deleteUserRequest);
        Gs2Identifier::operator=(deleteUserRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteUserRequest.m_pData);

        return *this;
    }

    DeleteUserRequest& operator=(DeleteUserRequest&& deleteUserRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteUserRequest));
        Gs2Identifier::operator=(std::move(deleteUserRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteUserRequest.m_pData;
        deleteUserRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteUserRequest* operator->() const
    {
        return this;
    }

    DeleteUserRequest* operator->()
    {
        return this;
    }

    /**
     * ユーザの名前を取得
     *
     * @return ユーザの名前
     */
    const optional<StringHolder>& getUserName() const
    {
        return ensureData().userName;
    }

    /**
     * ユーザの名前を設定
     *
     * @param userName ユーザの名前
     */
    void setUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
    }

    /**
     * ユーザの名前を設定
     *
     * @param userName ユーザの名前
     */
    DeleteUserRequest& withUserName(const Char* userName)
    {
        ensureData().userName.emplace(userName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteUserRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteUserRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteUserRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteUserRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_IDENTIFIER_CONTROL_DELETEUSERREQUEST_HPP_