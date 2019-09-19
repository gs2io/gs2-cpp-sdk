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

#ifndef GS2_STAMINA_CONTROL_UPDATESTAMINAMODELMASTERREQUEST_HPP_
#define GS2_STAMINA_CONTROL_UPDATESTAMINAMODELMASTERREQUEST_HPP_

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
 * スタミナモデルマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateStaminaModelMasterRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スタミナの種類名 */
        optional<StringHolder> staminaName;
        /** スタミナモデルマスターの説明 */
        optional<StringHolder> description;
        /** スタミナの種類のメタデータ */
        optional<StringHolder> metadata;
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

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            staminaName(data.staminaName),
            description(data.description),
            metadata(data.metadata),
            recoverIntervalMinutes(data.recoverIntervalMinutes),
            recoverValue(data.recoverValue),
            initialCapacity(data.initialCapacity),
            isOverflow(data.isOverflow),
            maxCapacity(data.maxCapacity),
            maxStaminaTableId(data.maxStaminaTableId)
        {
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
    UpdateStaminaModelMasterRequest() = default;
    UpdateStaminaModelMasterRequest(const UpdateStaminaModelMasterRequest& updateStaminaModelMasterRequest) = default;
    UpdateStaminaModelMasterRequest(UpdateStaminaModelMasterRequest&& updateStaminaModelMasterRequest) = default;
    ~UpdateStaminaModelMasterRequest() GS2_OVERRIDE = default;

    UpdateStaminaModelMasterRequest& operator=(const UpdateStaminaModelMasterRequest& updateStaminaModelMasterRequest) = default;
    UpdateStaminaModelMasterRequest& operator=(UpdateStaminaModelMasterRequest&& updateStaminaModelMasterRequest) = default;

    UpdateStaminaModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateStaminaModelMasterRequest);
    }

    const UpdateStaminaModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateStaminaModelMasterRequest* operator->()
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
    UpdateStaminaModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getStaminaName() const
    {
        return ensureData().staminaName;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaName スタミナの種類名
     */
    void setStaminaName(StringHolder staminaName)
    {
        ensureData().staminaName.emplace(std::move(staminaName));
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaName スタミナの種類名
     */
    UpdateStaminaModelMasterRequest& withStaminaName(StringHolder staminaName)
    {
        ensureData().staminaName.emplace(std::move(staminaName));
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
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * スタミナモデルマスターの説明を設定
     *
     * @param description スタミナモデルマスターの説明
     */
    UpdateStaminaModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
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
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * スタミナの種類のメタデータを設定
     *
     * @param metadata スタミナの種類のメタデータ
     */
    UpdateStaminaModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
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
    UpdateStaminaModelMasterRequest& withRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
    {
        ensureData().recoverIntervalMinutes.emplace(recoverIntervalMinutes);
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
    UpdateStaminaModelMasterRequest& withRecoverValue(Int32 recoverValue)
    {
        ensureData().recoverValue.emplace(recoverValue);
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
    UpdateStaminaModelMasterRequest& withInitialCapacity(Int32 initialCapacity)
    {
        ensureData().initialCapacity.emplace(initialCapacity);
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
    UpdateStaminaModelMasterRequest& withIsOverflow(Bool isOverflow)
    {
        ensureData().isOverflow.emplace(isOverflow);
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
    UpdateStaminaModelMasterRequest& withMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
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
    void setMaxStaminaTableId(StringHolder maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(std::move(maxStaminaTableId));
    }

    /**
     * GS2-Experience のランクによって最大スタミナ値を決定するスタミナの最大値テーブルマスター のGRNを設定
     *
     * @param maxStaminaTableId GS2-Experience のランクによって最大スタミナ値を決定するスタミナの最大値テーブルマスター のGRN
     */
    UpdateStaminaModelMasterRequest& withMaxStaminaTableId(StringHolder maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(std::move(maxStaminaTableId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateStaminaModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateStaminaModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_UPDATESTAMINAMODELMASTERREQUEST_HPP_