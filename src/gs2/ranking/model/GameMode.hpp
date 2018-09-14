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

#ifndef GS2_RANKING_MODEL_GAMEMODE_HPP_
#define GS2_RANKING_MODEL_GAMEMODE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace ranking {

/**
 * ゲームモード
 *
 * @author Game Server Services, Inc.
 *
 */
class GameMode : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ゲームモードGRN */
        optional<StringHolder> gameModeId;
        /** ランキングテーブル */
        optional<StringHolder> rankingTableId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** ゲームモード名 */
        optional<StringHolder> gameMode;
        /** ランキング計算に昇順を適用するか */
        optional<Bool> asc;
        /** 集計間隔(分) */
        optional<Int32> calcInterval;
        /** 集計処理中か否か */
        optional<Bool> calculating;
        /** スコア登録時 に実行されるGS2-Script */
        optional<StringHolder> putScoreTriggerScript;
        /** スコア登録完了時 に実行されるGS2-Script */
        optional<StringHolder> putScoreDoneTriggerScript;
        /** 集計処理完了時 に実行されるGS2-Script */
        optional<StringHolder> calculateRankingDoneTriggerScript;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 更新日時(エポック秒) */
        optional<Int32> updateAt;
        /** 最終集計日時(エポック秒) */
        optional<Int32> lastCalcAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gameModeId(data.gameModeId),
            rankingTableId(data.rankingTableId),
            ownerId(data.ownerId),
            gameMode(data.gameMode),
            asc(data.asc),
            calcInterval(data.calcInterval),
            calculating(data.calculating),
            putScoreTriggerScript(data.putScoreTriggerScript),
            putScoreDoneTriggerScript(data.putScoreDoneTriggerScript),
            calculateRankingDoneTriggerScript(data.calculateRankingDoneTriggerScript),
            createAt(data.createAt),
            updateAt(data.updateAt),
            lastCalcAt(data.lastCalcAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gameModeId(std::move(data.gameModeId)),
            rankingTableId(std::move(data.rankingTableId)),
            ownerId(std::move(data.ownerId)),
            gameMode(std::move(data.gameMode)),
            asc(std::move(data.asc)),
            calcInterval(std::move(data.calcInterval)),
            calculating(std::move(data.calculating)),
            putScoreTriggerScript(std::move(data.putScoreTriggerScript)),
            putScoreDoneTriggerScript(std::move(data.putScoreDoneTriggerScript)),
            calculateRankingDoneTriggerScript(std::move(data.calculateRankingDoneTriggerScript)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt)),
            lastCalcAt(std::move(data.lastCalcAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gameModeId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gameModeId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "rankingTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->rankingTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "gameMode") == 0) {
                if (jsonValue.IsString())
                {
                    this->gameMode.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "asc") == 0) {
                if (jsonValue.IsBool())
                {
                    this->asc = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "calcInterval") == 0) {
                if (jsonValue.IsInt())
                {
                    this->calcInterval = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "calculating") == 0) {
                if (jsonValue.IsBool())
                {
                    this->calculating = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "putScoreTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->putScoreTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "putScoreDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->putScoreDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "calculateRankingDoneTriggerScript") == 0) {
                if (jsonValue.IsString())
                {
                    this->calculateRankingDoneTriggerScript.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "lastCalcAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->lastCalcAt = jsonValue.GetInt();
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
    GameMode() :
        m_pData(nullptr)
    {}

    GameMode(const GameMode& gameMode) :
        Gs2Object(gameMode),
        m_pData(gameMode.m_pData != nullptr ? new Data(*gameMode.m_pData) : nullptr)
    {}

    GameMode(GameMode&& gameMode) :
        Gs2Object(std::move(gameMode)),
        m_pData(gameMode.m_pData)
    {
        gameMode.m_pData = nullptr;
    }

    ~GameMode()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GameMode& operator=(const GameMode& gameMode)
    {
        Gs2Object::operator=(gameMode);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*gameMode.m_pData);

        return *this;
    }

    GameMode& operator=(GameMode&& gameMode)
    {
        Gs2Object::operator=(std::move(gameMode));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = gameMode.m_pData;
        gameMode.m_pData = nullptr;

        return *this;
    }

    const GameMode* operator->() const
    {
        return this;
    }

    GameMode* operator->()
    {
        return this;
    }


    /**
     * ゲームモードGRNを取得
     *
     * @return ゲームモードGRN
     */
    const optional<StringHolder>& getGameModeId() const
    {
        return ensureData().gameModeId;
    }

    /**
     * ゲームモードGRNを設定
     *
     * @param gameModeId ゲームモードGRN
     */
    void setGameModeId(const Char* gameModeId)
    {
        ensureData().gameModeId.emplace(gameModeId);
    }

    /**
     * ランキングテーブルを取得
     *
     * @return ランキングテーブル
     */
    const optional<StringHolder>& getRankingTableId() const
    {
        return ensureData().rankingTableId;
    }

    /**
     * ランキングテーブルを設定
     *
     * @param rankingTableId ランキングテーブル
     */
    void setRankingTableId(const Char* rankingTableId)
    {
        ensureData().rankingTableId.emplace(rankingTableId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
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
     * ランキング計算に昇順を適用するかを取得
     *
     * @return ランキング計算に昇順を適用するか
     */
    const optional<Bool>& getAsc() const
    {
        return ensureData().asc;
    }

    /**
     * ランキング計算に昇順を適用するかを設定
     *
     * @param asc ランキング計算に昇順を適用するか
     */
    void setAsc(Bool asc)
    {
        ensureData().asc.emplace(asc);
    }

    /**
     * 集計間隔(分)を取得
     *
     * @return 集計間隔(分)
     */
    const optional<Int32>& getCalcInterval() const
    {
        return ensureData().calcInterval;
    }

    /**
     * 集計間隔(分)を設定
     *
     * @param calcInterval 集計間隔(分)
     */
    void setCalcInterval(Int32 calcInterval)
    {
        ensureData().calcInterval.emplace(calcInterval);
    }

    /**
     * 集計処理中か否かを取得
     *
     * @return 集計処理中か否か
     */
    const optional<Bool>& getCalculating() const
    {
        return ensureData().calculating;
    }

    /**
     * 集計処理中か否かを設定
     *
     * @param calculating 集計処理中か否か
     */
    void setCalculating(Bool calculating)
    {
        ensureData().calculating.emplace(calculating);
    }

    /**
     * スコア登録時 に実行されるGS2-Scriptを取得
     *
     * @return スコア登録時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getPutScoreTriggerScript() const
    {
        return ensureData().putScoreTriggerScript;
    }

    /**
     * スコア登録時 に実行されるGS2-Scriptを設定
     *
     * @param putScoreTriggerScript スコア登録時 に実行されるGS2-Script
     */
    void setPutScoreTriggerScript(const Char* putScoreTriggerScript)
    {
        ensureData().putScoreTriggerScript.emplace(putScoreTriggerScript);
    }

    /**
     * スコア登録完了時 に実行されるGS2-Scriptを取得
     *
     * @return スコア登録完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getPutScoreDoneTriggerScript() const
    {
        return ensureData().putScoreDoneTriggerScript;
    }

    /**
     * スコア登録完了時 に実行されるGS2-Scriptを設定
     *
     * @param putScoreDoneTriggerScript スコア登録完了時 に実行されるGS2-Script
     */
    void setPutScoreDoneTriggerScript(const Char* putScoreDoneTriggerScript)
    {
        ensureData().putScoreDoneTriggerScript.emplace(putScoreDoneTriggerScript);
    }

    /**
     * 集計処理完了時 に実行されるGS2-Scriptを取得
     *
     * @return 集計処理完了時 に実行されるGS2-Script
     */
    const optional<StringHolder>& getCalculateRankingDoneTriggerScript() const
    {
        return ensureData().calculateRankingDoneTriggerScript;
    }

    /**
     * 集計処理完了時 に実行されるGS2-Scriptを設定
     *
     * @param calculateRankingDoneTriggerScript 集計処理完了時 に実行されるGS2-Script
     */
    void setCalculateRankingDoneTriggerScript(const Char* calculateRankingDoneTriggerScript)
    {
        ensureData().calculateRankingDoneTriggerScript.emplace(calculateRankingDoneTriggerScript);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 更新日時(エポック秒)を取得
     *
     * @return 更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 更新日時(エポック秒)を設定
     *
     * @param updateAt 更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }

    /**
     * 最終集計日時(エポック秒)を取得
     *
     * @return 最終集計日時(エポック秒)
     */
    const optional<Int32>& getLastCalcAt() const
    {
        return ensureData().lastCalcAt;
    }

    /**
     * 最終集計日時(エポック秒)を設定
     *
     * @param lastCalcAt 最終集計日時(エポック秒)
     */
    void setLastCalcAt(Int32 lastCalcAt)
    {
        ensureData().lastCalcAt.emplace(lastCalcAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_RANKING_MODEL_GAMEMODE_HPP_