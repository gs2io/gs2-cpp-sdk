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

#ifndef GS2_LOTTERY_MODEL_GITHUBCHECKOUTSETTING_HPP_
#define GS2_LOTTERY_MODEL_GITHUBCHECKOUTSETTING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace lottery {

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gitHubApiKeyId(data.gitHubApiKeyId),
            repositoryName(data.repositoryName),
            sourcePath(data.sourcePath),
            referenceType(data.referenceType),
            commitHash(data.commitHash),
            branchName(data.branchName),
            tagName(data.tagName)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gitHubApiKeyId(std::move(data.gitHubApiKeyId)),
            repositoryName(std::move(data.repositoryName)),
            sourcePath(std::move(data.sourcePath)),
            referenceType(std::move(data.referenceType)),
            commitHash(std::move(data.commitHash)),
            branchName(std::move(data.branchName)),
            tagName(std::move(data.tagName))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gitHubApiKeyId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gitHubApiKeyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "repositoryName") == 0) {
                if (jsonValue.IsString())
                {
                    this->repositoryName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "sourcePath") == 0) {
                if (jsonValue.IsString())
                {
                    this->sourcePath.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "referenceType") == 0) {
                if (jsonValue.IsString())
                {
                    this->referenceType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "commitHash") == 0) {
                if (jsonValue.IsString())
                {
                    this->commitHash.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "branchName") == 0) {
                if (jsonValue.IsString())
                {
                    this->branchName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "tagName") == 0) {
                if (jsonValue.IsString())
                {
                    this->tagName.emplace(jsonValue.GetString());
                }
            }
        }
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
    GitHubCheckoutSetting() :
        m_pData(nullptr)
    {}

    GitHubCheckoutSetting(const GitHubCheckoutSetting& gitHubCheckoutSetting) :
        Gs2Object(gitHubCheckoutSetting),
        m_pData(gitHubCheckoutSetting.m_pData != nullptr ? new Data(*gitHubCheckoutSetting.m_pData) : nullptr)
    {}

    GitHubCheckoutSetting(GitHubCheckoutSetting&& gitHubCheckoutSetting) :
        Gs2Object(std::move(gitHubCheckoutSetting)),
        m_pData(gitHubCheckoutSetting.m_pData)
    {
        gitHubCheckoutSetting.m_pData = nullptr;
    }

    ~GitHubCheckoutSetting()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GitHubCheckoutSetting& operator=(const GitHubCheckoutSetting& gitHubCheckoutSetting)
    {
        Gs2Object::operator=(gitHubCheckoutSetting);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*gitHubCheckoutSetting.m_pData);

        return *this;
    }

    GitHubCheckoutSetting& operator=(GitHubCheckoutSetting&& gitHubCheckoutSetting)
    {
        Gs2Object::operator=(std::move(gitHubCheckoutSetting));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = gitHubCheckoutSetting.m_pData;
        gitHubCheckoutSetting.m_pData = nullptr;

        return *this;
    }

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
    void setGitHubApiKeyId(const Char* gitHubApiKeyId)
    {
        ensureData().gitHubApiKeyId.emplace(gitHubApiKeyId);
    }

    /**
     * リソースの取得に使用するGitHub のAPIキー のGRNを設定
     *
     * @param gitHubApiKeyId リソースの取得に使用するGitHub のAPIキー のGRN
     */
    GitHubCheckoutSetting& withGitHubApiKeyId(const Char* gitHubApiKeyId)
    {
        setGitHubApiKeyId(gitHubApiKeyId);
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
    void setRepositoryName(const Char* repositoryName)
    {
        ensureData().repositoryName.emplace(repositoryName);
    }

    /**
     * リポジトリ名を設定
     *
     * @param repositoryName リポジトリ名
     */
    GitHubCheckoutSetting& withRepositoryName(const Char* repositoryName)
    {
        setRepositoryName(repositoryName);
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
    void setSourcePath(const Char* sourcePath)
    {
        ensureData().sourcePath.emplace(sourcePath);
    }

    /**
     * ソースコードのファイルパスを設定
     *
     * @param sourcePath ソースコードのファイルパス
     */
    GitHubCheckoutSetting& withSourcePath(const Char* sourcePath)
    {
        setSourcePath(sourcePath);
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
    void setReferenceType(const Char* referenceType)
    {
        ensureData().referenceType.emplace(referenceType);
    }

    /**
     * コードの取得元を設定
     *
     * @param referenceType コードの取得元
     */
    GitHubCheckoutSetting& withReferenceType(const Char* referenceType)
    {
        setReferenceType(referenceType);
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
    void setCommitHash(const Char* commitHash)
    {
        ensureData().commitHash.emplace(commitHash);
    }

    /**
     * コミットハッシュを設定
     *
     * @param commitHash コミットハッシュ
     */
    GitHubCheckoutSetting& withCommitHash(const Char* commitHash)
    {
        setCommitHash(commitHash);
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
    void setBranchName(const Char* branchName)
    {
        ensureData().branchName.emplace(branchName);
    }

    /**
     * ブランチ名を設定
     *
     * @param branchName ブランチ名
     */
    GitHubCheckoutSetting& withBranchName(const Char* branchName)
    {
        setBranchName(branchName);
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
    void setTagName(const Char* tagName)
    {
        ensureData().tagName.emplace(tagName);
    }

    /**
     * タグ名を設定
     *
     * @param tagName タグ名
     */
    GitHubCheckoutSetting& withTagName(const Char* tagName)
    {
        setTagName(tagName);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const GitHubCheckoutSetting& lhs, const GitHubCheckoutSetting& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->gitHubApiKeyId != lhr.m_pData->gitHubApiKeyId)
        {
            return true;
        }
        if (lhs.m_pData->repositoryName != lhr.m_pData->repositoryName)
        {
            return true;
        }
        if (lhs.m_pData->sourcePath != lhr.m_pData->sourcePath)
        {
            return true;
        }
        if (lhs.m_pData->referenceType != lhr.m_pData->referenceType)
        {
            return true;
        }
        if (lhs.m_pData->commitHash != lhr.m_pData->commitHash)
        {
            return true;
        }
        if (lhs.m_pData->branchName != lhr.m_pData->branchName)
        {
            return true;
        }
        if (lhs.m_pData->tagName != lhr.m_pData->tagName)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const GitHubCheckoutSetting& lhs, const GitHubCheckoutSetting& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_LOTTERY_MODEL_GITHUBCHECKOUTSETTING_HPP_