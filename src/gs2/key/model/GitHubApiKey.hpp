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

#ifndef GS2_KEY_MODEL_GITHUBAPIKEY_HPP_
#define GS2_KEY_MODEL_GITHUBAPIKEY_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace key {

/**
 * GitHub のAPIキー
 *
 * @author Game Server Services, Inc.
 *
 */
class GitHubApiKey : public Gs2Object
{
    friend bool operator!=(const GitHubApiKey& lhs, const GitHubApiKey& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** GitHub のAPIキー */
        optional<StringHolder> apiKeyId;
        /** GitHub APIキー名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** APIキー */
        optional<StringHolder> apiKey;
        /** APIキーの暗号化に使用する暗号鍵名 */
        optional<StringHolder> encryptionKeyName;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    GitHubApiKey() = default;
    GitHubApiKey(const GitHubApiKey& gitHubApiKey) = default;
    GitHubApiKey(GitHubApiKey&& gitHubApiKey) = default;
    ~GitHubApiKey() = default;

    GitHubApiKey& operator=(const GitHubApiKey& gitHubApiKey) = default;
    GitHubApiKey& operator=(GitHubApiKey&& gitHubApiKey) = default;

    GitHubApiKey deepCopy() const;

    const GitHubApiKey* operator->() const
    {
        return this;
    }

    GitHubApiKey* operator->()
    {
        return this;
    }
    /**
     * GitHub のAPIキーを取得
     *
     * @return GitHub のAPIキー
     */
    const optional<StringHolder>& getApiKeyId() const
    {
        return ensureData().apiKeyId;
    }

    /**
     * GitHub のAPIキーを設定
     *
     * @param apiKeyId GitHub のAPIキー
     */
    void setApiKeyId(StringHolder apiKeyId)
    {
        ensureData().apiKeyId.emplace(std::move(apiKeyId));
    }

    /**
     * GitHub のAPIキーを設定
     *
     * @param apiKeyId GitHub のAPIキー
     */
    GitHubApiKey& withApiKeyId(StringHolder apiKeyId)
    {
        setApiKeyId(std::move(apiKeyId));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * GitHub APIキー名を設定
     *
     * @param name GitHub APIキー名
     */
    GitHubApiKey& withName(StringHolder name)
    {
        setName(std::move(name));
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
    GitHubApiKey& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
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
    GitHubApiKey& withApiKey(StringHolder apiKey)
    {
        setApiKey(std::move(apiKey));
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
    GitHubApiKey& withEncryptionKeyName(StringHolder encryptionKeyName)
    {
        setEncryptionKeyName(std::move(encryptionKeyName));
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    GitHubApiKey& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    GitHubApiKey& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const GitHubApiKey& lhs, const GitHubApiKey& lhr);

inline bool operator==(const GitHubApiKey& lhs, const GitHubApiKey& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_KEY_MODEL_GITHUBAPIKEY_HPP_