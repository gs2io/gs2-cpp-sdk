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

#ifndef GS2_MATCHMAKING_CONTROL_GETBALLOTREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_GETBALLOTREQUEST_HPP_

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
 * 投票用紙を取得します。 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class GetBallotRequest : public Gs2BasicRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** レーティング名 */
        optional<StringHolder> ratingName;
        /** レーティング名 */
        optional<StringHolder> gatheringName;
        /** 投票対象となる */
        optional<StringHolder> gatheringId;
        /** 参加人数 */
        optional<Int32> numberOfPlayer;
        /** 投票用紙の署名計算に使用する暗号鍵 のGRN */
        optional<StringHolder> keyId;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            ratingName(data.ratingName),
            gatheringName(data.gatheringName),
            gatheringId(data.gatheringId),
            numberOfPlayer(data.numberOfPlayer),
            keyId(data.keyId),
            duplicationAvoider(data.duplicationAvoider)
        {
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
    GetBallotRequest() = default;
    GetBallotRequest(const GetBallotRequest& getBallotRequest) = default;
    GetBallotRequest(GetBallotRequest&& getBallotRequest) = default;
    ~GetBallotRequest() GS2_OVERRIDE = default;

    GetBallotRequest& operator=(const GetBallotRequest& getBallotRequest) = default;
    GetBallotRequest& operator=(GetBallotRequest&& getBallotRequest) = default;

    GetBallotRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetBallotRequest);
    }

    const GetBallotRequest* operator->() const
    {
        return this;
    }

    GetBallotRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    GetBallotRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
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
    GetBallotRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * レーティング名を取得
     *
     * @return レーティング名
     */
    const optional<StringHolder>& getRatingName() const
    {
        return ensureData().ratingName;
    }

    /**
     * レーティング名を設定
     *
     * @param ratingName レーティング名
     */
    void setRatingName(StringHolder ratingName)
    {
        ensureData().ratingName.emplace(std::move(ratingName));
    }

    /**
     * レーティング名を設定
     *
     * @param ratingName レーティング名
     */
    GetBallotRequest& withRatingName(StringHolder ratingName)
    {
        ensureData().ratingName.emplace(std::move(ratingName));
        return *this;
    }

    /**
     * レーティング名を取得
     *
     * @return レーティング名
     */
    const optional<StringHolder>& getGatheringName() const
    {
        return ensureData().gatheringName;
    }

    /**
     * レーティング名を設定
     *
     * @param gatheringName レーティング名
     */
    void setGatheringName(StringHolder gatheringName)
    {
        ensureData().gatheringName.emplace(std::move(gatheringName));
    }

    /**
     * レーティング名を設定
     *
     * @param gatheringName レーティング名
     */
    GetBallotRequest& withGatheringName(StringHolder gatheringName)
    {
        ensureData().gatheringName.emplace(std::move(gatheringName));
        return *this;
    }

    /**
     * 投票対象となるを取得
     *
     * @return 投票対象となる
     */
    const optional<StringHolder>& getGatheringId() const
    {
        return ensureData().gatheringId;
    }

    /**
     * 投票対象となるを設定
     *
     * @param gatheringId 投票対象となる
     */
    void setGatheringId(StringHolder gatheringId)
    {
        ensureData().gatheringId.emplace(std::move(gatheringId));
    }

    /**
     * 投票対象となるを設定
     *
     * @param gatheringId 投票対象となる
     */
    GetBallotRequest& withGatheringId(StringHolder gatheringId)
    {
        ensureData().gatheringId.emplace(std::move(gatheringId));
        return *this;
    }

    /**
     * 参加人数を取得
     *
     * @return 参加人数
     */
    const optional<Int32>& getNumberOfPlayer() const
    {
        return ensureData().numberOfPlayer;
    }

    /**
     * 参加人数を設定
     *
     * @param numberOfPlayer 参加人数
     */
    void setNumberOfPlayer(Int32 numberOfPlayer)
    {
        ensureData().numberOfPlayer.emplace(numberOfPlayer);
    }

    /**
     * 参加人数を設定
     *
     * @param numberOfPlayer 参加人数
     */
    GetBallotRequest& withNumberOfPlayer(Int32 numberOfPlayer)
    {
        ensureData().numberOfPlayer.emplace(numberOfPlayer);
        return *this;
    }

    /**
     * 投票用紙の署名計算に使用する暗号鍵 のGRNを取得
     *
     * @return 投票用紙の署名計算に使用する暗号鍵 のGRN
     */
    const optional<StringHolder>& getKeyId() const
    {
        return ensureData().keyId;
    }

    /**
     * 投票用紙の署名計算に使用する暗号鍵 のGRNを設定
     *
     * @param keyId 投票用紙の署名計算に使用する暗号鍵 のGRN
     */
    void setKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
    }

    /**
     * 投票用紙の署名計算に使用する暗号鍵 のGRNを設定
     *
     * @param keyId 投票用紙の署名計算に使用する暗号鍵 のGRN
     */
    GetBallotRequest& withKeyId(StringHolder keyId)
    {
        ensureData().keyId.emplace(std::move(keyId));
        return *this;
    }

    /**
     * 重複実行回避機能に使用するIDを取得
     *
     * @return 重複実行回避機能に使用するID
     */
    const optional<StringHolder>& getDuplicationAvoider() const
    {
        return ensureData().duplicationAvoider;
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    void setDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    GetBallotRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(std::move(duplicationAvoider));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetBallotRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetBallotRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_GETBALLOTREQUEST_HPP_