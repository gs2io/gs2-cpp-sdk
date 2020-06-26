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

#ifndef GS2_MATCHMAKING_CONTROL_PUTRESULTREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_PUTRESULTREQUEST_HPP_

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
 * レーティング値の再計算を実行 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class PutResultRequest : public Gs2BasicRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** レーティング名 */
        optional<StringHolder> ratingName;
        /** 対戦結果 */
        optional<List<GameResult>> gameResults;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            ratingName(data.ratingName)
        {
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
    PutResultRequest() = default;
    PutResultRequest(const PutResultRequest& putResultRequest) = default;
    PutResultRequest(PutResultRequest&& putResultRequest) = default;
    ~PutResultRequest() GS2_OVERRIDE = default;

    PutResultRequest& operator=(const PutResultRequest& putResultRequest) = default;
    PutResultRequest& operator=(PutResultRequest&& putResultRequest) = default;

    PutResultRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(PutResultRequest);
    }

    const PutResultRequest* operator->() const
    {
        return this;
    }

    PutResultRequest* operator->()
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
    PutResultRequest& withNamespaceName(StringHolder namespaceName)
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
    PutResultRequest& withRatingName(StringHolder ratingName)
    {
        ensureData().ratingName.emplace(std::move(ratingName));
        return *this;
    }

    /**
     * 対戦結果を取得
     *
     * @return 対戦結果
     */
    const optional<List<GameResult>>& getGameResults() const
    {
        return ensureData().gameResults;
    }

    /**
     * 対戦結果を設定
     *
     * @param gameResults 対戦結果
     */
    void setGameResults(List<GameResult> gameResults)
    {
        ensureData().gameResults.emplace(std::move(gameResults));
    }

    /**
     * 対戦結果を設定
     *
     * @param gameResults 対戦結果
     */
    PutResultRequest& withGameResults(List<GameResult> gameResults)
    {
        ensureData().gameResults.emplace(std::move(gameResults));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    PutResultRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    PutResultRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_PUTRESULTREQUEST_HPP_