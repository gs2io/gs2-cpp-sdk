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

#ifndef GS2_DEPLOY_CONTROL_CREATESTACKFROMGITHUBREQUEST_HPP_
#define GS2_DEPLOY_CONTROL_CREATESTACKFROMGITHUBREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2DeployConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace deploy
{

/**
 * スタックを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateStackFromGitHubRequest : public Gs2BasicRequest, public Gs2Deploy
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタック名 */
        optional<StringHolder> name;
        /** スタックの説明 */
        optional<StringHolder> description;
        /** GitHubからソースコードをチェックアウトしてくる設定 */
        optional<GitHubCheckoutSetting> checkoutSetting;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            checkoutSetting(data.checkoutSetting)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
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
    CreateStackFromGitHubRequest() :
        m_pData(nullptr)
    {}

    CreateStackFromGitHubRequest(const CreateStackFromGitHubRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Deploy(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateStackFromGitHubRequest(CreateStackFromGitHubRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Deploy(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateStackFromGitHubRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateStackFromGitHubRequest& operator=(const CreateStackFromGitHubRequest& createStackFromGitHubRequest)
    {
        Gs2BasicRequest::operator=(createStackFromGitHubRequest);
        Gs2Deploy::operator=(createStackFromGitHubRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createStackFromGitHubRequest.m_pData);

        return *this;
    }

    CreateStackFromGitHubRequest& operator=(CreateStackFromGitHubRequest&& createStackFromGitHubRequest)
    {
        Gs2BasicRequest::operator=(std::move(createStackFromGitHubRequest));
        Gs2Deploy::operator=(std::move(createStackFromGitHubRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createStackFromGitHubRequest.m_pData;
        createStackFromGitHubRequest.m_pData = nullptr;

        return *this;
    }

    const CreateStackFromGitHubRequest* operator->() const
    {
        return this;
    }

    CreateStackFromGitHubRequest* operator->()
    {
        return this;
    }

    /**
     * スタック名を取得
     *
     * @return スタック名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタック名を設定
     *
     * @param name スタック名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * スタック名を設定
     *
     * @param name スタック名
     */
    CreateStackFromGitHubRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * スタックの説明を取得
     *
     * @return スタックの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * スタックの説明を設定
     *
     * @param description スタックの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スタックの説明を設定
     *
     * @param description スタックの説明
     */
    CreateStackFromGitHubRequest& withDescription(const Char* description)
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
    CreateStackFromGitHubRequest& withCheckoutSetting(const GitHubCheckoutSetting& checkoutSetting)
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
    CreateStackFromGitHubRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateStackFromGitHubRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateStackFromGitHubRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateStackFromGitHubRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_DEPLOY_CONTROL_CREATESTACKFROMGITHUBREQUEST_HPP_