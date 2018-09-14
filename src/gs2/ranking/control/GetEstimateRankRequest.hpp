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

#ifndef GS2_RANKING_CONTROL_GETESTIMATERANKREQUEST_HPP_
#define GS2_RANKING_CONTROL_GETESTIMATERANKREQUEST_HPP_

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
class GetEstimateRankRequest : public Gs2BasicRequest, public Gs2Ranking
{
public:
    constexpr static const Char* const FUNCTION = "GetEstimateRank";

private:
    class Data : public Gs2Object
    {
    public:
        /** ランキングテーブルの名前を指定します。 */
        optional<StringHolder> rankingTableName;
        /** ゲームモードの名前を指定します。 */
        optional<StringHolder> gameMode;
        /** スコア値 */
        optional<Int64> score;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            rankingTableName(data.rankingTableName),
            gameMode(data.gameMode),
            score(data.score)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            rankingTableName(std::move(data.rankingTableName)),
            gameMode(std::move(data.gameMode)),
            score(std::move(data.score))
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
    GetEstimateRankRequest() :
        m_pData(nullptr)
    {}

    GetEstimateRankRequest(const GetEstimateRankRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Ranking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetEstimateRankRequest(GetEstimateRankRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Ranking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetEstimateRankRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetEstimateRankRequest& operator=(const GetEstimateRankRequest& getEstimateRankRequest)
    {
        Gs2BasicRequest::operator=(getEstimateRankRequest);
        Gs2Ranking::operator=(getEstimateRankRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getEstimateRankRequest.m_pData);

        return *this;
    }

    GetEstimateRankRequest& operator=(GetEstimateRankRequest&& getEstimateRankRequest)
    {
        Gs2BasicRequest::operator=(std::move(getEstimateRankRequest));
        Gs2Ranking::operator=(std::move(getEstimateRankRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getEstimateRankRequest.m_pData;
        getEstimateRankRequest.m_pData = nullptr;

        return *this;
    }

    const GetEstimateRankRequest* operator->() const
    {
        return this;
    }

    GetEstimateRankRequest* operator->()
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
    GetEstimateRankRequest& withRankingTableName(const Char* rankingTableName)
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
    GetEstimateRankRequest& withGameMode(const Char* gameMode)
    {
        ensureData().gameMode.emplace(gameMode);
        return *this;
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
     * スコア値を設定
     *
     * @param score スコア値
     */
    GetEstimateRankRequest& withScore(Int64 score)
    {
        ensureData().score.emplace(score);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetEstimateRankRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetEstimateRankRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetEstimateRankRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetEstimateRankRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_RANKING_CONTROL_GETESTIMATERANKREQUEST_HPP_