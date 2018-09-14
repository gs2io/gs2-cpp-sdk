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

#ifndef GS2_WATCH_CONTROL_CREATEALARMREQUEST_HPP_
#define GS2_WATCH_CONTROL_CREATEALARMREQUEST_HPP_

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
class CreateAlarmRequest : public Gs2BasicRequest, public Gs2Watch
{
public:
    constexpr static const Char* const FUNCTION = "CreateAlarm";

private:
    class Data : public Gs2Object
    {
    public:
        /** 名前 */
        optional<StringHolder> name;
        /** 説明文 */
        optional<StringHolder> description;
        /** サービス名 */
        optional<StringHolder> service;
        /** リソースGRN */
        optional<StringHolder> serviceId;
        /** 操作名 */
        optional<StringHolder> operation;
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
            name(data.name),
            description(data.description),
            service(data.service),
            serviceId(data.serviceId),
            operation(data.operation),
            expression(data.expression),
            threshold(data.threshold),
            notificationId(data.notificationId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            service(std::move(data.service)),
            serviceId(std::move(data.serviceId)),
            operation(std::move(data.operation)),
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
    CreateAlarmRequest() :
        m_pData(nullptr)
    {}

    CreateAlarmRequest(const CreateAlarmRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Watch(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateAlarmRequest(CreateAlarmRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Watch(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateAlarmRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateAlarmRequest& operator=(const CreateAlarmRequest& createAlarmRequest)
    {
        Gs2BasicRequest::operator=(createAlarmRequest);
        Gs2Watch::operator=(createAlarmRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createAlarmRequest.m_pData);

        return *this;
    }

    CreateAlarmRequest& operator=(CreateAlarmRequest&& createAlarmRequest)
    {
        Gs2BasicRequest::operator=(std::move(createAlarmRequest));
        Gs2Watch::operator=(std::move(createAlarmRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createAlarmRequest.m_pData;
        createAlarmRequest.m_pData = nullptr;

        return *this;
    }

    const CreateAlarmRequest* operator->() const
    {
        return this;
    }

    CreateAlarmRequest* operator->()
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
    CreateAlarmRequest& withName(const Char* name)
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
    CreateAlarmRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
        return *this;
    }

    /**
     * サービス名を取得
     *
     * @return サービス名
     */
    const optional<StringHolder>& getService() const
    {
        return ensureData().service;
    }

    /**
     * サービス名を設定
     *
     * @param service サービス名
     */
    void setService(const Char* service)
    {
        ensureData().service.emplace(service);
    }

    /**
     * サービス名を設定
     *
     * @param service サービス名
     */
    CreateAlarmRequest& withService(const Char* service)
    {
        ensureData().service.emplace(service);
        return *this;
    }

    /**
     * リソースGRNを取得
     *
     * @return リソースGRN
     */
    const optional<StringHolder>& getServiceId() const
    {
        return ensureData().serviceId;
    }

    /**
     * リソースGRNを設定
     *
     * @param serviceId リソースGRN
     */
    void setServiceId(const Char* serviceId)
    {
        ensureData().serviceId.emplace(serviceId);
    }

    /**
     * リソースGRNを設定
     *
     * @param serviceId リソースGRN
     */
    CreateAlarmRequest& withServiceId(const Char* serviceId)
    {
        ensureData().serviceId.emplace(serviceId);
        return *this;
    }

    /**
     * 操作名を取得
     *
     * @return 操作名
     */
    const optional<StringHolder>& getOperation() const
    {
        return ensureData().operation;
    }

    /**
     * 操作名を設定
     *
     * @param operation 操作名
     */
    void setOperation(const Char* operation)
    {
        ensureData().operation.emplace(operation);
    }

    /**
     * 操作名を設定
     *
     * @param operation 操作名
     */
    CreateAlarmRequest& withOperation(const Char* operation)
    {
        ensureData().operation.emplace(operation);
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
    CreateAlarmRequest& withExpression(const Char* expression)
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
    CreateAlarmRequest& withThreshold(Double threshold)
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
    CreateAlarmRequest& withNotificationId(const Char* notificationId)
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
    CreateAlarmRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateAlarmRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateAlarmRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateAlarmRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_WATCH_CONTROL_CREATEALARMREQUEST_HPP_