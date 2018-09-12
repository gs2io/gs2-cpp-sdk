/*
 * Copyright 2016-2018 Game Server Services, Inc. or its affiliates. All
 * Rights Reserved.
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

#include "JsonParser.hpp"
#include "IModel.hpp"

GS2_START_OF_NAMESPACE
namespace detail { namespace json {

void JsonParser::parse(IModel* model, const JsonConstObject& json)
{
    for (auto it = json.begin(); it != json.end(); ++it) {
        model->set(it->name.GetString(), it->value);
    }
}

void JsonParser::parse(IModel* model, const Char json[])
{
    auto allocator = Allocator::getInstance();
    JsonDocument document(&allocator, 1024, &allocator);
    document.Parse(json);
    if(document.IsArray()) {
        model->set("", document);
    } else if(document.IsObject()) {
        for (auto it = document.MemberBegin(); it != document.MemberEnd(); ++it) {
            model->set(it->name.GetString(), it->value);
        }
    }
}

} }
GS2_END_OF_NAMESPACE
