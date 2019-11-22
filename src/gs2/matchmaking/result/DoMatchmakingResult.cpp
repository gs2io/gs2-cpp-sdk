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

#include "DoMatchmakingResult.hpp"
#include <gs2/core/json/JsonParser.hpp>

namespace gs2 { namespace matchmaking
{

DoMatchmakingResult::Data::Data(const Data& data) :
    detail::json::IModel(data),
    matchmakingContextToken(data.matchmakingContextToken)
{
    if (data.item)
    {
        item = data.item->deepCopy();
    }
}

void DoMatchmakingResult::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "item") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->item.emplace();
            detail::json::JsonParser::parse(&this->item->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "matchmakingContextToken") == 0)
    {
        if (jsonValue.IsString())
        {
            this->matchmakingContextToken.emplace(jsonValue.GetString());
        }
    }
}

DoMatchmakingResult DoMatchmakingResult::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(DoMatchmakingResult);
}

} }