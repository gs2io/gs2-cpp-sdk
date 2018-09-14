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

#ifndef GS2_RANKING_CONTROL_UPDATEGAMEMODEREQUEST_HPP_
#define GS2_RANKING_CONTROL_UPDATEGAMEMODEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2RankingConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace ranking
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateGameModeRequest : public Gs2BasicRequest, public Gs2Ranking
{
public:
    constexpr static const Char* const FUNCTION = "UpdateGameMode";

private:
    class Data : public Gs2Object
    {
    public:
        /** ランキングテーブルの名前を指定します。 */
        optional<StringHolder> rankingTableName;
        /** ゲームモードの名前を指定します。 */
        optional<StringHolder> gameMode;
        /** このゲームモードのランキング集計間隔を分単位で指定します */
        optional<Int32> calcInterval;
        /** スコア登録時 に実行されるGS2-Script */
        optional<StringHolder> putScoreTriggerScript;
        /** スコア登録完了時 に実行されるGS2-Script */
        optional<StringHolder> putScoreDoneTriggerScript;
        /** 集計処理完了時 に実行されるGS2-Script */
        optional<StringHolder> calculateRankingDoneTriggerScript;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            rankingTableName(data.rankingTableName),
            gameMode(data.gameMode),
            calcInterval(data.calcInterval),
            putScoreTriggerScript(data.putScoreTriggerScript),
            putScoreDoneTriggerScript(data.putScoreDoneTriggerScript),
            calculateRankingDoneTriggerScript(data.calculateRankingDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            rankingTableName(std::move(data.rankingTableName)),
            gameMode(std::move(data.gameMode)),
            calcInterval(std::move(data.calcInterval)),
            putScoreTriggerScript(std::move(data.putScoreTriggerScript)),
            putScoreDoneTriggerScript(std::move(data.putScoreDoneTriggerScript)),
            calculateRankingDoneTriggerScript(std::move(data.calculateRankingDoneTriggerScript))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    UpdateGameModeRequest() :
        m_pData(nullptr)
    {}

    UpdateGameModeRequest(const UpdateGameModeRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Ranking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateGameModeRequest(UpdateGameModeRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Ranking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateGameModeRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateGameModeRequest& operator=(const UpdateGameModeRequest& updateGameModeRequest)
    {
        Gs2BasicRequest::operator=(updateGameModeRequest);
        Gs2Ranking::operator=(updateGameModeRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateGameModeRequest.m_pData);

        return *this;
    }

    UpdateGameModeRequest& operator=(UpdateGameModeRequest&& updateGameModeRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateGameModeRequest));
        Gs2Ranking::operator=(std::move(updateGameModeRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateGameModeRequest.m_pData;
        updateGameModeRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateGameModeRequest* operator->() const
    {
        return this;
    }

    UpdateGameModeRequest* operator->()
    {
        return this;
    }

    /**
     * ランキングテーブルの名前を指定します。を取得
     *
     * @return ランキングテーブルの名前を指定します。
     */
    const optional<StringHolder>& getRankingTableName() const
    {
        return ensureData().rankingTableName;
    }

    /**
     * ランキングテーブルの名前を指定します。を設定
     *
     * @param rankingTableName ランキングテーブルの名前を指定します。
     */
    void setRankingTableName(const Char* rankingTableName)
    {
        ensureData().rankingTableName.emplace(rankingTableName);
    }

    /**
     * ランキングテーブルの名前を指定します。を設定
     *
     * @param rankingTableName ランキングテーブルの名前を指定します。
     */
    UpdateGameModeRequest& withRankingTableName(const Char* rankingTableName)
    {
        ensureData().rankingTableName.emplace(rankingTableName);
        return *this;
    }

    /**
     * ゲームモードの名前を指定します。を取得
     *
     * @return ゲームモードの名前を指定します。
     */
    const optional<StringHolder>& getGameMode() const
    {
        return ensureData().gameMode;
    }

    /**
     * ゲームモードの名前を指定します。を設定
     *
     * @param gameMode ゲームモードの名前を指定します。
     */
    void setGameMode(const Char* gameMode)
    {
        ensureData().gameMode.emplace(gameMode);
    }

    /**
     * ゲームモードの名前を指定します。を設定
     *
     * @param gameMode ゲームモードの名前を指定します。
     */
    UpdateGameModeRequest& withGameMode(const Char* gameMode)
    {
        ensureData().gameMode.emplace(gameMode);
        return *this;
    }

    /**
     * このゲームモードのランキング集計間隔を分単位で指定しますを取得
     *
     * @return このゲームモードのランキング集計間隔を分単位で指定します
     */
    const optional<Int32>& getCalcInterval() const
    {
        return ensureData().calcInterval;
    }

    /**
     * このゲームモードのランキング集計間隔を分単位で指定しますを設定
     *
     * @param calcInterval このゲームモードのランキング集計間隔を分単位で指定します
     */
    void setCalcInterval(Int32 calcInterval)
    {
        ensureData().calcInterval.emplace(calcInterval);
    }

    /**
     * このゲームモードのランキング集計間隔を分単位で指定しますを設定
     *
     * @param calcInterval このゲームモードのランキング集計間隔を分単位で指定します
     */
    UpdateGameModeRequest& withCalcInterval(Int32 calcInterval)
    {
        ensureData().calcInterval.emplace(calcInterval);
        return *this;
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
     * スコア登録時 に実行されるGS2-Scriptを設定
     *
     * @param putScoreTriggerScript スコア登録時 に実行されるGS2-Script
     */
    UpdateGameModeRequest& withPutScoreTriggerScript(const Char* putScoreTriggerScript)
    {
        ensureData().putScoreTriggerScript.emplace(putScoreTriggerScript);
        return *this;
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
     * スコア登録完了時 に実行されるGS2-Scriptを設定
     *
     * @param putScoreDoneTriggerScript スコア登録完了時 に実行されるGS2-Script
     */
    UpdateGameModeRequest& withPutScoreDoneTriggerScript(const Char* putScoreDoneTriggerScript)
    {
        ensureData().putScoreDoneTriggerScript.emplace(putScoreDoneTriggerScript);
        return *this;
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
     * 集計処理完了時 に実行されるGS2-Scriptを設定
     *
     * @param calculateRankingDoneTriggerScript 集計処理完了時 に実行されるGS2-Script
     */
    UpdateGameModeRequest& withCalculateRankingDoneTriggerScript(const Char* calculateRankingDoneTriggerScript)
    {
        ensureData().calculateRankingDoneTriggerScript.emplace(calculateRankingDoneTriggerScript);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateGameModeRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    UpdateGameModeRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    UpdateGameModeRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateGameModeRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_RANKING_CONTROL_UPDATEGAMEMODEREQUEST_HPP_