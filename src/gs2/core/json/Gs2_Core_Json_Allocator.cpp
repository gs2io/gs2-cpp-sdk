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

#include "Allocator.hpp"

GS2_START_OF_NAMESPACE
namespace detail { namespace json {

Allocator Allocator::instance;

Allocator& Allocator::getInstance()
{
    return Allocator::instance;
}

void* Allocator::Malloc(std::size_t size)
{
    if (size)
        return getAllocator().malloc(size);
    else
        return nullptr;
}

void* Allocator::Realloc(void* originalPtr, std::size_t originalSize, std::size_t newSize)
{
    (void)originalSize;
    if (newSize == 0) {
        getAllocator().free(originalPtr);
        return nullptr;
    }
    return getAllocator().realloc(originalPtr, newSize);
}

void Allocator::Free(void *ptr)
{
    getAllocator().free(ptr);
}

} }
GS2_END_OF_NAMESPACE
