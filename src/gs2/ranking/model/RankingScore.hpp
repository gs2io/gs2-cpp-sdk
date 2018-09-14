/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_RANKING_MODEL_RANKINGSCORE_HPP_
#define GS2_RANKING_MODEL_RANKINGSCORE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace ranking {

/**
 * スコア
 *
 * @author Game Server Services, Inc.
 *
 */
class RankingScore : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 先頭からの位置 */
        optional<Int64> index;
        /** 同点同順位を採用した場合の順位 */
        optional<Int64> rank;
        /** ユーザID */
        optional<StringHolder> userId;
        /** スコア値 */
        optional<Int64> score;
        /** メタデータ */
        optional<StringHolder> meta;
        /** 登録日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            index(data.index),
            rank(data.rank),
            userId(data.userId),
            score(data.score),
            meta(data.meta),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            index(std::move(data.index)),
            rank(std::move(data.rank)),
            userId(std::move(data.userId)),
            score(std::move(data.score)),
            meta(std::move(data.meta)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "index") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->index = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "rank") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->rank = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "score") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->score = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "meta") == 0) {
                if (jsonValue.IsString())
                {
                    this->meta.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    RankingScore() :
        m_pData(nullptr)
    {}

    RankingScore(const RankingScore& rankingScore) :
        Gs2Object(rankingScore),
        m_pData(rankingScore.m_pData != nullptr ? new Data(*rankingScore.m_pData) : nullptr)
    {}

    RankingScore(RankingScore&& rankingScore) :
        Gs2Object(std::move(rankingScore)),
        m_pData(rankingScore.m_pData)
    {
        rankingScore.m_pData = nullptr;
    }

    ~RankingScore()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    RankingScore& operator=(const RankingScore& rankingScore)
    {
        Gs2Object::operator=(rankingScore);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*rankingScore.m_pData);

        return *this;
    }

    RankingScore& operator=(RankingScore&& rankingScore)
    {
        Gs2Object::operator=(std::move(rankingScore));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = rankingScore.m_pData;
        rankingScore.m_pData = nullptr;

        return *this;
    }

    const RankingScore* operator->() const
    {
        return this;
    }

    RankingScore* operator->()
    {
        return this;
    }


    /**
     * 先頭からの位置を取得
     *
     * @return 先頭からの位置
     */
    const optional<Int64>& getIndex() const
    {
        return ensureData().index;
    }

    /**
     * 先頭からの位置を設定
     *
     * @param index 先頭からの位置
     */
    void setIndex(Int64 index)
    {
        ensureData().index.emplace(index);
    }

    /**
     * 同点同順位を採用した場合の順位を取得
     *
     * @return 同点同順位を採用した場合の順位
     */
    const optional<Int64>& getRank() const
    {
        return ensureData().rank;
    }

    /**
     * 同点同順位を採用した場合の順位を設定
     *
     * @param rank 同点同順位を採用した場合の順位
     */
    void setRank(Int64 rank)
    {
        ensureData().rank.emplace(rank);
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
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * スコア値を取得
     *
     * @return スコア値
     */
    const optional<Int64>& getScore() const
    {
        return ensureData().score;
    }

    /**
     * スコア値を設定
     *
     * @param score スコア値
     */
    void setScore(Int64 score)
    {
        ensureData().score.emplace(score);
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * メタデータを設定
     *
     * @param meta メタデータ
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * 登録日時(エポック秒)を取得
     *
     * @return 登録日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 登録日時(エポック秒)を設定
     *
     * @param updateAt 登録日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_RANKING_MODEL_RANKINGSCORE_HPP_