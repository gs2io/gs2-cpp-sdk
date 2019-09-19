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
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2AccountConst.hpp"
#include "../model/model.hpp"
#include <memory>

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
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            type(data.type),
            userIdentifier(data.userIdentifier),
            password(data.password),
            duplicationAvoider(data.duplicationAvoider)
        {
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
    CreateTakeOverByUserIdRequest() = default;
    CreateTakeOverByUserIdRequest(const CreateTakeOverByUserIdRequest& createTakeOverByUserIdRequest) = default;
    CreateTakeOverByUserIdRequest(CreateTakeOverByUserIdRequest&& createTakeOverByUserIdRequest) = default;
    ~CreateTakeOverByUserIdRequest() GS2_OVERRIDE = default;

    CreateTakeOverByUserIdRequest& operator=(const CreateTakeOverByUserIdRequest& createTakeOverByUserIdRequest) = default;
    CreateTakeOverByUserIdRequest& operator=(CreateTakeOverByUserIdRequest&& createTakeOverByUserIdRequest) = default;

    CreateTakeOverByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateTakeOverByUserIdRequest);
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
    CreateTakeOverByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    CreateTakeOverByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
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
    void setUserIdentifier(StringHolder userIdentifier)
    {
        ensureData().userIdentifier.emplace(std::move(userIdentifier));
    }

    /**
     * 引き継ぎ用ユーザーIDを設定
     *
     * @param userIdentifier 引き継ぎ用ユーザーID
     */
    CreateTakeOverByUserIdRequest& withUserIdentifier(StringHolder userIdentifier)
    {
        ensureData().userIdentifier.emplace(std::move(userIdentifier));
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
    void setPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
    }

    /**
     * パスワードを設定
     *
     * @param password パスワード
     */
    CreateTakeOverByUserIdRequest& withPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
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
    CreateTakeOverByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    CreateTakeOverByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateTakeOverByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_CREATETAKEOVERBYUSERIDREQUEST_HPP_