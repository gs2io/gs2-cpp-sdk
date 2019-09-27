

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

#ifndef GS2_EZ_RANKING_MODEL_EZSCORE_HPP_
#define GS2_EZ_RANKING_MODEL_EZSCORE_HPP_

#include <gs2/ranking/model/Score.hpp>


namespace gs2 { namespace ez { namespace ranking {

class EzScore : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** カテゴリ名 */
        gs2::optional<StringHolder> categoryName;
        /** ユーザID */
        gs2::optional<StringHolder> userId;
        /** スコアを獲得したユーザID */
        gs2::optional<StringHolder> scorerUserId;
        /** スコア */
        gs2::optional<Int64> score;
        /** メタデータ */
        gs2::optional<StringHolder> metadata;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            categoryName(data.categoryName),
            userId(data.userId),
            scorerUserId(data.scorerUserId),
            score(data.score),
            metadata(data.metadata)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::ranking::Score& score) :
            categoryName(score.getCategoryName()),
            userId(score.getUserId()),
            scorerUserId(score.getScorerUserId()),
            score(score.getScore() ? *score.getScore() : 0),
            metadata(score.getMetadata())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzScore() = default;
    EzScore(const EzScore& ezScore) = default;
    EzScore(EzScore&& ezScore) = default;
    ~EzScore() = default;

    EzScore(gs2::ranking::Score score) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(score)
    {}

    EzScore& operator=(const EzScore& ezScore) = default;
    EzScore& operator=(EzScore&& ezScore) = default;

    EzScore deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzScore);
    }

    gs2::ranking::Score ToModel() const
    {
        gs2::ranking::Score score;
        score.setCategoryName(getCategoryName());
        score.setUserId(getUserId());
        score.setScorerUserId(getScorerUserId());
        score.setScore(getScore());
        score.setMetadata(getMetadata());
        return score;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getCategoryName() const
    {
        return *ensureData().categoryName;
    }

    const StringHolder& getUserId() const
    {
        return *ensureData().userId;
    }

    const StringHolder& getScorerUserId() const
    {
        return *ensureData().scorerUserId;
    }

    Int64 getScore() const
    {
        return *ensureData().score;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    // ========================================
    //   Setters
    // ========================================

    void setCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName = std::move(categoryName);
    }

    void setUserId(StringHolder userId)
    {
        ensureData().userId = std::move(userId);
    }

    void setScorerUserId(StringHolder scorerUserId)
    {
        ensureData().scorerUserId = std::move(scorerUserId);
    }

    void setScore(Int64 score)
    {
        ensureData().score = score;
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    EzScore& withCategoryName(StringHolder categoryName)
    {
        setCategoryName(std::move(categoryName));
        return *this;
    }

    EzScore& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    EzScore& withScorerUserId(StringHolder scorerUserId)
    {
        setScorerUserId(std::move(scorerUserId));
        return *this;
    }

    EzScore& withScore(Int64 score)
    {
        setScore(score);
        return *this;
    }

    EzScore& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }
};

}}}

#endif //GS2_EZ_RANKING_EZSCORE_HPP_