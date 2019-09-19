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

#ifndef GS2_EXPERIENCE_CONTROL_CREATEEXPERIENCEMODELMASTERREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_CREATEEXPERIENCEMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"
#include <memory>

namespace gs2 { namespace experience
{

/**
 * 経験値の種類マスターを新規作成 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class CreateExperienceModelMasterRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2BasicRequest::Data
    {
    public:
        /** ネームスペース名 */
        optional<StringHolder> namespaceName;
        /** 経験値の種類名 */
        optional<StringHolder> name;
        /** 経験値の種類マスターの説明 */
        optional<StringHolder> description;
        /** 経験値の種類のメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の初期値 */
        optional<Int64> defaultExperience;
        /** ランクキャップの初期値 */
        optional<Int64> defaultRankCap;
        /** ランクキャップの最大値 */
        optional<Int64> maxRankCap;
        /** ランク計算に用いる */
        optional<StringHolder> rankThresholdId;

        Data() = default;

        Data(const Data& data) :
            Gs2BasicRequest::Data(data),
            namespaceName(data.namespaceName),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            defaultExperience(data.defaultExperience),
            defaultRankCap(data.defaultRankCap),
            maxRankCap(data.maxRankCap),
            rankThresholdId(data.rankThresholdId)
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
    CreateExperienceModelMasterRequest() = default;
    CreateExperienceModelMasterRequest(const CreateExperienceModelMasterRequest& createExperienceModelMasterRequest) = default;
    CreateExperienceModelMasterRequest(CreateExperienceModelMasterRequest&& createExperienceModelMasterRequest) = default;
    ~CreateExperienceModelMasterRequest() GS2_OVERRIDE = default;

    CreateExperienceModelMasterRequest& operator=(const CreateExperienceModelMasterRequest& createExperienceModelMasterRequest) = default;
    CreateExperienceModelMasterRequest& operator=(CreateExperienceModelMasterRequest&& createExperienceModelMasterRequest) = default;

    CreateExperienceModelMasterRequest deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CreateExperienceModelMasterRequest);
    }

    const CreateExperienceModelMasterRequest* operator->() const
    {
        return this;
    }

    CreateExperienceModelMasterRequest* operator->()
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
    CreateExperienceModelMasterRequest& withNamespaceName(StringHolder namespaceName)
    {
        ensureData().namespaceName.emplace(std::move(namespaceName));
        return *this;
    }

    /**
     * 経験値の種類名を取得
     *
     * @return 経験値の種類名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * 経験値の種類名を設定
     *
     * @param name 経験値の種類名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * 経験値の種類名を設定
     *
     * @param name 経験値の種類名
     */
    CreateExperienceModelMasterRequest& withName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
        return *this;
    }

    /**
     * 経験値の種類マスターの説明を取得
     *
     * @return 経験値の種類マスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 経験値の種類マスターの説明を設定
     *
     * @param description 経験値の種類マスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * 経験値の種類マスターの説明を設定
     *
     * @param description 経験値の種類マスターの説明
     */
    CreateExperienceModelMasterRequest& withDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
        return *this;
    }

    /**
     * 経験値の種類のメタデータを取得
     *
     * @return 経験値の種類のメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * 経験値の種類のメタデータを設定
     *
     * @param metadata 経験値の種類のメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * 経験値の種類のメタデータを設定
     *
     * @param metadata 経験値の種類のメタデータ
     */
    CreateExperienceModelMasterRequest& withMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
        return *this;
    }

    /**
     * 経験値の初期値を取得
     *
     * @return 経験値の初期値
     */
    const optional<Int64>& getDefaultExperience() const
    {
        return ensureData().defaultExperience;
    }

    /**
     * 経験値の初期値を設定
     *
     * @param defaultExperience 経験値の初期値
     */
    void setDefaultExperience(Int64 defaultExperience)
    {
        ensureData().defaultExperience.emplace(defaultExperience);
    }

    /**
     * 経験値の初期値を設定
     *
     * @param defaultExperience 経験値の初期値
     */
    CreateExperienceModelMasterRequest& withDefaultExperience(Int64 defaultExperience)
    {
        ensureData().defaultExperience.emplace(defaultExperience);
        return *this;
    }

    /**
     * ランクキャップの初期値を取得
     *
     * @return ランクキャップの初期値
     */
    const optional<Int64>& getDefaultRankCap() const
    {
        return ensureData().defaultRankCap;
    }

    /**
     * ランクキャップの初期値を設定
     *
     * @param defaultRankCap ランクキャップの初期値
     */
    void setDefaultRankCap(Int64 defaultRankCap)
    {
        ensureData().defaultRankCap.emplace(defaultRankCap);
    }

    /**
     * ランクキャップの初期値を設定
     *
     * @param defaultRankCap ランクキャップの初期値
     */
    CreateExperienceModelMasterRequest& withDefaultRankCap(Int64 defaultRankCap)
    {
        ensureData().defaultRankCap.emplace(defaultRankCap);
        return *this;
    }

    /**
     * ランクキャップの最大値を取得
     *
     * @return ランクキャップの最大値
     */
    const optional<Int64>& getMaxRankCap() const
    {
        return ensureData().maxRankCap;
    }

    /**
     * ランクキャップの最大値を設定
     *
     * @param maxRankCap ランクキャップの最大値
     */
    void setMaxRankCap(Int64 maxRankCap)
    {
        ensureData().maxRankCap.emplace(maxRankCap);
    }

    /**
     * ランクキャップの最大値を設定
     *
     * @param maxRankCap ランクキャップの最大値
     */
    CreateExperienceModelMasterRequest& withMaxRankCap(Int64 maxRankCap)
    {
        ensureData().maxRankCap.emplace(maxRankCap);
        return *this;
    }

    /**
     * ランク計算に用いるを取得
     *
     * @return ランク計算に用いる
     */
    const optional<StringHolder>& getRankThresholdId() const
    {
        return ensureData().rankThresholdId;
    }

    /**
     * ランク計算に用いるを設定
     *
     * @param rankThresholdId ランク計算に用いる
     */
    void setRankThresholdId(StringHolder rankThresholdId)
    {
        ensureData().rankThresholdId.emplace(std::move(rankThresholdId));
    }

    /**
     * ランク計算に用いるを設定
     *
     * @param rankThresholdId ランク計算に用いる
     */
    CreateExperienceModelMasterRequest& withRankThresholdId(StringHolder rankThresholdId)
    {
        ensureData().rankThresholdId.emplace(std::move(rankThresholdId));
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    CreateExperienceModelMasterRequest& withGs2ClientId(StringHolder gs2ClientId)
    {
        setGs2ClientId(std::move(gs2ClientId));
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    CreateExperienceModelMasterRequest& withRequestId(StringHolder gs2RequestId)
    {
        setRequestId(std::move(gs2RequestId));
        return *this;
    }
};

} }

#endif //GS2_EXPERIENCE_CONTROL_CREATEEXPERIENCEMODELMASTERREQUEST_HPP_