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

#ifndef GS2_CHAT_CONTROL_CREATEROOMREQUEST_HPP_
#define GS2_CHAT_CONTROL_CREATEROOMREQUEST_HPP_

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
 * ルームを作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateRoomRequest : public Gs2BasicRequest, public Gs2Chat
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** アクセストークン */
        optional<StringHolder> accessToken;
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** ルーム名 */
        optional<StringHolder> name;
        /** メタデータ */
        optional<StringHolder> metadata;
        /** メッセージを投稿するために必要となるパスワード */
        optional<StringHolder> password;
        /** ルームに参加可能なユーザIDリスト */
        optional<List<StringHolder>> whiteListUserIds;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            accessToken(data.accessToken),
            namespaceName(data.namespaceName),
            name(data.name),
            metadata(data.metadata),
            password(data.password),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.whiteListUserIds)
            {
                whiteListUserIds = data.whiteListUserIds->deepCopy();
            }
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
    CreateRoomRequest() = default;
    CreateRoomRequest(const CreateRoomRequest& createRoomRequest) = default;
    CreateRoomRequest(CreateRoomRequest&& createRoomRequest) = default;
    ~CreateRoomRequest() GS2_OVERRIDE = default;

    CreateRoomRequest& operator=(const CreateRoomRequest& createRoomRequest) = default;
    CreateRoomRequest& operator=(CreateRoomRequest&& createRoomRequest) = default;

    CreateRoomRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateRoomRequest);
    }

    const CreateRoomRequest* operator->() const
    {
        return this;
    }

    CreateRoomRequest* operator->()
    {
        return this;
    }

    /**
     * アクセストークンを取得。
     *
     * @return アクセストークン
     */
    const gs2::optional<StringHolder>& getAccessToken() const
    {
        return ensureData().accessToken;
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     */
    void setAccessToken(StringHolder accessToken)
    {
        ensureData().accessToken.emplace(std::move(accessToken));
    }

    /**
     * アクセストークンを設定。
     *
     * @param accessToken アクセストークン
     * @return this
     */
    CreateRoomRequest& withAccessToken(StringHolder accessToken)
    {
        setAccessToken(std::move(accessToken));
        return *this;
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
    CreateRoomRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * ルーム名を取得
     *
     * @return ルーム名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * ルーム名を設定
     *
     * @param name ルーム名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * ルーム名を設定
     *
     * @param name ルーム名
     */
    CreateRoomRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    CreateRoomRequest& withMetadata(StringHolder metadata)
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
    CreateRoomRequest& withPassword(StringHolder password)
    {
        ensureData().password.emplace(std::move(password));
        return *this;
    }

    /**
     * ルームに参加可能なユーザIDリストを取得
     *
     * @return ルームに参加可能なユーザIDリスト
     */
    const optional<List<StringHolder>>& getWhiteListUserIds() const
    {
        return ensureData().whiteListUserIds;
    }

    /**
     * ルームに参加可能なユーザIDリストを設定
     *
     * @param whiteListUserIds ルームに参加可能なユーザIDリスト
     */
    void setWhiteListUserIds(List<StringHolder> whiteListUserIds)
    {
        ensureData().whiteListUserIds.emplace(std::move(whiteListUserIds));
    }

    /**
     * ルームに参加可能なユーザIDリストを設定
     *
     * @param whiteListUserIds ルームに参加可能なユーザIDリスト
     */
    CreateRoomRequest& withWhiteListUserIds(List<StringHolder> whiteListUserIds)
    {
        ensureData().whiteListUserIds.emplace(std::move(whiteListUserIds));
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
    CreateRoomRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    CreateRoomRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateRoomRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_CHAT_CONTROL_CREATEROOMREQUEST_HPP_