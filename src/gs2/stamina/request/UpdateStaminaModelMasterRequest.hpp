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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
    {
    public:
        /** スタミナの種類名 */
        optional<StringHolder> groupName;
        /** スタミナの種類名 */
        optional<StringHolder> staminaModelName;
        /** スタミナモデルマスターの説明 */
        optional<StringHolder> description;
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
        /** GS2-Experience と連携してスタミナの最大値を決定するか */
        optional<Bool> isCollaborateGs2Experience;
        /** GS2-Experience のランクによって最大スタミナ値を決定するスタミナ最大値テーブル のGRN */
        optional<StringHolder> maxStaminaTableId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            groupName(data.groupName),
            staminaModelName(data.staminaModelName),
            description(data.description),
            metadata(data.metadata),
            recoverIntervalMinutes(data.recoverIntervalMinutes),
            recoverValue(data.recoverValue),
            initialCapacity(data.initialCapacity),
            isOverflow(data.isOverflow),
            maxCapacity(data.maxCapacity),
            isCollaborateGs2Experience(data.isCollaborateGs2Experience),
            maxStaminaTableId(data.maxStaminaTableId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            groupName(std::move(data.groupName)),
            staminaModelName(std::move(data.staminaModelName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            recoverIntervalMinutes(std::move(data.recoverIntervalMinutes)),
            recoverValue(std::move(data.recoverValue)),
            initialCapacity(std::move(data.initialCapacity)),
            isOverflow(std::move(data.isOverflow)),
            maxCapacity(std::move(data.maxCapacity)),
            isCollaborateGs2Experience(std::move(data.isCollaborateGs2Experience)),
            maxStaminaTableId(std::move(data.maxStaminaTableId))
        {}

        ~Data() = default;

        // TODO:
        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
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
    UpdateStaminaModelMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateStaminaModelMasterRequest(const UpdateStaminaModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateStaminaModelMasterRequest(UpdateStaminaModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateStaminaModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateStaminaModelMasterRequest& operator=(const UpdateStaminaModelMasterRequest& updateStaminaModelMasterRequest)
    {
        Gs2BasicRequest::operator=(updateStaminaModelMasterRequest);
        Gs2Stamina::operator=(updateStaminaModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateStaminaModelMasterRequest.m_pData);

        return *this;
    }

    UpdateStaminaModelMasterRequest& operator=(UpdateStaminaModelMasterRequest&& updateStaminaModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateStaminaModelMasterRequest));
        Gs2Stamina::operator=(std::move(updateStaminaModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateStaminaModelMasterRequest.m_pData;
        updateStaminaModelMasterRequest.m_pData = nullptr;

        return *this;
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
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getGroupName() const
    {
        return ensureData().groupName;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param groupName スタミナの種類名
     */
    void setGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param groupName スタミナの種類名
     */
    UpdateStaminaModelMasterRequest& withGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
        return *this;
    }

    /**
     * スタミナの種類名を取得
     *
     * @return スタミナの種類名
     */
    const optional<StringHolder>& getStaminaModelName() const
    {
        return ensureData().staminaModelName;
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaModelName スタミナの種類名
     */
    void setStaminaModelName(const Char* staminaModelName)
    {
        ensureData().staminaModelName.emplace(staminaModelName);
    }

    /**
     * スタミナの種類名を設定
     *
     * @param staminaModelName スタミナの種類名
     */
    UpdateStaminaModelMasterRequest& withStaminaModelName(const Char* staminaModelName)
    {
        ensureData().staminaModelName.emplace(staminaModelName);
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
    UpdateStaminaModelMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    UpdateStaminaModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
     * GS2-Experience と連携してスタミナの最大値を決定するかを設定
     *
     * @param isCollaborateGs2Experience GS2-Experience と連携してスタミナの最大値を決定するか
     */
    UpdateStaminaModelMasterRequest& withIsCollaborateGs2Experience(Bool isCollaborateGs2Experience)
    {
        ensureData().isCollaborateGs2Experience.emplace(isCollaborateGs2Experience);
        return *this;
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
     * GS2-Experience のランクによって最大スタミナ値を決定するスタミナ最大値テーブル のGRNを設定
     *
     * @param maxStaminaTableId GS2-Experience のランクによって最大スタミナ値を決定するスタミナ最大値テーブル のGRN
     */
    UpdateStaminaModelMasterRequest& withMaxStaminaTableId(const Char* maxStaminaTableId)
    {
        ensureData().maxStaminaTableId.emplace(maxStaminaTableId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateStaminaModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
    {
        setGs2ClientId(gs2ClientId);
        return *this;
    }

    /**
     * タイムスタンプを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2Timestamp タイムスタンプ
     */
    UpdateStaminaModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
    {
        setGs2Timestamp(gs2Timestamp);
        return *this;
    }

    /**
     * GS2認証署名を設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2RequestSign GS2認証署名
     */
    UpdateStaminaModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateStaminaModelMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }

    virtual const Char* getModuleName() const
    {
        return MODULE;
    }

    virtual const Char* getFunctionName() const
    {
        return FUNCTION;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_UPDATESTAMINAMODELMASTERREQUEST_HPP_