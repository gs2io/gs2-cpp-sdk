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

#ifndef GS2_RANKING_MODEL_CATEGORYMODEL_HPP_
#define GS2_RANKING_MODEL_CATEGORYMODEL_HPP_

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
 * カテゴリ
 *
 * @author Game Server Services, Inc.
 *
 */
class CategoryModel : public Gs2Object
{
    friend bool operator!=(const CategoryModel& lhs, const CategoryModel& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** カテゴリ */
        optional<StringHolder> categoryModelId;
        /** カテゴリ名 */
        optional<StringHolder> name;
        /** カテゴリのメタデータ */
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
        /** スコアの集計間隔(分) */
        optional<Int32> calculateIntervalMinutes;

        Data() = default;

        Data(const Data& data) :
            detail::json::IModel(data),
            categoryModelId(data.categoryModelId),
            name(data.name),
            metadata(data.metadata),
            minimumValue(data.minimumValue),
            maximumValue(data.maximumValue),
            orderDirection(data.orderDirection),
            scope(data.scope),
            uniqueByUserId(data.uniqueByUserId),
            calculateIntervalMinutes(data.calculateIntervalMinutes)
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
            else if (std::strcmp(name_, "calculateIntervalMinutes") == 0)
            {
                if (jsonValue.IsInt())
                {
                    this->calculateIntervalMinutes = jsonValue.GetInt();
                }
            }
        }
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CategoryModel() = default;
    CategoryModel(const CategoryModel& categoryModel) = default;
    CategoryModel(CategoryModel&& categoryModel) = default;
    ~CategoryModel() = default;

    CategoryModel& operator=(const CategoryModel& categoryModel) = default;
    CategoryModel& operator=(CategoryModel&& categoryModel) = default;

    CategoryModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CategoryModel);
    }

    const CategoryModel* operator->() const
    {
        return this;
    }

    CategoryModel* operator->()
    {
        return this;
    }
    /**
     * カテゴリを取得
     *
     * @return カテゴリ
     */
    const optional<StringHolder>& getCategoryModelId() const
    {
        return ensureData().categoryModelId;
    }

    /**
     * カテゴリを設定
     *
     * @param categoryModelId カテゴリ
     */
    void setCategoryModelId(StringHolder categoryModelId)
    {
        ensureData().categoryModelId.emplace(std::move(categoryModelId));
    }

    /**
     * カテゴリを設定
     *
     * @param categoryModelId カテゴリ
     */
    CategoryModel& withCategoryModelId(StringHolder categoryModelId)
    {
        setCategoryModelId(std::move(categoryModelId));
        return *this;
    }

    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getName() const
    {
        return ensureData().name;
    }

    /**
     * カテゴリ名を設定
     *
     * @param name カテゴリ名
     */
    void setName(StringHolder name)
    {
        ensureData().name.emplace(std::move(name));
    }

    /**
     * カテゴリ名を設定
     *
     * @param name カテゴリ名
     */
    CategoryModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    /**
     * カテゴリのメタデータを取得
     *
     * @return カテゴリのメタデータ
     */
    const optional<StringHolder>& getMetadata() const
    {
        return ensureData().metadata;
    }

    /**
     * カテゴリのメタデータを設定
     *
     * @param metadata カテゴリのメタデータ
     */
    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata.emplace(std::move(metadata));
    }

    /**
     * カテゴリのメタデータを設定
     *
     * @param metadata カテゴリのメタデータ
     */
    CategoryModel& withMetadata(StringHolder metadata)
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
    CategoryModel& withMinimumValue(Int64 minimumValue)
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
    CategoryModel& withMaximumValue(Int64 maximumValue)
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
    CategoryModel& withOrderDirection(StringHolder orderDirection)
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
    CategoryModel& withScope(StringHolder scope)
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
    CategoryModel& withUniqueByUserId(Bool uniqueByUserId)
    {
        setUniqueByUserId(uniqueByUserId);
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
    CategoryModel& withCalculateIntervalMinutes(Int32 calculateIntervalMinutes)
    {
        setCalculateIntervalMinutes(calculateIntervalMinutes);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

inline bool operator!=(const CategoryModel& lhs, const CategoryModel& lhr)
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
        if (lhs.m_pData->calculateIntervalMinutes != lhr.m_pData->calculateIntervalMinutes)
        {
            return true;
        }
    }
    return false;
}

inline bool operator==(const CategoryModel& lhs, const CategoryModel& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_RANKING_MODEL_CATEGORYMODEL_HPP_