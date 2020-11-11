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

#include "EzMaterial.hpp"
#include <gs2/enhance/model/Material.hpp>


namespace gs2 { namespace ez { namespace enhance {

EzMaterial::Data::Data(const Data& data) :
    Gs2Object(data),
    materialItemSetId(data.materialItemSetId),
    count(data.count)
{
}

EzMaterial::Data::Data(const gs2::enhance::Material& material) :
    materialItemSetId(material.getMaterialItemSetId()),
    count(material.getCount() ? *material.getCount() : 0)
{
}

EzMaterial::EzMaterial(gs2::enhance::Material material) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(material)
{
}

EzMaterial EzMaterial::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzMaterial);
}

gs2::enhance::Material EzMaterial::ToModel() const
{
    gs2::enhance::Material material;
    material.setMaterialItemSetId(getMaterialItemSetId());
    material.setCount(getCount());
    return material;
}

}}}