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

namespace gs2 { namespace  {

/**
 * スタミナモデルマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class StaminaModelMaster : public Gs2Object
{
private:
    class Data : public detail::json::IModel
    {
    public:
        /** スタミナモデルマスター のGRN */
        optional<StringHolder> staminaModelId;
        /** スタミナの種類名 */
        optional<StringHolder> name;
        /** スタミナの種類のメタデータ */
        optional<StringHolder> metadata;
        /** スタミナモデルマスターの説明 */
        optional<StringHolder> description;
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
        /** GS2-Experience と連携してスタミナの最大値を決定するか */
        
        optional<Bool> isCollaborateGs2Experience;
        /** GS2-Experience のランクによって最大スタミナ値を決定するスタミナ最大値テーブル のGRN */
        optional<StringHolder> maxStaminaTableId;
        /** 作成日時 */
        
        optional<Int64> createAt;
        /** 最終更新日時 */
        
        optional<Int64> updateAt;

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
            isCollaborateGs2Experience(data.isCollaborateGs2Experience),
            maxStaminaTableId(data.maxStaminaTableId),
            createAt(data.createAt),
            updateAt(data.updateAt)
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
            isCollaborateGs2Experience(std::move(data.isCollaborateGs2Experience)),
            maxStaminaTableId(std::move(data.maxStaminaTableId)),
            createAt(std::move(data.createAt)),
            updateAt(std::move(data.updateAt))
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
            else if (std::strcmp(name, "description") == 0) {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
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
            else if (std::strcmp(name, "isCollaborateGs2Experience") == 0) {
                if (jsonValue.IsBool())
                {
                    this->isCollaborateGs2Experience = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name, "maxStaminaTableId") == 0) {
                if (jsonValue.IsString())
                {
                    this->maxStaminaTableId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name, "createAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->createAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name, "updateAt") == 0) {
                if (jsonValue.IsInt64())
                {
                    this->updateAt = jsonValue.GetInt64();
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
     * スタミナモデルマスター のGRNを取得
     *
     * @return スタミナモデルマスター のGRN
     */
    const optional<StringHolder>& getStaminaModelId() const
    {
        return ensureData().staminaModelId;
    }

    /**
     * スタミナモデルマスター のGRNを設定
     *
     * @param staminaModelId スタミナモデルマスター のGRN
     */
    void setStaminaModelId(const Char* staminaModelId)
    {
        ensureData().staminaModelId.emplace(staminaModelId);
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
     * GS2-Experience と連携してスタミナの最大値を決定するかを取得
     *
     * @return GS2-Experience と連携してスタミナの最大値を決定するか
     */
    const optional<Bool>& getIsCollaborateGs2Experience() const
    {
        return ensureData().isCollaborateGs2Experience;
    }

    /**
     * GS2-Experience と連携してスタミナの最大値を決定するかを設定
     *
     * @param isCollaborateGs2Experience GS2-Experience と連携してスタミナの最大値を決定するか
     */
    void setIsCollaborateGs2Experience(Bool isCollaborateGs2Experience)
    {
        ensureData().isCollaborateGs2Experience.emplace(isCollaborateGs2Experience);
    }

    /**
     * GS2-Experience のランクによって最大スタミナ値を決定するスタミナ最大値テーブル のGRNを取得
     *
     * @return GS2-Experience のランクによって最大スタミナ値を決定するスタミナ最大値テーブル のGRN
     */
    const optional<StringHolder>& getMaxStaminaTableId() const
    {
        return ensureData().maxStaminaTableId;
    }

    /**
     * GS2-Experience のランクによって最大スタミナ値を決定するスタミナ最大値テーブル のGRNを設定
     *
     * @param maxStaminaTableId GS2-Experience のランクによって最大スタミナ値を決定するスタミナ最大値テーブル のGRN
     */
    void setMaxStaminaTableId(const Char* maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(maxStaminaTableId);
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreateAt() const
    {
        return ensureData().createAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createAt 作成日時
     */
    void setCreateAt(Int64 createAt)
    {
        ensureData().createAt.emplace(createAt);
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdateAt() const
    {
        return ensureData().updateAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updateAt 最終更新日時
     */
    void setUpdateAt(Int64 updateAt)
    {
        ensureData().updateAt.emplace(updateAt);
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

} }

#endif //GS2_STAMINA_MODEL_STAMINAMODELMASTER_HPP_