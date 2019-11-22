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

#ifndef GS2_RANKING_MODEL_RANKING_HPP_
#define GS2_RANKING_MODEL_RANKING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace ranking {

/**
 * ランキング
 *
 * @author Game Server Services, Inc.
 *
 */
class Ranking : public Gs2Object
{
    friend bool operator!=(const Ranking& lhs, const Ranking& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 順位 */
        optional<Int64> rank;
        /** 1位からのインデックス */
        optional<Int64> index;
        /** ユーザID */
        optional<StringHolder> userId;
        /** スコア */
        optional<Int64> score;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** 作成日時 */
        optional<Int64> createdAt;

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
    Ranking() = default;
    Ranking(const Ranking& ranking) = default;
    Ranking(Ranking&& ranking) = default;
    ~Ranking() = default;

    Ranking& operator=(const Ranking& ranking) = default;
    Ranking& operator=(Ranking&& ranking) = default;

    Ranking deepCopy() const;

    const Ranking* operator->() const
    {
        return this;
    }

    Ranking* operator->()
    {
        return this;
    }
    /**
     * 順位を取得
     *
     * @return 順位
     */
    const optional<Int64>& getRank() const
    {
        return ensureData().rank;
    }

    /**
     * 順位を設定
     *
     * @param rank 順位
     */
    void setRank(Int64 rank)
    {
        ensureData().rank.emplace(rank);
    }

    /**
     * 順位を設定
     *
     * @param rank 順位
     */
    Ranking& withRank(Int64 rank)
    {
        setRank(rank);
        return *this;
    }

    /**
     * 1位からのインデックスを取得
     *
     * @return 1位からのインデックス
     */
    const optional<Int64>& getIndex() const
    {
        return ensureData().index;
    }

    /**
     * 1位からのインデックスを設定
     *
     * @param index 1位からのインデックス
     */
    void setIndex(Int64 index)
    {
        ensureData().index.emplace(index);
    }

    /**
     * 1位からのインデックスを設定
     *
     * @param index 1位からのインデックス
     */
    Ranking& withIndex(Int64 index)
    {
        setIndex(index);
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
    Ranking& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
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
    Ranking& withScore(Int64 score)
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
    Ranking& withMetadata(StringHolder metadata)
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
    Ranking& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const Ranking& lhs, const Ranking& lhr);

inline bool operator==(const Ranking& lhs, const Ranking& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_RANKING_MODEL_RANKING_HPP_