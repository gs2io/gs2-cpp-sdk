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

#ifndef GS2_CHAT_CONTROL_UPDATEROOMREQUEST_HPP_
#define GS2_CHAT_CONTROL_UPDATEROOMREQUEST_HPP_

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
 * ルームを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateRoomRequest : public Gs2BasicRequest, public Gs2Chat
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
        /** メタデータ */
        optional<StringHolder> metadata;
        /** メッセージを投稿するために必要となるパスワード */
        optional<StringHolder> password;
        /** ルームに参加可能なユーザIDリスト */
        optional<List<StringHolder>> whiteListUserIds;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            roomName(data.roomName),
            metadata(data.metadata),
            password(data.password)
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
    UpdateRoomRequest() = default;
    UpdateRoomRequest(const UpdateRoomRequest& updateRoomRequest) = default;
    UpdateRoomRequest(UpdateRoomRequest&& updateRoomRequest) = default;
    ~UpdateRoomRequest() GS2_OVERRIDE = default;

    UpdateRoomRequest& operator=(const UpdateRoomRequest& updateRoomRequest) = default;
    UpdateRoomRequest& operator=(UpdateRoomRequest&& updateRoomRequest) = default;

    UpdateRoomRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateRoomRequest);
    }

    const UpdateRoomRequest* operator->() const
    {
        return this;
    }

    UpdateRoomRequest* operator->()
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
    UpdateRoomRequest& withNamespaceName(StringHolder namespaceName)
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
    UpdateRoomRequest& withRoomName(StringHolder roomName)
    {
        ensureData().roomName.emplace(std::move(roomName));
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
    UpdateRoomRequest& withMetadata(StringHolder metadata)
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
    UpdateRoomRequest& withPassword(StringHolder password)
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
    UpdateRoomRequest& withWhiteListUserIds(List<StringHolder> whiteListUserIds)
    {
        ensureData().whiteListUserIds.emplace(std::move(whiteListUserIds));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateRoomRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateRoomRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_CHAT_CONTROL_UPDATEROOMREQUEST_HPP_