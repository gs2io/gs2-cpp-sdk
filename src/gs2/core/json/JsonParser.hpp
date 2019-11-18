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

#ifndef GS2_CORE_JSON_JSONPARSER_HPP_
#define GS2_CORE_JSON_JSONPARSER_HPP_

#include "../Gs2Object.hpp"
#include "Allocator.hpp"
#include "IModel.hpp"

#if GS2_TARGET == GS2_TARGET_WINDOWS
#pragma push_macro("GetObject")
#undef GetObject
#endif

#include "../external/rapidjson/include/rapidjson/document.h"

GS2_START_OF_NAMESPACE
namespace detail { namespace json {

typedef GS2_RAPIDJSON_NAMESPACE::GenericDocument<GS2_RAPIDJSON_NAMESPACE::UTF8<>, Allocator, Allocator> JsonDocument;
typedef GS2_RAPIDJSON_NAMESPACE::GenericArray<true, const JsonConstValue> JsonConstArray;
typedef GS2_RAPIDJSON_NAMESPACE::GenericObject<true, JsonConstValue> JsonConstObject;

class IModel;

class JsonParser : public Gs2Object
{
private:
public:

    static void parse(IModel* model, const Char json[]);
    static void parse(IModel* model, const JsonConstObject& jsonValue);
};

} }
GS2_END_OF_NAMESPACE

#if GS2_TARGET == GS2_TARGET_WINDOWS
#pragma pop_macro("GetObject")
#endif

#endif //GS2_CORE_JSON_JSONPARSER_HPP_
