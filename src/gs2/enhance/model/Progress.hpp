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

#ifndef GS2_ENHANCE_MODEL_PROGRESS_HPP_
#define GS2_ENHANCE_MODEL_PROGRESS_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace enhance {

/**
 * 強化実行
 *
 * @author Game Server Services, Inc.
 *
 */
class Progress : public Gs2Object
{
    friend bool operator!=(const Progress& lhs, const Progress& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** 強化実行 */
        optional<StringHolder> progressId;
        /** ユーザーID */
        optional<StringHolder> userId;
        /** レートモデル名 */
        optional<StringHolder> rateName;
        /** 強化対象のプロパティID */
        optional<StringHolder> propertyId;
        /** 入手できる経験値 */
        optional<Int32> experienceValue;
        /** 経験値倍率 */
        optional<Float> rate;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            progressId(data.progressId),
            userId(data.userId),
            rateName(data.rateName),
            propertyId(data.propertyId),
            experienceValue(data.experienceValue),
            rate(data.rate),
            createdAt(data.createdAt),
            updatedAt(data.updatedAt)
        {
        }

        Data(Data&& data) = default;

        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        virtual void set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
        {
            if (std::strcmp(name_, "progressId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->progressId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "userId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->userId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "rateName") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->rateName.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "propertyId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->propertyId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "experienceValue") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->experienceValue = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "rate") == 0)
            {
                if (jsonValue.IsFloat())
                {
                    this->rate = jsonValue.GetFloat();
                }
            }
            else if (std::strcmp(name_, "createdAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->createdAt = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "updatedAt") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->updatedAt = jsonValue.GetInt64();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    Progress() = default;
    Progress(const Progress& progress) = default;
    Progress(Progress&& progress) = default;
    ~Progress() = default;

    Progress& operator=(const Progress& progress) = default;
    Progress& operator=(Progress&& progress) = default;

    Progress deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Progress);
    }

    const Progress* operator->() const
    {
        return this;
    }

    Progress* operator->()
    {
        return this;
    }
    /**
     * 強化実行を取得
     *
     * @return 強化実行
     */
    const optional<StringHolder>& getProgressId() const
    {
        return ensureData().progressId;
    }

    /**
     * 強化実行を設定
     *
     * @param progressId 強化実行
     */
    void setProgressId(StringHolder progressId)
    {
        ensureData().progressId.emplace(std::move(progressId));
    }

    /**
     * 強化実行を設定
     *
     * @param progressId 強化実行
     */
    Progress& withProgressId(StringHolder progressId)
    {
        setProgressId(std::move(progressId));
        return *this;
    }

    /**
     * ユーザーIDを取得
     *
     * @return ユーザーID
     */
    const optional<StringHolder>& getUserId() const
    {
        return ensureData().userId;
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    void setUserId(StringHolder userId)
    {
        ensureData().userId.emplace(std::move(userId));
    }

    /**
     * ユーザーIDを設定
     *
     * @param userId ユーザーID
     */
    Progress& withUserId(StringHolder userId)
    {
        setUserId(std::move(userId));
        return *this;
    }

    /**
     * レートモデル名を取得
     *
     * @return レートモデル名
     */
    const optional<StringHolder>& getRateName() const
    {
        return ensureData().rateName;
    }

    /**
     * レートモデル名を設定
     *
     * @param rateName レートモデル名
     */
    void setRateName(StringHolder rateName)
    {
        ensureData().rateName.emplace(std::move(rateName));
    }

    /**
     * レートモデル名を設定
     *
     * @param rateName レートモデル名
     */
    Progress& withRateName(StringHolder rateName)
    {
        setRateName(std::move(rateName));
        return *this;
    }

    /**
     * 強化対象のプロパティIDを取得
     *
     * @return 強化対象のプロパティID
     */
    const optional<StringHolder>& getPropertyId() const
    {
        return ensureData().propertyId;
    }

    /**
     * 強化対象のプロパティIDを設定
     *
     * @param propertyId 強化対象のプロパティID
     */
    void setPropertyId(StringHolder propertyId)
    {
        ensureData().propertyId.emplace(std::move(propertyId));
    }

    /**
     * 強化対象のプロパティIDを設定
     *
     * @param propertyId 強化対象のプロパティID
     */
    Progress& withPropertyId(StringHolder propertyId)
    {
        setPropertyId(std::move(propertyId));
        return *this;
    }

    /**
     * 入手できる経験値を取得
     *
     * @return 入手できる経験値
     */
    const optional<Int32>& getExperienceValue() const
    {
        return ensureData().experienceValue;
    }

    /**
     * 入手できる経験値を設定
     *
     * @param experienceValue 入手できる経験値
     */
    void setExperienceValue(Int32 experienceValue)
    {
        ensureData().experienceValue.emplace(experienceValue);
    }

    /**
     * 入手できる経験値を設定
     *
     * @param experienceValue 入手できる経験値
     */
    Progress& withExperienceValue(Int32 experienceValue)
    {
        setExperienceValue(experienceValue);
        return *this;
    }

    /**
     * 経験値倍率を取得
     *
     * @return 経験値倍率
     */
    const optional<Float>& getRate() const
    {
        return ensureData().rate;
    }

    /**
     * 経験値倍率を設定
     *
     * @param rate 経験値倍率
     */
    void setRate(Float rate)
    {
        ensureData().rate.emplace(rate);
    }

    /**
     * 経験値倍率を設定
     *
     * @param rate 経験値倍率
     */
    Progress& withRate(Float rate)
    {
        setRate(rate);
        return *this;
    }

    /**
     * 作成日時を取得
     *
     * @return 作成日時
     */
    const optional<Int64>& getCreatedAt() const
    {
        return ensureData().createdAt;
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    void setCreatedAt(Int64 createdAt)
    {
        ensureData().createdAt.emplace(createdAt);
    }

    /**
     * 作成日時を設定
     *
     * @param createdAt 作成日時
     */
    Progress& withCreatedAt(Int64 createdAt)
    {
        setCreatedAt(createdAt);
        return *this;
    }

    /**
     * 最終更新日時を取得
     *
     * @return 最終更新日時
     */
    const optional<Int64>& getUpdatedAt() const
    {
        return ensureData().updatedAt;
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    void setUpdatedAt(Int64 updatedAt)
    {
        ensureData().updatedAt.emplace(updatedAt);
    }

    /**
     * 最終更新日時を設定
     *
     * @param updatedAt 最終更新日時
     */
    Progress& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const Progress& lhs, const Progress& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->progressId != lhr.m_pData->progressId)
        {
            return true;
        }
        if (lhs.m_pData->userId != lhr.m_pData->userId)
        {
            return true;
        }
        if (lhs.m_pData->rateName != lhr.m_pData->rateName)
        {
            return true;
        }
        if (lhs.m_pData->propertyId != lhr.m_pData->propertyId)
        {
            return true;
        }
        if (lhs.m_pData->experienceValue != lhr.m_pData->experienceValue)
        {
            return true;
        }
        if (lhs.m_pData->rate != lhr.m_pData->rate)
        {
            return true;
        }
        if (lhs.m_pData->createdAt != lhr.m_pData->createdAt)
        {
            return true;
        }
        if (lhs.m_pData->updatedAt != lhr.m_pData->updatedAt)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const Progress& lhs, const Progress& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_ENHANCE_MODEL_PROGRESS_HPP_