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
    allowUserIds = data.allowUserIds.deepCopy();
}

EzDataObject::Data::Data(const gs2::datastore::DataObject& dataObject) :
    dataObjectId(dataObject.getDataObjectId() ? *dataObject.getDataObjectId() : StringHolder()),
    name(dataObject.getName() ? *dataObject.getName() : StringHolder()),
    userId(dataObject.getUserId() ? *dataObject.getUserId() : StringHolder()),
    scope(dataObject.getScope() ? *dataObject.getScope() : StringHolder()),
    allowUserIds(dataObject.getAllowUserIds() ? *dataObject.getAllowUserIds() : List<StringHolder>()),
    status(dataObject.getStatus() ? *dataObject.getStatus() : StringHolder()),
    generation(dataObject.getGeneration() ? *dataObject.getGeneration() : StringHolder()),
    createdAt(dataObject.getCreatedAt() ? *dataObject.getCreatedAt() : 0),
    updatedAt(dataObject.getUpdatedAt() ? *dataObject.getUpdatedAt() : 0)
{
}

EzDataObject::Data::Data(const gs2::optional<gs2::datastore::DataObject>& dataObject) :
    dataObjectId(dataObject && dataObject->getDataObjectId() ? *dataObject->getDataObjectId() : StringHolder()),
    name(dataObject && dataObject->getName() ? *dataObject->getName() : StringHolder()),
    userId(dataObject && dataObject->getUserId() ? *dataObject->getUserId() : StringHolder()),
    scope(dataObject && dataObject->getScope() ? *dataObject->getScope() : StringHolder()),
    allowUserIds(dataObject && dataObject->getAllowUserIds() ? *dataObject->getAllowUserIds() : List<StringHolder>()),
    status(dataObject && dataObject->getStatus() ? *dataObject->getStatus() : StringHolder()),
    generation(dataObject && dataObject->getGeneration() ? *dataObject->getGeneration() : StringHolder()),
    createdAt(dataObject && dataObject->getCreatedAt() ? *dataObject->getCreatedAt() : 0),
    updatedAt(dataObject && dataObject->getUpdatedAt() ? *dataObject->getUpdatedAt() : 0)
{
}

EzDataObject::EzDataObject(gs2::datastore::DataObject dataObject) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(dataObject)
{
}

EzDataObject::EzDataObject(gs2::optional<gs2::datastore::DataObject> dataObject) :
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