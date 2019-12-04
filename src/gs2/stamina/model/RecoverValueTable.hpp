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

#ifndef GS2_STAMINA_MODEL_RECOVERVALUETABLE_HPP_
#define GS2_STAMINA_MODEL_RECOVERVALUETABLE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * スタミナ回復量テーブル
 *
 * @author Game Server Services, Inc.
 *
 */
class RecoverValueTable : public Gs2Object
{
    friend bool operator!=(const RecoverValueTable& lhs, const RecoverValueTable& lhr);

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
        /** 経験値の種類マスター のGRN */
        optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナ回復量テーブル */
        optional<List<Int32>> values;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            recoverValueTableId(data.recoverValueTableId),
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

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "recoverValueTableId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->recoverValueTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "experienceModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->experienceModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "values") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->values.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsInt())
                        {
                            *this->values += json->GetInt();
                        }
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RecoverValueTable() = default;
    RecoverValueTable(const RecoverValueTable& recoverValueTable) = default;
    RecoverValueTable(RecoverValueTable&& recoverValueTable) = default;
    ~RecoverValueTable() = default;

    RecoverValueTable& operator=(const RecoverValueTable& recoverValueTable) = default;
    RecoverValueTable& operator=(RecoverValueTable&& recoverValueTable) = default;

    RecoverValueTable deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RecoverValueTable);
    }

    const RecoverValueTable* operator->() const
    {
        return this;
    }

    RecoverValueTable* operator->()
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
    RecoverValueTable& withRecoverValueTableId(StringHolder recoverValueTableId)
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
    RecoverValueTable& withName(StringHolder name)
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
    RecoverValueTable& withMetadata(StringHolder metadata)
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
    RecoverValueTable& withExperienceModelId(StringHolder experienceModelId)
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
    RecoverValueTable& withValues(List<Int32> values)
    {
        setValues(std::move(values));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const RecoverValueTable& lhs, const RecoverValueTable& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->recoverValueTableId != lhr.m_pData->recoverValueTableId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->experienceModelId != lhr.m_pData->experienceModelId)
        {
            return true;
        }
        if (lhs.m_pData->values != lhr.m_pData->values)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const RecoverValueTable& lhs, const RecoverValueTable& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_STAMINA_MODEL_RECOVERVALUETABLE_HPP_