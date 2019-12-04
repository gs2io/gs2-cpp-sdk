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

#include "EzCategoryModel.hpp"
#include <gs2/ranking/model/CategoryModel.hpp>


namespace gs2 { namespace ez { namespace ranking {

EzCategoryModel::Data::Data(const Data& data) :
    Gs2Object(data),
    name(data.name),
    metadata(data.metadata)
{
}

EzCategoryModel::Data::Data(const gs2::ranking::CategoryModel& categoryModel) :
    name(categoryModel.getName()),
    metadata(categoryModel.getMetadata())
{
}

EzCategoryModel::EzCategoryModel(gs2::ranking::CategoryModel categoryModel) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(categoryModel)
{
}

EzCategoryModel EzCategoryModel::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzCategoryModel);
}

gs2::ranking::CategoryModel EzCategoryModel::ToModel() const
{
    gs2::ranking::CategoryModel categoryModel;
    categoryModel.setName(getName());
    categoryModel.setMetadata(getMetadata());
    return categoryModel;
}

}}}