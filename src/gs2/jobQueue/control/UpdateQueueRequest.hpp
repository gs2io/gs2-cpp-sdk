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

#ifndef GS2_JOBQUEUE_CONTROL_UPDATEQUEUEREQUEST_HPP_
#define GS2_JOBQUEUE_CONTROL_UPDATEQUEUEREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2JobQueueConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace jobQueue
{

/**
 * @author Game Server Services, Inc.
 */
class UpdateQueueRequest : public Gs2BasicRequest, public Gs2JobQueue
{
public:
    constexpr static const Char* const FUNCTION = "UpdateQueue";

private:
    class Data : public Gs2Object
    {
    public:
        /** ジョブキューの名前を指定します。 */
        optional<StringHolder> queueName;
        /** 説明文 */
        optional<StringHolder> description;
        /** ジョブが追加されたときの通知方式 */
        optional<StringHolder> notificationType;
        /** http/https を選択した際の通知先URL */
        optional<StringHolder> notificationUrl;
        /** gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名 */
        optional<StringHolder> notificationGameName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            queueName(data.queueName),
            description(data.description),
            notificationType(data.notificationType),
            notificationUrl(data.notificationUrl),
            notificationGameName(data.notificationGameName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            queueName(std::move(data.queueName)),
            description(std::move(data.description)),
            notificationType(std::move(data.notificationType)),
            notificationUrl(std::move(data.notificationUrl)),
            notificationGameName(std::move(data.notificationGameName))
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
    UpdateQueueRequest() :
        m_pData(nullptr)
    {}

    UpdateQueueRequest(const UpdateQueueRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2JobQueue(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateQueueRequest(UpdateQueueRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2JobQueue(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateQueueRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateQueueRequest& operator=(const UpdateQueueRequest& updateQueueRequest)
    {
        Gs2BasicRequest::operator=(updateQueueRequest);
        Gs2JobQueue::operator=(updateQueueRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateQueueRequest.m_pData);

        return *this;
    }

    UpdateQueueRequest& operator=(UpdateQueueRequest&& updateQueueRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateQueueRequest));
        Gs2JobQueue::operator=(std::move(updateQueueRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateQueueRequest.m_pData;
        updateQueueRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateQueueRequest* operator->() const
    {
        return this;
    }

    UpdateQueueRequest* operator->()
    {
        return this;
    }

    /**
     * ジョブキューの名前を指定します。を取得
     *
     * @return ジョブキューの名前を指定します。
     */
    const optional<StringHolder>& getQueueName() const
    {
        return ensureData().queueName;
    }

    /**
     * ジョブキューの名前を指定します。を設定
     *
     * @param queueName ジョブキューの名前を指定します。
     */
    void setQueueName(const Char* queueName)
    {
        ensureData().queueName.emplace(queueName);
    }

    /**
     * ジョブキューの名前を指定します。を設定
     *
     * @param queueName ジョブキューの名前を指定します。
     */
    UpdateQueueRequest& withQueueName(const Char* queueName)
    {
        ensureData().queueName.emplace(queueName);
        return *this;
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
     * 説明文を設定
     *
     * @param description 説明文
     */
    UpdateQueueRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
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
     * ジョブが追加されたときの通知方式を設定
     *
     * @param notificationType ジョブが追加されたときの通知方式
     */
    UpdateQueueRequest& withNotificationType(const Char* notificationType)
    {
        ensureData().notificationType.emplace(notificationType);
        return *this;
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
     * http/https を選択した際の通知先URLを設定
     *
     * @param notificationUrl http/https を選択した際の通知先URL
     */
    UpdateQueueRequest& withNotificationUrl(const Char* notificationUrl)
    {
        ensureData().notificationUrl.emplace(notificationUrl);
        return *this;
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
     * gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名を設定
     *
     * @param notificationGameName gs2-in-game-push-notification を選択した際の GS2-InGamePushNotification のゲーム名
     */
    UpdateQueueRequest& withNotificationGameName(const Char* notificationGameName)
    {
        ensureData().notificationGameName.emplace(notificationGameName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateQueueRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateQueueRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateQueueRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateQueueRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_JOBQUEUE_CONTROL_UPDATEQUEUEREQUEST_HPP_