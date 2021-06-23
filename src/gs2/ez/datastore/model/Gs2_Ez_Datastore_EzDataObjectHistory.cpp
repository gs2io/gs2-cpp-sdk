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

#include "EzDataObjectHistory.hpp"
#include <gs2/datastore/model/DataObjectHistory.hpp>


namespace gs2 { namespace ez { namespace datastore {

EzDataObjectHistory::Data::Data(const Data& data) :
    Gs2Object(data),
    dataObjectHistoryId(data.dataObjectHistoryId),
    generation(data.generation),
    contentLength(data.contentLength),
    createdAt(data.createdAt)
{
}

EzDataObjectHistory::Data::Data(const gs2::datastore::DataObjectHistory& dataObjectHistory) :
    dataObjectHistoryId(dataObjectHistory.getDataObjectHistoryId()),
    generation(dataObjectHistory.getGeneration()),
    contentLength(dataObjectHistory.getContentLength() ? *dataObjectHistory.getContentLength() : 0),
    createdAt(dataObjectHistory.getCreatedAt() ? *dataObjectHistory.getCreatedAt() : 0)
{
}

EzDataObjectHistory::EzDataObjectHistory(gs2::datastore::DataObjectHistory dataObjectHistory) :
    GS2_CORE_SHARED_DATA_INITIALIZATION(dataObjectHistory)
{
}

EzDataObjectHistory EzDataObjectHistory::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(EzDataObjectHistory);
}

gs2::datastore::DataObjectHistory EzDataObjectHistory::ToModel() const
{
    gs2::datastore::DataObjectHistory dataObjectHistory;
    dataObjectHistory.setDataObjectHistoryId(getDataObjectHistoryId());
    dataObjectHistory.setGeneration(getGeneration());
    dataObjectHistory.setContentLength(getContentLength());
    dataObjectHistory.setCreatedAt(getCreatedAt());
    return dataObjectHistory;
}

}}}