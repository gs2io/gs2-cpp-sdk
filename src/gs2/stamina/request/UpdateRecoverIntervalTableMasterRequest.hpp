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

#ifndef GS2_STAMINA_CONTROL_UPDATERECOVERINTERVALTABLEMASTERREQUEST_HPP_
#define GS2_STAMINA_CONTROL_UPDATERECOVERINTERVALTABLEMASTERREQUEST_HPP_

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
 * スタミナ回復間隔テーブルマスターを更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateRecoverIntervalTableMasterRequest : public Gs2BasicRequest, public Gs2Stamina
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** スタミナ回復間隔テーブル名 */
        optional<StringHolder> recoverIntervalTableName;
        /** スタミナ回復間隔テーブルマスターの説明 */
        optional<StringHolder> description;
        /** スタミナ回復間隔テーブルのメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の種類マスター のGRN */
        optional<StringHolder> experienceModelId;
        /** ランク毎のスタミナ回復間隔テーブル */
        optional<List<Int32>> values;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            recoverIntervalTableName(data.recoverIntervalTableName),
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
    UpdateRecoverIntervalTableMasterRequest() = default;
    UpdateRecoverIntervalTableMasterRequest(const UpdateRecoverIntervalTableMasterRequest& updateRecoverIntervalTableMasterRequest) = default;
    UpdateRecoverIntervalTableMasterRequest(UpdateRecoverIntervalTableMasterRequest&& updateRecoverIntervalTableMasterRequest) = default;
    ~UpdateRecoverIntervalTableMasterRequest() GS2_OVERRIDE = default;

    UpdateRecoverIntervalTableMasterRequest& operator=(const UpdateRecoverIntervalTableMasterRequest& updateRecoverIntervalTableMasterRequest) = default;
    UpdateRecoverIntervalTableMasterRequest& operator=(UpdateRecoverIntervalTableMasterRequest&& updateRecoverIntervalTableMasterRequest) = default;

    UpdateRecoverIntervalTableMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(UpdateRecoverIntervalTableMasterRequest);
    }

    const UpdateRecoverIntervalTableMasterRequest* operator->() const
    {
        return this;
    }

    UpdateRecoverIntervalTableMasterRequest* operator->()
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
    UpdateRecoverIntervalTableMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * スタミナ回復間隔テーブル名を取得
     *
     * @return スタミナ回復間隔テーブル名
     */
    const optional<StringHolder>& getRecoverIntervalTableName() const
    {
        return ensureData().recoverIntervalTableName;
    }

    /**
     * スタミナ回復間隔テーブル名を設定
     *
     * @param recoverIntervalTableName スタミナ回復間隔テーブル名
     */
    void setRecoverIntervalTableName(StringHolder recoverIntervalTableName)
    {
        ensureData().recoverIntervalTableName.emplace(std::move(recoverIntervalTableName));
    }

    /**
     * スタミナ回復間隔テーブル名を設定
     *
     * @param recoverIntervalTableName スタミナ回復間隔テーブル名
     */
    UpdateRecoverIntervalTableMasterRequest& withRecoverIntervalTableName(StringHolder recoverIntervalTableName)
    {
        ensureData().recoverIntervalTableName.emplace(std::move(recoverIntervalTableName));
        return *this;
    }

    /**
     * スタミナ回復間隔テーブルマスターの説明を取得
     *
     * @return スタミナ回復間隔テーブルマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * スタミナ回復間隔テーブルマスターの説明を設定
     *
     * @param description スタミナ回復間隔テーブルマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * スタミナ回復間隔テーブルマスターの説明を設定
     *
     * @param description スタミナ回復間隔テーブルマスターの説明
     */
    UpdateRecoverIntervalTableMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * スタミナ回復間隔テーブルのメタデータを取得
     *
     * @return スタミナ回復間隔テーブルのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * スタミナ回復間隔テーブルのメタデータを設定
     *
     * @param metadata スタミナ回復間隔テーブルのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * スタミナ回復間隔テーブルのメタデータを設定
     *
     * @param metadata スタミナ回復間隔テーブルのメタデータ
     */
    UpdateRecoverIntervalTableMasterRequest& withMetadata(StringHolder metadata)
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
    UpdateRecoverIntervalTableMasterRequest& withExperienceModelId(StringHolder experienceModelId)
    {
        ensureData().experienceModelId.emplace(std::move(experienceModelId));
        return *this;
    }

    /**
     * ランク毎のスタミナ回復間隔テーブルを取得
     *
     * @return ランク毎のスタミナ回復間隔テーブル
     */
    const optional<List<Int32>>& getValues() const
    {
        return ensureData().values;
    }

    /**
     * ランク毎のスタミナ回復間隔テーブルを設定
     *
     * @param values ランク毎のスタミナ回復間隔テーブル
     */
    void setValues(List<Int32> values)
    {
        ensureData().values.emplace(std::move(values));
    }

    /**
     * ランク毎のスタミナ回復間隔テーブルを設定
     *
     * @param values ランク毎のスタミナ回復間隔テーブル
     */
    UpdateRecoverIntervalTableMasterRequest& withValues(List<Int32> values)
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
    UpdateRecoverIntervalTableMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateRecoverIntervalTableMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_STAMINA_CONTROL_UPDATERECOVERINTERVALTABLEMASTERREQUEST_HPP_