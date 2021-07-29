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

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "EzMaxStaminaTable.hpp"
#include "EzRecoverIntervalTable.hpp"
#include "EzRecoverValueTable.hpp"
#include <memory>


namespace gs2 {

namespace stamina {

class StaminaModel;

}

namespace ez { namespace stamina {

class EzStaminaModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スタミナの種類名 */
        StringHolder name;
        /** スタミナの種類のメタデータ */
        StringHolder metadata;
        /** スタミナを回復する速度(分) */
        Int32 recoverIntervalMinutes;
        /** 時間経過後に回復する量 */
        Int32 recoverValue;
        /** スタミナの最大値の初期値 */
        Int32 initialCapacity;
        /** 最大値を超えて回復するか */
        Bool isOverflow;
        /** 溢れた状況での最大値 */
        Int32 maxCapacity;
        /** GS2-Experience と連携する際に使用するスタミナ最大値テーブル */
        EzMaxStaminaTable maxStaminaTable;
        /** GS2-Experience と連携する際に使用する回復間隔テーブル */
        EzRecoverIntervalTable recoverIntervalTable;
        /** GS2-Experience と連携する際に使用する回復量テーブル */
        EzRecoverValueTable recoverValueTable;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::stamina::StaminaModel& staminaModel);
        Data(const gs2::optional<gs2::stamina::StaminaModel>& staminaModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzStaminaModel() = default;
    EzStaminaModel(const EzStaminaModel& ezStaminaModel) = default;
    EzStaminaModel(EzStaminaModel&& ezStaminaModel) = default;
    ~EzStaminaModel() = default;

    EzStaminaModel(gs2::stamina::StaminaModel staminaModel);
    EzStaminaModel(gs2::optional<gs2::stamina::StaminaModel> staminaModel);

    EzStaminaModel& operator=(const EzStaminaModel& ezStaminaModel) = default;
    EzStaminaModel& operator=(EzStaminaModel&& ezStaminaModel) = default;

    EzStaminaModel deepCopy() const;

    gs2::stamina::StaminaModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return ensureData().metadata;
    }

    Int32 getRecoverIntervalMinutes() const
    {
        return ensureData().recoverIntervalMinutes;
    }

    Int32 getRecoverValue() const
    {
        return ensureData().recoverValue;
    }

    Int32 getInitialCapacity() const
    {
        return ensureData().initialCapacity;
    }

    Bool getIsOverflow() const
    {
        return ensureData().isOverflow;
    }

    Int32 getMaxCapacity() const
    {
        return ensureData().maxCapacity;
    }

    const EzMaxStaminaTable& getMaxStaminaTable() const
    {
        return ensureData().maxStaminaTable;
    }

    const EzRecoverIntervalTable& getRecoverIntervalTable() const
    {
        return ensureData().recoverIntervalTable;
    }

    const EzRecoverValueTable& getRecoverValueTable() const
    {
        return ensureData().recoverValueTable;
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

    void setRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        ensureData().recoverIntervalMinutes = recoverIntervalMinutes;
    }

    void setRecoverValue(Int32 recoverValue)
    {
        ensureData().recoverValue = recoverValue;
    }

    void setInitialCapacity(Int32 initialCapacity)
    {
        ensureData().initialCapacity = initialCapacity;
    }

    void setIsOverflow(Bool isOverflow)
    {
        ensureData().isOverflow = isOverflow;
    }

    void setMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity = maxCapacity;
    }

    void setMaxStaminaTable(EzMaxStaminaTable maxStaminaTable)
    {
        ensureData().maxStaminaTable = std::move(maxStaminaTable);
    }

    void setRecoverIntervalTable(EzRecoverIntervalTable recoverIntervalTable)
    {
        ensureData().recoverIntervalTable = std::move(recoverIntervalTable);
    }

    void setRecoverValueTable(EzRecoverValueTable recoverValueTable)
    {
        ensureData().recoverValueTable = std::move(recoverValueTable);
    }

    EzStaminaModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzStaminaModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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

    EzStaminaModel& withMaxStaminaTable(EzMaxStaminaTable maxStaminaTable)
    {
        setMaxStaminaTable(std::move(maxStaminaTable));
        return *this;
    }

    EzStaminaModel& withRecoverIntervalTable(EzRecoverIntervalTable recoverIntervalTable)
    {
        setRecoverIntervalTable(std::move(recoverIntervalTable));
        return *this;
    }

    EzStaminaModel& withRecoverValueTable(EzRecoverValueTable recoverValueTable)
    {
        setRecoverValueTable(std::move(recoverValueTable));
        return *this;
    }
};

}}}

#endif //GS2_EZ_STAMINA_EZSTAMINAMODEL_HPP_