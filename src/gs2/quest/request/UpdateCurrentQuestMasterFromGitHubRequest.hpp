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

#ifndef GS2_QUEST_CONTROL_UPDATECURRENTQUESTMASTERFROMGITHUBREQUEST_HPP_
#define GS2_QUEST_CONTROL_UPDATECURRENTQUESTMASTERFROMGITHUBREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2QuestConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace quest
{

/**
 * 現在有効な現在有効なクエストマスターを更新します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentQuestMasterFromGitHubRequest : public Gs2BasicRequest, public Gs2Quest
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> namespaceName;
        /** GitHubからマスターデータをチェックアウトしてくる設定 */
        optional<GitHubCheckoutSetting> checkoutSetting;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName)
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
    UpdateCurrentQuestMasterFromGitHubRequest() = default;
    UpdateCurrentQuestMasterFromGitHubRequest(const UpdateCurrentQuestMasterFromGitHubRequest& updateCurrentQuestMasterFromGitHubRequest) = default;
    UpdateCurrentQuestMasterFromGitHubRequest(UpdateCurrentQuestMasterFromGitHubRequest&& updateCurrentQuestMasterFromGitHubRequest) = default;
    ~UpdateCurrentQuestMasterFromGitHubRequest() GS2_OVERRIDE = default;

    UpdateCurrentQuestMasterFromGitHubRequest& operator=(const UpdateCurrentQuestMasterFromGitHubRequest& updateCurrentQuestMasterFromGitHubRequest) = default;
    UpdateCurrentQuestMasterFromGitHubRequest& operator=(UpdateCurrentQuestMasterFromGitHubRequest&& updateCurrentQuestMasterFromGitHubRequest) = default;

    UpdateCurrentQuestMasterFromGitHubRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateCurrentQuestMasterFromGitHubRequest);
    }

    const UpdateCurrentQuestMasterFromGitHubRequest* operator->() const
    {
        return this;
    }

    UpdateCurrentQuestMasterFromGitHubRequest* operator->()
    {
        return this;
    }

    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * カテゴリ名を設定
     *
     * @param namespaceName カテゴリ名
     */
    UpdateCurrentQuestMasterFromGitHubRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * GitHubからマスターデータをチェックアウトしてくる設定を取得
     *
     * @return GitHubからマスターデータをチェックアウトしてくる設定
     */
    const optional<GitHubCheckoutSetting>& getCheckoutSetting() const
    {
        return ensureData().checkoutSetting;
    }

    /**
     * GitHubからマスターデータをチェックアウトしてくる設定を設定
     *
     * @param checkoutSetting GitHubからマスターデータをチェックアウトしてくる設定
     */
    void setCheckoutSetting(GitHubCheckoutSetting checkoutSetting)
    {
        ensureData().checkoutSetting.emplace(std::move(checkoutSetting));
    }

    /**
     * GitHubからマスターデータをチェックアウトしてくる設定を設定
     *
     * @param checkoutSetting GitHubからマスターデータをチェックアウトしてくる設定
     */
    UpdateCurrentQuestMasterFromGitHubRequest& withCheckoutSetting(GitHubCheckoutSetting checkoutSetting)
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
    UpdateCurrentQuestMasterFromGitHubRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCurrentQuestMasterFromGitHubRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_QUEST_CONTROL_UPDATECURRENTQUESTMASTERFROMGITHUBREQUEST_HPP_