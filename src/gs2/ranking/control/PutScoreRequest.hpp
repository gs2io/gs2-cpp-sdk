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

#ifndef GS2_RANKING_CONTROL_PUTSCOREREQUEST_HPP_
#define GS2_RANKING_CONTROL_PUTSCOREREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2RankingConst.hpp"

namespace gs2 { namespace ranking {

/**
 * @author Game Server Services, Inc.
 */
class PutScoreRequest : public Gs2UserRequest, public Gs2Ranking
{
public:
    constexpr static const Char* const FUNCTION = "PutScore";

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
        /** スコアに付随するメタ情報 */
        optional<StringHolder> meta;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            rankingTableName(data.rankingTableName),
            gameMode(data.gameMode),
            score(data.score),
            meta(data.meta)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            rankingTableName(std::move(data.rankingTableName)),
            gameMode(std::move(data.gameMode)),
            score(std::move(data.score)),
            meta(std::move(data.meta))
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
    PutScoreRequest() :
        m_pData(nullptr)
    {}

    PutScoreRequest(const PutScoreRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Ranking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    PutScoreRequest(PutScoreRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Ranking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~PutScoreRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    PutScoreRequest& operator=(const PutScoreRequest& putScoreRequest)
    {
        Gs2UserRequest::operator=(putScoreRequest);
        Gs2Ranking::operator=(putScoreRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*putScoreRequest.m_pData);

        return *this;
    }

    PutScoreRequest& operator=(PutScoreRequest&& putScoreRequest)
    {
        Gs2UserRequest::operator=(std::move(putScoreRequest));
        Gs2Ranking::operator=(std::move(putScoreRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = putScoreRequest.m_pData;
        putScoreRequest.m_pData = nullptr;

        return *this;
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
    PutScoreRequest& withRankingTableName(const Char* rankingTableName)
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
    PutScoreRequest& withGameMode(const Char* gameMode)
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
    PutScoreRequest& withScore(Int64 score)
    {
        ensureData().score.emplace(score);
        return *this;
    }

    /**
     * スコアに付随するメタ情報を取得
     *
     * @return スコアに付随するメタ情報
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * スコアに付随するメタ情報を設定
     *
     * @param meta スコアに付随するメタ情報
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * スコアに付随するメタ情報を設定
     *
     * @param meta スコアに付随するメタ情報
     */
    PutScoreRequest& withMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    PutScoreRequest& withGs2ClientId(const Char* gs2ClientId)
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
    PutScoreRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    PutScoreRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    PutScoreRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    PutScoreRequest& withAccessToken(const Char* accessToken) {
        setAccessToken(accessToken);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_RANKING_CONTROL_PUTSCOREREQUEST_HPP_