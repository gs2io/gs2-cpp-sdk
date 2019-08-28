

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

#ifndef GS2_EZ_STAMINA_MODEL_EZSTAMINAMODEL_HPP_
#define GS2_EZ_STAMINA_MODEL_EZSTAMINAMODEL_HPP_

#include <gs2/stamina/model/StaminaModel.hpp>
#include "EzMaxStaminaTable.hpp"


namespace gs2 { namespace ez { namespace stamina {

class EzStaminaModel : public gs2::Gs2Object
{
private:
    /** スタミナの種類名 */
    gs2::optional<StringHolder> m_Name;
    /** スタミナの種類のメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** スタミナを回復する速度(秒) */
    gs2::optional<Int32> m_RecoverIntervalMinutes;
    /** 時間経過後に回復する量 */
    gs2::optional<Int32> m_RecoverValue;
    /** スタミナの最大値の初期値 */
    gs2::optional<Int32> m_InitialCapacity;
    /** 最大値を超えて回復するか */
    gs2::optional<Bool> m_IsOverflow;
    /** 溢れた状況での最大値 */
    gs2::optional<Int32> m_MaxCapacity;
    /** GS2-Experience と連携する際に使用するスタミナ最大値テーブル */
    gs2::optional<EzMaxStaminaTable> m_MaxStaminaTable;

public:
    EzStaminaModel() = default;

    EzStaminaModel(gs2::stamina::StaminaModel staminaModel) :
        m_Name(staminaModel.getName()),
        m_Metadata(staminaModel.getMetadata()),
        m_RecoverIntervalMinutes(staminaModel.getRecoverIntervalMinutes() ? *staminaModel.getRecoverIntervalMinutes() : 0),
        m_RecoverValue(staminaModel.getRecoverValue() ? *staminaModel.getRecoverValue() : 0),
        m_InitialCapacity(staminaModel.getInitialCapacity() ? *staminaModel.getInitialCapacity() : 0),
        m_IsOverflow(staminaModel.getIsOverflow() ? *staminaModel.getIsOverflow() : false),
        m_MaxCapacity(staminaModel.getMaxCapacity() ? *staminaModel.getMaxCapacity() : 0),
        m_MaxStaminaTable(*staminaModel.getMaxStaminaTable())
    {
    }

    gs2::stamina::StaminaModel ToModel() const
    {
        gs2::stamina::StaminaModel staminaModel;
        staminaModel.setName(*m_Name);
        staminaModel.setMetadata(*m_Metadata);
        staminaModel.setRecoverIntervalMinutes(*m_RecoverIntervalMinutes);
        staminaModel.setRecoverValue(*m_RecoverValue);
        staminaModel.setInitialCapacity(*m_InitialCapacity);
        staminaModel.setIsOverflow(*m_IsOverflow);
        staminaModel.setMaxCapacity(*m_MaxCapacity);
        staminaModel.setMaxStaminaTable(m_MaxStaminaTable->ToModel());
        return staminaModel;
    }

    // ========================================
    //   Getters
    // ========================================

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

    Int32 getRecoverIntervalMinutes() const
    {
        return *m_RecoverIntervalMinutes;
    }

    Int32 getRecoverValue() const
    {
        return *m_RecoverValue;
    }

    Int32 getInitialCapacity() const
    {
        return *m_InitialCapacity;
    }

    Bool getIsOverflow() const
    {
        return *m_IsOverflow;
    }

    Int32 getMaxCapacity() const
    {
        return *m_MaxCapacity;
    }

    const EzMaxStaminaTable& getMaxStaminaTable() const
    {
        return *m_MaxStaminaTable;
    }

    EzMaxStaminaTable& getMaxStaminaTable()
    {
        return *m_MaxStaminaTable;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(Char* name)
    {
        m_Name.emplace(name);
    }

    void setMetadata(Char* metadata)
    {
        m_Metadata.emplace(metadata);
    }

    void setRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        m_RecoverIntervalMinutes = recoverIntervalMinutes;
    }

    void setRecoverValue(Int32 recoverValue)
    {
        m_RecoverValue = recoverValue;
    }

    void setInitialCapacity(Int32 initialCapacity)
    {
        m_InitialCapacity = initialCapacity;
    }

    void setIsOverflow(Bool isOverflow)
    {
        m_IsOverflow = isOverflow;
    }

    void setMaxCapacity(Int32 maxCapacity)
    {
        m_MaxCapacity = maxCapacity;
    }

    void setMaxStaminaTable(const EzMaxStaminaTable& maxStaminaTable)
    {
        m_MaxStaminaTable = maxStaminaTable;
    }

    void setMaxStaminaTable(EzMaxStaminaTable&& maxStaminaTable)
    {
        m_MaxStaminaTable = std::move(maxStaminaTable);
    }

    EzStaminaModel& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzStaminaModel& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzStaminaModel& withRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        setRecoverIntervalMinutes(recoverIntervalMinutes);
        return *this;
    }

    EzStaminaModel& withRecoverValue(Int32 recoverValue)
    {
        setRecoverValue(recoverValue);
        return *this;
    }

    EzStaminaModel& withInitialCapacity(Int32 initialCapacity)
    {
        setInitialCapacity(initialCapacity);
        return *this;
    }

    EzStaminaModel& withIsOverflow(Bool isOverflow)
    {
        setIsOverflow(isOverflow);
        return *this;
    }

    EzStaminaModel& withMaxCapacity(Int32 maxCapacity)
    {
        setMaxCapacity(maxCapacity);
        return *this;
    }

    EzStaminaModel& withMaxStaminaTable(const EzMaxStaminaTable& maxStaminaTable)
    {
        setMaxStaminaTable(maxStaminaTable);
        return *this;
    }

    EzStaminaModel& withMaxStaminaTable(EzMaxStaminaTable&& maxStaminaTable)
    {
        setMaxStaminaTable(std::move(maxStaminaTable));
        return *this;
    }
};

}}}

#endif //GS2_EZ_STAMINA_EZSTAMINAMODEL_HPP_