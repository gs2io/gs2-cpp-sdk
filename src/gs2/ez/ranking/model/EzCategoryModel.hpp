

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

#include <gs2/ranking/model/CategoryModel.hpp>


namespace gs2 { namespace ez { namespace ranking {

class EzCategoryModel : public gs2::Gs2Object
{
private:
    class Data : public gs2::Gs2Object
    {
    public:
        /** カテゴリ名 */
        gs2::optional<StringHolder> name;
        /** カテゴリのメタデータ */
        gs2::optional<StringHolder> metadata;

        Data() = default;

        Data(const Data& data) :
            Gs2Object(data),
            name(data.name),
            metadata(data.metadata)
        {
        }

        Data(Data&& data) = default;

        Data(const gs2::ranking::CategoryModel& categoryModel) :
            name(categoryModel.getName()),
            metadata(categoryModel.getMetadata())
        {
        }

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

    EzCategoryModel(gs2::ranking::CategoryModel categoryModel) :
        GS2_CORE_SHARED_DATA_INITIALIZATION(categoryModel)
    {}

    EzCategoryModel& operator=(const EzCategoryModel& ezCategoryModel) = default;
    EzCategoryModel& operator=(EzCategoryModel&& ezCategoryModel) = default;

    EzCategoryModel deepCopy() const
    {
        GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCategoryModel);
    }

    gs2::ranking::CategoryModel ToModel() const
    {
        gs2::ranking::CategoryModel categoryModel;
        categoryModel.setName(getName());
        categoryModel.setMetadata(getMetadata());
        return categoryModel;
    }

    // ========================================
    //   Getters
    // ========================================

    const StringHolder& getName() const
    {
        return *ensureData().name;
    }

    const StringHolder& getMetadata() const
    {
        return *ensureData().metadata;
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
};

}}}

#endif //GS2_EZ_RANKING_EZCATEGORYMODEL_HPP_