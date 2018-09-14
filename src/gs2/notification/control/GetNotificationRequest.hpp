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

#ifndef GS2_NOTIFICATION_CONTROL_GETNOTIFICATIONREQUEST_HPP_
#define GS2_NOTIFICATION_CONTROL_GETNOTIFICATIONREQUEST_HPP_

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
class GetNotificationRequest : public Gs2BasicRequest, public Gs2Notification
{
public:
    constexpr static const Char* const FUNCTION = "GetNotification";

private:
    class Data : public Gs2Object
    {
    public:
        /** 通知の名前を指定します。 */
        optional<StringHolder> notificationName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            notificationName(data.notificationName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            notificationName(std::move(data.notificationName))
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
    GetNotificationRequest() :
        m_pData(nullptr)
    {}

    GetNotificationRequest(const GetNotificationRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Notification(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetNotificationRequest(GetNotificationRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Notification(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetNotificationRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetNotificationRequest& operator=(const GetNotificationRequest& getNotificationRequest)
    {
        Gs2BasicRequest::operator=(getNotificationRequest);
        Gs2Notification::operator=(getNotificationRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getNotificationRequest.m_pData);

        return *this;
    }

    GetNotificationRequest& operator=(GetNotificationRequest&& getNotificationRequest)
    {
        Gs2BasicRequest::operator=(std::move(getNotificationRequest));
        Gs2Notification::operator=(std::move(getNotificationRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getNotificationRequest.m_pData;
        getNotificationRequest.m_pData = nullptr;

        return *this;
    }

    const GetNotificationRequest* operator->() const
    {
        return this;
    }

    GetNotificationRequest* operator->()
    {
        return this;
    }

    /**
     * 通知の名前を指定します。を取得
     *
     * @return 通知の名前を指定します。
     */
    const optional<StringHolder>& getNotificationName() const
    {
        return ensureData().notificationName;
    }

    /**
     * 通知の名前を指定します。を設定
     *
     * @param notificationName 通知の名前を指定します。
     */
    void setNotificationName(const Char* notificationName)
    {
        ensureData().notificationName.emplace(notificationName);
    }

    /**
     * 通知の名前を指定します。を設定
     *
     * @param notificationName 通知の名前を指定します。
     */
    GetNotificationRequest& withNotificationName(const Char* notificationName)
    {
        ensureData().notificationName.emplace(notificationName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetNotificationRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetNotificationRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetNotificationRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetNotificationRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_NOTIFICATION_CONTROL_GETNOTIFICATIONREQUEST_HPP_