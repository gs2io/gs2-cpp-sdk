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

#ifndef GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGBYPLAYERREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGBYPLAYERREQUEST_HPP_

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
 * Player が参加できるギャザリングを探して参加する のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DoMatchmakingByPlayerRequest : public Gs2BasicRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** プレイヤー情報 */
        optional<Player> player;
        /** 検索の再開に使用する マッチメイキングの状態を保持するトークン */
        optional<StringHolder> matchmakingContextToken;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            matchmakingContextToken(data.matchmakingContextToken)
        {
            if (data.player)
            {
                player = data.player->deepCopy();
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
    DoMatchmakingByPlayerRequest() = default;
    DoMatchmakingByPlayerRequest(const DoMatchmakingByPlayerRequest& doMatchmakingByPlayerRequest) = default;
    DoMatchmakingByPlayerRequest(DoMatchmakingByPlayerRequest&& doMatchmakingByPlayerRequest) = default;
    ~DoMatchmakingByPlayerRequest() GS2_OVERRIDE = default;

    DoMatchmakingByPlayerRequest& operator=(const DoMatchmakingByPlayerRequest& doMatchmakingByPlayerRequest) = default;
    DoMatchmakingByPlayerRequest& operator=(DoMatchmakingByPlayerRequest&& doMatchmakingByPlayerRequest) = default;

    DoMatchmakingByPlayerRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DoMatchmakingByPlayerRequest);
    }

    const DoMatchmakingByPlayerRequest* operator->() const
    {
        return this;
    }

    DoMatchmakingByPlayerRequest* operator->()
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
    DoMatchmakingByPlayerRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * プレイヤー情報を取得
     *
     * @return プレイヤー情報
     */
    const optional<Player>& getPlayer() const
    {
        return ensureData().player;
    }

    /**
     * プレイヤー情報を設定
     *
     * @param player プレイヤー情報
     */
    void setPlayer(Player player)
    {
        ensureData().player.emplace(std::move(player));
    }

    /**
     * プレイヤー情報を設定
     *
     * @param player プレイヤー情報
     */
    DoMatchmakingByPlayerRequest& withPlayer(Player player)
    {
        ensureData().player.emplace(std::move(player));
        return *this;
    }

    /**
     * 検索の再開に使用する マッチメイキングの状態を保持するトークンを取得
     *
     * @return 検索の再開に使用する マッチメイキングの状態を保持するトークン
     */
    const optional<StringHolder>& getMatchmakingContextToken() const
    {
        return ensureData().matchmakingContextToken;
    }

    /**
     * 検索の再開に使用する マッチメイキングの状態を保持するトークンを設定
     *
     * @param matchmakingContextToken 検索の再開に使用する マッチメイキングの状態を保持するトークン
     */
    void setMatchmakingContextToken(StringHolder matchmakingContextToken)
    {
        ensureData().matchmakingContextToken.emplace(std::move(matchmakingContextToken));
    }

    /**
     * 検索の再開に使用する マッチメイキングの状態を保持するトークンを設定
     *
     * @param matchmakingContextToken 検索の再開に使用する マッチメイキングの状態を保持するトークン
     */
    DoMatchmakingByPlayerRequest& withMatchmakingContextToken(StringHolder matchmakingContextToken)
    {
        ensureData().matchmakingContextToken.emplace(std::move(matchmakingContextToken));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DoMatchmakingByPlayerRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DoMatchmakingByPlayerRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGBYPLAYERREQUEST_HPP_