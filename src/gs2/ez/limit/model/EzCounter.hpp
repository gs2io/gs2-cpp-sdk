

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

#ifndef GS2_EZ_LIMIT_MODEL_EZCOUNTER_HPP_
#define GS2_EZ_LIMIT_MODEL_EZCOUNTER_HPP_

#include <gs2/limit/model/Counter.hpp>


namespace gs2 { namespace ez { namespace limit {

class EzCounter : public gs2::Gs2Object
{
private:
    /** カウンター */
    gs2::optional<StringHolder> m_CounterId;
    /** カウンターの名前 */
    gs2::optional<StringHolder> m_Name;
    /** カウント値 */
    gs2::optional<Int32> m_Count;
    /** 作成日時 */
    gs2::optional<Int64> m_CreatedAt;
    /** 最終更新日時 */
    gs2::optional<Int64> m_UpdatedAt;

public:
    EzCounter() = default;

    EzCounter(gs2::limit::Counter counter) :
        m_CounterId(counter.getCounterId()),
        m_Name(counter.getName()),
        m_Count(counter.getCount() ? *counter.getCount() : 0),
        m_CreatedAt(counter.getCreatedAt() ? *counter.getCreatedAt() : 0),
        m_UpdatedAt(counter.getUpdatedAt() ? *counter.getUpdatedAt() : 0)
    {
    }

    gs2::limit::Counter ToModel() const
    {
        gs2::limit::Counter counter;
        counter.setCounterId(*m_CounterId);
        counter.setName(*m_Name);
        counter.setCount(*m_Count);
        counter.setCreatedAt(*m_CreatedAt);
        counter.setUpdatedAt(*m_UpdatedAt);
        return counter;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getCounterId() const
    {
        return *m_CounterId;
    }

    gs2::StringHolder& getCounterId()
    {
        return *m_CounterId;
    }

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    Int32 getCount() const
    {
        return *m_Count;
    }

    Int64 getCreatedAt() const
    {
        return *m_CreatedAt;
    }

    Int64 getUpdatedAt() const
    {
        return *m_UpdatedAt;
    }

    // ========================================
    //   Setters
    // ========================================

    void setCounterId(Char* counterId)
    {
        m_CounterId.emplace(counterId);
    }

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setCount(Int32 count)
    {
        m_Count = count;
    }

    void setCreatedAt(Int64 createdAt)
    {
        m_CreatedAt = createdAt;
    }

    void setUpdatedAt(Int64 updatedAt)
    {
        m_UpdatedAt = updatedAt;
    }

    EzCounter& withCounterId(Char* counterId)
    {
        setCounterId(counterId);
        return *this;
    }

    EzCounter& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzCounter& withCount(Int32 count)
    {
        setCount(count);
        return *this;
    }

    EzCounter& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    EzCounter& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }
};

}}}

#endif //GS2_EZ_LIMIT_EZCOUNTER_HPP_