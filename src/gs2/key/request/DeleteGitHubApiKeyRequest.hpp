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

#ifndef GS2_KEY_CONTROL_DELETEGITHUBAPIKEYREQUEST_HPP_
#define GS2_KEY_CONTROL_DELETEGITHUBAPIKEYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2KeyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace key
{

/**
 * GitHub のAPIキーを削除します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DeleteGitHubApiKeyRequest : public Gs2BasicRequest, public Gs2Key
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** GitHub APIキー名 */
        optional<StringHolder> apiKeyName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            apiKeyName(data.apiKeyName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            apiKeyName(std::move(data.apiKeyName))
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
    DeleteGitHubApiKeyRequest() :
        m_pData(nullptr)
    {}

    DeleteGitHubApiKeyRequest(const DeleteGitHubApiKeyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Key(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteGitHubApiKeyRequest(DeleteGitHubApiKeyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Key(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteGitHubApiKeyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteGitHubApiKeyRequest& operator=(const DeleteGitHubApiKeyRequest& deleteGitHubApiKeyRequest)
    {
        Gs2BasicRequest::operator=(deleteGitHubApiKeyRequest);
        Gs2Key::operator=(deleteGitHubApiKeyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteGitHubApiKeyRequest.m_pData);

        return *this;
    }

    DeleteGitHubApiKeyRequest& operator=(DeleteGitHubApiKeyRequest&& deleteGitHubApiKeyRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteGitHubApiKeyRequest));
        Gs2Key::operator=(std::move(deleteGitHubApiKeyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteGitHubApiKeyRequest.m_pData;
        deleteGitHubApiKeyRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteGitHubApiKeyRequest* operator->() const
    {
        return this;
    }

    DeleteGitHubApiKeyRequest* operator->()
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
    DeleteGitHubApiKeyRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * GitHub APIキー名を取得
     *
     * @return GitHub APIキー名
     */
    const optional<StringHolder>& getApiKeyName() const
    {
        return ensureData().apiKeyName;
    }

    /**
     * GitHub APIキー名を設定
     *
     * @param apiKeyName GitHub APIキー名
     */
    void setApiKeyName(const Char* apiKeyName)
    {
        ensureData().apiKeyName.emplace(apiKeyName);
    }

    /**
     * GitHub APIキー名を設定
     *
     * @param apiKeyName GitHub APIキー名
     */
    DeleteGitHubApiKeyRequest& withApiKeyName(const Char* apiKeyName)
    {
        ensureData().apiKeyName.emplace(apiKeyName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteGitHubApiKeyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteGitHubApiKeyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteGitHubApiKeyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteGitHubApiKeyRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_KEY_CONTROL_DELETEGITHUBAPIKEYREQUEST_HPP_