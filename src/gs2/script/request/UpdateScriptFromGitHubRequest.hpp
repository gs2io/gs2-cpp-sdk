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

#ifndef GS2_SCRIPT_CONTROL_UPDATESCRIPTFROMGITHUBREQUEST_HPP_
#define GS2_SCRIPT_CONTROL_UPDATESCRIPTFROMGITHUBREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ScriptConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace script
{

/**
 * スクリプトを更新します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateScriptFromGitHubRequest : public Gs2BasicRequest, public Gs2Script
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スクリプト名 */
        optional<StringHolder> scriptName;
        /** 説明文 */
        optional<StringHolder> description;
        /** GitHubからソースコードをチェックアウトしてくる設定 */
        optional<GitHubCheckoutSetting> checkoutSetting;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            scriptName(data.scriptName),
            description(data.description),
            checkoutSetting(data.checkoutSetting)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            scriptName(std::move(data.scriptName)),
            description(std::move(data.description)),
            checkoutSetting(std::move(data.checkoutSetting))
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
    UpdateScriptFromGitHubRequest() :
        m_pData(nullptr)
    {}

    UpdateScriptFromGitHubRequest(const UpdateScriptFromGitHubRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Script(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateScriptFromGitHubRequest(UpdateScriptFromGitHubRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Script(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateScriptFromGitHubRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateScriptFromGitHubRequest& operator=(const UpdateScriptFromGitHubRequest& updateScriptFromGitHubRequest)
    {
        Gs2BasicRequest::operator=(updateScriptFromGitHubRequest);
        Gs2Script::operator=(updateScriptFromGitHubRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateScriptFromGitHubRequest.m_pData);

        return *this;
    }

    UpdateScriptFromGitHubRequest& operator=(UpdateScriptFromGitHubRequest&& updateScriptFromGitHubRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateScriptFromGitHubRequest));
        Gs2Script::operator=(std::move(updateScriptFromGitHubRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateScriptFromGitHubRequest.m_pData;
        updateScriptFromGitHubRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateScriptFromGitHubRequest* operator->() const
    {
        return this;
    }

    UpdateScriptFromGitHubRequest* operator->()
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateScriptFromGitHubRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setScriptName(const Char* scriptName)
    {
        ensureData().scriptName.emplace(scriptName);
    }

    /**
     * スクリプト名を設定
     *
     * @param scriptName スクリプト名
     */
    UpdateScriptFromGitHubRequest& withScriptName(const Char* scriptName)
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
    UpdateScriptFromGitHubRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setCheckoutSetting(const GitHubCheckoutSetting& checkoutSetting)
    {
        ensureData().checkoutSetting.emplace(checkoutSetting);
    }

    /**
     * GitHubからソースコードをチェックアウトしてくる設定を設定
     *
     * @param checkoutSetting GitHubからソースコードをチェックアウトしてくる設定
     */
    UpdateScriptFromGitHubRequest& withCheckoutSetting(const GitHubCheckoutSetting& checkoutSetting)
    {
        ensureData().checkoutSetting.emplace(checkoutSetting);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateScriptFromGitHubRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateScriptFromGitHubRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateScriptFromGitHubRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateScriptFromGitHubRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_SCRIPT_CONTROL_UPDATESCRIPTFROMGITHUBREQUEST_HPP_