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

#ifndef GS2_JOBQUEUE_CONTROL_CREATEQUEUEREQUEST_HPP_
#define GS2_JOBQUEUE_CONTROL_CREATEQUEUEREQUEST_HPP_

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
class CreateQueueRequest : public Gs2BasicRequest, public Gs2JobQueue
{
public:
    constexpr static const Char* const FUNCTION = "CreateQueue";

private:
    class Data : public Gs2Object
    {
    public:
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description),
            notificationType(data.notificationType),
            notificationUrl(data.notificationUrl),
            notificationGameName(data.notificationGameName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
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
    CreateQueueRequest() :
        m_pData(nullptr)
    {}

    CreateQueueRequest(const CreateQueueRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2JobQueue(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateQueueRequest(CreateQueueRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2JobQueue(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateQueueRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateQueueRequest& operator=(const CreateQueueRequest& createQueueRequest)
    {
        Gs2BasicRequest::operator=(createQueueRequest);
        Gs2JobQueue::operator=(createQueueRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createQueueRequest.m_pData);

        return *this;
    }

    CreateQueueRequest& operator=(CreateQueueRequest&& createQueueRequest)
    {
        Gs2BasicRequest::operator=(std::move(createQueueRequest));
        Gs2JobQueue::operator=(std::move(createQueueRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createQueueRequest.m_pData;
        createQueueRequest.m_pData = nullptr;

        return *this;
    }

    const CreateQueueRequest* operator->() const
    {
        return this;
    }

    CreateQueueRequest* operator->()
    {
        return this;
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
     * 名前を設定
     *
     * @param name 名前
     */
    CreateQueueRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    CreateQueueRequest& withDescription(const Char* description)
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
    CreateQueueRequest& withNotificationType(const Char* notificationType)
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
    CreateQueueRequest& withNotificationUrl(const Char* notificationUrl)
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
    CreateQueueRequest& withNotificationGameName(const Char* notificationGameName)
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
    CreateQueueRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateQueueRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateQueueRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateQueueRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_JOBQUEUE_CONTROL_CREATEQUEUEREQUEST_HPP_