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

#ifndef GS2_SCRIPT_CONTROL_DEBUGINVOKEREQUEST_HPP_
#define GS2_SCRIPT_CONTROL_DEBUGINVOKEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScriptConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace script
{

/**
 * スクリプトを実行します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DebugInvokeRequest : public Gs2BasicRequest, public Gs2Script
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スクリプト */
        optional<StringHolder> script;
        /** None */
        optional<StringHolder> args;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            script(data.script),
            args(data.args)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            script(std::move(data.script)),
            args(std::move(data.args))
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
    DebugInvokeRequest() :
        m_pData(nullptr)
    {}

    DebugInvokeRequest(const DebugInvokeRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Script(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DebugInvokeRequest(DebugInvokeRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Script(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DebugInvokeRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DebugInvokeRequest& operator=(const DebugInvokeRequest& debugInvokeRequest)
    {
        Gs2BasicRequest::operator=(debugInvokeRequest);
        Gs2Script::operator=(debugInvokeRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*debugInvokeRequest.m_pData);

        return *this;
    }

    DebugInvokeRequest& operator=(DebugInvokeRequest&& debugInvokeRequest)
    {
        Gs2BasicRequest::operator=(std::move(debugInvokeRequest));
        Gs2Script::operator=(std::move(debugInvokeRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = debugInvokeRequest.m_pData;
        debugInvokeRequest.m_pData = nullptr;

        return *this;
    }

    const DebugInvokeRequest* operator->() const
    {
        return this;
    }

    DebugInvokeRequest* operator->()
    {
        return this;
    }
    /**
     * スクリプトを取得
     *
     * @return スクリプト
     */
    const optional<StringHolder>& getScript() const
    {
        return ensureData().script;
    }

    /**
     * スクリプトを設定
     *
     * @param script スクリプト
     */
    void setScript(const Char* script)
    {
        ensureData().script.emplace(script);
    }

    /**
     * スクリプトを設定
     *
     * @param script スクリプト
     */
    DebugInvokeRequest& withScript(const Char* script)
    {
        ensureData().script.emplace(script);
        return *this;
    }

    /**
     * Noneを取得
     *
     * @return None
     */
    const optional<StringHolder>& getArgs() const
    {
        return ensureData().args;
    }

    /**
     * Noneを設定
     *
     * @param args None
     */
    void setArgs(const Char* args)
    {
        ensureData().args.emplace(args);
    }

    /**
     * Noneを設定
     *
     * @param args None
     */
    DebugInvokeRequest& withArgs(const Char* args)
    {
        ensureData().args.emplace(args);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DebugInvokeRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DebugInvokeRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DebugInvokeRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DebugInvokeRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_SCRIPT_CONTROL_DEBUGINVOKEREQUEST_HPP_