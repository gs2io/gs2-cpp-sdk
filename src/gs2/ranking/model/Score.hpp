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

#ifndef GS2_RANKING_MODEL_SCORE_HPP_
#define GS2_RANKING_MODEL_SCORE_HPP_

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
class Score : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ランキングテーブルGRN */
        optional<StringHolder> rankingTableId;
        /** ゲームモード名 */
        optional<StringHolder> gameMode;
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
            rankingTableId(data.rankingTableId),
            gameMode(data.gameMode),
            userId(data.userId),
            score(data.score),
            meta(data.meta),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            rankingTableId(std::move(data.rankingTableId)),
            gameMode(std::move(data.gameMode)),
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
            if (std::strcmp(name, "rankingTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->rankingTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "gameMode") == 0) {
                if (jsonValue.IsString())
                {
                    this->gameMode.emplace(jsonValue.GetString());
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
    Score() :
        m_pData(nullptr)
    {}

    Score(const Score& score) :
        Gs2Object(score),
        m_pData(score.m_pData != nullptr ? new Data(*score.m_pData) : nullptr)
    {}

    Score(Score&& score) :
        Gs2Object(std::move(score)),
        m_pData(score.m_pData)
    {
        score.m_pData = nullptr;
    }

    ~Score()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Score& operator=(const Score& score)
    {
        Gs2Object::operator=(score);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*score.m_pData);

        return *this;
    }

    Score& operator=(Score&& score)
    {
        Gs2Object::operator=(std::move(score));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = score.m_pData;
        score.m_pData = nullptr;

        return *this;
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
     * ランキングテーブルGRNを取得
     *
     * @return ランキングテーブルGRN
     */
    const optional<StringHolder>& getRankingTableId() const
    {
        return ensureData().rankingTableId;
    }

    /**
     * ランキングテーブルGRNを設定
     *
     * @param rankingTableId ランキングテーブルGRN
     */
    void setRankingTableId(const Char* rankingTableId)
    {
        ensureData().rankingTableId.emplace(rankingTableId);
    }

    /**
     * ゲームモード名を取得
     *
     * @return ゲームモード名
     */
    const optional<StringHolder>& getGameMode() const
    {
        return ensureData().gameMode;
    }

    /**
     * ゲームモード名を設定
     *
     * @param gameMode ゲームモード名
     */
    void setGameMode(const Char* gameMode)
    {
        ensureData().gameMode.emplace(gameMode);
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

#endif //GS2_RANKING_MODEL_SCORE_HPP_