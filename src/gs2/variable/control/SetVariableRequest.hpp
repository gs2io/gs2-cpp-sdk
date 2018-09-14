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

#ifndef GS2_VARIABLE_CONTROL_SETVARIABLEREQUEST_HPP_
#define GS2_VARIABLE_CONTROL_SETVARIABLEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2VariableConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace variable
{

/**
 * @author Game Server Services, Inc.
 */
class SetVariableRequest : public Gs2BasicRequest, public Gs2Variable
{
public:
    constexpr static const Char* const FUNCTION = "SetVariable";

private:
    class Data : public Gs2Object
    {
    public:
        /** 変数のスコープとなるユーザID */
        optional<StringHolder> userId;
        /** 変数名 */
        optional<StringHolder> variableName;
        /** 値 */
        optional<StringHolder> value;
        /** 変数の有効期間(秒) */
        optional<Int32> ttl;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            userId(data.userId),
            variableName(data.variableName),
            value(data.value),
            ttl(data.ttl)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            userId(std::move(data.userId)),
            variableName(std::move(data.variableName)),
            value(std::move(data.value)),
            ttl(std::move(data.ttl))
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
    SetVariableRequest() :
        m_pData(nullptr)
    {}

    SetVariableRequest(const SetVariableRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Variable(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SetVariableRequest(SetVariableRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Variable(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SetVariableRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SetVariableRequest& operator=(const SetVariableRequest& setVariableRequest)
    {
        Gs2BasicRequest::operator=(setVariableRequest);
        Gs2Variable::operator=(setVariableRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*setVariableRequest.m_pData);

        return *this;
    }

    SetVariableRequest& operator=(SetVariableRequest&& setVariableRequest)
    {
        Gs2BasicRequest::operator=(std::move(setVariableRequest));
        Gs2Variable::operator=(std::move(setVariableRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = setVariableRequest.m_pData;
        setVariableRequest.m_pData = nullptr;

        return *this;
    }

    const SetVariableRequest* operator->() const
    {
        return this;
    }

    SetVariableRequest* operator->()
    {
        return this;
    }

    /**
     * 変数のスコープとなるユーザIDを取得
     *
     * @return 変数のスコープとなるユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * 変数のスコープとなるユーザIDを設定
     *
     * @param userId 変数のスコープとなるユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * 変数のスコープとなるユーザIDを設定
     *
     * @param userId 変数のスコープとなるユーザID
     */
    SetVariableRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
    SetVariableRequest& withVariableName(const Char* variableName)
    {
        ensureData().variableName.emplace(variableName);
        return *this;
    }

    /**
     * 値を取得
     *
     * @return 値
     */
    const optional<StringHolder>& getValue() const
    {
        return ensureData().value;
    }

    /**
     * 値を設定
     *
     * @param value 値
     */
    void setValue(const Char* value)
    {
        ensureData().value.emplace(value);
    }

    /**
     * 値を設定
     *
     * @param value 値
     */
    SetVariableRequest& withValue(const Char* value)
    {
        ensureData().value.emplace(value);
        return *this;
    }

    /**
     * 変数の有効期間(秒)を取得
     *
     * @return 変数の有効期間(秒)
     */
    const optional<Int32>& getTtl() const
    {
        return ensureData().ttl;
    }

    /**
     * 変数の有効期間(秒)を設定
     *
     * @param ttl 変数の有効期間(秒)
     */
    void setTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
    }

    /**
     * 変数の有効期間(秒)を設定
     *
     * @param ttl 変数の有効期間(秒)
     */
    SetVariableRequest& withTtl(Int32 ttl)
    {
        ensureData().ttl.emplace(ttl);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    SetVariableRequest& withGs2ClientId(const Char* gs2ClientId)
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
    SetVariableRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    SetVariableRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SetVariableRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_VARIABLE_CONTROL_SETVARIABLEREQUEST_HPP_