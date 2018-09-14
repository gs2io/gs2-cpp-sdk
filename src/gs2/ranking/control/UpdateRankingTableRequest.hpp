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

#ifndef GS2_RANKING_CONTROL_UPDATERANKINGTABLEREQUEST_HPP_
#define GS2_RANKING_CONTROL_UPDATERANKINGTABLEREQUEST_HPP_

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
class UpdateRankingTableRequest : public Gs2BasicRequest, public Gs2Ranking
{
public:
    constexpr static const Char* const FUNCTION = "UpdateRankingTable";

private:
    class Data : public Gs2Object
    {
    public:
        /** ランキングテーブルの名前を指定します。 */
        optional<StringHolder> rankingTableName;
        /** 説明文 */
        optional<StringHolder> description;
        /** スコア登録時 */
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
            description(data.description),
            putScoreTriggerScript(data.putScoreTriggerScript),
            putScoreDoneTriggerScript(data.putScoreDoneTriggerScript),
            calculateRankingDoneTriggerScript(data.calculateRankingDoneTriggerScript)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            rankingTableName(std::move(data.rankingTableName)),
            description(std::move(data.description)),
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
    UpdateRankingTableRequest() :
        m_pData(nullptr)
    {}

    UpdateRankingTableRequest(const UpdateRankingTableRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Ranking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateRankingTableRequest(UpdateRankingTableRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Ranking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateRankingTableRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateRankingTableRequest& operator=(const UpdateRankingTableRequest& updateRankingTableRequest)
    {
        Gs2BasicRequest::operator=(updateRankingTableRequest);
        Gs2Ranking::operator=(updateRankingTableRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateRankingTableRequest.m_pData);

        return *this;
    }

    UpdateRankingTableRequest& operator=(UpdateRankingTableRequest&& updateRankingTableRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateRankingTableRequest));
        Gs2Ranking::operator=(std::move(updateRankingTableRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateRankingTableRequest.m_pData;
        updateRankingTableRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateRankingTableRequest* operator->() const
    {
        return this;
    }

    UpdateRankingTableRequest* operator->()
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
    UpdateRankingTableRequest& withRankingTableName(const Char* rankingTableName)
    {
        ensureData().rankingTableName.emplace(rankingTableName);
        return *this;
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateRankingTableRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * スコア登録時を取得
     *
     * @return スコア登録時
     */
    const optional<StringHolder>& getPutScoreTriggerScript() const
    {
        return ensureData().putScoreTriggerScript;
    }

    /**
     * スコア登録時を設定
     *
     * @param putScoreTriggerScript スコア登録時
     */
    void setPutScoreTriggerScript(const Char* putScoreTriggerScript)
    {
        ensureData().putScoreTriggerScript.emplace(putScoreTriggerScript);
    }

    /**
     * スコア登録時を設定
     *
     * @param putScoreTriggerScript スコア登録時
     */
    UpdateRankingTableRequest& withPutScoreTriggerScript(const Char* putScoreTriggerScript)
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
    UpdateRankingTableRequest& withPutScoreDoneTriggerScript(const Char* putScoreDoneTriggerScript)
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
    UpdateRankingTableRequest& withCalculateRankingDoneTriggerScript(const Char* calculateRankingDoneTriggerScript)
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
    UpdateRankingTableRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateRankingTableRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateRankingTableRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateRankingTableRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_RANKING_CONTROL_UPDATERANKINGTABLEREQUEST_HPP_