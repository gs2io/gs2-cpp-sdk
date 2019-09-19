

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
    class Data : public gs2::Gs2Object
    {
    public:
        /** 最大スタミナ値テーブル名 */
        gs2::optional<StringHolder> name;
        /** 最大スタミナ値テーブルのメタデータ */
        gs2::optional<StringHolder> metadata;
        /** 経験値の種類マスター のGRN */
        gs2::optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナの最大値テーブル */
        gs2::optional<List<Int32>> values;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata),
            experienceModelId(data.experienceModelId)
        {
            if (data.values)
            {
                values = data.values->deepCopy();
            }
        }

        Data(Data&& data) = default;

        Data(const gs2::stamina::MaxStaminaTable& maxStaminaTable) :
            name(maxStaminaTable.getName()),
            metadata(maxStaminaTable.getMetadata()),
            experienceModelId(maxStaminaTable.getExperienceModelId()),
            values(maxStaminaTable.getValues())
        {
        }

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzMaxStaminaTable() = default;
    EzMaxStaminaTable(const EzMaxStaminaTable& ezMaxStaminaTable) = default;
    EzMaxStaminaTable(EzMaxStaminaTable&& ezMaxStaminaTable) = default;
    ~EzMaxStaminaTable() = default;

    EzMaxStaminaTable(gs2::stamina::MaxStaminaTable maxStaminaTable) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(maxStaminaTable)
    {}

    EzMaxStaminaTable& operator=(const EzMaxStaminaTable& ezMaxStaminaTable) = default;
    EzMaxStaminaTable& operator=(EzMaxStaminaTable&& ezMaxStaminaTable) = default;

    EzMaxStaminaTable deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMaxStaminaTable);
    }

    gs2::stamina::MaxStaminaTable ToModel() const
    {
        gs2::stamina::MaxStaminaTable maxStaminaTable;
        maxStaminaTable.setName(getName());
        maxStaminaTable.setMetadata(getMetadata());
        maxStaminaTable.setExperienceModelId(getExperienceModelId());
        maxStaminaTable.setValues(getValues());
        return maxStaminaTable;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
    }

    const StringHolder& getExperienceModelId() const
    {
        return *ensureData().experienceModelId;
    }

    const List<Int32>& getValues() const
    {
        return *ensureData().values;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setExperienceModelId(StringHolder experienceModelId)
    {
        ensureData().experienceModelId = std::move(experienceModelId);
    }

    void setValues(List<Int32> values)
    {
        ensureData().values = std::move(values);
    }

    EzMaxStaminaTable& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzMaxStaminaTable& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzMaxStaminaTable& withExperienceModelId(StringHolder experienceModelId)
    {
        setExperienceModelId(std::move(experienceModelId));
        return *this;
    }

    EzMaxStaminaTable& withValues(List<Int32> values)
    {
        setValues(std::move(values));
        return *this;
    }
};

}}}

#endif //GS2_EZ_STAMINA_EZMAXSTAMINATABLE_HPP_