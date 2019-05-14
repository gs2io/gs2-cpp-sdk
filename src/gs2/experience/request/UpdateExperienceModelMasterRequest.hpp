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

#ifndef GS2_EXPERIENCE_CONTROL_UPDATEEXPERIENCEMODELMASTERREQUEST_HPP_
#define GS2_EXPERIENCE_CONTROL_UPDATEEXPERIENCEMODELMASTERREQUEST_HPP_

#include <gs2/core/control/Gs2BasicRequest.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include "../Gs2ExperienceConst.hpp"
#include "../model/model.hpp"

namespace gs2 { namespace experience
{

/**
 * 経験値の種類を更新 のリクエストモデル
 *
 * @author Game Server Services, Inc.
 */
class UpdateExperienceModelMasterRequest : public Gs2BasicRequest, public Gs2Experience
{
public:
    constexpr static const Char* const FUNCTION = "";

private:
    class Data : public Gs2Object
    {
    public:
        /** 経験値名 */
        optional<StringHolder> experienceName;
        /** 経験値の種類名 */
        optional<StringHolder> experienceModelName;
        /** 経験値の種類の説明 */
        optional<StringHolder> description;
        /** 経験値の種類のメタデータ */
        optional<StringHolder> metadata;
        /** 経験値の初期値 */
        optional<Int64> defaultExperience;
        /** ランクキャップの初期値 */
        optional<Int64> defaultRankCap;
        /** ランクキャップの最大値 */
        optional<Int64> maxRankCap;
        /** ランク計算に用いるランクアップ閾値 のGRN */
        optional<StringHolder> rankThresholdId;

        Data()
        {}

        Data(const Data& data) :
            Gs2Object(data),
            experienceName(data.experienceName),
            experienceModelName(data.experienceModelName),
            description(data.description),
            metadata(data.metadata),
            defaultExperience(data.defaultExperience),
            defaultRankCap(data.defaultRankCap),
            maxRankCap(data.maxRankCap),
            rankThresholdId(data.rankThresholdId)
        {}

        Data(Data&& data) :
            Gs2Object(std::move(data)),
            experienceName(std::move(data.experienceName)),
            experienceModelName(std::move(data.experienceModelName)),
            description(std::move(data.description)),
            metadata(std::move(data.metadata)),
            defaultExperience(std::move(data.defaultExperience)),
            defaultRankCap(std::move(data.defaultRankCap)),
            maxRankCap(std::move(data.maxRankCap)),
            rankThresholdId(std::move(data.rankThresholdId))
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
    UpdateExperienceModelMasterRequest() :
        m_pData(nullptr)
    {}

    UpdateExperienceModelMasterRequest(const UpdateExperienceModelMasterRequest& obj) :
        Gs2BasicRequest(obj),
        Gs2Experience(obj),
        m_pData(obj.m_pData != nullptr ? new Data(*obj.m_pData) : nullptr)
    {}

    UpdateExperienceModelMasterRequest(UpdateExperienceModelMasterRequest&& obj) :
        Gs2BasicRequest(std::move(obj)),
        Gs2Experience(std::move(obj)),
        m_pData(obj.m_pData)
    {
        obj.m_pData = nullptr;
    }

    ~UpdateExperienceModelMasterRequest()
    {
        if (m_pData != nullptr)
        {
            delete m_pData;
        }
    }

    UpdateExperienceModelMasterRequest& operator=(const UpdateExperienceModelMasterRequest& updateExperienceModelMasterRequest)
    {
        Gs2BasicRequest::operator=(updateExperienceModelMasterRequest);
        Gs2Experience::operator=(updateExperienceModelMasterRequest);

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = new Data(*updateExperienceModelMasterRequest.m_pData);

        return *this;
    }

    UpdateExperienceModelMasterRequest& operator=(UpdateExperienceModelMasterRequest&& updateExperienceModelMasterRequest)
    {
        Gs2BasicRequest::operator=(std::move(updateExperienceModelMasterRequest));
        Gs2Experience::operator=(std::move(updateExperienceModelMasterRequest));

        if (m_pData != nullptr)
        {
            delete m_pData;
        }
        m_pData = updateExperienceModelMasterRequest.m_pData;
        updateExperienceModelMasterRequest.m_pData = nullptr;

        return *this;
    }

    const UpdateExperienceModelMasterRequest* operator->() const
    {
        return this;
    }

    UpdateExperienceModelMasterRequest* operator->()
    {
        return this;
    }
    /**
     * 経験値名を取得
     *
     * @return 経験値名
     */
    const optional<StringHolder>& getExperienceName() const
    {
        return ensureData().experienceName;
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    void setExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
    }

    /**
     * 経験値名を設定
     *
     * @param experienceName 経験値名
     */
    UpdateExperienceModelMasterRequest& withExperienceName(const Char* experienceName)
    {
        ensureData().experienceName.emplace(experienceName);
        return *this;
    }

    /**
     * 経験値の種類名を取得
     *
     * @return 経験値の種類名
     */
    const optional<StringHolder>& getExperienceModelName() const
    {
        return ensureData().experienceModelName;
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    void setExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
    }

    /**
     * 経験値の種類名を設定
     *
     * @param experienceModelName 経験値の種類名
     */
    UpdateExperienceModelMasterRequest& withExperienceModelName(const Char* experienceModelName)
    {
        ensureData().experienceModelName.emplace(experienceModelName);
        return *this;
    }

    /**
     * 経験値の種類の説明を取得
     *
     * @return 経験値の種類の説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * 経験値の種類の説明を設定
     *
     * @param description 経験値の種類の説明
     */
    void setDescription(const Char* description)
    {
        ensureData().description.emplace(description);
    }

    /**
     * 経験値の種類の説明を設定
     *
     * @param description 経験値の種類の説明
     */
    UpdateExperienceModelMasterRequest& withDescription(const Char* description)
    {
        ensureData().description.emplace(description);
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
    void setMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
    }

    /**
     * 経験値の種類のメタデータを設定
     *
     * @param metadata 経験値の種類のメタデータ
     */
    UpdateExperienceModelMasterRequest& withMetadata(const Char* metadata)
    {
        ensureData().metadata.emplace(metadata);
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
    UpdateExperienceModelMasterRequest& withDefaultExperience(Int64 defaultExperience)
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
    UpdateExperienceModelMasterRequest& withDefaultRankCap(Int64 defaultRankCap)
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
    UpdateExperienceModelMasterRequest& withMaxRankCap(Int64 maxRankCap)
    {
        ensureData().maxRankCap.emplace(maxRankCap);
        return *this;
    }

    /**
     * ランク計算に用いるランクアップ閾値 のGRNを取得
     *
     * @return ランク計算に用いるランクアップ閾値 のGRN
     */
    const optional<StringHolder>& getRankThresholdId() const
    {
        return ensureData().rankThresholdId;
    }

    /**
     * ランク計算に用いるランクアップ閾値 のGRNを設定
     *
     * @param rankThresholdId ランク計算に用いるランクアップ閾値 のGRN
     */
    void setRankThresholdId(const Char* rankThresholdId)
    {
        ensureData().rankThresholdId.emplace(rankThresholdId);
    }

    /**
     * ランク計算に用いるランクアップ閾値 のGRNを設定
     *
     * @param rankThresholdId ランク計算に用いるランクアップ閾値 のGRN
     */
    UpdateExperienceModelMasterRequest& withRankThresholdId(const Char* rankThresholdId)
    {
        ensureData().rankThresholdId.emplace(rankThresholdId);
        return *this;
    }


    /**
     * GS2認証クライアントIDを設定。
     * 通常は自動的に計算されるため、この値を設定する必要はありません。
     *
     * @param gs2ClientId GS2認証クライアントID
     */
    UpdateExperienceModelMasterRequest& withGs2ClientId(const Char* gs2ClientId)
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
    UpdateExperienceModelMasterRequest& withGs2Timestamp(Int64 gs2Timestamp)
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
    UpdateExperienceModelMasterRequest& withGs2RequestSign(const Char* gs2RequestSign)
    {
        setGs2RequestSign(gs2RequestSign);
        return *this;
    }

    /**
     * GS2リクエストIDを設定。
     *
     * @param gs2RequestId GS2リクエストID
     */
    UpdateExperienceModelMasterRequest& withRequestId(const Char* gs2RequestId)
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

#endif //GS2_EXPERIENCE_CONTROL_UPDATEEXPERIENCEMODELMASTERREQUEST_HPP_