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

#ifndef GS2_SCRIPT_CONTROL_GETSCRIPTSTATUSREQUEST_HPP_
#define GS2_SCRIPT_CONTROL_GETSCRIPTSTATUSREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScriptConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace script
{

/**
 * スクリプトを取得します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetScriptStatusRequest : public Gs2BasicRequest, public Gs2Script
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スクリプト名 */
        optional<StringHolder> scriptName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            scriptName(data.scriptName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            scriptName(std::move(data.scriptName))
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
    GetScriptStatusRequest() :
        m_pData(nullptr)
    {}

    GetScriptStatusRequest(const GetScriptStatusRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Script(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetScriptStatusRequest(GetScriptStatusRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Script(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetScriptStatusRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetScriptStatusRequest& operator=(const GetScriptStatusRequest& getScriptStatusRequest)
    {
        Gs2BasicRequest::operator=(getScriptStatusRequest);
        Gs2Script::operator=(getScriptStatusRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getScriptStatusRequest.m_pData);

        return *this;
    }

    GetScriptStatusRequest& operator=(GetScriptStatusRequest&& getScriptStatusRequest)
    {
        Gs2BasicRequest::operator=(std::move(getScriptStatusRequest));
        Gs2Script::operator=(std::move(getScriptStatusRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getScriptStatusRequest.m_pData;
        getScriptStatusRequest.m_pData = nullptr;

        return *this;
    }

    const GetScriptStatusRequest* operator->() const
    {
        return this;
    }

    GetScriptStatusRequest* operator->()
    {
        return this;
    }
    /**
     * スクリプト名を取得
     *
     * @return スクリプト名
     */
    const optional<StringHolder>& getScriptName() const
    {
        return ensureData().scriptName;
    }

    /**
     * スクリプト名を設定
     *
     * @param scriptName スクリプト名
     */
    void setScriptName(const Char* scriptName)
    {
        ensureData().scriptName.emplace(scriptName);
    }

    /**
     * スクリプト名を設定
     *
     * @param scriptName スクリプト名
     */
    GetScriptStatusRequest& withScriptName(const Char* scriptName)
    {
        ensureData().scriptName.emplace(scriptName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetScriptStatusRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetScriptStatusRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetScriptStatusRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetScriptStatusRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SCRIPT_CONTROL_GETSCRIPTSTATUSREQUEST_HPP_