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

#ifndef GS2_SCRIPT_CONTROL_UPDATESCRIPTREQUEST_HPP_
#define GS2_SCRIPT_CONTROL_UPDATESCRIPTREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/script/Gs2ScriptConst.hpp>
#include <gs2/script/model/model.hpp>
#include <memory>

namespace gs2 { namespace script
{

/**
 * スクリプトを更新します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateScriptRequest : public Gs2BasicRequest, public Gs2Script
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スクリプト名 */
        optional<StringHolder> scriptName;
        /** 説明文 */
        optional<StringHolder> description;
        /** Luaスクリプト */
        optional<StringHolder> script;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            scriptName(data.scriptName),
            description(data.description),
            script(data.script)
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
    UpdateScriptRequest() = default;
    UpdateScriptRequest(const UpdateScriptRequest& updateScriptRequest) = default;
    UpdateScriptRequest(UpdateScriptRequest&& updateScriptRequest) = default;
    ~UpdateScriptRequest() GS2_OVERRIDE = default;

    UpdateScriptRequest& operator=(const UpdateScriptRequest& updateScriptRequest) = default;
    UpdateScriptRequest& operator=(UpdateScriptRequest&& updateScriptRequest) = default;

    UpdateScriptRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateScriptRequest);
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
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateScriptRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
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
    void setScriptName(StringHolder scriptName)
    {
        ensureData().scriptName.emplace(std::move(scriptName));
    }

    /**
     * スクリプト名を設定
     *
     * @param scriptName スクリプト名
     */
    UpdateScriptRequest& withScriptName(StringHolder scriptName)
    {
        ensureData().scriptName.emplace(std::move(scriptName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateScriptRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setScript(StringHolder script)
    {
        ensureData().script.emplace(std::move(script));
    }

    /**
     * Luaスクリプトを設定
     *
     * @param script Luaスクリプト
     */
    UpdateScriptRequest& withScript(StringHolder script)
    {
        ensureData().script.emplace(std::move(script));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateScriptRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateScriptRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SCRIPT_CONTROL_UPDATESCRIPTREQUEST_HPP_