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

#ifndef GS2_WATCH_CONTROL_UPDATEALARMREQUEST_HPP_
#define GS2_WATCH_CONTROL_UPDATEALARMREQUEST_HPP_

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
class UpdateAlarmRequest : public Gs2BasicRequest, public Gs2Watch
{
public:
    constexpr static const Char* const FUNCTION = "UpdateAlarm";

private:
    class Data : public Gs2Object
    {
    public:
        /** アラームの名前を指定します。 */
        optional<StringHolder> alarmName;
        /** 説明文 */
        optional<StringHolder> description;
        /** 演算子 */
        optional<StringHolder> expression;
        /** 閾値 */
        optional<Double> threshold;
        /** 通知先 GS2-Notification 通知GRN */
        optional<StringHolder> notificationId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            alarmName(data.alarmName),
            description(data.description),
            expression(data.expression),
            threshold(data.threshold),
            notificationId(data.notificationId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            alarmName(std::move(data.alarmName)),
            description(std::move(data.description)),
            expression(std::move(data.expression)),
            threshold(std::move(data.threshold)),
            notificationId(std::move(data.notificationId))
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
    UpdateAlarmRequest() :
        m_pData(nullptr)
    {}

    UpdateAlarmRequest(const UpdateAlarmRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Watch(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateAlarmRequest(UpdateAlarmRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Watch(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateAlarmRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateAlarmRequest& operator=(const UpdateAlarmRequest& updateAlarmRequest)
    {
        Gs2BasicRequest::operator=(updateAlarmRequest);
        Gs2Watch::operator=(updateAlarmRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateAlarmRequest.m_pData);

        return *this;
    }

    UpdateAlarmRequest& operator=(UpdateAlarmRequest&& updateAlarmRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateAlarmRequest));
        Gs2Watch::operator=(std::move(updateAlarmRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateAlarmRequest.m_pData;
        updateAlarmRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateAlarmRequest* operator->() const
    {
        return this;
    }

    UpdateAlarmRequest* operator->()
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
    UpdateAlarmRequest& withAlarmName(const Char* alarmName)
    {
        ensureData().alarmName.emplace(alarmName);
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
    UpdateAlarmRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * 演算子を取得
     *
     * @return 演算子
     */
    const optional<StringHolder>& getExpression() const
    {
        return ensureData().expression;
    }

    /**
     * 演算子を設定
     *
     * @param expression 演算子
     */
    void setExpression(const Char* expression)
    {
        ensureData().expression.emplace(expression);
    }

    /**
     * 演算子を設定
     *
     * @param expression 演算子
     */
    UpdateAlarmRequest& withExpression(const Char* expression)
    {
        ensureData().expression.emplace(expression);
        return *this;
    }

    /**
     * 閾値を取得
     *
     * @return 閾値
     */
    const optional<Double>& getThreshold() const
    {
        return ensureData().threshold;
    }

    /**
     * 閾値を設定
     *
     * @param threshold 閾値
     */
    void setThreshold(Double threshold)
    {
        ensureData().threshold.emplace(threshold);
    }

    /**
     * 閾値を設定
     *
     * @param threshold 閾値
     */
    UpdateAlarmRequest& withThreshold(Double threshold)
    {
        ensureData().threshold.emplace(threshold);
        return *this;
    }

    /**
     * 通知先 GS2-Notification 通知GRNを取得
     *
     * @return 通知先 GS2-Notification 通知GRN
     */
    const optional<StringHolder>& getNotificationId() const
    {
        return ensureData().notificationId;
    }

    /**
     * 通知先 GS2-Notification 通知GRNを設定
     *
     * @param notificationId 通知先 GS2-Notification 通知GRN
     */
    void setNotificationId(const Char* notificationId)
    {
        ensureData().notificationId.emplace(notificationId);
    }

    /**
     * 通知先 GS2-Notification 通知GRNを設定
     *
     * @param notificationId 通知先 GS2-Notification 通知GRN
     */
    UpdateAlarmRequest& withNotificationId(const Char* notificationId)
    {
        ensureData().notificationId.emplace(notificationId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateAlarmRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateAlarmRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateAlarmRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateAlarmRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_WATCH_CONTROL_UPDATEALARMREQUEST_HPP_