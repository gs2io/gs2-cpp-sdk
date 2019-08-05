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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            gatewayNamespaceId(data.gatewayNamespaceId),
            enableTransferMobileNotification(data.enableTransferMobileNotification),
            sound(data.sound)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            gatewayNamespaceId(std::move(data.gatewayNamespaceId)),
            enableTransferMobileNotification(std::move(data.enableTransferMobileNotification)),
            sound(std::move(data.sound))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "gatewayNamespaceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->gatewayNamespaceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "enableTransferMobileNotification") == 0) {
                if (jsonValue.IsBool())
                {
                    this->enableTransferMobileNotification = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "sound") == 0) {
                if (jsonValue.IsString())
                {
                    this->sound.emplace(jsonValue.GetString());
                }
            }
        }
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
    NotificationSetting() :
        m_pData(nullptr)
    {}

    NotificationSetting(const NotificationSetting& notificationSetting) :
        Gs2Object(notificationSetting),
        m_pData(notificationSetting.m_pData != nullptr ? new Data(*notificationSetting.m_pData) : nullptr)
    {}

    NotificationSetting(NotificationSetting&& notificationSetting) :
        Gs2Object(std::move(notificationSetting)),
        m_pData(notificationSetting.m_pData)
    {
        notificationSetting.m_pData = nullptr;
    }

    ~NotificationSetting()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    NotificationSetting& operator=(const NotificationSetting& notificationSetting)
    {
        Gs2Object::operator=(notificationSetting);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*notificationSetting.m_pData);

        return *this;
    }

    NotificationSetting& operator=(NotificationSetting&& notificationSetting)
    {
        Gs2Object::operator=(std::move(notificationSetting));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = notificationSetting.m_pData;
        notificationSetting.m_pData = nullptr;

        return *this;
    }

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
    void setGatewayNamespaceId(const Char* gatewayNamespaceId)
    {
        ensureData().gatewayNamespaceId.emplace(gatewayNamespaceId);
    }

    /**
     * プッシュ通知に使用する GS2-Gateway のネームスペース のGRNを設定
     *
     * @param gatewayNamespaceId プッシュ通知に使用する GS2-Gateway のネームスペース のGRN
     */
    NotificationSetting& withGatewayNamespaceId(const Char* gatewayNamespaceId)
    {
        setGatewayNamespaceId(gatewayNamespaceId);
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
    void setSound(const Char* sound)
    {
        ensureData().sound.emplace(sound);
    }

    /**
     * モバイルプッシュ通知で使用するサウンドファイル名を設定
     *
     * @param sound モバイルプッシュ通知で使用するサウンドファイル名
     */
    NotificationSetting& withSound(const Char* sound)
    {
        setSound(sound);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const NotificationSetting& lhs, const NotificationSetting& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->gatewayNamespaceId != lhr.m_pData->gatewayNamespaceId)
        {
            return true;
        }
        if (lhs.m_pData->enableTransferMobileNotification != lhr.m_pData->enableTransferMobileNotification)
        {
            return true;
        }
        if (lhs.m_pData->sound != lhr.m_pData->sound)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const NotificationSetting& lhs, const NotificationSetting& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_MISSION_MODEL_NOTIFICATIONSETTING_HPP_