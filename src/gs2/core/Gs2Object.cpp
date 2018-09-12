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

#include "Gs2Object.hpp"
#include "util/DefaultAllocator.hpp"

GS2_START_OF_NAMESPACE

namespace {

detail::DefaultAllocator g_DefaultAllocator;

}

IAllocator* Gs2Object::g_pAllocator = &g_DefaultAllocator;

void Gs2Object::setAllocator(gs2::IAllocator &allocator)
{
    g_pAllocator = &allocator;
}

IAllocator& Gs2Object::getAllocator()
{
    return *g_pAllocator;
}

void* Gs2Object::operator new(std::size_t size)
{
    return g_pAllocator->malloc(size);
}

void* Gs2Object::operator new[](std::size_t size)
{
    return g_pAllocator->malloc(size);
}

void Gs2Object::operator delete(void* p)
{
    g_pAllocator->free(p);
}

void Gs2Object::operator delete[](void* p)
{
    g_pAllocator->free(p);
}
/*
void Gs2Object::operator delete(void* p) noexcept
{
    g_pAllocator->free(p);
}

void Gs2Object::operator delete[](void* p) noexcept
{
    g_pAllocator->free(p);
}
*/
void Gs2Object::operator delete(void* p, std::size_t size) noexcept
{
    GS2_NOT_USED(size);

    g_pAllocator->free(p);
}

void Gs2Object::operator delete[](void* p, std::size_t size) noexcept
{
    GS2_NOT_USED(size);

    g_pAllocator->free(p);
}

void* Gs2Object::operator new(std::size_t, void* address)
{
    return address;
}

void* Gs2Object::operator new[](std::size_t, void* address)
{
    return address;
}

//void* Gs2Object::operator new[](std::size_t size, Args...)
//{
//    GS2_NOT_USED(Args);
//
//    return g_pAllocator->malloc(size);
//}
//
//void Gs2Object::operator delete[](void* p, Args...) noexcept
//{
//    GS2_NOT_USED(Args);
//
//    g_pAllocator->free(p);
//}

GS2_END_OF_NAMESPACE
