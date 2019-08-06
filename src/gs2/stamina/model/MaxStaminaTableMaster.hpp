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
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

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

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            maxStaminaTableId(data.maxStaminaTableId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            experienceModelId(data.experienceModelId),
            values(data.values)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            maxStaminaTableId(std::move(data.maxStaminaTableId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            description(std::move(data.description)),
            experienceModelId(std::move(data.experienceModelId)),
            values(std::move(data.values))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "maxStaminaTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->maxStaminaTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0) {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0) {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "experienceModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->experienceModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "values") == 0) {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->values.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsInt())
                        {
                            detail::addToList(*this->values, json->GetInt());
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
    MaxStaminaTableMaster() :
        m_pData(nullptr)
    {}

    MaxStaminaTableMaster(const MaxStaminaTableMaster& maxStaminaTableMaster) :
        Gs2Object(maxStaminaTableMaster),
        m_pData(maxStaminaTableMaster.m_pData != nullptr ? new Data(*maxStaminaTableMaster.m_pData) : nullptr)
    {}

    MaxStaminaTableMaster(MaxStaminaTableMaster&& maxStaminaTableMaster) :
        Gs2Object(std::move(maxStaminaTableMaster)),
        m_pData(maxStaminaTableMaster.m_pData)
    {
        maxStaminaTableMaster.m_pData = nullptr;
    }

    ~MaxStaminaTableMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    MaxStaminaTableMaster& operator=(const MaxStaminaTableMaster& maxStaminaTableMaster)
    {
        Gs2Object::operator=(maxStaminaTableMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*maxStaminaTableMaster.m_pData);

        return *this;
    }

    MaxStaminaTableMaster& operator=(MaxStaminaTableMaster&& maxStaminaTableMaster)
    {
        Gs2Object::operator=(std::move(maxStaminaTableMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = maxStaminaTableMaster.m_pData;
        maxStaminaTableMaster.m_pData = nullptr;

        return *this;
    }

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
    void setMaxStaminaTableId(const Char* maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(maxStaminaTableId);
    }

    /**
     * スタミナの最大値テーブルマスターを設定
     *
     * @param maxStaminaTableId スタミナの最大値テーブルマスター
     */
    MaxStaminaTableMaster& withMaxStaminaTableId(const Char* maxStaminaTableId)
    {
        setMaxStaminaTableId(maxStaminaTableId);
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
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param name 最大スタミナ値テーブル名
     */
    MaxStaminaTableMaster& withName(const Char* name)
    {
        setName(name);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 最大スタミナ値テーブルのメタデータを設定
     *
     * @param metadata 最大スタミナ値テーブルのメタデータ
     */
    MaxStaminaTableMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スタミナの最大値テーブルマスターの説明を設定
     *
     * @param description スタミナの最大値テーブルマスターの説明
     */
    MaxStaminaTableMaster& withDescription(const Char* description)
    {
        setDescription(description);
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
    void setExperienceModelId(const Char* experienceModelId)
    {
        ensureData().experienceModelId.emplace(experienceModelId);
    }

    /**
     * 経験値の種類マスター のGRNを設定
     *
     * @param experienceModelId 経験値の種類マスター のGRN
     */
    MaxStaminaTableMaster& withExperienceModelId(const Char* experienceModelId)
    {
        setExperienceModelId(experienceModelId);
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
    void setValues(const List<Int32>& values)
    {
        ensureData().values.emplace(values);
    }

    /**
     * ランク毎のスタミナの最大値テーブルを設定
     *
     * @param values ランク毎のスタミナの最大値テーブル
     */
    MaxStaminaTableMaster& withValues(const List<Int32>& values)
    {
        setValues(values);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const MaxStaminaTableMaster& lhs, const MaxStaminaTableMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->maxStaminaTableId != lhr.m_pData->maxStaminaTableId)
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
        if (lhs.m_pData->description != lhr.m_pData->description)
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

inline bool operator==(const MaxStaminaTableMaster& lhs, const MaxStaminaTableMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_STAMINA_MODEL_MAXSTAMINATABLEMASTER_HPP_