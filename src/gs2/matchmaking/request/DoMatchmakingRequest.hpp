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

#ifndef GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MatchmakingConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace matchmaking
{

/**
 * 自分が参加できるギャザリングを探して参加する のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class DoMatchmakingRequest : public Gs2BasicRequest, public Gs2Matchmaking
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
        /** 自身のプレイヤー情報 */
        optional<Player> player;
        /** 検索の再開に使用する マッチメイキングの状態を保持するトークン */
        optional<StringHolder> matchmakingContextToken;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            matchmakingContextToken(data.matchmakingContextToken),
            duplicationAvoider(data.duplicationAvoider)
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
    DoMatchmakingRequest() = default;
    DoMatchmakingRequest(const DoMatchmakingRequest& doMatchmakingRequest) = default;
    DoMatchmakingRequest(DoMatchmakingRequest&& doMatchmakingRequest) = default;
    ~DoMatchmakingRequest() GS2_OVERRIDE = default;

    DoMatchmakingRequest& operator=(const DoMatchmakingRequest& doMatchmakingRequest) = default;
    DoMatchmakingRequest& operator=(DoMatchmakingRequest&& doMatchmakingRequest) = default;

    DoMatchmakingRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DoMatchmakingRequest);
    }

    const DoMatchmakingRequest* operator->() const
    {
        return this;
    }

    DoMatchmakingRequest* operator->()
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
    DoMatchmakingRequest& withAccessToken(StringHolder accessToken)
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
    DoMatchmakingRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 自身のプレイヤー情報を取得
     *
     * @return 自身のプレイヤー情報
     */
    const optional<Player>& getPlayer() const
    {
        return ensureData().player;
    }

    /**
     * 自身のプレイヤー情報を設定
     *
     * @param player 自身のプレイヤー情報
     */
    void setPlayer(Player player)
    {
        ensureData().player.emplace(std::move(player));
    }

    /**
     * 自身のプレイヤー情報を設定
     *
     * @param player 自身のプレイヤー情報
     */
    DoMatchmakingRequest& withPlayer(Player player)
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
    DoMatchmakingRequest& withMatchmakingContextToken(StringHolder matchmakingContextToken)
    {
        ensureData().matchmakingContextToken.emplace(std::move(matchmakingContextToken));
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
    DoMatchmakingRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    DoMatchmakingRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DoMatchmakingRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGREQUEST_HPP_