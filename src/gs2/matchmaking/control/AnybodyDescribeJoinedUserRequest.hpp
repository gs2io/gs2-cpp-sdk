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

#ifndef GS2_MATCHMAKING_CONTROL_ANYBODYDESCRIBEJOINEDUSERREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_ANYBODYDESCRIBEJOINEDUSERREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MatchmakingConst.hpp"

namespace gs2 { namespace matchmaking {

/**
 * @author Game Server Services, Inc.
 */
class AnybodyDescribeJoinedUserRequest : public Gs2UserRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "DescribeJoinedUser";

private:
    class Data : public Gs2Object
    {
    public:
        /** マッチメイキングの名前を指定します。 */
        optional<StringHolder> matchmakingName;
        /** ギャザリングのIDを指定します。 */
        optional<StringHolder> gatheringId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            matchmakingName(data.matchmakingName),
            gatheringId(data.gatheringId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            matchmakingName(std::move(data.matchmakingName)),
            gatheringId(std::move(data.gatheringId))
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
    AnybodyDescribeJoinedUserRequest() :
        m_pData(nullptr)
    {}

    AnybodyDescribeJoinedUserRequest(const AnybodyDescribeJoinedUserRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Matchmaking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    AnybodyDescribeJoinedUserRequest(AnybodyDescribeJoinedUserRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Matchmaking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~AnybodyDescribeJoinedUserRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    AnybodyDescribeJoinedUserRequest& operator=(const AnybodyDescribeJoinedUserRequest& anybodyDescribeJoinedUserRequest)
    {
        Gs2UserRequest::operator=(anybodyDescribeJoinedUserRequest);
        Gs2Matchmaking::operator=(anybodyDescribeJoinedUserRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*anybodyDescribeJoinedUserRequest.m_pData);

        return *this;
    }

    AnybodyDescribeJoinedUserRequest& operator=(AnybodyDescribeJoinedUserRequest&& anybodyDescribeJoinedUserRequest)
    {
        Gs2UserRequest::operator=(std::move(anybodyDescribeJoinedUserRequest));
        Gs2Matchmaking::operator=(std::move(anybodyDescribeJoinedUserRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = anybodyDescribeJoinedUserRequest.m_pData;
        anybodyDescribeJoinedUserRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * マッチメイキングの名前を指定します。を取得
     *
     * @return マッチメイキングの名前を指定します。
     */
    const optional<StringHolder>& getMatchmakingName() const
    {
        return ensureData().matchmakingName;
    }

    /**
     * マッチメイキングの名前を指定します。を設定
     *
     * @param matchmakingName マッチメイキングの名前を指定します。
     */
    void setMatchmakingName(const Char* matchmakingName)
    {
        ensureData().matchmakingName.emplace(matchmakingName);
    }

    /**
     * マッチメイキングの名前を指定します。を設定
     *
     * @param matchmakingName マッチメイキングの名前を指定します。
     */
    AnybodyDescribeJoinedUserRequest& withMatchmakingName(const Char* matchmakingName)
    {
        ensureData().matchmakingName.emplace(matchmakingName);
        return *this;
    }

    /**
     * ギャザリングのIDを指定します。を取得
     *
     * @return ギャザリングのIDを指定します。
     */
    const optional<StringHolder>& getGatheringId() const
    {
        return ensureData().gatheringId;
    }

    /**
     * ギャザリングのIDを指定します。を設定
     *
     * @param gatheringId ギャザリングのIDを指定します。
     */
    void setGatheringId(const Char* gatheringId)
    {
        ensureData().gatheringId.emplace(gatheringId);
    }

    /**
     * ギャザリングのIDを指定します。を設定
     *
     * @param gatheringId ギャザリングのIDを指定します。
     */
    AnybodyDescribeJoinedUserRequest& withGatheringId(const Char* gatheringId)
    {
        ensureData().gatheringId.emplace(gatheringId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    AnybodyDescribeJoinedUserRequest& withGs2ClientId(const Char* gs2ClientId)
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
    AnybodyDescribeJoinedUserRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    AnybodyDescribeJoinedUserRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    AnybodyDescribeJoinedUserRequest& withRequestId(const Char* gs2RequestId)
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
    AnybodyDescribeJoinedUserRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_MATCHMAKING_CONTROL_ANYBODYDESCRIBEJOINEDUSERREQUEST_HPP_