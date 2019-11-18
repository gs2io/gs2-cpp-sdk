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

#ifndef GS2_SCRIPT_CONTROL_CREATESCRIPTFROMGITHUBREQUEST_HPP_
#define GS2_SCRIPT_CONTROL_CREATESCRIPTFROMGITHUBREQUEST_HPP_

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
 * GitHubリポジトリのコードからスクリプトを新規作成します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateScriptFromGitHubRequest : public Gs2BasicRequest, public Gs2Script
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
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** GitHubからソースコードをチェックアウトしてくる設定 */
        optional<GitHubCheckoutSetting> checkoutSetting;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description)
        {
            if (data.checkoutSetting)
            {
                checkoutSetting = data.checkoutSetting->deepCopy();
            }
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
    CreateScriptFromGitHubRequest() = default;
    CreateScriptFromGitHubRequest(const CreateScriptFromGitHubRequest& createScriptFromGitHubRequest) = default;
    CreateScriptFromGitHubRequest(CreateScriptFromGitHubRequest&& createScriptFromGitHubRequest) = default;
    ~CreateScriptFromGitHubRequest() GS2_OVERRIDE = default;

    CreateScriptFromGitHubRequest& operator=(const CreateScriptFromGitHubRequest& createScriptFromGitHubRequest) = default;
    CreateScriptFromGitHubRequest& operator=(CreateScriptFromGitHubRequest&& createScriptFromGitHubRequest) = default;

    CreateScriptFromGitHubRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateScriptFromGitHubRequest);
    }

    const CreateScriptFromGitHubRequest* operator->() const
    {
        return this;
    }

    CreateScriptFromGitHubRequest* operator->()
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
    CreateScriptFromGitHubRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * スクリプト名を取得
     *
     * @return スクリプト名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スクリプト名を設定
     *
     * @param name スクリプト名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * スクリプト名を設定
     *
     * @param name スクリプト名
     */
    CreateScriptFromGitHubRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    CreateScriptFromGitHubRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * GitHubからソースコードをチェックアウトしてくる設定を取得
     *
     * @return GitHubからソースコードをチェックアウトしてくる設定
     */
    const optional<GitHubCheckoutSetting>& getCheckoutSetting() const
    {
        return ensureData().checkoutSetting;
    }

    /**
     * GitHubからソースコードをチェックアウトしてくる設定を設定
     *
     * @param checkoutSetting GitHubからソースコードをチェックアウトしてくる設定
     */
    void setCheckoutSetting(GitHubCheckoutSetting checkoutSetting)
    {
        ensureData().checkoutSetting.emplace(std::move(checkoutSetting));
    }

    /**
     * GitHubからソースコードをチェックアウトしてくる設定を設定
     *
     * @param checkoutSetting GitHubからソースコードをチェックアウトしてくる設定
     */
    CreateScriptFromGitHubRequest& withCheckoutSetting(GitHubCheckoutSetting checkoutSetting)
    {
        ensureData().checkoutSetting.emplace(std::move(checkoutSetting));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateScriptFromGitHubRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateScriptFromGitHubRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_SCRIPT_CONTROL_CREATESCRIPTFROMGITHUBREQUEST_HPP_