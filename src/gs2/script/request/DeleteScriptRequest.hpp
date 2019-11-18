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

#ifndef GS2_SCRIPT_CONTROL_DELETESCRIPTREQUEST_HPP_
#define GS2_SCRIPT_CONTROL_DELETESCRIPTREQUEST_HPP_

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
 * スクリプトを削除します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteScriptRequest : public Gs2BasicRequest, public Gs2Script
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            scriptName(data.scriptName)
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
    DeleteScriptRequest() = default;
    DeleteScriptRequest(const DeleteScriptRequest& deleteScriptRequest) = default;
    DeleteScriptRequest(DeleteScriptRequest&& deleteScriptRequest) = default;
    ~DeleteScriptRequest() GS2_OVERRIDE = default;

    DeleteScriptRequest& operator=(const DeleteScriptRequest& deleteScriptRequest) = default;
    DeleteScriptRequest& operator=(DeleteScriptRequest&& deleteScriptRequest) = default;

    DeleteScriptRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteScriptRequest);
    }

    const DeleteScriptRequest* operator->() const
    {
        return this;
    }

    DeleteScriptRequest* operator->()
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
    DeleteScriptRequest& withNamespaceName(StringHolder namespaceName)
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
    DeleteScriptRequest& withScriptName(StringHolder scriptName)
    {
        ensureData().scriptName.emplace(std::move(scriptName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteScriptRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteScriptRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SCRIPT_CONTROL_DELETESCRIPTREQUEST_HPP_