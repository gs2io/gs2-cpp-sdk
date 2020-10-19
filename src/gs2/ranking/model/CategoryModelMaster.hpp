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

#ifndef GS2_RANKING_MODEL_CATEGORYMODELMASTER_HPP_
#define GS2_RANKING_MODEL_CATEGORYMODELMASTER_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/json/JsonParser.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>
#include <cstring>

namespace gs2 { namespace ranking {

/**
 * カテゴリマスター
 *
 * @author Game Server Services, Inc.
 *
 */
class CategoryModelMaster : public Gs2Object
{
    friend bool operator!=(const CategoryModelMaster& lhs, const CategoryModelMaster& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** カテゴリマスター */
        optional<StringHolder> categoryModelId;
        /** カテゴリモデル名 */
        optional<StringHolder> name;
        /** カテゴリマスターの説明 */
        optional<StringHolder> description;
        /** カテゴリマスターのメタデータ */
        optional<StringHolder> metadata;
        /** スコアの最小値 */
        optional<Int64> minimumValue;
        /** スコアの最大値 */
        optional<Int64> maximumValue;
        /** スコアのソート方向 */
        optional<StringHolder> orderDirection;
        /** ランキングの種類 */
        optional<StringHolder> scope;
        /** ユーザID毎にスコアを1つしか登録されないようにする */
        optional<Bool> uniqueByUserId;
        /** スコアの固定集計開始時刻(時) */
        optional<Int32> calculateFixedTimingHour;
        /** スコアの固定集計開始時刻(分) */
        optional<Int32> calculateFixedTimingMinute;
        /** スコアの集計間隔(分) */
        optional<Int32> calculateIntervalMinutes;
        /** スコアの登録可能期間とするイベントマスター のGRN */
        optional<StringHolder> entryPeriodEventId;
        /** アクセス可能期間とするイベントマスター のGRN */
        optional<StringHolder> accessPeriodEventId;
        /** ランキングの世代 */
        optional<StringHolder> generation;
        /** 作成日時 */
        optional<Int64> createdAt;
        /** 最終更新日時 */
        optional<Int64> updatedAt;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            categoryModelId(data.categoryModelId),
            name(data.name),
            description(data.description),
            metadata(data.metadata),
            minimumValue(data.minimumValue),
            maximumValue(data.maximumValue),
            orderDirection(data.orderDirection),
            scope(data.scope),
            uniqueByUserId(data.uniqueByUserId),
            calculateFixedTimingHour(data.calculateFixedTimingHour),
            calculateFixedTimingMinute(data.calculateFixedTimingMinute),
            calculateIntervalMinutes(data.calculateIntervalMinutes),
            entryPeriodEventId(data.entryPeriodEventId),
            accessPeriodEventId(data.accessPeriodEventId),
            generation(data.generation),
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
            if (std::strcmp(name_, "categoryModelId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->categoryModelId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "name") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->name.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "description") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->description.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "metadata") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->metadata.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "minimumValue") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->minimumValue = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "maximumValue") == 0)
            {
                if (jsonValue.IsInt64())
                {
                    this->maximumValue = jsonValue.GetInt64();
                }
            }
            else if (std::strcmp(name_, "orderDirection") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->orderDirection.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "scope") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->scope.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "uniqueByUserId") == 0)
            {
                if (jsonValue.IsBool())
                {
                    this->uniqueByUserId = jsonValue.GetBool();
                }
            }
            else if (std::strcmp(name_, "calculateFixedTimingHour") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->calculateFixedTimingHour = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "calculateFixedTimingMinute") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->calculateFixedTimingMinute = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "calculateIntervalMinutes") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->calculateIntervalMinutes = jsonValue.GetInt();
                }
            }
            else if (std::strcmp(name_, "entryPeriodEventId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->entryPeriodEventId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "accessPeriodEventId") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->accessPeriodEventId.emplace(jsonValue.GetString());
                }
            }
            else if (std::strcmp(name_, "generation") == 0)
            {
                if (jsonValue.IsString())
                {
                    this->generation.emplace(jsonValue.GetString());
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
    CategoryModelMaster() = default;
    CategoryModelMaster(const CategoryModelMaster& categoryModelMaster) = default;
    CategoryModelMaster(CategoryModelMaster&& categoryModelMaster) = default;
    ~CategoryModelMaster() = default;

    CategoryModelMaster& operator=(const CategoryModelMaster& categoryModelMaster) = default;
    CategoryModelMaster& operator=(CategoryModelMaster&& categoryModelMaster) = default;

    CategoryModelMaster deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CategoryModelMaster);
    }

    const CategoryModelMaster* operator->() const
    {
        return this;
    }

    CategoryModelMaster* operator->()
    {
        return this;
    }
    /**
     * カテゴリマスターを取得
     *
     * @return カテゴリマスター
     */
    const optional<StringHolder>& getCategoryModelId() const
    {
        return ensureData().categoryModelId;
    }

    /**
     * カテゴリマスターを設定
     *
     * @param categoryModelId カテゴリマスター
     */
    void setCategoryModelId(StringHolder categoryModelId)
    {
        ensureData().categoryModelId.emplace(std::move(categoryModelId));
    }

    /**
     * カテゴリマスターを設定
     *
     * @param categoryModelId カテゴリマスター
     */
    CategoryModelMaster& withCategoryModelId(StringHolder categoryModelId)
    {
        setCategoryModelId(std::move(categoryModelId));
        return *this;
    }

    /**
     * カテゴリモデル名を取得
     *
     * @return カテゴリモデル名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カテゴリモデル名を設定
     *
     * @param name カテゴリモデル名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * カテゴリモデル名を設定
     *
     * @param name カテゴリモデル名
     */
    CategoryModelMaster& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * カテゴリマスターの説明を取得
     *
     * @return カテゴリマスターの説明
     */
    const optional<StringHolder>& getDescription() const
    {
        return ensureData().description;
    }

    /**
     * カテゴリマスターの説明を設定
     *
     * @param description カテゴリマスターの説明
     */
    void setDescription(StringHolder description)
    {
        ensureData().description.emplace(std::move(description));
    }

    /**
     * カテゴリマスターの説明を設定
     *
     * @param description カテゴリマスターの説明
     */
    CategoryModelMaster& withDescription(StringHolder description)
    {
        setDescription(std::move(description));
        return *this;
    }

    /**
     * カテゴリマスターのメタデータを取得
     *
     * @return カテゴリマスターのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * カテゴリマスターのメタデータを設定
     *
     * @param metadata カテゴリマスターのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * カテゴリマスターのメタデータを設定
     *
     * @param metadata カテゴリマスターのメタデータ
     */
    CategoryModelMaster& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    /**
     * スコアの最小値を取得
     *
     * @return スコアの最小値
     */
    const optional<Int64>& getMinimumValue() const
    {
        return ensureData().minimumValue;
    }

    /**
     * スコアの最小値を設定
     *
     * @param minimumValue スコアの最小値
     */
    void setMinimumValue(Int64 minimumValue)
    {
        ensureData().minimumValue.emplace(minimumValue);
    }

    /**
     * スコアの最小値を設定
     *
     * @param minimumValue スコアの最小値
     */
    CategoryModelMaster& withMinimumValue(Int64 minimumValue)
    {
        setMinimumValue(minimumValue);
        return *this;
    }

    /**
     * スコアの最大値を取得
     *
     * @return スコアの最大値
     */
    const optional<Int64>& getMaximumValue() const
    {
        return ensureData().maximumValue;
    }

    /**
     * スコアの最大値を設定
     *
     * @param maximumValue スコアの最大値
     */
    void setMaximumValue(Int64 maximumValue)
    {
        ensureData().maximumValue.emplace(maximumValue);
    }

    /**
     * スコアの最大値を設定
     *
     * @param maximumValue スコアの最大値
     */
    CategoryModelMaster& withMaximumValue(Int64 maximumValue)
    {
        setMaximumValue(maximumValue);
        return *this;
    }

    /**
     * スコアのソート方向を取得
     *
     * @return スコアのソート方向
     */
    const optional<StringHolder>& getOrderDirection() const
    {
        return ensureData().orderDirection;
    }

    /**
     * スコアのソート方向を設定
     *
     * @param orderDirection スコアのソート方向
     */
    void setOrderDirection(StringHolder orderDirection)
    {
        ensureData().orderDirection.emplace(std::move(orderDirection));
    }

    /**
     * スコアのソート方向を設定
     *
     * @param orderDirection スコアのソート方向
     */
    CategoryModelMaster& withOrderDirection(StringHolder orderDirection)
    {
        setOrderDirection(std::move(orderDirection));
        return *this;
    }

    /**
     * ランキングの種類を取得
     *
     * @return ランキングの種類
     */
    const optional<StringHolder>& getScope() const
    {
        return ensureData().scope;
    }

    /**
     * ランキングの種類を設定
     *
     * @param scope ランキングの種類
     */
    void setScope(StringHolder scope)
    {
        ensureData().scope.emplace(std::move(scope));
    }

    /**
     * ランキングの種類を設定
     *
     * @param scope ランキングの種類
     */
    CategoryModelMaster& withScope(StringHolder scope)
    {
        setScope(std::move(scope));
        return *this;
    }

    /**
     * ユーザID毎にスコアを1つしか登録されないようにするを取得
     *
     * @return ユーザID毎にスコアを1つしか登録されないようにする
     */
    const optional<Bool>& getUniqueByUserId() const
    {
        return ensureData().uniqueByUserId;
    }

    /**
     * ユーザID毎にスコアを1つしか登録されないようにするを設定
     *
     * @param uniqueByUserId ユーザID毎にスコアを1つしか登録されないようにする
     */
    void setUniqueByUserId(Bool uniqueByUserId)
    {
        ensureData().uniqueByUserId.emplace(uniqueByUserId);
    }

    /**
     * ユーザID毎にスコアを1つしか登録されないようにするを設定
     *
     * @param uniqueByUserId ユーザID毎にスコアを1つしか登録されないようにする
     */
    CategoryModelMaster& withUniqueByUserId(Bool uniqueByUserId)
    {
        setUniqueByUserId(uniqueByUserId);
        return *this;
    }

    /**
     * スコアの固定集計開始時刻(時)を取得
     *
     * @return スコアの固定集計開始時刻(時)
     */
    const optional<Int32>& getCalculateFixedTimingHour() const
    {
        return ensureData().calculateFixedTimingHour;
    }

    /**
     * スコアの固定集計開始時刻(時)を設定
     *
     * @param calculateFixedTimingHour スコアの固定集計開始時刻(時)
     */
    void setCalculateFixedTimingHour(Int32 calculateFixedTimingHour)
    {
        ensureData().calculateFixedTimingHour.emplace(calculateFixedTimingHour);
    }

    /**
     * スコアの固定集計開始時刻(時)を設定
     *
     * @param calculateFixedTimingHour スコアの固定集計開始時刻(時)
     */
    CategoryModelMaster& withCalculateFixedTimingHour(Int32 calculateFixedTimingHour)
    {
        setCalculateFixedTimingHour(calculateFixedTimingHour);
        return *this;
    }

    /**
     * スコアの固定集計開始時刻(分)を取得
     *
     * @return スコアの固定集計開始時刻(分)
     */
    const optional<Int32>& getCalculateFixedTimingMinute() const
    {
        return ensureData().calculateFixedTimingMinute;
    }

    /**
     * スコアの固定集計開始時刻(分)を設定
     *
     * @param calculateFixedTimingMinute スコアの固定集計開始時刻(分)
     */
    void setCalculateFixedTimingMinute(Int32 calculateFixedTimingMinute)
    {
        ensureData().calculateFixedTimingMinute.emplace(calculateFixedTimingMinute);
    }

    /**
     * スコアの固定集計開始時刻(分)を設定
     *
     * @param calculateFixedTimingMinute スコアの固定集計開始時刻(分)
     */
    CategoryModelMaster& withCalculateFixedTimingMinute(Int32 calculateFixedTimingMinute)
    {
        setCalculateFixedTimingMinute(calculateFixedTimingMinute);
        return *this;
    }

    /**
     * スコアの集計間隔(分)を取得
     *
     * @return スコアの集計間隔(分)
     */
    const optional<Int32>& getCalculateIntervalMinutes() const
    {
        return ensureData().calculateIntervalMinutes;
    }

    /**
     * スコアの集計間隔(分)を設定
     *
     * @param calculateIntervalMinutes スコアの集計間隔(分)
     */
    void setCalculateIntervalMinutes(Int32 calculateIntervalMinutes)
    {
        ensureData().calculateIntervalMinutes.emplace(calculateIntervalMinutes);
    }

    /**
     * スコアの集計間隔(分)を設定
     *
     * @param calculateIntervalMinutes スコアの集計間隔(分)
     */
    CategoryModelMaster& withCalculateIntervalMinutes(Int32 calculateIntervalMinutes)
    {
        setCalculateIntervalMinutes(calculateIntervalMinutes);
        return *this;
    }

    /**
     * スコアの登録可能期間とするイベントマスター のGRNを取得
     *
     * @return スコアの登録可能期間とするイベントマスター のGRN
     */
    const optional<StringHolder>& getEntryPeriodEventId() const
    {
        return ensureData().entryPeriodEventId;
    }

    /**
     * スコアの登録可能期間とするイベントマスター のGRNを設定
     *
     * @param entryPeriodEventId スコアの登録可能期間とするイベントマスター のGRN
     */
    void setEntryPeriodEventId(StringHolder entryPeriodEventId)
    {
        ensureData().entryPeriodEventId.emplace(std::move(entryPeriodEventId));
    }

    /**
     * スコアの登録可能期間とするイベントマスター のGRNを設定
     *
     * @param entryPeriodEventId スコアの登録可能期間とするイベントマスター のGRN
     */
    CategoryModelMaster& withEntryPeriodEventId(StringHolder entryPeriodEventId)
    {
        setEntryPeriodEventId(std::move(entryPeriodEventId));
        return *this;
    }

    /**
     * アクセス可能期間とするイベントマスター のGRNを取得
     *
     * @return アクセス可能期間とするイベントマスター のGRN
     */
    const optional<StringHolder>& getAccessPeriodEventId() const
    {
        return ensureData().accessPeriodEventId;
    }

    /**
     * アクセス可能期間とするイベントマスター のGRNを設定
     *
     * @param accessPeriodEventId アクセス可能期間とするイベントマスター のGRN
     */
    void setAccessPeriodEventId(StringHolder accessPeriodEventId)
    {
        ensureData().accessPeriodEventId.emplace(std::move(accessPeriodEventId));
    }

    /**
     * アクセス可能期間とするイベントマスター のGRNを設定
     *
     * @param accessPeriodEventId アクセス可能期間とするイベントマスター のGRN
     */
    CategoryModelMaster& withAccessPeriodEventId(StringHolder accessPeriodEventId)
    {
        setAccessPeriodEventId(std::move(accessPeriodEventId));
        return *this;
    }

    /**
     * ランキングの世代を取得
     *
     * @return ランキングの世代
     */
    const optional<StringHolder>& getGeneration() const
    {
        return ensureData().generation;
    }

    /**
     * ランキングの世代を設定
     *
     * @param generation ランキングの世代
     */
    void setGeneration(StringHolder generation)
    {
        ensureData().generation.emplace(std::move(generation));
    }

    /**
     * ランキングの世代を設定
     *
     * @param generation ランキングの世代
     */
    CategoryModelMaster& withGeneration(StringHolder generation)
    {
        setGeneration(std::move(generation));
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
    CategoryModelMaster& withCreatedAt(Int64 createdAt)
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
    CategoryModelMaster& withUpdatedAt(Int64 updatedAt)
    {
        setUpdatedAt(updatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const CategoryModelMaster& lhs, const CategoryModelMaster& lhr)
{
    if (lhs.m_pData != lhr.m_pData)
    {
        if (!lhs.m_pData || !lhr.m_pData)
        {
            return true;
        }
        if (lhs.m_pData->categoryModelId != lhr.m_pData->categoryModelId)
        {
            return true;
        }
        if (lhs.m_pData->name != lhr.m_pData->name)
        {
            return true;
        }
        if (lhs.m_pData->description != lhr.m_pData->description)
        {
            return true;
        }
        if (lhs.m_pData->metadata != lhr.m_pData->metadata)
        {
            return true;
        }
        if (lhs.m_pData->minimumValue != lhr.m_pData->minimumValue)
        {
            return true;
        }
        if (lhs.m_pData->maximumValue != lhr.m_pData->maximumValue)
        {
            return true;
        }
        if (lhs.m_pData->orderDirection != lhr.m_pData->orderDirection)
        {
            return true;
        }
        if (lhs.m_pData->scope != lhr.m_pData->scope)
        {
            return true;
        }
        if (lhs.m_pData->uniqueByUserId != lhr.m_pData->uniqueByUserId)
        {
            return true;
        }
        if (lhs.m_pData->calculateFixedTimingHour != lhr.m_pData->calculateFixedTimingHour)
        {
            return true;
        }
        if (lhs.m_pData->calculateFixedTimingMinute != lhr.m_pData->calculateFixedTimingMinute)
        {
            return true;
        }
        if (lhs.m_pData->calculateIntervalMinutes != lhr.m_pData->calculateIntervalMinutes)
        {
            return true;
        }
        if (lhs.m_pData->entryPeriodEventId != lhr.m_pData->entryPeriodEventId)
        {
            return true;
        }
        if (lhs.m_pData->accessPeriodEventId != lhr.m_pData->accessPeriodEventId)
        {
            return true;
        }
        if (lhs.m_pData->generation != lhr.m_pData->generation)
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

inline bool operator==(const CategoryModelMaster& lhs, const CategoryModelMaster& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_RANKING_MODEL_CATEGORYMODELMASTER_HPP_