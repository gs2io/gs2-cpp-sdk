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

#ifndef GS2_CORE_JSON_ALLOCATOR_HPP_
#define GS2_CORE_JSON_ALLOCATOR_HPP_

#include "../Gs2Object.hpp"

GS2_START_OF_NAMESPACE
namespace detail { namespace json {

class Allocator : public Gs2Object {
private:

    static Allocator instance;

public:

    static const bool kNeedFree = true;

    static Allocator& getInstance();

    void* Malloc(std::size_t size);

    void* Realloc(void* originalPtr, std::size_t originalSize, std::size_t newSize);

    static void Free(void *ptr);
};

} }
GS2_END_OF_NAMESPACE

#endif //GS2_CORE_JSON_ALLOCATOR_HPP_
