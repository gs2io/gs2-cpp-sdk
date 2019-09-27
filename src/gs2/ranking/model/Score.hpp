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

#ifndef GS2_RANKING_MODEL_SCORE_HPP_
#define GS2_RANKING_MODEL_SCORE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace ranking {

/**
 * スコア
 *
 * @author Game Server Services, Inc.
 *
 */
class Score : public Gs2Object
{
    friend bool operator!=(const Score& lhs, const Score& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スコア */
        optional<StringHolder> scoreId;
        /** カテゴリ名 */
        optional<StringHolder> categoryName;
        /** ユーザID */
        optional<StringHolder> userId;
        /** スコアのユニークID */
        optional<StringHolder> uniqueId;
        /** スコアを獲得したユーザID */
        optional<StringHolder> scorerUserId;
        /** スコア */
        optional<Int64> score;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** 作成日時 */
        optional<Int64> createdAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            scoreId(data.scoreId),
            categoryName(data.categoryName),
            userId(data.userId),
            uniqueId(data.uniqueId),
            scorerUserId(data.scorerUserId),
            score(data.score),
            metadata(data.metadata),
            createdAt(data.createdAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "scoreId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->scoreId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "categoryName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->categoryName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "uniqueId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->uniqueId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "scorerUserId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->scorerUserId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "score") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->score = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Score() = default;
    Score(const Score& score) = default;
    Score(Score&& score) = default;
    ~Score() = default;

    Score& operator=(const Score& score) = default;
    Score& operator=(Score&& score) = default;

    Score deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Score);
    }

    const Score* operator->() const
    {
        return this;
    }

    Score* operator->()
    {
        return this;
    }
    /**
     * スコアを取得
     *
     * @return スコア
     */
    const optional<StringHolder>& getScoreId() const
    {
        return ensureData().scoreId;
    }

    /**
     * スコアを設定
     *
     * @param scoreId スコア
     */
    void setScoreId(StringHolder scoreId)
    {
        ensureData().scoreId.emplace(std::move(scoreId));
    }

    /**
     * スコアを設定
     *
     * @param scoreId スコア
     */
    Score& withScoreId(StringHolder scoreId)
    {
        setScoreId(std::move(scoreId));
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
    Score& withCategoryName(StringHolder categoryName)
    {
        setCategoryName(std::move(categoryName));
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
    Score& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
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
    Score& withUniqueId(StringHolder uniqueId)
    {
        setUniqueId(std::move(uniqueId));
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
    Score& withScorerUserId(StringHolder scorerUserId)
    {
        setScorerUserId(std::move(scorerUserId));
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
    Score& withScore(Int64 score)
    {
        setScore(score);
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
    Score& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    Score& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Score& lhs, const Score& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->scoreId != lhr.m_pData->scoreId)
        {
            return true;
        }
        if (lhs.m_pData->categoryName != lhr.m_pData->categoryName)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->uniqueId != lhr.m_pData->uniqueId)
        {
            return true;
        }
        if (lhs.m_pData->scorerUserId != lhr.m_pData->scorerUserId)
        {
            return true;
        }
        if (lhs.m_pData->score != lhr.m_pData->score)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Score& lhs, const Score& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_RANKING_MODEL_SCORE_HPP_