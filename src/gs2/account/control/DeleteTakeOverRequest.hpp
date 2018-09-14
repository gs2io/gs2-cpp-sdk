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

#ifndef GS2_ACCOUNT_CONTROL_DELETETAKEOVERREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_DELETETAKEOVERREQUEST_HPP_

#include <gs2/core/control/Gs2UserRequest.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AccountConst.hpp"

namespace gs2 { namespace account {

/**
 * @author Game Server Services, Inc.
 */
class DeleteTakeOverRequest : public Gs2UserRequest, public Gs2Account
{
public:
    constexpr static const Char* const FUNCTION = "DeleteTakeOver";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゲームの名前を指定します。 */
        optional<StringHolder> gameName;
        /** 削除する引き継ぎ情報の種類を指定します。 */
        optional<Int32> type;
        /** 削除する引き継ぎ情報のユーザ固有IDを指定します。 */
        optional<StringHolder> userIdentifier;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gameName(data.gameName),
            type(data.type),
            userIdentifier(data.userIdentifier)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gameName(std::move(data.gameName)),
            type(std::move(data.type)),
            userIdentifier(std::move(data.userIdentifier))
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
    DeleteTakeOverRequest() :
        m_pData(nullptr)
    {}

    DeleteTakeOverRequest(const DeleteTakeOverRequest& obj) :
        Gs2UserRequest(obj),
        Gs2Account(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteTakeOverRequest(DeleteTakeOverRequest&& obj) :
        Gs2UserRequest(std::move(obj)),
        Gs2Account(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteTakeOverRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteTakeOverRequest& operator=(const DeleteTakeOverRequest& deleteTakeOverRequest)
    {
        Gs2UserRequest::operator=(deleteTakeOverRequest);
        Gs2Account::operator=(deleteTakeOverRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteTakeOverRequest.m_pData);

        return *this;
    }

    DeleteTakeOverRequest& operator=(DeleteTakeOverRequest&& deleteTakeOverRequest)
    {
        Gs2UserRequest::operator=(std::move(deleteTakeOverRequest));
        Gs2Account::operator=(std::move(deleteTakeOverRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteTakeOverRequest.m_pData;
        deleteTakeOverRequest.m_pData = nullptr;

        return *this;
    }

    /**
     * ゲームの名前を指定します。を取得
     *
     * @return ゲームの名前を指定します。
     */
    const optional<StringHolder>& getGameName() const
    {
        return ensureData().gameName;
    }

    /**
     * ゲームの名前を指定します。を設定
     *
     * @param gameName ゲームの名前を指定します。
     */
    void setGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
    }

    /**
     * ゲームの名前を指定します。を設定
     *
     * @param gameName ゲームの名前を指定します。
     */
    DeleteTakeOverRequest& withGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
        return *this;
    }

    /**
     * 削除する引き継ぎ情報の種類を指定します。を取得
     *
     * @return 削除する引き継ぎ情報の種類を指定します。
     */
    const optional<Int32>& getType() const
    {
        return ensureData().type;
    }

    /**
     * 削除する引き継ぎ情報の種類を指定します。を設定
     *
     * @param type 削除する引き継ぎ情報の種類を指定します。
     */
    void setType(Int32 type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * 削除する引き継ぎ情報の種類を指定します。を設定
     *
     * @param type 削除する引き継ぎ情報の種類を指定します。
     */
    DeleteTakeOverRequest& withType(Int32 type)
    {
        ensureData().type.emplace(type);
        return *this;
    }

    /**
     * 削除する引き継ぎ情報のユーザ固有IDを指定します。を取得
     *
     * @return 削除する引き継ぎ情報のユーザ固有IDを指定します。
     */
    const optional<StringHolder>& getUserIdentifier() const
    {
        return ensureData().userIdentifier;
    }

    /**
     * 削除する引き継ぎ情報のユーザ固有IDを指定します。を設定
     *
     * @param userIdentifier 削除する引き継ぎ情報のユーザ固有IDを指定します。
     */
    void setUserIdentifier(const Char* userIdentifier)
    {
        ensureData().userIdentifier.emplace(userIdentifier);
    }

    /**
     * 削除する引き継ぎ情報のユーザ固有IDを指定します。を設定
     *
     * @param userIdentifier 削除する引き継ぎ情報のユーザ固有IDを指定します。
     */
    DeleteTakeOverRequest& withUserIdentifier(const Char* userIdentifier)
    {
        ensureData().userIdentifier.emplace(userIdentifier);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteTakeOverRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteTakeOverRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteTakeOverRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteTakeOverRequest& withRequestId(const Char* gs2RequestId)
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
    DeleteTakeOverRequest& withAccessToken(const Char* accessToken) {
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

#endif //GS2_ACCOUNT_CONTROL_DELETETAKEOVERREQUEST_HPP_