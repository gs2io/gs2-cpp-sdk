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

#ifndef GS2_JOBQUEUE_MODEL_QUEUE_HPP_
#define GS2_JOBQUEUE_MODEL_QUEUE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace jobQueue {

/**
 * キュー
 *
 * @author Game Server Services, Inc.
 *
 */
class Queue : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** キューGRN */
        optional<StringHolder> queueId;
        /** オーナーID */
        optional<StringHolder> ownerId;
        /** 名前 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** ジョブが追加されたときの通知方式 */
        optional<StringHolder> notificationType;
        /** http/https を選択した際の通知先URL */
        optional<StringHolder> notificationUrl;
        /** gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名 */
        optional<StringHolder> notificationGameName;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            queueId(data.queueId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            notificationType(data.notificationType),
            notificationUrl(data.notificationUrl),
            notificationGameName(data.notificationGameName),
            createAt(data.createAt),
            updateAt(data.updateAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            queueId(std::move(data.queueId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            notificationType(std::move(data.notificationType)),
            notificationUrl(std::move(data.notificationUrl)),
            notificationGameName(std::move(data.notificationGameName)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "queueId") == 0) {
                if (jsonValue.IsString())
                {
                    this->queueId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "notificationType") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationType.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "notificationUrl") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationUrl.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "notificationGameName") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationGameName.emplace(jsonValue.GetString());
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
    Queue() :
        m_pData(nullptr)
    {}

    Queue(const Queue& queue) :
        Gs2Object(queue),
        m_pData(queue.m_pData != nullptr ? new Data(*queue.m_pData) : nullptr)
    {}

    Queue(Queue&& queue) :
        Gs2Object(std::move(queue)),
        m_pData(queue.m_pData)
    {
        queue.m_pData = nullptr;
    }

    ~Queue()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Queue& operator=(const Queue& queue)
    {
        Gs2Object::operator=(queue);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*queue.m_pData);

        return *this;
    }

    Queue& operator=(Queue&& queue)
    {
        Gs2Object::operator=(std::move(queue));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = queue.m_pData;
        queue.m_pData = nullptr;

        return *this;
    }

    const Queue* operator->() const
    {
        return this;
    }

    Queue* operator->()
    {
        return this;
    }


    /**
     * キューGRNを取得
     *
     * @return キューGRN
     */
    const optional<StringHolder>& getQueueId() const
    {
        return ensureData().queueId;
    }

    /**
     * キューGRNを設定
     *
     * @param queueId キューGRN
     */
    void setQueueId(const Char* queueId)
    {
        ensureData().queueId.emplace(queueId);
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
     * 名前を取得
     *
     * @return 名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 名前を設定
     *
     * @param name 名前
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
     * ジョブが追加されたときの通知方式を取得
     *
     * @return ジョブが追加されたときの通知方式
     */
    const optional<StringHolder>& getNotificationType() const
    {
        return ensureData().notificationType;
    }

    /**
     * ジョブが追加されたときの通知方式を設定
     *
     * @param notificationType ジョブが追加されたときの通知方式
     */
    void setNotificationType(const Char* notificationType)
    {
        ensureData().notificationType.emplace(notificationType);
    }

    /**
     * http/https を選択した際の通知先URLを取得
     *
     * @return http/https を選択した際の通知先URL
     */
    const optional<StringHolder>& getNotificationUrl() const
    {
        return ensureData().notificationUrl;
    }

    /**
     * http/https を選択した際の通知先URLを設定
     *
     * @param notificationUrl http/https を選択した際の通知先URL
     */
    void setNotificationUrl(const Char* notificationUrl)
    {
        ensureData().notificationUrl.emplace(notificationUrl);
    }

    /**
     * gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名を取得
     *
     * @return gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名
     */
    const optional<StringHolder>& getNotificationGameName() const
    {
        return ensureData().notificationGameName;
    }

    /**
     * gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名を設定
     *
     * @param notificationGameName gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名
     */
    void setNotificationGameName(const Char* notificationGameName)
    {
        ensureData().notificationGameName.emplace(notificationGameName);
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

#endif //GS2_JOBQUEUE_MODEL_QUEUE_HPP_