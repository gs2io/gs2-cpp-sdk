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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScriptConst.hpp"
#include "../model/model.hpp"
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** スクリプト */
        optional<StringHolder> script;
        /** None */
        optional<StringHolder> args;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            script(data.script),
            args(data.args)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    DebugInvokeRequest() = default;
    DebugInvokeRequest(const DebugInvokeRequest& debugInvokeRequest) = default;
    DebugInvokeRequest(DebugInvokeRequest&& debugInvokeRequest) = default;
    ~DebugInvokeRequest() GS2_OVERRIDE = default;

    DebugInvokeRequest& operator=(const DebugInvokeRequest& debugInvokeRequest) = default;
    DebugInvokeRequest& operator=(DebugInvokeRequest&& debugInvokeRequest) = default;

    DebugInvokeRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DebugInvokeRequest);
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
    void setScript(StringHolder script)
    {
        ensureData().script.emplace(std::move(script));
    }

    /**
     * スクリプトを設定
     *
     * @param script スクリプト
     */
    DebugInvokeRequest& withScript(StringHolder script)
    {
        ensureData().script.emplace(std::move(script));
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
    void setArgs(StringHolder args)
    {
        ensureData().args.emplace(std::move(args));
    }

    /**
     * Noneを設定
     *
     * @param args None
     */
    DebugInvokeRequest& withArgs(StringHolder args)
    {
        ensureData().args.emplace(std::move(args));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DebugInvokeRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DebugInvokeRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SCRIPT_CONTROL_DEBUGINVOKEREQUEST_HPP_