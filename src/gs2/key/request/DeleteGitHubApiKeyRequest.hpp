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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2KeyConst.hpp"
#include "../model/model.hpp"
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** GitHub APIキー名 */
        optional<StringHolder> apiKeyName;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            apiKeyName(data.apiKeyName)
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
    DeleteGitHubApiKeyRequest() = default;
    DeleteGitHubApiKeyRequest(const DeleteGitHubApiKeyRequest& deleteGitHubApiKeyRequest) = default;
    DeleteGitHubApiKeyRequest(DeleteGitHubApiKeyRequest&& deleteGitHubApiKeyRequest) = default;
    ~DeleteGitHubApiKeyRequest() GS2_OVERRIDE = default;

    DeleteGitHubApiKeyRequest& operator=(const DeleteGitHubApiKeyRequest& deleteGitHubApiKeyRequest) = default;
    DeleteGitHubApiKeyRequest& operator=(DeleteGitHubApiKeyRequest&& deleteGitHubApiKeyRequest) = default;

    DeleteGitHubApiKeyRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DeleteGitHubApiKeyRequest);
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
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    DeleteGitHubApiKeyRequest& withNamespaceName(StringHolder namespaceName)
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
    DeleteGitHubApiKeyRequest& withApiKeyName(StringHolder apiKeyName)
    {
        ensureData().apiKeyName.emplace(std::move(apiKeyName));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteGitHubApiKeyRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteGitHubApiKeyRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_KEY_CONTROL_DELETEGITHUBAPIKEYREQUEST_HPP_