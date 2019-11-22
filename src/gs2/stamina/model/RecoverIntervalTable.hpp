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

#ifndef GS2_STAMINA_MODEL_RECOVERINTERVALTABLE_HPP_
#define GS2_STAMINA_MODEL_RECOVERINTERVALTABLE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace stamina {

/**
 * スタミナ回復間隔テーブル
 *
 * @author Game Server Services, Inc.
 *
 */
class RecoverIntervalTable : public Gs2Object
{
    friend bool operator!=(const RecoverIntervalTable& lhs, const RecoverIntervalTable& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ回復間隔テーブルマスター */
        optional<StringHolder> recoverIntervalTableId;
        /** スタミナ回復間隔テーブル名 */
        optional<StringHolder> name;
        /** スタミナ回復間隔テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の種類マスター のGRN */
        optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナ回復間隔テーブル */
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
    RecoverIntervalTable() = default;
    RecoverIntervalTable(const RecoverIntervalTable& recoverIntervalTable) = default;
    RecoverIntervalTable(RecoverIntervalTable&& recoverIntervalTable) = default;
    ~RecoverIntervalTable() = default;

    RecoverIntervalTable& operator=(const RecoverIntervalTable& recoverIntervalTable) = default;
    RecoverIntervalTable& operator=(RecoverIntervalTable&& recoverIntervalTable) = default;

    RecoverIntervalTable deepCopy() const;

    const RecoverIntervalTable* operator->() const
    {
        return this;
    }

    RecoverIntervalTable* operator->()
    {
        return this;
    }
    /**
     * スタミナ回復間隔テーブルマスターを取得
     *
     * @return スタミナ回復間隔テーブルマスター
     */
    const optional<StringHolder>& getRecoverIntervalTableId() const
    {
        return ensureData().recoverIntervalTableId;
    }

    /**
     * スタミナ回復間隔テーブルマスターを設定
     *
     * @param recoverIntervalTableId スタミナ回復間隔テーブルマスター
     */
    void setRecoverIntervalTableId(StringHolder recoverIntervalTableId)
    {
        ensureData().recoverIntervalTableId.emplace(std::move(recoverIntervalTableId));
    }

    /**
     * スタミナ回復間隔テーブルマスターを設定
     *
     * @param recoverIntervalTableId スタミナ回復間隔テーブルマスター
     */
    RecoverIntervalTable& withRecoverIntervalTableId(StringHolder recoverIntervalTableId)
    {
        setRecoverIntervalTableId(std::move(recoverIntervalTableId));
        return *this;
    }

    /**
     * スタミナ回復間隔テーブル名を取得
     *
     * @return スタミナ回復間隔テーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタミナ回復間隔テーブル名を設定
     *
     * @param name スタミナ回復間隔テーブル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * スタミナ回復間隔テーブル名を設定
     *
     * @param name スタミナ回復間隔テーブル名
     */
    RecoverIntervalTable& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * スタミナ回復間隔テーブルのメタデータを取得
     *
     * @return スタミナ回復間隔テーブルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * スタミナ回復間隔テーブルのメタデータを設定
     *
     * @param metadata スタミナ回復間隔テーブルのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * スタミナ回復間隔テーブルのメタデータを設定
     *
     * @param metadata スタミナ回復間隔テーブルのメタデータ
     */
    RecoverIntervalTable& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
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
    RecoverIntervalTable& withExperienceModelId(StringHolder experienceModelId)
    {
        setExperienceModelId(std::move(experienceModelId));
        return *this;
    }

    /**
     * ランク毎のスタミナ回復間隔テーブルを取得
     *
     * @return ランク毎のスタミナ回復間隔テーブル
     */
    const optional<List<Int32>>& getValues() const
    {
        return ensureData().values;
    }

    /**
     * ランク毎のスタミナ回復間隔テーブルを設定
     *
     * @param values ランク毎のスタミナ回復間隔テーブル
     */
    void setValues(List<Int32> values)
    {
        ensureData().values.emplace(std::move(values));
    }

    /**
     * ランク毎のスタミナ回復間隔テーブルを設定
     *
     * @param values ランク毎のスタミナ回復間隔テーブル
     */
    RecoverIntervalTable& withValues(List<Int32> values)
    {
        setValues(std::move(values));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const RecoverIntervalTable& lhs, const RecoverIntervalTable& lhr);

inline bool operator==(const RecoverIntervalTable& lhs, const RecoverIntervalTable& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_STAMINA_MODEL_RECOVERINTERVALTABLE_HPP_