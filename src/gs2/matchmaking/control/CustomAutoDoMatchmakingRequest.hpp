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

#ifndef GS2_MATCHMAKING_CONTROL_CUSTOMAUTODOMATCHMAKINGREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_CUSTOMAUTODOMATCHMAKINGREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MatchmakingConst.hpp"

namespace gs2 { namespace matchmaking {

/**
 * @author Game Server Services, Inc.
 */
class CustomAutoDoMatchmakingRequest : public Gs2UserRequest, public Gs2Matchmaking
{
public:
    constexpr static const Char* const FUNCTION = "DoMatchmaking";

private:
    class Data : public Gs2Object
    {
    public:
        /** マッチメイキングの名前を指定します。 */
        optional<StringHolder> matchmakingName;
        /** ギャザリングを新規作成する場合の属性値1 */
        optional<Int32> attribute1;
        /** ギャザリングを新規作成する場合の属性値2 */
        optional<Int32> attribute2;
        /** ギャザリングを新規作成する場合の属性値3 */
        optional<Int32> attribute3;
        /** ギャザリングを新規作成する場合の属性値4 */
        optional<Int32> attribute4;
        /** ギャザリングを新規作成する場合の属性値5 */
        optional<Int32> attribute5;
        /** 既存のギャザリングに参加する対象とする属性値1の最小値 */
        optional<Int32> searchAttribute1Min;
        /** 既存のギャザリングに参加する対象とする属性値2の最小値 */
        optional<Int32> searchAttribute2Min;
        /** 既存のギャザリングに参加する対象とする属性値3の最小値 */
        optional<Int32> searchAttribute3Min;
        /** 既存のギャザリングに参加する対象とする属性値4の最小値 */
        optional<Int32> searchAttribute4Min;
        /** 既存のギャザリングに参加する対象とする属性値5の最小値 */
        optional<Int32> searchAttribute5Min;
        /** 既存のギャザリングに参加する対象とする属性値1の最大値 */
        optional<Int32> searchAttribute1Max;
        /** 既存のギャザリングに参加する対象とする属性値2の最大値 */
        optional<Int32> searchAttribute2Max;
        /** 既存のギャザリングに参加する対象とする属性値3の最大値 */
        optional<Int32> searchAttribute3Max;
        /** 既存のギャザリングに参加する対象とする属性値4の最大値 */
        optional<Int32> searchAttribute4Max;
        /** 既存のギャザリングに参加する対象とする属性値5の最大値 */
        optional<Int32> searchAttribute5Max;
        /** 中断された検索を再開するためのコンテキスト */
        optional<StringHolder> searchContext;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            matchmakingName(data.matchmakingName),
            attribute1(data.attribute1),
            attribute2(data.attribute2),
            attribute3(data.attribute3),
            attribute4(data.attribute4),
            attribute5(data.attribute5),
            searchAttribute1Min(data.searchAttribute1Min),
            searchAttribute2Min(data.searchAttribute2Min),
            searchAttribute3Min(data.searchAttribute3Min),
            searchAttribute4Min(data.searchAttribute4Min),
            searchAttribute5Min(data.searchAttribute5Min),
            searchAttribute1Max(data.searchAttribute1Max),
            searchAttribute2Max(data.searchAttribute2Max),
            searchAttribute3Max(data.searchAttribute3Max),
            searchAttribute4Max(data.searchAttribute4Max),
            searchAttribute5Max(data.searchAttribute5Max),
            searchContext(data.searchContext)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            matchmakingName(std::move(data.matchmakingName)),
            attribute1(std::move(data.attribute1)),
            attribute2(std::move(data.attribute2)),
            attribute3(std::move(data.attribute3)),
            attribute4(std::move(data.attribute4)),
            attribute5(std::move(data.attribute5)),
            searchAttribute1Min(std::move(data.searchAttribute1Min)),
            searchAttribute2Min(std::move(data.searchAttribute2Min)),
            searchAttribute3Min(std::move(data.searchAttribute3Min)),
            searchAttribute4Min(std::move(data.searchAttribute4Min)),
            searchAttribute5Min(std::move(data.searchAttribute5Min)),
            searchAttribute1Max(std::move(data.searchAttribute1Max)),
            searchAttribute2Max(std::move(data.searchAttribute2Max)),
            searchAttribute3Max(std::move(data.searchAttribute3Max)),
            searchAttribute4Max(std::move(data.searchAttribute4Max)),
            searchAttribute5Max(std::move(data.searchAttribute5Max)),
            searchContext(std::move(data.searchContext))
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
    CustomAutoDoMatchmakingRequest() :
        m_pData(nullptr)
    {}

    CustomAutoDoMatchmakingRequest(const CustomAutoDoMatchmakingRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Matchmaking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CustomAutoDoMatchmakingRequest(CustomAutoDoMatchmakingRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Matchmaking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CustomAutoDoMatchmakingRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CustomAutoDoMatchmakingRequest& operator=(const CustomAutoDoMatchmakingRequest& customAutoDoMatchmakingRequest)
    {
        Gs2UserRequest::operator=(customAutoDoMatchmakingRequest);
        Gs2Matchmaking::operator=(customAutoDoMatchmakingRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*customAutoDoMatchmakingRequest.m_pData);

        return *this;
    }

    CustomAutoDoMatchmakingRequest& operator=(CustomAutoDoMatchmakingRequest&& customAutoDoMatchmakingRequest)
    {
        Gs2UserRequest::operator=(std::move(customAutoDoMatchmakingRequest));
        Gs2Matchmaking::operator=(std::move(customAutoDoMatchmakingRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = customAutoDoMatchmakingRequest.m_pData;
        customAutoDoMatchmakingRequest.m_pData = nullptr;

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
    CustomAutoDoMatchmakingRequest& withMatchmakingName(const Char* matchmakingName)
    {
        ensureData().matchmakingName.emplace(matchmakingName);
        return *this;
    }

    /**
     * ギャザリングを新規作成する場合の属性値1を取得
     *
     * @return ギャザリングを新規作成する場合の属性値1
     */
    const optional<Int32>& getAttribute1() const
    {
        return ensureData().attribute1;
    }

    /**
     * ギャザリングを新規作成する場合の属性値1を設定
     *
     * @param attribute1 ギャザリングを新規作成する場合の属性値1
     */
    void setAttribute1(Int32 attribute1)
    {
        ensureData().attribute1.emplace(attribute1);
    }

    /**
     * ギャザリングを新規作成する場合の属性値1を設定
     *
     * @param attribute1 ギャザリングを新規作成する場合の属性値1
     */
    CustomAutoDoMatchmakingRequest& withAttribute1(Int32 attribute1)
    {
        ensureData().attribute1.emplace(attribute1);
        return *this;
    }

    /**
     * ギャザリングを新規作成する場合の属性値2を取得
     *
     * @return ギャザリングを新規作成する場合の属性値2
     */
    const optional<Int32>& getAttribute2() const
    {
        return ensureData().attribute2;
    }

    /**
     * ギャザリングを新規作成する場合の属性値2を設定
     *
     * @param attribute2 ギャザリングを新規作成する場合の属性値2
     */
    void setAttribute2(Int32 attribute2)
    {
        ensureData().attribute2.emplace(attribute2);
    }

    /**
     * ギャザリングを新規作成する場合の属性値2を設定
     *
     * @param attribute2 ギャザリングを新規作成する場合の属性値2
     */
    CustomAutoDoMatchmakingRequest& withAttribute2(Int32 attribute2)
    {
        ensureData().attribute2.emplace(attribute2);
        return *this;
    }

    /**
     * ギャザリングを新規作成する場合の属性値3を取得
     *
     * @return ギャザリングを新規作成する場合の属性値3
     */
    const optional<Int32>& getAttribute3() const
    {
        return ensureData().attribute3;
    }

    /**
     * ギャザリングを新規作成する場合の属性値3を設定
     *
     * @param attribute3 ギャザリングを新規作成する場合の属性値3
     */
    void setAttribute3(Int32 attribute3)
    {
        ensureData().attribute3.emplace(attribute3);
    }

    /**
     * ギャザリングを新規作成する場合の属性値3を設定
     *
     * @param attribute3 ギャザリングを新規作成する場合の属性値3
     */
    CustomAutoDoMatchmakingRequest& withAttribute3(Int32 attribute3)
    {
        ensureData().attribute3.emplace(attribute3);
        return *this;
    }

    /**
     * ギャザリングを新規作成する場合の属性値4を取得
     *
     * @return ギャザリングを新規作成する場合の属性値4
     */
    const optional<Int32>& getAttribute4() const
    {
        return ensureData().attribute4;
    }

    /**
     * ギャザリングを新規作成する場合の属性値4を設定
     *
     * @param attribute4 ギャザリングを新規作成する場合の属性値4
     */
    void setAttribute4(Int32 attribute4)
    {
        ensureData().attribute4.emplace(attribute4);
    }

    /**
     * ギャザリングを新規作成する場合の属性値4を設定
     *
     * @param attribute4 ギャザリングを新規作成する場合の属性値4
     */
    CustomAutoDoMatchmakingRequest& withAttribute4(Int32 attribute4)
    {
        ensureData().attribute4.emplace(attribute4);
        return *this;
    }

    /**
     * ギャザリングを新規作成する場合の属性値5を取得
     *
     * @return ギャザリングを新規作成する場合の属性値5
     */
    const optional<Int32>& getAttribute5() const
    {
        return ensureData().attribute5;
    }

    /**
     * ギャザリングを新規作成する場合の属性値5を設定
     *
     * @param attribute5 ギャザリングを新規作成する場合の属性値5
     */
    void setAttribute5(Int32 attribute5)
    {
        ensureData().attribute5.emplace(attribute5);
    }

    /**
     * ギャザリングを新規作成する場合の属性値5を設定
     *
     * @param attribute5 ギャザリングを新規作成する場合の属性値5
     */
    CustomAutoDoMatchmakingRequest& withAttribute5(Int32 attribute5)
    {
        ensureData().attribute5.emplace(attribute5);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値1の最小値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値1の最小値
     */
    const optional<Int32>& getSearchAttribute1Min() const
    {
        return ensureData().searchAttribute1Min;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値1の最小値を設定
     *
     * @param searchAttribute1Min 既存のギャザリングに参加する対象とする属性値1の最小値
     */
    void setSearchAttribute1Min(Int32 searchAttribute1Min)
    {
        ensureData().searchAttribute1Min.emplace(searchAttribute1Min);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値1の最小値を設定
     *
     * @param searchAttribute1Min 既存のギャザリングに参加する対象とする属性値1の最小値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute1Min(Int32 searchAttribute1Min)
    {
        ensureData().searchAttribute1Min.emplace(searchAttribute1Min);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値2の最小値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値2の最小値
     */
    const optional<Int32>& getSearchAttribute2Min() const
    {
        return ensureData().searchAttribute2Min;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値2の最小値を設定
     *
     * @param searchAttribute2Min 既存のギャザリングに参加する対象とする属性値2の最小値
     */
    void setSearchAttribute2Min(Int32 searchAttribute2Min)
    {
        ensureData().searchAttribute2Min.emplace(searchAttribute2Min);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値2の最小値を設定
     *
     * @param searchAttribute2Min 既存のギャザリングに参加する対象とする属性値2の最小値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute2Min(Int32 searchAttribute2Min)
    {
        ensureData().searchAttribute2Min.emplace(searchAttribute2Min);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値3の最小値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値3の最小値
     */
    const optional<Int32>& getSearchAttribute3Min() const
    {
        return ensureData().searchAttribute3Min;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値3の最小値を設定
     *
     * @param searchAttribute3Min 既存のギャザリングに参加する対象とする属性値3の最小値
     */
    void setSearchAttribute3Min(Int32 searchAttribute3Min)
    {
        ensureData().searchAttribute3Min.emplace(searchAttribute3Min);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値3の最小値を設定
     *
     * @param searchAttribute3Min 既存のギャザリングに参加する対象とする属性値3の最小値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute3Min(Int32 searchAttribute3Min)
    {
        ensureData().searchAttribute3Min.emplace(searchAttribute3Min);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値4の最小値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値4の最小値
     */
    const optional<Int32>& getSearchAttribute4Min() const
    {
        return ensureData().searchAttribute4Min;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値4の最小値を設定
     *
     * @param searchAttribute4Min 既存のギャザリングに参加する対象とする属性値4の最小値
     */
    void setSearchAttribute4Min(Int32 searchAttribute4Min)
    {
        ensureData().searchAttribute4Min.emplace(searchAttribute4Min);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値4の最小値を設定
     *
     * @param searchAttribute4Min 既存のギャザリングに参加する対象とする属性値4の最小値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute4Min(Int32 searchAttribute4Min)
    {
        ensureData().searchAttribute4Min.emplace(searchAttribute4Min);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値5の最小値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値5の最小値
     */
    const optional<Int32>& getSearchAttribute5Min() const
    {
        return ensureData().searchAttribute5Min;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値5の最小値を設定
     *
     * @param searchAttribute5Min 既存のギャザリングに参加する対象とする属性値5の最小値
     */
    void setSearchAttribute5Min(Int32 searchAttribute5Min)
    {
        ensureData().searchAttribute5Min.emplace(searchAttribute5Min);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値5の最小値を設定
     *
     * @param searchAttribute5Min 既存のギャザリングに参加する対象とする属性値5の最小値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute5Min(Int32 searchAttribute5Min)
    {
        ensureData().searchAttribute5Min.emplace(searchAttribute5Min);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値1の最大値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値1の最大値
     */
    const optional<Int32>& getSearchAttribute1Max() const
    {
        return ensureData().searchAttribute1Max;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値1の最大値を設定
     *
     * @param searchAttribute1Max 既存のギャザリングに参加する対象とする属性値1の最大値
     */
    void setSearchAttribute1Max(Int32 searchAttribute1Max)
    {
        ensureData().searchAttribute1Max.emplace(searchAttribute1Max);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値1の最大値を設定
     *
     * @param searchAttribute1Max 既存のギャザリングに参加する対象とする属性値1の最大値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute1Max(Int32 searchAttribute1Max)
    {
        ensureData().searchAttribute1Max.emplace(searchAttribute1Max);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値2の最大値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値2の最大値
     */
    const optional<Int32>& getSearchAttribute2Max() const
    {
        return ensureData().searchAttribute2Max;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値2の最大値を設定
     *
     * @param searchAttribute2Max 既存のギャザリングに参加する対象とする属性値2の最大値
     */
    void setSearchAttribute2Max(Int32 searchAttribute2Max)
    {
        ensureData().searchAttribute2Max.emplace(searchAttribute2Max);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値2の最大値を設定
     *
     * @param searchAttribute2Max 既存のギャザリングに参加する対象とする属性値2の最大値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute2Max(Int32 searchAttribute2Max)
    {
        ensureData().searchAttribute2Max.emplace(searchAttribute2Max);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値3の最大値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値3の最大値
     */
    const optional<Int32>& getSearchAttribute3Max() const
    {
        return ensureData().searchAttribute3Max;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値3の最大値を設定
     *
     * @param searchAttribute3Max 既存のギャザリングに参加する対象とする属性値3の最大値
     */
    void setSearchAttribute3Max(Int32 searchAttribute3Max)
    {
        ensureData().searchAttribute3Max.emplace(searchAttribute3Max);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値3の最大値を設定
     *
     * @param searchAttribute3Max 既存のギャザリングに参加する対象とする属性値3の最大値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute3Max(Int32 searchAttribute3Max)
    {
        ensureData().searchAttribute3Max.emplace(searchAttribute3Max);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値4の最大値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値4の最大値
     */
    const optional<Int32>& getSearchAttribute4Max() const
    {
        return ensureData().searchAttribute4Max;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値4の最大値を設定
     *
     * @param searchAttribute4Max 既存のギャザリングに参加する対象とする属性値4の最大値
     */
    void setSearchAttribute4Max(Int32 searchAttribute4Max)
    {
        ensureData().searchAttribute4Max.emplace(searchAttribute4Max);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値4の最大値を設定
     *
     * @param searchAttribute4Max 既存のギャザリングに参加する対象とする属性値4の最大値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute4Max(Int32 searchAttribute4Max)
    {
        ensureData().searchAttribute4Max.emplace(searchAttribute4Max);
        return *this;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値5の最大値を取得
     *
     * @return 既存のギャザリングに参加する対象とする属性値5の最大値
     */
    const optional<Int32>& getSearchAttribute5Max() const
    {
        return ensureData().searchAttribute5Max;
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値5の最大値を設定
     *
     * @param searchAttribute5Max 既存のギャザリングに参加する対象とする属性値5の最大値
     */
    void setSearchAttribute5Max(Int32 searchAttribute5Max)
    {
        ensureData().searchAttribute5Max.emplace(searchAttribute5Max);
    }

    /**
     * 既存のギャザリングに参加する対象とする属性値5の最大値を設定
     *
     * @param searchAttribute5Max 既存のギャザリングに参加する対象とする属性値5の最大値
     */
    CustomAutoDoMatchmakingRequest& withSearchAttribute5Max(Int32 searchAttribute5Max)
    {
        ensureData().searchAttribute5Max.emplace(searchAttribute5Max);
        return *this;
    }

    /**
     * 中断された検索を再開するためのコンテキストを取得
     *
     * @return 中断された検索を再開するためのコンテキスト
     */
    const optional<StringHolder>& getSearchContext() const
    {
        return ensureData().searchContext;
    }

    /**
     * 中断された検索を再開するためのコンテキストを設定
     *
     * @param searchContext 中断された検索を再開するためのコンテキスト
     */
    void setSearchContext(const Char* searchContext)
    {
        ensureData().searchContext.emplace(searchContext);
    }

    /**
     * 中断された検索を再開するためのコンテキストを設定
     *
     * @param searchContext 中断された検索を再開するためのコンテキスト
     */
    CustomAutoDoMatchmakingRequest& withSearchContext(const Char* searchContext)
    {
        ensureData().searchContext.emplace(searchContext);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CustomAutoDoMatchmakingRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CustomAutoDoMatchmakingRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CustomAutoDoMatchmakingRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CustomAutoDoMatchmakingRequest& withRequestId(const Char* gs2RequestId)
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
    CustomAutoDoMatchmakingRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_MATCHMAKING_CONTROL_CUSTOMAUTODOMATCHMAKINGREQUEST_HPP_