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

#ifndef GS2_REALTIME_CONTROL_WANTROOMREQUEST_HPP_
#define GS2_REALTIME_CONTROL_WANTROOMREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/realtime/Gs2RealtimeConst.hpp>
#include <gs2/realtime/model/model.hpp>
#include <memory>

namespace gs2 { namespace realtime
{

/**
 * ルームの作成依頼。 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class WantRoomRequest : public Gs2BasicRequest, public Gs2Realtime
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
        optional<StringHolder> name;
        /** ルームの作成が終わったときに通知を受けるユーザIDリスト */
        optional<List<StringHolder>> notificationUserIds;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name)
        {
            if (data.notificationUserIds)
            {
                notificationUserIds = data.notificationUserIds->deepCopy();
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
    WantRoomRequest() = default;
    WantRoomRequest(const WantRoomRequest& wantRoomRequest) = default;
    WantRoomRequest(WantRoomRequest&& wantRoomRequest) = default;
    ~WantRoomRequest() GS2_OVERRIDE = default;

    WantRoomRequest& operator=(const WantRoomRequest& wantRoomRequest) = default;
    WantRoomRequest& operator=(WantRoomRequest&& wantRoomRequest) = default;

    WantRoomRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(WantRoomRequest);
    }

    const WantRoomRequest* operator->() const
    {
        return this;
    }

    WantRoomRequest* operator->()
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
    WantRoomRequest& withNamespaceName(StringHolder namespaceName)
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
    WantRoomRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * ルームの作成が終わったときに通知を受けるユーザIDリストを取得
     *
     * @return ルームの作成が終わったときに通知を受けるユーザIDリスト
     */
    const optional<List<StringHolder>>& getNotificationUserIds() const
    {
        return ensureData().notificationUserIds;
    }

    /**
     * ルームの作成が終わったときに通知を受けるユーザIDリストを設定
     *
     * @param notificationUserIds ルームの作成が終わったときに通知を受けるユーザIDリスト
     */
    void setNotificationUserIds(List<StringHolder> notificationUserIds)
    {
        ensureData().notificationUserIds.emplace(std::move(notificationUserIds));
    }

    /**
     * ルームの作成が終わったときに通知を受けるユーザIDリストを設定
     *
     * @param notificationUserIds ルームの作成が終わったときに通知を受けるユーザIDリスト
     */
    WantRoomRequest& withNotificationUserIds(List<StringHolder> notificationUserIds)
    {
        ensureData().notificationUserIds.emplace(std::move(notificationUserIds));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    WantRoomRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    WantRoomRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_REALTIME_CONTROL_WANTROOMREQUEST_HPP_