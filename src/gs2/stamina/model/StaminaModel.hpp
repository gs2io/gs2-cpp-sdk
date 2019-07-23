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

#ifndef GS2_STAMINA_MODEL_STAMINAMODEL_HPP_
#define GS2_STAMINA_MODEL_STAMINAMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "MaxStaminaTable.hpp"
#include <cstring>

namespace gs2 { namespace stamina {

/**
 * スタミナモデル
 *
 * @author Game Server Services, Inc.
 *
 */
class StaminaModel : public Gs2Object
{
    friend bool operator!=(const StaminaModel& lhs, const StaminaModel& lhr);

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
        /** スタミナを回復する速度(秒) */
        optional<Int32> recoverIntervalMinutes;
        /** 時間経過後に回復する量 */
        optional<Int32> recoverValue;
        /** スタミナの最大値の初期値 */
        optional<Int32> initialCapacity;
        /** 最大値を超えて回復するか */
        optional<Bool> isOverflow;
        /** 溢れた状況での最大値 */
        optional<Int32> maxCapacity;
        /** GS2-Experience と連携する際に使用するスタミナ最大値テーブル */
        optional<MaxStaminaTable> maxStaminaTable;

        Data()
        {}

        Data(const Data& data) :
            detail::json::IModel(data),
            staminaModelId(data.staminaModelId),
            name(data.name),
            metadata(data.metadata),
            recoverIntervalMinutes(data.recoverIntervalMinutes),
            recoverValue(data.recoverValue),
            initialCapacity(data.initialCapacity),
            isOverflow(data.isOverflow),
            maxCapacity(data.maxCapacity),
            maxStaminaTable(data.maxStaminaTable)
        {}

        Data(Data&& data) :
            detail::json::IModel(std::move(data)),
            staminaModelId(std::move(data.staminaModelId)),
            name(std::move(data.name)),
            metadata(std::move(data.metadata)),
            recoverIntervalMinutes(std::move(data.recoverIntervalMinutes)),
            recoverValue(std::move(data.recoverValue)),
            initialCapacity(std::move(data.initialCapacity)),
            isOverflow(std::move(data.isOverflow)),
            maxCapacity(std::move(data.maxCapacity)),
            maxStaminaTable(std::move(data.maxStaminaTable))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name, "staminaModelId") == 0) {
                if (jsonValue.IsString())
                {
                    this->staminaModelId.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "recoverIntervalMinutes") == 0) {
                if (jsonValue.IsInt())
                {
                    this->recoverIntervalMinutes = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "recoverValue") == 0) {
                if (jsonValue.IsInt())
                {
                    this->recoverValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "initialCapacity") == 0) {
                if (jsonValue.IsInt())
                {
                    this->initialCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "isOverflow") == 0) {
                if (jsonValue.IsBool())
                {
                    this->isOverflow = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "maxCapacity") == 0) {
                if (jsonValue.IsInt())
                {
                    this->maxCapacity = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name, "maxStaminaTable") == 0) {
                if (jsonValue.IsObject())
                {
                    const auto& jsonObject = jsonValue.GetObject();
                    this->maxStaminaTable.emplace();
                    detail::json::JsonParser::parse(&this->maxStaminaTable->getModel(), jsonObject);
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
    StaminaModel() :
        m_pData(nullptr)
    {}

    StaminaModel(const StaminaModel& staminaModel) :
        Gs2Object(staminaModel),
        m_pData(staminaModel.m_pData != nullptr ? new Data(*staminaModel.m_pData) : nullptr)
    {}

    StaminaModel(StaminaModel&& staminaModel) :
        Gs2Object(std::move(staminaModel)),
        m_pData(staminaModel.m_pData)
    {
        staminaModel.m_pData = nullptr;
    }

    ~StaminaModel()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    StaminaModel& operator=(const StaminaModel& staminaModel)
    {
        Gs2Object::operator=(staminaModel);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*staminaModel.m_pData);

        return *this;
    }

    StaminaModel& operator=(StaminaModel&& staminaModel)
    {
        Gs2Object::operator=(std::move(staminaModel));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = staminaModel.m_pData;
        staminaModel.m_pData = nullptr;

        return *this;
    }

    const StaminaModel* operator->() const
    {
        return this;
    }

    StaminaModel* operator->()
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
    StaminaModel& withStaminaModelId(const Char* staminaModelId)
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
    StaminaModel& withName(const Char* name)
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
    StaminaModel& withMetadata(const Char* metadata)
    {
        setMetadata(metadata);
        return *this;
    }

    /**
     * スタミナを回復する速度(秒)を取得
     *
     * @return スタミナを回復する速度(秒)
     */
    const optional<Int32>& getRecoverIntervalMinutes() const
    {
        return ensureData().recoverIntervalMinutes;
    }

    /**
     * スタミナを回復する速度(秒)を設定
     *
     * @param recoverIntervalMinutes スタミナを回復する速度(秒)
     */
    void setRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        ensureData().recoverIntervalMinutes.emplace(recoverIntervalMinutes);
    }

    /**
     * スタミナを回復する速度(秒)を設定
     *
     * @param recoverIntervalMinutes スタミナを回復する速度(秒)
     */
    StaminaModel& withRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
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
    StaminaModel& withRecoverValue(Int32 recoverValue)
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
    StaminaModel& withInitialCapacity(Int32 initialCapacity)
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
    StaminaModel& withIsOverflow(Bool isOverflow)
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
    StaminaModel& withMaxCapacity(Int32 maxCapacity)
    {
        setMaxCapacity(maxCapacity);
        return *this;
    }

    /**
     * GS2-Experience と連携する際に使用するスタミナ最大値テーブルを取得
     *
     * @return GS2-Experience と連携する際に使用するスタミナ最大値テーブル
     */
    const optional<MaxStaminaTable>& getMaxStaminaTable() const
    {
        return ensureData().maxStaminaTable;
    }

    /**
     * GS2-Experience と連携する際に使用するスタミナ最大値テーブルを設定
     *
     * @param maxStaminaTable GS2-Experience と連携する際に使用するスタミナ最大値テーブル
     */
    void setMaxStaminaTable(const MaxStaminaTable& maxStaminaTable)
    {
        ensureData().maxStaminaTable.emplace(maxStaminaTable);
    }

    /**
     * GS2-Experience と連携する際に使用するスタミナ最大値テーブルを設定
     *
     * @param maxStaminaTable GS2-Experience と連携する際に使用するスタミナ最大値テーブル
     */
    StaminaModel& withMaxStaminaTable(const MaxStaminaTable& maxStaminaTable)
    {
        setMaxStaminaTable(maxStaminaTable);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const StaminaModel& lhs, const StaminaModel& lhr)
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
        if (lhs.m_pData->maxStaminaTable != lhr.m_pData->maxStaminaTable)
        {
            return true;
        }
    }
    return false;
}

bool operator==(const StaminaModel& lhs, const StaminaModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_STAMINA_MODEL_STAMINAMODEL_HPP_