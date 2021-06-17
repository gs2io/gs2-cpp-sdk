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

#ifndef GS2_RANKING_CONTROL_GETRANKINGBYUSERIDREQUEST_HPP_
#define GS2_RANKING_CONTROL_GETRANKINGBYUSERIDREQUEST_HPP_

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
class GetRankingByUserIdRequest : public Gs2BasicRequest, public Gs2Ranking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** カテゴリ名 */
        optional<StringHolder> categoryName;
        /** ユーザID */
        optional<StringHolder> userId;
        /** スコアを獲得したユーザID */
        optional<StringHolder> scorerUserId;
        /** スコアのユニークID */
        optional<StringHolder> uniqueId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            categoryName(data.categoryName),
            userId(data.userId),
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
    GetRankingByUserIdRequest() = default;
    GetRankingByUserIdRequest(const GetRankingByUserIdRequest& getRankingByUserIdRequest) = default;
    GetRankingByUserIdRequest(GetRankingByUserIdRequest&& getRankingByUserIdRequest) = default;
    ~GetRankingByUserIdRequest() GS2_OVERRIDE = default;

    GetRankingByUserIdRequest& operator=(const GetRankingByUserIdRequest& getRankingByUserIdRequest) = default;
    GetRankingByUserIdRequest& operator=(GetRankingByUserIdRequest&& getRankingByUserIdRequest) = default;

    GetRankingByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetRankingByUserIdRequest);
    }

    const GetRankingByUserIdRequest* operator->() const
    {
        return this;
    }

    GetRankingByUserIdRequest* operator->()
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
    GetRankingByUserIdRequest& withNamespaceName(StringHolder namespaceName)
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
    GetRankingByUserIdRequest& withCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
        return *this;
    }

    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    GetRankingByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
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
    GetRankingByUserIdRequest& withScorerUserId(StringHolder scorerUserId)
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
    GetRankingByUserIdRequest& withUniqueId(StringHolder uniqueId)
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
    GetRankingByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    GetRankingByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetRankingByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_RANKING_CONTROL_GETRANKINGBYUSERIDREQUEST_HPP_