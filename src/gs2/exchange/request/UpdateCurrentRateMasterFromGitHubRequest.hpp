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

#ifndef GS2_EXCHANGE_CONTROL_UPDATECURRENTRATEMASTERFROMGITHUBREQUEST_HPP_
#define GS2_EXCHANGE_CONTROL_UPDATECURRENTRATEMASTERFROMGITHUBREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/exchange/Gs2ExchangeConst.hpp>
#include <gs2/exchange/model/model.hpp>
#include <memory>

namespace gs2 { namespace exchange
{

/**
 * 現在有効な交換レート設定を更新します のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateCurrentRateMasterFromGitHubRequest : public Gs2BasicRequest, public Gs2Exchange
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
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
    UpdateCurrentRateMasterFromGitHubRequest() = default;
    UpdateCurrentRateMasterFromGitHubRequest(const UpdateCurrentRateMasterFromGitHubRequest& updateCurrentRateMasterFromGitHubRequest) = default;
    UpdateCurrentRateMasterFromGitHubRequest(UpdateCurrentRateMasterFromGitHubRequest&& updateCurrentRateMasterFromGitHubRequest) = default;
    ~UpdateCurrentRateMasterFromGitHubRequest() GS2_OVERRIDE = default;

    UpdateCurrentRateMasterFromGitHubRequest& operator=(const UpdateCurrentRateMasterFromGitHubRequest& updateCurrentRateMasterFromGitHubRequest) = default;
    UpdateCurrentRateMasterFromGitHubRequest& operator=(UpdateCurrentRateMasterFromGitHubRequest&& updateCurrentRateMasterFromGitHubRequest) = default;

    UpdateCurrentRateMasterFromGitHubRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateCurrentRateMasterFromGitHubRequest);
    }

    const UpdateCurrentRateMasterFromGitHubRequest* operator->() const
    {
        return this;
    }

    UpdateCurrentRateMasterFromGitHubRequest* operator->()
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
    UpdateCurrentRateMasterFromGitHubRequest& withNamespaceName(StringHolder namespaceName)
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
    UpdateCurrentRateMasterFromGitHubRequest& withCheckoutSetting(GitHubCheckoutSetting checkoutSetting)
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
    UpdateCurrentRateMasterFromGitHubRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateCurrentRateMasterFromGitHubRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_EXCHANGE_CONTROL_UPDATECURRENTRATEMASTERFROMGITHUBREQUEST_HPP_