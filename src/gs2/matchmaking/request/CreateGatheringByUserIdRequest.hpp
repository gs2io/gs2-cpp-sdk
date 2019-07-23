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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2MatchmakingConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            userId(data.userId),
            player(data.player),
            attributeRanges(data.attributeRanges),
            capacityOfRoles(data.capacityOfRoles),
            allowUserIds(data.allowUserIds),
            duplicationAvoider(data.duplicationAvoider)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            userId(std::move(data.userId)),
            player(std::move(data.player)),
            attributeRanges(std::move(data.attributeRanges)),
            capacityOfRoles(std::move(data.capacityOfRoles)),
            allowUserIds(std::move(data.allowUserIds)),
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
    CreateGatheringByUserIdRequest() :
        m_pData(nullptr)
    {}

    CreateGatheringByUserIdRequest(const CreateGatheringByUserIdRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Matchmaking(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateGatheringByUserIdRequest(CreateGatheringByUserIdRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Matchmaking(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateGatheringByUserIdRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateGatheringByUserIdRequest& operator=(const CreateGatheringByUserIdRequest& createGatheringByUserIdRequest)
    {
        Gs2BasicRequest::operator=(createGatheringByUserIdRequest);
        Gs2Matchmaking::operator=(createGatheringByUserIdRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createGatheringByUserIdRequest.m_pData);

        return *this;
    }

    CreateGatheringByUserIdRequest& operator=(CreateGatheringByUserIdRequest&& createGatheringByUserIdRequest)
    {
        Gs2BasicRequest::operator=(std::move(createGatheringByUserIdRequest));
        Gs2Matchmaking::operator=(std::move(createGatheringByUserIdRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createGatheringByUserIdRequest.m_pData;
        createGatheringByUserIdRequest.m_pData = nullptr;

        return *this;
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    CreateGatheringByUserIdRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    CreateGatheringByUserIdRequest& withUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
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
    void setPlayer(const Player& player)
    {
        ensureData().player.emplace(player);
    }

    /**
     * 自身のプレイヤー情報を設定
     *
     * @param player 自身のプレイヤー情報
     */
    CreateGatheringByUserIdRequest& withPlayer(const Player& player)
    {
        ensureData().player.emplace(player);
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
    void setAttributeRanges(const List<AttributeRange>& attributeRanges)
    {
        ensureData().attributeRanges.emplace(attributeRanges);
    }

    /**
     * 募集条件を設定
     *
     * @param attributeRanges 募集条件
     */
    CreateGatheringByUserIdRequest& withAttributeRanges(const List<AttributeRange>& attributeRanges)
    {
        ensureData().attributeRanges.emplace(attributeRanges);
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
    void setCapacityOfRoles(const List<CapacityOfRole>& capacityOfRoles)
    {
        ensureData().capacityOfRoles.emplace(capacityOfRoles);
    }

    /**
     * 参加者を設定
     *
     * @param capacityOfRoles 参加者
     */
    CreateGatheringByUserIdRequest& withCapacityOfRoles(const List<CapacityOfRole>& capacityOfRoles)
    {
        ensureData().capacityOfRoles.emplace(capacityOfRoles);
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
    void setAllowUserIds(const List<StringHolder>& allowUserIds)
    {
        ensureData().allowUserIds.emplace(allowUserIds);
    }

    /**
     * 参加を許可するユーザIDリストを設定
     *
     * @param allowUserIds 参加を許可するユーザIDリスト
     */
    CreateGatheringByUserIdRequest& withAllowUserIds(const List<StringHolder>& allowUserIds)
    {
        ensureData().allowUserIds.emplace(allowUserIds);
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
    CreateGatheringByUserIdRequest& withDuplicationAvoider(const Char* duplicationAvoider)
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
    CreateGatheringByUserIdRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateGatheringByUserIdRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateGatheringByUserIdRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateGatheringByUserIdRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_MATCHMAKING_CONTROL_CREATEGATHERINGBYUSERIDREQUEST_HPP_