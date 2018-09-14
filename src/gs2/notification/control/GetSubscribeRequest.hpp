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

#ifndef GS2_NOTIFICATION_CONTROL_GETSUBSCRIBEREQUEST_HPP_
#define GS2_NOTIFICATION_CONTROL_GETSUBSCRIBEREQUEST_HPP_

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
class GetSubscribeRequest : public Gs2BasicRequest, public Gs2Notification
{
public:
    constexpr static const Char* const FUNCTION = "GetSubscribe";

private:
    class Data : public Gs2Object
    {
    public:
        /** 通知の名前を指定します。 */
        optional<StringHolder> notificationName;
        /** 取得する購読IDを指定します。 */
        optional<StringHolder> subscribeId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            notificationName(data.notificationName),
            subscribeId(data.subscribeId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            notificationName(std::move(data.notificationName)),
            subscribeId(std::move(data.subscribeId))
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
    GetSubscribeRequest() :
        m_pData(nullptr)
    {}

    GetSubscribeRequest(const GetSubscribeRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Notification(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    GetSubscribeRequest(GetSubscribeRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Notification(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~GetSubscribeRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    GetSubscribeRequest& operator=(const GetSubscribeRequest& getSubscribeRequest)
    {
        Gs2BasicRequest::operator=(getSubscribeRequest);
        Gs2Notification::operator=(getSubscribeRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*getSubscribeRequest.m_pData);

        return *this;
    }

    GetSubscribeRequest& operator=(GetSubscribeRequest&& getSubscribeRequest)
    {
        Gs2BasicRequest::operator=(std::move(getSubscribeRequest));
        Gs2Notification::operator=(std::move(getSubscribeRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = getSubscribeRequest.m_pData;
        getSubscribeRequest.m_pData = nullptr;

        return *this;
    }

    const GetSubscribeRequest* operator->() const
    {
        return this;
    }

    GetSubscribeRequest* operator->()
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
    GetSubscribeRequest& withNotificationName(const Char* notificationName)
    {
        ensureData().notificationName.emplace(notificationName);
        return *this;
    }

    /**
     * 取得する購読IDを指定します。を取得
     *
     * @return 取得する購読IDを指定します。
     */
    const optional<StringHolder>& getSubscribeId() const
    {
        return ensureData().subscribeId;
    }

    /**
     * 取得する購読IDを指定します。を設定
     *
     * @param subscribeId 取得する購読IDを指定します。
     */
    void setSubscribeId(const Char* subscribeId)
    {
        ensureData().subscribeId.emplace(subscribeId);
    }

    /**
     * 取得する購読IDを指定します。を設定
     *
     * @param subscribeId 取得する購読IDを指定します。
     */
    GetSubscribeRequest& withSubscribeId(const Char* subscribeId)
    {
        ensureData().subscribeId.emplace(subscribeId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    GetSubscribeRequest& withGs2ClientId(const Char* gs2ClientId)
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
    GetSubscribeRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    GetSubscribeRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    GetSubscribeRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_NOTIFICATION_CONTROL_GETSUBSCRIBEREQUEST_HPP_