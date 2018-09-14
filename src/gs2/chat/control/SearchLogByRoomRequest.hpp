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

#ifndef GS2_CHAT_CONTROL_SEARCHLOGBYROOMREQUEST_HPP_
#define GS2_CHAT_CONTROL_SEARCHLOGBYROOMREQUEST_HPP_

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
class SearchLogByRoomRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "SearchLogByRoom";

private:
    class Data : public Gs2Object
    {
    public:
        /** ロビーの名前 */
        optional<StringHolder> lobbyName;
        /** ルームID */
        optional<StringHolder> roomId;
        /** 検索するユーザID文字列(部分一致) */
        optional<StringHolder> userId;
        /** 検索するメッセージテキスト文字列(部分一致) */
        optional<StringHolder> message;
        /** 検索するメッセージメタデータ文字列(部分一致) */
        optional<StringHolder> meta;
        /** 検索期間 開始日時（エポック秒） */
        optional<Int32> begin;
        /** 検索期間 終了日時（エポック秒） */
        optional<Int32> end;
        /** データの取得を開始する位置を指定するトークン */
        optional<StringHolder> pageToken;
        /** データの取得件数 */
        optional<Int32> limit;
        /** クエリキャッシュを有効にするか */
        optional<Bool> useCache;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            lobbyName(data.lobbyName),
            roomId(data.roomId),
            userId(data.userId),
            message(data.message),
            meta(data.meta),
            begin(data.begin),
            end(data.end),
            pageToken(data.pageToken),
            limit(data.limit),
            useCache(data.useCache)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            lobbyName(std::move(data.lobbyName)),
            roomId(std::move(data.roomId)),
            userId(std::move(data.userId)),
            message(std::move(data.message)),
            meta(std::move(data.meta)),
            begin(std::move(data.begin)),
            end(std::move(data.end)),
            pageToken(std::move(data.pageToken)),
            limit(std::move(data.limit)),
            useCache(std::move(data.useCache))
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
    SearchLogByRoomRequest() :
        m_pData(nullptr)
    {}

    SearchLogByRoomRequest(const SearchLogByRoomRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Chat(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    SearchLogByRoomRequest(SearchLogByRoomRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Chat(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~SearchLogByRoomRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    SearchLogByRoomRequest& operator=(const SearchLogByRoomRequest& searchLogByRoomRequest)
    {
        Gs2BasicRequest::operator=(searchLogByRoomRequest);
        Gs2Chat::operator=(searchLogByRoomRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*searchLogByRoomRequest.m_pData);

        return *this;
    }

    SearchLogByRoomRequest& operator=(SearchLogByRoomRequest&& searchLogByRoomRequest)
    {
        Gs2BasicRequest::operator=(std::move(searchLogByRoomRequest));
        Gs2Chat::operator=(std::move(searchLogByRoomRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = searchLogByRoomRequest.m_pData;
        searchLogByRoomRequest.m_pData = nullptr;

        return *this;
    }

    const SearchLogByRoomRequest* operator->() const
    {
        return this;
    }

    SearchLogByRoomRequest* operator->()
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
    SearchLogByRoomRequest& withLobbyName(const Char* lobbyName)
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
    SearchLogByRoomRequest& withRoomId(const Char* roomId)
    {
        ensureData().roomId.emplace(roomId);
        return *this;
    }

    /**
     * 検索するユーザID文字列(部分一致)を取得
     *
     * @return 検索するユーザID文字列(部分一致)
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * 検索するユーザID文字列(部分一致)を設定
     *
     * @param userId 検索するユーザID文字列(部分一致)
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * 検索するユーザID文字列(部分一致)を設定
     *
     * @param userId 検索するユーザID文字列(部分一致)
     */
    SearchLogByRoomRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * 検索するメッセージテキスト文字列(部分一致)を取得
     *
     * @return 検索するメッセージテキスト文字列(部分一致)
     */
    const optional<StringHolder>& getMessage() const
    {
        return ensureData().message;
    }

    /**
     * 検索するメッセージテキスト文字列(部分一致)を設定
     *
     * @param message 検索するメッセージテキスト文字列(部分一致)
     */
    void setMessage(const Char* message)
    {
        ensureData().message.emplace(message);
    }

    /**
     * 検索するメッセージテキスト文字列(部分一致)を設定
     *
     * @param message 検索するメッセージテキスト文字列(部分一致)
     */
    SearchLogByRoomRequest& withMessage(const Char* message)
    {
        ensureData().message.emplace(message);
        return *this;
    }

    /**
     * 検索するメッセージメタデータ文字列(部分一致)を取得
     *
     * @return 検索するメッセージメタデータ文字列(部分一致)
     */
    const optional<StringHolder>& getMeta() const
    {
        return ensureData().meta;
    }

    /**
     * 検索するメッセージメタデータ文字列(部分一致)を設定
     *
     * @param meta 検索するメッセージメタデータ文字列(部分一致)
     */
    void setMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
    }

    /**
     * 検索するメッセージメタデータ文字列(部分一致)を設定
     *
     * @param meta 検索するメッセージメタデータ文字列(部分一致)
     */
    SearchLogByRoomRequest& withMeta(const Char* meta)
    {
        ensureData().meta.emplace(meta);
        return *this;
    }

    /**
     * 検索期間 開始日時（エポック秒）を取得
     *
     * @return 検索期間 開始日時（エポック秒）
     */
    const optional<Int32>& getBegin() const
    {
        return ensureData().begin;
    }

    /**
     * 検索期間 開始日時（エポック秒）を設定
     *
     * @param begin 検索期間 開始日時（エポック秒）
     */
    void setBegin(Int32 begin)
    {
        ensureData().begin.emplace(begin);
    }

    /**
     * 検索期間 開始日時（エポック秒）を設定
     *
     * @param begin 検索期間 開始日時（エポック秒）
     */
    SearchLogByRoomRequest& withBegin(Int32 begin)
    {
        ensureData().begin.emplace(begin);
        return *this;
    }

    /**
     * 検索期間 終了日時（エポック秒）を取得
     *
     * @return 検索期間 終了日時（エポック秒）
     */
    const optional<Int32>& getEnd() const
    {
        return ensureData().end;
    }

    /**
     * 検索期間 終了日時（エポック秒）を設定
     *
     * @param end 検索期間 終了日時（エポック秒）
     */
    void setEnd(Int32 end)
    {
        ensureData().end.emplace(end);
    }

    /**
     * 検索期間 終了日時（エポック秒）を設定
     *
     * @param end 検索期間 終了日時（エポック秒）
     */
    SearchLogByRoomRequest& withEnd(Int32 end)
    {
        ensureData().end.emplace(end);
        return *this;
    }

    /**
     * データの取得を開始する位置を指定するトークンを取得
     *
     * @return データの取得を開始する位置を指定するトークン
     */
    const optional<StringHolder>& getPageToken() const
    {
        return ensureData().pageToken;
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    void setPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
    }

    /**
     * データの取得を開始する位置を指定するトークンを設定
     *
     * @param pageToken データの取得を開始する位置を指定するトークン
     */
    SearchLogByRoomRequest& withPageToken(const Char* pageToken)
    {
        ensureData().pageToken.emplace(pageToken);
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
    SearchLogByRoomRequest& withLimit(Int32 limit)
    {
        ensureData().limit.emplace(limit);
        return *this;
    }

    /**
     * クエリキャッシュを有効にするかを取得
     *
     * @return クエリキャッシュを有効にするか
     */
    const optional<Bool>& getUseCache() const
    {
        return ensureData().useCache;
    }

    /**
     * クエリキャッシュを有効にするかを設定
     *
     * @param useCache クエリキャッシュを有効にするか
     */
    void setUseCache(Bool useCache)
    {
        ensureData().useCache.emplace(useCache);
    }

    /**
     * クエリキャッシュを有効にするかを設定
     *
     * @param useCache クエリキャッシュを有効にするか
     */
    SearchLogByRoomRequest& withUseCache(Bool useCache)
    {
        ensureData().useCache.emplace(useCache);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    SearchLogByRoomRequest& withGs2ClientId(const Char* gs2ClientId)
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
    SearchLogByRoomRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    SearchLogByRoomRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    SearchLogByRoomRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_CHAT_CONTROL_SEARCHLOGBYROOMREQUEST_HPP_