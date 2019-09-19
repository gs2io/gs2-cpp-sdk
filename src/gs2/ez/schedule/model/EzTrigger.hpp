

/*
 * Copyright 2016 Game Server Services, Inc. or its affiliates. All Rights
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

#ifndef GS2_EZ_SCHEDULE_MODEL_EZTRIGGER_HPP_
#define GS2_EZ_SCHEDULE_MODEL_EZTRIGGER_HPP_

#include <gs2/schedule/model/Trigger.hpp>


namespace gs2 { namespace ez { namespace schedule {

class EzTrigger : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** トリガー */
        gs2::optional<StringHolder> triggerId;
        /** トリガーの名前 */
        gs2::optional<StringHolder> name;
        /** 作成日時 */
        gs2::optional<Int64> createdAt;
        /** トリガーの有効期限 */
        gs2::optional<Int64> expiresAt;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            triggerId(data.triggerId),
            name(data.name),
            createdAt(data.createdAt),
            expiresAt(data.expiresAt)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::schedule::Trigger& trigger) :
            triggerId(trigger.getTriggerId()),
            name(trigger.getName()),
            createdAt(trigger.getCreatedAt() ? *trigger.getCreatedAt() : 0),
            expiresAt(trigger.getExpiresAt() ? *trigger.getExpiresAt() : 0)
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzTrigger() = default;
    EzTrigger(const EzTrigger& ezTrigger) = default;
    EzTrigger(EzTrigger&& ezTrigger) = default;
    ~EzTrigger() = default;

    EzTrigger(gs2::schedule::Trigger trigger) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(trigger)
    {}

    EzTrigger& operator=(const EzTrigger& ezTrigger) = default;
    EzTrigger& operator=(EzTrigger&& ezTrigger) = default;

    EzTrigger deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzTrigger);
    }

    gs2::schedule::Trigger ToModel() const
    {
        gs2::schedule::Trigger trigger;
        trigger.setTriggerId(getTriggerId());
        trigger.setName(getName());
        trigger.setCreatedAt(getCreatedAt());
        trigger.setExpiresAt(getExpiresAt());
        return trigger;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getTriggerId() const
    {
        return *ensureData().triggerId;
    }

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    Int64 getCreatedAt() const
    {
        return *ensureData().createdAt;
    }

    Int64 getExpiresAt() const
    {
        return *ensureData().expiresAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setTriggerId(StringHolder triggerId)
    {
        ensureData().triggerId = std::move(triggerId);
    }

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt = createdAt;
    }

    void setExpiresAt(Int64 expiresAt)
    {
        ensureData().expiresAt = expiresAt;
    }

    EzTrigger& withTriggerId(StringHolder triggerId)
    {
        setTriggerId(std::move(triggerId));
        return *this;
    }

    EzTrigger& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzTrigger& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    EzTrigger& withExpiresAt(Int64 expiresAt)
    {
        setExpiresAt(expiresAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_SCHEDULE_EZTRIGGER_HPP_