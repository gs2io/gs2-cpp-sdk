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
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

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
    class Data : public Gs2Object
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

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            namespaceName(data.namespaceName),
            maxStaminaTableName(data.maxStaminaTableName),
            description(data.description),
            metadata(data.metadata),
            experienceModelId(data.experienceModelId),
            values(data.values)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            namespaceName(std::move(data.namespaceName)),
            maxStaminaTableName(std::move(data.maxStaminaTableName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            experienceModelId(std::move(data.experienceModelId)),
            values(std::move(data.values))
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
    UpdateMaxStaminaTableMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateMaxStaminaTableMasterRequest(const UpdateMaxStaminaTableMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateMaxStaminaTableMasterRequest(UpdateMaxStaminaTableMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateMaxStaminaTableMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateMaxStaminaTableMasterRequest& operator=(const UpdateMaxStaminaTableMasterRequest& updateMaxStaminaTableMasterRequest)
    {
        Gs2BasicRequest::operator=(updateMaxStaminaTableMasterRequest);
        Gs2Stamina::operator=(updateMaxStaminaTableMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateMaxStaminaTableMasterRequest.m_pData);

        return *this;
    }

    UpdateMaxStaminaTableMasterRequest& operator=(UpdateMaxStaminaTableMasterRequest&& updateMaxStaminaTableMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateMaxStaminaTableMasterRequest));
        Gs2Stamina::operator=(std::move(updateMaxStaminaTableMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateMaxStaminaTableMasterRequest.m_pData;
        updateMaxStaminaTableMasterRequest.m_pData = nullptr;

        return *this;
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
    void setNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
    }

    /**
     * ネームスペース名を設定
     *
     * @param namespaceName ネームスペース名
     */
    UpdateMaxStaminaTableMasterRequest& withNamespaceName(const Char* namespaceName)
    {
        ensureData().namespaceName.emplace(namespaceName);
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
    void setMaxStaminaTableName(const Char* maxStaminaTableName)
    {
        ensureData().maxStaminaTableName.emplace(maxStaminaTableName);
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param maxStaminaTableName 最大スタミナ値テーブル名
     */
    UpdateMaxStaminaTableMasterRequest& withMaxStaminaTableName(const Char* maxStaminaTableName)
    {
        ensureData().maxStaminaTableName.emplace(maxStaminaTableName);
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
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スタミナの最大値テーブルマスターの説明を設定
     *
     * @param description スタミナの最大値テーブルマスターの説明
     */
    UpdateMaxStaminaTableMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 最大スタミナ値テーブルのメタデータを設定
     *
     * @param metadata 最大スタミナ値テーブルのメタデータ
     */
    UpdateMaxStaminaTableMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
    void setExperienceModelId(const Char* experienceModelId)
    {
        ensureData().experienceModelId.emplace(experienceModelId);
    }

    /**
     * 経験値の種類マスター のGRNを設定
     *
     * @param experienceModelId 経験値の種類マスター のGRN
     */
    UpdateMaxStaminaTableMasterRequest& withExperienceModelId(const Char* experienceModelId)
    {
        ensureData().experienceModelId.emplace(experienceModelId);
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
    void setValues(const List<Int32>& values)
    {
        ensureData().values.emplace(values);
    }

    /**
     * ランク毎のスタミナの最大値テーブルを設定
     *
     * @param values ランク毎のスタミナの最大値テーブル
     */
    UpdateMaxStaminaTableMasterRequest& withValues(const List<Int32>& values)
    {
        ensureData().values.emplace(values);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateMaxStaminaTableMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateMaxStaminaTableMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateMaxStaminaTableMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateMaxStaminaTableMasterRequest& withRequestId(const Char* gs2RequestId)
    {
        setRequestId(gs2RequestId);
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_UPDATEMAXSTAMINATABLEMASTERREQUEST_HPP_