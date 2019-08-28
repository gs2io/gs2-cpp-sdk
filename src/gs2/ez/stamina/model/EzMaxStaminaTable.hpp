

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

#ifndef GS2_EZ_STAMINA_MODEL_EZMAXSTAMINATABLE_HPP_
#define GS2_EZ_STAMINA_MODEL_EZMAXSTAMINATABLE_HPP_

#include <gs2/stamina/model/MaxStaminaTable.hpp>


namespace gs2 { namespace ez { namespace stamina {

class EzMaxStaminaTable : public gs2::Gs2Object
{
private:
    /** 最大スタミナ値テーブル名 */
    gs2::optional<StringHolder> m_Name;
    /** 最大スタミナ値テーブルのメタデータ */
    gs2::optional<StringHolder> m_Metadata;
    /** 経験値の種類マスター のGRN */
    gs2::optional<StringHolder> m_ExperienceModelId;
    /** ランク毎のスタミナの最大値テーブル */
    gs2::optional<List<Int32>> m_Values;

public:
    EzMaxStaminaTable() = default;

    EzMaxStaminaTable(gs2::stamina::MaxStaminaTable maxStaminaTable) :
        m_Name(maxStaminaTable.getName()),
        m_Metadata(maxStaminaTable.getMetadata()),
        m_ExperienceModelId(maxStaminaTable.getExperienceModelId()),
        m_Values(maxStaminaTable.getValues())
    {
    }

    gs2::stamina::MaxStaminaTable ToModel() const
    {
        gs2::stamina::MaxStaminaTable maxStaminaTable;
        maxStaminaTable.setName(*m_Name);
        maxStaminaTable.setMetadata(*m_Metadata);
        maxStaminaTable.setExperienceModelId(*m_ExperienceModelId);
        maxStaminaTable.setValues(*m_Values);
        return maxStaminaTable;
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

    const gs2::StringHolder& getExperienceModelId() const
    {
        return *m_ExperienceModelId;
    }

    gs2::StringHolder& getExperienceModelId()
    {
        return *m_ExperienceModelId;
    }

    const List<Int32>& getValues() const
    {
        return *m_Values;
    }

    List<Int32>& getValues()
    {
        return *m_Values;
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

    void setExperienceModelId(Char* experienceModelId)
    {
        m_ExperienceModelId.emplace(experienceModelId);
    }

    void setValues(const List<Int32>& values)
    {
        m_Values = values;
    }

    void setValues(List<Int32>&& values)
    {
        m_Values = std::move(values);
    }

    EzMaxStaminaTable& withName(Char* name)
    {
        setName(name);
        return *this;
    }

    EzMaxStaminaTable& withMetadata(Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    EzMaxStaminaTable& withExperienceModelId(Char* experienceModelId)
    {
        setExperienceModelId(experienceModelId);
        return *this;
    }

    EzMaxStaminaTable& withValues(const List<Int32>& values)
    {
        setValues(values);
        return *this;
    }

    EzMaxStaminaTable& withValues(List<Int32>&& values)
    {
        setValues(std::move(values));
        return *this;
    }
};

}}}

#endif //GS2_EZ_STAMINA_EZMAXSTAMINATABLE_HPP_