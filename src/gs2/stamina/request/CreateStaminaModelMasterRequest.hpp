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

#ifndef GS2_STAMINA_CONTROL_CREATESTAMINAMODELMASTERREQUEST_HPP_
#define GS2_STAMINA_CONTROL_CREATESTAMINAMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <gs2/stamina/Gs2StaminaConst.hpp>
#include <gs2/stamina/model/model.hpp>
#include <memory>

namespace gs2 { namespace stamina
{

/**
 * スタミナモデルマスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateStaminaModelMasterRequest : public Gs2BasicRequest, public Gs2Stamina
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
        optional<StringHolder> name;
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
        /** GS2-Experience のランクによって最大スタミナ値を決定する */
        optional<StringHolder> maxStaminaTableId;
        /** GS2-Experience のランクによってスタミナの回復間隔を決定する */
        optional<StringHolder> recoverIntervalTableId;
        /** GS2-Experience のランクによってスタミナの回復量を決定する */
        optional<StringHolder> recoverValueTableId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            recoverIntervalMinutes(data.recoverIntervalMinutes),
            recoverValue(data.recoverValue),
            initialCapacity(data.initialCapacity),
            isOverflow(data.isOverflow),
            maxCapacity(data.maxCapacity),
            maxStaminaTableId(data.maxStaminaTableId),
            recoverIntervalTableId(data.recoverIntervalTableId),
            recoverValueTableId(data.recoverValueTableId)
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
    CreateStaminaModelMasterRequest() = default;
    CreateStaminaModelMasterRequest(const CreateStaminaModelMasterRequest& createStaminaModelMasterRequest) = default;
    CreateStaminaModelMasterRequest(CreateStaminaModelMasterRequest&& createStaminaModelMasterRequest) = default;
    ~CreateStaminaModelMasterRequest() GS2_OVERRIDE = default;

    CreateStaminaModelMasterRequest& operator=(const CreateStaminaModelMasterRequest& createStaminaModelMasterRequest) = default;
    CreateStaminaModelMasterRequest& operator=(CreateStaminaModelMasterRequest&& createStaminaModelMasterRequest) = default;

    CreateStaminaModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateStaminaModelMasterRequest);
    }

    const CreateStaminaModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateStaminaModelMasterRequest* operator->()
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
    CreateStaminaModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
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
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * スタミナの種類名を設定
     *
     * @param name スタミナの種類名
     */
    CreateStaminaModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
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
    CreateStaminaModelMasterRequest& withDescription(StringHolder description)
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
    CreateStaminaModelMasterRequest& withMetadata(StringHolder metadata)
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
    CreateStaminaModelMasterRequest& withRecoverIntervalMinutes(Int32 recoverIntervalMinutes)
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
    CreateStaminaModelMasterRequest& withRecoverValue(Int32 recoverValue)
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
    CreateStaminaModelMasterRequest& withInitialCapacity(Int32 initialCapacity)
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
    CreateStaminaModelMasterRequest& withIsOverflow(Bool isOverflow)
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
    CreateStaminaModelMasterRequest& withMaxCapacity(Int32 maxCapacity)
    {
        ensureData().maxCapacity.emplace(maxCapacity);
        return *this;
    }

    /**
     * GS2-Experience のランクによって最大スタミナ値を決定するを取得
     *
     * @return GS2-Experience のランクによって最大スタミナ値を決定する
     */
    const optional<StringHolder>& getMaxStaminaTableId() const
    {
        return ensureData().maxStaminaTableId;
    }

    /**
     * GS2-Experience のランクによって最大スタミナ値を決定するを設定
     *
     * @param maxStaminaTableId GS2-Experience のランクによって最大スタミナ値を決定する
     */
    void setMaxStaminaTableId(StringHolder maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(std::move(maxStaminaTableId));
    }

    /**
     * GS2-Experience のランクによって最大スタミナ値を決定するを設定
     *
     * @param maxStaminaTableId GS2-Experience のランクによって最大スタミナ値を決定する
     */
    CreateStaminaModelMasterRequest& withMaxStaminaTableId(StringHolder maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(std::move(maxStaminaTableId));
        return *this;
    }

    /**
     * GS2-Experience のランクによってスタミナの回復間隔を決定するを取得
     *
     * @return GS2-Experience のランクによってスタミナの回復間隔を決定する
     */
    const optional<StringHolder>& getRecoverIntervalTableId() const
    {
        return ensureData().recoverIntervalTableId;
    }

    /**
     * GS2-Experience のランクによってスタミナの回復間隔を決定するを設定
     *
     * @param recoverIntervalTableId GS2-Experience のランクによってスタミナの回復間隔を決定する
     */
    void setRecoverIntervalTableId(StringHolder recoverIntervalTableId)
    {
        ensureData().recoverIntervalTableId.emplace(std::move(recoverIntervalTableId));
    }

    /**
     * GS2-Experience のランクによってスタミナの回復間隔を決定するを設定
     *
     * @param recoverIntervalTableId GS2-Experience のランクによってスタミナの回復間隔を決定する
     */
    CreateStaminaModelMasterRequest& withRecoverIntervalTableId(StringHolder recoverIntervalTableId)
    {
        ensureData().recoverIntervalTableId.emplace(std::move(recoverIntervalTableId));
        return *this;
    }

    /**
     * GS2-Experience のランクによってスタミナの回復量を決定するを取得
     *
     * @return GS2-Experience のランクによってスタミナの回復量を決定する
     */
    const optional<StringHolder>& getRecoverValueTableId() const
    {
        return ensureData().recoverValueTableId;
    }

    /**
     * GS2-Experience のランクによってスタミナの回復量を決定するを設定
     *
     * @param recoverValueTableId GS2-Experience のランクによってスタミナの回復量を決定する
     */
    void setRecoverValueTableId(StringHolder recoverValueTableId)
    {
        ensureData().recoverValueTableId.emplace(std::move(recoverValueTableId));
    }

    /**
     * GS2-Experience のランクによってスタミナの回復量を決定するを設定
     *
     * @param recoverValueTableId GS2-Experience のランクによってスタミナの回復量を決定する
     */
    CreateStaminaModelMasterRequest& withRecoverValueTableId(StringHolder recoverValueTableId)
    {
        ensureData().recoverValueTableId.emplace(std::move(recoverValueTableId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateStaminaModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateStaminaModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_CREATESTAMINAMODELMASTERREQUEST_HPP_