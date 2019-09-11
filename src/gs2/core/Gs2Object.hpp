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

#ifndef GS2_CORE_GS2OBJECT_HPP_
#define GS2_CORE_GS2OBJECT_HPP_

#include "common.hpp"
#include "IAllocator.hpp"

GS2_START_OF_NAMESPACE

class IAllocator;

class Gs2Object {
private:
    static IAllocator* g_pAllocator;

public:
    static void setAllocator(IAllocator& allocator);
    static IAllocator& getAllocator();

    void* operator new(std::size_t);

    void* operator new[](std::size_t);

    void operator delete(void *);

    void operator delete[](void *);

//    void operator delete(void *) noexcept;

//    void operator delete[](void *) noexcept;

    void operator delete(void *, std::size_t) noexcept;

    void operator delete[](void *, std::size_t) noexcept;

    void* operator new(std::size_t, void* address);

    void* operator new[](std::size_t, void* address);

//    void* operator new(std::size_t, Args...);
//
//    void operator delete(void *, Args...) noexcept;

//    void* operator new[](std::size_t, Args...);
//
//    void operator delete[](void *, Args...) noexcept;
};

#define GS2_CORE_SHARED_DATA_DEFINE_MEMBERS(Data, ensureData) \
    std::shared_ptr<Data> m_pData; \
 \
    Data& ensureData() \
    { \
        if (!m_pData) \
        { \
            m_pData = std::allocate_shared<Data>(detail::StandardAllocator<char>()); \
        } \
        return *m_pData; \
    } \
 \
    const Data& ensureData() const \
    { \
        if (!m_pData) \
        { \
            const_cast<std::shared_ptr<Data>&>(m_pData) = std::allocate_shared<Data>(detail::StandardAllocator<char>()); \
        } \
        return *m_pData; \
    }

#define GS2_CORE_SHARED_DATA_DEEP_COPY_IMPLEMENTATION(Clazz) \
    Clazz copy; \
    if (m_pData) \
    { \
        copy.m_pData = std::allocate_shared<Data>(detail::StandardAllocator<char>(), *m_pData); \
    } \
    return copy

GS2_END_OF_NAMESPACE

#endif //GS2_CORE_GS2OBJECT_HPP_
