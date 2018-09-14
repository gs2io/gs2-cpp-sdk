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

#ifndef GS2_SCRIPT_CONTROL_UPDATESCRIPTREQUEST_HPP_
#define GS2_SCRIPT_CONTROL_UPDATESCRIPTREQUEST_HPP_

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
class UpdateScriptRequest : public Gs2BasicRequest, public Gs2Script
{
public:
    constexpr static const Char* const FUNCTION = "UpdateScript";

private:
    class Data : public Gs2Object
    {
    public:
        /** スクリプトの名前を指定します。 */
        optional<StringHolder> scriptName;
        /** 説明文 */
        optional<StringHolder> description;
        /** Luaスクリプト */
        optional<StringHolder> script;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            scriptName(data.scriptName),
            description(data.description),
            script(data.script)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            scriptName(std::move(data.scriptName)),
            description(std::move(data.description)),
            script(std::move(data.script))
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
    UpdateScriptRequest() :
        m_pData(nullptr)
    {}

    UpdateScriptRequest(const UpdateScriptRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Script(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateScriptRequest(UpdateScriptRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Script(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateScriptRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateScriptRequest& operator=(const UpdateScriptRequest& updateScriptRequest)
    {
        Gs2BasicRequest::operator=(updateScriptRequest);
        Gs2Script::operator=(updateScriptRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateScriptRequest.m_pData);

        return *this;
    }

    UpdateScriptRequest& operator=(UpdateScriptRequest&& updateScriptRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateScriptRequest));
        Gs2Script::operator=(std::move(updateScriptRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateScriptRequest.m_pData;
        updateScriptRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateScriptRequest* operator->() const
    {
        return this;
    }

    UpdateScriptRequest* operator->()
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
    UpdateScriptRequest& withScriptName(const Char* scriptName)
    {
        ensureData().scriptName.emplace(scriptName);
        return *this;
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateScriptRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * Luaスクリプトを取得
     *
     * @return Luaスクリプト
     */
    const optional<StringHolder>& getScript() const
    {
        return ensureData().script;
    }

    /**
     * Luaスクリプトを設定
     *
     * @param script Luaスクリプト
     */
    void setScript(const Char* script)
    {
        ensureData().script.emplace(script);
    }

    /**
     * Luaスクリプトを設定
     *
     * @param script Luaスクリプト
     */
    UpdateScriptRequest& withScript(const Char* script)
    {
        ensureData().script.emplace(script);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateScriptRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateScriptRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateScriptRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateScriptRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SCRIPT_CONTROL_UPDATESCRIPTREQUEST_HPP_