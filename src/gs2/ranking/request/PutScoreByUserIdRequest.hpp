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

#ifndef GS2_RANKING_CONTROL_PUTSCOREBYUSERIDREQUEST_HPP_
#define GS2_RANKING_CONTROL_PUTSCOREBYUSERIDREQUEST_HPP_

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
 * ユーザーIDを指定してスコアを登録 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class PutScoreByUserIdRequest : public Gs2BasicRequest, public Gs2Ranking
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
        /** スコア */
        optional<Int64> score;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            categoryName(data.categoryName),
            userId(data.userId),
            score(data.score),
            metadata(data.metadata),
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
    PutScoreByUserIdRequest() = default;
    PutScoreByUserIdRequest(const PutScoreByUserIdRequest& putScoreByUserIdRequest) = default;
    PutScoreByUserIdRequest(PutScoreByUserIdRequest&& putScoreByUserIdRequest) = default;
    ~PutScoreByUserIdRequest() GS2_OVERRIDE = default;

    PutScoreByUserIdRequest& operator=(const PutScoreByUserIdRequest& putScoreByUserIdRequest) = default;
    PutScoreByUserIdRequest& operator=(PutScoreByUserIdRequest&& putScoreByUserIdRequest) = default;

    PutScoreByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(PutScoreByUserIdRequest);
    }

    const PutScoreByUserIdRequest* operator->() const
    {
        return this;
    }

    PutScoreByUserIdRequest* operator->()
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
    PutScoreByUserIdRequest& withNamespaceName(StringHolder namespaceName)
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
    PutScoreByUserIdRequest& withCategoryName(StringHolder categoryName)
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
    PutScoreByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * スコアを取得
     *
     * @return スコア
     */
    const optional<Int64>& getScore() const
    {
        return ensureData().score;
    }

    /**
     * スコアを設定
     *
     * @param score スコア
     */
    void setScore(Int64 score)
    {
        ensureData().score.emplace(score);
    }

    /**
     * スコアを設定
     *
     * @param score スコア
     */
    PutScoreByUserIdRequest& withScore(Int64 score)
    {
        ensureData().score.emplace(score);
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    PutScoreByUserIdRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
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
    PutScoreByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    PutScoreByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    PutScoreByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_RANKING_CONTROL_PUTSCOREBYUSERIDREQUEST_HPP_