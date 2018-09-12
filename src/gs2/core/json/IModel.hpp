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

#ifndef GS2_CORE_JSON_IMODEL_HPP_
#define GS2_CORE_JSON_IMODEL_HPP_

#include "../Gs2Object.hpp"
#include "Allocator.hpp"
#include "../external/rapidjson/include/rapidjson/document.h"

GS2_START_OF_NAMESPACE
namespace detail { namespace json {

typedef GS2_RAPIDJSON_NAMESPACE::GenericValue<GS2_RAPIDJSON_NAMESPACE::UTF8<>, Allocator> JsonConstValue;

class IModel : public Gs2Object
{
public:
    virtual void set(const Char name[], const JsonConstValue& jsonValue) = 0;
};

} }
GS2_END_OF_NAMESPACE

#endif //GS2_CORE_JSON_IMODEL_HPP_
