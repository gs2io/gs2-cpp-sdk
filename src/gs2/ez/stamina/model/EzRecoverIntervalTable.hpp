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

#ifndef GS2_EZ_STAMINA_MODEL_EZRECOVERINTERVALTABLE_HPP_
#define GS2_EZ_STAMINA_MODEL_EZRECOVERINTERVALTABLE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace stamina {

class RecoverIntervalTable;

}

namespace ez { namespace stamina {

class EzRecoverIntervalTable : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** スタミナ回復間隔テーブル名 */
        gs2::optional<StringHolder> name;
        /** スタミナ回復間隔テーブルのメタデータ */
        gs2::optional<StringHolder> metadata;
        /** 経験値の種類マスター のGRN */
        gs2::optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナ回復間隔テーブル */
        gs2::optional<List<Int32>> values;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::stamina::RecoverIntervalTable& recoverIntervalTable);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzRecoverIntervalTable() = default;
    EzRecoverIntervalTable(const EzRecoverIntervalTable& ezRecoverIntervalTable) = default;
    EzRecoverIntervalTable(EzRecoverIntervalTable&& ezRecoverIntervalTable) = default;
    ~EzRecoverIntervalTable() = default;

    EzRecoverIntervalTable(gs2::stamina::RecoverIntervalTable recoverIntervalTable);

    EzRecoverIntervalTable& operator=(const EzRecoverIntervalTable& ezRecoverIntervalTable) = default;
    EzRecoverIntervalTable& operator=(EzRecoverIntervalTable&& ezRecoverIntervalTable) = default;

    EzRecoverIntervalTable deepCopy() const;

    gs2::stamina::RecoverIntervalTable ToModel() const;

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

    EzRecoverIntervalTable& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzRecoverIntervalTable& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzRecoverIntervalTable& withExperienceModelId(StringHolder experienceModelId)
    {
        setExperienceModelId(std::move(experienceModelId));
        return *this;
    }

    EzRecoverIntervalTable& withValues(List<Int32> values)
    {
        setValues(std::move(values));
        return *this;
    }
};

}}}

#endif //GS2_EZ_STAMINA_EZRECOVERINTERVALTABLE_HPP_