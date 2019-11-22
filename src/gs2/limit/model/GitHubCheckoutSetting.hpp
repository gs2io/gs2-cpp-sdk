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

#ifndef GS2_LIMIT_MODEL_GITHUBCHECKOUTSETTING_HPP_
#define GS2_LIMIT_MODEL_GITHUBCHECKOUTSETTING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace limit {

/**
 * GitHubからリソースをチェックアウトしてくる設定
 *
 * @author Game Server Services, Inc.
 *
 */
class GitHubCheckoutSetting : public Gs2Object
{
    friend bool operator!=(const GitHubCheckoutSetting& lhs, const GitHubCheckoutSetting& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** リソースの取得に使用するGitHub のAPIキー のGRN */
        optional<StringHolder> gitHubApiKeyId;
        /** リポジトリ名 */
        optional<StringHolder> repositoryName;
        /** ソースコードのファイルパス */
        optional<StringHolder> sourcePath;
        /** コードの取得元 */
        optional<StringHolder> referenceType;
        /** コミットハッシュ */
        optional<StringHolder> commitHash;
        /** ブランチ名 */
        optional<StringHolder> branchName;
        /** タグ名 */
        optional<StringHolder> tagName;

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
    GitHubCheckoutSetting() = default;
    GitHubCheckoutSetting(const GitHubCheckoutSetting& gitHubCheckoutSetting) = default;
    GitHubCheckoutSetting(GitHubCheckoutSetting&& gitHubCheckoutSetting) = default;
    ~GitHubCheckoutSetting() = default;

    GitHubCheckoutSetting& operator=(const GitHubCheckoutSetting& gitHubCheckoutSetting) = default;
    GitHubCheckoutSetting& operator=(GitHubCheckoutSetting&& gitHubCheckoutSetting) = default;

    GitHubCheckoutSetting deepCopy() const;

    const GitHubCheckoutSetting* operator->() const
    {
        return this;
    }

    GitHubCheckoutSetting* operator->()
    {
        return this;
    }
    /**
     * リソースの取得に使用するGitHub のAPIキー のGRNを取得
     *
     * @return リソースの取得に使用するGitHub のAPIキー のGRN
     */
    const optional<StringHolder>& getGitHubApiKeyId() const
    {
        return ensureData().gitHubApiKeyId;
    }

    /**
     * リソースの取得に使用するGitHub のAPIキー のGRNを設定
     *
     * @param gitHubApiKeyId リソースの取得に使用するGitHub のAPIキー のGRN
     */
    void setGitHubApiKeyId(StringHolder gitHubApiKeyId)
    {
        ensureData().gitHubApiKeyId.emplace(std::move(gitHubApiKeyId));
    }

    /**
     * リソースの取得に使用するGitHub のAPIキー のGRNを設定
     *
     * @param gitHubApiKeyId リソースの取得に使用するGitHub のAPIキー のGRN
     */
    GitHubCheckoutSetting& withGitHubApiKeyId(StringHolder gitHubApiKeyId)
    {
        setGitHubApiKeyId(std::move(gitHubApiKeyId));
        return *this;
    }

    /**
     * リポジトリ名を取得
     *
     * @return リポジトリ名
     */
    const optional<StringHolder>& getRepositoryName() const
    {
        return ensureData().repositoryName;
    }

    /**
     * リポジトリ名を設定
     *
     * @param repositoryName リポジトリ名
     */
    void setRepositoryName(StringHolder repositoryName)
    {
        ensureData().repositoryName.emplace(std::move(repositoryName));
    }

    /**
     * リポジトリ名を設定
     *
     * @param repositoryName リポジトリ名
     */
    GitHubCheckoutSetting& withRepositoryName(StringHolder repositoryName)
    {
        setRepositoryName(std::move(repositoryName));
        return *this;
    }

    /**
     * ソースコードのファイルパスを取得
     *
     * @return ソースコードのファイルパス
     */
    const optional<StringHolder>& getSourcePath() const
    {
        return ensureData().sourcePath;
    }

    /**
     * ソースコードのファイルパスを設定
     *
     * @param sourcePath ソースコードのファイルパス
     */
    void setSourcePath(StringHolder sourcePath)
    {
        ensureData().sourcePath.emplace(std::move(sourcePath));
    }

    /**
     * ソースコードのファイルパスを設定
     *
     * @param sourcePath ソースコードのファイルパス
     */
    GitHubCheckoutSetting& withSourcePath(StringHolder sourcePath)
    {
        setSourcePath(std::move(sourcePath));
        return *this;
    }

    /**
     * コードの取得元を取得
     *
     * @return コードの取得元
     */
    const optional<StringHolder>& getReferenceType() const
    {
        return ensureData().referenceType;
    }

    /**
     * コードの取得元を設定
     *
     * @param referenceType コードの取得元
     */
    void setReferenceType(StringHolder referenceType)
    {
        ensureData().referenceType.emplace(std::move(referenceType));
    }

    /**
     * コードの取得元を設定
     *
     * @param referenceType コードの取得元
     */
    GitHubCheckoutSetting& withReferenceType(StringHolder referenceType)
    {
        setReferenceType(std::move(referenceType));
        return *this;
    }

    /**
     * コミットハッシュを取得
     *
     * @return コミットハッシュ
     */
    const optional<StringHolder>& getCommitHash() const
    {
        return ensureData().commitHash;
    }

    /**
     * コミットハッシュを設定
     *
     * @param commitHash コミットハッシュ
     */
    void setCommitHash(StringHolder commitHash)
    {
        ensureData().commitHash.emplace(std::move(commitHash));
    }

    /**
     * コミットハッシュを設定
     *
     * @param commitHash コミットハッシュ
     */
    GitHubCheckoutSetting& withCommitHash(StringHolder commitHash)
    {
        setCommitHash(std::move(commitHash));
        return *this;
    }

    /**
     * ブランチ名を取得
     *
     * @return ブランチ名
     */
    const optional<StringHolder>& getBranchName() const
    {
        return ensureData().branchName;
    }

    /**
     * ブランチ名を設定
     *
     * @param branchName ブランチ名
     */
    void setBranchName(StringHolder branchName)
    {
        ensureData().branchName.emplace(std::move(branchName));
    }

    /**
     * ブランチ名を設定
     *
     * @param branchName ブランチ名
     */
    GitHubCheckoutSetting& withBranchName(StringHolder branchName)
    {
        setBranchName(std::move(branchName));
        return *this;
    }

    /**
     * タグ名を取得
     *
     * @return タグ名
     */
    const optional<StringHolder>& getTagName() const
    {
        return ensureData().tagName;
    }

    /**
     * タグ名を設定
     *
     * @param tagName タグ名
     */
    void setTagName(StringHolder tagName)
    {
        ensureData().tagName.emplace(std::move(tagName));
    }

    /**
     * タグ名を設定
     *
     * @param tagName タグ名
     */
    GitHubCheckoutSetting& withTagName(StringHolder tagName)
    {
        setTagName(std::move(tagName));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const GitHubCheckoutSetting& lhs, const GitHubCheckoutSetting& lhr);

inline bool operator==(const GitHubCheckoutSetting& lhs, const GitHubCheckoutSetting& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LIMIT_MODEL_GITHUBCHECKOUTSETTING_HPP_