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

#ifndef GS2_ENHANCE_MODEL_RATEMODELMASTER_HPP_
#define GS2_ENHANCE_MODEL_RATEMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "BonusRate.hpp"
#include <memory>
#include <cstring>

namespace gs2 { namespace enhance {

/**
 * 強化レートマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class RateModelMaster : public Gs2Object
{
    friend bool operator!=(const RateModelMaster& lhs, const RateModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 強化レートマスター */
        optional<StringHolder> rateModelId;
        /** 強化レート名 */
        optional<StringHolder> name;
        /** 強化レートマスターの説明 */
        optional<StringHolder> description;
        /** 強化レートのメタデータ */
        optional<StringHolder> metadata;
        /** 強化対象に使用できるインベントリ のGRN */
        optional<StringHolder> targetInventoryId;
        /** GS2-Experience で入手した経験値を格納する プロパティID に付与するサフィックス */
        optional<StringHolder> acquireExperienceSuffix;
        /** 強化素材に使用できるインベントリ のGRN */
        optional<StringHolder> materialInventoryId;
        /** 入手経験値を格納しているメタデータのJSON階層 */
        optional<List<StringHolder>> acquireExperienceHierarchy;
        /** 獲得できる経験値の種類マスター のGRN */
        optional<StringHolder> experienceModelId;
        /** 経験値獲得量ボーナス */
        optional<List<BonusRate>> bonusRates;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            rateModelId(data.rateModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            targetInventoryId(data.targetInventoryId),
            acquireExperienceSuffix(data.acquireExperienceSuffix),
            materialInventoryId(data.materialInventoryId),
            experienceModelId(data.experienceModelId),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
            if (data.acquireExperienceHierarchy)
            {
                acquireExperienceHierarchy = data.acquireExperienceHierarchy->deepCopy();
            }
            if (data.bonusRates)
            {
                bonusRates = data.bonusRates->deepCopy();
            }
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "rateModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->rateModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "targetInventoryId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->targetInventoryId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "acquireExperienceSuffix") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->acquireExperienceSuffix.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "materialInventoryId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->materialInventoryId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "acquireExperienceHierarchy") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->acquireExperienceHierarchy.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        if (json->IsString())
                        {
                            auto valueStr = json->GetString();
                            StringHolder stringHolder(valueStr);
                            *this->acquireExperienceHierarchy += std::move(stringHolder);
                        }
                    }
                }
            }
            else if (std::strcmp(name_, "experienceModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->experienceModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "bonusRates") == 0)
            {
                if (jsonValue.IsArray())
                {
                    const auto& array = jsonValue.GetArray();
                    this->bonusRates.emplace();
                    for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                        BonusRate item;
                        detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->bonusRates += std::move(item);
                    }
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RateModelMaster() = default;
    RateModelMaster(const RateModelMaster& rateModelMaster) = default;
    RateModelMaster(RateModelMaster&& rateModelMaster) = default;
    ~RateModelMaster() = default;

    RateModelMaster& operator=(const RateModelMaster& rateModelMaster) = default;
    RateModelMaster& operator=(RateModelMaster&& rateModelMaster) = default;

    RateModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RateModelMaster);
    }

    const RateModelMaster* operator->() const
    {
        return this;
    }

    RateModelMaster* operator->()
    {
        return this;
    }
    /**
     * 強化レートマスターを取得
     *
     * @return 強化レートマスター
     */
    const optional<StringHolder>& getRateModelId() const
    {
        return ensureData().rateModelId;
    }

    /**
     * 強化レートマスターを設定
     *
     * @param rateModelId 強化レートマスター
     */
    void setRateModelId(StringHolder rateModelId)
    {
        ensureData().rateModelId.emplace(std::move(rateModelId));
    }

    /**
     * 強化レートマスターを設定
     *
     * @param rateModelId 強化レートマスター
     */
    RateModelMaster& withRateModelId(StringHolder rateModelId)
    {
        setRateModelId(std::move(rateModelId));
        return *this;
    }

    /**
     * 強化レート名を取得
     *
     * @return 強化レート名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 強化レート名を設定
     *
     * @param name 強化レート名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 強化レート名を設定
     *
     * @param name 強化レート名
     */
    RateModelMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 強化レートマスターの説明を取得
     *
     * @return 強化レートマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 強化レートマスターの説明を設定
     *
     * @param description 強化レートマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 強化レートマスターの説明を設定
     *
     * @param description 強化レートマスターの説明
     */
    RateModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * 強化レートのメタデータを取得
     *
     * @return 強化レートのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 強化レートのメタデータを設定
     *
     * @param metadata 強化レートのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 強化レートのメタデータを設定
     *
     * @param metadata 強化レートのメタデータ
     */
    RateModelMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 強化対象に使用できるインベントリ のGRNを取得
     *
     * @return 強化対象に使用できるインベントリ のGRN
     */
    const optional<StringHolder>& getTargetInventoryId() const
    {
        return ensureData().targetInventoryId;
    }

    /**
     * 強化対象に使用できるインベントリ のGRNを設定
     *
     * @param targetInventoryId 強化対象に使用できるインベントリ のGRN
     */
    void setTargetInventoryId(StringHolder targetInventoryId)
    {
        ensureData().targetInventoryId.emplace(std::move(targetInventoryId));
    }

    /**
     * 強化対象に使用できるインベントリ のGRNを設定
     *
     * @param targetInventoryId 強化対象に使用できるインベントリ のGRN
     */
    RateModelMaster& withTargetInventoryId(StringHolder targetInventoryId)
    {
        setTargetInventoryId(std::move(targetInventoryId));
        return *this;
    }

    /**
     * GS2-Experience で入手した経験値を格納する プロパティID に付与するサフィックスを取得
     *
     * @return GS2-Experience で入手した経験値を格納する プロパティID に付与するサフィックス
     */
    const optional<StringHolder>& getAcquireExperienceSuffix() const
    {
        return ensureData().acquireExperienceSuffix;
    }

    /**
     * GS2-Experience で入手した経験値を格納する プロパティID に付与するサフィックスを設定
     *
     * @param acquireExperienceSuffix GS2-Experience で入手した経験値を格納する プロパティID に付与するサフィックス
     */
    void setAcquireExperienceSuffix(StringHolder acquireExperienceSuffix)
    {
        ensureData().acquireExperienceSuffix.emplace(std::move(acquireExperienceSuffix));
    }

    /**
     * GS2-Experience で入手した経験値を格納する プロパティID に付与するサフィックスを設定
     *
     * @param acquireExperienceSuffix GS2-Experience で入手した経験値を格納する プロパティID に付与するサフィックス
     */
    RateModelMaster& withAcquireExperienceSuffix(StringHolder acquireExperienceSuffix)
    {
        setAcquireExperienceSuffix(std::move(acquireExperienceSuffix));
        return *this;
    }

    /**
     * 強化素材に使用できるインベントリ のGRNを取得
     *
     * @return 強化素材に使用できるインベントリ のGRN
     */
    const optional<StringHolder>& getMaterialInventoryId() const
    {
        return ensureData().materialInventoryId;
    }

    /**
     * 強化素材に使用できるインベントリ のGRNを設定
     *
     * @param materialInventoryId 強化素材に使用できるインベントリ のGRN
     */
    void setMaterialInventoryId(StringHolder materialInventoryId)
    {
        ensureData().materialInventoryId.emplace(std::move(materialInventoryId));
    }

    /**
     * 強化素材に使用できるインベントリ のGRNを設定
     *
     * @param materialInventoryId 強化素材に使用できるインベントリ のGRN
     */
    RateModelMaster& withMaterialInventoryId(StringHolder materialInventoryId)
    {
        setMaterialInventoryId(std::move(materialInventoryId));
        return *this;
    }

    /**
     * 入手経験値を格納しているメタデータのJSON階層を取得
     *
     * @return 入手経験値を格納しているメタデータのJSON階層
     */
    const optional<List<StringHolder>>& getAcquireExperienceHierarchy() const
    {
        return ensureData().acquireExperienceHierarchy;
    }

    /**
     * 入手経験値を格納しているメタデータのJSON階層を設定
     *
     * @param acquireExperienceHierarchy 入手経験値を格納しているメタデータのJSON階層
     */
    void setAcquireExperienceHierarchy(List<StringHolder> acquireExperienceHierarchy)
    {
        ensureData().acquireExperienceHierarchy.emplace(std::move(acquireExperienceHierarchy));
    }

    /**
     * 入手経験値を格納しているメタデータのJSON階層を設定
     *
     * @param acquireExperienceHierarchy 入手経験値を格納しているメタデータのJSON階層
     */
    RateModelMaster& withAcquireExperienceHierarchy(List<StringHolder> acquireExperienceHierarchy)
    {
        setAcquireExperienceHierarchy(std::move(acquireExperienceHierarchy));
        return *this;
    }

    /**
     * 獲得できる経験値の種類マスター のGRNを取得
     *
     * @return 獲得できる経験値の種類マスター のGRN
     */
    const optional<StringHolder>& getExperienceModelId() const
    {
        return ensureData().experienceModelId;
    }

    /**
     * 獲得できる経験値の種類マスター のGRNを設定
     *
     * @param experienceModelId 獲得できる経験値の種類マスター のGRN
     */
    void setExperienceModelId(StringHolder experienceModelId)
    {
        ensureData().experienceModelId.emplace(std::move(experienceModelId));
    }

    /**
     * 獲得できる経験値の種類マスター のGRNを設定
     *
     * @param experienceModelId 獲得できる経験値の種類マスター のGRN
     */
    RateModelMaster& withExperienceModelId(StringHolder experienceModelId)
    {
        setExperienceModelId(std::move(experienceModelId));
        return *this;
    }

    /**
     * 経験値獲得量ボーナスを取得
     *
     * @return 経験値獲得量ボーナス
     */
    const optional<List<BonusRate>>& getBonusRates() const
    {
        return ensureData().bonusRates;
    }

    /**
     * 経験値獲得量ボーナスを設定
     *
     * @param bonusRates 経験値獲得量ボーナス
     */
    void setBonusRates(List<BonusRate> bonusRates)
    {
        ensureData().bonusRates.emplace(std::move(bonusRates));
    }

    /**
     * 経験値獲得量ボーナスを設定
     *
     * @param bonusRates 経験値獲得量ボーナス
     */
    RateModelMaster& withBonusRates(List<BonusRate> bonusRates)
    {
        setBonusRates(std::move(bonusRates));
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
    RateModelMaster& withCreatedAt(Int64 createdAt)
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
    RateModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const RateModelMaster& lhs, const RateModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->rateModelId != lhr.m_pData->rateModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->targetInventoryId != lhr.m_pData->targetInventoryId)
        {
            return true;
        }
        if (lhs.m_pData->acquireExperienceSuffix != lhr.m_pData->acquireExperienceSuffix)
        {
            return true;
        }
        if (lhs.m_pData->materialInventoryId != lhr.m_pData->materialInventoryId)
        {
            return true;
        }
        if (lhs.m_pData->acquireExperienceHierarchy != lhr.m_pData->acquireExperienceHierarchy)
        {
            return true;
        }
        if (lhs.m_pData->experienceModelId != lhr.m_pData->experienceModelId)
        {
            return true;
        }
        if (lhs.m_pData->bonusRates != lhr.m_pData->bonusRates)
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

inline bool operator==(const RateModelMaster& lhs, const RateModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ENHANCE_MODEL_RATEMODELMASTER_HPP_