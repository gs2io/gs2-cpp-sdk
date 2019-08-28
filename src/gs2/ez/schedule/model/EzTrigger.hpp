

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
    /** トリガー */
    gs2::optional<StringHolder> m_TriggerId;
    /** トリガーの名前 */
    gs2::optional<StringHolder> m_Name;
    /** 作成日時 */
    gs2::optional<Int64> m_CreatedAt;
    /** トリガーの有効期限 */
    gs2::optional<Int64> m_ExpiresAt;

public:
    EzTrigger() = default;

    EzTrigger(gs2::schedule::Trigger trigger) :
        m_TriggerId(trigger.getTriggerId()),
        m_Name(trigger.getName()),
        m_CreatedAt(trigger.getCreatedAt() ? *trigger.getCreatedAt() : 0),
        m_ExpiresAt(trigger.getExpiresAt() ? *trigger.getExpiresAt() : 0)
    {
    }

    gs2::schedule::Trigger ToModel() const
    {
        gs2::schedule::Trigger trigger;
        trigger.setTriggerId(*m_TriggerId);
        trigger.setName(*m_Name);
        trigger.setCreatedAt(*m_CreatedAt);
        trigger.setExpiresAt(*m_ExpiresAt);
        return trigger;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getTriggerId() const
    {
        return *m_TriggerId;
    }

    gs2::StringHolder& getTriggerId()
    {
        return *m_TriggerId;
    }

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    Int64 getCreatedAt() const
    {
        return *m_CreatedAt;
    }

    Int64 getExpiresAt() const
    {
        return *m_ExpiresAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setTriggerId(Char* triggerId)
    {
        m_TriggerId.emplace(triggerId);
    }

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setCreatedAt(Int64 createdAt)
    {
        m_CreatedAt = createdAt;
    }

    void setExpiresAt(Int64 expiresAt)
    {
        m_ExpiresAt = expiresAt;
    }

    EzTrigger& withTriggerId(Char* triggerId)
    {
        setTriggerId(triggerId);
        return *this;
    }

    EzTrigger& withName(Char* name)
    {
        setName(name);
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