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

#ifndef GS2_ACCOUNT_CONTROL_UPDATETAKEOVERBYUSERIDREQUEST_HPP_
#define GS2_ACCOUNT_CONTROL_UPDATETAKEOVERBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/account/Gs2AccountConst.hpp>
#include <gs2/account/model/model.hpp>
#include <memory>

namespace gs2 { namespace account
{

/**
 * 引き継ぎ設定を更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateTakeOverByUserIdRequest : public Gs2BasicRequest, public Gs2Account
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
        /** 古いパスワード */
        optional<StringHolder> oldPassword;
        /** 新しいパスワード */
        optional<StringHolder> password;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            type(data.type),
            oldPassword(data.oldPassword),
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
    UpdateTakeOverByUserIdRequest() = default;
    UpdateTakeOverByUserIdRequest(const UpdateTakeOverByUserIdRequest& updateTakeOverByUserIdRequest) = default;
    UpdateTakeOverByUserIdRequest(UpdateTakeOverByUserIdRequest&& updateTakeOverByUserIdRequest) = default;
    ~UpdateTakeOverByUserIdRequest() GS2_OVERRIDE = default;

    UpdateTakeOverByUserIdRequest& operator=(const UpdateTakeOverByUserIdRequest& updateTakeOverByUserIdRequest) = default;
    UpdateTakeOverByUserIdRequest& operator=(UpdateTakeOverByUserIdRequest&& updateTakeOverByUserIdRequest) = default;

    UpdateTakeOverByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateTakeOverByUserIdRequest);
    }

    const UpdateTakeOverByUserIdRequest* operator->() const
    {
        return this;
    }

    UpdateTakeOverByUserIdRequest* operator->()
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
    UpdateTakeOverByUserIdRequest& withNamespaceName(StringHolder namespaceName)
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
    UpdateTakeOverByUserIdRequest& withUserId(StringHolder userId)
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
    UpdateTakeOverByUserIdRequest& withType(Int32 type)
    {
        ensureData().type.emplace(type);
        return *this;
    }

    /**
     * 古いパスワードを取得
     *
     * @return 古いパスワード
     */
    const optional<StringHolder>& getOldPassword() const
    {
        return ensureData().oldPassword;
    }

    /**
     * 古いパスワードを設定
     *
     * @param oldPassword 古いパスワード
     */
    void setOldPassword(StringHolder oldPassword)
    {
        ensureData().oldPassword.emplace(std::move(oldPassword));
    }

    /**
     * 古いパスワードを設定
     *
     * @param oldPassword 古いパスワード
     */
    UpdateTakeOverByUserIdRequest& withOldPassword(StringHolder oldPassword)
    {
        ensureData().oldPassword.emplace(std::move(oldPassword));
        return *this;
    }

    /**
     * 新しいパスワードを取得
     *
     * @return 新しいパスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * 新しいパスワードを設定
     *
     * @param password 新しいパスワード
     */
    void setPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
    }

    /**
     * 新しいパスワードを設定
     *
     * @param password 新しいパスワード
     */
    UpdateTakeOverByUserIdRequest& withPassword(StringHolder password)
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
    UpdateTakeOverByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    UpdateTakeOverByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateTakeOverByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_ACCOUNT_CONTROL_UPDATETAKEOVERBYUSERIDREQUEST_HPP_