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

#ifndef GS2_VARIABLE_CONTROL_DELETEMYVARIABLEREQUEST_HPP_
#define GS2_VARIABLE_CONTROL_DELETEMYVARIABLEREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2VariableConst.hpp"

namespace gs2 { namespace variable {

/**
 * @author Game Server Services, Inc.
 */
class DeleteMyVariableRequest : public Gs2UserRequest, public Gs2Variable
{
public:
    constexpr static const Char* const FUNCTION = "DeleteMyVariable";

private:
    class Data : public Gs2Object
    {
    public:
        /** 変数名 */
        optional<StringHolder> variableName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            variableName(data.variableName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            variableName(std::move(data.variableName))
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
    DeleteMyVariableRequest() :
        m_pData(nullptr)
    {}

    DeleteMyVariableRequest(const DeleteMyVariableRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Variable(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteMyVariableRequest(DeleteMyVariableRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Variable(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteMyVariableRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteMyVariableRequest& operator=(const DeleteMyVariableRequest& deleteMyVariableRequest)
    {
        Gs2UserRequest::operator=(deleteMyVariableRequest);
        Gs2Variable::operator=(deleteMyVariableRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteMyVariableRequest.m_pData);

        return *this;
    }

    DeleteMyVariableRequest& operator=(DeleteMyVariableRequest&& deleteMyVariableRequest)
    {
        Gs2UserRequest::operator=(std::move(deleteMyVariableRequest));
        Gs2Variable::operator=(std::move(deleteMyVariableRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteMyVariableRequest.m_pData;
        deleteMyVariableRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * 変数名を取得
     *
     * @return 変数名
     */
    const optional<StringHolder>& getVariableName() const
    {
        return ensureData().variableName;
    }

    /**
     * 変数名を設定
     *
     * @param variableName 変数名
     */
    void setVariableName(const Char* variableName)
    {
        ensureData().variableName.emplace(variableName);
    }

    /**
     * 変数名を設定
     *
     * @param variableName 変数名
     */
    DeleteMyVariableRequest& withVariableName(const Char* variableName)
    {
        ensureData().variableName.emplace(variableName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteMyVariableRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteMyVariableRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteMyVariableRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteMyVariableRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    DeleteMyVariableRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_VARIABLE_CONTROL_DELETEMYVARIABLEREQUEST_HPP_