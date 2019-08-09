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

#ifndef GS2_KEY_CONTROL_CREATEGITHUBAPIKEYREQUEST_HPP_
#define GS2_KEY_CONTROL_CREATEGITHUBAPIKEYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2KeyConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace key
{

/**
 * GitHub のAPIキーを新規作成します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateGitHubApiKeyRequest : public Gs2BasicRequest, public Gs2Key
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
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** APIキー */
        optional<StringHolder> apiKey;
        /** APIキーの暗号化に使用する暗号鍵名 */
        optional<StringHolder> encryptionKeyName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            apiKey(data.apiKey),
            encryptionKeyName(data.encryptionKeyName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            apiKey(std::move(data.apiKey)),
            encryptionKeyName(std::move(data.encryptionKeyName))
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
    CreateGitHubApiKeyRequest() :
        m_pData(nullptr)
    {}

    CreateGitHubApiKeyRequest(const CreateGitHubApiKeyRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Key(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateGitHubApiKeyRequest(CreateGitHubApiKeyRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Key(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateGitHubApiKeyRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGitHubApiKeyRequest& operator=(const CreateGitHubApiKeyRequest& createGitHubApiKeyRequest)
    {
        Gs2BasicRequest::operator=(createGitHubApiKeyRequest);
        Gs2Key::operator=(createGitHubApiKeyRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGitHubApiKeyRequest.m_pData);

        return *this;
    }

    CreateGitHubApiKeyRequest& operator=(CreateGitHubApiKeyRequest&& createGitHubApiKeyRequest)
    {
        Gs2BasicRequest::operator=(std::move(createGitHubApiKeyRequest));
        Gs2Key::operator=(std::move(createGitHubApiKeyRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGitHubApiKeyRequest.m_pData;
        createGitHubApiKeyRequest.m_pData = nullptr;

        return *this;
    }

    const CreateGitHubApiKeyRequest* operator->() const
    {
        return this;
    }

    CreateGitHubApiKeyRequest* operator->()
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
    CreateGitHubApiKeyRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
        return *this;
    }

    /**
     * GitHub APIキー名を取得
     *
     * @return GitHub APIキー名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * GitHub APIキー名を設定
     *
     * @param name GitHub APIキー名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * GitHub APIキー名を設定
     *
     * @param name GitHub APIキー名
     */
    CreateGitHubApiKeyRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    CreateGitHubApiKeyRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * APIキーを取得
     *
     * @return APIキー
     */
    const optional<StringHolder>& getApiKey() const
    {
        return ensureData().apiKey;
    }

    /**
     * APIキーを設定
     *
     * @param apiKey APIキー
     */
    void setApiKey(const Char* apiKey)
    {
        ensureData().apiKey.emplace(apiKey);
    }

    /**
     * APIキーを設定
     *
     * @param apiKey APIキー
     */
    CreateGitHubApiKeyRequest& withApiKey(const Char* apiKey)
    {
        ensureData().apiKey.emplace(apiKey);
        return *this;
    }

    /**
     * APIキーの暗号化に使用する暗号鍵名を取得
     *
     * @return APIキーの暗号化に使用する暗号鍵名
     */
    const optional<StringHolder>& getEncryptionKeyName() const
    {
        return ensureData().encryptionKeyName;
    }

    /**
     * APIキーの暗号化に使用する暗号鍵名を設定
     *
     * @param encryptionKeyName APIキーの暗号化に使用する暗号鍵名
     */
    void setEncryptionKeyName(const Char* encryptionKeyName)
    {
        ensureData().encryptionKeyName.emplace(encryptionKeyName);
    }

    /**
     * APIキーの暗号化に使用する暗号鍵名を設定
     *
     * @param encryptionKeyName APIキーの暗号化に使用する暗号鍵名
     */
    CreateGitHubApiKeyRequest& withEncryptionKeyName(const Char* encryptionKeyName)
    {
        ensureData().encryptionKeyName.emplace(encryptionKeyName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateGitHubApiKeyRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateGitHubApiKeyRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateGitHubApiKeyRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGitHubApiKeyRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_KEY_CONTROL_CREATEGITHUBAPIKEYREQUEST_HPP_