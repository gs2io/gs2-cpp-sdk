/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_NOTIFICATION_MODEL_NOTIFICATION_HPP_
#define GS2_NOTIFICATION_MODEL_NOTIFICATION_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace notification {

/**
 * 通知
 *
 * @author Game Server Services, Inc.
 *
 */
class Notification : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** 通知GRN */
        optional<StringHolder> notificationId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 通知名 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            notificationId(data.notificationId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            notificationId(std::move(data.notificationId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "notificationId") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "ownerId") == 0) {
                if (jsonValue.IsString())
                {
                    this->ownerId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->createAt = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->updateAt = jsonValue.GetInt();
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
    Notification() :
        m_pData(nullptr)
    {}

    Notification(const Notification& notification) :
        Gs2Object(notification),
        m_pData(notification.m_pData != nullptr ? new Data(*notification.m_pData) : nullptr)
    {}

    Notification(Notification&& notification) :
        Gs2Object(std::move(notification)),
        m_pData(notification.m_pData)
    {
        notification.m_pData = nullptr;
    }

    ~Notification()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Notification& operator=(const Notification& notification)
    {
        Gs2Object::operator=(notification);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*notification.m_pData);

        return *this;
    }

    Notification& operator=(Notification&& notification)
    {
        Gs2Object::operator=(std::move(notification));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = notification.m_pData;
        notification.m_pData = nullptr;

        return *this;
    }

    const Notification* operator->() const
    {
        return this;
    }

    Notification* operator->()
    {
        return this;
    }


    /**
     * 通知GRNを取得
     *
     * @return 通知GRN
     */
    const optional<StringHolder>& getNotificationId() const
    {
        return ensureData().notificationId;
    }

    /**
     * 通知GRNを設定
     *
     * @param notificationId 通知GRN
     */
    void setNotificationId(const Char* notificationId)
    {
        ensureData().notificationId.emplace(notificationId);
    }

    /**
     * オーナーIDを取得
     *
     * @return オーナーID
     */
    const optional<StringHolder>& getOwnerId() const
    {
        return ensureData().ownerId;
    }

    /**
     * オーナーIDを設定
     *
     * @param ownerId オーナーID
     */
    void setOwnerId(const Char* ownerId)
    {
        ensureData().ownerId.emplace(ownerId);
    }

    /**
     * 通知名を取得
     *
     * @return 通知名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 通知名を設定
     *
     * @param name 通知名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 説明文を取得
     *
     * @return 説明文
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 説明文を設定
     *
     * @param description 説明文
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 作成日時(エポック秒)を取得
     *
     * @return 作成日時(エポック秒)
     */
    const optional<Int32>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時(エポック秒)を設定
     *
     * @param createAt 作成日時(エポック秒)
     */
    void setCreateAt(Int32 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時(エポック秒)を取得
     *
     * @return 最終更新日時(エポック秒)
     */
    const optional<Int32>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時(エポック秒)を設定
     *
     * @param updateAt 最終更新日時(エポック秒)
     */
    void setUpdateAt(Int32 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_NOTIFICATION_MODEL_NOTIFICATION_HPP_