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

#include "DefaultAllocator.hpp"
#include <memory>

GS2_START_OF_NAMESPACE

namespace detail {

void* DefaultAllocator::malloc(std::size_t size)
{
    return std::malloc(size);
}

void DefaultAllocator::free(void* ptr)
{
    std::free(ptr);
}

void* DefaultAllocator::calloc(std::size_t nmemb, std::size_t size)
{
    return std::calloc(nmemb, size);
}

void* DefaultAllocator::realloc(void* ptr, std::size_t size)
{
    return std::realloc(ptr, size);
}

}

GS2_END_OF_NAMESPACE
