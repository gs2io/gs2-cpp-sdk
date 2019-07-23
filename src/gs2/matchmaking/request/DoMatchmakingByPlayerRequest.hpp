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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MatchmakingConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** プレイヤー情報 */
        optional<Player> player;
        /** 検索の再開に使用する マッチメイキングの状態を保持するトークン */
        optional<StringHolder> matchmakingContextToken;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            player(data.player),
            matchmakingContextToken(data.matchmakingContextToken)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            player(std::move(data.player)),
            matchmakingContextToken(std::move(data.matchmakingContextToken))
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
    DoMatchmakingByPlayerRequest() :
        m_pData(nullptr)
    {}

    DoMatchmakingByPlayerRequest(const DoMatchmakingByPlayerRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Matchmaking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DoMatchmakingByPlayerRequest(DoMatchmakingByPlayerRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Matchmaking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DoMatchmakingByPlayerRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DoMatchmakingByPlayerRequest& operator=(const DoMatchmakingByPlayerRequest& doMatchmakingByPlayerRequest)
    {
        Gs2BasicRequest::operator=(doMatchmakingByPlayerRequest);
        Gs2Matchmaking::operator=(doMatchmakingByPlayerRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*doMatchmakingByPlayerRequest.m_pData);

        return *this;
    }

    DoMatchmakingByPlayerRequest& operator=(DoMatchmakingByPlayerRequest&& doMatchmakingByPlayerRequest)
    {
        Gs2BasicRequest::operator=(std::move(doMatchmakingByPlayerRequest));
        Gs2Matchmaking::operator=(std::move(doMatchmakingByPlayerRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = doMatchmakingByPlayerRequest.m_pData;
        doMatchmakingByPlayerRequest.m_pData = nullptr;

        return *this;
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    DoMatchmakingByPlayerRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setPlayer(const Player& player)
    {
        ensureData().player.emplace(player);
    }

    /**
     * プレイヤー情報を設定
     *
     * @param player プレイヤー情報
     */
    DoMatchmakingByPlayerRequest& withPlayer(const Player& player)
    {
        ensureData().player.emplace(player);
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
    void setMatchmakingContextToken(const Char* matchmakingContextToken)
    {
        ensureData().matchmakingContextToken.emplace(matchmakingContextToken);
    }

    /**
     * 検索の再開に使用する マッチメイキングの状態を保持するトークンを設定
     *
     * @param matchmakingContextToken 検索の再開に使用する マッチメイキングの状態を保持するトークン
     */
    DoMatchmakingByPlayerRequest& withMatchmakingContextToken(const Char* matchmakingContextToken)
    {
        ensureData().matchmakingContextToken.emplace(matchmakingContextToken);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DoMatchmakingByPlayerRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DoMatchmakingByPlayerRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DoMatchmakingByPlayerRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DoMatchmakingByPlayerRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MATCHMAKING_CONTROL_DOMATCHMAKINGBYPLAYERREQUEST_HPP_