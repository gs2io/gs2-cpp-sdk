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

#ifndef GS2_STAMINA_MODEL_RECOVERVALUETABLEMASTER_HPP_
#define GS2_STAMINA_MODEL_RECOVERVALUETABLEMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace stamina {

/**
 * スタミナ回復量テーブルマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class RecoverValueTableMaster : public Gs2Object
{
    friend bool operator!=(const RecoverValueTableMaster& lhs, const RecoverValueTableMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ回復量テーブルマスター */
        optional<StringHolder> recoverValueTableId;
        /** スタミナ回復量テーブル名 */
        optional<StringHolder> name;
        /** スタミナ回復量テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** スタミナ回復量テーブルマスターの説明 */
        optional<StringHolder> description;
        /** 経験値の種類マスター のGRN */
        optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナ回復量テーブル */
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
    RecoverValueTableMaster() = default;
    RecoverValueTableMaster(const RecoverValueTableMaster& recoverValueTableMaster) = default;
    RecoverValueTableMaster(RecoverValueTableMaster&& recoverValueTableMaster) = default;
    ~RecoverValueTableMaster() = default;

    RecoverValueTableMaster& operator=(const RecoverValueTableMaster& recoverValueTableMaster) = default;
    RecoverValueTableMaster& operator=(RecoverValueTableMaster&& recoverValueTableMaster) = default;

    RecoverValueTableMaster deepCopy() const;

    const RecoverValueTableMaster* operator->() const
    {
        return this;
    }

    RecoverValueTableMaster* operator->()
    {
        return this;
    }
    /**
     * スタミナ回復量テーブルマスターを取得
     *
     * @return スタミナ回復量テーブルマスター
     */
    const optional<StringHolder>& getRecoverValueTableId() const
    {
        return ensureData().recoverValueTableId;
    }

    /**
     * スタミナ回復量テーブルマスターを設定
     *
     * @param recoverValueTableId スタミナ回復量テーブルマスター
     */
    void setRecoverValueTableId(StringHolder recoverValueTableId)
    {
        ensureData().recoverValueTableId.emplace(std::move(recoverValueTableId));
    }

    /**
     * スタミナ回復量テーブルマスターを設定
     *
     * @param recoverValueTableId スタミナ回復量テーブルマスター
     */
    RecoverValueTableMaster& withRecoverValueTableId(StringHolder recoverValueTableId)
    {
        setRecoverValueTableId(std::move(recoverValueTableId));
        return *this;
    }

    /**
     * スタミナ回復量テーブル名を取得
     *
     * @return スタミナ回復量テーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタミナ回復量テーブル名を設定
     *
     * @param name スタミナ回復量テーブル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * スタミナ回復量テーブル名を設定
     *
     * @param name スタミナ回復量テーブル名
     */
    RecoverValueTableMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * スタミナ回復量テーブルのメタデータを取得
     *
     * @return スタミナ回復量テーブルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * スタミナ回復量テーブルのメタデータを設定
     *
     * @param metadata スタミナ回復量テーブルのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * スタミナ回復量テーブルのメタデータを設定
     *
     * @param metadata スタミナ回復量テーブルのメタデータ
     */
    RecoverValueTableMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * スタミナ回復量テーブルマスターの説明を取得
     *
     * @return スタミナ回復量テーブルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * スタミナ回復量テーブルマスターの説明を設定
     *
     * @param description スタミナ回復量テーブルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * スタミナ回復量テーブルマスターの説明を設定
     *
     * @param description スタミナ回復量テーブルマスターの説明
     */
    RecoverValueTableMaster& withDescription(StringHolder description)
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
    RecoverValueTableMaster& withExperienceModelId(StringHolder experienceModelId)
    {
        setExperienceModelId(std::move(experienceModelId));
        return *this;
    }

    /**
     * ランク毎のスタミナ回復量テーブルを取得
     *
     * @return ランク毎のスタミナ回復量テーブル
     */
    const optional<List<Int32>>& getValues() const
    {
        return ensureData().values;
    }

    /**
     * ランク毎のスタミナ回復量テーブルを設定
     *
     * @param values ランク毎のスタミナ回復量テーブル
     */
    void setValues(List<Int32> values)
    {
        ensureData().values.emplace(std::move(values));
    }

    /**
     * ランク毎のスタミナ回復量テーブルを設定
     *
     * @param values ランク毎のスタミナ回復量テーブル
     */
    RecoverValueTableMaster& withValues(List<Int32> values)
    {
        setValues(std::move(values));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const RecoverValueTableMaster& lhs, const RecoverValueTableMaster& lhr);

inline bool operator==(const RecoverValueTableMaster& lhs, const RecoverValueTableMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_STAMINA_MODEL_RECOVERVALUETABLEMASTER_HPP_