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

#ifndef GS2_ACCOUNT_CONTROL_CREATETAKEOVERBYUSERIDREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_CREATETAKEOVERBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AccountConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace account
{

/**
 * ユーザーIDを指定して引き継ぎ設定を新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateTakeOverByUserIdRequest : public Gs2BasicRequest, public Gs2Account
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** ゲーム名 */
        optional<StringHolder> gameName;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** スロット番号 */
        optional<Int32> type;
        /** 引き継ぎ用ユーザーID */
        optional<StringHolder> userIdentifier;
        /** パスワード */
        optional<StringHolder> password;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            gameName(data.gameName),
            userId(data.userId),
            type(data.type),
            userIdentifier(data.userIdentifier),
            password(data.password),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            gameName(std::move(data.gameName)),
            userId(std::move(data.userId)),
            type(std::move(data.type)),
            userIdentifier(std::move(data.userIdentifier)),
            password(std::move(data.password)),
            duplicationAvoider(std::move(data.duplicationAvoider))
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
    CreateTakeOverByUserIdRequest() :
        m_pData(nullptr)
    {}

    CreateTakeOverByUserIdRequest(const CreateTakeOverByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Account(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateTakeOverByUserIdRequest(CreateTakeOverByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Account(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateTakeOverByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateTakeOverByUserIdRequest& operator=(const CreateTakeOverByUserIdRequest& createTakeOverByUserIdRequest)
    {
        Gs2BasicRequest::operator=(createTakeOverByUserIdRequest);
        Gs2Account::operator=(createTakeOverByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createTakeOverByUserIdRequest.m_pData);

        return *this;
    }

    CreateTakeOverByUserIdRequest& operator=(CreateTakeOverByUserIdRequest&& createTakeOverByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(createTakeOverByUserIdRequest));
        Gs2Account::operator=(std::move(createTakeOverByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createTakeOverByUserIdRequest.m_pData;
        createTakeOverByUserIdRequest.m_pData = nullptr;

        return *this;
    }

    const CreateTakeOverByUserIdRequest* operator->() const
    {
        return this;
    }

    CreateTakeOverByUserIdRequest* operator->()
    {
        return this;
    }
    /**
     * ゲーム名を取得
     *
     * @return ゲーム名
     */
    const optional<StringHolder>& getGameName() const
    {
        return ensureData().gameName;
    }

    /**
     * ゲーム名を設定
     *
     * @param gameName ゲーム名
     */
    void setGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
    }

    /**
     * ゲーム名を設定
     *
     * @param gameName ゲーム名
     */
    CreateTakeOverByUserIdRequest& withGameName(const Char* gameName)
    {
        ensureData().gameName.emplace(gameName);
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    CreateTakeOverByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
        return *this;
    }

    /**
     * スロット番号を取得
     *
     * @return スロット番号
     */
    const optional<Int32>& getType() const
    {
        return ensureData().type;
    }

    /**
     * スロット番号を設定
     *
     * @param type スロット番号
     */
    void setType(Int32 type)
    {
        ensureData().type.emplace(type);
    }

    /**
     * スロット番号を設定
     *
     * @param type スロット番号
     */
    CreateTakeOverByUserIdRequest& withType(Int32 type)
    {
        ensureData().type.emplace(type);
        return *this;
    }

    /**
     * 引き継ぎ用ユーザーIDを取得
     *
     * @return 引き継ぎ用ユーザーID
     */
    const optional<StringHolder>& getUserIdentifier() const
    {
        return ensureData().userIdentifier;
    }

    /**
     * 引き継ぎ用ユーザーIDを設定
     *
     * @param userIdentifier 引き継ぎ用ユーザーID
     */
    void setUserIdentifier(const Char* userIdentifier)
    {
        ensureData().userIdentifier.emplace(userIdentifier);
    }

    /**
     * 引き継ぎ用ユーザーIDを設定
     *
     * @param userIdentifier 引き継ぎ用ユーザーID
     */
    CreateTakeOverByUserIdRequest& withUserIdentifier(const Char* userIdentifier)
    {
        ensureData().userIdentifier.emplace(userIdentifier);
        return *this;
    }

    /**
     * パスワードを取得
     *
     * @return パスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    void setPassword(const Char* password)
    {
        ensureData().password.emplace(password);
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    CreateTakeOverByUserIdRequest& withPassword(const Char* password)
    {
        ensureData().password.emplace(password);
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
    void setDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
    }

    /**
     * 重複実行回避機能に使用するIDを設定
     *
     * @param duplicationAvoider 重複実行回避機能に使用するID
     */
    CreateTakeOverByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
    {
        ensureData().duplicationAvoider.emplace(duplicationAvoider);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateTakeOverByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateTakeOverByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateTakeOverByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateTakeOverByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_ACCOUNT_CONTROL_CREATETAKEOVERBYUSERIDREQUEST_HPP_