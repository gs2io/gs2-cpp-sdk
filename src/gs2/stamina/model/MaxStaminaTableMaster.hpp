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

#ifndef GS2_STAMINA_MODEL_MAXSTAMINATABLEMASTER_HPP_
#define GS2_STAMINA_MODEL_MAXSTAMINATABLEMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace stamina {

/**
 * スタミナの最大値テーブルマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class MaxStaminaTableMaster : public Gs2Object
{
    friend bool operator!=(const MaxStaminaTableMaster& lhs, const MaxStaminaTableMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナの最大値テーブルマスター */
        optional<StringHolder> maxStaminaTableId;
        /** 最大スタミナ値テーブル名 */
        optional<StringHolder> name;
        /** 最大スタミナ値テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** スタミナの最大値テーブルマスターの説明 */
        optional<StringHolder> description;
        /** 経験値の種類マスター のGRN */
        optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナの最大値テーブル */
        optional<List<Int32>> values;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    MaxStaminaTableMaster() = default;
    MaxStaminaTableMaster(const MaxStaminaTableMaster& maxStaminaTableMaster) = default;
    MaxStaminaTableMaster(MaxStaminaTableMaster&& maxStaminaTableMaster) = default;
    ~MaxStaminaTableMaster() = default;

    MaxStaminaTableMaster& operator=(const MaxStaminaTableMaster& maxStaminaTableMaster) = default;
    MaxStaminaTableMaster& operator=(MaxStaminaTableMaster&& maxStaminaTableMaster) = default;

    MaxStaminaTableMaster deepCopy() const;

    const MaxStaminaTableMaster* operator->() const
    {
        return this;
    }

    MaxStaminaTableMaster* operator->()
    {
        return this;
    }
    /**
     * スタミナの最大値テーブルマスターを取得
     *
     * @return スタミナの最大値テーブルマスター
     */
    const optional<StringHolder>& getMaxStaminaTableId() const
    {
        return ensureData().maxStaminaTableId;
    }

    /**
     * スタミナの最大値テーブルマスターを設定
     *
     * @param maxStaminaTableId スタミナの最大値テーブルマスター
     */
    void setMaxStaminaTableId(StringHolder maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(std::move(maxStaminaTableId));
    }

    /**
     * スタミナの最大値テーブルマスターを設定
     *
     * @param maxStaminaTableId スタミナの最大値テーブルマスター
     */
    MaxStaminaTableMaster& withMaxStaminaTableId(StringHolder maxStaminaTableId)
    {
        setMaxStaminaTableId(std::move(maxStaminaTableId));
        return *this;
    }

    /**
     * 最大スタミナ値テーブル名を取得
     *
     * @return 最大スタミナ値テーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param name 最大スタミナ値テーブル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param name 最大スタミナ値テーブル名
     */
    MaxStaminaTableMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 最大スタミナ値テーブルのメタデータを取得
     *
     * @return 最大スタミナ値テーブルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 最大スタミナ値テーブルのメタデータを設定
     *
     * @param metadata 最大スタミナ値テーブルのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 最大スタミナ値テーブルのメタデータを設定
     *
     * @param metadata 最大スタミナ値テーブルのメタデータ
     */
    MaxStaminaTableMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * スタミナの最大値テーブルマスターの説明を取得
     *
     * @return スタミナの最大値テーブルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * スタミナの最大値テーブルマスターの説明を設定
     *
     * @param description スタミナの最大値テーブルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * スタミナの最大値テーブルマスターの説明を設定
     *
     * @param description スタミナの最大値テーブルマスターの説明
     */
    MaxStaminaTableMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * 経験値の種類マスター のGRNを取得
     *
     * @return 経験値の種類マスター のGRN
     */
    const optional<StringHolder>& getExperienceModelId() const
    {
        return ensureData().experienceModelId;
    }

    /**
     * 経験値の種類マスター のGRNを設定
     *
     * @param experienceModelId 経験値の種類マスター のGRN
     */
    void setExperienceModelId(StringHolder experienceModelId)
    {
        ensureData().experienceModelId.emplace(std::move(experienceModelId));
    }

    /**
     * 経験値の種類マスター のGRNを設定
     *
     * @param experienceModelId 経験値の種類マスター のGRN
     */
    MaxStaminaTableMaster& withExperienceModelId(StringHolder experienceModelId)
    {
        setExperienceModelId(std::move(experienceModelId));
        return *this;
    }

    /**
     * ランク毎のスタミナの最大値テーブルを取得
     *
     * @return ランク毎のスタミナの最大値テーブル
     */
    const optional<List<Int32>>& getValues() const
    {
        return ensureData().values;
    }

    /**
     * ランク毎のスタミナの最大値テーブルを設定
     *
     * @param values ランク毎のスタミナの最大値テーブル
     */
    void setValues(List<Int32> values)
    {
        ensureData().values.emplace(std::move(values));
    }

    /**
     * ランク毎のスタミナの最大値テーブルを設定
     *
     * @param values ランク毎のスタミナの最大値テーブル
     */
    MaxStaminaTableMaster& withValues(List<Int32> values)
    {
        setValues(std::move(values));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const MaxStaminaTableMaster& lhs, const MaxStaminaTableMaster& lhr);

inline bool operator==(const MaxStaminaTableMaster& lhs, const MaxStaminaTableMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_STAMINA_MODEL_MAXSTAMINATABLEMASTER_HPP_