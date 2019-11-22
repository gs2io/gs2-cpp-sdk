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

#include "GetItemWithSignatureByUserIdResult.hpp"
#include <gs2/core/json/JsonParser.hpp>

namespace gs2 { namespace inventory
{

GetItemWithSignatureByUserIdResult::Data::Data(const Data& data) :
    detail::json::IModel(data),
    body(data.body),
    signature(data.signature)
{
    if (data.items)
    {
        items = data.items->deepCopy();
    }
    if (data.itemModel)
    {
        itemModel = data.itemModel->deepCopy();
    }
    if (data.inventory)
    {
        inventory = data.inventory->deepCopy();
    }
}

void GetItemWithSignatureByUserIdResult::Data::set(const Char name_[], const detail::json::JsonConstValue& jsonValue)
{
    if (std::strcmp(name_, "items") == 0)
    {
        if (jsonValue.IsArray())
        {
            const auto& array = jsonValue.GetArray();
            this->items.emplace();
            for (const detail::json::JsonConstValue* json = array.Begin(); json != array.End(); ++json) {
                ItemSet item;
                detail::json::JsonParser::parse(&item.getModel(), static_cast<detail::json::JsonConstObject>(detail::json::getObject(*json)));
                *this->items += std::move(item);
            }
        }
    }
    else if (std::strcmp(name_, "itemModel") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->itemModel.emplace();
            detail::json::JsonParser::parse(&this->itemModel->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "inventory") == 0)
    {
        if (jsonValue.IsObject())
        {
            const auto& jsonObject = detail::json::getObject(jsonValue);
            this->inventory.emplace();
            detail::json::JsonParser::parse(&this->inventory->getModel(), jsonObject);
        }
    }
    else if (std::strcmp(name_, "body") == 0)
    {
        if (jsonValue.IsString())
        {
            this->body.emplace(jsonValue.GetString());
        }
    }
    else if (std::strcmp(name_, "signature") == 0)
    {
        if (jsonValue.IsString())
        {
            this->signature.emplace(jsonValue.GetString());
        }
    }
}

GetItemWithSignatureByUserIdResult GetItemWithSignatureByUserIdResult::deepCopy() const
{
    GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(GetItemWithSignatureByUserIdResult);
}

} }