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

#ifndef GS2_STAMINA_MODEL_MAXSTAMINATABLE_HPP_
#define GS2_STAMINA_MODEL_MAXSTAMINATABLE_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * スタミナ最大値テーブル
 *
 * @author Game Server Services, Inc.
 *
 */
class MaxStaminaTable : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナ最大値テーブル のGRN */
        optional<StringHolder> maxStaminaTableId;
        /** 最大スタミナ値テーブル名 */
        optional<StringHolder> name;
        /** 最大スタミナ値テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の種類 のGRN */
        optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナの最大値テーブル */
        optional<List<Int32>> values;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            maxStaminaTableId(data.maxStaminaTableId),
            name(data.name),
            metadata(data.metadata),
            experienceModelId(data.experienceModelId),
            values(data.values)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            maxStaminaTableId(std::move(data.maxStaminaTableId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            experienceModelId(std::move(data.experienceModelId)),
            values(std::move(data.values))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "maxStaminaTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->maxStaminaTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "experienceModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "values") == 0) {
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

    Data* m_pData;

    Data& ensureData() {
        if (m_pData == nullptr) {
            m_pData = new Data();
        }
        return *m_pData;
    }

    const Data& ensureData() const {
        if (m_pData == nullptr) {
            *const_cast<Data**>(&m_pData) = new Data();
        }
        return *m_pData;
    }

public:
    MaxStaminaTable() :
        m_pData(nullptr)
    {}

    MaxStaminaTable(const MaxStaminaTable& maxStaminaTable) :
        Gs2Object(maxStaminaTable),
        m_pData(maxStaminaTable.m_pData != nullptr ? new Data(*maxStaminaTable.m_pData) : nullptr)
    {}

    MaxStaminaTable(MaxStaminaTable&& maxStaminaTable) :
        Gs2Object(std::move(maxStaminaTable)),
        m_pData(maxStaminaTable.m_pData)
    {
        maxStaminaTable.m_pData = nullptr;
    }

    ~MaxStaminaTable()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    MaxStaminaTable& operator=(const MaxStaminaTable& maxStaminaTable)
    {
        Gs2Object::operator=(maxStaminaTable);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*maxStaminaTable.m_pData);

        return *this;
    }

    MaxStaminaTable& operator=(MaxStaminaTable&& maxStaminaTable)
    {
        Gs2Object::operator=(std::move(maxStaminaTable));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = maxStaminaTable.m_pData;
        maxStaminaTable.m_pData = nullptr;

        return *this;
    }

    const MaxStaminaTable* operator->() const
    {
        return this;
    }

    MaxStaminaTable* operator->()
    {
        return this;
    }
    /**
     * スタミナ最大値テーブル のGRNを取得
     *
     * @return スタミナ最大値テーブル のGRN
     */
    const optional<StringHolder>& getMaxStaminaTableId() const
    {
        return ensureData().maxStaminaTableId;
    }

    /**
     * スタミナ最大値テーブル のGRNを設定
     *
     * @param maxStaminaTableId スタミナ最大値テーブル のGRN
     */
    void setMaxStaminaTableId(const Char* maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(maxStaminaTableId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 経験値の種類 のGRNを取得
     *
     * @return 経験値の種類 のGRN
     */
    const optional<StringHolder>& getExperienceModelId() const
    {
        return ensureData().experienceModelId;
    }

    /**
     * 経験値の種類 のGRNを設定
     *
     * @param experienceModelId 経験値の種類 のGRN
     */
    void setExperienceModelId(const Char* experienceModelId)
    {
        ensureData().experienceModelId.emplace(experienceModelId);
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
    void setValues(const List<Int32>& values)
    {
        ensureData().values.emplace(values);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_MODEL_MAXSTAMINATABLE_HPP_