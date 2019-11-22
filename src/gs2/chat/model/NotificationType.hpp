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

#ifndef GS2_CHAT_MODEL_NOTIFICATIONTYPE_HPP_
#define GS2_CHAT_MODEL_NOTIFICATIONTYPE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace chat {

/**
 * フォローしているユーザー
 *
 * @author Game Server Services, Inc.
 *
 */
class NotificationType : public Gs2Object
{
    friend bool operator!=(const NotificationType& lhs, const NotificationType& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 新着メッセージ通知を受け取るカテゴリ */
        optional<Int32> category;
        /** オフラインだった時にモバイルプッシュ通知に転送するか */
        optional<Bool> enableTransferMobilePushNotification;

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
    NotificationType() = default;
    NotificationType(const NotificationType& notificationType) = default;
    NotificationType(NotificationType&& notificationType) = default;
    ~NotificationType() = default;

    NotificationType& operator=(const NotificationType& notificationType) = default;
    NotificationType& operator=(NotificationType&& notificationType) = default;

    NotificationType deepCopy() const;

    const NotificationType* operator->() const
    {
        return this;
    }

    NotificationType* operator->()
    {
        return this;
    }
    /**
     * 新着メッセージ通知を受け取るカテゴリを取得
     *
     * @return 新着メッセージ通知を受け取るカテゴリ
     */
    const optional<Int32>& getCategory() const
    {
        return ensureData().category;
    }

    /**
     * 新着メッセージ通知を受け取るカテゴリを設定
     *
     * @param category 新着メッセージ通知を受け取るカテゴリ
     */
    void setCategory(Int32 category)
    {
        ensureData().category.emplace(category);
    }

    /**
     * 新着メッセージ通知を受け取るカテゴリを設定
     *
     * @param category 新着メッセージ通知を受け取るカテゴリ
     */
    NotificationType& withCategory(Int32 category)
    {
        setCategory(category);
        return *this;
    }

    /**
     * オフラインだった時にモバイルプッシュ通知に転送するかを取得
     *
     * @return オフラインだった時にモバイルプッシュ通知に転送するか
     */
    const optional<Bool>& getEnableTransferMobilePushNotification() const
    {
        return ensureData().enableTransferMobilePushNotification;
    }

    /**
     * オフラインだった時にモバイルプッシュ通知に転送するかを設定
     *
     * @param enableTransferMobilePushNotification オフラインだった時にモバイルプッシュ通知に転送するか
     */
    void setEnableTransferMobilePushNotification(Bool enableTransferMobilePushNotification)
    {
        ensureData().enableTransferMobilePushNotification.emplace(enableTransferMobilePushNotification);
    }

    /**
     * オフラインだった時にモバイルプッシュ通知に転送するかを設定
     *
     * @param enableTransferMobilePushNotification オフラインだった時にモバイルプッシュ通知に転送するか
     */
    NotificationType& withEnableTransferMobilePushNotification(Bool enableTransferMobilePushNotification)
    {
        setEnableTransferMobilePushNotification(enableTransferMobilePushNotification);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const NotificationType& lhs, const NotificationType& lhr);

inline bool operator==(const NotificationType& lhs, const NotificationType& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_CHAT_MODEL_NOTIFICATIONTYPE_HPP_