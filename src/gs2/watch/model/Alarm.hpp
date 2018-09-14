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

#ifndef GS2_WATCH_MODEL_ALARM_HPP_
#define GS2_WATCH_MODEL_ALARM_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace watch {

/**
 * アラーム
 *
 * @author Game Server Services, Inc.
 *
 */
class Alarm : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** アラームGRN */
        optional<StringHolder> alarmId;
        /** オーナーID */
        optional<StringHolder> ownerId;
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
        /** 現在の状態 */
        optional<StringHolder> status;
        /** 作成日時(エポック秒) */
        optional<Int32> createAt;
        /** 最終更新日時(エポック秒) */
        optional<Int32> updateAt;
        /** 最終ステータス変化日時(エポック秒) */
        optional<Int32> lastStatusChangeAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            alarmId(data.alarmId),
            ownerId(data.ownerId),
            name(data.name),
            description(data.description),
            service(data.service),
            serviceId(data.serviceId),
            operation(data.operation),
            expression(data.expression),
            threshold(data.threshold),
            notificationId(data.notificationId),
            status(data.status),
            createAt(data.createAt),
            updateAt(data.updateAt),
            lastStatusChangeAt(data.lastStatusChangeAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            alarmId(std::move(data.alarmId)),
            ownerId(std::move(data.ownerId)),
            name(std::move(data.name)),
            description(std::move(data.description)),
            service(std::move(data.service)),
            serviceId(std::move(data.serviceId)),
            operation(std::move(data.operation)),
            expression(std::move(data.expression)),
            threshold(std::move(data.threshold)),
            notificationId(std::move(data.notificationId)),
            status(std::move(data.status)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt)),
            lastStatusChangeAt(std::move(data.lastStatusChangeAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "alarmId") == 0) {
                if (jsonValue.IsString())
                {
                    this->alarmId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "service") == 0) {
                if (jsonValue.IsString())
                {
                    this->service.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "serviceId") == 0) {
                if (jsonValue.IsString())
                {
                    this->serviceId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "operation") == 0) {
                if (jsonValue.IsString())
                {
                    this->operation.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "expression") == 0) {
                if (jsonValue.IsString())
                {
                    this->expression.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "threshold") == 0) {
                if (jsonValue.IsDouble())
                {
                    this->threshold = jsonValue.GetDouble();
                }
            }
            else if (std::strcmp(name, "notificationId") == 0) {
                if (jsonValue.IsString())
                {
                    this->notificationId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "status") == 0) {
                if (jsonValue.IsString())
                {
                    this->status.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "lastStatusChangeAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->lastStatusChangeAt = jsonValue.GetInt();
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
    Alarm() :
        m_pData(nullptr)
    {}

    Alarm(const Alarm& alarm) :
        Gs2Object(alarm),
        m_pData(alarm.m_pData != nullptr ? new Data(*alarm.m_pData) : nullptr)
    {}

    Alarm(Alarm&& alarm) :
        Gs2Object(std::move(alarm)),
        m_pData(alarm.m_pData)
    {
        alarm.m_pData = nullptr;
    }

    ~Alarm()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Alarm& operator=(const Alarm& alarm)
    {
        Gs2Object::operator=(alarm);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*alarm.m_pData);

        return *this;
    }

    Alarm& operator=(Alarm&& alarm)
    {
        Gs2Object::operator=(std::move(alarm));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = alarm.m_pData;
        alarm.m_pData = nullptr;

        return *this;
    }

    const Alarm* operator->() const
    {
        return this;
    }

    Alarm* operator->()
    {
        return this;
    }


    /**
     * アラームGRNを取得
     *
     * @return アラームGRN
     */
    const optional<StringHolder>& getAlarmId() const
    {
        return ensureData().alarmId;
    }

    /**
     * アラームGRNを設定
     *
     * @param alarmId アラームGRN
     */
    void setAlarmId(const Char* alarmId)
    {
        ensureData().alarmId.emplace(alarmId);
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
     * 現在の状態を取得
     *
     * @return 現在の状態
     */
    const optional<StringHolder>& getStatus() const
    {
        return ensureData().status;
    }

    /**
     * 現在の状態を設定
     *
     * @param status 現在の状態
     */
    void setStatus(const Char* status)
    {
        ensureData().status.emplace(status);
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

    /**
     * 最終ステータス変化日時(エポック秒)を取得
     *
     * @return 最終ステータス変化日時(エポック秒)
     */
    const optional<Int32>& getLastStatusChangeAt() const
    {
        return ensureData().lastStatusChangeAt;
    }

    /**
     * 最終ステータス変化日時(エポック秒)を設定
     *
     * @param lastStatusChangeAt 最終ステータス変化日時(エポック秒)
     */
    void setLastStatusChangeAt(Int32 lastStatusChangeAt)
    {
        ensureData().lastStatusChangeAt.emplace(lastStatusChangeAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_WATCH_MODEL_ALARM_HPP_