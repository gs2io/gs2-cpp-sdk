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

#ifndef GS2_RANKING_CONTROL_GETRANKINGREQUEST_HPP_
#define GS2_RANKING_CONTROL_GETRANKINGREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/ranking/Gs2RankingConst.hpp>
#include <gs2/ranking/model/model.hpp>
#include <memory>

namespace gs2 { namespace ranking
{

/**
 * ランキングを取得 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetRankingRequest : public Gs2BasicRequest, public Gs2Ranking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** カテゴリ名 */
        optional<StringHolder> categoryName;
        /** スコアを獲得したユーザID */
        optional<StringHolder> scorerUserId;
        /** スコアのユニークID */
        optional<StringHolder> uniqueId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            categoryName(data.categoryName),
            scorerUserId(data.scorerUserId),
            uniqueId(data.uniqueId),
            duplicationAvoider(data.duplicationAvoider)
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
    GetRankingRequest() = default;
    GetRankingRequest(const GetRankingRequest& getRankingRequest) = default;
    GetRankingRequest(GetRankingRequest&& getRankingRequest) = default;
    ~GetRankingRequest() GS2_OVERRIDE = default;

    GetRankingRequest& operator=(const GetRankingRequest& getRankingRequest) = default;
    GetRankingRequest& operator=(GetRankingRequest&& getRankingRequest) = default;

    GetRankingRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetRankingRequest);
    }

    const GetRankingRequest* operator->() const
    {
        return this;
    }

    GetRankingRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    GetRankingRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
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
    GetRankingRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getCategoryName() const
    {
        return ensureData().categoryName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    void setCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    GetRankingRequest& withCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
        return *this;
    }

    /**
     * スコアを獲得したユーザIDを取得
     *
     * @return スコアを獲得したユーザID
     */
    const optional<StringHolder>& getScorerUserId() const
    {
        return ensureData().scorerUserId;
    }

    /**
     * スコアを獲得したユーザIDを設定
     *
     * @param scorerUserId スコアを獲得したユーザID
     */
    void setScorerUserId(StringHolder scorerUserId)
    {
        ensureData().scorerUserId.emplace(std::move(scorerUserId));
    }

    /**
     * スコアを獲得したユーザIDを設定
     *
     * @param scorerUserId スコアを獲得したユーザID
     */
    GetRankingRequest& withScorerUserId(StringHolder scorerUserId)
    {
        ensureData().scorerUserId.emplace(std::move(scorerUserId));
        return *this;
    }

    /**
     * スコアのユニークIDを取得
     *
     * @return スコアのユニークID
     */
    const optional<StringHolder>& getUniqueId() const
    {
        return ensureData().uniqueId;
    }

    /**
     * スコアのユニークIDを設定
     *
     * @param uniqueId スコアのユニークID
     */
    void setUniqueId(StringHolder uniqueId)
    {
        ensureData().uniqueId.emplace(std::move(uniqueId));
    }

    /**
     * スコアのユニークIDを設定
     *
     * @param uniqueId スコアのユニークID
     */
    GetRankingRequest& withUniqueId(StringHolder uniqueId)
    {
        ensureData().uniqueId.emplace(std::move(uniqueId));
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    GetRankingRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetRankingRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetRankingRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_RANKING_CONTROL_GETRANKINGREQUEST_HPP_