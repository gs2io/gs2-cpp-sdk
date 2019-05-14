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

#ifndef GS2_STAMINA_CONTROL_CREATEMAXSTAMINATABLEMASTERREQUEST_HPP_
#define GS2_STAMINA_CONTROL_CREATEMAXSTAMINATABLEMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2StaminaConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace stamina
{

/**
 * スタミナ最大値テーブルを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateMaxStaminaTableMasterRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** スタミナの種類名 */
        optional<StringHolder> groupName;
        /** 最大スタミナ値テーブル名 */
        optional<StringHolder> name;
        /** スタミナ最大値テーブルの説明 */
        optional<StringHolder> description;
        /** 最大スタミナ値テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の種類 のGRN */
        optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナの最大値テーブル */
        optional<List<Int32>> values;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            groupName(data.groupName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            experienceModelId(data.experienceModelId),
            values(data.values)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            groupName(std::move(data.groupName)),
            name(std::move(data.name)),
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
    CreateMaxStaminaTableMasterRequest() :
        m_pData(nullptr)
    {}

    CreateMaxStaminaTableMasterRequest(const CreateMaxStaminaTableMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Stamina(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    CreateMaxStaminaTableMasterRequest(CreateMaxStaminaTableMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Stamina(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~CreateMaxStaminaTableMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    CreateMaxStaminaTableMasterRequest& operator=(const CreateMaxStaminaTableMasterRequest& createMaxStaminaTableMasterRequest)
    {
        Gs2BasicRequest::operator=(createMaxStaminaTableMasterRequest);
        Gs2Stamina::operator=(createMaxStaminaTableMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*createMaxStaminaTableMasterRequest.m_pData);

        return *this;
    }

    CreateMaxStaminaTableMasterRequest& operator=(CreateMaxStaminaTableMasterRequest&& createMaxStaminaTableMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(createMaxStaminaTableMasterRequest));
        Gs2Stamina::operator=(std::move(createMaxStaminaTableMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = createMaxStaminaTableMasterRequest.m_pData;
        createMaxStaminaTableMasterRequest.m_pData = nullptr;

        return *this;
    }

    const CreateMaxStaminaTableMasterRequest* operator->() const
    {
        return this;
    }

    CreateMaxStaminaTableMasterRequest* operator->()
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
    CreateMaxStaminaTableMasterRequest& withGroupName(const Char* groupName)
    {
        ensureData().groupName.emplace(groupName);
        return *this;
    }

    /**
     * 最大スタミナ値テーブル名を取得
     *
     * @return 最大スタミナ値テーブル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param name 最大スタミナ値テーブル名
     */
    void setName(const Char* name)
    {
        ensureData().name.emplace(name);
    }

    /**
     * 最大スタミナ値テーブル名を設定
     *
     * @param name 最大スタミナ値テーブル名
     */
    CreateMaxStaminaTableMasterRequest& withName(const Char* name)
    {
        ensureData().name.emplace(name);
        return *this;
    }

    /**
     * スタミナ最大値テーブルの説明を取得
     *
     * @return スタミナ最大値テーブルの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * スタミナ最大値テーブルの説明を設定
     *
     * @param description スタミナ最大値テーブルの説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * スタミナ最大値テーブルの説明を設定
     *
     * @param description スタミナ最大値テーブルの説明
     */
    CreateMaxStaminaTableMasterRequest& withDescription(const Char* description)
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
    CreateMaxStaminaTableMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
        return *this;
    }

    /**
     * 経験値の種類 のGRNを取得
     *
     * @return 経験値の種類 のGRN
     */
    const optional<StringHolder>& getExperienceModelId() const
    {
        return ensureData().experienceModelId;
    }

    /**
     * 経験値の種類 のGRNを設定
     *
     * @param experienceModelId 経験値の種類 のGRN
     */
    void setExperienceModelId(const Char* experienceModelId)
    {
        ensureData().experienceModelId.emplace(experienceModelId);
    }

    /**
     * 経験値の種類 のGRNを設定
     *
     * @param experienceModelId 経験値の種類 のGRN
     */
    CreateMaxStaminaTableMasterRequest& withExperienceModelId(const Char* experienceModelId)
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
    CreateMaxStaminaTableMasterRequest& withValues(const List<Int32>& values)
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
    CreateMaxStaminaTableMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    CreateMaxStaminaTableMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    CreateMaxStaminaTableMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateMaxStaminaTableMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_STAMINA_CONTROL_CREATEMAXSTAMINATABLEMASTERREQUEST_HPP_