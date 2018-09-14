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

#ifndef GS2_SCHEDULE_MODEL_TRIGGER_HPP_
#define GS2_SCHEDULE_MODEL_TRIGGER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace schedule {

/**
 * トリガー
 *
 * @author Game Server Services, Inc.
 *
 */
class Trigger : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** ユーザID */
        optional<StringHolder> userId;
        /** トリガーID */
        optional<StringHolder> triggerName;
        /** トリガーを引いた時間(エポック秒) */
        optional<Int32> triggerAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            userId(data.userId),
            triggerName(data.triggerName),
            triggerAt(data.triggerAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            userId(std::move(data.userId)),
            triggerName(std::move(data.triggerName)),
            triggerAt(std::move(data.triggerAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "userId") == 0) {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "triggerName") == 0) {
                if (jsonValue.IsString())
                {
                    this->triggerName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "triggerAt") == 0) {
                if (jsonValue.IsInt())
                {
                    this->triggerAt = jsonValue.GetInt();
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
    Trigger() :
        m_pData(nullptr)
    {}

    Trigger(const Trigger& trigger) :
        Gs2Object(trigger),
        m_pData(trigger.m_pData != nullptr ? new Data(*trigger.m_pData) : nullptr)
    {}

    Trigger(Trigger&& trigger) :
        Gs2Object(std::move(trigger)),
        m_pData(trigger.m_pData)
    {
        trigger.m_pData = nullptr;
    }

    ~Trigger()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    Trigger& operator=(const Trigger& trigger)
    {
        Gs2Object::operator=(trigger);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*trigger.m_pData);

        return *this;
    }

    Trigger& operator=(Trigger&& trigger)
    {
        Gs2Object::operator=(std::move(trigger));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = trigger.m_pData;
        trigger.m_pData = nullptr;

        return *this;
    }

    const Trigger* operator->() const
    {
        return this;
    }

    Trigger* operator->()
    {
        return this;
    }


    /**
     * ユーザIDを取得
     *
     * @return ユーザID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザIDを設定
     *
     * @param userId ユーザID
     */
    void setUserId(const Char* userId)
    {
        ensureData().userId.emplace(userId);
    }

    /**
     * トリガーIDを取得
     *
     * @return トリガーID
     */
    const optional<StringHolder>& getTriggerName() const
    {
        return ensureData().triggerName;
    }

    /**
     * トリガーIDを設定
     *
     * @param triggerName トリガーID
     */
    void setTriggerName(const Char* triggerName)
    {
        ensureData().triggerName.emplace(triggerName);
    }

    /**
     * トリガーを引いた時間(エポック秒)を取得
     *
     * @return トリガーを引いた時間(エポック秒)
     */
    const optional<Int32>& getTriggerAt() const
    {
        return ensureData().triggerAt;
    }

    /**
     * トリガーを引いた時間(エポック秒)を設定
     *
     * @param triggerAt トリガーを引いた時間(エポック秒)
     */
    void setTriggerAt(Int32 triggerAt)
    {
        ensureData().triggerAt.emplace(triggerAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_SCHEDULE_MODEL_TRIGGER_HPP_