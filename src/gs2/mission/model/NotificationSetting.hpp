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

#ifndef GS2_MISSION_MODEL_NOTIFICATIONSETTING_HPP_
#define GS2_MISSION_MODEL_NOTIFICATIONSETTING_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace mission {

/**
 * プッシュ通知設定
 *
 * @author Game Server Services, Inc.
 *
 */
class NotificationSetting : public Gs2Object
{
    friend bool operator!=(const NotificationSetting& lhs, const NotificationSetting& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** プッシュ通知に使用する GS2-Gateway のネームスペース のGRN */
        optional<StringHolder> gatewayNamespaceId;
        /** モバイルプッシュ通知へ転送するか */
        optional<Bool> enableTransferMobileNotification;
        /** モバイルプッシュ通知で使用するサウンドファイル名 */
        optional<StringHolder> sound;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    NotificationSetting() = default;
    NotificationSetting(const NotificationSetting& notificationSetting) = default;
    NotificationSetting(NotificationSetting&& notificationSetting) = default;
    ~NotificationSetting() = default;

    NotificationSetting& operator=(const NotificationSetting& notificationSetting) = default;
    NotificationSetting& operator=(NotificationSetting&& notificationSetting) = default;

    NotificationSetting deepCopy() const;

    const NotificationSetting* operator->() const
    {
        return this;
    }

    NotificationSetting* operator->()
    {
        return this;
    }
    /**
     * プッシュ通知に使用する GS2-Gateway のネームスペース のGRNを取得
     *
     * @return プッシュ通知に使用する GS2-Gateway のネームスペース のGRN
     */
    const optional<StringHolder>& getGatewayNamespaceId() const
    {
        return ensureData().gatewayNamespaceId;
    }

    /**
     * プッシュ通知に使用する GS2-Gateway のネームスペース のGRNを設定
     *
     * @param gatewayNamespaceId プッシュ通知に使用する GS2-Gateway のネームスペース のGRN
     */
    void setGatewayNamespaceId(StringHolder gatewayNamespaceId)
    {
        ensureData().gatewayNamespaceId.emplace(std::move(gatewayNamespaceId));
    }

    /**
     * プッシュ通知に使用する GS2-Gateway のネームスペース のGRNを設定
     *
     * @param gatewayNamespaceId プッシュ通知に使用する GS2-Gateway のネームスペース のGRN
     */
    NotificationSetting& withGatewayNamespaceId(StringHolder gatewayNamespaceId)
    {
        setGatewayNamespaceId(std::move(gatewayNamespaceId));
        return *this;
    }

    /**
     * モバイルプッシュ通知へ転送するかを取得
     *
     * @return モバイルプッシュ通知へ転送するか
     */
    const optional<Bool>& getEnableTransferMobileNotification() const
    {
        return ensureData().enableTransferMobileNotification;
    }

    /**
     * モバイルプッシュ通知へ転送するかを設定
     *
     * @param enableTransferMobileNotification モバイルプッシュ通知へ転送するか
     */
    void setEnableTransferMobileNotification(Bool enableTransferMobileNotification)
    {
        ensureData().enableTransferMobileNotification.emplace(enableTransferMobileNotification);
    }

    /**
     * モバイルプッシュ通知へ転送するかを設定
     *
     * @param enableTransferMobileNotification モバイルプッシュ通知へ転送するか
     */
    NotificationSetting& withEnableTransferMobileNotification(Bool enableTransferMobileNotification)
    {
        setEnableTransferMobileNotification(enableTransferMobileNotification);
        return *this;
    }

    /**
     * モバイルプッシュ通知で使用するサウンドファイル名を取得
     *
     * @return モバイルプッシュ通知で使用するサウンドファイル名
     */
    const optional<StringHolder>& getSound() const
    {
        return ensureData().sound;
    }

    /**
     * モバイルプッシュ通知で使用するサウンドファイル名を設定
     *
     * @param sound モバイルプッシュ通知で使用するサウンドファイル名
     */
    void setSound(StringHolder sound)
    {
        ensureData().sound.emplace(std::move(sound));
    }

    /**
     * モバイルプッシュ通知で使用するサウンドファイル名を設定
     *
     * @param sound モバイルプッシュ通知で使用するサウンドファイル名
     */
    NotificationSetting& withSound(StringHolder sound)
    {
        setSound(std::move(sound));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const NotificationSetting& lhs, const NotificationSetting& lhr);

inline bool operator==(const NotificationSetting& lhs, const NotificationSetting& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_NOTIFICATIONSETTING_HPP_