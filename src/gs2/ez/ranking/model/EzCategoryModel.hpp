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

#ifndef GS2_EZ_RANKING_MODEL_EZCATEGORYMODEL_HPP_
#define GS2_EZ_RANKING_MODEL_EZCATEGORYMODEL_HPP_

#include <gs2/core/Gs2Object.hpp>
#include <gs2/core/util/List.hpp>
#include <gs2/core/util/StringHolder.hpp>
#include <gs2/core/util/StandardAllocator.hpp>
#include <gs2/core/external/optional/optional.hpp>
#include <memory>


namespace gs2 {

namespace ranking {

class CategoryModel;

}

namespace ez { namespace ranking {

class EzCategoryModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** カテゴリ名 */
        StringHolder name;
        /** カテゴリのメタデータ */
        StringHolder metadata;
        /** スコアの登録可能期間とするイベントマスター のGRN */
        StringHolder entryPeriodEventId;
        /** アクセス可能期間とするイベントマスター のGRN */
        StringHolder accessPeriodEventId;

        Data() = default;
        Data(const Data& data);
        Data(Data&& data) = default;
        Data(const gs2::ranking::CategoryModel& categoryModel);
        Data(const gs2::optional<gs2::ranking::CategoryModel>& categoryModel);
        ~Data() = default;

        Data& operator=(const Data&) = delete;
        Data& operator=(Data&&) = delete;
    };

    GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData)

public:
    EzCategoryModel() = default;
    EzCategoryModel(const EzCategoryModel& ezCategoryModel) = default;
    EzCategoryModel(EzCategoryModel&& ezCategoryModel) = default;
    ~EzCategoryModel() = default;

    EzCategoryModel(gs2::ranking::CategoryModel categoryModel);
    EzCategoryModel(gs2::optional<gs2::ranking::CategoryModel> categoryModel);

    EzCategoryModel& operator=(const EzCategoryModel& ezCategoryModel) = default;
    EzCategoryModel& operator=(EzCategoryModel&& ezCategoryModel) = default;

    EzCategoryModel deepCopy() const;

    gs2::ranking::CategoryModel ToModel() const;

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return ensureData().metadata;
    }

    const StringHolder& getEntryPeriodEventId() const
    {
        return ensureData().entryPeriodEventId;
    }

    const StringHolder& getAccessPeriodEventId() const
    {
        return ensureData().accessPeriodEventId;
    }

    // ========================================
    //   Setters
    // ========================================

    void setName(StringHolder name)
    {
        ensureData().name = std::move(name);
    }

    void setMetadata(StringHolder metadata)
    {
        ensureData().metadata = std::move(metadata);
    }

    void setEntryPeriodEventId(StringHolder entryPeriodEventId)
    {
        ensureData().entryPeriodEventId = std::move(entryPeriodEventId);
    }

    void setAccessPeriodEventId(StringHolder accessPeriodEventId)
    {
        ensureData().accessPeriodEventId = std::move(accessPeriodEventId);
    }

    EzCategoryModel& withName(StringHolder name)
    {
        setName(std::move(name));
        return *this;
    }

    EzCategoryModel& withMetadata(StringHolder metadata)
    {
        setMetadata(std::move(metadata));
        return *this;
    }

    EzCategoryModel& withEntryPeriodEventId(StringHolder entryPeriodEventId)
    {
        setEntryPeriodEventId(std::move(entryPeriodEventId));
        return *this;
    }

    EzCategoryModel& withAccessPeriodEventId(StringHolder accessPeriodEventId)
    {
        setAccessPeriodEventId(std::move(accessPeriodEventId));
        return *this;
    }
};

}}}

#endif //GS2_EZ_RANKING_EZCATEGORYMODEL_HPP_