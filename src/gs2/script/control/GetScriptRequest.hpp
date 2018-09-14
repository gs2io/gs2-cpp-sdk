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

#ifndef GS2_SCRIPT_CONTROL_GETSCRIPTREQUEST_HPP_
#define GS2_SCRIPT_CONTROL_GETSCRIPTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScriptConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace script
{

/**
 * @author Game Server Services, Inc.
 */
class GetScriptRequest : public Gs2BasicRequest, public Gs2Script
{
public:
    constexpr static const Char* const FUNCTION = "GetScript";

private:
    class Data : public Gs2Object
    {
    public:
        /** スクリプトの名前を指定します。 */
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
    GetScriptRequest() :
        m_pData(nullptr)
    {}

    GetScriptRequest(const GetScriptRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Script(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetScriptRequest(GetScriptRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Script(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetScriptRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetScriptRequest& operator=(const GetScriptRequest& getScriptRequest)
    {
        Gs2BasicRequest::operator=(getScriptRequest);
        Gs2Script::operator=(getScriptRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getScriptRequest.m_pData);

        return *this;
    }

    GetScriptRequest& operator=(GetScriptRequest&& getScriptRequest)
    {
        Gs2BasicRequest::operator=(std::move(getScriptRequest));
        Gs2Script::operator=(std::move(getScriptRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getScriptRequest.m_pData;
        getScriptRequest.m_pData = nullptr;

        return *this;
    }

    const GetScriptRequest* operator->() const
    {
        return this;
    }

    GetScriptRequest* operator->()
    {
        return this;
    }

    /**
     * スクリプトの名前を指定します。を取得
     *
     * @return スクリプトの名前を指定します。
     */
    const optional<StringHolder>& getScriptName() const
    {
        return ensureData().scriptName;
    }

    /**
     * スクリプトの名前を指定します。を設定
     *
     * @param scriptName スクリプトの名前を指定します。
     */
    void setScriptName(const Char* scriptName)
    {
        ensureData().scriptName.emplace(scriptName);
    }

    /**
     * スクリプトの名前を指定します。を設定
     *
     * @param scriptName スクリプトの名前を指定します。
     */
    GetScriptRequest& withScriptName(const Char* scriptName)
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
    GetScriptRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetScriptRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetScriptRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetScriptRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SCRIPT_CONTROL_GETSCRIPTREQUEST_HPP_