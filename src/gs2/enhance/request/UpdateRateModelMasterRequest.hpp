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

#ifndef GS2_ENHANCE_CONTROL_UPDATERATEMODELMASTERREQUEST_HPP_
#define GS2_ENHANCE_CONTROL_UPDATERATEMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/enhance/Gs2EnhanceConst.hpp>
#include <gs2/enhance/model/model.hpp>
#include <memory>

namespace gs2 { namespace enhance
{

/**
 * 強化レートマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateRateModelMasterRequest : public Gs2BasicRequest, public Gs2Enhance
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 強化レート名 */
        optional<StringHolder> rateName;
        /** 強化レートマスターの説明 */
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
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            rateName(data.rateName),
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
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

    Gs2BasicRequest::Data& getData_() GS2_OVERRIDE
    {
        return ensureData();
    }

    const Gs2BasicRequest::Data& getData_() const GS2_OVERRIDE
    {
        return ensureData();
    }

public:
    UpdateRateModelMasterRequest() = default;
    UpdateRateModelMasterRequest(const UpdateRateModelMasterRequest& updateRateModelMasterRequest) = default;
    UpdateRateModelMasterRequest(UpdateRateModelMasterRequest&& updateRateModelMasterRequest) = default;
    ~UpdateRateModelMasterRequest() GS2_OVERRIDE = default;

    UpdateRateModelMasterRequest& operator=(const UpdateRateModelMasterRequest& updateRateModelMasterRequest) = default;
    UpdateRateModelMasterRequest& operator=(UpdateRateModelMasterRequest&& updateRateModelMasterRequest) = default;

    UpdateRateModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateRateModelMasterRequest);
    }

    const UpdateRateModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateRateModelMasterRequest* operator->()
    {
        return this;
    }

    /**
     * ネームスペース名を取得
     *
     * @return ネームスペース名
     */
    const optional<StringHolder>& getNamespaceName() const
    {
        return ensureData().namespaceName;
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    void setNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateRateModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 強化レート名を取得
     *
     * @return 強化レート名
     */
    const optional<StringHolder>& getRateName() const
    {
        return ensureData().rateName;
    }

    /**
     * 強化レート名を設定
     *
     * @param rateName 強化レート名
     */
    void setRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
    }

    /**
     * 強化レート名を設定
     *
     * @param rateName 強化レート名
     */
    UpdateRateModelMasterRequest& withRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
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
    UpdateRateModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    UpdateRateModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
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
    UpdateRateModelMasterRequest& withTargetInventoryModelId(StringHolder targetInventoryModelId)
    {
        ensureData().targetInventoryModelId.emplace(std::move(targetInventoryModelId));
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
    UpdateRateModelMasterRequest& withAcquireExperienceSuffix(StringHolder acquireExperienceSuffix)
    {
        ensureData().acquireExperienceSuffix.emplace(std::move(acquireExperienceSuffix));
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
    UpdateRateModelMasterRequest& withMaterialInventoryModelId(StringHolder materialInventoryModelId)
    {
        ensureData().materialInventoryModelId.emplace(std::move(materialInventoryModelId));
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
    UpdateRateModelMasterRequest& withAcquireExperienceHierarchy(List<StringHolder> acquireExperienceHierarchy)
    {
        ensureData().acquireExperienceHierarchy.emplace(std::move(acquireExperienceHierarchy));
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
    UpdateRateModelMasterRequest& withExperienceModelId(StringHolder experienceModelId)
    {
        ensureData().experienceModelId.emplace(std::move(experienceModelId));
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
    UpdateRateModelMasterRequest& withBonusRates(List<BonusRate> bonusRates)
    {
        ensureData().bonusRates.emplace(std::move(bonusRates));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateRateModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateRateModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_ENHANCE_CONTROL_UPDATERATEMODELMASTERREQUEST_HPP_