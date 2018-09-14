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

#ifndef GS2_NOTIFICATION_CONTROL_CREATENOTIFICATIONREQUEST_HPP_
#define GS2_NOTIFICATION_CONTROL_CREATENOTIFICATIONREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2NotificationConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace notification
{

/**
 * @author Game Server Services, Inc.
 */
class CreateNotificationRequest : public Gs2BasicRequest, public Gs2Notification
{
public:
    constexpr static const Char* const FUNCTION = "CreateNotification";

private:
    class Data : public Gs2Object
    {
    public:
        /** 通知の名前 */
        optional<StringHolder> name;
        /** 通知の説明 */
        optional<StringHolder> description;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            description(data.description)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description))
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
    CreateNotificationRequest() :
        m_pData(nullptr)
    {}

    CreateNotificationRequest(const CreateNotificationRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Notification(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateNotificationRequest(CreateNotificationRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Notification(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateNotificationRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateNotificationRequest& operator=(const CreateNotificationRequest& createNotificationRequest)
    {
        Gs2BasicRequest::operator=(createNotificationRequest);
        Gs2Notification::operator=(createNotificationRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createNotificationRequest.m_pData);

        return *this;
    }

    CreateNotificationRequest& operator=(CreateNotificationRequest&& createNotificationRequest)
    {
        Gs2BasicRequest::operator=(std::move(createNotificationRequest));
        Gs2Notification::operator=(std::move(createNotificationRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createNotificationRequest.m_pData;
        createNotificationRequest.m_pData = nullptr;

        return *this;
    }

    const CreateNotificationRequest* operator->() const
    {
        return this;
    }

    CreateNotificationRequest* operator->()
    {
        return this;
    }

    /**
     * 通知の名前を取得
     *
     * @return 通知の名前
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 通知の名前を設定
     *
     * @param name 通知の名前
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 通知の名前を設定
     *
     * @param name 通知の名前
     */
    CreateNotificationRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * 通知の説明を取得
     *
     * @return 通知の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 通知の説明を設定
     *
     * @param description 通知の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 通知の説明を設定
     *
     * @param description 通知の説明
     */
    CreateNotificationRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateNotificationRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateNotificationRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateNotificationRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateNotificationRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_NOTIFICATION_CONTROL_CREATENOTIFICATIONREQUEST_HPP_