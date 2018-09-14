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

#ifndef GS2_WATCH_CONTROL_DELETEALARMREQUEST_HPP_
#define GS2_WATCH_CONTROL_DELETEALARMREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2WatchConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace watch
{

/**
 * @author Game Server Services, Inc.
 */
class DeleteAlarmRequest : public Gs2BasicRequest, public Gs2Watch
{
public:
    constexpr static const Char* const FUNCTION = "DeleteAlarm";

private:
    class Data : public Gs2Object
    {
    public:
        /** アラームの名前を指定します。 */
        optional<StringHolder> alarmName;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            alarmName(data.alarmName)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            alarmName(std::move(data.alarmName))
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
    DeleteAlarmRequest() :
        m_pData(nullptr)
    {}

    DeleteAlarmRequest(const DeleteAlarmRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Watch(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    DeleteAlarmRequest(DeleteAlarmRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Watch(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~DeleteAlarmRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    DeleteAlarmRequest& operator=(const DeleteAlarmRequest& deleteAlarmRequest)
    {
        Gs2BasicRequest::operator=(deleteAlarmRequest);
        Gs2Watch::operator=(deleteAlarmRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*deleteAlarmRequest.m_pData);

        return *this;
    }

    DeleteAlarmRequest& operator=(DeleteAlarmRequest&& deleteAlarmRequest)
    {
        Gs2BasicRequest::operator=(std::move(deleteAlarmRequest));
        Gs2Watch::operator=(std::move(deleteAlarmRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = deleteAlarmRequest.m_pData;
        deleteAlarmRequest.m_pData = nullptr;

        return *this;
    }

    const DeleteAlarmRequest* operator->() const
    {
        return this;
    }

    DeleteAlarmRequest* operator->()
    {
        return this;
    }

    /**
     * アラームの名前を指定します。を取得
     *
     * @return アラームの名前を指定します。
     */
    const optional<StringHolder>& getAlarmName() const
    {
        return ensureData().alarmName;
    }

    /**
     * アラームの名前を指定します。を設定
     *
     * @param alarmName アラームの名前を指定します。
     */
    void setAlarmName(const Char* alarmName)
    {
        ensureData().alarmName.emplace(alarmName);
    }

    /**
     * アラームの名前を指定します。を設定
     *
     * @param alarmName アラームの名前を指定します。
     */
    DeleteAlarmRequest& withAlarmName(const Char* alarmName)
    {
        ensureData().alarmName.emplace(alarmName);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    DeleteAlarmRequest& withGs2ClientId(const Char* gs2ClientId)
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
    DeleteAlarmRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    DeleteAlarmRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    DeleteAlarmRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_WATCH_CONTROL_DELETEALARMREQUEST_HPP_