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

#ifndef GS2_STAMINA_MODEL_STAMINAMODELMASTER_HPP_
#define GS2_STAMINA_MODEL_STAMINAMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * スタミナモデルマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class StaminaModelMaster : public Gs2Object
{
    friend bool operator!=(const StaminaModelMaster& lhs, const StaminaModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナモデルマスター */
        optional<StringHolder> staminaModelId;
        /** スタミナの種類名 */
        optional<StringHolder> name;
        /** スタミナの種類のメタデータ */
        optional<StringHolder> metadata;
        /** スタミナモデルマスターの説明 */
        optional<StringHolder> description;
        /** スタミナを回復する速度(分) */
        optional<Int32> recoverIntervalMinutes;
        /** 時間経過後に回復する量 */
        optional<Int32> recoverValue;
        /** スタミナの最大値の初期値 */
        optional<Int32> initialCapacity;
        /** 最大値を超えて回復するか */
        optional<Bool> isOverflow;
        /** 溢れた状況での最大値 */
        optional<Int32> maxCapacity;
        /** GS2-Experience のランクによって最大スタミナ値を決定するスタミナの最大値テーブルマスター のGRN */
        optional<StringHolder> maxStaminaTableId;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            staminaModelId(data.staminaModelId),
            name(data.name),
            metadata(data.metadata),
            description(data.description),
            recoverIntervalMinutes(data.recoverIntervalMinutes),
            recoverValue(data.recoverValue),
            initialCapacity(data.initialCapacity),
            isOverflow(data.isOverflow),
            maxCapacity(data.maxCapacity),
            maxStaminaTableId(data.maxStaminaTableId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            staminaModelId(std::move(data.staminaModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            description(std::move(data.description)),
            recoverIntervalMinutes(std::move(data.recoverIntervalMinutes)),
            recoverValue(std::move(data.recoverValue)),
            initialCapacity(std::move(data.initialCapacity)),
            isOverflow(std::move(data.isOverflow)),
            maxCapacity(std::move(data.maxCapacity)),
            maxStaminaTableId(std::move(data.maxStaminaTableId)),
            createdAt(std::move(data.createdAt)),
            updatedAt(std::move(data.updatedAt))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "staminaModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->staminaModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name_, "recoverIntervalMinutes") == 0) {
                if (jsonValue.IsInt())
                {
                    this->recoverIntervalMinutes = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "recoverValue") == 0) {
                if (jsonValue.IsInt())
                {
                    this->recoverValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "initialCapacity") == 0) {
                if (jsonValue.IsInt())
                {
                    this->initialCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "isOverflow") == 0) {
                if (jsonValue.IsBool())
                {
                    this->isOverflow = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name_, "maxCapacity") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "maxStaminaTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->maxStaminaTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
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
    StaminaModelMaster() :
        m_pData(nullptr)
    {}

    StaminaModelMaster(const StaminaModelMaster& staminaModelMaster) :
        Gs2Object(staminaModelMaster),
        m_pData(staminaModelMaster.m_pData != nullptr ? new Data(*staminaModelMaster.m_pData) : nullptr)
    {}

    StaminaModelMaster(StaminaModelMaster&& staminaModelMaster) :
        Gs2Object(std::move(staminaModelMaster)),
        m_pData(staminaModelMaster.m_pData)
    {
        staminaModelMaster.m_pData = nullptr;
    }

    ~StaminaModelMaster()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    StaminaModelMaster& operator=(const StaminaModelMaster& staminaModelMaster)
    {
        Gs2Object::operator=(staminaModelMaster);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*staminaModelMaster.m_pData);

        return *this;
    }

    StaminaModelMaster& operator=(StaminaModelMaster&& staminaModelMaster)
    {
        Gs2Object::operator=(std::move(staminaModelMaster));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = staminaModelMaster.m_pData;
        staminaModelMaster.m_pData = nullptr;

        return *this;
    }

    const StaminaModelMaster* operator->() const
    {
        return this;
    }

    StaminaModelMaster* operator->()
    {
        return this;
    }
    /**
     * スタミナモデルマスターを取得
     *
     * @return スタミナモデルマスター
     */
    const optional<StringHolder>& getStaminaModelId() const
    {
        return ensureData().staminaModelId;
    }

    /**
     * スタミナモデルマスターを設定
     *
     * @param staminaModelId スタミナモデルマスター
     */
    void setStaminaModelId(const Char* staminaModelId)
    {
        ensureData().staminaModelId.emplace(staminaModelId);
    }

    /**
     * スタミナモデルマスターを設定
     *
     * @param staminaModelId スタミナモデルマスター
     */
    StaminaModelMaster& withStaminaModelId(const Char* staminaModelId)
    {
        setStaminaModelId(staminaModelId);
        return *this;
    }

    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param name スタミナの種類名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param name スタミナの種類名
     */
    StaminaModelMaster& withName(const Char* name)
    {
        setName(name);
        return *this;
    }

    /**
     * スタミナの種類のメタデータを取得
     *
     * @return スタミナの種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * スタミナの種類のメタデータを設定
     *
     * @param metadata スタミナの種類のメタデータ
     */
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * スタミナの種類のメタデータを設定
     *
     * @param metadata スタミナの種類のメタデータ
     */
    StaminaModelMaster& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * スタミナモデルマスターの説明を取得
     *
     * @return スタミナモデルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * スタミナモデルマスターの説明を設定
     *
     * @param description スタミナモデルマスターの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スタミナモデルマスターの説明を設定
     *
     * @param description スタミナモデルマスターの説明
     */
    StaminaModelMaster& withDescription(const Char* description)
    {
        setDescription(description);
        return *this;
    }

    /**
     * スタミナを回復する速度(分)を取得
     *
     * @return スタミナを回復する速度(分)
     */
    const optional<Int32>& getRecoverIntervalMinutes() const
    {
        return ensureData().recoverIntervalMinutes;
    }

    /**
     * スタミナを回復する速度(分)を設定
     *
     * @param recoverIntervalMinutes スタミナを回復する速度(分)
     */
    void setRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        ensureData().recoverIntervalMinutes.emplace(recoverIntervalMinutes);
    }

    /**
     * スタミナを回復する速度(分)を設定
     *
     * @param recoverIntervalMinutes スタミナを回復する速度(分)
     */
    StaminaModelMaster& withRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        setRecoverIntervalMinutes(recoverIntervalMinutes);
        return *this;
    }

    /**
     * 時間経過後に回復する量を取得
     *
     * @return 時間経過後に回復する量
     */
    const optional<Int32>& getRecoverValue() const
    {
        return ensureData().recoverValue;
    }

    /**
     * 時間経過後に回復する量を設定
     *
     * @param recoverValue 時間経過後に回復する量
     */
    void setRecoverValue(Int32 recoverValue)
    {
        ensureData().recoverValue.emplace(recoverValue);
    }

    /**
     * 時間経過後に回復する量を設定
     *
     * @param recoverValue 時間経過後に回復する量
     */
    StaminaModelMaster& withRecoverValue(Int32 recoverValue)
    {
        setRecoverValue(recoverValue);
        return *this;
    }

    /**
     * スタミナの最大値の初期値を取得
     *
     * @return スタミナの最大値の初期値
     */
    const optional<Int32>& getInitialCapacity() const
    {
        return ensureData().initialCapacity;
    }

    /**
     * スタミナの最大値の初期値を設定
     *
     * @param initialCapacity スタミナの最大値の初期値
     */
    void setInitialCapacity(Int32 initialCapacity)
    {
        ensureData().initialCapacity.emplace(initialCapacity);
    }

    /**
     * スタミナの最大値の初期値を設定
     *
     * @param initialCapacity スタミナの最大値の初期値
     */
    StaminaModelMaster& withInitialCapacity(Int32 initialCapacity)
    {
        setInitialCapacity(initialCapacity);
        return *this;
    }

    /**
     * 最大値を超えて回復するかを取得
     *
     * @return 最大値を超えて回復するか
     */
    const optional<Bool>& getIsOverflow() const
    {
        return ensureData().isOverflow;
    }

    /**
     * 最大値を超えて回復するかを設定
     *
     * @param isOverflow 最大値を超えて回復するか
     */
    void setIsOverflow(Bool isOverflow)
    {
        ensureData().isOverflow.emplace(isOverflow);
    }

    /**
     * 最大値を超えて回復するかを設定
     *
     * @param isOverflow 最大値を超えて回復するか
     */
    StaminaModelMaster& withIsOverflow(Bool isOverflow)
    {
        setIsOverflow(isOverflow);
        return *this;
    }

    /**
     * 溢れた状況での最大値を取得
     *
     * @return 溢れた状況での最大値
     */
    const optional<Int32>& getMaxCapacity() const
    {
        return ensureData().maxCapacity;
    }

    /**
     * 溢れた状況での最大値を設定
     *
     * @param maxCapacity 溢れた状況での最大値
     */
    void setMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
    }

    /**
     * 溢れた状況での最大値を設定
     *
     * @param maxCapacity 溢れた状況での最大値
     */
    StaminaModelMaster& withMaxCapacity(Int32 maxCapacity)
    {
        setMaxCapacity(maxCapacity);
        return *this;
    }

    /**
     * GS2-Experience のランクによって最大スタミナ値を決定するスタミナの最大値テーブルマスター のGRNを取得
     *
     * @return GS2-Experience のランクによって最大スタミナ値を決定するスタミナの最大値テーブルマスター のGRN
     */
    const optional<StringHolder>& getMaxStaminaTableId() const
    {
        return ensureData().maxStaminaTableId;
    }

    /**
     * GS2-Experience のランクによって最大スタミナ値を決定するスタミナの最大値テーブルマスター のGRNを設定
     *
     * @param maxStaminaTableId GS2-Experience のランクによって最大スタミナ値を決定するスタミナの最大値テーブルマスター のGRN
     */
    void setMaxStaminaTableId(const Char* maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(maxStaminaTableId);
    }

    /**
     * GS2-Experience のランクによって最大スタミナ値を決定するスタミナの最大値テーブルマスター のGRNを設定
     *
     * @param maxStaminaTableId GS2-Experience のランクによって最大スタミナ値を決定するスタミナの最大値テーブルマスター のGRN
     */
    StaminaModelMaster& withMaxStaminaTableId(const Char* maxStaminaTableId)
    {
        setMaxStaminaTableId(maxStaminaTableId);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    StaminaModelMaster& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    StaminaModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const StaminaModelMaster& lhs, const StaminaModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (lhs.m_pData == nullptr || lhr.m_pData == nullptr)
        {
            return true;
        }
        if (lhs.m_pData->staminaModelId != lhr.m_pData->staminaModelId)
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
        if (lhs.m_pData->recoverIntervalMinutes != lhr.m_pData->recoverIntervalMinutes)
        {
            return true;
        }
        if (lhs.m_pData->recoverValue != lhr.m_pData->recoverValue)
        {
            return true;
        }
        if (lhs.m_pData->initialCapacity != lhr.m_pData->initialCapacity)
        {
            return true;
        }
        if (lhs.m_pData->isOverflow != lhr.m_pData->isOverflow)
        {
            return true;
        }
        if (lhs.m_pData->maxCapacity != lhr.m_pData->maxCapacity)
        {
            return true;
        }
        if (lhs.m_pData->maxStaminaTableId != lhr.m_pData->maxStaminaTableId)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const StaminaModelMaster& lhs, const StaminaModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_STAMINA_MODEL_STAMINAMODELMASTER_HPP_