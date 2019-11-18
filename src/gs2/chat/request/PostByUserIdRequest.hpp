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

#ifndef GS2_CHAT_CONTROL_POSTBYUSERIDREQUEST_HPP_
#define GS2_CHAT_CONTROL_POSTBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/chat/Gs2ChatConst.hpp>
#include <gs2/chat/model/model.hpp>
#include <memory>

namespace gs2 { namespace chat
{

/**
 * ユーザIDを指定してメッセージを投稿 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class PostByUserIdRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ルーム名 */
        optional<StringHolder> roomName;
        /** 発言したユーザID */
        optional<StringHolder> userId;
        /** メッセージの種類を分類したい時の種類番号 */
        optional<Int32> category;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** メッセージを投稿するために必要となるパスワード */
        optional<StringHolder> password;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            roomName(data.roomName),
            userId(data.userId),
            category(data.category),
            metadata(data.metadata),
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
    PostByUserIdRequest() = default;
    PostByUserIdRequest(const PostByUserIdRequest& postByUserIdRequest) = default;
    PostByUserIdRequest(PostByUserIdRequest&& postByUserIdRequest) = default;
    ~PostByUserIdRequest() GS2_OVERRIDE = default;

    PostByUserIdRequest& operator=(const PostByUserIdRequest& postByUserIdRequest) = default;
    PostByUserIdRequest& operator=(PostByUserIdRequest&& postByUserIdRequest) = default;

    PostByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(PostByUserIdRequest);
    }

    const PostByUserIdRequest* operator->() const
    {
        return this;
    }

    PostByUserIdRequest* operator->()
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
    PostByUserIdRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ルーム名を取得
     *
     * @return ルーム名
     */
    const optional<StringHolder>& getRoomName() const
    {
        return ensureData().roomName;
    }

    /**
     * ルーム名を設定
     *
     * @param roomName ルーム名
     */
    void setRoomName(StringHolder roomName)
    {
        ensureData().roomName.emplace(std::move(roomName));
    }

    /**
     * ルーム名を設定
     *
     * @param roomName ルーム名
     */
    PostByUserIdRequest& withRoomName(StringHolder roomName)
    {
        ensureData().roomName.emplace(std::move(roomName));
        return *this;
    }

    /**
     * 発言したユーザIDを取得
     *
     * @return 発言したユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * 発言したユーザIDを設定
     *
     * @param userId 発言したユーザID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * 発言したユーザIDを設定
     *
     * @param userId 発言したユーザID
     */
    PostByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * メッセージの種類を分類したい時の種類番号を取得
     *
     * @return メッセージの種類を分類したい時の種類番号
     */
    const optional<Int32>& getCategory() const
    {
        return ensureData().category;
    }

    /**
     * メッセージの種類を分類したい時の種類番号を設定
     *
     * @param category メッセージの種類を分類したい時の種類番号
     */
    void setCategory(Int32 category)
    {
        ensureData().category.emplace(category);
    }

    /**
     * メッセージの種類を分類したい時の種類番号を設定
     *
     * @param category メッセージの種類を分類したい時の種類番号
     */
    PostByUserIdRequest& withCategory(Int32 category)
    {
        ensureData().category.emplace(category);
        return *this;
    }

    /**
     * メタデータを取得
     *
     * @return メタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * メタデータを設定
     *
     * @param metadata メタデータ
     */
    PostByUserIdRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * メッセージを投稿するために必要となるパスワードを取得
     *
     * @return メッセージを投稿するために必要となるパスワード
     */
    const optional<StringHolder>& getPassword() const
    {
        return ensureData().password;
    }

    /**
     * メッセージを投稿するために必要となるパスワードを設定
     *
     * @param password メッセージを投稿するために必要となるパスワード
     */
    void setPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
    }

    /**
     * メッセージを投稿するために必要となるパスワードを設定
     *
     * @param password メッセージを投稿するために必要となるパスワード
     */
    PostByUserIdRequest& withPassword(StringHolder password)
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
    PostByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    PostByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    PostByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_CHAT_CONTROL_POSTBYUSERIDREQUEST_HPP_