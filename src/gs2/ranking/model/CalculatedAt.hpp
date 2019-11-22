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

#ifndef GS2_RANKING_MODEL_CALCULATEDAT_HPP_
#define GS2_RANKING_MODEL_CALCULATEDAT_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/json/IModel.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>

namespace gs2 { namespace ranking {

/**
 * 集計日時
 *
 * @author Game Server Services, Inc.
 *
 */
class CalculatedAt : public Gs2Object
{
    friend bool operator!=(const CalculatedAt& lhs, const CalculatedAt& lhr);

private:
    class Data : public detail::json::IModel
    {
    public:
        /** カテゴリ名 */
        optional<StringHolder> categoryName;
        /** 集計日時 */
        optional<Int64> calculatedAt;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        ~Data() GS2_OVERRIDE = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;

        void set(const Char name_[], const detail::json::JsonConstValue& jsonValue) GS2_OVERRIDE;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    CalculatedAt() = default;
    CalculatedAt(const CalculatedAt& calculatedAt) = default;
    CalculatedAt(CalculatedAt&& calculatedAt) = default;
    ~CalculatedAt() = default;

    CalculatedAt& operator=(const CalculatedAt& calculatedAt) = default;
    CalculatedAt& operator=(CalculatedAt&& calculatedAt) = default;

    CalculatedAt deepCopy() const;

    const CalculatedAt* operator->() const
    {
        return this;
    }

    CalculatedAt* operator->()
    {
        return this;
    }
    /**
     * カテゴリ名を取得
     *
     * @return カテゴリ名
     */
    const optional<StringHolder>& getCategoryName() const
    {
        return ensureData().categoryName;
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    void setCategoryName(StringHolder categoryName)
    {
        ensureData().categoryName.emplace(std::move(categoryName));
    }

    /**
     * カテゴリ名を設定
     *
     * @param categoryName カテゴリ名
     */
    CalculatedAt& withCategoryName(StringHolder categoryName)
    {
        setCategoryName(std::move(categoryName));
        return *this;
    }

    /**
     * 集計日時を取得
     *
     * @return 集計日時
     */
    const optional<Int64>& getCalculatedAt() const
    {
        return ensureData().calculatedAt;
    }

    /**
     * 集計日時を設定
     *
     * @param calculatedAt 集計日時
     */
    void setCalculatedAt(Int64 calculatedAt)
    {
        ensureData().calculatedAt.emplace(calculatedAt);
    }

    /**
     * 集計日時を設定
     *
     * @param calculatedAt 集計日時
     */
    CalculatedAt& withCalculatedAt(Int64 calculatedAt)
    {
        setCalculatedAt(calculatedAt);
        return *this;
    }


    detail::json::IModel& getModel()
    {
        return ensureData();
    }
};

bool operator!=(const CalculatedAt& lhs, const CalculatedAt& lhr);

inline bool operator==(const CalculatedAt& lhs, const CalculatedAt& lhr)
{
    return !(lhs != lhr);
}

} }

#endif //GS2_RANKING_MODEL_CALCULATEDAT_HPP_