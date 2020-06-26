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

#ifndef GS2_MATCHMAKING_CONTROL_VOTEMULTIPLEREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_VOTEMULTIPLEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/matchmaking/Gs2MatchmakingConst.hpp>
#include <gs2/matchmaking/model/model.hpp>
#include <memory>

namespace gs2 { namespace matchmaking
{

/**
 * 対戦結果をまとめて投票します。 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class VoteMultipleRequest : public Gs2BasicRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 署名付の投票用紙リスト */
        optional<List<SignedBallot>> signedBallots;
        /** 投票内容。対戦を行ったプレイヤーグループ1に所属するユーザIDのリスト */
        optional<List<GameResult>> gameResults;
        /** 投票用紙の署名検証に使用する暗号鍵 のGRN */
        optional<StringHolder> keyId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            keyId(data.keyId)
        {
            if (data.signedBallots)
            {
                signedBallots = data.signedBallots->deepCopy();
            }
            if (data.gameResults)
            {
                gameResults = data.gameResults->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    VoteMultipleRequest() = default;
    VoteMultipleRequest(const VoteMultipleRequest& voteMultipleRequest) = default;
    VoteMultipleRequest(VoteMultipleRequest&& voteMultipleRequest) = default;
    ~VoteMultipleRequest() GS2_OVERRIDE = default;

    VoteMultipleRequest& operator=(const VoteMultipleRequest& voteMultipleRequest) = default;
    VoteMultipleRequest& operator=(VoteMultipleRequest&& voteMultipleRequest) = default;

    VoteMultipleRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(VoteMultipleRequest);
    }

    const VoteMultipleRequest* operator->() const
    {
        return this;
    }

    VoteMultipleRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    VoteMultipleRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 署名付の投票用紙リストを取得
     *
     * @return 署名付の投票用紙リスト
     */
    const optional<List<SignedBallot>>& getSignedBallots() const
    {
        return ensureData().signedBallots;
    }

    /**
     * 署名付の投票用紙リストを設定
     *
     * @param signedBallots 署名付の投票用紙リスト
     */
    void setSignedBallots(List<SignedBallot> signedBallots)
    {
        ensureData().signedBallots.emplace(std::move(signedBallots));
    }

    /**
     * 署名付の投票用紙リストを設定
     *
     * @param signedBallots 署名付の投票用紙リスト
     */
    VoteMultipleRequest& withSignedBallots(List<SignedBallot> signedBallots)
    {
        ensureData().signedBallots.emplace(std::move(signedBallots));
        return *this;
    }

    /**
     * 投票内容。対戦を行ったプレイヤーグループ1に所属するユーザIDのリストを取得
     *
     * @return 投票内容。対戦を行ったプレイヤーグループ1に所属するユーザIDのリスト
     */
    const optional<List<GameResult>>& getGameResults() const
    {
        return ensureData().gameResults;
    }

    /**
     * 投票内容。対戦を行ったプレイヤーグループ1に所属するユーザIDのリストを設定
     *
     * @param gameResults 投票内容。対戦を行ったプレイヤーグループ1に所属するユーザIDのリスト
     */
    void setGameResults(List<GameResult> gameResults)
    {
        ensureData().gameResults.emplace(std::move(gameResults));
    }

    /**
     * 投票内容。対戦を行ったプレイヤーグループ1に所属するユーザIDのリストを設定
     *
     * @param gameResults 投票内容。対戦を行ったプレイヤーグループ1に所属するユーザIDのリスト
     */
    VoteMultipleRequest& withGameResults(List<GameResult> gameResults)
    {
        ensureData().gameResults.emplace(std::move(gameResults));
        return *this;
    }

    /**
     * 投票用紙の署名検証に使用する暗号鍵 のGRNを取得
     *
     * @return 投票用紙の署名検証に使用する暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 投票用紙の署名検証に使用する暗号鍵 のGRNを設定
     *
     * @param keyId 投票用紙の署名検証に使用する暗号鍵 のGRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 投票用紙の署名検証に使用する暗号鍵 のGRNを設定
     *
     * @param keyId 投票用紙の署名検証に使用する暗号鍵 のGRN
     */
    VoteMultipleRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    VoteMultipleRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    VoteMultipleRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_VOTEMULTIPLEREQUEST_HPP_