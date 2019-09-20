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

#ifndef GS2_MATCHMAKING_CONTROL_CREATEGATHERINGBYUSERIDREQUEST_HPP_
#define GS2_MATCHMAKING_CONTROL_CREATEGATHERINGBYUSERIDREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/matchmaking/Gs2MatchmakingConst.hpp>
#include <gs2/matchmaking/model/model.hpp>
#include <memory>

namespace gs2 { namespace matchmaking
{

/**
 * ギャザリングを作成して募集を開始 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateGatheringByUserIdRequest : public Gs2BasicRequest, public Gs2Matchmaking
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
        /** 自身のプレイヤー情報 */
        optional<Player> player;
        /** 募集条件 */
        optional<List<AttributeRange>> attributeRanges;
        /** 参加者 */
        optional<List<CapacityOfRole>> capacityOfRoles;
        /** 参加を許可するユーザIDリスト */
        optional<List<StringHolder>> allowUserIds;
        /** 重複実行回避機能に使用するID */
        optional<StringHolder> duplicationAvoider;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            duplicationAvoider(data.duplicationAvoider)
        {
            if (data.player)
            {
                player = data.player->deepCopy();
            }
            if (data.attributeRanges)
            {
                attributeRanges = data.attributeRanges->deepCopy();
            }
            if (data.capacityOfRoles)
            {
                capacityOfRoles = data.capacityOfRoles->deepCopy();
            }
            if (data.allowUserIds)
            {
                allowUserIds = data.allowUserIds->deepCopy();
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
    CreateGatheringByUserIdRequest() = default;
    CreateGatheringByUserIdRequest(const CreateGatheringByUserIdRequest& createGatheringByUserIdRequest) = default;
    CreateGatheringByUserIdRequest(CreateGatheringByUserIdRequest&& createGatheringByUserIdRequest) = default;
    ~CreateGatheringByUserIdRequest() GS2_OVERRIDE = default;

    CreateGatheringByUserIdRequest& operator=(const CreateGatheringByUserIdRequest& createGatheringByUserIdRequest) = default;
    CreateGatheringByUserIdRequest& operator=(CreateGatheringByUserIdRequest&& createGatheringByUserIdRequest) = default;

    CreateGatheringByUserIdRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateGatheringByUserIdRequest);
    }

    const CreateGatheringByUserIdRequest* operator->() const
    {
        return this;
    }

    CreateGatheringByUserIdRequest* operator->()
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
    CreateGatheringByUserIdRequest& withNamespaceName(StringHolder namespaceName)
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
    CreateGatheringByUserIdRequest& withUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
        return *this;
    }

    /**
     * 自身のプレイヤー情報を取得
     *
     * @return 自身のプレイヤー情報
     */
    const optional<Player>& getPlayer() const
    {
        return ensureData().player;
    }

    /**
     * 自身のプレイヤー情報を設定
     *
     * @param player 自身のプレイヤー情報
     */
    void setPlayer(Player player)
    {
        ensureData().player.emplace(std::move(player));
    }

    /**
     * 自身のプレイヤー情報を設定
     *
     * @param player 自身のプレイヤー情報
     */
    CreateGatheringByUserIdRequest& withPlayer(Player player)
    {
        ensureData().player.emplace(std::move(player));
        return *this;
    }

    /**
     * 募集条件を取得
     *
     * @return 募集条件
     */
    const optional<List<AttributeRange>>& getAttributeRanges() const
    {
        return ensureData().attributeRanges;
    }

    /**
     * 募集条件を設定
     *
     * @param attributeRanges 募集条件
     */
    void setAttributeRanges(List<AttributeRange> attributeRanges)
    {
        ensureData().attributeRanges.emplace(std::move(attributeRanges));
    }

    /**
     * 募集条件を設定
     *
     * @param attributeRanges 募集条件
     */
    CreateGatheringByUserIdRequest& withAttributeRanges(List<AttributeRange> attributeRanges)
    {
        ensureData().attributeRanges.emplace(std::move(attributeRanges));
        return *this;
    }

    /**
     * 参加者を取得
     *
     * @return 参加者
     */
    const optional<List<CapacityOfRole>>& getCapacityOfRoles() const
    {
        return ensureData().capacityOfRoles;
    }

    /**
     * 参加者を設定
     *
     * @param capacityOfRoles 参加者
     */
    void setCapacityOfRoles(List<CapacityOfRole> capacityOfRoles)
    {
        ensureData().capacityOfRoles.emplace(std::move(capacityOfRoles));
    }

    /**
     * 参加者を設定
     *
     * @param capacityOfRoles 参加者
     */
    CreateGatheringByUserIdRequest& withCapacityOfRoles(List<CapacityOfRole> capacityOfRoles)
    {
        ensureData().capacityOfRoles.emplace(std::move(capacityOfRoles));
        return *this;
    }

    /**
     * 参加を許可するユーザIDリストを取得
     *
     * @return 参加を許可するユーザIDリスト
     */
    const optional<List<StringHolder>>& getAllowUserIds() const
    {
        return ensureData().allowUserIds;
    }

    /**
     * 参加を許可するユーザIDリストを設定
     *
     * @param allowUserIds 参加を許可するユーザIDリスト
     */
    void setAllowUserIds(List<StringHolder> allowUserIds)
    {
        ensureData().allowUserIds.emplace(std::move(allowUserIds));
    }

    /**
     * 参加を許可するユーザIDリストを設定
     *
     * @param allowUserIds 参加を許可するユーザIDリスト
     */
    CreateGatheringByUserIdRequest& withAllowUserIds(List<StringHolder> allowUserIds)
    {
        ensureData().allowUserIds.emplace(std::move(allowUserIds));
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
    CreateGatheringByUserIdRequest& withDuplicationAvoider(StringHolder duplicationAvoider)
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
    CreateGatheringByUserIdRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGatheringByUserIdRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_MATCHMAKING_CONTROL_CREATEGATHERINGBYUSERIDREQUEST_HPP_