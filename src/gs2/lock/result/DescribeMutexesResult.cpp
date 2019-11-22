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

#include "DescribeMutexesResult.hpp"
#include <gs2/core/json/JsonParser.hpp>

namespace gs2 { namespace lock
{

DescribeMutexesResult::Data::Data(const Data& data) :
    detail::json::IModel(data),
    nextPageToken(data.nextPageToken)
{
    if (data.items)
    {
        items = data.items->deepCopy();
    }
}

void DescribeMutexesResult::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "items") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->items.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                Mutex item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->items += std::move(item);
            }
        }
    }
    else if (std::strcmp(name_, "nextPageToken") == 0)
    {
        if (jsonValue.IsString())
        {
            this->nextPageToken.emplace(jsonValue.GetString());
        }
    }
}

DescribeMutexesResult DescribeMutexesResult::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DescribeMutexesResult);
}

} }