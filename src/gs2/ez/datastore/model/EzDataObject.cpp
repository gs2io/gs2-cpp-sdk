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

#include "EzDataObject.hpp"
#include <gs2/datastore/model/DataObject.hpp>


namespace gs2 { namespace ez { namespace datastore {

EzDataObject::Data::Data(const Data& data) :
    Gs2Object(data),
    dataObjectId(data.dataObjectId),
    name(data.name),
    userId(data.userId),
    scope(data.scope),
    status(data.status),
    generation(data.generation),
    createdAt(data.createdAt),
    updatedAt(data.updatedAt)
{
    if (data.allowUserIds)
    {
        allowUserIds = data.allowUserIds->deepCopy();
    }
}

EzDataObject::Data::Data(const gs2::datastore::DataObject& dataObject) :
    dataObjectId(dataObject.getDataObjectId()),
    name(dataObject.getName()),
    userId(dataObject.getUserId()),
    scope(dataObject.getScope()),
    allowUserIds(dataObject.getAllowUserIds()),
    status(dataObject.getStatus()),
    generation(dataObject.getGeneration()),
    createdAt(dataObject.getCreatedAt() ? *dataObject.getCreatedAt() : 0),
    updatedAt(dataObject.getUpdatedAt() ? *dataObject.getUpdatedAt() : 0)
{
}

EzDataObject::EzDataObject(gs2::datastore::DataObject dataObject) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(dataObject)
{
}

EzDataObject EzDataObject::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDataObject);
}

gs2::datastore::DataObject EzDataObject::ToModel() const
{
    gs2::datastore::DataObject dataObject;
    dataObject.setDataObjectId(getDataObjectId());
    dataObject.setName(getName());
    dataObject.setUserId(getUserId());
    dataObject.setScope(getScope());
    dataObject.setAllowUserIds(getAllowUserIds());
    dataObject.setStatus(getStatus());
    dataObject.setGeneration(getGeneration());
    dataObject.setCreatedAt(getCreatedAt());
    dataObject.setUpdatedAt(getUpdatedAt());
    return dataObject;
}

}}}