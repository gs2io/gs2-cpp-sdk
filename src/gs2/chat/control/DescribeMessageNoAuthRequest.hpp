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

#ifndef GS2_CHAT_CONTROL_DESCRIBEMESSAGENOAUTHREQUEST_HPP_
#define GS2_CHAT_CONTROL_DESCRIBEMESSAGENOAUTHREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ChatConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace chat
{

/**
 * @author Game Server Services, Inc.
 */
class DescribeMessageNoAuthRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "DescribeMessageNoAuth";

private:
    class Data : public Gs2Object
    {
    public:
        /** ロビーの名前 */
        optional<StringHolder> lobbyName;
        /** ルームID */
        optional<StringHolder> roomId;
        /** メッセージの取得を開始する日時(エポック秒) */
        optional<Int32> startAt;
        /** データの取得件数 */
        optional<Int32> limit;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lobbyName(data.lobbyName),
            roomId(data.roomId),
            startAt(data.startAt),
            limit(data.limit)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lobbyName(std::move(data.lobbyName)),
            roomId(std::move(data.roomId)),
            startAt(std::move(data.startAt)),
            limit(std::move(data.limit))
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
    DescribeMessageNoAuthRequest() :
        m_pData(nullptr)
    {}

    DescribeMessageNoAuthRequest(const DescribeMessageNoAuthRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Chat(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DescribeMessageNoAuthRequest(DescribeMessageNoAuthRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Chat(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DescribeMessageNoAuthRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DescribeMessageNoAuthRequest& operator=(const DescribeMessageNoAuthRequest& describeMessageNoAuthRequest)
    {
        Gs2BasicRequest::operator=(describeMessageNoAuthRequest);
        Gs2Chat::operator=(describeMessageNoAuthRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*describeMessageNoAuthRequest.m_pData);

        return *this;
    }

    DescribeMessageNoAuthRequest& operator=(DescribeMessageNoAuthRequest&& describeMessageNoAuthRequest)
    {
        Gs2BasicRequest::operator=(std::move(describeMessageNoAuthRequest));
        Gs2Chat::operator=(std::move(describeMessageNoAuthRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = describeMessageNoAuthRequest.m_pData;
        describeMessageNoAuthRequest.m_pData = nullptr;

        return *this;
    }

    const DescribeMessageNoAuthRequest* operator->() const
    {
        return this;
    }

    DescribeMessageNoAuthRequest* operator->()
    {
        return this;
    }

    /**
     * ロビーの名前を取得
     *
     * @return ロビーの名前
     */
    const optional<StringHolder>& getLobbyName() const
    {
        return ensureData().lobbyName;
    }

    /**
     * ロビーの名前を設定
     *
     * @param lobbyName ロビーの名前
     */
    void setLobbyName(const Char* lobbyName)
    {
        ensureData().lobbyName.emplace(lobbyName);
    }

    /**
     * ロビーの名前を設定
     *
     * @param lobbyName ロビーの名前
     */
    DescribeMessageNoAuthRequest& withLobbyName(const Char* lobbyName)
    {
        ensureData().lobbyName.emplace(lobbyName);
        return *this;
    }

    /**
     * ルームIDを取得
     *
     * @return ルームID
     */
    const optional<StringHolder>& getRoomId() const
    {
        return ensureData().roomId;
    }

    /**
     * ルームIDを設定
     *
     * @param roomId ルームID
     */
    void setRoomId(const Char* roomId)
    {
        ensureData().roomId.emplace(roomId);
    }

    /**
     * ルームIDを設定
     *
     * @param roomId ルームID
     */
    DescribeMessageNoAuthRequest& withRoomId(const Char* roomId)
    {
        ensureData().roomId.emplace(roomId);
        return *this;
    }

    /**
     * メッセージの取得を開始する日時(エポック秒)を取得
     *
     * @return メッセージの取得を開始する日時(エポック秒)
     */
    const optional<Int32>& getStartAt() const
    {
        return ensureData().startAt;
    }

    /**
     * メッセージの取得を開始する日時(エポック秒)を設定
     *
     * @param startAt メッセージの取得を開始する日時(エポック秒)
     */
    void setStartAt(Int32 startAt)
    {
        ensureData().startAt.emplace(startAt);
    }

    /**
     * メッセージの取得を開始する日時(エポック秒)を設定
     *
     * @param startAt メッセージの取得を開始する日時(エポック秒)
     */
    DescribeMessageNoAuthRequest& withStartAt(Int32 startAt)
    {
        ensureData().startAt.emplace(startAt);
        return *this;
    }

    /**
     * データの取得件数を取得
     *
     * @return データの取得件数
     */
    const optional<Int32>& getLimit() const
    {
        return ensureData().limit;
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    void setLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
    }

    /**
     * データの取得件数を設定
     *
     * @param limit データの取得件数
     */
    DescribeMessageNoAuthRequest& withLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DescribeMessageNoAuthRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DescribeMessageNoAuthRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DescribeMessageNoAuthRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DescribeMessageNoAuthRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CHAT_CONTROL_DESCRIBEMESSAGENOAUTHREQUEST_HPP_