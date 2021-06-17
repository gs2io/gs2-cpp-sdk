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

#ifndef GS2_ENHANCE_MODEL_RATEMODEL_HPP_
#define GS2_ENHANCE_MODEL_RATEMODEL_HPP_

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
 * 強化レートモデル
 *
 * @author Game Server Services, Inc.
 *
 */
class RateModel : public Gs2Object
{
    friend bool operator!=(const RateModel& lhs, const RateModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 強化レートモデル */
        optional<StringHolder> rateModelId;
        /** 強化レート名 */
        optional<StringHolder> name;
        /** 強化レートの説明 */
        optional<StringHolder> description;
        /** 強化レートのメタデータ */
        optional<StringHolder> metadata;
        /** 強化対象に使用できるインベントリモデル のGRN */
        optional<StringHolder> targetInventoryModelId;
        /** GS2-Experience で入手した経験値を格納する プロパティID に付与するサフィックス */
        optional<StringHolder> acquireExperienceSuffix;
        /** 強化素材に使用できるインベントリモデル のGRN */
        optional<StringHolder> materialInventoryModelId;
        /** 入手経験値を格納しているメタデータのJSON階層 */
        optional<List<StringHolder>> acquireExperienceHierarchy;
        /** 獲得できる経験値の種類マスター のGRN */
        optional<StringHolder> experienceModelId;
        /** 経験値獲得量ボーナス */
        optional<List<BonusRate>> bonusRates;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            rateModelId(data.rateModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            targetInventoryModelId(data.targetInventoryModelId),
            acquireExperienceSuffix(data.acquireExperienceSuffix),
            materialInventoryModelId(data.materialInventoryModelId),
            experienceModelId(data.experienceModelId)
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
            else if (std::strcmp(name_, "targetInventoryModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->targetInventoryModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "acquireExperienceSuffix") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->acquireExperienceSuffix.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "materialInventoryModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->materialInventoryModelId.emplace(jsonValue.GetString());
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
                        BonusRate item_;
                        detail::json::JsonParser::parse(&item_.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                        *this->bonusRates += std::move(item_);
                    }
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    RateModel() = default;
    RateModel(const RateModel& rateModel) = default;
    RateModel(RateModel&& rateModel) = default;
    ~RateModel() = default;

    RateModel& operator=(const RateModel& rateModel) = default;
    RateModel& operator=(RateModel&& rateModel) = default;

    RateModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(RateModel);
    }

    const RateModel* operator->() const
    {
        return this;
    }

    RateModel* operator->()
    {
        return this;
    }
    /**
     * 強化レートモデルを取得
     *
     * @return 強化レートモデル
     */
    const optional<StringHolder>& getRateModelId() const
    {
        return ensureData().rateModelId;
    }

    /**
     * 強化レートモデルを設定
     *
     * @param rateModelId 強化レートモデル
     */
    void setRateModelId(StringHolder rateModelId)
    {
        ensureData().rateModelId.emplace(std::move(rateModelId));
    }

    /**
     * 強化レートモデルを設定
     *
     * @param rateModelId 強化レートモデル
     */
    RateModel& withRateModelId(StringHolder rateModelId)
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
    RateModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * 強化レートの説明を取得
     *
     * @return 強化レートの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 強化レートの説明を設定
     *
     * @param description 強化レートの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 強化レートの説明を設定
     *
     * @param description 強化レートの説明
     */
    RateModel& withDescription(StringHolder description)
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
    RateModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * 強化対象に使用できるインベントリモデル のGRNを取得
     *
     * @return 強化対象に使用できるインベントリモデル のGRN
     */
    const optional<StringHolder>& getTargetInventoryModelId() const
    {
        return ensureData().targetInventoryModelId;
    }

    /**
     * 強化対象に使用できるインベントリモデル のGRNを設定
     *
     * @param targetInventoryModelId 強化対象に使用できるインベントリモデル のGRN
     */
    void setTargetInventoryModelId(StringHolder targetInventoryModelId)
    {
        ensureData().targetInventoryModelId.emplace(std::move(targetInventoryModelId));
    }

    /**
     * 強化対象に使用できるインベントリモデル のGRNを設定
     *
     * @param targetInventoryModelId 強化対象に使用できるインベントリモデル のGRN
     */
    RateModel& withTargetInventoryModelId(StringHolder targetInventoryModelId)
    {
        setTargetInventoryModelId(std::move(targetInventoryModelId));
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
    RateModel& withAcquireExperienceSuffix(StringHolder acquireExperienceSuffix)
    {
        setAcquireExperienceSuffix(std::move(acquireExperienceSuffix));
        return *this;
    }

    /**
     * 強化素材に使用できるインベントリモデル のGRNを取得
     *
     * @return 強化素材に使用できるインベントリモデル のGRN
     */
    const optional<StringHolder>& getMaterialInventoryModelId() const
    {
        return ensureData().materialInventoryModelId;
    }

    /**
     * 強化素材に使用できるインベントリモデル のGRNを設定
     *
     * @param materialInventoryModelId 強化素材に使用できるインベントリモデル のGRN
     */
    void setMaterialInventoryModelId(StringHolder materialInventoryModelId)
    {
        ensureData().materialInventoryModelId.emplace(std::move(materialInventoryModelId));
    }

    /**
     * 強化素材に使用できるインベントリモデル のGRNを設定
     *
     * @param materialInventoryModelId 強化素材に使用できるインベントリモデル のGRN
     */
    RateModel& withMaterialInventoryModelId(StringHolder materialInventoryModelId)
    {
        setMaterialInventoryModelId(std::move(materialInventoryModelId));
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
    RateModel& withAcquireExperienceHierarchy(List<StringHolder> acquireExperienceHierarchy)
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
    RateModel& withExperienceModelId(StringHolder experienceModelId)
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
    RateModel& withBonusRates(List<BonusRate> bonusRates)
    {
        setBonusRates(std::move(bonusRates));
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const RateModel& lhs, const RateModel& lhr)
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
        if (lhs.m_pData->targetInventoryModelId != lhr.m_pData->targetInventoryModelId)
        {
            return true;
        }
        if (lhs.m_pData->acquireExperienceSuffix != lhr.m_pData->acquireExperienceSuffix)
        {
            return true;
        }
        if (lhs.m_pData->materialInventoryModelId != lhr.m_pData->materialInventoryModelId)
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
    }
    return false;
}

inline bool operator==(const RateModel& lhs, const RateModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ENHANCE_MODEL_RATEMODEL_HPP_