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

#ifndef GS2_STAMINA_CONTROL_UPDATEMAXSTAMINATABLEMASTERREQUEST_HPP_
#define GS2_STAMINA_CONTROL_UPDATEMAXSTAMINATABLEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace stamina
{

/**
 * スタミナの最大値テーブルマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateMaxStaminaTableMasterRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 最大スタミナ値テーブル名 */
        optional<StringHolder> maxStaminaTableName;
        /** スタミナの最大値テーブルマスターの説明 */
        optional<StringHolder> description;
        /** 最大スタミナ値テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の種類マスター のGRN */
        optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナの最大値テーブル */
        optional<List<Int32>> values;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            maxStaminaTableName(data.maxStaminaTableName),
            description(data.description),
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
    UpdateMaxStaminaTableMasterRequest() = default;
    UpdateMaxStaminaTableMasterRequest(const UpdateMaxStaminaTableMasterRequest& updateMaxStaminaTableMasterRequest) = default;
    UpdateMaxStaminaTableMasterRequest(UpdateMaxStaminaTableMasterRequest&& updateMaxStaminaTableMasterRequest) = default;
    ~UpdateMaxStaminaTableMasterRequest() GS2_OVERRIDE = default;

    UpdateMaxStaminaTableMasterRequest& operator=(const UpdateMaxStaminaTableMasterRequest& updateMaxStaminaTableMasterRequest) = default;
    UpdateMaxStaminaTableMasterRequest& operator=(UpdateMaxStaminaTableMasterRequest&& updateMaxStaminaTableMasterRequest) = default;

    UpdateMaxStaminaTableMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateMaxStaminaTableMasterRequest);
    }

    const UpdateMaxStaminaTableMasterRequest* operator->() const
    {
        return this;
    }

    UpdateMaxStaminaTableMasterRequest* operator->()
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
    UpdateMaxStaminaTableMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 最大スタミナ値テーブル名を取得
     *
     * @return 最大スタミナ値テーブル名
     */
    const optional<StringHolder>& getMaxStaminaTableName() const
    {
        return ensureData().maxStaminaTableName;
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param maxStaminaTableName 最大スタミナ値テーブル名
     */
    void setMaxStaminaTableName(StringHolder maxStaminaTableName)
    {
        ensureData().maxStaminaTableName.emplace(std::move(maxStaminaTableName));
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param maxStaminaTableName 最大スタミナ値テーブル名
     */
    UpdateMaxStaminaTableMasterRequest& withMaxStaminaTableName(StringHolder maxStaminaTableName)
    {
        ensureData().maxStaminaTableName.emplace(std::move(maxStaminaTableName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * スタミナの最大値テーブルマスターの説明を設定
     *
     * @param description スタミナの最大値テーブルマスターの説明
     */
    UpdateMaxStaminaTableMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 最大スタミナ値テーブルのメタデータを設定
     *
     * @param metadata 最大スタミナ値テーブルのメタデータ
     */
    UpdateMaxStaminaTableMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
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
    UpdateMaxStaminaTableMasterRequest& withExperienceModelId(StringHolder experienceModelId)
    {
        ensureData().experienceModelId.emplace(std::move(experienceModelId));
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
    void setValues(List<Int32> values)
    {
        ensureData().values.emplace(std::move(values));
    }

    /**
     * ランク毎のスタミナの最大値テーブルを設定
     *
     * @param values ランク毎のスタミナの最大値テーブル
     */
    UpdateMaxStaminaTableMasterRequest& withValues(List<Int32> values)
    {
        ensureData().values.emplace(std::move(values));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateMaxStaminaTableMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateMaxStaminaTableMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_UPDATEMAXSTAMINATABLEMASTERREQUEST_HPP_