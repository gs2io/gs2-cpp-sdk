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

#ifndef GS2_EZ_CHAT_MODEL_EZNOTIFICATIONTYPE_HPP_
#define GS2_EZ_CHAT_MODEL_EZNOTIFICATIONTYPE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace chat {

class NotificationType;

}

namespace ez { namespace chat {

class EzNotificationType : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** 新着メッセージ通知を受け取るカテゴリ */
        gs2::optional<Int32> category;
        /** オフラインだった時にモバイルプッシュ通知に転送するか */
        gs2::optional<Bool> enableTransferMobilePushNotification;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::chat::NotificationType& notificationType);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzNotificationType() = default;
    EzNotificationType(const EzNotificationType& ezNotificationType) = default;
    EzNotificationType(EzNotificationType&& ezNotificationType) = default;
    ~EzNotificationType() = default;

    EzNotificationType(gs2::chat::NotificationType notificationType);

    EzNotificationType& operator=(const EzNotificationType& ezNotificationType) = default;
    EzNotificationType& operator=(EzNotificationType&& ezNotificationType) = default;

    EzNotificationType deepCopy() const;

    gs2::chat::NotificationType ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    Int32 getCategory() const
    {
        return *ensureData().category;
    }

    Bool getEnableTransferMobilePushNotification() const
    {
        return *ensureData().enableTransferMobilePushNotification;
    }

    // ========================================
    //   Setters
    // ========================================

    void setCategory(Int32 category)
    {
        ensureData().category = category;
    }

    void setEnableTransferMobilePushNotification(Bool enableTransferMobilePushNotification)
    {
        ensureData().enableTransferMobilePushNotification = enableTransferMobilePushNotification;
    }

    EzNotificationType& withCategory(Int32 category)
    {
        setCategory(category);
        return *this;
    }

    EzNotificationType& withEnableTransferMobilePushNotification(Bool enableTransferMobilePushNotification)
    {
        setEnableTransferMobilePushNotification(enableTransferMobilePushNotification);
        return *this;
    }
};

}}}

#endif //GS2_EZ_CHAT_EZNOTIFICATIONTYPE_HPP_