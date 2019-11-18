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

#ifndef GS2_KEY_CONTROL_UPDATEGITHUBAPIKEYREQUEST_HPP_
#define GS2_KEY_CONTROL_UPDATEGITHUBAPIKEYREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/key/Gs2KeyConst.hpp>
#include <gs2/key/model/model.hpp>
#include <memory>

namespace gs2 { namespace key
{

/**
 * GitHub のAPIキーを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateGitHubApiKeyRequest : public Gs2BasicRequest, public Gs2Key
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** GitHub APIキー名 */
        optional<StringHolder> apiKeyName;
        /** 説明文 */
        optional<StringHolder> description;
        /** APIキー */
        optional<StringHolder> apiKey;
        /** APIキーの暗号化に使用する暗号鍵名 */
        optional<StringHolder> encryptionKeyName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            apiKeyName(data.apiKeyName),
            description(data.description),
            apiKey(data.apiKey),
            encryptionKeyName(data.encryptionKeyName)
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
    UpdateGitHubApiKeyRequest() = default;
    UpdateGitHubApiKeyRequest(const UpdateGitHubApiKeyRequest& updateGitHubApiKeyRequest) = default;
    UpdateGitHubApiKeyRequest(UpdateGitHubApiKeyRequest&& updateGitHubApiKeyRequest) = default;
    ~UpdateGitHubApiKeyRequest() GS2_OVERRIDE = default;

    UpdateGitHubApiKeyRequest& operator=(const UpdateGitHubApiKeyRequest& updateGitHubApiKeyRequest) = default;
    UpdateGitHubApiKeyRequest& operator=(UpdateGitHubApiKeyRequest&& updateGitHubApiKeyRequest) = default;

    UpdateGitHubApiKeyRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateGitHubApiKeyRequest);
    }

    const UpdateGitHubApiKeyRequest* operator->() const
    {
        return this;
    }

    UpdateGitHubApiKeyRequest* operator->()
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
    UpdateGitHubApiKeyRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setApiKeyName(StringHolder apiKeyName)
    {
        ensureData().apiKeyName.emplace(std::move(apiKeyName));
    }

    /**
     * GitHub APIキー名を設定
     *
     * @param apiKeyName GitHub APIキー名
     */
    UpdateGitHubApiKeyRequest& withApiKeyName(StringHolder apiKeyName)
    {
        ensureData().apiKeyName.emplace(std::move(apiKeyName));
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
    UpdateGitHubApiKeyRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setApiKey(StringHolder apiKey)
    {
        ensureData().apiKey.emplace(std::move(apiKey));
    }

    /**
     * APIキーを設定
     *
     * @param apiKey APIキー
     */
    UpdateGitHubApiKeyRequest& withApiKey(StringHolder apiKey)
    {
        ensureData().apiKey.emplace(std::move(apiKey));
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
    void setEncryptionKeyName(StringHolder encryptionKeyName)
    {
        ensureData().encryptionKeyName.emplace(std::move(encryptionKeyName));
    }

    /**
     * APIキーの暗号化に使用する暗号鍵名を設定
     *
     * @param encryptionKeyName APIキーの暗号化に使用する暗号鍵名
     */
    UpdateGitHubApiKeyRequest& withEncryptionKeyName(StringHolder encryptionKeyName)
    {
        ensureData().encryptionKeyName.emplace(std::move(encryptionKeyName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateGitHubApiKeyRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateGitHubApiKeyRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_KEY_CONTROL_UPDATEGITHUBAPIKEYREQUEST_HPP_