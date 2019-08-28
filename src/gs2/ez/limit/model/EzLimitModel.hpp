

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

#ifndef GS2_EZ_LIMIT_MODEL_EZLIMITMODEL_HPP_
#define GS2_EZ_LIMIT_MODEL_EZLIMITMODEL_HPP_

#include <gs2/limit/model/LimitModel.hpp>


namespace gs2 { namespace ez { namespace limit {

class EzLimitModel : public gs2::Gs2Object
{
private:
    /** 回数制限の種類 */
    gs2::optional<StringHolder> m_LimitModelId;
    /** 回数制限の種類名 */
    gs2::optional<StringHolder> m_Name;
    /** 回数制限の種類のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** リセットタイミング */
    gs2::optional<StringHolder> m_ResetType;
    /** リセットをする日にち */
    gs2::optional<Int32> m_ResetDayOfMonth;
    /** リセットする曜日 */
    gs2::optional<StringHolder> m_ResetDayOfWeek;
    /** リセット時刻 */
    gs2::optional<Int32> m_ResetHour;

public:
    EzLimitModel() = default;

    EzLimitModel(gs2::limit::LimitModel limitModel) :
        m_LimitModelId(limitModel.getLimitModelId()),
        m_Name(limitModel.getName()),
        m_Metadata(limitModel.getMetadata()),
        m_ResetType(limitModel.getResetType()),
        m_ResetDayOfMonth(limitModel.getResetDayOfMonth() ? *limitModel.getResetDayOfMonth() : 0),
        m_ResetDayOfWeek(limitModel.getResetDayOfWeek()),
        m_ResetHour(limitModel.getResetHour() ? *limitModel.getResetHour() : 0)
    {
    }

    gs2::limit::LimitModel ToModel() const
    {
        gs2::limit::LimitModel limitModel;
        limitModel.setLimitModelId(*m_LimitModelId);
        limitModel.setName(*m_Name);
        limitModel.setMetadata(*m_Metadata);
        limitModel.setResetType(*m_ResetType);
        limitModel.setResetDayOfMonth(*m_ResetDayOfMonth);
        limitModel.setResetDayOfWeek(*m_ResetDayOfWeek);
        limitModel.setResetHour(*m_ResetHour);
        return limitModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const gs2::StringHolder& getLimitModelId() const
    {
        return *m_LimitModelId;
    }

    gs2::StringHolder& getLimitModelId()
    {
        return *m_LimitModelId;
    }

    const gs2::StringHolder& getName() const
    {
        return *m_Name;
    }

    gs2::StringHolder& getName()
    {
        return *m_Name;
    }

    const gs2::StringHolder& getMetadata() const
    {
        return *m_Metadata;
    }

    gs2::StringHolder& getMetadata()
    {
        return *m_Metadata;
    }

    const gs2::StringHolder& getResetType() const
    {
        return *m_ResetType;
    }

    gs2::StringHolder& getResetType()
    {
        return *m_ResetType;
    }

    Int32 getResetDayOfMonth() const
    {
        return *m_ResetDayOfMonth;
    }

    const gs2::StringHolder& getResetDayOfWeek() const
    {
        return *m_ResetDayOfWeek;
    }

    gs2::StringHolder& getResetDayOfWeek()
    {
        return *m_ResetDayOfWeek;
    }

    Int32 getResetHour() const
    {
        return *m_ResetHour;
    }

    // ========================================
    //   Setters
    // ========================================

    void setLimitModelId(Char* limitModelId)
    {
        m_LimitModelId.emplace(limitModelId);
    }

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setResetType(Char* resetType)
    {
        m_ResetType.emplace(resetType);
    }

    void setResetDayOfMonth(Int32 resetDayOfMonth)
    {
        m_ResetDayOfMonth = resetDayOfMonth;
    }

    void setResetDayOfWeek(Char* resetDayOfWeek)
    {
        m_ResetDayOfWeek.emplace(resetDayOfWeek);
    }

    void setResetHour(Int32 resetHour)
    {
        m_ResetHour = resetHour;
    }

    EzLimitModel& withLimitModelId(Char* limitModelId)
    {
        setLimitModelId(limitModelId);
        return *this;
    }

    EzLimitModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzLimitModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzLimitModel& withResetType(Char* resetType)
    {
        setResetType(resetType);
        return *this;
    }

    EzLimitModel& withResetDayOfMonth(Int32 resetDayOfMonth)
    {
        setResetDayOfMonth(resetDayOfMonth);
        return *this;
    }

    EzLimitModel& withResetDayOfWeek(Char* resetDayOfWeek)
    {
        setResetDayOfWeek(resetDayOfWeek);
        return *this;
    }

    EzLimitModel& withResetHour(Int32 resetHour)
    {
        setResetHour(resetHour);
        return *this;
    }
};

}}}

#endif //GS2_EZ_LIMIT_EZLIMITMODEL_HPP_