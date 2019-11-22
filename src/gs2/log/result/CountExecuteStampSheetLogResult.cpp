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

#include "CountExecuteStampSheetLogResult.hpp"
#include <gs2/core/json/JsonParser.hpp>

namespace gs2 { namespace log
{

CountExecuteStampSheetLogResult::Data::Data(const Data& data) :
    detail::json::IModel(data),
    nextPageToken(data.nextPageToken),
    totalCount(data.totalCount),
    scanSize(data.scanSize)
{
    if (data.items)
    {
        items = data.items->deepCopy();
    }
}

void CountExecuteStampSheetLogResult::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "items") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->items.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                ExecuteStampSheetLogCount item;
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
    else if (std::strcmp(name_, "totalCount") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->totalCount = jsonValue.GetInt64();
        }
    }
    else if (std::strcmp(name_, "scanSize") == 0)
    {
        if (jsonValue.IsInt64())
        {
            this->scanSize = jsonValue.GetInt64();
        }
    }
}

CountExecuteStampSheetLogResult CountExecuteStampSheetLogResult::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(CountExecuteStampSheetLogResult);
}

} }